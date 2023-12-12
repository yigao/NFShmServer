#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Escort.pb.h"
#include "E_Escort_s.h"

#define DEFINE_SHEET_ESCORTESCORT_E_ESCORTESCORT_LIST_MAX_NUM 8
#define DEFINE_E_ESCORTCHANCE_M_ESCORT_MAX_NUM 4
#define DEFINE_SHEET_ESCORTCHANCE_E_ESCORTCHANCE_LIST_MAX_NUM 4
#define DEFINE_E_ESCORTREWARD_M_REWARD_MAX_NUM 12
#define DEFINE_SHEET_ESCORTREWARD_E_ESCORTREWARD_LIST_MAX_NUM 2048
#define DEFINE_SHEET_ESCORTCONST_E_ESCORTCONST_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_EscortEscort_s : public NFDescStoreSeqOP {
		E_EscortEscort_s();
		virtual ~E_EscortEscort_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_convoyId;//镖车ID
		NFShmString<64> m_convoyName;//物资车名称
		int32_t m_MonsterId;//物资车ID
		NFShmString<64> m_scalle;//大小与y轴朝向
		int32_t m_convoyLevel;//镖车等级
		int32_t m_chance;//默认获得权重
		int32_t m_rewardLvMultiply;//基础经验倍率

		virtual void write_to_pbmsg(::proto_ff::E_EscortEscort & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortEscort & msg);
		static ::proto_ff::E_EscortEscort* new_pbmsg(){ return new ::proto_ff::E_EscortEscort(); }
		static ::proto_ff::E_EscortEscort make_pbmsg(){ return ::proto_ff::E_EscortEscort(); }
	};
	typedef struct E_EscortEscort_s E_EscortEscort_t;

	struct Sheet_EscortEscort_s : public NFDescStoreSeqOP {
		Sheet_EscortEscort_s();
		virtual ~Sheet_EscortEscort_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EscortEscort_s, DEFINE_SHEET_ESCORTESCORT_E_ESCORTESCORT_LIST_MAX_NUM> E_EscortEscort_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EscortEscort & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EscortEscort & msg);
		static ::proto_ff::Sheet_EscortEscort* new_pbmsg(){ return new ::proto_ff::Sheet_EscortEscort(); }
		static ::proto_ff::Sheet_EscortEscort make_pbmsg(){ return ::proto_ff::Sheet_EscortEscort(); }
	};
	typedef struct Sheet_EscortEscort_s Sheet_EscortEscort_t;

	struct E_EscortChanceEscortDesc_s : public NFDescStoreSeqOP {
		E_EscortChanceEscortDesc_s();
		virtual ~E_EscortChanceEscortDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_chance;//权重
		int32_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EscortChanceEscortDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortChanceEscortDesc & msg);
		static ::proto_ff::E_EscortChanceEscortDesc* new_pbmsg(){ return new ::proto_ff::E_EscortChanceEscortDesc(); }
		static ::proto_ff::E_EscortChanceEscortDesc make_pbmsg(){ return ::proto_ff::E_EscortChanceEscortDesc(); }
	};
	typedef struct E_EscortChanceEscortDesc_s E_EscortChanceEscortDesc_t;

	struct E_EscortChance_s : public NFDescStoreSeqOP {
		E_EscortChance_s();
		virtual ~E_EscortChance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_convoyId;//镖车ID
		NFShmVector<struct E_EscortChanceEscortDesc_s, DEFINE_E_ESCORTCHANCE_M_ESCORT_MAX_NUM> m_escort;//镖车

		virtual void write_to_pbmsg(::proto_ff::E_EscortChance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortChance & msg);
		static ::proto_ff::E_EscortChance* new_pbmsg(){ return new ::proto_ff::E_EscortChance(); }
		static ::proto_ff::E_EscortChance make_pbmsg(){ return ::proto_ff::E_EscortChance(); }
	};
	typedef struct E_EscortChance_s E_EscortChance_t;

	struct Sheet_EscortChance_s : public NFDescStoreSeqOP {
		Sheet_EscortChance_s();
		virtual ~Sheet_EscortChance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EscortChance_s, DEFINE_SHEET_ESCORTCHANCE_E_ESCORTCHANCE_LIST_MAX_NUM> E_EscortChance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EscortChance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EscortChance & msg);
		static ::proto_ff::Sheet_EscortChance* new_pbmsg(){ return new ::proto_ff::Sheet_EscortChance(); }
		static ::proto_ff::Sheet_EscortChance make_pbmsg(){ return ::proto_ff::Sheet_EscortChance(); }
	};
	typedef struct Sheet_EscortChance_s Sheet_EscortChance_t;

	struct E_EscortRewardRewardDesc_s : public NFDescStoreSeqOP {
		E_EscortRewardRewardDesc_s();
		virtual ~E_EscortRewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//物品
		int32_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EscortRewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortRewardRewardDesc & msg);
		static ::proto_ff::E_EscortRewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_EscortRewardRewardDesc(); }
		static ::proto_ff::E_EscortRewardRewardDesc make_pbmsg(){ return ::proto_ff::E_EscortRewardRewardDesc(); }
	};
	typedef struct E_EscortRewardRewardDesc_s E_EscortRewardRewardDesc_t;

	struct E_EscortReward_s : public NFDescStoreSeqOP {
		E_EscortReward_s();
		virtual ~E_EscortReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//角色等级
		int64_t m_exp;//物资车奖励经验
		NFShmVector<struct E_EscortRewardRewardDesc_s, DEFINE_E_ESCORTREWARD_M_REWARD_MAX_NUM> m_reward;//镖车奖励

		virtual void write_to_pbmsg(::proto_ff::E_EscortReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortReward & msg);
		static ::proto_ff::E_EscortReward* new_pbmsg(){ return new ::proto_ff::E_EscortReward(); }
		static ::proto_ff::E_EscortReward make_pbmsg(){ return ::proto_ff::E_EscortReward(); }
	};
	typedef struct E_EscortReward_s E_EscortReward_t;

	struct Sheet_EscortReward_s : public NFDescStoreSeqOP {
		Sheet_EscortReward_s();
		virtual ~Sheet_EscortReward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EscortReward_s, DEFINE_SHEET_ESCORTREWARD_E_ESCORTREWARD_LIST_MAX_NUM> E_EscortReward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EscortReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EscortReward & msg);
		static ::proto_ff::Sheet_EscortReward* new_pbmsg(){ return new ::proto_ff::Sheet_EscortReward(); }
		static ::proto_ff::Sheet_EscortReward make_pbmsg(){ return ::proto_ff::Sheet_EscortReward(); }
	};
	typedef struct Sheet_EscortReward_s Sheet_EscortReward_t;

	struct E_EscortConst_s : public NFDescStoreSeqOP {
		E_EscortConst_s();
		virtual ~E_EscortConst_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_tokenId;//护送令商品id
		int32_t m_tokenNumber;//物资卷轴数量
		int32_t m_dayTime;//每日次数
		int32_t m_freeNum;//免费次数
		int32_t m_mapId;//地图ID
		int32_t m_startNpcID;//开始任务npcID
		int32_t m_startNpcPointID;//开始任务npc坐标点
		int32_t m_overNpcID;//完成任务npcID
		int32_t m_activityID;//活动信息id
		int32_t m_taskID;//任务id
		int32_t m_DistanceA;//最大距离
		int32_t m_DistanceB;//跟进距离
		int32_t m_DistanceC;//最近距离
		int32_t m_timeLimit;//任务时间限制

		virtual void write_to_pbmsg(::proto_ff::E_EscortConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EscortConst & msg);
		static ::proto_ff::E_EscortConst* new_pbmsg(){ return new ::proto_ff::E_EscortConst(); }
		static ::proto_ff::E_EscortConst make_pbmsg(){ return ::proto_ff::E_EscortConst(); }
	};
	typedef struct E_EscortConst_s E_EscortConst_t;

	struct Sheet_EscortConst_s : public NFDescStoreSeqOP {
		Sheet_EscortConst_s();
		virtual ~Sheet_EscortConst_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EscortConst_s, DEFINE_SHEET_ESCORTCONST_E_ESCORTCONST_LIST_MAX_NUM> E_EscortConst_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EscortConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EscortConst & msg);
		static ::proto_ff::Sheet_EscortConst* new_pbmsg(){ return new ::proto_ff::Sheet_EscortConst(); }
		static ::proto_ff::Sheet_EscortConst make_pbmsg(){ return ::proto_ff::Sheet_EscortConst(); }
	};
	typedef struct Sheet_EscortConst_s Sheet_EscortConst_t;

}

