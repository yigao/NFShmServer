CREATE TABLE IF NOT EXISTS RoleDBSnsDetail (
 cid BIGINT UNSIGNED NOT NULL ,
 friend_info BLOB /*!99104 COMPRESSED */ ,
 PRIMARY KEY(cid))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table RoleDBSnsDetail add column cid BIGINT UNSIGNED NOT NULL;
alter table RoleDBSnsDetail add column friend_info BLOB ;
*/
