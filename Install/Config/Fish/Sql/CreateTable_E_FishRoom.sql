CREATE TABLE IF NOT EXISTS E_FishRoom ( m_id int  NOT NULL  COMMENT "唯一ID", PRIMARY KEY(m_id)) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

alter table E_FishRoom add column m_roomid int  COMMENT "房间ID";
alter table E_FishRoom add INDEX m_roomid (m_roomid);
alter table E_FishRoom add column m_gameid int  COMMENT "游戏ID";
alter table E_FishRoom add INDEX m_gameid (m_gameid);
alter table E_FishRoom add column m_gamename varchar(64)  COMMENT "游戏名";
alter table E_FishRoom add column m_roomtype int  COMMENT "房间类型";
alter table E_FishRoom add column m_roomlevel int  COMMENT "房间等级";
alter table E_FishRoom add column m_roomname varchar(64)  COMMENT "房间名";
alter table E_FishRoom add column m_sitenum int  COMMENT "座位数";
alter table E_FishRoom add column m_deskcount int  COMMENT "桌子数";
alter table E_FishRoom add column m_maxpeople int  COMMENT "最大玩家数";
alter table E_FishRoom add column m_entermin int  COMMENT "最小筹码";
alter table E_FishRoom add column m_entermax int  COMMENT "最大筹码";
alter table E_FishRoom add column m_autochair int  COMMENT "选位置";
alter table E_FishRoom add column m_isexpscene int  COMMENT "体验场";
alter table E_FishRoom add column m_expscenegold int  COMMENT "体验场金币";
alter table E_FishRoom add column m_tax int  COMMENT "抽水率";


replace into E_FishRoom(m_id,m_roomid,m_gameid,m_gamename,m_roomtype,m_roomlevel,m_roomname,m_sitenum,m_deskcount,m_maxpeople,m_entermin,m_entermax,m_autochair,m_isexpscene,m_expscenegold,m_tax) values ("1","1","2004","大闹天空2","1","1","体验场","4","255","10","0","1000000","0","1","100000","0");
replace into E_FishRoom(m_id,m_roomid,m_gameid,m_gamename,m_roomtype,m_roomlevel,m_roomname,m_sitenum,m_deskcount,m_maxpeople,m_entermin,m_entermax,m_autochair,m_isexpscene,m_expscenegold,m_tax) values ("2","2","2004","大闹天空2","1","1","初级场","4","255","10","0","1000000","0","0","0","0");
replace into E_FishRoom(m_id,m_roomid,m_gameid,m_gamename,m_roomtype,m_roomlevel,m_roomname,m_sitenum,m_deskcount,m_maxpeople,m_entermin,m_entermax,m_autochair,m_isexpscene,m_expscenegold,m_tax) values ("3","3","2004","大闹天空2","1","1","中级场","4","255","10","0","1000000","0","0","0","0");
replace into E_FishRoom(m_id,m_roomid,m_gameid,m_gamename,m_roomtype,m_roomlevel,m_roomname,m_sitenum,m_deskcount,m_maxpeople,m_entermin,m_entermax,m_autochair,m_isexpscene,m_expscenegold,m_tax) values ("4","4","2004","大闹天空2","1","1","高级场","4","255","10","0","1000000","0","0","0","0");
