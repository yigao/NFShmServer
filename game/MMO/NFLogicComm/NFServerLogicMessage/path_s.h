#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "path.pb.h"
#include "path_s.h"

namespace proto_ff_s {

	struct pathpath_s : public NFDescStoreSeqOP {
		pathpath_s();
		virtual ~pathpath_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t belongToSceneID;

		virtual void write_to_pbmsg(::proto_ff::pathpath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pathpath & msg);
		static ::proto_ff::pathpath* new_pbmsg(){ return new ::proto_ff::pathpath(); }
		static ::proto_ff::pathpath make_pbmsg(){ return ::proto_ff::pathpath(); }
	};
	typedef struct pathpath_s pathpath_t;

	struct Sheet_pathpath_s : public NFDescStoreSeqOP {
		Sheet_pathpath_s();
		virtual ~Sheet_pathpath_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct pathpath_s, 20> pathpath_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_pathpath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_pathpath & msg);
		static ::proto_ff::Sheet_pathpath* new_pbmsg(){ return new ::proto_ff::Sheet_pathpath(); }
		static ::proto_ff::Sheet_pathpath make_pbmsg(){ return ::proto_ff::Sheet_pathpath(); }
	};
	typedef struct Sheet_pathpath_s Sheet_pathpath_t;

}

