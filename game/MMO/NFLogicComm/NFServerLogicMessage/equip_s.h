#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "equip.pb.h"
#include "equip_s.h"

namespace proto_ff_s {

	struct equipequipattributeDesc_s : public NFDescStoreSeqOP {
		equipequipattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t valueMin;
		int32_t type;
		int32_t valueMax;

		virtual void write_to_pbmsg(::proto_ff::equipequipattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequipattributeDesc & msg);
		static ::proto_ff::equipequipattributeDesc* new_pbmsg(){ return new ::proto_ff::equipequipattributeDesc(); }
		static ::proto_ff::equipequipattributeDesc make_pbmsg(){ return ::proto_ff::equipequipattributeDesc(); }
	};
	typedef struct equipequipattributeDesc_s equipequipattributeDesc_t;

	struct equipequip_s : public NFDescStoreSeqOP {
		equipequip_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> name;
		int32_t wearQuality;
		int32_t position;
		NFSizeString<60> profession;
		int32_t professionLv;
		int32_t level;
		int32_t quality;
		int32_t star;
		int32_t refineAttributeDown;
		int32_t refineAttributeUp;
		NFSizeString<60> refineAttribute_typeLibrary;
		NFSizeString<60> refineAttribute_valueMin;
		NFSizeString<60> refineAttribute_valueMax;
		int32_t blueStarNum;
		NFSizeString<60> blueStar_type;
		NFSizeString<60> blueStar_lv;
		NFSizeString<60> blueStar_number;
		int32_t isCanbind;
		int32_t isTradeBind;
		int32_t sellPrice;
		NFSizeString<60> icon;
		int32_t time;
		int32_t Combat;
		int32_t broadcast;
		NFSizeString<60> meltingResult;
		NFArray<struct equipequipattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::equipequip & msg);
		static ::proto_ff::equipequip* new_pbmsg(){ return new ::proto_ff::equipequip(); }
		static ::proto_ff::equipequip make_pbmsg(){ return ::proto_ff::equipequip(); }
	};
	typedef struct equipequip_s equipequip_t;

	struct Sheet_equipequip_s : public NFDescStoreSeqOP {
		Sheet_equipequip_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct equipequip_s, 4000> equipequip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_equipequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_equipequip & msg);
		static ::proto_ff::Sheet_equipequip* new_pbmsg(){ return new ::proto_ff::Sheet_equipequip(); }
		static ::proto_ff::Sheet_equipequip make_pbmsg(){ return ::proto_ff::Sheet_equipequip(); }
	};
	typedef struct Sheet_equipequip_s Sheet_equipequip_t;

}

