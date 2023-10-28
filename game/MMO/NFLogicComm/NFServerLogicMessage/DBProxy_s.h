#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProxy.pb.h"
#include "DBProxy_s.h"
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
#define DEFINE_MINIDBDATA_USE_ITEM_ADD_ATTR_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_FACADEDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_KUN_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_BLOOD_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_BABY_SLOT_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_KUN_CHANGE_DATA_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FAIRY_LAND_MAX_NUM 1
#define DEFINE_MOUNTDATAINFO_FAIRY_SLOT_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_FANTASY_MAP_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_FRAGMENT_MAP_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_SKILL_DATA_MAX_NUM 1
#define DEFINE_DEITYDATAINFO_BATTLE_DATA_MAX_NUM 1
#define DEFINE_FACADEDBDATA_DATA_MAX_NUM 1
#define DEFINE_SKILLDBGROUP_POS_LST_MAX_NUM 1
#define DEFINE_SKILLDBTALENT_INFO_MAX_NUM 1
#define DEFINE_SKILLDBDATA_INFO_LST_MAX_NUM 1
#define DEFINE_SKILLDBDATA_GROUP_LST_MAX_NUM 1
#define DEFINE_SKILLDBDATA_ADV_POS_MAX_NUM 1
#define DEFINE_SKILLDBDATA_ADV_INFO_MAX_NUM 1
#define DEFINE_SKILLDBDATA_PET_CD_MAX_NUM 1
#define DEFINE_GODRELICSACTIVITYDATA_GROUP_DATA_MAX_NUM 1
#define DEFINE_DUPTOWERDBRECORD_ENTRYS_MAX_NUM 1
#define DEFINE_DUPTOWERDBDATA_IDS_MAX_NUM 1
#define DEFINE_GHOSTDBDATA_RECV_IDS_MAX_NUM 1
#define DEFINE_MOYUDBDATA_RECV_LAYER_MAX_NUM 1
#define DEFINE_YAOTADBDATA_PASS_IDS_MAX_NUM 1
#define DEFINE_YAOTADBDATA_FIRST_PASS_IDS_MAX_NUM 1
#define DEFINE_DUPDBDATA_RECORD_MAX_NUM 1
#define DEFINE_DUPDBDATA_GROUPS_MAX_NUM 1
#define DEFINE_GHOSTDUPRANKDB_RANKS_MAX_NUM 1
#define DEFINE_BUFFDBDATA_INFO_LST_MAX_NUM 1
#define DEFINE_BUFFDBDATA_CD_LST_MAX_NUM 1
#define DEFINE_BOSSSIMPLEINFODB_GROUPINFO_MAX_NUM 1
#define DEFINE_BOSSDBDATA_INFOS_MAX_NUM 1
#define DEFINE_BOSSDBDATA_ATTENTS_MAX_NUM 1
#define DEFINE_VIPDBDATA_PRIVILEGE_IDS_MAX_NUM 1
#define DEFINE_VIPDBDATA_LV_GIFT_MAX_NUM 1
#define DEFINE_ATTRDBDATA_ATTR_LST_MAX_NUM 1
#define DEFINE_PETDBRECORD_COSTITEM_MAX_NUM 1
#define DEFINE_PETDBRECORD_COSTPET_MAX_NUM 1
#define DEFINE_PETDBDATA_FETTER_MAX_NUM 1
#define DEFINE_PETDBDATA_PETS_MAX_NUM 1
#define DEFINE_PETDBDATA_HATCHS_MAX_NUM 1
#define DEFINE_PETDBDATA_RECORDS_MAX_NUM 1
#define DEFINE_PETDBDATA_CFGIDS_MAX_NUM 1
#define DEFINE_PETDBDATA_GROWS_MAX_NUM 1
#define DEFINE_MALLDBDATA_DAY_MAX_NUM 1
#define DEFINE_MALLDBDATA_WEEK_MAX_NUM 1
#define DEFINE_MALLDBDATA_FOREVER_MAX_NUM 1
#define DEFINE_ARMORDBDATA_INFOS_MAX_NUM 1
#define DEFINE_ASSISTDBDATA_REWARDIDS_MAX_NUM 1
#define DEFINE_ASSISTDBDATA_THANKSINFO_MAX_NUM 1
#define DEFINE_TITLEDBDATA_DATA_MAX_NUM 1
#define DEFINE_GODEVILMULTCONDDBPROTO_LST_MAX_NUM 1
#define DEFINE_GODEVILDBDATA_EQUIP_MAX_NUM 1
#define DEFINE_GODEVILDBDATA_DRESS_MAX_NUM 1
#define DEFINE_PAYDBDATA_DB_ID_MAX_NUM 1
#define DEFINE_PAYDBDATA_PRODUCT_MAX_NUM 1
#define DEFINE_FACTIONDBSKILL_INFO_MAX_NUM 1
#define DEFINE_ROLEFACTIONDBDATA_SALARY_MAX_NUM 1
#define DEFINE_ROLEBESTEQDBDATA_SLOTS_MAX_NUM 1
#define DEFINE_ROLEBESTEQDBDATA_TASKS_MAX_NUM 1
#define DEFINE_ANCIENTDBDATA_INFOS_MAX_NUM 1
#define DEFINE_ROLE1V1DBINFO_ALREADY_FETCH_MAX_NUM 1
#define DEFINE_ROLEPVPDBDATA_EMBLEM_MAX_NUM 1
#define DEFINE_ROLEMARRYDBDATA_TOSLEF_MAX_NUM 1
#define DEFINE_ROLEMARRYDBDATA_TOOTHER_MAX_NUM 1
#define DEFINE_GVBPDATA_REWARDS_STATE_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_FIRST_FETCH_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_DIA_FETCH_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_STAR_FETCH_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_KING_FETCH_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_SECOND_FETCH_MAX_NUM 1
#define DEFINE_CHARGEDBDATA_OPEN_TOTAL_FETCH_MAX_NUM 1
#define DEFINE_GIFTDBDATA_COND_MAX_NUM 1
#define DEFINE_GIFTDBDATA_ZERO_MAX_NUM 1
#define DEFINE_GIFTDBDATA_ZERO_LOG_MAX_NUM 1
#define DEFINE_FESTSHOPDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTGOLDSTOREDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTDIGEGGDBPROTO_ID_LST_MAX_NUM 1
#define DEFINE_FESTDIGEGGDBPROTO_TASK_MAX_NUM 1
#define DEFINE_FESTCANDLEDBPROTO_ID_LST_MAX_NUM 1
#define DEFINE_FESTRTURNABLERECHARGEDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTDAILYTOTALRECHARGEDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTTURNABLEDBPROTO_TASK_MAX_NUM 1
#define DEFINE_FESTTURNABLEDBPROTO_CHOU_JIANG_IDS_MAX_NUM 1
#define DEFINE_FESTDONATEDBPROTO_SINGLE_MAX_NUM 1
#define DEFINE_FESTDONATEDBPROTO_SERVER_MAX_NUM 1
#define DEFINE_FESTDONATEDBPROTO_TASK_MAX_NUM 1
#define DEFINE_FESTONLINEDBPROTO_DATA_MAX_NUM 1
#define DEFINE_FESTCOLLECTWORDDBPROTO_DATA_MAX_NUM 1
#define DEFINE_FESTBOSSFIRSTDB_RECV_KILL_IDS_MAX_NUM 1
#define DEFINE_FESTBOSSFIRSTDB_RECV_RED_IDS_MAX_NUM 1
#define DEFINE_FESTBOSSFIRSTDB_M_KILLS_IDS_MAX_NUM 1
#define DEFINE_FMARRYROLEDB_TASKS_MAX_NUM 1
#define DEFINE_FMARRYROLEDB_PROCESS_IDS_MAX_NUM 1
#define DEFINE_DAYTOTALRECHARGEDBPROTO_FETCH_LST_MAX_NUM 1
#define DEFINE_TOTALRECHARGEDBPROTO_FETCH_LST_MAX_NUM 1
#define DEFINE_LOGINREWARDDBPROTO_FETCH_MAX_NUM 1
#define DEFINE_FESTDBDATA_INFO_MAX_NUM 1
#define DEFINE_FESTDBDATA_CLOSE_MAX_NUM 1
#define DEFINE_SHADOWDBPROTO_FRAG_MAX_NUM 1
#define DEFINE_HALODBPROTO_INFO_MAX_NUM 1
#define DEFINE_ROLEDBTURNDATA_ENTRYS_MAX_NUM 1
#define DEFINE_ROLEDBTURNDATA_HELPER_MAX_NUM 1
#define DEFINE_ROLEDBTURNDATA_TASKS_MAX_NUM 1
#define DEFINE_SOULDBDATA_TASKS_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_SEND_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_WAIT_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBDATA_TRIGGER_LST_MAX_NUM 1
#define DEFINE_REDFETCHLISTDBPROTO_INFO_MAX_NUM 1
#define DEFINE_REDDBDATA_WAIT_MAX_NUM 1
#define DEFINE_REDDBDATA_TRIGGER_LST_MAX_NUM 1
#define DEFINE_REDDBDATA_SEND_MAX_NUM 1
#define DEFINE_ROLEMIRRORDATA_BEAST_EQUIPS_MAX_NUM 1
#define DEFINE_ROLEMIRRORDATA_BEAST_SLOTS_MAX_NUM 1
#define DEFINE_FACTIONMULTMEMDBPROTO_MEM_LST_MAX_NUM 1
#define DEFINE_FACTIONMULTAPPLYDBPROTO_APPLY_LST_MAX_NUM 1
#define DEFINE_FACTIONMUTRECORDDBPROTO_RECORD_LST_MAX_NUM 1
#define DEFINE_FACTIONBEASTDBDATA_HARM_MAX_NUM 1
#define DEFINE_FACTIONGUARDDBDATA_HARM_MAX_NUM 1
#define DEFINE_FACTIONGUARDDBDATA_OLD_HARM_MAX_NUM 1
#define DEFINE_FACTIONDBMOYURANK_RANK_MAX_NUM 1
#define DEFINE_FACTIONDBMOYURANKDB_INFOS_MAX_NUM 1
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
#define DEFINE_GLOBALYAOTADUPDBENTRY_INFO_MAX_NUM 1
#define DEFINE_GLOBALYAOTADUPDBDATA_ENTRYS_MAX_NUM 1
#define DEFINE_ACTDBRSP_LST_MAX_NUM 1
#define DEFINE_ACTSAVEDBREQ_LST_MAX_NUM 1
#define DEFINE_ARENAMOREDBINFO_INFO_MAX_NUM 1
#define DEFINE_ALLARENADBRESPONSE_INFO_MAX_NUM 1
#define DEFINE_SAVEARENADBREQUEST_INFO_MAX_NUM 1
#define DEFINE_FACTIONDATADBRSP_DATA_LST_MAX_NUM 1
#define DEFINE_FACTIONREDDBRSP_DATA_LST_MAX_NUM 1
#define DEFINE_ROLEREDDBRSP_DATA_LST_MAX_NUM 1
#define DEFINE_COMLOADALLDBRSP_DATA_MAX_NUM 1
#define DEFINE_COMDELDBREQ_ID_LST_MAX_NUM 1
#define DEFINE_MARRYDBLOADRSP_SIMPLE_MAX_NUM 1
#define DEFINE_ANSWERDBDATA_RANK_MAX_NUM 1
#define DEFINE_GUARDDBDATA_OLD_RANK_MAX_NUM 1
#define DEFINE_GUARDDBDATA_CUR_RANK_MAX_NUM 1
#define DEFINE_ACT1V1DBDATA_RANK_MAX_NUM 1
#define DEFINE_RACEDBPROTO_INFO_LST_MAX_NUM 1
#define DEFINE_FACTIONWARDBDATA_RACE_MAX_NUM 1
#define DEFINE_FACTIONWARDBDATA_RANK_MAX_NUM 1
#define DEFINE_FESTDIGEGGLOGDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTDIGEGGLOGDBDATA_LOG_MAX_NUM 1
#define DEFINE_FESTRTURNABLELOGDBDATA_LOG_MAX_NUM 1
#define DEFINE_FESTDONATEDBDATA_DATA_MAX_NUM 1
#define DEFINE_FESTDRAWPIZELOGDBDATA_LOG_MAX_NUM 1
#define DEFINE_MARKETDBLOADRSP_INFOS_MAX_NUM 1
#define DEFINE_CANDLEDBDATA_HAM_MAX_NUM 1


namespace proto_ff_s {

