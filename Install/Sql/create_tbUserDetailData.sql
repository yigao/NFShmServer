CREATE TABLE IF NOT EXISTS tbUserDetailData (
 userid BIGINT UNSIGNED NOT NULL COMMENT "玩家ID" ,
 nickname VARCHAR(64) COMMENT "昵称" ,
 faceid INT UNSIGNED COMMENT "头像" ,
 regdate BIGINT UNSIGNED COMMENT "注册时间" ,
 gender INT UNSIGNED COMMENT "性别" ,
 age INT UNSIGNED COMMENT "年龄" ,
 email VARCHAR(64) COMMENT "邮件" ,
 phonenum BIGINT UNSIGNED COMMENT "手机号码" ,
 jetton BIGINT UNSIGNED COMMENT "金币" ,
 country VARCHAR(64) COMMENT "国家" ,
 province VARCHAR(64) COMMENT "省份" ,
 city VARCHAR(64) COMMENT "城市" ,
 isrobot BOOL COMMENT "机器人:0=否,1=是" ,
 bank_password VARCHAR(64) ,
 bank_jetton BIGINT UNSIGNED COMMENT "银行存款" ,
 ip VARCHAR(64) COMMENT "IP地址" ,
 last_login_time BIGINT UNSIGNED COMMENT "最近一次登录时间" ,
 last_logout_time BIGINT UNSIGNED COMMENT "最近一次退出时间" ,
 aread_id INT UNSIGNED COMMENT "地区id" ,
 channel_id INT UNSIGNED COMMENT "渠道id" ,
 platform_os VARCHAR(64) COMMENT "手机系统" ,
 phone_model VARCHAR(64) COMMENT "手机型号" ,
 first_recharge BOOL COMMENT "首冲:0=否,1=是" ,
 agent_id BIGINT UNSIGNED COMMENT "上级代理ID" ,
 referrer_id BIGINT UNSIGNED ,
 vip_level INT UNSIGNED ,
 misc_data BLOB /*!99104 COMPRESSED */ ,
 online BOOL COMMENT "在线:0=否,1=是" ,
 game_id INT UNSIGNED COMMENT "游戏ID:1001=水果玛丽,1002=幸运转轮,1003=水浒传,1004=鼠来宝,1005=福星高照,2001=大闹天空2,2002=大闹天空,2003=欢乐捕鱼3D,2004=海王" ,
 room_id INT UNSIGNED COMMENT "房间ID:1=体验场,2=初级场,3=普通场,4=中级场,5=高级场" ,
 all_win BIGINT COMMENT "总输赢" ,
 all_recharge BIGINT UNSIGNED COMMENT "总付费" ,
 all_give BIGINT UNSIGNED COMMENT "总赠送" ,
 all_draw BIGINT UNSIGNED COMMENT "总出款" ,
 today_win BIGINT COMMENT "今日输赢" ,
 today_recharge BIGINT UNSIGNED COMMENT "今日付费" ,
 today_give BIGINT UNSIGNED COMMENT "今日赠送" ,
 today_draw BIGINT UNSIGNED COMMENT "今日出款" ,
 week_win BIGINT COMMENT "周输赢" ,
 week_recharge BIGINT UNSIGNED COMMENT "周付费" ,
 week_give BIGINT UNSIGNED COMMENT "周赠送" ,
 week_draw BIGINT UNSIGNED COMMENT "周出款" ,
 month_win BIGINT COMMENT "月输赢" ,
 month_recharge BIGINT UNSIGNED COMMENT "月付费" ,
 month_give BIGINT UNSIGNED COMMENT "月赠送" ,
 month_draw BIGINT UNSIGNED COMMENT "月出款" ,
 is_ban INT UNSIGNED COMMENT "封号:0=正常,1=封号" ,
 no_transfer INT UNSIGNED COMMENT "转账:0=正常,1=禁止" ,
 reg_ip VARCHAR(64) COMMENT "注册IP地址" ,
 device_id VARCHAR(128) COMMENT "机器码" ,
 reg_device_id VARCHAR(128) COMMENT "注册机器码" ,
 show_userid BIGINT UNSIGNED COMMENT "显示玩家ID" ,
 all_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP总转入" ,
 today_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP今日转入" ,
 week_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP周转入" ,
 month_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP月转入" ,
 all_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP总转出" ,
 today_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP今日转出" ,
 week_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP周转出" ,
 month_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP月转出" ,
 INDEX(nickname),
 INDEX(agent_id),
 INDEX(game_id),
 INDEX(room_id),
 INDEX(all_win),
 INDEX(show_userid),
 PRIMARY KEY(userid))  ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*
