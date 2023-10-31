#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Battlepass.pb.h"
#include "E_Battlepass_s.h"

#define DEFINE_SHEET_BATTLEPASSBATTLEPASS_E_BATTLEPASSBATTLEPASS_LIST_MAX_NUM 16
#define DEFINE_E_BATTLEPASSREWARD_M_ITEM_MAX_NUM 1
#define DEFINE_E_BATTLEPASSREWARD_M_PROITEM_MAX_NUM 2
#define DEFINE_SHEET_BATTLEPASSREWARD_E_BATTLEPASSREWARD_LIST_MAX_NUM 2048
#define DEFINE_E_BATTLEPASSTASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_BATTLEPASSTASK_E_BATTLEPASSTASK_LIST_MAX_NUM 32
#define DEFINE_SHEET_BATTLEPASSSHOP_E_BATTLEPASSSHOP_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_BattlepassBattlepass_s : public NFDescStoreSeqOP {
		E_BattlepassBattlepass_s();
		virtual ~E_BattlepassBattlepass_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_reward;//奖励组
		int32_t m_task;//任务组
		NFShmString<64> m_taskNum;//抽取任务数量
		int32_t m_freshCost;//刷新消耗
		int32_t m_shop;//店铺组
		int32_t m_shopCurrency;//商店货币
		int32_t m_severOpenType;//服务器开放类型
		int32_t m_openSeverDay;//开始开服时间
		int32_t m_closeSeverDay;//关闭时间
		int32_t m_priceType;//价格类型
		int32_t m_price;//普通版价格
		int32_t m_priceP;//高级版额外价格
		int32_t m_presentExp;//高级版赠送的经验值
		int32_t m_expCost;//经验货币
		int32_t m_expPrice;//每货币兑换经验值
		int32_t m_expItem;//获得道具自动获得经验

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassBattlepass & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassBattlepass & msg);
		static ::proto_ff::E_BattlepassBattlepass* new_pbmsg(){ return new ::proto_ff::E_BattlepassBattlepass(); }
		static ::proto_ff::E_BattlepassBattlepass make_pbmsg(){ return ::proto_ff::E_BattlepassBattlepass(); }
	};
	typedef struct E_BattlepassBattlepass_s E_BattlepassBattlepass_t;

	struct Sheet_BattlepassBattlepass_s : public NFDescStoreSeqOP {
		Sheet_BattlepassBattlepass_s();
		virtual ~Sheet_BattlepassBattlepass_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BattlepassBattlepass_s, DEFINE_SHEET_BATTLEPASSBATTLEPASS_E_BATTLEPASSBATTLEPASS_LIST_MAX_NUM> E_BattlepassBattlepass_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BattlepassBattlepass & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BattlepassBattlepass & msg);
		static ::proto_ff::Sheet_BattlepassBattlepass* new_pbmsg(){ return new ::proto_ff::Sheet_BattlepassBattlepass(); }
		static ::proto_ff::Sheet_BattlepassBattlepass make_pbmsg(){ return ::proto_ff::Sheet_BattlepassBattlepass(); }
	};
	typedef struct Sheet_BattlepassBattlepass_s Sheet_BattlepassBattlepass_t;

	struct E_BattlepassRewardItemDesc_s : public NFDescStoreSeqOP {
		E_BattlepassRewardItemDesc_s();
		virtual ~E_BattlepassRewardItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassRewardItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassRewardItemDesc & msg);
		static ::proto_ff::E_BattlepassRewardItemDesc* new_pbmsg(){ return new ::proto_ff::E_BattlepassRewardItemDesc(); }
		static ::proto_ff::E_BattlepassRewardItemDesc make_pbmsg(){ return ::proto_ff::E_BattlepassRewardItemDesc(); }
	};
	typedef struct E_BattlepassRewardItemDesc_s E_BattlepassRewardItemDesc_t;

	struct E_BattlepassRewardProitemDesc_s : public NFDescStoreSeqOP {
		E_BattlepassRewardProitemDesc_s();
		virtual ~E_BattlepassRewardProitemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassRewardProitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassRewardProitemDesc & msg);
		static ::proto_ff::E_BattlepassRewardProitemDesc* new_pbmsg(){ return new ::proto_ff::E_BattlepassRewardProitemDesc(); }
		static ::proto_ff::E_BattlepassRewardProitemDesc make_pbmsg(){ return ::proto_ff::E_BattlepassRewardProitemDesc(); }
	};
	typedef struct E_BattlepassRewardProitemDesc_s E_BattlepassRewardProitemDesc_t;

	struct E_BattlepassReward_s : public NFDescStoreSeqOP {
		E_BattlepassReward_s();
		virtual ~E_BattlepassReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组类型
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验
		int32_t m_Core;//核心节点标识
		int32_t m_buyLevel;//购买节点标识
		int32_t m_showItem;//展示物id
		NFShmVector<struct E_BattlepassRewardItemDesc_s, DEFINE_E_BATTLEPASSREWARD_M_ITEM_MAX_NUM> m_item;//奖励物品
		NFShmVector<struct E_BattlepassRewardProitemDesc_s, DEFINE_E_BATTLEPASSREWARD_M_PROITEM_MAX_NUM> m_proItem;//加强奖励物品

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassReward & msg);
		static ::proto_ff::E_BattlepassReward* new_pbmsg(){ return new ::proto_ff::E_BattlepassReward(); }
		static ::proto_ff::E_BattlepassReward make_pbmsg(){ return ::proto_ff::E_BattlepassReward(); }
	};
	typedef struct E_BattlepassReward_s E_BattlepassReward_t;

	struct Sheet_BattlepassReward_s : public NFDescStoreSeqOP {
		Sheet_BattlepassReward_s();
		virtual ~Sheet_BattlepassReward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BattlepassReward_s, DEFINE_SHEET_BATTLEPASSREWARD_E_BATTLEPASSREWARD_LIST_MAX_NUM> E_BattlepassReward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BattlepassReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BattlepassReward & msg);
		static ::proto_ff::Sheet_BattlepassReward* new_pbmsg(){ return new ::proto_ff::Sheet_BattlepassReward(); }
		static ::proto_ff::Sheet_BattlepassReward make_pbmsg(){ return ::proto_ff::Sheet_BattlepassReward(); }
	};
	typedef struct Sheet_BattlepassReward_s Sheet_BattlepassReward_t;

	struct E_BattlepassTask_s : public NFDescStoreSeqOP {
		E_BattlepassTask_s();
		virtual ~E_BattlepassTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_group;//组id
		int32_t m_taskRefresh;//任务类型
		int32_t m_lv;//开放等级
		int32_t m_tag;//所属页签
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_link;//链接
		int32_t m_exp;//经验
		NFShmVector<int32_t, DEFINE_E_BATTLEPASSTASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassTask & msg);
		static ::proto_ff::E_BattlepassTask* new_pbmsg(){ return new ::proto_ff::E_BattlepassTask(); }
		static ::proto_ff::E_BattlepassTask make_pbmsg(){ return ::proto_ff::E_BattlepassTask(); }
	};
	typedef struct E_BattlepassTask_s E_BattlepassTask_t;

	struct Sheet_BattlepassTask_s : public NFDescStoreSeqOP {
		Sheet_BattlepassTask_s();
		virtual ~Sheet_BattlepassTask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BattlepassTask_s, DEFINE_SHEET_BATTLEPASSTASK_E_BATTLEPASSTASK_LIST_MAX_NUM> E_BattlepassTask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BattlepassTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BattlepassTask & msg);
		static ::proto_ff::Sheet_BattlepassTask* new_pbmsg(){ return new ::proto_ff::Sheet_BattlepassTask(); }
		static ::proto_ff::Sheet_BattlepassTask make_pbmsg(){ return ::proto_ff::Sheet_BattlepassTask(); }
	};
	typedef struct Sheet_BattlepassTask_s Sheet_BattlepassTask_t;

	struct E_BattlepassShop_s : public NFDescStoreSeqOP {
		E_BattlepassShop_s();
		virtual ~E_BattlepassShop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_group;//组id
		int32_t m_itemID;//物品id
		int32_t m_itemNum;//物品数量
		int32_t m_costItem;//花费道具
		int32_t m_costNum;//花费数量
		int32_t m_numLimit;//限购数量

		virtual void write_to_pbmsg(::proto_ff::E_BattlepassShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BattlepassShop & msg);
		static ::proto_ff::E_BattlepassShop* new_pbmsg(){ return new ::proto_ff::E_BattlepassShop(); }
		static ::proto_ff::E_BattlepassShop make_pbmsg(){ return ::proto_ff::E_BattlepassShop(); }
	};
	typedef struct E_BattlepassShop_s E_BattlepassShop_t;

	struct Sheet_BattlepassShop_s : public NFDescStoreSeqOP {
		Sheet_BattlepassShop_s();
		virtual ~Sheet_BattlepassShop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BattlepassShop_s, DEFINE_SHEET_BATTLEPASSSHOP_E_BATTLEPASSSHOP_LIST_MAX_NUM> E_BattlepassShop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BattlepassShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BattlepassShop & msg);
		static ::proto_ff::Sheet_BattlepassShop* new_pbmsg(){ return new ::proto_ff::Sheet_BattlepassShop(); }
		static ::proto_ff::Sheet_BattlepassShop make_pbmsg(){ return ::proto_ff::Sheet_BattlepassShop(); }
	};
	typedef struct Sheet_BattlepassShop_s Sheet_BattlepassShop_t;

}

