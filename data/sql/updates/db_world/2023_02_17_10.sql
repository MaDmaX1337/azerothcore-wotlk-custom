-- DB update 2023_02_17_09 -> 2023_02_17_10
--
DELETE FROM `creature` WHERE `id1`=18677;
INSERT INTO `creature` (`guid`, `id1`, `map`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `MovementType`) VALUES
(24918, 18677, 530, 1, -101.271, 3075.18, -1.36056, 3.92147, 21600, 2),
(24919, 18677, 530, 1, -221.482, 3098.84, -60.1361, 4.15876, 21600, 2),
(24920, 18677, 530, 1, -974.96, 3384.15, 85.6275, 6.22306, 21600, 2),
(24921, 18677, 530, 1, -1141.97, 2217.95, 38.9775, 6.13274, 21600, 2);

DELETE FROM `creature_addon` WHERE (`guid` IN (24918, 24919, 24920, 24921, 151922));
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(24918, 249180, 0, 0, 1, 0, 0, ''),
(24919, 249190, 0, 0, 1, 0, 0, ''),
(24920, 249200, 0, 0, 1, 0, 0, ''),
(24921, 249210, 0, 0, 1, 0, 0, '');

DELETE FROM `waypoint_data` WHERE `id` IN (249180, 249190, 249200, 249210, 1519220);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(249180, 1, -101.271, 3075.18, -1.36056),
(249180, 2, -131.354, 3072.52, 1.13944),
(249180, 3, -98.6659, 3100.89, 0.0436902),
(249190, 1, -221.482, 3098.84, -60.1358),
(249190, 2, -242.789, 3052.01, -65.5532),
(249190, 3, -255.483, 2973.82, -66.1634),
(249190, 4, -271.69, 2933.8, -61.2217),
(249190, 5, -258.917, 2804.03, -38.9403),
(249190, 6, -250.113, 2708.84, -21.4125),
(249190, 7, -259.258, 2679.84, -16.955),
(249190, 8, -261.718, 2762.64, -31.8066),
(249190, 9, -281.904, 2917.37, -58.7656),
(249190, 10, -318.014, 2962.57, -65.8476),
(249190, 11, -378.32, 3048.69, -62.8578),
(249190, 12, -328.135, 3006.61, -66.2201),
(249190, 13, -291.092, 3005.17, -66.2201),
(249190, 14, -259.706, 3024.96, -66.146),
(249190, 15, -229.574, 3078.48, -62.3166),
(249200, 1, -974.96, 3384.15, 85.6275),
(249200, 2, -945.458, 3380.19, 82.2227),
(249200, 3, -928.032, 3386.34, 82.8514),
(249200, 4, -843.423, 3386.61, 76.2591),
(249200, 5, -794.345, 3356.64, 59.5092),
(249200, 6, -715.729, 3318.94, 31.7372),
(249200, 7, -670.369, 3284.27, 16.67),
(249200, 8, -630.544, 3267.81, 8.81919),
(249200, 9, -572.965, 3237.67, 5.10526),
(249200, 10, -566.145, 3147.39, 4.97542),
(249200, 11, -553.724, 3141.03, 5.34744),
(249200, 12, -546.554, 3154.08, 18.6763),
(249200, 13, -538.377, 3164.28, 18.4966),
(249200, 14, -546.554, 3154.08, 18.6763),
(249200, 15, -553.724, 3141.03, 5.34744),
(249200, 16, -566.145, 3147.39, 4.97542),
(249200, 17, -572.965, 3237.67, 5.10526),
(249200, 18, -630.544, 3267.81, 8.81919),
(249200, 19, -670.369, 3284.27, 16.67),
(249200, 20, -715.729, 3318.94, 31.7372),
(249200, 21, -794.345, 3356.64, 59.5092),
(249200, 22, -843.423, 3386.61, 76.2591),
(249200, 23, -928.032, 3386.34, 82.8514),
(249200, 24, -945.458, 3380.19, 82.2227),
(249200, 25, -974.96, 3384.15, 85.6275),
(249210, 1, -1141.97, 2217.95, 38.9775),
(249210, 2, -1056.16, 2204.01, 20.5715),
(249210, 3, -976.365, 2201.53, 11.475),
(249210, 4, -927.05, 2151.84, 14.4697),
(249210, 5, -881.321, 2068.67, 31.261),
(249210, 6, -927.918, 2022.61, 62.6539),
(249210, 7, -944.76, 2015.79, 66.6124),
(249210, 8, -990.451, 2015.07, 66.9408),
(249210, 9, -1026.87, 2036.99, 66.9915),
(249210, 10, -1033.48, 2063.15, 66.9338),
(249210, 11, -1057.21, 2109.23, 56.5627),
(249210, 12, -1053.45, 2173.46, 26.8283),
(249210, 13, -1100.46, 2210.16, 30.2365),
(249210, 14, -1140.56, 2206.97, 40.1512);

DELETE FROM `pool_template` WHERE `entry`=1082 AND `description` LIKE '%Mekthorg%';
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES (1082, 1, 'Mekthorg the Wild (18677)');

DELETE FROM `pool_creature` WHERE `pool_entry`=1082 AND `description` LIKE '%Mekthorg%';
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(24918, 1082, 0, 'Mekthorg the Wild (18677)'),
(24919, 1082, 0, 'Mekthorg the Wild (18677)'),
(24920, 1082, 0, 'Mekthorg the Wild (18677)'),
(24921, 1082, 0, 'Mekthorg the Wild (18677)');