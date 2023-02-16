#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "arena.pb.h"
#include "arena_s.h"

namespace proto_ff_s {

	struct E_ArenaRobotAttrDesc_s : public NFDescStoreSeqOP {
		E_ArenaRobotAttrDesc_s();
		virtual ~E_ArenaRobotAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_val;

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
		int32_t m_arenaid;
		NFShmString<60> m_robotname;
		int32_t m_aiid;
		int32_t m_rankid;
		int32_t m_robotprofession;
		int32_t m_robotlv;
		int32_t m_sword;
		int32_t m_facadeid;
		int32_t m_occupationid;
		NFShmVector<struct E_ArenaRobotAttrDesc_s, 70> m_attr;

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
		NFShmVector<struct E_ArenaRobot_s, 6000> E_ArenaRobot_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int32_t m_id;
		int32_t m_color;
		NFShmVector<struct E_ArenaRobotfacadeFacadeDesc_s, 17> m_facade;

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
		NFShmVector<struct E_ArenaRobotfacade_s, 20> E_ArenaRobotfacade_List;

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
		int32_t m_id;
		int32_t m_value;

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
		int32_t m_id;
		int32_t m_lvdown;
		int32_t m_lvup;
		NFShmVector<struct E_ArenaArenawardRewardDesc_s, 5> m_reward;

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
		NFShmVector<struct E_ArenaArenaward_s, 2000> E_ArenaArenaward_List;

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
		int32_t m_id;
		int32_t m_value;

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
		int32_t m_prizeid;
		int32_t m_arenadown;
		int32_t m_arenaup;
		NFShmVector<struct E_ArenaRankawardRewardDesc_s, 5> m_reward;

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
		NFShmVector<struct E_ArenaRankaward_s, 20> E_ArenaRankaward_List;

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
		int32_t m_id;
		int32_t m_value;

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
		int32_t m_id;
		int32_t m_rankdown;
		int32_t m_rankup;
		NFShmVector<struct E_ArenaFirstrankRewardDesc_s, 5> m_reward;

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
		NFShmVector<struct E_ArenaFirstrank_s, 20> E_ArenaFirstrank_List;

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
		int32_t m_count;
		int32_t m_costtype;
		int32_t m_cost;

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
		NFShmVector<struct E_ArenaBuychallenge_s, 20> E_ArenaBuychallenge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ArenaBuychallenge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ArenaBuychallenge & msg);
		static ::proto_ff::Sheet_ArenaBuychallenge* new_pbmsg(){ return new ::proto_ff::Sheet_ArenaBuychallenge(); }
		static ::proto_ff::Sheet_ArenaBuychallenge make_pbmsg(){ return ::proto_ff::Sheet_ArenaBuychallenge(); }
	};
	typedef struct Sheet_ArenaBuychallenge_s Sheet_ArenaBuychallenge_t;

}