	struct RoleReliveProto_s : public NFDescStoreSeqOP {
		RoleReliveProto_s();
		virtual ~RoleReliveProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t tired_time;//
		int32_t relive_num;//
		int32_t is_tired;//
		uint64_t mapid;//
		int32_t map_relive_num;//

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
		NFShmString<32> name;//
		uint32_t prof;//
		uint32_t level;//
		int64_t exp;//
		int64_t hp;//
		int64_t fight;//
		uint64_t createTime;//
		uint64_t loginTime;//
		uint64_t logoutTime;//
		uint64_t enter_scene_id;//
		uint64_t enter_map_id;//
		float enterposx;//
		float enterposy;//
		float enterposz;//
		uint64_t lastsceneid;//
		uint64_t lastmapid;//
		float lastposx;//
		float lastposy;//
		float lastposz;//
		struct RoleFacadeProto_s facade;//
		uint32_t vip_level;//
		int32_t state;//
		uint64_t hanguptime;//
		struct RoleReliveProto_s relive;//
		int64_t gold;//
		int64_t dia;//
		int64_t bdia;//
		int64_t magic;//
		int64_t prestige;//
		int32_t contri;//
		int64_t arenacoin;//
		int64_t godevil_exp;//
		int32_t godevil_level;//
		uint32_t login_day;//
		uint64_t login_day_time;//
		int64_t best_aq;//
		int64_t best_lj;//
		uint32_t day_prestige;//
		uint64_t prestige_time;//
		uint32_t pt_stage;//
		NFShmString<32> guide;//
		int64_t battlepass_xiance;//
		int64_t battlepass_baoding;//
		int64_t findtreasure_shengfu;//
		int64_t findtreasure_battlesoul;//
		int64_t holybeast_build;//
		int64_t magic_sum;//
		int32_t subpack_type;//
		int32_t subpack_fetch;//
		uint64_t hunling;//

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
		NFShmVector<struct ItemProtoInfo_s, DEFINE_BAGITEMSDBDATA_DATA_MAX_NUM> data;//
		int32_t offset;//

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
		uint32_t package_type;//
		uint32_t expand_num;//

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
		NFShmString<32> table_name;//
		struct BagDBSimpleData_s simple;//
		NFShmVector<struct BagItemsDBData_s, DEFINE_ROLEDBUNITBAGDATA_PARTS_MAX_NUM> parts;//

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
		NFShmVector<struct RoleDBUnitBagData_s, DEFINE_ROLEDBBAGDATA_BAGS_MAX_NUM> bags;//

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
		NFShmVector<struct EquipInfo_s, DEFINE_ROLEDBEQUIPDATA_INFOS_MAX_NUM> infos;//
		NFShmVector<struct EquipLvAttrInfo_s, DEFINE_ROLEDBEQUIPDATA_LV_ATTR_MAX_NUM> lv_attr;//
		uint32_t stove_level;//
		uint64_t stove_exp;//

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
		int64_t id;//
		int32_t lv;//
		int64_t time;//

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
		int32_t type;//
		NFShmVector<struct GrowPartEntryDBInfo_s, DEFINE_GROWPARTDBDATA_ENTRYS_MAX_NUM> entrys;//
		int64_t curId;//

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
		NFShmVector<struct GrowPartDBData_s, DEFINE_GROWDBDATA_PARTS_MAX_NUM> parts;//

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
		NFShmVector<struct ComPair64_s, DEFINE_DAYUSEITEMDATA_INFO_MAX_NUM> info;//

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
		uint32_t challengeTimes;//
		uint64_t updateTime;//
		uint32_t historyRankId;//
		uint32_t buyChallengeTimes;//
		NFShmVector<struct ArenaChallResult_s, DEFINE_CHARACTERARENADATA_RESULT_MAX_NUM> result;//
		NFShmVector<struct ChallArenaReward_s, DEFINE_CHARACTERARENADATA_CHALL_REWARD_MAX_NUM> chall_reward;//
		int32_t allChallengeTimes;//
		int32_t rank_id;//

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
		uint64_t lastTime;//
		struct DayUseItemData_s useItem;//
		struct CharacterArenaData_s arena_data;//
		NFShmVector<struct ComPair64_s, DEFINE_MINIDBDATA_USE_ITEM_ADD_ATTR_MAX_NUM> use_item_add_attr;//

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
		uint32_t facade_type;//
		uint64_t facade_id;//
		uint32_t facade_lev;//
		uint64_t facade_exp;//
		bool use_soul_item;//
		bool use_facade;//
		uint64_t equip_fantasy_id;//
		NFShmVector<struct FacadeFantasyData_s, DEFINE_FACADEDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;//
		NFShmVector<struct FacadeFragmentData_s, DEFINE_FACADEDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;//
		NFShmVector<struct FacadeSkillData_s, DEFINE_FACADEDATAINFO_SKILL_DATA_MAX_NUM> skill_data;//
		struct FacadeSoulData_s soul_data;//

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
		uint64_t mount_id;//
		uint32_t mount_lev;//
		uint64_t mount_exp;//
		bool use_facade;//
		uint64_t equip_fantasy_id;//
		NFShmVector<struct MountFantasyData_s, DEFINE_MOUNTDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;//
		NFShmVector<struct MountFragmentData_s, DEFINE_MOUNTDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;//
		NFShmVector<struct MountSkillData_s, DEFINE_MOUNTDATAINFO_SKILL_DATA_MAX_NUM> skill_data;//
		NFShmVector<struct MountKunData_s, DEFINE_MOUNTDATAINFO_KUN_DATA_MAX_NUM> kun_data;//
		NFShmVector<struct MountBloodData_s, DEFINE_MOUNTDATAINFO_BLOOD_DATA_MAX_NUM> blood_data;//
		NFShmVector<struct MountBabySlotData_s, DEFINE_MOUNTDATAINFO_BABY_SLOT_DATA_MAX_NUM> baby_slot_data;//
		uint32_t ride_state;//
		uint64_t mount_model_id;//
		uint64_t last_mount_model_id;//
		NFShmVector<struct MountKunChangeData_s, DEFINE_MOUNTDATAINFO_KUN_CHANGE_DATA_MAX_NUM> kun_change_data;//
		uint64_t equip_kun_id;//
		uint64_t equip_kun_change_id;//
		NFShmVector<struct MountFairyLand_s, DEFINE_MOUNTDATAINFO_FAIRY_LAND_MAX_NUM> fairy_land;//
		NFShmVector<struct MountFairySlot_s, DEFINE_MOUNTDATAINFO_FAIRY_SLOT_MAX_NUM> fairy_slot;//
		uint64_t cur_fairy_land;//

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
		uint64_t deity_id;//
		uint32_t deity_lev;//
		uint64_t deity_exp;//
		NFShmVector<struct DeityFantasyData_s, DEFINE_DEITYDATAINFO_FANTASY_MAP_MAX_NUM> fantasy_map;//
		NFShmVector<struct DeityFragmentData_s, DEFINE_DEITYDATAINFO_FRAGMENT_MAP_MAX_NUM> fragment_map;//
		NFShmVector<struct DeitySkillData_s, DEFINE_DEITYDATAINFO_SKILL_DATA_MAX_NUM> skill_data;//
		NFShmVector<struct DeityBattleSlotData_s, DEFINE_DEITYDATAINFO_BATTLE_DATA_MAX_NUM> battle_data;//

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
		NFShmVector<struct FacadeDataInfo_s, DEFINE_FACADEDBDATA_DATA_MAX_NUM> data;//

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
		uint64_t skill_id;//
		int32_t level;//
		int32_t wakeup;//
		int64_t use_msc;//

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
		uint64_t skill_id;//
		uint32_t pos;//
		int32_t use;//

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
		uint32_t pos;//
		uint32_t advance;//
		uint32_t unlock;//

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
		int32_t advance;//
		int32_t level;//

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
		uint32_t group;//
		int32_t chg;//
		NFShmVector<struct SkillDBPos_s, DEFINE_SKILLDBGROUP_POS_LST_MAX_NUM> pos_lst;//

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
		uint64_t skill_id;//
		uint64_t use_msec;//
		int64_t pet_instid;//

		virtual void write_to_pbmsg(::proto_ff::PetSkillCdDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetSkillCdDB & msg);
		static ::proto_ff::PetSkillCdDB* new_pbmsg(){ return new ::proto_ff::PetSkillCdDB(); }
		static ::proto_ff::PetSkillCdDB make_pbmsg(){ return ::proto_ff::PetSkillCdDB(); }
	};
	typedef struct PetSkillCdDB_s PetSkillCdDB_t;

	struct SkillDBTalentProto_s : public NFDescStoreSeqOP {
		SkillDBTalentProto_s();
		virtual ~SkillDBTalentProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t level;//

		virtual void write_to_pbmsg(::proto_ff::SkillDBTalentProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBTalentProto & msg);
		static ::proto_ff::SkillDBTalentProto* new_pbmsg(){ return new ::proto_ff::SkillDBTalentProto(); }
		static ::proto_ff::SkillDBTalentProto make_pbmsg(){ return ::proto_ff::SkillDBTalentProto(); }
	};
	typedef struct SkillDBTalentProto_s SkillDBTalentProto_t;

	struct SkillDBTalent_s : public NFDescStoreSeqOP {
		SkillDBTalent_s();
		virtual ~SkillDBTalent_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct SkillDBTalentProto_s, DEFINE_SKILLDBTALENT_INFO_MAX_NUM> info;//
		uint32_t cnt;//

		virtual void write_to_pbmsg(::proto_ff::SkillDBTalent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SkillDBTalent & msg);
		static ::proto_ff::SkillDBTalent* new_pbmsg(){ return new ::proto_ff::SkillDBTalent(); }
		static ::proto_ff::SkillDBTalent make_pbmsg(){ return ::proto_ff::SkillDBTalent(); }
	};
	typedef struct SkillDBTalent_s SkillDBTalent_t;

	struct SkillDBData_s : public NFDescStoreSeqOP {
		SkillDBData_s();
		virtual ~SkillDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct SkillDBInfo_s, DEFINE_SKILLDBDATA_INFO_LST_MAX_NUM> info_lst;//
		NFShmVector<struct SkillDBGroup_s, DEFINE_SKILLDBDATA_GROUP_LST_MAX_NUM> group_lst;//
		uint32_t group;//
		uint64_t last_group;//
		NFShmVector<struct SkillDBAdvPos_s, DEFINE_SKILLDBDATA_ADV_POS_MAX_NUM> adv_pos;//
		NFShmVector<struct SkillDBAdvInfo_s, DEFINE_SKILLDBDATA_ADV_INFO_MAX_NUM> adv_info;//
		uint32_t cur_advpos;//
		NFShmVector<struct PetSkillCdDB_s, DEFINE_SKILLDBDATA_PET_CD_MAX_NUM> pet_cd;//
		struct SkillDBTalent_s talent;//
		uint32_t anger_value;//

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
		NFShmVector<struct GodRelicsTaskGroupEntry_s, DEFINE_GODRELICSACTIVITYDATA_GROUP_DATA_MAX_NUM> group_data;//
		int64_t cur_group_id;//

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
		struct GodRelicsActivityData_s god_relics_data;//
		struct DailyTaskAllData_s daily_data;//

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
		uint64_t dupId;//
		int32_t star;//

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
		int32_t group;//
		int32_t enterNum;//
		int32_t buyNum;//
		int32_t useNum;//
		uint64_t lastFresh;//

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
		NFShmString<32> name;//
		uint64_t time;//
		uint64_t cid;//

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
		uint64_t id;//
		NFShmVector<struct DupTowerDBRecordEntry_s, DEFINE_DUPTOWERDBRECORD_ENTRYS_MAX_NUM> entrys;//

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
		NFShmVector<uint64_t, DEFINE_DUPTOWERDBDATA_IDS_MAX_NUM> ids;//

		virtual void write_to_pbmsg(::proto_ff::DupTowerDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupTowerDBData & msg);
		static ::proto_ff::DupTowerDBData* new_pbmsg(){ return new ::proto_ff::DupTowerDBData(); }
		static ::proto_ff::DupTowerDBData make_pbmsg(){ return ::proto_ff::DupTowerDBData(); }
	};
	typedef struct DupTowerDBData_s DupTowerDBData_t;

	struct GhostDBData_s : public NFDescStoreSeqOP {
		GhostDBData_s();
		virtual ~GhostDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t wave;//
		int32_t time;//
		NFShmVector<int32_t, DEFINE_GHOSTDBDATA_RECV_IDS_MAX_NUM> recv_ids;//

		virtual void write_to_pbmsg(::proto_ff::GhostDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GhostDBData & msg);
		static ::proto_ff::GhostDBData* new_pbmsg(){ return new ::proto_ff::GhostDBData(); }
		static ::proto_ff::GhostDBData make_pbmsg(){ return ::proto_ff::GhostDBData(); }
	};
	typedef struct GhostDBData_s GhostDBData_t;

