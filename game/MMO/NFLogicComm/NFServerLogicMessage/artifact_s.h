#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "artifact.pb.h"
#include "artifact_s.h"

namespace proto_ff_s {

	struct artifactartifactattributeDesc_s : public NFDescStoreSeqOP {
		artifactartifactattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::artifactartifactattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::artifactartifactattributeDesc & msg);
		static ::proto_ff::artifactartifactattributeDesc* new_pbmsg(){ return new ::proto_ff::artifactartifactattributeDesc(); }
		static ::proto_ff::artifactartifactattributeDesc make_pbmsg(){ return ::proto_ff::artifactartifactattributeDesc(); }
	};
	typedef struct artifactartifactattributeDesc_s artifactartifactattributeDesc_t;

	struct artifactartifact_s : public NFDescStoreSeqOP {
		artifactartifact_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> resource;
		NFSizeString<32> previewRes;
		int32_t professionID;
		NFSizeString<32> name;
		NFSizeString<72> activeDesc;
		int32_t quality;
		int64_t starId;
		NFSizeString<151> starNum;
		int32_t starUp;
		int32_t starBer;
		int64_t skill;
		NFSizeString<79> skillUi;
		int32_t artifactType;
		NFArray<struct artifactartifactattributeDesc_s, 5> attribute;

		virtual void write_to_pbmsg(::proto_ff::artifactartifact & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::artifactartifact & msg);
		static ::proto_ff::artifactartifact* new_pbmsg(){ return new ::proto_ff::artifactartifact(); }
		static ::proto_ff::artifactartifact make_pbmsg(){ return ::proto_ff::artifactartifact(); }
	};
	typedef struct artifactartifact_s artifactartifact_t;

	struct Sheet_artifactartifact_s : public NFDescStoreSeqOP {
		Sheet_artifactartifact_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct artifactartifact_s, 128> artifactartifact_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_artifactartifact & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_artifactartifact & msg);
		static ::proto_ff::Sheet_artifactartifact* new_pbmsg(){ return new ::proto_ff::Sheet_artifactartifact(); }
		static ::proto_ff::Sheet_artifactartifact make_pbmsg(){ return ::proto_ff::Sheet_artifactartifact(); }
	};
	typedef struct Sheet_artifactartifact_s Sheet_artifactartifact_t;

}

