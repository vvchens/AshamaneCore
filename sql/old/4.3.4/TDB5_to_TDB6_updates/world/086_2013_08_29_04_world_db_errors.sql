-- Update sai to correlate with the pointid changes, otherwise we get a cluster of bad movement
UPDATE `smart_scripts` SET `event_param1`=7 WHERE  `entryorguid`=27411 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `event_param1`=37 WHERE  `entryorguid`=27409 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=75 WHERE  `entryorguid`=27409 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=103 WHERE  `entryorguid`=27409 AND `source_type`=0 AND `id`=2 AND `link`=5;

DELETE FROM `waypoints` WHERE entry = 27409;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27409, 1, 4431.638672, -2481.546143, 245.497971, ''),
(27409, 2, 4449.238281, -2471.332031, 242.360382, ''),
(27409, 3, 4461.925293, -2462.848145, 239.519882, ''),
(27409, 4, 4462.994141, -2448.238037, 237.881256, ''),
(27409, 5, 4479.575684, -2434.093506, 235.040390, ''),
(27409, 6, 4488.495605, -2420.688477, 233.043091, ''),
(27409, 7, 4494.654785, -2414.143066, 230.241013, ''),
(27409, 8, 4499.730469, -2414.861572, 230.952850, ''),
(27409, 9, 4510.846191, -2401.806641, 226.618698, ''),
(27409, 10, 4517.005371, -2388.016357, 220.151077, ''),
(27409, 11, 4520.017578, -2373.915283, 213.041779, ''),
(27409, 12, 4524.577637, -2355.400391, 202.208481, ''),
(27409, 13, 4520.500977, -2332.202148, 190.853638, ''),
(27409, 14, 4509.677734, -2314.525635, 182.408096, ''),
(27409, 15, 4488.281250, -2309.130127, 184.351913, ''),
(27409, 16, 4480.724609, -2311.419434, 185.420715, ''),
(27409, 17, 4470.293457, -2314.579346, 183.929382, ''),
(27409, 18, 4453.349121, -2318.290771, 189.487000, ''),
(27409, 19, 4442.953613, -2311.859375, 192.656219, ''),
(27409, 20, 4414.564941, -2297.739258, 191.105362, ''),
(27409, 21, 4396.023438, -2286.889648, 192.638016, ''),
(27409, 22, 4383.112305, -2278.546631, 188.321487, ''),
(27409, 23, 4369.118652, -2256.089844, 187.592911, ''),
(27409, 24, 4339.653320, -2250.217529, 188.636993, ''),
(27409, 25, 4299.784180, -2260.091309, 205.303589, ''),
(27409, 26, 4292.068848, -2261.806885, 209.099808, ''),
(27409, 27, 4258.068359, -2270.728027, 212.053543, ''),
(27409, 28, 4224.148926, -2276.497559, 214.878052, ''),
(27409, 29, 4210.618652, -2280.829346, 214.910553, ''),
(27409, 30, 4193.759766, -2285.936035, 219.885529, ''),
(27409, 31, 4168.561523, -2272.436279, 221.375009, ''),
(27409, 32, 4151.019531, -2269.352783, 223.433472, ''),
(27409, 33, 4131.847168, -2271.157715, 221.920700, ''),
(27409, 34, 4112.480469, -2276.041748, 219.916550, ''),
(27409, 35, 4103.597656, -2274.198730, 219.276031, ''),
(27409, 36, 4093.837158, -2276.393066, 219.042526, ''),
(27409, 37, 4084.734375, -2272.286133, 217.870331, ''), -- Jump PoS
(27409, 38, 4063.238525, -2261.991211, 215.988922, ''), -- Jump continuation
(27409, 39, 4059.935547, -2260.473145, 216.993256, ''),
(27409, 40, 4028.185791, -2252.874512, 218.258530, ''),
(27409, 41, 4020.977539, -2249.354004, 217.129837, ''),
(27409, 42, 4005.426025, -2256.105957, 218.451675, ''),
(27409, 43, 3988.108398, -2262.058350, 217.109756, ''),
(27409, 44, 3968.364014, -2267.235840, 215.268341, ''),
(27409, 45, 3953.139893, -2268.633057, 212.391113, ''),
(27409, 46, 3935.732422, -2276.518066, 209.669937, ''),
(27409, 47, 3922.170898, -2282.024414, 211.200699, ''),
(27409, 48, 3913.766846, -2300.279541, 209.620239, ''),
(27409, 49, 3914.160156, -2317.614990, 208.949615, ''),
(27409, 50, 3911.533936, -2330.580078, 207.751999, ''),
(27409, 51, 3907.095947, -2346.107422, 204.630707, ''),
(27409, 52, 3901.425537, -2362.481201, 206.197708, ''),
(27409, 53, 3885.374756, -2368.482178, 202.270737, ''),
(27409, 54, 3871.682617, -2371.436035, 196.694305, ''),
(27409, 55, 3858.806396, -2374.236816, 194.038589, ''),
(27409, 56, 3833.323975, -2390.121582, 187.584473, ''),
(27409, 57, 3818.713379, -2403.767090, 183.718597, ''),
(27409, 58, 3812.403564, -2425.267334, 185.086273, ''),
(27409, 59, 3812.611328, -2432.785400, 186.023727, ''),
(27409, 60, 3812.221680, -2453.928711, 188.508041, ''),
(27409, 61, 3815.669189, -2479.355957, 192.388458, ''),
(27409, 62, 3819.468262, -2503.677002, 195.024658, ''),
(27409, 63, 3822.264648, -2517.937256, 194.068130, ''),
(27409, 64, 3825.485107, -2534.361572, 196.379684, ''),
(27409, 65, 3829.201660, -2554.680664, 196.714203, ''),
(27409, 66, 3836.672119, -2578.528076, 196.706253, ''),
(27409, 67, 3847.536133, -2609.345459, 200.060410, ''),
(27409, 68, 3861.525879, -2624.756592, 202.314850, ''),
(27409, 69, 3882.063232, -2655.939209, 203.425415, ''),
(27409, 70, 3886.698975, -2663.550293, 208.091705, ''),
(27409, 71, 3900.575928, -2672.409912, 212.662750, ''),
(27409, 72, 3909.817383, -2687.583008, 217.098572, ''),
(27409, 73, 3911.782959, -2695.853027, 220.364487, ''),
(27409, 74, 3916.008301, -2703.185791, 221.175446, ''),
(27409, 75, 3912.544678, -2712.180420, 221.059509, ''), -- Jump location
(27409, 76, 3900.396484, -2743.329346, 219.152481, ''), -- Jump continue
(27409, 77, 3889.821777, -2751.587646, 221.798737, ''),
(27409, 78, 3883.421875, -2756.963379, 223.885544, ''),
(27409, 79, 3851.103027, -2769.906494, 227.460480, ''),
(27409, 80, 3837.903076, -2769.537842, 226.115402, ''),
(27409, 81, 3813.292725, -2770.593018, 220.927460, ''),
(27409, 82, 3801.162109, -2771.017578, 219.535080, ''),
(27409, 83, 3780.501709, -2772.391602, 213.905884, ''),
(27409, 84, 3767.551025, -2775.388672, 211.281708, ''),
(27409, 85, 3759.778320, -2782.290771, 209.165924, ''),
(27409, 86, 3752.759277, -2787.596436, 206.495926, ''),
(27409, 87, 3729.982422, -2803.813721, 210.023056, ''),
(27409, 88, 3723.949951, -2808.085693, 211.655594, ''),
(27409, 89, 3705.986328, -2819.675537, 215.066315, ''),
(27409, 90, 3685.556152, -2832.987549, 217.602127, ''),
(27409, 91, 3674.411377, -2843.797852, 217.875214, ''),
(27409, 92, 3662.455811, -2853.292480, 216.581512, ''),
(27409, 93, 3647.392822, -2857.280518, 213.150558, ''),
(27409, 94, 3630.625977, -2860.268555, 214.962250, ''),
(27409, 95, 3610.744141, -2858.618164, 208.903931, ''),
(27409, 96, 3587.919189, -2854.562500, 203.447754, ''),
(27409, 97, 3562.793213, -2842.607666, 197.044495, ''),
(27409, 98, 3534.265625, -2828.214600, 197.154617, ''),
(27409, 99, 3515.692871, -2829.376709, 201.276230, ''),
(27409, 100, 3487.658691, -2829.192871, 202.143524, ''),
(27409, 101, 3472.460693, -2821.599365, 201.429428, ''),
(27409, 102, 3460.582031, -2817.212402, 201.804962, ''),
(27409, 103, 3443.644531, -2811.332520, 202.097687, '');

-- Freed Alliance Scout waypoints
DELETE FROM `waypoints` WHERE entry = 27411;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27411, 1, 4394.648438, -2502.304688, 252.802429, ''),
(27411, 2, 4389.777832, -2502.323242, 252.251602, ''),
(27411, 3, 4382.442383, -2501.507080, 246.809448, ''),
(27411, 4, 4381.006836, -2497.183838, 247.235260, ''),
(27411, 5, 4393.843750, -2484.841553, 248.717392, ''),
(27411, 6, 4416.043457, -2481.504150, 247.175400, ''),
(27411, 7, 4425.312500, -2486.656006, 246.555176, '');