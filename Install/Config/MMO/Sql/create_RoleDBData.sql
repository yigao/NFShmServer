CREATE TABLE IF NOT EXISTS RoleDBData (
 cid BIGINT UNSIGNED ,
 zid INT UNSIGNED ,
 uid INT UNSIGNED ,
 base BLOB /*!99104 COMPRESSED */ ,
 bag BLOB /*!99104 COMPRESSED */ ,
 equip BLOB /*!99104 COMPRESSED */ ,
 task BLOB /*!99104 COMPRESSED */ ,
 unlockInfo BLOB /*!99104 COMPRESSED */ ,
 grow BLOB /*!99104 COMPRESSED */ ,
 mini BLOB /*!99104 COMPRESSED */ ,
)  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table RoleDBData add column cid BIGINT UNSIGNED;
alter table RoleDBData add column zid INT UNSIGNED;
alter table RoleDBData add column uid INT UNSIGNED;
alter table RoleDBData add column base BLOB ;
alter table RoleDBData add column bag BLOB ;
alter table RoleDBData add column equip BLOB ;
alter table RoleDBData add column task BLOB ;
alter table RoleDBData add column unlockInfo BLOB ;
alter table RoleDBData add column grow BLOB ;
alter table RoleDBData add column mini BLOB ;
*/
