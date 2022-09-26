#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "teleport.pb.h"
#include "teleport_s.h"

namespace proto_ff_s {

	struct teleportborn_s : public NFDescStoreSeqOP {
		teleportborn_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		int64_t scene;
		int32_t roleBornRange;

		virtual void write_to_pbmsg(::proto_ff::teleportborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::teleportborn & msg);
		static ::proto_ff::teleportborn* new_pbmsg(){ return new ::proto_ff::teleportborn(); }
		static ::proto_ff::teleportborn make_pbmsg(){ return ::proto_ff::teleportborn(); }
	};
	typedef struct teleportborn_s teleportborn_t;

	struct Sheet_teleportborn_s : public NFDescStoreSeqOP {
		Sheet_teleportborn_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct teleportborn_s, 300> teleportborn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_teleportborn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_teleportborn & msg);
		static ::proto_ff::Sheet_teleportborn* new_pbmsg(){ return new ::proto_ff::Sheet_teleportborn(); }
		static ::proto_ff::Sheet_teleportborn make_pbmsg(){ return ::proto_ff::Sheet_teleportborn(); }
	};
	typedef struct Sheet_teleportborn_s Sheet_teleportborn_t;

	struct teleportteleport_s : public NFDescStoreSeqOP {
		teleportteleport_s();
		int CreateInit();
		int ResumeInit();
		int64_t teleportID;
		int32_t teleportType;
		NFSizeString<60> name;
		int64_t monsterId;
		int32_t showCondition;
		NFSizeString<80> conditionValue;
		int32_t canEnter;
		int64_t showPathID;
		int64_t toPathID;
		int64_t toDuplicateId;
		NFSizeString<60> enterCost;
		int32_t trigRange;
		int32_t livingTime;
		int64_t openChatId;
		int64_t progressChatId;

		virtual void write_to_pbmsg(::proto_ff::teleportteleport & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::teleportteleport & msg);
		static ::proto_ff::teleportteleport* new_pbmsg(){ return new ::proto_ff::teleportteleport(); }
		static ::proto_ff::teleportteleport make_pbmsg(){ return ::proto_ff::teleportteleport(); }
	};
	typedef struct teleportteleport_s teleportteleport_t;

	struct Sheet_teleportteleport_s : public NFDescStoreSeqOP {
		Sheet_teleportteleport_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct teleportteleport_s, 40> teleportteleport_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_teleportteleport & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_teleportteleport & msg);
		static ::proto_ff::Sheet_teleportteleport* new_pbmsg(){ return new ::proto_ff::Sheet_teleportteleport(); }
		static ::proto_ff::Sheet_teleportteleport make_pbmsg(){ return ::proto_ff::Sheet_teleportteleport(); }
	};
	typedef struct Sheet_teleportteleport_s Sheet_teleportteleport_t;

}

