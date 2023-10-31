#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Boss.pb.h"
#include "E_Boss_s.h"

#define DEFINE_SHEET_BOSSRAREITEM_E_BOSSRAREITEM_LIST_MAX_NUM 1024
#define DEFINE_SHEET_BOSSBOSS_E_BOSSBOSS_LIST_MAX_NUM 1024
#define DEFINE_E_BOSSBOSSTYPE_M_GROUP_MAX_NUM 3
#define DEFINE_SHEET_BOSSBOSSTYPE_E_BOSSBOSSTYPE_LIST_MAX_NUM 16
#define DEFINE_SHEET_BOSSLAYER_E_BOSSLAYER_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_BossRareitem_s : public NFDescStoreSeqOP {
		E_BossRareitem_s();
		virtual ~E_BossRareitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_itemID;//物品ID
		int32_t m_top;//是否置顶

		virtual void write_to_pbmsg(::proto_ff::E_BossRareitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossRareitem & msg);
		static ::proto_ff::E_BossRareitem* new_pbmsg(){ return new ::proto_ff::E_BossRareitem(); }
		static ::proto_ff::E_BossRareitem make_pbmsg(){ return ::proto_ff::E_BossRareitem(); }
	};
	typedef struct E_BossRareitem_s E_BossRareitem_t;

	struct Sheet_BossRareitem_s : public NFDescStoreSeqOP {
		Sheet_BossRareitem_s();
		virtual ~Sheet_BossRareitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossRareitem_s, DEFINE_SHEET_BOSSRAREITEM_E_BOSSRAREITEM_LIST_MAX_NUM> E_BossRareitem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossRareitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossRareitem & msg);
		static ::proto_ff::Sheet_BossRareitem* new_pbmsg(){ return new ::proto_ff::Sheet_BossRareitem(); }
		static ::proto_ff::Sheet_BossRareitem make_pbmsg(){ return ::proto_ff::Sheet_BossRareitem(); }
	};
	typedef struct Sheet_BossRareitem_s Sheet_BossRareitem_t;

	struct E_BossBoss_s : public NFDescStoreSeqOP {
		E_BossBoss_s();
		virtual ~E_BossBoss_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//bossID
		int32_t m_bossType;//BOSS类型
		int32_t m_monsterID;//怪物ID
		int32_t m_classOrder;//阶次
		int32_t m_sceneOrder;//所属层级
		int32_t m_duplicateID;//副本ID
		int32_t m_peaceMask;//和平标记
		int32_t m_pointID;//位置点
		int32_t m_flashNum;//刷新数量
		int32_t m_group_type;//组类型
		int32_t m_ishide;//是否是隐藏boss
		int32_t m_triggerPro;//触发隐藏的概率
		int32_t m_flashTime;//刷新间隔
		int32_t m_retrieveGiftID;//找回礼包id
		int32_t m_noTimes;//是否不消耗次数
		int32_t m_assistPrestige;//协助击杀奖励的声望

		virtual void write_to_pbmsg(::proto_ff::E_BossBoss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBoss & msg);
		static ::proto_ff::E_BossBoss* new_pbmsg(){ return new ::proto_ff::E_BossBoss(); }
		static ::proto_ff::E_BossBoss make_pbmsg(){ return ::proto_ff::E_BossBoss(); }
	};
	typedef struct E_BossBoss_s E_BossBoss_t;

	struct Sheet_BossBoss_s : public NFDescStoreSeqOP {
		Sheet_BossBoss_s();
		virtual ~Sheet_BossBoss_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossBoss_s, DEFINE_SHEET_BOSSBOSS_E_BOSSBOSS_LIST_MAX_NUM> E_BossBoss_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossBoss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossBoss & msg);
		static ::proto_ff::Sheet_BossBoss* new_pbmsg(){ return new ::proto_ff::Sheet_BossBoss(); }
		static ::proto_ff::Sheet_BossBoss make_pbmsg(){ return ::proto_ff::Sheet_BossBoss(); }
	};
	typedef struct Sheet_BossBoss_s Sheet_BossBoss_t;

	struct E_BossBosstypeGroupDesc_s : public NFDescStoreSeqOP {
		E_BossBosstypeGroupDesc_s();
		virtual ~E_BossBosstypeGroupDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_times;//次数
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_BossBosstypeGroupDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBosstypeGroupDesc & msg);
		static ::proto_ff::E_BossBosstypeGroupDesc* new_pbmsg(){ return new ::proto_ff::E_BossBosstypeGroupDesc(); }
		static ::proto_ff::E_BossBosstypeGroupDesc make_pbmsg(){ return ::proto_ff::E_BossBosstypeGroupDesc(); }
	};
	typedef struct E_BossBosstypeGroupDesc_s E_BossBosstypeGroupDesc_t;

	struct E_BossBosstype_s : public NFDescStoreSeqOP {
		E_BossBosstype_s();
		virtual ~E_BossBosstype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_bossType;//总类型
		int32_t m_mapType;//地图类型
		int32_t m_functionId;//功能解锁ID
		int32_t m_duplicateGroupID;//副本组ID
		int32_t m_privilegeType;//特权类型
		int64_t m_callingCardId;//召唤卡id
		int32_t m_enterTimes;//进入次数
		int32_t m_costitem;//进入消耗物品
		NFShmString<64> m_costnum;//进入消耗物品数量
		int32_t m_bossTimes;//boss次数
		int32_t m_addItemID;//增加次数物品ID
		int32_t m_canhelp;//是否可以援助
		int32_t m_qkill;//是否支持快速击杀
		int32_t m_retrievedDays;//找回天数
		int32_t m_skill;//纳入全服首杀
		NFShmVector<struct E_BossBosstypeGroupDesc_s, DEFINE_E_BOSSBOSSTYPE_M_GROUP_MAX_NUM> m_group;//Boss组

		virtual void write_to_pbmsg(::proto_ff::E_BossBosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBosstype & msg);
		static ::proto_ff::E_BossBosstype* new_pbmsg(){ return new ::proto_ff::E_BossBosstype(); }
		static ::proto_ff::E_BossBosstype make_pbmsg(){ return ::proto_ff::E_BossBosstype(); }
	};
	typedef struct E_BossBosstype_s E_BossBosstype_t;

	struct Sheet_BossBosstype_s : public NFDescStoreSeqOP {
		Sheet_BossBosstype_s();
		virtual ~Sheet_BossBosstype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossBosstype_s, DEFINE_SHEET_BOSSBOSSTYPE_E_BOSSBOSSTYPE_LIST_MAX_NUM> E_BossBosstype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossBosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossBosstype & msg);
		static ::proto_ff::Sheet_BossBosstype* new_pbmsg(){ return new ::proto_ff::Sheet_BossBosstype(); }
		static ::proto_ff::Sheet_BossBosstype make_pbmsg(){ return ::proto_ff::Sheet_BossBosstype(); }
	};
	typedef struct Sheet_BossBosstype_s Sheet_BossBosstype_t;

	struct E_BossLayer_s : public NFDescStoreSeqOP {
		E_BossLayer_s();
		virtual ~E_BossLayer_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//id
		int32_t m_bossType;//类型
		int32_t m_order;//排序
		int32_t m_subType;//类型
		NFShmString<64> m_enterCondition;//进入条件
		NFShmString<64> m_unlockCondition;//解锁条件
		int32_t m_mapID;//地图ID
		int32_t m_maxlv;//最大进入等级

		virtual void write_to_pbmsg(::proto_ff::E_BossLayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossLayer & msg);
		static ::proto_ff::E_BossLayer* new_pbmsg(){ return new ::proto_ff::E_BossLayer(); }
		static ::proto_ff::E_BossLayer make_pbmsg(){ return ::proto_ff::E_BossLayer(); }
	};
	typedef struct E_BossLayer_s E_BossLayer_t;

	struct Sheet_BossLayer_s : public NFDescStoreSeqOP {
		Sheet_BossLayer_s();
		virtual ~Sheet_BossLayer_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossLayer_s, DEFINE_SHEET_BOSSLAYER_E_BOSSLAYER_LIST_MAX_NUM> E_BossLayer_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossLayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossLayer & msg);
		static ::proto_ff::Sheet_BossLayer* new_pbmsg(){ return new ::proto_ff::Sheet_BossLayer(); }
		static ::proto_ff::Sheet_BossLayer make_pbmsg(){ return ::proto_ff::Sheet_BossLayer(); }
	};
	typedef struct Sheet_BossLayer_s Sheet_BossLayer_t;

}

