CREATE TABLE IF NOT EXISTS RoleDBData (
 cid BIGINT UNSIGNED NOT NULL ,
 zid INT UNSIGNED ,
 uid INT UNSIGNED ,
 base BLOB /*!99104 COMPRESSED */ ,
 bag BLOB /*!99104 COMPRESSED */ ,
 equip BLOB /*!99104 COMPRESSED */ ,
 task BLOB /*!99104 COMPRESSED */ ,
 unlockinfo BLOB /*!99104 COMPRESSED */ ,
 grow BLOB /*!99104 COMPRESSED */ ,
 mini BLOB /*!99104 COMPRESSED */ ,
 facade BLOB /*!99104 COMPRESSED */ ,
 skill BLOB /*!99104 COMPRESSED */ ,
 mini_activity BLOB /*!99104 COMPRESSED */ ,
 dup BLOB /*!99104 COMPRESSED */ ,
 buff BLOB /*!99104 COMPRESSED */ ,
 boss BLOB /*!99104 COMPRESSED */ ,
 vip BLOB /*!99104 COMPRESSED */ ,
 INDEX(zid),
 INDEX(uid),
 PRIMARY KEY(cid))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table RoleDBData add column cid BIGINT UNSIGNED NOT NULL;
alter table RoleDBData add column zid INT UNSIGNED;
alter table RoleDBData add column uid INT UNSIGNED;
alter table RoleDBData add column base BLOB ;
alter table RoleDBData add column bag BLOB ;
alter table RoleDBData add column equip BLOB ;
alter table RoleDBData add column task BLOB ;
alter table RoleDBData add column unlockinfo BLOB ;
alter table RoleDBData add column grow BLOB ;
alter table RoleDBData add column mini BLOB ;
alter table RoleDBData add column facade BLOB ;
alter table RoleDBData add column skill BLOB ;
alter table RoleDBData add column mini_activity BLOB ;
alter table RoleDBData add column dup BLOB ;
alter table RoleDBData add column buff BLOB ;
alter table RoleDBData add column boss BLOB ;
alter table RoleDBData add column vip BLOB ;
*/
