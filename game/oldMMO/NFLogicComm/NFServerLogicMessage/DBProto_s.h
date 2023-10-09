#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProto.pb.h"
#include "DBProto_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

#define DEFINE_BAGITEMSDBDATA_DATA_MAX_NUM 1
#define DEFINE_ROLEDBUNITBAGDATA_PARTS_MAX_NUM 1
#define DEFINE_ROLEDBBAGDATA_BAGS_MAX_NUM 1
#define DEFINE_ROLEDBEQUIPDATA_INFOS_MAX_NUM 1
#define DEFINE_ROLEDBEQUIPDATA_LV_ATTR_MAX_NUM 1
#define DEFINE_GROWPARTDBDATA_ENTRYS_MAX_NUM 1
#define DEFINE_GROWDBDATA_PARTS_MAX_NUM 1
#define DEFINE_DAYUSEITEMDATA_INFO_MAX_NUM 1
#define DEFINE_CHARACTERARENADATA_RESULT_MAX_NUM 1
#define DEFINE_CHARACTERARENADATA_CHALL_REWARD_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_KUN_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_BLOOD_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_BABY_SLOT_DATA_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_BATTLE_DATA_MAX_NUM 1
#define DEFINE_FACADEDBDATA_DATA_MAX_NUM 1
#define DEFINE_SKILLDBGROUP_POS_LST_MAX_NUM 1
#define DEFINE_SKILLDBDATA_INFO_LST_MAX_NUM 1
#define DEFINE_SKILLDBDATA_GROUP_LST_MAX_NUM 1
#define DEFINE_SKILLDBDATA_ADV_POS_MAX_NUM 1
#define DEFINE_SKILLDBDATA_ADV_INFO_MAX_NUM 1
#define DEFINE_SKILLDBDATA_PET_CD_MAX_NUM 1
#define DEFINE_GODRELICSACTIVITYDATA_GROUP_DATA_MAX_NUM 1
#define DEFINE_DUPTOWERDBRECORD_ENTRYS_MAX_NUM 1
#define DEFINE_DUPTOWERDBDATA_IDS_MAX_NUM 1
#define DEFINE_DUPDBDATA_RECORD_MAX_NUM 1
#define DEFINE_DUPDBDATA_GROUPS_MAX_NUM 1
#define DEFINE_BUFFDBDATA_INFO_LST_MAX_NUM 1
#define DEFINE_BUFFDBDATA_CD_LST_MAX_NUM 1
#define DEFINE_BOSSDBDATA_INFOS_MAX_NUM 1
#define DEFINE_BOSSDBDATA_ATTENTS_MAX_NUM 1
#define DEFINE_ATTRDBDATA_ATTR_LST_MAX_NUM 1
#define DEFINE_PETDBRECORD_COSTITEM_MAX_NUM 1
#define DEFINE_PETDBRECORD_COSTPET_MAX_NUM 1
#define DEFINE_PETDBDATA_FETTER_MAX_NUM 1
#define DEFINE_PETDBDATA_PETS_MAX_NUM 1
#define DEFINE_PETDBDATA_HATCHS_MAX_NUM 1
#define DEFINE_PETDBDATA_RECORDS_MAX_NUM 1
#define DEFINE_PETDBDATA_CFGIDS_MAX_NUM 1
#define DEFINE_MALLDBDATA_DAY_MAX_NUM 1
#define DEFINE_MALLDBDATA_WEEK_MAX_NUM 1
#define DEFINE_MALLDBDATA_FOREVER_MAX_NUM 1
#define DEFINE_ARMORDBDATA_INFOS_MAX_NUM 1
#define DEFINE_ASSISTDBDATA_REWARDIDS_MAX_NUM 1
#define DEFINE_ASSISTDBDATA_THANKSINFO_MAX_NUM 1
#define DEFINE_TITLEDBDATA_DATA_MAX_NUM 1
#define DEFINE_GODEVILMULTCONDDBPROTO_LST_MAX_NUM 1
#define DEFINE_PAYDBDATA_DB_ID_MAX_NUM 1
#define DEFINE_PAYDBDATA_PRODUCT_MAX_NUM 1
#define DEFINE_ROLEFACTIONDBDATA_SALARY_MAX_NUM 1
#define DEFINE_ROLEBESTEQDBDATA_EQUIPS_MAX_NUM 1
#define DEFINE_ROLEBESTEQDBDATA_SLOTS_MAX_NUM 1
#define DEFINE_ROLEBESTEQDBDATA_TASKS_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_SEND_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_WAIT_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_TRIGGER_LST_MAX_NUM 1
#define DEFINE_REDFETCHLISTDBPROTO_INFO_MAX_NUM 1
#define DEFINE_REDDBDATA_WAIT_MAX_NUM 1
#define DEFINE_REDDBDATA_TRIGGER_LST_MAX_NUM 1
#define DEFINE_REDDBDATA_SEND_MAX_NUM 1
#define DEFINE_FACTIONMULTMEMDBPROTO_MEM_LST_MAX_NUM 1
#define DEFINE_FACTIONMULTAPPLYDBPROTO_APPLY_LST_MAX_NUM 1
#define DEFINE_FACTIONMUTRECORDDBPROTO_RECORD_LST_MAX_NUM 1
#define DEFINE_ROLELISTDBRSP_ROLE_LST_MAX_NUM 1
#define DEFINE_ROLESIMPLELISTDBRSP_INFO_MAX_NUM 1
#define DEFINE_NEWMAILDBINFO_DATA_MAX_NUM 1
#define DEFINE_MAILDBOPERATEINFO_MID_LST_MAX_NUM 1
#define DEFINE_CHARACTERMAILDBRESPONSE_INFO_MAX_NUM 1
#define DEFINE_ZONEMAILTRANSCHARACTERMAILRSP_DATA_MAX_NUM 1
#define DEFINE_WEBMAILDBDATAREQ_ID_LST_MAX_NUM 1
#define DEFINE_WEBMAILDBDATARSP_ID_LST_MAX_NUM 1
#define DEFINE_WEBMAILDBDATARSP_INFO_LST_MAX_NUM 1
#define DEFINE_FRIENDDBREQUEST_DSTID_LST_MAX_NUM 1
#define DEFINE_FRIENDDBRESPONSE_INFO_LST_MAX_NUM 1
#define DEFINE_FRIENDDBRESPONSE_LAST_LST_MAX_NUM 1
#define DEFINE_ALLFRIENDDBRESPONSE_INFO_MAX_NUM 1
#define DEFINE_SAVEFRIENDDBREQUEST_INFO_MAX_NUM 1
#define DEFINE_GLOBALDBRESPONSE_ENTRY_MAX_NUM 1
#define DEFINE_GLOBALCOMDATA_TOWERDUPREWARD_MAX_NUM 1
#define DEFINE_ACTDBRSP_LST_MAX_NUM 1
#define DEFINE_ACTSAVEDBREQ_LST_MAX_NUM 1
#define DEFINE_ARENAMOREDBINFO_INFO_MAX_NUM 1
#define DEFINE_ALLARENADBRESPONSE_INFO_MAX_NUM 1
#define DEFINE_SAVEARENADBREQUEST_INFO_MAX_NUM 1
#define DEFINE_FACTIONDATADBRSP_DATA_LST_MAX_NUM 1
#define DEFINE_FACTIONREDDBRSP_DATA_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBRSP_DATA_LST_MAX_NUM 1
namespace proto_ff_s {

	struct RoleReliveProto_s : public NFDescStoreSeqOP {
		RoleReliveProto_s();
		virtual ~RoleReliveProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t tired_time;
		int32_t relive_num;
		int32_t is_tired;
		uint64_t mapid;
		int32_t map_relive_num;

		virtual void write_to_pbmsg(::proto_ff::RoleReliveProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleReliveProto & msg);
		static ::proto_ff::RoleReliveProto* new_pbmsg(){ return new ::proto_ff::RoleReliveProto(); }
		static ::proto_ff::RoleReliveProto make_pbmsg(){ return ::proto_ff::RoleReliveProto(); }
	};
	typedef struct RoleReliveProto_s RoleReliveProto_t;

	struct RoleDBBaseData_s : public NFDescStoreSeqOP {
		RoleDBBaseData_s();
		virtual ~RoleDBBaseData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;
		uint32_t prof;
		uint32_t level;
		int64_t exp;
		int64_t hp;
		int64_t fight;
		uint64_t createTime;
		uint64_t loginTime;
		uint64_t logoutTime;
		uint64_t enter_scene_id;
		uint64_t enter_map_id;
		float enterposx;
		float enterposy;
		float enterposz;
		uint64_t lastsceneid;
		uint64_t lastmapid;
		float lastposx;
		float lastposy;
		float lastposz;
		struct RoleFacadeProto_s facade;
		uint32_t vip_level;
		int32_t state;
		uint64_t hanguptime;
		struct RoleReliveProto_s relive;
		int64_t gold;
		int64_t dia;
		int64_t bdia;
		int64_t magic;
		int64_t prestige;
		int32_t vipLv;
		int64_t arenacoin;
		int64_t godevil_exp;
		int32_t godevil_level;
		uint32_t login_day;
		uint64_t login_day_time;
		int64_t best_aq;
		int64_t best_lj;

		virtual void write_to_pbmsg(::proto_ff::RoleDBBaseData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBBaseData & msg);
		static ::proto_ff::RoleDBBaseData* new_pbmsg(){ return new ::proto_ff::RoleDBBaseData(); }
		static ::proto_ff::RoleDBBaseData make_pbmsg(){ return ::proto_ff::RoleDBBaseData(); }
	};
	typedef struct RoleDBBaseData_s RoleDBBaseData_t;

	struct BagItemsDBData_s : public NFDescStoreSeqOP {
		BagItemsDBData_s();
		virtual ~BagItemsDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ItemProtoInfo_s, DEFINE_BAGITEMSDBDATA_DATA_MAX_NUM> data;
		int32_t offset;

		virtual void write_to_pbmsg(::proto_ff::BagItemsDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BagItemsDBData & msg);
		static ::proto_ff::BagItemsDBData* new_pbmsg(){ return new ::proto_ff::BagItemsDBData(); }
		static ::proto_ff::BagItemsDBData make_pbmsg(){ return ::proto_ff::BagItemsDBData(); }
	};
	typedef struct BagItemsDBData_s BagItemsDBData_t;

	struct BagDBSimpleData_s : public NFDescStoreSeqOP {
		BagDBSimpleData_s();
		virtual ~BagDBSimpleData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t package_type;
		uint32_t expand_num;

		virtual void write_to_pbmsg(::proto_ff::BagDBSimpleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BagDBSimpleData & msg);
		static ::proto_ff::BagDBSimpleData* new_pbmsg(){ return new ::proto_ff::BagDBSimpleData(); }
		static ::proto_ff::BagDBSimpleData make_pbmsg(){ return ::proto_ff::BagDBSimpleData(); }
	};
	typedef struct BagDBSimpleData_s BagDBSimpleData_t;

	struct RoleDBUnitBagData_s : public NFDescStoreSeqOP {
		RoleDBUnitBagData_s();
		virtual ~RoleDBUnitBagData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> table_name;
		struct BagDBSimpleData_s simple;
		NFShmVector<struct BagItemsDBData_s, DEFINE_ROLEDBUNITBAGDATA_PARTS_MAX_NUM> parts;

		virtual void write_to_pbmsg(::proto_ff::RoleDBUnitBagData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBUnitBagData & msg);
		static ::proto_ff::RoleDBUnitBagData* new_pbmsg(){ return new ::proto_ff::RoleDBUnitBagData(); }
		static ::proto_ff::RoleDBUnitBagData make_pbmsg(){ return ::proto_ff::RoleDBUnitBagData(); }
	};
	typedef struct RoleDBUnitBagData_s RoleDBUnitBagData_t;

	struct RoleDBBagData_s : public NFDescStoreSeqOP {
		RoleDBBagData_s();
		virtual ~RoleDBBagData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RoleDBUnitBagData_s, DEFINE_ROLEDBBAGDATA_BAGS_MAX_NUM> bags;

		virtual void write_to_pbmsg(::proto_ff::RoleDBBagData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBBagData & msg);
		static ::proto_ff::RoleDBBagData* new_pbmsg(){ return new ::proto_ff::RoleDBBagData(); }
		static ::proto_ff::RoleDBBagData make_pbmsg(){ return ::proto_ff::RoleDBBagData(); }
	};
	typedef struct RoleDBBagData_s RoleDBBagData_t;

	struct RoleDBEquipData_s : public NFDescStoreSeqOP {
		RoleDBEquipData_s();
		virtual ~RoleDBEquipData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct EquipInfo_s, DEFINE_ROLEDBEQUIPDATA_INFOS_MAX_NUM> infos;
		NFShmVector<struct EquipLvAttrInfo_s, DEFINE_ROLEDBEQUIPDATA_LV_ATTR_MAX_NUM> lv_attr;
		uint32_t stove_level;
		uint64_t stove_exp;

		virtual void write_to_pbmsg(::proto_ff::RoleDBEquipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBEquipData & msg);
		static ::proto_ff::RoleDBEquipData* new_pbmsg(){ return new ::proto_ff::RoleDBEquipData(); }
		static ::proto_ff::RoleDBEquipData make_pbmsg(){ return ::proto_ff::RoleDBEquipData(); }
	};
	typedef struct RoleDBEquipData_s RoleDBEquipData_t;

