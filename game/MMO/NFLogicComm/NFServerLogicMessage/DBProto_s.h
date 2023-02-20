#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProto.pb.h"
#include "DBProto_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

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
		NFShmVector<struct ItemProtoInfo_s, 1> data;
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
		NFShmVector<struct BagItemsDBData_s, 1> parts;

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
		NFShmVector<struct RoleDBUnitBagData_s, 1> bags;

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
		NFShmVector<struct EquipInfo_s, 1> infos;
		NFShmVector<struct EquipLvAttrInfo_s, 1> lv_attr;
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
		NFShmVector<struct GrowPartEntryDBInfo_s, 1> entrys;
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
		NFShmVector<struct GrowPartDBData_s, 1> parts;

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
		NFShmVector<struct ComPair64_s, 1> info;

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
		NFShmVector<struct ArenaChallResult_s, 1> result;
		NFShmVector<struct ChallArenaReward_s, 1> chall_reward;
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
		NFShmVector<struct FacadeFantasyData_s, 1> fantasy_map;
		NFShmVector<struct FacadeFragmentData_s, 1> fragment_map;
		NFShmVector<struct FacadeSkillData_s, 1> skill_data;
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
		NFShmVector<struct MountFantasyData_s, 1> fantasy_map;
		NFShmVector<struct MountFragmentData_s, 1> fragment_map;
		NFShmVector<struct MountSkillData_s, 1> skill_data;
		NFShmVector<struct MountKunData_s, 1> kun_data;
		NFShmVector<struct MountBloodData_s, 1> blood_data;
		NFShmVector<struct MountBabySlotData_s, 1> baby_slot_data;
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
		NFShmVector<struct DeityFantasyData_s, 1> fantasy_map;
		NFShmVector<struct DeityFragmentData_s, 1> fragment_map;
		NFShmVector<struct DeitySkillData_s, 1> skill_data;
		NFShmVector<struct DeityBattleSlotData_s, 1> battle_data;

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
		NFShmVector<struct FacadeDataInfo_s, 1> data;

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
		NFShmVector<struct SkillDBPos_s, 1> pos_lst;

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
		NFShmVector<struct SkillDBInfo_s, 1> info_lst;
		NFShmVector<struct SkillDBGroup_s, 1> group_lst;
		uint32_t group;
		uint64_t last_group;
		NFShmVector<struct SkillDBAdvPos_s, 1> adv_pos;
		NFShmVector<struct SkillDBAdvInfo_s, 1> adv_info;
		uint32_t cur_advpos;
		NFShmVector<struct PetSkillCdDB_s, 1> pet_cd;

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
		NFShmVector<struct GodRelicsTaskGroupEntry_s, 1> group_data;
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
		NFShmVector<struct DupTowerDBRecordEntry_s, 1> entrys;

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
		NFShmVector<uint64_t, 1> ids;

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
		NFShmVector<struct DupRecord_s, 1> record;
		NFShmVector<struct DupGroupData_s, 1> groups;
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
		NFShmVector<struct BuffDBInfo_s, 1> info_lst;
		NFShmVector<struct BuffDBCdInfo_s, 1> cd_lst;

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
		NFShmVector<struct BossSimpleInfoDB_s, 1> infos;
		uint64_t lastTime;
		NFShmVector<int64_t, 1> attents;

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
		NFShmVector<struct Attr64_s, 1> attr_lst;

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
		NFShmVector<struct ComPair64_s, 1> costItem;
		NFShmVector<struct ComPair64_s, 1> costPet;

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
		NFShmVector<int32_t, 1> fetter;
		NFShmVector<struct PetInfo_s, 1> pets;
		NFShmVector<struct PetHatchInfo_s, 1> hatchs;
		NFShmVector<struct PetDBRecord_s, 1> records;
		NFShmVector<int64_t, 1> cfgids;

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
		NFShmVector<struct MallDBInfo_s, 1> day;
		NFShmVector<struct MallDBInfo_s, 1> week;
		NFShmVector<struct MallDBInfo_s, 1> forever;

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
		NFShmVector<struct ArmorInfo_s, 1> infos;

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

		virtual void write_to_pbmsg(::proto_ff::AssistDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AssistDBData & msg);
		static ::proto_ff::AssistDBData* new_pbmsg(){ return new ::proto_ff::AssistDBData(); }
		static ::proto_ff::AssistDBData make_pbmsg(){ return ::proto_ff::AssistDBData(); }
	};
	typedef struct AssistDBData_s AssistDBData_t;

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

		virtual void write_to_pbmsg(::proto_ff::RoleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBData & msg);
		static ::proto_ff::RoleDBData* new_pbmsg(){ return new ::proto_ff::RoleDBData(); }
		static ::proto_ff::RoleDBData make_pbmsg(){ return ::proto_ff::RoleDBData(); }
	};
	typedef struct RoleDBData_s RoleDBData_t;

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
		NFShmVector<struct FactionMemDBProto_s, 1> mem_lst;

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
		NFShmVector<struct FactionApplyDBProto_s, 1> apply_lst;

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
		NFShmVector<struct FactionRecordDBProto_s, 1> record_lst;

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
		NFShmVector<struct RoleListDBProto_s, 1> role_lst;
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
		NFShmVector<struct CenterRoleProto_s, 1> info;
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
		NFShmVector<struct MailInfo_s, 1> data;
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
		NFShmVector<uint32_t, 1> mid_lst;
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
		NFShmVector<struct MailInfo_s, 1> info;
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
		NFShmVector<struct MailInfo_s, 1> data;

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
		NFShmVector<uint32_t, 1> id_lst;
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
		NFShmVector<uint32_t, 1> id_lst;
		NFShmVector<struct WebMailDataProto_s, 1> info_lst;
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
		NFShmVector<uint64_t, 1> dstid_lst;
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
		NFShmVector<struct FriendDBInfo_s, 1> info_lst;
		NFShmVector<uint64_t, 1> last_lst;
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
		NFShmVector<struct FriendDBInfo_s, 1> info;

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
		NFShmVector<struct FriendDBInfo_s, 1> info;

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
		NFShmVector<struct GlobalDBEntry_s, 1> entry;
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
		NFShmVector<struct DupTowerDBRecord_s, 1> towerDupReward;

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
		NFShmVector<struct ActDBProto_s, 1> lst;

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
		NFShmVector<struct ActDBProto_s, 1> lst;

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
		NFShmVector<struct ArenaDBInfo_s, 1> info;
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
		NFShmVector<struct ArenaDBInfo_s, 1> info;

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
		NFShmVector<struct ArenaDBInfo_s, 1> info;

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
		NFShmVector<struct FactionAllDBData_s, 1> data_lst;
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

}

