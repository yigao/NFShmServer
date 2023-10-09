#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Xiuzhenroad.pb.h"
#include "E_Xiuzhenroad_s.h"

#define DEFINE_E_XIUZHENROADTASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_XIUZHENROADTASK_E_XIUZHENROADTASK_LIST_MAX_NUM 128
#define DEFINE_E_XIUZHENROADBONUSPOINTS_M_TOTALITEMS_MAX_NUM 2
#define DEFINE_SHEET_XIUZHENROADBONUSPOINTS_E_XIUZHENROADBONUSPOINTS_LIST_MAX_NUM 32
#define DEFINE_SHEET_XIUZHENROADSKILL_E_XIUZHENROADSKILL_LIST_MAX_NUM 32
#define DEFINE_SHEET_XIUZHENROADCLASSIFY_E_XIUZHENROADCLASSIFY_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_XiuzhenroadTask_s : public NFDescStoreSeqOP {
		E_XiuzhenroadTask_s();
		virtual ~E_XiuzhenroadTask_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_taskid;//任务ID
		int32_t m_tasktype;//任务类型
		int32_t m_eventtype;//事件类型
		int32_t m_reachprice;//达成值
		int32_t m_reward;//奖励物品
		int32_t m_reward_value;//奖励物品数量
		int32_t m_boxid;//box礼包ID
		int32_t m_integral;//奖励的积分
		int32_t m_linkid;//跳转ID
		NFShmVector<int32_t, DEFINE_E_XIUZHENROADTASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenroadTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenroadTask & msg);
		static ::proto_ff::E_XiuzhenroadTask* new_pbmsg(){ return new ::proto_ff::E_XiuzhenroadTask(); }
		static ::proto_ff::E_XiuzhenroadTask make_pbmsg(){ return ::proto_ff::E_XiuzhenroadTask(); }
	};
	typedef struct E_XiuzhenroadTask_s E_XiuzhenroadTask_t;

	struct Sheet_XiuzhenroadTask_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenroadTask_s();
		virtual ~Sheet_XiuzhenroadTask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenroadTask_s, DEFINE_SHEET_XIUZHENROADTASK_E_XIUZHENROADTASK_LIST_MAX_NUM> E_XiuzhenroadTask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadTask & msg);
		static ::proto_ff::Sheet_XiuzhenroadTask* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenroadTask(); }
		static ::proto_ff::Sheet_XiuzhenroadTask make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenroadTask(); }
	};
	typedef struct Sheet_XiuzhenroadTask_s Sheet_XiuzhenroadTask_t;

	struct E_XiuzhenroadBonuspointsTotalitemsDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenroadBonuspointsTotalitemsDesc_s();
		virtual ~E_XiuzhenroadBonuspointsTotalitemsDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc & msg);
		static ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc(); }
		static ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc(); }
	};
	typedef struct E_XiuzhenroadBonuspointsTotalitemsDesc_s E_XiuzhenroadBonuspointsTotalitemsDesc_t;

	struct E_XiuzhenroadBonuspoints_s : public NFDescStoreSeqOP {
		E_XiuzhenroadBonuspoints_s();
		virtual ~E_XiuzhenroadBonuspoints_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_totalrewardsid;//总积分奖励
		int32_t m_achievedpoints;//达成点数
		NFShmVector<struct E_XiuzhenroadBonuspointsTotalitemsDesc_s, DEFINE_E_XIUZHENROADBONUSPOINTS_M_TOTALITEMS_MAX_NUM> m_totalitems;//奖励物品

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenroadBonuspoints & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenroadBonuspoints & msg);
		static ::proto_ff::E_XiuzhenroadBonuspoints* new_pbmsg(){ return new ::proto_ff::E_XiuzhenroadBonuspoints(); }
		static ::proto_ff::E_XiuzhenroadBonuspoints make_pbmsg(){ return ::proto_ff::E_XiuzhenroadBonuspoints(); }
	};
	typedef struct E_XiuzhenroadBonuspoints_s E_XiuzhenroadBonuspoints_t;

	struct Sheet_XiuzhenroadBonuspoints_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenroadBonuspoints_s();
		virtual ~Sheet_XiuzhenroadBonuspoints_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenroadBonuspoints_s, DEFINE_SHEET_XIUZHENROADBONUSPOINTS_E_XIUZHENROADBONUSPOINTS_LIST_MAX_NUM> E_XiuzhenroadBonuspoints_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadBonuspoints & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadBonuspoints & msg);
		static ::proto_ff::Sheet_XiuzhenroadBonuspoints* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenroadBonuspoints(); }
		static ::proto_ff::Sheet_XiuzhenroadBonuspoints make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenroadBonuspoints(); }
	};
	typedef struct Sheet_XiuzhenroadBonuspoints_s Sheet_XiuzhenroadBonuspoints_t;

	struct E_XiuzhenroadSkill_s : public NFDescStoreSeqOP {
		E_XiuzhenroadSkill_s();
		virtual ~E_XiuzhenroadSkill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_activityskills;//活动分类技能
		int32_t m_skillid;//技能ID
		int32_t m_itenmid;//属性道具ID
		int32_t m_attribute;//道具增加属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenroadSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenroadSkill & msg);
		static ::proto_ff::E_XiuzhenroadSkill* new_pbmsg(){ return new ::proto_ff::E_XiuzhenroadSkill(); }
		static ::proto_ff::E_XiuzhenroadSkill make_pbmsg(){ return ::proto_ff::E_XiuzhenroadSkill(); }
	};
	typedef struct E_XiuzhenroadSkill_s E_XiuzhenroadSkill_t;

	struct Sheet_XiuzhenroadSkill_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenroadSkill_s();
		virtual ~Sheet_XiuzhenroadSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenroadSkill_s, DEFINE_SHEET_XIUZHENROADSKILL_E_XIUZHENROADSKILL_LIST_MAX_NUM> E_XiuzhenroadSkill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadSkill & msg);
		static ::proto_ff::Sheet_XiuzhenroadSkill* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenroadSkill(); }
		static ::proto_ff::Sheet_XiuzhenroadSkill make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenroadSkill(); }
	};
	typedef struct Sheet_XiuzhenroadSkill_s Sheet_XiuzhenroadSkill_t;

	struct E_XiuzhenroadClassify_s : public NFDescStoreSeqOP {
		E_XiuzhenroadClassify_s();
		virtual ~E_XiuzhenroadClassify_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_typeid;//任务类型ID
		NFShmString<64> m_gift;//礼包名称
		int32_t m_giftid;//礼包ID
		int32_t m_rechargeid;//礼包计费点ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenroadClassify & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenroadClassify & msg);
		static ::proto_ff::E_XiuzhenroadClassify* new_pbmsg(){ return new ::proto_ff::E_XiuzhenroadClassify(); }
		static ::proto_ff::E_XiuzhenroadClassify make_pbmsg(){ return ::proto_ff::E_XiuzhenroadClassify(); }
	};
	typedef struct E_XiuzhenroadClassify_s E_XiuzhenroadClassify_t;

	struct Sheet_XiuzhenroadClassify_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenroadClassify_s();
		virtual ~Sheet_XiuzhenroadClassify_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenroadClassify_s, DEFINE_SHEET_XIUZHENROADCLASSIFY_E_XIUZHENROADCLASSIFY_LIST_MAX_NUM> E_XiuzhenroadClassify_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadClassify & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadClassify & msg);
		static ::proto_ff::Sheet_XiuzhenroadClassify* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenroadClassify(); }
		static ::proto_ff::Sheet_XiuzhenroadClassify make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenroadClassify(); }
	};
	typedef struct Sheet_XiuzhenroadClassify_s Sheet_XiuzhenroadClassify_t;

}

