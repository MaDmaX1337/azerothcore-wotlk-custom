DROP TABLE IF EXISTS `map_difficulty_data`;
CREATE TABLE IF NOT EXISTS `map_difficulty_data` (
  `mapId` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `difficulty` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `parentDifficulty` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `comment` TEXT,
  PRIMARY KEY (`mapId`, `difficulty`)
) ENGINE=MYISAM;

DELETE FROM `command` WHERE `name`='mythic';
INSERT INTO `command` VALUES 
('mythic', 0, 'Syntax: .mythic [#level]\r\n\r\nSets your (and your groups) Dungeon Difficulty to mythic. If a level is set, sets that mythic plus dungeon to that level.');

DELETE FROM `dungeon_access_template` WHERE `map_id`=576 AND `difficulty`=2;
INSERT INTO `dungeon_access_template` (`map_id`, `difficulty`, `min_level`, `max_level`, `min_avg_item_level`, `comment`) VALUES 
(576, 2, 80, 0, 0, 'Halls of Lightning (Mythic Plus)');

DELETE FROM `map_difficulty_data` WHERE `MapId`=576 AND `Difficulty`=2;
INSERT INTO `map_difficulty_data` (`MapId`, `Difficulty`, `ParentDifficulty`, `Comment`) VALUES 
(576, 2, 1, 'The Nexus (Mythic Plus)');

-- Spawn stuff in mythic too
UPDATE creature SET spawnMask = spawnmask | 4 WHERE map = 576;
UPDATE gameobject SET spawnMask = spawnmask | 4 WHERE map = 576;