CREATE TABLE IF NOT EXISTS tbRoleInfo (
 charId BIGINT UNSIGNED NOT NULL ,
 playerId BIGINT UNSIGNED ,
 bornZoneId BIGINT UNSIGNED ,
 charName VARCHAR(128) ,
 platId VARCHAR(128) ,
 baseData BLOB /*!99104 COMPRESSED */ ,
 INDEX(playerId),
 INDEX(bornZoneId),
 PRIMARY KEY(charId))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbRoleInfo add column charId BIGINT UNSIGNED NOT NULL;
alter table tbRoleInfo add column playerId BIGINT UNSIGNED;
alter table tbRoleInfo add column bornZoneId BIGINT UNSIGNED;
alter table tbRoleInfo add column charName VARCHAR(128);
alter table tbRoleInfo add column platId VARCHAR(128);
alter table tbRoleInfo add column baseData BLOB ;
*/