	struct RoleDBTaskData_s : public NFDescStoreSeqOP {
		RoleDBTaskData_s();
		virtual ~RoleDBTaskData_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::RoleDBTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBTaskData & msg);
		static ::proto_ff::RoleDBTaskData* new_pbmsg(){ return new ::proto_ff::RoleDBTaskData(); }
		static ::proto_ff::RoleDBTaskData make_pbmsg(){ return ::proto_ff::RoleDBTaskData(); }
	};
	typedef struct RoleDBTaskData_s RoleDBTaskData_t;

	struct GrowPartEntryDBInfo_s : public NFDescStoreSeqOP {
		GrowPartEntryDBInfo_s();
		virtual ~GrowPartEntryDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t lv;

		virtual void write_to_pbmsg(::proto_ff::GrowPartEntryDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GrowPartEntryDBInfo & msg);
		static ::proto_ff::GrowPartEntryDBInfo* new_pbmsg(){ return new ::proto_ff::GrowPartEntryDBInfo(); }
		static ::proto_ff::GrowPartEntryDBInfo make_pbmsg(){ return ::proto_ff::GrowPartEntryDBInfo(); }
	};
	typedef struct GrowPartEntryDBInfo_s GrowPartEntryDBInfo_t;

	struct GrowPartDBData_s : public NFDescStoreSeqOP {
		GrowPartDBData_s();
		virtual ~GrowPartDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		NFShmVector<struct GrowPartEntryDBInfo_s, DEFINE_GROWPARTDBDATA_ENTRYS_MAX_NUM> entrys;
		int64_t curId;

		virtual void write_to_pbmsg(::proto_ff::GrowPartDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GrowPartDBData & msg);
		static ::proto_ff::GrowPartDBData* new_pbmsg(){ return new ::proto_ff::GrowPartDBData(); }
		static ::proto_ff::GrowPartDBData make_pbmsg(){ return ::proto_ff::GrowPartDBData(); }
	};
	typedef struct GrowPartDBData_s GrowPartDBData_t;

	struct GrowDBData_s : public NFDescStoreSeqOP {
		GrowDBData_s();
		virtual ~GrowDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GrowPartDBData_s, DEFINE_GROWDBDATA_PARTS_MAX_NUM> parts;

		virtual void write_to_pbmsg(::proto_ff::GrowDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GrowDBData & msg);
		static ::proto_ff::GrowDBData* new_pbmsg(){ return new ::proto_ff::GrowDBData(); }
		static ::proto_ff::GrowDBData make_pbmsg(){ return ::proto_ff::GrowDBData(); }
	};
	typedef struct GrowDBData_s GrowDBData_t;

	struct DayUseItemData_s : public NFDescStoreSeqOP {
		DayUseItemData_s();
		virtual ~DayUseItemData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair64_s, DEFINE_DAYUSEITEMDATA_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::DayUseItemData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DayUseItemData & msg);
		static ::proto_ff::DayUseItemData* new_pbmsg(){ return new ::proto_ff::DayUseItemData(); }
		static ::proto_ff::DayUseItemData make_pbmsg(){ return ::proto_ff::DayUseItemData(); }
	};
	typedef struct DayUseItemData_s DayUseItemData_t;

	struct CharacterArenaData_s : public NFDescStoreSeqOP {
		CharacterArenaData_s();
		virtual ~CharacterArenaData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t challengeTimes;
		uint64_t updateTime;
		uint32_t historyRankId;
		uint32_t buyChallengeTimes;
		NFShmVector<struct ArenaChallResult_s, DEFINE_CHARACTERARENADATA_RESULT_MAX_NUM> result;
		NFShmVector<struct ChallArenaReward_s, DEFINE_CHARACTERARENADATA_CHALL_REWARD_MAX_NUM> chall_reward;
		int32_t allChallengeTimes;
		int32_t rank_id;

		virtual void write_to_pbmsg(::proto_ff::CharacterArenaData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterArenaData & msg);
		static ::proto_ff::CharacterArenaData* new_pbmsg(){ return new ::proto_ff::CharacterArenaData(); }
		static ::proto_ff::CharacterArenaData make_pbmsg(){ return ::proto_ff::CharacterArenaData(); }
	};
	typedef struct CharacterArenaData_s CharacterArenaData_t;

	struct MiniDBData_s : public NFDescStoreSeqOP {
		MiniDBData_s();
		virtual ~MiniDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t lastTime;
		struct DayUseItemData_s useItem;
		struct CharacterArenaData_s arena_data;

		virtual void write_to_pbmsg(::proto_ff::MiniDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MiniDBData & msg);
		static ::proto_ff::MiniDBData* new_pbmsg(){ return new ::proto_ff::MiniDBData(); }
		static ::proto_ff::MiniDBData make_pbmsg(){ return ::proto_ff::MiniDBData(); }
	};
	typedef struct MiniDBData_s MiniDBData_t;

	struct FacadeDataInfo_s : public NFDescStoreSeqOP {
		FacadeDataInfo_s();
		virtual ~FacadeDataInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t facade_type;
		uint64_t facade_id;
		uint32_t facade_lev;
		uint64_t facade_exp;
		bool use_soul_item;
		bool use_facade;
		uint64_t equip_fantasy_id;
		NFShmVector<struct FacadeFantasyData_s, DEFINE_FACADEDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;
		NFShmVector<struct FacadeFragmentData_s, DEFINE_FACADEDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;
		NFShmVector<struct FacadeSkillData_s, DEFINE_FACADEDATAINFO_SKILL_DATA_MAX_NUM> skill_data;
		struct FacadeSoulData_s soul_data;

		virtual void write_to_pbmsg(::proto_ff::FacadeDataInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeDataInfo & msg);
		static ::proto_ff::FacadeDataInfo* new_pbmsg(){ return new ::proto_ff::FacadeDataInfo(); }
		static ::proto_ff::FacadeDataInfo make_pbmsg(){ return ::proto_ff::FacadeDataInfo(); }
	};
	typedef struct FacadeDataInfo_s FacadeDataInfo_t;

	struct MountDataInfo_s : public NFDescStoreSeqOP {
		MountDataInfo_s();
		virtual ~MountDataInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t mount_id;
		uint32_t mount_lev;
		uint64_t mount_exp;
		bool use_facade;
		uint64_t equip_fantasy_id;
		NFShmVector<struct MountFantasyData_s, DEFINE_MOUNTDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;
		NFShmVector<struct MountFragmentData_s, DEFINE_MOUNTDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;
		NFShmVector<struct MountSkillData_s, DEFINE_MOUNTDATAINFO_SKILL_DATA_MAX_NUM> skill_data;
		NFShmVector<struct MountKunData_s, DEFINE_MOUNTDATAINFO_KUN_DATA_MAX_NUM> kun_data;
		NFShmVector<struct MountBloodData_s, DEFINE_MOUNTDATAINFO_BLOOD_DATA_MAX_NUM> blood_data;
		NFShmVector<struct MountBabySlotData_s, DEFINE_MOUNTDATAINFO_BABY_SLOT_DATA_MAX_NUM> baby_slot_data;
		uint32_t ride_state;
		uint64_t mount_model_id;
		uint64_t last_mount_model_id;

		virtual void write_to_pbmsg(::proto_ff::MountDataInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountDataInfo & msg);
		static ::proto_ff::MountDataInfo* new_pbmsg(){ return new ::proto_ff::MountDataInfo(); }
		static ::proto_ff::MountDataInfo make_pbmsg(){ return ::proto_ff::MountDataInfo(); }
	};
	typedef struct MountDataInfo_s MountDataInfo_t;

	struct DeityDataInfo_s : public NFDescStoreSeqOP {
		DeityDataInfo_s();
		virtual ~DeityDataInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t deity_id;
		uint32_t deity_lev;
		uint64_t deity_exp;
		NFShmVector<struct DeityFantasyData_s, DEFINE_DEITYDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;
		NFShmVector<struct DeityFragmentData_s, DEFINE_DEITYDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;
		NFShmVector<struct DeitySkillData_s, DEFINE_DEITYDATAINFO_SKILL_DATA_MAX_NUM> skill_data;
		NFShmVector<struct DeityBattleSlotData_s, DEFINE_DEITYDATAINFO_BATTLE_DATA_MAX_NUM> battle_data;

		virtual void write_to_pbmsg(::proto_ff::DeityDataInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeityDataInfo & msg);
		static ::proto_ff::DeityDataInfo* new_pbmsg(){ return new ::proto_ff::DeityDataInfo(); }
		static ::proto_ff::DeityDataInfo make_pbmsg(){ return ::proto_ff::DeityDataInfo(); }
	};
	typedef struct DeityDataInfo_s DeityDataInfo_t;

	struct FacadeDBData_s : public NFDescStoreSeqOP {
		FacadeDBData_s();
		virtual ~FacadeDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FacadeDataInfo_s, DEFINE_FACADEDBDATA_DATA_MAX_NUM> data;

		virtual void write_to_pbmsg(::proto_ff::FacadeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FacadeDBData & msg);
		static ::proto_ff::FacadeDBData* new_pbmsg(){ return new ::proto_ff::FacadeDBData(); }
		static ::proto_ff::FacadeDBData make_pbmsg(){ return ::proto_ff::FacadeDBData(); }
	};
	typedef struct FacadeDBData_s FacadeDBData_t;

	struct SkillDBInfo_s : public NFDescStoreSeqOP {
		SkillDBInfo_s();
		virtual ~SkillDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;
		int32_t level;
		int32_t wakeup;
		int64_t use_msc;

		virtual void write_to_pbmsg(::proto_ff::SkillDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBInfo & msg);
		static ::proto_ff::SkillDBInfo* new_pbmsg(){ return new ::proto_ff::SkillDBInfo(); }
		static ::proto_ff::SkillDBInfo make_pbmsg(){ return ::proto_ff::SkillDBInfo(); }
	};
	typedef struct SkillDBInfo_s SkillDBInfo_t;

	struct SkillDBPos_s : public NFDescStoreSeqOP {
		SkillDBPos_s();
		virtual ~SkillDBPos_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;
		uint32_t pos;
		int32_t use;

		virtual void write_to_pbmsg(::proto_ff::SkillDBPos & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBPos & msg);
		static ::proto_ff::SkillDBPos* new_pbmsg(){ return new ::proto_ff::SkillDBPos(); }
		static ::proto_ff::SkillDBPos make_pbmsg(){ return ::proto_ff::SkillDBPos(); }
	};
	typedef struct SkillDBPos_s SkillDBPos_t;

	struct SkillDBAdvPos_s : public NFDescStoreSeqOP {
		SkillDBAdvPos_s();
		virtual ~SkillDBAdvPos_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t pos;
		uint32_t advance;
		uint32_t unlock;

		virtual void write_to_pbmsg(::proto_ff::SkillDBAdvPos & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBAdvPos & msg);
		static ::proto_ff::SkillDBAdvPos* new_pbmsg(){ return new ::proto_ff::SkillDBAdvPos(); }
		static ::proto_ff::SkillDBAdvPos make_pbmsg(){ return ::proto_ff::SkillDBAdvPos(); }
	};
	typedef struct SkillDBAdvPos_s SkillDBAdvPos_t;

	struct SkillDBAdvInfo_s : public NFDescStoreSeqOP {
		SkillDBAdvInfo_s();
		virtual ~SkillDBAdvInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t advance;
		int32_t level;

		virtual void write_to_pbmsg(::proto_ff::SkillDBAdvInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBAdvInfo & msg);
		static ::proto_ff::SkillDBAdvInfo* new_pbmsg(){ return new ::proto_ff::SkillDBAdvInfo(); }
		static ::proto_ff::SkillDBAdvInfo make_pbmsg(){ return ::proto_ff::SkillDBAdvInfo(); }
	};
	typedef struct SkillDBAdvInfo_s SkillDBAdvInfo_t;

	struct SkillDBGroup_s : public NFDescStoreSeqOP {
		SkillDBGroup_s();
		virtual ~SkillDBGroup_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t group;
		int32_t chg;
		NFShmVector<struct SkillDBPos_s, DEFINE_SKILLDBGROUP_POS_LST_MAX_NUM> pos_lst;

		virtual void write_to_pbmsg(::proto_ff::SkillDBGroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBGroup & msg);
		static ::proto_ff::SkillDBGroup* new_pbmsg(){ return new ::proto_ff::SkillDBGroup(); }
		static ::proto_ff::SkillDBGroup make_pbmsg(){ return ::proto_ff::SkillDBGroup(); }
	};
	typedef struct SkillDBGroup_s SkillDBGroup_t;

	struct PetSkillCdDB_s : public NFDescStoreSeqOP {
		PetSkillCdDB_s();
		virtual ~PetSkillCdDB_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t skill_id;
		uint64_t use_msec;
		int64_t pet_instid;

		virtual void write_to_pbmsg(::proto_ff::PetSkillCdDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetSkillCdDB & msg);
		static ::proto_ff::PetSkillCdDB* new_pbmsg(){ return new ::proto_ff::PetSkillCdDB(); }
		static ::proto_ff::PetSkillCdDB make_pbmsg(){ return ::proto_ff::PetSkillCdDB(); }
	};
	typedef struct PetSkillCdDB_s PetSkillCdDB_t;

	struct SkillDBData_s : public NFDescStoreSeqOP {
		SkillDBData_s();
		virtual ~SkillDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct SkillDBInfo_s, DEFINE_SKILLDBDATA_INFO_LST_MAX_NUM> info_lst;
		NFShmVector<struct SkillDBGroup_s, DEFINE_SKILLDBDATA_GROUP_LST_MAX_NUM> group_lst;
		uint32_t group;
		uint64_t last_group;
		NFShmVector<struct SkillDBAdvPos_s, DEFINE_SKILLDBDATA_ADV_POS_MAX_NUM> adv_pos;
		NFShmVector<struct SkillDBAdvInfo_s, DEFINE_SKILLDBDATA_ADV_INFO_MAX_NUM> adv_info;
		uint32_t cur_advpos;
		NFShmVector<struct PetSkillCdDB_s, DEFINE_SKILLDBDATA_PET_CD_MAX_NUM> pet_cd;

		virtual void write_to_pbmsg(::proto_ff::SkillDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBData & msg);
		static ::proto_ff::SkillDBData* new_pbmsg(){ return new ::proto_ff::SkillDBData(); }
		static ::proto_ff::SkillDBData make_pbmsg(){ return ::proto_ff::SkillDBData(); }
	};
	typedef struct SkillDBData_s SkillDBData_t;

	struct GodRelicsActivityData_s : public NFDescStoreSeqOP {
		GodRelicsActivityData_s();
		virtual ~GodRelicsActivityData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GodRelicsTaskGroupEntry_s, DEFINE_GODRELICSACTIVITYDATA_GROUP_DATA_MAX_NUM> group_data;
		int64_t cur_group_id;

		virtual void write_to_pbmsg(::proto_ff::GodRelicsActivityData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodRelicsActivityData & msg);
		static ::proto_ff::GodRelicsActivityData* new_pbmsg(){ return new ::proto_ff::GodRelicsActivityData(); }
		static ::proto_ff::GodRelicsActivityData make_pbmsg(){ return ::proto_ff::GodRelicsActivityData(); }
	};
	typedef struct GodRelicsActivityData_s GodRelicsActivityData_t;

	struct MiniActivityDBData_s : public NFDescStoreSeqOP {
		MiniActivityDBData_s();
		virtual ~MiniActivityDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct GodRelicsActivityData_s god_relics_data;
		struct DailyTaskAllData_s daily_data;

		virtual void write_to_pbmsg(::proto_ff::MiniActivityDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MiniActivityDBData & msg);
		static ::proto_ff::MiniActivityDBData* new_pbmsg(){ return new ::proto_ff::MiniActivityDBData(); }
		static ::proto_ff::MiniActivityDBData make_pbmsg(){ return ::proto_ff::MiniActivityDBData(); }
	};
	typedef struct MiniActivityDBData_s MiniActivityDBData_t;

	struct DupRecord_s : public NFDescStoreSeqOP {
		DupRecord_s();
		virtual ~DupRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t dupId;
		int32_t star;

		virtual void write_to_pbmsg(::proto_ff::DupRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupRecord & msg);
		static ::proto_ff::DupRecord* new_pbmsg(){ return new ::proto_ff::DupRecord(); }
		static ::proto_ff::DupRecord make_pbmsg(){ return ::proto_ff::DupRecord(); }
	};
	typedef struct DupRecord_s DupRecord_t;

	struct DupGroupData_s : public NFDescStoreSeqOP {
		DupGroupData_s();
		virtual ~DupGroupData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t group;
		int32_t enterNum;
		int32_t buyNum;
		int32_t useNum;
		uint64_t lastFresh;

		virtual void write_to_pbmsg(::proto_ff::DupGroupData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupGroupData & msg);
		static ::proto_ff::DupGroupData* new_pbmsg(){ return new ::proto_ff::DupGroupData(); }
		static ::proto_ff::DupGroupData make_pbmsg(){ return ::proto_ff::DupGroupData(); }
	};
	typedef struct DupGroupData_s DupGroupData_t;

	struct DupTowerDBRecordEntry_s : public NFDescStoreSeqOP {
		DupTowerDBRecordEntry_s();
		virtual ~DupTowerDBRecordEntry_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;
		uint64_t time;
		uint64_t cid;

		virtual void write_to_pbmsg(::proto_ff::DupTowerDBRecordEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupTowerDBRecordEntry & msg);
		static ::proto_ff::DupTowerDBRecordEntry* new_pbmsg(){ return new ::proto_ff::DupTowerDBRecordEntry(); }
		static ::proto_ff::DupTowerDBRecordEntry make_pbmsg(){ return ::proto_ff::DupTowerDBRecordEntry(); }
	};
	typedef struct DupTowerDBRecordEntry_s DupTowerDBRecordEntry_t;

	struct DupTowerDBRecord_s : public NFDescStoreSeqOP {
		DupTowerDBRecord_s();
		virtual ~DupTowerDBRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFShmVector<struct DupTowerDBRecordEntry_s, DEFINE_DUPTOWERDBRECORD_ENTRYS_MAX_NUM> entrys;

		virtual void write_to_pbmsg(::proto_ff::DupTowerDBRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupTowerDBRecord & msg);
		static ::proto_ff::DupTowerDBRecord* new_pbmsg(){ return new ::proto_ff::DupTowerDBRecord(); }
		static ::proto_ff::DupTowerDBRecord make_pbmsg(){ return ::proto_ff::DupTowerDBRecord(); }
	};
	typedef struct DupTowerDBRecord_s DupTowerDBRecord_t;

	struct DupTowerDBData_s : public NFDescStoreSeqOP {
		DupTowerDBData_s();
		virtual ~DupTowerDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<uint64_t, DEFINE_DUPTOWERDBDATA_IDS_MAX_NUM> ids;

		virtual void write_to_pbmsg(::proto_ff::DupTowerDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupTowerDBData & msg);
		static ::proto_ff::DupTowerDBData* new_pbmsg(){ return new ::proto_ff::DupTowerDBData(); }
		static ::proto_ff::DupTowerDBData make_pbmsg(){ return ::proto_ff::DupTowerDBData(); }
	};
	typedef struct DupTowerDBData_s DupTowerDBData_t;

	struct DupDBData_s : public NFDescStoreSeqOP {
		DupDBData_s();
		virtual ~DupDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DupRecord_s, DEFINE_DUPDBDATA_RECORD_MAX_NUM> record;
		NFShmVector<struct DupGroupData_s, DEFINE_DUPDBDATA_GROUPS_MAX_NUM> groups;
		struct DupTowerDBData_s tower;

		virtual void write_to_pbmsg(::proto_ff::DupDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupDBData & msg);
		static ::proto_ff::DupDBData* new_pbmsg(){ return new ::proto_ff::DupDBData(); }
		static ::proto_ff::DupDBData make_pbmsg(){ return ::proto_ff::DupDBData(); }
	};
	typedef struct DupDBData_s DupDBData_t;

	struct BuffDBInfo_s : public NFDescStoreSeqOP {
		BuffDBInfo_s();
		virtual ~BuffDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t buffid;
		uint64_t index;
		uint64_t skillid;
		uint32_t skilllev;
		bool is_forever;
		int64_t startmsec;
		bool is_effect;
		int64_t param1;
		int64_t param2;
		int64_t extramsec;
		int32_t is_end;

		virtual void write_to_pbmsg(::proto_ff::BuffDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffDBInfo & msg);
		static ::proto_ff::BuffDBInfo* new_pbmsg(){ return new ::proto_ff::BuffDBInfo(); }
		static ::proto_ff::BuffDBInfo make_pbmsg(){ return ::proto_ff::BuffDBInfo(); }
	};
	typedef struct BuffDBInfo_s BuffDBInfo_t;

	struct BuffDBCdInfo_s : public NFDescStoreSeqOP {
		BuffDBCdInfo_s();
		virtual ~BuffDBCdInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t buffid;
		uint64_t lastmsec;

		virtual void write_to_pbmsg(::proto_ff::BuffDBCdInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffDBCdInfo & msg);
		static ::proto_ff::BuffDBCdInfo* new_pbmsg(){ return new ::proto_ff::BuffDBCdInfo(); }
		static ::proto_ff::BuffDBCdInfo make_pbmsg(){ return ::proto_ff::BuffDBCdInfo(); }
	};
	typedef struct BuffDBCdInfo_s BuffDBCdInfo_t;

	struct BuffDBData_s : public NFDescStoreSeqOP {
		BuffDBData_s();
		virtual ~BuffDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct BuffDBInfo_s, DEFINE_BUFFDBDATA_INFO_LST_MAX_NUM> info_lst;
		NFShmVector<struct BuffDBCdInfo_s, DEFINE_BUFFDBDATA_CD_LST_MAX_NUM> cd_lst;

		virtual void write_to_pbmsg(::proto_ff::BuffDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffDBData & msg);
		static ::proto_ff::BuffDBData* new_pbmsg(){ return new ::proto_ff::BuffDBData(); }
		static ::proto_ff::BuffDBData make_pbmsg(){ return ::proto_ff::BuffDBData(); }
	};
	typedef struct BuffDBData_s BuffDBData_t;

	struct BossSimpleInfoDB_s : public NFDescStoreSeqOP {
		BossSimpleInfoDB_s();
		virtual ~BossSimpleInfoDB_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t boss_type;
		int32_t cur_num;
		int32_t back_num;
		int32_t back_max_num;
		int32_t enter_num;
		int32_t use_item_num;

		virtual void write_to_pbmsg(::proto_ff::BossSimpleInfoDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BossSimpleInfoDB & msg);
		static ::proto_ff::BossSimpleInfoDB* new_pbmsg(){ return new ::proto_ff::BossSimpleInfoDB(); }
		static ::proto_ff::BossSimpleInfoDB make_pbmsg(){ return ::proto_ff::BossSimpleInfoDB(); }
	};
	typedef struct BossSimpleInfoDB_s BossSimpleInfoDB_t;

	struct BossDBData_s : public NFDescStoreSeqOP {
		BossDBData_s();
		virtual ~BossDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct BossSimpleInfoDB_s, DEFINE_BOSSDBDATA_INFOS_MAX_NUM> infos;
		uint64_t lastTime;
		NFShmVector<int64_t, DEFINE_BOSSDBDATA_ATTENTS_MAX_NUM> attents;

		virtual void write_to_pbmsg(::proto_ff::BossDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BossDBData & msg);
		static ::proto_ff::BossDBData* new_pbmsg(){ return new ::proto_ff::BossDBData(); }
		static ::proto_ff::BossDBData make_pbmsg(){ return ::proto_ff::BossDBData(); }
	};
	typedef struct BossDBData_s BossDBData_t;

	struct VipDBData_s : public NFDescStoreSeqOP {
		VipDBData_s();
		virtual ~VipDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t vipExp;
		int32_t expDiamond;

		virtual void write_to_pbmsg(::proto_ff::VipDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::VipDBData & msg);
		static ::proto_ff::VipDBData* new_pbmsg(){ return new ::proto_ff::VipDBData(); }
		static ::proto_ff::VipDBData make_pbmsg(){ return ::proto_ff::VipDBData(); }
	};
	typedef struct VipDBData_s VipDBData_t;

	struct AttrDBData_s : public NFDescStoreSeqOP {
		AttrDBData_s();
		virtual ~AttrDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct Attr64_s, DEFINE_ATTRDBDATA_ATTR_LST_MAX_NUM> attr_lst;

		virtual void write_to_pbmsg(::proto_ff::AttrDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AttrDBData & msg);
		static ::proto_ff::AttrDBData* new_pbmsg(){ return new ::proto_ff::AttrDBData(); }
		static ::proto_ff::AttrDBData make_pbmsg(){ return ::proto_ff::AttrDBData(); }
	};
	typedef struct AttrDBData_s AttrDBData_t;

	struct PetDBRecord_s : public NFDescStoreSeqOP {
		PetDBRecord_s();
		virtual ~PetDBRecord_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t instId;
		NFShmVector<struct ComPair64_s, DEFINE_PETDBRECORD_COSTITEM_MAX_NUM> costItem;
		NFShmVector<struct ComPair64_s, DEFINE_PETDBRECORD_COSTPET_MAX_NUM> costPet;

		virtual void write_to_pbmsg(::proto_ff::PetDBRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetDBRecord & msg);
		static ::proto_ff::PetDBRecord* new_pbmsg(){ return new ::proto_ff::PetDBRecord(); }
		static ::proto_ff::PetDBRecord make_pbmsg(){ return ::proto_ff::PetDBRecord(); }
	};
	typedef struct PetDBRecord_s PetDBRecord_t;

	struct PetDBData_s : public NFDescStoreSeqOP {
		PetDBData_s();
		virtual ~PetDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_PETDBDATA_FETTER_MAX_NUM> fetter;
		NFShmVector<struct PetInfo_s, DEFINE_PETDBDATA_PETS_MAX_NUM> pets;
		NFShmVector<struct PetHatchInfo_s, DEFINE_PETDBDATA_HATCHS_MAX_NUM> hatchs;
		NFShmVector<struct PetDBRecord_s, DEFINE_PETDBDATA_RECORDS_MAX_NUM> records;
		NFShmVector<int64_t, DEFINE_PETDBDATA_CFGIDS_MAX_NUM> cfgids;

		virtual void write_to_pbmsg(::proto_ff::PetDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetDBData & msg);
		static ::proto_ff::PetDBData* new_pbmsg(){ return new ::proto_ff::PetDBData(); }
		static ::proto_ff::PetDBData make_pbmsg(){ return ::proto_ff::PetDBData(); }
	};
	typedef struct PetDBData_s PetDBData_t;

	struct MallDBInfo_s : public NFDescStoreSeqOP {
		MallDBInfo_s();
		virtual ~MallDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		uint32_t num;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::MallDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MallDBInfo & msg);
		static ::proto_ff::MallDBInfo* new_pbmsg(){ return new ::proto_ff::MallDBInfo(); }
		static ::proto_ff::MallDBInfo make_pbmsg(){ return ::proto_ff::MallDBInfo(); }
	};
	typedef struct MallDBInfo_s MallDBInfo_t;

	struct MallDBData_s : public NFDescStoreSeqOP {
		MallDBData_s();
		virtual ~MallDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_DAY_MAX_NUM> day;
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_WEEK_MAX_NUM> week;
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_FOREVER_MAX_NUM> forever;

		virtual void write_to_pbmsg(::proto_ff::MallDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MallDBData & msg);
		static ::proto_ff::MallDBData* new_pbmsg(){ return new ::proto_ff::MallDBData(); }
		static ::proto_ff::MallDBData make_pbmsg(){ return ::proto_ff::MallDBData(); }
	};
	typedef struct MallDBData_s MallDBData_t;

	struct ConvoyData_s : public NFDescStoreSeqOP {
		ConvoyData_s();
		virtual ~ConvoyData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t daynum;
		int32_t escortid;
		uint64_t endTime;
		int32_t freeNum;
		int32_t genEscortId;
		uint64_t resetTime;

		virtual void write_to_pbmsg(::proto_ff::ConvoyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ConvoyData & msg);
		static ::proto_ff::ConvoyData* new_pbmsg(){ return new ::proto_ff::ConvoyData(); }
		static ::proto_ff::ConvoyData make_pbmsg(){ return ::proto_ff::ConvoyData(); }
	};
	typedef struct ConvoyData_s ConvoyData_t;

	struct ArmorDBData_s : public NFDescStoreSeqOP {
		ArmorDBData_s();
		virtual ~ArmorDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ArmorInfo_s, DEFINE_ARMORDBDATA_INFOS_MAX_NUM> infos;

		virtual void write_to_pbmsg(::proto_ff::ArmorDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArmorDBData & msg);
		static ::proto_ff::ArmorDBData* new_pbmsg(){ return new ::proto_ff::ArmorDBData(); }
		static ::proto_ff::ArmorDBData make_pbmsg(){ return ::proto_ff::ArmorDBData(); }
	};
	typedef struct ArmorDBData_s ArmorDBData_t;

	struct AssistDBData_s : public NFDescStoreSeqOP {
		AssistDBData_s();
		virtual ~AssistDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t resetTime;
		int32_t dayPrestige;
		int32_t sendNum;
		int32_t helpNum;
		int32_t allSendNum;
		int32_t allHelpNum;
		int32_t recvSendGiftNum;
		int32_t recvHelpGiftNum;
		NFShmVector<int32_t, DEFINE_ASSISTDBDATA_REWARDIDS_MAX_NUM> rewardIds;
		NFShmVector<struct ComPair64_s, DEFINE_ASSISTDBDATA_THANKSINFO_MAX_NUM> thanksInfo;

		virtual void write_to_pbmsg(::proto_ff::AssistDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AssistDBData & msg);
		static ::proto_ff::AssistDBData* new_pbmsg(){ return new ::proto_ff::AssistDBData(); }
		static ::proto_ff::AssistDBData make_pbmsg(){ return ::proto_ff::AssistDBData(); }
	};
	typedef struct AssistDBData_s AssistDBData_t;

	struct TitleDBData_s : public NFDescStoreSeqOP {
		TitleDBData_s();
		virtual ~TitleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cur_wearing_title;
		NFShmVector<struct TitleInfo_s, DEFINE_TITLEDBDATA_DATA_MAX_NUM> data;

		virtual void write_to_pbmsg(::proto_ff::TitleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TitleDBData & msg);
		static ::proto_ff::TitleDBData* new_pbmsg(){ return new ::proto_ff::TitleDBData(); }
		static ::proto_ff::TitleDBData make_pbmsg(){ return ::proto_ff::TitleDBData(); }
	};
	typedef struct TitleDBData_s TitleDBData_t;

	struct GodEvilCondDBProto_s : public NFDescStoreSeqOP {
		GodEvilCondDBProto_s();
		virtual ~GodEvilCondDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t state;
		int32_t cur;

		virtual void write_to_pbmsg(::proto_ff::GodEvilCondDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilCondDBProto & msg);
		static ::proto_ff::GodEvilCondDBProto* new_pbmsg(){ return new ::proto_ff::GodEvilCondDBProto(); }
		static ::proto_ff::GodEvilCondDBProto make_pbmsg(){ return ::proto_ff::GodEvilCondDBProto(); }
	};
	typedef struct GodEvilCondDBProto_s GodEvilCondDBProto_t;

	struct GodEvilMultCondDBProto_s : public NFDescStoreSeqOP {
		GodEvilMultCondDBProto_s();
		virtual ~GodEvilMultCondDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GodEvilCondDBProto_s, DEFINE_GODEVILMULTCONDDBPROTO_LST_MAX_NUM> lst;

		virtual void write_to_pbmsg(::proto_ff::GodEvilMultCondDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilMultCondDBProto & msg);
		static ::proto_ff::GodEvilMultCondDBProto* new_pbmsg(){ return new ::proto_ff::GodEvilMultCondDBProto(); }
		static ::proto_ff::GodEvilMultCondDBProto make_pbmsg(){ return ::proto_ff::GodEvilMultCondDBProto(); }
	};
	typedef struct GodEvilMultCondDBProto_s GodEvilMultCondDBProto_t;

	struct GodEvilTaskDBProto_s : public NFDescStoreSeqOP {
		GodEvilTaskDBProto_s();
		virtual ~GodEvilTaskDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t stage;
		struct GodEvilMultCondDBProto_s cond;
		int32_t finish;
		int32_t accept;

		virtual void write_to_pbmsg(::proto_ff::GodEvilTaskDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilTaskDBProto & msg);
		static ::proto_ff::GodEvilTaskDBProto* new_pbmsg(){ return new ::proto_ff::GodEvilTaskDBProto(); }
		static ::proto_ff::GodEvilTaskDBProto make_pbmsg(){ return ::proto_ff::GodEvilTaskDBProto(); }
	};
	typedef struct GodEvilTaskDBProto_s GodEvilTaskDBProto_t;

	struct GodEvilDBData_s : public NFDescStoreSeqOP {
		GodEvilDBData_s();
		virtual ~GodEvilDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t fetch;
		struct GodEvilTaskDBProto_s task;
		int32_t type;
		uint64_t last_time;
		int32_t vessel_lev;
		int32_t mirror_lev;
		int64_t extra_exp;

		virtual void write_to_pbmsg(::proto_ff::GodEvilDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilDBData & msg);
		static ::proto_ff::GodEvilDBData* new_pbmsg(){ return new ::proto_ff::GodEvilDBData(); }
		static ::proto_ff::GodEvilDBData make_pbmsg(){ return ::proto_ff::GodEvilDBData(); }
	};
	typedef struct GodEvilDBData_s GodEvilDBData_t;

	struct PayDBData_s : public NFDescStoreSeqOP {
		PayDBData_s();
		virtual ~PayDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<uint32_t, DEFINE_PAYDBDATA_DB_ID_MAX_NUM> db_id;
		NFShmVector<NFShmString<32>, DEFINE_PAYDBDATA_PRODUCT_MAX_NUM> product;
		uint32_t relrmb;
		uint32_t rmb;
		uint32_t fakermb;
		uint32_t todayrmb;
		uint64_t todaytime;

		virtual void write_to_pbmsg(::proto_ff::PayDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PayDBData & msg);
		static ::proto_ff::PayDBData* new_pbmsg(){ return new ::proto_ff::PayDBData(); }
		static ::proto_ff::PayDBData make_pbmsg(){ return ::proto_ff::PayDBData(); }
	};
	typedef struct PayDBData_s PayDBData_t;

	struct FactionDBSalary_s : public NFDescStoreSeqOP {
		FactionDBSalary_s();
		virtual ~FactionDBSalary_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t cur;
		int32_t fetch;

		virtual void write_to_pbmsg(::proto_ff::FactionDBSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBSalary & msg);
		static ::proto_ff::FactionDBSalary* new_pbmsg(){ return new ::proto_ff::FactionDBSalary(); }
		static ::proto_ff::FactionDBSalary make_pbmsg(){ return ::proto_ff::FactionDBSalary(); }
	};
	typedef struct FactionDBSalary_s FactionDBSalary_t;

	struct RoleFactionDBData_s : public NFDescStoreSeqOP {
		RoleFactionDBData_s();
		virtual ~RoleFactionDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t donate_num;
		uint64_t donate_fresh;
		NFShmVector<struct FactionDBSalary_s, DEFINE_ROLEFACTIONDBDATA_SALARY_MAX_NUM> salary;
		uint64_t salary_fresh;

		virtual void write_to_pbmsg(::proto_ff::RoleFactionDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleFactionDBData & msg);
		static ::proto_ff::RoleFactionDBData* new_pbmsg(){ return new ::proto_ff::RoleFactionDBData(); }
		static ::proto_ff::RoleFactionDBData make_pbmsg(){ return ::proto_ff::RoleFactionDBData(); }
	};
	typedef struct RoleFactionDBData_s RoleFactionDBData_t;

	struct RoleBestEQDBData_s : public NFDescStoreSeqOP {
		RoleBestEQDBData_s();
		virtual ~RoleBestEQDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct BestEQEquipInfo_s, DEFINE_ROLEBESTEQDBDATA_EQUIPS_MAX_NUM> equips;
		NFShmVector<struct BestEQSlotInfo_s, DEFINE_ROLEBESTEQDBDATA_SLOTS_MAX_NUM> slots;
		NFShmVector<struct BestEQTask_s, DEFINE_ROLEBESTEQDBDATA_TASKS_MAX_NUM> tasks;

		virtual void write_to_pbmsg(::proto_ff::RoleBestEQDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleBestEQDBData & msg);
		static ::proto_ff::RoleBestEQDBData* new_pbmsg(){ return new ::proto_ff::RoleBestEQDBData(); }
		static ::proto_ff::RoleBestEQDBData make_pbmsg(){ return ::proto_ff::RoleBestEQDBData(); }
	};
	typedef struct RoleBestEQDBData_s RoleBestEQDBData_t;

	struct RoleDBData_s : public NFDescStoreSeqOP {
		RoleDBData_s();
		virtual ~RoleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint32_t zid;
		uint32_t uid;
		struct RoleDBBaseData_s base;
		struct RoleDBBagData_s bag;
		struct RoleDBEquipData_s equip;
		struct CharacterDBTaskData_s task;
		struct FunctionUnlockInfo_s unlockinfo;
		struct GrowDBData_s grow;
		struct MiniDBData_s mini;
		struct FacadeDBData_s facade;
		struct SkillDBData_s skill;
		struct MiniActivityDBData_s mini_activity;
		struct DupDBData_s dup;
		struct BuffDBData_s buff;
		struct BossDBData_s boss;
		struct VipDBData_s vip;
		struct AttrDBData_s attr;
		struct MountDataInfo_s mount;
		struct DeityDataInfo_s deity;
		struct PetDBData_s pet;
		struct MallDBData_s mall;
		struct ConvoyData_s convoy;
		struct ArmorDBData_s armor;
		struct AssistDBData_s assist;
		struct TitleDBData_s title;
		struct GodEvilDBData_s godevil;
		struct OccupationMissionData_s occupatoin;
		struct PayDBData_s pay;
		struct RoleFactionDBData_s role_faction;
		struct RoleBestEQDBData_s best_equip;

		virtual void write_to_pbmsg(::proto_ff::RoleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBData & msg);
		static ::proto_ff::RoleDBData* new_pbmsg(){ return new ::proto_ff::RoleDBData(); }
		static ::proto_ff::RoleDBData make_pbmsg(){ return ::proto_ff::RoleDBData(); }
	};
	typedef struct RoleDBData_s RoleDBData_t;

	struct RedWaitDBProto_s : public NFDescStoreSeqOP {
		RedWaitDBProto_s();
		virtual ~RedWaitDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t idx;
		int32_t cfgid;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::RedWaitDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedWaitDBProto & msg);
		static ::proto_ff::RedWaitDBProto* new_pbmsg(){ return new ::proto_ff::RedWaitDBProto(); }
		static ::proto_ff::RedWaitDBProto make_pbmsg(){ return ::proto_ff::RedWaitDBProto(); }
	};
	typedef struct RedWaitDBProto_s RedWaitDBProto_t;

	struct RedTriggerDBProto_s : public NFDescStoreSeqOP {
		RedTriggerDBProto_s();
		virtual ~RedTriggerDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t cfgid;
		int32_t count;

		virtual void write_to_pbmsg(::proto_ff::RedTriggerDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedTriggerDBProto & msg);
		static ::proto_ff::RedTriggerDBProto* new_pbmsg(){ return new ::proto_ff::RedTriggerDBProto(); }
		static ::proto_ff::RedTriggerDBProto make_pbmsg(){ return ::proto_ff::RedTriggerDBProto(); }
	};
	typedef struct RedTriggerDBProto_s RedTriggerDBProto_t;

	struct RoleRedDBData_s : public NFDescStoreSeqOP {
		RoleRedDBData_s();
		virtual ~RoleRedDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t bdia;
		uint32_t magic;
		uint32_t todaynum;
		uint32_t todaymagic;
		uint32_t todaybdia;
		uint64_t freshtime;
		NFShmVector<int32_t, DEFINE_ROLEREDDBDATA_SEND_LST_MAX_NUM> send_lst;
		NFShmVector<struct RedWaitDBProto_s, DEFINE_ROLEREDDBDATA_WAIT_LST_MAX_NUM> wait_lst;
		uint64_t cid;
		NFShmVector<struct RedTriggerDBProto_s, DEFINE_ROLEREDDBDATA_TRIGGER_LST_MAX_NUM> trigger_lst;

		virtual void write_to_pbmsg(::proto_ff::RoleRedDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleRedDBData & msg);
		static ::proto_ff::RoleRedDBData* new_pbmsg(){ return new ::proto_ff::RoleRedDBData(); }
		static ::proto_ff::RoleRedDBData make_pbmsg(){ return ::proto_ff::RoleRedDBData(); }
	};
	typedef struct RoleRedDBData_s RoleRedDBData_t;

	struct RedFetchDBProto_s : public NFDescStoreSeqOP {
		RedFetchDBProto_s();
		virtual ~RedFetchDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint32_t val;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::RedFetchDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedFetchDBProto & msg);
		static ::proto_ff::RedFetchDBProto* new_pbmsg(){ return new ::proto_ff::RedFetchDBProto(); }
		static ::proto_ff::RedFetchDBProto make_pbmsg(){ return ::proto_ff::RedFetchDBProto(); }
	};
	typedef struct RedFetchDBProto_s RedFetchDBProto_t;

	struct RedFetchListDBProto_s : public NFDescStoreSeqOP {
		RedFetchListDBProto_s();
		virtual ~RedFetchListDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RedFetchDBProto_s, DEFINE_REDFETCHLISTDBPROTO_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::RedFetchListDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedFetchListDBProto & msg);
		static ::proto_ff::RedFetchListDBProto* new_pbmsg(){ return new ::proto_ff::RedFetchListDBProto(); }
		static ::proto_ff::RedFetchListDBProto make_pbmsg(){ return ::proto_ff::RedFetchListDBProto(); }
	};
	typedef struct RedFetchListDBProto_s RedFetchListDBProto_t;

	struct RedSendDBProto_s : public NFDescStoreSeqOP {
		RedSendDBProto_s();
		virtual ~RedSendDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t idx;
		int32_t cfgid;
		uint64_t sender;
		uint64_t sendtime;
		NFShmString<32> word;
		int32_t finish;
		struct RedFetchListDBProto_s fetch;

		virtual void write_to_pbmsg(::proto_ff::RedSendDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedSendDBProto & msg);
		static ::proto_ff::RedSendDBProto* new_pbmsg(){ return new ::proto_ff::RedSendDBProto(); }
		static ::proto_ff::RedSendDBProto make_pbmsg(){ return ::proto_ff::RedSendDBProto(); }
	};
	typedef struct RedSendDBProto_s RedSendDBProto_t;

	struct RedDBData_s : public NFDescStoreSeqOP {
		RedDBData_s();
		virtual ~RedDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RedWaitDBProto_s, DEFINE_REDDBDATA_WAIT_MAX_NUM> wait;
		NFShmVector<struct RedTriggerDBProto_s, DEFINE_REDDBDATA_TRIGGER_LST_MAX_NUM> trigger_lst;
		uint64_t freshtime;
		NFShmVector<struct RedSendDBProto_s, DEFINE_REDDBDATA_SEND_MAX_NUM> send;
		uint32_t faction_id;

		virtual void write_to_pbmsg(::proto_ff::RedDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RedDBData & msg);
		static ::proto_ff::RedDBData* new_pbmsg(){ return new ::proto_ff::RedDBData(); }
		static ::proto_ff::RedDBData make_pbmsg(){ return ::proto_ff::RedDBData(); }
	};
	typedef struct RedDBData_s RedDBData_t;

	struct RoleMirrorData_s : public NFDescStoreSeqOP {
		RoleMirrorData_s();
		virtual ~RoleMirrorData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		int32_t type;
		uint32_t teamid;
		uint32_t zid;
		struct AttrDBData_s attr;
		struct SkillDBData_s skill;
		struct RoleDBBaseData_s base;

		virtual void write_to_pbmsg(::proto_ff::RoleMirrorData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleMirrorData & msg);
		static ::proto_ff::RoleMirrorData* new_pbmsg(){ return new ::proto_ff::RoleMirrorData(); }
		static ::proto_ff::RoleMirrorData make_pbmsg(){ return ::proto_ff::RoleMirrorData(); }
	};
	typedef struct RoleMirrorData_s RoleMirrorData_t;

	struct FactionMemDBProto_s : public NFDescStoreSeqOP {
		FactionMemDBProto_s();
		virtual ~FactionMemDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		int32_t duty;
		uint64_t join_time;
		uint32_t total_contri;

		virtual void write_to_pbmsg(::proto_ff::FactionMemDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionMemDBProto & msg);
		static ::proto_ff::FactionMemDBProto* new_pbmsg(){ return new ::proto_ff::FactionMemDBProto(); }
		static ::proto_ff::FactionMemDBProto make_pbmsg(){ return ::proto_ff::FactionMemDBProto(); }
	};
	typedef struct FactionMemDBProto_s FactionMemDBProto_t;

	struct FactionMultMemDBProto_s : public NFDescStoreSeqOP {
		FactionMultMemDBProto_s();
		virtual ~FactionMultMemDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionMemDBProto_s, DEFINE_FACTIONMULTMEMDBPROTO_MEM_LST_MAX_NUM> mem_lst;

		virtual void write_to_pbmsg(::proto_ff::FactionMultMemDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionMultMemDBProto & msg);
		static ::proto_ff::FactionMultMemDBProto* new_pbmsg(){ return new ::proto_ff::FactionMultMemDBProto(); }
		static ::proto_ff::FactionMultMemDBProto make_pbmsg(){ return ::proto_ff::FactionMultMemDBProto(); }
	};
	typedef struct FactionMultMemDBProto_s FactionMultMemDBProto_t;

	struct FactionApplyDBProto_s : public NFDescStoreSeqOP {
		FactionApplyDBProto_s();
		virtual ~FactionApplyDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint64_t time;

		virtual void write_to_pbmsg(::proto_ff::FactionApplyDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionApplyDBProto & msg);
		static ::proto_ff::FactionApplyDBProto* new_pbmsg(){ return new ::proto_ff::FactionApplyDBProto(); }
		static ::proto_ff::FactionApplyDBProto make_pbmsg(){ return ::proto_ff::FactionApplyDBProto(); }
	};
	typedef struct FactionApplyDBProto_s FactionApplyDBProto_t;

	struct FactionMultApplyDBProto_s : public NFDescStoreSeqOP {
		FactionMultApplyDBProto_s();
		virtual ~FactionMultApplyDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionApplyDBProto_s, DEFINE_FACTIONMULTAPPLYDBPROTO_APPLY_LST_MAX_NUM> apply_lst;

		virtual void write_to_pbmsg(::proto_ff::FactionMultApplyDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionMultApplyDBProto & msg);
		static ::proto_ff::FactionMultApplyDBProto* new_pbmsg(){ return new ::proto_ff::FactionMultApplyDBProto(); }
		static ::proto_ff::FactionMultApplyDBProto make_pbmsg(){ return ::proto_ff::FactionMultApplyDBProto(); }
	};
	typedef struct FactionMultApplyDBProto_s FactionMultApplyDBProto_t;

	struct FactionRecordDBProto_s : public NFDescStoreSeqOP {
		FactionRecordDBProto_s();
		virtual ~FactionRecordDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint64_t time;
		int32_t op;
		int64_t param1;

		virtual void write_to_pbmsg(::proto_ff::FactionRecordDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionRecordDBProto & msg);
		static ::proto_ff::FactionRecordDBProto* new_pbmsg(){ return new ::proto_ff::FactionRecordDBProto(); }
		static ::proto_ff::FactionRecordDBProto make_pbmsg(){ return ::proto_ff::FactionRecordDBProto(); }
	};
	typedef struct FactionRecordDBProto_s FactionRecordDBProto_t;

	struct FactionMutRecordDBProto_s : public NFDescStoreSeqOP {
		FactionMutRecordDBProto_s();
		virtual ~FactionMutRecordDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionRecordDBProto_s, DEFINE_FACTIONMUTRECORDDBPROTO_RECORD_LST_MAX_NUM> record_lst;

		virtual void write_to_pbmsg(::proto_ff::FactionMutRecordDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionMutRecordDBProto & msg);
		static ::proto_ff::FactionMutRecordDBProto* new_pbmsg(){ return new ::proto_ff::FactionMutRecordDBProto(); }
		static ::proto_ff::FactionMutRecordDBProto make_pbmsg(){ return ::proto_ff::FactionMutRecordDBProto(); }
	};
	typedef struct FactionMutRecordDBProto_s FactionMutRecordDBProto_t;

	struct FactionDBBase_s : public NFDescStoreSeqOP {
		FactionDBBase_s();
		virtual ~FactionDBBase_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;
		NFShmString<32> name;
		uint64_t leader_id;
		uint64_t fight;
		NFShmString<32> notice;
		uint64_t last_notice_time;
		uint32_t level;
		uint64_t exp;
		uint64_t create_time;
		uint64_t proxy_id;
		uint64_t proxy_time;
		int32_t grade;
		struct FactionMultMemDBProto_s member;
		struct FactionMultApplyDBProto_s apply;
		struct FactionMutRecordDBProto_s record;

		virtual void write_to_pbmsg(::proto_ff::FactionDBBase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBBase & msg);
		static ::proto_ff::FactionDBBase* new_pbmsg(){ return new ::proto_ff::FactionDBBase(); }
		static ::proto_ff::FactionDBBase make_pbmsg(){ return ::proto_ff::FactionDBBase(); }
	};
	typedef struct FactionDBBase_s FactionDBBase_t;

	struct FactionDBData_s : public NFDescStoreSeqOP {
		FactionDBData_s();
		virtual ~FactionDBData_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::FactionDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBData & msg);
		static ::proto_ff::FactionDBData* new_pbmsg(){ return new ::proto_ff::FactionDBData(); }
		static ::proto_ff::FactionDBData make_pbmsg(){ return ::proto_ff::FactionDBData(); }
	};
	typedef struct FactionDBData_s FactionDBData_t;

	struct FactionAllDBData_s : public NFDescStoreSeqOP {
		FactionAllDBData_s();
		virtual ~FactionAllDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;
		struct FactionDBBase_s base;
		struct FactionDBData_s data;

		virtual void write_to_pbmsg(::proto_ff::FactionAllDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionAllDBData & msg);
		static ::proto_ff::FactionAllDBData* new_pbmsg(){ return new ::proto_ff::FactionAllDBData(); }
		static ::proto_ff::FactionAllDBData make_pbmsg(){ return ::proto_ff::FactionAllDBData(); }
	};
	typedef struct FactionAllDBData_s FactionAllDBData_t;

	struct RoleListDBReq_s : public NFDescStoreSeqOP {
		RoleListDBReq_s();
		virtual ~RoleListDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t reqid;
		uint32_t uid;
		uint32_t gateid;
		uint32_t born_zid;

		virtual void write_to_pbmsg(::proto_ff::RoleListDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleListDBReq & msg);
		static ::proto_ff::RoleListDBReq* new_pbmsg(){ return new ::proto_ff::RoleListDBReq(); }
		static ::proto_ff::RoleListDBReq make_pbmsg(){ return ::proto_ff::RoleListDBReq(); }
	};
	typedef struct RoleListDBReq_s RoleListDBReq_t;

	struct RoleListDBRsp_s : public NFDescStoreSeqOP {
		RoleListDBRsp_s();
		virtual ~RoleListDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		uint64_t reqid;
		uint32_t uid;
		uint32_t gateid;
		NFShmVector<struct RoleListDBProto_s, DEFINE_ROLELISTDBRSP_ROLE_LST_MAX_NUM> role_lst;
		uint32_t regnum;

		virtual void write_to_pbmsg(::proto_ff::RoleListDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleListDBRsp & msg);
		static ::proto_ff::RoleListDBRsp* new_pbmsg(){ return new ::proto_ff::RoleListDBRsp(); }
		static ::proto_ff::RoleListDBRsp make_pbmsg(){ return ::proto_ff::RoleListDBRsp(); }
	};
	typedef struct RoleListDBRsp_s RoleListDBRsp_t;

	struct CreateRoleDBReq_s : public NFDescStoreSeqOP {
		CreateRoleDBReq_s();
		virtual ~CreateRoleDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t reqid;
		uint32_t zid;
		uint32_t gateid;
		struct RoleDBData_s data;
		uint32_t uid;
		uint32_t channel_id;
		uint32_t zone_mid;
		uint32_t born_zid;

		virtual void write_to_pbmsg(::proto_ff::CreateRoleDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CreateRoleDBReq & msg);
		static ::proto_ff::CreateRoleDBReq* new_pbmsg(){ return new ::proto_ff::CreateRoleDBReq(); }
		static ::proto_ff::CreateRoleDBReq make_pbmsg(){ return ::proto_ff::CreateRoleDBReq(); }
	};
	typedef struct CreateRoleDBReq_s CreateRoleDBReq_t;

	struct CreateRoleDBRsp_s : public NFDescStoreSeqOP {
		CreateRoleDBRsp_s();
		virtual ~CreateRoleDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		uint64_t reqid;
		uint32_t uid;
		uint32_t gateid;
		struct RoleListDBProto_s info;
		uint32_t born_zid;
		struct CenterRoleProto_s simple;

		virtual void write_to_pbmsg(::proto_ff::CreateRoleDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CreateRoleDBRsp & msg);
		static ::proto_ff::CreateRoleDBRsp* new_pbmsg(){ return new ::proto_ff::CreateRoleDBRsp(); }
		static ::proto_ff::CreateRoleDBRsp make_pbmsg(){ return ::proto_ff::CreateRoleDBRsp(); }
	};
	typedef struct CreateRoleDBRsp_s CreateRoleDBRsp_t;

	struct RoleInfoDBReq_s : public NFDescStoreSeqOP {
		RoleInfoDBReq_s();
		virtual ~RoleInfoDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t reqid;
		uint64_t cid;
		int32_t change;

		virtual void write_to_pbmsg(::proto_ff::RoleInfoDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleInfoDBReq & msg);
		static ::proto_ff::RoleInfoDBReq* new_pbmsg(){ return new ::proto_ff::RoleInfoDBReq(); }
		static ::proto_ff::RoleInfoDBReq make_pbmsg(){ return ::proto_ff::RoleInfoDBReq(); }
	};
	typedef struct RoleInfoDBReq_s RoleInfoDBReq_t;

	struct RoleInfoDBRsp_s : public NFDescStoreSeqOP {
		RoleInfoDBRsp_s();
		virtual ~RoleInfoDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		uint64_t reqid;
		uint64_t cid;
		int32_t change;
		struct RoleDBData_s info;

		virtual void write_to_pbmsg(::proto_ff::RoleInfoDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleInfoDBRsp & msg);
		static ::proto_ff::RoleInfoDBRsp* new_pbmsg(){ return new ::proto_ff::RoleInfoDBRsp(); }
		static ::proto_ff::RoleInfoDBRsp make_pbmsg(){ return ::proto_ff::RoleInfoDBRsp(); }
	};
	typedef struct RoleInfoDBRsp_s RoleInfoDBRsp_t;

	struct RoleInfoUpdateDBReq_s : public NFDescStoreSeqOP {
		RoleInfoUpdateDBReq_s();
		virtual ~RoleInfoUpdateDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint32_t uid;
		struct RoleDBData_s info;

		virtual void write_to_pbmsg(::proto_ff::RoleInfoUpdateDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleInfoUpdateDBReq & msg);
		static ::proto_ff::RoleInfoUpdateDBReq* new_pbmsg(){ return new ::proto_ff::RoleInfoUpdateDBReq(); }
		static ::proto_ff::RoleInfoUpdateDBReq make_pbmsg(){ return ::proto_ff::RoleInfoUpdateDBReq(); }
	};
	typedef struct RoleInfoUpdateDBReq_s RoleInfoUpdateDBReq_t;

	struct RoleChgNameDBReq_s : public NFDescStoreSeqOP {
		RoleChgNameDBReq_s();
		virtual ~RoleChgNameDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		NFShmString<32> name;

		virtual void write_to_pbmsg(::proto_ff::RoleChgNameDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleChgNameDBReq & msg);
		static ::proto_ff::RoleChgNameDBReq* new_pbmsg(){ return new ::proto_ff::RoleChgNameDBReq(); }
		static ::proto_ff::RoleChgNameDBReq make_pbmsg(){ return ::proto_ff::RoleChgNameDBReq(); }
	};
	typedef struct RoleChgNameDBReq_s RoleChgNameDBReq_t;

	struct RoleChgNameDBRsp_s : public NFDescStoreSeqOP {
		RoleChgNameDBRsp_s();
		virtual ~RoleChgNameDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		uint64_t cid;
		NFShmString<32> name;

		virtual void write_to_pbmsg(::proto_ff::RoleChgNameDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleChgNameDBRsp & msg);
		static ::proto_ff::RoleChgNameDBRsp* new_pbmsg(){ return new ::proto_ff::RoleChgNameDBRsp(); }
		static ::proto_ff::RoleChgNameDBRsp make_pbmsg(){ return ::proto_ff::RoleChgNameDBRsp(); }
	};
	typedef struct RoleChgNameDBRsp_s RoleChgNameDBRsp_t;

	struct RoleSimpleListDBReq_s : public NFDescStoreSeqOP {
		RoleSimpleListDBReq_s();
		virtual ~RoleSimpleListDBReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::RoleSimpleListDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleSimpleListDBReq & msg);
		static ::proto_ff::RoleSimpleListDBReq* new_pbmsg(){ return new ::proto_ff::RoleSimpleListDBReq(); }
		static ::proto_ff::RoleSimpleListDBReq make_pbmsg(){ return ::proto_ff::RoleSimpleListDBReq(); }
	};
	typedef struct RoleSimpleListDBReq_s RoleSimpleListDBReq_t;

	struct RoleSimpleListDBRsp_s : public NFDescStoreSeqOP {
		RoleSimpleListDBRsp_s();
		virtual ~RoleSimpleListDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		NFShmVector<struct CenterRoleProto_s, DEFINE_ROLESIMPLELISTDBRSP_INFO_MAX_NUM> info;
		int32_t finish_flag;

		virtual void write_to_pbmsg(::proto_ff::RoleSimpleListDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleSimpleListDBRsp & msg);
		static ::proto_ff::RoleSimpleListDBRsp* new_pbmsg(){ return new ::proto_ff::RoleSimpleListDBRsp(); }
		static ::proto_ff::RoleSimpleListDBRsp make_pbmsg(){ return ::proto_ff::RoleSimpleListDBRsp(); }
	};
	typedef struct RoleSimpleListDBRsp_s RoleSimpleListDBRsp_t;

	struct CreatureTransLogicDBReq_s : public NFDescStoreSeqOP {
		CreatureTransLogicDBReq_s();
		virtual ~CreatureTransLogicDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> trans_data;

		virtual void write_to_pbmsg(::proto_ff::CreatureTransLogicDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CreatureTransLogicDBReq & msg);
		static ::proto_ff::CreatureTransLogicDBReq* new_pbmsg(){ return new ::proto_ff::CreatureTransLogicDBReq(); }
		static ::proto_ff::CreatureTransLogicDBReq make_pbmsg(){ return ::proto_ff::CreatureTransLogicDBReq(); }
	};
	typedef struct CreatureTransLogicDBReq_s CreatureTransLogicDBReq_t;

	struct CreatureTransLogicDBRsp_s : public NFDescStoreSeqOP {
		CreatureTransLogicDBRsp_s();
		virtual ~CreatureTransLogicDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t retcode;
		uint64_t cid;

		virtual void write_to_pbmsg(::proto_ff::CreatureTransLogicDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CreatureTransLogicDBRsp & msg);
		static ::proto_ff::CreatureTransLogicDBRsp* new_pbmsg(){ return new ::proto_ff::CreatureTransLogicDBRsp(); }
		static ::proto_ff::CreatureTransLogicDBRsp make_pbmsg(){ return ::proto_ff::CreatureTransLogicDBRsp(); }
	};
	typedef struct CreatureTransLogicDBRsp_s CreatureTransLogicDBRsp_t;

	struct NewMailDBInfo_s : public NFDescStoreSeqOP {
		NewMailDBInfo_s();
		virtual ~NewMailDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct MailInfo_s, DEFINE_NEWMAILDBINFO_DATA_MAX_NUM> data;
		int32_t result;

		virtual void write_to_pbmsg(::proto_ff::NewMailDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NewMailDBInfo & msg);
		static ::proto_ff::NewMailDBInfo* new_pbmsg(){ return new ::proto_ff::NewMailDBInfo(); }
		static ::proto_ff::NewMailDBInfo make_pbmsg(){ return ::proto_ff::NewMailDBInfo(); }
	};
	typedef struct NewMailDBInfo_s NewMailDBInfo_t;

	struct MailDBOperateInfo_s : public NFDescStoreSeqOP {
		MailDBOperateInfo_s();
		virtual ~MailDBOperateInfo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<uint32_t, DEFINE_MAILDBOPERATEINFO_MID_LST_MAX_NUM> mid_lst;
		int32_t result;

		virtual void write_to_pbmsg(::proto_ff::MailDBOperateInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MailDBOperateInfo & msg);
		static ::proto_ff::MailDBOperateInfo* new_pbmsg(){ return new ::proto_ff::MailDBOperateInfo(); }
		static ::proto_ff::MailDBOperateInfo make_pbmsg(){ return ::proto_ff::MailDBOperateInfo(); }
	};
	typedef struct MailDBOperateInfo_s MailDBOperateInfo_t;

	struct SaveMailDBReq_s : public NFDescStoreSeqOP {
		SaveMailDBReq_s();
		virtual ~SaveMailDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charid;
		struct NewMailDBInfo_s info;
		struct MailDBOperateInfo_s del;
		struct MailDBOperateInfo_s fetch;
		struct MailDBOperateInfo_s read;
		int32_t notify;

		virtual void write_to_pbmsg(::proto_ff::SaveMailDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SaveMailDBReq & msg);
		static ::proto_ff::SaveMailDBReq* new_pbmsg(){ return new ::proto_ff::SaveMailDBReq(); }
		static ::proto_ff::SaveMailDBReq make_pbmsg(){ return ::proto_ff::SaveMailDBReq(); }
	};
	typedef struct SaveMailDBReq_s SaveMailDBReq_t;

	struct SaveMailDBRsp_s : public NFDescStoreSeqOP {
		SaveMailDBRsp_s();
		virtual ~SaveMailDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charid;
		struct NewMailDBInfo_s info;
		struct MailDBOperateInfo_s del;
		struct MailDBOperateInfo_s fetch;
		struct MailDBOperateInfo_s read;
		int32_t notify;

		virtual void write_to_pbmsg(::proto_ff::SaveMailDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SaveMailDBRsp & msg);
		static ::proto_ff::SaveMailDBRsp* new_pbmsg(){ return new ::proto_ff::SaveMailDBRsp(); }
		static ::proto_ff::SaveMailDBRsp make_pbmsg(){ return ::proto_ff::SaveMailDBRsp(); }
	};
	typedef struct SaveMailDBRsp_s SaveMailDBRsp_t;

	struct CharacterMailDBRequest_s : public NFDescStoreSeqOP {
		CharacterMailDBRequest_s();
		virtual ~CharacterMailDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charID;
		uint32_t zone_mail_flag;
		int32_t offset;
		uint32_t reqid;

		virtual void write_to_pbmsg(::proto_ff::CharacterMailDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterMailDBRequest & msg);
		static ::proto_ff::CharacterMailDBRequest* new_pbmsg(){ return new ::proto_ff::CharacterMailDBRequest(); }
		static ::proto_ff::CharacterMailDBRequest make_pbmsg(){ return ::proto_ff::CharacterMailDBRequest(); }
	};
	typedef struct CharacterMailDBRequest_s CharacterMailDBRequest_t;

	struct CharacterMailDBResponse_s : public NFDescStoreSeqOP {
		CharacterMailDBResponse_s();
		virtual ~CharacterMailDBResponse_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charID;
		NFShmVector<struct MailInfo_s, DEFINE_CHARACTERMAILDBRESPONSE_INFO_MAX_NUM> info;
		uint32_t zoneMailId;
		int32_t offset;
		uint32_t reqid;

		virtual void write_to_pbmsg(::proto_ff::CharacterMailDBResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterMailDBResponse & msg);
		static ::proto_ff::CharacterMailDBResponse* new_pbmsg(){ return new ::proto_ff::CharacterMailDBResponse(); }
		static ::proto_ff::CharacterMailDBResponse make_pbmsg(){ return ::proto_ff::CharacterMailDBResponse(); }
	};
	typedef struct CharacterMailDBResponse_s CharacterMailDBResponse_t;

	struct MaxMailIDRequest_s : public NFDescStoreSeqOP {
		MaxMailIDRequest_s();
		virtual ~MaxMailIDRequest_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::MaxMailIDRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MaxMailIDRequest & msg);
		static ::proto_ff::MaxMailIDRequest* new_pbmsg(){ return new ::proto_ff::MaxMailIDRequest(); }
		static ::proto_ff::MaxMailIDRequest make_pbmsg(){ return ::proto_ff::MaxMailIDRequest(); }
	};
	typedef struct MaxMailIDRequest_s MaxMailIDRequest_t;

	struct MaxMailIDResponse_s : public NFDescStoreSeqOP {
		MaxMailIDResponse_s();
		virtual ~MaxMailIDResponse_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t maxZoneMailId;
		uint32_t maxMailId;

		virtual void write_to_pbmsg(::proto_ff::MaxMailIDResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MaxMailIDResponse & msg);
		static ::proto_ff::MaxMailIDResponse* new_pbmsg(){ return new ::proto_ff::MaxMailIDResponse(); }
		static ::proto_ff::MaxMailIDResponse make_pbmsg(){ return ::proto_ff::MaxMailIDResponse(); }
	};
	typedef struct MaxMailIDResponse_s MaxMailIDResponse_t;

	struct DeleteCharacterMail_s : public NFDescStoreSeqOP {
		DeleteCharacterMail_s();
		virtual ~DeleteCharacterMail_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charID;

		virtual void write_to_pbmsg(::proto_ff::DeleteCharacterMail & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeleteCharacterMail & msg);
		static ::proto_ff::DeleteCharacterMail* new_pbmsg(){ return new ::proto_ff::DeleteCharacterMail(); }
		static ::proto_ff::DeleteCharacterMail make_pbmsg(){ return ::proto_ff::DeleteCharacterMail(); }
	};
	typedef struct DeleteCharacterMail_s DeleteCharacterMail_t;

	struct ZoneMailSaveRsp_s : public NFDescStoreSeqOP {
		ZoneMailSaveRsp_s();
		virtual ~ZoneMailSaveRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t mailId;

		virtual void write_to_pbmsg(::proto_ff::ZoneMailSaveRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ZoneMailSaveRsp & msg);
		static ::proto_ff::ZoneMailSaveRsp* new_pbmsg(){ return new ::proto_ff::ZoneMailSaveRsp(); }
		static ::proto_ff::ZoneMailSaveRsp make_pbmsg(){ return ::proto_ff::ZoneMailSaveRsp(); }
	};
	typedef struct ZoneMailSaveRsp_s ZoneMailSaveRsp_t;

	struct ZoneMailTransCharacterMailReq_s : public NFDescStoreSeqOP {
		ZoneMailTransCharacterMailReq_s();
		virtual ~ZoneMailTransCharacterMailReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t mailId;
		uint64_t cid;

		virtual void write_to_pbmsg(::proto_ff::ZoneMailTransCharacterMailReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ZoneMailTransCharacterMailReq & msg);
		static ::proto_ff::ZoneMailTransCharacterMailReq* new_pbmsg(){ return new ::proto_ff::ZoneMailTransCharacterMailReq(); }
		static ::proto_ff::ZoneMailTransCharacterMailReq make_pbmsg(){ return ::proto_ff::ZoneMailTransCharacterMailReq(); }
	};
	typedef struct ZoneMailTransCharacterMailReq_s ZoneMailTransCharacterMailReq_t;

	struct ZoneMailTransCharacterMailRsp_s : public NFDescStoreSeqOP {
		ZoneMailTransCharacterMailRsp_s();
		virtual ~ZoneMailTransCharacterMailRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		NFShmVector<struct MailInfo_s, DEFINE_ZONEMAILTRANSCHARACTERMAILRSP_DATA_MAX_NUM> data;

		virtual void write_to_pbmsg(::proto_ff::ZoneMailTransCharacterMailRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ZoneMailTransCharacterMailRsp & msg);
		static ::proto_ff::ZoneMailTransCharacterMailRsp* new_pbmsg(){ return new ::proto_ff::ZoneMailTransCharacterMailRsp(); }
		static ::proto_ff::ZoneMailTransCharacterMailRsp make_pbmsg(){ return ::proto_ff::ZoneMailTransCharacterMailRsp(); }
	};
	typedef struct ZoneMailTransCharacterMailRsp_s ZoneMailTransCharacterMailRsp_t;

	struct WebMailDBDataReq_s : public NFDescStoreSeqOP {
		WebMailDBDataReq_s();
		virtual ~WebMailDBDataReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t op_type;
		uint64_t cid;
		uint32_t pernum;
		uint32_t curpage;
		NFShmVector<uint32_t, DEFINE_WEBMAILDBDATAREQ_ID_LST_MAX_NUM> id_lst;
		NFShmString<32> webId;

		virtual void write_to_pbmsg(::proto_ff::WebMailDBDataReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WebMailDBDataReq & msg);
		static ::proto_ff::WebMailDBDataReq* new_pbmsg(){ return new ::proto_ff::WebMailDBDataReq(); }
		static ::proto_ff::WebMailDBDataReq make_pbmsg(){ return ::proto_ff::WebMailDBDataReq(); }
	};
	typedef struct WebMailDBDataReq_s WebMailDBDataReq_t;

	struct WebMailDBDataRsp_s : public NFDescStoreSeqOP {
		WebMailDBDataRsp_s();
		virtual ~WebMailDBDataRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t op_type;
		uint64_t cid;
		uint32_t curpage;
		uint32_t totalcount;
		NFShmVector<uint32_t, DEFINE_WEBMAILDBDATARSP_ID_LST_MAX_NUM> id_lst;
		NFShmVector<struct WebMailDataProto_s, DEFINE_WEBMAILDBDATARSP_INFO_LST_MAX_NUM> info_lst;
		NFShmString<32> webId;

		virtual void write_to_pbmsg(::proto_ff::WebMailDBDataRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WebMailDBDataRsp & msg);
		static ::proto_ff::WebMailDBDataRsp* new_pbmsg(){ return new ::proto_ff::WebMailDBDataRsp(); }
		static ::proto_ff::WebMailDBDataRsp make_pbmsg(){ return ::proto_ff::WebMailDBDataRsp(); }
	};
	typedef struct WebMailDBDataRsp_s WebMailDBDataRsp_t;

	struct FriendDBInfo_s : public NFDescStoreSeqOP {
		FriendDBInfo_s();
		virtual ~FriendDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charID;
		struct RelationDBInfo_s data;

		virtual void write_to_pbmsg(::proto_ff::FriendDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FriendDBInfo & msg);
		static ::proto_ff::FriendDBInfo* new_pbmsg(){ return new ::proto_ff::FriendDBInfo(); }
		static ::proto_ff::FriendDBInfo make_pbmsg(){ return ::proto_ff::FriendDBInfo(); }
	};
	typedef struct FriendDBInfo_s FriendDBInfo_t;

	struct FriendDBRequest_s : public NFDescStoreSeqOP {
		FriendDBRequest_s();
		virtual ~FriendDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charid;
		NFShmVector<uint64_t, DEFINE_FRIENDDBREQUEST_DSTID_LST_MAX_NUM> dstid_lst;
		uint32_t operate_type;
		NFShmString<32> data;
		uint32_t query_times;

		virtual void write_to_pbmsg(::proto_ff::FriendDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FriendDBRequest & msg);
		static ::proto_ff::FriendDBRequest* new_pbmsg(){ return new ::proto_ff::FriendDBRequest(); }
		static ::proto_ff::FriendDBRequest make_pbmsg(){ return ::proto_ff::FriendDBRequest(); }
	};
	typedef struct FriendDBRequest_s FriendDBRequest_t;

	struct FriendDBResponse_s : public NFDescStoreSeqOP {
		FriendDBResponse_s();
		virtual ~FriendDBResponse_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t retcode;
		uint64_t charid;
		uint32_t operate_type;
		NFShmVector<struct FriendDBInfo_s, DEFINE_FRIENDDBRESPONSE_INFO_LST_MAX_NUM> info_lst;
		NFShmVector<uint64_t, DEFINE_FRIENDDBRESPONSE_LAST_LST_MAX_NUM> last_lst;
		NFShmString<32> data;
		uint32_t query_times;

		virtual void write_to_pbmsg(::proto_ff::FriendDBResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FriendDBResponse & msg);
		static ::proto_ff::FriendDBResponse* new_pbmsg(){ return new ::proto_ff::FriendDBResponse(); }
		static ::proto_ff::FriendDBResponse make_pbmsg(){ return ::proto_ff::FriendDBResponse(); }
	};
	typedef struct FriendDBResponse_s FriendDBResponse_t;

	struct AllFriendDBRequest_s : public NFDescStoreSeqOP {
		AllFriendDBRequest_s();
		virtual ~AllFriendDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t offset;

		virtual void write_to_pbmsg(::proto_ff::AllFriendDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AllFriendDBRequest & msg);
		static ::proto_ff::AllFriendDBRequest* new_pbmsg(){ return new ::proto_ff::AllFriendDBRequest(); }
		static ::proto_ff::AllFriendDBRequest make_pbmsg(){ return ::proto_ff::AllFriendDBRequest(); }
	};
	typedef struct AllFriendDBRequest_s AllFriendDBRequest_t;

	struct AllFriendDBResponse_s : public NFDescStoreSeqOP {
		AllFriendDBResponse_s();
		virtual ~AllFriendDBResponse_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t retcode;
		int32_t offset;
		NFShmVector<struct FriendDBInfo_s, DEFINE_ALLFRIENDDBRESPONSE_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::AllFriendDBResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AllFriendDBResponse & msg);
		static ::proto_ff::AllFriendDBResponse* new_pbmsg(){ return new ::proto_ff::AllFriendDBResponse(); }
		static ::proto_ff::AllFriendDBResponse make_pbmsg(){ return ::proto_ff::AllFriendDBResponse(); }
	};
	typedef struct AllFriendDBResponse_s AllFriendDBResponse_t;

	struct SaveFriendDBRequest_s : public NFDescStoreSeqOP {
		SaveFriendDBRequest_s();
		virtual ~SaveFriendDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FriendDBInfo_s, DEFINE_SAVEFRIENDDBREQUEST_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::SaveFriendDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SaveFriendDBRequest & msg);
		static ::proto_ff::SaveFriendDBRequest* new_pbmsg(){ return new ::proto_ff::SaveFriendDBRequest(); }
		static ::proto_ff::SaveFriendDBRequest make_pbmsg(){ return ::proto_ff::SaveFriendDBRequest(); }
	};
	typedef struct SaveFriendDBRequest_s SaveFriendDBRequest_t;

	struct DelteFriendDBRequest_s : public NFDescStoreSeqOP {
		DelteFriendDBRequest_s();
		virtual ~DelteFriendDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charId;

		virtual void write_to_pbmsg(::proto_ff::DelteFriendDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DelteFriendDBRequest & msg);
		static ::proto_ff::DelteFriendDBRequest* new_pbmsg(){ return new ::proto_ff::DelteFriendDBRequest(); }
		static ::proto_ff::DelteFriendDBRequest make_pbmsg(){ return ::proto_ff::DelteFriendDBRequest(); }
	};
	typedef struct DelteFriendDBRequest_s DelteFriendDBRequest_t;

	struct GlobalDBRequst_s : public NFDescStoreSeqOP {
		GlobalDBRequst_s();
		virtual ~GlobalDBRequst_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::GlobalDBRequst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalDBRequst & msg);
		static ::proto_ff::GlobalDBRequst* new_pbmsg(){ return new ::proto_ff::GlobalDBRequst(); }
		static ::proto_ff::GlobalDBRequst make_pbmsg(){ return ::proto_ff::GlobalDBRequst(); }
	};
	typedef struct GlobalDBRequst_s GlobalDBRequst_t;

	struct GlobalDBEntry_s : public NFDescStoreSeqOP {
		GlobalDBEntry_s();
		virtual ~GlobalDBEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type_id;
		NFShmString<32> data;

		virtual void write_to_pbmsg(::proto_ff::GlobalDBEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalDBEntry & msg);
		static ::proto_ff::GlobalDBEntry* new_pbmsg(){ return new ::proto_ff::GlobalDBEntry(); }
		static ::proto_ff::GlobalDBEntry make_pbmsg(){ return ::proto_ff::GlobalDBEntry(); }
	};
	typedef struct GlobalDBEntry_s GlobalDBEntry_t;

	struct GlobalDBResponse_s : public NFDescStoreSeqOP {
		GlobalDBResponse_s();
		virtual ~GlobalDBResponse_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GlobalDBEntry_s, DEFINE_GLOBALDBRESPONSE_ENTRY_MAX_NUM> entry;
		int32_t isfinish;

		virtual void write_to_pbmsg(::proto_ff::GlobalDBResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalDBResponse & msg);
		static ::proto_ff::GlobalDBResponse* new_pbmsg(){ return new ::proto_ff::GlobalDBResponse(); }
		static ::proto_ff::GlobalDBResponse make_pbmsg(){ return ::proto_ff::GlobalDBResponse(); }
	};
	typedef struct GlobalDBResponse_s GlobalDBResponse_t;

	struct GlobalDBSetRequest_s : public NFDescStoreSeqOP {
		GlobalDBSetRequest_s();
		virtual ~GlobalDBSetRequest_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type_id;
		NFShmString<32> data;

		virtual void write_to_pbmsg(::proto_ff::GlobalDBSetRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalDBSetRequest & msg);
		static ::proto_ff::GlobalDBSetRequest* new_pbmsg(){ return new ::proto_ff::GlobalDBSetRequest(); }
		static ::proto_ff::GlobalDBSetRequest make_pbmsg(){ return ::proto_ff::GlobalDBSetRequest(); }
	};
	typedef struct GlobalDBSetRequest_s GlobalDBSetRequest_t;

	struct GlobalDBSetResponse_s : public NFDescStoreSeqOP {
		GlobalDBSetResponse_s();
		virtual ~GlobalDBSetResponse_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t retcode;
		int32_t type_id;

		virtual void write_to_pbmsg(::proto_ff::GlobalDBSetResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalDBSetResponse & msg);
		static ::proto_ff::GlobalDBSetResponse* new_pbmsg(){ return new ::proto_ff::GlobalDBSetResponse(); }
		static ::proto_ff::GlobalDBSetResponse make_pbmsg(){ return ::proto_ff::GlobalDBSetResponse(); }
	};
	typedef struct GlobalDBSetResponse_s GlobalDBSetResponse_t;

	struct GlobalComData_s : public NFDescStoreSeqOP {
		GlobalComData_s();
		virtual ~GlobalComData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DupTowerDBRecord_s, DEFINE_GLOBALCOMDATA_TOWERDUPREWARD_MAX_NUM> towerDupReward;

		virtual void write_to_pbmsg(::proto_ff::GlobalComData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalComData & msg);
		static ::proto_ff::GlobalComData* new_pbmsg(){ return new ::proto_ff::GlobalComData(); }
		static ::proto_ff::GlobalComData make_pbmsg(){ return ::proto_ff::GlobalComData(); }
	};
	typedef struct GlobalComData_s GlobalComData_t;

	struct ActDBProto_s : public NFDescStoreSeqOP {
		ActDBProto_s();
		virtual ~ActDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t actid;
		uint32_t zid;
		uint64_t finishtime;

		virtual void write_to_pbmsg(::proto_ff::ActDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ActDBProto & msg);
		static ::proto_ff::ActDBProto* new_pbmsg(){ return new ::proto_ff::ActDBProto(); }
		static ::proto_ff::ActDBProto make_pbmsg(){ return ::proto_ff::ActDBProto(); }
	};
	typedef struct ActDBProto_s ActDBProto_t;

	struct ActDBReq_s : public NFDescStoreSeqOP {
		ActDBReq_s();
		virtual ~ActDBReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::ActDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ActDBReq & msg);
		static ::proto_ff::ActDBReq* new_pbmsg(){ return new ::proto_ff::ActDBReq(); }
		static ::proto_ff::ActDBReq make_pbmsg(){ return ::proto_ff::ActDBReq(); }
	};
	typedef struct ActDBReq_s ActDBReq_t;

	struct ActDBRsp_s : public NFDescStoreSeqOP {
		ActDBRsp_s();
		virtual ~ActDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ActDBProto_s, DEFINE_ACTDBRSP_LST_MAX_NUM> lst;

		virtual void write_to_pbmsg(::proto_ff::ActDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ActDBRsp & msg);
		static ::proto_ff::ActDBRsp* new_pbmsg(){ return new ::proto_ff::ActDBRsp(); }
		static ::proto_ff::ActDBRsp make_pbmsg(){ return ::proto_ff::ActDBRsp(); }
	};
	typedef struct ActDBRsp_s ActDBRsp_t;

	struct ActSaveDBReq_s : public NFDescStoreSeqOP {
		ActSaveDBReq_s();
		virtual ~ActSaveDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ActDBProto_s, DEFINE_ACTSAVEDBREQ_LST_MAX_NUM> lst;

		virtual void write_to_pbmsg(::proto_ff::ActSaveDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ActSaveDBReq & msg);
		static ::proto_ff::ActSaveDBReq* new_pbmsg(){ return new ::proto_ff::ActSaveDBReq(); }
		static ::proto_ff::ActSaveDBReq make_pbmsg(){ return ::proto_ff::ActSaveDBReq(); }
	};
	typedef struct ActSaveDBReq_s ActSaveDBReq_t;

	struct AllArenaDBRequest_s : public NFDescStoreSeqOP {
		AllArenaDBRequest_s();
		virtual ~AllArenaDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t offset;
		int32_t retnum;

		virtual void write_to_pbmsg(::proto_ff::AllArenaDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AllArenaDBRequest & msg);
		static ::proto_ff::AllArenaDBRequest* new_pbmsg(){ return new ::proto_ff::AllArenaDBRequest(); }
		static ::proto_ff::AllArenaDBRequest make_pbmsg(){ return ::proto_ff::AllArenaDBRequest(); }
	};
	typedef struct AllArenaDBRequest_s AllArenaDBRequest_t;

	struct ArenaDBInfo_s : public NFDescStoreSeqOP {
		ArenaDBInfo_s();
		virtual ~ArenaDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charID;
		uint32_t rankId;

		virtual void write_to_pbmsg(::proto_ff::ArenaDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArenaDBInfo & msg);
		static ::proto_ff::ArenaDBInfo* new_pbmsg(){ return new ::proto_ff::ArenaDBInfo(); }
		static ::proto_ff::ArenaDBInfo make_pbmsg(){ return ::proto_ff::ArenaDBInfo(); }
	};
	typedef struct ArenaDBInfo_s ArenaDBInfo_t;

	struct ArenaMoreDBInfo_s : public NFDescStoreSeqOP {
		ArenaMoreDBInfo_s();
		virtual ~ArenaMoreDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ArenaDBInfo_s, DEFINE_ARENAMOREDBINFO_INFO_MAX_NUM> info;
		uint32_t day;
		uint32_t giveReward;
		uint32_t max_rank;

		virtual void write_to_pbmsg(::proto_ff::ArenaMoreDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ArenaMoreDBInfo & msg);
		static ::proto_ff::ArenaMoreDBInfo* new_pbmsg(){ return new ::proto_ff::ArenaMoreDBInfo(); }
		static ::proto_ff::ArenaMoreDBInfo make_pbmsg(){ return ::proto_ff::ArenaMoreDBInfo(); }
	};
	typedef struct ArenaMoreDBInfo_s ArenaMoreDBInfo_t;

	struct AllArenaDBResponse_s : public NFDescStoreSeqOP {
		AllArenaDBResponse_s();
		virtual ~AllArenaDBResponse_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t retcode;
		int32_t offset;
		NFShmVector<struct ArenaDBInfo_s, DEFINE_ALLARENADBRESPONSE_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::AllArenaDBResponse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AllArenaDBResponse & msg);
		static ::proto_ff::AllArenaDBResponse* new_pbmsg(){ return new ::proto_ff::AllArenaDBResponse(); }
		static ::proto_ff::AllArenaDBResponse make_pbmsg(){ return ::proto_ff::AllArenaDBResponse(); }
	};
	typedef struct AllArenaDBResponse_s AllArenaDBResponse_t;

	struct SaveArenaDBRequest_s : public NFDescStoreSeqOP {
		SaveArenaDBRequest_s();
		virtual ~SaveArenaDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ArenaDBInfo_s, DEFINE_SAVEARENADBREQUEST_INFO_MAX_NUM> info;

		virtual void write_to_pbmsg(::proto_ff::SaveArenaDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SaveArenaDBRequest & msg);
		static ::proto_ff::SaveArenaDBRequest* new_pbmsg(){ return new ::proto_ff::SaveArenaDBRequest(); }
		static ::proto_ff::SaveArenaDBRequest make_pbmsg(){ return ::proto_ff::SaveArenaDBRequest(); }
	};
	typedef struct SaveArenaDBRequest_s SaveArenaDBRequest_t;

	struct DeleteArenaDBRequest_s : public NFDescStoreSeqOP {
		DeleteArenaDBRequest_s();
		virtual ~DeleteArenaDBRequest_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t charId;

		virtual void write_to_pbmsg(::proto_ff::DeleteArenaDBRequest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DeleteArenaDBRequest & msg);
		static ::proto_ff::DeleteArenaDBRequest* new_pbmsg(){ return new ::proto_ff::DeleteArenaDBRequest(); }
		static ::proto_ff::DeleteArenaDBRequest make_pbmsg(){ return ::proto_ff::DeleteArenaDBRequest(); }
	};
	typedef struct DeleteArenaDBRequest_s DeleteArenaDBRequest_t;

	struct RoleMirrorDBReq_s : public NFDescStoreSeqOP {
		RoleMirrorDBReq_s();
		virtual ~RoleMirrorDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		int64_t int_param;
		NFShmString<32> str_param;
		uint32_t reqtype;

		virtual void write_to_pbmsg(::proto_ff::RoleMirrorDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleMirrorDBReq & msg);
		static ::proto_ff::RoleMirrorDBReq* new_pbmsg(){ return new ::proto_ff::RoleMirrorDBReq(); }
		static ::proto_ff::RoleMirrorDBReq make_pbmsg(){ return ::proto_ff::RoleMirrorDBReq(); }
	};
	typedef struct RoleMirrorDBReq_s RoleMirrorDBReq_t;

	struct RoleMirrorDBRsp_s : public NFDescStoreSeqOP {
		RoleMirrorDBRsp_s();
		virtual ~RoleMirrorDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;
		uint64_t cid;
		int64_t int_param;
		NFShmString<32> str_param;
		uint32_t reqtype;
		struct RoleMirrorData_s data;

		virtual void write_to_pbmsg(::proto_ff::RoleMirrorDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleMirrorDBRsp & msg);
		static ::proto_ff::RoleMirrorDBRsp* new_pbmsg(){ return new ::proto_ff::RoleMirrorDBRsp(); }
		static ::proto_ff::RoleMirrorDBRsp make_pbmsg(){ return ::proto_ff::RoleMirrorDBRsp(); }
	};
	typedef struct RoleMirrorDBRsp_s RoleMirrorDBRsp_t;

	struct FactionDataDBReq_s : public NFDescStoreSeqOP {
		FactionDataDBReq_s();
		virtual ~FactionDataDBReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::FactionDataDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDataDBReq & msg);
		static ::proto_ff::FactionDataDBReq* new_pbmsg(){ return new ::proto_ff::FactionDataDBReq(); }
		static ::proto_ff::FactionDataDBReq make_pbmsg(){ return ::proto_ff::FactionDataDBReq(); }
	};
	typedef struct FactionDataDBReq_s FactionDataDBReq_t;

	struct FactionDataDBRsp_s : public NFDescStoreSeqOP {
		FactionDataDBRsp_s();
		virtual ~FactionDataDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionAllDBData_s, DEFINE_FACTIONDATADBRSP_DATA_LST_MAX_NUM> data_lst;
		int32_t finish;

		virtual void write_to_pbmsg(::proto_ff::FactionDataDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDataDBRsp & msg);
		static ::proto_ff::FactionDataDBRsp* new_pbmsg(){ return new ::proto_ff::FactionDataDBRsp(); }
		static ::proto_ff::FactionDataDBRsp make_pbmsg(){ return ::proto_ff::FactionDataDBRsp(); }
	};
	typedef struct FactionDataDBRsp_s FactionDataDBRsp_t;

	struct FactionSaveDBReq_s : public NFDescStoreSeqOP {
		FactionSaveDBReq_s();
		virtual ~FactionSaveDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		struct FactionAllDBData_s data;

		virtual void write_to_pbmsg(::proto_ff::FactionSaveDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionSaveDBReq & msg);
		static ::proto_ff::FactionSaveDBReq* new_pbmsg(){ return new ::proto_ff::FactionSaveDBReq(); }
		static ::proto_ff::FactionSaveDBReq make_pbmsg(){ return ::proto_ff::FactionSaveDBReq(); }
	};
	typedef struct FactionSaveDBReq_s FactionSaveDBReq_t;

	struct FactionDelDBReq_s : public NFDescStoreSeqOP {
		FactionDelDBReq_s();
		virtual ~FactionDelDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;

		virtual void write_to_pbmsg(::proto_ff::FactionDelDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDelDBReq & msg);
		static ::proto_ff::FactionDelDBReq* new_pbmsg(){ return new ::proto_ff::FactionDelDBReq(); }
		static ::proto_ff::FactionDelDBReq make_pbmsg(){ return ::proto_ff::FactionDelDBReq(); }
	};
	typedef struct FactionDelDBReq_s FactionDelDBReq_t;

	struct FactionRedDBReq_s : public NFDescStoreSeqOP {
		FactionRedDBReq_s();
		virtual ~FactionRedDBReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::FactionRedDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionRedDBReq & msg);
		static ::proto_ff::FactionRedDBReq* new_pbmsg(){ return new ::proto_ff::FactionRedDBReq(); }
		static ::proto_ff::FactionRedDBReq make_pbmsg(){ return ::proto_ff::FactionRedDBReq(); }
	};
	typedef struct FactionRedDBReq_s FactionRedDBReq_t;

	struct FactionRedDBRsp_s : public NFDescStoreSeqOP {
		FactionRedDBRsp_s();
		virtual ~FactionRedDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RedDBData_s, DEFINE_FACTIONREDDBRSP_DATA_LST_MAX_NUM> data_lst;
		int32_t finish;

		virtual void write_to_pbmsg(::proto_ff::FactionRedDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionRedDBRsp & msg);
		static ::proto_ff::FactionRedDBRsp* new_pbmsg(){ return new ::proto_ff::FactionRedDBRsp(); }
		static ::proto_ff::FactionRedDBRsp make_pbmsg(){ return ::proto_ff::FactionRedDBRsp(); }
	};
	typedef struct FactionRedDBRsp_s FactionRedDBRsp_t;

	struct FactionRedSaveDBReq_s : public NFDescStoreSeqOP {
		FactionRedSaveDBReq_s();
		virtual ~FactionRedSaveDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;
		struct RedDBData_s data0;
		struct RedDBData_s data1;
		struct RedDBData_s data2;

		virtual void write_to_pbmsg(::proto_ff::FactionRedSaveDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionRedSaveDBReq & msg);
		static ::proto_ff::FactionRedSaveDBReq* new_pbmsg(){ return new ::proto_ff::FactionRedSaveDBReq(); }
		static ::proto_ff::FactionRedSaveDBReq make_pbmsg(){ return ::proto_ff::FactionRedSaveDBReq(); }
	};
	typedef struct FactionRedSaveDBReq_s FactionRedSaveDBReq_t;

	struct FactionRedDelDBReq_s : public NFDescStoreSeqOP {
		FactionRedDelDBReq_s();
		virtual ~FactionRedDelDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;

		virtual void write_to_pbmsg(::proto_ff::FactionRedDelDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionRedDelDBReq & msg);
		static ::proto_ff::FactionRedDelDBReq* new_pbmsg(){ return new ::proto_ff::FactionRedDelDBReq(); }
		static ::proto_ff::FactionRedDelDBReq make_pbmsg(){ return ::proto_ff::FactionRedDelDBReq(); }
	};
	typedef struct FactionRedDelDBReq_s FactionRedDelDBReq_t;

	struct RoleRedDBReq_s : public NFDescStoreSeqOP {
		RoleRedDBReq_s();
		virtual ~RoleRedDBReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::RoleRedDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleRedDBReq & msg);
		static ::proto_ff::RoleRedDBReq* new_pbmsg(){ return new ::proto_ff::RoleRedDBReq(); }
		static ::proto_ff::RoleRedDBReq make_pbmsg(){ return ::proto_ff::RoleRedDBReq(); }
	};
	typedef struct RoleRedDBReq_s RoleRedDBReq_t;

	struct RoleRedDBRsp_s : public NFDescStoreSeqOP {
		RoleRedDBRsp_s();
		virtual ~RoleRedDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RoleRedDBData_s, DEFINE_ROLEREDDBRSP_DATA_LST_MAX_NUM> data_lst;
		int32_t finish;

		virtual void write_to_pbmsg(::proto_ff::RoleRedDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleRedDBRsp & msg);
		static ::proto_ff::RoleRedDBRsp* new_pbmsg(){ return new ::proto_ff::RoleRedDBRsp(); }
		static ::proto_ff::RoleRedDBRsp make_pbmsg(){ return ::proto_ff::RoleRedDBRsp(); }
	};
	typedef struct RoleRedDBRsp_s RoleRedDBRsp_t;

	struct CenterLoadRoleDBReq_s : public NFDescStoreSeqOP {
		CenterLoadRoleDBReq_s();
		virtual ~CenterLoadRoleDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		NFShmString<32> table_name;
		uint32_t cmd;

		virtual void write_to_pbmsg(::proto_ff::CenterLoadRoleDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CenterLoadRoleDBReq & msg);
		static ::proto_ff::CenterLoadRoleDBReq* new_pbmsg(){ return new ::proto_ff::CenterLoadRoleDBReq(); }
		static ::proto_ff::CenterLoadRoleDBReq make_pbmsg(){ return ::proto_ff::CenterLoadRoleDBReq(); }
	};
	typedef struct CenterLoadRoleDBReq_s CenterLoadRoleDBReq_t;

	struct CenterLoadRoleDBRsp_s : public NFDescStoreSeqOP {
		CenterLoadRoleDBRsp_s();
		virtual ~CenterLoadRoleDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		NFShmString<32> data;

		virtual void write_to_pbmsg(::proto_ff::CenterLoadRoleDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CenterLoadRoleDBRsp & msg);
		static ::proto_ff::CenterLoadRoleDBRsp* new_pbmsg(){ return new ::proto_ff::CenterLoadRoleDBRsp(); }
		static ::proto_ff::CenterLoadRoleDBRsp make_pbmsg(){ return ::proto_ff::CenterLoadRoleDBRsp(); }
	};
	typedef struct CenterLoadRoleDBRsp_s CenterLoadRoleDBRsp_t;

	struct CenterSaveRoleDBReq_s : public NFDescStoreSeqOP {
		CenterSaveRoleDBReq_s();
		virtual ~CenterSaveRoleDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		NFShmString<32> data;
		NFShmString<32> table_name;

		virtual void write_to_pbmsg(::proto_ff::CenterSaveRoleDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CenterSaveRoleDBReq & msg);
		static ::proto_ff::CenterSaveRoleDBReq* new_pbmsg(){ return new ::proto_ff::CenterSaveRoleDBReq(); }
		static ::proto_ff::CenterSaveRoleDBReq make_pbmsg(){ return ::proto_ff::CenterSaveRoleDBReq(); }
	};
	typedef struct CenterSaveRoleDBReq_s CenterSaveRoleDBReq_t;

}

