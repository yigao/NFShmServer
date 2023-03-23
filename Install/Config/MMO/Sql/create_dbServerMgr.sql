CREATE TABLE IF NOT EXISTS dbServerMgr (
 id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT COMMENT "ID" ,
 contract VARCHAR(128) COMMENT "合同号" ,
 machine_addr VARCHAR(128) COMMENT "机器码" ,
 ip VARCHAR(128) COMMENT "IP地址" ,
 bus_name VARCHAR(128) COMMENT "服务器ID" ,
 server_desc VARCHAR(128) COMMENT "描述信息" ,
 cur_count INT UNSIGNED COMMENT "当前服务器数" ,
 last_login_time BIGINT UNSIGNED COMMENT "上一次登录时间" ,
 last_logout_time BIGINT UNSIGNED COMMENT "上一次下线时间" ,
 logout_time_1 BIGINT UNSIGNED ,
 logout_time_2 BIGINT UNSIGNED ,
 logout_time_3 BIGINT UNSIGNED ,
 desc_1 VARCHAR(128) ,
 desc_2 VARCHAR(128) ,
 pair_1_key INT UNSIGNED ,
 pair_1_value INT UNSIGNED ,
 pair_2_key INT UNSIGNED ,
 pair_2_value INT UNSIGNED ,
 facade_1_slot INT ,
 facade_1_instId INT ,
 facade_1_pourId INT ,
 facade_1_pourExp INT ,
 facade_1_pourUnLock INT ,
 facade_1_breakInfo BLOB ,
 facade_1_awakenLv INT ,
 facade_2_slot INT ,
 facade_2_instId INT ,
 facade_2_pourId INT ,
 facade_2_pourExp INT ,
 facade_2_pourUnLock INT ,
 facade_2_breakInfo BLOB ,
 facade_2_awakenLv INT ,
 INDEX(machine_addr),
 INDEX(ip),
 INDEX(bus_name),
 UNIQUE(contract),
 PRIMARY KEY(id)) AUTO_INCREMENT = 10000 ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table dbServerMgr add column id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT COMMENT "ID";
alter table dbServerMgr add column contract VARCHAR(128) COMMENT "合同号";
alter table dbServerMgr add column machine_addr VARCHAR(128) COMMENT "机器码";
alter table dbServerMgr add column ip VARCHAR(128) COMMENT "IP地址";
alter table dbServerMgr add column bus_name VARCHAR(128) COMMENT "服务器ID";
alter table dbServerMgr add column server_desc VARCHAR(128) COMMENT "描述信息";
alter table dbServerMgr add column cur_count INT UNSIGNED COMMENT "当前服务器数";
alter table dbServerMgr add column last_login_time BIGINT UNSIGNED COMMENT "上一次登录时间";
alter table dbServerMgr add column last_logout_time BIGINT UNSIGNED COMMENT "上一次下线时间";
alter table dbServerMgr add column logout_time_1 BIGINT UNSIGNED;
alter table dbServerMgr add column logout_time_2 BIGINT UNSIGNED;
alter table dbServerMgr add column logout_time_3 BIGINT UNSIGNED;
alter table dbServerMgr add column desc_1 VARCHAR(128);
alter table dbServerMgr add column desc_2 VARCHAR(128);
alter table dbServerMgr add column pair_1_key INT UNSIGNED;
alter table dbServerMgr add column pair_1_value INT UNSIGNED;
alter table dbServerMgr add column pair_2_key INT UNSIGNED;
alter table dbServerMgr add column pair_2_value INT UNSIGNED;
alter table dbServerMgr add column facade_1_slot INT;
alter table dbServerMgr add column facade_1_instId INT;
alter table dbServerMgr add column facade_1_pourId INT;
alter table dbServerMgr add column facade_1_pourExp INT;
alter table dbServerMgr add column facade_1_pourUnLock INT;
alter table dbServerMgr add column facade_1_breakInfo BLOB;
alter table dbServerMgr add column facade_1_awakenLv INT;
alter table dbServerMgr add column facade_2_slot INT;
alter table dbServerMgr add column facade_2_instId INT;
alter table dbServerMgr add column facade_2_pourId INT;
alter table dbServerMgr add column facade_2_pourExp INT;
alter table dbServerMgr add column facade_2_pourUnLock INT;
alter table dbServerMgr add column facade_2_breakInfo BLOB;
alter table dbServerMgr add column facade_2_awakenLv INT;
*/
