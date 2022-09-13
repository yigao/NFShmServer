CREATE TABLE IF NOT EXISTS tbAccountTable (
 player_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT ,
 account VARCHAR(128) ,
 password VARCHAR(128) ,
 account_type INT UNSIGNED ,
 device_id VARCHAR(128) ,
 phonenum BIGINT UNSIGNED ,
 real_player_id BIGINT UNSIGNED ,
 INDEX(password),
 UNIQUE(account),
 PRIMARY KEY(player_id)) AUTO_INCREMENT = 10000 ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbAccountTable add column player_id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT;
alter table tbAccountTable add column account VARCHAR(128);
alter table tbAccountTable add column password VARCHAR(128);
alter table tbAccountTable add column account_type INT UNSIGNED;
alter table tbAccountTable add column device_id VARCHAR(128);
alter table tbAccountTable add column phonenum BIGINT UNSIGNED;
alter table tbAccountTable add column real_player_id BIGINT UNSIGNED;
*/
