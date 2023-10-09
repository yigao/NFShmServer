#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Cloudpeak.pb.h"
#include "E_Cloudpeak_s.h"

#define DEFINE_SHEET_CLOUDPEAKRANKREWARDS_E_CLOUDPEAKRANKREWARDS_LIST_MAX_NUM 32
#define DEFINE_E_CLOUDPEAKCONSTANT_M_REVIVALPOINT_MAX_NUM 8
#define DEFINE_E_CLOUDPEAKCONSTANT_M_BUFF_MAX_NUM 8
#define DEFINE_E_CLOUDPEAKCONSTANT_M_REBOT_ID_MAX_NUM 10
#define DEFINE_SHEET_CLOUDPEAKCONSTANT_E_CLOUDPEAKCONSTANT_LIST_MAX_NUM 256
#define DEFINE_SHEET_CLOUDPEAKEXP_E_CLOUDPEAKEXP_LIST_MAX_NUM 512


namespace proto_ff_s {

	struct E_CloudpeakRankrewards_s : public NFDescStoreSeqOP {
		E_CloudpeakRankrewards_s();
		virtual ~E_CloudpeakRankrewards_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一id
		int32_t m_rewarditem;//奖励道具
		int64_t m_itemnum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_CloudpeakRankrewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloudpeakRankrewards & msg);
		static ::proto_ff::E_CloudpeakRankrewards* new_pbmsg(){ return new ::proto_ff::E_CloudpeakRankrewards(); }
		static ::proto_ff::E_CloudpeakRankrewards make_pbmsg(){ return ::proto_ff::E_CloudpeakRankrewards(); }
	};
	typedef struct E_CloudpeakRankrewards_s E_CloudpeakRankrewards_t;

	struct Sheet_CloudpeakRankrewards_s : public NFDescStoreSeqOP {
		Sheet_CloudpeakRankrewards_s();
		virtual ~Sheet_CloudpeakRankrewards_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloudpeakRankrewards_s, DEFINE_SHEET_CLOUDPEAKRANKREWARDS_E_CLOUDPEAKRANKREWARDS_LIST_MAX_NUM> E_CloudpeakRankrewards_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloudpeakRankrewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakRankrewards & msg);
		static ::proto_ff::Sheet_CloudpeakRankrewards* new_pbmsg(){ return new ::proto_ff::Sheet_CloudpeakRankrewards(); }
		static ::proto_ff::Sheet_CloudpeakRankrewards make_pbmsg(){ return ::proto_ff::Sheet_CloudpeakRankrewards(); }
	};
	typedef struct Sheet_CloudpeakRankrewards_s Sheet_CloudpeakRankrewards_t;

	struct E_CloudpeakConstantBuffDesc_s : public NFDescStoreSeqOP {
		E_CloudpeakConstantBuffDesc_s();
		virtual ~E_CloudpeakConstantBuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//位置
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_CloudpeakConstantBuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloudpeakConstantBuffDesc & msg);
		static ::proto_ff::E_CloudpeakConstantBuffDesc* new_pbmsg(){ return new ::proto_ff::E_CloudpeakConstantBuffDesc(); }
		static ::proto_ff::E_CloudpeakConstantBuffDesc make_pbmsg(){ return ::proto_ff::E_CloudpeakConstantBuffDesc(); }
	};
	typedef struct E_CloudpeakConstantBuffDesc_s E_CloudpeakConstantBuffDesc_t;

	struct E_CloudpeakConstant_s : public NFDescStoreSeqOP {
		E_CloudpeakConstant_s();
		virtual ~E_CloudpeakConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_revivalbuff;//复活buff
		int32_t m_refresh;//buff刷新时间
		int32_t m_victoryreward;//阵营胜利奖励
		int32_t m_failurereward;//阵营失败奖励
		int32_t m_round;//比赛轮数
		int32_t m_roundtime;//每轮持续时间
		int32_t m_initialscoring;//初始积分
		int32_t m_getscoring;//获得积分
		int32_t m_assistscoring;//助攻积分
		int32_t m_matchtime;//匹配时间
		int32_t m_matchentry;//匹配地图出生位置
		int64_t m_mapid;//所在地图
		int32_t m_playersmax;//每个房间最多人数
		int32_t m_rebotid;//机器人id
		int32_t m_rebotcount;//机器人数量
		int32_t m_actid;//活动ID
		NFShmVector<int32_t, DEFINE_E_CLOUDPEAKCONSTANT_M_REVIVALPOINT_MAX_NUM> m_revivalpoint;//复活点
		NFShmVector<struct E_CloudpeakConstantBuffDesc_s, DEFINE_E_CLOUDPEAKCONSTANT_M_BUFF_MAX_NUM> m_buff;//增益
		NFShmVector<int32_t, DEFINE_E_CLOUDPEAKCONSTANT_M_REBOT_ID_MAX_NUM> m_rebot_id;//机器人id

		virtual void write_to_pbmsg(::proto_ff::E_CloudpeakConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloudpeakConstant & msg);
		static ::proto_ff::E_CloudpeakConstant* new_pbmsg(){ return new ::proto_ff::E_CloudpeakConstant(); }
		static ::proto_ff::E_CloudpeakConstant make_pbmsg(){ return ::proto_ff::E_CloudpeakConstant(); }
	};
	typedef struct E_CloudpeakConstant_s E_CloudpeakConstant_t;

	struct Sheet_CloudpeakConstant_s : public NFDescStoreSeqOP {
		Sheet_CloudpeakConstant_s();
		virtual ~Sheet_CloudpeakConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloudpeakConstant_s, DEFINE_SHEET_CLOUDPEAKCONSTANT_E_CLOUDPEAKCONSTANT_LIST_MAX_NUM> E_CloudpeakConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloudpeakConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakConstant & msg);
		static ::proto_ff::Sheet_CloudpeakConstant* new_pbmsg(){ return new ::proto_ff::Sheet_CloudpeakConstant(); }
		static ::proto_ff::Sheet_CloudpeakConstant make_pbmsg(){ return ::proto_ff::Sheet_CloudpeakConstant(); }
	};
	typedef struct Sheet_CloudpeakConstant_s Sheet_CloudpeakConstant_t;

	struct E_CloudpeakExp_s : public NFDescStoreSeqOP {
		E_CloudpeakExp_s();
		virtual ~E_CloudpeakExp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_getexp;//活动经验

		virtual void write_to_pbmsg(::proto_ff::E_CloudpeakExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloudpeakExp & msg);
		static ::proto_ff::E_CloudpeakExp* new_pbmsg(){ return new ::proto_ff::E_CloudpeakExp(); }
		static ::proto_ff::E_CloudpeakExp make_pbmsg(){ return ::proto_ff::E_CloudpeakExp(); }
	};
	typedef struct E_CloudpeakExp_s E_CloudpeakExp_t;

	struct Sheet_CloudpeakExp_s : public NFDescStoreSeqOP {
		Sheet_CloudpeakExp_s();
		virtual ~Sheet_CloudpeakExp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloudpeakExp_s, DEFINE_SHEET_CLOUDPEAKEXP_E_CLOUDPEAKEXP_LIST_MAX_NUM> E_CloudpeakExp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloudpeakExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakExp & msg);
		static ::proto_ff::Sheet_CloudpeakExp* new_pbmsg(){ return new ::proto_ff::Sheet_CloudpeakExp(); }
		static ::proto_ff::Sheet_CloudpeakExp make_pbmsg(){ return ::proto_ff::Sheet_CloudpeakExp(); }
	};
	typedef struct Sheet_CloudpeakExp_s Sheet_CloudpeakExp_t;

}

