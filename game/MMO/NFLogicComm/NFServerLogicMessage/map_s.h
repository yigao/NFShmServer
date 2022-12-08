#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "map.pb.h"
#include "map_s.h"

namespace proto_ff_s {

	struct mapmap_s : public NFDescStoreSeqOP {
		mapmap_s();
		virtual ~mapmap_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t mapId;
		int32_t levelLimit;
		NFShmString<60> adviceLv;
		int32_t mapType;
		int32_t mapSubType;
		int32_t clearanceTime;
		int32_t mapPkmode;
		int32_t pklock;
		int32_t pk;
		int32_t killValue;
		int32_t BanGroup;
		int32_t reviveTime;
		int32_t mapWide;
		int32_t mapHeight;
		NFShmString<60> mapResources;
		int64_t reviveSkill;
		int32_t reviveInPlaceType;
		int32_t isHangUp;
		int32_t itemDropType;
		NFShmString<60> itemDropID;
		int64_t linkOffLine;
		int32_t banOnHook;
		int32_t Rewait;
		int32_t REtime;
		int32_t HREBan;
		int32_t Retiered;
		int32_t REskillid;
		int32_t Reteimes;
		int32_t drivePoint;
		int32_t dieDP;
		int32_t timeDP;
		int32_t meditation;

		virtual void write_to_pbmsg(::proto_ff::mapmap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mapmap & msg);
		static ::proto_ff::mapmap* new_pbmsg(){ return new ::proto_ff::mapmap(); }
		static ::proto_ff::mapmap make_pbmsg(){ return ::proto_ff::mapmap(); }
	};
	typedef struct mapmap_s mapmap_t;

	struct Sheet_mapmap_s : public NFDescStoreSeqOP {
		Sheet_mapmap_s();
		virtual ~Sheet_mapmap_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct mapmap_s, 40> mapmap_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mapmap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mapmap & msg);
		static ::proto_ff::Sheet_mapmap* new_pbmsg(){ return new ::proto_ff::Sheet_mapmap(); }
		static ::proto_ff::Sheet_mapmap make_pbmsg(){ return ::proto_ff::Sheet_mapmap(); }
	};
	typedef struct Sheet_mapmap_s Sheet_mapmap_t;

	struct mapitemdrop_s : public NFDescStoreSeqOP {
		mapitemdrop_s();
		virtual ~mapitemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t itemDropID;
		int32_t dropType;
		int32_t odds;
		int32_t dropvaluea;
		int32_t dropvalueb;
		int32_t dropvaluec;
		int32_t dropvalued;
		int32_t dropvaluee;
		int32_t dropvaluef;

		virtual void write_to_pbmsg(::proto_ff::mapitemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mapitemdrop & msg);
		static ::proto_ff::mapitemdrop* new_pbmsg(){ return new ::proto_ff::mapitemdrop(); }
		static ::proto_ff::mapitemdrop make_pbmsg(){ return ::proto_ff::mapitemdrop(); }
	};
	typedef struct mapitemdrop_s mapitemdrop_t;

	struct Sheet_mapitemdrop_s : public NFDescStoreSeqOP {
		Sheet_mapitemdrop_s();
		virtual ~Sheet_mapitemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct mapitemdrop_s, 40> mapitemdrop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mapitemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mapitemdrop & msg);
		static ::proto_ff::Sheet_mapitemdrop* new_pbmsg(){ return new ::proto_ff::Sheet_mapitemdrop(); }
		static ::proto_ff::Sheet_mapitemdrop make_pbmsg(){ return ::proto_ff::Sheet_mapitemdrop(); }
	};
	typedef struct Sheet_mapitemdrop_s Sheet_mapitemdrop_t;

	struct mapdestroyitem_s : public NFDescStoreSeqOP {
		mapdestroyitem_s();
		virtual ~mapdestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t destroyitemID;

		virtual void write_to_pbmsg(::proto_ff::mapdestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mapdestroyitem & msg);
		static ::proto_ff::mapdestroyitem* new_pbmsg(){ return new ::proto_ff::mapdestroyitem(); }
		static ::proto_ff::mapdestroyitem make_pbmsg(){ return ::proto_ff::mapdestroyitem(); }
	};
	typedef struct mapdestroyitem_s mapdestroyitem_t;

	struct Sheet_mapdestroyitem_s : public NFDescStoreSeqOP {
		Sheet_mapdestroyitem_s();
		virtual ~Sheet_mapdestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct mapdestroyitem_s, 200> mapdestroyitem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mapdestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mapdestroyitem & msg);
		static ::proto_ff::Sheet_mapdestroyitem* new_pbmsg(){ return new ::proto_ff::Sheet_mapdestroyitem(); }
		static ::proto_ff::Sheet_mapdestroyitem make_pbmsg(){ return ::proto_ff::Sheet_mapdestroyitem(); }
	};
	typedef struct Sheet_mapdestroyitem_s Sheet_mapdestroyitem_t;

}