alter table tbUserDetailData add column userid BIGINT UNSIGNED NOT NULL COMMENT "玩家ID";
alter table tbUserDetailData add column nickname VARCHAR(64) COMMENT "昵称";
alter table tbUserDetailData add column faceid INT UNSIGNED COMMENT "头像";
alter table tbUserDetailData add column regdate BIGINT UNSIGNED COMMENT "注册时间";
alter table tbUserDetailData add column gender INT UNSIGNED COMMENT "性别";
alter table tbUserDetailData add column age INT UNSIGNED COMMENT "年龄";
alter table tbUserDetailData add column email VARCHAR(64) COMMENT "邮件";
alter table tbUserDetailData add column phonenum BIGINT UNSIGNED COMMENT "手机号码";
alter table tbUserDetailData add column jetton BIGINT UNSIGNED COMMENT "金币";
alter table tbUserDetailData add column country VARCHAR(64) COMMENT "国家";
alter table tbUserDetailData add column province VARCHAR(64) COMMENT "省份";
alter table tbUserDetailData add column city VARCHAR(64) COMMENT "城市";
alter table tbUserDetailData add column isrobot BOOL COMMENT "机器人:0=否,1=是";
alter table tbUserDetailData add column bank_password VARCHAR(64);
alter table tbUserDetailData add column bank_jetton BIGINT UNSIGNED COMMENT "银行存款";
alter table tbUserDetailData add column ip VARCHAR(64) COMMENT "IP地址";
alter table tbUserDetailData add column last_login_time BIGINT UNSIGNED COMMENT "最近一次登录时间";
alter table tbUserDetailData add column last_logout_time BIGINT UNSIGNED COMMENT "最近一次退出时间";
alter table tbUserDetailData add column aread_id INT UNSIGNED COMMENT "地区id";
alter table tbUserDetailData add column channel_id INT UNSIGNED COMMENT "渠道id";
alter table tbUserDetailData add column platform_os VARCHAR(64) COMMENT "手机系统";
alter table tbUserDetailData add column phone_model VARCHAR(64) COMMENT "手机型号";
alter table tbUserDetailData add column first_recharge BOOL COMMENT "首冲:0=否,1=是";
alter table tbUserDetailData add column agent_id BIGINT UNSIGNED COMMENT "上级代理ID";
alter table tbUserDetailData add column referrer_id BIGINT UNSIGNED;
alter table tbUserDetailData add column vip_level INT UNSIGNED;
alter table tbUserDetailData add column misc_data BLOB ;
alter table tbUserDetailData add column online BOOL COMMENT "在线:0=否,1=是";
alter table tbUserDetailData add column game_id INT UNSIGNED COMMENT "游戏ID:1001=水果玛丽,1002=幸运转轮,1003=水浒传,1004=鼠来宝,1005=福星高照,2001=大闹天空2,2002=大闹天空,2003=欢乐捕鱼3D,2004=海王";
alter table tbUserDetailData add column room_id INT UNSIGNED COMMENT "房间ID:1=体验场,2=初级场,3=普通场,4=中级场,5=高级场";
alter table tbUserDetailData add column all_win BIGINT COMMENT "总输赢";
alter table tbUserDetailData add column all_recharge BIGINT UNSIGNED COMMENT "总付费";
alter table tbUserDetailData add column all_give BIGINT UNSIGNED COMMENT "总赠送";
alter table tbUserDetailData add column all_draw BIGINT UNSIGNED COMMENT "总出款";
alter table tbUserDetailData add column today_win BIGINT COMMENT "今日输赢";
alter table tbUserDetailData add column today_recharge BIGINT UNSIGNED COMMENT "今日付费";
alter table tbUserDetailData add column today_give BIGINT UNSIGNED COMMENT "今日赠送";
alter table tbUserDetailData add column today_draw BIGINT UNSIGNED COMMENT "今日出款";
alter table tbUserDetailData add column week_win BIGINT COMMENT "周输赢";
alter table tbUserDetailData add column week_recharge BIGINT UNSIGNED COMMENT "周付费";
alter table tbUserDetailData add column week_give BIGINT UNSIGNED COMMENT "周赠送";
alter table tbUserDetailData add column week_draw BIGINT UNSIGNED COMMENT "周出款";
alter table tbUserDetailData add column month_win BIGINT COMMENT "月输赢";
alter table tbUserDetailData add column month_recharge BIGINT UNSIGNED COMMENT "月付费";
alter table tbUserDetailData add column month_give BIGINT UNSIGNED COMMENT "月赠送";
alter table tbUserDetailData add column month_draw BIGINT UNSIGNED COMMENT "月出款";
alter table tbUserDetailData add column is_ban INT UNSIGNED COMMENT "封号:0=正常,1=封号";
alter table tbUserDetailData add column no_transfer INT UNSIGNED COMMENT "转账:0=正常,1=禁止";
alter table tbUserDetailData add column reg_ip VARCHAR(64) COMMENT "注册IP地址";
alter table tbUserDetailData add column device_id VARCHAR(128) COMMENT "机器码";
alter table tbUserDetailData add column reg_device_id VARCHAR(128) COMMENT "注册机器码";
alter table tbUserDetailData add column show_userid BIGINT UNSIGNED COMMENT "显示玩家ID";
alter table tbUserDetailData add column all_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP总转入";
alter table tbUserDetailData add column today_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP今日转入";
alter table tbUserDetailData add column week_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP周转入";
alter table tbUserDetailData add column month_vip_zhuanru BIGINT UNSIGNED COMMENT "VIP月转入";
alter table tbUserDetailData add column all_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP总转出";
alter table tbUserDetailData add column today_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP今日转出";
alter table tbUserDetailData add column week_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP周转出";
alter table tbUserDetailData add column month_vip_zhuanchu BIGINT UNSIGNED COMMENT "VIP月转出";
*/
