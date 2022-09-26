#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "GMCommand.pb.h"
#include "GMCommand_s.h"

namespace proto_ff_s {

	struct GMCommandGMCommand_s : public NFDescStoreSeqOP {
		GMCommandGMCommand_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		NFSizeString<35> Key;
		int32_t ParamCount;
		NFSizeString<43> Des;

		virtual void write_to_pbmsg(::proto_ff::GMCommandGMCommand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMCommandGMCommand & msg);
		static ::proto_ff::GMCommandGMCommand* new_pbmsg(){ return new ::proto_ff::GMCommandGMCommand(); }
		static ::proto_ff::GMCommandGMCommand make_pbmsg(){ return ::proto_ff::GMCommandGMCommand(); }
	};
	typedef struct GMCommandGMCommand_s GMCommandGMCommand_t;

	struct Sheet_GMCommandGMCommand_s : public NFDescStoreSeqOP {
		Sheet_GMCommandGMCommand_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMCommandGMCommand_s, 150> GMCommandGMCommand_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMCommandGMCommand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMCommandGMCommand & msg);
		static ::proto_ff::Sheet_GMCommandGMCommand* new_pbmsg(){ return new ::proto_ff::Sheet_GMCommandGMCommand(); }
		static ::proto_ff::Sheet_GMCommandGMCommand make_pbmsg(){ return ::proto_ff::Sheet_GMCommandGMCommand(); }
	};
	typedef struct Sheet_GMCommandGMCommand_s Sheet_GMCommandGMCommand_t;

}

