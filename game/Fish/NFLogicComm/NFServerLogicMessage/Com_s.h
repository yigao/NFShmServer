#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

namespace proto_ff_s {

	struct EmptyMessage_s : public NFDescStoreSeqOP {
		EmptyMessage_s();
		virtual ~EmptyMessage_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::EmptyMessage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EmptyMessage & msg);
		static ::proto_ff::EmptyMessage* new_pbmsg(){ return new ::proto_ff::EmptyMessage(); }
		static ::proto_ff::EmptyMessage make_pbmsg(){ return ::proto_ff::EmptyMessage(); }
	};
	typedef struct EmptyMessage_s EmptyMessage_t;

	struct ComPair_s : public NFDescStoreSeqOP {
		ComPair_s();
		virtual ~ComPair_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t key;
		uint32_t value;

		virtual void write_to_pbmsg(::proto_ff::ComPair & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPair & msg);
		static ::proto_ff::ComPair* new_pbmsg(){ return new ::proto_ff::ComPair(); }
		static ::proto_ff::ComPair make_pbmsg(){ return ::proto_ff::ComPair(); }
	};
	typedef struct ComPair_s ComPair_t;

	struct ComPair64_s : public NFDescStoreSeqOP {
		ComPair64_s();
		virtual ~ComPair64_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t key;
		uint64_t value;

		virtual void write_to_pbmsg(::proto_ff::ComPair64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPair64 & msg);
		static ::proto_ff::ComPair64* new_pbmsg(){ return new ::proto_ff::ComPair64(); }
		static ::proto_ff::ComPair64 make_pbmsg(){ return ::proto_ff::ComPair64(); }
	};
	typedef struct ComPair64_s ComPair64_t;

	struct ComPairBool_s : public NFDescStoreSeqOP {
		ComPairBool_s();
		virtual ~ComPairBool_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t key;
		bool value;

		virtual void write_to_pbmsg(::proto_ff::ComPairBool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPairBool & msg);
		static ::proto_ff::ComPairBool* new_pbmsg(){ return new ::proto_ff::ComPairBool(); }
		static ::proto_ff::ComPairBool make_pbmsg(){ return ::proto_ff::ComPairBool(); }
	};
	typedef struct ComPairBool_s ComPairBool_t;

	struct ComItem_s : public NFDescStoreSeqOP {
		ComItem_s();
		virtual ~ComItem_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;
		uint64_t item_num;

		virtual void write_to_pbmsg(::proto_ff::ComItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComItem & msg);
		static ::proto_ff::ComItem* new_pbmsg(){ return new ::proto_ff::ComItem(); }
		static ::proto_ff::ComItem make_pbmsg(){ return ::proto_ff::ComItem(); }
	};
	typedef struct ComItem_s ComItem_t;

	struct ComItemWithType_s : public NFDescStoreSeqOP {
		ComItemWithType_s();
		virtual ~ComItemWithType_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;
		uint64_t item_num;
		uint32_t type;

		virtual void write_to_pbmsg(::proto_ff::ComItemWithType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComItemWithType & msg);
		static ::proto_ff::ComItemWithType* new_pbmsg(){ return new ::proto_ff::ComItemWithType(); }
		static ::proto_ff::ComItemWithType make_pbmsg(){ return ::proto_ff::ComItemWithType(); }
	};
	typedef struct ComItemWithType_s ComItemWithType_t;

	struct Vector3PB_s : public NFDescStoreSeqOP {
		Vector3PB_s();
		virtual ~Vector3PB_s(){}
		int CreateInit();
		int ResumeInit();
		float x;
		float y;
		float z;

		virtual void write_to_pbmsg(::proto_ff::Vector3PB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Vector3PB & msg);
		static ::proto_ff::Vector3PB* new_pbmsg(){ return new ::proto_ff::Vector3PB(); }
		static ::proto_ff::Vector3PB make_pbmsg(){ return ::proto_ff::Vector3PB(); }
	};
	typedef struct Vector3PB_s Vector3PB_t;

	struct Vector2PB_s : public NFDescStoreSeqOP {
		Vector2PB_s();
		virtual ~Vector2PB_s(){}
		int CreateInit();
		int ResumeInit();
		float x;
		float y;

		virtual void write_to_pbmsg(::proto_ff::Vector2PB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Vector2PB & msg);
		static ::proto_ff::Vector2PB* new_pbmsg(){ return new ::proto_ff::Vector2PB(); }
		static ::proto_ff::Vector2PB make_pbmsg(){ return ::proto_ff::Vector2PB(); }
	};
	typedef struct Vector2PB_s Vector2PB_t;

	struct Attr64_s : public NFDescStoreSeqOP {
		Attr64_s();
		virtual ~Attr64_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::Attr64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr64 & msg);
		static ::proto_ff::Attr64* new_pbmsg(){ return new ::proto_ff::Attr64(); }
		static ::proto_ff::Attr64 make_pbmsg(){ return ::proto_ff::Attr64(); }
	};
	typedef struct Attr64_s Attr64_t;

}

