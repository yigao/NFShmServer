#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "boss.pb.h"
#include "boss_s.h"

namespace proto_ff_s {

	struct bossrareItem_s : public NFDescStoreSeqOP {
		bossrareItem_s();
		virtual ~bossrareItem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t itemID;
		int32_t top;

		virtual void write_to_pbmsg(::proto_ff::bossrareItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::bossrareItem & msg);
		static ::proto_ff::bossrareItem* new_pbmsg(){ return new ::proto_ff::bossrareItem(); }
		static ::proto_ff::bossrareItem make_pbmsg(){ return ::proto_ff::bossrareItem(); }
	};
	typedef struct bossrareItem_s bossrareItem_t;

	struct Sheet_bossrareItem_s : public NFDescStoreSeqOP {
		Sheet_bossrareItem_s();
		virtual ~Sheet_bossrareItem_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct bossrareItem_s, 600> bossrareItem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_bossrareItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_bossrareItem & msg);
		static ::proto_ff::Sheet_bossrareItem* new_pbmsg(){ return new ::proto_ff::Sheet_bossrareItem(); }
		static ::proto_ff::Sheet_bossrareItem make_pbmsg(){ return ::proto_ff::Sheet_bossrareItem(); }
	};
	typedef struct Sheet_bossrareItem_s Sheet_bossrareItem_t;

	struct bossboss_s : public NFDescStoreSeqOP {
		bossboss_s();
		virtual ~bossboss_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t bossType;
		int32_t monsterID;
		int32_t classOrder;
		int32_t sceneOrder;
		int32_t duplicateID;
		int32_t peaceMask;
		int32_t pointID;
		int32_t group_type;
		int32_t flashTime;
		int32_t retrieveGiftID;
		int32_t noTimes;

		virtual void write_to_pbmsg(::proto_ff::bossboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::bossboss & msg);
		static ::proto_ff::bossboss* new_pbmsg(){ return new ::proto_ff::bossboss(); }
		static ::proto_ff::bossboss make_pbmsg(){ return ::proto_ff::bossboss(); }
	};
	typedef struct bossboss_s bossboss_t;

	struct Sheet_bossboss_s : public NFDescStoreSeqOP {
		Sheet_bossboss_s();
		virtual ~Sheet_bossboss_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct bossboss_s, 80> bossboss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_bossboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_bossboss & msg);
		static ::proto_ff::Sheet_bossboss* new_pbmsg(){ return new ::proto_ff::Sheet_bossboss(); }
		static ::proto_ff::Sheet_bossboss make_pbmsg(){ return ::proto_ff::Sheet_bossboss(); }
	};
	typedef struct Sheet_bossboss_s Sheet_bossboss_t;

	struct bossbosstypegroupDesc_s : public NFDescStoreSeqOP {
		bossbosstypegroupDesc_s();
		virtual ~bossbosstypegroupDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::bossbosstypegroupDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::bossbosstypegroupDesc & msg);
		static ::proto_ff::bossbosstypegroupDesc* new_pbmsg(){ return new ::proto_ff::bossbosstypegroupDesc(); }
		static ::proto_ff::bossbosstypegroupDesc make_pbmsg(){ return ::proto_ff::bossbosstypegroupDesc(); }
	};
	typedef struct bossbosstypegroupDesc_s bossbosstypegroupDesc_t;

	struct bossbosstype_s : public NFDescStoreSeqOP {
		bossbosstype_s();
		virtual ~bossbosstype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t bossType;
		int32_t mapType;
		int32_t functionId;
		int32_t duplicateGroupID;
		int32_t privilegeType;
		int64_t callingCardId;
		int32_t enterTimes;
		int32_t costitem;
		NFShmString<60> costnum;
		int32_t bossTimes;
		int32_t addItemID;
		int32_t canhelp;
		int32_t qkill;
		int32_t retrievedDays;
		int32_t skill;
		NFArray<struct bossbosstypegroupDesc_s, 3> group;

		virtual void write_to_pbmsg(::proto_ff::bossbosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::bossbosstype & msg);
		static ::proto_ff::bossbosstype* new_pbmsg(){ return new ::proto_ff::bossbosstype(); }
		static ::proto_ff::bossbosstype make_pbmsg(){ return ::proto_ff::bossbosstype(); }
	};
	typedef struct bossbosstype_s bossbosstype_t;

	struct Sheet_bossbosstype_s : public NFDescStoreSeqOP {
		Sheet_bossbosstype_s();
		virtual ~Sheet_bossbosstype_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct bossbosstype_s, 20> bossbosstype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_bossbosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_bossbosstype & msg);
		static ::proto_ff::Sheet_bossbosstype* new_pbmsg(){ return new ::proto_ff::Sheet_bossbosstype(); }
		static ::proto_ff::Sheet_bossbosstype make_pbmsg(){ return ::proto_ff::Sheet_bossbosstype(); }
	};
	typedef struct Sheet_bossbosstype_s Sheet_bossbosstype_t;

	struct bosslayer_s : public NFDescStoreSeqOP {
		bosslayer_s();
		virtual ~bosslayer_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t bossType;
		int32_t order;
		NFShmString<60> name;
		NFShmString<60> enterCondition;
		NFShmString<60> unlockCondition;
		int32_t mapID;

		virtual void write_to_pbmsg(::proto_ff::bosslayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::bosslayer & msg);
		static ::proto_ff::bosslayer* new_pbmsg(){ return new ::proto_ff::bosslayer(); }
		static ::proto_ff::bosslayer make_pbmsg(){ return ::proto_ff::bosslayer(); }
	};
	typedef struct bosslayer_s bosslayer_t;

	struct Sheet_bosslayer_s : public NFDescStoreSeqOP {
		Sheet_bosslayer_s();
		virtual ~Sheet_bosslayer_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct bosslayer_s, 20> bosslayer_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_bosslayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_bosslayer & msg);
		static ::proto_ff::Sheet_bosslayer* new_pbmsg(){ return new ::proto_ff::Sheet_bosslayer(); }
		static ::proto_ff::Sheet_bosslayer make_pbmsg(){ return ::proto_ff::Sheet_bosslayer(); }
	};
	typedef struct Sheet_bosslayer_s Sheet_bosslayer_t;

}