	struct MoyuDBData_s : public NFDescStoreSeqOP {
		MoyuDBData_s();
		virtual ~MoyuDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_MOYUDBDATA_RECV_LAYER_MAX_NUM> recv_layer;//
		uint64_t day_harm;//
		uint64_t week_harm;//
		uint64_t last_day_harm;//
		uint64_t last_week_harm;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::MoyuDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MoyuDBData & msg);
		static ::proto_ff::MoyuDBData* new_pbmsg(){ return new ::proto_ff::MoyuDBData(); }
		static ::proto_ff::MoyuDBData make_pbmsg(){ return ::proto_ff::MoyuDBData(); }
	};
	typedef struct MoyuDBData_s MoyuDBData_t;

	struct YaoTaDBData_s : public NFDescStoreSeqOP {
		YaoTaDBData_s();
		virtual ~YaoTaDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_YAOTADBDATA_PASS_IDS_MAX_NUM> pass_ids;//
		NFShmVector<int32_t, DEFINE_YAOTADBDATA_FIRST_PASS_IDS_MAX_NUM> first_pass_ids;//
		uint64_t pass_time_point;//
		int32_t pass_duration;//

		virtual void write_to_pbmsg(::proto_ff::YaoTaDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::YaoTaDBData & msg);
		static ::proto_ff::YaoTaDBData* new_pbmsg(){ return new ::proto_ff::YaoTaDBData(); }
		static ::proto_ff::YaoTaDBData make_pbmsg(){ return ::proto_ff::YaoTaDBData(); }
	};
	typedef struct YaoTaDBData_s YaoTaDBData_t;

	struct DupDBData_s : public NFDescStoreSeqOP {
		DupDBData_s();
		virtual ~DupDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DupRecord_s, DEFINE_DUPDBDATA_RECORD_MAX_NUM> record;//
		NFShmVector<struct DupGroupData_s, DEFINE_DUPDBDATA_GROUPS_MAX_NUM> groups;//
		struct DupTowerDBData_s tower;//
		struct GhostDBData_s ghost;//
		struct MoyuDBData_s moyu;//
		struct YaoTaDBData_s yaota;//

		virtual void write_to_pbmsg(::proto_ff::DupDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DupDBData & msg);
		static ::proto_ff::DupDBData* new_pbmsg(){ return new ::proto_ff::DupDBData(); }
		static ::proto_ff::DupDBData make_pbmsg(){ return ::proto_ff::DupDBData(); }
	};
	typedef struct DupDBData_s DupDBData_t;

	struct GhostDupRankDB_s : public NFDescStoreSeqOP {
		GhostDupRankDB_s();
		virtual ~GhostDupRankDB_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GHostDupRankInfo_s, DEFINE_GHOSTDUPRANKDB_RANKS_MAX_NUM> ranks;//

		virtual void write_to_pbmsg(::proto_ff::GhostDupRankDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GhostDupRankDB & msg);
		static ::proto_ff::GhostDupRankDB* new_pbmsg(){ return new ::proto_ff::GhostDupRankDB(); }
		static ::proto_ff::GhostDupRankDB make_pbmsg(){ return ::proto_ff::GhostDupRankDB(); }
	};
	typedef struct GhostDupRankDB_s GhostDupRankDB_t;

	struct BuffDBInfo_s : public NFDescStoreSeqOP {
		BuffDBInfo_s();
		virtual ~BuffDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t buffid;//
		uint64_t index;//
		uint64_t skillid;//
		uint32_t skilllev;//
		bool is_forever;//
		int64_t startmsec;//
		bool is_effect;//
		int64_t param1;//
		int64_t param2;//
		int64_t extramsec;//
		int32_t is_end;//
		int64_t param3;//
		int64_t param4;//
		int64_t param5;//
		int64_t param6;//
		int64_t param7;//

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
		uint64_t buffid;//
		uint64_t lastmsec;//

		virtual void write_to_pbmsg(::proto_ff::BuffDBCdInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffDBCdInfo & msg);
		static ::proto_ff::BuffDBCdInfo* new_pbmsg(){ return new ::proto_ff::BuffDBCdInfo(); }
		static ::proto_ff::BuffDBCdInfo make_pbmsg(){ return ::proto_ff::BuffDBCdInfo(); }
	};
	typedef struct BuffDBCdInfo_s BuffDBCdInfo_t;

	struct BuffDBShieldInfo_s : public NFDescStoreSeqOP {
		BuffDBShieldInfo_s();
		virtual ~BuffDBShieldInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t god_shield;//
		int64_t mag_shield;//

		virtual void write_to_pbmsg(::proto_ff::BuffDBShieldInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuffDBShieldInfo & msg);
		static ::proto_ff::BuffDBShieldInfo* new_pbmsg(){ return new ::proto_ff::BuffDBShieldInfo(); }
		static ::proto_ff::BuffDBShieldInfo make_pbmsg(){ return ::proto_ff::BuffDBShieldInfo(); }
	};
	typedef struct BuffDBShieldInfo_s BuffDBShieldInfo_t;

	struct BuffDBData_s : public NFDescStoreSeqOP {
		BuffDBData_s();
		virtual ~BuffDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct BuffDBInfo_s, DEFINE_BUFFDBDATA_INFO_LST_MAX_NUM> info_lst;//
		NFShmVector<struct BuffDBCdInfo_s, DEFINE_BUFFDBDATA_CD_LST_MAX_NUM> cd_lst;//
		struct BuffDBShieldInfo_s shield;//

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
		int32_t boss_type;//
		int32_t cur_num;//
		int32_t back_num;//
		int32_t back_max_num;//
		int32_t enter_num;//
		int32_t use_item_num;//
		NFShmVector<struct ComPair_s, DEFINE_BOSSSIMPLEINFODB_GROUPINFO_MAX_NUM> groupInfo;//

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
		NFShmVector<struct BossSimpleInfoDB_s, DEFINE_BOSSDBDATA_INFOS_MAX_NUM> infos;//
		uint64_t lastTime;//
		NFShmVector<int64_t, DEFINE_BOSSDBDATA_ATTENTS_MAX_NUM> attents;//

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
		int32_t vipExp;//
		int32_t expDiamond;//
		NFShmVector<int32_t, DEFINE_VIPDBDATA_PRIVILEGE_IDS_MAX_NUM> privilege_ids;//
		int32_t vip_hide;//
		int32_t active_type;//
		uint64_t outtime;//
		uint64_t last_recv_day_gift_time;//
		NFShmVector<int32_t, DEFINE_VIPDBDATA_LV_GIFT_MAX_NUM> lv_gift;//
		int32_t zero_state;//
		int32_t recv_zero;//
		uint64_t add_exp;//
		int32_t recv_exp;//
		uint64_t refresh_time;//
		uint64_t active_time;//

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
		NFShmVector<struct Attr64_s, DEFINE_ATTRDBDATA_ATTR_LST_MAX_NUM> attr_lst;//

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
		int32_t instId;//
		NFShmVector<struct ComPair64_s, DEFINE_PETDBRECORD_COSTITEM_MAX_NUM> costItem;//
		NFShmVector<struct ComPair64_s, DEFINE_PETDBRECORD_COSTPET_MAX_NUM> costPet;//

		virtual void write_to_pbmsg(::proto_ff::PetDBRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetDBRecord & msg);
		static ::proto_ff::PetDBRecord* new_pbmsg(){ return new ::proto_ff::PetDBRecord(); }
		static ::proto_ff::PetDBRecord make_pbmsg(){ return ::proto_ff::PetDBRecord(); }
	};
	typedef struct PetDBRecord_s PetDBRecord_t;

	struct PetGrowDB_s : public NFDescStoreSeqOP {
		PetGrowDB_s();
		virtual ~PetGrowDB_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t cfgid;//
		int32_t stronglv;//
		int32_t starlv;//
		int32_t starindex;//
		int32_t failnum;//

		virtual void write_to_pbmsg(::proto_ff::PetGrowDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetGrowDB & msg);
		static ::proto_ff::PetGrowDB* new_pbmsg(){ return new ::proto_ff::PetGrowDB(); }
		static ::proto_ff::PetGrowDB make_pbmsg(){ return ::proto_ff::PetGrowDB(); }
	};
	typedef struct PetGrowDB_s PetGrowDB_t;

	struct PetDBData_s : public NFDescStoreSeqOP {
		PetDBData_s();
		virtual ~PetDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_PETDBDATA_FETTER_MAX_NUM> fetter;//
		NFShmVector<struct PetInfo_s, DEFINE_PETDBDATA_PETS_MAX_NUM> pets;//
		NFShmVector<struct PetHatchInfo_s, DEFINE_PETDBDATA_HATCHS_MAX_NUM> hatchs;//
		NFShmVector<struct PetDBRecord_s, DEFINE_PETDBDATA_RECORDS_MAX_NUM> records;//
		NFShmVector<int64_t, DEFINE_PETDBDATA_CFGIDS_MAX_NUM> cfgids;//
		NFShmVector<struct PetGrowDB_s, DEFINE_PETDBDATA_GROWS_MAX_NUM> grows;//
		struct PetYaoHunModule_s yaohun;//

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
		int64_t id;//
		uint32_t num;//
		uint64_t time;//

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
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_DAY_MAX_NUM> day;//
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_WEEK_MAX_NUM> week;//
		NFShmVector<struct MallDBInfo_s, DEFINE_MALLDBDATA_FOREVER_MAX_NUM> forever;//

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
		int32_t daynum;//
		int32_t escortid;//
		uint64_t endTime;//
		int32_t freeNum;//
		int32_t genEscortId;//
		uint64_t resetTime;//

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
		NFShmVector<struct ArmorInfo_s, DEFINE_ARMORDBDATA_INFOS_MAX_NUM> infos;//

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
		uint64_t resetTime;//
		int32_t dayPrestige;//
		int32_t sendNum;//
		int32_t helpNum;//
		int32_t allSendNum;//
		int32_t allHelpNum;//
		int32_t recvSendGiftNum;//
		int32_t recvHelpGiftNum;//
		NFShmVector<int32_t, DEFINE_ASSISTDBDATA_REWARDIDS_MAX_NUM> rewardIds;//
		NFShmVector<struct ComPair64_s, DEFINE_ASSISTDBDATA_THANKSINFO_MAX_NUM> thanksInfo;//

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
		uint64_t cur_wearing_title;//
		NFShmVector<struct TitleInfo_s, DEFINE_TITLEDBDATA_DATA_MAX_NUM> data;//

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
		int32_t id;//
		int32_t state;//
		int32_t cur;//

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
		NFShmVector<struct GodEvilCondDBProto_s, DEFINE_GODEVILMULTCONDDBPROTO_LST_MAX_NUM> lst;//

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
		int32_t stage;//
		struct GodEvilMultCondDBProto_s cond;//
		int32_t finish;//
		int32_t accept;//

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
		int32_t fetch;//
		struct GodEvilTaskDBProto_s task;//
		int32_t type;//
		uint64_t last_time;//
		int32_t vessel_lev;//
		int32_t mirror_lev;//
		int64_t extra_exp;//
		NFShmVector<struct ItemProtoInfo_s, DEFINE_GODEVILDBDATA_EQUIP_MAX_NUM> equip;//
		NFShmVector<struct ItemProtoInfo_s, DEFINE_GODEVILDBDATA_DRESS_MAX_NUM> dress;//

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
		NFShmVector<uint32_t, DEFINE_PAYDBDATA_DB_ID_MAX_NUM> db_id;//
		NFShmVector<NFShmString<32>, DEFINE_PAYDBDATA_PRODUCT_MAX_NUM> product;//
		uint32_t relrmb;//
		uint32_t rmb;//
		uint32_t fakermb;//
		uint32_t todayrmb;//
		uint64_t todaytime;//
		uint32_t sdkrmb;//

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
		int32_t id;//
		int32_t cur;//
		int32_t fetch;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBSalary & msg);
		static ::proto_ff::FactionDBSalary* new_pbmsg(){ return new ::proto_ff::FactionDBSalary(); }
		static ::proto_ff::FactionDBSalary make_pbmsg(){ return ::proto_ff::FactionDBSalary(); }
	};
	typedef struct FactionDBSalary_s FactionDBSalary_t;

	struct FactionDBDinner_s : public NFDescStoreSeqOP {
		FactionDBDinner_s();
		virtual ~FactionDBDinner_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t trans;//
		int32_t meat;//
		uint32_t exp;//
		uint32_t contri;//
		uint64_t time;//
		uint64_t trans_time;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBDinner & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBDinner & msg);
		static ::proto_ff::FactionDBDinner* new_pbmsg(){ return new ::proto_ff::FactionDBDinner(); }
		static ::proto_ff::FactionDBDinner make_pbmsg(){ return ::proto_ff::FactionDBDinner(); }
	};
	typedef struct FactionDBDinner_s FactionDBDinner_t;

	struct FactionDBSkillProto_s : public NFDescStoreSeqOP {
		FactionDBSkillProto_s();
		virtual ~FactionDBSkillProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t level;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBSkillProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBSkillProto & msg);
		static ::proto_ff::FactionDBSkillProto* new_pbmsg(){ return new ::proto_ff::FactionDBSkillProto(); }
		static ::proto_ff::FactionDBSkillProto make_pbmsg(){ return ::proto_ff::FactionDBSkillProto(); }
	};
	typedef struct FactionDBSkillProto_s FactionDBSkillProto_t;

	struct FactionDBSkill_s : public NFDescStoreSeqOP {
		FactionDBSkill_s();
		virtual ~FactionDBSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionDBSkillProto_s, DEFINE_FACTIONDBSKILL_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBSkill & msg);
		static ::proto_ff::FactionDBSkill* new_pbmsg(){ return new ::proto_ff::FactionDBSkill(); }
		static ::proto_ff::FactionDBSkill make_pbmsg(){ return ::proto_ff::FactionDBSkill(); }
	};
	typedef struct FactionDBSkill_s FactionDBSkill_t;

	struct FactionDBGuard_s : public NFDescStoreSeqOP {
		FactionDBGuard_s();
		virtual ~FactionDBGuard_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t exp;//
		uint32_t contri;//
		uint64_t cur_encouragement_gold_count;//
		uint64_t cur_encouragement_diamond_count;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBGuard & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBGuard & msg);
		static ::proto_ff::FactionDBGuard* new_pbmsg(){ return new ::proto_ff::FactionDBGuard(); }
		static ::proto_ff::FactionDBGuard make_pbmsg(){ return ::proto_ff::FactionDBGuard(); }
	};
	typedef struct FactionDBGuard_s FactionDBGuard_t;

	struct RoleFactionDBData_s : public NFDescStoreSeqOP {
		RoleFactionDBData_s();
		virtual ~RoleFactionDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t donate_num;//
		uint64_t donate_fresh;//
		NFShmVector<struct FactionDBSalary_s, DEFINE_ROLEFACTIONDBDATA_SALARY_MAX_NUM> salary;//
		uint64_t salary_fresh;//
		struct FactionDBDinner_s dinner;//
		struct FactionDBSkill_s skill;//
		struct FactionDBGuard_s guard;//
		int32_t fetch_war;//
		uint64_t fetch_time;//

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
		NFShmVector<struct BestEQSlotInfo_s, DEFINE_ROLEBESTEQDBDATA_SLOTS_MAX_NUM> slots;//
		NFShmVector<struct BestEQTask_s, DEFINE_ROLEBESTEQDBDATA_TASKS_MAX_NUM> tasks;//

		virtual void write_to_pbmsg(::proto_ff::RoleBestEQDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleBestEQDBData & msg);
		static ::proto_ff::RoleBestEQDBData* new_pbmsg(){ return new ::proto_ff::RoleBestEQDBData(); }
		static ::proto_ff::RoleBestEQDBData make_pbmsg(){ return ::proto_ff::RoleBestEQDBData(); }
	};
	typedef struct RoleBestEQDBData_s RoleBestEQDBData_t;

	struct AncientDBData_s : public NFDescStoreSeqOP {
		AncientDBData_s();
		virtual ~AncientDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t unlock_star_id;//
		NFShmVector<struct AncientInfo_s, DEFINE_ANCIENTDBDATA_INFOS_MAX_NUM> infos;//

		virtual void write_to_pbmsg(::proto_ff::AncientDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AncientDBData & msg);
		static ::proto_ff::AncientDBData* new_pbmsg(){ return new ::proto_ff::AncientDBData(); }
		static ::proto_ff::AncientDBData make_pbmsg(){ return ::proto_ff::AncientDBData(); }
	};
	typedef struct AncientDBData_s AncientDBData_t;

	struct RoleEmblemDBInfo_s : public NFDescStoreSeqOP {
		RoleEmblemDBInfo_s();
		virtual ~RoleEmblemDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t lv;//
		int32_t star;//

		virtual void write_to_pbmsg(::proto_ff::RoleEmblemDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleEmblemDBInfo & msg);
		static ::proto_ff::RoleEmblemDBInfo* new_pbmsg(){ return new ::proto_ff::RoleEmblemDBInfo(); }
		static ::proto_ff::RoleEmblemDBInfo make_pbmsg(){ return ::proto_ff::RoleEmblemDBInfo(); }
	};
	typedef struct RoleEmblemDBInfo_s RoleEmblemDBInfo_t;

	struct Role1v1DBInfo_s : public NFDescStoreSeqOP {
		Role1v1DBInfo_s();
		virtual ~Role1v1DBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t score;//
		int32_t match_num;//
		int32_t win_num;//
		int32_t conti_num;//
		int32_t reward_num;//
		NFShmVector<int32_t, DEFINE_ROLE1V1DBINFO_ALREADY_FETCH_MAX_NUM> already_fetch;//
		uint64_t reward_time;//
		uint64_t reset_time;//
		int32_t cur_conti_num;//

		virtual void write_to_pbmsg(::proto_ff::Role1v1DBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Role1v1DBInfo & msg);
		static ::proto_ff::Role1v1DBInfo* new_pbmsg(){ return new ::proto_ff::Role1v1DBInfo(); }
		static ::proto_ff::Role1v1DBInfo make_pbmsg(){ return ::proto_ff::Role1v1DBInfo(); }
	};
	typedef struct Role1v1DBInfo_s Role1v1DBInfo_t;

	struct RolePvpDBData_s : public NFDescStoreSeqOP {
		RolePvpDBData_s();
		virtual ~RolePvpDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t pkmode;//
		int32_t chg_time;//
		int32_t killvalue;//
		int32_t onlinesec;//
		NFShmVector<struct RoleEmblemDBInfo_s, DEFINE_ROLEPVPDBDATA_EMBLEM_MAX_NUM> emblem;//
		struct Role1v1DBInfo_s pk1v1;//

		virtual void write_to_pbmsg(::proto_ff::RolePvpDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RolePvpDBData & msg);
		static ::proto_ff::RolePvpDBData* new_pbmsg(){ return new ::proto_ff::RolePvpDBData(); }
		static ::proto_ff::RolePvpDBData make_pbmsg(){ return ::proto_ff::RolePvpDBData(); }
	};
	typedef struct RolePvpDBData_s RolePvpDBData_t;

	struct RoleMarryExpress_s : public NFDescStoreSeqOP {
		RoleMarryExpress_s();
		virtual ~RoleMarryExpress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//
		uint64_t item;//
		int32_t text_id;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::RoleMarryExpress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleMarryExpress & msg);
		static ::proto_ff::RoleMarryExpress* new_pbmsg(){ return new ::proto_ff::RoleMarryExpress(); }
		static ::proto_ff::RoleMarryExpress make_pbmsg(){ return ::proto_ff::RoleMarryExpress(); }
	};
	typedef struct RoleMarryExpress_s RoleMarryExpress_t;

	struct RoleMarryDBData_s : public NFDescStoreSeqOP {
		RoleMarryDBData_s();
		virtual ~RoleMarryDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct MarrySelfInfo_s info;//
		NFShmVector<struct RoleMarryExpress_s, DEFINE_ROLEMARRYDBDATA_TOSLEF_MAX_NUM> toSlef;//
		NFShmVector<struct RoleMarryExpress_s, DEFINE_ROLEMARRYDBDATA_TOOTHER_MAX_NUM> toOther;//
		struct WeddingDupRoleInfo_s dup_record;//
		uint64_t lastTime;//

		virtual void write_to_pbmsg(::proto_ff::RoleMarryDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleMarryDBData & msg);
		static ::proto_ff::RoleMarryDBData* new_pbmsg(){ return new ::proto_ff::RoleMarryDBData(); }
		static ::proto_ff::RoleMarryDBData make_pbmsg(){ return ::proto_ff::RoleMarryDBData(); }
	};
	typedef struct RoleMarryDBData_s RoleMarryDBData_t;

	struct EncylopediaDBData_s : public NFDescStoreSeqOP {
		EncylopediaDBData_s();
		virtual ~EncylopediaDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct HandBookPBData_s hand_book;//

		virtual void write_to_pbmsg(::proto_ff::EncylopediaDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EncylopediaDBData & msg);
		static ::proto_ff::EncylopediaDBData* new_pbmsg(){ return new ::proto_ff::EncylopediaDBData(); }
		static ::proto_ff::EncylopediaDBData make_pbmsg(){ return ::proto_ff::EncylopediaDBData(); }
	};
	typedef struct EncylopediaDBData_s EncylopediaDBData_t;

	struct GVBPData_s : public NFDescStoreSeqOP {
		GVBPData_s();
		virtual ~GVBPData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<uint32_t, DEFINE_GVBPDATA_REWARDS_STATE_MAX_NUM> rewards_state;//
		uint32_t daily_score;//
		uint64_t record_time;//

		virtual void write_to_pbmsg(::proto_ff::GVBPData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GVBPData & msg);
		static ::proto_ff::GVBPData* new_pbmsg(){ return new ::proto_ff::GVBPData(); }
		static ::proto_ff::GVBPData make_pbmsg(){ return ::proto_ff::GVBPData(); }
	};
	typedef struct GVBPData_s GVBPData_t;

	struct ChargeDBData_s : public NFDescStoreSeqOP {
		ChargeDBData_s();
		virtual ~ChargeDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t first_rmb;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_FIRST_FETCH_MAX_NUM> first_fetch;//
		int32_t dia_rmb;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_DIA_FETCH_MAX_NUM> dia_fetch;//
		int32_t star_rmb;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_STAR_FETCH_MAX_NUM> star_fetch;//
		int32_t king_rmb;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_KING_FETCH_MAX_NUM> king_fetch;//
		int32_t second_rmb;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_SECOND_FETCH_MAX_NUM> second_fetch;//
		int32_t open_total;//
		NFShmVector<int32_t, DEFINE_CHARGEDBDATA_OPEN_TOTAL_FETCH_MAX_NUM> open_total_fetch;//

		virtual void write_to_pbmsg(::proto_ff::ChargeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ChargeDBData & msg);
		static ::proto_ff::ChargeDBData* new_pbmsg(){ return new ::proto_ff::ChargeDBData(); }
		static ::proto_ff::ChargeDBData make_pbmsg(){ return ::proto_ff::ChargeDBData(); }
	};
	typedef struct ChargeDBData_s ChargeDBData_t;

	struct GiftCondDBProto_s : public NFDescStoreSeqOP {
		GiftCondDBProto_s();
		virtual ~GiftCondDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		uint64_t time;//
		int32_t buy;//
		int32_t close;//

		virtual void write_to_pbmsg(::proto_ff::GiftCondDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GiftCondDBProto & msg);
		static ::proto_ff::GiftCondDBProto* new_pbmsg(){ return new ::proto_ff::GiftCondDBProto(); }
		static ::proto_ff::GiftCondDBProto make_pbmsg(){ return ::proto_ff::GiftCondDBProto(); }
	};
	typedef struct GiftCondDBProto_s GiftCondDBProto_t;

	struct GiftZeroDBProto_s : public NFDescStoreSeqOP {
		GiftZeroDBProto_s();
		virtual ~GiftZeroDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t buy;//
		int32_t fetch;//

		virtual void write_to_pbmsg(::proto_ff::GiftZeroDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GiftZeroDBProto & msg);
		static ::proto_ff::GiftZeroDBProto* new_pbmsg(){ return new ::proto_ff::GiftZeroDBProto(); }
		static ::proto_ff::GiftZeroDBProto make_pbmsg(){ return ::proto_ff::GiftZeroDBProto(); }
	};
	typedef struct GiftZeroDBProto_s GiftZeroDBProto_t;

	struct GiftZeroLogDBProto_s : public NFDescStoreSeqOP {
		GiftZeroLogDBProto_s();
		virtual ~GiftZeroLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//
		int32_t type;//
		int32_t value;//

		virtual void write_to_pbmsg(::proto_ff::GiftZeroLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GiftZeroLogDBProto & msg);
		static ::proto_ff::GiftZeroLogDBProto* new_pbmsg(){ return new ::proto_ff::GiftZeroLogDBProto(); }
		static ::proto_ff::GiftZeroLogDBProto make_pbmsg(){ return ::proto_ff::GiftZeroLogDBProto(); }
	};
	typedef struct GiftZeroLogDBProto_s GiftZeroLogDBProto_t;

	struct GiftDBData_s : public NFDescStoreSeqOP {
		GiftDBData_s();
		virtual ~GiftDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GiftCondDBProto_s, DEFINE_GIFTDBDATA_COND_MAX_NUM> cond;//
		NFShmVector<struct GiftZeroDBProto_s, DEFINE_GIFTDBDATA_ZERO_MAX_NUM> zero;//
		NFShmVector<struct GiftZeroLogDBProto_s, DEFINE_GIFTDBDATA_ZERO_LOG_MAX_NUM> zero_log;//

		virtual void write_to_pbmsg(::proto_ff::GiftDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GiftDBData & msg);
		static ::proto_ff::GiftDBData* new_pbmsg(){ return new ::proto_ff::GiftDBData(); }
		static ::proto_ff::GiftDBData make_pbmsg(){ return ::proto_ff::GiftDBData(); }
	};
	typedef struct GiftDBData_s GiftDBData_t;

	struct FestSimpleDBProto_s : public NFDescStoreSeqOP {
		FestSimpleDBProto_s();
		virtual ~FestSimpleDBProto_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::FestSimpleDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestSimpleDBProto & msg);
		static ::proto_ff::FestSimpleDBProto* new_pbmsg(){ return new ::proto_ff::FestSimpleDBProto(); }
		static ::proto_ff::FestSimpleDBProto make_pbmsg(){ return ::proto_ff::FestSimpleDBProto(); }
	};
	typedef struct FestSimpleDBProto_s FestSimpleDBProto_t;

	struct FestShopDBProto_s : public NFDescStoreSeqOP {
		FestShopDBProto_s();
		virtual ~FestShopDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_FESTSHOPDBPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FestShopDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestShopDBProto & msg);
		static ::proto_ff::FestShopDBProto* new_pbmsg(){ return new ::proto_ff::FestShopDBProto(); }
		static ::proto_ff::FestShopDBProto make_pbmsg(){ return ::proto_ff::FestShopDBProto(); }
	};
	typedef struct FestShopDBProto_s FestShopDBProto_t;

	struct FestSignDBProto_s : public NFDescStoreSeqOP {
		FestSignDBProto_s();
		virtual ~FestSignDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t is_sign;//

		virtual void write_to_pbmsg(::proto_ff::FestSignDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestSignDBProto & msg);
		static ::proto_ff::FestSignDBProto* new_pbmsg(){ return new ::proto_ff::FestSignDBProto(); }
		static ::proto_ff::FestSignDBProto make_pbmsg(){ return ::proto_ff::FestSignDBProto(); }
	};
	typedef struct FestSignDBProto_s FestSignDBProto_t;

	struct FestGoldStoreDBProto_s : public NFDescStoreSeqOP {
		FestGoldStoreDBProto_s();
		virtual ~FestGoldStoreDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_FESTGOLDSTOREDBPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FestGoldStoreDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestGoldStoreDBProto & msg);
		static ::proto_ff::FestGoldStoreDBProto* new_pbmsg(){ return new ::proto_ff::FestGoldStoreDBProto(); }
		static ::proto_ff::FestGoldStoreDBProto make_pbmsg(){ return ::proto_ff::FestGoldStoreDBProto(); }
	};
	typedef struct FestGoldStoreDBProto_s FestGoldStoreDBProto_t;

	struct FestDigEggTaskDBProto_s : public NFDescStoreSeqOP {
		FestDigEggTaskDBProto_s();
		virtual ~FestDigEggTaskDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur;//
		int32_t fetch;//

		virtual void write_to_pbmsg(::proto_ff::FestDigEggTaskDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDigEggTaskDBProto & msg);
		static ::proto_ff::FestDigEggTaskDBProto* new_pbmsg(){ return new ::proto_ff::FestDigEggTaskDBProto(); }
		static ::proto_ff::FestDigEggTaskDBProto make_pbmsg(){ return ::proto_ff::FestDigEggTaskDBProto(); }
	};
	typedef struct FestDigEggTaskDBProto_s FestDigEggTaskDBProto_t;

	struct FestDigEggDBProto_s : public NFDescStoreSeqOP {
		FestDigEggDBProto_s();
		virtual ~FestDigEggDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_FESTDIGEGGDBPROTO_ID_LST_MAX_NUM> id_lst;//
		int32_t free;//
		uint64_t time;//
		uint64_t auto_time;//
		NFShmVector<struct FestDigEggTaskDBProto_s, DEFINE_FESTDIGEGGDBPROTO_TASK_MAX_NUM> task;//
		uint64_t task_time;//

		virtual void write_to_pbmsg(::proto_ff::FestDigEggDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDigEggDBProto & msg);
		static ::proto_ff::FestDigEggDBProto* new_pbmsg(){ return new ::proto_ff::FestDigEggDBProto(); }
		static ::proto_ff::FestDigEggDBProto make_pbmsg(){ return ::proto_ff::FestDigEggDBProto(); }
	};
	typedef struct FestDigEggDBProto_s FestDigEggDBProto_t;

	struct FestCandleDBProto_s : public NFDescStoreSeqOP {
		FestCandleDBProto_s();
		virtual ~FestCandleDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_FESTCANDLEDBPROTO_ID_LST_MAX_NUM> id_lst;//
		uint64_t time;//
		int64_t harm;//

		virtual void write_to_pbmsg(::proto_ff::FestCandleDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestCandleDBProto & msg);
		static ::proto_ff::FestCandleDBProto* new_pbmsg(){ return new ::proto_ff::FestCandleDBProto(); }
		static ::proto_ff::FestCandleDBProto make_pbmsg(){ return ::proto_ff::FestCandleDBProto(); }
	};
	typedef struct FestCandleDBProto_s FestCandleDBProto_t;

	struct FestBtDragonDBProto_s : public NFDescStoreSeqOP {
		FestBtDragonDBProto_s();
		virtual ~FestBtDragonDBProto_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::FestBtDragonDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestBtDragonDBProto & msg);
		static ::proto_ff::FestBtDragonDBProto* new_pbmsg(){ return new ::proto_ff::FestBtDragonDBProto(); }
		static ::proto_ff::FestBtDragonDBProto make_pbmsg(){ return ::proto_ff::FestBtDragonDBProto(); }
	};
	typedef struct FestBtDragonDBProto_s FestBtDragonDBProto_t;

	struct FestRTurnableRechargeDBProto_s : public NFDescStoreSeqOP {
		FestRTurnableRechargeDBProto_s();
		virtual ~FestRTurnableRechargeDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestRTurnableRechargeOneProto_s, DEFINE_FESTRTURNABLERECHARGEDBPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FestRTurnableRechargeDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRTurnableRechargeDBProto & msg);
		static ::proto_ff::FestRTurnableRechargeDBProto* new_pbmsg(){ return new ::proto_ff::FestRTurnableRechargeDBProto(); }
		static ::proto_ff::FestRTurnableRechargeDBProto make_pbmsg(){ return ::proto_ff::FestRTurnableRechargeDBProto(); }
	};
	typedef struct FestRTurnableRechargeDBProto_s FestRTurnableRechargeDBProto_t;

	struct FestDailyTotalRechargeDBProto_s : public NFDescStoreSeqOP {
		FestDailyTotalRechargeDBProto_s();
		virtual ~FestDailyTotalRechargeDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestDailyTotalRechargeOneProto_s, DEFINE_FESTDAILYTOTALRECHARGEDBPROTO_INFO_MAX_NUM> info;//
		uint32_t total_recharge;//
		uint64_t flush_time;//

		virtual void write_to_pbmsg(::proto_ff::FestDailyTotalRechargeDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDailyTotalRechargeDBProto & msg);
		static ::proto_ff::FestDailyTotalRechargeDBProto* new_pbmsg(){ return new ::proto_ff::FestDailyTotalRechargeDBProto(); }
		static ::proto_ff::FestDailyTotalRechargeDBProto make_pbmsg(){ return ::proto_ff::FestDailyTotalRechargeDBProto(); }
	};
	typedef struct FestDailyTotalRechargeDBProto_s FestDailyTotalRechargeDBProto_t;

	struct FestTurnableDBProto_s : public NFDescStoreSeqOP {
		FestTurnableDBProto_s();
		virtual ~FestTurnableDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestTurnableTaskProto_s, DEFINE_FESTTURNABLEDBPROTO_TASK_MAX_NUM> task;//
		uint32_t left_num;//
		uint64_t flush_time;//
		NFShmVector<int32_t, DEFINE_FESTTURNABLEDBPROTO_CHOU_JIANG_IDS_MAX_NUM> chou_jiang_ids;//

		virtual void write_to_pbmsg(::proto_ff::FestTurnableDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestTurnableDBProto & msg);
		static ::proto_ff::FestTurnableDBProto* new_pbmsg(){ return new ::proto_ff::FestTurnableDBProto(); }
		static ::proto_ff::FestTurnableDBProto make_pbmsg(){ return ::proto_ff::FestTurnableDBProto(); }
	};
	typedef struct FestTurnableDBProto_s FestTurnableDBProto_t;

	struct FestDonateDBProto_s : public NFDescStoreSeqOP {
		FestDonateDBProto_s();
		virtual ~FestDonateDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestDonateSingleProto_s, DEFINE_FESTDONATEDBPROTO_SINGLE_MAX_NUM> single;//
		NFShmVector<struct FestDonateServerProto_s, DEFINE_FESTDONATEDBPROTO_SERVER_MAX_NUM> server;//
		uint32_t single_num;//
		NFShmVector<struct FestDonateTaskProto_s, DEFINE_FESTDONATEDBPROTO_TASK_MAX_NUM> task;//
		uint64_t flush_time;//

		virtual void write_to_pbmsg(::proto_ff::FestDonateDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDonateDBProto & msg);
		static ::proto_ff::FestDonateDBProto* new_pbmsg(){ return new ::proto_ff::FestDonateDBProto(); }
		static ::proto_ff::FestDonateDBProto make_pbmsg(){ return ::proto_ff::FestDonateDBProto(); }
	};
	typedef struct FestDonateDBProto_s FestDonateDBProto_t;

	struct FestOnlineDBProto_s : public NFDescStoreSeqOP {
		FestOnlineDBProto_s();
		virtual ~FestOnlineDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestOnlineOneProto_s, DEFINE_FESTONLINEDBPROTO_DATA_MAX_NUM> data;//
		uint64_t flush_time;//

		virtual void write_to_pbmsg(::proto_ff::FestOnlineDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestOnlineDBProto & msg);
		static ::proto_ff::FestOnlineDBProto* new_pbmsg(){ return new ::proto_ff::FestOnlineDBProto(); }
		static ::proto_ff::FestOnlineDBProto make_pbmsg(){ return ::proto_ff::FestOnlineDBProto(); }
	};
	typedef struct FestOnlineDBProto_s FestOnlineDBProto_t;

	struct FestCollectWordDBProto_s : public NFDescStoreSeqOP {
		FestCollectWordDBProto_s();
		virtual ~FestCollectWordDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestCollectWordOneProto_s, DEFINE_FESTCOLLECTWORDDBPROTO_DATA_MAX_NUM> data;//
		uint64_t flush_time;//

		virtual void write_to_pbmsg(::proto_ff::FestCollectWordDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestCollectWordDBProto & msg);
		static ::proto_ff::FestCollectWordDBProto* new_pbmsg(){ return new ::proto_ff::FestCollectWordDBProto(); }
		static ::proto_ff::FestCollectWordDBProto make_pbmsg(){ return ::proto_ff::FestCollectWordDBProto(); }
	};
	typedef struct FestCollectWordDBProto_s FestCollectWordDBProto_t;

	struct FestBossFirstDB_s : public NFDescStoreSeqOP {
		FestBossFirstDB_s();
		virtual ~FestBossFirstDB_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_FESTBOSSFIRSTDB_RECV_KILL_IDS_MAX_NUM> recv_kill_ids;//
		NFShmVector<int32_t, DEFINE_FESTBOSSFIRSTDB_RECV_RED_IDS_MAX_NUM> recv_red_ids;//
		NFShmVector<int32_t, DEFINE_FESTBOSSFIRSTDB_M_KILLS_IDS_MAX_NUM> m_kills_ids;//

		virtual void write_to_pbmsg(::proto_ff::FestBossFirstDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestBossFirstDB & msg);
		static ::proto_ff::FestBossFirstDB* new_pbmsg(){ return new ::proto_ff::FestBossFirstDB(); }
		static ::proto_ff::FestBossFirstDB make_pbmsg(){ return ::proto_ff::FestBossFirstDB(); }
	};
	typedef struct FestBossFirstDB_s FestBossFirstDB_t;

	struct FMarryRoleDB_s : public NFDescStoreSeqOP {
		FMarryRoleDB_s();
		virtual ~FMarryRoleDB_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FMarryTask_s, DEFINE_FMARRYROLEDB_TASKS_MAX_NUM> tasks;//
		NFShmVector<int32_t, DEFINE_FMARRYROLEDB_PROCESS_IDS_MAX_NUM> process_ids;//
		int32_t score;//

		virtual void write_to_pbmsg(::proto_ff::FMarryRoleDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FMarryRoleDB & msg);
		static ::proto_ff::FMarryRoleDB* new_pbmsg(){ return new ::proto_ff::FMarryRoleDB(); }
		static ::proto_ff::FMarryRoleDB make_pbmsg(){ return ::proto_ff::FMarryRoleDB(); }
	};
	typedef struct FMarryRoleDB_s FMarryRoleDB_t;

	struct DayTotalRechargeDBProto_s : public NFDescStoreSeqOP {
		DayTotalRechargeDBProto_s();
		virtual ~DayTotalRechargeDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_DAYTOTALRECHARGEDBPROTO_FETCH_LST_MAX_NUM> fetch_lst;//
		uint32_t recharge;//
		uint64_t time;//
		uint64_t reset_time;//

		virtual void write_to_pbmsg(::proto_ff::DayTotalRechargeDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DayTotalRechargeDBProto & msg);
		static ::proto_ff::DayTotalRechargeDBProto* new_pbmsg(){ return new ::proto_ff::DayTotalRechargeDBProto(); }
		static ::proto_ff::DayTotalRechargeDBProto make_pbmsg(){ return ::proto_ff::DayTotalRechargeDBProto(); }
	};
	typedef struct DayTotalRechargeDBProto_s DayTotalRechargeDBProto_t;

	struct TotalRechargeDBProto_s : public NFDescStoreSeqOP {
		TotalRechargeDBProto_s();
		virtual ~TotalRechargeDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_TOTALRECHARGEDBPROTO_FETCH_LST_MAX_NUM> fetch_lst;//
		uint32_t recharge;//

		virtual void write_to_pbmsg(::proto_ff::TotalRechargeDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TotalRechargeDBProto & msg);
		static ::proto_ff::TotalRechargeDBProto* new_pbmsg(){ return new ::proto_ff::TotalRechargeDBProto(); }
		static ::proto_ff::TotalRechargeDBProto make_pbmsg(){ return ::proto_ff::TotalRechargeDBProto(); }
	};
	typedef struct TotalRechargeDBProto_s TotalRechargeDBProto_t;

	struct LoginRewardDBProto_s : public NFDescStoreSeqOP {
		LoginRewardDBProto_s();
		virtual ~LoginRewardDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_LOGINREWARDDBPROTO_FETCH_MAX_NUM> fetch;//

		virtual void write_to_pbmsg(::proto_ff::LoginRewardDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LoginRewardDBProto & msg);
		static ::proto_ff::LoginRewardDBProto* new_pbmsg(){ return new ::proto_ff::LoginRewardDBProto(); }
		static ::proto_ff::LoginRewardDBProto make_pbmsg(){ return ::proto_ff::LoginRewardDBProto(); }
	};
	typedef struct LoginRewardDBProto_s LoginRewardDBProto_t;

	struct FestDetailDBProto_s : public NFDescStoreSeqOP {
		FestDetailDBProto_s();
		virtual ~FestDetailDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t template_id;//
		int32_t period;//
		uint64_t begintime;//
		struct FestShopDBProto_s shop;//
		struct FestDailyTotalRechargeDBProto_s daily_total_recharge;//
		struct FestSignDBProto_s sign;//
		struct FestGoldStoreDBProto_s gold_store;//
		struct FestDigEggDBProto_s dig_egg;//
		struct FestRTurnableRechargeDBProto_s rturnable_recharge;//
		struct FestTurnableDBProto_s turntable;//
		struct FestDonateDBProto_s donate;//
		struct FestOnlineDBProto_s online;//
		struct FestCollectWordDBProto_s collect_word;//
		struct DrawPizeProto_s draw_pize;//
		struct FestRankDBData_s server_rank;//
		struct FestBossFirstDB_s boss;//
		struct FestHuiMengXiYouData_s hui_meng_xi_you;//
		struct FestBtDragonDBProto_s bt_dragon;//
		struct FestCandleDBProto_s candle;//
		struct FMarryRoleDB_s marry;//
		struct DayTotalRechargeDBProto_s day_total_recharge;//
		struct TotalRechargeDBProto_s total_recharge;//
		struct LoginRewardDBProto_s login;//

		virtual void write_to_pbmsg(::proto_ff::FestDetailDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDetailDBProto & msg);
		static ::proto_ff::FestDetailDBProto* new_pbmsg(){ return new ::proto_ff::FestDetailDBProto(); }
		static ::proto_ff::FestDetailDBProto make_pbmsg(){ return ::proto_ff::FestDetailDBProto(); }
	};
	typedef struct FestDetailDBProto_s FestDetailDBProto_t;

	struct FestDBData_s : public NFDescStoreSeqOP {
		FestDBData_s();
		virtual ~FestDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestDetailDBProto_s, DEFINE_FESTDBDATA_INFO_MAX_NUM> info;//
		NFShmVector<int32_t, DEFINE_FESTDBDATA_CLOSE_MAX_NUM> close;//

		virtual void write_to_pbmsg(::proto_ff::FestDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDBData & msg);
		static ::proto_ff::FestDBData* new_pbmsg(){ return new ::proto_ff::FestDBData(); }
		static ::proto_ff::FestDBData make_pbmsg(){ return ::proto_ff::FestDBData(); }
	};
	typedef struct FestDBData_s FestDBData_t;

	struct ShadowDBProto_s : public NFDescStoreSeqOP {
		ShadowDBProto_s();
		virtual ~ShadowDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lev;//
		int32_t exp;//
		int32_t star;//
		int32_t lucky;//
		NFShmVector<struct ComPair_s, DEFINE_SHADOWDBPROTO_FRAG_MAX_NUM> frag;//
		int32_t curstar;//

		virtual void write_to_pbmsg(::proto_ff::ShadowDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ShadowDBProto & msg);
		static ::proto_ff::ShadowDBProto* new_pbmsg(){ return new ::proto_ff::ShadowDBProto(); }
		static ::proto_ff::ShadowDBProto make_pbmsg(){ return ::proto_ff::ShadowDBProto(); }
	};
	typedef struct ShadowDBProto_s ShadowDBProto_t;

	struct HaloDBProto_s : public NFDescStoreSeqOP {
		HaloDBProto_s();
		virtual ~HaloDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_HALODBPROTO_INFO_MAX_NUM> info;//
		int32_t curid;//
		int32_t curstar;//

		virtual void write_to_pbmsg(::proto_ff::HaloDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HaloDBProto & msg);
		static ::proto_ff::HaloDBProto* new_pbmsg(){ return new ::proto_ff::HaloDBProto(); }
		static ::proto_ff::HaloDBProto make_pbmsg(){ return ::proto_ff::HaloDBProto(); }
	};
	typedef struct HaloDBProto_s HaloDBProto_t;

	struct DragonDBData_s : public NFDescStoreSeqOP {
		DragonDBData_s();
		virtual ~DragonDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct ShadowDBProto_s shadow;//
		struct HaloDBProto_s halo;//

		virtual void write_to_pbmsg(::proto_ff::DragonDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DragonDBData & msg);
		static ::proto_ff::DragonDBData* new_pbmsg(){ return new ::proto_ff::DragonDBData(); }
		static ::proto_ff::DragonDBData make_pbmsg(){ return ::proto_ff::DragonDBData(); }
	};
	typedef struct DragonDBData_s DragonDBData_t;

	struct RoleDBTurnData_s : public NFDescStoreSeqOP {
		RoleDBTurnData_s();
		virtual ~RoleDBTurnData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct TurnEntry_s, DEFINE_ROLEDBTURNDATA_ENTRYS_MAX_NUM> entrys;//
		struct TurnSimple_s simple;//
		NFShmVector<struct TurnHelper_s, DEFINE_ROLEDBTURNDATA_HELPER_MAX_NUM> helper;//
		uint64_t refresh_time;//
		NFShmVector<struct TurnTask_s, DEFINE_ROLEDBTURNDATA_TASKS_MAX_NUM> tasks;//

		virtual void write_to_pbmsg(::proto_ff::RoleDBTurnData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBTurnData & msg);
		static ::proto_ff::RoleDBTurnData* new_pbmsg(){ return new ::proto_ff::RoleDBTurnData(); }
		static ::proto_ff::RoleDBTurnData make_pbmsg(){ return ::proto_ff::RoleDBTurnData(); }
	};
	typedef struct RoleDBTurnData_s RoleDBTurnData_t;

	struct GMADbData_s : public NFDescStoreSeqOP {
		GMADbData_s();
		virtual ~GMADbData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t remainTime;//
		uint32_t freeTimeRemain;//
		uint32_t freeTime;//
		uint32_t privilege;//
		uint64_t recvFreeTimePrev;//
		int64_t expTotal;//
		int64_t expAccumulate;//

		virtual void write_to_pbmsg(::proto_ff::GMADbData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMADbData & msg);
		static ::proto_ff::GMADbData* new_pbmsg(){ return new ::proto_ff::GMADbData(); }
		static ::proto_ff::GMADbData make_pbmsg(){ return ::proto_ff::GMADbData(); }
	};
	typedef struct GMADbData_s GMADbData_t;

	struct SoulDBData_s : public NFDescStoreSeqOP {
		SoulDBData_s();
		virtual ~SoulDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct SoulEntry_s entry;//
		struct SoulPool_s pool;//
		NFShmVector<struct ComPair_s, DEFINE_SOULDBDATA_TASKS_MAX_NUM> tasks;//

		virtual void write_to_pbmsg(::proto_ff::SoulDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SoulDBData & msg);
		static ::proto_ff::SoulDBData* new_pbmsg(){ return new ::proto_ff::SoulDBData(); }
		static ::proto_ff::SoulDBData make_pbmsg(){ return ::proto_ff::SoulDBData(); }
	};
	typedef struct SoulDBData_s SoulDBData_t;

	struct RoleDBData_s : public NFDescStoreSeqOP {
		RoleDBData_s();
		virtual ~RoleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint32_t zid;//
		uint32_t uid;//
		struct RoleDBBaseData_s base;//
		struct RoleDBBagData_s bag;//
		struct RoleDBEquipData_s equip;//
		struct CharacterDBTaskData_s task;//
		struct FunctionUnlockInfo_s unlockinfo;//
		struct GrowDBData_s grow;//
		struct MiniDBData_s mini;//
		struct FacadeDBData_s facade;//
		struct SkillDBData_s skill;//
		struct MiniActivityDBData_s mini_activity;//
		struct DupDBData_s dup;//
		struct BuffDBData_s buff;//
		struct BossDBData_s boss;//
		struct VipDBData_s vip;//
		struct AttrDBData_s attr;//
		struct MountDataInfo_s mount;//
		struct DeityDataInfo_s deity;//
		struct PetDBData_s pet;//
		struct MallDBData_s mall;//
		struct ConvoyData_s convoy;//
		struct ArmorDBData_s armor;//
		struct AssistDBData_s assist;//
		struct TitleDBData_s title;//
		struct GodEvilDBData_s godevil;//
		struct OccupationMissionData_s occupatoin;//
		struct PayDBData_s pay;//
		struct RoleFactionDBData_s role_faction;//
		struct RoleBestEQDBData_s best_equip;//
		struct AchievementData_s achievement;//
		struct AncientDBData_s ancient;//
		struct RolePvpDBData_s pvp;//
		struct PracticeTrueDBData_s ptdata;//
		struct RoleMarryDBData_s role_marry;//
		struct EncylopediaDBData_s encylopeddia;//
		struct GVBPData_s gvb_pdata;//
		struct PSDatas_s psdatas;//
		struct DragonSoulData_s dragon_soul;//
		struct WelfarePBData_s welfare;//
		struct DailyWelfarePBData_s daily_welfare;//
		struct ChargeDBData_s charge;//
		struct GiftDBData_s gift;//
		struct FindTreatureDBData_s find_treature;//
		struct FestDBData_s fest;//
		struct DragonDBData_s dragon;//
		struct StarData_s star;//
		int32_t change;//
		struct RoleDBTurnData_s turn;//
		struct GMADbData_s gma_datas;//
		struct SoulDBData_s soul;//

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
		uint32_t idx;//
		int32_t cfgid;//
		uint64_t time;//

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
		int32_t cfgid;//
		int32_t count;//

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
		uint32_t bdia;//
		uint32_t magic;//
		uint32_t todaynum;//
		uint32_t todaymagic;//
		uint32_t todaybdia;//
		uint64_t freshtime;//
		NFShmVector<int32_t, DEFINE_ROLEREDDBDATA_SEND_LST_MAX_NUM> send_lst;//
		NFShmVector<struct RedWaitDBProto_s, DEFINE_ROLEREDDBDATA_WAIT_LST_MAX_NUM> wait_lst;//
		uint64_t cid;//
		NFShmVector<struct RedTriggerDBProto_s, DEFINE_ROLEREDDBDATA_TRIGGER_LST_MAX_NUM> trigger_lst;//

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
		uint64_t cid;//
		uint32_t val;//
		uint64_t time;//

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
		NFShmVector<struct RedFetchDBProto_s, DEFINE_REDFETCHLISTDBPROTO_INFO_MAX_NUM> info;//

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
		uint32_t idx;//
		int32_t cfgid;//
		uint64_t sender;//
		uint64_t sendtime;//
		NFShmString<32> word;//
		int32_t finish;//
		struct RedFetchListDBProto_s fetch;//

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
		NFShmVector<struct RedWaitDBProto_s, DEFINE_REDDBDATA_WAIT_MAX_NUM> wait;//
		NFShmVector<struct RedTriggerDBProto_s, DEFINE_REDDBDATA_TRIGGER_LST_MAX_NUM> trigger_lst;//
		uint64_t freshtime;//
		NFShmVector<struct RedSendDBProto_s, DEFINE_REDDBDATA_SEND_MAX_NUM> send;//
		uint32_t faction_id;//

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
		uint64_t cid;//
		int32_t type;//
		uint32_t teamid;//
		uint32_t zid;//
		struct AttrDBData_s attr;//
		struct SkillDBData_s skill;//
		struct RoleDBBaseData_s base;//
		struct RoleDBEquipData_s equip;//
		NFShmVector<struct BestEQEquipInfo_s, DEFINE_ROLEMIRRORDATA_BEAST_EQUIPS_MAX_NUM> beast_equips;//
		NFShmVector<struct BestEQSlotInfo_s, DEFINE_ROLEMIRRORDATA_BEAST_SLOTS_MAX_NUM> beast_slots;//
		int32_t campid;//

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
		uint64_t cid;//
		int32_t duty;//
		uint64_t join_time;//
		uint32_t total_contri;//

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
		NFShmVector<struct FactionMemDBProto_s, DEFINE_FACTIONMULTMEMDBPROTO_MEM_LST_MAX_NUM> mem_lst;//

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
		uint64_t cid;//
		uint64_t time;//

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
		NFShmVector<struct FactionApplyDBProto_s, DEFINE_FACTIONMULTAPPLYDBPROTO_APPLY_LST_MAX_NUM> apply_lst;//

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
		uint64_t cid;//
		uint64_t time;//
		int32_t op;//
		int64_t param1;//

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
		NFShmVector<struct FactionRecordDBProto_s, DEFINE_FACTIONMUTRECORDDBPROTO_RECORD_LST_MAX_NUM> record_lst;//

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
		uint32_t faction_id;//
		NFShmString<32> name;//
		uint64_t leader_id;//
		uint64_t fight;//
		NFShmString<32> notice;//
		uint64_t last_notice_time;//
		uint32_t level;//
		uint64_t exp;//
		uint64_t create_time;//
		uint64_t proxy_id;//
		uint64_t proxy_time;//
		int32_t grade;//
		struct FactionMultMemDBProto_s member;//
		struct FactionMultApplyDBProto_s apply;//
		struct FactionMutRecordDBProto_s record;//
		int32_t apply_type;//
		int32_t apply_lev;//
		uint64_t apply_fight;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBBase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBBase & msg);
		static ::proto_ff::FactionDBBase* new_pbmsg(){ return new ::proto_ff::FactionDBBase(); }
		static ::proto_ff::FactionDBBase make_pbmsg(){ return ::proto_ff::FactionDBBase(); }
	};
	typedef struct FactionDBBase_s FactionDBBase_t;

	struct FactionBeastHarmDBProto_s : public NFDescStoreSeqOP {
		FactionBeastHarmDBProto_s();
		virtual ~FactionBeastHarmDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		int64_t harm;//

		virtual void write_to_pbmsg(::proto_ff::FactionBeastHarmDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionBeastHarmDBProto & msg);
		static ::proto_ff::FactionBeastHarmDBProto* new_pbmsg(){ return new ::proto_ff::FactionBeastHarmDBProto(); }
		static ::proto_ff::FactionBeastHarmDBProto make_pbmsg(){ return ::proto_ff::FactionBeastHarmDBProto(); }
	};
	typedef struct FactionBeastHarmDBProto_s FactionBeastHarmDBProto_t;

	struct FactionBeastDBData_s : public NFDescStoreSeqOP {
		FactionBeastDBData_s();
		virtual ~FactionBeastDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionBeastHarmDBProto_s, DEFINE_FACTIONBEASTDBDATA_HARM_MAX_NUM> harm;//
		uint32_t star;//
		int32_t is_open;//
		uint32_t tribute;//
		uint32_t today_count;//
		uint64_t today_fresh;//
		uint32_t week_count;//
		uint64_t week_fresh;//
		int32_t level;//
		uint64_t opentime;//

		virtual void write_to_pbmsg(::proto_ff::FactionBeastDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionBeastDBData & msg);
		static ::proto_ff::FactionBeastDBData* new_pbmsg(){ return new ::proto_ff::FactionBeastDBData(); }
		static ::proto_ff::FactionBeastDBData make_pbmsg(){ return ::proto_ff::FactionBeastDBData(); }
	};
	typedef struct FactionBeastDBData_s FactionBeastDBData_t;

	struct FactionGuardHarmDBProto_s : public NFDescStoreSeqOP {
		FactionGuardHarmDBProto_s();
		virtual ~FactionGuardHarmDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int64_t harm;//

		virtual void write_to_pbmsg(::proto_ff::FactionGuardHarmDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionGuardHarmDBProto & msg);
		static ::proto_ff::FactionGuardHarmDBProto* new_pbmsg(){ return new ::proto_ff::FactionGuardHarmDBProto(); }
		static ::proto_ff::FactionGuardHarmDBProto make_pbmsg(){ return ::proto_ff::FactionGuardHarmDBProto(); }
	};
	typedef struct FactionGuardHarmDBProto_s FactionGuardHarmDBProto_t;

	struct FactionGuardDBData_s : public NFDescStoreSeqOP {
		FactionGuardDBData_s();
		virtual ~FactionGuardDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionGuardHarmDBProto_s, DEFINE_FACTIONGUARDDBDATA_HARM_MAX_NUM> harm;//
		NFShmVector<struct FactionGuardHarmDBProto_s, DEFINE_FACTIONGUARDDBDATA_OLD_HARM_MAX_NUM> old_harm;//
		bool can_enter;//

		virtual void write_to_pbmsg(::proto_ff::FactionGuardDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionGuardDBData & msg);
		static ::proto_ff::FactionGuardDBData* new_pbmsg(){ return new ::proto_ff::FactionGuardDBData(); }
		static ::proto_ff::FactionGuardDBData make_pbmsg(){ return ::proto_ff::FactionGuardDBData(); }
	};
	typedef struct FactionGuardDBData_s FactionGuardDBData_t;

	struct FactionMoyu_s : public NFDescStoreSeqOP {
		FactionMoyu_s();
		virtual ~FactionMoyu_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t week_harm;//
		uint64_t last_week_harm;//
		int32_t cur_layer;//
		uint64_t cur_hp;//
		uint64_t max_hp;//
		uint64_t harm_time;//
		uint64_t refresh_time;//
		int32_t pass_layer;//

		virtual void write_to_pbmsg(::proto_ff::FactionMoyu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionMoyu & msg);
		static ::proto_ff::FactionMoyu* new_pbmsg(){ return new ::proto_ff::FactionMoyu(); }
		static ::proto_ff::FactionMoyu make_pbmsg(){ return ::proto_ff::FactionMoyu(); }
	};
	typedef struct FactionMoyu_s FactionMoyu_t;

	struct FactionDBData_s : public NFDescStoreSeqOP {
		FactionDBData_s();
		virtual ~FactionDBData_s(){}
		int CreateInit();
		int ResumeInit();
		struct FactionBeastDBData_s beast;//
		struct FactionGuardDBData_s guard;//
		struct FactionMoyu_s moyu;//

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
		uint32_t faction_id;//
		struct FactionDBBase_s base;//
		struct FactionDBData_s data;//

		virtual void write_to_pbmsg(::proto_ff::FactionAllDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionAllDBData & msg);
		static ::proto_ff::FactionAllDBData* new_pbmsg(){ return new ::proto_ff::FactionAllDBData(); }
		static ::proto_ff::FactionAllDBData make_pbmsg(){ return ::proto_ff::FactionAllDBData(); }
	};
	typedef struct FactionAllDBData_s FactionAllDBData_t;

	struct FactionDBMoyuRankEntry_s : public NFDescStoreSeqOP {
		FactionDBMoyuRankEntry_s();
		virtual ~FactionDBMoyuRankEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> name;//
		int32_t zid;//
		uint64_t harm;//
		uint64_t harm_time;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBMoyuRankEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBMoyuRankEntry & msg);
		static ::proto_ff::FactionDBMoyuRankEntry* new_pbmsg(){ return new ::proto_ff::FactionDBMoyuRankEntry(); }
		static ::proto_ff::FactionDBMoyuRankEntry make_pbmsg(){ return ::proto_ff::FactionDBMoyuRankEntry(); }
	};
	typedef struct FactionDBMoyuRankEntry_s FactionDBMoyuRankEntry_t;

	struct FactionDBMoyuRank_s : public NFDescStoreSeqOP {
		FactionDBMoyuRank_s();
		virtual ~FactionDBMoyuRank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;//
		int32_t group;//
		NFShmVector<struct FactionDBMoyuRankEntry_s, DEFINE_FACTIONDBMOYURANK_RANK_MAX_NUM> rank;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBMoyuRank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBMoyuRank & msg);
		static ::proto_ff::FactionDBMoyuRank* new_pbmsg(){ return new ::proto_ff::FactionDBMoyuRank(); }
		static ::proto_ff::FactionDBMoyuRank make_pbmsg(){ return ::proto_ff::FactionDBMoyuRank(); }
	};
	typedef struct FactionDBMoyuRank_s FactionDBMoyuRank_t;

	struct FactionDBMoyuRankDB_s : public NFDescStoreSeqOP {
		FactionDBMoyuRankDB_s();
		virtual ~FactionDBMoyuRankDB_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FactionDBMoyuRank_s, DEFINE_FACTIONDBMOYURANKDB_INFOS_MAX_NUM> infos;//

		virtual void write_to_pbmsg(::proto_ff::FactionDBMoyuRankDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionDBMoyuRankDB & msg);
		static ::proto_ff::FactionDBMoyuRankDB* new_pbmsg(){ return new ::proto_ff::FactionDBMoyuRankDB(); }
		static ::proto_ff::FactionDBMoyuRankDB make_pbmsg(){ return ::proto_ff::FactionDBMoyuRankDB(); }
	};
	typedef struct FactionDBMoyuRankDB_s FactionDBMoyuRankDB_t;

	struct RoleListDBReq_s : public NFDescStoreSeqOP {
		RoleListDBReq_s();
		virtual ~RoleListDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t reqid;//
		uint32_t uid;//
		uint32_t gateid;//
		uint32_t born_zid;//

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
		int32_t ret;//
		uint64_t reqid;//
		uint32_t uid;//
		uint32_t gateid;//
		NFShmVector<struct RoleListDBProto_s, DEFINE_ROLELISTDBRSP_ROLE_LST_MAX_NUM> role_lst;//
		uint32_t regnum;//

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
		uint64_t reqid;//
		uint32_t zid;//
		uint32_t gateid;//
		struct RoleDBData_s data;//
		uint32_t uid;//
		uint32_t channel_id;//
		uint32_t zone_mid;//
		uint32_t born_zid;//

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
		int32_t ret;//
		uint64_t reqid;//
		uint32_t uid;//
		uint32_t gateid;//
		struct RoleListDBProto_s info;//
		uint32_t born_zid;//
		struct CenterRoleProto_s simple;//

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
		uint64_t reqid;//
		uint64_t cid;//
		int32_t change;//

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
		int32_t ret;//
		uint64_t reqid;//
		uint64_t cid;//
		int32_t change;//
		struct RoleDBData_s info;//

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
		uint64_t cid;//
		uint32_t uid;//
		struct RoleDBData_s info;//

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
		uint64_t cid;//
		NFShmString<32> name;//

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
		int32_t ret;//
		uint64_t cid;//
		NFShmString<32> name;//

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
		int32_t ret;//
		NFShmVector<struct CenterRoleProto_s, DEFINE_ROLESIMPLELISTDBRSP_INFO_MAX_NUM> info;//
		int32_t finish_flag;//

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
		NFShmString<32> trans_data;//

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
		int32_t retcode;//
		uint64_t cid;//

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
		NFShmVector<struct MailInfo_s, DEFINE_NEWMAILDBINFO_DATA_MAX_NUM> data;//
		int32_t result;//

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
		NFShmVector<uint32_t, DEFINE_MAILDBOPERATEINFO_MID_LST_MAX_NUM> mid_lst;//
		int32_t result;//

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
		uint64_t charid;//
		struct NewMailDBInfo_s info;//
		struct MailDBOperateInfo_s del;//
		struct MailDBOperateInfo_s fetch;//
		struct MailDBOperateInfo_s read;//
		int32_t notify;//

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
		uint64_t charid;//
		struct NewMailDBInfo_s info;//
		struct MailDBOperateInfo_s del;//
		struct MailDBOperateInfo_s fetch;//
		struct MailDBOperateInfo_s read;//
		int32_t notify;//

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
		uint64_t charID;//
		uint32_t zone_mail_flag;//
		int32_t offset;//
		uint32_t reqid;//

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
		uint64_t charID;//
		NFShmVector<struct MailInfo_s, DEFINE_CHARACTERMAILDBRESPONSE_INFO_MAX_NUM> info;//
		uint32_t zoneMailId;//
		int32_t offset;//
		uint32_t reqid;//

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
		uint32_t maxZoneMailId;//

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
		uint64_t charID;//

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
		uint32_t mailId;//

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
		uint32_t mailId;//
		uint64_t cid;//
		uint64_t createtime;//

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
		uint64_t cid;//
		NFShmVector<struct MailInfo_s, DEFINE_ZONEMAILTRANSCHARACTERMAILRSP_DATA_MAX_NUM> data;//
		uint32_t max_zone_mailid;//

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
		int32_t op_type;//
		uint64_t cid;//
		uint32_t pernum;//
		uint32_t curpage;//
		NFShmVector<uint32_t, DEFINE_WEBMAILDBDATAREQ_ID_LST_MAX_NUM> id_lst;//
		NFShmString<32> webId;//

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
		int32_t op_type;//
		uint64_t cid;//
		uint32_t curpage;//
		uint32_t totalcount;//
		NFShmVector<uint32_t, DEFINE_WEBMAILDBDATARSP_ID_LST_MAX_NUM> id_lst;//
		NFShmVector<struct WebMailDataProto_s, DEFINE_WEBMAILDBDATARSP_INFO_LST_MAX_NUM> info_lst;//
		NFShmString<32> webId;//

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
		uint64_t charID;//
		struct RelationDBInfo_s data;//

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
		uint64_t charid;//
		NFShmVector<uint64_t, DEFINE_FRIENDDBREQUEST_DSTID_LST_MAX_NUM> dstid_lst;//
		uint32_t operate_type;//
		NFShmString<32> data;//
		uint32_t query_times;//

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
		int32_t retcode;//
		uint64_t charid;//
		uint32_t operate_type;//
		NFShmVector<struct FriendDBInfo_s, DEFINE_FRIENDDBRESPONSE_INFO_LST_MAX_NUM> info_lst;//
		NFShmVector<uint64_t, DEFINE_FRIENDDBRESPONSE_LAST_LST_MAX_NUM> last_lst;//
		NFShmString<32> data;//
		uint32_t query_times;//

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
		int32_t offset;//

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
		int32_t retcode;//
		int32_t offset;//
		NFShmVector<struct FriendDBInfo_s, DEFINE_ALLFRIENDDBRESPONSE_INFO_MAX_NUM> info;//

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
		NFShmVector<struct FriendDBInfo_s, DEFINE_SAVEFRIENDDBREQUEST_INFO_MAX_NUM> info;//

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
		uint64_t charId;//

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
		int32_t type_id;//
		NFShmString<32> data;//

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
		NFShmVector<struct GlobalDBEntry_s, DEFINE_GLOBALDBRESPONSE_ENTRY_MAX_NUM> entry;//
		int32_t isfinish;//

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
		int32_t type_id;//
		NFShmString<32> data;//

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
		int32_t retcode;//
		int32_t type_id;//

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
		NFShmVector<struct DupTowerDBRecord_s, DEFINE_GLOBALCOMDATA_TOWERDUPREWARD_MAX_NUM> towerDupReward;//

		virtual void write_to_pbmsg(::proto_ff::GlobalComData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalComData & msg);
		static ::proto_ff::GlobalComData* new_pbmsg(){ return new ::proto_ff::GlobalComData(); }
		static ::proto_ff::GlobalComData make_pbmsg(){ return ::proto_ff::GlobalComData(); }
	};
	typedef struct GlobalComData_s GlobalComData_t;

	struct GlobalYaotaDupDBEntry_s : public NFDescStoreSeqOP {
		GlobalYaotaDupDBEntry_s();
		virtual ~GlobalYaotaDupDBEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t dupid;//
		NFShmVector<struct RolePlayerMiniInfo_s, DEFINE_GLOBALYAOTADUPDBENTRY_INFO_MAX_NUM> info;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::GlobalYaotaDupDBEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalYaotaDupDBEntry & msg);
		static ::proto_ff::GlobalYaotaDupDBEntry* new_pbmsg(){ return new ::proto_ff::GlobalYaotaDupDBEntry(); }
		static ::proto_ff::GlobalYaotaDupDBEntry make_pbmsg(){ return ::proto_ff::GlobalYaotaDupDBEntry(); }
	};
	typedef struct GlobalYaotaDupDBEntry_s GlobalYaotaDupDBEntry_t;

	struct GlobalYaotaDupDBData_s : public NFDescStoreSeqOP {
		GlobalYaotaDupDBData_s();
		virtual ~GlobalYaotaDupDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GlobalYaotaDupDBEntry_s, DEFINE_GLOBALYAOTADUPDBDATA_ENTRYS_MAX_NUM> entrys;//

		virtual void write_to_pbmsg(::proto_ff::GlobalYaotaDupDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalYaotaDupDBData & msg);
		static ::proto_ff::GlobalYaotaDupDBData* new_pbmsg(){ return new ::proto_ff::GlobalYaotaDupDBData(); }
		static ::proto_ff::GlobalYaotaDupDBData make_pbmsg(){ return ::proto_ff::GlobalYaotaDupDBData(); }
	};
	typedef struct GlobalYaotaDupDBData_s GlobalYaotaDupDBData_t;

	struct ActDBProto_s : public NFDescStoreSeqOP {
		ActDBProto_s();
		virtual ~ActDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t actid;//
		uint32_t zid;//
		uint64_t finishtime;//

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
		NFShmVector<struct ActDBProto_s, DEFINE_ACTDBRSP_LST_MAX_NUM> lst;//

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
		NFShmVector<struct ActDBProto_s, DEFINE_ACTSAVEDBREQ_LST_MAX_NUM> lst;//

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
		int32_t offset;//
		int32_t retnum;//

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
		uint64_t charID;//
		uint32_t rankId;//

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
		NFShmVector<struct ArenaDBInfo_s, DEFINE_ARENAMOREDBINFO_INFO_MAX_NUM> info;//
		uint32_t day;//
		uint32_t giveReward;//
		uint32_t max_rank;//

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
		int32_t retcode;//
		int32_t offset;//
		NFShmVector<struct ArenaDBInfo_s, DEFINE_ALLARENADBRESPONSE_INFO_MAX_NUM> info;//

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
		NFShmVector<struct ArenaDBInfo_s, DEFINE_SAVEARENADBREQUEST_INFO_MAX_NUM> info;//

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
		uint64_t charId;//

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
		uint64_t cid;//
		int64_t int_param;//
		NFShmString<32> str_param;//
		uint32_t reqtype;//

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
		int32_t ret;//
		uint64_t cid;//
		int64_t int_param;//
		NFShmString<32> str_param;//
		uint32_t reqtype;//
		struct RoleMirrorData_s data;//

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
		NFShmVector<struct FactionAllDBData_s, DEFINE_FACTIONDATADBRSP_DATA_LST_MAX_NUM> data_lst;//
		int32_t finish;//

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
		struct FactionAllDBData_s data;//

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
		uint32_t faction_id;//

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
		NFShmVector<struct RedDBData_s, DEFINE_FACTIONREDDBRSP_DATA_LST_MAX_NUM> data_lst;//
		int32_t finish;//

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
		uint32_t faction_id;//
		struct RedDBData_s data0;//
		struct RedDBData_s data1;//
		struct RedDBData_s data2;//

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
		uint32_t faction_id;//

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
		NFShmVector<struct RoleRedDBData_s, DEFINE_ROLEREDDBRSP_DATA_LST_MAX_NUM> data_lst;//
		int32_t finish;//

		virtual void write_to_pbmsg(::proto_ff::RoleRedDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleRedDBRsp & msg);
		static ::proto_ff::RoleRedDBRsp* new_pbmsg(){ return new ::proto_ff::RoleRedDBRsp(); }
		static ::proto_ff::RoleRedDBRsp make_pbmsg(){ return ::proto_ff::RoleRedDBRsp(); }
	};
	typedef struct RoleRedDBRsp_s RoleRedDBRsp_t;

	struct ComLoadDBReq_s : public NFDescStoreSeqOP {
		ComLoadDBReq_s();
		virtual ~ComLoadDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> table_name;//
		uint32_t cmd;//

		virtual void write_to_pbmsg(::proto_ff::ComLoadDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComLoadDBReq & msg);
		static ::proto_ff::ComLoadDBReq* new_pbmsg(){ return new ::proto_ff::ComLoadDBReq(); }
		static ::proto_ff::ComLoadDBReq make_pbmsg(){ return ::proto_ff::ComLoadDBReq(); }
	};
	typedef struct ComLoadDBReq_s ComLoadDBReq_t;

	struct ComLoadDBRsp_s : public NFDescStoreSeqOP {
		ComLoadDBRsp_s();
		virtual ~ComLoadDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> data;//

		virtual void write_to_pbmsg(::proto_ff::ComLoadDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComLoadDBRsp & msg);
		static ::proto_ff::ComLoadDBRsp* new_pbmsg(){ return new ::proto_ff::ComLoadDBRsp(); }
		static ::proto_ff::ComLoadDBRsp make_pbmsg(){ return ::proto_ff::ComLoadDBRsp(); }
	};
	typedef struct ComLoadDBRsp_s ComLoadDBRsp_t;

	struct ComLoadAllDBReq_s : public NFDescStoreSeqOP {
		ComLoadAllDBReq_s();
		virtual ~ComLoadAllDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> table_name;//
		uint32_t cmd;//

		virtual void write_to_pbmsg(::proto_ff::ComLoadAllDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComLoadAllDBReq & msg);
		static ::proto_ff::ComLoadAllDBReq* new_pbmsg(){ return new ::proto_ff::ComLoadAllDBReq(); }
		static ::proto_ff::ComLoadAllDBReq make_pbmsg(){ return ::proto_ff::ComLoadAllDBReq(); }
	};
	typedef struct ComLoadAllDBReq_s ComLoadAllDBReq_t;

	struct ComDBProto_s : public NFDescStoreSeqOP {
		ComDBProto_s();
		virtual ~ComDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> data;//

		virtual void write_to_pbmsg(::proto_ff::ComDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComDBProto & msg);
		static ::proto_ff::ComDBProto* new_pbmsg(){ return new ::proto_ff::ComDBProto(); }
		static ::proto_ff::ComDBProto make_pbmsg(){ return ::proto_ff::ComDBProto(); }
	};
	typedef struct ComDBProto_s ComDBProto_t;

	struct ComLoadAllDBRsp_s : public NFDescStoreSeqOP {
		ComLoadAllDBRsp_s();
		virtual ~ComLoadAllDBRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComDBProto_s, DEFINE_COMLOADALLDBRSP_DATA_MAX_NUM> data;//
		int32_t is_finish;//

		virtual void write_to_pbmsg(::proto_ff::ComLoadAllDBRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComLoadAllDBRsp & msg);
		static ::proto_ff::ComLoadAllDBRsp* new_pbmsg(){ return new ::proto_ff::ComLoadAllDBRsp(); }
		static ::proto_ff::ComLoadAllDBRsp make_pbmsg(){ return ::proto_ff::ComLoadAllDBRsp(); }
	};
	typedef struct ComLoadAllDBRsp_s ComLoadAllDBRsp_t;

	struct ComSaveDBReq_s : public NFDescStoreSeqOP {
		ComSaveDBReq_s();
		virtual ~ComSaveDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> data;//
		NFShmString<32> table_name;//

		virtual void write_to_pbmsg(::proto_ff::ComSaveDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComSaveDBReq & msg);
		static ::proto_ff::ComSaveDBReq* new_pbmsg(){ return new ::proto_ff::ComSaveDBReq(); }
		static ::proto_ff::ComSaveDBReq make_pbmsg(){ return ::proto_ff::ComSaveDBReq(); }
	};
	typedef struct ComSaveDBReq_s ComSaveDBReq_t;

	struct ComDelDBReq_s : public NFDescStoreSeqOP {
		ComDelDBReq_s();
		virtual ~ComDelDBReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> table_name;//
		NFShmVector<uint64_t, DEFINE_COMDELDBREQ_ID_LST_MAX_NUM> id_lst;//

		virtual void write_to_pbmsg(::proto_ff::ComDelDBReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComDelDBReq & msg);
		static ::proto_ff::ComDelDBReq* new_pbmsg(){ return new ::proto_ff::ComDelDBReq(); }
		static ::proto_ff::ComDelDBReq make_pbmsg(){ return ::proto_ff::ComDelDBReq(); }
	};
	typedef struct ComDelDBReq_s ComDelDBReq_t;

	struct MarryApply_s : public NFDescStoreSeqOP {
		MarryApply_s();
		virtual ~MarryApply_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t apply_dst_id;//
		uint64_t time;//
		int32_t gear;//

		virtual void write_to_pbmsg(::proto_ff::MarryApply & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryApply & msg);
		static ::proto_ff::MarryApply* new_pbmsg(){ return new ::proto_ff::MarryApply(); }
		static ::proto_ff::MarryApply make_pbmsg(){ return ::proto_ff::MarryApply(); }
	};
	typedef struct MarryApply_s MarryApply_t;

	struct MarrySimpleInfo_s : public NFDescStoreSeqOP {
		MarrySimpleInfo_s();
		virtual ~MarrySimpleInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t m_id;//
		uint64_t dst_id;//
		uint32_t marry_id;//
		struct MarryBrief_s brief;//
		struct MarryApply_s apply;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::MarrySimpleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarrySimpleInfo & msg);
		static ::proto_ff::MarrySimpleInfo* new_pbmsg(){ return new ::proto_ff::MarrySimpleInfo(); }
		static ::proto_ff::MarrySimpleInfo make_pbmsg(){ return ::proto_ff::MarrySimpleInfo(); }
	};
	typedef struct MarrySimpleInfo_s MarrySimpleInfo_t;

	struct MarryDBLoadReq_s : public NFDescStoreSeqOP {
		MarryDBLoadReq_s();
		virtual ~MarryDBLoadReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t offset;//

		virtual void write_to_pbmsg(::proto_ff::MarryDBLoadReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryDBLoadReq & msg);
		static ::proto_ff::MarryDBLoadReq* new_pbmsg(){ return new ::proto_ff::MarryDBLoadReq(); }
		static ::proto_ff::MarryDBLoadReq make_pbmsg(){ return ::proto_ff::MarryDBLoadReq(); }
	};
	typedef struct MarryDBLoadReq_s MarryDBLoadReq_t;

	struct MarryDBLoadRsp_s : public NFDescStoreSeqOP {
		MarryDBLoadRsp_s();
		virtual ~MarryDBLoadRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//
		int32_t offset;//
		NFShmVector<struct MarrySimpleInfo_s, DEFINE_MARRYDBLOADRSP_SIMPLE_MAX_NUM> simple;//

		virtual void write_to_pbmsg(::proto_ff::MarryDBLoadRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryDBLoadRsp & msg);
		static ::proto_ff::MarryDBLoadRsp* new_pbmsg(){ return new ::proto_ff::MarryDBLoadRsp(); }
		static ::proto_ff::MarryDBLoadRsp make_pbmsg(){ return ::proto_ff::MarryDBLoadRsp(); }
	};
	typedef struct MarryDBLoadRsp_s MarryDBLoadRsp_t;

	struct MarryDBSaveReq_s : public NFDescStoreSeqOP {
		MarryDBSaveReq_s();
		virtual ~MarryDBSaveReq_s(){}
		int CreateInit();
		int ResumeInit();
		struct MarrySimpleInfo_s info;//

		virtual void write_to_pbmsg(::proto_ff::MarryDBSaveReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryDBSaveReq & msg);
		static ::proto_ff::MarryDBSaveReq* new_pbmsg(){ return new ::proto_ff::MarryDBSaveReq(); }
		static ::proto_ff::MarryDBSaveReq make_pbmsg(){ return ::proto_ff::MarryDBSaveReq(); }
	};
	typedef struct MarryDBSaveReq_s MarryDBSaveReq_t;

	struct AnswerRankDBProto_s : public NFDescStoreSeqOP {
		AnswerRankDBProto_s();
		virtual ~AnswerRankDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t factionid;//
		NFShmString<32> name;//
		uint32_t count;//
		uint32_t zid;//

		virtual void write_to_pbmsg(::proto_ff::AnswerRankDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AnswerRankDBProto & msg);
		static ::proto_ff::AnswerRankDBProto* new_pbmsg(){ return new ::proto_ff::AnswerRankDBProto(); }
		static ::proto_ff::AnswerRankDBProto make_pbmsg(){ return ::proto_ff::AnswerRankDBProto(); }
	};
	typedef struct AnswerRankDBProto_s AnswerRankDBProto_t;

	struct AnswerDBData_s : public NFDescStoreSeqOP {
		AnswerDBData_s();
		virtual ~AnswerDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct AnswerRankDBProto_s, DEFINE_ANSWERDBDATA_RANK_MAX_NUM> rank;//

		virtual void write_to_pbmsg(::proto_ff::AnswerDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AnswerDBData & msg);
		static ::proto_ff::AnswerDBData* new_pbmsg(){ return new ::proto_ff::AnswerDBData(); }
		static ::proto_ff::AnswerDBData make_pbmsg(){ return ::proto_ff::AnswerDBData(); }
	};
	typedef struct AnswerDBData_s AnswerDBData_t;

	struct GuardRankDBProto_s : public NFDescStoreSeqOP {
		GuardRankDBProto_s();
		virtual ~GuardRankDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t factionid;//
		NFShmString<32> name;//
		uint32_t count;//
		uint64_t time;//
		uint32_t zid;//

		virtual void write_to_pbmsg(::proto_ff::GuardRankDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GuardRankDBProto & msg);
		static ::proto_ff::GuardRankDBProto* new_pbmsg(){ return new ::proto_ff::GuardRankDBProto(); }
		static ::proto_ff::GuardRankDBProto make_pbmsg(){ return ::proto_ff::GuardRankDBProto(); }
	};
	typedef struct GuardRankDBProto_s GuardRankDBProto_t;

	struct GuardDBData_s : public NFDescStoreSeqOP {
		GuardDBData_s();
		virtual ~GuardDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GuardRankDBProto_s, DEFINE_GUARDDBDATA_OLD_RANK_MAX_NUM> old_rank;//
		NFShmVector<struct GuardRankDBProto_s, DEFINE_GUARDDBDATA_CUR_RANK_MAX_NUM> cur_rank;//

		virtual void write_to_pbmsg(::proto_ff::GuardDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GuardDBData & msg);
		static ::proto_ff::GuardDBData* new_pbmsg(){ return new ::proto_ff::GuardDBData(); }
		static ::proto_ff::GuardDBData make_pbmsg(){ return ::proto_ff::GuardDBData(); }
	};
	typedef struct GuardDBData_s GuardDBData_t;

	struct Rank1v1DBProto_s : public NFDescStoreSeqOP {
		Rank1v1DBProto_s();
		virtual ~Rank1v1DBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t rank;//
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t prof;//
		uint64_t fight;//
		uint32_t zid;//
		int32_t score;//
		uint64_t time;//
		int32_t match_num;//

		virtual void write_to_pbmsg(::proto_ff::Rank1v1DBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Rank1v1DBProto & msg);
		static ::proto_ff::Rank1v1DBProto* new_pbmsg(){ return new ::proto_ff::Rank1v1DBProto(); }
		static ::proto_ff::Rank1v1DBProto make_pbmsg(){ return ::proto_ff::Rank1v1DBProto(); }
	};
	typedef struct Rank1v1DBProto_s Rank1v1DBProto_t;

	struct Act1v1DBData_s : public NFDescStoreSeqOP {
		Act1v1DBData_s();
		virtual ~Act1v1DBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct Rank1v1DBProto_s, DEFINE_ACT1V1DBDATA_RANK_MAX_NUM> rank;//
		uint64_t reset_time;//
		int32_t num;//

		virtual void write_to_pbmsg(::proto_ff::Act1v1DBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Act1v1DBData & msg);
		static ::proto_ff::Act1v1DBData* new_pbmsg(){ return new ::proto_ff::Act1v1DBData(); }
		static ::proto_ff::Act1v1DBData make_pbmsg(){ return ::proto_ff::Act1v1DBData(); }
	};
	typedef struct Act1v1DBData_s Act1v1DBData_t;

	struct RaceFactionDBProto_s : public NFDescStoreSeqOP {
		RaceFactionDBProto_s();
		virtual ~RaceFactionDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;//
		NFShmString<32> name;//
		uint64_t fight;//
		uint32_t zid;//

		virtual void write_to_pbmsg(::proto_ff::RaceFactionDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RaceFactionDBProto & msg);
		static ::proto_ff::RaceFactionDBProto* new_pbmsg(){ return new ::proto_ff::RaceFactionDBProto(); }
		static ::proto_ff::RaceFactionDBProto make_pbmsg(){ return ::proto_ff::RaceFactionDBProto(); }
	};
	typedef struct RaceFactionDBProto_s RaceFactionDBProto_t;

	struct RaceMatchDBProto_s : public NFDescStoreSeqOP {
		RaceMatchDBProto_s();
		virtual ~RaceMatchDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id1;//
		uint32_t faction_id2;//
		uint32_t faction_id;//

		virtual void write_to_pbmsg(::proto_ff::RaceMatchDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RaceMatchDBProto & msg);
		static ::proto_ff::RaceMatchDBProto* new_pbmsg(){ return new ::proto_ff::RaceMatchDBProto(); }
		static ::proto_ff::RaceMatchDBProto make_pbmsg(){ return ::proto_ff::RaceMatchDBProto(); }
	};
	typedef struct RaceMatchDBProto_s RaceMatchDBProto_t;

	struct RaceDBProto_s : public NFDescStoreSeqOP {
		RaceDBProto_s();
		virtual ~RaceDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t race;//
		NFShmVector<struct RaceFactionDBProto_s, DEFINE_RACEDBPROTO_INFO_LST_MAX_NUM> info_lst;//

		virtual void write_to_pbmsg(::proto_ff::RaceDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RaceDBProto & msg);
		static ::proto_ff::RaceDBProto* new_pbmsg(){ return new ::proto_ff::RaceDBProto(); }
		static ::proto_ff::RaceDBProto make_pbmsg(){ return ::proto_ff::RaceDBProto(); }
	};
	typedef struct RaceDBProto_s RaceDBProto_t;

	struct WarRankDBProto_s : public NFDescStoreSeqOP {
		WarRankDBProto_s();
		virtual ~WarRankDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t faction_id;//
		NFShmString<32> name;//
		uint32_t zid;//
		int32_t rank;//

		virtual void write_to_pbmsg(::proto_ff::WarRankDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WarRankDBProto & msg);
		static ::proto_ff::WarRankDBProto* new_pbmsg(){ return new ::proto_ff::WarRankDBProto(); }
		static ::proto_ff::WarRankDBProto make_pbmsg(){ return ::proto_ff::WarRankDBProto(); }
	};
	typedef struct WarRankDBProto_s WarRankDBProto_t;

	struct FactionWarDBData_s : public NFDescStoreSeqOP {
		FactionWarDBData_s();
		virtual ~FactionWarDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct RaceDBProto_s, DEFINE_FACTIONWARDBDATA_RACE_MAX_NUM> race;//
		NFShmVector<struct WarRankDBProto_s, DEFINE_FACTIONWARDBDATA_RANK_MAX_NUM> rank;//
		uint32_t win_id;//
		NFShmString<32> win_name;//
		int32_t win_num;//
		uint32_t win_zid;//

		virtual void write_to_pbmsg(::proto_ff::FactionWarDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FactionWarDBData & msg);
		static ::proto_ff::FactionWarDBData* new_pbmsg(){ return new ::proto_ff::FactionWarDBData(); }
		static ::proto_ff::FactionWarDBData make_pbmsg(){ return ::proto_ff::FactionWarDBData(); }
	};
	typedef struct FactionWarDBData_s FactionWarDBData_t;

	struct DigEggLogDBProto_s : public NFDescStoreSeqOP {
		DigEggLogDBProto_s();
		virtual ~DigEggLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//
		int32_t id;//
		uint64_t cid;//

		virtual void write_to_pbmsg(::proto_ff::DigEggLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DigEggLogDBProto & msg);
		static ::proto_ff::DigEggLogDBProto* new_pbmsg(){ return new ::proto_ff::DigEggLogDBProto(); }
		static ::proto_ff::DigEggLogDBProto make_pbmsg(){ return ::proto_ff::DigEggLogDBProto(); }
	};
	typedef struct DigEggLogDBProto_s DigEggLogDBProto_t;

	struct FestDigEggLogDBProto_s : public NFDescStoreSeqOP {
		FestDigEggLogDBProto_s();
		virtual ~FestDigEggLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t template_id;//
		NFShmVector<struct DigEggLogDBProto_s, DEFINE_FESTDIGEGGLOGDBPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FestDigEggLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDigEggLogDBProto & msg);
		static ::proto_ff::FestDigEggLogDBProto* new_pbmsg(){ return new ::proto_ff::FestDigEggLogDBProto(); }
		static ::proto_ff::FestDigEggLogDBProto make_pbmsg(){ return ::proto_ff::FestDigEggLogDBProto(); }
	};
	typedef struct FestDigEggLogDBProto_s FestDigEggLogDBProto_t;

	struct FestDigEggLogDBData_s : public NFDescStoreSeqOP {
		FestDigEggLogDBData_s();
		virtual ~FestDigEggLogDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestDigEggLogDBProto_s, DEFINE_FESTDIGEGGLOGDBDATA_LOG_MAX_NUM> log;//

		virtual void write_to_pbmsg(::proto_ff::FestDigEggLogDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDigEggLogDBData & msg);
		static ::proto_ff::FestDigEggLogDBData* new_pbmsg(){ return new ::proto_ff::FestDigEggLogDBData(); }
		static ::proto_ff::FestDigEggLogDBData make_pbmsg(){ return ::proto_ff::FestDigEggLogDBData(); }
	};
	typedef struct FestDigEggLogDBData_s FestDigEggLogDBData_t;

	struct FestRTurnableLogDBData_s : public NFDescStoreSeqOP {
		FestRTurnableLogDBData_s();
		virtual ~FestRTurnableLogDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestRTurnableLogDBProto_s, DEFINE_FESTRTURNABLELOGDBDATA_LOG_MAX_NUM> log;//

		virtual void write_to_pbmsg(::proto_ff::FestRTurnableLogDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRTurnableLogDBData & msg);
		static ::proto_ff::FestRTurnableLogDBData* new_pbmsg(){ return new ::proto_ff::FestRTurnableLogDBData(); }
		static ::proto_ff::FestRTurnableLogDBData make_pbmsg(){ return ::proto_ff::FestRTurnableLogDBData(); }
	};
	typedef struct FestRTurnableLogDBData_s FestRTurnableLogDBData_t;

	struct FestDonateDBData_s : public NFDescStoreSeqOP {
		FestDonateDBData_s();
		virtual ~FestDonateDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DonateServerDBProto_s, DEFINE_FESTDONATEDBDATA_DATA_MAX_NUM> data;//

		virtual void write_to_pbmsg(::proto_ff::FestDonateDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDonateDBData & msg);
		static ::proto_ff::FestDonateDBData* new_pbmsg(){ return new ::proto_ff::FestDonateDBData(); }
		static ::proto_ff::FestDonateDBData make_pbmsg(){ return ::proto_ff::FestDonateDBData(); }
	};
	typedef struct FestDonateDBData_s FestDonateDBData_t;

	struct FestDrawPizeLogDBData_s : public NFDescStoreSeqOP {
		FestDrawPizeLogDBData_s();
		virtual ~FestDrawPizeLogDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestDrawPizeLogDBProto_s, DEFINE_FESTDRAWPIZELOGDBDATA_LOG_MAX_NUM> log;//

		virtual void write_to_pbmsg(::proto_ff::FestDrawPizeLogDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDrawPizeLogDBData & msg);
		static ::proto_ff::FestDrawPizeLogDBData* new_pbmsg(){ return new ::proto_ff::FestDrawPizeLogDBData(); }
		static ::proto_ff::FestDrawPizeLogDBData make_pbmsg(){ return ::proto_ff::FestDrawPizeLogDBData(); }
	};
	typedef struct FestDrawPizeLogDBData_s FestDrawPizeLogDBData_t;

	struct GoodsDB_s : public NFDescStoreSeqOP {
		GoodsDB_s();
		virtual ~GoodsDB_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t order_id;//
		int32_t market_type;//
		uint64_t market_owner;//
		uint64_t role_id;//
		uint64_t start_time;//
		uint64_t end_time;//
		uint64_t vie_id;//
		int32_t state;//
		int32_t isdelete;//
		uint64_t cmpt_time;//
		int32_t cur_price;//
		int32_t cmpt_price;//
		uint64_t buyer_id;//
		uint64_t vie_time;//
		struct ItemProtoInfo_s item_data;//
		int32_t item_price;//
		NFShmString<32> take_list;//
		NFShmString<32> vie_list;//
		uint64_t ready_time;//
		int32_t is_take;//

		virtual void write_to_pbmsg(::proto_ff::GoodsDB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GoodsDB & msg);
		static ::proto_ff::GoodsDB* new_pbmsg(){ return new ::proto_ff::GoodsDB(); }
		static ::proto_ff::GoodsDB make_pbmsg(){ return ::proto_ff::GoodsDB(); }
	};
	typedef struct GoodsDB_s GoodsDB_t;

	struct LoadGoodsReq_s : public NFDescStoreSeqOP {
		LoadGoodsReq_s();
		virtual ~LoadGoodsReq_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t start_time;//

		virtual void write_to_pbmsg(::proto_ff::LoadGoodsReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LoadGoodsReq & msg);
		static ::proto_ff::LoadGoodsReq* new_pbmsg(){ return new ::proto_ff::LoadGoodsReq(); }
		static ::proto_ff::LoadGoodsReq make_pbmsg(){ return ::proto_ff::LoadGoodsReq(); }
	};
	typedef struct LoadGoodsReq_s LoadGoodsReq_t;

	struct MarketDBLoadRsp_s : public NFDescStoreSeqOP {
		MarketDBLoadRsp_s();
		virtual ~MarketDBLoadRsp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GoodsDB_s, DEFINE_MARKETDBLOADRSP_INFOS_MAX_NUM> infos;//
		int32_t is_finish;//

		virtual void write_to_pbmsg(::proto_ff::MarketDBLoadRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarketDBLoadRsp & msg);
		static ::proto_ff::MarketDBLoadRsp* new_pbmsg(){ return new ::proto_ff::MarketDBLoadRsp(); }
		static ::proto_ff::MarketDBLoadRsp make_pbmsg(){ return ::proto_ff::MarketDBLoadRsp(); }
	};
	typedef struct MarketDBLoadRsp_s MarketDBLoadRsp_t;

	struct MarketSaveReq_s : public NFDescStoreSeqOP {
		MarketSaveReq_s();
		virtual ~MarketSaveReq_s(){}
		int CreateInit();
		int ResumeInit();
		struct GoodsDB_s info;//

		virtual void write_to_pbmsg(::proto_ff::MarketSaveReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarketSaveReq & msg);
		static ::proto_ff::MarketSaveReq* new_pbmsg(){ return new ::proto_ff::MarketSaveReq(); }
		static ::proto_ff::MarketSaveReq make_pbmsg(){ return ::proto_ff::MarketSaveReq(); }
	};
	typedef struct MarketSaveReq_s MarketSaveReq_t;

	struct MarketDelReq_s : public NFDescStoreSeqOP {
		MarketDelReq_s();
		virtual ~MarketDelReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t order_id;//

		virtual void write_to_pbmsg(::proto_ff::MarketDelReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarketDelReq & msg);
		static ::proto_ff::MarketDelReq* new_pbmsg(){ return new ::proto_ff::MarketDelReq(); }
		static ::proto_ff::MarketDelReq make_pbmsg(){ return ::proto_ff::MarketDelReq(); }
	};
	typedef struct MarketDelReq_s MarketDelReq_t;

	struct CandleHarmDBProto_s : public NFDescStoreSeqOP {
		CandleHarmDBProto_s();
		virtual ~CandleHarmDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		uint64_t harm;//
		uint32_t zid;//
		int32_t rank;//

		virtual void write_to_pbmsg(::proto_ff::CandleHarmDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CandleHarmDBProto & msg);
		static ::proto_ff::CandleHarmDBProto* new_pbmsg(){ return new ::proto_ff::CandleHarmDBProto(); }
		static ::proto_ff::CandleHarmDBProto make_pbmsg(){ return ::proto_ff::CandleHarmDBProto(); }
	};
	typedef struct CandleHarmDBProto_s CandleHarmDBProto_t;

	struct CandleDBData_s : public NFDescStoreSeqOP {
		CandleDBData_s();
		virtual ~CandleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t index;//
		NFShmVector<struct CandleHarmDBProto_s, DEFINE_CANDLEDBDATA_HAM_MAX_NUM> ham;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::CandleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CandleDBData & msg);
		static ::proto_ff::CandleDBData* new_pbmsg(){ return new ::proto_ff::CandleDBData(); }
		static ::proto_ff::CandleDBData make_pbmsg(){ return ::proto_ff::CandleDBData(); }
	};
	typedef struct CandleDBData_s CandleDBData_t;

}

