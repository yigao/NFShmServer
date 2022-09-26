#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "combine.pb.h"
#include "combine_s.h"

namespace proto_ff_s {

	struct combinecitemneedMaterialDesc_s : public NFDescStoreSeqOP {
		combinecitemneedMaterialDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::combinecitemneedMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinecitemneedMaterialDesc & msg);
		static ::proto_ff::combinecitemneedMaterialDesc* new_pbmsg(){ return new ::proto_ff::combinecitemneedMaterialDesc(); }
		static ::proto_ff::combinecitemneedMaterialDesc make_pbmsg(){ return ::proto_ff::combinecitemneedMaterialDesc(); }
	};
	typedef struct combinecitemneedMaterialDesc_s combinecitemneedMaterialDesc_t;

	struct combinecitem_s : public NFDescStoreSeqOP {
		combinecitem_s();
		int CreateInit();
		int ResumeInit();
		int64_t newItem;
		int32_t moneyType;
		int32_t price;
		int32_t huobiType;
		int32_t huobiPrice;
		int32_t probability;
		int32_t level;
		int32_t floor;
		NFArray<struct combinecitemneedMaterialDesc_s, 3> needMaterial;

		virtual void write_to_pbmsg(::proto_ff::combinecitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinecitem & msg);
		static ::proto_ff::combinecitem* new_pbmsg(){ return new ::proto_ff::combinecitem(); }
		static ::proto_ff::combinecitem make_pbmsg(){ return ::proto_ff::combinecitem(); }
	};
	typedef struct combinecitem_s combinecitem_t;

	struct Sheet_combinecitem_s : public NFDescStoreSeqOP {
		Sheet_combinecitem_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct combinecitem_s, 500> combinecitem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_combinecitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_combinecitem & msg);
		static ::proto_ff::Sheet_combinecitem* new_pbmsg(){ return new ::proto_ff::Sheet_combinecitem(); }
		static ::proto_ff::Sheet_combinecitem make_pbmsg(){ return ::proto_ff::Sheet_combinecitem(); }
	};
	typedef struct Sheet_combinecitem_s Sheet_combinecitem_t;

	struct combinestarUp_s : public NFDescStoreSeqOP {
		combinestarUp_s();
		int CreateInit();
		int ResumeInit();
		int64_t newItem;
		int32_t equipMin;
		int32_t num;
		int64_t needMaterial_id;
		int32_t needMaterial_num;
		int32_t star;
		int32_t wearQuality;
		int32_t quality;
		int32_t sameProfession;
		NFSizeString<60> samePosition;
		int32_t probability;
		int32_t increase;

		virtual void write_to_pbmsg(::proto_ff::combinestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinestarUp & msg);
		static ::proto_ff::combinestarUp* new_pbmsg(){ return new ::proto_ff::combinestarUp(); }
		static ::proto_ff::combinestarUp make_pbmsg(){ return ::proto_ff::combinestarUp(); }
	};
	typedef struct combinestarUp_s combinestarUp_t;

	struct Sheet_combinestarUp_s : public NFDescStoreSeqOP {
		Sheet_combinestarUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct combinestarUp_s, 800> combinestarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_combinestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_combinestarUp & msg);
		static ::proto_ff::Sheet_combinestarUp* new_pbmsg(){ return new ::proto_ff::Sheet_combinestarUp(); }
		static ::proto_ff::Sheet_combinestarUp make_pbmsg(){ return ::proto_ff::Sheet_combinestarUp(); }
	};
	typedef struct Sheet_combinestarUp_s Sheet_combinestarUp_t;

	struct combineitemUp_s : public NFDescStoreSeqOP {
		combineitemUp_s();
		int CreateInit();
		int ResumeInit();
		int64_t newItem;
		int32_t moneyType;
		int32_t price;
		int64_t needMaterialID;
		int32_t needMaterialMin;
		int32_t needMaterialMan;
		int32_t probability;
		int32_t increase;

		virtual void write_to_pbmsg(::proto_ff::combineitemUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combineitemUp & msg);
		static ::proto_ff::combineitemUp* new_pbmsg(){ return new ::proto_ff::combineitemUp(); }
		static ::proto_ff::combineitemUp make_pbmsg(){ return ::proto_ff::combineitemUp(); }
	};
	typedef struct combineitemUp_s combineitemUp_t;

	struct Sheet_combineitemUp_s : public NFDescStoreSeqOP {
		Sheet_combineitemUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct combineitemUp_s, 60> combineitemUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_combineitemUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_combineitemUp & msg);
		static ::proto_ff::Sheet_combineitemUp* new_pbmsg(){ return new ::proto_ff::Sheet_combineitemUp(); }
		static ::proto_ff::Sheet_combineitemUp make_pbmsg(){ return ::proto_ff::Sheet_combineitemUp(); }
	};
	typedef struct Sheet_combineitemUp_s Sheet_combineitemUp_t;

	struct combinerankUp_s : public NFDescStoreSeqOP {
		combinerankUp_s();
		int CreateInit();
		int ResumeInit();
		int64_t newItem;
		int32_t num;
		int64_t needMaterial_id;
		int32_t needMaterial_num;
		int32_t star;
		int32_t wearQuality;
		int32_t quality;
		int32_t sameProfession;
		NFSizeString<60> samePosition;
		int32_t probability;

		virtual void write_to_pbmsg(::proto_ff::combinerankUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinerankUp & msg);
		static ::proto_ff::combinerankUp* new_pbmsg(){ return new ::proto_ff::combinerankUp(); }
		static ::proto_ff::combinerankUp make_pbmsg(){ return ::proto_ff::combinerankUp(); }
	};
	typedef struct combinerankUp_s combinerankUp_t;

	struct Sheet_combinerankUp_s : public NFDescStoreSeqOP {
		Sheet_combinerankUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct combinerankUp_s, 40> combinerankUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_combinerankUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_combinerankUp & msg);
		static ::proto_ff::Sheet_combinerankUp* new_pbmsg(){ return new ::proto_ff::Sheet_combinerankUp(); }
		static ::proto_ff::Sheet_combinerankUp make_pbmsg(){ return ::proto_ff::Sheet_combinerankUp(); }
	};
	typedef struct Sheet_combinerankUp_s Sheet_combinerankUp_t;

	struct combinequalityUpneedEqupDesc_s : public NFDescStoreSeqOP {
		combinequalityUpneedEqupDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<160> id;

		virtual void write_to_pbmsg(::proto_ff::combinequalityUpneedEqupDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinequalityUpneedEqupDesc & msg);
		static ::proto_ff::combinequalityUpneedEqupDesc* new_pbmsg(){ return new ::proto_ff::combinequalityUpneedEqupDesc(); }
		static ::proto_ff::combinequalityUpneedEqupDesc make_pbmsg(){ return ::proto_ff::combinequalityUpneedEqupDesc(); }
	};
	typedef struct combinequalityUpneedEqupDesc_s combinequalityUpneedEqupDesc_t;

	struct combinequalityUpneedMaterialDesc_s : public NFDescStoreSeqOP {
		combinequalityUpneedMaterialDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::combinequalityUpneedMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinequalityUpneedMaterialDesc & msg);
		static ::proto_ff::combinequalityUpneedMaterialDesc* new_pbmsg(){ return new ::proto_ff::combinequalityUpneedMaterialDesc(); }
		static ::proto_ff::combinequalityUpneedMaterialDesc make_pbmsg(){ return ::proto_ff::combinequalityUpneedMaterialDesc(); }
	};
	typedef struct combinequalityUpneedMaterialDesc_s combinequalityUpneedMaterialDesc_t;

	struct combinequalityUp_s : public NFDescStoreSeqOP {
		combinequalityUp_s();
		int CreateInit();
		int ResumeInit();
		int64_t newItem;
		int32_t num;
		int32_t needEqup_num;
		int32_t star;
		int32_t wearQuality;
		int32_t quality;
		int32_t sameProfession;
		NFSizeString<60> samePosition;
		int32_t probability;
		int32_t costType;
		int32_t bindJewelCost;
		NFArray<struct combinequalityUpneedEqupDesc_s, 1> needEqup;
		NFArray<struct combinequalityUpneedMaterialDesc_s, 2> needMaterial;

		virtual void write_to_pbmsg(::proto_ff::combinequalityUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::combinequalityUp & msg);
		static ::proto_ff::combinequalityUp* new_pbmsg(){ return new ::proto_ff::combinequalityUp(); }
		static ::proto_ff::combinequalityUp make_pbmsg(){ return ::proto_ff::combinequalityUp(); }
	};
	typedef struct combinequalityUp_s combinequalityUp_t;

	struct Sheet_combinequalityUp_s : public NFDescStoreSeqOP {
		Sheet_combinequalityUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct combinequalityUp_s, 300> combinequalityUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_combinequalityUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_combinequalityUp & msg);
		static ::proto_ff::Sheet_combinequalityUp* new_pbmsg(){ return new ::proto_ff::Sheet_combinequalityUp(); }
		static ::proto_ff::Sheet_combinequalityUp make_pbmsg(){ return ::proto_ff::Sheet_combinequalityUp(); }
	};
	typedef struct Sheet_combinequalityUp_s Sheet_combinequalityUp_t;

}

