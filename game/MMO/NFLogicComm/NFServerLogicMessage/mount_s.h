#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "mount.pb.h"
#include "mount_s.h"

namespace proto_ff_s {

	struct mountmountuseattrDesc_s : public NFDescStoreSeqOP {
		mountmountuseattrDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::mountmountuseattrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mountmountuseattrDesc & msg);
		static ::proto_ff::mountmountuseattrDesc* new_pbmsg(){ return new ::proto_ff::mountmountuseattrDesc(); }
		static ::proto_ff::mountmountuseattrDesc make_pbmsg(){ return ::proto_ff::mountmountuseattrDesc(); }
	};
	typedef struct mountmountuseattrDesc_s mountmountuseattrDesc_t;

	struct mountmount_s : public NFDescStoreSeqOP {
		mountmount_s();
		int CreateInit();
		int ResumeInit();
		int64_t mountId;
		NFSizeString<60> name;
		int32_t quality;
		int64_t occupation;
		int32_t speedNum;
		int64_t needItem;
		NFSizeString<200> ItemNum;
		int32_t starLv;
		int32_t starNumber;
		int32_t sourceLink;
		int64_t upAttributeId;
		NFArray<struct mountmountuseattrDesc_s, 3> useattr;

		virtual void write_to_pbmsg(::proto_ff::mountmount & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mountmount & msg);
		static ::proto_ff::mountmount* new_pbmsg(){ return new ::proto_ff::mountmount(); }
		static ::proto_ff::mountmount make_pbmsg(){ return ::proto_ff::mountmount(); }
	};
	typedef struct mountmount_s mountmount_t;

	struct Sheet_mountmount_s : public NFDescStoreSeqOP {
		Sheet_mountmount_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct mountmount_s, 80> mountmount_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mountmount & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mountmount & msg);
		static ::proto_ff::Sheet_mountmount* new_pbmsg(){ return new ::proto_ff::Sheet_mountmount(); }
		static ::proto_ff::Sheet_mountmount make_pbmsg(){ return ::proto_ff::Sheet_mountmount(); }
	};
	typedef struct Sheet_mountmount_s Sheet_mountmount_t;

	struct mountstarUpupAttributeDesc_s : public NFDescStoreSeqOP {
		mountstarUpupAttributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::mountstarUpupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mountstarUpupAttributeDesc & msg);
		static ::proto_ff::mountstarUpupAttributeDesc* new_pbmsg(){ return new ::proto_ff::mountstarUpupAttributeDesc(); }
		static ::proto_ff::mountstarUpupAttributeDesc make_pbmsg(){ return ::proto_ff::mountstarUpupAttributeDesc(); }
	};
	typedef struct mountstarUpupAttributeDesc_s mountstarUpupAttributeDesc_t;

	struct mountstarUp_s : public NFDescStoreSeqOP {
		mountstarUp_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t upAttributeId;
		int32_t starID;
		NFArray<struct mountstarUpupAttributeDesc_s, 2> upAttribute;

		virtual void write_to_pbmsg(::proto_ff::mountstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mountstarUp & msg);
		static ::proto_ff::mountstarUp* new_pbmsg(){ return new ::proto_ff::mountstarUp(); }
		static ::proto_ff::mountstarUp make_pbmsg(){ return ::proto_ff::mountstarUp(); }
	};
	typedef struct mountstarUp_s mountstarUp_t;

	struct Sheet_mountstarUp_s : public NFDescStoreSeqOP {
		Sheet_mountstarUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct mountstarUp_s, 80> mountstarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mountstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mountstarUp & msg);
		static ::proto_ff::Sheet_mountstarUp* new_pbmsg(){ return new ::proto_ff::Sheet_mountstarUp(); }
		static ::proto_ff::Sheet_mountstarUp make_pbmsg(){ return ::proto_ff::Sheet_mountstarUp(); }
	};
	typedef struct Sheet_mountstarUp_s Sheet_mountstarUp_t;

}

