CREATE TABLE IF NOT EXISTS tbEventLog (
 user_id BIGINT UNSIGNED NOT NULL ,
 event_id BIGINT UNSIGNED NOT NULL ,
 create_time INT ,
 expire_time INT ,
 data BLOB /*!99104 COMPRESSED */ ,
 PRIMARY KEY(user_id,event_id))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbEventLog add column user_id BIGINT UNSIGNED NOT NULL;
alter table tbEventLog add column event_id BIGINT UNSIGNED NOT NULL;
alter table tbEventLog add column create_time INT;
alter table tbEventLog add column expire_time INT;
alter table tbEventLog add column data BLOB ;
*/
