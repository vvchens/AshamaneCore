/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "tanaan_intro.h"
#include "ScriptedFollowerAI.h"
#include "GameObject.h"

/// Passive Scene Object
class playerScript_cavern_teleport : public PlayerScript
{
public:
    playerScript_cavern_teleport() : PlayerScript("playerScript_cavern_teleport") { }

    void OnSceneTriggerEvent(Player* p_Player, uint32 p_SceneInstanceID, std::string p_Event) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceID, TanaanSceneObjects::SceneNerZhulReveal))
            return;

        if (p_Event == "Teleport")
        {
            p_Player->TeleportTo(TanaanZones::MapTanaan, 4537.817f, -2291.243f, 32.451f, 0.728175f);

            // Ces phases seront ajout�es apr�s la fin de la scene
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseBlackrockSlaves);
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseBlackrockMainNpcs);

            p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneFromCaveToRidge);
        }
    }
};

/// Archmage Khadgar - 78561 (Main quest giver/taker)
class npc_archmage_khadgar_shadowmoon : public CreatureScript
{
public:
    npc_archmage_khadgar_shadowmoon() : CreatureScript("npc_archmage_khadgar_shadowmoon")
    {
    }

    bool OnQuestReward(Player* p_Player, Creature* p_Creature, const Quest* p_Quest, uint32 p_Option) override
    {
        switch (p_Quest->GetQuestId())
        {
            case TanaanQuests::QuestKillYourHundred:
            {

                if (p_Creature->GetAI())
                {
                    p_Creature->AI()->SetData(0, 1500);
                    p_Creature->AI()->SetGUID(p_Player->GetGUID(), 0);
                }
                break;
            }
            default:
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_archmage_khadgar_shadowmoonAI(creature);
    }

    struct npc_archmage_khadgar_shadowmoonAI : public ScriptedAI
    {
        npc_archmage_khadgar_shadowmoonAI(Creature* creature) : ScriptedAI(creature) { }

        uint16 m_SceneTimer;
        ObjectGuid p_PlayerGuid;

        void Reset() override
        {
            p_PlayerGuid = ObjectGuid::Empty;
            m_SceneTimer = 0;
        }

        void SetData(uint32 /*p_Id*/, uint32 p_Value) override
        {
            m_SceneTimer = (uint16)p_Value;
        }

        void SetGUID(ObjectGuid p_Guid, int32 /*p_Id*/) override
        {
            p_PlayerGuid = p_Guid;
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (m_SceneTimer)
            {
                if (m_SceneTimer <= m_SceneTimer)
                {
                    if (!p_PlayerGuid.IsEmpty())
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, p_PlayerGuid))
                        {
                            l_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseShadowmoonQuianaMaladaar);
                            l_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseShadowmoonLiadrinOlin);

                            l_Player->GetSceneMgr().PlaySceneByPackageId(l_Player->GetTeamId() == TEAM_ALLIANCE ? TanaanSceneObjects::SceneQuianaAndMaladaarEnter : TanaanSceneObjects::SceneLiadrinAndOlinEnter);
                        }
                    }
                    m_SceneTimer = 0;
                }
                else
                    m_SceneTimer -= p_Diff;
            }
        }
    };
};

/// 79583 - Ungra
class npc_tanaan_ungra : public CreatureScript
{
public:
    npc_tanaan_ungra() : CreatureScript("npc_tanaan_ungra")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tanaan_ungraAI(creature);
    }

    struct npc_tanaan_ungraAI : public ScriptedAI
    {
        npc_tanaan_ungraAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* /*p_Killer*/) override
        {
            std::list<Player*> l_PlayerList;
            GetPlayerListInGrid(l_PlayerList, me, 20.0f);

            for (Player* l_Player : l_PlayerList)
                l_Player->KilledMonsterCredit(me->GetEntry());
        }
    };
};

/// 79585 - Taskmaster Gurran
class npc_taskmaster_gurran : public CreatureScript
{
public:
    npc_taskmaster_gurran() : CreatureScript("npc_taskmaster_gurran")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_taskmaster_gurranAI(creature);
    }

    struct npc_taskmaster_gurranAI : public ScriptedAI
    {
        npc_taskmaster_gurranAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* /*p_Killer*/) override
        {
            std::list<Player*> l_PlayerList;
            GetPlayerListInGrid(l_PlayerList, me, 20.0f);

            for (Player* l_Player : l_PlayerList)
                l_Player->KilledMonsterCredit(me->GetEntry());
        }
    };
};

