CREATE TABLE IF NOT EXISTS tbUserSimpleData (
 userid BIGINT UNSIGNED NOT NULL COMMENT "用户ID" ,
 nickname VARCHAR(64) COMMENT "昵称" ,
 face INT UNSIGNED COMMENT "头像" ,
 gender INT UNSIGNED COMMENT "性别" ,
 age INT UNSIGNED COMMENT "年龄" ,
 agentid BIGINT UNSIGNED COMMENT "上级代理ID" ,
 create_time BIGINT UNSIGNED COMMENT "注册时间" ,
 is_robot BOOL COMMENT "机器人:0=否,1=是" ,
 agent_level INT UNSIGNED COMMENT "代理:0=普通代理,1=总代,2=一级代理,3=二级代理,4=三级代理" ,
 ach_day BIGINT UNSIGNED COMMENT "今日流水" ,
 ach_week BIGINT UNSIGNED COMMENT "周流水" ,
 ach_month BIGINT UNSIGNED COMMENT "月流水" ,
 ach_all BIGINT UNSIGNED COMMENT "总流水" ,
 ach_team_day BIGINT UNSIGNED COMMENT "今日团队流水" ,
 ach_team_week BIGINT UNSIGNED COMMENT "周团队流水" ,
 ach_team_month BIGINT UNSIGNED COMMENT "月团队流水" ,
 ach_team_all BIGINT UNSIGNED COMMENT "总团队流水" ,
 team_user_num BIGINT UNSIGNED COMMENT "团队人数" ,
 new_user_day BIGINT UNSIGNED COMMENT "每日新增团队人数" ,
 activity_user_day BIGINT UNSIGNED COMMENT "团队活跃人数" ,
 getrate INT UNSIGNED COMMENT "流水保底" ,
 tax_getrate INT UNSIGNED COMMENT "税收保底" ,
 takemoney INT UNSIGNED COMMENT "可提现佣金余额" ,
 tax_takemoney INT UNSIGNED COMMENT "可提现税收佣金余额" ,
 all_takemoney BIGINT UNSIGNED COMMENT "佣金总额" ,
 all_fee BIGINT UNSIGNED COMMENT "抽水总额" ,
 show_userid BIGINT UNSIGNED COMMENT "代理靓号" ,
 vip_level BIGINT UNSIGNED COMMENT "vip" ,
 misc_data BLOB /*!99104 COMPRESSED */ ,
 INDEX(nickname),
 INDEX(agentid),
 PRIMARY KEY(userid))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbUserSimpleData add column userid BIGINT UNSIGNED NOT NULL COMMENT "用户ID";
alter table tbUserSimpleData add column nickname VARCHAR(64) COMMENT "昵称";
alter table tbUserSimpleData add column face INT UNSIGNED COMMENT "头像";
alter table tbUserSimpleData add column gender INT UNSIGNED COMMENT "性别";
alter table tbUserSimpleData add column age INT UNSIGNED COMMENT "年龄";
alter table tbUserSimpleData add column agentid BIGINT UNSIGNED COMMENT "上级代理ID";
alter table tbUserSimpleData add column create_time BIGINT UNSIGNED COMMENT "注册时间";
alter table tbUserSimpleData add column is_robot BOOL COMMENT "机器人:0=否,1=是";
alter table tbUserSimpleData add column agent_level INT UNSIGNED COMMENT "代理:0=普通代理,1=总代,2=一级代理,3=二级代理,4=三级代理";
alter table tbUserSimpleData add column ach_day BIGINT UNSIGNED COMMENT "今日流水";
alter table tbUserSimpleData add column ach_week BIGINT UNSIGNED COMMENT "周流水";
alter table tbUserSimpleData add column ach_month BIGINT UNSIGNED COMMENT "月流水";
alter table tbUserSimpleData add column ach_all BIGINT UNSIGNED COMMENT "总流水";
alter table tbUserSimpleData add column ach_team_day BIGINT UNSIGNED COMMENT "今日团队流水";
alter table tbUserSimpleData add column ach_team_week BIGINT UNSIGNED COMMENT "周团队流水";
alter table tbUserSimpleData add column ach_team_month BIGINT UNSIGNED COMMENT "月团队流水";
alter table tbUserSimpleData add column ach_team_all BIGINT UNSIGNED COMMENT "总团队流水";
alter table tbUserSimpleData add column team_user_num BIGINT UNSIGNED COMMENT "团队人数";
alter table tbUserSimpleData add column new_user_day BIGINT UNSIGNED COMMENT "每日新增团队人数";
alter table tbUserSimpleData add column activity_user_day BIGINT UNSIGNED COMMENT "团队活跃人数";
alter table tbUserSimpleData add column getrate INT UNSIGNED COMMENT "流水保底";
alter table tbUserSimpleData add column tax_getrate INT UNSIGNED COMMENT "税收保底";
alter table tbUserSimpleData add column takemoney INT UNSIGNED COMMENT "可提现佣金余额";
alter table tbUserSimpleData add column tax_takemoney INT UNSIGNED COMMENT "可提现税收佣金余额";
alter table tbUserSimpleData add column all_takemoney BIGINT UNSIGNED COMMENT "佣金总额";
alter table tbUserSimpleData add column all_fee BIGINT UNSIGNED COMMENT "抽水总额";
alter table tbUserSimpleData add column show_userid BIGINT UNSIGNED COMMENT "代理靓号";
alter table tbUserSimpleData add column vip_level BIGINT UNSIGNED COMMENT "vip";
alter table tbUserSimpleData add column misc_data BLOB ;
*/
