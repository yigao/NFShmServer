#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "dup.pb.h"
#include "dup_s.h"

namespace proto_ff_s {

	struct E_DupBplevel_s : public NFDescStoreSeqOP {
		E_DupBplevel_s();
		virtual ~E_DupBplevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		NFShmVector<int64_t, 5> m_bgdup;

		virtual void write_to_pbmsg(::proto_ff::E_DupBplevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupBplevel & msg);
		static ::proto_ff::E_DupBplevel* new_pbmsg(){ return new ::proto_ff::E_DupBplevel(); }
		static ::proto_ff::E_DupBplevel make_pbmsg(){ return ::proto_ff::E_DupBplevel(); }
	};
	typedef struct E_DupBplevel_s E_DupBplevel_t;

	struct Sheet_DupBplevel_s : public NFDescStoreSeqOP {
		Sheet_DupBplevel_s();
		virtual ~Sheet_DupBplevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupBplevel_s, 1100> E_DupBplevel_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupBplevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupBplevel & msg);
		static ::proto_ff::Sheet_DupBplevel* new_pbmsg(){ return new ::proto_ff::Sheet_DupBplevel(); }
		static ::proto_ff::Sheet_DupBplevel make_pbmsg(){ return ::proto_ff::Sheet_DupBplevel(); }
	};
	typedef struct Sheet_DupBplevel_s Sheet_DupBplevel_t;

	struct E_DupDup_s : public NFDescStoreSeqOP {
		E_DupDup_s();
		virtual ~E_DupDup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_scripid;
		int32_t m_scriptype;
		int32_t m_duplevel;
		int32_t m_groupid;
		int32_t m_layer;
		int32_t m_duplicatetype;
		int64_t m_mapid;
		int32_t m_levellimit;
		int32_t m_pre;
		int32_t m_isautofight;
		NFShmString<60> m_condition;
		int32_t m_revivemaxtimes;
		int32_t m_teamobjectid;
		NFShmString<60> m_gradecondition;
		int64_t m_sweeprewardboxid;
		int32_t m_sweeprewardexp;
		NFShmString<60> m_trackpoint;
		NFShmString<60> m_pathofmonster;
		int32_t m_ispatrol;
		int32_t m_sweeptype;
		NFShmVector<int32_t, 3> m_box;

		virtual void write_to_pbmsg(::proto_ff::E_DupDup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupDup & msg);
		static ::proto_ff::E_DupDup* new_pbmsg(){ return new ::proto_ff::E_DupDup(); }
		static ::proto_ff::E_DupDup make_pbmsg(){ return ::proto_ff::E_DupDup(); }
	};
	typedef struct E_DupDup_s E_DupDup_t;

	struct Sheet_DupDup_s : public NFDescStoreSeqOP {
		Sheet_DupDup_s();
		virtual ~Sheet_DupDup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupDup_s, 80> E_DupDup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupDup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupDup & msg);
		static ::proto_ff::Sheet_DupDup* new_pbmsg(){ return new ::proto_ff::Sheet_DupDup(); }
		static ::proto_ff::Sheet_DupDup make_pbmsg(){ return ::proto_ff::Sheet_DupDup(); }
	};
	typedef struct Sheet_DupDup_s Sheet_DupDup_t;

	struct E_DupTowerreward_s : public NFDescStoreSeqOP {
		E_DupTowerreward_s();
		virtual ~E_DupTowerreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_cond;
		int32_t m_boxid;

		virtual void write_to_pbmsg(::proto_ff::E_DupTowerreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupTowerreward & msg);
		static ::proto_ff::E_DupTowerreward* new_pbmsg(){ return new ::proto_ff::E_DupTowerreward(); }
		static ::proto_ff::E_DupTowerreward make_pbmsg(){ return ::proto_ff::E_DupTowerreward(); }
	};
	typedef struct E_DupTowerreward_s E_DupTowerreward_t;

	struct Sheet_DupTowerreward_s : public NFDescStoreSeqOP {
		Sheet_DupTowerreward_s();
		virtual ~Sheet_DupTowerreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupTowerreward_s, 20> E_DupTowerreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupTowerreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupTowerreward & msg);
		static ::proto_ff::Sheet_DupTowerreward* new_pbmsg(){ return new ::proto_ff::Sheet_DupTowerreward(); }
		static ::proto_ff::Sheet_DupTowerreward make_pbmsg(){ return ::proto_ff::Sheet_DupTowerreward(); }
	};
	typedef struct Sheet_DupTowerreward_s Sheet_DupTowerreward_t;

	struct E_DupGroup_s : public NFDescStoreSeqOP {
		E_DupGroup_s();
		virtual ~E_DupGroup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;
		int32_t m_privilegetype;
		int32_t m_dynamiclevel;
		int32_t m_grouptimestype;
		int32_t m_grouptimes;
		int32_t m_enteritemid;
		int32_t m_sweepcondition;
		int32_t m_mergecondition;
		int32_t m_additemid;
		int32_t m_buytype;
		int32_t m_buyitemid;
		NFShmString<60> m_buycost;
		int32_t m_countdown;
		int32_t m_enddown;
		int32_t m_accountdown;
		int32_t m_funcionid;

		virtual void write_to_pbmsg(::proto_ff::E_DupGroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupGroup & msg);
		static ::proto_ff::E_DupGroup* new_pbmsg(){ return new ::proto_ff::E_DupGroup(); }
		static ::proto_ff::E_DupGroup make_pbmsg(){ return ::proto_ff::E_DupGroup(); }
	};
	typedef struct E_DupGroup_s E_DupGroup_t;

	struct Sheet_DupGroup_s : public NFDescStoreSeqOP {
		Sheet_DupGroup_s();
		virtual ~Sheet_DupGroup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupGroup_s, 20> E_DupGroup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupGroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupGroup & msg);
		static ::proto_ff::Sheet_DupGroup* new_pbmsg(){ return new ::proto_ff::Sheet_DupGroup(); }
		static ::proto_ff::Sheet_DupGroup make_pbmsg(){ return ::proto_ff::Sheet_DupGroup(); }
	};
	typedef struct Sheet_DupGroup_s Sheet_DupGroup_t;

}