/// 79593 - Ankova the Fallen
class npc_ankova_the_fallen : public CreatureScript
{
public:
    npc_ankova_the_fallen() : CreatureScript("npc_ankova_the_fallen")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ankova_the_fallenAI(creature);
    }

    struct npc_ankova_the_fallenAI : public ScriptedAI
    {
        npc_ankova_the_fallenAI(Creature* creature) : ScriptedAI(creature) { }

        enum data
        {
            SPELL_ANKOVA_CREDIT = 160774
        };

        void Reset() override
        {
            SetCanSeeEvenInPassiveMode(true);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) < 10.0f)
                if (Player* player = who->ToPlayer())
                    if (player->HasQuest(TanaanQuests::QuestMastersOfShadowAlly) || player->HasQuest(TanaanQuests::QuestMastersOfShadowHorde))
                        who->CastSpell(who, SPELL_ANKOVA_CREDIT, true);
        }
    };
};

/// 78994 - Yrel
class npc_tanaan_yrel : public CreatureScript
{
public:
    npc_tanaan_yrel() : CreatureScript("npc_tanaan_yrel") { }

    bool OnQuestAccept(Player* p_Player, Creature* p_Creature, const Quest* p_Quest) override
    {
        if (p_Quest->GetQuestId() == TanaanQuests::QuestYrelTanaan || p_Quest->GetQuestId() == TanaanQuests::QuestYrelHorde)
            p_Player->SummonCreature(TanaanCreatures::NpcYrelSummon, p_Creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);

        return false;
    }
};

/// 79794 - Yrel
class npc_tanaan_yrel_summon : public CreatureScript
{
public:
    npc_tanaan_yrel_summon() : CreatureScript("npc_tanaan_yrel_summon")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tanaan_yrel_summonAI(creature);
    }

    struct npc_tanaan_yrel_summonAI : public FollowerAI
    {
        npc_tanaan_yrel_summonAI(Creature* creature) : FollowerAI(creature)  { }

        enum eEvents
        {
            EventCheckStopFollow    = 1,
            EventContinueRun        = 2,
            EventCheckSummoner      = 3
        };

        EventMap m_Events;
        ObjectGuid m_PlayerGuid;

        void IsSummonedBy(Unit* p_Summoner) override
        {
            if (!p_Summoner->ToPlayer())
                return;

            m_PlayerGuid = p_Summoner->GetGUID();

            StartFollow(p_Summoner->ToPlayer(), 35);

            m_Events.ScheduleEvent(eEvents::EventCheckStopFollow, 6000);
        }

        void MovementInform(uint32 p_Type, uint32 p_Id) override
        {
            if (p_Type != POINT_MOTION_TYPE)
                return;

            switch (p_Id)
            {
                case 1:
                    me->GetMotionMaster()->MovePoint(2, 4540.006f, -2501.200f, 20.08f);
                    break;
                case 2:
                    me->GetMotionMaster()->MovePoint(3, 4541.180f, -2474.347f, 25.218f);
                    break;
                case 3:
                    me->GetMotionMaster()->MovePoint(4, 4513.743f, -2473.987f, 25.298f);
                    break;
                case 4:
                    me->GetMotionMaster()->MovePoint(5, 4516.58f, -2495.62f, 25.872f);
                    break;
                case 5:
                {
                    me->SetFacingTo(1.664600f);
                    if (!m_PlayerGuid.IsEmpty())
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                        {
                            if (l_Player->HasQuest(TanaanQuests::QuestYrelTanaan) || l_Player->HasQuest(TanaanQuests::QuestYrelHorde))
                                l_Player->KilledMonsterCredit(TanaanKillCredits::CreditEscortYrel);

                            me->DespawnOrUnsummon();
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            m_Events.Update(p_Diff);
            FollowerAI::UpdateAI(p_Diff);

            switch (m_Events.ExecuteEvent())
            {
                case eEvents::EventCheckStopFollow:
                {
                    if (GetClosestCreatureWithEntry(me, TanaanCreatures::NpcExarchMaladaar, 50.0f) ||
                        GetClosestCreatureWithEntry(me, TanaanCreatures::NpcLadyLiadrin, 50.0f)
                        || me->GetPositionX() < 4560.0f)
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                        SetFollowPaused(true);

                        m_Events.CancelEvent(eEvents::EventCheckStopFollow);
                        m_Events.ScheduleEvent(eEvents::EventContinueRun, 1000);
                    }
                    else
                        m_Events.ScheduleEvent(eEvents::EventCheckStopFollow, 800);

                    break;
                }
                case eEvents::EventContinueRun:
                {
                    me->GetMotionMaster()->MovePoint(1, 4539.223f, -2521.753f, 14.361f);
                    break;
                }
                case eEvents::EventCheckSummoner:
                {
                    Player* l_Player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid);

                    if (!l_Player || !l_Player->IsAlive())
                        me->DespawnOrUnsummon();

                    if (!l_Player->HasQuest(TanaanQuests::QuestYrelTanaan) && !l_Player->HasQuest(TanaanQuests::QuestYrelHorde))
                        me->DespawnOrUnsummon();

                    break;
                }
                default:
                    break;
            }
        }
    };
};

