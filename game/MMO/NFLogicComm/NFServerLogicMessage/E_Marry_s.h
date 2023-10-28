#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Marry.pb.h"
#include "E_Marry_s.h"

#define DEFINE_SHEET_MARRYMARRIAGE_E_MARRYMARRIAGE_LIST_MAX_NUM 4
#define DEFINE_SHEET_MARRYBANQUET_E_MARRYBANQUET_LIST_MAX_NUM 32
#define DEFINE_E_MARRYLOCKLV_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_E_MARRYLOCKLV_M_SKILL_MAX_NUM 5
#define DEFINE_SHEET_MARRYLOCKLV_E_MARRYLOCKLV_LIST_MAX_NUM 1024
#define DEFINE_E_MARRYLOCKSKILL_M_SKILL_MAX_NUM 3
#define DEFINE_SHEET_MARRYLOCKSKILL_E_MARRYLOCKSKILL_LIST_MAX_NUM 8
#define DEFINE_E_MARRYCHILD_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_MARRYCHILD_M_STARIATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_MARRYCHILD_E_MARRYCHILD_LIST_MAX_NUM 16
#define DEFINE_E_MARRYCHILDVALUE_M_LVVALUE_MAX_NUM 31
#define DEFINE_SHEET_MARRYCHILDVALUE_E_MARRYCHILDVALUE_LIST_MAX_NUM 128
#define DEFINE_E_MARRYCHILDEXP_M_GRADE_MAX_NUM 3
#define DEFINE_SHEET_MARRYCHILDEXP_E_MARRYCHILDEXP_LIST_MAX_NUM 32
#define DEFINE_E_MARRYEXPRESS_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_MARRYEXPRESS_E_MARRYEXPRESS_LIST_MAX_NUM 1024
#define DEFINE_SHEET_MARRYEXPRESSLANGUAGE_E_MARRYEXPRESSLANGUAGE_LIST_MAX_NUM 32
#define DEFINE_SHEET_MARRYEXPRESSSHOP_E_MARRYEXPRESSSHOP_LIST_MAX_NUM 4
#define DEFINE_E_MARRYCONSTANT_M_TOURMONSTER_MAX_NUM 8
#define DEFINE_SHEET_MARRYCONSTANT_E_MARRYCONSTANT_LIST_MAX_NUM 4
#define DEFINE_SHEET_MARRYCOMMON_E_MARRYCOMMON_LIST_MAX_NUM 512
#define DEFINE_E_MARRYWEDDING_M_STAGE_MAX_NUM 6
#define DEFINE_E_MARRYWEDDING_M_FIRE_MAX_NUM 2
#define DEFINE_E_MARRYWEDDING_M_MOOD_MAX_NUM 5
#define DEFINE_SHEET_MARRYWEDDING_E_MARRYWEDDING_LIST_MAX_NUM 2
#define DEFINE_SHEET_MARRYEXP_E_MARRYEXP_LIST_MAX_NUM 512


namespace proto_ff_s {

	struct E_MarryMarriage_s : public NFDescStoreSeqOP {
		E_MarryMarriage_s();
		virtual ~E_MarryMarriage_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_weddingname;//婚礼名称
		int32_t m_banquet;//是否宴会
		int32_t m_cruise;//是否巡游
		int32_t m_money;//货币
		int32_t m_price;//价格
		int32_t m_firstboxid;//首次奖励组id
		int32_t m_firstaddpower;//首次增加战力
		int32_t m_repeatboxid;//多次奖励组id
		int32_t m_repeataddpower;//多次增加战力
		int32_t m_titleid;//称号
		int32_t m_equip;//同心锁
		int32_t m_freeprice;//免费席位

		virtual void write_to_pbmsg(::proto_ff::E_MarryMarriage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryMarriage & msg);
		static ::proto_ff::E_MarryMarriage* new_pbmsg(){ return new ::proto_ff::E_MarryMarriage(); }
		static ::proto_ff::E_MarryMarriage make_pbmsg(){ return ::proto_ff::E_MarryMarriage(); }
	};
	typedef struct E_MarryMarriage_s E_MarryMarriage_t;

