#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"

#define DEFINE_ROLEFACADEPROTO_GROWFACADE_MAX_NUM 1
#define DEFINE_MARRYBRIEF_GEARS_MAX_NUM 1
#define DEFINE_MARRYBRIEF_RECVED_GEARS_MAX_NUM 1
#define DEFINE_TURNATTR_COM_POS_MAX_NUM 1
#define DEFINE_TURNATTR_STAR_POS_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_BASE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_REFINE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_BLUE_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_GOD_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_MISC_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_GOLD_STAR_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_SILVER_STAR_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_SKILL_MAX_NUM 1
#define DEFINE_ITEMPROTOINFO_UNLOCK_ATTR_INDEX_MAX_NUM 1
#define DEFINE_REFINESLOTINFO_UNLOCKS_MAX_NUM 1
#define DEFINE_REFINESLOTINFO_LOCK_POS_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_STONES_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_WASHS_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_SEAL_SLOTS_MAX_NUM 1
#define DEFINE_EQUIPSLOTINFO_ACTIVE_SEAL_IDS_MAX_NUM 1
#define DEFINE_MULTITEMSIMPLEPROTO_INFO_MAX_NUM 1
#define DEFINE_PETINFO_EXCLUSIVESKILLLVVEC_MAX_NUM 1
#define DEFINE_PETINFO_PASSIVESKILLLVVEC_MAX_NUM 1
#define DEFINE_PETYAOHUNENTRY_INFOS_MAX_NUM 1
#define DEFINE_PETYAOHUNENTRY_SUITIDS_MAX_NUM 1
#define DEFINE_PETYAOHUNMODULE_ENTRYS_MAX_NUM 1
#define DEFINE_MAILPARAMPROTO_STR_PARAM_MAX_NUM 1
#define DEFINE_MAILPARAMPROTO_INT_PARAM_MAX_NUM 1
#define DEFINE_MAILATTACHMENTLIST_ITEMINFO_MAX_NUM 1
#define DEFINE_WEBMAILDATAPROTO_ITEMLIST_MAX_NUM 1
#define DEFINE_USEITEMARGPROTO_ITEM_LST_MAX_NUM 1
#define DEFINE_ARENACHALLRESULT_ITEMS_MAX_NUM 1
#define DEFINE_FUNCTIONUNLOCKINFO_DATA_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_FRIENDLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_BLACKLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_HATELIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_APPLYLIST_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_GIFTRECORDS_MAX_NUM 1
#define DEFINE_RELATIONDBINFO_ARENA_RESULT_MAX_NUM 1
#define DEFINE_BUFFLISTPROTO_INFO_MAX_NUM 1
#define DEFINE_SKILLGROUPPROTO_LST_MAX_NUM 1
#define DEFINE_SKILLGROUPLISTPROTO_INFO_MAX_NUM 1
#define DEFINE_GODEVILTASKLISTPROTO_LST_MAX_NUM 1
#define DEFINE_GODEVILPROTO_EQUIP_MAX_NUM 1
#define DEFINE_RECHARGEPROTO_PRODUCT_MAX_NUM 1
#define DEFINE_MOUNTKUNEQUIPDATA_INFOS_MAX_NUM 1
#define DEFINE_MOUNTKUNEQUIPDATA_SLOT_STATUS_MAX_NUM 1
#define DEFINE_MOUNTKUNDATA_EQUIP_SUIT_DATA_MAX_NUM 1
#define DEFINE_MOUNTFAIRYLAND_TOUR_MAX_NUM 1
#define DEFINE_MOUNTFAIRYSLOT_REWARD_ITEM_MAX_NUM 1
#define DEFINE_MOUNTFAIRYSLOT_RECORD_MAX_NUM 1
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
#define DEFINE_NOTIFYVIPDATARSP_LV_GIFT_MAX_NUM 1
#define DEFINE_NOTIFYPRIVILEGEOPT_IDS_MAX_NUM 1
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
#define DEFINE_BESTEQBREAK_EXPS_MAX_NUM 1
#define DEFINE_BESTEQBREAK_GENATTR_MAX_NUM 1
#define DEFINE_ONEGOALDATA_DATA_MAX_NUM 1
#define DEFINE_ONEBATTLEPASSDATA_REWARD_MAX_NUM 1
#define DEFINE_ONEBATTLEPASSDATA_TASK_MAX_NUM 1
#define DEFINE_ONEBATTLEPASSDATA_SHOP_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_ACH_DATA_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_ACH_TOTAL_DATA_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_XIUZHENROAD_DATA_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_XIUZHENROAD_POINTS_DATA_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_XIUZHEROAD_RECHARGE_DATA_MAX_NUM 1
#define DEFINE_ACHIEVEMENTDATA_GOAL_DATA_MAX_NUM 1
#define DEFINE_PTGBEVENTLOG_ITEMS_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_GBEVENTSLOG_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_GBEVENTITEMS_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_GFLIST_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_LGLIST_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_LGPOTIONS_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_JMLIST_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_PURCHASEDLIST_MAX_NUM 1
#define DEFINE_PRACTICETRUEDBDATA_GFBOOKPURCHASEDLIST_MAX_NUM 1
#define DEFINE_ANCIENTSLOTINFO_ATTR_INDEX_MAX_NUM 1
#define DEFINE_ANCIENTINFO_UNLOCK_NUM_MAX_NUM 1
#define DEFINE_ANCIENTINFO_SLOTS_MAX_NUM 1
#define DEFINE_MARRYSELFINFO_CHILDS_MAX_NUM 1
#define DEFINE_MARRYSELFINFO_GEARS_MAX_NUM 1
#define DEFINE_MARRYSELFINFO_RECVED_GEARS_MAX_NUM 1
#define DEFINE_MARRYWEDDINGINFO_MINI_MAX_NUM 1
#define DEFINE_MARRYWEDDINGINFO_INVITE_LIST_MAX_NUM 1
#define DEFINE_WEDDINGDBINFO_INVITE_LIST_MAX_NUM 1
#define DEFINE_WEDDINGDBINFO_APPLY_LIST_MAX_NUM 1
#define DEFINE_WEDDINGDBLIST_INFOS_MAX_NUM 1
#define DEFINE_WEDDINGDETAIL_INVITE_LIST_MAX_NUM 1
#define DEFINE_WEDDINGDETAIL_APPLY_LIST_MAX_NUM 1
#define DEFINE_GLOBALEXPRESSLOG_LOGS_MAX_NUM 1
#define DEFINE_HANDBOOKPBINFO_SKILLS_MAX_NUM 1
#define DEFINE_HANDBOOKBEASTEQUIPDATA_INFOS_MAX_NUM 1
#define DEFINE_HANDBOOKBEASTEQUIPDATA_LV_ATTR_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_DATA_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_FETTERS_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_EMPLOYS_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_TABLES_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_BEASTS_MAX_NUM 1
#define DEFINE_HANDBOOKPBDATA_SLOTS_MAX_NUM 1
#define DEFINE_RANKNODEDBDATA_PARAMINT_MAX_NUM 1
#define DEFINE_RANKNODEDBDATA_PARAMSTR_MAX_NUM 1
#define DEFINE_RANKTYPEDBDATA_NODELIST_MAX_NUM 1
#define DEFINE_RANKNODEDATA_SPARAM_MAX_NUM 1
#define DEFINE_RANKDATAINFO_RANKLIST_MAX_NUM 1
#define DEFINE_MERGEREQ_INDEX_LIST_MAX_NUM 1
#define DEFINE_PSDSHOP_SALELIST_MAX_NUM 1
#define DEFINE_PSDSHOP_PURCHASEDLIST_MAX_NUM 1
#define DEFINE_PSDATAS_SHOPLIST_MAX_NUM 1
#define DEFINE_DRAGONSOULDATA_HOLE_DATA_MAX_NUM 1
#define DEFINE_DRAGONSOULDATA_STAR_MAX_NUM 1
#define DEFINE_NOTIFYQYACTRANK_RANK_MAX_NUM 1
#define DEFINE_WELFAREFRAUDREWARDPBDATA_ID_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_SIGN_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_ACCURE_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_LV_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_ONLINE_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_WEEKEND_MAX_NUM 1
#define DEFINE_WELFAREPBDATA_LOGON_MAX_NUM 1
#define DEFINE_ONEWELFAREINVESTDATA_DATA_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_XING_YUN_MI_SHI_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_DAILY_GIFT_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_TODAY_RECHARGE_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_ACC_RECHARGE_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_MONTH_CARD_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_TURNTABLE_ACC_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_TURNTABLE_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_TURNTABLE_RECORD_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_SUPER_BUY_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_INVEST_MAX_NUM 1
#define DEFINE_DAILYWELFAREPBDATA_YTTL_GIFT_MAX_NUM 1
#define DEFINE_C2SSYNINITRANKREQ_INFOS_MAX_NUM 1
#define DEFINE_FINDTREASUREREWARDRECORDDBDATA_RECORD_MAX_NUM 1
#define DEFINE_FINDTREASUREBIGDRAGONDATA_REWARD_MAX_NUM 1
#define DEFINE_FINDTREASUREBAILIANACTIVEDATA_SHOP_DATA_MAX_NUM 1
#define DEFINE_FINDTREASUREBAILIANDATA_RECORD_MAX_NUM 1
#define DEFINE_FINDTREASUREBAILIANDATA_ACTIVE_MAX_NUM 1
#define DEFINE_FINDTREASURESISHENGDATA_PERSON_TOTAL_REWARD_MAX_NUM 1
#define DEFINE_FINDTREASURESISHENGDATA_SERVER_TOTAL_REWARD_MAX_NUM 1
#define DEFINE_FINDTREASURESISHENGDATA_RECORD_MAX_NUM 1
#define DEFINE_FINDTREATUREDBDATA_BIG_DRAGON_MAX_NUM 1
#define DEFINE_FINDTREATUREDBDATA_BAI_LIAN_MAX_NUM 1
#define DEFINE_FINDTREATUREDBDATA_SI_SHENG_MAX_NUM 1
#define DEFINE_FESTRTURNABLELOGDBPROTO_INFO_MAX_NUM 1
#define DEFINE_DRAWPIZEPROTO_TASK_MAX_NUM 1
#define DEFINE_FESTDRAWPIZELOGDBPROTO_INFO_MAX_NUM 1
#define DEFINE_FESTRANKDATA_DATA_MAX_NUM 1
#define DEFINE_FESTRANKDBDATA_DATA_MAX_NUM 1
#define DEFINE_SYNWORLDINFOREQ_INFOS_MAX_NUM 1
#define DEFINE_FESTHUIMENGXIYOUDATA_REWARD_MAX_NUM 1
#define DEFINE_FESTHUIMENGXIYOUDATA_GAME_MAX_NUM 1
#define DEFINE_STARSETUPDATA_HOLE_DATA_MAX_NUM 1
#define DEFINE_STARSETUPDATA_STAR_ATTR_MAX_NUM 1
#define DEFINE_STARDATA_SETUP_DATA_MAX_NUM 1
#define DEFINE_STARDATA_FANTASY_DATA_MAX_NUM 1
#define DEFINE_STARDATA_SKILL_DATA_MAX_NUM 1
#define DEFINE_STARDATA_SKILL_SLOT_DATA_MAX_NUM 1
#define DEFINE_STARDATA_SHOP_DATA_MAX_NUM 1
#define DEFINE_TURNENTRY_INFOS_MAX_NUM 1
#define DEFINE_TURNENTRY_STRONG_IDS_MAX_NUM 1


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

	struct ComItemBind_s : public NFDescStoreSeqOP {
		ComItemBind_s();
		virtual ~ComItemBind_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;//
		uint64_t item_num;//
		int32_t bind;//

		virtual void write_to_pbmsg(::proto_ff::ComItemBind & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComItemBind & msg);
		static ::proto_ff::ComItemBind* new_pbmsg(){ return new ::proto_ff::ComItemBind(); }
		static ::proto_ff::ComItemBind make_pbmsg(){ return ::proto_ff::ComItemBind(); }
	};
	typedef struct ComItemBind_s ComItemBind_t;

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

	struct RoleHeadPicProto_s : public NFDescStoreSeqOP {
		RoleHeadPicProto_s();
		virtual ~RoleHeadPicProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t prof;//
		int64_t frame;//
		int64_t head;//

		virtual void write_to_pbmsg(::proto_ff::RoleHeadPicProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleHeadPicProto & msg);
		static ::proto_ff::RoleHeadPicProto* new_pbmsg(){ return new ::proto_ff::RoleHeadPicProto(); }
		static ::proto_ff::RoleHeadPicProto make_pbmsg(){ return ::proto_ff::RoleHeadPicProto(); }
	};
	typedef struct RoleHeadPicProto_s RoleHeadPicProto_t;

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

	struct MarryBrief_s : public NFDescStoreSeqOP {
		MarryBrief_s();
		virtual ~MarryBrief_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		int32_t child_id;//
		uint64_t card_buy_time;//
		int32_t express_lv;//
		NFShmVector<int32_t, DEFINE_MARRYBRIEF_GEARS_MAX_NUM> gears;//
		int32_t buy_dup_num;//
		int32_t marry_flag;//
		NFShmVector<int32_t, DEFINE_MARRYBRIEF_RECVED_GEARS_MAX_NUM> recved_gears;//
		int32_t dst_recv_day;//
		int32_t dst_give_dup_num;//
		int32_t card_surplus_day;//

		virtual void write_to_pbmsg(::proto_ff::MarryBrief & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryBrief & msg);
		static ::proto_ff::MarryBrief* new_pbmsg(){ return new ::proto_ff::MarryBrief(); }
		static ::proto_ff::MarryBrief make_pbmsg(){ return ::proto_ff::MarryBrief(); }
	};
	typedef struct MarryBrief_s MarryBrief_t;

	struct LoginSynMarry_s : public NFDescStoreSeqOP {
		LoginSynMarry_s();
		virtual ~LoginSynMarry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t my_dst_recv_day;//
		int32_t dst_give_dup_num;//
		int32_t marry_id;//
		struct MarryBrief_s brief;//
		NFShmString<32> dst_name;//

		virtual void write_to_pbmsg(::proto_ff::LoginSynMarry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LoginSynMarry & msg);
		static ::proto_ff::LoginSynMarry* new_pbmsg(){ return new ::proto_ff::LoginSynMarry(); }
		static ::proto_ff::LoginSynMarry make_pbmsg(){ return ::proto_ff::LoginSynMarry(); }
	};
	typedef struct LoginSynMarry_s LoginSynMarry_t;

	struct AoPlatProto_s : public NFDescStoreSeqOP {
		AoPlatProto_s();
		virtual ~AoPlatProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> udid;//
		NFShmString<32> imei;//
		NFShmString<32> idfa;//
		NFShmString<32> oaid;//
		NFShmString<32> caid;//
		NFShmString<32> android_id;//
		int32_t group_id;//
		NFShmString<32> brand;//
		NFShmString<32> device_model;//
		int32_t is_emulator;//
		int32_t screen_length;//
		int32_t screen_width;//
		NFShmString<32> os_version;//
		NFShmString<32> network_type;//
		NFShmString<32> app_channel;//
		NFShmString<32> app_version;//
		int32_t channel_id;//
		int32_t sub_channel_id;//
		NFShmString<32> account_id;//
		NFShmString<32> ip;//
		int32_t port;//
		int32_t timezone_offset;//
		NFShmString<32> platform_tag;//

		virtual void write_to_pbmsg(::proto_ff::AoPlatProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AoPlatProto & msg);
		static ::proto_ff::AoPlatProto* new_pbmsg(){ return new ::proto_ff::AoPlatProto(); }
		static ::proto_ff::AoPlatProto make_pbmsg(){ return ::proto_ff::AoPlatProto(); }
	};
	typedef struct AoPlatProto_s AoPlatProto_t;

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
		struct LoginSynMarry_s marry;//
		struct AoPlatProto_s plat;//

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
		uint32_t pt_stage;//
		uint32_t active;//
		uint64_t create_time;//
		uint32_t sdkrmb;//
		int32_t yaota_dupid;//

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
		uint32_t scenezid;//
		uint32_t factionid;//
		int32_t yaota_dupid;//

		virtual void write_to_pbmsg(::proto_ff::SocialRoleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SocialRoleProto & msg);
		static ::proto_ff::SocialRoleProto* new_pbmsg(){ return new ::proto_ff::SocialRoleProto(); }
		static ::proto_ff::SocialRoleProto make_pbmsg(){ return ::proto_ff::SocialRoleProto(); }
	};
	typedef struct SocialRoleProto_s SocialRoleProto_t;

	struct ClanView_s : public NFDescStoreSeqOP {
		ClanView_s();
		virtual ~ClanView_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t clan_id;//
		uint64_t cid;//
		int32_t clan_type;//
		NFShmString<32> clan_name;//
		int32_t badge_id;//
		NFShmString<32> badge_name;//

		virtual void write_to_pbmsg(::proto_ff::ClanView & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ClanView & msg);
		static ::proto_ff::ClanView* new_pbmsg(){ return new ::proto_ff::ClanView(); }
		static ::proto_ff::ClanView make_pbmsg(){ return ::proto_ff::ClanView(); }
	};
	typedef struct ClanView_s ClanView_t;

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

	struct TurnAttr_s : public NFDescStoreSeqOP {
		TurnAttr_s();
		virtual ~TurnAttr_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, DEFINE_TURNATTR_COM_POS_MAX_NUM> com_pos;//
		NFShmVector<int32_t, DEFINE_TURNATTR_STAR_POS_MAX_NUM> star_pos;//

		virtual void write_to_pbmsg(::proto_ff::TurnAttr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnAttr & msg);
		static ::proto_ff::TurnAttr* new_pbmsg(){ return new ::proto_ff::TurnAttr(); }
		static ::proto_ff::TurnAttr make_pbmsg(){ return ::proto_ff::TurnAttr(); }
	};
	typedef struct TurnAttr_s TurnAttr_t;

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
		uint64_t expireTime;//
		int32_t strong_lv;//
		int32_t strong_wear_quality;//
		int32_t strong_exp;//
		int32_t spec_lv;//
		int32_t strong_wear_quality_exp;//
		NFShmVector<struct Attr_s, DEFINE_ITEMPROTOINFO_MISC_MAX_NUM> misc;//
		int32_t makeId;//
		int32_t state;//
		NFShmVector<int32_t, DEFINE_ITEMPROTOINFO_GOLD_STAR_MAX_NUM> gold_star;//
		NFShmVector<int32_t, DEFINE_ITEMPROTOINFO_SILVER_STAR_MAX_NUM> silver_star;//
		uint64_t make_time;//
		NFShmString<32> make_name;//
		int32_t savvy;//
		NFShmVector<struct ComPair64_s, DEFINE_ITEMPROTOINFO_SKILL_MAX_NUM> skill;//
		int32_t evolve_lv;//
		int32_t awaken_lv;//
		struct TurnAttr_s turn_attr;//
		int64_t item_chg_count;//
		NFShmVector<int32_t, DEFINE_ITEMPROTOINFO_UNLOCK_ATTR_INDEX_MAX_NUM> unlock_attr_index;//
		uint32_t base_attr_percent;//
		uint32_t star_attr_percent;//
		uint32_t god_attr_percent;//

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

	struct RefineSlotInfo_s : public NFDescStoreSeqOP {
		RefineSlotInfo_s();
		virtual ~RefineSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t refine_lv;//
		NFShmVector<struct ComPair_s, DEFINE_REFINESLOTINFO_UNLOCKS_MAX_NUM> unlocks;//
		int32_t gm_lv;//
		NFShmVector<int32_t, DEFINE_REFINESLOTINFO_LOCK_POS_MAX_NUM> lock_pos;//

		virtual void write_to_pbmsg(::proto_ff::RefineSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RefineSlotInfo & msg);
		static ::proto_ff::RefineSlotInfo* new_pbmsg(){ return new ::proto_ff::RefineSlotInfo(); }
		static ::proto_ff::RefineSlotInfo make_pbmsg(){ return ::proto_ff::RefineSlotInfo(); }
	};
	typedef struct RefineSlotInfo_s RefineSlotInfo_t;

	struct SealSlotInfo_s : public NFDescStoreSeqOP {
		SealSlotInfo_s();
		virtual ~SealSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot;//
		int32_t itemid;//

		virtual void write_to_pbmsg(::proto_ff::SealSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SealSlotInfo & msg);
		static ::proto_ff::SealSlotInfo* new_pbmsg(){ return new ::proto_ff::SealSlotInfo(); }
		static ::proto_ff::SealSlotInfo make_pbmsg(){ return ::proto_ff::SealSlotInfo(); }
	};
	typedef struct SealSlotInfo_s SealSlotInfo_t;

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
		struct RefineSlotInfo_s refine;//
		int32_t awaken_lv;//
		int32_t awaken_break_flag;//
		int32_t soaring_lv;//
		int32_t quality_lv;//
		NFShmVector<struct SealSlotInfo_s, DEFINE_EQUIPSLOTINFO_SEAL_SLOTS_MAX_NUM> seal_slots;//
		NFShmVector<int32_t, DEFINE_EQUIPSLOTINFO_ACTIVE_SEAL_IDS_MAX_NUM> active_seal_ids;//

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

	struct PetGrow_s : public NFDescStoreSeqOP {
		PetGrow_s();
		virtual ~PetGrow_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t cfgid;//
		int32_t stronglv;//
		int32_t starlv;//
		int32_t starindex;//

		virtual void write_to_pbmsg(::proto_ff::PetGrow & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetGrow & msg);
		static ::proto_ff::PetGrow* new_pbmsg(){ return new ::proto_ff::PetGrow(); }
		static ::proto_ff::PetGrow make_pbmsg(){ return ::proto_ff::PetGrow(); }
	};
	typedef struct PetGrow_s PetGrow_t;

	struct PetYaoHunSlot_s : public NFDescStoreSeqOP {
		PetYaoHunSlot_s();
		virtual ~PetYaoHunSlot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot_pos;//
		int32_t lv;//
		int32_t exp;//
		int32_t step;//
		struct ItemProtoInfo_s equip;//

		virtual void write_to_pbmsg(::proto_ff::PetYaoHunSlot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetYaoHunSlot & msg);
		static ::proto_ff::PetYaoHunSlot* new_pbmsg(){ return new ::proto_ff::PetYaoHunSlot(); }
		static ::proto_ff::PetYaoHunSlot make_pbmsg(){ return ::proto_ff::PetYaoHunSlot(); }
	};
	typedef struct PetYaoHunSlot_s PetYaoHunSlot_t;

	struct PetYaoHunEntry_s : public NFDescStoreSeqOP {
		PetYaoHunEntry_s();
		virtual ~PetYaoHunEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t fight_pos;//
		int32_t is_unlock;//
		NFShmVector<struct PetYaoHunSlot_s, DEFINE_PETYAOHUNENTRY_INFOS_MAX_NUM> infos;//
		NFShmVector<int32_t, DEFINE_PETYAOHUNENTRY_SUITIDS_MAX_NUM> suitids;//

		virtual void write_to_pbmsg(::proto_ff::PetYaoHunEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetYaoHunEntry & msg);
		static ::proto_ff::PetYaoHunEntry* new_pbmsg(){ return new ::proto_ff::PetYaoHunEntry(); }
		static ::proto_ff::PetYaoHunEntry make_pbmsg(){ return ::proto_ff::PetYaoHunEntry(); }
	};
	typedef struct PetYaoHunEntry_s PetYaoHunEntry_t;

	struct PetYaoHunModule_s : public NFDescStoreSeqOP {
		PetYaoHunModule_s();
		virtual ~PetYaoHunModule_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct PetYaoHunEntry_s, DEFINE_PETYAOHUNMODULE_ENTRYS_MAX_NUM> entrys;//
		int32_t lianyao_tq_flag;//
		int32_t yaolu_lv;//
		int32_t yaolu_exp;//
		int32_t yaoqi;//

		virtual void write_to_pbmsg(::proto_ff::PetYaoHunModule & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PetYaoHunModule & msg);
		static ::proto_ff::PetYaoHunModule* new_pbmsg(){ return new ::proto_ff::PetYaoHunModule(); }
		static ::proto_ff::PetYaoHunModule make_pbmsg(){ return ::proto_ff::PetYaoHunModule(); }
	};
	typedef struct PetYaoHunModule_s PetYaoHunModule_t;

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
		uint64_t clan3_id;//
		uint64_t clan5_id;//

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
		uint32_t itemNum;//

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
		NFShmVector<struct ArenaChallResult_s, DEFINE_RELATIONDBINFO_ARENA_RESULT_MAX_NUM> arena_result;//

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
		int64_t param1;//

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
		NFShmVector<struct ItemProtoInfo_s, DEFINE_GODEVILPROTO_EQUIP_MAX_NUM> equip;//

		virtual void write_to_pbmsg(::proto_ff::GodEvilProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GodEvilProto & msg);
		static ::proto_ff::GodEvilProto* new_pbmsg(){ return new ::proto_ff::GodEvilProto(); }
		static ::proto_ff::GodEvilProto make_pbmsg(){ return ::proto_ff::GodEvilProto(); }
	};
	typedef struct GodEvilProto_s GodEvilProto_t;

	struct RechargeProto_s : public NFDescStoreSeqOP {
		RechargeProto_s();
		virtual ~RechargeProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<NFShmString<32>, DEFINE_RECHARGEPROTO_PRODUCT_MAX_NUM> product;//

		virtual void write_to_pbmsg(::proto_ff::RechargeProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RechargeProto & msg);
		static ::proto_ff::RechargeProto* new_pbmsg(){ return new ::proto_ff::RechargeProto(); }
		static ::proto_ff::RechargeProto make_pbmsg(){ return ::proto_ff::RechargeProto(); }
	};
	typedef struct RechargeProto_s RechargeProto_t;

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

	struct MountKunEquipData_s : public NFDescStoreSeqOP {
		MountKunEquipData_s();
		virtual ~MountKunEquipData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct EquipInfo_s, DEFINE_MOUNTKUNEQUIPDATA_INFOS_MAX_NUM> infos;//
		NFShmVector<uint32_t, DEFINE_MOUNTKUNEQUIPDATA_SLOT_STATUS_MAX_NUM> slot_status;//

		virtual void write_to_pbmsg(::proto_ff::MountKunEquipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountKunEquipData & msg);
		static ::proto_ff::MountKunEquipData* new_pbmsg(){ return new ::proto_ff::MountKunEquipData(); }
		static ::proto_ff::MountKunEquipData make_pbmsg(){ return ::proto_ff::MountKunEquipData(); }
	};
	typedef struct MountKunEquipData_s MountKunEquipData_t;

	struct MountKunEquipSuitData_s : public NFDescStoreSeqOP {
		MountKunEquipSuitData_s();
		virtual ~MountKunEquipSuitData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		uint32_t state;//

		virtual void write_to_pbmsg(::proto_ff::MountKunEquipSuitData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountKunEquipSuitData & msg);
		static ::proto_ff::MountKunEquipSuitData* new_pbmsg(){ return new ::proto_ff::MountKunEquipSuitData(); }
		static ::proto_ff::MountKunEquipSuitData make_pbmsg(){ return ::proto_ff::MountKunEquipSuitData(); }
	};
	typedef struct MountKunEquipSuitData_s MountKunEquipSuitData_t;

	struct MountKunData_s : public NFDescStoreSeqOP {
		MountKunData_s();
		virtual ~MountKunData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t kun_id;//
		uint32_t kun_lev;//
		uint64_t kun_lev_exp;//
		uint32_t kun_star;//
		uint32_t kun_advance_lev;//
		uint64_t fight;//
		struct MountKunEquipData_s equip_data;//
		NFShmVector<struct MountKunEquipSuitData_s, DEFINE_MOUNTKUNDATA_EQUIP_SUIT_DATA_MAX_NUM> equip_suit_data;//
		bool kun_tiwu_quality;//
		uint32_t kun_tiwu_level;//
		uint32_t kun_change_id;//

		virtual void write_to_pbmsg(::proto_ff::MountKunData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountKunData & msg);
		static ::proto_ff::MountKunData* new_pbmsg(){ return new ::proto_ff::MountKunData(); }
		static ::proto_ff::MountKunData make_pbmsg(){ return ::proto_ff::MountKunData(); }
	};
	typedef struct MountKunData_s MountKunData_t;

	struct MountKunChangeData_s : public NFDescStoreSeqOP {
		MountKunChangeData_s();
		virtual ~MountKunChangeData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t kun_change_id;//
		uint32_t kun_change_star;//
		bool kun_change_quality;//

		virtual void write_to_pbmsg(::proto_ff::MountKunChangeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountKunChangeData & msg);
		static ::proto_ff::MountKunChangeData* new_pbmsg(){ return new ::proto_ff::MountKunChangeData(); }
		static ::proto_ff::MountKunChangeData make_pbmsg(){ return ::proto_ff::MountKunChangeData(); }
	};
	typedef struct MountKunChangeData_s MountKunChangeData_t;

	struct MountBloodData_s : public NFDescStoreSeqOP {
		MountBloodData_s();
		virtual ~MountBloodData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t blood_id;//
		uint32_t blood_state;//
		struct ComPair64_s select_attr;//

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

	struct MountFairyLandTour_s : public NFDescStoreSeqOP {
		MountFairyLandTour_s();
		virtual ~MountFairyLandTour_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t tour_id;//
		uint32_t active_state;//

		virtual void write_to_pbmsg(::proto_ff::MountFairyLandTour & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFairyLandTour & msg);
		static ::proto_ff::MountFairyLandTour* new_pbmsg(){ return new ::proto_ff::MountFairyLandTour(); }
		static ::proto_ff::MountFairyLandTour make_pbmsg(){ return ::proto_ff::MountFairyLandTour(); }
	};
	typedef struct MountFairyLandTour_s MountFairyLandTour_t;

	struct MountFairyLand_s : public NFDescStoreSeqOP {
		MountFairyLand_s();
		virtual ~MountFairyLand_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t fairy_id;//
		NFShmVector<struct MountFairyLandTour_s, DEFINE_MOUNTFAIRYLAND_TOUR_MAX_NUM> tour;//
		bool active;//
		int64_t cur_active_tour_id;//

		virtual void write_to_pbmsg(::proto_ff::MountFairyLand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFairyLand & msg);
		static ::proto_ff::MountFairyLand* new_pbmsg(){ return new ::proto_ff::MountFairyLand(); }
		static ::proto_ff::MountFairyLand make_pbmsg(){ return ::proto_ff::MountFairyLand(); }
	};
	typedef struct MountFairyLand_s MountFairyLand_t;

	struct MountFairySlotRecord_s : public NFDescStoreSeqOP {
		MountFairySlotRecord_s();
		virtual ~MountFairySlotRecord_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t cur_fairy_id;//
		int64_t event_id;//
		int64_t create_time;//
		bool finish;//
		struct ComItem_s reward_item;//

		virtual void write_to_pbmsg(::proto_ff::MountFairySlotRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFairySlotRecord & msg);
		static ::proto_ff::MountFairySlotRecord* new_pbmsg(){ return new ::proto_ff::MountFairySlotRecord(); }
		static ::proto_ff::MountFairySlotRecord make_pbmsg(){ return ::proto_ff::MountFairySlotRecord(); }
	};
	typedef struct MountFairySlotRecord_s MountFairySlotRecord_t;

	struct MountFairySlot_s : public NFDescStoreSeqOP {
		MountFairySlot_s();
		virtual ~MountFairySlot_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t slot_id;//
		uint32_t cur_kun_id;//
		uint32_t cur_dissociate_level;//
		uint32_t cur_dissociate_time;//
		uint32_t cur_end_time;//
		uint32_t status;//
		bool can_get_reward;//
		NFShmVector<struct ComItem_s, DEFINE_MOUNTFAIRYSLOT_REWARD_ITEM_MAX_NUM> reward_item;//
		uint64_t reward_gold;//
		uint64_t reward_dia;//
		uint64_t reward_bdia;//
		NFShmVector<struct MountFairySlotRecord_s, DEFINE_MOUNTFAIRYSLOT_RECORD_MAX_NUM> record;//

		virtual void write_to_pbmsg(::proto_ff::MountFairySlot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MountFairySlot & msg);
		static ::proto_ff::MountFairySlot* new_pbmsg(){ return new ::proto_ff::MountFairySlot(); }
		static ::proto_ff::MountFairySlot make_pbmsg(){ return ::proto_ff::MountFairySlot(); }
	};
	typedef struct MountFairySlot_s MountFairySlot_t;

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
		int32_t all_num;//

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
		uint64_t ready_add_time;//
		bool is_fest_open;//

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
		int32_t vip_hide;//
		int32_t active_type;//
		uint64_t outtime;//
		int32_t can_recv_day_gift;//
		int32_t day_recv;//
		NFShmVector<int32_t, DEFINE_NOTIFYVIPDATARSP_LV_GIFT_MAX_NUM> lv_gift;//
		int32_t zero_state;//
		int32_t recv_zero;//
		uint64_t add_exp;//
		int32_t recv_exp;//

		virtual void write_to_pbmsg(::proto_ff::NotifyVipDataRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyVipDataRsp & msg);
		static ::proto_ff::NotifyVipDataRsp* new_pbmsg(){ return new ::proto_ff::NotifyVipDataRsp(); }
		static ::proto_ff::NotifyVipDataRsp make_pbmsg(){ return ::proto_ff::NotifyVipDataRsp(); }
	};
	typedef struct NotifyVipDataRsp_s NotifyVipDataRsp_t;

	struct NotifyPrivilegeOpt_s : public NFDescStoreSeqOP {
		NotifyPrivilegeOpt_s();
		virtual ~NotifyPrivilegeOpt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t opt;//
		NFShmVector<int32_t, DEFINE_NOTIFYPRIVILEGEOPT_IDS_MAX_NUM> ids;//

		virtual void write_to_pbmsg(::proto_ff::NotifyPrivilegeOpt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyPrivilegeOpt & msg);
		static ::proto_ff::NotifyPrivilegeOpt* new_pbmsg(){ return new ::proto_ff::NotifyPrivilegeOpt(); }
		static ::proto_ff::NotifyPrivilegeOpt make_pbmsg(){ return ::proto_ff::NotifyPrivilegeOpt(); }
	};
	typedef struct NotifyPrivilegeOpt_s NotifyPrivilegeOpt_t;

	struct BuyVipGiftReq_s : public NFDescStoreSeqOP {
		BuyVipGiftReq_s();
		virtual ~BuyVipGiftReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t opt;//
		int32_t lv;//

		virtual void write_to_pbmsg(::proto_ff::BuyVipGiftReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuyVipGiftReq & msg);
		static ::proto_ff::BuyVipGiftReq* new_pbmsg(){ return new ::proto_ff::BuyVipGiftReq(); }
		static ::proto_ff::BuyVipGiftReq make_pbmsg(){ return ::proto_ff::BuyVipGiftReq(); }
	};
	typedef struct BuyVipGiftReq_s BuyVipGiftReq_t;

	struct BuyVipGiftRsp_s : public NFDescStoreSeqOP {
		BuyVipGiftRsp_s();
		virtual ~BuyVipGiftRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t opt;//
		int32_t lv;//
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::BuyVipGiftRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BuyVipGiftRsp & msg);
		static ::proto_ff::BuyVipGiftRsp* new_pbmsg(){ return new ::proto_ff::BuyVipGiftRsp(); }
		static ::proto_ff::BuyVipGiftRsp make_pbmsg(){ return ::proto_ff::BuyVipGiftRsp(); }
	};
	typedef struct BuyVipGiftRsp_s BuyVipGiftRsp_t;

	struct RcveVipRewardReq_s : public NFDescStoreSeqOP {
		RcveVipRewardReq_s();
		virtual ~RcveVipRewardReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t opt;//

		virtual void write_to_pbmsg(::proto_ff::RcveVipRewardReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RcveVipRewardReq & msg);
		static ::proto_ff::RcveVipRewardReq* new_pbmsg(){ return new ::proto_ff::RcveVipRewardReq(); }
		static ::proto_ff::RcveVipRewardReq make_pbmsg(){ return ::proto_ff::RcveVipRewardReq(); }
	};
	typedef struct RcveVipRewardReq_s RcveVipRewardReq_t;

	struct RcveVipRewardRsp_s : public NFDescStoreSeqOP {
		RcveVipRewardRsp_s();
		virtual ~RcveVipRewardRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t opt;//
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::RcveVipRewardRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RcveVipRewardRsp & msg);
		static ::proto_ff::RcveVipRewardRsp* new_pbmsg(){ return new ::proto_ff::RcveVipRewardRsp(); }
		static ::proto_ff::RcveVipRewardRsp make_pbmsg(){ return ::proto_ff::RcveVipRewardRsp(); }
	};
	typedef struct RcveVipRewardRsp_s RcveVipRewardRsp_t;

	struct VipHideReq_s : public NFDescStoreSeqOP {
		VipHideReq_s();
		virtual ~VipHideReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t hide;//

		virtual void write_to_pbmsg(::proto_ff::VipHideReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::VipHideReq & msg);
		static ::proto_ff::VipHideReq* new_pbmsg(){ return new ::proto_ff::VipHideReq(); }
		static ::proto_ff::VipHideReq make_pbmsg(){ return ::proto_ff::VipHideReq(); }
	};
	typedef struct VipHideReq_s VipHideReq_t;

	struct VipHideRsp_s : public NFDescStoreSeqOP {
		VipHideRsp_s();
		virtual ~VipHideRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t hide;//
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::VipHideRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::VipHideRsp & msg);
		static ::proto_ff::VipHideRsp* new_pbmsg(){ return new ::proto_ff::VipHideRsp(); }
		static ::proto_ff::VipHideRsp make_pbmsg(){ return ::proto_ff::VipHideRsp(); }
	};
	typedef struct VipHideRsp_s VipHideRsp_t;

	struct NotifyVipEvent_s : public NFDescStoreSeqOP {
		NotifyVipEvent_s();
		virtual ~NotifyVipEvent_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;//

		virtual void write_to_pbmsg(::proto_ff::NotifyVipEvent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyVipEvent & msg);
		static ::proto_ff::NotifyVipEvent* new_pbmsg(){ return new ::proto_ff::NotifyVipEvent(); }
		static ::proto_ff::NotifyVipEvent make_pbmsg(){ return ::proto_ff::NotifyVipEvent(); }
	};
	typedef struct NotifyVipEvent_s NotifyVipEvent_t;

	struct RecvVipCacheExpReq_s : public NFDescStoreSeqOP {
		RecvVipCacheExpReq_s();
		virtual ~RecvVipCacheExpReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::RecvVipCacheExpReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RecvVipCacheExpReq & msg);
		static ::proto_ff::RecvVipCacheExpReq* new_pbmsg(){ return new ::proto_ff::RecvVipCacheExpReq(); }
		static ::proto_ff::RecvVipCacheExpReq make_pbmsg(){ return ::proto_ff::RecvVipCacheExpReq(); }
	};
	typedef struct RecvVipCacheExpReq_s RecvVipCacheExpReq_t;

	struct RecvVipCacheExpRsp_s : public NFDescStoreSeqOP {
		RecvVipCacheExpRsp_s();
		virtual ~RecvVipCacheExpRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::RecvVipCacheExpRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RecvVipCacheExpRsp & msg);
		static ::proto_ff::RecvVipCacheExpRsp* new_pbmsg(){ return new ::proto_ff::RecvVipCacheExpRsp(); }
		static ::proto_ff::RecvVipCacheExpRsp make_pbmsg(){ return ::proto_ff::RecvVipCacheExpRsp(); }
	};
	typedef struct RecvVipCacheExpRsp_s RecvVipCacheExpRsp_t;

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
		int32_t pourId;//
		int32_t pourExp;//
		int32_t pourUnLock;//
		struct BestEQBreak_s breakInfo;//
		int32_t awakenLv;//
		struct ItemProtoInfo_s dressEquip;//

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

	struct OneAchievementData_s : public NFDescStoreSeqOP {
		OneAchievementData_s();
		virtual ~OneAchievementData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		int32_t status;//
		int32_t all_num;//
		int32_t cur_num;//

		virtual void write_to_pbmsg(::proto_ff::OneAchievementData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneAchievementData & msg);
		static ::proto_ff::OneAchievementData* new_pbmsg(){ return new ::proto_ff::OneAchievementData(); }
		static ::proto_ff::OneAchievementData make_pbmsg(){ return ::proto_ff::OneAchievementData(); }
	};
	typedef struct OneAchievementData_s OneAchievementData_t;

	struct OneXiuZhenRoadTaskData_s : public NFDescStoreSeqOP {
		OneXiuZhenRoadTaskData_s();
		virtual ~OneXiuZhenRoadTaskData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		int32_t status;//
		int32_t all_num;//
		int32_t cur_num;//

		virtual void write_to_pbmsg(::proto_ff::OneXiuZhenRoadTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadTaskData & msg);
		static ::proto_ff::OneXiuZhenRoadTaskData* new_pbmsg(){ return new ::proto_ff::OneXiuZhenRoadTaskData(); }
		static ::proto_ff::OneXiuZhenRoadTaskData make_pbmsg(){ return ::proto_ff::OneXiuZhenRoadTaskData(); }
	};
	typedef struct OneXiuZhenRoadTaskData_s OneXiuZhenRoadTaskData_t;

	struct OneXiuZhenRoadPointsData_s : public NFDescStoreSeqOP {
		OneXiuZhenRoadPointsData_s();
		virtual ~OneXiuZhenRoadPointsData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::OneXiuZhenRoadPointsData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadPointsData & msg);
		static ::proto_ff::OneXiuZhenRoadPointsData* new_pbmsg(){ return new ::proto_ff::OneXiuZhenRoadPointsData(); }
		static ::proto_ff::OneXiuZhenRoadPointsData make_pbmsg(){ return ::proto_ff::OneXiuZhenRoadPointsData(); }
	};
	typedef struct OneXiuZhenRoadPointsData_s OneXiuZhenRoadPointsData_t;

	struct OneXiuZhenRoadRechargeData_s : public NFDescStoreSeqOP {
		OneXiuZhenRoadRechargeData_s();
		virtual ~OneXiuZhenRoadRechargeData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::OneXiuZhenRoadRechargeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadRechargeData & msg);
		static ::proto_ff::OneXiuZhenRoadRechargeData* new_pbmsg(){ return new ::proto_ff::OneXiuZhenRoadRechargeData(); }
		static ::proto_ff::OneXiuZhenRoadRechargeData make_pbmsg(){ return ::proto_ff::OneXiuZhenRoadRechargeData(); }
	};
	typedef struct OneXiuZhenRoadRechargeData_s OneXiuZhenRoadRechargeData_t;

	struct OneGoalTaskData_s : public NFDescStoreSeqOP {
		OneGoalTaskData_s();
		virtual ~OneGoalTaskData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t task_id;//
		int32_t group_id;//
		int32_t task_status;//
		int32_t all_num;//
		int32_t cur_num;//

		virtual void write_to_pbmsg(::proto_ff::OneGoalTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneGoalTaskData & msg);
		static ::proto_ff::OneGoalTaskData* new_pbmsg(){ return new ::proto_ff::OneGoalTaskData(); }
		static ::proto_ff::OneGoalTaskData make_pbmsg(){ return ::proto_ff::OneGoalTaskData(); }
	};
	typedef struct OneGoalTaskData_s OneGoalTaskData_t;

	struct OneGoalData_s : public NFDescStoreSeqOP {
		OneGoalData_s();
		virtual ~OneGoalData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t group_id;//
		int32_t group_status;//
		NFShmVector<struct OneGoalTaskData_s, DEFINE_ONEGOALDATA_DATA_MAX_NUM> data;//

		virtual void write_to_pbmsg(::proto_ff::OneGoalData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneGoalData & msg);
		static ::proto_ff::OneGoalData* new_pbmsg(){ return new ::proto_ff::OneGoalData(); }
		static ::proto_ff::OneGoalData make_pbmsg(){ return ::proto_ff::OneGoalData(); }
	};
	typedef struct OneGoalData_s OneGoalData_t;

	struct OneBattlePassRewardData_s : public NFDescStoreSeqOP {
		OneBattlePassRewardData_s();
		virtual ~OneBattlePassRewardData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t super_status;//

		virtual void write_to_pbmsg(::proto_ff::OneBattlePassRewardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneBattlePassRewardData & msg);
		static ::proto_ff::OneBattlePassRewardData* new_pbmsg(){ return new ::proto_ff::OneBattlePassRewardData(); }
		static ::proto_ff::OneBattlePassRewardData make_pbmsg(){ return ::proto_ff::OneBattlePassRewardData(); }
	};
	typedef struct OneBattlePassRewardData_s OneBattlePassRewardData_t;

	struct OneBattlePassTaskData_s : public NFDescStoreSeqOP {
		OneBattlePassTaskData_s();
		virtual ~OneBattlePassTaskData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t task_id;//
		int32_t task_status;//
		int32_t cur_num;//
		int32_t all_num;//

		virtual void write_to_pbmsg(::proto_ff::OneBattlePassTaskData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneBattlePassTaskData & msg);
		static ::proto_ff::OneBattlePassTaskData* new_pbmsg(){ return new ::proto_ff::OneBattlePassTaskData(); }
		static ::proto_ff::OneBattlePassTaskData make_pbmsg(){ return ::proto_ff::OneBattlePassTaskData(); }
	};
	typedef struct OneBattlePassTaskData_s OneBattlePassTaskData_t;

	struct OneBattlePassShopData_s : public NFDescStoreSeqOP {
		OneBattlePassShopData_s();
		virtual ~OneBattlePassShopData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur_num;//
		int32_t all_num;//

		virtual void write_to_pbmsg(::proto_ff::OneBattlePassShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneBattlePassShopData & msg);
		static ::proto_ff::OneBattlePassShopData* new_pbmsg(){ return new ::proto_ff::OneBattlePassShopData(); }
		static ::proto_ff::OneBattlePassShopData make_pbmsg(){ return ::proto_ff::OneBattlePassShopData(); }
	};
	typedef struct OneBattlePassShopData_s OneBattlePassShopData_t;

	struct OneBattlePassData_s : public NFDescStoreSeqOP {
		OneBattlePassData_s();
		virtual ~OneBattlePassData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t buy_status;//
		int32_t exp;//
		int32_t lv;//
		NFShmVector<struct OneBattlePassRewardData_s, DEFINE_ONEBATTLEPASSDATA_REWARD_MAX_NUM> reward;//
		NFShmVector<struct OneBattlePassTaskData_s, DEFINE_ONEBATTLEPASSDATA_TASK_MAX_NUM> task;//
		NFShmVector<struct OneBattlePassShopData_s, DEFINE_ONEBATTLEPASSDATA_SHOP_MAX_NUM> shop;//

		virtual void write_to_pbmsg(::proto_ff::OneBattlePassData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneBattlePassData & msg);
		static ::proto_ff::OneBattlePassData* new_pbmsg(){ return new ::proto_ff::OneBattlePassData(); }
		static ::proto_ff::OneBattlePassData make_pbmsg(){ return ::proto_ff::OneBattlePassData(); }
	};
	typedef struct OneBattlePassData_s OneBattlePassData_t;

	struct BattlePassData_s : public NFDescStoreSeqOP {
		BattlePassData_s();
		virtual ~BattlePassData_s(){}
		int CreateInit();
		int ResumeInit();
		struct OneBattlePassData_s xian_ce;//
		struct OneBattlePassData_s bao_ding;//
		uint64_t flush_time;//

		virtual void write_to_pbmsg(::proto_ff::BattlePassData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::BattlePassData & msg);
		static ::proto_ff::BattlePassData* new_pbmsg(){ return new ::proto_ff::BattlePassData(); }
		static ::proto_ff::BattlePassData make_pbmsg(){ return ::proto_ff::BattlePassData(); }
	};
	typedef struct BattlePassData_s BattlePassData_t;

	struct AchievementData_s : public NFDescStoreSeqOP {
		AchievementData_s();
		virtual ~AchievementData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t ach_point;//
		NFShmVector<struct OneAchievementData_s, DEFINE_ACHIEVEMENTDATA_ACH_DATA_MAX_NUM> ach_data;//
		NFShmVector<struct OneAchievementData_s, DEFINE_ACHIEVEMENTDATA_ACH_TOTAL_DATA_MAX_NUM> ach_total_data;//
		NFShmVector<struct OneXiuZhenRoadTaskData_s, DEFINE_ACHIEVEMENTDATA_XIUZHENROAD_DATA_MAX_NUM> xiuzhenroad_data;//
		uint64_t xiuezhenroad_point;//
		NFShmVector<struct OneXiuZhenRoadPointsData_s, DEFINE_ACHIEVEMENTDATA_XIUZHENROAD_POINTS_DATA_MAX_NUM> xiuzhenroad_points_data;//
		NFShmVector<struct OneXiuZhenRoadRechargeData_s, DEFINE_ACHIEVEMENTDATA_XIUZHEROAD_RECHARGE_DATA_MAX_NUM> xiuzheroad_recharge_data;//
		uint64_t xiuzhenroad_open_time;//
		uint32_t xiuzhenroad_back_status;//
		NFShmVector<struct OneGoalData_s, DEFINE_ACHIEVEMENTDATA_GOAL_DATA_MAX_NUM> goal_data;//
		struct BattlePassData_s battle_pass;//

		virtual void write_to_pbmsg(::proto_ff::AchievementData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AchievementData & msg);
		static ::proto_ff::AchievementData* new_pbmsg(){ return new ::proto_ff::AchievementData(); }
		static ::proto_ff::AchievementData make_pbmsg(){ return ::proto_ff::AchievementData(); }
	};
	typedef struct AchievementData_s AchievementData_t;

	struct PTGBEventItem_s : public NFDescStoreSeqOP {
		PTGBEventItem_s();
		virtual ~PTGBEventItem_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint64_t num;//

		virtual void write_to_pbmsg(::proto_ff::PTGBEventItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTGBEventItem & msg);
		static ::proto_ff::PTGBEventItem* new_pbmsg(){ return new ::proto_ff::PTGBEventItem(); }
		static ::proto_ff::PTGBEventItem make_pbmsg(){ return ::proto_ff::PTGBEventItem(); }
	};
	typedef struct PTGBEventItem_s PTGBEventItem_t;

	struct PTGBEventLog_s : public NFDescStoreSeqOP {
		PTGBEventLog_s();
		virtual ~PTGBEventLog_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t evtId;//
		uint64_t time;//
		uint64_t energyAdd;//
		NFShmVector<struct PTGBEventItem_s, DEFINE_PTGBEVENTLOG_ITEMS_MAX_NUM> items;//

		virtual void write_to_pbmsg(::proto_ff::PTGBEventLog & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTGBEventLog & msg);
		static ::proto_ff::PTGBEventLog* new_pbmsg(){ return new ::proto_ff::PTGBEventLog(); }
		static ::proto_ff::PTGBEventLog make_pbmsg(){ return ::proto_ff::PTGBEventLog(); }
	};
	typedef struct PTGBEventLog_s PTGBEventLog_t;

	struct PTFuncMagic_s : public NFDescStoreSeqOP {
		PTFuncMagic_s();
		virtual ~PTFuncMagic_s(){}
		int CreateInit();
		int ResumeInit();
		bool actived;//
		uint32_t lvl;//
		uint32_t stage;//

		virtual void write_to_pbmsg(::proto_ff::PTFuncMagic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTFuncMagic & msg);
		static ::proto_ff::PTFuncMagic* new_pbmsg(){ return new ::proto_ff::PTFuncMagic(); }
		static ::proto_ff::PTFuncMagic make_pbmsg(){ return ::proto_ff::PTFuncMagic(); }
	};
	typedef struct PTFuncMagic_s PTFuncMagic_t;

	struct PTlg_s : public NFDescStoreSeqOP {
		PTlg_s();
		virtual ~PTlg_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t lvl;//
		uint32_t points;//

		virtual void write_to_pbmsg(::proto_ff::PTlg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTlg & msg);
		static ::proto_ff::PTlg* new_pbmsg(){ return new ::proto_ff::PTlg(); }
		static ::proto_ff::PTlg make_pbmsg(){ return ::proto_ff::PTlg(); }
	};
	typedef struct PTlg_s PTlg_t;

	struct PTlgPotion_s : public NFDescStoreSeqOP {
		PTlgPotion_s();
		virtual ~PTlgPotion_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t eatCount;//

		virtual void write_to_pbmsg(::proto_ff::PTlgPotion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTlgPotion & msg);
		static ::proto_ff::PTlgPotion* new_pbmsg(){ return new ::proto_ff::PTlgPotion(); }
		static ::proto_ff::PTlgPotion make_pbmsg(){ return ::proto_ff::PTlgPotion(); }
	};
	typedef struct PTlgPotion_s PTlgPotion_t;

	struct PTjm_s : public NFDescStoreSeqOP {
		PTjm_s();
		virtual ~PTjm_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t lvl;//
		uint32_t stage;//

		virtual void write_to_pbmsg(::proto_ff::PTjm & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTjm & msg);
		static ::proto_ff::PTjm* new_pbmsg(){ return new ::proto_ff::PTjm(); }
		static ::proto_ff::PTjm make_pbmsg(){ return ::proto_ff::PTjm(); }
	};
	typedef struct PTjm_s PTjm_t;

	struct PTPurchaseRecord_s : public NFDescStoreSeqOP {
		PTPurchaseRecord_s();
		virtual ~PTPurchaseRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::PTPurchaseRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PTPurchaseRecord & msg);
		static ::proto_ff::PTPurchaseRecord* new_pbmsg(){ return new ::proto_ff::PTPurchaseRecord(); }
		static ::proto_ff::PTPurchaseRecord make_pbmsg(){ return ::proto_ff::PTPurchaseRecord(); }
	};
	typedef struct PTPurchaseRecord_s PTPurchaseRecord_t;

	struct PracticeTrueDBData_s : public NFDescStoreSeqOP {
		PracticeTrueDBData_s();
		virtual ~PracticeTrueDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t level;//
		uint32_t djRateAdd;//
		uint32_t djFailInvigoration;//
		uint64_t gbEnergy;//
		uint32_t gbEventRate;//
		uint32_t gbEnergyCritRate;//
		uint32_t gbLevel;//
		uint32_t gbArea;//
		NFShmVector<struct PTGBEventLog_s, DEFINE_PRACTICETRUEDBDATA_GBEVENTSLOG_MAX_NUM> gbEventsLog;//
		NFShmVector<struct PTGBEventItem_s, DEFINE_PRACTICETRUEDBDATA_GBEVENTITEMS_MAX_NUM> gbEventItems;//
		uint64_t gbXLRemainTime;//
		uint32_t ebLevel;//
		uint32_t ebLvlUpRate;//
		NFShmVector<struct PTFuncMagic_s, DEFINE_PRACTICETRUEDBDATA_GFLIST_MAX_NUM> gfList;//
		uint32_t ebFlyRateAdd;//
		uint32_t ebFlyFailInvigoration;//
		NFShmVector<struct PTlg_s, DEFINE_PRACTICETRUEDBDATA_LGLIST_MAX_NUM> lgList;//
		NFShmVector<struct PTlgPotion_s, DEFINE_PRACTICETRUEDBDATA_LGPOTIONS_MAX_NUM> lgPotions;//
		NFShmVector<struct PTjm_s, DEFINE_PRACTICETRUEDBDATA_JMLIST_MAX_NUM> jmList;//
		uint32_t jmLvlUpRateAdd;//
		uint32_t jmStageUpRateAdd;//
		uint32_t jmStageUpFailInvigoration;//
		uint32_t jmMergeLvl;//
		NFShmVector<struct PTPurchaseRecord_s, DEFINE_PRACTICETRUEDBDATA_PURCHASEDLIST_MAX_NUM> purchasedList;//
		uint32_t gbXLForever;//
		uint32_t gbXWPAdd;//
		uint32_t gbXLEventGetItemRate;//
		uint32_t gbXLEventXWPAdd;//
		uint32_t ebFlyFailInvigorationAdd;//
		NFShmVector<struct PTPurchaseRecord_s, DEFINE_PRACTICETRUEDBDATA_GFBOOKPURCHASEDLIST_MAX_NUM> gfBookPurchasedList;//

		virtual void write_to_pbmsg(::proto_ff::PracticeTrueDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PracticeTrueDBData & msg);
		static ::proto_ff::PracticeTrueDBData* new_pbmsg(){ return new ::proto_ff::PracticeTrueDBData(); }
		static ::proto_ff::PracticeTrueDBData make_pbmsg(){ return ::proto_ff::PracticeTrueDBData(); }
	};
	typedef struct PracticeTrueDBData_s PracticeTrueDBData_t;

	struct AncientSlotInfo_s : public NFDescStoreSeqOP {
		AncientSlotInfo_s();
		virtual ~AncientSlotInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t slot;//
		int32_t step;//
		int32_t step_value;//
		int32_t bless;//
		NFShmVector<int32_t, DEFINE_ANCIENTSLOTINFO_ATTR_INDEX_MAX_NUM> attr_index;//

		virtual void write_to_pbmsg(::proto_ff::AncientSlotInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AncientSlotInfo & msg);
		static ::proto_ff::AncientSlotInfo* new_pbmsg(){ return new ::proto_ff::AncientSlotInfo(); }
		static ::proto_ff::AncientSlotInfo make_pbmsg(){ return ::proto_ff::AncientSlotInfo(); }
	};
	typedef struct AncientSlotInfo_s AncientSlotInfo_t;

	struct AncientInfo_s : public NFDescStoreSeqOP {
		AncientInfo_s();
		virtual ~AncientInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		NFShmVector<int32_t, DEFINE_ANCIENTINFO_UNLOCK_NUM_MAX_NUM> unlock_num;//
		int32_t lock;//
		NFShmVector<struct AncientSlotInfo_s, DEFINE_ANCIENTINFO_SLOTS_MAX_NUM> slots;//

		virtual void write_to_pbmsg(::proto_ff::AncientInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::AncientInfo & msg);
		static ::proto_ff::AncientInfo* new_pbmsg(){ return new ::proto_ff::AncientInfo(); }
		static ::proto_ff::AncientInfo make_pbmsg(){ return ::proto_ff::AncientInfo(); }
	};
	typedef struct AncientInfo_s AncientInfo_t;

	struct MarryChild_s : public NFDescStoreSeqOP {
		MarryChild_s();
		virtual ~MarryChild_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t lv;//
		int32_t exp;//
		int32_t star;//

		virtual void write_to_pbmsg(::proto_ff::MarryChild & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryChild & msg);
		static ::proto_ff::MarryChild* new_pbmsg(){ return new ::proto_ff::MarryChild(); }
		static ::proto_ff::MarryChild make_pbmsg(){ return ::proto_ff::MarryChild(); }
	};
	typedef struct MarryChild_s MarryChild_t;

	struct MarrySelfInfo_s : public NFDescStoreSeqOP {
		MarrySelfInfo_s();
		virtual ~MarrySelfInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t marry_flag;//
		int32_t lock_lv;//
		int32_t lock_exp;//
		uint64_t card_buy_time;//
		int32_t child_id;//
		NFShmVector<struct MarryChild_s, DEFINE_MARRYSELFINFO_CHILDS_MAX_NUM> childs;//
		int32_t express_lv;//
		int32_t express_exp;//
		NFShmVector<int32_t, DEFINE_MARRYSELFINFO_GEARS_MAX_NUM> gears;//
		uint64_t child_hatch_time;//
		int32_t buy_dup_num;//
		int32_t dst_give_dup_num;//
		int32_t enter_marry_dup_num;//
		int32_t marry_id;//
		NFShmVector<int32_t, DEFINE_MARRYSELFINFO_RECVED_GEARS_MAX_NUM> recved_gears;//
		int32_t cur_can_recv_gear;//
		int32_t recv_child;//
		int32_t buy_card_reward_state;//
		int32_t card_reward_state;//
		int32_t dst_card_reward_state;//
		int32_t card_surplus_day;//
		int32_t recv_self_box_days;//
		int32_t task_state;//

		virtual void write_to_pbmsg(::proto_ff::MarrySelfInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarrySelfInfo & msg);
		static ::proto_ff::MarrySelfInfo* new_pbmsg(){ return new ::proto_ff::MarrySelfInfo(); }
		static ::proto_ff::MarrySelfInfo make_pbmsg(){ return ::proto_ff::MarrySelfInfo(); }
	};
	typedef struct MarrySelfInfo_s MarrySelfInfo_t;

	struct MarryWeddingInfo_s : public NFDescStoreSeqOP {
		MarryWeddingInfo_s();
		virtual ~MarryWeddingInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		uint64_t start_time;//
		uint64_t end_time;//
		NFShmVector<struct RolePlayerMiniInfo_s, DEFINE_MARRYWEDDINGINFO_MINI_MAX_NUM> mini;//
		NFShmVector<uint64_t, DEFINE_MARRYWEDDINGINFO_INVITE_LIST_MAX_NUM> invite_list;//

		virtual void write_to_pbmsg(::proto_ff::MarryWeddingInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MarryWeddingInfo & msg);
		static ::proto_ff::MarryWeddingInfo* new_pbmsg(){ return new ::proto_ff::MarryWeddingInfo(); }
		static ::proto_ff::MarryWeddingInfo make_pbmsg(){ return ::proto_ff::MarryWeddingInfo(); }
	};
	typedef struct MarryWeddingInfo_s MarryWeddingInfo_t;

	struct ExpressLog_s : public NFDescStoreSeqOP {
		ExpressLog_s();
		virtual ~ExpressLog_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> src_name;//
		uint64_t src_id;//
		NFShmString<32> dst_name;//
		uint64_t dst_id;//
		int32_t text_id;//
		uint64_t item;//

		virtual void write_to_pbmsg(::proto_ff::ExpressLog & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ExpressLog & msg);
		static ::proto_ff::ExpressLog* new_pbmsg(){ return new ::proto_ff::ExpressLog(); }
		static ::proto_ff::ExpressLog make_pbmsg(){ return ::proto_ff::ExpressLog(); }
	};
	typedef struct ExpressLog_s ExpressLog_t;

	struct WeddingDBInfo_s : public NFDescStoreSeqOP {
		WeddingDBInfo_s();
		virtual ~WeddingDBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t wedding_id;//
		int32_t wedding_gear;//
		uint64_t src_cid;//
		uint64_t dst_cid;//
		int32_t marry_id;//
		NFShmVector<int32_t, DEFINE_WEDDINGDBINFO_INVITE_LIST_MAX_NUM> invite_list;//
		NFShmVector<int32_t, DEFINE_WEDDINGDBINFO_APPLY_LIST_MAX_NUM> apply_list;//
		int32_t add_num;//

		virtual void write_to_pbmsg(::proto_ff::WeddingDBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WeddingDBInfo & msg);
		static ::proto_ff::WeddingDBInfo* new_pbmsg(){ return new ::proto_ff::WeddingDBInfo(); }
		static ::proto_ff::WeddingDBInfo make_pbmsg(){ return ::proto_ff::WeddingDBInfo(); }
	};
	typedef struct WeddingDBInfo_s WeddingDBInfo_t;

	struct WeddingDBList_s : public NFDescStoreSeqOP {
		WeddingDBList_s();
		virtual ~WeddingDBList_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct WeddingDBInfo_s, DEFINE_WEDDINGDBLIST_INFOS_MAX_NUM> infos;//
		uint64_t last_times;//

		virtual void write_to_pbmsg(::proto_ff::WeddingDBList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WeddingDBList & msg);
		static ::proto_ff::WeddingDBList* new_pbmsg(){ return new ::proto_ff::WeddingDBList(); }
		static ::proto_ff::WeddingDBList make_pbmsg(){ return ::proto_ff::WeddingDBList(); }
	};
	typedef struct WeddingDBList_s WeddingDBList_t;

	struct WeddingSimpleInfo_s : public NFDescStoreSeqOP {
		WeddingSimpleInfo_s();
		virtual ~WeddingSimpleInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t wedding_id;//
		int32_t wedding_gear;//
		struct RolePlayerMiniInfo_s src;//
		struct RolePlayerMiniInfo_s dst;//
		int32_t marry_id;//
		uint64_t apply_end_time;//
		uint64_t tour_start_time;//
		uint64_t start_time;//
		uint64_t end_time;//
		int32_t step;//

		virtual void write_to_pbmsg(::proto_ff::WeddingSimpleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WeddingSimpleInfo & msg);
		static ::proto_ff::WeddingSimpleInfo* new_pbmsg(){ return new ::proto_ff::WeddingSimpleInfo(); }
		static ::proto_ff::WeddingSimpleInfo make_pbmsg(){ return ::proto_ff::WeddingSimpleInfo(); }
	};
	typedef struct WeddingSimpleInfo_s WeddingSimpleInfo_t;

	struct WeddingDetail_s : public NFDescStoreSeqOP {
		WeddingDetail_s();
		virtual ~WeddingDetail_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t wedding_id;//
		int32_t wedding_gear;//
		NFShmVector<struct RolePlayerMiniInfo_s, DEFINE_WEDDINGDETAIL_INVITE_LIST_MAX_NUM> invite_list;//
		NFShmVector<struct RolePlayerMiniInfo_s, DEFINE_WEDDINGDETAIL_APPLY_LIST_MAX_NUM> apply_list;//
		int32_t add_num;//

		virtual void write_to_pbmsg(::proto_ff::WeddingDetail & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WeddingDetail & msg);
		static ::proto_ff::WeddingDetail* new_pbmsg(){ return new ::proto_ff::WeddingDetail(); }
		static ::proto_ff::WeddingDetail make_pbmsg(){ return ::proto_ff::WeddingDetail(); }
	};
	typedef struct WeddingDetail_s WeddingDetail_t;

	struct WeddingDupRoleInfo_s : public NFDescStoreSeqOP {
		WeddingDupRoleInfo_s();
		virtual ~WeddingDupRoleInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t sign_num;//
		int32_t cake_reward_num;//
		int32_t kill_monster_reward_num;//
		uint64_t add_exp;//

		virtual void write_to_pbmsg(::proto_ff::WeddingDupRoleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WeddingDupRoleInfo & msg);
		static ::proto_ff::WeddingDupRoleInfo* new_pbmsg(){ return new ::proto_ff::WeddingDupRoleInfo(); }
		static ::proto_ff::WeddingDupRoleInfo make_pbmsg(){ return ::proto_ff::WeddingDupRoleInfo(); }
	};
	typedef struct WeddingDupRoleInfo_s WeddingDupRoleInfo_t;

	struct GlobalExpressLog_s : public NFDescStoreSeqOP {
		GlobalExpressLog_s();
		virtual ~GlobalExpressLog_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ExpressLog_s, DEFINE_GLOBALEXPRESSLOG_LOGS_MAX_NUM> logs;//

		virtual void write_to_pbmsg(::proto_ff::GlobalExpressLog & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GlobalExpressLog & msg);
		static ::proto_ff::GlobalExpressLog* new_pbmsg(){ return new ::proto_ff::GlobalExpressLog(); }
		static ::proto_ff::GlobalExpressLog make_pbmsg(){ return ::proto_ff::GlobalExpressLog(); }
	};
	typedef struct GlobalExpressLog_s GlobalExpressLog_t;

	struct SceneProto_s : public NFDescStoreSeqOP {
		SceneProto_s();
		virtual ~SceneProto_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t zid;//
		uint64_t sceneid;//
		uint64_t mapid;//

		virtual void write_to_pbmsg(::proto_ff::SceneProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SceneProto & msg);
		static ::proto_ff::SceneProto* new_pbmsg(){ return new ::proto_ff::SceneProto(); }
		static ::proto_ff::SceneProto make_pbmsg(){ return ::proto_ff::SceneProto(); }
	};
	typedef struct SceneProto_s SceneProto_t;

	struct HandBookPBInfo_s : public NFDescStoreSeqOP {
		HandBookPBInfo_s();
		virtual ~HandBookPBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t level;//
		uint32_t star;//
		NFShmVector<uint64_t, DEFINE_HANDBOOKPBINFO_SKILLS_MAX_NUM> skills;//

		virtual void write_to_pbmsg(::proto_ff::HandBookPBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookPBInfo & msg);
		static ::proto_ff::HandBookPBInfo* new_pbmsg(){ return new ::proto_ff::HandBookPBInfo(); }
		static ::proto_ff::HandBookPBInfo make_pbmsg(){ return ::proto_ff::HandBookPBInfo(); }
	};
	typedef struct HandBookPBInfo_s HandBookPBInfo_t;

	struct HandBookEmployPBInfo_s : public NFDescStoreSeqOP {
		HandBookEmployPBInfo_s();
		virtual ~HandBookEmployPBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::HandBookEmployPBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookEmployPBInfo & msg);
		static ::proto_ff::HandBookEmployPBInfo* new_pbmsg(){ return new ::proto_ff::HandBookEmployPBInfo(); }
		static ::proto_ff::HandBookEmployPBInfo make_pbmsg(){ return ::proto_ff::HandBookEmployPBInfo(); }
	};
	typedef struct HandBookEmployPBInfo_s HandBookEmployPBInfo_t;

	struct HandBookTablePBInfo_s : public NFDescStoreSeqOP {
		HandBookTablePBInfo_s();
		virtual ~HandBookTablePBInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::HandBookTablePBInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookTablePBInfo & msg);
		static ::proto_ff::HandBookTablePBInfo* new_pbmsg(){ return new ::proto_ff::HandBookTablePBInfo(); }
		static ::proto_ff::HandBookTablePBInfo make_pbmsg(){ return ::proto_ff::HandBookTablePBInfo(); }
	};
	typedef struct HandBookTablePBInfo_s HandBookTablePBInfo_t;

	struct HandBookBeastEquipData_s : public NFDescStoreSeqOP {
		HandBookBeastEquipData_s();
		virtual ~HandBookBeastEquipData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct EquipInfo_s, DEFINE_HANDBOOKBEASTEQUIPDATA_INFOS_MAX_NUM> infos;//
		NFShmVector<struct EquipLvAttrInfo_s, DEFINE_HANDBOOKBEASTEQUIPDATA_LV_ATTR_MAX_NUM> lv_attr;//

		virtual void write_to_pbmsg(::proto_ff::HandBookBeastEquipData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookBeastEquipData & msg);
		static ::proto_ff::HandBookBeastEquipData* new_pbmsg(){ return new ::proto_ff::HandBookBeastEquipData(); }
		static ::proto_ff::HandBookBeastEquipData make_pbmsg(){ return ::proto_ff::HandBookBeastEquipData(); }
	};
	typedef struct HandBookBeastEquipData_s HandBookBeastEquipData_t;

	struct HandBookBeastPBData_s : public NFDescStoreSeqOP {
		HandBookBeastPBData_s();
		virtual ~HandBookBeastPBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint32_t status;//
		struct HandBookBeastEquipData_s equip_data;//

		virtual void write_to_pbmsg(::proto_ff::HandBookBeastPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookBeastPBData & msg);
		static ::proto_ff::HandBookBeastPBData* new_pbmsg(){ return new ::proto_ff::HandBookBeastPBData(); }
		static ::proto_ff::HandBookBeastPBData make_pbmsg(){ return ::proto_ff::HandBookBeastPBData(); }
	};
	typedef struct HandBookBeastPBData_s HandBookBeastPBData_t;

	struct HandBookBeastBattleSlotData_s : public NFDescStoreSeqOP {
		HandBookBeastBattleSlotData_s();
		virtual ~HandBookBeastBattleSlotData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t cur_state;//
		int64_t beast_id;//

		virtual void write_to_pbmsg(::proto_ff::HandBookBeastBattleSlotData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookBeastBattleSlotData & msg);
		static ::proto_ff::HandBookBeastBattleSlotData* new_pbmsg(){ return new ::proto_ff::HandBookBeastBattleSlotData(); }
		static ::proto_ff::HandBookBeastBattleSlotData make_pbmsg(){ return ::proto_ff::HandBookBeastBattleSlotData(); }
	};
	typedef struct HandBookBeastBattleSlotData_s HandBookBeastBattleSlotData_t;

	struct HandBookPBData_s : public NFDescStoreSeqOP {
		HandBookPBData_s();
		virtual ~HandBookPBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct HandBookPBInfo_s, DEFINE_HANDBOOKPBDATA_DATA_MAX_NUM> data;//
		NFShmVector<uint64_t, DEFINE_HANDBOOKPBDATA_FETTERS_MAX_NUM> fetters;//
		NFShmVector<struct HandBookEmployPBInfo_s, DEFINE_HANDBOOKPBDATA_EMPLOYS_MAX_NUM> employs;//
		NFShmVector<struct HandBookTablePBInfo_s, DEFINE_HANDBOOKPBDATA_TABLES_MAX_NUM> tables;//
		NFShmVector<struct HandBookBeastPBData_s, DEFINE_HANDBOOKPBDATA_BEASTS_MAX_NUM> beasts;//
		NFShmVector<struct HandBookBeastBattleSlotData_s, DEFINE_HANDBOOKPBDATA_SLOTS_MAX_NUM> slots;//
		uint64_t beast_priv_id;//

		virtual void write_to_pbmsg(::proto_ff::HandBookPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::HandBookPBData & msg);
		static ::proto_ff::HandBookPBData* new_pbmsg(){ return new ::proto_ff::HandBookPBData(); }
		static ::proto_ff::HandBookPBData make_pbmsg(){ return ::proto_ff::HandBookPBData(); }
	};
	typedef struct HandBookPBData_s HandBookPBData_t;

	struct RankNodeDBData_s : public NFDescStoreSeqOP {
		RankNodeDBData_s();
		virtual ~RankNodeDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint64_t value;//
		NFShmVector<int64_t, DEFINE_RANKNODEDBDATA_PARAMINT_MAX_NUM> paramInt;//
		NFShmVector<NFShmString<32>, DEFINE_RANKNODEDBDATA_PARAMSTR_MAX_NUM> paramStr;//

		virtual void write_to_pbmsg(::proto_ff::RankNodeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RankNodeDBData & msg);
		static ::proto_ff::RankNodeDBData* new_pbmsg(){ return new ::proto_ff::RankNodeDBData(); }
		static ::proto_ff::RankNodeDBData make_pbmsg(){ return ::proto_ff::RankNodeDBData(); }
	};
	typedef struct RankNodeDBData_s RankNodeDBData_t;

	struct RankTypeDBData_s : public NFDescStoreSeqOP {
		RankTypeDBData_s();
		virtual ~RankTypeDBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t rankType;//
		NFShmVector<struct RankNodeDBData_s, DEFINE_RANKTYPEDBDATA_NODELIST_MAX_NUM> nodeList;//
		int64_t lastTime;//
		int64_t lastKillTopCid;//
		int64_t newKillTopCid;//

		virtual void write_to_pbmsg(::proto_ff::RankTypeDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RankTypeDBData & msg);
		static ::proto_ff::RankTypeDBData* new_pbmsg(){ return new ::proto_ff::RankTypeDBData(); }
		static ::proto_ff::RankTypeDBData make_pbmsg(){ return ::proto_ff::RankTypeDBData(); }
	};
	typedef struct RankTypeDBData_s RankTypeDBData_t;

	struct RankNodeData_s : public NFDescStoreSeqOP {
		RankNodeData_s();
		virtual ~RankNodeData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint32_t vipLevel;//
		NFShmVector<NFShmString<32>, DEFINE_RANKNODEDATA_SPARAM_MAX_NUM> sParam;//
		bool online;//
		uint64_t fight;//
		NFShmString<32> name;//
		struct RoleFacadeProto_s facade;//

		virtual void write_to_pbmsg(::proto_ff::RankNodeData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RankNodeData & msg);
		static ::proto_ff::RankNodeData* new_pbmsg(){ return new ::proto_ff::RankNodeData(); }
		static ::proto_ff::RankNodeData make_pbmsg(){ return ::proto_ff::RankNodeData(); }
	};
	typedef struct RankNodeData_s RankNodeData_t;

	struct RankDataInfo_s : public NFDescStoreSeqOP {
		RankDataInfo_s();
		virtual ~RankDataInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t rankType;//
		uint32_t selfRank;//
		struct RankNodeData_s selfData;//
		NFShmVector<struct RankNodeData_s, DEFINE_RANKDATAINFO_RANKLIST_MAX_NUM> rankList;//

		virtual void write_to_pbmsg(::proto_ff::RankDataInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RankDataInfo & msg);
		static ::proto_ff::RankDataInfo* new_pbmsg(){ return new ::proto_ff::RankDataInfo(); }
		static ::proto_ff::RankDataInfo make_pbmsg(){ return ::proto_ff::RankDataInfo(); }
	};
	typedef struct RankDataInfo_s RankDataInfo_t;

	struct MergeReq_s : public NFDescStoreSeqOP {
		MergeReq_s();
		virtual ~MergeReq_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;//
		int32_t id;//
		NFShmVector<int32_t, DEFINE_MERGEREQ_INDEX_LIST_MAX_NUM> index_list;//
		int32_t num;//
		int32_t target_pos;//

		virtual void write_to_pbmsg(::proto_ff::MergeReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MergeReq & msg);
		static ::proto_ff::MergeReq* new_pbmsg(){ return new ::proto_ff::MergeReq(); }
		static ::proto_ff::MergeReq make_pbmsg(){ return ::proto_ff::MergeReq(); }
	};
	typedef struct MergeReq_s MergeReq_t;

	struct MergeRsp_s : public NFDescStoreSeqOP {
		MergeRsp_s();
		virtual ~MergeRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//
		int32_t type;//
		int32_t id;//
		int64_t itemId;//
		int32_t num;//
		int32_t result;//

		virtual void write_to_pbmsg(::proto_ff::MergeRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MergeRsp & msg);
		static ::proto_ff::MergeRsp* new_pbmsg(){ return new ::proto_ff::MergeRsp(); }
		static ::proto_ff::MergeRsp make_pbmsg(){ return ::proto_ff::MergeRsp(); }
	};
	typedef struct MergeRsp_s MergeRsp_t;

	struct PSDGoods_s : public NFDescStoreSeqOP {
		PSDGoods_s();
		virtual ~PSDGoods_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t amount;//

		virtual void write_to_pbmsg(::proto_ff::PSDGoods & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PSDGoods & msg);
		static ::proto_ff::PSDGoods* new_pbmsg(){ return new ::proto_ff::PSDGoods(); }
		static ::proto_ff::PSDGoods make_pbmsg(){ return ::proto_ff::PSDGoods(); }
	};
	typedef struct PSDGoods_s PSDGoods_t;

	struct PSDPurchaseRecord_s : public NFDescStoreSeqOP {
		PSDPurchaseRecord_s();
		virtual ~PSDPurchaseRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t goodsId;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::PSDPurchaseRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PSDPurchaseRecord & msg);
		static ::proto_ff::PSDPurchaseRecord* new_pbmsg(){ return new ::proto_ff::PSDPurchaseRecord(); }
		static ::proto_ff::PSDPurchaseRecord make_pbmsg(){ return ::proto_ff::PSDPurchaseRecord(); }
	};
	typedef struct PSDPurchaseRecord_s PSDPurchaseRecord_t;

	struct PSDShop_s : public NFDescStoreSeqOP {
		PSDShop_s();
		virtual ~PSDShop_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t shopId;//
		uint32_t freeRefreshCount;//
		uint64_t openTime;//
		NFShmVector<struct PSDGoods_s, DEFINE_PSDSHOP_SALELIST_MAX_NUM> saleList;//
		NFShmVector<struct PSDPurchaseRecord_s, DEFINE_PSDSHOP_PURCHASEDLIST_MAX_NUM> purchasedList;//

		virtual void write_to_pbmsg(::proto_ff::PSDShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PSDShop & msg);
		static ::proto_ff::PSDShop* new_pbmsg(){ return new ::proto_ff::PSDShop(); }
		static ::proto_ff::PSDShop make_pbmsg(){ return ::proto_ff::PSDShop(); }
	};
	typedef struct PSDShop_s PSDShop_t;

	struct PSDatas_s : public NFDescStoreSeqOP {
		PSDatas_s();
		virtual ~PSDatas_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct PSDShop_s, DEFINE_PSDATAS_SHOPLIST_MAX_NUM> shopList;//

		virtual void write_to_pbmsg(::proto_ff::PSDatas & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PSDatas & msg);
		static ::proto_ff::PSDatas* new_pbmsg(){ return new ::proto_ff::PSDatas(); }
		static ::proto_ff::PSDatas make_pbmsg(){ return ::proto_ff::PSDatas(); }
	};
	typedef struct PSDatas_s PSDatas_t;

	struct DragonSoulHoleData_s : public NFDescStoreSeqOP {
		DragonSoulHoleData_s();
		virtual ~DragonSoulHoleData_s(){}
		int CreateInit();
		int ResumeInit();
		struct EquipInfo_s equip_info;//
		int32_t status;//
		int32_t id;//
		int32_t wake_lv;//

		virtual void write_to_pbmsg(::proto_ff::DragonSoulHoleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DragonSoulHoleData & msg);
		static ::proto_ff::DragonSoulHoleData* new_pbmsg(){ return new ::proto_ff::DragonSoulHoleData(); }
		static ::proto_ff::DragonSoulHoleData make_pbmsg(){ return ::proto_ff::DragonSoulHoleData(); }
	};
	typedef struct DragonSoulHoleData_s DragonSoulHoleData_t;

	struct DragonSoulStar_s : public NFDescStoreSeqOP {
		DragonSoulStar_s();
		virtual ~DragonSoulStar_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::DragonSoulStar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DragonSoulStar & msg);
		static ::proto_ff::DragonSoulStar* new_pbmsg(){ return new ::proto_ff::DragonSoulStar(); }
		static ::proto_ff::DragonSoulStar make_pbmsg(){ return ::proto_ff::DragonSoulStar(); }
	};
	typedef struct DragonSoulStar_s DragonSoulStar_t;

	struct DragonSoulData_s : public NFDescStoreSeqOP {
		DragonSoulData_s();
		virtual ~DragonSoulData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DragonSoulHoleData_s, DEFINE_DRAGONSOULDATA_HOLE_DATA_MAX_NUM> hole_data;//
		NFShmVector<struct DragonSoulStar_s, DEFINE_DRAGONSOULDATA_STAR_MAX_NUM> star;//

		virtual void write_to_pbmsg(::proto_ff::DragonSoulData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DragonSoulData & msg);
		static ::proto_ff::DragonSoulData* new_pbmsg(){ return new ::proto_ff::DragonSoulData(); }
		static ::proto_ff::DragonSoulData make_pbmsg(){ return ::proto_ff::DragonSoulData(); }
	};
	typedef struct DragonSoulData_s DragonSoulData_t;

	struct EnterQyActReq_s : public NFDescStoreSeqOP {
		EnterQyActReq_s();
		virtual ~EnterQyActReq_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::EnterQyActReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EnterQyActReq & msg);
		static ::proto_ff::EnterQyActReq* new_pbmsg(){ return new ::proto_ff::EnterQyActReq(); }
		static ::proto_ff::EnterQyActReq make_pbmsg(){ return ::proto_ff::EnterQyActReq(); }
	};
	typedef struct EnterQyActReq_s EnterQyActReq_t;

	struct EnterQyActRsp_s : public NFDescStoreSeqOP {
		EnterQyActRsp_s();
		virtual ~EnterQyActRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::EnterQyActRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EnterQyActRsp & msg);
		static ::proto_ff::EnterQyActRsp* new_pbmsg(){ return new ::proto_ff::EnterQyActRsp(); }
		static ::proto_ff::EnterQyActRsp make_pbmsg(){ return ::proto_ff::EnterQyActRsp(); }
	};
	typedef struct EnterQyActRsp_s EnterQyActRsp_t;

	struct NotifyQyActDupData_s : public NFDescStoreSeqOP {
		NotifyQyActDupData_s();
		virtual ~NotifyQyActDupData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t layer;//
		int32_t num;//

		virtual void write_to_pbmsg(::proto_ff::NotifyQyActDupData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyQyActDupData & msg);
		static ::proto_ff::NotifyQyActDupData* new_pbmsg(){ return new ::proto_ff::NotifyQyActDupData(); }
		static ::proto_ff::NotifyQyActDupData make_pbmsg(){ return ::proto_ff::NotifyQyActDupData(); }
	};
	typedef struct NotifyQyActDupData_s NotifyQyActDupData_t;

	struct QyRankInfo_s : public NFDescStoreSeqOP {
		QyRankInfo_s();
		virtual ~QyRankInfo_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t layer;//
		int32_t zid;//
		int32_t rank;//
		int32_t passtime;//

		virtual void write_to_pbmsg(::proto_ff::QyRankInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::QyRankInfo & msg);
		static ::proto_ff::QyRankInfo* new_pbmsg(){ return new ::proto_ff::QyRankInfo(); }
		static ::proto_ff::QyRankInfo make_pbmsg(){ return ::proto_ff::QyRankInfo(); }
	};
	typedef struct QyRankInfo_s QyRankInfo_t;

	struct NotifyQyPassLayer_s : public NFDescStoreSeqOP {
		NotifyQyPassLayer_s();
		virtual ~NotifyQyPassLayer_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t layer;//

		virtual void write_to_pbmsg(::proto_ff::NotifyQyPassLayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyQyPassLayer & msg);
		static ::proto_ff::NotifyQyPassLayer* new_pbmsg(){ return new ::proto_ff::NotifyQyPassLayer(); }
		static ::proto_ff::NotifyQyPassLayer make_pbmsg(){ return ::proto_ff::NotifyQyPassLayer(); }
	};
	typedef struct NotifyQyPassLayer_s NotifyQyPassLayer_t;

	struct NotifyQyActRank_s : public NFDescStoreSeqOP {
		NotifyQyActRank_s();
		virtual ~NotifyQyActRank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct QyRankInfo_s, DEFINE_NOTIFYQYACTRANK_RANK_MAX_NUM> rank;//

		virtual void write_to_pbmsg(::proto_ff::NotifyQyActRank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyQyActRank & msg);
		static ::proto_ff::NotifyQyActRank* new_pbmsg(){ return new ::proto_ff::NotifyQyActRank(); }
		static ::proto_ff::NotifyQyActRank make_pbmsg(){ return ::proto_ff::NotifyQyActRank(); }
	};
	typedef struct NotifyQyActRank_s NotifyQyActRank_t;

	struct L2CEnterActReq_s : public NFDescStoreSeqOP {
		L2CEnterActReq_s();
		virtual ~L2CEnterActReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		int32_t zid;//
		int32_t acttype;//

		virtual void write_to_pbmsg(::proto_ff::L2CEnterActReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::L2CEnterActReq & msg);
		static ::proto_ff::L2CEnterActReq* new_pbmsg(){ return new ::proto_ff::L2CEnterActReq(); }
		static ::proto_ff::L2CEnterActReq make_pbmsg(){ return ::proto_ff::L2CEnterActReq(); }
	};
	typedef struct L2CEnterActReq_s L2CEnterActReq_t;

	struct C2LEnterActReq_s : public NFDescStoreSeqOP {
		C2LEnterActReq_s();
		virtual ~C2LEnterActReq_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		int32_t zid;//
		int32_t acttype;//

		virtual void write_to_pbmsg(::proto_ff::C2LEnterActReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::C2LEnterActReq & msg);
		static ::proto_ff::C2LEnterActReq* new_pbmsg(){ return new ::proto_ff::C2LEnterActReq(); }
		static ::proto_ff::C2LEnterActReq make_pbmsg(){ return ::proto_ff::C2LEnterActReq(); }
	};
	typedef struct C2LEnterActReq_s C2LEnterActReq_t;

	struct L2CEnterActRsp_s : public NFDescStoreSeqOP {
		L2CEnterActRsp_s();
		virtual ~L2CEnterActRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//
		uint64_t cid;//
		int32_t zid;//
		int32_t acttype;//

		virtual void write_to_pbmsg(::proto_ff::L2CEnterActRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::L2CEnterActRsp & msg);
		static ::proto_ff::L2CEnterActRsp* new_pbmsg(){ return new ::proto_ff::L2CEnterActRsp(); }
		static ::proto_ff::L2CEnterActRsp make_pbmsg(){ return ::proto_ff::L2CEnterActRsp(); }
	};
	typedef struct L2CEnterActRsp_s L2CEnterActRsp_t;

	struct NotifyEnterActRsp_s : public NFDescStoreSeqOP {
		NotifyEnterActRsp_s();
		virtual ~NotifyEnterActRsp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ret;//
		uint64_t cid;//
		uint64_t zid;//
		int32_t acttype;//

		virtual void write_to_pbmsg(::proto_ff::NotifyEnterActRsp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyEnterActRsp & msg);
		static ::proto_ff::NotifyEnterActRsp* new_pbmsg(){ return new ::proto_ff::NotifyEnterActRsp(); }
		static ::proto_ff::NotifyEnterActRsp make_pbmsg(){ return ::proto_ff::NotifyEnterActRsp(); }
	};
	typedef struct NotifyEnterActRsp_s NotifyEnterActRsp_t;

	struct WelfareSignPBData_s : public NFDescStoreSeqOP {
		WelfareSignPBData_s();
		virtual ~WelfareSignPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareSignPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareSignPBData & msg);
		static ::proto_ff::WelfareSignPBData* new_pbmsg(){ return new ::proto_ff::WelfareSignPBData(); }
		static ::proto_ff::WelfareSignPBData make_pbmsg(){ return ::proto_ff::WelfareSignPBData(); }
	};
	typedef struct WelfareSignPBData_s WelfareSignPBData_t;

	struct WelfareAccrueRewardPBData_s : public NFDescStoreSeqOP {
		WelfareAccrueRewardPBData_s();
		virtual ~WelfareAccrueRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareAccrueRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareAccrueRewardPBData & msg);
		static ::proto_ff::WelfareAccrueRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareAccrueRewardPBData(); }
		static ::proto_ff::WelfareAccrueRewardPBData make_pbmsg(){ return ::proto_ff::WelfareAccrueRewardPBData(); }
	};
	typedef struct WelfareAccrueRewardPBData_s WelfareAccrueRewardPBData_t;

	struct WelfareLvRewardPBData_s : public NFDescStoreSeqOP {
		WelfareLvRewardPBData_s();
		virtual ~WelfareLvRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t vip_status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareLvRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareLvRewardPBData & msg);
		static ::proto_ff::WelfareLvRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareLvRewardPBData(); }
		static ::proto_ff::WelfareLvRewardPBData make_pbmsg(){ return ::proto_ff::WelfareLvRewardPBData(); }
	};
	typedef struct WelfareLvRewardPBData_s WelfareLvRewardPBData_t;

	struct WelfareOnlineRewardPBData_s : public NFDescStoreSeqOP {
		WelfareOnlineRewardPBData_s();
		virtual ~WelfareOnlineRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareOnlineRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareOnlineRewardPBData & msg);
		static ::proto_ff::WelfareOnlineRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareOnlineRewardPBData(); }
		static ::proto_ff::WelfareOnlineRewardPBData make_pbmsg(){ return ::proto_ff::WelfareOnlineRewardPBData(); }
	};
	typedef struct WelfareOnlineRewardPBData_s WelfareOnlineRewardPBData_t;

	struct WelfareFraudRewardPBData_s : public NFDescStoreSeqOP {
		WelfareFraudRewardPBData_s();
		virtual ~WelfareFraudRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t status;//
		NFShmVector<int32_t, DEFINE_WELFAREFRAUDREWARDPBDATA_ID_MAX_NUM> id;//

		virtual void write_to_pbmsg(::proto_ff::WelfareFraudRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareFraudRewardPBData & msg);
		static ::proto_ff::WelfareFraudRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareFraudRewardPBData(); }
		static ::proto_ff::WelfareFraudRewardPBData make_pbmsg(){ return ::proto_ff::WelfareFraudRewardPBData(); }
	};
	typedef struct WelfareFraudRewardPBData_s WelfareFraudRewardPBData_t;

	struct WelfareNotifyRewardPBData_s : public NFDescStoreSeqOP {
		WelfareNotifyRewardPBData_s();
		virtual ~WelfareNotifyRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t status;//
		int32_t version_id;//

		virtual void write_to_pbmsg(::proto_ff::WelfareNotifyRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareNotifyRewardPBData & msg);
		static ::proto_ff::WelfareNotifyRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareNotifyRewardPBData(); }
		static ::proto_ff::WelfareNotifyRewardPBData make_pbmsg(){ return ::proto_ff::WelfareNotifyRewardPBData(); }
	};
	typedef struct WelfareNotifyRewardPBData_s WelfareNotifyRewardPBData_t;

	struct WelfareWeekEndRewardPBData_s : public NFDescStoreSeqOP {
		WelfareWeekEndRewardPBData_s();
		virtual ~WelfareWeekEndRewardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareWeekEndRewardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareWeekEndRewardPBData & msg);
		static ::proto_ff::WelfareWeekEndRewardPBData* new_pbmsg(){ return new ::proto_ff::WelfareWeekEndRewardPBData(); }
		static ::proto_ff::WelfareWeekEndRewardPBData make_pbmsg(){ return ::proto_ff::WelfareWeekEndRewardPBData(); }
	};
	typedef struct WelfareWeekEndRewardPBData_s WelfareWeekEndRewardPBData_t;

	struct WelfareQiFuData_s : public NFDescStoreSeqOP {
		WelfareQiFuData_s();
		virtual ~WelfareQiFuData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t last_free_qifu_time;//
		int32_t free_qifu_status;//
		int32_t max_gold_qifu_buy_num;//
		int32_t left_gold_qifu_buy_num;//
		int32_t max_exp_qifu_buy_num;//
		int32_t left_exp_qifu_buy_num;//
		int32_t save_money;//
		int32_t last_save_money_time;//
		int32_t last_get_money_time;//
		int32_t get_money_day;//
		int32_t all_get_money;//

		virtual void write_to_pbmsg(::proto_ff::WelfareQiFuData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareQiFuData & msg);
		static ::proto_ff::WelfareQiFuData* new_pbmsg(){ return new ::proto_ff::WelfareQiFuData(); }
		static ::proto_ff::WelfareQiFuData make_pbmsg(){ return ::proto_ff::WelfareQiFuData(); }
	};
	typedef struct WelfareQiFuData_s WelfareQiFuData_t;

	struct WelfareLogonData_s : public NFDescStoreSeqOP {
		WelfareLogonData_s();
		virtual ~WelfareLogonData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::WelfareLogonData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfareLogonData & msg);
		static ::proto_ff::WelfareLogonData* new_pbmsg(){ return new ::proto_ff::WelfareLogonData(); }
		static ::proto_ff::WelfareLogonData make_pbmsg(){ return ::proto_ff::WelfareLogonData(); }
	};
	typedef struct WelfareLogonData_s WelfareLogonData_t;

	struct WelfarePBData_s : public NFDescStoreSeqOP {
		WelfarePBData_s();
		virtual ~WelfarePBData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t create_time;//
		int64_t flush_time;//
		int64_t online_time;//
		NFShmVector<struct WelfareSignPBData_s, DEFINE_WELFAREPBDATA_SIGN_MAX_NUM> sign;//
		NFShmVector<struct WelfareAccrueRewardPBData_s, DEFINE_WELFAREPBDATA_ACCURE_MAX_NUM> accure;//
		NFShmVector<struct WelfareLvRewardPBData_s, DEFINE_WELFAREPBDATA_LV_MAX_NUM> lv;//
		NFShmVector<struct WelfareOnlineRewardPBData_s, DEFINE_WELFAREPBDATA_ONLINE_MAX_NUM> online;//
		struct WelfareNotifyRewardPBData_s notify;//
		struct WelfareFraudRewardPBData_s fraud;//
		NFShmVector<struct WelfareWeekEndRewardPBData_s, DEFINE_WELFAREPBDATA_WEEKEND_MAX_NUM> weekend;//
		int64_t last_week_end_flush_time;//
		struct WelfareQiFuData_s pray;//
		NFShmVector<struct WelfareLogonData_s, DEFINE_WELFAREPBDATA_LOGON_MAX_NUM> logon;//
		int32_t cur_logon_day;//

		virtual void write_to_pbmsg(::proto_ff::WelfarePBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WelfarePBData & msg);
		static ::proto_ff::WelfarePBData* new_pbmsg(){ return new ::proto_ff::WelfarePBData(); }
		static ::proto_ff::WelfarePBData make_pbmsg(){ return ::proto_ff::WelfarePBData(); }
	};
	typedef struct WelfarePBData_s WelfarePBData_t;

	struct WPPState_s : public NFDescStoreSeqOP {
		WPPState_s();
		virtual ~WPPState_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t type;//
		struct Vector3PB_s dir;//

		virtual void write_to_pbmsg(::proto_ff::WPPState & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WPPState & msg);
		static ::proto_ff::WPPState* new_pbmsg(){ return new ::proto_ff::WPPState(); }
		static ::proto_ff::WPPState make_pbmsg(){ return ::proto_ff::WPPState(); }
	};
	typedef struct WPPState_s WPPState_t;

	struct XingYunMiShiPBData_s : public NFDescStoreSeqOP {
		XingYunMiShiPBData_s();
		virtual ~XingYunMiShiPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::XingYunMiShiPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::XingYunMiShiPBData & msg);
		static ::proto_ff::XingYunMiShiPBData* new_pbmsg(){ return new ::proto_ff::XingYunMiShiPBData(); }
		static ::proto_ff::XingYunMiShiPBData make_pbmsg(){ return ::proto_ff::XingYunMiShiPBData(); }
	};
	typedef struct XingYunMiShiPBData_s XingYunMiShiPBData_t;

	struct XingYunMiShiPBRecord_s : public NFDescStoreSeqOP {
		XingYunMiShiPBRecord_s();
		virtual ~XingYunMiShiPBRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::XingYunMiShiPBRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::XingYunMiShiPBRecord & msg);
		static ::proto_ff::XingYunMiShiPBRecord* new_pbmsg(){ return new ::proto_ff::XingYunMiShiPBRecord(); }
		static ::proto_ff::XingYunMiShiPBRecord make_pbmsg(){ return ::proto_ff::XingYunMiShiPBRecord(); }
	};
	typedef struct XingYunMiShiPBRecord_s XingYunMiShiPBRecord_t;

	struct DailyGiftPBData_s : public NFDescStoreSeqOP {
		DailyGiftPBData_s();
		virtual ~DailyGiftPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::DailyGiftPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyGiftPBData & msg);
		static ::proto_ff::DailyGiftPBData* new_pbmsg(){ return new ::proto_ff::DailyGiftPBData(); }
		static ::proto_ff::DailyGiftPBData make_pbmsg(){ return ::proto_ff::DailyGiftPBData(); }
	};
	typedef struct DailyGiftPBData_s DailyGiftPBData_t;

	struct DailyGiftPBDataRecord_s : public NFDescStoreSeqOP {
		DailyGiftPBDataRecord_s();
		virtual ~DailyGiftPBDataRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::DailyGiftPBDataRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyGiftPBDataRecord & msg);
		static ::proto_ff::DailyGiftPBDataRecord* new_pbmsg(){ return new ::proto_ff::DailyGiftPBDataRecord(); }
		static ::proto_ff::DailyGiftPBDataRecord make_pbmsg(){ return ::proto_ff::DailyGiftPBDataRecord(); }
	};
	typedef struct DailyGiftPBDataRecord_s DailyGiftPBDataRecord_t;

	struct LianChongTodayPBData_s : public NFDescStoreSeqOP {
		LianChongTodayPBData_s();
		virtual ~LianChongTodayPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::LianChongTodayPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LianChongTodayPBData & msg);
		static ::proto_ff::LianChongTodayPBData* new_pbmsg(){ return new ::proto_ff::LianChongTodayPBData(); }
		static ::proto_ff::LianChongTodayPBData make_pbmsg(){ return ::proto_ff::LianChongTodayPBData(); }
	};
	typedef struct LianChongTodayPBData_s LianChongTodayPBData_t;

	struct LianChongTodayPBDataRecord_s : public NFDescStoreSeqOP {
		LianChongTodayPBDataRecord_s();
		virtual ~LianChongTodayPBDataRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::LianChongTodayPBDataRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LianChongTodayPBDataRecord & msg);
		static ::proto_ff::LianChongTodayPBDataRecord* new_pbmsg(){ return new ::proto_ff::LianChongTodayPBDataRecord(); }
		static ::proto_ff::LianChongTodayPBDataRecord make_pbmsg(){ return ::proto_ff::LianChongTodayPBDataRecord(); }
	};
	typedef struct LianChongTodayPBDataRecord_s LianChongTodayPBDataRecord_t;

	struct LianChongAccPBData_s : public NFDescStoreSeqOP {
		LianChongAccPBData_s();
		virtual ~LianChongAccPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t days;//
		bool cur_flag;//

		virtual void write_to_pbmsg(::proto_ff::LianChongAccPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LianChongAccPBData & msg);
		static ::proto_ff::LianChongAccPBData* new_pbmsg(){ return new ::proto_ff::LianChongAccPBData(); }
		static ::proto_ff::LianChongAccPBData make_pbmsg(){ return ::proto_ff::LianChongAccPBData(); }
	};
	typedef struct LianChongAccPBData_s LianChongAccPBData_t;

	struct LianChongAccPBDataRecord_s : public NFDescStoreSeqOP {
		LianChongAccPBDataRecord_s();
		virtual ~LianChongAccPBDataRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::LianChongAccPBDataRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::LianChongAccPBDataRecord & msg);
		static ::proto_ff::LianChongAccPBDataRecord* new_pbmsg(){ return new ::proto_ff::LianChongAccPBDataRecord(); }
		static ::proto_ff::LianChongAccPBDataRecord make_pbmsg(){ return ::proto_ff::LianChongAccPBDataRecord(); }
	};
	typedef struct LianChongAccPBDataRecord_s LianChongAccPBDataRecord_t;

	struct MonthCardPBData_s : public NFDescStoreSeqOP {
		MonthCardPBData_s();
		virtual ~MonthCardPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		uint64_t buy_time;//
		uint64_t last_get_reward;//
		uint64_t last_buy_time;//

		virtual void write_to_pbmsg(::proto_ff::MonthCardPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MonthCardPBData & msg);
		static ::proto_ff::MonthCardPBData* new_pbmsg(){ return new ::proto_ff::MonthCardPBData(); }
		static ::proto_ff::MonthCardPBData make_pbmsg(){ return ::proto_ff::MonthCardPBData(); }
	};
	typedef struct MonthCardPBData_s MonthCardPBData_t;

	struct MonthCardPBDataRecord_s : public NFDescStoreSeqOP {
		MonthCardPBDataRecord_s();
		virtual ~MonthCardPBDataRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::MonthCardPBDataRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MonthCardPBDataRecord & msg);
		static ::proto_ff::MonthCardPBDataRecord* new_pbmsg(){ return new ::proto_ff::MonthCardPBDataRecord(); }
		static ::proto_ff::MonthCardPBDataRecord make_pbmsg(){ return ::proto_ff::MonthCardPBDataRecord(); }
	};
	typedef struct MonthCardPBDataRecord_s MonthCardPBDataRecord_t;

	struct TurntableAccPBData_s : public NFDescStoreSeqOP {
		TurntableAccPBData_s();
		virtual ~TurntableAccPBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t cur_num;//

		virtual void write_to_pbmsg(::proto_ff::TurntableAccPBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurntableAccPBData & msg);
		static ::proto_ff::TurntableAccPBData* new_pbmsg(){ return new ::proto_ff::TurntableAccPBData(); }
		static ::proto_ff::TurntableAccPBData make_pbmsg(){ return ::proto_ff::TurntableAccPBData(); }
	};
	typedef struct TurntableAccPBData_s TurntableAccPBData_t;

	struct TurntablePBData_s : public NFDescStoreSeqOP {
		TurntablePBData_s();
		virtual ~TurntablePBData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur_num;//
		int32_t acc_num;//

		virtual void write_to_pbmsg(::proto_ff::TurntablePBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurntablePBData & msg);
		static ::proto_ff::TurntablePBData* new_pbmsg(){ return new ::proto_ff::TurntablePBData(); }
		static ::proto_ff::TurntablePBData make_pbmsg(){ return ::proto_ff::TurntablePBData(); }
	};
	typedef struct TurntablePBData_s TurntablePBData_t;

	struct TurntablePBDataRecord_s : public NFDescStoreSeqOP {
		TurntablePBDataRecord_s();
		virtual ~TurntablePBDataRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		int32_t id;//
		int64_t time;//

		virtual void write_to_pbmsg(::proto_ff::TurntablePBDataRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurntablePBDataRecord & msg);
		static ::proto_ff::TurntablePBDataRecord* new_pbmsg(){ return new ::proto_ff::TurntablePBDataRecord(); }
		static ::proto_ff::TurntablePBDataRecord make_pbmsg(){ return ::proto_ff::TurntablePBDataRecord(); }
	};
	typedef struct TurntablePBDataRecord_s TurntablePBDataRecord_t;

	struct OneSuperGiftBuy_s : public NFDescStoreSeqOP {
		OneSuperGiftBuy_s();
		virtual ~OneSuperGiftBuy_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur_num;//
		int32_t max_num;//

		virtual void write_to_pbmsg(::proto_ff::OneSuperGiftBuy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneSuperGiftBuy & msg);
		static ::proto_ff::OneSuperGiftBuy* new_pbmsg(){ return new ::proto_ff::OneSuperGiftBuy(); }
		static ::proto_ff::OneSuperGiftBuy make_pbmsg(){ return ::proto_ff::OneSuperGiftBuy(); }
	};
	typedef struct OneSuperGiftBuy_s OneSuperGiftBuy_t;

	struct OnWelfareInvestRewardData_s : public NFDescStoreSeqOP {
		OnWelfareInvestRewardData_s();
		virtual ~OnWelfareInvestRewardData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::OnWelfareInvestRewardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OnWelfareInvestRewardData & msg);
		static ::proto_ff::OnWelfareInvestRewardData* new_pbmsg(){ return new ::proto_ff::OnWelfareInvestRewardData(); }
		static ::proto_ff::OnWelfareInvestRewardData make_pbmsg(){ return ::proto_ff::OnWelfareInvestRewardData(); }
	};
	typedef struct OnWelfareInvestRewardData_s OnWelfareInvestRewardData_t;

	struct OneWelfareInvestData_s : public NFDescStoreSeqOP {
		OneWelfareInvestData_s();
		virtual ~OneWelfareInvestData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t invest_id;//
		int32_t status;//
		NFShmVector<struct OnWelfareInvestRewardData_s, DEFINE_ONEWELFAREINVESTDATA_DATA_MAX_NUM> data;//

		virtual void write_to_pbmsg(::proto_ff::OneWelfareInvestData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneWelfareInvestData & msg);
		static ::proto_ff::OneWelfareInvestData* new_pbmsg(){ return new ::proto_ff::OneWelfareInvestData(); }
		static ::proto_ff::OneWelfareInvestData make_pbmsg(){ return ::proto_ff::OneWelfareInvestData(); }
	};
	typedef struct OneWelfareInvestData_s OneWelfareInvestData_t;

	struct OneYTTLGift_s : public NFDescStoreSeqOP {
		OneYTTLGift_s();
		virtual ~OneYTTLGift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t buyed;//

		virtual void write_to_pbmsg(::proto_ff::OneYTTLGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::OneYTTLGift & msg);
		static ::proto_ff::OneYTTLGift* new_pbmsg(){ return new ::proto_ff::OneYTTLGift(); }
		static ::proto_ff::OneYTTLGift make_pbmsg(){ return ::proto_ff::OneYTTLGift(); }
	};
	typedef struct OneYTTLGift_s OneYTTLGift_t;

	struct DailyWelfarePBData_s : public NFDescStoreSeqOP {
		DailyWelfarePBData_s();
		virtual ~DailyWelfarePBData_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t flush_time;//
		NFShmVector<struct XingYunMiShiPBData_s, DEFINE_DAILYWELFAREPBDATA_XING_YUN_MI_SHI_MAX_NUM> xing_yun_mi_shi;//
		int32_t xing_yun_super_gift_status;//
		NFShmVector<struct DailyGiftPBData_s, DEFINE_DAILYWELFAREPBDATA_DAILY_GIFT_MAX_NUM> daily_gift;//
		NFShmVector<struct LianChongTodayPBData_s, DEFINE_DAILYWELFAREPBDATA_TODAY_RECHARGE_MAX_NUM> today_recharge;//
		NFShmVector<struct LianChongAccPBData_s, DEFINE_DAILYWELFAREPBDATA_ACC_RECHARGE_MAX_NUM> acc_recharge;//
		int32_t cur_recharge_num;//
		NFShmVector<struct MonthCardPBData_s, DEFINE_DAILYWELFAREPBDATA_MONTH_CARD_MAX_NUM> month_card;//
		NFShmVector<struct TurntableAccPBData_s, DEFINE_DAILYWELFAREPBDATA_TURNTABLE_ACC_MAX_NUM> turntable_acc;//
		NFShmVector<struct TurntablePBData_s, DEFINE_DAILYWELFAREPBDATA_TURNTABLE_MAX_NUM> turntable;//
		NFShmVector<struct TurntablePBDataRecord_s, DEFINE_DAILYWELFAREPBDATA_TURNTABLE_RECORD_MAX_NUM> turntable_record;//
		NFShmVector<struct OneSuperGiftBuy_s, DEFINE_DAILYWELFAREPBDATA_SUPER_BUY_MAX_NUM> super_buy;//
		NFShmVector<struct OneWelfareInvestData_s, DEFINE_DAILYWELFAREPBDATA_INVEST_MAX_NUM> invest;//
		NFShmVector<struct OneYTTLGift_s, DEFINE_DAILYWELFAREPBDATA_YTTL_GIFT_MAX_NUM> yttl_gift;//

		virtual void write_to_pbmsg(::proto_ff::DailyWelfarePBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DailyWelfarePBData & msg);
		static ::proto_ff::DailyWelfarePBData* new_pbmsg(){ return new ::proto_ff::DailyWelfarePBData(); }
		static ::proto_ff::DailyWelfarePBData make_pbmsg(){ return ::proto_ff::DailyWelfarePBData(); }
	};
	typedef struct DailyWelfarePBData_s DailyWelfarePBData_t;

	struct SynRankEntry_s : public NFDescStoreSeqOP {
		SynRankEntry_s();
		virtual ~SynRankEntry_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint64_t fight;//
		int32_t zid;//

		virtual void write_to_pbmsg(::proto_ff::SynRankEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SynRankEntry & msg);
		static ::proto_ff::SynRankEntry* new_pbmsg(){ return new ::proto_ff::SynRankEntry(); }
		static ::proto_ff::SynRankEntry make_pbmsg(){ return ::proto_ff::SynRankEntry(); }
	};
	typedef struct SynRankEntry_s SynRankEntry_t;

	struct C2SSynInitRankReq_s : public NFDescStoreSeqOP {
		C2SSynInitRankReq_s();
		virtual ~C2SSynInitRankReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct SynRankEntry_s, DEFINE_C2SSYNINITRANKREQ_INFOS_MAX_NUM> infos;//

		virtual void write_to_pbmsg(::proto_ff::C2SSynInitRankReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::C2SSynInitRankReq & msg);
		static ::proto_ff::C2SSynInitRankReq* new_pbmsg(){ return new ::proto_ff::C2SSynInitRankReq(); }
		static ::proto_ff::C2SSynInitRankReq make_pbmsg(){ return ::proto_ff::C2SSynInitRankReq(); }
	};
	typedef struct C2SSynInitRankReq_s C2SSynInitRankReq_t;

	struct FindTreasureRewardRecord_s : public NFDescStoreSeqOP {
		FindTreasureRewardRecord_s();
		virtual ~FindTreasureRewardRecord_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		uint32_t id;//
		uint32_t time;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureRewardRecord & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureRewardRecord & msg);
		static ::proto_ff::FindTreasureRewardRecord* new_pbmsg(){ return new ::proto_ff::FindTreasureRewardRecord(); }
		static ::proto_ff::FindTreasureRewardRecord make_pbmsg(){ return ::proto_ff::FindTreasureRewardRecord(); }
	};
	typedef struct FindTreasureRewardRecord_s FindTreasureRewardRecord_t;

	struct FindTreasureRewardRecordDBData_s : public NFDescStoreSeqOP {
		FindTreasureRewardRecordDBData_s();
		virtual ~FindTreasureRewardRecordDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t num;//
		NFShmVector<struct FindTreasureRewardRecord_s, DEFINE_FINDTREASUREREWARDRECORDDBDATA_RECORD_MAX_NUM> record;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureRewardRecordDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureRewardRecordDBData & msg);
		static ::proto_ff::FindTreasureRewardRecordDBData* new_pbmsg(){ return new ::proto_ff::FindTreasureRewardRecordDBData(); }
		static ::proto_ff::FindTreasureRewardRecordDBData make_pbmsg(){ return ::proto_ff::FindTreasureRewardRecordDBData(); }
	};
	typedef struct FindTreasureRewardRecordDBData_s FindTreasureRewardRecordDBData_t;

	struct FindTreasureBigDragonRewardData_s : public NFDescStoreSeqOP {
		FindTreasureBigDragonRewardData_s();
		virtual ~FindTreasureBigDragonRewardData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureBigDragonRewardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureBigDragonRewardData & msg);
		static ::proto_ff::FindTreasureBigDragonRewardData* new_pbmsg(){ return new ::proto_ff::FindTreasureBigDragonRewardData(); }
		static ::proto_ff::FindTreasureBigDragonRewardData make_pbmsg(){ return ::proto_ff::FindTreasureBigDragonRewardData(); }
	};
	typedef struct FindTreasureBigDragonRewardData_s FindTreasureBigDragonRewardData_t;

	struct FindTreasureBigDragonData_s : public NFDescStoreSeqOP {
		FindTreasureBigDragonData_s();
		virtual ~FindTreasureBigDragonData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t all_num;//
		NFShmVector<struct FindTreasureBigDragonRewardData_s, DEFINE_FINDTREASUREBIGDRAGONDATA_REWARD_MAX_NUM> reward;//
		uint32_t pool_id;//
		uint64_t pool_time;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureBigDragonData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureBigDragonData & msg);
		static ::proto_ff::FindTreasureBigDragonData* new_pbmsg(){ return new ::proto_ff::FindTreasureBigDragonData(); }
		static ::proto_ff::FindTreasureBigDragonData make_pbmsg(){ return ::proto_ff::FindTreasureBigDragonData(); }
	};
	typedef struct FindTreasureBigDragonData_s FindTreasureBigDragonData_t;

	struct FindTreasureBaiLianShopData_s : public NFDescStoreSeqOP {
		FindTreasureBaiLianShopData_s();
		virtual ~FindTreasureBaiLianShopData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t left_num;//
		uint32_t all_num;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureBaiLianShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianShopData & msg);
		static ::proto_ff::FindTreasureBaiLianShopData* new_pbmsg(){ return new ::proto_ff::FindTreasureBaiLianShopData(); }
		static ::proto_ff::FindTreasureBaiLianShopData make_pbmsg(){ return ::proto_ff::FindTreasureBaiLianShopData(); }
	};
	typedef struct FindTreasureBaiLianShopData_s FindTreasureBaiLianShopData_t;

	struct FindTreasureBaiLianActiveData_s : public NFDescStoreSeqOP {
		FindTreasureBaiLianActiveData_s();
		virtual ~FindTreasureBaiLianActiveData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t type;//
		uint32_t buy_status;//
		NFShmVector<struct FindTreasureBaiLianShopData_s, DEFINE_FINDTREASUREBAILIANACTIVEDATA_SHOP_DATA_MAX_NUM> shop_data;//
		int32_t open_status;//
		uint64_t last_time;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureBaiLianActiveData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianActiveData & msg);
		static ::proto_ff::FindTreasureBaiLianActiveData* new_pbmsg(){ return new ::proto_ff::FindTreasureBaiLianActiveData(); }
		static ::proto_ff::FindTreasureBaiLianActiveData make_pbmsg(){ return ::proto_ff::FindTreasureBaiLianActiveData(); }
	};
	typedef struct FindTreasureBaiLianActiveData_s FindTreasureBaiLianActiveData_t;

	struct FindTreasureBaiLianData_s : public NFDescStoreSeqOP {
		FindTreasureBaiLianData_s();
		virtual ~FindTreasureBaiLianData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		NFShmVector<struct FindTreasureRewardRecord_s, DEFINE_FINDTREASUREBAILIANDATA_RECORD_MAX_NUM> record;//
		NFShmVector<struct FindTreasureBaiLianActiveData_s, DEFINE_FINDTREASUREBAILIANDATA_ACTIVE_MAX_NUM> active;//
		uint32_t pool_id;//
		uint64_t pool_time;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureBaiLianData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianData & msg);
		static ::proto_ff::FindTreasureBaiLianData* new_pbmsg(){ return new ::proto_ff::FindTreasureBaiLianData(); }
		static ::proto_ff::FindTreasureBaiLianData make_pbmsg(){ return ::proto_ff::FindTreasureBaiLianData(); }
	};
	typedef struct FindTreasureBaiLianData_s FindTreasureBaiLianData_t;

	struct FindTreasureSiShengRewardData_s : public NFDescStoreSeqOP {
		FindTreasureSiShengRewardData_s();
		virtual ~FindTreasureSiShengRewardData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureSiShengRewardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureSiShengRewardData & msg);
		static ::proto_ff::FindTreasureSiShengRewardData* new_pbmsg(){ return new ::proto_ff::FindTreasureSiShengRewardData(); }
		static ::proto_ff::FindTreasureSiShengRewardData make_pbmsg(){ return ::proto_ff::FindTreasureSiShengRewardData(); }
	};
	typedef struct FindTreasureSiShengRewardData_s FindTreasureSiShengRewardData_t;

	struct FindTreasureSiShengData_s : public NFDescStoreSeqOP {
		FindTreasureSiShengData_s();
		virtual ~FindTreasureSiShengData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		NFShmVector<struct FindTreasureSiShengRewardData_s, DEFINE_FINDTREASURESISHENGDATA_PERSON_TOTAL_REWARD_MAX_NUM> person_total_reward;//
		NFShmVector<struct FindTreasureSiShengRewardData_s, DEFINE_FINDTREASURESISHENGDATA_SERVER_TOTAL_REWARD_MAX_NUM> server_total_reward;//
		uint32_t all_num;//
		NFShmVector<struct FindTreasureRewardRecord_s, DEFINE_FINDTREASURESISHENGDATA_RECORD_MAX_NUM> record;//
		uint32_t pool_id;//
		uint64_t pool_time;//

		virtual void write_to_pbmsg(::proto_ff::FindTreasureSiShengData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreasureSiShengData & msg);
		static ::proto_ff::FindTreasureSiShengData* new_pbmsg(){ return new ::proto_ff::FindTreasureSiShengData(); }
		static ::proto_ff::FindTreasureSiShengData make_pbmsg(){ return ::proto_ff::FindTreasureSiShengData(); }
	};
	typedef struct FindTreasureSiShengData_s FindTreasureSiShengData_t;

	struct FindTreatureDBData_s : public NFDescStoreSeqOP {
		FindTreatureDBData_s();
		virtual ~FindTreatureDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FindTreasureBigDragonData_s, DEFINE_FINDTREATUREDBDATA_BIG_DRAGON_MAX_NUM> big_dragon;//
		NFShmVector<struct FindTreasureBaiLianData_s, DEFINE_FINDTREATUREDBDATA_BAI_LIAN_MAX_NUM> bai_lian;//
		NFShmVector<struct FindTreasureSiShengData_s, DEFINE_FINDTREATUREDBDATA_SI_SHENG_MAX_NUM> si_sheng;//

		virtual void write_to_pbmsg(::proto_ff::FindTreatureDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FindTreatureDBData & msg);
		static ::proto_ff::FindTreatureDBData* new_pbmsg(){ return new ::proto_ff::FindTreatureDBData(); }
		static ::proto_ff::FindTreatureDBData make_pbmsg(){ return ::proto_ff::FindTreatureDBData(); }
	};
	typedef struct FindTreatureDBData_s FindTreatureDBData_t;

	struct FestDailyTotalRechargeOneProto_s : public NFDescStoreSeqOP {
		FestDailyTotalRechargeOneProto_s();
		virtual ~FestDailyTotalRechargeOneProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FestDailyTotalRechargeOneProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDailyTotalRechargeOneProto & msg);
		static ::proto_ff::FestDailyTotalRechargeOneProto* new_pbmsg(){ return new ::proto_ff::FestDailyTotalRechargeOneProto(); }
		static ::proto_ff::FestDailyTotalRechargeOneProto make_pbmsg(){ return ::proto_ff::FestDailyTotalRechargeOneProto(); }
	};
	typedef struct FestDailyTotalRechargeOneProto_s FestDailyTotalRechargeOneProto_t;

	struct FestRTurnableRechargeOneProto_s : public NFDescStoreSeqOP {
		FestRTurnableRechargeOneProto_s();
		virtual ~FestRTurnableRechargeOneProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur_num;//
		int32_t all_num;//
		int32_t turable_num;//

		virtual void write_to_pbmsg(::proto_ff::FestRTurnableRechargeOneProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRTurnableRechargeOneProto & msg);
		static ::proto_ff::FestRTurnableRechargeOneProto* new_pbmsg(){ return new ::proto_ff::FestRTurnableRechargeOneProto(); }
		static ::proto_ff::FestRTurnableRechargeOneProto make_pbmsg(){ return ::proto_ff::FestRTurnableRechargeOneProto(); }
	};
	typedef struct FestRTurnableRechargeOneProto_s FestRTurnableRechargeOneProto_t;

	struct RTurnableLogDBProto_s : public NFDescStoreSeqOP {
		RTurnableLogDBProto_s();
		virtual ~RTurnableLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//
		int32_t id;//
		int32_t diamod;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::RTurnableLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RTurnableLogDBProto & msg);
		static ::proto_ff::RTurnableLogDBProto* new_pbmsg(){ return new ::proto_ff::RTurnableLogDBProto(); }
		static ::proto_ff::RTurnableLogDBProto make_pbmsg(){ return ::proto_ff::RTurnableLogDBProto(); }
	};
	typedef struct RTurnableLogDBProto_s RTurnableLogDBProto_t;

	struct FestRTurnableLogDBProto_s : public NFDescStoreSeqOP {
		FestRTurnableLogDBProto_s();
		virtual ~FestRTurnableLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t template_id;//
		NFShmVector<struct RTurnableLogDBProto_s, DEFINE_FESTRTURNABLELOGDBPROTO_INFO_MAX_NUM> info;//

		virtual void write_to_pbmsg(::proto_ff::FestRTurnableLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRTurnableLogDBProto & msg);
		static ::proto_ff::FestRTurnableLogDBProto* new_pbmsg(){ return new ::proto_ff::FestRTurnableLogDBProto(); }
		static ::proto_ff::FestRTurnableLogDBProto make_pbmsg(){ return ::proto_ff::FestRTurnableLogDBProto(); }
	};
	typedef struct FestRTurnableLogDBProto_s FestRTurnableLogDBProto_t;

	struct FestTurnableTaskProto_s : public NFDescStoreSeqOP {
		FestTurnableTaskProto_s();
		virtual ~FestTurnableTaskProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t cur_num;//
		int32_t all_num;//

		virtual void write_to_pbmsg(::proto_ff::FestTurnableTaskProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestTurnableTaskProto & msg);
		static ::proto_ff::FestTurnableTaskProto* new_pbmsg(){ return new ::proto_ff::FestTurnableTaskProto(); }
		static ::proto_ff::FestTurnableTaskProto make_pbmsg(){ return ::proto_ff::FestTurnableTaskProto(); }
	};
	typedef struct FestTurnableTaskProto_s FestTurnableTaskProto_t;

	struct FestDonateTaskProto_s : public NFDescStoreSeqOP {
		FestDonateTaskProto_s();
		virtual ~FestDonateTaskProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		int32_t cur_num;//
		int32_t all_num;//

		virtual void write_to_pbmsg(::proto_ff::FestDonateTaskProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDonateTaskProto & msg);
		static ::proto_ff::FestDonateTaskProto* new_pbmsg(){ return new ::proto_ff::FestDonateTaskProto(); }
		static ::proto_ff::FestDonateTaskProto make_pbmsg(){ return ::proto_ff::FestDonateTaskProto(); }
	};
	typedef struct FestDonateTaskProto_s FestDonateTaskProto_t;

	struct FestDonateSingleProto_s : public NFDescStoreSeqOP {
		FestDonateSingleProto_s();
		virtual ~FestDonateSingleProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FestDonateSingleProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDonateSingleProto & msg);
		static ::proto_ff::FestDonateSingleProto* new_pbmsg(){ return new ::proto_ff::FestDonateSingleProto(); }
		static ::proto_ff::FestDonateSingleProto make_pbmsg(){ return ::proto_ff::FestDonateSingleProto(); }
	};
	typedef struct FestDonateSingleProto_s FestDonateSingleProto_t;

	struct FestDonateServerProto_s : public NFDescStoreSeqOP {
		FestDonateServerProto_s();
		virtual ~FestDonateServerProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FestDonateServerProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDonateServerProto & msg);
		static ::proto_ff::FestDonateServerProto* new_pbmsg(){ return new ::proto_ff::FestDonateServerProto(); }
		static ::proto_ff::FestDonateServerProto make_pbmsg(){ return ::proto_ff::FestDonateServerProto(); }
	};
	typedef struct FestDonateServerProto_s FestDonateServerProto_t;

	struct FestOnlineOneProto_s : public NFDescStoreSeqOP {
		FestOnlineOneProto_s();
		virtual ~FestOnlineOneProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//
		uint64_t start_time;//
		uint64_t end_time;//

		virtual void write_to_pbmsg(::proto_ff::FestOnlineOneProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestOnlineOneProto & msg);
		static ::proto_ff::FestOnlineOneProto* new_pbmsg(){ return new ::proto_ff::FestOnlineOneProto(); }
		static ::proto_ff::FestOnlineOneProto make_pbmsg(){ return ::proto_ff::FestOnlineOneProto(); }
	};
	typedef struct FestOnlineOneProto_s FestOnlineOneProto_t;

	struct FestCollectWordOneProto_s : public NFDescStoreSeqOP {
		FestCollectWordOneProto_s();
		virtual ~FestCollectWordOneProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		uint32_t left_num;//

		virtual void write_to_pbmsg(::proto_ff::FestCollectWordOneProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestCollectWordOneProto & msg);
		static ::proto_ff::FestCollectWordOneProto* new_pbmsg(){ return new ::proto_ff::FestCollectWordOneProto(); }
		static ::proto_ff::FestCollectWordOneProto make_pbmsg(){ return ::proto_ff::FestCollectWordOneProto(); }
	};
	typedef struct FestCollectWordOneProto_s FestCollectWordOneProto_t;

	struct DonateServerDBProto_s : public NFDescStoreSeqOP {
		DonateServerDBProto_s();
		virtual ~DonateServerDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t template_id;//
		uint32_t server_num;//

		virtual void write_to_pbmsg(::proto_ff::DonateServerDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DonateServerDBProto & msg);
		static ::proto_ff::DonateServerDBProto* new_pbmsg(){ return new ::proto_ff::DonateServerDBProto(); }
		static ::proto_ff::DonateServerDBProto make_pbmsg(){ return ::proto_ff::DonateServerDBProto(); }
	};
	typedef struct DonateServerDBProto_s DonateServerDBProto_t;

	struct DrawPizeTaskProto_s : public NFDescStoreSeqOP {
		DrawPizeTaskProto_s();
		virtual ~DrawPizeTaskProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::DrawPizeTaskProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DrawPizeTaskProto & msg);
		static ::proto_ff::DrawPizeTaskProto* new_pbmsg(){ return new ::proto_ff::DrawPizeTaskProto(); }
		static ::proto_ff::DrawPizeTaskProto make_pbmsg(){ return ::proto_ff::DrawPizeTaskProto(); }
	};
	typedef struct DrawPizeTaskProto_s DrawPizeTaskProto_t;

	struct DrawPizeProto_s : public NFDescStoreSeqOP {
		DrawPizeProto_s();
		virtual ~DrawPizeProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct DrawPizeTaskProto_s, DEFINE_DRAWPIZEPROTO_TASK_MAX_NUM> task;//
		uint32_t choujiang_num;//

		virtual void write_to_pbmsg(::proto_ff::DrawPizeProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DrawPizeProto & msg);
		static ::proto_ff::DrawPizeProto* new_pbmsg(){ return new ::proto_ff::DrawPizeProto(); }
		static ::proto_ff::DrawPizeProto make_pbmsg(){ return ::proto_ff::DrawPizeProto(); }
	};
	typedef struct DrawPizeProto_s DrawPizeProto_t;

	struct DrawPizeLogDBProto_s : public NFDescStoreSeqOP {
		DrawPizeLogDBProto_s();
		virtual ~DrawPizeLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//
		int32_t id;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::DrawPizeLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::DrawPizeLogDBProto & msg);
		static ::proto_ff::DrawPizeLogDBProto* new_pbmsg(){ return new ::proto_ff::DrawPizeLogDBProto(); }
		static ::proto_ff::DrawPizeLogDBProto make_pbmsg(){ return ::proto_ff::DrawPizeLogDBProto(); }
	};
	typedef struct DrawPizeLogDBProto_s DrawPizeLogDBProto_t;

	struct FestDrawPizeLogDBProto_s : public NFDescStoreSeqOP {
		FestDrawPizeLogDBProto_s();
		virtual ~FestDrawPizeLogDBProto_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t template_id;//
		NFShmVector<struct DrawPizeLogDBProto_s, DEFINE_FESTDRAWPIZELOGDBPROTO_INFO_MAX_NUM> info;//
		uint32_t server_num;//

		virtual void write_to_pbmsg(::proto_ff::FestDrawPizeLogDBProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestDrawPizeLogDBProto & msg);
		static ::proto_ff::FestDrawPizeLogDBProto* new_pbmsg(){ return new ::proto_ff::FestDrawPizeLogDBProto(); }
		static ::proto_ff::FestDrawPizeLogDBProto make_pbmsg(){ return ::proto_ff::FestDrawPizeLogDBProto(); }
	};
	typedef struct FestDrawPizeLogDBProto_s FestDrawPizeLogDBProto_t;

	struct FestRankRewardData_s : public NFDescStoreSeqOP {
		FestRankRewardData_s();
		virtual ~FestRankRewardData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FestRankRewardData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRankRewardData & msg);
		static ::proto_ff::FestRankRewardData* new_pbmsg(){ return new ::proto_ff::FestRankRewardData(); }
		static ::proto_ff::FestRankRewardData make_pbmsg(){ return ::proto_ff::FestRankRewardData(); }
	};
	typedef struct FestRankRewardData_s FestRankRewardData_t;

	struct FestRankData_s : public NFDescStoreSeqOP {
		FestRankData_s();
		virtual ~FestRankData_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t rank_id;//
		NFShmVector<struct FestRankRewardData_s, DEFINE_FESTRANKDATA_DATA_MAX_NUM> data;//
		uint32_t active_status;//
		uint32_t red_point_status;//
		uint32_t gift_status;//

		virtual void write_to_pbmsg(::proto_ff::FestRankData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRankData & msg);
		static ::proto_ff::FestRankData* new_pbmsg(){ return new ::proto_ff::FestRankData(); }
		static ::proto_ff::FestRankData make_pbmsg(){ return ::proto_ff::FestRankData(); }
	};
	typedef struct FestRankData_s FestRankData_t;

	struct FestRankDBData_s : public NFDescStoreSeqOP {
		FestRankDBData_s();
		virtual ~FestRankDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestRankData_s, DEFINE_FESTRANKDBDATA_DATA_MAX_NUM> data;//

		virtual void write_to_pbmsg(::proto_ff::FestRankDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestRankDBData & msg);
		static ::proto_ff::FestRankDBData* new_pbmsg(){ return new ::proto_ff::FestRankDBData(); }
		static ::proto_ff::FestRankDBData make_pbmsg(){ return ::proto_ff::FestRankDBData(); }
	};
	typedef struct FestRankDBData_s FestRankDBData_t;

	struct NotifyWorldInfo_s : public NFDescStoreSeqOP {
		NotifyWorldInfo_s();
		virtual ~NotifyWorldInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t world_lv;//
		int32_t world_lv_4;//
		int32_t world_lv_8;//
		int32_t world_lv_16;//

		virtual void write_to_pbmsg(::proto_ff::NotifyWorldInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NotifyWorldInfo & msg);
		static ::proto_ff::NotifyWorldInfo* new_pbmsg(){ return new ::proto_ff::NotifyWorldInfo(); }
		static ::proto_ff::NotifyWorldInfo make_pbmsg(){ return ::proto_ff::NotifyWorldInfo(); }
	};
	typedef struct NotifyWorldInfo_s NotifyWorldInfo_t;

	struct SynWorldInfoReq_s : public NFDescStoreSeqOP {
		SynWorldInfoReq_s();
		virtual ~SynWorldInfoReq_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct ComPair_s, DEFINE_SYNWORLDINFOREQ_INFOS_MAX_NUM> infos;//

		virtual void write_to_pbmsg(::proto_ff::SynWorldInfoReq & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SynWorldInfoReq & msg);
		static ::proto_ff::SynWorldInfoReq* new_pbmsg(){ return new ::proto_ff::SynWorldInfoReq(); }
		static ::proto_ff::SynWorldInfoReq make_pbmsg(){ return ::proto_ff::SynWorldInfoReq(); }
	};
	typedef struct SynWorldInfoReq_s SynWorldInfoReq_t;

	struct SceneTransParam_s : public NFDescStoreSeqOP {
		SceneTransParam_s();
		virtual ~SceneTransParam_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t src_map;//
		NFShmString<32> src_param;//
		int32_t trans_type;//
		int64_t param1;//
		int64_t param2;//
		int64_t param3;//
		NFShmString<32> str_param;//
		bool forceTP;//
		int32_t ret;//

		virtual void write_to_pbmsg(::proto_ff::SceneTransParam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SceneTransParam & msg);
		static ::proto_ff::SceneTransParam* new_pbmsg(){ return new ::proto_ff::SceneTransParam(); }
		static ::proto_ff::SceneTransParam make_pbmsg(){ return ::proto_ff::SceneTransParam(); }
	};
	typedef struct SceneTransParam_s SceneTransParam_t;

	struct FestHuiMengXiYouReward_s : public NFDescStoreSeqOP {
		FestHuiMengXiYouReward_s();
		virtual ~FestHuiMengXiYouReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t status;//

		virtual void write_to_pbmsg(::proto_ff::FestHuiMengXiYouReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouReward & msg);
		static ::proto_ff::FestHuiMengXiYouReward* new_pbmsg(){ return new ::proto_ff::FestHuiMengXiYouReward(); }
		static ::proto_ff::FestHuiMengXiYouReward make_pbmsg(){ return ::proto_ff::FestHuiMengXiYouReward(); }
	};
	typedef struct FestHuiMengXiYouReward_s FestHuiMengXiYouReward_t;

	struct FestHuiMengXiYouGame_s : public NFDescStoreSeqOP {
		FestHuiMengXiYouGame_s();
		virtual ~FestHuiMengXiYouGame_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t cur_points;//
		bool finish;//
		int32_t cur_prestige;//

		virtual void write_to_pbmsg(::proto_ff::FestHuiMengXiYouGame & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouGame & msg);
		static ::proto_ff::FestHuiMengXiYouGame* new_pbmsg(){ return new ::proto_ff::FestHuiMengXiYouGame(); }
		static ::proto_ff::FestHuiMengXiYouGame make_pbmsg(){ return ::proto_ff::FestHuiMengXiYouGame(); }
	};
	typedef struct FestHuiMengXiYouGame_s FestHuiMengXiYouGame_t;

	struct FestHuiMengXiYouData_s : public NFDescStoreSeqOP {
		FestHuiMengXiYouData_s();
		virtual ~FestHuiMengXiYouData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct FestHuiMengXiYouReward_s, DEFINE_FESTHUIMENGXIYOUDATA_REWARD_MAX_NUM> reward;//
		int32_t cur_points;//
		NFShmVector<struct FestHuiMengXiYouGame_s, DEFINE_FESTHUIMENGXIYOUDATA_GAME_MAX_NUM> game;//
		int32_t prestige;//
		uint64_t flush_time;//
		int32_t cur_game_id;//

		virtual void write_to_pbmsg(::proto_ff::FestHuiMengXiYouData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouData & msg);
		static ::proto_ff::FestHuiMengXiYouData* new_pbmsg(){ return new ::proto_ff::FestHuiMengXiYouData(); }
		static ::proto_ff::FestHuiMengXiYouData make_pbmsg(){ return ::proto_ff::FestHuiMengXiYouData(); }
	};
	typedef struct FestHuiMengXiYouData_s FestHuiMengXiYouData_t;

	struct GHostDupRankInfo_s : public NFDescStoreSeqOP {
		GHostDupRankInfo_s();
		virtual ~GHostDupRankInfo_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t rank;//
		NFShmString<32> name;//
		uint64_t cid;//
		int32_t wave;//
		int32_t time;//
		uint64_t update_time;//

		virtual void write_to_pbmsg(::proto_ff::GHostDupRankInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GHostDupRankInfo & msg);
		static ::proto_ff::GHostDupRankInfo* new_pbmsg(){ return new ::proto_ff::GHostDupRankInfo(); }
		static ::proto_ff::GHostDupRankInfo make_pbmsg(){ return ::proto_ff::GHostDupRankInfo(); }
	};
	typedef struct GHostDupRankInfo_s GHostDupRankInfo_t;

	struct StarFantasyData_s : public NFDescStoreSeqOP {
		StarFantasyData_s();
		virtual ~StarFantasyData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t status;//
		uint32_t level;//
		uint32_t advance_level;//

		virtual void write_to_pbmsg(::proto_ff::StarFantasyData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarFantasyData & msg);
		static ::proto_ff::StarFantasyData* new_pbmsg(){ return new ::proto_ff::StarFantasyData(); }
		static ::proto_ff::StarFantasyData make_pbmsg(){ return ::proto_ff::StarFantasyData(); }
	};
	typedef struct StarFantasyData_s StarFantasyData_t;

	struct StarSetupHoleData_s : public NFDescStoreSeqOP {
		StarSetupHoleData_s();
		virtual ~StarSetupHoleData_s(){}
		int CreateInit();
		int ResumeInit();
		struct EquipInfo_s equip_info;//
		uint32_t id;//
		uint64_t score;//

		virtual void write_to_pbmsg(::proto_ff::StarSetupHoleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarSetupHoleData & msg);
		static ::proto_ff::StarSetupHoleData* new_pbmsg(){ return new ::proto_ff::StarSetupHoleData(); }
		static ::proto_ff::StarSetupHoleData make_pbmsg(){ return ::proto_ff::StarSetupHoleData(); }
	};
	typedef struct StarSetupHoleData_s StarSetupHoleData_t;

	struct StarSetupStarAttrData_s : public NFDescStoreSeqOP {
		StarSetupStarAttrData_s();
		virtual ~StarSetupStarAttrData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t status;//

		virtual void write_to_pbmsg(::proto_ff::StarSetupStarAttrData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarSetupStarAttrData & msg);
		static ::proto_ff::StarSetupStarAttrData* new_pbmsg(){ return new ::proto_ff::StarSetupStarAttrData(); }
		static ::proto_ff::StarSetupStarAttrData make_pbmsg(){ return ::proto_ff::StarSetupStarAttrData(); }
	};
	typedef struct StarSetupStarAttrData_s StarSetupStarAttrData_t;

	struct StarSetupData_s : public NFDescStoreSeqOP {
		StarSetupData_s();
		virtual ~StarSetupData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t status;//
		uint64_t unlock_time;//
		NFShmVector<struct StarSetupHoleData_s, DEFINE_STARSETUPDATA_HOLE_DATA_MAX_NUM> hole_data;//
		uint32_t guizhen_id;//
		uint32_t guizhen_status;//
		uint32_t star_num;//
		NFShmVector<struct StarSetupStarAttrData_s, DEFINE_STARSETUPDATA_STAR_ATTR_MAX_NUM> star_attr;//

		virtual void write_to_pbmsg(::proto_ff::StarSetupData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarSetupData & msg);
		static ::proto_ff::StarSetupData* new_pbmsg(){ return new ::proto_ff::StarSetupData(); }
		static ::proto_ff::StarSetupData make_pbmsg(){ return ::proto_ff::StarSetupData(); }
	};
	typedef struct StarSetupData_s StarSetupData_t;

	struct StarSkillData_s : public NFDescStoreSeqOP {
		StarSkillData_s();
		virtual ~StarSkillData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t level;//
		bool finish;//

		virtual void write_to_pbmsg(::proto_ff::StarSkillData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarSkillData & msg);
		static ::proto_ff::StarSkillData* new_pbmsg(){ return new ::proto_ff::StarSkillData(); }
		static ::proto_ff::StarSkillData make_pbmsg(){ return ::proto_ff::StarSkillData(); }
	};
	typedef struct StarSkillData_s StarSkillData_t;

	struct StarSkillSlotData_s : public NFDescStoreSeqOP {
		StarSkillSlotData_s();
		virtual ~StarSkillSlotData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t slot_id;//
		uint32_t status;//
		uint32_t cur_id;//
		uint32_t cur_end_time;//

		virtual void write_to_pbmsg(::proto_ff::StarSkillSlotData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarSkillSlotData & msg);
		static ::proto_ff::StarSkillSlotData* new_pbmsg(){ return new ::proto_ff::StarSkillSlotData(); }
		static ::proto_ff::StarSkillSlotData make_pbmsg(){ return ::proto_ff::StarSkillSlotData(); }
	};
	typedef struct StarSkillSlotData_s StarSkillSlotData_t;

	struct StarShopData_s : public NFDescStoreSeqOP {
		StarShopData_s();
		virtual ~StarShopData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		uint32_t buy_num;//

		virtual void write_to_pbmsg(::proto_ff::StarShopData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarShopData & msg);
		static ::proto_ff::StarShopData* new_pbmsg(){ return new ::proto_ff::StarShopData(); }
		static ::proto_ff::StarShopData make_pbmsg(){ return ::proto_ff::StarShopData(); }
	};
	typedef struct StarShopData_s StarShopData_t;

	struct StarData_s : public NFDescStoreSeqOP {
		StarData_s();
		virtual ~StarData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct StarSetupData_s, DEFINE_STARDATA_SETUP_DATA_MAX_NUM> setup_data;//
		NFShmVector<struct StarFantasyData_s, DEFINE_STARDATA_FANTASY_DATA_MAX_NUM> fantasy_data;//
		uint32_t cur_fantasy_id;//
		NFShmVector<struct StarSkillData_s, DEFINE_STARDATA_SKILL_DATA_MAX_NUM> skill_data;//
		NFShmVector<struct StarSkillSlotData_s, DEFINE_STARDATA_SKILL_SLOT_DATA_MAX_NUM> skill_slot_data;//
		NFShmVector<struct StarShopData_s, DEFINE_STARDATA_SHOP_DATA_MAX_NUM> shop_data;//
		uint64_t last_shop_refresh_time;//

		virtual void write_to_pbmsg(::proto_ff::StarData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::StarData & msg);
		static ::proto_ff::StarData* new_pbmsg(){ return new ::proto_ff::StarData(); }
		static ::proto_ff::StarData make_pbmsg(){ return ::proto_ff::StarData(); }
	};
	typedef struct StarData_s StarData_t;

	struct TurnSlot_s : public NFDescStoreSeqOP {
		TurnSlot_s();
		virtual ~TurnSlot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t stronglv;//

		virtual void write_to_pbmsg(::proto_ff::TurnSlot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnSlot & msg);
		static ::proto_ff::TurnSlot* new_pbmsg(){ return new ::proto_ff::TurnSlot(); }
		static ::proto_ff::TurnSlot make_pbmsg(){ return ::proto_ff::TurnSlot(); }
	};
	typedef struct TurnSlot_s TurnSlot_t;

	struct TurnGrow_s : public NFDescStoreSeqOP {
		TurnGrow_s();
		virtual ~TurnGrow_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t pos;//
		struct ItemProtoInfo_s equip;//
		struct TurnSlot_s slot;//

		virtual void write_to_pbmsg(::proto_ff::TurnGrow & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnGrow & msg);
		static ::proto_ff::TurnGrow* new_pbmsg(){ return new ::proto_ff::TurnGrow(); }
		static ::proto_ff::TurnGrow make_pbmsg(){ return ::proto_ff::TurnGrow(); }
	};
	typedef struct TurnGrow_s TurnGrow_t;

	struct TurnEntry_s : public NFDescStoreSeqOP {
		TurnEntry_s();
		virtual ~TurnEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;//
		NFShmVector<struct TurnGrow_s, DEFINE_TURNENTRY_INFOS_MAX_NUM> infos;//
		NFShmVector<int32_t, DEFINE_TURNENTRY_STRONG_IDS_MAX_NUM> strong_ids;//

		virtual void write_to_pbmsg(::proto_ff::TurnEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnEntry & msg);
		static ::proto_ff::TurnEntry* new_pbmsg(){ return new ::proto_ff::TurnEntry(); }
		static ::proto_ff::TurnEntry make_pbmsg(){ return ::proto_ff::TurnEntry(); }
	};
	typedef struct TurnEntry_s TurnEntry_t;

	struct TurnSimple_s : public NFDescStoreSeqOP {
		TurnSimple_s();
		virtual ~TurnSimple_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t turn_lv;//
		int32_t cur_lv;//
		uint64_t cur_exp;//
		int32_t failed_add;//
		int32_t day_turn_num;//
		int32_t active_all_star_id;//

		virtual void write_to_pbmsg(::proto_ff::TurnSimple & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnSimple & msg);
		static ::proto_ff::TurnSimple* new_pbmsg(){ return new ::proto_ff::TurnSimple(); }
		static ::proto_ff::TurnSimple make_pbmsg(){ return ::proto_ff::TurnSimple(); }
	};
	typedef struct TurnSimple_s TurnSimple_t;

	struct TurnHelper_s : public NFDescStoreSeqOP {
		TurnHelper_s();
		virtual ~TurnHelper_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		NFShmString<32> name;//
		uint64_t time;//

		virtual void write_to_pbmsg(::proto_ff::TurnHelper & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnHelper & msg);
		static ::proto_ff::TurnHelper* new_pbmsg(){ return new ::proto_ff::TurnHelper(); }
		static ::proto_ff::TurnHelper make_pbmsg(){ return ::proto_ff::TurnHelper(); }
	};
	typedef struct TurnHelper_s TurnHelper_t;

	struct TurnTask_s : public NFDescStoreSeqOP {
		TurnTask_s();
		virtual ~TurnTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::TurnTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::TurnTask & msg);
		static ::proto_ff::TurnTask* new_pbmsg(){ return new ::proto_ff::TurnTask(); }
		static ::proto_ff::TurnTask make_pbmsg(){ return ::proto_ff::TurnTask(); }
	};
	typedef struct TurnTask_s TurnTask_t;

	struct FMarryTask_s : public NFDescStoreSeqOP {
		FMarryTask_s();
		virtual ~FMarryTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t val;//
		int32_t state;//

		virtual void write_to_pbmsg(::proto_ff::FMarryTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::FMarryTask & msg);
		static ::proto_ff::FMarryTask* new_pbmsg(){ return new ::proto_ff::FMarryTask(); }
		static ::proto_ff::FMarryTask make_pbmsg(){ return ::proto_ff::FMarryTask(); }
	};
	typedef struct FMarryTask_s FMarryTask_t;

	struct SoulEntry_s : public NFDescStoreSeqOP {
		SoulEntry_s();
		virtual ~SoulEntry_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;//
		int32_t lv;//
		int32_t steplv;//

		virtual void write_to_pbmsg(::proto_ff::SoulEntry & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SoulEntry & msg);
		static ::proto_ff::SoulEntry* new_pbmsg(){ return new ::proto_ff::SoulEntry(); }
		static ::proto_ff::SoulEntry make_pbmsg(){ return ::proto_ff::SoulEntry(); }
	};
	typedef struct SoulEntry_s SoulEntry_t;

	struct SoulPool_s : public NFDescStoreSeqOP {
		SoulPool_s();
		virtual ~SoulPool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t poolBlessLv;//
		int32_t poolPgLv;//

		virtual void write_to_pbmsg(::proto_ff::SoulPool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::SoulPool & msg);
		static ::proto_ff::SoulPool* new_pbmsg(){ return new ::proto_ff::SoulPool(); }
		static ::proto_ff::SoulPool make_pbmsg(){ return ::proto_ff::SoulPool(); }
	};
	typedef struct SoulPool_s SoulPool_t;

}

