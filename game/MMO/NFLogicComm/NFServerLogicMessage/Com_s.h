#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Com.pb.h"
#include "Com_s.h"
#include "common_logic.pb.h"
#include "common_logic_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

#define DEFINE_ROLEFACADEPROTO_GROWFACADE_MAX_NUM 30
#define DEFINE_PETINFO_EXCLUSIVESKILLLVVEC_MAX_NUM 1
#define DEFINE_PETINFO_PASSIVESKILLLVVEC_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_BASE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_REFINE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_BLUE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_GOD_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_SPECIAL_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_STONES_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_WASHS_MAX_NUM 1
#define DEFINE_MULTITEMSIMPLEPROTO_INFO_MAX_NUM 1
#define DEFINE_MAILPARAMPROTO_STR_PARAM_MAX_NUM 1
#define DEFINE_MAILPARAMPROTO_INT_PARAM_MAX_NUM 1
#define DEFINE_MAILATTACHMENTLIST_ITEMINFO_MAX_NUM 1
#define DEFINE_WEBMAILDATAPROTO_ITEMLIST_MAX_NUM 1
#define DEFINE_USEITEMARGPROTO_ITEM_LST_MAX_NUM 1
#define DEFINE_FUNCTIONUNLOCKINFO_DATA_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_FRIENDLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_BLACKLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_HATELIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_APPLYLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_GIFTRECORDS_MAX_NUM 1
#define DEFINE_BUFFLISTPROTO_INFO_MAX_NUM 1
#define DEFINE_SKILLGROUPPROTO_LST_MAX_NUM 1
#define DEFINE_SKILLGROUPLISTPROTO_INFO_MAX_NUM 1
#define DEFINE_GODEVILTASKLISTPROTO_LST_MAX_NUM 1
#define DEFINE_GODRELICSTASKGROUPENTRY_ENTRYS_MAX_NUM 1
#define DEFINE_DAILYTASKBACKENTRY_DAY_DATA_MAX_NUM 1
#define DEFINE_DAILYTASKALLDATA_TASK_DATA_MAX_NUM 1
#define DEFINE_DAILYTASKALLDATA_TASK_LIMIT_DATA_MAX_NUM 1
#define DEFINE_DAILYTASKALLDATA_BACK_DATA_MAX_NUM 1
#define DEFINE_DAILYTASKALLDATA_REWARD_DATA_MAX_NUM 1
#define DEFINE_CHARACTERDBMISSIONTRACK_ITEMINFO_MAX_NUM 1
#define DEFINE_GUILDPRESTIGEMISSIONDB_TASK_POOL_MAX_NUM 1
#define DEFINE_CHARACTERDBTASKDATA_MISSIONTRACK_MAX_NUM 1
#define DEFINE_CHARACTERDBTASKDATA_DYINFO_MAX_NUM 1
#define DEFINE_CHARACTERDBTASKDATA_ALREADY_SUBMIT_MAX_NUM 1
#define DEFINE_CHARACTERDBTASKDATA_RECENT_SUBMIT_MAX_NUM 1
#define DEFINE_NOTIFYVIPDATARSP_IDS_MAX_NUM 1
#define DEFINE_ARENACHALLRESULT_ITEMS_MAX_NUM 1
#define DEFINE_FACADESOULDATA_SKILL_DATA_MAX_NUM 1
#define DEFINE_FACADESOULDATA_ACVIITY_DATA_MAX_NUM 1
#define DEFINE_DEITYEQUIPDATA_INFOS_MAX_NUM 1
#define DEFINE_DEITYEQUIPDATA_LV_ATTR_MAX_NUM 1
#define DEFINE_DEITYFANTASYDATA_SKILL_DATA_MAX_NUM 1
#define DEFINE_DEITYFANTASYDATA_EQUIP_SUIT_DATA_MAX_NUM 1
#define DEFINE_ARMORINFO_SUITS_MAX_NUM 1
#define DEFINE_ARMORINFO_POS_MAX_NUM 1
#define DEFINE_OCCUPATIONMISSIONSTAGEDATA_SOUL_DATA_MAX_NUM 1
#define DEFINE_OCCUPATIONMISSIONGRADEDATA_STAGE_DATA_MAX_NUM 1
#define DEFINE_OCCUPATIONMISSIONDATA_GRADE_DATA_MAX_NUM 1
#define DEFINE_BESTEQEQUIPINFO_SKILLS_MAX_NUM 1
#define DEFINE_BESTEQBREAK_EXPS_MAX_NUM 1
#define DEFINE_BESTEQBREAK_GENATTR_MAX_NUM 1


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
		uint32_t key;//
		uint32_t value;//

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
		uint64_t key;//
		uint64_t value;//

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
		uint32_t key;//
		bool value;//

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
		uint64_t item_id;//
		uint64_t item_num;//

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
		uint64_t item_id;//
		uint64_t item_num;//
		uint32_t type;//

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
		float x;//
		float y;//
		float z;//

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
		float x;//
		float y;//

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
		uint32_t id;//
		int64_t value;//

		virtual void write_to_pbmsg(::proto_ff::Attr64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr64 & msg);
		static ::proto_ff::Attr64* new_pbmsg(){ return new ::proto_ff::Attr64(); }
		static ::proto_ff::Attr64 make_pbmsg(){ return ::proto_ff::Attr64(); }
	};
	typedef struct Attr64_s Attr64_t;

	struct RoleFacadeProto_s : public NFDescStoreSeqOP {
		RoleFacadeProto_s();
		virtual ~RoleFacadeProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct Attr64_s, DEFINE_ROLEFACADEPROTO_GROWFACADE_MAX_NUM> growFacade;//
		int32_t color;//
		int32_t prof;//

		virtual void write_to_pbmsg(::proto_ff::RoleFacadeProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleFacadeProto & msg);
		static ::proto_ff::RoleFacadeProto* new_pbmsg(){ return new ::proto_ff::RoleFacadeProto(); }
		static ::proto_ff::RoleFacadeProto make_pbmsg(){ return ::proto_ff::RoleFacadeProto(); }
	};
	typedef struct RoleFacadeProto_s RoleFacadeProto_t;

	struct RoleListDBProto_s : public NFDescStoreSeqOP {
		RoleListDBProto_s();
		virtual ~RoleListDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		uint32_t prof;//
		uint32_t level;//
		uint64_t fight;//
		uint64_t createtime;//
		struct RoleFacadeProto_s facade;//
		uint64_t sceneid;//
		uint64_t mapid;//
		struct Vector3PB_s pos;//
		uint64_t lastsceneid;//
		uint64_t lastmapid;//
		struct Vector3PB_s lastpos;//

		virtual void write_to_pbmsg(::proto_ff::RoleListDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleListDBProto & msg);
		static ::proto_ff::RoleListDBProto* new_pbmsg(){ return new ::proto_ff::RoleListDBProto(); }
		static ::proto_ff::RoleListDBProto make_pbmsg(){ return ::proto_ff::RoleListDBProto(); }
	};
	typedef struct RoleListDBProto_s RoleListDBProto_t;

	struct LoginRoleProto_s : public NFDescStoreSeqOP {
		LoginRoleProto_s();
		virtual ~LoginRoleProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		uint32_t prof;//
		uint32_t level;//
		uint64_t fight;//
		uint64_t createtime;//
		struct RoleFacadeProto_s facade;//

		virtual void write_to_pbmsg(::proto_ff::LoginRoleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LoginRoleProto & msg);
		static ::proto_ff::LoginRoleProto* new_pbmsg(){ return new ::proto_ff::LoginRoleProto(); }
		static ::proto_ff::LoginRoleProto make_pbmsg(){ return ::proto_ff::LoginRoleProto(); }
	};
	typedef struct LoginRoleProto_s LoginRoleProto_t;

	struct LoginSyncProto_s : public NFDescStoreSeqOP {
		LoginSyncProto_s();
		virtual ~LoginSyncProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;//
		NFShmString<32> faction_name;//
		int32_t duty;//
		uint64_t faction_leader;//
		int32_t faction_level;//
		uint32_t team_id;//
		uint64_t leader;//
		int32_t mem_count;//
		int32_t cloness_lev;//

		virtual void write_to_pbmsg(::proto_ff::LoginSyncProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LoginSyncProto & msg);
		static ::proto_ff::LoginSyncProto* new_pbmsg(){ return new ::proto_ff::LoginSyncProto(); }
		static ::proto_ff::LoginSyncProto make_pbmsg(){ return ::proto_ff::LoginSyncProto(); }
	};
	typedef struct LoginSyncProto_s LoginSyncProto_t;

	struct CenterRoleProto_s : public NFDescStoreSeqOP {
		CenterRoleProto_s();
		virtual ~CenterRoleProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint32_t uid;//
		NFShmString<32> name;//
		uint32_t level;//
		uint64_t fight;//
		uint64_t lastlogout;//
		struct RoleFacadeProto_s facade;//
		uint32_t vip_level;//
		int64_t hp;//
		int64_t max_hp;//

		virtual void write_to_pbmsg(::proto_ff::CenterRoleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CenterRoleProto & msg);
		static ::proto_ff::CenterRoleProto* new_pbmsg(){ return new ::proto_ff::CenterRoleProto(); }
		static ::proto_ff::CenterRoleProto make_pbmsg(){ return ::proto_ff::CenterRoleProto(); }
	};
	typedef struct CenterRoleProto_s CenterRoleProto_t;

	struct SocialRoleProto_s : public NFDescStoreSeqOP {
		SocialRoleProto_s();
		virtual ~SocialRoleProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint32_t uid;//
		NFShmString<32> name;//
		uint32_t prof;//
		uint32_t level;//
		uint64_t fight;//
		uint64_t lastlogout;//
		struct RoleFacadeProto_s facade;//
		uint32_t vip_level;//
		uint32_t zid;//
		bool isonline;//
		int64_t hp;//
		int64_t max_hp;//
		uint64_t sceneid;//
		uint64_t mapid;//

		virtual void write_to_pbmsg(::proto_ff::SocialRoleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SocialRoleProto & msg);
		static ::proto_ff::SocialRoleProto* new_pbmsg(){ return new ::proto_ff::SocialRoleProto(); }
		static ::proto_ff::SocialRoleProto make_pbmsg(){ return ::proto_ff::SocialRoleProto(); }
	};
	typedef struct SocialRoleProto_s SocialRoleProto_t;

	struct Attr_s : public NFDescStoreSeqOP {
		Attr_s();
		virtual ~Attr_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t value;//

		virtual void write_to_pbmsg(::proto_ff::Attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr & msg);
		static ::proto_ff::Attr* new_pbmsg(){ return new ::proto_ff::Attr(); }
		static ::proto_ff::Attr make_pbmsg(){ return ::proto_ff::Attr(); }
	};
	typedef struct Attr_s Attr_t;

	struct BlueStarAttr_s : public NFDescStoreSeqOP {
		BlueStarAttr_s();
		virtual ~BlueStarAttr_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		int64_t value;//
		int32_t lv_part;//

		virtual void write_to_pbmsg(::proto_ff::BlueStarAttr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BlueStarAttr & msg);
		static ::proto_ff::BlueStarAttr* new_pbmsg(){ return new ::proto_ff::BlueStarAttr(); }
		static ::proto_ff::BlueStarAttr make_pbmsg(){ return ::proto_ff::BlueStarAttr(); }
	};
	typedef struct BlueStarAttr_s BlueStarAttr_t;

	struct PetInfo_s : public NFDescStoreSeqOP {
		PetInfo_s();
		virtual ~PetInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t instId;//
		int64_t cfgid;//
		int32_t lv;//
		int32_t steplv;//
		int32_t starlv;//
		int32_t activeSkillLv;//
		NFShmVector<int32_t, DEFINE_PETINFO_EXCLUSIVESKILLLVVEC_MAX_NUM> exclusiveSkillLvVec;//
		NFShmVector<int32_t, DEFINE_PETINFO_PASSIVESKILLLVVEC_MAX_NUM> passiveSkillLvVec;//
		float initgrow;//
		int32_t slot;//
		int32_t lvexp;//

		virtual void write_to_pbmsg(::proto_ff::PetInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetInfo & msg);
		static ::proto_ff::PetInfo* new_pbmsg(){ return new ::proto_ff::PetInfo(); }
		static ::proto_ff::PetInfo make_pbmsg(){ return ::proto_ff::PetInfo(); }
	};
	typedef struct PetInfo_s PetInfo_t;

	struct PetHatchInfo_s : public NFDescStoreSeqOP {
		PetHatchInfo_s();
		virtual ~PetHatchInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot;//
		int32_t unlock;//
		int64_t eggid;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::PetHatchInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetHatchInfo & msg);
		static ::proto_ff::PetHatchInfo* new_pbmsg(){ return new ::proto_ff::PetHatchInfo(); }
		static ::proto_ff::PetHatchInfo make_pbmsg(){ return ::proto_ff::PetHatchInfo(); }
	};
	typedef struct PetHatchInfo_s PetHatchInfo_t;

	struct ItemProtoInfo_s : public NFDescStoreSeqOP {
		ItemProtoInfo_s();
		virtual ~ItemProtoInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t index;//
		uint64_t item_id;//
		int64_t item_num;//
		int32_t bind;//
		int32_t level;//
		NFShmVector<struct Attr_s, DEFINE_ITEMPROTOINFO_BASE_MAX_NUM> base;//
		NFShmVector<struct Attr_s, DEFINE_ITEMPROTOINFO_REFINE_MAX_NUM> refine;//
		NFShmVector<struct BlueStarAttr_s, DEFINE_ITEMPROTOINFO_BLUE_MAX_NUM> blue;//
		NFShmVector<struct Attr_s, DEFINE_ITEMPROTOINFO_GOD_MAX_NUM> god;//
		NFShmVector<struct Attr_s, DEFINE_ITEMPROTOINFO_SPECIAL_MAX_NUM> special;//
		uint64_t expireTime;//
		int32_t strong_lv;//
		int32_t strong_wear_quality;//

		virtual void write_to_pbmsg(::proto_ff::ItemProtoInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemProtoInfo & msg);
		static ::proto_ff::ItemProtoInfo* new_pbmsg(){ return new ::proto_ff::ItemProtoInfo(); }
		static ::proto_ff::ItemProtoInfo make_pbmsg(){ return ::proto_ff::ItemProtoInfo(); }
	};
	typedef struct ItemProtoInfo_s ItemProtoInfo_t;

	struct StoneSlotInfo_s : public NFDescStoreSeqOP {
		StoneSlotInfo_s();
		virtual ~StoneSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t stone_pos;//
		int64_t stoneid;//

		virtual void write_to_pbmsg(::proto_ff::StoneSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StoneSlotInfo & msg);
		static ::proto_ff::StoneSlotInfo* new_pbmsg(){ return new ::proto_ff::StoneSlotInfo(); }
		static ::proto_ff::StoneSlotInfo make_pbmsg(){ return ::proto_ff::StoneSlotInfo(); }
	};
	typedef struct StoneSlotInfo_s StoneSlotInfo_t;

	struct WashSlotInfo_s : public NFDescStoreSeqOP {
		WashSlotInfo_s();
		virtual ~WashSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot;//
		int32_t quality;//
		int32_t lock;//
		int32_t id;//
		int32_t value;//

		virtual void write_to_pbmsg(::proto_ff::WashSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WashSlotInfo & msg);
		static ::proto_ff::WashSlotInfo* new_pbmsg(){ return new ::proto_ff::WashSlotInfo(); }
		static ::proto_ff::WashSlotInfo make_pbmsg(){ return ::proto_ff::WashSlotInfo(); }
	};
	typedef struct WashSlotInfo_s WashSlotInfo_t;

	struct EquipSlotInfo_s : public NFDescStoreSeqOP {
		EquipSlotInfo_s();
		virtual ~EquipSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot_pos;//
		int64_t total_score;//
		int32_t stronglv;//
		NFShmVector<struct StoneSlotInfo_s, DEFINE_EQUIPSLOTINFO_STONES_MAX_NUM> stones;//
		int32_t stone_pay_slot_open;//
		NFShmVector<struct WashSlotInfo_s, DEFINE_EQUIPSLOTINFO_WASHS_MAX_NUM> washs;//
		int32_t suitlv;//

		virtual void write_to_pbmsg(::proto_ff::EquipSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipSlotInfo & msg);
		static ::proto_ff::EquipSlotInfo* new_pbmsg(){ return new ::proto_ff::EquipSlotInfo(); }
		static ::proto_ff::EquipSlotInfo make_pbmsg(){ return ::proto_ff::EquipSlotInfo(); }
	};
	typedef struct EquipSlotInfo_s EquipSlotInfo_t;

	struct EquipInfo_s : public NFDescStoreSeqOP {
		EquipInfo_s();
		virtual ~EquipInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t pos;//
		struct ItemProtoInfo_s equip;//
		struct EquipSlotInfo_s slot;//

		virtual void write_to_pbmsg(::proto_ff::EquipInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipInfo & msg);
		static ::proto_ff::EquipInfo* new_pbmsg(){ return new ::proto_ff::EquipInfo(); }
		static ::proto_ff::EquipInfo make_pbmsg(){ return ::proto_ff::EquipInfo(); }
	};
	typedef struct EquipInfo_s EquipInfo_t;

	struct EquipLvAttrInfo_s : public NFDescStoreSeqOP {
		EquipLvAttrInfo_s();
		virtual ~EquipLvAttrInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;//
		int32_t id;//

		virtual void write_to_pbmsg(::proto_ff::EquipLvAttrInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipLvAttrInfo & msg);
		static ::proto_ff::EquipLvAttrInfo* new_pbmsg(){ return new ::proto_ff::EquipLvAttrInfo(); }
		static ::proto_ff::EquipLvAttrInfo make_pbmsg(){ return ::proto_ff::EquipLvAttrInfo(); }
	};
	typedef struct EquipLvAttrInfo_s EquipLvAttrInfo_t;

	struct ItemSimpleProto_s : public NFDescStoreSeqOP {
		ItemSimpleProto_s();
		virtual ~ItemSimpleProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t itemid;//
		int64_t num;//
		int32_t bind;//

		virtual void write_to_pbmsg(::proto_ff::ItemSimpleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemSimpleProto & msg);
		static ::proto_ff::ItemSimpleProto* new_pbmsg(){ return new ::proto_ff::ItemSimpleProto(); }
		static ::proto_ff::ItemSimpleProto make_pbmsg(){ return ::proto_ff::ItemSimpleProto(); }
	};
	typedef struct ItemSimpleProto_s ItemSimpleProto_t;

	struct MultItemSimpleProto_s : public NFDescStoreSeqOP {
		MultItemSimpleProto_s();
		virtual ~MultItemSimpleProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ItemSimpleProto_s, DEFINE_MULTITEMSIMPLEPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::MultItemSimpleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MultItemSimpleProto & msg);
		static ::proto_ff::MultItemSimpleProto* new_pbmsg(){ return new ::proto_ff::MultItemSimpleProto(); }
		static ::proto_ff::MultItemSimpleProto make_pbmsg(){ return ::proto_ff::MultItemSimpleProto(); }
	};
	typedef struct MultItemSimpleProto_s MultItemSimpleProto_t;

	struct MailParamProto_s : public NFDescStoreSeqOP {
		MailParamProto_s();
		virtual ~MailParamProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cfgid;//
		NFShmVector<NFShmString<32>, DEFINE_MAILPARAMPROTO_STR_PARAM_MAX_NUM> str_param;//
		NFShmVector<uint64_t, DEFINE_MAILPARAMPROTO_INT_PARAM_MAX_NUM> int_param;//

		virtual void write_to_pbmsg(::proto_ff::MailParamProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailParamProto & msg);
		static ::proto_ff::MailParamProto* new_pbmsg(){ return new ::proto_ff::MailParamProto(); }
		static ::proto_ff::MailParamProto make_pbmsg(){ return ::proto_ff::MailParamProto(); }
	};
	typedef struct MailParamProto_s MailParamProto_t;

	struct MailStrProto_s : public NFDescStoreSeqOP {
		MailStrProto_s();
		virtual ~MailStrProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> str;//
		struct MailParamProto_s param;//

		virtual void write_to_pbmsg(::proto_ff::MailStrProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailStrProto & msg);
		static ::proto_ff::MailStrProto* new_pbmsg(){ return new ::proto_ff::MailStrProto(); }
		static ::proto_ff::MailStrProto make_pbmsg(){ return ::proto_ff::MailStrProto(); }
	};
	typedef struct MailStrProto_s MailStrProto_t;

	struct MailAttachmentList_s : public NFDescStoreSeqOP {
		MailAttachmentList_s();
		virtual ~MailAttachmentList_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ItemProtoInfo_s, DEFINE_MAILATTACHMENTLIST_ITEMINFO_MAX_NUM> itemInfo;//

		virtual void write_to_pbmsg(::proto_ff::MailAttachmentList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailAttachmentList & msg);
		static ::proto_ff::MailAttachmentList* new_pbmsg(){ return new ::proto_ff::MailAttachmentList(); }
		static ::proto_ff::MailAttachmentList make_pbmsg(){ return ::proto_ff::MailAttachmentList(); }
	};
	typedef struct MailAttachmentList_s MailAttachmentList_t;

	struct MailHead_s : public NFDescStoreSeqOP {
		MailHead_s();
		virtual ~MailHead_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t mailId;//
		uint32_t type;//
		uint64_t sendPlayerId;//
		NFShmString<32> sendPlayerName;//
		uint64_t destPlayerId;//
		struct MailStrProto_s topic;//
		uint64_t createTime;//
		uint32_t status;//
		int32_t fetch;//
		int32_t has_attach;//
		uint64_t begin_time;//
		uint64_t end_time;//

		virtual void write_to_pbmsg(::proto_ff::MailHead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailHead & msg);
		static ::proto_ff::MailHead* new_pbmsg(){ return new ::proto_ff::MailHead(); }
		static ::proto_ff::MailHead make_pbmsg(){ return ::proto_ff::MailHead(); }
	};
	typedef struct MailHead_s MailHead_t;

	struct MailInfo_s : public NFDescStoreSeqOP {
		MailInfo_s();
		virtual ~MailInfo_s(){}
		int CreateInit();
		int ResumeInit();
		struct MailHead_s mailHead;//
		struct MailStrProto_s content;//
		uint64_t gold;//
		uint64_t diamond;//
		uint64_t bindDiamond;//
		uint64_t magiccrystal;//
		uint64_t prestige;//
		struct MailAttachmentList_s attachmentList;//
		int32_t source;//
		int64_t sourceVal;//

		virtual void write_to_pbmsg(::proto_ff::MailInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailInfo & msg);
		static ::proto_ff::MailInfo* new_pbmsg(){ return new ::proto_ff::MailInfo(); }
		static ::proto_ff::MailInfo make_pbmsg(){ return ::proto_ff::MailInfo(); }
	};
	typedef struct MailInfo_s MailInfo_t;

	struct WebMailItemProto_s : public NFDescStoreSeqOP {
		WebMailItemProto_s();
		virtual ~WebMailItemProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint64_t num;//

		virtual void write_to_pbmsg(::proto_ff::WebMailItemProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WebMailItemProto & msg);
		static ::proto_ff::WebMailItemProto* new_pbmsg(){ return new ::proto_ff::WebMailItemProto(); }
		static ::proto_ff::WebMailItemProto make_pbmsg(){ return ::proto_ff::WebMailItemProto(); }
	};
	typedef struct WebMailItemProto_s WebMailItemProto_t;

	struct WebMailDataProto_s : public NFDescStoreSeqOP {
		WebMailDataProto_s();
		virtual ~WebMailDataProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t mailId;//
		uint64_t createTime;//
		struct MailStrProto_s topic;//
		int32_t fetch;//
		struct MailStrProto_s content;//
		uint64_t gold;//
		uint64_t diamond;//
		uint64_t bindDiamond;//
		uint64_t arenaScore;//
		uint64_t magiccrystal;//
		uint64_t prestige;//
		NFShmVector<struct WebMailItemProto_s, DEFINE_WEBMAILDATAPROTO_ITEMLIST_MAX_NUM> itemList;//

		virtual void write_to_pbmsg(::proto_ff::WebMailDataProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WebMailDataProto & msg);
		static ::proto_ff::WebMailDataProto* new_pbmsg(){ return new ::proto_ff::WebMailDataProto(); }
		static ::proto_ff::WebMailDataProto make_pbmsg(){ return ::proto_ff::WebMailDataProto(); }
	};
	typedef struct WebMailDataProto_s WebMailDataProto_t;

	struct UseItemArgProto_s : public NFDescStoreSeqOP {
		UseItemArgProto_s();
		virtual ~UseItemArgProto_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t int_param;//
		NFShmString<32> str_param;//
		NFShmVector<uint64_t, DEFINE_USEITEMARGPROTO_ITEM_LST_MAX_NUM> item_lst;//

		virtual void write_to_pbmsg(::proto_ff::UseItemArgProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::UseItemArgProto & msg);
		static ::proto_ff::UseItemArgProto* new_pbmsg(){ return new ::proto_ff::UseItemArgProto(); }
		static ::proto_ff::UseItemArgProto make_pbmsg(){ return ::proto_ff::UseItemArgProto(); }
	};
	typedef struct UseItemArgProto_s UseItemArgProto_t;

	struct NotifyRoleFacadeCastRsp_s : public NFDescStoreSeqOP {
		NotifyRoleFacadeCastRsp_s();
		virtual ~NotifyRoleFacadeCastRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t roleid;//
		struct RoleFacadeProto_s facade;//

		virtual void write_to_pbmsg(::proto_ff::NotifyRoleFacadeCastRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyRoleFacadeCastRsp & msg);
		static ::proto_ff::NotifyRoleFacadeCastRsp* new_pbmsg(){ return new ::proto_ff::NotifyRoleFacadeCastRsp(); }
		static ::proto_ff::NotifyRoleFacadeCastRsp make_pbmsg(){ return ::proto_ff::NotifyRoleFacadeCastRsp(); }
	};
	typedef struct NotifyRoleFacadeCastRsp_s NotifyRoleFacadeCastRsp_t;

	struct FunctionUnlockInfoData_s : public NFDescStoreSeqOP {
		FunctionUnlockInfoData_s();
		virtual ~FunctionUnlockInfoData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t unlockId;//
		bool get_reward;//

		virtual void write_to_pbmsg(::proto_ff::FunctionUnlockInfoData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FunctionUnlockInfoData & msg);
		static ::proto_ff::FunctionUnlockInfoData* new_pbmsg(){ return new ::proto_ff::FunctionUnlockInfoData(); }
		static ::proto_ff::FunctionUnlockInfoData make_pbmsg(){ return ::proto_ff::FunctionUnlockInfoData(); }
	};
	typedef struct FunctionUnlockInfoData_s FunctionUnlockInfoData_t;

	struct FunctionUnlockInfo_s : public NFDescStoreSeqOP {
		FunctionUnlockInfo_s();
		virtual ~FunctionUnlockInfo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FunctionUnlockInfoData_s, DEFINE_FUNCTIONUNLOCKINFO_DATA_MAX_NUM> data;//

		virtual void write_to_pbmsg(::proto_ff::FunctionUnlockInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FunctionUnlockInfo & msg);
		static ::proto_ff::FunctionUnlockInfo* new_pbmsg(){ return new ::proto_ff::FunctionUnlockInfo(); }
		static ::proto_ff::FunctionUnlockInfo make_pbmsg(){ return ::proto_ff::FunctionUnlockInfo(); }
	};
	typedef struct FunctionUnlockInfo_s FunctionUnlockInfo_t;

	struct RolePlayerMiniInfo_s : public NFDescStoreSeqOP {
		RolePlayerMiniInfo_s();
		virtual ~RolePlayerMiniInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t playerId;//
		NFShmString<32> playerName;//
		uint32_t zid;//
		uint32_t level;//
		uint32_t closeness;//
		uint32_t recentType;//
		uint64_t recentTime;//
		uint32_t prof;//
		uint32_t teamId;//
		uint32_t unionId;//
		uint64_t fightPower;//
		uint32_t killMeTimes;//
		uint64_t offlineTime;//
		NFShmString<32> connect;//
		bool online;//
		uint32_t vipLevel;//
		struct RoleFacadeProto_s facade;//
		uint32_t marry;//

		virtual void write_to_pbmsg(::proto_ff::RolePlayerMiniInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RolePlayerMiniInfo & msg);
		static ::proto_ff::RolePlayerMiniInfo* new_pbmsg(){ return new ::proto_ff::RolePlayerMiniInfo(); }
		static ::proto_ff::RolePlayerMiniInfo make_pbmsg(){ return ::proto_ff::RolePlayerMiniInfo(); }
	};
	typedef struct RolePlayerMiniInfo_s RolePlayerMiniInfo_t;

	struct FriendInfo_s : public NFDescStoreSeqOP {
		FriendInfo_s();
		virtual ~FriendInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t closeness;//
		uint32_t todayCloseness;//
		uint64_t updateTime;//

		virtual void write_to_pbmsg(::proto_ff::FriendInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FriendInfo & msg);
		static ::proto_ff::FriendInfo* new_pbmsg(){ return new ::proto_ff::FriendInfo(); }
		static ::proto_ff::FriendInfo make_pbmsg(){ return ::proto_ff::FriendInfo(); }
	};
	typedef struct FriendInfo_s FriendInfo_t;

	struct FriendApplyInfo_s : public NFDescStoreSeqOP {
		FriendApplyInfo_s();
		virtual ~FriendApplyInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> connect;//

		virtual void write_to_pbmsg(::proto_ff::FriendApplyInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FriendApplyInfo & msg);
		static ::proto_ff::FriendApplyInfo* new_pbmsg(){ return new ::proto_ff::FriendApplyInfo(); }
		static ::proto_ff::FriendApplyInfo make_pbmsg(){ return ::proto_ff::FriendApplyInfo(); }
	};
	typedef struct FriendApplyInfo_s FriendApplyInfo_t;

	struct RelationHateInfo_s : public NFDescStoreSeqOP {
		RelationHateInfo_s();
		virtual ~RelationHateInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t killMeTimes;//

		virtual void write_to_pbmsg(::proto_ff::RelationHateInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RelationHateInfo & msg);
		static ::proto_ff::RelationHateInfo* new_pbmsg(){ return new ::proto_ff::RelationHateInfo(); }
		static ::proto_ff::RelationHateInfo make_pbmsg(){ return ::proto_ff::RelationHateInfo(); }
	};
	typedef struct RelationHateInfo_s RelationHateInfo_t;

	struct RelationGiftRecord_s : public NFDescStoreSeqOP {
		RelationGiftRecord_s();
		virtual ~RelationGiftRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t friendId;//
		uint64_t itemId;//
		uint32_t isThanks;//

		virtual void write_to_pbmsg(::proto_ff::RelationGiftRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RelationGiftRecord & msg);
		static ::proto_ff::RelationGiftRecord* new_pbmsg(){ return new ::proto_ff::RelationGiftRecord(); }
		static ::proto_ff::RelationGiftRecord make_pbmsg(){ return ::proto_ff::RelationGiftRecord(); }
	};
	typedef struct RelationGiftRecord_s RelationGiftRecord_t;

	struct RelationDBInfo_s : public NFDescStoreSeqOP {
		RelationDBInfo_s();
		virtual ~RelationDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FriendInfo_s, DEFINE_RELATIONDBINFO_FRIENDLIST_MAX_NUM> friendList;//
		NFShmVector<uint64_t, DEFINE_RELATIONDBINFO_BLACKLIST_MAX_NUM> blackList;//
		NFShmVector<struct RelationHateInfo_s, DEFINE_RELATIONDBINFO_HATELIST_MAX_NUM> hateList;//
		NFShmVector<struct FriendApplyInfo_s, DEFINE_RELATIONDBINFO_APPLYLIST_MAX_NUM> applyList;//
		uint32_t friends_add;//
		NFShmVector<struct RelationGiftRecord_s, DEFINE_RELATIONDBINFO_GIFTRECORDS_MAX_NUM> giftRecords;//

		virtual void write_to_pbmsg(::proto_ff::RelationDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RelationDBInfo & msg);
		static ::proto_ff::RelationDBInfo* new_pbmsg(){ return new ::proto_ff::RelationDBInfo(); }
		static ::proto_ff::RelationDBInfo make_pbmsg(){ return ::proto_ff::RelationDBInfo(); }
	};
	typedef struct RelationDBInfo_s RelationDBInfo_t;

	struct DigPerfor_s : public NFDescStoreSeqOP {
		DigPerfor_s();
		virtual ~DigPerfor_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t type;//
		int64_t value;//

		virtual void write_to_pbmsg(::proto_ff::DigPerfor & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DigPerfor & msg);
		static ::proto_ff::DigPerfor* new_pbmsg(){ return new ::proto_ff::DigPerfor(); }
		static ::proto_ff::DigPerfor make_pbmsg(){ return ::proto_ff::DigPerfor(); }
	};
	typedef struct DigPerfor_s DigPerfor_t;

	struct BuffProto_s : public NFDescStoreSeqOP {
		BuffProto_s();
		virtual ~BuffProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t buff_index;//
		uint64_t buff_id;//
		uint64_t recver_cid;//
		int64_t left_msec;//
		uint64_t skill_id;//
		int32_t skill_lev;//
		int32_t is_effect;//

		virtual void write_to_pbmsg(::proto_ff::BuffProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffProto & msg);
		static ::proto_ff::BuffProto* new_pbmsg(){ return new ::proto_ff::BuffProto(); }
		static ::proto_ff::BuffProto make_pbmsg(){ return ::proto_ff::BuffProto(); }
	};
	typedef struct BuffProto_s BuffProto_t;

	struct BuffListProto_s : public NFDescStoreSeqOP {
		BuffListProto_s();
		virtual ~BuffListProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmVector<struct BuffProto_s, DEFINE_BUFFLISTPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::BuffListProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffListProto & msg);
		static ::proto_ff::BuffListProto* new_pbmsg(){ return new ::proto_ff::BuffListProto(); }
		static ::proto_ff::BuffListProto make_pbmsg(){ return ::proto_ff::BuffListProto(); }
	};
	typedef struct BuffListProto_s BuffListProto_t;

	struct SkillPosProto_s : public NFDescStoreSeqOP {
		SkillPosProto_s();
		virtual ~SkillPosProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;//
		uint32_t pos;//
		int32_t cd;//
		int32_t use;//

		virtual void write_to_pbmsg(::proto_ff::SkillPosProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillPosProto & msg);
		static ::proto_ff::SkillPosProto* new_pbmsg(){ return new ::proto_ff::SkillPosProto(); }
		static ::proto_ff::SkillPosProto make_pbmsg(){ return ::proto_ff::SkillPosProto(); }
	};
	typedef struct SkillPosProto_s SkillPosProto_t;

	struct SkillGroupProto_s : public NFDescStoreSeqOP {
		SkillGroupProto_s();
		virtual ~SkillGroupProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t group;//
		NFShmVector<struct SkillPosProto_s, DEFINE_SKILLGROUPPROTO_LST_MAX_NUM> lst;//

		virtual void write_to_pbmsg(::proto_ff::SkillGroupProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillGroupProto & msg);
		static ::proto_ff::SkillGroupProto* new_pbmsg(){ return new ::proto_ff::SkillGroupProto(); }
		static ::proto_ff::SkillGroupProto make_pbmsg(){ return ::proto_ff::SkillGroupProto(); }
	};
	typedef struct SkillGroupProto_s SkillGroupProto_t;

	struct SkillGroupListProto_s : public NFDescStoreSeqOP {
		SkillGroupListProto_s();
		virtual ~SkillGroupListProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct SkillGroupProto_s, DEFINE_SKILLGROUPLISTPROTO_INFO_MAX_NUM> info;//
		uint32_t cur_skill_group;//

		virtual void write_to_pbmsg(::proto_ff::SkillGroupListProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillGroupListProto & msg);
		static ::proto_ff::SkillGroupListProto* new_pbmsg(){ return new ::proto_ff::SkillGroupListProto(); }
		static ::proto_ff::SkillGroupListProto make_pbmsg(){ return ::proto_ff::SkillGroupListProto(); }
	};
	typedef struct SkillGroupListProto_s SkillGroupListProto_t;

	struct GodEvilTaskProto_s : public NFDescStoreSeqOP {
		GodEvilTaskProto_s();
		virtual ~GodEvilTaskProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::GodEvilTaskProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilTaskProto & msg);
		static ::proto_ff::GodEvilTaskProto* new_pbmsg(){ return new ::proto_ff::GodEvilTaskProto(); }
		static ::proto_ff::GodEvilTaskProto make_pbmsg(){ return ::proto_ff::GodEvilTaskProto(); }
	};
	typedef struct GodEvilTaskProto_s GodEvilTaskProto_t;

	struct GodEvilTaskListProto_s : public NFDescStoreSeqOP {
		GodEvilTaskListProto_s();
		virtual ~GodEvilTaskListProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GodEvilTaskProto_s, DEFINE_GODEVILTASKLISTPROTO_LST_MAX_NUM> lst;//

		virtual void write_to_pbmsg(::proto_ff::GodEvilTaskListProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilTaskListProto & msg);
		static ::proto_ff::GodEvilTaskListProto* new_pbmsg(){ return new ::proto_ff::GodEvilTaskListProto(); }
		static ::proto_ff::GodEvilTaskListProto make_pbmsg(){ return ::proto_ff::GodEvilTaskListProto(); }
	};
	typedef struct GodEvilTaskListProto_s GodEvilTaskListProto_t;

	struct GodEvilStageProto_s : public NFDescStoreSeqOP {
		GodEvilStageProto_s();
		virtual ~GodEvilStageProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t stage;//
		struct GodEvilTaskListProto_s task;//
		int32_t finish;//

		virtual void write_to_pbmsg(::proto_ff::GodEvilStageProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilStageProto & msg);
		static ::proto_ff::GodEvilStageProto* new_pbmsg(){ return new ::proto_ff::GodEvilStageProto(); }
		static ::proto_ff::GodEvilStageProto make_pbmsg(){ return ::proto_ff::GodEvilStageProto(); }
	};
	typedef struct GodEvilStageProto_s GodEvilStageProto_t;

	struct GodEvilProto_s : public NFDescStoreSeqOP {
		GodEvilProto_s();
		virtual ~GodEvilProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t fetch;//
		struct GodEvilStageProto_s stage;//
		int32_t type;//
		int32_t cd;//
		int32_t vessel_lev;//
		int32_t mirror_lev;//
		int64_t extra_exp;//

		virtual void write_to_pbmsg(::proto_ff::GodEvilProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilProto & msg);
		static ::proto_ff::GodEvilProto* new_pbmsg(){ return new ::proto_ff::GodEvilProto(); }
		static ::proto_ff::GodEvilProto make_pbmsg(){ return ::proto_ff::GodEvilProto(); }
	};
	typedef struct GodEvilProto_s GodEvilProto_t;

	struct FacadeFantasyData_s : public NFDescStoreSeqOP {
		FacadeFantasyData_s();
		virtual ~FacadeFantasyData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fantasy_id;//
		uint32_t fantasy_lev;//

		virtual void write_to_pbmsg(::proto_ff::FacadeFantasyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeFantasyData & msg);
		static ::proto_ff::FacadeFantasyData* new_pbmsg(){ return new ::proto_ff::FacadeFantasyData(); }
		static ::proto_ff::FacadeFantasyData make_pbmsg(){ return ::proto_ff::FacadeFantasyData(); }
	};
	typedef struct FacadeFantasyData_s FacadeFantasyData_t;

	struct FacadeFragmentData_s : public NFDescStoreSeqOP {
		FacadeFragmentData_s();
		virtual ~FacadeFragmentData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fragment_id;//
		uint32_t use_times;//

		virtual void write_to_pbmsg(::proto_ff::FacadeFragmentData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeFragmentData & msg);
		static ::proto_ff::FacadeFragmentData* new_pbmsg(){ return new ::proto_ff::FacadeFragmentData(); }
		static ::proto_ff::FacadeFragmentData make_pbmsg(){ return ::proto_ff::FacadeFragmentData(); }
	};
	typedef struct FacadeFragmentData_s FacadeFragmentData_t;

	struct FacadeSkillData_s : public NFDescStoreSeqOP {
		FacadeSkillData_s();
		virtual ~FacadeSkillData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;//
		uint32_t skill_lev;//

		virtual void write_to_pbmsg(::proto_ff::FacadeSkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeSkillData & msg);
		static ::proto_ff::FacadeSkillData* new_pbmsg(){ return new ::proto_ff::FacadeSkillData(); }
		static ::proto_ff::FacadeSkillData make_pbmsg(){ return ::proto_ff::FacadeSkillData(); }
	};
	typedef struct FacadeSkillData_s FacadeSkillData_t;

	struct MountFantasyData_s : public NFDescStoreSeqOP {
		MountFantasyData_s();
		virtual ~MountFantasyData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fantasy_id;//
		uint32_t fantasy_lev;//
		uint64_t fantasy_lev_exp;//
		uint32_t fantasy_star;//

		virtual void write_to_pbmsg(::proto_ff::MountFantasyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFantasyData & msg);
		static ::proto_ff::MountFantasyData* new_pbmsg(){ return new ::proto_ff::MountFantasyData(); }
		static ::proto_ff::MountFantasyData make_pbmsg(){ return ::proto_ff::MountFantasyData(); }
	};
	typedef struct MountFantasyData_s MountFantasyData_t;

	struct MountFragmentData_s : public NFDescStoreSeqOP {
		MountFragmentData_s();
		virtual ~MountFragmentData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fragment_id;//
		uint32_t use_times;//

		virtual void write_to_pbmsg(::proto_ff::MountFragmentData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFragmentData & msg);
		static ::proto_ff::MountFragmentData* new_pbmsg(){ return new ::proto_ff::MountFragmentData(); }
		static ::proto_ff::MountFragmentData make_pbmsg(){ return ::proto_ff::MountFragmentData(); }
	};
	typedef struct MountFragmentData_s MountFragmentData_t;

	struct MountSkillData_s : public NFDescStoreSeqOP {
		MountSkillData_s();
		virtual ~MountSkillData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;//
		uint32_t skill_lev;//

		virtual void write_to_pbmsg(::proto_ff::MountSkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountSkillData & msg);
		static ::proto_ff::MountSkillData* new_pbmsg(){ return new ::proto_ff::MountSkillData(); }
		static ::proto_ff::MountSkillData make_pbmsg(){ return ::proto_ff::MountSkillData(); }
	};
	typedef struct MountSkillData_s MountSkillData_t;

	struct MountKunData_s : public NFDescStoreSeqOP {
		MountKunData_s();
		virtual ~MountKunData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t kun_id;//
		uint32_t kun_lev;//
		uint64_t kun_lev_exp;//
		uint32_t kun_star;//

		virtual void write_to_pbmsg(::proto_ff::MountKunData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountKunData & msg);
		static ::proto_ff::MountKunData* new_pbmsg(){ return new ::proto_ff::MountKunData(); }
		static ::proto_ff::MountKunData make_pbmsg(){ return ::proto_ff::MountKunData(); }
	};
	typedef struct MountKunData_s MountKunData_t;

	struct MountBloodData_s : public NFDescStoreSeqOP {
		MountBloodData_s();
		virtual ~MountBloodData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t blood_id;//
		uint32_t blood_state;//

		virtual void write_to_pbmsg(::proto_ff::MountBloodData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountBloodData & msg);
		static ::proto_ff::MountBloodData* new_pbmsg(){ return new ::proto_ff::MountBloodData(); }
		static ::proto_ff::MountBloodData make_pbmsg(){ return ::proto_ff::MountBloodData(); }
	};
	typedef struct MountBloodData_s MountBloodData_t;

	struct MountBabySlotData_s : public NFDescStoreSeqOP {
		MountBabySlotData_s();
		virtual ~MountBabySlotData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t slot;//
		uint32_t cur_state;//
		int64_t cur_baby_eggid;//
		int64_t cur_baby_create_time;//

		virtual void write_to_pbmsg(::proto_ff::MountBabySlotData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountBabySlotData & msg);
		static ::proto_ff::MountBabySlotData* new_pbmsg(){ return new ::proto_ff::MountBabySlotData(); }
		static ::proto_ff::MountBabySlotData make_pbmsg(){ return ::proto_ff::MountBabySlotData(); }
	};
	typedef struct MountBabySlotData_s MountBabySlotData_t;

	struct StatisticDataProto_s : public NFDescStoreSeqOP {
		StatisticDataProto_s();
		virtual ~StatisticDataProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t level;//
		uint32_t total_login_day;//
		uint32_t total_rmb;//
		uint32_t today_rmb;//
		uint32_t total_activityCount;//

		virtual void write_to_pbmsg(::proto_ff::StatisticDataProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StatisticDataProto & msg);
		static ::proto_ff::StatisticDataProto* new_pbmsg(){ return new ::proto_ff::StatisticDataProto(); }
		static ::proto_ff::StatisticDataProto make_pbmsg(){ return ::proto_ff::StatisticDataProto(); }
	};
	typedef struct StatisticDataProto_s StatisticDataProto_t;

	struct GodRelicsTaskEntry_s : public NFDescStoreSeqOP {
		GodRelicsTaskEntry_s();
		virtual ~GodRelicsTaskEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;//
		int32_t cur_num;//
		int32_t task_state;//

		virtual void write_to_pbmsg(::proto_ff::GodRelicsTaskEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodRelicsTaskEntry & msg);
		static ::proto_ff::GodRelicsTaskEntry* new_pbmsg(){ return new ::proto_ff::GodRelicsTaskEntry(); }
		static ::proto_ff::GodRelicsTaskEntry make_pbmsg(){ return ::proto_ff::GodRelicsTaskEntry(); }
	};
	typedef struct GodRelicsTaskEntry_s GodRelicsTaskEntry_t;

	struct GodRelicsTaskGroupEntry_s : public NFDescStoreSeqOP {
		GodRelicsTaskGroupEntry_s();
		virtual ~GodRelicsTaskGroupEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t group_cfg_id;//
		NFShmVector<struct GodRelicsTaskEntry_s, DEFINE_GODRELICSTASKGROUPENTRY_ENTRYS_MAX_NUM> entrys;//
		int32_t normal_reward_state;//
		uint64_t create_time;//

		virtual void write_to_pbmsg(::proto_ff::GodRelicsTaskGroupEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodRelicsTaskGroupEntry & msg);
		static ::proto_ff::GodRelicsTaskGroupEntry* new_pbmsg(){ return new ::proto_ff::GodRelicsTaskGroupEntry(); }
		static ::proto_ff::GodRelicsTaskGroupEntry make_pbmsg(){ return ::proto_ff::GodRelicsTaskGroupEntry(); }
	};
	typedef struct GodRelicsTaskGroupEntry_s GodRelicsTaskGroupEntry_t;

	struct DailyTaskEntry_s : public NFDescStoreSeqOP {
		DailyTaskEntry_s();
		virtual ~DailyTaskEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;//
		int32_t cur_num;//
		int32_t task_state;//
		uint64_t last_time;//
		int32_t buy_num;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskEntry & msg);
		static ::proto_ff::DailyTaskEntry* new_pbmsg(){ return new ::proto_ff::DailyTaskEntry(); }
		static ::proto_ff::DailyTaskEntry make_pbmsg(){ return ::proto_ff::DailyTaskEntry(); }
	};
	typedef struct DailyTaskEntry_s DailyTaskEntry_t;

	struct DailyTaskLimitEntry_s : public NFDescStoreSeqOP {
		DailyTaskLimitEntry_s();
		virtual ~DailyTaskLimitEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;//
		int32_t cur_num;//
		int32_t task_state;//
		uint64_t last_time;//
		int32_t buy_num;//
		bool ready_add;//
		bool is_open;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskLimitEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskLimitEntry & msg);
		static ::proto_ff::DailyTaskLimitEntry* new_pbmsg(){ return new ::proto_ff::DailyTaskLimitEntry(); }
		static ::proto_ff::DailyTaskLimitEntry make_pbmsg(){ return ::proto_ff::DailyTaskLimitEntry(); }
	};
	typedef struct DailyTaskLimitEntry_s DailyTaskLimitEntry_t;

	struct DailyTaskBackDayEntry_s : public NFDescStoreSeqOP {
		DailyTaskBackDayEntry_s();
		virtual ~DailyTaskBackDayEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t left_num;//
		int32_t external_left_num;//
		int64_t last_time;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskBackDayEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskBackDayEntry & msg);
		static ::proto_ff::DailyTaskBackDayEntry* new_pbmsg(){ return new ::proto_ff::DailyTaskBackDayEntry(); }
		static ::proto_ff::DailyTaskBackDayEntry make_pbmsg(){ return ::proto_ff::DailyTaskBackDayEntry(); }
	};
	typedef struct DailyTaskBackDayEntry_s DailyTaskBackDayEntry_t;

	struct DailyTaskBackEntry_s : public NFDescStoreSeqOP {
		DailyTaskBackEntry_s();
		virtual ~DailyTaskBackEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t task_cfg_id;//
		int32_t task_state;//
		NFShmVector<struct DailyTaskBackDayEntry_s, DEFINE_DAILYTASKBACKENTRY_DAY_DATA_MAX_NUM> day_data;//
		int32_t left_num;//
		int32_t external_left_num;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskBackEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskBackEntry & msg);
		static ::proto_ff::DailyTaskBackEntry* new_pbmsg(){ return new ::proto_ff::DailyTaskBackEntry(); }
		static ::proto_ff::DailyTaskBackEntry make_pbmsg(){ return ::proto_ff::DailyTaskBackEntry(); }
	};
	typedef struct DailyTaskBackEntry_s DailyTaskBackEntry_t;

	struct DailyTaskRewardEntry_s : public NFDescStoreSeqOP {
		DailyTaskRewardEntry_s();
		virtual ~DailyTaskRewardEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t reward_id;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskRewardEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskRewardEntry & msg);
		static ::proto_ff::DailyTaskRewardEntry* new_pbmsg(){ return new ::proto_ff::DailyTaskRewardEntry(); }
		static ::proto_ff::DailyTaskRewardEntry make_pbmsg(){ return ::proto_ff::DailyTaskRewardEntry(); }
	};
	typedef struct DailyTaskRewardEntry_s DailyTaskRewardEntry_t;

	struct DailyTaskAllData_s : public NFDescStoreSeqOP {
		DailyTaskAllData_s();
		virtual ~DailyTaskAllData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DailyTaskEntry_s, DEFINE_DAILYTASKALLDATA_TASK_DATA_MAX_NUM> task_data;//
		NFShmVector<struct DailyTaskLimitEntry_s, DEFINE_DAILYTASKALLDATA_TASK_LIMIT_DATA_MAX_NUM> task_limit_data;//
		NFShmVector<struct DailyTaskBackEntry_s, DEFINE_DAILYTASKALLDATA_BACK_DATA_MAX_NUM> back_data;//
		NFShmVector<struct DailyTaskRewardEntry_s, DEFINE_DAILYTASKALLDATA_REWARD_DATA_MAX_NUM> reward_data;//
		uint32_t daily_score;//
		uint32_t daily_level;//
		uint64_t create_time;//
		uint64_t daily_exp;//

		virtual void write_to_pbmsg(::proto_ff::DailyTaskAllData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyTaskAllData & msg);
		static ::proto_ff::DailyTaskAllData* new_pbmsg(){ return new ::proto_ff::DailyTaskAllData(); }
		static ::proto_ff::DailyTaskAllData make_pbmsg(){ return ::proto_ff::DailyTaskAllData(); }
	};
	typedef struct DailyTaskAllData_s DailyTaskAllData_t;

	struct CharacterDBRecentSubmitMission_s : public NFDescStoreSeqOP {
		CharacterDBRecentSubmitMission_s();
		virtual ~CharacterDBRecentSubmitMission_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t mission_type;//
		uint64_t mission_id;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBRecentSubmitMission & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBRecentSubmitMission & msg);
		static ::proto_ff::CharacterDBRecentSubmitMission* new_pbmsg(){ return new ::proto_ff::CharacterDBRecentSubmitMission(); }
		static ::proto_ff::CharacterDBRecentSubmitMission make_pbmsg(){ return ::proto_ff::CharacterDBRecentSubmitMission(); }
	};
	typedef struct CharacterDBRecentSubmitMission_s CharacterDBRecentSubmitMission_t;

	struct CharacterDBMissionItemInfo_s : public NFDescStoreSeqOP {
		CharacterDBMissionItemInfo_s();
		virtual ~CharacterDBMissionItemInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t type;//
		uint64_t id;//
		uint32_t currentValue;//
		uint32_t finalValue;//
		bool completedFlag;//
		uint64_t parma1;//
		uint64_t parma2;//
		uint64_t parma3;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMissionItemInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMissionItemInfo & msg);
		static ::proto_ff::CharacterDBMissionItemInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBMissionItemInfo(); }
		static ::proto_ff::CharacterDBMissionItemInfo make_pbmsg(){ return ::proto_ff::CharacterDBMissionItemInfo(); }
	};
	typedef struct CharacterDBMissionItemInfo_s CharacterDBMissionItemInfo_t;

	struct CharacterDBMissionTrack_s : public NFDescStoreSeqOP {
		CharacterDBMissionTrack_s();
		virtual ~CharacterDBMissionTrack_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t missionId;//
		uint64_t dynamicid;//
		uint32_t status;//
		uint64_t acceptMissionTime;//
		NFShmVector<struct CharacterDBMissionItemInfo_s, DEFINE_CHARACTERDBMISSIONTRACK_ITEMINFO_MAX_NUM> itemInfo;//
		uint64_t textid;//
		uint32_t missionType;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBMissionTrack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBMissionTrack & msg);
		static ::proto_ff::CharacterDBMissionTrack* new_pbmsg(){ return new ::proto_ff::CharacterDBMissionTrack(); }
		static ::proto_ff::CharacterDBMissionTrack make_pbmsg(){ return ::proto_ff::CharacterDBMissionTrack(); }
	};
	typedef struct CharacterDBMissionTrack_s CharacterDBMissionTrack_t;

	struct CharacterDBDyMissionBountyParam_s : public NFDescStoreSeqOP {
		CharacterDBDyMissionBountyParam_s();
		virtual ~CharacterDBDyMissionBountyParam_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t ten_state;//
		uint32_t twenty_state;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDyMissionBountyParam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionBountyParam & msg);
		static ::proto_ff::CharacterDBDyMissionBountyParam* new_pbmsg(){ return new ::proto_ff::CharacterDBDyMissionBountyParam(); }
		static ::proto_ff::CharacterDBDyMissionBountyParam make_pbmsg(){ return ::proto_ff::CharacterDBDyMissionBountyParam(); }
	};
	typedef struct CharacterDBDyMissionBountyParam_s CharacterDBDyMissionBountyParam_t;

	struct CharacterDBDyMissionInfo_s : public NFDescStoreSeqOP {
		CharacterDBDyMissionInfo_s();
		virtual ~CharacterDBDyMissionInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t mission_type;//
		uint64_t lastfresh;//
		int32_t accept_num;//
		struct CharacterDBDyMissionBountyParam_s bounty_param;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBDyMissionInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionInfo & msg);
		static ::proto_ff::CharacterDBDyMissionInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBDyMissionInfo(); }
		static ::proto_ff::CharacterDBDyMissionInfo make_pbmsg(){ return ::proto_ff::CharacterDBDyMissionInfo(); }
	};
	typedef struct CharacterDBDyMissionInfo_s CharacterDBDyMissionInfo_t;

	struct GuildPrestigeMissionDBData_s : public NFDescStoreSeqOP {
		GuildPrestigeMissionDBData_s();
		virtual ~GuildPrestigeMissionDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t prestige_id;//
		int64_t task_id;//
		int32_t task_state;//
		int32_t index;//
		struct CharacterDBMissionTrack_s track;//

		virtual void write_to_pbmsg(::proto_ff::GuildPrestigeMissionDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GuildPrestigeMissionDBData & msg);
		static ::proto_ff::GuildPrestigeMissionDBData* new_pbmsg(){ return new ::proto_ff::GuildPrestigeMissionDBData(); }
		static ::proto_ff::GuildPrestigeMissionDBData make_pbmsg(){ return ::proto_ff::GuildPrestigeMissionDBData(); }
	};
	typedef struct GuildPrestigeMissionDBData_s GuildPrestigeMissionDBData_t;

	struct GuildPrestigeMissionDB_s : public NFDescStoreSeqOP {
		GuildPrestigeMissionDB_s();
		virtual ~GuildPrestigeMissionDB_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t refresh_num;//
		int32_t all_refresh_num;//
		int32_t accept_num;//
		int32_t all_accept_num;//
		NFShmVector<struct GuildPrestigeMissionDBData_s, DEFINE_GUILDPRESTIGEMISSIONDB_TASK_POOL_MAX_NUM> task_pool;//
		int64_t last_refresh_time;//

		virtual void write_to_pbmsg(::proto_ff::GuildPrestigeMissionDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GuildPrestigeMissionDB & msg);
		static ::proto_ff::GuildPrestigeMissionDB* new_pbmsg(){ return new ::proto_ff::GuildPrestigeMissionDB(); }
		static ::proto_ff::GuildPrestigeMissionDB make_pbmsg(){ return ::proto_ff::GuildPrestigeMissionDB(); }
	};
	typedef struct GuildPrestigeMissionDB_s GuildPrestigeMissionDB_t;

	struct CharacterDBTaskData_s : public NFDescStoreSeqOP {
		CharacterDBTaskData_s();
		virtual ~CharacterDBTaskData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct CharacterDBMissionTrack_s, DEFINE_CHARACTERDBTASKDATA_MISSIONTRACK_MAX_NUM> missionTrack;//
		NFShmVector<struct CharacterDBDyMissionInfo_s, DEFINE_CHARACTERDBTASKDATA_DYINFO_MAX_NUM> dyinfo;//
		NFShmVector<uint64_t, DEFINE_CHARACTERDBTASKDATA_ALREADY_SUBMIT_MAX_NUM> already_submit;//
		NFShmVector<struct CharacterDBRecentSubmitMission_s, DEFINE_CHARACTERDBTASKDATA_RECENT_SUBMIT_MAX_NUM> recent_submit;//
		struct GuildPrestigeMissionDB_s prestige_mission;//

		virtual void write_to_pbmsg(::proto_ff::CharacterDBTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBTaskData & msg);
		static ::proto_ff::CharacterDBTaskData* new_pbmsg(){ return new ::proto_ff::CharacterDBTaskData(); }
		static ::proto_ff::CharacterDBTaskData make_pbmsg(){ return ::proto_ff::CharacterDBTaskData(); }
	};
	typedef struct CharacterDBTaskData_s CharacterDBTaskData_t;

	struct NotifyVipDataRsp_s : public NFDescStoreSeqOP {
		NotifyVipDataRsp_s();
		virtual ~NotifyVipDataRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t exp;//
		NFShmVector<int32_t, DEFINE_NOTIFYVIPDATARSP_IDS_MAX_NUM> ids;//

		virtual void write_to_pbmsg(::proto_ff::NotifyVipDataRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyVipDataRsp & msg);
		static ::proto_ff::NotifyVipDataRsp* new_pbmsg(){ return new ::proto_ff::NotifyVipDataRsp(); }
		static ::proto_ff::NotifyVipDataRsp make_pbmsg(){ return ::proto_ff::NotifyVipDataRsp(); }
	};
	typedef struct NotifyVipDataRsp_s NotifyVipDataRsp_t;

	struct ArenaChallResult_s : public NFDescStoreSeqOP {
		ArenaChallResult_s();
		virtual ~ArenaChallResult_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t result;//
		bool chall;//
		int64_t time;//
		NFShmString<32> dst_name;//
		int32_t src_rank_id;//
		int32_t dst_rank_id;//
		NFShmVector<struct ComItem_s, DEFINE_ARENACHALLRESULT_ITEMS_MAX_NUM> items;//
		int64_t dup_id;//

		virtual void write_to_pbmsg(::proto_ff::ArenaChallResult & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArenaChallResult & msg);
		static ::proto_ff::ArenaChallResult* new_pbmsg(){ return new ::proto_ff::ArenaChallResult(); }
		static ::proto_ff::ArenaChallResult make_pbmsg(){ return ::proto_ff::ArenaChallResult(); }
	};
	typedef struct ArenaChallResult_s ArenaChallResult_t;

	struct DailyArenaReward_s : public NFDescStoreSeqOP {
		DailyArenaReward_s();
		virtual ~DailyArenaReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t cfg_id;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::DailyArenaReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyArenaReward & msg);
		static ::proto_ff::DailyArenaReward* new_pbmsg(){ return new ::proto_ff::DailyArenaReward(); }
		static ::proto_ff::DailyArenaReward make_pbmsg(){ return ::proto_ff::DailyArenaReward(); }
	};
	typedef struct DailyArenaReward_s DailyArenaReward_t;

	struct ChallArenaReward_s : public NFDescStoreSeqOP {
		ChallArenaReward_s();
		virtual ~ChallArenaReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t cfg_id;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::ChallArenaReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ChallArenaReward & msg);
		static ::proto_ff::ChallArenaReward* new_pbmsg(){ return new ::proto_ff::ChallArenaReward(); }
		static ::proto_ff::ChallArenaReward make_pbmsg(){ return ::proto_ff::ChallArenaReward(); }
	};
	typedef struct ChallArenaReward_s ChallArenaReward_t;

	struct NotifyServerFlag_s : public NFDescStoreSeqOP {
		NotifyServerFlag_s();
		virtual ~NotifyServerFlag_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t bt_dup;//

		virtual void write_to_pbmsg(::proto_ff::NotifyServerFlag & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyServerFlag & msg);
		static ::proto_ff::NotifyServerFlag* new_pbmsg(){ return new ::proto_ff::NotifyServerFlag(); }
		static ::proto_ff::NotifyServerFlag make_pbmsg(){ return ::proto_ff::NotifyServerFlag(); }
	};
	typedef struct NotifyServerFlag_s NotifyServerFlag_t;

	struct FacadeSoulSkillData_s : public NFDescStoreSeqOP {
		FacadeSoulSkillData_s();
		virtual ~FacadeSoulSkillData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t skill_id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FacadeSoulSkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeSoulSkillData & msg);
		static ::proto_ff::FacadeSoulSkillData* new_pbmsg(){ return new ::proto_ff::FacadeSoulSkillData(); }
		static ::proto_ff::FacadeSoulSkillData make_pbmsg(){ return ::proto_ff::FacadeSoulSkillData(); }
	};
	typedef struct FacadeSoulSkillData_s FacadeSoulSkillData_t;

	struct FacadeSoulActivityData_s : public NFDescStoreSeqOP {
		FacadeSoulActivityData_s();
		virtual ~FacadeSoulActivityData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t activity_id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FacadeSoulActivityData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeSoulActivityData & msg);
		static ::proto_ff::FacadeSoulActivityData* new_pbmsg(){ return new ::proto_ff::FacadeSoulActivityData(); }
		static ::proto_ff::FacadeSoulActivityData make_pbmsg(){ return ::proto_ff::FacadeSoulActivityData(); }
	};
	typedef struct FacadeSoulActivityData_s FacadeSoulActivityData_t;

	struct FacadeSoulData_s : public NFDescStoreSeqOP {
		FacadeSoulData_s();
		virtual ~FacadeSoulData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t soul_id;//
		bool soul_active;//
		uint32_t soul_level;//
		NFShmVector<struct FacadeSoulSkillData_s, DEFINE_FACADESOULDATA_SKILL_DATA_MAX_NUM> skill_data;//
		NFShmVector<struct FacadeSoulActivityData_s, DEFINE_FACADESOULDATA_ACVIITY_DATA_MAX_NUM> acviity_data;//

		virtual void write_to_pbmsg(::proto_ff::FacadeSoulData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeSoulData & msg);
		static ::proto_ff::FacadeSoulData* new_pbmsg(){ return new ::proto_ff::FacadeSoulData(); }
		static ::proto_ff::FacadeSoulData make_pbmsg(){ return ::proto_ff::FacadeSoulData(); }
	};
	typedef struct FacadeSoulData_s FacadeSoulData_t;

	struct ItemSellProto_s : public NFDescStoreSeqOP {
		ItemSellProto_s();
		virtual ~ItemSellProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t index;//
		int32_t num;//

		virtual void write_to_pbmsg(::proto_ff::ItemSellProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemSellProto & msg);
		static ::proto_ff::ItemSellProto* new_pbmsg(){ return new ::proto_ff::ItemSellProto(); }
		static ::proto_ff::ItemSellProto make_pbmsg(){ return ::proto_ff::ItemSellProto(); }
	};
	typedef struct ItemSellProto_s ItemSellProto_t;

	struct DeityFantasySkillData_s : public NFDescStoreSeqOP {
		DeityFantasySkillData_s();
		virtual ~DeityFantasySkillData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;//
		uint32_t skill_state;//

		virtual void write_to_pbmsg(::proto_ff::DeityFantasySkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityFantasySkillData & msg);
		static ::proto_ff::DeityFantasySkillData* new_pbmsg(){ return new ::proto_ff::DeityFantasySkillData(); }
		static ::proto_ff::DeityFantasySkillData make_pbmsg(){ return ::proto_ff::DeityFantasySkillData(); }
	};
	typedef struct DeityFantasySkillData_s DeityFantasySkillData_t;

	struct DeityEquipData_s : public NFDescStoreSeqOP {
		DeityEquipData_s();
		virtual ~DeityEquipData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct EquipInfo_s, DEFINE_DEITYEQUIPDATA_INFOS_MAX_NUM> infos;//
		NFShmVector<struct EquipLvAttrInfo_s, DEFINE_DEITYEQUIPDATA_LV_ATTR_MAX_NUM> lv_attr;//

		virtual void write_to_pbmsg(::proto_ff::DeityEquipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityEquipData & msg);
		static ::proto_ff::DeityEquipData* new_pbmsg(){ return new ::proto_ff::DeityEquipData(); }
		static ::proto_ff::DeityEquipData make_pbmsg(){ return ::proto_ff::DeityEquipData(); }
	};
	typedef struct DeityEquipData_s DeityEquipData_t;

	struct DeityEquipSuitData_s : public NFDescStoreSeqOP {
		DeityEquipSuitData_s();
		virtual ~DeityEquipSuitData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		uint32_t state;//

		virtual void write_to_pbmsg(::proto_ff::DeityEquipSuitData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityEquipSuitData & msg);
		static ::proto_ff::DeityEquipSuitData* new_pbmsg(){ return new ::proto_ff::DeityEquipSuitData(); }
		static ::proto_ff::DeityEquipSuitData make_pbmsg(){ return ::proto_ff::DeityEquipSuitData(); }
	};
	typedef struct DeityEquipSuitData_s DeityEquipSuitData_t;

	struct DeityFantasyData_s : public NFDescStoreSeqOP {
		DeityFantasyData_s();
		virtual ~DeityFantasyData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fantasy_id;//
		uint32_t fantasy_lev;//
		uint64_t fantasy_lev_exp;//
		uint32_t fantasy_star;//
		NFShmVector<struct DeityFantasySkillData_s, DEFINE_DEITYFANTASYDATA_SKILL_DATA_MAX_NUM> skill_data;//
		uint64_t fantasy_fight;//
		struct DeityEquipData_s equip_data;//
		NFShmVector<struct DeityEquipSuitData_s, DEFINE_DEITYFANTASYDATA_EQUIP_SUIT_DATA_MAX_NUM> equip_suit_data;//

		virtual void write_to_pbmsg(::proto_ff::DeityFantasyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityFantasyData & msg);
		static ::proto_ff::DeityFantasyData* new_pbmsg(){ return new ::proto_ff::DeityFantasyData(); }
		static ::proto_ff::DeityFantasyData make_pbmsg(){ return ::proto_ff::DeityFantasyData(); }
	};
	typedef struct DeityFantasyData_s DeityFantasyData_t;

	struct DeityFragmentData_s : public NFDescStoreSeqOP {
		DeityFragmentData_s();
		virtual ~DeityFragmentData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t fragment_id;//
		uint32_t use_times;//

		virtual void write_to_pbmsg(::proto_ff::DeityFragmentData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityFragmentData & msg);
		static ::proto_ff::DeityFragmentData* new_pbmsg(){ return new ::proto_ff::DeityFragmentData(); }
		static ::proto_ff::DeityFragmentData make_pbmsg(){ return ::proto_ff::DeityFragmentData(); }
	};
	typedef struct DeityFragmentData_s DeityFragmentData_t;

	struct DeitySkillData_s : public NFDescStoreSeqOP {
		DeitySkillData_s();
		virtual ~DeitySkillData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;//
		uint32_t skill_lev;//

		virtual void write_to_pbmsg(::proto_ff::DeitySkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeitySkillData & msg);
		static ::proto_ff::DeitySkillData* new_pbmsg(){ return new ::proto_ff::DeitySkillData(); }
		static ::proto_ff::DeitySkillData make_pbmsg(){ return ::proto_ff::DeitySkillData(); }
	};
	typedef struct DeitySkillData_s DeitySkillData_t;

	struct DeityBattleSlotData_s : public NFDescStoreSeqOP {
		DeityBattleSlotData_s();
		virtual ~DeityBattleSlotData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t cur_state;//
		int64_t deity_id;//
		int64_t enter_war_time;//

		virtual void write_to_pbmsg(::proto_ff::DeityBattleSlotData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityBattleSlotData & msg);
		static ::proto_ff::DeityBattleSlotData* new_pbmsg(){ return new ::proto_ff::DeityBattleSlotData(); }
		static ::proto_ff::DeityBattleSlotData make_pbmsg(){ return ::proto_ff::DeityBattleSlotData(); }
	};
	typedef struct DeityBattleSlotData_s DeityBattleSlotData_t;

	struct ArmorSuitState_s : public NFDescStoreSeqOP {
		ArmorSuitState_s();
		virtual ~ArmorSuitState_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t index;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::ArmorSuitState & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArmorSuitState & msg);
		static ::proto_ff::ArmorSuitState* new_pbmsg(){ return new ::proto_ff::ArmorSuitState(); }
		static ::proto_ff::ArmorSuitState make_pbmsg(){ return ::proto_ff::ArmorSuitState(); }
	};
	typedef struct ArmorSuitState_s ArmorSuitState_t;

	struct ArmorInfo_s : public NFDescStoreSeqOP {
		ArmorInfo_s();
		virtual ~ArmorInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		NFShmVector<struct ArmorSuitState_s, DEFINE_ARMORINFO_SUITS_MAX_NUM> suits;//
		int32_t allstate;//
		NFShmVector<int32_t, DEFINE_ARMORINFO_POS_MAX_NUM> pos;//

		virtual void write_to_pbmsg(::proto_ff::ArmorInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArmorInfo & msg);
		static ::proto_ff::ArmorInfo* new_pbmsg(){ return new ::proto_ff::ArmorInfo(); }
		static ::proto_ff::ArmorInfo make_pbmsg(){ return ::proto_ff::ArmorInfo(); }
	};
	typedef struct ArmorInfo_s ArmorInfo_t;

	struct TitleInfo_s : public NFDescStoreSeqOP {
		TitleInfo_s();
		virtual ~TitleInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t title_id;//
		int32_t status;//
		int64_t start_time;//
		int64_t end_time;//
		int32_t star;//

		virtual void write_to_pbmsg(::proto_ff::TitleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TitleInfo & msg);
		static ::proto_ff::TitleInfo* new_pbmsg(){ return new ::proto_ff::TitleInfo(); }
		static ::proto_ff::TitleInfo make_pbmsg(){ return ::proto_ff::TitleInfo(); }
	};
	typedef struct TitleInfo_s TitleInfo_t;

	struct OccupationMissionSoulData_s : public NFDescStoreSeqOP {
		OccupationMissionSoulData_s();
		virtual ~OccupationMissionSoulData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t soul_type;//
		int32_t soul_pos;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::OccupationMissionSoulData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationMissionSoulData & msg);
		static ::proto_ff::OccupationMissionSoulData* new_pbmsg(){ return new ::proto_ff::OccupationMissionSoulData(); }
		static ::proto_ff::OccupationMissionSoulData make_pbmsg(){ return ::proto_ff::OccupationMissionSoulData(); }
	};
	typedef struct OccupationMissionSoulData_s OccupationMissionSoulData_t;

	struct OccupationMissionStageData_s : public NFDescStoreSeqOP {
		OccupationMissionStageData_s();
		virtual ~OccupationMissionStageData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t stage;//
		int32_t status;//
		NFShmVector<struct OccupationMissionSoulData_s, DEFINE_OCCUPATIONMISSIONSTAGEDATA_SOUL_DATA_MAX_NUM> soul_data;//

		virtual void write_to_pbmsg(::proto_ff::OccupationMissionStageData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationMissionStageData & msg);
		static ::proto_ff::OccupationMissionStageData* new_pbmsg(){ return new ::proto_ff::OccupationMissionStageData(); }
		static ::proto_ff::OccupationMissionStageData make_pbmsg(){ return ::proto_ff::OccupationMissionStageData(); }
	};
	typedef struct OccupationMissionStageData_s OccupationMissionStageData_t;

	struct OccupationMissionGradeData_s : public NFDescStoreSeqOP {
		OccupationMissionGradeData_s();
		virtual ~OccupationMissionGradeData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t grade;//
		int32_t status;//
		NFShmVector<struct OccupationMissionStageData_s, DEFINE_OCCUPATIONMISSIONGRADEDATA_STAGE_DATA_MAX_NUM> stage_data;//

		virtual void write_to_pbmsg(::proto_ff::OccupationMissionGradeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationMissionGradeData & msg);
		static ::proto_ff::OccupationMissionGradeData* new_pbmsg(){ return new ::proto_ff::OccupationMissionGradeData(); }
		static ::proto_ff::OccupationMissionGradeData make_pbmsg(){ return ::proto_ff::OccupationMissionGradeData(); }
	};
	typedef struct OccupationMissionGradeData_s OccupationMissionGradeData_t;

	struct OccupationMissionData_s : public NFDescStoreSeqOP {
		OccupationMissionData_s();
		virtual ~OccupationMissionData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct OccupationMissionGradeData_s, DEFINE_OCCUPATIONMISSIONDATA_GRADE_DATA_MAX_NUM> grade_data;//

		virtual void write_to_pbmsg(::proto_ff::OccupationMissionData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OccupationMissionData & msg);
		static ::proto_ff::OccupationMissionData* new_pbmsg(){ return new ::proto_ff::OccupationMissionData(); }
		static ::proto_ff::OccupationMissionData make_pbmsg(){ return ::proto_ff::OccupationMissionData(); }
	};
	typedef struct OccupationMissionData_s OccupationMissionData_t;

	struct BestEQEquipInfo_s : public NFDescStoreSeqOP {
		BestEQEquipInfo_s();
		virtual ~BestEQEquipInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t instId;//
		int32_t cfgId;//
		int32_t makeId;//
		NFShmVector<struct ComPair_s, DEFINE_BESTEQEQUIPINFO_SKILLS_MAX_NUM> skills;//

		virtual void write_to_pbmsg(::proto_ff::BestEQEquipInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BestEQEquipInfo & msg);
		static ::proto_ff::BestEQEquipInfo* new_pbmsg(){ return new ::proto_ff::BestEQEquipInfo(); }
		static ::proto_ff::BestEQEquipInfo make_pbmsg(){ return ::proto_ff::BestEQEquipInfo(); }
	};
	typedef struct BestEQEquipInfo_s BestEQEquipInfo_t;

	struct BestEQBreak_s : public NFDescStoreSeqOP {
		BestEQBreak_s();
		virtual ~BestEQBreak_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;//
		NFShmVector<int32_t, DEFINE_BESTEQBREAK_EXPS_MAX_NUM> exps;//
		NFShmVector<struct ComPair_s, DEFINE_BESTEQBREAK_GENATTR_MAX_NUM> genAttr;//

		virtual void write_to_pbmsg(::proto_ff::BestEQBreak & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BestEQBreak & msg);
		static ::proto_ff::BestEQBreak* new_pbmsg(){ return new ::proto_ff::BestEQBreak(); }
		static ::proto_ff::BestEQBreak make_pbmsg(){ return ::proto_ff::BestEQBreak(); }
	};
	typedef struct BestEQBreak_s BestEQBreak_t;

	struct BestEQSlotInfo_s : public NFDescStoreSeqOP {
		BestEQSlotInfo_s();
		virtual ~BestEQSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot;//
		int32_t instId;//
		int32_t pourId;//
		int32_t pourExp;//
		int32_t pourUnLock;//
		struct BestEQBreak_s breakInfo;//
		int32_t awakenLv;//

		virtual void write_to_pbmsg(::proto_ff::BestEQSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BestEQSlotInfo & msg);
		static ::proto_ff::BestEQSlotInfo* new_pbmsg(){ return new ::proto_ff::BestEQSlotInfo(); }
		static ::proto_ff::BestEQSlotInfo make_pbmsg(){ return ::proto_ff::BestEQSlotInfo(); }
	};
	typedef struct BestEQSlotInfo_s BestEQSlotInfo_t;

	struct BestEQTask_s : public NFDescStoreSeqOP {
		BestEQTask_s();
		virtual ~BestEQTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::BestEQTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BestEQTask & msg);
		static ::proto_ff::BestEQTask* new_pbmsg(){ return new ::proto_ff::BestEQTask(); }
		static ::proto_ff::BestEQTask make_pbmsg(){ return ::proto_ff::BestEQTask(); }
	};
	typedef struct BestEQTask_s BestEQTask_t;

}

