#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Nickgod.pb.h"
#include "E_Nickgod_s.h"

#define DEFINE_SHEET_NICKGODCONSTANT_E_NICKGODCONSTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_NICKGODNAME_E_NICKGODNAME_LIST_MAX_NUM 32
#define DEFINE_E_NICKGODSTAGE_M_MOS_MAX_NUM 10
#define DEFINE_E_NICKGODSTAGE_M_BOSS_MAX_NUM 4
#define DEFINE_E_NICKGODSTAGE_M_REVIVALPOINT_MAX_NUM 8
#define DEFINE_SHEET_NICKGODSTAGE_E_NICKGODSTAGE_LIST_MAX_NUM 4
#define DEFINE_E_NICKGODREWARDS_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_NICKGODREWARDS_E_NICKGODREWARDS_LIST_MAX_NUM 16
#define DEFINE_SHEET_NICKGODLATTICE_E_NICKGODLATTICE_LIST_MAX_NUM 64
#define DEFINE_E_NICKGODTREASURY_M_ITEM_MAX_NUM 37
#define DEFINE_SHEET_NICKGODTREASURY_E_NICKGODTREASURY_LIST_MAX_NUM 16
#define DEFINE_E_NICKGODPRIVILEGE_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_NICKGODPRIVILEGE_E_NICKGODPRIVILEGE_LIST_MAX_NUM 16
#define DEFINE_E_NICKGODSALE_M_ITEM_MAX_NUM 4
#define DEFINE_SHEET_NICKGODSALE_E_NICKGODSALE_LIST_MAX_NUM 8
#define DEFINE_E_NICKGODCHARGEUP_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_NICKGODCHARGEUP_E_NICKGODCHARGEUP_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_NickgodConstant_s : public NFDescStoreSeqOP {
		E_NickgodConstant_s();
		virtual ~E_NickgodConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//序号
		int32_t m_skill;//模版技能
		int32_t m_time;//备战时间上限
		int32_t m_maxUser;//备战人数上限
		int32_t m_floorsMax;//宝库最大层数
		int32_t m_lattice;//每层格子数
		int32_t m_repairItem;//道具补足货币
		int32_t m_repairNum;//道具补足数量
		int32_t m_openItem;//特权开通货币
		int32_t m_openNum;//特权开通数量
		NFShmString<64> m_week;//特权特惠开启周
		int32_t m_opentime;//特权特惠开启时间
		int32_t m_endtime;//特权特惠结束时间
		int32_t m_logMax;//日志最大数量
		int32_t m_readyMap;//备战地图
		int32_t m_readyPiont;//备战出生点
		int32_t m_actId;//活动id

		virtual void write_to_pbmsg(::proto_ff::E_NickgodConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodConstant & msg);
		static ::proto_ff::E_NickgodConstant* new_pbmsg(){ return new ::proto_ff::E_NickgodConstant(); }
		static ::proto_ff::E_NickgodConstant make_pbmsg(){ return ::proto_ff::E_NickgodConstant(); }
	};
	typedef struct E_NickgodConstant_s E_NickgodConstant_t;

	struct Sheet_NickgodConstant_s : public NFDescStoreSeqOP {
		Sheet_NickgodConstant_s();
		virtual ~Sheet_NickgodConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodConstant_s, DEFINE_SHEET_NICKGODCONSTANT_E_NICKGODCONSTANT_LIST_MAX_NUM> E_NickgodConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodConstant & msg);
		static ::proto_ff::Sheet_NickgodConstant* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodConstant(); }
		static ::proto_ff::Sheet_NickgodConstant make_pbmsg(){ return ::proto_ff::Sheet_NickgodConstant(); }
	};
	typedef struct Sheet_NickgodConstant_s Sheet_NickgodConstant_t;

	struct E_NickgodName_s : public NFDescStoreSeqOP {
		E_NickgodName_s();
		virtual ~E_NickgodName_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名称

		virtual void write_to_pbmsg(::proto_ff::E_NickgodName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodName & msg);
		static ::proto_ff::E_NickgodName* new_pbmsg(){ return new ::proto_ff::E_NickgodName(); }
		static ::proto_ff::E_NickgodName make_pbmsg(){ return ::proto_ff::E_NickgodName(); }
	};
	typedef struct E_NickgodName_s E_NickgodName_t;

	struct Sheet_NickgodName_s : public NFDescStoreSeqOP {
		Sheet_NickgodName_s();
		virtual ~Sheet_NickgodName_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodName_s, DEFINE_SHEET_NICKGODNAME_E_NICKGODNAME_LIST_MAX_NUM> E_NickgodName_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodName & msg);
		static ::proto_ff::Sheet_NickgodName* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodName(); }
		static ::proto_ff::Sheet_NickgodName make_pbmsg(){ return ::proto_ff::Sheet_NickgodName(); }
	};
	typedef struct Sheet_NickgodName_s Sheet_NickgodName_t;

	struct E_NickgodStageMosDesc_s : public NFDescStoreSeqOP {
		E_NickgodStageMosDesc_s();
		virtual ~E_NickgodStageMosDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_point;//刷新点

		virtual void write_to_pbmsg(::proto_ff::E_NickgodStageMosDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodStageMosDesc & msg);
		static ::proto_ff::E_NickgodStageMosDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodStageMosDesc(); }
		static ::proto_ff::E_NickgodStageMosDesc make_pbmsg(){ return ::proto_ff::E_NickgodStageMosDesc(); }
	};
	typedef struct E_NickgodStageMosDesc_s E_NickgodStageMosDesc_t;

	struct E_NickgodStageBossDesc_s : public NFDescStoreSeqOP {
		E_NickgodStageBossDesc_s();
		virtual ~E_NickgodStageBossDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_dropPreview;//掉落预览
		int32_t m_id;//id
		int32_t m_point;//刷新点

		virtual void write_to_pbmsg(::proto_ff::E_NickgodStageBossDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodStageBossDesc & msg);
		static ::proto_ff::E_NickgodStageBossDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodStageBossDesc(); }
		static ::proto_ff::E_NickgodStageBossDesc make_pbmsg(){ return ::proto_ff::E_NickgodStageBossDesc(); }
	};
	typedef struct E_NickgodStageBossDesc_s E_NickgodStageBossDesc_t;

	struct E_NickgodStage_s : public NFDescStoreSeqOP {
		E_NickgodStage_s();
		virtual ~E_NickgodStage_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//阶段id
		int32_t m_map;//阶段地图id
		int32_t m_duration;//阶段持续时间
		int32_t m_mosDieRefresh;//小怪死亡刷新时间
		int32_t m_bossFirstRefresh;//boss初始刷新时间
		int32_t m_bossDieRefresh;//boss死亡刷新时间
		int32_t m_playerDieDrop;//玩家死亡掉落装备概率
		int32_t m_sceneIntegralTime;//场景积分间隔时间
		int32_t m_sceneIntegral;//场景积分
		int32_t m_killmosIntegral;//击杀小怪积分
		int32_t m_killbossIntegral;//击杀boss积分
		int32_t m_killplayerIntegral;//击杀玩家积分
		int32_t m_assistplayerIntegral;//助攻玩家积分
		NFShmVector<struct E_NickgodStageMosDesc_s, DEFINE_E_NICKGODSTAGE_M_MOS_MAX_NUM> m_mos;//小怪
		NFShmVector<struct E_NickgodStageBossDesc_s, DEFINE_E_NICKGODSTAGE_M_BOSS_MAX_NUM> m_boss;//boss
		NFShmVector<int32_t, DEFINE_E_NICKGODSTAGE_M_REVIVALPOINT_MAX_NUM> m_revivalPoint;//复活点

		virtual void write_to_pbmsg(::proto_ff::E_NickgodStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodStage & msg);
		static ::proto_ff::E_NickgodStage* new_pbmsg(){ return new ::proto_ff::E_NickgodStage(); }
		static ::proto_ff::E_NickgodStage make_pbmsg(){ return ::proto_ff::E_NickgodStage(); }
	};
	typedef struct E_NickgodStage_s E_NickgodStage_t;

	struct Sheet_NickgodStage_s : public NFDescStoreSeqOP {
		Sheet_NickgodStage_s();
		virtual ~Sheet_NickgodStage_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodStage_s, DEFINE_SHEET_NICKGODSTAGE_E_NICKGODSTAGE_LIST_MAX_NUM> E_NickgodStage_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodStage & msg);
		static ::proto_ff::Sheet_NickgodStage* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodStage(); }
		static ::proto_ff::Sheet_NickgodStage make_pbmsg(){ return ::proto_ff::Sheet_NickgodStage(); }
	};
	typedef struct Sheet_NickgodStage_s Sheet_NickgodStage_t;

	struct E_NickgodRewardsRewardDesc_s : public NFDescStoreSeqOP {
		E_NickgodRewardsRewardDesc_s();
		virtual ~E_NickgodRewardsRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_NickgodRewardsRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodRewardsRewardDesc & msg);
		static ::proto_ff::E_NickgodRewardsRewardDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodRewardsRewardDesc(); }
		static ::proto_ff::E_NickgodRewardsRewardDesc make_pbmsg(){ return ::proto_ff::E_NickgodRewardsRewardDesc(); }
	};
	typedef struct E_NickgodRewardsRewardDesc_s E_NickgodRewardsRewardDesc_t;

	struct E_NickgodRewards_s : public NFDescStoreSeqOP {
		E_NickgodRewards_s();
		virtual ~E_NickgodRewards_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_rankingMin;//名次最小值
		int32_t m_rankingMax;//名次最大值
		int32_t m_score;//积分数量
		NFShmVector<struct E_NickgodRewardsRewardDesc_s, DEFINE_E_NICKGODREWARDS_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_NickgodRewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodRewards & msg);
		static ::proto_ff::E_NickgodRewards* new_pbmsg(){ return new ::proto_ff::E_NickgodRewards(); }
		static ::proto_ff::E_NickgodRewards make_pbmsg(){ return ::proto_ff::E_NickgodRewards(); }
	};
	typedef struct E_NickgodRewards_s E_NickgodRewards_t;

	struct Sheet_NickgodRewards_s : public NFDescStoreSeqOP {
		Sheet_NickgodRewards_s();
		virtual ~Sheet_NickgodRewards_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodRewards_s, DEFINE_SHEET_NICKGODREWARDS_E_NICKGODREWARDS_LIST_MAX_NUM> E_NickgodRewards_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodRewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodRewards & msg);
		static ::proto_ff::Sheet_NickgodRewards* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodRewards(); }
		static ::proto_ff::Sheet_NickgodRewards make_pbmsg(){ return ::proto_ff::Sheet_NickgodRewards(); }
	};
	typedef struct Sheet_NickgodRewards_s Sheet_NickgodRewards_t;

	struct E_NickgodLattice_s : public NFDescStoreSeqOP {
		E_NickgodLattice_s();
		virtual ~E_NickgodLattice_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//进度id
		int32_t m_itemId;//消耗道具
		int32_t m_itemNum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_NickgodLattice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodLattice & msg);
		static ::proto_ff::E_NickgodLattice* new_pbmsg(){ return new ::proto_ff::E_NickgodLattice(); }
		static ::proto_ff::E_NickgodLattice make_pbmsg(){ return ::proto_ff::E_NickgodLattice(); }
	};
	typedef struct E_NickgodLattice_s E_NickgodLattice_t;

	struct Sheet_NickgodLattice_s : public NFDescStoreSeqOP {
		Sheet_NickgodLattice_s();
		virtual ~Sheet_NickgodLattice_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodLattice_s, DEFINE_SHEET_NICKGODLATTICE_E_NICKGODLATTICE_LIST_MAX_NUM> E_NickgodLattice_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodLattice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodLattice & msg);
		static ::proto_ff::Sheet_NickgodLattice* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodLattice(); }
		static ::proto_ff::Sheet_NickgodLattice make_pbmsg(){ return ::proto_ff::Sheet_NickgodLattice(); }
	};
	typedef struct Sheet_NickgodLattice_s Sheet_NickgodLattice_t;

	struct E_NickgodTreasuryItemDesc_s : public NFDescStoreSeqOP {
		E_NickgodTreasuryItemDesc_s();
		virtual ~E_NickgodTreasuryItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_show;//展示
		int32_t m_rand;//权重
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_NickgodTreasuryItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodTreasuryItemDesc & msg);
		static ::proto_ff::E_NickgodTreasuryItemDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodTreasuryItemDesc(); }
		static ::proto_ff::E_NickgodTreasuryItemDesc make_pbmsg(){ return ::proto_ff::E_NickgodTreasuryItemDesc(); }
	};
	typedef struct E_NickgodTreasuryItemDesc_s E_NickgodTreasuryItemDesc_t;

	struct E_NickgodTreasury_s : public NFDescStoreSeqOP {
		E_NickgodTreasury_s();
		virtual ~E_NickgodTreasury_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//层数
		NFShmVector<struct E_NickgodTreasuryItemDesc_s, DEFINE_E_NICKGODTREASURY_M_ITEM_MAX_NUM> m_item;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_NickgodTreasury & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodTreasury & msg);
		static ::proto_ff::E_NickgodTreasury* new_pbmsg(){ return new ::proto_ff::E_NickgodTreasury(); }
		static ::proto_ff::E_NickgodTreasury make_pbmsg(){ return ::proto_ff::E_NickgodTreasury(); }
	};
	typedef struct E_NickgodTreasury_s E_NickgodTreasury_t;

	struct Sheet_NickgodTreasury_s : public NFDescStoreSeqOP {
		Sheet_NickgodTreasury_s();
		virtual ~Sheet_NickgodTreasury_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodTreasury_s, DEFINE_SHEET_NICKGODTREASURY_E_NICKGODTREASURY_LIST_MAX_NUM> E_NickgodTreasury_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodTreasury & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodTreasury & msg);
		static ::proto_ff::Sheet_NickgodTreasury* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodTreasury(); }
		static ::proto_ff::Sheet_NickgodTreasury make_pbmsg(){ return ::proto_ff::Sheet_NickgodTreasury(); }
	};
	typedef struct Sheet_NickgodTreasury_s Sheet_NickgodTreasury_t;

	struct E_NickgodPrivilegeRewardDesc_s : public NFDescStoreSeqOP {
		E_NickgodPrivilegeRewardDesc_s();
		virtual ~E_NickgodPrivilegeRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_NickgodPrivilegeRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodPrivilegeRewardDesc & msg);
		static ::proto_ff::E_NickgodPrivilegeRewardDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodPrivilegeRewardDesc(); }
		static ::proto_ff::E_NickgodPrivilegeRewardDesc make_pbmsg(){ return ::proto_ff::E_NickgodPrivilegeRewardDesc(); }
	};
	typedef struct E_NickgodPrivilegeRewardDesc_s E_NickgodPrivilegeRewardDesc_t;

	struct E_NickgodPrivilege_s : public NFDescStoreSeqOP {
		E_NickgodPrivilege_s();
		virtual ~E_NickgodPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//奖励id
		int32_t m_condition;//领取条件
		int32_t m_param;//参数
		int32_t m_open;//是否需要开通特权
		NFShmVector<struct E_NickgodPrivilegeRewardDesc_s, DEFINE_E_NICKGODPRIVILEGE_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_NickgodPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodPrivilege & msg);
		static ::proto_ff::E_NickgodPrivilege* new_pbmsg(){ return new ::proto_ff::E_NickgodPrivilege(); }
		static ::proto_ff::E_NickgodPrivilege make_pbmsg(){ return ::proto_ff::E_NickgodPrivilege(); }
	};
	typedef struct E_NickgodPrivilege_s E_NickgodPrivilege_t;

	struct Sheet_NickgodPrivilege_s : public NFDescStoreSeqOP {
		Sheet_NickgodPrivilege_s();
		virtual ~Sheet_NickgodPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodPrivilege_s, DEFINE_SHEET_NICKGODPRIVILEGE_E_NICKGODPRIVILEGE_LIST_MAX_NUM> E_NickgodPrivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodPrivilege & msg);
		static ::proto_ff::Sheet_NickgodPrivilege* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodPrivilege(); }
		static ::proto_ff::Sheet_NickgodPrivilege make_pbmsg(){ return ::proto_ff::Sheet_NickgodPrivilege(); }
	};
	typedef struct Sheet_NickgodPrivilege_s Sheet_NickgodPrivilege_t;

	struct E_NickgodSaleItemDesc_s : public NFDescStoreSeqOP {
		E_NickgodSaleItemDesc_s();
		virtual ~E_NickgodSaleItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_NickgodSaleItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodSaleItemDesc & msg);
		static ::proto_ff::E_NickgodSaleItemDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodSaleItemDesc(); }
		static ::proto_ff::E_NickgodSaleItemDesc make_pbmsg(){ return ::proto_ff::E_NickgodSaleItemDesc(); }
	};
	typedef struct E_NickgodSaleItemDesc_s E_NickgodSaleItemDesc_t;

	struct E_NickgodSale_s : public NFDescStoreSeqOP {
		E_NickgodSale_s();
		virtual ~E_NickgodSale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//礼包id
		NFShmString<64> m_discount;//折扣
		int32_t m_money;//购买货币
		int32_t m_price;//购买价格
		int32_t m_buyLimit;//限购次数
		NFShmVector<struct E_NickgodSaleItemDesc_s, DEFINE_E_NICKGODSALE_M_ITEM_MAX_NUM> m_item;//物品

		virtual void write_to_pbmsg(::proto_ff::E_NickgodSale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodSale & msg);
		static ::proto_ff::E_NickgodSale* new_pbmsg(){ return new ::proto_ff::E_NickgodSale(); }
		static ::proto_ff::E_NickgodSale make_pbmsg(){ return ::proto_ff::E_NickgodSale(); }
	};
	typedef struct E_NickgodSale_s E_NickgodSale_t;

	struct Sheet_NickgodSale_s : public NFDescStoreSeqOP {
		Sheet_NickgodSale_s();
		virtual ~Sheet_NickgodSale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodSale_s, DEFINE_SHEET_NICKGODSALE_E_NICKGODSALE_LIST_MAX_NUM> E_NickgodSale_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodSale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodSale & msg);
		static ::proto_ff::Sheet_NickgodSale* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodSale(); }
		static ::proto_ff::Sheet_NickgodSale make_pbmsg(){ return ::proto_ff::Sheet_NickgodSale(); }
	};
	typedef struct Sheet_NickgodSale_s Sheet_NickgodSale_t;

	struct E_NickgodChargeupRewardDesc_s : public NFDescStoreSeqOP {
		E_NickgodChargeupRewardDesc_s();
		virtual ~E_NickgodChargeupRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_NickgodChargeupRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodChargeupRewardDesc & msg);
		static ::proto_ff::E_NickgodChargeupRewardDesc* new_pbmsg(){ return new ::proto_ff::E_NickgodChargeupRewardDesc(); }
		static ::proto_ff::E_NickgodChargeupRewardDesc make_pbmsg(){ return ::proto_ff::E_NickgodChargeupRewardDesc(); }
	};
	typedef struct E_NickgodChargeupRewardDesc_s E_NickgodChargeupRewardDesc_t;

	struct E_NickgodChargeup_s : public NFDescStoreSeqOP {
		E_NickgodChargeup_s();
		virtual ~E_NickgodChargeup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//累充id
		int32_t m_pay;//充值金额
		NFShmVector<struct E_NickgodChargeupRewardDesc_s, DEFINE_E_NICKGODCHARGEUP_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_NickgodChargeup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_NickgodChargeup & msg);
		static ::proto_ff::E_NickgodChargeup* new_pbmsg(){ return new ::proto_ff::E_NickgodChargeup(); }
		static ::proto_ff::E_NickgodChargeup make_pbmsg(){ return ::proto_ff::E_NickgodChargeup(); }
	};
	typedef struct E_NickgodChargeup_s E_NickgodChargeup_t;

	struct Sheet_NickgodChargeup_s : public NFDescStoreSeqOP {
		Sheet_NickgodChargeup_s();
		virtual ~Sheet_NickgodChargeup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_NickgodChargeup_s, DEFINE_SHEET_NICKGODCHARGEUP_E_NICKGODCHARGEUP_LIST_MAX_NUM> E_NickgodChargeup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_NickgodChargeup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NickgodChargeup & msg);
		static ::proto_ff::Sheet_NickgodChargeup* new_pbmsg(){ return new ::proto_ff::Sheet_NickgodChargeup(); }
		static ::proto_ff::Sheet_NickgodChargeup make_pbmsg(){ return ::proto_ff::Sheet_NickgodChargeup(); }
	};
	typedef struct Sheet_NickgodChargeup_s Sheet_NickgodChargeup_t;

}

