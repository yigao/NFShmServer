#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "team.pb.h"
#include "team_s.h"

namespace proto_ff_s {

	struct teamteam_s : public NFDescStoreSeqOP {
		teamteam_s();
		int CreateInit();
		int ResumeInit();
		int32_t TeamObjectID;
		int32_t FObjectNameID;
		int32_t SObjectNameID;
		int64_t duplicateId;
		int64_t activityId;
		int32_t LowLV;
		int32_t UpLV;
		int32_t isAutoMatch;
		int32_t speakChannel;
		int32_t teamnumber;

		virtual void write_to_pbmsg(::proto_ff::teamteam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::teamteam & msg);
		static ::proto_ff::teamteam* new_pbmsg(){ return new ::proto_ff::teamteam(); }
		static ::proto_ff::teamteam make_pbmsg(){ return ::proto_ff::teamteam(); }
	};
	typedef struct teamteam_s teamteam_t;

	struct Sheet_teamteam_s : public NFDescStoreSeqOP {
		Sheet_teamteam_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct teamteam_s, 40> teamteam_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_teamteam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_teamteam & msg);
		static ::proto_ff::Sheet_teamteam* new_pbmsg(){ return new ::proto_ff::Sheet_teamteam(); }
		static ::proto_ff::Sheet_teamteam make_pbmsg(){ return ::proto_ff::Sheet_teamteam(); }
	};
	typedef struct Sheet_teamteam_s Sheet_teamteam_t;

}

