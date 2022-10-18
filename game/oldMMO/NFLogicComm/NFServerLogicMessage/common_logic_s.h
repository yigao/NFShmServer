#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "common_logic.pb.h"
#include "common_logic_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

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
		NFArray<struct CharTrimProto_s, 12> trim_lst;

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

	struct AttrEx64_s : public NFDescStoreSeqOP {
		AttrEx64_s();
		int CreateInit();
		int ResumeInit();
		uint32_t AttrNum;
		uint64_t Attrvalue;
		uint32_t AttrIndex;

		virtual void write_to_pbmsg(::proto_ff::AttrEx64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AttrEx64 & msg);
		static ::proto_ff::AttrEx64* new_pbmsg(){ return new ::proto_ff::AttrEx64(); }
		static ::proto_ff::AttrEx64 make_pbmsg(){ return ::proto_ff::AttrEx64(); }
	};
	typedef struct AttrEx64_s AttrEx64_t;

	struct FieldItemAttrInfo_s : public NFDescStoreSeqOP {
		FieldItemAttrInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct Attr_s, 12> base_attr;
		NFArray<struct Attr_s, 12> star_attr;
		NFArray<struct Attr_s, 12> blue_star_attr;
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
		NFArray<struct ComposeSingleCostProto_s, 12> info;

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
		NFArray<struct Attr_s, 12> baseattr;
		int32_t index;
		int32_t level;
		NFArray<struct Attr_s, 12> refineex;
		NFArray<struct blustarAttr_s, 12> con_attr;
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
		NFArray<struct ItemProtoInfo_s, 12> items;
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
		NFArray<struct CharacterDBPackageBag_s, 12> bags;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPackageData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPackageData & msg);
		static ::proto_ff::CharacterDBPackageData* new_pbmsg(){ return new ::proto_ff::CharacterDBPackageData(); }
		static ::proto_ff::CharacterDBPackageData make_pbmsg(){ return ::proto_ff::CharacterDBPackageData(); }
	};
	typedef struct CharacterDBPackageData_s CharacterDBPackageData_t;

	struct CharacterDBMissionItemInfo_s : public NFDescStoreSeqOP {
		CharacterDBMissionItemInfo_s();
		int CreateInit();
		int ResumeInit();
		uint32_t type;
		uint64_t id;
		uint32_t currentValue;
		uint32_t finalValue;
		bool completedFlag;
		uint64_t parma1;
		uint64_t parma2;
		uint64_t parma3;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMissionItemInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMissionItemInfo & msg);
		static ::proto_ff::CharacterDBMissionItemInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBMissionItemInfo(); }
		static ::proto_ff::CharacterDBMissionItemInfo make_pbmsg(){ return ::proto_ff::CharacterDBMissionItemInfo(); }
	};
	typedef struct CharacterDBMissionItemInfo_s CharacterDBMissionItemInfo_t;

	struct CharacterDBMissionTrack_s : public NFDescStoreSeqOP {
		CharacterDBMissionTrack_s();
		int CreateInit();
		int ResumeInit();
		uint64_t missionId;
		uint64_t dynamicid;
		uint32_t status;
		uint64_t acceptMissionTime;
		NFArray<struct CharacterDBMissionItemInfo_s, 12> itemInfo;
		uint64_t textid;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMissionTrack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMissionTrack & msg);
		static ::proto_ff::CharacterDBMissionTrack* new_pbmsg(){ return new ::proto_ff::CharacterDBMissionTrack(); }
		static ::proto_ff::CharacterDBMissionTrack make_pbmsg(){ return ::proto_ff::CharacterDBMissionTrack(); }
	};
	typedef struct CharacterDBMissionTrack_s CharacterDBMissionTrack_t;

	struct CharacterDBDyMissionInfo_s : public NFDescStoreSeqOP {
		CharacterDBDyMissionInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t mission_type;
		uint64_t lastfresh;
		int32_t accept_num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDyMissionInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionInfo & msg);
		static ::proto_ff::CharacterDBDyMissionInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBDyMissionInfo(); }
		static ::proto_ff::CharacterDBDyMissionInfo make_pbmsg(){ return ::proto_ff::CharacterDBDyMissionInfo(); }
	};
	typedef struct CharacterDBDyMissionInfo_s CharacterDBDyMissionInfo_t;

	struct CharacterDBRecentSubmitMission_s : public NFDescStoreSeqOP {
		CharacterDBRecentSubmitMission_s();
		int CreateInit();
		int ResumeInit();
		int32_t mission_type;
		uint64_t mission_id;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBRecentSubmitMission & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBRecentSubmitMission & msg);
		static ::proto_ff::CharacterDBRecentSubmitMission* new_pbmsg(){ return new ::proto_ff::CharacterDBRecentSubmitMission(); }
		static ::proto_ff::CharacterDBRecentSubmitMission make_pbmsg(){ return ::proto_ff::CharacterDBRecentSubmitMission(); }
	};
	typedef struct CharacterDBRecentSubmitMission_s CharacterDBRecentSubmitMission_t;

	struct CharacterDBTaskData_s : public NFDescStoreSeqOP {
		CharacterDBTaskData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBMissionTrack_s, 12> missionTrack;
		NFArray<struct CharacterDBDyMissionInfo_s, 12> dyinfo;
		NFArray<uint64_t, 12> already_submit;
		NFArray<struct CharacterDBRecentSubmitMission_s, 12> recent_submit;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBTaskData & msg);
		static ::proto_ff::CharacterDBTaskData* new_pbmsg(){ return new ::proto_ff::CharacterDBTaskData(); }
		static ::proto_ff::CharacterDBTaskData make_pbmsg(){ return ::proto_ff::CharacterDBTaskData(); }
	};
	typedef struct CharacterDBTaskData_s CharacterDBTaskData_t;

	struct CharacterDBSkillItem_s : public NFDescStoreSeqOP {
		CharacterDBSkillItem_s();
		int CreateInit();
		int ResumeInit();
		int64_t skillID;
		int32_t skillLevel;
		uint64_t cd;
		int32_t unlock;
		int64_t replace_skillid;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSkillItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSkillItem & msg);
		static ::proto_ff::CharacterDBSkillItem* new_pbmsg(){ return new ::proto_ff::CharacterDBSkillItem(); }
		static ::proto_ff::CharacterDBSkillItem make_pbmsg(){ return ::proto_ff::CharacterDBSkillItem(); }
	};
	typedef struct CharacterDBSkillItem_s CharacterDBSkillItem_t;

	struct CharacterDBSkillData_s : public NFDescStoreSeqOP {
		CharacterDBSkillData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBSkillItem_s, 20> skillList;
		NFArray<uint32_t, 12> skillAttrs;
		NFArray<int64_t, 12> skillslot;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSkillData & msg);
		static ::proto_ff::CharacterDBSkillData* new_pbmsg(){ return new ::proto_ff::CharacterDBSkillData(); }
		static ::proto_ff::CharacterDBSkillData make_pbmsg(){ return ::proto_ff::CharacterDBSkillData(); }
	};
	typedef struct CharacterDBSkillData_s CharacterDBSkillData_t;

	struct CharacterDBAttrDetailInfo_s : public NFDescStoreSeqOP {
		CharacterDBAttrDetailInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct Attr64_s, 12> attrs;
		struct Vector3PB_s cur_pos;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBAttrDetailInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBAttrDetailInfo & msg);
		static ::proto_ff::CharacterDBAttrDetailInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBAttrDetailInfo(); }
		static ::proto_ff::CharacterDBAttrDetailInfo make_pbmsg(){ return ::proto_ff::CharacterDBAttrDetailInfo(); }
	};
	typedef struct CharacterDBAttrDetailInfo_s CharacterDBAttrDetailInfo_t;

	struct CharacterDBExtendData_s : public NFDescStoreSeqOP {
		CharacterDBExtendData_s();
		int CreateInit();
		int ResumeInit();
		struct CharacterDBAttrDetailInfo_s attr_detail;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBExtendData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBExtendData & msg);
		static ::proto_ff::CharacterDBExtendData* new_pbmsg(){ return new ::proto_ff::CharacterDBExtendData(); }
		static ::proto_ff::CharacterDBExtendData make_pbmsg(){ return ::proto_ff::CharacterDBExtendData(); }
	};
	typedef struct CharacterDBExtendData_s CharacterDBExtendData_t;

	struct EquipSlotProto_s : public NFDescStoreSeqOP {
		EquipSlotProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t index;
		int32_t strenlv;
		int32_t refinelv;
		NFArray<uint64_t, 12> inlay;
		int32_t strenexp;
		int32_t refineexp;
		NFArray<struct Attr_s, 12> strenAttr;
		int64_t refinepecent;
		int32_t scrutinyTrepanningNum;
		NFArray<struct AttrEx64_s, 12> scrutinyAttr;
		int32_t clearStep;
		int64_t clearCombat;
		int32_t suitlv;
		int32_t suit_record_max_lv;
		int32_t awaklv;
		int32_t enchantinglv;

		virtual void write_to_pbmsg(::proto_ff::EquipSlotProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipSlotProto & msg);
		static ::proto_ff::EquipSlotProto* new_pbmsg(){ return new ::proto_ff::EquipSlotProto(); }
		static ::proto_ff::EquipSlotProto make_pbmsg(){ return ::proto_ff::EquipSlotProto(); }
	};
	typedef struct EquipSlotProto_s EquipSlotProto_t;

	struct CharacterDBEquipData_s : public NFDescStoreSeqOP {
		CharacterDBEquipData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ItemProtoInfo_s, 12> equip;
		NFArray<struct EquipSlotProto_s, 12> equip_slot;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBEquipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBEquipData & msg);
		static ::proto_ff::CharacterDBEquipData* new_pbmsg(){ return new ::proto_ff::CharacterDBEquipData(); }
		static ::proto_ff::CharacterDBEquipData make_pbmsg(){ return ::proto_ff::CharacterDBEquipData(); }
	};
	typedef struct CharacterDBEquipData_s CharacterDBEquipData_t;

	struct DuplicateSingleProto_s : public NFDescStoreSeqOP {
		DuplicateSingleProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t duplicate_id;
		int32_t star;
		int32_t cur_layer;

		virtual void write_to_pbmsg(::proto_ff::DuplicateSingleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DuplicateSingleProto & msg);
		static ::proto_ff::DuplicateSingleProto* new_pbmsg(){ return new ::proto_ff::DuplicateSingleProto(); }
		static ::proto_ff::DuplicateSingleProto make_pbmsg(){ return ::proto_ff::DuplicateSingleProto(); }
	};
	typedef struct DuplicateSingleProto_s DuplicateSingleProto_t;

	struct DuplicateGroupProto_s : public NFDescStoreSeqOP {
		DuplicateGroupProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t group_id;
		int32_t enter_num;
		int32_t total_num;
		int32_t buy_num;
		uint64_t last_fresh;

		virtual void write_to_pbmsg(::proto_ff::DuplicateGroupProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DuplicateGroupProto & msg);
		static ::proto_ff::DuplicateGroupProto* new_pbmsg(){ return new ::proto_ff::DuplicateGroupProto(); }
		static ::proto_ff::DuplicateGroupProto make_pbmsg(){ return ::proto_ff::DuplicateGroupProto(); }
	};
	typedef struct DuplicateGroupProto_s DuplicateGroupProto_t;

	struct DuplicateLadderExProto_s : public NFDescStoreSeqOP {
		DuplicateLadderExProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t cur_layer;
		uint64_t last_mail_time;

		virtual void write_to_pbmsg(::proto_ff::DuplicateLadderExProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DuplicateLadderExProto & msg);
		static ::proto_ff::DuplicateLadderExProto* new_pbmsg(){ return new ::proto_ff::DuplicateLadderExProto(); }
		static ::proto_ff::DuplicateLadderExProto make_pbmsg(){ return ::proto_ff::DuplicateLadderExProto(); }
	};
	typedef struct DuplicateLadderExProto_s DuplicateLadderExProto_t;

	struct DupHistoryExpProto_s : public NFDescStoreSeqOP {
		DupHistoryExpProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t duplicate_id;
		uint64_t exp;

		virtual void write_to_pbmsg(::proto_ff::DupHistoryExpProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupHistoryExpProto & msg);
		static ::proto_ff::DupHistoryExpProto* new_pbmsg(){ return new ::proto_ff::DupHistoryExpProto(); }
		static ::proto_ff::DupHistoryExpProto make_pbmsg(){ return ::proto_ff::DupHistoryExpProto(); }
	};
	typedef struct DupHistoryExpProto_s DupHistoryExpProto_t;

	struct DupUnionBossDBProto_s : public NFDescStoreSeqOP {
		DupUnionBossDBProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<uint64_t, 12> mutex_id;
		uint64_t last_pass;
		uint64_t last_fail;

		virtual void write_to_pbmsg(::proto_ff::DupUnionBossDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupUnionBossDBProto & msg);
		static ::proto_ff::DupUnionBossDBProto* new_pbmsg(){ return new ::proto_ff::DupUnionBossDBProto(); }
		static ::proto_ff::DupUnionBossDBProto make_pbmsg(){ return ::proto_ff::DupUnionBossDBProto(); }
	};
	typedef struct DupUnionBossDBProto_s DupUnionBossDBProto_t;

	struct DupPalaceFetchDBProto_s : public NFDescStoreSeqOP {
		DupPalaceFetchDBProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t layer;
		int32_t pass_num;
		NFArray<uint32_t, 12> num_lst;

		virtual void write_to_pbmsg(::proto_ff::DupPalaceFetchDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupPalaceFetchDBProto & msg);
		static ::proto_ff::DupPalaceFetchDBProto* new_pbmsg(){ return new ::proto_ff::DupPalaceFetchDBProto(); }
		static ::proto_ff::DupPalaceFetchDBProto make_pbmsg(){ return ::proto_ff::DupPalaceFetchDBProto(); }
	};
	typedef struct DupPalaceFetchDBProto_s DupPalaceFetchDBProto_t;

	struct DupPalaceMultFetchDBProto_s : public NFDescStoreSeqOP {
		DupPalaceMultFetchDBProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct DupPalaceFetchDBProto_s, 12> fetch_progress;

		virtual void write_to_pbmsg(::proto_ff::DupPalaceMultFetchDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupPalaceMultFetchDBProto & msg);
		static ::proto_ff::DupPalaceMultFetchDBProto* new_pbmsg(){ return new ::proto_ff::DupPalaceMultFetchDBProto(); }
		static ::proto_ff::DupPalaceMultFetchDBProto make_pbmsg(){ return ::proto_ff::DupPalaceMultFetchDBProto(); }
	};
	typedef struct DupPalaceMultFetchDBProto_s DupPalaceMultFetchDBProto_t;

	struct DupUnionPalaceDBProto_s : public NFDescStoreSeqOP {
		DupUnionPalaceDBProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t layer;
		NFArray<int32_t, 12> fetched_lst;
		struct DupPalaceMultFetchDBProto_s fetch;
		int32_t break_count;

		virtual void write_to_pbmsg(::proto_ff::DupUnionPalaceDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupUnionPalaceDBProto & msg);
		static ::proto_ff::DupUnionPalaceDBProto* new_pbmsg(){ return new ::proto_ff::DupUnionPalaceDBProto(); }
		static ::proto_ff::DupUnionPalaceDBProto make_pbmsg(){ return ::proto_ff::DupUnionPalaceDBProto(); }
	};
	typedef struct DupUnionPalaceDBProto_s DupUnionPalaceDBProto_t;

	struct CharacterDBDuplicateData_s : public NFDescStoreSeqOP {
		CharacterDBDuplicateData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct DuplicateSingleProto_s, 12> duplicate;
		NFArray<struct DuplicateGroupProto_s, 12> group;
		NFArray<uint32_t, 12> open_dup;
		struct DuplicateLadderExProto_s ladder;
		NFArray<struct DupHistoryExpProto_s, 12> dup_exp;
		struct DupUnionBossDBProto_s union_boss;
		struct DupUnionPalaceDBProto_s palace;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDuplicateData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDuplicateData & msg);
		static ::proto_ff::CharacterDBDuplicateData* new_pbmsg(){ return new ::proto_ff::CharacterDBDuplicateData(); }
		static ::proto_ff::CharacterDBDuplicateData make_pbmsg(){ return ::proto_ff::CharacterDBDuplicateData(); }
	};
	typedef struct CharacterDBDuplicateData_s CharacterDBDuplicateData_t;

	struct SingleAchievementDBData_s : public NFDescStoreSeqOP {
		SingleAchievementDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t status;
		uint32_t completeCount;

		virtual void write_to_pbmsg(::proto_ff::SingleAchievementDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SingleAchievementDBData & msg);
		static ::proto_ff::SingleAchievementDBData* new_pbmsg(){ return new ::proto_ff::SingleAchievementDBData(); }
		static ::proto_ff::SingleAchievementDBData make_pbmsg(){ return ::proto_ff::SingleAchievementDBData(); }
	};
	typedef struct SingleAchievementDBData_s SingleAchievementDBData_t;

	struct GroupAchievementDBData_s : public NFDescStoreSeqOP {
		GroupAchievementDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t sortType;
		NFArray<struct SingleAchievementDBData_s, 12> achievementInfoList;
		uint32_t achievementReward;

		virtual void write_to_pbmsg(::proto_ff::GroupAchievementDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GroupAchievementDBData & msg);
		static ::proto_ff::GroupAchievementDBData* new_pbmsg(){ return new ::proto_ff::GroupAchievementDBData(); }
		static ::proto_ff::GroupAchievementDBData make_pbmsg(){ return ::proto_ff::GroupAchievementDBData(); }
	};
	typedef struct GroupAchievementDBData_s GroupAchievementDBData_t;

	struct CharacterAchievementDBData_s : public NFDescStoreSeqOP {
		CharacterAchievementDBData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GroupAchievementDBData_s, 12> groupAchievementData;

		virtual void write_to_pbmsg(::proto_ff::CharacterAchievementDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterAchievementDBData & msg);
		static ::proto_ff::CharacterAchievementDBData* new_pbmsg(){ return new ::proto_ff::CharacterAchievementDBData(); }
		static ::proto_ff::CharacterAchievementDBData make_pbmsg(){ return ::proto_ff::CharacterAchievementDBData(); }
	};
	typedef struct CharacterAchievementDBData_s CharacterAchievementDBData_t;

	struct EffectParamProto_s : public NFDescStoreSeqOP {
		EffectParamProto_s();
		int CreateInit();
		int ResumeInit();
		int64_t param1;
		int64_t param2;

		virtual void write_to_pbmsg(::proto_ff::EffectParamProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EffectParamProto & msg);
		static ::proto_ff::EffectParamProto* new_pbmsg(){ return new ::proto_ff::EffectParamProto(); }
		static ::proto_ff::EffectParamProto make_pbmsg(){ return ::proto_ff::EffectParamProto(); }
	};
	typedef struct EffectParamProto_s EffectParamProto_t;

	struct MultEffectParamProto_s : public NFDescStoreSeqOP {
		MultEffectParamProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct EffectParamProto_s, 128> param_lst;

		virtual void write_to_pbmsg(::proto_ff::MultEffectParamProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MultEffectParamProto & msg);
		static ::proto_ff::MultEffectParamProto* new_pbmsg(){ return new ::proto_ff::MultEffectParamProto(); }
		static ::proto_ff::MultEffectParamProto make_pbmsg(){ return ::proto_ff::MultEffectParamProto(); }
	};
	typedef struct MultEffectParamProto_s MultEffectParamProto_t;

	struct BuffBagInfo_s : public NFDescStoreSeqOP {
		BuffBagInfo_s();
		int CreateInit();
		int ResumeInit();
		uint32_t buffBagInstId;
		uint64_t stateBagId;
		uint32_t stateBagTime;
		uint32_t delayedTime;
		bool isForever;
		uint64_t skillId;
		uint32_t skillLevel;
		uint64_t senderCid;
		NFArray<uint64_t, 12> params;
		uint32_t status;
		uint32_t targettype;
		uint64_t startTime;
		struct MultEffectParamProto_s eparam;

		virtual void write_to_pbmsg(::proto_ff::BuffBagInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffBagInfo & msg);
		static ::proto_ff::BuffBagInfo* new_pbmsg(){ return new ::proto_ff::BuffBagInfo(); }
		static ::proto_ff::BuffBagInfo make_pbmsg(){ return ::proto_ff::BuffBagInfo(); }
	};
	typedef struct BuffBagInfo_s BuffBagInfo_t;

	struct CharacterBuffData_s : public NFDescStoreSeqOP {
		CharacterBuffData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct BuffBagInfo_s, 12> delayedBag;
		NFArray<struct BuffBagInfo_s, 12> buffbagLst;

		virtual void write_to_pbmsg(::proto_ff::CharacterBuffData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterBuffData & msg);
		static ::proto_ff::CharacterBuffData* new_pbmsg(){ return new ::proto_ff::CharacterBuffData(); }
		static ::proto_ff::CharacterBuffData make_pbmsg(){ return ::proto_ff::CharacterBuffData(); }
	};
	typedef struct CharacterBuffData_s CharacterBuffData_t;

	struct CharacterArenaData_s : public NFDescStoreSeqOP {
		CharacterArenaData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t challengeTimes;
		uint64_t updateTime;
		uint32_t historyRankId;
		uint32_t buyChallengeTimes;

		virtual void write_to_pbmsg(::proto_ff::CharacterArenaData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterArenaData & msg);
		static ::proto_ff::CharacterArenaData* new_pbmsg(){ return new ::proto_ff::CharacterArenaData(); }
		static ::proto_ff::CharacterArenaData make_pbmsg(){ return ::proto_ff::CharacterArenaData(); }
	};
	typedef struct CharacterArenaData_s CharacterArenaData_t;

	struct CharacterTitleInfo_s : public NFDescStoreSeqOP {
		CharacterTitleInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t param;
		uint64_t startTime;
		NFSizeString<128> name;

		virtual void write_to_pbmsg(::proto_ff::CharacterTitleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterTitleInfo & msg);
		static ::proto_ff::CharacterTitleInfo* new_pbmsg(){ return new ::proto_ff::CharacterTitleInfo(); }
		static ::proto_ff::CharacterTitleInfo make_pbmsg(){ return ::proto_ff::CharacterTitleInfo(); }
	};
	typedef struct CharacterTitleInfo_s CharacterTitleInfo_t;

	struct CharacterTitleSaveData_s : public NFDescStoreSeqOP {
		CharacterTitleSaveData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterTitleInfo_s, 12> titelData;

		virtual void write_to_pbmsg(::proto_ff::CharacterTitleSaveData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterTitleSaveData & msg);
		static ::proto_ff::CharacterTitleSaveData* new_pbmsg(){ return new ::proto_ff::CharacterTitleSaveData(); }
		static ::proto_ff::CharacterTitleSaveData make_pbmsg(){ return ::proto_ff::CharacterTitleSaveData(); }
	};
	typedef struct CharacterTitleSaveData_s CharacterTitleSaveData_t;

	struct CharacterDBSingleOperateLimitInfo_s : public NFDescStoreSeqOP {
		CharacterDBSingleOperateLimitInfo_s();
		int CreateInit();
		int ResumeInit();
		uint32_t type;
		uint32_t value;
		uint32_t lastTime;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSingleOperateLimitInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSingleOperateLimitInfo & msg);
		static ::proto_ff::CharacterDBSingleOperateLimitInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBSingleOperateLimitInfo(); }
		static ::proto_ff::CharacterDBSingleOperateLimitInfo make_pbmsg(){ return ::proto_ff::CharacterDBSingleOperateLimitInfo(); }
	};
	typedef struct CharacterDBSingleOperateLimitInfo_s CharacterDBSingleOperateLimitInfo_t;

	struct CharacterDBOperateProto_s : public NFDescStoreSeqOP {
		CharacterDBOperateProto_s();
		int CreateInit();
		int ResumeInit();
		uint32_t id;
		uint64_t num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOperateProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOperateProto & msg);
		static ::proto_ff::CharacterDBOperateProto* new_pbmsg(){ return new ::proto_ff::CharacterDBOperateProto(); }
		static ::proto_ff::CharacterDBOperateProto make_pbmsg(){ return ::proto_ff::CharacterDBOperateProto(); }
	};
	typedef struct CharacterDBOperateProto_s CharacterDBOperateProto_t;

	struct CharacterDBOperateMutProto_s : public NFDescStoreSeqOP {
		CharacterDBOperateMutProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBOperateProto_s, 12> operate_lst;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOperateMutProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOperateMutProto & msg);
		static ::proto_ff::CharacterDBOperateMutProto* new_pbmsg(){ return new ::proto_ff::CharacterDBOperateMutProto(); }
		static ::proto_ff::CharacterDBOperateMutProto make_pbmsg(){ return ::proto_ff::CharacterDBOperateMutProto(); }
	};
	typedef struct CharacterDBOperateMutProto_s CharacterDBOperateMutProto_t;

	struct CharacterDBOperateInfo_s : public NFDescStoreSeqOP {
		CharacterDBOperateInfo_s();
		int CreateInit();
		int ResumeInit();
		struct CharacterDBOperateMutProto_s kill_mons;
		struct CharacterDBOperateMutProto_s last_kill_mons;
		struct CharacterDBOperateMutProto_s attend_act;
		struct CharacterDBOperateMutProto_s last_attend_act;
		struct CharacterDBOperateMutProto_s finish_act;
		struct CharacterDBOperateMutProto_s pass_dup;
		struct CharacterDBOperateMutProto_s coll_action;
		struct CharacterDBOperateMutProto_s make_action;
		struct CharacterDBOperateMutProto_s collect;
		struct CharacterDBOperateMutProto_s make;
		uint64_t make_gold_quip;
		uint64_t identify;
		uint64_t arena_success;
		uint64_t die;
		uint64_t kill_enemy;
		uint64_t kill_enemy_camp;
		uint64_t charge;
		uint64_t gold;
		uint64_t treasure;
		uint64_t pandos_trans;
		uint64_t world_chat;
		uint64_t refine_success;
		uint64_t refine_fail;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOperateInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOperateInfo & msg);
		static ::proto_ff::CharacterDBOperateInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBOperateInfo(); }
		static ::proto_ff::CharacterDBOperateInfo make_pbmsg(){ return ::proto_ff::CharacterDBOperateInfo(); }
	};
	typedef struct CharacterDBOperateInfo_s CharacterDBOperateInfo_t;

	struct CharacterDBOperateLimitInfo_s : public NFDescStoreSeqOP {
		CharacterDBOperateLimitInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBSingleOperateLimitInfo_s, 12> operateLimitInfo;
		struct CharacterDBOperateInfo_s operate_data;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOperateLimitInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOperateLimitInfo & msg);
		static ::proto_ff::CharacterDBOperateLimitInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBOperateLimitInfo(); }
		static ::proto_ff::CharacterDBOperateLimitInfo make_pbmsg(){ return ::proto_ff::CharacterDBOperateLimitInfo(); }
	};
	typedef struct CharacterDBOperateLimitInfo_s CharacterDBOperateLimitInfo_t;

	struct CharacterDBSingleHuoYueDuInfoInfo_s : public NFDescStoreSeqOP {
		CharacterDBSingleHuoYueDuInfoInfo_s();
		int CreateInit();
		int ResumeInit();
		uint32_t type;
		uint32_t value;
		uint32_t time;
		uint32_t sin_process;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSingleHuoYueDuInfoInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo & msg);
		static ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo(); }
		static ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo make_pbmsg(){ return ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo(); }
	};
	typedef struct CharacterDBSingleHuoYueDuInfoInfo_s CharacterDBSingleHuoYueDuInfoInfo_t;

	struct CharacterDBHuoYueDuInfo_s : public NFDescStoreSeqOP {
		CharacterDBHuoYueDuInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBSingleHuoYueDuInfoInfo_s, 12> huoYueDuInfo;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBHuoYueDuInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBHuoYueDuInfo & msg);
		static ::proto_ff::CharacterDBHuoYueDuInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBHuoYueDuInfo(); }
		static ::proto_ff::CharacterDBHuoYueDuInfo make_pbmsg(){ return ::proto_ff::CharacterDBHuoYueDuInfo(); }
	};
	typedef struct CharacterDBHuoYueDuInfo_s CharacterDBHuoYueDuInfo_t;

	struct IndultTaskEntry_s : public NFDescStoreSeqOP {
		IndultTaskEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;
		int32_t cur_num;
		int32_t task_state;

		virtual void write_to_pbmsg(::proto_ff::IndultTaskEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::IndultTaskEntry & msg);
		static ::proto_ff::IndultTaskEntry* new_pbmsg(){ return new ::proto_ff::IndultTaskEntry(); }
		static ::proto_ff::IndultTaskEntry make_pbmsg(){ return ::proto_ff::IndultTaskEntry(); }
	};
	typedef struct IndultTaskEntry_s IndultTaskEntry_t;

	struct IndultTaskGroupEntry_s : public NFDescStoreSeqOP {
		IndultTaskGroupEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t group_cfg_id;
		NFArray<struct IndultTaskEntry_s, 12> entrys;
		int32_t normal_reward_state;

		virtual void write_to_pbmsg(::proto_ff::IndultTaskGroupEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::IndultTaskGroupEntry & msg);
		static ::proto_ff::IndultTaskGroupEntry* new_pbmsg(){ return new ::proto_ff::IndultTaskGroupEntry(); }
		static ::proto_ff::IndultTaskGroupEntry make_pbmsg(){ return ::proto_ff::IndultTaskGroupEntry(); }
	};
	typedef struct IndultTaskGroupEntry_s IndultTaskGroupEntry_t;

	struct ColPointsTaskEntry_s : public NFDescStoreSeqOP {
		ColPointsTaskEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;
		int32_t cur_num;
		int32_t task_state;

		virtual void write_to_pbmsg(::proto_ff::ColPointsTaskEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ColPointsTaskEntry & msg);
		static ::proto_ff::ColPointsTaskEntry* new_pbmsg(){ return new ::proto_ff::ColPointsTaskEntry(); }
		static ::proto_ff::ColPointsTaskEntry make_pbmsg(){ return ::proto_ff::ColPointsTaskEntry(); }
	};
	typedef struct ColPointsTaskEntry_s ColPointsTaskEntry_t;

	struct ColPointsTaskGroupEntry_s : public NFDescStoreSeqOP {
		ColPointsTaskGroupEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t group_cfg_id;
		NFArray<struct ColPointsTaskEntry_s, 12> entrys;
		int32_t normal_reward_state;
		int32_t cur_points;
		uint64_t create_time;

		virtual void write_to_pbmsg(::proto_ff::ColPointsTaskGroupEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ColPointsTaskGroupEntry & msg);
		static ::proto_ff::ColPointsTaskGroupEntry* new_pbmsg(){ return new ::proto_ff::ColPointsTaskGroupEntry(); }
		static ::proto_ff::ColPointsTaskGroupEntry make_pbmsg(){ return ::proto_ff::ColPointsTaskGroupEntry(); }
	};
	typedef struct ColPointsTaskGroupEntry_s ColPointsTaskGroupEntry_t;

	struct ColPointsTaskData_s : public NFDescStoreSeqOP {
		ColPointsTaskData_s();
		int CreateInit();
		int ResumeInit();
		struct ColPointsTaskGroupEntry_s data;
		uint64_t last_refresh_time;
		uint64_t online_time;

		virtual void write_to_pbmsg(::proto_ff::ColPointsTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ColPointsTaskData & msg);
		static ::proto_ff::ColPointsTaskData* new_pbmsg(){ return new ::proto_ff::ColPointsTaskData(); }
		static ::proto_ff::ColPointsTaskData make_pbmsg(){ return ::proto_ff::ColPointsTaskData(); }
	};
	typedef struct ColPointsTaskData_s ColPointsTaskData_t;

	struct WelfareDailySignInDBData_s : public NFDescStoreSeqOP {
		WelfareDailySignInDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t dayIndex;
		uint32_t nState;
		uint64_t lastResetTime;
		bool bRecharge;

		virtual void write_to_pbmsg(::proto_ff::WelfareDailySignInDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareDailySignInDBData & msg);
		static ::proto_ff::WelfareDailySignInDBData* new_pbmsg(){ return new ::proto_ff::WelfareDailySignInDBData(); }
		static ::proto_ff::WelfareDailySignInDBData make_pbmsg(){ return ::proto_ff::WelfareDailySignInDBData(); }
	};
	typedef struct WelfareDailySignInDBData_s WelfareDailySignInDBData_t;

	struct WelfareLoginGiftDBData_s : public NFDescStoreSeqOP {
		WelfareLoginGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t LoninCount;
		uint64_t lastResetTime;
		NFArray<struct ComPair_s, 12> getState;
		uint32_t nState;

		virtual void write_to_pbmsg(::proto_ff::WelfareLoginGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareLoginGiftDBData & msg);
		static ::proto_ff::WelfareLoginGiftDBData* new_pbmsg(){ return new ::proto_ff::WelfareLoginGiftDBData(); }
		static ::proto_ff::WelfareLoginGiftDBData make_pbmsg(){ return ::proto_ff::WelfareLoginGiftDBData(); }
	};
	typedef struct WelfareLoginGiftDBData_s WelfareLoginGiftDBData_t;

	struct WelfareLevelGiftDBData_s : public NFDescStoreSeqOP {
		WelfareLevelGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::WelfareLevelGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareLevelGiftDBData & msg);
		static ::proto_ff::WelfareLevelGiftDBData* new_pbmsg(){ return new ::proto_ff::WelfareLevelGiftDBData(); }
		static ::proto_ff::WelfareLevelGiftDBData make_pbmsg(){ return ::proto_ff::WelfareLevelGiftDBData(); }
	};
	typedef struct WelfareLevelGiftDBData_s WelfareLevelGiftDBData_t;

	struct CommodityEntry_s : public NFDescStoreSeqOP {
		CommodityEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t commodity_id;
		int32_t cur_buy_num;

		virtual void write_to_pbmsg(::proto_ff::CommodityEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CommodityEntry & msg);
		static ::proto_ff::CommodityEntry* new_pbmsg(){ return new ::proto_ff::CommodityEntry(); }
		static ::proto_ff::CommodityEntry make_pbmsg(){ return ::proto_ff::CommodityEntry(); }
	};
	typedef struct CommodityEntry_s CommodityEntry_t;

	struct LimitShopGroupEntry_s : public NFDescStoreSeqOP {
		LimitShopGroupEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t group_cfg_id;
		int32_t open_time;
		NFArray<struct CommodityEntry_s, 12> entrys;

		virtual void write_to_pbmsg(::proto_ff::LimitShopGroupEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitShopGroupEntry & msg);
		static ::proto_ff::LimitShopGroupEntry* new_pbmsg(){ return new ::proto_ff::LimitShopGroupEntry(); }
		static ::proto_ff::LimitShopGroupEntry make_pbmsg(){ return ::proto_ff::LimitShopGroupEntry(); }
	};
	typedef struct LimitShopGroupEntry_s LimitShopGroupEntry_t;

	struct LimitShopData_s : public NFDescStoreSeqOP {
		LimitShopData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct LimitShopGroupEntry_s, 12> groups;

		virtual void write_to_pbmsg(::proto_ff::LimitShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitShopData & msg);
		static ::proto_ff::LimitShopData* new_pbmsg(){ return new ::proto_ff::LimitShopData(); }
		static ::proto_ff::LimitShopData make_pbmsg(){ return ::proto_ff::LimitShopData(); }
	};
	typedef struct LimitShopData_s LimitShopData_t;

	struct LimitTaskEntry_s : public NFDescStoreSeqOP {
		LimitTaskEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;
		int32_t cur_num;
		int32_t task_state;

		virtual void write_to_pbmsg(::proto_ff::LimitTaskEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitTaskEntry & msg);
		static ::proto_ff::LimitTaskEntry* new_pbmsg(){ return new ::proto_ff::LimitTaskEntry(); }
		static ::proto_ff::LimitTaskEntry make_pbmsg(){ return ::proto_ff::LimitTaskEntry(); }
	};
	typedef struct LimitTaskEntry_s LimitTaskEntry_t;

	struct LimitTaskGroupEntry_s : public NFDescStoreSeqOP {
		LimitTaskGroupEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t group_cfg_id;
		int32_t open_time;
		NFArray<struct LimitTaskEntry_s, 12> entrys;
		int32_t normal_reward_state;
		int32_t senior_reward_state;

		virtual void write_to_pbmsg(::proto_ff::LimitTaskGroupEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitTaskGroupEntry & msg);
		static ::proto_ff::LimitTaskGroupEntry* new_pbmsg(){ return new ::proto_ff::LimitTaskGroupEntry(); }
		static ::proto_ff::LimitTaskGroupEntry make_pbmsg(){ return ::proto_ff::LimitTaskGroupEntry(); }
	};
	typedef struct LimitTaskGroupEntry_s LimitTaskGroupEntry_t;

	struct LimitTaskData_s : public NFDescStoreSeqOP {
		LimitTaskData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct LimitTaskGroupEntry_s, 12> groups;

		virtual void write_to_pbmsg(::proto_ff::LimitTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitTaskData & msg);
		static ::proto_ff::LimitTaskData* new_pbmsg(){ return new ::proto_ff::LimitTaskData(); }
		static ::proto_ff::LimitTaskData make_pbmsg(){ return ::proto_ff::LimitTaskData(); }
	};
	typedef struct LimitTaskData_s LimitTaskData_t;

	struct WishDBTypeEntry_s : public NFDescStoreSeqOP {
		WishDBTypeEntry_s();
		int CreateInit();
		int ResumeInit();
		int32_t wish_type;
		int32_t wished_num;
		uint64_t refresh_time;
		uint64_t last_time;

		virtual void write_to_pbmsg(::proto_ff::WishDBTypeEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WishDBTypeEntry & msg);
		static ::proto_ff::WishDBTypeEntry* new_pbmsg(){ return new ::proto_ff::WishDBTypeEntry(); }
		static ::proto_ff::WishDBTypeEntry make_pbmsg(){ return ::proto_ff::WishDBTypeEntry(); }
	};
	typedef struct WishDBTypeEntry_s WishDBTypeEntry_t;

	struct WishDBData_s : public NFDescStoreSeqOP {
		WishDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct WishDBTypeEntry_s, 12> type_entry;

		virtual void write_to_pbmsg(::proto_ff::WishDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WishDBData & msg);
		static ::proto_ff::WishDBData* new_pbmsg(){ return new ::proto_ff::WishDBData(); }
		static ::proto_ff::WishDBData make_pbmsg(){ return ::proto_ff::WishDBData(); }
	};
	typedef struct WishDBData_s WishDBData_t;

	struct FestivalInvestDBData_s : public NFDescStoreSeqOP {
		FestivalInvestDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t nActiveId;
		bool bInvest;
		uint64_t nLastResetTime;
		int32_t nLoninCount;
		NFArray<struct ComPair_s, 12> getState;
		NFArray<struct ComPair_s, 12> params;
		int64_t investTime;

		virtual void write_to_pbmsg(::proto_ff::FestivalInvestDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalInvestDBData & msg);
		static ::proto_ff::FestivalInvestDBData* new_pbmsg(){ return new ::proto_ff::FestivalInvestDBData(); }
		static ::proto_ff::FestivalInvestDBData make_pbmsg(){ return ::proto_ff::FestivalInvestDBData(); }
	};
	typedef struct FestivalInvestDBData_s FestivalInvestDBData_t;

	struct FestivalExchangeDBData_s : public NFDescStoreSeqOP {
		FestivalExchangeDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t nActiveId;
		NFArray<struct ComPair_s, 12> exchangeCount;

		virtual void write_to_pbmsg(::proto_ff::FestivalExchangeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalExchangeDBData & msg);
		static ::proto_ff::FestivalExchangeDBData* new_pbmsg(){ return new ::proto_ff::FestivalExchangeDBData(); }
		static ::proto_ff::FestivalExchangeDBData make_pbmsg(){ return ::proto_ff::FestivalExchangeDBData(); }
	};
	typedef struct FestivalExchangeDBData_s FestivalExchangeDBData_t;

	struct FestivalLoginDBData_s : public NFDescStoreSeqOP {
		FestivalLoginDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t nLastResetTime;
		uint32_t nLoninCount;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::FestivalLoginDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalLoginDBData & msg);
		static ::proto_ff::FestivalLoginDBData* new_pbmsg(){ return new ::proto_ff::FestivalLoginDBData(); }
		static ::proto_ff::FestivalLoginDBData make_pbmsg(){ return ::proto_ff::FestivalLoginDBData(); }
	};
	typedef struct FestivalLoginDBData_s FestivalLoginDBData_t;

	struct FestivalTotalRechargeDBData_s : public NFDescStoreSeqOP {
		FestivalTotalRechargeDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t nRechargeCount;
		NFArray<struct ComPair_s, 12> getState;
		uint32_t nRechargeHoly;

		virtual void write_to_pbmsg(::proto_ff::FestivalTotalRechargeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalTotalRechargeDBData & msg);
		static ::proto_ff::FestivalTotalRechargeDBData* new_pbmsg(){ return new ::proto_ff::FestivalTotalRechargeDBData(); }
		static ::proto_ff::FestivalTotalRechargeDBData make_pbmsg(){ return ::proto_ff::FestivalTotalRechargeDBData(); }
	};
	typedef struct FestivalTotalRechargeDBData_s FestivalTotalRechargeDBData_t;

	struct FestivalConsumptionDBData_s : public NFDescStoreSeqOP {
		FestivalConsumptionDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t nConsumptionValue;
		NFArray<struct ComPair_s, 12> getState;
		uint32_t nConsumptionHoly;
		uint32_t nConsumptionVoucher;

		virtual void write_to_pbmsg(::proto_ff::FestivalConsumptionDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalConsumptionDBData & msg);
		static ::proto_ff::FestivalConsumptionDBData* new_pbmsg(){ return new ::proto_ff::FestivalConsumptionDBData(); }
		static ::proto_ff::FestivalConsumptionDBData make_pbmsg(){ return ::proto_ff::FestivalConsumptionDBData(); }
	};
	typedef struct FestivalConsumptionDBData_s FestivalConsumptionDBData_t;

	struct FestivalKillBossData_s : public NFDescStoreSeqOP {
		FestivalKillBossData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::FestivalKillBossData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalKillBossData & msg);
		static ::proto_ff::FestivalKillBossData* new_pbmsg(){ return new ::proto_ff::FestivalKillBossData(); }
		static ::proto_ff::FestivalKillBossData make_pbmsg(){ return ::proto_ff::FestivalKillBossData(); }
	};
	typedef struct FestivalKillBossData_s FestivalKillBossData_t;

	struct FestivalZhiChongData_s : public NFDescStoreSeqOP {
		FestivalZhiChongData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct ComPair_s, 12> getState;
		NFArray<int64_t, 12> pointList;

		virtual void write_to_pbmsg(::proto_ff::FestivalZhiChongData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalZhiChongData & msg);
		static ::proto_ff::FestivalZhiChongData* new_pbmsg(){ return new ::proto_ff::FestivalZhiChongData(); }
		static ::proto_ff::FestivalZhiChongData make_pbmsg(){ return ::proto_ff::FestivalZhiChongData(); }
	};
	typedef struct FestivalZhiChongData_s FestivalZhiChongData_t;

	struct FestivalPreRechargeData_s : public NFDescStoreSeqOP {
		FestivalPreRechargeData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct ComPair_s, 12> buy;
		NFArray<int64_t, 12> pointList;

		virtual void write_to_pbmsg(::proto_ff::FestivalPreRechargeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalPreRechargeData & msg);
		static ::proto_ff::FestivalPreRechargeData* new_pbmsg(){ return new ::proto_ff::FestivalPreRechargeData(); }
		static ::proto_ff::FestivalPreRechargeData make_pbmsg(){ return ::proto_ff::FestivalPreRechargeData(); }
	};
	typedef struct FestivalPreRechargeData_s FestivalPreRechargeData_t;

	struct FestivalSuperDBData_s : public NFDescStoreSeqOP {
		FestivalSuperDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t nLastResetTime;
		uint32_t nLoninCount;
		int32_t getId;
		int32_t active_state;

		virtual void write_to_pbmsg(::proto_ff::FestivalSuperDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalSuperDBData & msg);
		static ::proto_ff::FestivalSuperDBData* new_pbmsg(){ return new ::proto_ff::FestivalSuperDBData(); }
		static ::proto_ff::FestivalSuperDBData make_pbmsg(){ return ::proto_ff::FestivalSuperDBData(); }
	};
	typedef struct FestivalSuperDBData_s FestivalSuperDBData_t;

	struct FestivalSuperDoubleDBData_s : public NFDescStoreSeqOP {
		FestivalSuperDoubleDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t nLastResetTime;
		uint32_t curGiftId;
		int32_t curGiftState;
		int32_t curDailyState;

		virtual void write_to_pbmsg(::proto_ff::FestivalSuperDoubleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalSuperDoubleDBData & msg);
		static ::proto_ff::FestivalSuperDoubleDBData* new_pbmsg(){ return new ::proto_ff::FestivalSuperDoubleDBData(); }
		static ::proto_ff::FestivalSuperDoubleDBData make_pbmsg(){ return ::proto_ff::FestivalSuperDoubleDBData(); }
	};
	typedef struct FestivalSuperDoubleDBData_s FestivalSuperDoubleDBData_t;

	struct FestivalHuoYueDuDBData_s : public NFDescStoreSeqOP {
		FestivalHuoYueDuDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t nHuoYueDu;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::FestivalHuoYueDuDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalHuoYueDuDBData & msg);
		static ::proto_ff::FestivalHuoYueDuDBData* new_pbmsg(){ return new ::proto_ff::FestivalHuoYueDuDBData(); }
		static ::proto_ff::FestivalHuoYueDuDBData make_pbmsg(){ return ::proto_ff::FestivalHuoYueDuDBData(); }
	};
	typedef struct FestivalHuoYueDuDBData_s FestivalHuoYueDuDBData_t;

	struct FestivalFirstRechargeDBData_s : public NFDescStoreSeqOP {
		FestivalFirstRechargeDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t rechargeTime;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::FestivalFirstRechargeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalFirstRechargeDBData & msg);
		static ::proto_ff::FestivalFirstRechargeDBData* new_pbmsg(){ return new ::proto_ff::FestivalFirstRechargeDBData(); }
		static ::proto_ff::FestivalFirstRechargeDBData make_pbmsg(){ return ::proto_ff::FestivalFirstRechargeDBData(); }
	};
	typedef struct FestivalFirstRechargeDBData_s FestivalFirstRechargeDBData_t;

	struct FestivalYanHuaDBData_s : public NFDescStoreSeqOP {
		FestivalYanHuaDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<uint64_t, 12> getItems;

		virtual void write_to_pbmsg(::proto_ff::FestivalYanHuaDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalYanHuaDBData & msg);
		static ::proto_ff::FestivalYanHuaDBData* new_pbmsg(){ return new ::proto_ff::FestivalYanHuaDBData(); }
		static ::proto_ff::FestivalYanHuaDBData make_pbmsg(){ return ::proto_ff::FestivalYanHuaDBData(); }
	};
	typedef struct FestivalYanHuaDBData_s FestivalYanHuaDBData_t;

	struct FestivalBigYanHuaDBData_s : public NFDescStoreSeqOP {
		FestivalBigYanHuaDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<uint64_t, 12> getItems;

		virtual void write_to_pbmsg(::proto_ff::FestivalBigYanHuaDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalBigYanHuaDBData & msg);
		static ::proto_ff::FestivalBigYanHuaDBData* new_pbmsg(){ return new ::proto_ff::FestivalBigYanHuaDBData(); }
		static ::proto_ff::FestivalBigYanHuaDBData make_pbmsg(){ return ::proto_ff::FestivalBigYanHuaDBData(); }
	};
	typedef struct FestivalBigYanHuaDBData_s FestivalBigYanHuaDBData_t;

	struct FestivalShopDBData_s : public NFDescStoreSeqOP {
		FestivalShopDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct ComPair64_s, 12> buyCount;

		virtual void write_to_pbmsg(::proto_ff::FestivalShopDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalShopDBData & msg);
		static ::proto_ff::FestivalShopDBData* new_pbmsg(){ return new ::proto_ff::FestivalShopDBData(); }
		static ::proto_ff::FestivalShopDBData make_pbmsg(){ return ::proto_ff::FestivalShopDBData(); }
	};
	typedef struct FestivalShopDBData_s FestivalShopDBData_t;

	struct LimitGiftDBData_s : public NFDescStoreSeqOP {
		LimitGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t giftId;
		uint64_t buyTime;
		uint32_t getState;
		uint32_t totalBack;
		uint32_t openTime;
		uint64_t lastResetTime;

		virtual void write_to_pbmsg(::proto_ff::LimitGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitGiftDBData & msg);
		static ::proto_ff::LimitGiftDBData* new_pbmsg(){ return new ::proto_ff::LimitGiftDBData(); }
		static ::proto_ff::LimitGiftDBData make_pbmsg(){ return ::proto_ff::LimitGiftDBData(); }
	};
	typedef struct LimitGiftDBData_s LimitGiftDBData_t;

	struct LimitGiftActiveDBData_s : public NFDescStoreSeqOP {
		LimitGiftActiveDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		bool isFinish;
		NFArray<struct LimitGiftDBData_s, 12> giftList;

		virtual void write_to_pbmsg(::proto_ff::LimitGiftActiveDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LimitGiftActiveDBData & msg);
		static ::proto_ff::LimitGiftActiveDBData* new_pbmsg(){ return new ::proto_ff::LimitGiftActiveDBData(); }
		static ::proto_ff::LimitGiftActiveDBData make_pbmsg(){ return ::proto_ff::LimitGiftActiveDBData(); }
	};
	typedef struct LimitGiftActiveDBData_s LimitGiftActiveDBData_t;

	struct FRechargeDBData_s : public NFDescStoreSeqOP {
		FRechargeDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t pointId;
		uint32_t state;

		virtual void write_to_pbmsg(::proto_ff::FRechargeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FRechargeDBData & msg);
		static ::proto_ff::FRechargeDBData* new_pbmsg(){ return new ::proto_ff::FRechargeDBData(); }
		static ::proto_ff::FRechargeDBData make_pbmsg(){ return ::proto_ff::FRechargeDBData(); }
	};
	typedef struct FRechargeDBData_s FRechargeDBData_t;

	struct FRechargeActiveDBData_s : public NFDescStoreSeqOP {
		FRechargeActiveDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct FRechargeDBData_s, 12> dataList;

		virtual void write_to_pbmsg(::proto_ff::FRechargeActiveDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FRechargeActiveDBData & msg);
		static ::proto_ff::FRechargeActiveDBData* new_pbmsg(){ return new ::proto_ff::FRechargeActiveDBData(); }
		static ::proto_ff::FRechargeActiveDBData make_pbmsg(){ return ::proto_ff::FRechargeActiveDBData(); }
	};
	typedef struct FRechargeActiveDBData_s FRechargeActiveDBData_t;

	struct FSmashEggDBData_s : public NFDescStoreSeqOP {
		FSmashEggDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t itemId;
		uint32_t position;
		uint32_t quality;
		uint32_t itemNum;

		virtual void write_to_pbmsg(::proto_ff::FSmashEggDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FSmashEggDBData & msg);
		static ::proto_ff::FSmashEggDBData* new_pbmsg(){ return new ::proto_ff::FSmashEggDBData(); }
		static ::proto_ff::FSmashEggDBData make_pbmsg(){ return ::proto_ff::FSmashEggDBData(); }
	};
	typedef struct FSmashEggDBData_s FSmashEggDBData_t;

	struct FestivalSmashEggDBData_s : public NFDescStoreSeqOP {
		FestivalSmashEggDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t smashCount;
		uint64_t smashCountToday;
		uint64_t freeTimeDeadLine;
		uint32_t addRateCount;
		uint32_t resetRewardTime;
		NFArray<struct FSmashEggDBData_s, 12> eggData;
		NFArray<struct ComPair_s, 12> rewardGetState;
		int32_t daynum;
		int64_t lastTime;

		virtual void write_to_pbmsg(::proto_ff::FestivalSmashEggDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalSmashEggDBData & msg);
		static ::proto_ff::FestivalSmashEggDBData* new_pbmsg(){ return new ::proto_ff::FestivalSmashEggDBData(); }
		static ::proto_ff::FestivalSmashEggDBData make_pbmsg(){ return ::proto_ff::FestivalSmashEggDBData(); }
	};
	typedef struct FestivalSmashEggDBData_s FestivalSmashEggDBData_t;

	struct OperateReward_s : public NFDescStoreSeqOP {
		OperateReward_s();
		int CreateInit();
		int ResumeInit();
		uint64_t key_id;
		bool isFinish;
		bool isReceiveReward;
		struct ComPair_s rechargeDays;

		virtual void write_to_pbmsg(::proto_ff::OperateReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateReward & msg);
		static ::proto_ff::OperateReward* new_pbmsg(){ return new ::proto_ff::OperateReward(); }
		static ::proto_ff::OperateReward make_pbmsg(){ return ::proto_ff::OperateReward(); }
	};
	typedef struct OperateReward_s OperateReward_t;

	struct OperateDailyRechargeData_s : public NFDescStoreSeqOP {
		OperateDailyRechargeData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t rmbToday;
		uint32_t rmbTotal;
		uint32_t lastRechargeDate;
		NFArray<struct OperateReward_s, 12> list;

		virtual void write_to_pbmsg(::proto_ff::OperateDailyRechargeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateDailyRechargeData & msg);
		static ::proto_ff::OperateDailyRechargeData* new_pbmsg(){ return new ::proto_ff::OperateDailyRechargeData(); }
		static ::proto_ff::OperateDailyRechargeData make_pbmsg(){ return ::proto_ff::OperateDailyRechargeData(); }
	};
	typedef struct OperateDailyRechargeData_s OperateDailyRechargeData_t;

	struct OperateMoonCardData_s : public NFDescStoreSeqOP {
		OperateMoonCardData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t buyDate;
		NFArray<struct OperateReward_s, 12> list;

		virtual void write_to_pbmsg(::proto_ff::OperateMoonCardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateMoonCardData & msg);
		static ::proto_ff::OperateMoonCardData* new_pbmsg(){ return new ::proto_ff::OperateMoonCardData(); }
		static ::proto_ff::OperateMoonCardData make_pbmsg(){ return ::proto_ff::OperateMoonCardData(); }
	};
	typedef struct OperateMoonCardData_s OperateMoonCardData_t;

	struct OperateFundData_s : public NFDescStoreSeqOP {
		OperateFundData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t level;
		uint32_t buyDate;
		NFArray<struct OperateReward_s, 12> list;

		virtual void write_to_pbmsg(::proto_ff::OperateFundData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateFundData & msg);
		static ::proto_ff::OperateFundData* new_pbmsg(){ return new ::proto_ff::OperateFundData(); }
		static ::proto_ff::OperateFundData make_pbmsg(){ return ::proto_ff::OperateFundData(); }
	};
	typedef struct OperateFundData_s OperateFundData_t;

	struct OperateFirstRechargeType_s : public NFDescStoreSeqOP {
		OperateFirstRechargeType_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		uint64_t updateTime;
		int32_t loginDay;

		virtual void write_to_pbmsg(::proto_ff::OperateFirstRechargeType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateFirstRechargeType & msg);
		static ::proto_ff::OperateFirstRechargeType* new_pbmsg(){ return new ::proto_ff::OperateFirstRechargeType(); }
		static ::proto_ff::OperateFirstRechargeType make_pbmsg(){ return ::proto_ff::OperateFirstRechargeType(); }
	};
	typedef struct OperateFirstRechargeType_s OperateFirstRechargeType_t;

	struct OperateFirstRechargeData_s : public NFDescStoreSeqOP {
		OperateFirstRechargeData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct OperateReward_s, 12> list;
		NFArray<struct OperateFirstRechargeType_s, 12> firstType;
		int32_t rmb;

		virtual void write_to_pbmsg(::proto_ff::OperateFirstRechargeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateFirstRechargeData & msg);
		static ::proto_ff::OperateFirstRechargeData* new_pbmsg(){ return new ::proto_ff::OperateFirstRechargeData(); }
		static ::proto_ff::OperateFirstRechargeData make_pbmsg(){ return ::proto_ff::OperateFirstRechargeData(); }
	};
	typedef struct OperateFirstRechargeData_s OperateFirstRechargeData_t;

	struct WelfareVipGiftDBData_s : public NFDescStoreSeqOP {
		WelfareVipGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::WelfareVipGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareVipGiftDBData & msg);
		static ::proto_ff::WelfareVipGiftDBData* new_pbmsg(){ return new ::proto_ff::WelfareVipGiftDBData(); }
		static ::proto_ff::WelfareVipGiftDBData make_pbmsg(){ return ::proto_ff::WelfareVipGiftDBData(); }
	};
	typedef struct WelfareVipGiftDBData_s WelfareVipGiftDBData_t;

	struct HoroscopeJackpotDBData_s : public NFDescStoreSeqOP {
		HoroscopeJackpotDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t id;
		bool bOpen;
		uint32_t nNeedLevel;
		uint32_t luckyValue;
		uint32_t welfareValue;
		uint32_t getLuckyCount;
		NFArray<struct ComPair_s, 12> welfareGetState;
		int64_t lastTime;
		int32_t curNum;

		virtual void write_to_pbmsg(::proto_ff::HoroscopeJackpotDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HoroscopeJackpotDBData & msg);
		static ::proto_ff::HoroscopeJackpotDBData* new_pbmsg(){ return new ::proto_ff::HoroscopeJackpotDBData(); }
		static ::proto_ff::HoroscopeJackpotDBData make_pbmsg(){ return ::proto_ff::HoroscopeJackpotDBData(); }
	};
	typedef struct HoroscopeJackpotDBData_s HoroscopeJackpotDBData_t;

	struct HoroscopeActiveDBData_s : public NFDescStoreSeqOP {
		HoroscopeActiveDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t drawCount;
		uint32_t freeOpId;
		uint64_t lastFreeGetTime;
		NFArray<struct HoroscopeJackpotDBData_s, 12> jackpotList;

		virtual void write_to_pbmsg(::proto_ff::HoroscopeActiveDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HoroscopeActiveDBData & msg);
		static ::proto_ff::HoroscopeActiveDBData* new_pbmsg(){ return new ::proto_ff::HoroscopeActiveDBData(); }
		static ::proto_ff::HoroscopeActiveDBData make_pbmsg(){ return ::proto_ff::HoroscopeActiveDBData(); }
	};
	typedef struct HoroscopeActiveDBData_s HoroscopeActiveDBData_t;

	struct WelfareOnlineGiftDBData_s : public NFDescStoreSeqOP {
		WelfareOnlineGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t lastRefreshTime;
		uint64_t OnlineTime;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::WelfareOnlineGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareOnlineGiftDBData & msg);
		static ::proto_ff::WelfareOnlineGiftDBData* new_pbmsg(){ return new ::proto_ff::WelfareOnlineGiftDBData(); }
		static ::proto_ff::WelfareOnlineGiftDBData make_pbmsg(){ return ::proto_ff::WelfareOnlineGiftDBData(); }
	};
	typedef struct WelfareOnlineGiftDBData_s WelfareOnlineGiftDBData_t;

	struct OperationTurntableTaskDBData_s : public NFDescStoreSeqOP {
		OperationTurntableTaskDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t taskId;
		uint64_t progress;
		uint32_t state;

		virtual void write_to_pbmsg(::proto_ff::OperationTurntableTaskDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperationTurntableTaskDBData & msg);
		static ::proto_ff::OperationTurntableTaskDBData* new_pbmsg(){ return new ::proto_ff::OperationTurntableTaskDBData(); }
		static ::proto_ff::OperationTurntableTaskDBData make_pbmsg(){ return ::proto_ff::OperationTurntableTaskDBData(); }
	};
	typedef struct OperationTurntableTaskDBData_s OperationTurntableTaskDBData_t;

	struct OperationTurntableDBData_s : public NFDescStoreSeqOP {
		OperationTurntableDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t lastRefreshTime;
		NFArray<struct OperationTurntableTaskDBData_s, 12> tasklist;

		virtual void write_to_pbmsg(::proto_ff::OperationTurntableDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperationTurntableDBData & msg);
		static ::proto_ff::OperationTurntableDBData* new_pbmsg(){ return new ::proto_ff::OperationTurntableDBData(); }
		static ::proto_ff::OperationTurntableDBData make_pbmsg(){ return ::proto_ff::OperationTurntableDBData(); }
	};
	typedef struct OperationTurntableDBData_s OperationTurntableDBData_t;

	struct OperationTutoraskDBData_s : public NFDescStoreSeqOP {
		OperationTutoraskDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t taskId;
		uint64_t progress;
		uint32_t state;

		virtual void write_to_pbmsg(::proto_ff::OperationTutoraskDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperationTutoraskDBData & msg);
		static ::proto_ff::OperationTutoraskDBData* new_pbmsg(){ return new ::proto_ff::OperationTutoraskDBData(); }
		static ::proto_ff::OperationTutoraskDBData make_pbmsg(){ return ::proto_ff::OperationTutoraskDBData(); }
	};
	typedef struct OperationTutoraskDBData_s OperationTutoraskDBData_t;

	struct OperationTutorDBData_s : public NFDescStoreSeqOP {
		OperationTutorDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint64_t lastRefreshTime;
		uint64_t diligentValue;
		NFArray<struct OperationTutoraskDBData_s, 12> tasklist;

		virtual void write_to_pbmsg(::proto_ff::OperationTutorDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperationTutorDBData & msg);
		static ::proto_ff::OperationTutorDBData* new_pbmsg(){ return new ::proto_ff::OperationTutorDBData(); }
		static ::proto_ff::OperationTutorDBData make_pbmsg(){ return ::proto_ff::OperationTutorDBData(); }
	};
	typedef struct OperationTutorDBData_s OperationTutorDBData_t;

	struct limitInfo_s : public NFDescStoreSeqOP {
		limitInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFArray<struct ComPair64_s, 12> infos;

		virtual void write_to_pbmsg(::proto_ff::limitInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::limitInfo & msg);
		static ::proto_ff::limitInfo* new_pbmsg(){ return new ::proto_ff::limitInfo(); }
		static ::proto_ff::limitInfo make_pbmsg(){ return ::proto_ff::limitInfo(); }
	};
	typedef struct limitInfo_s limitInfo_t;

	struct FestivalWorldBossData_s : public NFDescStoreSeqOP {
		FestivalWorldBossData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct ComPair_s, 12> getState;

		virtual void write_to_pbmsg(::proto_ff::FestivalWorldBossData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestivalWorldBossData & msg);
		static ::proto_ff::FestivalWorldBossData* new_pbmsg(){ return new ::proto_ff::FestivalWorldBossData(); }
		static ::proto_ff::FestivalWorldBossData make_pbmsg(){ return ::proto_ff::FestivalWorldBossData(); }
	};
	typedef struct FestivalWorldBossData_s FestivalWorldBossData_t;

	struct OperateCommonEntryData_s : public NFDescStoreSeqOP {
		OperateCommonEntryData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		int32_t state;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::OperateCommonEntryData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateCommonEntryData & msg);
		static ::proto_ff::OperateCommonEntryData* new_pbmsg(){ return new ::proto_ff::OperateCommonEntryData(); }
		static ::proto_ff::OperateCommonEntryData make_pbmsg(){ return ::proto_ff::OperateCommonEntryData(); }
	};
	typedef struct OperateCommonEntryData_s OperateCommonEntryData_t;

	struct OperateWingGiftData_s : public NFDescStoreSeqOP {
		OperateWingGiftData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct OperateCommonEntryData_s, 12> entrys;
		int64_t refreshTime;
		int32_t loginDay;

		virtual void write_to_pbmsg(::proto_ff::OperateWingGiftData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateWingGiftData & msg);
		static ::proto_ff::OperateWingGiftData* new_pbmsg(){ return new ::proto_ff::OperateWingGiftData(); }
		static ::proto_ff::OperateWingGiftData make_pbmsg(){ return ::proto_ff::OperateWingGiftData(); }
	};
	typedef struct OperateWingGiftData_s OperateWingGiftData_t;

	struct OperateRechargeGiftData_s : public NFDescStoreSeqOP {
		OperateRechargeGiftData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		NFArray<struct OperateCommonEntryData_s, 12> entrys;
		int32_t rechargeRmb;

		virtual void write_to_pbmsg(::proto_ff::OperateRechargeGiftData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OperateRechargeGiftData & msg);
		static ::proto_ff::OperateRechargeGiftData* new_pbmsg(){ return new ::proto_ff::OperateRechargeGiftData(); }
		static ::proto_ff::OperateRechargeGiftData make_pbmsg(){ return ::proto_ff::OperateRechargeGiftData(); }
	};
	typedef struct OperateRechargeGiftData_s OperateRechargeGiftData_t;

	struct CharacterDBOperateData_s : public NFDescStoreSeqOP {
		CharacterDBOperateData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct WelfareDailySignInDBData_s, 12> signInData;
		NFArray<struct WelfareLoginGiftDBData_s, 12> loginGiftData;
		NFArray<struct WelfareLevelGiftDBData_s, 12> levelGiftData;
		NFArray<struct LimitShopData_s, 12> shopData;
		NFArray<struct LimitTaskData_s, 12> taskData;
		NFArray<struct WishDBData_s, 12> wishData;
		struct OperateDailyRechargeData_s dailyRecharge;
		struct OperateFirstRechargeData_s firstRecharge;
		struct OperateMoonCardData_s moonCard;
		struct OperateFundData_s noviceFund;
		struct OperateFundData_s growthFund;
		struct OperateFundData_s dreamFund;
		struct OperateFundData_s noviceFundHigh;
		struct OperateFundData_s growthFundHigh;
		struct OperateFundData_s dreamFundHigh;
		NFArray<struct FestivalInvestDBData_s, 12> fInvestDBData;
		NFArray<struct FestivalExchangeDBData_s, 12> fExchangeDBData;
		NFArray<struct FestivalLoginDBData_s, 12> fLoginDBData;
		NFArray<struct FestivalTotalRechargeDBData_s, 12> fRechargeDBData;
		NFArray<struct FestivalConsumptionDBData_s, 12> fConsumptionDBData;
		NFArray<struct FestivalFirstRechargeDBData_s, 12> fFirstRechargeDBData;
		NFArray<struct FestivalYanHuaDBData_s, 12> fYanHuaDBData;
		NFArray<struct FestivalShopDBData_s, 12> fShopDBData;
		NFArray<struct LimitGiftActiveDBData_s, 12> limitGiftDBData;
		NFArray<struct HoroscopeActiveDBData_s, 12> horoscopeDBData;
		NFArray<struct FRechargeActiveDBData_s, 12> festivalRechargeDBData;
		NFArray<struct FestivalSmashEggDBData_s, 12> fSmashEggDBData;
		NFArray<struct ComPair64_s, 12> redPointClickData;
		NFArray<struct WelfareVipGiftDBData_s, 12> wVipDBData;
		NFArray<struct WelfareOnlineGiftDBData_s, 12> wOnlineDBData;
		NFArray<struct FestivalKillBossData_s, 12> fBossDBData;
		NFArray<struct FestivalHuoYueDuDBData_s, 12> fHuoYueDuDBData;
		NFArray<struct OperationTurntableDBData_s, 12> fTurntableDBData;
		NFArray<struct OperationTutorDBData_s, 12> TutorDBData;
		NFArray<struct FestivalZhiChongData_s, 12> zhiChongData;
		NFArray<struct limitInfo_s, 12> limitData;
		NFArray<struct FestivalSuperDBData_s, 12> superData;
		NFArray<struct FestivalBigYanHuaDBData_s, 12> fBigYanHuaDBData;
		NFArray<struct FestivalWorldBossData_s, 12> worldBossData;
		NFArray<struct FestivalPreRechargeData_s, 12> prerechargedata;
		struct OperateWingGiftData_s winggiftdata;
		struct OperateRechargeGiftData_s rechargegiftdata;
		NFArray<struct FestivalSuperDoubleDBData_s, 12> superDoubleData;
		NFArray<struct IndultTaskGroupEntry_s, 12> IndultTaskDBData;
		struct ColPointsTaskData_s ColPointsTaskData;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOperateData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOperateData & msg);
		static ::proto_ff::CharacterDBOperateData* new_pbmsg(){ return new ::proto_ff::CharacterDBOperateData(); }
		static ::proto_ff::CharacterDBOperateData make_pbmsg(){ return ::proto_ff::CharacterDBOperateData(); }
	};
	typedef struct CharacterDBOperateData_s CharacterDBOperateData_t;

	struct PlayerActiveAnswerData_s : public NFDescStoreSeqOP {
		PlayerActiveAnswerData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t answerIndex;
		NFArray<uint32_t, 12> answerList;
		uint32_t allexp;
		uint32_t allmoney;
		uint32_t correctnum;
		uint32_t isGetReward;
		uint64_t lastAnswerTime;

		virtual void write_to_pbmsg(::proto_ff::PlayerActiveAnswerData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PlayerActiveAnswerData & msg);
		static ::proto_ff::PlayerActiveAnswerData* new_pbmsg(){ return new ::proto_ff::PlayerActiveAnswerData(); }
		static ::proto_ff::PlayerActiveAnswerData make_pbmsg(){ return ::proto_ff::PlayerActiveAnswerData(); }
	};
	typedef struct PlayerActiveAnswerData_s PlayerActiveAnswerData_t;

	struct CharacterDBActiveInfo_s : public NFDescStoreSeqOP {
		CharacterDBActiveInfo_s();
		int CreateInit();
		int ResumeInit();
		struct PlayerActiveAnswerData_s playerActiveAnswerInfo;
		struct PlayerActiveAnswerData_s playerActiveDailyAnswerInfo;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBActiveInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBActiveInfo & msg);
		static ::proto_ff::CharacterDBActiveInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBActiveInfo(); }
		static ::proto_ff::CharacterDBActiveInfo make_pbmsg(){ return ::proto_ff::CharacterDBActiveInfo(); }
	};
	typedef struct CharacterDBActiveInfo_s CharacterDBActiveInfo_t;

	struct PayCountDBProto_s : public NFDescStoreSeqOP {
		PayCountDBProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t charge_id;
		uint32_t count;

		virtual void write_to_pbmsg(::proto_ff::PayCountDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PayCountDBProto & msg);
		static ::proto_ff::PayCountDBProto* new_pbmsg(){ return new ::proto_ff::PayCountDBProto(); }
		static ::proto_ff::PayCountDBProto make_pbmsg(){ return ::proto_ff::PayCountDBProto(); }
	};
	typedef struct PayCountDBProto_s PayCountDBProto_t;

	struct OfflineRetDBProto_s : public NFDescStoreSeqOP {
		OfflineRetDBProto_s();
		int CreateInit();
		int ResumeInit();
		int64_t diamond;
		uint64_t time;
		uint64_t freshtime;

		virtual void write_to_pbmsg(::proto_ff::OfflineRetDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OfflineRetDBProto & msg);
		static ::proto_ff::OfflineRetDBProto* new_pbmsg(){ return new ::proto_ff::OfflineRetDBProto(); }
		static ::proto_ff::OfflineRetDBProto make_pbmsg(){ return ::proto_ff::OfflineRetDBProto(); }
	};
	typedef struct OfflineRetDBProto_s OfflineRetDBProto_t;

	struct CharacterPayData_s : public NFDescStoreSeqOP {
		CharacterPayData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t rmb;
		uint32_t maxPayId;
		NFArray<NFSizeString<128>, 12> payedProducts;
		uint32_t today_rmb;
		uint64_t last_time;
		NFArray<struct PayCountDBProto_s, 12> pay_count;
		uint64_t pay_count_time;
		int64_t diamond;
		uint64_t real_rmb;
		int64_t freshtime;
		int32_t openwindow;
		struct OfflineRetDBProto_s offline_ret;

		virtual void write_to_pbmsg(::proto_ff::CharacterPayData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterPayData & msg);
		static ::proto_ff::CharacterPayData* new_pbmsg(){ return new ::proto_ff::CharacterPayData(); }
		static ::proto_ff::CharacterPayData make_pbmsg(){ return ::proto_ff::CharacterPayData(); }
	};
	typedef struct CharacterPayData_s CharacterPayData_t;

	struct FunctionUnlockInfo_s : public NFDescStoreSeqOP {
		FunctionUnlockInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<uint64_t, 12> unlockIds;

		virtual void write_to_pbmsg(::proto_ff::FunctionUnlockInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FunctionUnlockInfo & msg);
		static ::proto_ff::FunctionUnlockInfo* new_pbmsg(){ return new ::proto_ff::FunctionUnlockInfo(); }
		static ::proto_ff::FunctionUnlockInfo make_pbmsg(){ return ::proto_ff::FunctionUnlockInfo(); }
	};
	typedef struct FunctionUnlockInfo_s FunctionUnlockInfo_t;

	struct EmblemSlot_s : public NFDescStoreSeqOP {
		EmblemSlot_s();
		int CreateInit();
		int ResumeInit();
		uint32_t slotId;
		uint32_t groupId;
		uint32_t posId;
		uint32_t attrType;
		bool open;
		uint64_t itemId;
		uint32_t bind;

		virtual void write_to_pbmsg(::proto_ff::EmblemSlot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EmblemSlot & msg);
		static ::proto_ff::EmblemSlot* new_pbmsg(){ return new ::proto_ff::EmblemSlot(); }
		static ::proto_ff::EmblemSlot make_pbmsg(){ return ::proto_ff::EmblemSlot(); }
	};
	typedef struct EmblemSlot_s EmblemSlot_t;

	struct CharacterDBEmblemData_s : public NFDescStoreSeqOP {
		CharacterDBEmblemData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct EmblemSlot_s, 12> slots;
		NFArray<struct ComPair_s, 12> groupSuitIds;
		NFArray<struct ComPair_s, 12> suitSkillId;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBEmblemData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBEmblemData & msg);
		static ::proto_ff::CharacterDBEmblemData* new_pbmsg(){ return new ::proto_ff::CharacterDBEmblemData(); }
		static ::proto_ff::CharacterDBEmblemData make_pbmsg(){ return ::proto_ff::CharacterDBEmblemData(); }
	};
	typedef struct CharacterDBEmblemData_s CharacterDBEmblemData_t;

	struct CharacterDBIdentifyData_s : public NFDescStoreSeqOP {
		CharacterDBIdentifyData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComPair64_s, 12> identifys;
		NFArray<struct ComPair64_s, 12> identifyfates;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBIdentifyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBIdentifyData & msg);
		static ::proto_ff::CharacterDBIdentifyData* new_pbmsg(){ return new ::proto_ff::CharacterDBIdentifyData(); }
		static ::proto_ff::CharacterDBIdentifyData make_pbmsg(){ return ::proto_ff::CharacterDBIdentifyData(); }
	};
	typedef struct CharacterDBIdentifyData_s CharacterDBIdentifyData_t;

	struct ElementInfoData_s : public NFDescStoreSeqOP {
		ElementInfoData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t type;
		uint32_t level;
		uint64_t exp;

		virtual void write_to_pbmsg(::proto_ff::ElementInfoData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ElementInfoData & msg);
		static ::proto_ff::ElementInfoData* new_pbmsg(){ return new ::proto_ff::ElementInfoData(); }
		static ::proto_ff::ElementInfoData make_pbmsg(){ return ::proto_ff::ElementInfoData(); }
	};
	typedef struct ElementInfoData_s ElementInfoData_t;

	struct CharacterDBElementData_s : public NFDescStoreSeqOP {
		CharacterDBElementData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ElementInfoData_s, 12> elements;
		NFArray<struct ComPair64_s, 12> fragments;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBElementData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBElementData & msg);
		static ::proto_ff::CharacterDBElementData* new_pbmsg(){ return new ::proto_ff::CharacterDBElementData(); }
		static ::proto_ff::CharacterDBElementData make_pbmsg(){ return ::proto_ff::CharacterDBElementData(); }
	};
	typedef struct CharacterDBElementData_s CharacterDBElementData_t;

	struct CharacterDBFashionData_s : public NFDescStoreSeqOP {
		CharacterDBFashionData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComPair64_s, 12> fashions;
		uint64_t dressClothesFashionID;
		uint64_t dressWeaponFashionID;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBFashionData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBFashionData & msg);
		static ::proto_ff::CharacterDBFashionData* new_pbmsg(){ return new ::proto_ff::CharacterDBFashionData(); }
		static ::proto_ff::CharacterDBFashionData make_pbmsg(){ return ::proto_ff::CharacterDBFashionData(); }
	};
	typedef struct CharacterDBFashionData_s CharacterDBFashionData_t;

	struct CharacterDBWingData_s : public NFDescStoreSeqOP {
		CharacterDBWingData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t advanceWingExp;
		uint32_t advanceWingLev;
		uint64_t equipWingID;
		NFArray<struct ComPair64_s, 12> fantasyWings;
		NFArray<struct ComPair64_s, 12> fragments;
		int32_t isbreak;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBWingData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBWingData & msg);
		static ::proto_ff::CharacterDBWingData* new_pbmsg(){ return new ::proto_ff::CharacterDBWingData(); }
		static ::proto_ff::CharacterDBWingData make_pbmsg(){ return ::proto_ff::CharacterDBWingData(); }
	};
	typedef struct CharacterDBWingData_s CharacterDBWingData_t;

	struct CharacterDBPartnerData_s : public NFDescStoreSeqOP {
		CharacterDBPartnerData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t advancePartnerExp;
		uint32_t advancePartnerLev;
		uint64_t equipPartnerID;
		NFArray<struct ComPair64_s, 12> fantasyPartners;
		NFArray<struct ComPair64_s, 12> fragments;
		uint64_t commonPartnerExp;
		uint32_t autoSwallowFlag;
		uint64_t autoSwallowClass;
		int32_t isbreak;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPartnerData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPartnerData & msg);
		static ::proto_ff::CharacterDBPartnerData* new_pbmsg(){ return new ::proto_ff::CharacterDBPartnerData(); }
		static ::proto_ff::CharacterDBPartnerData make_pbmsg(){ return ::proto_ff::CharacterDBPartnerData(); }
	};
	typedef struct CharacterDBPartnerData_s CharacterDBPartnerData_t;

	struct CharacterDBMountData_s : public NFDescStoreSeqOP {
		CharacterDBMountData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComPair64_s, 12> mounts;
		uint64_t mountID;
		uint32_t rideState;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMountData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMountData & msg);
		static ::proto_ff::CharacterDBMountData* new_pbmsg(){ return new ::proto_ff::CharacterDBMountData(); }
		static ::proto_ff::CharacterDBMountData make_pbmsg(){ return ::proto_ff::CharacterDBMountData(); }
	};
	typedef struct CharacterDBMountData_s CharacterDBMountData_t;

	struct PlayerBossDataInfo_s : public NFDescStoreSeqOP {
		PlayerBossDataInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t group_type;
		int32_t cur_num;
		int32_t max_num;
		int32_t vip_buy_num;
		int32_t boss_type;

		virtual void write_to_pbmsg(::proto_ff::PlayerBossDataInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PlayerBossDataInfo & msg);
		static ::proto_ff::PlayerBossDataInfo* new_pbmsg(){ return new ::proto_ff::PlayerBossDataInfo(); }
		static ::proto_ff::PlayerBossDataInfo make_pbmsg(){ return ::proto_ff::PlayerBossDataInfo(); }
	};
	typedef struct PlayerBossDataInfo_s PlayerBossDataInfo_t;

	struct CharacterDBBossAttentInfo_s : public NFDescStoreSeqOP {
		CharacterDBBossAttentInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		int32_t type;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBBossAttentInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBBossAttentInfo & msg);
		static ::proto_ff::CharacterDBBossAttentInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBBossAttentInfo(); }
		static ::proto_ff::CharacterDBBossAttentInfo make_pbmsg(){ return ::proto_ff::CharacterDBBossAttentInfo(); }
	};
	typedef struct CharacterDBBossAttentInfo_s CharacterDBBossAttentInfo_t;

	struct CharacterDBBossData_s : public NFDescStoreSeqOP {
		CharacterDBBossData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct PlayerBossDataInfo_s, 12> infos;
		uint64_t lastTime;
		NFArray<int64_t, 12> attent_list;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBBossData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBBossData & msg);
		static ::proto_ff::CharacterDBBossData* new_pbmsg(){ return new ::proto_ff::CharacterDBBossData(); }
		static ::proto_ff::CharacterDBBossData make_pbmsg(){ return ::proto_ff::CharacterDBBossData(); }
	};
	typedef struct CharacterDBBossData_s CharacterDBBossData_t;

	struct RedPlayerInfo_s : public NFDescStoreSeqOP {
		RedPlayerInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::RedPlayerInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedPlayerInfo & msg);
		static ::proto_ff::RedPlayerInfo* new_pbmsg(){ return new ::proto_ff::RedPlayerInfo(); }
		static ::proto_ff::RedPlayerInfo make_pbmsg(){ return ::proto_ff::RedPlayerInfo(); }
	};
	typedef struct RedPlayerInfo_s RedPlayerInfo_t;

	struct CharacterDBPvpData_s : public NFDescStoreSeqOP {
		CharacterDBPvpData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t pk_mode;
		uint32_t pk_killing_value;
		NFArray<struct RedPlayerInfo_s, 12> red_player;
		uint64_t online_time;
		int32_t kill_num;
		int32_t be_kill_num;
		int64_t lastTime;
		NFSizeString<128> be_kill_name;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPvpData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPvpData & msg);
		static ::proto_ff::CharacterDBPvpData* new_pbmsg(){ return new ::proto_ff::CharacterDBPvpData(); }
		static ::proto_ff::CharacterDBPvpData make_pbmsg(){ return ::proto_ff::CharacterDBPvpData(); }
	};
	typedef struct CharacterDBPvpData_s CharacterDBPvpData_t;

	struct CharacterDBTreasureData_s : public NFDescStoreSeqOP {
		CharacterDBTreasureData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t advanceTreasureExp;
		uint32_t advanceTreasureLev;
		uint64_t equipTreasureID;
		NFArray<struct ComPair64_s, 12> fantasyTreasures;
		NFArray<struct ComPair64_s, 12> fragments;
		uint64_t skillTreasureID;
		int32_t isbreak;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBTreasureData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBTreasureData & msg);
		static ::proto_ff::CharacterDBTreasureData* new_pbmsg(){ return new ::proto_ff::CharacterDBTreasureData(); }
		static ::proto_ff::CharacterDBTreasureData make_pbmsg(){ return ::proto_ff::CharacterDBTreasureData(); }
	};
	typedef struct CharacterDBTreasureData_s CharacterDBTreasureData_t;

	struct ArtifactInfo_s : public NFDescStoreSeqOP {
		ArtifactInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		int32_t star_lv;

		virtual void write_to_pbmsg(::proto_ff::ArtifactInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArtifactInfo & msg);
		static ::proto_ff::ArtifactInfo* new_pbmsg(){ return new ::proto_ff::ArtifactInfo(); }
		static ::proto_ff::ArtifactInfo make_pbmsg(){ return ::proto_ff::ArtifactInfo(); }
	};
	typedef struct ArtifactInfo_s ArtifactInfo_t;

	struct CharacterDBArtifactData_s : public NFDescStoreSeqOP {
		CharacterDBArtifactData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ArtifactInfo_s, 12> infos;
		uint64_t dress_id;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBArtifactData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBArtifactData & msg);
		static ::proto_ff::CharacterDBArtifactData* new_pbmsg(){ return new ::proto_ff::CharacterDBArtifactData(); }
		static ::proto_ff::CharacterDBArtifactData make_pbmsg(){ return ::proto_ff::CharacterDBArtifactData(); }
	};
	typedef struct CharacterDBArtifactData_s CharacterDBArtifactData_t;

	struct CharacterDBFateStarData_s : public NFDescStoreSeqOP {
		CharacterDBFateStarData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t freeTime;
		uint32_t towerLevel;
		uint32_t nbless;
		NFArray<struct ComPair_s, 12> soltData;
		NFArray<struct ItemProtoInfo_s, 12> equipStars;
		uint32_t curnum;
		uint64_t lasttime;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBFateStarData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBFateStarData & msg);
		static ::proto_ff::CharacterDBFateStarData* new_pbmsg(){ return new ::proto_ff::CharacterDBFateStarData(); }
		static ::proto_ff::CharacterDBFateStarData make_pbmsg(){ return ::proto_ff::CharacterDBFateStarData(); }
	};
	typedef struct CharacterDBFateStarData_s CharacterDBFateStarData_t;

	struct CharacterDBConvoyData_s : public NFDescStoreSeqOP {
		CharacterDBConvoyData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t doTimes;
		uint32_t convoyDate;
		uint64_t escortid;
		uint64_t acceptTime;
		uint32_t refreshTimes;
		uint64_t selectEscortId;
		uint64_t refreshTimeStamp;
		uint64_t LastResetTime;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBConvoyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBConvoyData & msg);
		static ::proto_ff::CharacterDBConvoyData* new_pbmsg(){ return new ::proto_ff::CharacterDBConvoyData(); }
		static ::proto_ff::CharacterDBConvoyData make_pbmsg(){ return ::proto_ff::CharacterDBConvoyData(); }
	};
	typedef struct CharacterDBConvoyData_s CharacterDBConvoyData_t;

	struct CharacterDBDailyEntry_s : public NFDescStoreSeqOP {
		CharacterDBDailyEntry_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cfg_id;
		int32_t cur_num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDailyEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDailyEntry & msg);
		static ::proto_ff::CharacterDBDailyEntry* new_pbmsg(){ return new ::proto_ff::CharacterDBDailyEntry(); }
		static ::proto_ff::CharacterDBDailyEntry make_pbmsg(){ return ::proto_ff::CharacterDBDailyEntry(); }
	};
	typedef struct CharacterDBDailyEntry_s CharacterDBDailyEntry_t;

	struct CharacterDBDailyData_s : public NFDescStoreSeqOP {
		CharacterDBDailyData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharacterDBDailyEntry_s, 12> daily_entry;
		NFArray<uint64_t, 12> rewards;
		uint64_t lasttime;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDailyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDailyData & msg);
		static ::proto_ff::CharacterDBDailyData* new_pbmsg(){ return new ::proto_ff::CharacterDBDailyData(); }
		static ::proto_ff::CharacterDBDailyData make_pbmsg(){ return ::proto_ff::CharacterDBDailyData(); }
	};
	typedef struct CharacterDBDailyData_s CharacterDBDailyData_t;

	struct FieldCylstalInfo_s : public NFDescStoreSeqOP {
		FieldCylstalInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t slotIndex;
		int64_t itemid;

		virtual void write_to_pbmsg(::proto_ff::FieldCylstalInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FieldCylstalInfo & msg);
		static ::proto_ff::FieldCylstalInfo* new_pbmsg(){ return new ::proto_ff::FieldCylstalInfo(); }
		static ::proto_ff::FieldCylstalInfo make_pbmsg(){ return ::proto_ff::FieldCylstalInfo(); }
	};
	typedef struct FieldCylstalInfo_s FieldCylstalInfo_t;

	struct FieldExInfo_s : public NFDescStoreSeqOP {
		FieldExInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t actived;
		NFArray<struct ItemProtoInfo_s, 12> slotInfos;
		uint64_t fieldId;
		uint64_t fightNum;
		NFArray<struct FieldCylstalInfo_s, 12> cylstalInfos;
		bool first_active;

		virtual void write_to_pbmsg(::proto_ff::FieldExInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FieldExInfo & msg);
		static ::proto_ff::FieldExInfo* new_pbmsg(){ return new ::proto_ff::FieldExInfo(); }
		static ::proto_ff::FieldExInfo make_pbmsg(){ return ::proto_ff::FieldExInfo(); }
	};
	typedef struct FieldExInfo_s FieldExInfo_t;

	struct CharacterDBFieldData_s : public NFDescStoreSeqOP {
		CharacterDBFieldData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct FieldExInfo_s, 12> fieldInfos;
		uint64_t curExp;
		int32_t maxNum;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBFieldData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBFieldData & msg);
		static ::proto_ff::CharacterDBFieldData* new_pbmsg(){ return new ::proto_ff::CharacterDBFieldData(); }
		static ::proto_ff::CharacterDBFieldData make_pbmsg(){ return ::proto_ff::CharacterDBFieldData(); }
	};
	typedef struct CharacterDBFieldData_s CharacterDBFieldData_t;

	struct vipGiftDBData_s : public NFDescStoreSeqOP {
		vipGiftDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t giftId;
		uint64_t activeTime;
		uint64_t lastGetTime;

		virtual void write_to_pbmsg(::proto_ff::vipGiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipGiftDBData & msg);
		static ::proto_ff::vipGiftDBData* new_pbmsg(){ return new ::proto_ff::vipGiftDBData(); }
		static ::proto_ff::vipGiftDBData make_pbmsg(){ return ::proto_ff::vipGiftDBData(); }
	};
	typedef struct vipGiftDBData_s vipGiftDBData_t;

	struct VipTCardInfo_s : public NFDescStoreSeqOP {
		VipTCardInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t endTime;
		int32_t state;
		int32_t rewardState;

		virtual void write_to_pbmsg(::proto_ff::VipTCardInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::VipTCardInfo & msg);
		static ::proto_ff::VipTCardInfo* new_pbmsg(){ return new ::proto_ff::VipTCardInfo(); }
		static ::proto_ff::VipTCardInfo make_pbmsg(){ return ::proto_ff::VipTCardInfo(); }
	};
	typedef struct VipTCardInfo_s VipTCardInfo_t;

	struct VipTCardData_s : public NFDescStoreSeqOP {
		VipTCardData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct VipTCardInfo_s, 12> cardInfo;
		int32_t giftState;
		int32_t point;

		virtual void write_to_pbmsg(::proto_ff::VipTCardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::VipTCardData & msg);
		static ::proto_ff::VipTCardData* new_pbmsg(){ return new ::proto_ff::VipTCardData(); }
		static ::proto_ff::VipTCardData make_pbmsg(){ return ::proto_ff::VipTCardData(); }
	};
	typedef struct VipTCardData_s VipTCardData_t;

	struct CharacterDBVipData_s : public NFDescStoreSeqOP {
		CharacterDBVipData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t vipState;
		uint64_t vipExp;
		uint64_t getRewardTime;
		uint64_t expDiamond;
		NFArray<struct ComPair64_s, 12> timeLimitExp;
		NFArray<struct vipGiftDBData_s, 12> vipGift;
		struct VipTCardData_s cardData;
		int64_t cardLastTime;
		int64_t curAddVipExp;
		int32_t point;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBVipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBVipData & msg);
		static ::proto_ff::CharacterDBVipData* new_pbmsg(){ return new ::proto_ff::CharacterDBVipData(); }
		static ::proto_ff::CharacterDBVipData make_pbmsg(){ return ::proto_ff::CharacterDBVipData(); }
	};
	typedef struct CharacterDBVipData_s CharacterDBVipData_t;

	struct CharacterDBMallData_s : public NFDescStoreSeqOP {
		CharacterDBMallData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t refreshTime;
		NFArray<struct ComPair64_s, 12> goodsInfo;
		uint64_t dailyRefreshTime;
		int32_t refreshNum;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMallData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMallData & msg);
		static ::proto_ff::CharacterDBMallData* new_pbmsg(){ return new ::proto_ff::CharacterDBMallData(); }
		static ::proto_ff::CharacterDBMallData make_pbmsg(){ return ::proto_ff::CharacterDBMallData(); }
	};
	typedef struct CharacterDBMallData_s CharacterDBMallData_t;

	struct GodhoodSlot_s : public NFDescStoreSeqOP {
		GodhoodSlot_s();
		int CreateInit();
		int ResumeInit();
		uint32_t idx;
		bool open;
		struct ItemProtoInfo_s item;

		virtual void write_to_pbmsg(::proto_ff::GodhoodSlot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodhoodSlot & msg);
		static ::proto_ff::GodhoodSlot* new_pbmsg(){ return new ::proto_ff::GodhoodSlot(); }
		static ::proto_ff::GodhoodSlot make_pbmsg(){ return ::proto_ff::GodhoodSlot(); }
	};
	typedef struct GodhoodSlot_s GodhoodSlot_t;

	struct CharacterDBGodhoodData_s : public NFDescStoreSeqOP {
		CharacterDBGodhoodData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GodhoodSlot_s, 12> godhoodSlot;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBGodhoodData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBGodhoodData & msg);
		static ::proto_ff::CharacterDBGodhoodData* new_pbmsg(){ return new ::proto_ff::CharacterDBGodhoodData(); }
		static ::proto_ff::CharacterDBGodhoodData make_pbmsg(){ return ::proto_ff::CharacterDBGodhoodData(); }
	};
	typedef struct CharacterDBGodhoodData_s CharacterDBGodhoodData_t;

	struct RecoveryCompleteDBData_s : public NFDescStoreSeqOP {
		RecoveryCompleteDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t level;
		uint32_t vipLevel;
		uint64_t time;
		NFArray<struct ComPair_s, 12> completeList;
		NFArray<struct ComPairBool_s, 12> funUnlock;

		virtual void write_to_pbmsg(::proto_ff::RecoveryCompleteDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RecoveryCompleteDBData & msg);
		static ::proto_ff::RecoveryCompleteDBData* new_pbmsg(){ return new ::proto_ff::RecoveryCompleteDBData(); }
		static ::proto_ff::RecoveryCompleteDBData make_pbmsg(){ return ::proto_ff::RecoveryCompleteDBData(); }
	};
	typedef struct RecoveryCompleteDBData_s RecoveryCompleteDBData_t;

	struct RecoveryDBReward_s : public NFDescStoreSeqOP {
		RecoveryDBReward_s();
		int CreateInit();
		int ResumeInit();
		uint32_t groupid;
		uint32_t day1CountMax;
		uint32_t day2CountMax;
		uint32_t day1VipCountMax;
		uint32_t day2VipCountMax;
		uint32_t commonCount;
		uint32_t vipCount;
		uint32_t goldExp;
		uint32_t diamondsExp;
		uint32_t goldItemCount;
		uint32_t diamondsItemCount;
		uint32_t needGold;
		uint32_t needDiamonds;
		uint64_t ItemId;
		uint32_t confid;

		virtual void write_to_pbmsg(::proto_ff::RecoveryDBReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RecoveryDBReward & msg);
		static ::proto_ff::RecoveryDBReward* new_pbmsg(){ return new ::proto_ff::RecoveryDBReward(); }
		static ::proto_ff::RecoveryDBReward make_pbmsg(){ return ::proto_ff::RecoveryDBReward(); }
	};
	typedef struct RecoveryDBReward_s RecoveryDBReward_t;

	struct RecoveryDBData_s : public NFDescStoreSeqOP {
		RecoveryDBData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t time;
		NFArray<struct RecoveryDBReward_s, 12> list;

		virtual void write_to_pbmsg(::proto_ff::RecoveryDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RecoveryDBData & msg);
		static ::proto_ff::RecoveryDBData* new_pbmsg(){ return new ::proto_ff::RecoveryDBData(); }
		static ::proto_ff::RecoveryDBData make_pbmsg(){ return ::proto_ff::RecoveryDBData(); }
	};
	typedef struct RecoveryDBData_s RecoveryDBData_t;

	struct CharacterDBRecoveryData_s : public NFDescStoreSeqOP {
		CharacterDBRecoveryData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct RecoveryCompleteDBData_s, 12> completeDBData;
		struct RecoveryDBData_s recoveryDBData;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBRecoveryData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBRecoveryData & msg);
		static ::proto_ff::CharacterDBRecoveryData* new_pbmsg(){ return new ::proto_ff::CharacterDBRecoveryData(); }
		static ::proto_ff::CharacterDBRecoveryData make_pbmsg(){ return ::proto_ff::CharacterDBRecoveryData(); }
	};
	typedef struct CharacterDBRecoveryData_s CharacterDBRecoveryData_t;

	struct CharacterDBActivityScuffleData_s : public NFDescStoreSeqOP {
		CharacterDBActivityScuffleData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cur_cfg_id;
		int32_t cur_points;
		uint64_t activity_id;
		uint64_t before_map_id;
		struct Vector3PB_s before_map_point;
		int32_t last_time;
		int32_t end_time;
		int32_t kill_num;
		int32_t last_kill_num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBActivityScuffleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBActivityScuffleData & msg);
		static ::proto_ff::CharacterDBActivityScuffleData* new_pbmsg(){ return new ::proto_ff::CharacterDBActivityScuffleData(); }
		static ::proto_ff::CharacterDBActivityScuffleData make_pbmsg(){ return ::proto_ff::CharacterDBActivityScuffleData(); }
	};
	typedef struct CharacterDBActivityScuffleData_s CharacterDBActivityScuffleData_t;

	struct CharacterDBActivityChaosDragonsData_s : public NFDescStoreSeqOP {
		CharacterDBActivityChaosDragonsData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t before_map_id;
		struct Vector3PB_s before_map_point;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBActivityChaosDragonsData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBActivityChaosDragonsData & msg);
		static ::proto_ff::CharacterDBActivityChaosDragonsData* new_pbmsg(){ return new ::proto_ff::CharacterDBActivityChaosDragonsData(); }
		static ::proto_ff::CharacterDBActivityChaosDragonsData make_pbmsg(){ return ::proto_ff::CharacterDBActivityChaosDragonsData(); }
	};
	typedef struct CharacterDBActivityChaosDragonsData_s CharacterDBActivityChaosDragonsData_t;

	struct CharacterDBActivityAsharmData_s : public NFDescStoreSeqOP {
		CharacterDBActivityAsharmData_s();
		int CreateInit();
		int ResumeInit();
		int32_t step;
		uint64_t end_time;
		uint64_t last_time;
		int32_t cur_num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBActivityAsharmData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBActivityAsharmData & msg);
		static ::proto_ff::CharacterDBActivityAsharmData* new_pbmsg(){ return new ::proto_ff::CharacterDBActivityAsharmData(); }
		static ::proto_ff::CharacterDBActivityAsharmData make_pbmsg(){ return ::proto_ff::CharacterDBActivityAsharmData(); }
	};
	typedef struct CharacterDBActivityAsharmData_s CharacterDBActivityAsharmData_t;

	struct CharacterDBCombatTeamData_s : public NFDescStoreSeqOP {
		CharacterDBCombatTeamData_s();
		int CreateInit();
		int ResumeInit();
		int32_t team_id;
		uint64_t team_end_time;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBCombatTeamData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBCombatTeamData & msg);
		static ::proto_ff::CharacterDBCombatTeamData* new_pbmsg(){ return new ::proto_ff::CharacterDBCombatTeamData(); }
		static ::proto_ff::CharacterDBCombatTeamData make_pbmsg(){ return ::proto_ff::CharacterDBCombatTeamData(); }
	};
	typedef struct CharacterDBCombatTeamData_s CharacterDBCombatTeamData_t;

	struct CharacterDBSoloData_s : public NFDescStoreSeqOP {
		CharacterDBSoloData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<int32_t, 12> rewarded_join_index;
		int32_t my_solo_num;
		NFArray<int32_t, 12> rewarded_stage_index;
		NFArray<int32_t, 12> rewarded_day_stage_index;
		uint64_t solo_time_end;
		int32_t solo_season;
		int32_t cur_buy_num;
		uint64_t last_time;
		int32_t lose_num;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSoloData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSoloData & msg);
		static ::proto_ff::CharacterDBSoloData* new_pbmsg(){ return new ::proto_ff::CharacterDBSoloData(); }
		static ::proto_ff::CharacterDBSoloData make_pbmsg(){ return ::proto_ff::CharacterDBSoloData(); }
	};
	typedef struct CharacterDBSoloData_s CharacterDBSoloData_t;

	struct CharacterDBAtBoxData_s : public NFDescStoreSeqOP {
		CharacterDBAtBoxData_s();
		int CreateInit();
		int ResumeInit();
		int32_t use_count;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBAtBoxData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBAtBoxData & msg);
		static ::proto_ff::CharacterDBAtBoxData* new_pbmsg(){ return new ::proto_ff::CharacterDBAtBoxData(); }
		static ::proto_ff::CharacterDBAtBoxData make_pbmsg(){ return ::proto_ff::CharacterDBAtBoxData(); }
	};
	typedef struct CharacterDBAtBoxData_s CharacterDBAtBoxData_t;

	struct CharDBAncientShopProto_s : public NFDescStoreSeqOP {
		CharDBAncientShopProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t idx;
		int32_t exchge;

		virtual void write_to_pbmsg(::proto_ff::CharDBAncientShopProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharDBAncientShopProto & msg);
		static ::proto_ff::CharDBAncientShopProto* new_pbmsg(){ return new ::proto_ff::CharDBAncientShopProto(); }
		static ::proto_ff::CharDBAncientShopProto make_pbmsg(){ return ::proto_ff::CharDBAncientShopProto(); }
	};
	typedef struct CharDBAncientShopProto_s CharDBAncientShopProto_t;

	struct CharDBAncientShopData_s : public NFDescStoreSeqOP {
		CharDBAncientShopData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharDBAncientShopProto_s, 12> info;
		int64_t score;
		int32_t score_cnt;
		int32_t dia_cnt;
		int32_t free_cnt;
		uint64_t fresh_time;
		uint64_t reset_time;

		virtual void write_to_pbmsg(::proto_ff::CharDBAncientShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharDBAncientShopData & msg);
		static ::proto_ff::CharDBAncientShopData* new_pbmsg(){ return new ::proto_ff::CharDBAncientShopData(); }
		static ::proto_ff::CharDBAncientShopData make_pbmsg(){ return ::proto_ff::CharDBAncientShopData(); }
	};
	typedef struct CharDBAncientShopData_s CharDBAncientShopData_t;

	struct CharacterDBAncientData_s : public NFDescStoreSeqOP {
		CharacterDBAncientData_s();
		int CreateInit();
		int ResumeInit();
		int64_t bless_value;
		int64_t score_incr;
		struct CharDBAncientShopData_s shop;
		uint64_t bless_reset_time;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBAncientData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBAncientData & msg);
		static ::proto_ff::CharacterDBAncientData* new_pbmsg(){ return new ::proto_ff::CharacterDBAncientData(); }
		static ::proto_ff::CharacterDBAncientData make_pbmsg(){ return ::proto_ff::CharacterDBAncientData(); }
	};
	typedef struct CharacterDBAncientData_s CharacterDBAncientData_t;

	struct ChooseGiftData_s : public NFDescStoreSeqOP {
		ChooseGiftData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeTime;
		int32_t headState;
		int32_t rechargeIndex;
		int32_t rechargeIndexState;

		virtual void write_to_pbmsg(::proto_ff::ChooseGiftData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ChooseGiftData & msg);
		static ::proto_ff::ChooseGiftData* new_pbmsg(){ return new ::proto_ff::ChooseGiftData(); }
		static ::proto_ff::ChooseGiftData make_pbmsg(){ return ::proto_ff::ChooseGiftData(); }
	};
	typedef struct ChooseGiftData_s ChooseGiftData_t;

	struct CharacterDBActivityData_s : public NFDescStoreSeqOP {
		CharacterDBActivityData_s();
		int CreateInit();
		int ResumeInit();
		struct CharacterDBActivityScuffleData_s scuffle_cross_data;
		struct CharacterDBActivityScuffleData_s scuffle_local_data;
		struct CharacterDBActivityChaosDragonsData_s chaos_dragons_data;
		struct CharacterDBActivityAsharmData_s asharm_data;
		struct CharacterDBSoloData_s solo_data;
		struct CharacterDBAtBoxData_s box_data;
		struct CharacterDBAncientData_s ancient_data;
		struct ChooseGiftData_s choosegift_data;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBActivityData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBActivityData & msg);
		static ::proto_ff::CharacterDBActivityData* new_pbmsg(){ return new ::proto_ff::CharacterDBActivityData(); }
		static ::proto_ff::CharacterDBActivityData make_pbmsg(){ return ::proto_ff::CharacterDBActivityData(); }
	};
	typedef struct CharacterDBActivityData_s CharacterDBActivityData_t;

	struct SOAcitveTotalRechargeData_s : public NFDescStoreSeqOP {
		SOAcitveTotalRechargeData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t pageId;
		uint64_t rechargeValue;
		NFArray<struct ComPair_s, 12> getState;
		uint64_t rechargeholy;

		virtual void write_to_pbmsg(::proto_ff::SOAcitveTotalRechargeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SOAcitveTotalRechargeData & msg);
		static ::proto_ff::SOAcitveTotalRechargeData* new_pbmsg(){ return new ::proto_ff::SOAcitveTotalRechargeData(); }
		static ::proto_ff::SOAcitveTotalRechargeData make_pbmsg(){ return ::proto_ff::SOAcitveTotalRechargeData(); }
	};
	typedef struct SOAcitveTotalRechargeData_s SOAcitveTotalRechargeData_t;

	struct SOAcitveAdvanceData_s : public NFDescStoreSeqOP {
		SOAcitveAdvanceData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t pageId;
		uint64_t advanceValue;
		NFArray<struct ComPair_s, 12> getState;
		NFArray<struct ComPair64_s, 12> advanceValueMap;

		virtual void write_to_pbmsg(::proto_ff::SOAcitveAdvanceData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SOAcitveAdvanceData & msg);
		static ::proto_ff::SOAcitveAdvanceData* new_pbmsg(){ return new ::proto_ff::SOAcitveAdvanceData(); }
		static ::proto_ff::SOAcitveAdvanceData make_pbmsg(){ return ::proto_ff::SOAcitveAdvanceData(); }
	};
	typedef struct SOAcitveAdvanceData_s SOAcitveAdvanceData_t;

	struct SOAcitveGoodsData_s : public NFDescStoreSeqOP {
		SOAcitveGoodsData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t activeId;
		uint32_t pageId;
		NFArray<struct ComPair64_s, 12> buyCount;

		virtual void write_to_pbmsg(::proto_ff::SOAcitveGoodsData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SOAcitveGoodsData & msg);
		static ::proto_ff::SOAcitveGoodsData* new_pbmsg(){ return new ::proto_ff::SOAcitveGoodsData(); }
		static ::proto_ff::SOAcitveGoodsData make_pbmsg(){ return ::proto_ff::SOAcitveGoodsData(); }
	};
	typedef struct SOAcitveGoodsData_s SOAcitveGoodsData_t;

	struct CharacterDBSOAcitveData_s : public NFDescStoreSeqOP {
		CharacterDBSOAcitveData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct SOAcitveTotalRechargeData_s, 12> totalRecharge;
		NFArray<struct SOAcitveAdvanceData_s, 12> advance;
		NFArray<struct SOAcitveGoodsData_s, 12> goods;
		NFArray<struct ComPair64_s, 12> redPointClickData;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSOAcitveData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSOAcitveData & msg);
		static ::proto_ff::CharacterDBSOAcitveData* new_pbmsg(){ return new ::proto_ff::CharacterDBSOAcitveData(); }
		static ::proto_ff::CharacterDBSOAcitveData make_pbmsg(){ return ::proto_ff::CharacterDBSOAcitveData(); }
	};
	typedef struct CharacterDBSOAcitveData_s CharacterDBSOAcitveData_t;

	struct CharacterDBUseItemData_s : public NFDescStoreSeqOP {
		CharacterDBUseItemData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComPair64_s, 12> itemUseTimes;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBUseItemData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBUseItemData & msg);
		static ::proto_ff::CharacterDBUseItemData* new_pbmsg(){ return new ::proto_ff::CharacterDBUseItemData(); }
		static ::proto_ff::CharacterDBUseItemData make_pbmsg(){ return ::proto_ff::CharacterDBUseItemData(); }
	};
	typedef struct CharacterDBUseItemData_s CharacterDBUseItemData_t;

	struct CharacterDBDayUseItemData_s : public NFDescStoreSeqOP {
		CharacterDBDayUseItemData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t day;
		NFArray<struct ComPair64_s, 12> itemUseTimes;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDayUseItemData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDayUseItemData & msg);
		static ::proto_ff::CharacterDBDayUseItemData* new_pbmsg(){ return new ::proto_ff::CharacterDBDayUseItemData(); }
		static ::proto_ff::CharacterDBDayUseItemData make_pbmsg(){ return ::proto_ff::CharacterDBDayUseItemData(); }
	};
	typedef struct CharacterDBDayUseItemData_s CharacterDBDayUseItemData_t;

	struct MysteryShopDBData_s : public NFDescStoreSeqOP {
		MysteryShopDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t nId;
		uint64_t nStartTime;
		uint64_t nFinishTime;
		uint32_t nState;

		virtual void write_to_pbmsg(::proto_ff::MysteryShopDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MysteryShopDBData & msg);
		static ::proto_ff::MysteryShopDBData* new_pbmsg(){ return new ::proto_ff::MysteryShopDBData(); }
		static ::proto_ff::MysteryShopDBData make_pbmsg(){ return ::proto_ff::MysteryShopDBData(); }
	};
	typedef struct MysteryShopDBData_s MysteryShopDBData_t;

	struct CharacterDBMysteryShopData_s : public NFDescStoreSeqOP {
		CharacterDBMysteryShopData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct MysteryShopDBData_s, 12> dataList;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMysteryShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMysteryShopData & msg);
		static ::proto_ff::CharacterDBMysteryShopData* new_pbmsg(){ return new ::proto_ff::CharacterDBMysteryShopData(); }
		static ::proto_ff::CharacterDBMysteryShopData make_pbmsg(){ return ::proto_ff::CharacterDBMysteryShopData(); }
	};
	typedef struct CharacterDBMysteryShopData_s CharacterDBMysteryShopData_t;

	struct CharacterDBPackageTestRebateData_s : public NFDescStoreSeqOP {
		CharacterDBPackageTestRebateData_s();
		int CreateInit();
		int ResumeInit();
		bool bChecked;
		uint32_t state;
		uint32_t rechargeValue;
		uint32_t powerRank;
		uint64_t deadline;
		NFArray<struct ComPair64_s, 12> rewardStateMap;
		NFArray<struct ComPair64_s, 12> backStateMap;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBPackageTestRebateData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBPackageTestRebateData & msg);
		static ::proto_ff::CharacterDBPackageTestRebateData* new_pbmsg(){ return new ::proto_ff::CharacterDBPackageTestRebateData(); }
		static ::proto_ff::CharacterDBPackageTestRebateData make_pbmsg(){ return ::proto_ff::CharacterDBPackageTestRebateData(); }
	};
	typedef struct CharacterDBPackageTestRebateData_s CharacterDBPackageTestRebateData_t;

	struct FuncFightDBData_s : public NFDescStoreSeqOP {
		FuncFightDBData_s();
		int CreateInit();
		int ResumeInit();
		int64_t equip_total;
		int64_t equip_base;
		int64_t equip_strong;
		int64_t stone;
		int64_t equip_scrutiny;
		int64_t equip_suit;
		int64_t equip_awake;
		int64_t equip_enchant;
		int64_t fatestar;
		int64_t godhood;
		int64_t identify;
		int64_t partner;
		int64_t field;
		int64_t element;
		int64_t wing;
		int64_t treasure;
		int64_t fantasty_total;
		int64_t artifact_fantasty;
		int64_t horse_fantasty;
		int64_t wing_fantasty;
		int64_t fashion_fantasty;
		int64_t partner_fantasty;
		int64_t treasure_fantasty;

		virtual void write_to_pbmsg(::proto_ff::FuncFightDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FuncFightDBData & msg);
		static ::proto_ff::FuncFightDBData* new_pbmsg(){ return new ::proto_ff::FuncFightDBData(); }
		static ::proto_ff::FuncFightDBData make_pbmsg(){ return ::proto_ff::FuncFightDBData(); }
	};
	typedef struct FuncFightDBData_s FuncFightDBData_t;

	struct PowerInfo_s : public NFDescStoreSeqOP {
		PowerInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t titleId;
		int32_t curBuyNum;
		int32_t skillUpdateId;

		virtual void write_to_pbmsg(::proto_ff::PowerInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PowerInfo & msg);
		static ::proto_ff::PowerInfo* new_pbmsg(){ return new ::proto_ff::PowerInfo(); }
		static ::proto_ff::PowerInfo make_pbmsg(){ return ::proto_ff::PowerInfo(); }
	};
	typedef struct PowerInfo_s PowerInfo_t;

	struct PowerInfoDBList_s : public NFDescStoreSeqOP {
		PowerInfoDBList_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct PowerInfo_s, 12> infos;

		virtual void write_to_pbmsg(::proto_ff::PowerInfoDBList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PowerInfoDBList & msg);
		static ::proto_ff::PowerInfoDBList* new_pbmsg(){ return new ::proto_ff::PowerInfoDBList(); }
		static ::proto_ff::PowerInfoDBList make_pbmsg(){ return ::proto_ff::PowerInfoDBList(); }
	};
	typedef struct PowerInfoDBList_s PowerInfoDBList_t;

	struct OccupationTaskInfo_s : public NFDescStoreSeqOP {
		OccupationTaskInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t taskID;
		int32_t curValue;
		int32_t taskState;

		virtual void write_to_pbmsg(::proto_ff::OccupationTaskInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationTaskInfo & msg);
		static ::proto_ff::OccupationTaskInfo* new_pbmsg(){ return new ::proto_ff::OccupationTaskInfo(); }
		static ::proto_ff::OccupationTaskInfo make_pbmsg(){ return ::proto_ff::OccupationTaskInfo(); }
	};
	typedef struct OccupationTaskInfo_s OccupationTaskInfo_t;

	struct OccupationTakeList_s : public NFDescStoreSeqOP {
		OccupationTakeList_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct OccupationTaskInfo_s, 12> tasks;

		virtual void write_to_pbmsg(::proto_ff::OccupationTakeList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationTakeList & msg);
		static ::proto_ff::OccupationTakeList* new_pbmsg(){ return new ::proto_ff::OccupationTakeList(); }
		static ::proto_ff::OccupationTakeList make_pbmsg(){ return ::proto_ff::OccupationTakeList(); }
	};
	typedef struct OccupationTakeList_s OccupationTakeList_t;

	struct ComStarInfo_s : public NFDescStoreSeqOP {
		ComStarInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		int32_t star_lv;

		virtual void write_to_pbmsg(::proto_ff::ComStarInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComStarInfo & msg);
		static ::proto_ff::ComStarInfo* new_pbmsg(){ return new ::proto_ff::ComStarInfo(); }
		static ::proto_ff::ComStarInfo make_pbmsg(){ return ::proto_ff::ComStarInfo(); }
	};
	typedef struct ComStarInfo_s ComStarInfo_t;

	struct CharacterDBHeadSetData_s : public NFDescStoreSeqOP {
		CharacterDBHeadSetData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ComStarInfo_s, 12> headList;
		uint64_t cur_head_id;
		NFArray<struct ComStarInfo_s, 12> frameList;
		uint64_t cur_frame_id;
		NFArray<struct ComStarInfo_s, 12> bubbleList;
		uint64_t cur_bubble_id;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBHeadSetData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBHeadSetData & msg);
		static ::proto_ff::CharacterDBHeadSetData* new_pbmsg(){ return new ::proto_ff::CharacterDBHeadSetData(); }
		static ::proto_ff::CharacterDBHeadSetData make_pbmsg(){ return ::proto_ff::CharacterDBHeadSetData(); }
	};
	typedef struct CharacterDBHeadSetData_s CharacterDBHeadSetData_t;

	struct CharacterDBOnlineGiftInfo_s : public NFDescStoreSeqOP {
		CharacterDBOnlineGiftInfo_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t state;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOnlineGiftInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOnlineGiftInfo & msg);
		static ::proto_ff::CharacterDBOnlineGiftInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBOnlineGiftInfo(); }
		static ::proto_ff::CharacterDBOnlineGiftInfo make_pbmsg(){ return ::proto_ff::CharacterDBOnlineGiftInfo(); }
	};
	typedef struct CharacterDBOnlineGiftInfo_s CharacterDBOnlineGiftInfo_t;

	struct CharacterDBOnlineGiftData_s : public NFDescStoreSeqOP {
		CharacterDBOnlineGiftData_s();
		int CreateInit();
		int ResumeInit();
		int32_t online_time;
		NFArray<struct CharacterDBOnlineGiftInfo_s, 12> infos;
		int32_t reset_day;
		int64_t lasttime;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBOnlineGiftData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBOnlineGiftData & msg);
		static ::proto_ff::CharacterDBOnlineGiftData* new_pbmsg(){ return new ::proto_ff::CharacterDBOnlineGiftData(); }
		static ::proto_ff::CharacterDBOnlineGiftData make_pbmsg(){ return ::proto_ff::CharacterDBOnlineGiftData(); }
	};
	typedef struct CharacterDBOnlineGiftData_s CharacterDBOnlineGiftData_t;

	struct CharDropItemDBProto_s : public NFDescStoreSeqOP {
		CharDropItemDBProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t itemid;
		int64_t num;

		virtual void write_to_pbmsg(::proto_ff::CharDropItemDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharDropItemDBProto & msg);
		static ::proto_ff::CharDropItemDBProto* new_pbmsg(){ return new ::proto_ff::CharDropItemDBProto(); }
		static ::proto_ff::CharDropItemDBProto make_pbmsg(){ return ::proto_ff::CharDropItemDBProto(); }
	};
	typedef struct CharDropItemDBProto_s CharDropItemDBProto_t;

	struct CharDropMultItemDBProto_s : public NFDescStoreSeqOP {
		CharDropMultItemDBProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharDropItemDBProto_s, 12> info;

		virtual void write_to_pbmsg(::proto_ff::CharDropMultItemDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharDropMultItemDBProto & msg);
		static ::proto_ff::CharDropMultItemDBProto* new_pbmsg(){ return new ::proto_ff::CharDropMultItemDBProto(); }
		static ::proto_ff::CharDropMultItemDBProto make_pbmsg(){ return ::proto_ff::CharDropMultItemDBProto(); }
	};
	typedef struct CharDropMultItemDBProto_s CharDropMultItemDBProto_t;

	struct CharDropLimitDBData_s : public NFDescStoreSeqOP {
		CharDropLimitDBData_s();
		int CreateInit();
		int ResumeInit();
		struct CharDropMultItemDBProto_s limit;
		uint64_t fresh_time;

		virtual void write_to_pbmsg(::proto_ff::CharDropLimitDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharDropLimitDBData & msg);
		static ::proto_ff::CharDropLimitDBData* new_pbmsg(){ return new ::proto_ff::CharDropLimitDBData(); }
		static ::proto_ff::CharDropLimitDBData make_pbmsg(){ return ::proto_ff::CharDropLimitDBData(); }
	};
	typedef struct CharDropLimitDBData_s CharDropLimitDBData_t;

	struct CharacterDBGmHelpData_s : public NFDescStoreSeqOP {
		CharacterDBGmHelpData_s();
		int CreateInit();
		int ResumeInit();
		int64_t timeEnd;
		int64_t helpTime;
		int32_t helpDay;
		int64_t applyTime;
		int32_t applyDay;
		int64_t helpcid;
		NFArray<struct ComPair_s, 12> helpState;
		int32_t applyResult;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBGmHelpData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBGmHelpData & msg);
		static ::proto_ff::CharacterDBGmHelpData* new_pbmsg(){ return new ::proto_ff::CharacterDBGmHelpData(); }
		static ::proto_ff::CharacterDBGmHelpData make_pbmsg(){ return ::proto_ff::CharacterDBGmHelpData(); }
	};
	typedef struct CharacterDBGmHelpData_s CharacterDBGmHelpData_t;

	struct GMToolsDB_s : public NFDescStoreSeqOP {
		GMToolsDB_s();
		int CreateInit();
		int ResumeInit();
		NFArray<int32_t, 12> gifts;
		NFArray<struct ComPair_s, 12> unlimits;
		uint64_t refresh_time;
		uint64_t cur_use;

		virtual void write_to_pbmsg(::proto_ff::GMToolsDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMToolsDB & msg);
		static ::proto_ff::GMToolsDB* new_pbmsg(){ return new ::proto_ff::GMToolsDB(); }
		static ::proto_ff::GMToolsDB make_pbmsg(){ return ::proto_ff::GMToolsDB(); }
	};
	typedef struct GMToolsDB_s GMToolsDB_t;

	struct CharacterDBGodGMData_s : public NFDescStoreSeqOP {
		CharacterDBGodGMData_s();
		int CreateInit();
		int ResumeInit();
		int32_t curType;
		int64_t timeEnd;
		int32_t curExchangeNum;
		int32_t normalGiftState;
		int32_t seniorGiftState;
		int64_t lastTime;
		int32_t unlock;
		struct GMToolsDB_s gmtool;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBGodGMData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBGodGMData & msg);
		static ::proto_ff::CharacterDBGodGMData* new_pbmsg(){ return new ::proto_ff::CharacterDBGodGMData(); }
		static ::proto_ff::CharacterDBGodGMData make_pbmsg(){ return ::proto_ff::CharacterDBGodGMData(); }
	};
	typedef struct CharacterDBGodGMData_s CharacterDBGodGMData_t;

	struct BowlDBRewardProto_s : public NFDescStoreSeqOP {
		BowlDBRewardProto_s();
		int CreateInit();
		int ResumeInit();
		uint32_t recharge_id;
		uint32_t count;

		virtual void write_to_pbmsg(::proto_ff::BowlDBRewardProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BowlDBRewardProto & msg);
		static ::proto_ff::BowlDBRewardProto* new_pbmsg(){ return new ::proto_ff::BowlDBRewardProto(); }
		static ::proto_ff::BowlDBRewardProto make_pbmsg(){ return ::proto_ff::BowlDBRewardProto(); }
	};
	typedef struct BowlDBRewardProto_s BowlDBRewardProto_t;

	struct BowlDBData_s : public NFDescStoreSeqOP {
		BowlDBData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t level;
		int32_t active;
		NFArray<struct BowlDBRewardProto_s, 12> info;

		virtual void write_to_pbmsg(::proto_ff::BowlDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BowlDBData & msg);
		static ::proto_ff::BowlDBData* new_pbmsg(){ return new ::proto_ff::BowlDBData(); }
		static ::proto_ff::BowlDBData make_pbmsg(){ return ::proto_ff::BowlDBData(); }
	};
	typedef struct BowlDBData_s BowlDBData_t;

	struct HidePeriodDBProto_s : public NFDescStoreSeqOP {
		HidePeriodDBProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		uint64_t total;
		int32_t reward;
		uint64_t lasttime;

		virtual void write_to_pbmsg(::proto_ff::HidePeriodDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HidePeriodDBProto & msg);
		static ::proto_ff::HidePeriodDBProto* new_pbmsg(){ return new ::proto_ff::HidePeriodDBProto(); }
		static ::proto_ff::HidePeriodDBProto make_pbmsg(){ return ::proto_ff::HidePeriodDBProto(); }
	};
	typedef struct HidePeriodDBProto_s HidePeriodDBProto_t;

	struct CharacterDBHideData_s : public NFDescStoreSeqOP {
		CharacterDBHideData_s();
		int CreateInit();
		int ResumeInit();
		int32_t forever_quota;
		int64_t lastTime;
		int32_t unit_quota;
		NFArray<int32_t, 12> unit_ids;
		NFArray<int32_t, 12> unit_once_ids;
		NFArray<int32_t, 12> f_ids;
		int64_t ctime;
		int32_t days;
		NFArray<struct HidePeriodDBProto_s, 12> period;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBHideData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBHideData & msg);
		static ::proto_ff::CharacterDBHideData* new_pbmsg(){ return new ::proto_ff::CharacterDBHideData(); }
		static ::proto_ff::CharacterDBHideData make_pbmsg(){ return ::proto_ff::CharacterDBHideData(); }
	};
	typedef struct CharacterDBHideData_s CharacterDBHideData_t;

	struct tbRoleInfo_s : public NFDescStoreSeqOP {
		tbRoleInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t charId;
		uint64_t playerId;
		uint64_t bornZoneId;
		NFSizeString<128> charName;
		NFSizeString<128> platId;
		uint64_t deletechartime;
		int32_t dirty;
		struct CharacterDBBaseInfo_s baseData;
		struct CharacterDBPackageData_s itemData;
		struct CharacterDBTaskData_s taskData;
		struct CharacterDBSkillData_s skillData;
		struct CharacterDBExtendData_s extendData;
		struct CharacterDBEquipData_s equipData;
		struct CharacterDBDuplicateData_s duplicateData;
		struct CharacterAchievementDBData_s achievementData;
		struct CharacterBuffData_s buffData;
		struct CharacterArenaData_s arenaData;
		struct CharacterTitleSaveData_s titleData;
		struct CharacterDBOperateLimitInfo_s operateLimitData;
		struct CharacterDBHuoYueDuInfo_s huoYueDuData;
		struct CharacterDBOperateData_s operateData;
		struct CharacterDBActiveInfo_s playerActiveInfo;
		struct CharacterPayData_s cPayData;
		struct FunctionUnlockInfo_s unlockInfo;
		struct CharacterDBEmblemData_s emblemData;
		struct CharacterDBIdentifyData_s identifyData;
		struct CharacterDBElementData_s elementData;
		struct CharacterDBFashionData_s fashionData;
		struct CharacterDBWingData_s wingData;
		struct CharacterDBMountData_s mountData;
		struct CharacterDBBossData_s bossData;
		struct CharacterDBPvpData_s pvpData;
		struct CharacterDBTreasureData_s treasure_data;
		struct CharacterDBArtifactData_s artifact_data;
		struct CharacterDBFateStarData_s fateStarData;
		struct CharacterDBConvoyData_s convoyData;
		struct CharacterDBDailyData_s daily_data;
		struct CharacterDBFieldData_s field_data;
		struct CharacterDBVipData_s vipData;
		struct CharacterDBPartnerData_s partnerData;
		struct CharacterDBMallData_s mallData;
		struct CharacterDBGodhoodData_s godhoodData;
		struct CharacterDBRecoveryData_s recoveryData;
		struct CharacterDBActivityData_s activityData;
		struct CharacterDBSOAcitveData_s soActivityData;
		struct CharacterDBUseItemData_s useitemData;
		struct CharacterDBDayUseItemData_s dayUseItemData;
		struct CharacterDBMysteryShopData_s mysteryshop_data;
		struct CharacterDBPackageTestRebateData_s packagetestrebate_data;
		struct FuncFightDBData_s fight_data;
		struct PowerInfoDBList_s power_data;
		struct OccupationTakeList_s occupation_data;
		struct CharacterDBHeadSetData_s headset_data;
		struct CharacterDBOnlineGiftData_s online_gift_data;
		struct CharDropLimitDBData_s droplimit_data;
		struct CharacterDBGmHelpData_s gmhelp_data;
		struct CharacterDBGodGMData_s godgm_data;
		struct BowlDBData_s bowl_data;
		struct CharacterDBPackageData_s bagitemData;
		struct CharacterDBHideData_s hide_data;

		virtual void write_to_pbmsg(::proto_ff::tbRoleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbRoleInfo & msg);
		static ::proto_ff::tbRoleInfo* new_pbmsg(){ return new ::proto_ff::tbRoleInfo(); }
		static ::proto_ff::tbRoleInfo make_pbmsg(){ return ::proto_ff::tbRoleInfo(); }
	};
	typedef struct tbRoleInfo_s tbRoleInfo_t;

	struct CharacterDBSimpleInfo_s {
		CharacterDBSimpleInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t charId;
		std::string name;
		uint32_t sex;
		uint32_t prof;
		uint32_t level;
		int64_t exp;
		uint64_t hp;
		uint64_t fightPower;
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
		struct CharFacadeProto_s facade;
		int32_t curstate;
		uint64_t deletechartime;
		uint64_t createTime;
		uint32_t totalpay;
		float clx;
		float cly;
		float clz;
		uint64_t occupation;
		uint64_t aptitude;
		int32_t finish_flag;
		std::string platid;
		int32_t palace_layer;
		int32_t palace_break_count;
		int32_t dirty;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBSimpleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBSimpleInfo & msg);
		static ::proto_ff::CharacterDBSimpleInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBSimpleInfo(); }
		static ::proto_ff::CharacterDBSimpleInfo make_pbmsg(){ return ::proto_ff::CharacterDBSimpleInfo(); }
	};
	typedef struct CharacterDBSimpleInfo_s CharacterDBSimpleInfo_t;

}

