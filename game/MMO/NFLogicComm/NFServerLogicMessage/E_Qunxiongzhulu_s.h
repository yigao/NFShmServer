#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Qunxiongzhulu.pb.h"
#include "E_Qunxiongzhulu_s.h"

#define DEFINE_E_QUNXIONGZHULUCONSTANT_M_CROSSPOINT_MAX_NUM 8
#define DEFINE_E_QUNXIONGZHULUCONSTANT_M_CARPOINT_MAX_NUM 16
#define DEFINE_SHEET_QUNXIONGZHULUCONSTANT_E_QUNXIONGZHULUCONSTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_QUNXIONGZHULUSKILL_E_QUNXIONGZHULUSKILL_LIST_MAX_NUM 4
#define DEFINE_E_QUNXIONGZHULUSERVERRANK_M_ITEM_MAX_NUM 11
#define DEFINE_SHEET_QUNXIONGZHULUSERVERRANK_E_QUNXIONGZHULUSERVERRANK_LIST_MAX_NUM 8
#define DEFINE_E_QUNXIONGZHULUWORLDRANK_M_ITEM_MAX_NUM 11
#define DEFINE_SHEET_QUNXIONGZHULUWORLDRANK_E_QUNXIONGZHULUWORLDRANK_LIST_MAX_NUM 8
#define DEFINE_E_QUNXIONGZHULULOCALRANK_M_ITEM_MAX_NUM 11
#define DEFINE_SHEET_QUNXIONGZHULULOCALRANK_E_QUNXIONGZHULULOCALRANK_LIST_MAX_NUM 8
#define DEFINE_E_QUNXIONGZHULUBOSSREWARD_M_ITEM_MAX_NUM 8
#define DEFINE_SHEET_QUNXIONGZHULUBOSSREWARD_E_QUNXIONGZHULUBOSSREWARD_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_QunxiongzhuluConstant_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluConstant_s();
		virtual ~E_QunxiongzhuluConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_thisMap;//本服地图
		int32_t m_thisBossId;//本服bossid
		int32_t m_thisBossPonit;//本服boss点
		int32_t m_gateMonster;//跨服boss传送点怪物id
		int32_t m_gatePoint;//跨服boss传送点
		int32_t m_thisPickupLimit;//本服个人拾取上限
		int32_t m_crossMap;//跨服地图
		int32_t m_crossBossId;//跨服bossid
		int32_t m_crossBossPoint;//跨服boss点
		int32_t m_crossPickupLimit;//跨服个人拾取上限
		int32_t m_carId;//战车id
		int32_t m_preview;//奖励预览
		int32_t m_actId;//活动id
		NFShmVector<int32_t, DEFINE_E_QUNXIONGZHULUCONSTANT_M_CROSSPOINT_MAX_NUM> m_crossPoint;//跨服出生点
		NFShmVector<int32_t, DEFINE_E_QUNXIONGZHULUCONSTANT_M_CARPOINT_MAX_NUM> m_carPoint;//战车坐标

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluConstant & msg);
		static ::proto_ff::E_QunxiongzhuluConstant* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluConstant(); }
		static ::proto_ff::E_QunxiongzhuluConstant make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluConstant(); }
	};
	typedef struct E_QunxiongzhuluConstant_s E_QunxiongzhuluConstant_t;

	struct Sheet_QunxiongzhuluConstant_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluConstant_s();
		virtual ~Sheet_QunxiongzhuluConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluConstant_s, DEFINE_SHEET_QUNXIONGZHULUCONSTANT_E_QUNXIONGZHULUCONSTANT_LIST_MAX_NUM> E_QunxiongzhuluConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluConstant & msg);
		static ::proto_ff::Sheet_QunxiongzhuluConstant* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluConstant(); }
		static ::proto_ff::Sheet_QunxiongzhuluConstant make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluConstant(); }
	};
	typedef struct Sheet_QunxiongzhuluConstant_s Sheet_QunxiongzhuluConstant_t;

	struct E_QunxiongzhuluSkill_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluSkill_s();
		virtual ~E_QunxiongzhuluSkill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluSkill & msg);
		static ::proto_ff::E_QunxiongzhuluSkill* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluSkill(); }
		static ::proto_ff::E_QunxiongzhuluSkill make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluSkill(); }
	};
	typedef struct E_QunxiongzhuluSkill_s E_QunxiongzhuluSkill_t;

	struct Sheet_QunxiongzhuluSkill_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluSkill_s();
		virtual ~Sheet_QunxiongzhuluSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluSkill_s, DEFINE_SHEET_QUNXIONGZHULUSKILL_E_QUNXIONGZHULUSKILL_LIST_MAX_NUM> E_QunxiongzhuluSkill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluSkill & msg);
		static ::proto_ff::Sheet_QunxiongzhuluSkill* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluSkill(); }
		static ::proto_ff::Sheet_QunxiongzhuluSkill make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluSkill(); }
	};
	typedef struct Sheet_QunxiongzhuluSkill_s Sheet_QunxiongzhuluSkill_t;

	struct E_QunxiongzhuluServerrankItemDesc_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluServerrankItemDesc_s();
		virtual ~E_QunxiongzhuluServerrankItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluServerrankItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluServerrankItemDesc & msg);
		static ::proto_ff::E_QunxiongzhuluServerrankItemDesc* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluServerrankItemDesc(); }
		static ::proto_ff::E_QunxiongzhuluServerrankItemDesc make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluServerrankItemDesc(); }
	};
	typedef struct E_QunxiongzhuluServerrankItemDesc_s E_QunxiongzhuluServerrankItemDesc_t;

	struct E_QunxiongzhuluServerrank_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluServerrank_s();
		virtual ~E_QunxiongzhuluServerrank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_rankMax;//名次上限
		int32_t m_rankMin;//名次下限
		NFShmVector<struct E_QunxiongzhuluServerrankItemDesc_s, DEFINE_E_QUNXIONGZHULUSERVERRANK_M_ITEM_MAX_NUM> m_item;//奖励道具

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluServerrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluServerrank & msg);
		static ::proto_ff::E_QunxiongzhuluServerrank* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluServerrank(); }
		static ::proto_ff::E_QunxiongzhuluServerrank make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluServerrank(); }
	};
	typedef struct E_QunxiongzhuluServerrank_s E_QunxiongzhuluServerrank_t;

	struct Sheet_QunxiongzhuluServerrank_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluServerrank_s();
		virtual ~Sheet_QunxiongzhuluServerrank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluServerrank_s, DEFINE_SHEET_QUNXIONGZHULUSERVERRANK_E_QUNXIONGZHULUSERVERRANK_LIST_MAX_NUM> E_QunxiongzhuluServerrank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluServerrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluServerrank & msg);
		static ::proto_ff::Sheet_QunxiongzhuluServerrank* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluServerrank(); }
		static ::proto_ff::Sheet_QunxiongzhuluServerrank make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluServerrank(); }
	};
	typedef struct Sheet_QunxiongzhuluServerrank_s Sheet_QunxiongzhuluServerrank_t;

	struct E_QunxiongzhuluWorldrankItemDesc_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluWorldrankItemDesc_s();
		virtual ~E_QunxiongzhuluWorldrankItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluWorldrankItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluWorldrankItemDesc & msg);
		static ::proto_ff::E_QunxiongzhuluWorldrankItemDesc* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluWorldrankItemDesc(); }
		static ::proto_ff::E_QunxiongzhuluWorldrankItemDesc make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluWorldrankItemDesc(); }
	};
	typedef struct E_QunxiongzhuluWorldrankItemDesc_s E_QunxiongzhuluWorldrankItemDesc_t;

	struct E_QunxiongzhuluWorldrank_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluWorldrank_s();
		virtual ~E_QunxiongzhuluWorldrank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_rankMax;//名次上限
		int32_t m_rankMin;//名次下限
		NFShmVector<struct E_QunxiongzhuluWorldrankItemDesc_s, DEFINE_E_QUNXIONGZHULUWORLDRANK_M_ITEM_MAX_NUM> m_item;//奖励道具

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluWorldrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluWorldrank & msg);
		static ::proto_ff::E_QunxiongzhuluWorldrank* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluWorldrank(); }
		static ::proto_ff::E_QunxiongzhuluWorldrank make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluWorldrank(); }
	};
	typedef struct E_QunxiongzhuluWorldrank_s E_QunxiongzhuluWorldrank_t;

	struct Sheet_QunxiongzhuluWorldrank_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluWorldrank_s();
		virtual ~Sheet_QunxiongzhuluWorldrank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluWorldrank_s, DEFINE_SHEET_QUNXIONGZHULUWORLDRANK_E_QUNXIONGZHULUWORLDRANK_LIST_MAX_NUM> E_QunxiongzhuluWorldrank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluWorldrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluWorldrank & msg);
		static ::proto_ff::Sheet_QunxiongzhuluWorldrank* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluWorldrank(); }
		static ::proto_ff::Sheet_QunxiongzhuluWorldrank make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluWorldrank(); }
	};
	typedef struct Sheet_QunxiongzhuluWorldrank_s Sheet_QunxiongzhuluWorldrank_t;

	struct E_QunxiongzhuluLocalrankItemDesc_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluLocalrankItemDesc_s();
		virtual ~E_QunxiongzhuluLocalrankItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluLocalrankItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluLocalrankItemDesc & msg);
		static ::proto_ff::E_QunxiongzhuluLocalrankItemDesc* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluLocalrankItemDesc(); }
		static ::proto_ff::E_QunxiongzhuluLocalrankItemDesc make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluLocalrankItemDesc(); }
	};
	typedef struct E_QunxiongzhuluLocalrankItemDesc_s E_QunxiongzhuluLocalrankItemDesc_t;

	struct E_QunxiongzhuluLocalrank_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluLocalrank_s();
		virtual ~E_QunxiongzhuluLocalrank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_rankMax;//名次上限
		int32_t m_rankMin;//名次下限
		NFShmVector<struct E_QunxiongzhuluLocalrankItemDesc_s, DEFINE_E_QUNXIONGZHULULOCALRANK_M_ITEM_MAX_NUM> m_item;//奖励道具

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluLocalrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluLocalrank & msg);
		static ::proto_ff::E_QunxiongzhuluLocalrank* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluLocalrank(); }
		static ::proto_ff::E_QunxiongzhuluLocalrank make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluLocalrank(); }
	};
	typedef struct E_QunxiongzhuluLocalrank_s E_QunxiongzhuluLocalrank_t;

	struct Sheet_QunxiongzhuluLocalrank_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluLocalrank_s();
		virtual ~Sheet_QunxiongzhuluLocalrank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluLocalrank_s, DEFINE_SHEET_QUNXIONGZHULULOCALRANK_E_QUNXIONGZHULULOCALRANK_LIST_MAX_NUM> E_QunxiongzhuluLocalrank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluLocalrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluLocalrank & msg);
		static ::proto_ff::Sheet_QunxiongzhuluLocalrank* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluLocalrank(); }
		static ::proto_ff::Sheet_QunxiongzhuluLocalrank make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluLocalrank(); }
	};
	typedef struct Sheet_QunxiongzhuluLocalrank_s Sheet_QunxiongzhuluLocalrank_t;

	struct E_QunxiongzhuluBossrewardItemDesc_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluBossrewardItemDesc_s();
		virtual ~E_QunxiongzhuluBossrewardItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluBossrewardItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluBossrewardItemDesc & msg);
		static ::proto_ff::E_QunxiongzhuluBossrewardItemDesc* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluBossrewardItemDesc(); }
		static ::proto_ff::E_QunxiongzhuluBossrewardItemDesc make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluBossrewardItemDesc(); }
	};
	typedef struct E_QunxiongzhuluBossrewardItemDesc_s E_QunxiongzhuluBossrewardItemDesc_t;

	struct E_QunxiongzhuluBossreward_s : public NFDescStoreSeqOP {
		E_QunxiongzhuluBossreward_s();
		virtual ~E_QunxiongzhuluBossreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_type;//服务器类型
		NFShmVector<struct E_QunxiongzhuluBossrewardItemDesc_s, DEFINE_E_QUNXIONGZHULUBOSSREWARD_M_ITEM_MAX_NUM> m_item;//奖励道具

		virtual void write_to_pbmsg(::proto_ff::E_QunxiongzhuluBossreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluBossreward & msg);
		static ::proto_ff::E_QunxiongzhuluBossreward* new_pbmsg(){ return new ::proto_ff::E_QunxiongzhuluBossreward(); }
		static ::proto_ff::E_QunxiongzhuluBossreward make_pbmsg(){ return ::proto_ff::E_QunxiongzhuluBossreward(); }
	};
	typedef struct E_QunxiongzhuluBossreward_s E_QunxiongzhuluBossreward_t;

	struct Sheet_QunxiongzhuluBossreward_s : public NFDescStoreSeqOP {
		Sheet_QunxiongzhuluBossreward_s();
		virtual ~Sheet_QunxiongzhuluBossreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QunxiongzhuluBossreward_s, DEFINE_SHEET_QUNXIONGZHULUBOSSREWARD_E_QUNXIONGZHULUBOSSREWARD_LIST_MAX_NUM> E_QunxiongzhuluBossreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluBossreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluBossreward & msg);
		static ::proto_ff::Sheet_QunxiongzhuluBossreward* new_pbmsg(){ return new ::proto_ff::Sheet_QunxiongzhuluBossreward(); }
		static ::proto_ff::Sheet_QunxiongzhuluBossreward make_pbmsg(){ return ::proto_ff::Sheet_QunxiongzhuluBossreward(); }
	};
	typedef struct Sheet_QunxiongzhuluBossreward_s Sheet_QunxiongzhuluBossreward_t;

}

