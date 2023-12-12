#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Cloak.pb.h"
#include "E_Cloak_s.h"

#define DEFINE_SHEET_CLOAKACTIVATE_E_CLOAKACTIVATE_LIST_MAX_NUM 8
#define DEFINE_E_CLOAKVALUE_M_CLOAKATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_CLOAKVALUE_E_CLOAKVALUE_LIST_MAX_NUM 1024
#define DEFINE_SHEET_CLOAKINTENSIFYITEM_E_CLOAKINTENSIFYITEM_LIST_MAX_NUM 4
#define DEFINE_E_CLOAKREFINE_M_ITEM_MAX_NUM 3
#define DEFINE_E_CLOAKREFINE_M_ATT_MAX_NUM 4
#define DEFINE_SHEET_CLOAKREFINE_E_CLOAKREFINE_LIST_MAX_NUM 128
#define DEFINE_SHEET_CLOAKREFINEUNLOCK_E_CLOAKREFINEUNLOCK_LIST_MAX_NUM 64
#define DEFINE_E_CLOAKGRADE_M_ITEM_MAX_NUM 6
#define DEFINE_E_CLOAKGRADE_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_CLOAKGRADE_E_CLOAKGRADE_LIST_MAX_NUM 32
#define DEFINE_E_CLOAKGOD_M_ITEM_MAX_NUM 2
#define DEFINE_E_CLOAKGOD_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_CLOAKGOD_E_CLOAKGOD_LIST_MAX_NUM 8
#define DEFINE_E_CLOAKSOUL_M_MINORSKILL_MAX_NUM 8
#define DEFINE_E_CLOAKSOUL_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_CLOAKSOUL_E_CLOAKSOUL_LIST_MAX_NUM 2
#define DEFINE_E_CLOAKSOULACTIVE_M_UNLOCK_MAX_NUM 3
#define DEFINE_SHEET_CLOAKSOULACTIVE_E_CLOAKSOULACTIVE_LIST_MAX_NUM 16
#define DEFINE_E_CLOAKSOULLV_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_CLOAKSOULLV_E_CLOAKSOULLV_LIST_MAX_NUM 128
#define DEFINE_E_CLOAKSOULCLEAR_M_CLEARATT_MAX_NUM 2
#define DEFINE_SHEET_CLOAKSOULCLEAR_E_CLOAKSOULCLEAR_LIST_MAX_NUM 2
#define DEFINE_SHEET_CLOAKSOULACHIEVEMENT_E_CLOAKSOULACHIEVEMENT_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_CloakActivate_s : public NFDescStoreSeqOP {
		E_CloakActivate_s();
		virtual ~E_CloakActivate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_cloakId;//披风id
		int32_t m_show;//是否初始显示
		int32_t m_quality;//品质
		int32_t m_facade;//形象id
		int32_t m_activateItem;//激活道具id
		int32_t m_activateNum;//激活道具数量

		virtual void write_to_pbmsg(::proto_ff::E_CloakActivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakActivate & msg);
		static ::proto_ff::E_CloakActivate* new_pbmsg(){ return new ::proto_ff::E_CloakActivate(); }
		static ::proto_ff::E_CloakActivate make_pbmsg(){ return ::proto_ff::E_CloakActivate(); }
	};
	typedef struct E_CloakActivate_s E_CloakActivate_t;

	struct Sheet_CloakActivate_s : public NFDescStoreSeqOP {
		Sheet_CloakActivate_s();
		virtual ~Sheet_CloakActivate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakActivate_s, DEFINE_SHEET_CLOAKACTIVATE_E_CLOAKACTIVATE_LIST_MAX_NUM> E_CloakActivate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakActivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakActivate & msg);
		static ::proto_ff::Sheet_CloakActivate* new_pbmsg(){ return new ::proto_ff::Sheet_CloakActivate(); }
		static ::proto_ff::Sheet_CloakActivate make_pbmsg(){ return ::proto_ff::Sheet_CloakActivate(); }
	};
	typedef struct Sheet_CloakActivate_s Sheet_CloakActivate_t;

	struct E_CloakValueCloakattributeDesc_s : public NFDescStoreSeqOP {
		E_CloakValueCloakattributeDesc_s();
		virtual ~E_CloakValueCloakattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_CloakValueCloakattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakValueCloakattributeDesc & msg);
		static ::proto_ff::E_CloakValueCloakattributeDesc* new_pbmsg(){ return new ::proto_ff::E_CloakValueCloakattributeDesc(); }
		static ::proto_ff::E_CloakValueCloakattributeDesc make_pbmsg(){ return ::proto_ff::E_CloakValueCloakattributeDesc(); }
	};
	typedef struct E_CloakValueCloakattributeDesc_s E_CloakValueCloakattributeDesc_t;

	struct E_CloakValue_s : public NFDescStoreSeqOP {
		E_CloakValue_s();
		virtual ~E_CloakValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int64_t m_cloakExp;//披风升级经验
		NFShmVector<struct E_CloakValueCloakattributeDesc_s, DEFINE_E_CLOAKVALUE_M_CLOAKATTRIBUTE_MAX_NUM> m_cloakAttribute;//披风基础属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakValue & msg);
		static ::proto_ff::E_CloakValue* new_pbmsg(){ return new ::proto_ff::E_CloakValue(); }
		static ::proto_ff::E_CloakValue make_pbmsg(){ return ::proto_ff::E_CloakValue(); }
	};
	typedef struct E_CloakValue_s E_CloakValue_t;

	struct Sheet_CloakValue_s : public NFDescStoreSeqOP {
		Sheet_CloakValue_s();
		virtual ~Sheet_CloakValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakValue_s, DEFINE_SHEET_CLOAKVALUE_E_CLOAKVALUE_LIST_MAX_NUM> E_CloakValue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakValue & msg);
		static ::proto_ff::Sheet_CloakValue* new_pbmsg(){ return new ::proto_ff::Sheet_CloakValue(); }
		static ::proto_ff::Sheet_CloakValue make_pbmsg(){ return ::proto_ff::Sheet_CloakValue(); }
	};
	typedef struct Sheet_CloakValue_s Sheet_CloakValue_t;

	struct E_CloakIntensifyitem_s : public NFDescStoreSeqOP {
		E_CloakIntensifyitem_s();
		virtual ~E_CloakIntensifyitem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//道具id
		int32_t m_addExp;//增加经验值

		virtual void write_to_pbmsg(::proto_ff::E_CloakIntensifyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakIntensifyitem & msg);
		static ::proto_ff::E_CloakIntensifyitem* new_pbmsg(){ return new ::proto_ff::E_CloakIntensifyitem(); }
		static ::proto_ff::E_CloakIntensifyitem make_pbmsg(){ return ::proto_ff::E_CloakIntensifyitem(); }
	};
	typedef struct E_CloakIntensifyitem_s E_CloakIntensifyitem_t;

	struct Sheet_CloakIntensifyitem_s : public NFDescStoreSeqOP {
		Sheet_CloakIntensifyitem_s();
		virtual ~Sheet_CloakIntensifyitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakIntensifyitem_s, DEFINE_SHEET_CLOAKINTENSIFYITEM_E_CLOAKINTENSIFYITEM_LIST_MAX_NUM> E_CloakIntensifyitem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakIntensifyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakIntensifyitem & msg);
		static ::proto_ff::Sheet_CloakIntensifyitem* new_pbmsg(){ return new ::proto_ff::Sheet_CloakIntensifyitem(); }
		static ::proto_ff::Sheet_CloakIntensifyitem make_pbmsg(){ return ::proto_ff::Sheet_CloakIntensifyitem(); }
	};
	typedef struct Sheet_CloakIntensifyitem_s Sheet_CloakIntensifyitem_t;

	struct E_CloakRefineItemDesc_s : public NFDescStoreSeqOP {
		E_CloakRefineItemDesc_s();
		virtual ~E_CloakRefineItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_CloakRefineItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakRefineItemDesc & msg);
		static ::proto_ff::E_CloakRefineItemDesc* new_pbmsg(){ return new ::proto_ff::E_CloakRefineItemDesc(); }
		static ::proto_ff::E_CloakRefineItemDesc make_pbmsg(){ return ::proto_ff::E_CloakRefineItemDesc(); }
	};
	typedef struct E_CloakRefineItemDesc_s E_CloakRefineItemDesc_t;

	struct E_CloakRefineAttDesc_s : public NFDescStoreSeqOP {
		E_CloakRefineAttDesc_s();
		virtual ~E_CloakRefineAttDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_vlue;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_CloakRefineAttDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakRefineAttDesc & msg);
		static ::proto_ff::E_CloakRefineAttDesc* new_pbmsg(){ return new ::proto_ff::E_CloakRefineAttDesc(); }
		static ::proto_ff::E_CloakRefineAttDesc make_pbmsg(){ return ::proto_ff::E_CloakRefineAttDesc(); }
	};
	typedef struct E_CloakRefineAttDesc_s E_CloakRefineAttDesc_t;

	struct E_CloakRefine_s : public NFDescStoreSeqOP {
		E_CloakRefine_s();
		virtual ~E_CloakRefine_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_cloakId;//披风id
		int32_t m_refineLv;//精炼等级
		int32_t m_success;//精炼成功率
		int32_t m_guarant;//精炼保底次数
		NFShmVector<struct E_CloakRefineItemDesc_s, DEFINE_E_CLOAKREFINE_M_ITEM_MAX_NUM> m_item;//消耗道具
		NFShmVector<struct E_CloakRefineAttDesc_s, DEFINE_E_CLOAKREFINE_M_ATT_MAX_NUM> m_att;//精炼属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakRefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakRefine & msg);
		static ::proto_ff::E_CloakRefine* new_pbmsg(){ return new ::proto_ff::E_CloakRefine(); }
		static ::proto_ff::E_CloakRefine make_pbmsg(){ return ::proto_ff::E_CloakRefine(); }
	};
	typedef struct E_CloakRefine_s E_CloakRefine_t;

	struct Sheet_CloakRefine_s : public NFDescStoreSeqOP {
		Sheet_CloakRefine_s();
		virtual ~Sheet_CloakRefine_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakRefine_s, DEFINE_SHEET_CLOAKREFINE_E_CLOAKREFINE_LIST_MAX_NUM> E_CloakRefine_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakRefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakRefine & msg);
		static ::proto_ff::Sheet_CloakRefine* new_pbmsg(){ return new ::proto_ff::Sheet_CloakRefine(); }
		static ::proto_ff::Sheet_CloakRefine make_pbmsg(){ return ::proto_ff::Sheet_CloakRefine(); }
	};
	typedef struct Sheet_CloakRefine_s Sheet_CloakRefine_t;

	struct E_CloakRefineunlock_s : public NFDescStoreSeqOP {
		E_CloakRefineunlock_s();
		virtual ~E_CloakRefineunlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_cloakId;//披风id
		int32_t m_refineLv;//精炼等级
		int32_t m_unlockAtt;//精炼解锁属性id
		int32_t m_unlockVlue;//精炼解锁属性值
		int32_t m_skill;//激活技能

		virtual void write_to_pbmsg(::proto_ff::E_CloakRefineunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakRefineunlock & msg);
		static ::proto_ff::E_CloakRefineunlock* new_pbmsg(){ return new ::proto_ff::E_CloakRefineunlock(); }
		static ::proto_ff::E_CloakRefineunlock make_pbmsg(){ return ::proto_ff::E_CloakRefineunlock(); }
	};
	typedef struct E_CloakRefineunlock_s E_CloakRefineunlock_t;

	struct Sheet_CloakRefineunlock_s : public NFDescStoreSeqOP {
		Sheet_CloakRefineunlock_s();
		virtual ~Sheet_CloakRefineunlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakRefineunlock_s, DEFINE_SHEET_CLOAKREFINEUNLOCK_E_CLOAKREFINEUNLOCK_LIST_MAX_NUM> E_CloakRefineunlock_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakRefineunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakRefineunlock & msg);
		static ::proto_ff::Sheet_CloakRefineunlock* new_pbmsg(){ return new ::proto_ff::Sheet_CloakRefineunlock(); }
		static ::proto_ff::Sheet_CloakRefineunlock make_pbmsg(){ return ::proto_ff::Sheet_CloakRefineunlock(); }
	};
	typedef struct Sheet_CloakRefineunlock_s Sheet_CloakRefineunlock_t;

	struct E_CloakGradeItemDesc_s : public NFDescStoreSeqOP {
		E_CloakGradeItemDesc_s();
		virtual ~E_CloakGradeItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_CloakGradeItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGradeItemDesc & msg);
		static ::proto_ff::E_CloakGradeItemDesc* new_pbmsg(){ return new ::proto_ff::E_CloakGradeItemDesc(); }
		static ::proto_ff::E_CloakGradeItemDesc make_pbmsg(){ return ::proto_ff::E_CloakGradeItemDesc(); }
	};
	typedef struct E_CloakGradeItemDesc_s E_CloakGradeItemDesc_t;

	struct E_CloakGradeAttributeDesc_s : public NFDescStoreSeqOP {
		E_CloakGradeAttributeDesc_s();
		virtual ~E_CloakGradeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_vlue;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_CloakGradeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGradeAttributeDesc & msg);
		static ::proto_ff::E_CloakGradeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CloakGradeAttributeDesc(); }
		static ::proto_ff::E_CloakGradeAttributeDesc make_pbmsg(){ return ::proto_ff::E_CloakGradeAttributeDesc(); }
	};
	typedef struct E_CloakGradeAttributeDesc_s E_CloakGradeAttributeDesc_t;

	struct E_CloakGrade_s : public NFDescStoreSeqOP {
		E_CloakGrade_s();
		virtual ~E_CloakGrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_cloakId;//披风id
		int32_t m_quality;//升品品质
		NFShmVector<struct E_CloakGradeItemDesc_s, DEFINE_E_CLOAKGRADE_M_ITEM_MAX_NUM> m_item;//升品道具
		NFShmVector<struct E_CloakGradeAttributeDesc_s, DEFINE_E_CLOAKGRADE_M_ATTRIBUTE_MAX_NUM> m_attribute;//升品属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGrade & msg);
		static ::proto_ff::E_CloakGrade* new_pbmsg(){ return new ::proto_ff::E_CloakGrade(); }
		static ::proto_ff::E_CloakGrade make_pbmsg(){ return ::proto_ff::E_CloakGrade(); }
	};
	typedef struct E_CloakGrade_s E_CloakGrade_t;

	struct Sheet_CloakGrade_s : public NFDescStoreSeqOP {
		Sheet_CloakGrade_s();
		virtual ~Sheet_CloakGrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakGrade_s, DEFINE_SHEET_CLOAKGRADE_E_CLOAKGRADE_LIST_MAX_NUM> E_CloakGrade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakGrade & msg);
		static ::proto_ff::Sheet_CloakGrade* new_pbmsg(){ return new ::proto_ff::Sheet_CloakGrade(); }
		static ::proto_ff::Sheet_CloakGrade make_pbmsg(){ return ::proto_ff::Sheet_CloakGrade(); }
	};
	typedef struct Sheet_CloakGrade_s Sheet_CloakGrade_t;

	struct E_CloakGodItemDesc_s : public NFDescStoreSeqOP {
		E_CloakGodItemDesc_s();
		virtual ~E_CloakGodItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_CloakGodItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGodItemDesc & msg);
		static ::proto_ff::E_CloakGodItemDesc* new_pbmsg(){ return new ::proto_ff::E_CloakGodItemDesc(); }
		static ::proto_ff::E_CloakGodItemDesc make_pbmsg(){ return ::proto_ff::E_CloakGodItemDesc(); }
	};
	typedef struct E_CloakGodItemDesc_s E_CloakGodItemDesc_t;

	struct E_CloakGodAttributeDesc_s : public NFDescStoreSeqOP {
		E_CloakGodAttributeDesc_s();
		virtual ~E_CloakGodAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_vlue;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_CloakGodAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGodAttributeDesc & msg);
		static ::proto_ff::E_CloakGodAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CloakGodAttributeDesc(); }
		static ::proto_ff::E_CloakGodAttributeDesc make_pbmsg(){ return ::proto_ff::E_CloakGodAttributeDesc(); }
	};
	typedef struct E_CloakGodAttributeDesc_s E_CloakGodAttributeDesc_t;

	struct E_CloakGod_s : public NFDescStoreSeqOP {
		E_CloakGod_s();
		virtual ~E_CloakGod_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_cloakId;//披风id
		int32_t m_skill;//激活技能
		NFShmVector<struct E_CloakGodItemDesc_s, DEFINE_E_CLOAKGOD_M_ITEM_MAX_NUM> m_item;//化神道具
		NFShmVector<struct E_CloakGodAttributeDesc_s, DEFINE_E_CLOAKGOD_M_ATTRIBUTE_MAX_NUM> m_attribute;//化神属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakGod & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakGod & msg);
		static ::proto_ff::E_CloakGod* new_pbmsg(){ return new ::proto_ff::E_CloakGod(); }
		static ::proto_ff::E_CloakGod make_pbmsg(){ return ::proto_ff::E_CloakGod(); }
	};
	typedef struct E_CloakGod_s E_CloakGod_t;

	struct Sheet_CloakGod_s : public NFDescStoreSeqOP {
		Sheet_CloakGod_s();
		virtual ~Sheet_CloakGod_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakGod_s, DEFINE_SHEET_CLOAKGOD_E_CLOAKGOD_LIST_MAX_NUM> E_CloakGod_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakGod & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakGod & msg);
		static ::proto_ff::Sheet_CloakGod* new_pbmsg(){ return new ::proto_ff::Sheet_CloakGod(); }
		static ::proto_ff::Sheet_CloakGod make_pbmsg(){ return ::proto_ff::Sheet_CloakGod(); }
	};
	typedef struct Sheet_CloakGod_s Sheet_CloakGod_t;

	struct E_CloakSoulAttributeDesc_s : public NFDescStoreSeqOP {
		E_CloakSoulAttributeDesc_s();
		virtual ~E_CloakSoulAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoulAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoulAttributeDesc & msg);
		static ::proto_ff::E_CloakSoulAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CloakSoulAttributeDesc(); }
		static ::proto_ff::E_CloakSoulAttributeDesc make_pbmsg(){ return ::proto_ff::E_CloakSoulAttributeDesc(); }
	};
	typedef struct E_CloakSoulAttributeDesc_s E_CloakSoulAttributeDesc_t;

	struct E_CloakSoul_s : public NFDescStoreSeqOP {
		E_CloakSoul_s();
		virtual ~E_CloakSoul_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//器魂ID
		int32_t m_rechargeID;//价格计费点
		int32_t m_mainSkill;//主技能ID
		NFShmString<64> m_attributeType;//升级属性类型
		int32_t m_itemId;//重置货币id
		int32_t m_itemNum;//重置货币数量
		NFShmVector<int32_t, DEFINE_E_CLOAKSOUL_M_MINORSKILL_MAX_NUM> m_minorSkill;//副技能ID
		NFShmVector<struct E_CloakSoulAttributeDesc_s, DEFINE_E_CLOAKSOUL_M_ATTRIBUTE_MAX_NUM> m_attribute;//激活基础属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoul & msg);
		static ::proto_ff::E_CloakSoul* new_pbmsg(){ return new ::proto_ff::E_CloakSoul(); }
		static ::proto_ff::E_CloakSoul make_pbmsg(){ return ::proto_ff::E_CloakSoul(); }
	};
	typedef struct E_CloakSoul_s E_CloakSoul_t;

	struct Sheet_CloakSoul_s : public NFDescStoreSeqOP {
		Sheet_CloakSoul_s();
		virtual ~Sheet_CloakSoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakSoul_s, DEFINE_SHEET_CLOAKSOUL_E_CLOAKSOUL_LIST_MAX_NUM> E_CloakSoul_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakSoul & msg);
		static ::proto_ff::Sheet_CloakSoul* new_pbmsg(){ return new ::proto_ff::Sheet_CloakSoul(); }
		static ::proto_ff::Sheet_CloakSoul make_pbmsg(){ return ::proto_ff::Sheet_CloakSoul(); }
	};
	typedef struct Sheet_CloakSoul_s Sheet_CloakSoul_t;

	struct E_CloakSoulactiveUnlockDesc_s : public NFDescStoreSeqOP {
		E_CloakSoulactiveUnlockDesc_s();
		virtual ~E_CloakSoulactiveUnlockDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_parama;//参数
		int32_t m_condition;//条件

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoulactiveUnlockDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoulactiveUnlockDesc & msg);
		static ::proto_ff::E_CloakSoulactiveUnlockDesc* new_pbmsg(){ return new ::proto_ff::E_CloakSoulactiveUnlockDesc(); }
		static ::proto_ff::E_CloakSoulactiveUnlockDesc make_pbmsg(){ return ::proto_ff::E_CloakSoulactiveUnlockDesc(); }
	};
	typedef struct E_CloakSoulactiveUnlockDesc_s E_CloakSoulactiveUnlockDesc_t;

	struct E_CloakSoulactive_s : public NFDescStoreSeqOP {
		E_CloakSoulactive_s();
		virtual ~E_CloakSoulactive_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//技能ID
		NFShmVector<struct E_CloakSoulactiveUnlockDesc_s, DEFINE_E_CLOAKSOULACTIVE_M_UNLOCK_MAX_NUM> m_unlock;//解锁

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoulactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoulactive & msg);
		static ::proto_ff::E_CloakSoulactive* new_pbmsg(){ return new ::proto_ff::E_CloakSoulactive(); }
		static ::proto_ff::E_CloakSoulactive make_pbmsg(){ return ::proto_ff::E_CloakSoulactive(); }
	};
	typedef struct E_CloakSoulactive_s E_CloakSoulactive_t;

	struct Sheet_CloakSoulactive_s : public NFDescStoreSeqOP {
		Sheet_CloakSoulactive_s();
		virtual ~Sheet_CloakSoulactive_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakSoulactive_s, DEFINE_SHEET_CLOAKSOULACTIVE_E_CLOAKSOULACTIVE_LIST_MAX_NUM> E_CloakSoulactive_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakSoulactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulactive & msg);
		static ::proto_ff::Sheet_CloakSoulactive* new_pbmsg(){ return new ::proto_ff::Sheet_CloakSoulactive(); }
		static ::proto_ff::Sheet_CloakSoulactive make_pbmsg(){ return ::proto_ff::Sheet_CloakSoulactive(); }
	};
	typedef struct Sheet_CloakSoulactive_s Sheet_CloakSoulactive_t;

	struct E_CloakSoullvAttributeDesc_s : public NFDescStoreSeqOP {
		E_CloakSoullvAttributeDesc_s();
		virtual ~E_CloakSoullvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoullvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoullvAttributeDesc & msg);
		static ::proto_ff::E_CloakSoullvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CloakSoullvAttributeDesc(); }
		static ::proto_ff::E_CloakSoullvAttributeDesc make_pbmsg(){ return ::proto_ff::E_CloakSoullvAttributeDesc(); }
	};
	typedef struct E_CloakSoullvAttributeDesc_s E_CloakSoullvAttributeDesc_t;

	struct E_CloakSoullv_s : public NFDescStoreSeqOP {
		E_CloakSoullv_s();
		virtual ~E_CloakSoullv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_soullLv;//等级
		int32_t m_itemID;//消耗道具
		int32_t m_num;//消耗数量
		int32_t m_successRate;//升级成功率
		int32_t m_downLv;//是否掉级
		NFShmVector<struct E_CloakSoullvAttributeDesc_s, DEFINE_E_CLOAKSOULLV_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoullv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoullv & msg);
		static ::proto_ff::E_CloakSoullv* new_pbmsg(){ return new ::proto_ff::E_CloakSoullv(); }
		static ::proto_ff::E_CloakSoullv make_pbmsg(){ return ::proto_ff::E_CloakSoullv(); }
	};
	typedef struct E_CloakSoullv_s E_CloakSoullv_t;

	struct Sheet_CloakSoullv_s : public NFDescStoreSeqOP {
		Sheet_CloakSoullv_s();
		virtual ~Sheet_CloakSoullv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakSoullv_s, DEFINE_SHEET_CLOAKSOULLV_E_CLOAKSOULLV_LIST_MAX_NUM> E_CloakSoullv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakSoullv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakSoullv & msg);
		static ::proto_ff::Sheet_CloakSoullv* new_pbmsg(){ return new ::proto_ff::Sheet_CloakSoullv(); }
		static ::proto_ff::Sheet_CloakSoullv make_pbmsg(){ return ::proto_ff::Sheet_CloakSoullv(); }
	};
	typedef struct Sheet_CloakSoullv_s Sheet_CloakSoullv_t;

	struct E_CloakSoulclear_s : public NFDescStoreSeqOP {
		E_CloakSoulclear_s();
		virtual ~E_CloakSoulclear_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_soullLv;//等级
		NFShmVector<int32_t, DEFINE_E_CLOAKSOULCLEAR_M_CLEARATT_MAX_NUM> m_clearAtt;//解锁属性

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoulclear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoulclear & msg);
		static ::proto_ff::E_CloakSoulclear* new_pbmsg(){ return new ::proto_ff::E_CloakSoulclear(); }
		static ::proto_ff::E_CloakSoulclear make_pbmsg(){ return ::proto_ff::E_CloakSoulclear(); }
	};
	typedef struct E_CloakSoulclear_s E_CloakSoulclear_t;

	struct Sheet_CloakSoulclear_s : public NFDescStoreSeqOP {
		Sheet_CloakSoulclear_s();
		virtual ~Sheet_CloakSoulclear_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakSoulclear_s, DEFINE_SHEET_CLOAKSOULCLEAR_E_CLOAKSOULCLEAR_LIST_MAX_NUM> E_CloakSoulclear_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakSoulclear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulclear & msg);
		static ::proto_ff::Sheet_CloakSoulclear* new_pbmsg(){ return new ::proto_ff::Sheet_CloakSoulclear(); }
		static ::proto_ff::Sheet_CloakSoulclear make_pbmsg(){ return ::proto_ff::Sheet_CloakSoulclear(); }
	};
	typedef struct Sheet_CloakSoulclear_s Sheet_CloakSoulclear_t;

	struct E_CloakSoulachievement_s : public NFDescStoreSeqOP {
		E_CloakSoulachievement_s();
		virtual ~E_CloakSoulachievement_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//成就id
		int32_t m_type;//类型
		int32_t m_parama;//影响值
		int32_t m_itemID;//奖励道具
		int32_t m_num;//奖励数量

		virtual void write_to_pbmsg(::proto_ff::E_CloakSoulachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CloakSoulachievement & msg);
		static ::proto_ff::E_CloakSoulachievement* new_pbmsg(){ return new ::proto_ff::E_CloakSoulachievement(); }
		static ::proto_ff::E_CloakSoulachievement make_pbmsg(){ return ::proto_ff::E_CloakSoulachievement(); }
	};
	typedef struct E_CloakSoulachievement_s E_CloakSoulachievement_t;

	struct Sheet_CloakSoulachievement_s : public NFDescStoreSeqOP {
		Sheet_CloakSoulachievement_s();
		virtual ~Sheet_CloakSoulachievement_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CloakSoulachievement_s, DEFINE_SHEET_CLOAKSOULACHIEVEMENT_E_CLOAKSOULACHIEVEMENT_LIST_MAX_NUM> E_CloakSoulachievement_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CloakSoulachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulachievement & msg);
		static ::proto_ff::Sheet_CloakSoulachievement* new_pbmsg(){ return new ::proto_ff::Sheet_CloakSoulachievement(); }
		static ::proto_ff::Sheet_CloakSoulachievement make_pbmsg(){ return ::proto_ff::Sheet_CloakSoulachievement(); }
	};
	typedef struct Sheet_CloakSoulachievement_s Sheet_CloakSoulachievement_t;

}