/// 79537 - Exarch Maladaar
/// 79675 - Lady Liadrin
class npc_maladaar_liadrin_tanaan_cave : public CreatureScript
{
public:
    npc_maladaar_liadrin_tanaan_cave() : CreatureScript("npc_maladaar_liadrin_tanaan_cave") { }

    bool OnQuestAccept(Player* p_Player, Creature* p_Creature, const Quest* p_Quest) override
    {
        if (p_Quest->GetQuestId() == TanaanQuests::QuestKeliDanTheBreakerAlly || p_Quest->GetQuestId() == TanaanQuests::QuestKeliDanTheBreakerHorde)
            p_Player->GetSceneMgr().PlaySceneByPackageId(p_Creature->GetEntry() == TanaanCreatures::NpcExarchMaladaar ? TanaanSceneObjects::SceneYrelLeaveAlliance : TanaanSceneObjects::SceneYrelLeaveHorde);

        return false;
    }
};

class go_iron_cage_door : public GameObjectScript
{
public:
    go_iron_cage_door() : GameObjectScript("go_iron_cage_door")
    {
        checkTimer = 1000;
    }

    uint32 checkTimer;

    void OnUpdate(GameObject* p_Object, uint32 p_Diff) override
    {
        if (checkTimer < p_Diff)
        {
            checkTimer -= p_Diff;
            return;
        }

        std::list<Player*> l_PlayerList;
        GetPlayerListInGrid(l_PlayerList, p_Object, 10.0f);
        bool playerWithQuestInSight = false;

        for (Player* player : l_PlayerList)
        {
            if (player->HasQuest(TanaanQuests::QuestKeliDanTheBreakerAlly) || player->HasQuest(TanaanQuests::QuestKeliDanTheBreakerHorde))
            {
                playerWithQuestInSight = true;
                break;
            }
        }

        if (playerWithQuestInSight)
            p_Object->UseDoorOrButton(86400);
        else
            p_Object->ResetDoorOrButton();

        checkTimer = 1000;
    }
};

/// 79702 - Keli'Dan the Breaker
class npc_keli_dan_the_breaker : public CreatureScript
{
public:
    npc_keli_dan_the_breaker() : CreatureScript("npc_keli_dan_the_breaker") { }

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new npc_keli_dan_the_breakerAI(p_Creature);
    }

    struct npc_keli_dan_the_breakerAI : public ScriptedAI
    {
        npc_keli_dan_the_breakerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        EventMap m_events;

        enum eDatas
        {
            EVENT_VOID_SHELL        = 1,
            EVENT_VOID_BOLT_VOLLEY  = 2,

            SPELL_VOID_SHELL        = 165880,
            SPELL_VOID_BOLT_VOLLEY  = 165875,
            //SPELL_VOID_VACUUM       = 165871
        };

        void Reset() override
        {
            m_events.ScheduleEvent(EVENT_VOID_BOLT_VOLLEY,  urand(8000, 15000));
            m_events.ScheduleEvent(EVENT_VOID_SHELL,        urand(10000, 20000));
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            m_events.Update(p_Diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (m_events.ExecuteEvent())
            {
                case EVENT_VOID_BOLT_VOLLEY:
                {
                    DoCastAOE(SPELL_VOID_BOLT_VOLLEY);
                    m_events.ScheduleEvent(EVENT_VOID_BOLT_VOLLEY, urand(10000, 20000));
                    break;
                }
                case EVENT_VOID_SHELL:
                {
                    DoCastAOE(SPELL_VOID_SHELL);
                    m_events.ScheduleEvent(EVENT_VOID_SHELL, urand(15000, 210000));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*p_Killer*/) override
        {
            std::list<Player*> l_PlayerList;
            GetPlayerListInGrid(l_PlayerList, me, 36.0f);

            for (Player* l_Player : l_PlayerList)
            {
                if (l_Player->HasQuest(TanaanQuests::QuestKeliDanTheBreakerAlly) || l_Player->HasQuest(TanaanQuests::QuestKeliDanTheBreakerHorde))
                {
                    l_Player->KilledMonsterCredit(me->GetEntry());
                    l_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneNerZhulReveal, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                }
            }
        }
    };
};

void AddSC_tanaan_intro_shadowmoon()
{
    new npc_archmage_khadgar_shadowmoon();
    new npc_tanaan_ungra();
    new npc_taskmaster_gurran();
    new npc_ankova_the_fallen();
    new npc_tanaan_yrel_summon();
    new npc_tanaan_yrel();
    new npc_maladaar_liadrin_tanaan_cave();
    new go_iron_cage_door();
    new npc_keli_dan_the_breaker();

    new playerScript_cavern_teleport();
}