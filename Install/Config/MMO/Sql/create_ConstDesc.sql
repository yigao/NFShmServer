CREATE TABLE IF NOT EXISTS ConstDesc (
 id INT NOT NULL AUTO_INCREMENT COMMENT "编号" ,
 value VARCHAR(128) COMMENT "常量值" ,
 type_name VARCHAR(128) COMMENT "类型名称" ,
 PRIMARY KEY(id)) AUTO_INCREMENT = 1 ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table ConstDesc add column id INT NOT NULL AUTO_INCREMENT COMMENT "编号";
alter table ConstDesc add column value VARCHAR(128) COMMENT "常量值";
alter table ConstDesc add column type_name VARCHAR(128) COMMENT "类型名称";
*/
INSERT INTO ConstDesc (type_name,id,value) VALUES('玩家初始赠送金币','1','1000000.0');
INSERT INTO ConstDesc (type_name,id,value) VALUES('玩家初始头像','2','1,2,3,4,5,6,7,8,9,10,11');
INSERT INTO ConstDesc (type_name,id,value) VALUES('玩家初始银行密码','3','8888.0');