	struct Sheet_MarryMarriage_s : public NFDescStoreSeqOP {
		Sheet_MarryMarriage_s();
		virtual ~Sheet_MarryMarriage_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryMarriage_s, DEFINE_SHEET_MARRYMARRIAGE_E_MARRYMARRIAGE_LIST_MAX_NUM> E_MarryMarriage_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryMarriage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryMarriage & msg);
		static ::proto_ff::Sheet_MarryMarriage* new_pbmsg(){ return new ::proto_ff::Sheet_MarryMarriage(); }
		static ::proto_ff::Sheet_MarryMarriage make_pbmsg(){ return ::proto_ff::Sheet_MarryMarriage(); }
	};
	typedef struct Sheet_MarryMarriage_s Sheet_MarryMarriage_t;

	struct E_MarryBanquet_s : public NFDescStoreSeqOP {
		E_MarryBanquet_s();
		virtual ~E_MarryBanquet_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_begintime;//宴会开始时间
		NFShmString<64> m_finishtime;//宴会结束时间
		int32_t m_pre_broad_sec;//提前广播时间
		int32_t m_broad_inter_sec;//广播间隔

		virtual void write_to_pbmsg(::proto_ff::E_MarryBanquet & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryBanquet & msg);
		static ::proto_ff::E_MarryBanquet* new_pbmsg(){ return new ::proto_ff::E_MarryBanquet(); }
		static ::proto_ff::E_MarryBanquet make_pbmsg(){ return ::proto_ff::E_MarryBanquet(); }
	};
	typedef struct E_MarryBanquet_s E_MarryBanquet_t;

	struct Sheet_MarryBanquet_s : public NFDescStoreSeqOP {
		Sheet_MarryBanquet_s();
		virtual ~Sheet_MarryBanquet_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryBanquet_s, DEFINE_SHEET_MARRYBANQUET_E_MARRYBANQUET_LIST_MAX_NUM> E_MarryBanquet_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryBanquet & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryBanquet & msg);
		static ::proto_ff::Sheet_MarryBanquet* new_pbmsg(){ return new ::proto_ff::Sheet_MarryBanquet(); }
		static ::proto_ff::Sheet_MarryBanquet make_pbmsg(){ return ::proto_ff::Sheet_MarryBanquet(); }
	};
	typedef struct Sheet_MarryBanquet_s Sheet_MarryBanquet_t;

	struct E_MarryLocklvAttributeDesc_s : public NFDescStoreSeqOP {
		E_MarryLocklvAttributeDesc_s();
		virtual ~E_MarryLocklvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MarryLocklvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryLocklvAttributeDesc & msg);
		static ::proto_ff::E_MarryLocklvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MarryLocklvAttributeDesc(); }
		static ::proto_ff::E_MarryLocklvAttributeDesc make_pbmsg(){ return ::proto_ff::E_MarryLocklvAttributeDesc(); }
	};
	typedef struct E_MarryLocklvAttributeDesc_s E_MarryLocklvAttributeDesc_t;

	struct E_MarryLocklvSkillDesc_s : public NFDescStoreSeqOP {
		E_MarryLocklvSkillDesc_s();
		virtual ~E_MarryLocklvSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_skill;//

		virtual void write_to_pbmsg(::proto_ff::E_MarryLocklvSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryLocklvSkillDesc & msg);
		static ::proto_ff::E_MarryLocklvSkillDesc* new_pbmsg(){ return new ::proto_ff::E_MarryLocklvSkillDesc(); }
		static ::proto_ff::E_MarryLocklvSkillDesc make_pbmsg(){ return ::proto_ff::E_MarryLocklvSkillDesc(); }
	};
	typedef struct E_MarryLocklvSkillDesc_s E_MarryLocklvSkillDesc_t;

	struct E_MarryLocklv_s : public NFDescStoreSeqOP {
		E_MarryLocklv_s();
		virtual ~E_MarryLocklv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//星级
		int32_t m_exp;//升级需要经验
		NFShmVector<struct E_MarryLocklvAttributeDesc_s, DEFINE_E_MARRYLOCKLV_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_MarryLocklvSkillDesc_s, DEFINE_E_MARRYLOCKLV_M_SKILL_MAX_NUM> m_skill;//技能

		virtual void write_to_pbmsg(::proto_ff::E_MarryLocklv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryLocklv & msg);
		static ::proto_ff::E_MarryLocklv* new_pbmsg(){ return new ::proto_ff::E_MarryLocklv(); }
		static ::proto_ff::E_MarryLocklv make_pbmsg(){ return ::proto_ff::E_MarryLocklv(); }
	};
	typedef struct E_MarryLocklv_s E_MarryLocklv_t;

	struct Sheet_MarryLocklv_s : public NFDescStoreSeqOP {
		Sheet_MarryLocklv_s();
		virtual ~Sheet_MarryLocklv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryLocklv_s, DEFINE_SHEET_MARRYLOCKLV_E_MARRYLOCKLV_LIST_MAX_NUM> E_MarryLocklv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryLocklv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryLocklv & msg);
		static ::proto_ff::Sheet_MarryLocklv* new_pbmsg(){ return new ::proto_ff::Sheet_MarryLocklv(); }
		static ::proto_ff::Sheet_MarryLocklv make_pbmsg(){ return ::proto_ff::Sheet_MarryLocklv(); }
	};
	typedef struct Sheet_MarryLocklv_s Sheet_MarryLocklv_t;

	struct E_MarryLockskillSkillDesc_s : public NFDescStoreSeqOP {
		E_MarryLockskillSkillDesc_s();
		virtual ~E_MarryLockskillSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_grade;//品阶
		int32_t m_lv;//等级

		virtual void write_to_pbmsg(::proto_ff::E_MarryLockskillSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryLockskillSkillDesc & msg);
		static ::proto_ff::E_MarryLockskillSkillDesc* new_pbmsg(){ return new ::proto_ff::E_MarryLockskillSkillDesc(); }
		static ::proto_ff::E_MarryLockskillSkillDesc make_pbmsg(){ return ::proto_ff::E_MarryLockskillSkillDesc(); }
	};
	typedef struct E_MarryLockskillSkillDesc_s E_MarryLockskillSkillDesc_t;

	struct E_MarryLockskill_s : public NFDescStoreSeqOP {
		E_MarryLockskill_s();
		virtual ~E_MarryLockskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_order;//技能位置
		int32_t m_skillid;//技能id
		NFShmVector<struct E_MarryLockskillSkillDesc_s, DEFINE_E_MARRYLOCKSKILL_M_SKILL_MAX_NUM> m_skill;//技能

		virtual void write_to_pbmsg(::proto_ff::E_MarryLockskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryLockskill & msg);
		static ::proto_ff::E_MarryLockskill* new_pbmsg(){ return new ::proto_ff::E_MarryLockskill(); }
		static ::proto_ff::E_MarryLockskill make_pbmsg(){ return ::proto_ff::E_MarryLockskill(); }
	};
	typedef struct E_MarryLockskill_s E_MarryLockskill_t;

	struct Sheet_MarryLockskill_s : public NFDescStoreSeqOP {
		Sheet_MarryLockskill_s();
		virtual ~Sheet_MarryLockskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryLockskill_s, DEFINE_SHEET_MARRYLOCKSKILL_E_MARRYLOCKSKILL_LIST_MAX_NUM> E_MarryLockskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryLockskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryLockskill & msg);
		static ::proto_ff::Sheet_MarryLockskill* new_pbmsg(){ return new ::proto_ff::Sheet_MarryLockskill(); }
		static ::proto_ff::Sheet_MarryLockskill make_pbmsg(){ return ::proto_ff::Sheet_MarryLockskill(); }
	};
	typedef struct Sheet_MarryLockskill_s Sheet_MarryLockskill_t;

	struct E_MarryChildAttributeDesc_s : public NFDescStoreSeqOP {
		E_MarryChildAttributeDesc_s();
		virtual ~E_MarryChildAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MarryChildAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChildAttributeDesc & msg);
		static ::proto_ff::E_MarryChildAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MarryChildAttributeDesc(); }
		static ::proto_ff::E_MarryChildAttributeDesc make_pbmsg(){ return ::proto_ff::E_MarryChildAttributeDesc(); }
	};
	typedef struct E_MarryChildAttributeDesc_s E_MarryChildAttributeDesc_t;

	struct E_MarryChildStariattributeDesc_s : public NFDescStoreSeqOP {
		E_MarryChildStariattributeDesc_s();
		virtual ~E_MarryChildStariattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MarryChildStariattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChildStariattributeDesc & msg);
		static ::proto_ff::E_MarryChildStariattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MarryChildStariattributeDesc(); }
		static ::proto_ff::E_MarryChildStariattributeDesc make_pbmsg(){ return ::proto_ff::E_MarryChildStariattributeDesc(); }
	};
	typedef struct E_MarryChildStariattributeDesc_s E_MarryChildStariattributeDesc_t;

	struct E_MarryChild_s : public NFDescStoreSeqOP {
		E_MarryChild_s();
		virtual ~E_MarryChild_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_childid;//仙娃id
		int64_t m_itemid;//激活物品id
		NFShmString<64> m_childname;//仙娃名称
		int32_t m_childquality;//仙娃品质
		int32_t m_handz;//仙娃组
		NFShmString<64> m_handzname;//仙娃组名称
		NFShmString<64> m_skillid;//解锁技能组
		int64_t m_starid;//升星道具id
		NFShmString<64> m_starnum;//升星道具数量
		NFShmVector<struct E_MarryChildAttributeDesc_s, DEFINE_E_MARRYCHILD_M_ATTRIBUTE_MAX_NUM> m_attribute;//激活属性
		NFShmVector<struct E_MarryChildStariattributeDesc_s, DEFINE_E_MARRYCHILD_M_STARIATTRIBUTE_MAX_NUM> m_stariattribute;//升星属性

		virtual void write_to_pbmsg(::proto_ff::E_MarryChild & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChild & msg);
		static ::proto_ff::E_MarryChild* new_pbmsg(){ return new ::proto_ff::E_MarryChild(); }
		static ::proto_ff::E_MarryChild make_pbmsg(){ return ::proto_ff::E_MarryChild(); }
	};
	typedef struct E_MarryChild_s E_MarryChild_t;

	struct Sheet_MarryChild_s : public NFDescStoreSeqOP {
		Sheet_MarryChild_s();
		virtual ~Sheet_MarryChild_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryChild_s, DEFINE_SHEET_MARRYCHILD_E_MARRYCHILD_LIST_MAX_NUM> E_MarryChild_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryChild & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryChild & msg);
		static ::proto_ff::Sheet_MarryChild* new_pbmsg(){ return new ::proto_ff::Sheet_MarryChild(); }
		static ::proto_ff::Sheet_MarryChild make_pbmsg(){ return ::proto_ff::Sheet_MarryChild(); }
	};
	typedef struct Sheet_MarryChild_s Sheet_MarryChild_t;

	struct E_MarryChildvalue_s : public NFDescStoreSeqOP {
		E_MarryChildvalue_s();
		virtual ~E_MarryChildvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//属性组ID
		NFShmVector<int32_t, DEFINE_E_MARRYCHILDVALUE_M_LVVALUE_MAX_NUM> m_lvvalue;//等级值

		virtual void write_to_pbmsg(::proto_ff::E_MarryChildvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChildvalue & msg);
		static ::proto_ff::E_MarryChildvalue* new_pbmsg(){ return new ::proto_ff::E_MarryChildvalue(); }
		static ::proto_ff::E_MarryChildvalue make_pbmsg(){ return ::proto_ff::E_MarryChildvalue(); }
	};
	typedef struct E_MarryChildvalue_s E_MarryChildvalue_t;

	struct Sheet_MarryChildvalue_s : public NFDescStoreSeqOP {
		Sheet_MarryChildvalue_s();
		virtual ~Sheet_MarryChildvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryChildvalue_s, DEFINE_SHEET_MARRYCHILDVALUE_E_MARRYCHILDVALUE_LIST_MAX_NUM> E_MarryChildvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryChildvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryChildvalue & msg);
		static ::proto_ff::Sheet_MarryChildvalue* new_pbmsg(){ return new ::proto_ff::Sheet_MarryChildvalue(); }
		static ::proto_ff::Sheet_MarryChildvalue make_pbmsg(){ return ::proto_ff::Sheet_MarryChildvalue(); }
	};
	typedef struct Sheet_MarryChildvalue_s Sheet_MarryChildvalue_t;

	struct E_MarryChildexpGradeDesc_s : public NFDescStoreSeqOP {
		E_MarryChildexpGradeDesc_s();
		virtual ~E_MarryChildexpGradeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验
		int32_t m_lv;//等级

		virtual void write_to_pbmsg(::proto_ff::E_MarryChildexpGradeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChildexpGradeDesc & msg);
		static ::proto_ff::E_MarryChildexpGradeDesc* new_pbmsg(){ return new ::proto_ff::E_MarryChildexpGradeDesc(); }
		static ::proto_ff::E_MarryChildexpGradeDesc make_pbmsg(){ return ::proto_ff::E_MarryChildexpGradeDesc(); }
	};
	typedef struct E_MarryChildexpGradeDesc_s E_MarryChildexpGradeDesc_t;

	struct E_MarryChildexp_s : public NFDescStoreSeqOP {
		E_MarryChildexp_s();
		virtual ~E_MarryChildexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//阶级
		NFShmVector<struct E_MarryChildexpGradeDesc_s, DEFINE_E_MARRYCHILDEXP_M_GRADE_MAX_NUM> m_grade;//品阶

		virtual void write_to_pbmsg(::proto_ff::E_MarryChildexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryChildexp & msg);
		static ::proto_ff::E_MarryChildexp* new_pbmsg(){ return new ::proto_ff::E_MarryChildexp(); }
		static ::proto_ff::E_MarryChildexp make_pbmsg(){ return ::proto_ff::E_MarryChildexp(); }
	};
	typedef struct E_MarryChildexp_s E_MarryChildexp_t;

	struct Sheet_MarryChildexp_s : public NFDescStoreSeqOP {
		Sheet_MarryChildexp_s();
		virtual ~Sheet_MarryChildexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryChildexp_s, DEFINE_SHEET_MARRYCHILDEXP_E_MARRYCHILDEXP_LIST_MAX_NUM> E_MarryChildexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryChildexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryChildexp & msg);
		static ::proto_ff::Sheet_MarryChildexp* new_pbmsg(){ return new ::proto_ff::Sheet_MarryChildexp(); }
		static ::proto_ff::Sheet_MarryChildexp make_pbmsg(){ return ::proto_ff::Sheet_MarryChildexp(); }
	};
	typedef struct Sheet_MarryChildexp_s Sheet_MarryChildexp_t;

	struct E_MarryExpressAttributeDesc_s : public NFDescStoreSeqOP {
		E_MarryExpressAttributeDesc_s();
		virtual ~E_MarryExpressAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MarryExpressAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryExpressAttributeDesc & msg);
		static ::proto_ff::E_MarryExpressAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MarryExpressAttributeDesc(); }
		static ::proto_ff::E_MarryExpressAttributeDesc make_pbmsg(){ return ::proto_ff::E_MarryExpressAttributeDesc(); }
	};
	typedef struct E_MarryExpressAttributeDesc_s E_MarryExpressAttributeDesc_t;

	struct E_MarryExpress_s : public NFDescStoreSeqOP {
		E_MarryExpress_s();
		virtual ~E_MarryExpress_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级需要经验
		NFShmVector<struct E_MarryExpressAttributeDesc_s, DEFINE_E_MARRYEXPRESS_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MarryExpress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryExpress & msg);
		static ::proto_ff::E_MarryExpress* new_pbmsg(){ return new ::proto_ff::E_MarryExpress(); }
		static ::proto_ff::E_MarryExpress make_pbmsg(){ return ::proto_ff::E_MarryExpress(); }
	};
	typedef struct E_MarryExpress_s E_MarryExpress_t;

	struct Sheet_MarryExpress_s : public NFDescStoreSeqOP {
		Sheet_MarryExpress_s();
		virtual ~Sheet_MarryExpress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryExpress_s, DEFINE_SHEET_MARRYEXPRESS_E_MARRYEXPRESS_LIST_MAX_NUM> E_MarryExpress_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryExpress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryExpress & msg);
		static ::proto_ff::Sheet_MarryExpress* new_pbmsg(){ return new ::proto_ff::Sheet_MarryExpress(); }
		static ::proto_ff::Sheet_MarryExpress make_pbmsg(){ return ::proto_ff::Sheet_MarryExpress(); }
	};
	typedef struct Sheet_MarryExpress_s Sheet_MarryExpress_t;

	struct E_MarryExpresslanguage_s : public NFDescStoreSeqOP {
		E_MarryExpresslanguage_s();
		virtual ~E_MarryExpresslanguage_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<256> m_language;//表白文字

		virtual void write_to_pbmsg(::proto_ff::E_MarryExpresslanguage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryExpresslanguage & msg);
		static ::proto_ff::E_MarryExpresslanguage* new_pbmsg(){ return new ::proto_ff::E_MarryExpresslanguage(); }
		static ::proto_ff::E_MarryExpresslanguage make_pbmsg(){ return ::proto_ff::E_MarryExpresslanguage(); }
	};
	typedef struct E_MarryExpresslanguage_s E_MarryExpresslanguage_t;

	struct Sheet_MarryExpresslanguage_s : public NFDescStoreSeqOP {
		Sheet_MarryExpresslanguage_s();
		virtual ~Sheet_MarryExpresslanguage_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryExpresslanguage_s, DEFINE_SHEET_MARRYEXPRESSLANGUAGE_E_MARRYEXPRESSLANGUAGE_LIST_MAX_NUM> E_MarryExpresslanguage_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryExpresslanguage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryExpresslanguage & msg);
		static ::proto_ff::Sheet_MarryExpresslanguage* new_pbmsg(){ return new ::proto_ff::Sheet_MarryExpresslanguage(); }
		static ::proto_ff::Sheet_MarryExpresslanguage make_pbmsg(){ return ::proto_ff::Sheet_MarryExpresslanguage(); }
	};
	typedef struct Sheet_MarryExpresslanguage_s Sheet_MarryExpresslanguage_t;

	struct E_MarryExpressshop_s : public NFDescStoreSeqOP {
		E_MarryExpressshop_s();
		virtual ~E_MarryExpressshop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exitem;//表白道具
		int32_t m_mallid;//商城id
		int32_t m_exp;//增加表白值
		int32_t m_expto;//被表白经验值
		int32_t m_broadcastid;//广播id
		int32_t m_effectid;//表白特效ID

		virtual void write_to_pbmsg(::proto_ff::E_MarryExpressshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryExpressshop & msg);
		static ::proto_ff::E_MarryExpressshop* new_pbmsg(){ return new ::proto_ff::E_MarryExpressshop(); }
		static ::proto_ff::E_MarryExpressshop make_pbmsg(){ return ::proto_ff::E_MarryExpressshop(); }
	};
	typedef struct E_MarryExpressshop_s E_MarryExpressshop_t;

	struct Sheet_MarryExpressshop_s : public NFDescStoreSeqOP {
		Sheet_MarryExpressshop_s();
		virtual ~Sheet_MarryExpressshop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryExpressshop_s, DEFINE_SHEET_MARRYEXPRESSSHOP_E_MARRYEXPRESSSHOP_LIST_MAX_NUM> E_MarryExpressshop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryExpressshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryExpressshop & msg);
		static ::proto_ff::Sheet_MarryExpressshop* new_pbmsg(){ return new ::proto_ff::Sheet_MarryExpressshop(); }
		static ::proto_ff::Sheet_MarryExpressshop make_pbmsg(){ return ::proto_ff::Sheet_MarryExpressshop(); }
	};
	typedef struct Sheet_MarryExpressshop_s Sheet_MarryExpressshop_t;

	struct E_MarryConstantTourmonsterDesc_s : public NFDescStoreSeqOP {
		E_MarryConstantTourmonsterDesc_s();
		virtual ~E_MarryConstantTourmonsterDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_pathid;//pathid
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_MarryConstantTourmonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryConstantTourmonsterDesc & msg);
		static ::proto_ff::E_MarryConstantTourmonsterDesc* new_pbmsg(){ return new ::proto_ff::E_MarryConstantTourmonsterDesc(); }
		static ::proto_ff::E_MarryConstantTourmonsterDesc make_pbmsg(){ return ::proto_ff::E_MarryConstantTourmonsterDesc(); }
	};
	typedef struct E_MarryConstantTourmonsterDesc_s E_MarryConstantTourmonsterDesc_t;

	struct E_MarryConstant_s : public NFDescStoreSeqOP {
		E_MarryConstant_s();
		virtual ~E_MarryConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_money;//宝匣购买货币
		int32_t m_price;//宝匣购买价格
		int32_t m_buyitem;//宝匣购买立得材料
		int32_t m_dailyitem;//宝匣每日材料
		int32_t m_boxitme;//宝匣持续时间
		int32_t m_interval;//发送结缘请求间隔时间
		int32_t m_lifetime;//结缘请求存在寿命
		int32_t m_scale;//表白分享属性比例
		int32_t m_giveboy;//赠送男仙娃
		int32_t m_givegirl;//赠送女仙娃
		int32_t m_xytime;//巡游提前宴会开始时间
		int32_t m_free;//副本免费次数
		int32_t m_buynum;//可购买次数
		int32_t m_consume;//消耗货币
		int32_t m_consumenum;//价格
		int32_t m_marrylv;//结缘等级
		int32_t m_childtime;//仙娃领取时间
		int32_t m_lockitem;//信物养成道具
		int32_t m_lockitemexp;//信物经验值
		int32_t m_childitem;//仙娃养成道具
		int32_t m_childitemexp;//仙娃经验值
		int32_t m_guestprice;//席位货币
		int32_t m_guestpricenum;//席位价格
		int32_t m_asklimit;//申请列表上限
		int32_t m_hyreward;//婚宴奖励展示
		int32_t m_toursceneid;//巡游场景id
		int32_t m_tourfollowindex;//巡游挂点怪
		NFShmString<64> m_hyicon;//婚宴icon
		NFShmString<64> m_hyname;//婚宴名称
		NFShmString<64> m_xyicon;//巡游icon
		NFShmString<64> m_xyname;//巡游名称
		int32_t m_redbagnum;//巡游免费红包数量
		int32_t m_redmoney;//红包购买货币
		int32_t m_redprice;//红包购买价格
		int32_t m_sendredreward;//发红包奖励货币
		int32_t m_sendrednum;//发红包奖励价格
		int32_t m_redcollect;//红包采集物
		int32_t m_redcollectnum;//红包采集物数量
		int32_t m_cakemonster;//婚宴蛋糕模型
		int32_t m_hymonster;//宴席模型
		NFShmVector<struct E_MarryConstantTourmonsterDesc_s, DEFINE_E_MARRYCONSTANT_M_TOURMONSTER_MAX_NUM> m_tourmonster;//巡游怪物

		virtual void write_to_pbmsg(::proto_ff::E_MarryConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryConstant & msg);
		static ::proto_ff::E_MarryConstant* new_pbmsg(){ return new ::proto_ff::E_MarryConstant(); }
		static ::proto_ff::E_MarryConstant make_pbmsg(){ return ::proto_ff::E_MarryConstant(); }
	};
	typedef struct E_MarryConstant_s E_MarryConstant_t;

	struct Sheet_MarryConstant_s : public NFDescStoreSeqOP {
		Sheet_MarryConstant_s();
		virtual ~Sheet_MarryConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryConstant_s, DEFINE_SHEET_MARRYCONSTANT_E_MARRYCONSTANT_LIST_MAX_NUM> E_MarryConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryConstant & msg);
		static ::proto_ff::Sheet_MarryConstant* new_pbmsg(){ return new ::proto_ff::Sheet_MarryConstant(); }
		static ::proto_ff::Sheet_MarryConstant make_pbmsg(){ return ::proto_ff::Sheet_MarryConstant(); }
	};
	typedef struct Sheet_MarryConstant_s Sheet_MarryConstant_t;

	struct E_MarryCommon_s : public NFDescStoreSeqOP {
		E_MarryCommon_s();
		virtual ~E_MarryCommon_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//阶阶

		virtual void write_to_pbmsg(::proto_ff::E_MarryCommon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryCommon & msg);
		static ::proto_ff::E_MarryCommon* new_pbmsg(){ return new ::proto_ff::E_MarryCommon(); }
		static ::proto_ff::E_MarryCommon make_pbmsg(){ return ::proto_ff::E_MarryCommon(); }
	};
	typedef struct E_MarryCommon_s E_MarryCommon_t;

	struct Sheet_MarryCommon_s : public NFDescStoreSeqOP {
		Sheet_MarryCommon_s();
		virtual ~Sheet_MarryCommon_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryCommon_s, DEFINE_SHEET_MARRYCOMMON_E_MARRYCOMMON_LIST_MAX_NUM> E_MarryCommon_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryCommon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryCommon & msg);
		static ::proto_ff::Sheet_MarryCommon* new_pbmsg(){ return new ::proto_ff::Sheet_MarryCommon(); }
		static ::proto_ff::Sheet_MarryCommon make_pbmsg(){ return ::proto_ff::Sheet_MarryCommon(); }
	};
	typedef struct Sheet_MarryCommon_s Sheet_MarryCommon_t;

	struct E_MarryWeddingStageDesc_s : public NFDescStoreSeqOP {
		E_MarryWeddingStageDesc_s();
		virtual ~E_MarryWeddingStageDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//阶段

		virtual void write_to_pbmsg(::proto_ff::E_MarryWeddingStageDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryWeddingStageDesc & msg);
		static ::proto_ff::E_MarryWeddingStageDesc* new_pbmsg(){ return new ::proto_ff::E_MarryWeddingStageDesc(); }
		static ::proto_ff::E_MarryWeddingStageDesc make_pbmsg(){ return ::proto_ff::E_MarryWeddingStageDesc(); }
	};
	typedef struct E_MarryWeddingStageDesc_s E_MarryWeddingStageDesc_t;

	struct E_MarryWeddingFireDesc_s : public NFDescStoreSeqOP {
		E_MarryWeddingFireDesc_s();
		virtual ~E_MarryWeddingFireDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//号氛围值
		int32_t m_type;//号

		virtual void write_to_pbmsg(::proto_ff::E_MarryWeddingFireDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryWeddingFireDesc & msg);
		static ::proto_ff::E_MarryWeddingFireDesc* new_pbmsg(){ return new ::proto_ff::E_MarryWeddingFireDesc(); }
		static ::proto_ff::E_MarryWeddingFireDesc make_pbmsg(){ return ::proto_ff::E_MarryWeddingFireDesc(); }
	};
	typedef struct E_MarryWeddingFireDesc_s E_MarryWeddingFireDesc_t;

	struct E_MarryWeddingMoodDesc_s : public NFDescStoreSeqOP {
		E_MarryWeddingMoodDesc_s();
		virtual ~E_MarryWeddingMoodDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_reward;//奖励
		int32_t m_value;//数量

		virtual void write_to_pbmsg(::proto_ff::E_MarryWeddingMoodDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryWeddingMoodDesc & msg);
		static ::proto_ff::E_MarryWeddingMoodDesc* new_pbmsg(){ return new ::proto_ff::E_MarryWeddingMoodDesc(); }
		static ::proto_ff::E_MarryWeddingMoodDesc make_pbmsg(){ return ::proto_ff::E_MarryWeddingMoodDesc(); }
	};
	typedef struct E_MarryWeddingMoodDesc_s E_MarryWeddingMoodDesc_t;

	struct E_MarryWedding_s : public NFDescStoreSeqOP {
		E_MarryWedding_s();
		virtual ~E_MarryWedding_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_signreward;//签到奖励
		int32_t m_signdaynum;//每日签到奖励次数
		int32_t m_cakereftime;//蛋糕采集物
		int32_t m_cakenum;//蛋糕数量
		int32_t m_cake;//蛋糕刷新时间
		NFShmString<64> m_model;//变身模型
		int32_t m_modeltime;//变身持续时间
		int32_t m_cakereward;//采集奖励
		int32_t m_signcakenum;//每日采集蛋糕奖励次数
		int32_t m_monster;//亲友怪物id
		int32_t m_monsternum;//亲友怪物数量
		int32_t m_monstertime;//怪物击杀时间
		int32_t m_npcid;//亲友npcid
		int32_t m_npcnum;//亲友npc数量
		int32_t m_monsterreward;//亲友奖励
		int32_t m_monsterdaynum;//每日亲友奖励次数
		int32_t m_feastid;//宴席采集物id
		int32_t m_feastreward;//宴席采集奖励
		int32_t m_feastnum;//单场宴席采集次数
		int32_t m_interval;//获得经验间隔
		int32_t m_skillid;//丢蛋糕技能id
		NFShmVector<struct E_MarryWeddingStageDesc_s, DEFINE_E_MARRYWEDDING_M_STAGE_MAX_NUM> m_stage;//第
		NFShmVector<struct E_MarryWeddingFireDesc_s, DEFINE_E_MARRYWEDDING_M_FIRE_MAX_NUM> m_fire;//烟花
		NFShmVector<struct E_MarryWeddingMoodDesc_s, DEFINE_E_MARRYWEDDING_M_MOOD_MAX_NUM> m_mood;//氛围值

		virtual void write_to_pbmsg(::proto_ff::E_MarryWedding & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryWedding & msg);
		static ::proto_ff::E_MarryWedding* new_pbmsg(){ return new ::proto_ff::E_MarryWedding(); }
		static ::proto_ff::E_MarryWedding make_pbmsg(){ return ::proto_ff::E_MarryWedding(); }
	};
	typedef struct E_MarryWedding_s E_MarryWedding_t;

	struct Sheet_MarryWedding_s : public NFDescStoreSeqOP {
		Sheet_MarryWedding_s();
		virtual ~Sheet_MarryWedding_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryWedding_s, DEFINE_SHEET_MARRYWEDDING_E_MARRYWEDDING_LIST_MAX_NUM> E_MarryWedding_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryWedding & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryWedding & msg);
		static ::proto_ff::Sheet_MarryWedding* new_pbmsg(){ return new ::proto_ff::Sheet_MarryWedding(); }
		static ::proto_ff::Sheet_MarryWedding make_pbmsg(){ return ::proto_ff::Sheet_MarryWedding(); }
	};
	typedef struct Sheet_MarryWedding_s Sheet_MarryWedding_t;

	struct E_MarryExp_s : public NFDescStoreSeqOP {
		E_MarryExp_s();
		virtual ~E_MarryExp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_weddingexp;//婚宴经验
		int32_t m_dayexpmax;//每日最大经验值

		virtual void write_to_pbmsg(::proto_ff::E_MarryExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarryExp & msg);
		static ::proto_ff::E_MarryExp* new_pbmsg(){ return new ::proto_ff::E_MarryExp(); }
		static ::proto_ff::E_MarryExp make_pbmsg(){ return ::proto_ff::E_MarryExp(); }
	};
	typedef struct E_MarryExp_s E_MarryExp_t;

	struct Sheet_MarryExp_s : public NFDescStoreSeqOP {
		Sheet_MarryExp_s();
		virtual ~Sheet_MarryExp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarryExp_s, DEFINE_SHEET_MARRYEXP_E_MARRYEXP_LIST_MAX_NUM> E_MarryExp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarryExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarryExp & msg);
		static ::proto_ff::Sheet_MarryExp* new_pbmsg(){ return new ::proto_ff::Sheet_MarryExp(); }
		static ::proto_ff::Sheet_MarryExp make_pbmsg(){ return ::proto_ff::Sheet_MarryExp(); }
	};
	typedef struct Sheet_MarryExp_s Sheet_MarryExp_t;

}

