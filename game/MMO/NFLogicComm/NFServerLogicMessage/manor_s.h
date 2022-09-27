#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "manor.pb.h"
#include "manor_s.h"

namespace proto_ff_s {

	struct manorconstants_s : public NFDescStoreSeqOP {
		manorconstants_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t valuedata;
		NFSizeString<60> stringdata;

		virtual void write_to_pbmsg(::proto_ff::manorconstants & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorconstants & msg);
		static ::proto_ff::manorconstants* new_pbmsg(){ return new ::proto_ff::manorconstants(); }
		static ::proto_ff::manorconstants make_pbmsg(){ return ::proto_ff::manorconstants(); }
	};
	typedef struct manorconstants_s manorconstants_t;

	struct Sheet_manorconstants_s : public NFDescStoreSeqOP {
		Sheet_manorconstants_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorconstants_s, 60> manorconstants_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorconstants & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorconstants & msg);
		static ::proto_ff::Sheet_manorconstants* new_pbmsg(){ return new ::proto_ff::Sheet_manorconstants(); }
		static ::proto_ff::Sheet_manorconstants make_pbmsg(){ return ::proto_ff::Sheet_manorconstants(); }
	};
	typedef struct Sheet_manorconstants_s Sheet_manorconstants_t;

	struct manoritemCost_s : public NFDescStoreSeqOP {
		manoritemCost_s();
		int CreateInit();
		int ResumeInit();
		int64_t itemId;
		int32_t useFor;
		int32_t itemValue;
		int32_t backType;
		int32_t backValue;

		virtual void write_to_pbmsg(::proto_ff::manoritemCost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manoritemCost & msg);
		static ::proto_ff::manoritemCost* new_pbmsg(){ return new ::proto_ff::manoritemCost(); }
		static ::proto_ff::manoritemCost make_pbmsg(){ return ::proto_ff::manoritemCost(); }
	};
	typedef struct manoritemCost_s manoritemCost_t;

	struct Sheet_manoritemCost_s : public NFDescStoreSeqOP {
		Sheet_manoritemCost_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manoritemCost_s, 20> manoritemCost_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manoritemCost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manoritemCost & msg);
		static ::proto_ff::Sheet_manoritemCost* new_pbmsg(){ return new ::proto_ff::Sheet_manoritemCost(); }
		static ::proto_ff::Sheet_manoritemCost make_pbmsg(){ return ::proto_ff::Sheet_manoritemCost(); }
	};
	typedef struct Sheet_manoritemCost_s Sheet_manoritemCost_t;

	struct manormanorlistinitialMonsterDesc_s : public NFDescStoreSeqOP {
		manormanorlistinitialMonsterDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::manormanorlistinitialMonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manormanorlistinitialMonsterDesc & msg);
		static ::proto_ff::manormanorlistinitialMonsterDesc* new_pbmsg(){ return new ::proto_ff::manormanorlistinitialMonsterDesc(); }
		static ::proto_ff::manormanorlistinitialMonsterDesc make_pbmsg(){ return ::proto_ff::manormanorlistinitialMonsterDesc(); }
	};
	typedef struct manormanorlistinitialMonsterDesc_s manormanorlistinitialMonsterDesc_t;

	struct manormanorlist_s : public NFDescStoreSeqOP {
		manormanorlist_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> name;
		int32_t manorType;
		int32_t attackBuildLevel;
		int32_t coreBaseLevel;
		int64_t mapId;
		int32_t productId;
		int64_t coreBasePath;
		int32_t coreBaseMaxLevel;
		int64_t coreBaseId;
		int64_t hatcheryBasePath;
		int32_t hatcheryBaseMaxLevel;
		int64_t hatcheryBaseId;
		int64_t buffBasePath;
		int32_t buffBaseMaxLevel;
		int64_t buffBaseId;
		int64_t shopPath;
		int32_t shopMaxLevel;
		int64_t shopId;
		int64_t crossGateBasePath;
		int32_t crossGateMaxLevel;
		int64_t crossGateBaseId;
		NFArray<struct manormanorlistinitialMonsterDesc_s, 4> initialMonster;
		NFArray<int64_t, 4> patBeastAttack_Path;
		NFArray<int64_t, 4> initialMonster_Id;

		virtual void write_to_pbmsg(::proto_ff::manormanorlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manormanorlist & msg);
		static ::proto_ff::manormanorlist* new_pbmsg(){ return new ::proto_ff::manormanorlist(); }
		static ::proto_ff::manormanorlist make_pbmsg(){ return ::proto_ff::manormanorlist(); }
	};
	typedef struct manormanorlist_s manormanorlist_t;

	struct Sheet_manormanorlist_s : public NFDescStoreSeqOP {
		Sheet_manormanorlist_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manormanorlist_s, 60> manormanorlist_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manormanorlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manormanorlist & msg);
		static ::proto_ff::Sheet_manormanorlist* new_pbmsg(){ return new ::proto_ff::Sheet_manormanorlist(); }
		static ::proto_ff::Sheet_manormanorlist make_pbmsg(){ return ::proto_ff::Sheet_manormanorlist(); }
	};
	typedef struct Sheet_manormanorlist_s Sheet_manormanorlist_t;

	struct manorproductproductDesc_s : public NFDescStoreSeqOP {
		manorproductproductDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int32_t buildLevle;

		virtual void write_to_pbmsg(::proto_ff::manorproductproductDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorproductproductDesc & msg);
		static ::proto_ff::manorproductproductDesc* new_pbmsg(){ return new ::proto_ff::manorproductproductDesc(); }
		static ::proto_ff::manorproductproductDesc make_pbmsg(){ return ::proto_ff::manorproductproductDesc(); }
	};
	typedef struct manorproductproductDesc_s manorproductproductDesc_t;

	struct manorproduct_s : public NFDescStoreSeqOP {
		manorproduct_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		NFArray<int64_t, 3> product_Item;
		NFArray<struct manorproductproductDesc_s, 3> product;

		virtual void write_to_pbmsg(::proto_ff::manorproduct & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorproduct & msg);
		static ::proto_ff::manorproduct* new_pbmsg(){ return new ::proto_ff::manorproduct(); }
		static ::proto_ff::manorproduct make_pbmsg(){ return ::proto_ff::manorproduct(); }
	};
	typedef struct manorproduct_s manorproduct_t;

	struct Sheet_manorproduct_s : public NFDescStoreSeqOP {
		Sheet_manorproduct_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorproduct_s, 40> manorproduct_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorproduct & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorproduct & msg);
		static ::proto_ff::Sheet_manorproduct* new_pbmsg(){ return new ::proto_ff::Sheet_manorproduct(); }
		static ::proto_ff::Sheet_manorproduct make_pbmsg(){ return ::proto_ff::Sheet_manorproduct(); }
	};
	typedef struct Sheet_manorproduct_s Sheet_manorproduct_t;

	struct manorbuild_s : public NFDescStoreSeqOP {
		manorbuild_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> name;
		int32_t buildingType;
		int64_t monsterId;
		NFSizeString<60> buildingvalue;
		NFSizeString<140> buildingAddBuff;
		NFSizeString<60> buildingConsume;

		virtual void write_to_pbmsg(::proto_ff::manorbuild & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorbuild & msg);
		static ::proto_ff::manorbuild* new_pbmsg(){ return new ::proto_ff::manorbuild(); }
		static ::proto_ff::manorbuild make_pbmsg(){ return ::proto_ff::manorbuild(); }
	};
	typedef struct manorbuild_s manorbuild_t;

	struct Sheet_manorbuild_s : public NFDescStoreSeqOP {
		Sheet_manorbuild_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorbuild_s, 20> manorbuild_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorbuild & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorbuild & msg);
		static ::proto_ff::Sheet_manorbuild* new_pbmsg(){ return new ::proto_ff::Sheet_manorbuild(); }
		static ::proto_ff::Sheet_manorbuild make_pbmsg(){ return ::proto_ff::Sheet_manorbuild(); }
	};
	typedef struct Sheet_manorbuild_s Sheet_manorbuild_t;

	struct manorbuildUpbuildDesc_s : public NFDescStoreSeqOP {
		manorbuildUpbuildDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::manorbuildUpbuildDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorbuildUpbuildDesc & msg);
		static ::proto_ff::manorbuildUpbuildDesc* new_pbmsg(){ return new ::proto_ff::manorbuildUpbuildDesc(); }
		static ::proto_ff::manorbuildUpbuildDesc make_pbmsg(){ return ::proto_ff::manorbuildUpbuildDesc(); }
	};
	typedef struct manorbuildUpbuildDesc_s manorbuildUpbuildDesc_t;

	struct manorbuildUp_s : public NFDescStoreSeqOP {
		manorbuildUp_s();
		int CreateInit();
		int ResumeInit();
		int32_t level;
		NFArray<int32_t, 5> build_type;
		NFArray<struct manorbuildUpbuildDesc_s, 5> build;

		virtual void write_to_pbmsg(::proto_ff::manorbuildUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorbuildUp & msg);
		static ::proto_ff::manorbuildUp* new_pbmsg(){ return new ::proto_ff::manorbuildUp(); }
		static ::proto_ff::manorbuildUp make_pbmsg(){ return ::proto_ff::manorbuildUp(); }
	};
	typedef struct manorbuildUp_s manorbuildUp_t;

	struct Sheet_manorbuildUp_s : public NFDescStoreSeqOP {
		Sheet_manorbuildUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorbuildUp_s, 20> manorbuildUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorbuildUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorbuildUp & msg);
		static ::proto_ff::Sheet_manorbuildUp* new_pbmsg(){ return new ::proto_ff::Sheet_manorbuildUp(); }
		static ::proto_ff::Sheet_manorbuildUp make_pbmsg(){ return ::proto_ff::Sheet_manorbuildUp(); }
	};
	typedef struct Sheet_manorbuildUp_s Sheet_manorbuildUp_t;

	struct manoregg_s : public NFDescStoreSeqOP {
		manoregg_s();
		int CreateInit();
		int ResumeInit();
		int64_t eggItemID;
		int32_t incubationTime;
		NFSizeString<80> patBeastsProbab;

		virtual void write_to_pbmsg(::proto_ff::manoregg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manoregg & msg);
		static ::proto_ff::manoregg* new_pbmsg(){ return new ::proto_ff::manoregg(); }
		static ::proto_ff::manoregg make_pbmsg(){ return ::proto_ff::manoregg(); }
	};
	typedef struct manoregg_s manoregg_t;

	struct Sheet_manoregg_s : public NFDescStoreSeqOP {
		Sheet_manoregg_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manoregg_s, 20> manoregg_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manoregg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manoregg & msg);
		static ::proto_ff::Sheet_manoregg* new_pbmsg(){ return new ::proto_ff::Sheet_manoregg(); }
		static ::proto_ff::Sheet_manoregg make_pbmsg(){ return ::proto_ff::Sheet_manoregg(); }
	};
	typedef struct Sheet_manoregg_s Sheet_manoregg_t;

	struct manorpatBeast_s : public NFDescStoreSeqOP {
		manorpatBeast_s();
		int CreateInit();
		int ResumeInit();
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::manorpatBeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorpatBeast & msg);
		static ::proto_ff::manorpatBeast* new_pbmsg(){ return new ::proto_ff::manorpatBeast(); }
		static ::proto_ff::manorpatBeast make_pbmsg(){ return ::proto_ff::manorpatBeast(); }
	};
	typedef struct manorpatBeast_s manorpatBeast_t;

	struct Sheet_manorpatBeast_s : public NFDescStoreSeqOP {
		Sheet_manorpatBeast_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorpatBeast_s, 20> manorpatBeast_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorpatBeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorpatBeast & msg);
		static ::proto_ff::Sheet_manorpatBeast* new_pbmsg(){ return new ::proto_ff::Sheet_manorpatBeast(); }
		static ::proto_ff::Sheet_manorpatBeast make_pbmsg(){ return ::proto_ff::Sheet_manorpatBeast(); }
	};
	typedef struct Sheet_manorpatBeast_s Sheet_manorpatBeast_t;

	struct manorpatBeastUP_s : public NFDescStoreSeqOP {
		manorpatBeastUP_s();
		int CreateInit();
		int ResumeInit();
		int32_t level;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::manorpatBeastUP & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorpatBeastUP & msg);
		static ::proto_ff::manorpatBeastUP* new_pbmsg(){ return new ::proto_ff::manorpatBeastUP(); }
		static ::proto_ff::manorpatBeastUP make_pbmsg(){ return ::proto_ff::manorpatBeastUP(); }
	};
	typedef struct manorpatBeastUP_s manorpatBeastUP_t;

	struct Sheet_manorpatBeastUP_s : public NFDescStoreSeqOP {
		Sheet_manorpatBeastUP_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorpatBeastUP_s, 20> manorpatBeastUP_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorpatBeastUP & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorpatBeastUP & msg);
		static ::proto_ff::Sheet_manorpatBeastUP* new_pbmsg(){ return new ::proto_ff::Sheet_manorpatBeastUP(); }
		static ::proto_ff::Sheet_manorpatBeastUP make_pbmsg(){ return ::proto_ff::Sheet_manorpatBeastUP(); }
	};
	typedef struct Sheet_manorpatBeastUP_s Sheet_manorpatBeastUP_t;

	struct manorbuildBuff_s : public NFDescStoreSeqOP {
		manorbuildBuff_s();
		int CreateInit();
		int ResumeInit();
		int32_t levelSum;
		int64_t skillId;

		virtual void write_to_pbmsg(::proto_ff::manorbuildBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorbuildBuff & msg);
		static ::proto_ff::manorbuildBuff* new_pbmsg(){ return new ::proto_ff::manorbuildBuff(); }
		static ::proto_ff::manorbuildBuff make_pbmsg(){ return ::proto_ff::manorbuildBuff(); }
	};
	typedef struct manorbuildBuff_s manorbuildBuff_t;

	struct Sheet_manorbuildBuff_s : public NFDescStoreSeqOP {
		Sheet_manorbuildBuff_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorbuildBuff_s, 20> manorbuildBuff_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorbuildBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorbuildBuff & msg);
		static ::proto_ff::Sheet_manorbuildBuff* new_pbmsg(){ return new ::proto_ff::Sheet_manorbuildBuff(); }
		static ::proto_ff::Sheet_manorbuildBuff make_pbmsg(){ return ::proto_ff::Sheet_manorbuildBuff(); }
	};
	typedef struct Sheet_manorbuildBuff_s Sheet_manorbuildBuff_t;

	struct manorshop_s : public NFDescStoreSeqOP {
		manorshop_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t itemId;
		int32_t needShopLV;
		int32_t buyLimit;
		int32_t moneyCode;
		int64_t moneyType;
		int32_t Price;

		virtual void write_to_pbmsg(::proto_ff::manorshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorshop & msg);
		static ::proto_ff::manorshop* new_pbmsg(){ return new ::proto_ff::manorshop(); }
		static ::proto_ff::manorshop make_pbmsg(){ return ::proto_ff::manorshop(); }
	};
	typedef struct manorshop_s manorshop_t;

	struct Sheet_manorshop_s : public NFDescStoreSeqOP {
		Sheet_manorshop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorshop_s, 20> manorshop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorshop & msg);
		static ::proto_ff::Sheet_manorshop* new_pbmsg(){ return new ::proto_ff::Sheet_manorshop(); }
		static ::proto_ff::Sheet_manorshop make_pbmsg(){ return ::proto_ff::Sheet_manorshop(); }
	};
	typedef struct Sheet_manorshop_s Sheet_manorshop_t;

	struct manorbuildAdd_s : public NFDescStoreSeqOP {
		manorbuildAdd_s();
		int CreateInit();
		int ResumeInit();
		int32_t levelSum;
		int32_t addRatio;

		virtual void write_to_pbmsg(::proto_ff::manorbuildAdd & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorbuildAdd & msg);
		static ::proto_ff::manorbuildAdd* new_pbmsg(){ return new ::proto_ff::manorbuildAdd(); }
		static ::proto_ff::manorbuildAdd make_pbmsg(){ return ::proto_ff::manorbuildAdd(); }
	};
	typedef struct manorbuildAdd_s manorbuildAdd_t;

	struct Sheet_manorbuildAdd_s : public NFDescStoreSeqOP {
		Sheet_manorbuildAdd_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorbuildAdd_s, 20> manorbuildAdd_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorbuildAdd & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorbuildAdd & msg);
		static ::proto_ff::Sheet_manorbuildAdd* new_pbmsg(){ return new ::proto_ff::Sheet_manorbuildAdd(); }
		static ::proto_ff::Sheet_manorbuildAdd make_pbmsg(){ return ::proto_ff::Sheet_manorbuildAdd(); }
	};
	typedef struct Sheet_manorbuildAdd_s Sheet_manorbuildAdd_t;

	struct manorlog_s : public NFDescStoreSeqOP {
		manorlog_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;

		virtual void write_to_pbmsg(::proto_ff::manorlog & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::manorlog & msg);
		static ::proto_ff::manorlog* new_pbmsg(){ return new ::proto_ff::manorlog(); }
		static ::proto_ff::manorlog make_pbmsg(){ return ::proto_ff::manorlog(); }
	};
	typedef struct manorlog_s manorlog_t;

	struct Sheet_manorlog_s : public NFDescStoreSeqOP {
		Sheet_manorlog_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct manorlog_s, 20> manorlog_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_manorlog & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_manorlog & msg);
		static ::proto_ff::Sheet_manorlog* new_pbmsg(){ return new ::proto_ff::Sheet_manorlog(); }
		static ::proto_ff::Sheet_manorlog make_pbmsg(){ return ::proto_ff::Sheet_manorlog(); }
	};
	typedef struct Sheet_manorlog_s Sheet_manorlog_t;

}

