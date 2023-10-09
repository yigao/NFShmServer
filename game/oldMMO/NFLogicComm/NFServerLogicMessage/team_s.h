#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "team.pb.h"
#include "team_s.h"

#define DEFINE_SHEET_TEAMTEAM_E_TEAMTEAM_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_TeamTeam_s : public NFDescStoreSeqOP {
		E_TeamTeam_s();
		virtual ~E_TeamTeam_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_teamobjectid;
		int32_t m_fobjectnameid;
		int32_t m_sobjectnameid;
		int64_t m_duplicateid;
		int64_t m_activityid;
		int32_t m_lowlv;
		int32_t m_uplv;
		int32_t m_isautomatch;
		int32_t m_speakchannel;
		int32_t m_teamnumber;

		virtual void write_to_pbmsg(::proto_ff::E_TeamTeam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TeamTeam & msg);
		static ::proto_ff::E_TeamTeam* new_pbmsg(){ return new ::proto_ff::E_TeamTeam(); }
		static ::proto_ff::E_TeamTeam make_pbmsg(){ return ::proto_ff::E_TeamTeam(); }
	};
	typedef struct E_TeamTeam_s E_TeamTeam_t;

	struct Sheet_TeamTeam_s : public NFDescStoreSeqOP {
		Sheet_TeamTeam_s();
		virtual ~Sheet_TeamTeam_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TeamTeam_s, DEFINE_SHEET_TEAMTEAM_E_TEAMTEAM_LIST_MAX_NUM> E_TeamTeam_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TeamTeam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TeamTeam & msg);
		static ::proto_ff::Sheet_TeamTeam* new_pbmsg(){ return new ::proto_ff::Sheet_TeamTeam(); }
		static ::proto_ff::Sheet_TeamTeam make_pbmsg(){ return ::proto_ff::Sheet_TeamTeam(); }
	};
	typedef struct Sheet_TeamTeam_s Sheet_TeamTeam_t;

}

