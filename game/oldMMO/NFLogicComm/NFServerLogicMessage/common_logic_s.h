#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "common_logic.pb.h"
#include "common_logic_s.h"

namespace proto_ff_s {

	struct PacketMsg_s {
		PacketMsg_s();
		int CreateInit();
		int ResumeInit();
		uint32_t cmd;
		uint32_t serverType;
		uint32_t upper_limit;
		uint32_t min_interval;
		uint32_t control_time;

		virtual void write_to_pbmsg(::proto_ff::PacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PacketMsg & msg);
		static ::proto_ff::PacketMsg* new_pbmsg(){ return new ::proto_ff::PacketMsg(); }
		static ::proto_ff::PacketMsg make_pbmsg(){ return ::proto_ff::PacketMsg(); }
	};
	typedef struct PacketMsg_s PacketMsg_t;

	struct ServerPacketMsg_s {
		ServerPacketMsg_s();
		int CreateInit();
		int ResumeInit();
		std::vector<struct PacketMsg_s> PacketMsg;

		virtual void write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg);
		static ::proto_ff::ServerPacketMsg* new_pbmsg(){ return new ::proto_ff::ServerPacketMsg(); }
		static ::proto_ff::ServerPacketMsg make_pbmsg(){ return ::proto_ff::ServerPacketMsg(); }
	};
	typedef struct ServerPacketMsg_s ServerPacketMsg_t;

	struct WorldExternalConfig_s {
		WorldExternalConfig_s();
		int CreateInit();
		int ResumeInit();
		bool TokenTimeCheck;

		virtual void write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg);
		static ::proto_ff::WorldExternalConfig* new_pbmsg(){ return new ::proto_ff::WorldExternalConfig(); }
		static ::proto_ff::WorldExternalConfig make_pbmsg(){ return ::proto_ff::WorldExternalConfig(); }
	};
	typedef struct WorldExternalConfig_s WorldExternalConfig_t;

	struct CharFacadeProto_s : public NFDescStoreSeqOP {
		CharFacadeProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cur_mount_id;
		uint64_t wing_id;
		uint64_t fashion_clothes_id;
		uint64_t fashion_weapon_id;
		uint64_t occupationId;
		uint64_t treasure_id;
		int32_t treasure_type;
		uint64_t artifact_id;
		uint64_t cur_select_mount_id;
		uint64_t partner_id;
		uint64_t head_id;
		uint64_t frame_id;
		uint64_t bubble_id;

		virtual void write_to_pbmsg(::proto_ff::CharFacadeProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharFacadeProto & msg);
		static ::proto_ff::CharFacadeProto* new_pbmsg(){ return new ::proto_ff::CharFacadeProto(); }
		static ::proto_ff::CharFacadeProto make_pbmsg(){ return ::proto_ff::CharFacadeProto(); }
	};
	typedef struct CharFacadeProto_s CharFacadeProto_t;

	struct CharTrimProto_s : public NFDescStoreSeqOP {
		CharTrimProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t trim_type;
		int32_t trim_level;

		virtual void write_to_pbmsg(::proto_ff::CharTrimProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharTrimProto & msg);
		static ::proto_ff::CharTrimProto* new_pbmsg(){ return new ::proto_ff::CharTrimProto(); }
		static ::proto_ff::CharTrimProto make_pbmsg(){ return ::proto_ff::CharTrimProto(); }
	};
	typedef struct CharTrimProto_s CharTrimProto_t;

	struct ForceDupProto_s : public NFDescStoreSeqOP {
		ForceDupProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t treasure_state;
		int32_t ladder_state;

		virtual void write_to_pbmsg(::proto_ff::ForceDupProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ForceDupProto & msg);
		static ::proto_ff::ForceDupProto* new_pbmsg(){ return new ::proto_ff::ForceDupProto(); }
		static ::proto_ff::ForceDupProto make_pbmsg(){ return ::proto_ff::ForceDupProto(); }
	};
	typedef struct ForceDupProto_s ForceDupProto_t;

	struct CharMultTrimProto_s : public NFDescStoreSeqOP {
		CharMultTrimProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharTrimProto_s, 128> trim_lst;

		virtual void write_to_pbmsg(::proto_ff::CharMultTrimProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharMultTrimProto & msg);
		static ::proto_ff::CharMultTrimProto* new_pbmsg(){ return new ::proto_ff::CharMultTrimProto(); }
		static ::proto_ff::CharMultTrimProto make_pbmsg(){ return ::proto_ff::CharMultTrimProto(); }
	};
	typedef struct CharMultTrimProto_s CharMultTrimProto_t;

	struct CharacterDBBaseInfo_s : public NFDescStoreSeqOP {
		CharacterDBBaseInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t createTime;
		uint64_t lastSaveTime;
		uint64_t onlineTime;
		uint64_t loginTime;
		uint64_t logoutTime;
		NFSizeString<128> name;
		uint32_t sex;
		uint32_t prof;
		uint32_t level;
		int64_t exp;
		int64_t hp;
		int64_t fight;
		uint64_t gold;
		uint64_t diamond;
		uint64_t binddiamond;
		uint64_t enter_scene_id;
		uint64_t enter_map_id;
		float enterPosX;
		float enterPosY;
		float enterPosZ;
		uint64_t lastSceneId;
		uint64_t lastMapId;
		float lastPosX;
		float lastPosY;
		float lastPosZ;
		uint64_t lastReviveTime;
		uint32_t curState;
		float clx;
		float cly;
		float clz;
		uint64_t occupation;
		uint64_t aptitude;
		struct CharFacadeProto_s facade;
		int64_t arenacoin;
		int64_t starEssence;
		int64_t starExp;
		int64_t starFragment;
		int64_t hangUpTime;
		uint32_t active_num;
		int64_t vipLevel;
		int64_t godhoodExp;
		int64_t smallSpirit;
		int64_t bigSpirit;
		struct CharMultTrimProto_s trim;
		int32_t finish_flag;
		NFSizeString<128> guide;
		struct ForceDupProto_s force;
		int64_t useTitle;
		int32_t subpack_type;
		int32_t subpack_fetch;
		int32_t rechargeDiscountDate;
		int32_t friendNum;
		NFSizeString<128> platid;
		int32_t solo_score;
		int32_t solo_prv_score;
		int32_t dragons_num;
		uint32_t total_login_day;
		uint64_t login_day_time;
		int32_t login_gift;
		int64_t vipCardDiamond;
		uint64_t holydia;
		int32_t relive_num;
		int64_t last_relive_time;
		int64_t dead_static_map_id;
		int32_t dead_static_num;
		int64_t dead_static_cd;
		int32_t fushi_time;
		int64_t starStone;
		int64_t voucher;
		int64_t waiguan;
		int64_t gmpoint;
		int64_t gmpoint_limit;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBBaseInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBBaseInfo & msg);
		static ::proto_ff::CharacterDBBaseInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBBaseInfo(); }
		static ::proto_ff::CharacterDBBaseInfo make_pbmsg(){ return ::proto_ff::CharacterDBBaseInfo(); }
	};
	typedef struct CharacterDBBaseInfo_s CharacterDBBaseInfo_t;

	struct Attr_s : public NFDescStoreSeqOP {
		Attr_s();
		int CreateInit();
		int ResumeInit();
		uint32_t AttrNum;
		uint32_t Attrvalue;

		virtual void write_to_pbmsg(::proto_ff::Attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr & msg);
		static ::proto_ff::Attr* new_pbmsg(){ return new ::proto_ff::Attr(); }
		static ::proto_ff::Attr make_pbmsg(){ return ::proto_ff::Attr(); }
	};
	typedef struct Attr_s Attr_t;

	struct Attr64_s : public NFDescStoreSeqOP {
		Attr64_s();
		int CreateInit();
		int ResumeInit();
		uint32_t AttrNum;
		int64_t Attrvalue;

		virtual void write_to_pbmsg(::proto_ff::Attr64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr64 & msg);
		static ::proto_ff::Attr64* new_pbmsg(){ return new ::proto_ff::Attr64(); }
		static ::proto_ff::Attr64 make_pbmsg(){ return ::proto_ff::Attr64(); }
	};
	typedef struct Attr64_s Attr64_t;

	struct FieldItemAttrInfo_s : public NFDescStoreSeqOP {
		FieldItemAttrInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct Attr_s, 128> base_attr;
		NFArray<struct Attr_s, 128> star_attr;
		NFArray<struct Attr_s, 128> blue_star_attr;
		int32_t refine_level;

		virtual void write_to_pbmsg(::proto_ff::FieldItemAttrInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FieldItemAttrInfo & msg);
		static ::proto_ff::FieldItemAttrInfo* new_pbmsg(){ return new ::proto_ff::FieldItemAttrInfo(); }
		static ::proto_ff::FieldItemAttrInfo make_pbmsg(){ return ::proto_ff::FieldItemAttrInfo(); }
	};
	typedef struct FieldItemAttrInfo_s FieldItemAttrInfo_t;

	struct MarryEquipInfo_s : public NFDescStoreSeqOP {
		MarryEquipInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t strong_lv;
		int32_t strong_exp;
		int32_t stage_lv;

		virtual void write_to_pbmsg(::proto_ff::MarryEquipInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryEquipInfo & msg);
		static ::proto_ff::MarryEquipInfo* new_pbmsg(){ return new ::proto_ff::MarryEquipInfo(); }
		static ::proto_ff::MarryEquipInfo make_pbmsg(){ return ::proto_ff::MarryEquipInfo(); }
	};
	typedef struct MarryEquipInfo_s MarryEquipInfo_t;

	struct ComposeSingleCostProto_s : public NFDescStoreSeqOP {
		ComposeSingleCostProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t itemid;
		int32_t bind;

		virtual void write_to_pbmsg(::proto_ff::ComposeSingleCostProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComposeSingleCostProto & msg);
		static ::proto_ff::ComposeSingleCostProto* new_pbmsg(){ return new ::proto_ff::ComposeSingleCostProto(); }
		static ::proto_ff::ComposeSingleCostProto make_pbmsg(){ return ::proto_ff::ComposeSingleCostProto(); }
	};
	typedef struct ComposeSingleCostProto_s ComposeSingleCostProto_t;

	struct ComposeCostProto_s : public NFDescStoreSeqOP {
		ComposeCostProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComposeSingleCostProto_s, 128> info;

		virtual void write_to_pbmsg(::proto_ff::ComposeCostProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComposeCostProto & msg);
		static ::proto_ff::ComposeCostProto* new_pbmsg(){ return new ::proto_ff::ComposeCostProto(); }
		static ::proto_ff::ComposeCostProto make_pbmsg(){ return ::proto_ff::ComposeCostProto(); }
	};
	typedef struct ComposeCostProto_s ComposeCostProto_t;

	struct blustarAttr_s : public NFDescStoreSeqOP {
		blustarAttr_s();
		int CreateInit();
		int ResumeInit();
		uint32_t attrid;
		uint32_t levelinterval;
		uint32_t attrvalue;

		virtual void write_to_pbmsg(::proto_ff::blustarAttr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::blustarAttr & msg);
		static ::proto_ff::blustarAttr* new_pbmsg(){ return new ::proto_ff::blustarAttr(); }
		static ::proto_ff::blustarAttr make_pbmsg(){ return ::proto_ff::blustarAttr(); }
	};
	typedef struct blustarAttr_s blustarAttr_t;

	struct ItemProtoInfo_s : public NFDescStoreSeqOP {
		ItemProtoInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;
		int64_t item_num;
		int32_t bind;
		NFArray<struct Attr_s, 128> baseattr;
		int32_t index;
		int32_t level;
		NFArray<struct Attr_s, 128> refineex;
		NFArray<struct blustarAttr_s, 128> con_attr;
		uint64_t expireTime;
		struct FieldItemAttrInfo_s field_data;
		struct MarryEquipInfo_s marry_equip_data;
		struct ComposeCostProto_s compose;
		uint64_t out_time;

		virtual void write_to_pbmsg(::proto_ff::ItemProtoInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemProtoInfo & msg);
		static ::proto_ff::ItemProtoInfo* new_pbmsg(){ return new ::proto_ff::ItemProtoInfo(); }
		static ::proto_ff::ItemProtoInfo make_pbmsg(){ return ::proto_ff::ItemProtoInfo(); }
	};
	typedef struct ItemProtoInfo_s ItemProtoInfo_t;

	struct CharacterDBPackageBag_s : public NFDescStoreSeqOP {
		CharacterDBPackageBag_s();
		int CreateInit();
		int ResumeInit();
		uint32_t package_type;
		uint32_t expand_num;
		NFArray<struct ItemProtoInfo_s, 128> items;
		int32_t offset;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPackageBag & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPackageBag & msg);
		static ::proto_ff::CharacterDBPackageBag* new_pbmsg(){ return new ::proto_ff::CharacterDBPackageBag(); }
		static ::proto_ff::CharacterDBPackageBag make_pbmsg(){ return ::proto_ff::CharacterDBPackageBag(); }
	};
	typedef struct CharacterDBPackageBag_s CharacterDBPackageBag_t;

	struct CharacterDBPackageData_s : public NFDescStoreSeqOP {
		CharacterDBPackageData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBPackageBag_s, 128> bags;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPackageData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPackageData & msg);
		static ::proto_ff::CharacterDBPackageData* new_pbmsg(){ return new ::proto_ff::CharacterDBPackageData(); }
		static ::proto_ff::CharacterDBPackageData make_pbmsg(){ return ::proto_ff::CharacterDBPackageData(); }
	};
	typedef struct CharacterDBPackageData_s CharacterDBPackageData_t;

	struct tbRoleInfo_s : public NFDescStoreSeqOP {
		tbRoleInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t charId;
		uint64_t playerId;
		uint64_t bornZoneId;
		NFSizeString<128> charName;
		NFSizeString<128> platId;
		struct CharacterDBBaseInfo_s baseData;
		struct CharacterDBPackageData_s itemData;

		virtual void write_to_pbmsg(::proto_ff::tbRoleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbRoleInfo & msg);
		static ::proto_ff::tbRoleInfo* new_pbmsg(){ return new ::proto_ff::tbRoleInfo(); }
		static ::proto_ff::tbRoleInfo make_pbmsg(){ return ::proto_ff::tbRoleInfo(); }
	};
	typedef struct tbRoleInfo_s tbRoleInfo_t;

}

