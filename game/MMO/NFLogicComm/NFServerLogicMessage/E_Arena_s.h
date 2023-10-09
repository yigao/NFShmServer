#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Arena.pb.h"
#include "E_Arena_s.h"

#define DEFINE_E_ARENAROBOT_M_ATTR_MAX_NUM 70
#define DEFINE_SHEET_ARENAROBOT_E_ARENAROBOT_LIST_MAX_NUM 8192
#define DEFINE_E_ARENAROBOTFACADE_M_FACADE_MAX_NUM 17
#define DEFINE_SHEET_ARENAROBOTFACADE_E_ARENAROBOTFACADE_LIST_MAX_NUM 2
#define DEFINE_E_ARENAARENAWARD_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_ARENAARENAWARD_E_ARENAARENAWARD_LIST_MAX_NUM 2048
#define DEFINE_E_ARENARANKAWARD_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_ARENARANKAWARD_E_ARENARANKAWARD_LIST_MAX_NUM 8
#define DEFINE_E_ARENAFIRSTRANK_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_ARENAFIRSTRANK_E_ARENAFIRSTRANK_LIST_MAX_NUM 16
#define DEFINE_SHEET_ARENABUYCHALLENGE_E_ARENABUYCHALLENGE_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_ArenaRobotAttrDesc_s : public NFDescStoreSeqOP {
		E_ArenaRobotAttrDesc_s();
		virtual ~E_ArenaRobotAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_val;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRobotAttrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRobotAttrDesc & msg);
		static ::proto_ff::E_ArenaRobotAttrDesc* new_pbmsg(){ return new ::proto_ff::E_ArenaRobotAttrDesc(); }
		static ::proto_ff::E_ArenaRobotAttrDesc make_pbmsg(){ return ::proto_ff::E_ArenaRobotAttrDesc(); }
	};
	typedef struct E_ArenaRobotAttrDesc_s E_ArenaRobotAttrDesc_t;

	struct E_ArenaRobot_s : public NFDescStoreSeqOP {
		E_ArenaRobot_s();
		virtual ~E_ArenaRobot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_arenaid;//竞技场排名ID
		NFShmString<64> m_robotname;//机器人名称
		int32_t m_aiid;//aiID
		int32_t m_rankid;//排名id
		int32_t m_robotprofession;//机器人职业
		int32_t m_robotlv;//机器人等级
		int32_t m_sword;//战力
		int32_t m_facadeid;//外观ID
		int32_t m_occupationid;//转职ID
		NFShmVector<struct E_ArenaRobotAttrDesc_s, DEFINE_E_ARENAROBOT_M_ATTR_MAX_NUM> m_attr;//属性

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRobot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRobot & msg);
		static ::proto_ff::E_ArenaRobot* new_pbmsg(){ return new ::proto_ff::E_ArenaRobot(); }
		static ::proto_ff::E_ArenaRobot make_pbmsg(){ return ::proto_ff::E_ArenaRobot(); }
	};
	typedef struct E_ArenaRobot_s E_ArenaRobot_t;

	struct Sheet_ArenaRobot_s : public NFDescStoreSeqOP {
		Sheet_ArenaRobot_s();
		virtual ~Sheet_ArenaRobot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaRobot_s, DEFINE_SHEET_ARENAROBOT_E_ARENAROBOT_LIST_MAX_NUM> E_ArenaRobot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaRobot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaRobot & msg);
		static ::proto_ff::Sheet_ArenaRobot* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaRobot(); }
		static ::proto_ff::Sheet_ArenaRobot make_pbmsg(){ return ::proto_ff::Sheet_ArenaRobot(); }
	};
	typedef struct Sheet_ArenaRobot_s Sheet_ArenaRobot_t;

	struct E_ArenaRobotfacadeFacadeDesc_s : public NFDescStoreSeqOP {
		E_ArenaRobotfacadeFacadeDesc_s();
		virtual ~E_ArenaRobotfacadeFacadeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRobotfacadeFacadeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRobotfacadeFacadeDesc & msg);
		static ::proto_ff::E_ArenaRobotfacadeFacadeDesc* new_pbmsg(){ return new ::proto_ff::E_ArenaRobotfacadeFacadeDesc(); }
		static ::proto_ff::E_ArenaRobotfacadeFacadeDesc make_pbmsg(){ return ::proto_ff::E_ArenaRobotfacadeFacadeDesc(); }
	};
	typedef struct E_ArenaRobotfacadeFacadeDesc_s E_ArenaRobotfacadeFacadeDesc_t;

	struct E_ArenaRobotfacade_s : public NFDescStoreSeqOP {
		E_ArenaRobotfacade_s();
		virtual ~E_ArenaRobotfacade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_color;//创建颜色
		NFShmVector<struct E_ArenaRobotfacadeFacadeDesc_s, DEFINE_E_ARENAROBOTFACADE_M_FACADE_MAX_NUM> m_facade;//外观

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRobotfacade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRobotfacade & msg);
		static ::proto_ff::E_ArenaRobotfacade* new_pbmsg(){ return new ::proto_ff::E_ArenaRobotfacade(); }
		static ::proto_ff::E_ArenaRobotfacade make_pbmsg(){ return ::proto_ff::E_ArenaRobotfacade(); }
	};
	typedef struct E_ArenaRobotfacade_s E_ArenaRobotfacade_t;

	struct Sheet_ArenaRobotfacade_s : public NFDescStoreSeqOP {
		Sheet_ArenaRobotfacade_s();
		virtual ~Sheet_ArenaRobotfacade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaRobotfacade_s, DEFINE_SHEET_ARENAROBOTFACADE_E_ARENAROBOTFACADE_LIST_MAX_NUM> E_ArenaRobotfacade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaRobotfacade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaRobotfacade & msg);
		static ::proto_ff::Sheet_ArenaRobotfacade* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaRobotfacade(); }
		static ::proto_ff::Sheet_ArenaRobotfacade make_pbmsg(){ return ::proto_ff::Sheet_ArenaRobotfacade(); }
	};
	typedef struct Sheet_ArenaRobotfacade_s Sheet_ArenaRobotfacade_t;

	struct E_ArenaArenawardRewardDesc_s : public NFDescStoreSeqOP {
		E_ArenaArenawardRewardDesc_s();
		virtual ~E_ArenaArenawardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_ArenaArenawardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaArenawardRewardDesc & msg);
		static ::proto_ff::E_ArenaArenawardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ArenaArenawardRewardDesc(); }
		static ::proto_ff::E_ArenaArenawardRewardDesc make_pbmsg(){ return ::proto_ff::E_ArenaArenawardRewardDesc(); }
	};
	typedef struct E_ArenaArenawardRewardDesc_s E_ArenaArenawardRewardDesc_t;

	struct E_ArenaArenaward_s : public NFDescStoreSeqOP {
		E_ArenaArenaward_s();
		virtual ~E_ArenaArenaward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvdown;//下限等级
		int32_t m_lvup;//上限等级
		NFShmVector<struct E_ArenaArenawardRewardDesc_s, DEFINE_E_ARENAARENAWARD_M_REWARD_MAX_NUM> m_reward;//奖励物品

		virtual void write_to_pbmsg(::proto_ff::E_ArenaArenaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaArenaward & msg);
		static ::proto_ff::E_ArenaArenaward* new_pbmsg(){ return new ::proto_ff::E_ArenaArenaward(); }
		static ::proto_ff::E_ArenaArenaward make_pbmsg(){ return ::proto_ff::E_ArenaArenaward(); }
	};
	typedef struct E_ArenaArenaward_s E_ArenaArenaward_t;

	struct Sheet_ArenaArenaward_s : public NFDescStoreSeqOP {
		Sheet_ArenaArenaward_s();
		virtual ~Sheet_ArenaArenaward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaArenaward_s, DEFINE_SHEET_ARENAARENAWARD_E_ARENAARENAWARD_LIST_MAX_NUM> E_ArenaArenaward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaArenaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaArenaward & msg);
		static ::proto_ff::Sheet_ArenaArenaward* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaArenaward(); }
		static ::proto_ff::Sheet_ArenaArenaward make_pbmsg(){ return ::proto_ff::Sheet_ArenaArenaward(); }
	};
	typedef struct Sheet_ArenaArenaward_s Sheet_ArenaArenaward_t;

	struct E_ArenaRankawardRewardDesc_s : public NFDescStoreSeqOP {
		E_ArenaRankawardRewardDesc_s();
		virtual ~E_ArenaRankawardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRankawardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRankawardRewardDesc & msg);
		static ::proto_ff::E_ArenaRankawardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ArenaRankawardRewardDesc(); }
		static ::proto_ff::E_ArenaRankawardRewardDesc make_pbmsg(){ return ::proto_ff::E_ArenaRankawardRewardDesc(); }
	};
	typedef struct E_ArenaRankawardRewardDesc_s E_ArenaRankawardRewardDesc_t;

	struct E_ArenaRankaward_s : public NFDescStoreSeqOP {
		E_ArenaRankaward_s();
		virtual ~E_ArenaRankaward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_prizeid;//奖励ID
		int32_t m_arenadown;//下限排名
		int32_t m_arenaup;//上限排名
		NFShmVector<struct E_ArenaRankawardRewardDesc_s, DEFINE_E_ARENARANKAWARD_M_REWARD_MAX_NUM> m_reward;//奖励物品

		virtual void write_to_pbmsg(::proto_ff::E_ArenaRankaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaRankaward & msg);
		static ::proto_ff::E_ArenaRankaward* new_pbmsg(){ return new ::proto_ff::E_ArenaRankaward(); }
		static ::proto_ff::E_ArenaRankaward make_pbmsg(){ return ::proto_ff::E_ArenaRankaward(); }
	};
	typedef struct E_ArenaRankaward_s E_ArenaRankaward_t;

	struct Sheet_ArenaRankaward_s : public NFDescStoreSeqOP {
		Sheet_ArenaRankaward_s();
		virtual ~Sheet_ArenaRankaward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaRankaward_s, DEFINE_SHEET_ARENARANKAWARD_E_ARENARANKAWARD_LIST_MAX_NUM> E_ArenaRankaward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaRankaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaRankaward & msg);
		static ::proto_ff::Sheet_ArenaRankaward* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaRankaward(); }
		static ::proto_ff::Sheet_ArenaRankaward make_pbmsg(){ return ::proto_ff::Sheet_ArenaRankaward(); }
	};
	typedef struct Sheet_ArenaRankaward_s Sheet_ArenaRankaward_t;

	struct E_ArenaFirstrankRewardDesc_s : public NFDescStoreSeqOP {
		E_ArenaFirstrankRewardDesc_s();
		virtual ~E_ArenaFirstrankRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_ArenaFirstrankRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaFirstrankRewardDesc & msg);
		static ::proto_ff::E_ArenaFirstrankRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ArenaFirstrankRewardDesc(); }
		static ::proto_ff::E_ArenaFirstrankRewardDesc make_pbmsg(){ return ::proto_ff::E_ArenaFirstrankRewardDesc(); }
	};
	typedef struct E_ArenaFirstrankRewardDesc_s E_ArenaFirstrankRewardDesc_t;

	struct E_ArenaFirstrank_s : public NFDescStoreSeqOP {
		E_ArenaFirstrank_s();
		virtual ~E_ArenaFirstrank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_rankdown;//下限排名
		int32_t m_rankup;//上限排名
		NFShmVector<struct E_ArenaFirstrankRewardDesc_s, DEFINE_E_ARENAFIRSTRANK_M_REWARD_MAX_NUM> m_reward;//奖励物品

		virtual void write_to_pbmsg(::proto_ff::E_ArenaFirstrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaFirstrank & msg);
		static ::proto_ff::E_ArenaFirstrank* new_pbmsg(){ return new ::proto_ff::E_ArenaFirstrank(); }
		static ::proto_ff::E_ArenaFirstrank make_pbmsg(){ return ::proto_ff::E_ArenaFirstrank(); }
	};
	typedef struct E_ArenaFirstrank_s E_ArenaFirstrank_t;

	struct Sheet_ArenaFirstrank_s : public NFDescStoreSeqOP {
		Sheet_ArenaFirstrank_s();
		virtual ~Sheet_ArenaFirstrank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaFirstrank_s, DEFINE_SHEET_ARENAFIRSTRANK_E_ARENAFIRSTRANK_LIST_MAX_NUM> E_ArenaFirstrank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaFirstrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaFirstrank & msg);
		static ::proto_ff::Sheet_ArenaFirstrank* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaFirstrank(); }
		static ::proto_ff::Sheet_ArenaFirstrank make_pbmsg(){ return ::proto_ff::Sheet_ArenaFirstrank(); }
	};
	typedef struct Sheet_ArenaFirstrank_s Sheet_ArenaFirstrank_t;

	struct E_ArenaBuychallenge_s : public NFDescStoreSeqOP {
		E_ArenaBuychallenge_s();
		virtual ~E_ArenaBuychallenge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_count;//购买计次
		int32_t m_costtype;//花费类型
		int32_t m_cost;//花费

		virtual void write_to_pbmsg(::proto_ff::E_ArenaBuychallenge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ArenaBuychallenge & msg);
		static ::proto_ff::E_ArenaBuychallenge* new_pbmsg(){ return new ::proto_ff::E_ArenaBuychallenge(); }
		static ::proto_ff::E_ArenaBuychallenge make_pbmsg(){ return ::proto_ff::E_ArenaBuychallenge(); }
	};
	typedef struct E_ArenaBuychallenge_s E_ArenaBuychallenge_t;

	struct Sheet_ArenaBuychallenge_s : public NFDescStoreSeqOP {
		Sheet_ArenaBuychallenge_s();
		virtual ~Sheet_ArenaBuychallenge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ArenaBuychallenge_s, DEFINE_SHEET_ARENABUYCHALLENGE_E_ARENABUYCHALLENGE_LIST_MAX_NUM> E_ArenaBuychallenge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaBuychallenge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaBuychallenge & msg);
		static ::proto_ff::Sheet_ArenaBuychallenge* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaBuychallenge(); }
		static ::proto_ff::Sheet_ArenaBuychallenge make_pbmsg(){ return ::proto_ff::Sheet_ArenaBuychallenge(); }
	};
	typedef struct Sheet_ArenaBuychallenge_s Sheet_ArenaBuychallenge_t;

}

