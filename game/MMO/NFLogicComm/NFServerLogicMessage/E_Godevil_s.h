#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Godevil.pb.h"
#include "E_Godevil_s.h"

#define DEFINE_SHEET_GODEVILPREPOSETASK_E_GODEVILPREPOSETASK_LIST_MAX_NUM 16
#define DEFINE_E_GODEVILGODEVILLV_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_GODEVILGODEVILLV_E_GODEVILGODEVILLV_LIST_MAX_NUM 2048
#define DEFINE_SHEET_GODEVILGODEVILPRIVILEGE_E_GODEVILGODEVILPRIVILEGE_LIST_MAX_NUM 32
#define DEFINE_E_GODEVILSTRONG_M_ST_MAX_NUM 5
#define DEFINE_SHEET_GODEVILSTRONG_E_GODEVILSTRONG_LIST_MAX_NUM 1024
#define DEFINE_SHEET_GODEVILSTRONGEXP_E_GODEVILSTRONGEXP_LIST_MAX_NUM 8
#define DEFINE_E_GODEVILADVANCELV_M_AD_MAX_NUM 2
#define DEFINE_SHEET_GODEVILADVANCELV_E_GODEVILADVANCELV_LIST_MAX_NUM 16
#define DEFINE_SHEET_GODEVILADVANCEEXP_E_GODEVILADVANCEEXP_LIST_MAX_NUM 32
#define DEFINE_E_GODEVILQUALITYLV_M_ITEM_MAX_NUM 3
#define DEFINE_SHEET_GODEVILQUALITYLV_E_GODEVILQUALITYLV_LIST_MAX_NUM 16
#define DEFINE_SHEET_GODEVILPOSITIONUNLOCK_E_GODEVILPOSITIONUNLOCK_LIST_MAX_NUM 16
#define DEFINE_E_GODEVILBLACKSMITH_M_ITEM_MAX_NUM 3
#define DEFINE_E_GODEVILBLACKSMITH_M_SKILL_MAX_NUM 12
#define DEFINE_SHEET_GODEVILBLACKSMITH_E_GODEVILBLACKSMITH_LIST_MAX_NUM 32
#define DEFINE_SHEET_GODEVILGODEVILSKILL_E_GODEVILGODEVILSKILL_LIST_MAX_NUM 2
#define DEFINE_SHEET_GODEVILPREFIXNAME_E_GODEVILPREFIXNAME_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_GodevilPreposetask_s : public NFDescStoreSeqOP {
		E_GodevilPreposetask_s();
		virtual ~E_GodevilPreposetask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号ID
		int32_t m_type;//类型
		int32_t m_modeltype;//所属阶段
		int32_t m_starttask;//任务ID
		int32_t m_endtask;//结束任务ID
		int32_t m_condition;//条件
		int32_t m_value;//条件值
		int32_t m_rewardid;//奖励ID

		virtual void write_to_pbmsg(::proto_ff::E_GodevilPreposetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilPreposetask & msg);
		static ::proto_ff::E_GodevilPreposetask* new_pbmsg(){ return new ::proto_ff::E_GodevilPreposetask(); }
		static ::proto_ff::E_GodevilPreposetask make_pbmsg(){ return ::proto_ff::E_GodevilPreposetask(); }
	};
	typedef struct E_GodevilPreposetask_s E_GodevilPreposetask_t;

	struct Sheet_GodevilPreposetask_s : public NFDescStoreSeqOP {
		Sheet_GodevilPreposetask_s();
		virtual ~Sheet_GodevilPreposetask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilPreposetask_s, DEFINE_SHEET_GODEVILPREPOSETASK_E_GODEVILPREPOSETASK_LIST_MAX_NUM> E_GodevilPreposetask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilPreposetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilPreposetask & msg);
		static ::proto_ff::Sheet_GodevilPreposetask* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilPreposetask(); }
		static ::proto_ff::Sheet_GodevilPreposetask make_pbmsg(){ return ::proto_ff::Sheet_GodevilPreposetask(); }
	};
	typedef struct Sheet_GodevilPreposetask_s Sheet_GodevilPreposetask_t;

	struct E_GodevilGodevillvAttributeDesc_s : public NFDescStoreSeqOP {
		E_GodevilGodevillvAttributeDesc_s();
		virtual ~E_GodevilGodevillvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevillvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevillvAttributeDesc & msg);
		static ::proto_ff::E_GodevilGodevillvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevillvAttributeDesc(); }
		static ::proto_ff::E_GodevilGodevillvAttributeDesc make_pbmsg(){ return ::proto_ff::E_GodevilGodevillvAttributeDesc(); }
	};
	typedef struct E_GodevilGodevillvAttributeDesc_s E_GodevilGodevillvAttributeDesc_t;

	struct E_GodevilGodevillv_s : public NFDescStoreSeqOP {
		E_GodevilGodevillv_s();
		virtual ~E_GodevilGodevillv_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//等级
		int64_t m_exp;//下级经验
		int64_t m_explimit;//经验上限
		int32_t m_itemid;//突破材料
		int32_t m_num;//材料数量
		NFShmVector<struct E_GodevilGodevillvAttributeDesc_s, DEFINE_E_GODEVILGODEVILLV_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevillv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevillv & msg);
		static ::proto_ff::E_GodevilGodevillv* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevillv(); }
		static ::proto_ff::E_GodevilGodevillv make_pbmsg(){ return ::proto_ff::E_GodevilGodevillv(); }
	};
	typedef struct E_GodevilGodevillv_s E_GodevilGodevillv_t;

	struct Sheet_GodevilGodevillv_s : public NFDescStoreSeqOP {
		Sheet_GodevilGodevillv_s();
		virtual ~Sheet_GodevilGodevillv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilGodevillv_s, DEFINE_SHEET_GODEVILGODEVILLV_E_GODEVILGODEVILLV_LIST_MAX_NUM> E_GodevilGodevillv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilGodevillv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevillv & msg);
		static ::proto_ff::Sheet_GodevilGodevillv* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilGodevillv(); }
		static ::proto_ff::Sheet_GodevilGodevillv make_pbmsg(){ return ::proto_ff::Sheet_GodevilGodevillv(); }
	};
	typedef struct Sheet_GodevilGodevillv_s Sheet_GodevilGodevillv_t;

	struct E_GodevilGodevilprivilege_s : public NFDescStoreSeqOP {
		E_GodevilGodevilprivilege_s();
		virtual ~E_GodevilGodevilprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_oldprice;//原价元
		int32_t m_newprice;//现价
		int32_t m_rechargid;//计费点
		int32_t m_type;//特权类型
		int32_t m_lv;//特权等级
		int32_t m_functiontype;//功能类型
		int32_t m_parama;//参数
		int32_t m_equipmentid;//获取装备道具ID
		int32_t m_itemid;//赠送的装备道具ID

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevilprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevilprivilege & msg);
		static ::proto_ff::E_GodevilGodevilprivilege* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevilprivilege(); }
		static ::proto_ff::E_GodevilGodevilprivilege make_pbmsg(){ return ::proto_ff::E_GodevilGodevilprivilege(); }
	};
	typedef struct E_GodevilGodevilprivilege_s E_GodevilGodevilprivilege_t;

	struct Sheet_GodevilGodevilprivilege_s : public NFDescStoreSeqOP {
		Sheet_GodevilGodevilprivilege_s();
		virtual ~Sheet_GodevilGodevilprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilGodevilprivilege_s, DEFINE_SHEET_GODEVILGODEVILPRIVILEGE_E_GODEVILGODEVILPRIVILEGE_LIST_MAX_NUM> E_GodevilGodevilprivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilGodevilprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevilprivilege & msg);
		static ::proto_ff::Sheet_GodevilGodevilprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilGodevilprivilege(); }
		static ::proto_ff::Sheet_GodevilGodevilprivilege make_pbmsg(){ return ::proto_ff::Sheet_GodevilGodevilprivilege(); }
	};
	typedef struct Sheet_GodevilGodevilprivilege_s Sheet_GodevilGodevilprivilege_t;

	struct E_GodevilStrongStDesc_s : public NFDescStoreSeqOP {
		E_GodevilStrongStDesc_s();
		virtual ~E_GodevilStrongStDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_typeid;//提升属性类型
		NFShmString<64> m_quality;//品质
		NFShmString<64> m_position;//部位

		virtual void write_to_pbmsg(::proto_ff::E_GodevilStrongStDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilStrongStDesc & msg);
		static ::proto_ff::E_GodevilStrongStDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilStrongStDesc(); }
		static ::proto_ff::E_GodevilStrongStDesc make_pbmsg(){ return ::proto_ff::E_GodevilStrongStDesc(); }
	};
	typedef struct E_GodevilStrongStDesc_s E_GodevilStrongStDesc_t;

	struct E_GodevilStrong_s : public NFDescStoreSeqOP {
		E_GodevilStrong_s();
		virtual ~E_GodevilStrong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//强化等级
		int32_t m_exp;//经验值
		int32_t m_type_num;//属性提升系数
		int32_t m_godevillv;//需求神魔等级
		NFShmVector<struct E_GodevilStrongStDesc_s, DEFINE_E_GODEVILSTRONG_M_ST_MAX_NUM> m_st;//装备

		virtual void write_to_pbmsg(::proto_ff::E_GodevilStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilStrong & msg);
		static ::proto_ff::E_GodevilStrong* new_pbmsg(){ return new ::proto_ff::E_GodevilStrong(); }
		static ::proto_ff::E_GodevilStrong make_pbmsg(){ return ::proto_ff::E_GodevilStrong(); }
	};
	typedef struct E_GodevilStrong_s E_GodevilStrong_t;

	struct Sheet_GodevilStrong_s : public NFDescStoreSeqOP {
		Sheet_GodevilStrong_s();
		virtual ~Sheet_GodevilStrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilStrong_s, DEFINE_SHEET_GODEVILSTRONG_E_GODEVILSTRONG_LIST_MAX_NUM> E_GodevilStrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilStrong & msg);
		static ::proto_ff::Sheet_GodevilStrong* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilStrong(); }
		static ::proto_ff::Sheet_GodevilStrong make_pbmsg(){ return ::proto_ff::Sheet_GodevilStrong(); }
	};
	typedef struct Sheet_GodevilStrong_s Sheet_GodevilStrong_t;

	struct E_GodevilStrongexp_s : public NFDescStoreSeqOP {
		E_GodevilStrongexp_s();
		virtual ~E_GodevilStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_parama;//影响值
		int32_t m_strongexp;//经验值

		virtual void write_to_pbmsg(::proto_ff::E_GodevilStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilStrongexp & msg);
		static ::proto_ff::E_GodevilStrongexp* new_pbmsg(){ return new ::proto_ff::E_GodevilStrongexp(); }
		static ::proto_ff::E_GodevilStrongexp make_pbmsg(){ return ::proto_ff::E_GodevilStrongexp(); }
	};
	typedef struct E_GodevilStrongexp_s E_GodevilStrongexp_t;

	struct Sheet_GodevilStrongexp_s : public NFDescStoreSeqOP {
		Sheet_GodevilStrongexp_s();
		virtual ~Sheet_GodevilStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilStrongexp_s, DEFINE_SHEET_GODEVILSTRONGEXP_E_GODEVILSTRONGEXP_LIST_MAX_NUM> E_GodevilStrongexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilStrongexp & msg);
		static ::proto_ff::Sheet_GodevilStrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilStrongexp(); }
		static ::proto_ff::Sheet_GodevilStrongexp make_pbmsg(){ return ::proto_ff::Sheet_GodevilStrongexp(); }
	};
	typedef struct Sheet_GodevilStrongexp_s Sheet_GodevilStrongexp_t;

	struct E_GodevilAdvancelvAdDesc_s : public NFDescStoreSeqOP {
		E_GodevilAdvancelvAdDesc_s();
		virtual ~E_GodevilAdvancelvAdDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_godevillv;//需求神魔等级
		int32_t m_exp;//下级经验值
		NFShmString<64> m_position;//

		virtual void write_to_pbmsg(::proto_ff::E_GodevilAdvancelvAdDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilAdvancelvAdDesc & msg);
		static ::proto_ff::E_GodevilAdvancelvAdDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilAdvancelvAdDesc(); }
		static ::proto_ff::E_GodevilAdvancelvAdDesc make_pbmsg(){ return ::proto_ff::E_GodevilAdvancelvAdDesc(); }
	};
	typedef struct E_GodevilAdvancelvAdDesc_s E_GodevilAdvancelvAdDesc_t;

	struct E_GodevilAdvancelv_s : public NFDescStoreSeqOP {
		E_GodevilAdvancelv_s();
		virtual ~E_GodevilAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_wearlv;//装备品阶
		NFShmVector<struct E_GodevilAdvancelvAdDesc_s, DEFINE_E_GODEVILADVANCELV_M_AD_MAX_NUM> m_ad;//部位

		virtual void write_to_pbmsg(::proto_ff::E_GodevilAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilAdvancelv & msg);
		static ::proto_ff::E_GodevilAdvancelv* new_pbmsg(){ return new ::proto_ff::E_GodevilAdvancelv(); }
		static ::proto_ff::E_GodevilAdvancelv make_pbmsg(){ return ::proto_ff::E_GodevilAdvancelv(); }
	};
	typedef struct E_GodevilAdvancelv_s E_GodevilAdvancelv_t;

	struct Sheet_GodevilAdvancelv_s : public NFDescStoreSeqOP {
		Sheet_GodevilAdvancelv_s();
		virtual ~Sheet_GodevilAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilAdvancelv_s, DEFINE_SHEET_GODEVILADVANCELV_E_GODEVILADVANCELV_LIST_MAX_NUM> E_GodevilAdvancelv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilAdvancelv & msg);
		static ::proto_ff::Sheet_GodevilAdvancelv* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilAdvancelv(); }
		static ::proto_ff::Sheet_GodevilAdvancelv make_pbmsg(){ return ::proto_ff::Sheet_GodevilAdvancelv(); }
	};
	typedef struct Sheet_GodevilAdvancelv_s Sheet_GodevilAdvancelv_t;

	struct E_GodevilAdvanceexp_s : public NFDescStoreSeqOP {
		E_GodevilAdvanceexp_s();
		virtual ~E_GodevilAdvanceexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wearlv;//装备品阶
		NFShmString<64> m_position;//部位
		int32_t m_lvparama;//阶数系数
		int32_t m_goldparama;//黄星系数
		int32_t m_silverparama;//白星系数
		int32_t m_quality6;//红品系数
		int32_t m_quality7;//粉品系数
		int32_t m_quality8;//彩品系数
		int32_t m_quality9;//暗金品系数
		int32_t m_quality10;//神话品系数

		virtual void write_to_pbmsg(::proto_ff::E_GodevilAdvanceexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilAdvanceexp & msg);
		static ::proto_ff::E_GodevilAdvanceexp* new_pbmsg(){ return new ::proto_ff::E_GodevilAdvanceexp(); }
		static ::proto_ff::E_GodevilAdvanceexp make_pbmsg(){ return ::proto_ff::E_GodevilAdvanceexp(); }
	};
	typedef struct E_GodevilAdvanceexp_s E_GodevilAdvanceexp_t;

	struct Sheet_GodevilAdvanceexp_s : public NFDescStoreSeqOP {
		Sheet_GodevilAdvanceexp_s();
		virtual ~Sheet_GodevilAdvanceexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilAdvanceexp_s, DEFINE_SHEET_GODEVILADVANCEEXP_E_GODEVILADVANCEEXP_LIST_MAX_NUM> E_GodevilAdvanceexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilAdvanceexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilAdvanceexp & msg);
		static ::proto_ff::Sheet_GodevilAdvanceexp* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilAdvanceexp(); }
		static ::proto_ff::Sheet_GodevilAdvanceexp make_pbmsg(){ return ::proto_ff::Sheet_GodevilAdvanceexp(); }
	};
	typedef struct Sheet_GodevilAdvanceexp_s Sheet_GodevilAdvanceexp_t;

	struct E_GodevilQualitylvItemDesc_s : public NFDescStoreSeqOP {
		E_GodevilQualitylvItemDesc_s();
		virtual ~E_GodevilQualitylvItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_GodevilQualitylvItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilQualitylvItemDesc & msg);
		static ::proto_ff::E_GodevilQualitylvItemDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilQualitylvItemDesc(); }
		static ::proto_ff::E_GodevilQualitylvItemDesc make_pbmsg(){ return ::proto_ff::E_GodevilQualitylvItemDesc(); }
	};
	typedef struct E_GodevilQualitylvItemDesc_s E_GodevilQualitylvItemDesc_t;

	struct E_GodevilQualitylv_s : public NFDescStoreSeqOP {
		E_GodevilQualitylv_s();
		virtual ~E_GodevilQualitylv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//品质
		int32_t m_wearlv;//需求装备阶数
		int32_t m_percent;//下级成功率
		NFShmString<64> m_position;//部位
		int32_t m_costwuxiongitem;//消耗神品悟性道具
		int32_t m_costnumber;//数量
		NFShmVector<struct E_GodevilQualitylvItemDesc_s, DEFINE_E_GODEVILQUALITYLV_M_ITEM_MAX_NUM> m_item;//材料

		virtual void write_to_pbmsg(::proto_ff::E_GodevilQualitylv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilQualitylv & msg);
		static ::proto_ff::E_GodevilQualitylv* new_pbmsg(){ return new ::proto_ff::E_GodevilQualitylv(); }
		static ::proto_ff::E_GodevilQualitylv make_pbmsg(){ return ::proto_ff::E_GodevilQualitylv(); }
	};
	typedef struct E_GodevilQualitylv_s E_GodevilQualitylv_t;

	struct Sheet_GodevilQualitylv_s : public NFDescStoreSeqOP {
		Sheet_GodevilQualitylv_s();
		virtual ~Sheet_GodevilQualitylv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilQualitylv_s, DEFINE_SHEET_GODEVILQUALITYLV_E_GODEVILQUALITYLV_LIST_MAX_NUM> E_GodevilQualitylv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilQualitylv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilQualitylv & msg);
		static ::proto_ff::Sheet_GodevilQualitylv* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilQualitylv(); }
		static ::proto_ff::Sheet_GodevilQualitylv make_pbmsg(){ return ::proto_ff::Sheet_GodevilQualitylv(); }
	};
	typedef struct Sheet_GodevilQualitylv_s Sheet_GodevilQualitylv_t;

	struct E_GodevilPositionunlock_s : public NFDescStoreSeqOP {
		E_GodevilPositionunlock_s();
		virtual ~E_GodevilPositionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//部位id
		int32_t m_day;//解锁天数
		int32_t m_godevillv;//神魔等级

		virtual void write_to_pbmsg(::proto_ff::E_GodevilPositionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilPositionunlock & msg);
		static ::proto_ff::E_GodevilPositionunlock* new_pbmsg(){ return new ::proto_ff::E_GodevilPositionunlock(); }
		static ::proto_ff::E_GodevilPositionunlock make_pbmsg(){ return ::proto_ff::E_GodevilPositionunlock(); }
	};
	typedef struct E_GodevilPositionunlock_s E_GodevilPositionunlock_t;

	struct Sheet_GodevilPositionunlock_s : public NFDescStoreSeqOP {
		Sheet_GodevilPositionunlock_s();
		virtual ~Sheet_GodevilPositionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilPositionunlock_s, DEFINE_SHEET_GODEVILPOSITIONUNLOCK_E_GODEVILPOSITIONUNLOCK_LIST_MAX_NUM> E_GodevilPositionunlock_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilPositionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilPositionunlock & msg);
		static ::proto_ff::Sheet_GodevilPositionunlock* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilPositionunlock(); }
		static ::proto_ff::Sheet_GodevilPositionunlock make_pbmsg(){ return ::proto_ff::Sheet_GodevilPositionunlock(); }
	};
	typedef struct Sheet_GodevilPositionunlock_s Sheet_GodevilPositionunlock_t;

	struct E_GodevilBlacksmithItemDesc_s : public NFDescStoreSeqOP {
		E_GodevilBlacksmithItemDesc_s();
		virtual ~E_GodevilBlacksmithItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_GodevilBlacksmithItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmithItemDesc & msg);
		static ::proto_ff::E_GodevilBlacksmithItemDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilBlacksmithItemDesc(); }
		static ::proto_ff::E_GodevilBlacksmithItemDesc make_pbmsg(){ return ::proto_ff::E_GodevilBlacksmithItemDesc(); }
	};
	typedef struct E_GodevilBlacksmithItemDesc_s E_GodevilBlacksmithItemDesc_t;

	struct E_GodevilBlacksmithSkillDesc_s : public NFDescStoreSeqOP {
		E_GodevilBlacksmithSkillDesc_s();
		virtual ~E_GodevilBlacksmithSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_probability;//概率
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_GodevilBlacksmithSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmithSkillDesc & msg);
		static ::proto_ff::E_GodevilBlacksmithSkillDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilBlacksmithSkillDesc(); }
		static ::proto_ff::E_GodevilBlacksmithSkillDesc make_pbmsg(){ return ::proto_ff::E_GodevilBlacksmithSkillDesc(); }
	};
	typedef struct E_GodevilBlacksmithSkillDesc_s E_GodevilBlacksmithSkillDesc_t;

	struct E_GodevilBlacksmith_s : public NFDescStoreSeqOP {
		E_GodevilBlacksmith_s();
		virtual ~E_GodevilBlacksmith_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//打造id
		int32_t m_type;//打造类型
		int32_t m_position;//装备部位
		int32_t m_quality;//装备品质
		int32_t m_probability;//出现概率
		NFShmString<64> m_godpoint;//悟性随机
		NFShmString<64> m_starsprobability;//词条数和概率
		int32_t m_gold;//黄星概率
		int32_t m_silver;//白星概率
		int32_t m_paperid;//图纸ID
		int32_t m_papernum;//图纸数量
		int32_t m_substituteitem;//缺省道具
		int32_t m_number;//缺省道具数量
		int32_t m_godevilskill;//神魔技能ID
		NFShmString<64> m_skillset;//被动技能概率
		NFShmVector<struct E_GodevilBlacksmithItemDesc_s, DEFINE_E_GODEVILBLACKSMITH_M_ITEM_MAX_NUM> m_item;//道具
		NFShmVector<struct E_GodevilBlacksmithSkillDesc_s, DEFINE_E_GODEVILBLACKSMITH_M_SKILL_MAX_NUM> m_skill;//被动技能

		virtual void write_to_pbmsg(::proto_ff::E_GodevilBlacksmith & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmith & msg);
		static ::proto_ff::E_GodevilBlacksmith* new_pbmsg(){ return new ::proto_ff::E_GodevilBlacksmith(); }
		static ::proto_ff::E_GodevilBlacksmith make_pbmsg(){ return ::proto_ff::E_GodevilBlacksmith(); }
	};
	typedef struct E_GodevilBlacksmith_s E_GodevilBlacksmith_t;

	struct Sheet_GodevilBlacksmith_s : public NFDescStoreSeqOP {
		Sheet_GodevilBlacksmith_s();
		virtual ~Sheet_GodevilBlacksmith_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilBlacksmith_s, DEFINE_SHEET_GODEVILBLACKSMITH_E_GODEVILBLACKSMITH_LIST_MAX_NUM> E_GodevilBlacksmith_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilBlacksmith & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilBlacksmith & msg);
		static ::proto_ff::Sheet_GodevilBlacksmith* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilBlacksmith(); }
		static ::proto_ff::Sheet_GodevilBlacksmith make_pbmsg(){ return ::proto_ff::Sheet_GodevilBlacksmith(); }
	};
	typedef struct Sheet_GodevilBlacksmith_s Sheet_GodevilBlacksmith_t;

	struct E_GodevilGodevilskill_s : public NFDescStoreSeqOP {
		E_GodevilGodevilskill_s();
		virtual ~E_GodevilGodevilskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_godevilskill;//神魔技能ID
		int32_t m_goldstars;//金星星数

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevilskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevilskill & msg);
		static ::proto_ff::E_GodevilGodevilskill* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevilskill(); }
		static ::proto_ff::E_GodevilGodevilskill make_pbmsg(){ return ::proto_ff::E_GodevilGodevilskill(); }
	};
	typedef struct E_GodevilGodevilskill_s E_GodevilGodevilskill_t;

	struct Sheet_GodevilGodevilskill_s : public NFDescStoreSeqOP {
		Sheet_GodevilGodevilskill_s();
		virtual ~Sheet_GodevilGodevilskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilGodevilskill_s, DEFINE_SHEET_GODEVILGODEVILSKILL_E_GODEVILGODEVILSKILL_LIST_MAX_NUM> E_GodevilGodevilskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilGodevilskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevilskill & msg);
		static ::proto_ff::Sheet_GodevilGodevilskill* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilGodevilskill(); }
		static ::proto_ff::Sheet_GodevilGodevilskill make_pbmsg(){ return ::proto_ff::Sheet_GodevilGodevilskill(); }
	};
	typedef struct Sheet_GodevilGodevilskill_s Sheet_GodevilGodevilskill_t;

	struct E_GodevilPrefixname_s : public NFDescStoreSeqOP {
		E_GodevilPrefixname_s();
		virtual ~E_GodevilPrefixname_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//词缀id
		int32_t m_type;//词缀类型
		int32_t m_number;//词缀数量

		virtual void write_to_pbmsg(::proto_ff::E_GodevilPrefixname & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilPrefixname & msg);
		static ::proto_ff::E_GodevilPrefixname* new_pbmsg(){ return new ::proto_ff::E_GodevilPrefixname(); }
		static ::proto_ff::E_GodevilPrefixname make_pbmsg(){ return ::proto_ff::E_GodevilPrefixname(); }
	};
	typedef struct E_GodevilPrefixname_s E_GodevilPrefixname_t;

	struct Sheet_GodevilPrefixname_s : public NFDescStoreSeqOP {
		Sheet_GodevilPrefixname_s();
		virtual ~Sheet_GodevilPrefixname_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilPrefixname_s, DEFINE_SHEET_GODEVILPREFIXNAME_E_GODEVILPREFIXNAME_LIST_MAX_NUM> E_GodevilPrefixname_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilPrefixname & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilPrefixname & msg);
		static ::proto_ff::Sheet_GodevilPrefixname* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilPrefixname(); }
		static ::proto_ff::Sheet_GodevilPrefixname make_pbmsg(){ return ::proto_ff::Sheet_GodevilPrefixname(); }
	};
	typedef struct Sheet_GodevilPrefixname_s Sheet_GodevilPrefixname_t;

}

