#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Encyclopedia.pb.h"
#include "E_Encyclopedia_s.h"

#define DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_LVIATTRIBUTE_MAX_NUM 4
#define DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_AWAKESKILL_MAX_NUM 3
#define DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_STARIATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_ENCYCLOPEDIAHANDBOOK_E_ENCYCLOPEDIAHANDBOOK_LIST_MAX_NUM 512
#define DEFINE_E_ENCYCLOPEDIAHANDBOOKFATE_M_FATEHAND_MAX_NUM 4
#define DEFINE_E_ENCYCLOPEDIAHANDBOOKFATE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKFATE_E_ENCYCLOPEDIAHANDBOOKFATE_LIST_MAX_NUM 128
#define DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKRESOLVE_E_ENCYCLOPEDIAHANDBOOKRESOLVE_LIST_MAX_NUM 8
#define DEFINE_E_ENCYCLOPEDIAHANDBOOKLV_ATTR_M_ATT_MAX_NUM 100
#define DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKLV_ATTR_E_ENCYCLOPEDIAHANDBOOKLV_ATTR_LIST_MAX_NUM 256
#define DEFINE_E_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_M_ATT_MAX_NUM 20
#define DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_E_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_LIST_MAX_NUM 256
#define DEFINE_E_ENCYCLOPEDIABEAST_M_POS_MAX_NUM 5
#define DEFINE_E_ENCYCLOPEDIABEAST_M_BEAST_MAX_NUM 6
#define DEFINE_E_ENCYCLOPEDIABEAST_M_SKILL_MAX_NUM 3
#define DEFINE_SHEET_ENCYCLOPEDIABEAST_E_ENCYCLOPEDIABEAST_LIST_MAX_NUM 32
#define DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_BEASTSTAR_MAX_NUM 2
#define DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_GOLDSTAR_MAX_NUM 5
#define DEFINE_SHEET_ENCYCLOPEDIAEQUIPEXPVALUE_E_ENCYCLOPEDIAEQUIPEXPVALUE_LIST_MAX_NUM 64
#define DEFINE_SHEET_ENCYCLOPEDIABEASTEXPAND_E_ENCYCLOPEDIABEASTEXPAND_LIST_MAX_NUM 8
#define DEFINE_E_ENCYCLOPEDIABEASTPRIVILEGE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_ENCYCLOPEDIABEASTPRIVILEGE_E_ENCYCLOPEDIABEASTPRIVILEGE_LIST_MAX_NUM 4
#define DEFINE_SHEET_ENCYCLOPEDIABEASTEXP_E_ENCYCLOPEDIABEASTEXP_LIST_MAX_NUM 256
#define DEFINE_E_ENCYCLOPEDIAEMPLOY_M_LVIATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_ENCYCLOPEDIAEMPLOY_E_ENCYCLOPEDIAEMPLOY_LIST_MAX_NUM 128
#define DEFINE_E_ENCYCLOPEDIATABLE_M_LVIATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_ENCYCLOPEDIATABLE_E_ENCYCLOPEDIATABLE_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_EncyclopediaHandbookLviattributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookLviattributeDesc_s();
		virtual ~E_EncyclopediaHandbookLviattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookLviattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookLviattributeDesc & msg);
		static ::proto_ff::E_EncyclopediaHandbookLviattributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookLviattributeDesc(); }
		static ::proto_ff::E_EncyclopediaHandbookLviattributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookLviattributeDesc(); }
	};
	typedef struct E_EncyclopediaHandbookLviattributeDesc_s E_EncyclopediaHandbookLviattributeDesc_t;

	struct E_EncyclopediaHandbookStariattributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookStariattributeDesc_s();
		virtual ~E_EncyclopediaHandbookStariattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookStariattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookStariattributeDesc & msg);
		static ::proto_ff::E_EncyclopediaHandbookStariattributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookStariattributeDesc(); }
		static ::proto_ff::E_EncyclopediaHandbookStariattributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookStariattributeDesc(); }
	};
	typedef struct E_EncyclopediaHandbookStariattributeDesc_s E_EncyclopediaHandbookStariattributeDesc_t;

	struct E_EncyclopediaHandbook_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbook_s();
		virtual ~E_EncyclopediaHandbook_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_handbookID;//图鉴id
		int64_t m_itemId;//关联物品id
		NFShmString<64> m_handbookName;//图鉴名称
		int32_t m_handbookQuality;//图鉴品质
		int32_t m_handbookType;//图鉴类型
		NFShmString<64> m_handbookType_name;//图鉴类型名称
		int32_t m_handZ;//图鉴组
		NFShmString<64> m_handZName;//图鉴组名称
		int32_t m_handbookLv;//图鉴等级上限
		int64_t m_LvId;//升级道具id
		NFShmString<256> m_LvNum;//升级道具数量
		int64_t m_starId;//升星道具id
		NFShmString<64> m_starNum;//升星道具数量
		NFShmVector<struct E_EncyclopediaHandbookLviattributeDesc_s, DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_LVIATTRIBUTE_MAX_NUM> m_LvIattribute;//属性
		NFShmVector<int32_t, DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_AWAKESKILL_MAX_NUM> m_awakeSkill;//技能
		NFShmVector<struct E_EncyclopediaHandbookStariattributeDesc_s, DEFINE_E_ENCYCLOPEDIAHANDBOOK_M_STARIATTRIBUTE_MAX_NUM> m_starIattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbook & msg);
		static ::proto_ff::E_EncyclopediaHandbook* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbook(); }
		static ::proto_ff::E_EncyclopediaHandbook make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbook(); }
	};
	typedef struct E_EncyclopediaHandbook_s E_EncyclopediaHandbook_t;

	struct Sheet_EncyclopediaHandbook_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaHandbook_s();
		virtual ~Sheet_EncyclopediaHandbook_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaHandbook_s, DEFINE_SHEET_ENCYCLOPEDIAHANDBOOK_E_ENCYCLOPEDIAHANDBOOK_LIST_MAX_NUM> E_EncyclopediaHandbook_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbook & msg);
		static ::proto_ff::Sheet_EncyclopediaHandbook* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaHandbook(); }
		static ::proto_ff::Sheet_EncyclopediaHandbook make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaHandbook(); }
	};
	typedef struct Sheet_EncyclopediaHandbook_s Sheet_EncyclopediaHandbook_t;

	struct E_EncyclopediaHandbookfateAttributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookfateAttributeDesc_s();
		virtual ~E_EncyclopediaHandbookfateAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookfateAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc & msg);
		static ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc(); }
		static ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc(); }
	};
	typedef struct E_EncyclopediaHandbookfateAttributeDesc_s E_EncyclopediaHandbookfateAttributeDesc_t;

	struct E_EncyclopediaHandbookfate_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookfate_s();
		virtual ~E_EncyclopediaHandbookfate_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fateID;//羁绊id
		NFShmString<64> m_fateName;//羁绊名称
		int32_t m_fateQuality;//羁绊品质
		NFShmVector<int64_t, DEFINE_E_ENCYCLOPEDIAHANDBOOKFATE_M_FATEHAND_MAX_NUM> m_fateHand;//羁绊图鉴
		NFShmVector<struct E_EncyclopediaHandbookfateAttributeDesc_s, DEFINE_E_ENCYCLOPEDIAHANDBOOKFATE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookfate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookfate & msg);
		static ::proto_ff::E_EncyclopediaHandbookfate* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookfate(); }
		static ::proto_ff::E_EncyclopediaHandbookfate make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookfate(); }
	};
	typedef struct E_EncyclopediaHandbookfate_s E_EncyclopediaHandbookfate_t;

	struct Sheet_EncyclopediaHandbookfate_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaHandbookfate_s();
		virtual ~Sheet_EncyclopediaHandbookfate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaHandbookfate_s, DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKFATE_E_ENCYCLOPEDIAHANDBOOKFATE_LIST_MAX_NUM> E_EncyclopediaHandbookfate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookfate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookfate & msg);
		static ::proto_ff::Sheet_EncyclopediaHandbookfate* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaHandbookfate(); }
		static ::proto_ff::Sheet_EncyclopediaHandbookfate make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaHandbookfate(); }
	};
	typedef struct Sheet_EncyclopediaHandbookfate_s Sheet_EncyclopediaHandbookfate_t;

	struct E_EncyclopediaHandbookresolve_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookresolve_s();
		virtual ~E_EncyclopediaHandbookresolve_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_handbookQuality;//图鉴道具品质
		int32_t m_resolveItem;//分解道具
		int32_t m_resolveNum;//分解数量

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookresolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookresolve & msg);
		static ::proto_ff::E_EncyclopediaHandbookresolve* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookresolve(); }
		static ::proto_ff::E_EncyclopediaHandbookresolve make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookresolve(); }
	};
	typedef struct E_EncyclopediaHandbookresolve_s E_EncyclopediaHandbookresolve_t;

	struct Sheet_EncyclopediaHandbookresolve_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaHandbookresolve_s();
		virtual ~Sheet_EncyclopediaHandbookresolve_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaHandbookresolve_s, DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKRESOLVE_E_ENCYCLOPEDIAHANDBOOKRESOLVE_LIST_MAX_NUM> E_EncyclopediaHandbookresolve_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookresolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookresolve & msg);
		static ::proto_ff::Sheet_EncyclopediaHandbookresolve* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaHandbookresolve(); }
		static ::proto_ff::Sheet_EncyclopediaHandbookresolve make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaHandbookresolve(); }
	};
	typedef struct Sheet_EncyclopediaHandbookresolve_s Sheet_EncyclopediaHandbookresolve_t;

	struct E_EncyclopediaHandbooklv_attr_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbooklv_attr_s();
		virtual ~E_EncyclopediaHandbooklv_attr_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attID;//属性组id
		NFShmVector<int32_t, DEFINE_E_ENCYCLOPEDIAHANDBOOKLV_ATTR_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbooklv_attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbooklv_attr & msg);
		static ::proto_ff::E_EncyclopediaHandbooklv_attr* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbooklv_attr(); }
		static ::proto_ff::E_EncyclopediaHandbooklv_attr make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbooklv_attr(); }
	};
	typedef struct E_EncyclopediaHandbooklv_attr_s E_EncyclopediaHandbooklv_attr_t;

	struct Sheet_EncyclopediaHandbooklv_attr_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaHandbooklv_attr_s();
		virtual ~Sheet_EncyclopediaHandbooklv_attr_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaHandbooklv_attr_s, DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKLV_ATTR_E_ENCYCLOPEDIAHANDBOOKLV_ATTR_LIST_MAX_NUM> E_EncyclopediaHandbooklv_attr_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbooklv_attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbooklv_attr & msg);
		static ::proto_ff::Sheet_EncyclopediaHandbooklv_attr* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaHandbooklv_attr(); }
		static ::proto_ff::Sheet_EncyclopediaHandbooklv_attr make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaHandbooklv_attr(); }
	};
	typedef struct Sheet_EncyclopediaHandbooklv_attr_s Sheet_EncyclopediaHandbooklv_attr_t;

	struct E_EncyclopediaHandbookstar_attr_s : public NFDescStoreSeqOP {
		E_EncyclopediaHandbookstar_attr_s();
		virtual ~E_EncyclopediaHandbookstar_attr_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attID;//属性组id
		NFShmVector<int32_t, DEFINE_E_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookstar_attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookstar_attr & msg);
		static ::proto_ff::E_EncyclopediaHandbookstar_attr* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaHandbookstar_attr(); }
		static ::proto_ff::E_EncyclopediaHandbookstar_attr make_pbmsg(){ return ::proto_ff::E_EncyclopediaHandbookstar_attr(); }
	};
	typedef struct E_EncyclopediaHandbookstar_attr_s E_EncyclopediaHandbookstar_attr_t;

	struct Sheet_EncyclopediaHandbookstar_attr_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaHandbookstar_attr_s();
		virtual ~Sheet_EncyclopediaHandbookstar_attr_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaHandbookstar_attr_s, DEFINE_SHEET_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_E_ENCYCLOPEDIAHANDBOOKSTAR_ATTR_LIST_MAX_NUM> E_EncyclopediaHandbookstar_attr_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookstar_attr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookstar_attr & msg);
		static ::proto_ff::Sheet_EncyclopediaHandbookstar_attr* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaHandbookstar_attr(); }
		static ::proto_ff::Sheet_EncyclopediaHandbookstar_attr make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaHandbookstar_attr(); }
	};
	typedef struct Sheet_EncyclopediaHandbookstar_attr_s Sheet_EncyclopediaHandbookstar_attr_t;

	struct E_EncyclopediaBeastBeastDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeastBeastDesc_s();
		virtual ~E_EncyclopediaBeastBeastDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//值
		int32_t m_att;//Id

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeastBeastDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastBeastDesc & msg);
		static ::proto_ff::E_EncyclopediaBeastBeastDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeastBeastDesc(); }
		static ::proto_ff::E_EncyclopediaBeastBeastDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeastBeastDesc(); }
	};
	typedef struct E_EncyclopediaBeastBeastDesc_s E_EncyclopediaBeastBeastDesc_t;

	struct E_EncyclopediaBeast_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeast_s();
		virtual ~E_EncyclopediaBeast_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//神兽ID
		NFShmString<64> m_name;//神兽名称
		NFShmVector<int32_t, DEFINE_E_ENCYCLOPEDIABEAST_M_POS_MAX_NUM> m_pos;//品质
		NFShmVector<struct E_EncyclopediaBeastBeastDesc_s, DEFINE_E_ENCYCLOPEDIABEAST_M_BEAST_MAX_NUM> m_beast;//神兽属性
		NFShmVector<int64_t, DEFINE_E_ENCYCLOPEDIABEAST_M_SKILL_MAX_NUM> m_skill;//神兽技能

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeast & msg);
		static ::proto_ff::E_EncyclopediaBeast* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeast(); }
		static ::proto_ff::E_EncyclopediaBeast make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeast(); }
	};
	typedef struct E_EncyclopediaBeast_s E_EncyclopediaBeast_t;

	struct Sheet_EncyclopediaBeast_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaBeast_s();
		virtual ~Sheet_EncyclopediaBeast_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaBeast_s, DEFINE_SHEET_ENCYCLOPEDIABEAST_E_ENCYCLOPEDIABEAST_LIST_MAX_NUM> E_EncyclopediaBeast_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeast & msg);
		static ::proto_ff::Sheet_EncyclopediaBeast* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaBeast(); }
		static ::proto_ff::Sheet_EncyclopediaBeast make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaBeast(); }
	};
	typedef struct Sheet_EncyclopediaBeast_s Sheet_EncyclopediaBeast_t;

	struct E_EncyclopediaEquipexpvalueBeaststarDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaEquipexpvalueBeaststarDesc_s();
		virtual ~E_EncyclopediaEquipexpvalueBeaststarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//值
		int32_t m_att;//

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc & msg);
		static ::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc(); }
		static ::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaEquipexpvalueBeaststarDesc(); }
	};
	typedef struct E_EncyclopediaEquipexpvalueBeaststarDesc_s E_EncyclopediaEquipexpvalueBeaststarDesc_t;

	struct E_EncyclopediaEquipexpvalueGoldstarDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaEquipexpvalueGoldstarDesc_s();
		virtual ~E_EncyclopediaEquipexpvalueGoldstarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//值
		int32_t m_att;//

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc & msg);
		static ::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc(); }
		static ::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaEquipexpvalueGoldstarDesc(); }
	};
	typedef struct E_EncyclopediaEquipexpvalueGoldstarDesc_s E_EncyclopediaEquipexpvalueGoldstarDesc_t;

	struct E_EncyclopediaEquipexpvalue_s : public NFDescStoreSeqOP {
		E_EncyclopediaEquipexpvalue_s();
		virtual ~E_EncyclopediaEquipexpvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//材料ID
		int64_t m_type;//材料类型
		NFShmString<64> m_name;//材料名称
		int32_t m_exp;//初始经验
		int64_t m_link;//来源
		int32_t m_goldAttAll;//仙品共条数
		int32_t m_goldAtt;//黄星属性条数
		NFShmVector<struct E_EncyclopediaEquipexpvalueBeaststarDesc_s, DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_BEASTSTAR_MAX_NUM> m_beastStar;//蓝星属性
		NFShmVector<struct E_EncyclopediaEquipexpvalueGoldstarDesc_s, DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_GOLDSTAR_MAX_NUM> m_goldStar;//黄星属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaEquipexpvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaEquipexpvalue & msg);
		static ::proto_ff::E_EncyclopediaEquipexpvalue* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaEquipexpvalue(); }
		static ::proto_ff::E_EncyclopediaEquipexpvalue make_pbmsg(){ return ::proto_ff::E_EncyclopediaEquipexpvalue(); }
	};
	typedef struct E_EncyclopediaEquipexpvalue_s E_EncyclopediaEquipexpvalue_t;

	struct Sheet_EncyclopediaEquipexpvalue_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaEquipexpvalue_s();
		virtual ~Sheet_EncyclopediaEquipexpvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaEquipexpvalue_s, DEFINE_SHEET_ENCYCLOPEDIAEQUIPEXPVALUE_E_ENCYCLOPEDIAEQUIPEXPVALUE_LIST_MAX_NUM> E_EncyclopediaEquipexpvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaEquipexpvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaEquipexpvalue & msg);
		static ::proto_ff::Sheet_EncyclopediaEquipexpvalue* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaEquipexpvalue(); }
		static ::proto_ff::Sheet_EncyclopediaEquipexpvalue make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaEquipexpvalue(); }
	};
	typedef struct Sheet_EncyclopediaEquipexpvalue_s Sheet_EncyclopediaEquipexpvalue_t;

	struct E_EncyclopediaBeastexpand_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeastexpand_s();
		virtual ~E_EncyclopediaBeastexpand_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_number;//激活个数
		int32_t m_lv;//激活等级
		int64_t m_id;//激活道具id
		int32_t m_num;//激活道具数量

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeastexpand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastexpand & msg);
		static ::proto_ff::E_EncyclopediaBeastexpand* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeastexpand(); }
		static ::proto_ff::E_EncyclopediaBeastexpand make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeastexpand(); }
	};
	typedef struct E_EncyclopediaBeastexpand_s E_EncyclopediaBeastexpand_t;

	struct Sheet_EncyclopediaBeastexpand_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaBeastexpand_s();
		virtual ~Sheet_EncyclopediaBeastexpand_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaBeastexpand_s, DEFINE_SHEET_ENCYCLOPEDIABEASTEXPAND_E_ENCYCLOPEDIABEASTEXPAND_LIST_MAX_NUM> E_EncyclopediaBeastexpand_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastexpand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastexpand & msg);
		static ::proto_ff::Sheet_EncyclopediaBeastexpand* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaBeastexpand(); }
		static ::proto_ff::Sheet_EncyclopediaBeastexpand make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaBeastexpand(); }
	};
	typedef struct Sheet_EncyclopediaBeastexpand_s Sheet_EncyclopediaBeastexpand_t;

	struct E_EncyclopediaBeastprivilegeAttributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeastprivilegeAttributeDesc_s();
		virtual ~E_EncyclopediaBeastprivilegeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc & msg);
		static ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc(); }
		static ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc(); }
	};
	typedef struct E_EncyclopediaBeastprivilegeAttributeDesc_s E_EncyclopediaBeastprivilegeAttributeDesc_t;

	struct E_EncyclopediaBeastprivilege_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeastprivilege_s();
		virtual ~E_EncyclopediaBeastprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_privilegeType;//特权类型
		NFShmString<64> m_name;//名字
		int32_t m_price;//价格链接
		int64_t m_expAddition;//经验值加成
		NFShmVector<struct E_EncyclopediaBeastprivilegeAttributeDesc_s, DEFINE_E_ENCYCLOPEDIABEASTPRIVILEGE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeastprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastprivilege & msg);
		static ::proto_ff::E_EncyclopediaBeastprivilege* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeastprivilege(); }
		static ::proto_ff::E_EncyclopediaBeastprivilege make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeastprivilege(); }
	};
	typedef struct E_EncyclopediaBeastprivilege_s E_EncyclopediaBeastprivilege_t;

	struct Sheet_EncyclopediaBeastprivilege_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaBeastprivilege_s();
		virtual ~Sheet_EncyclopediaBeastprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaBeastprivilege_s, DEFINE_SHEET_ENCYCLOPEDIABEASTPRIVILEGE_E_ENCYCLOPEDIABEASTPRIVILEGE_LIST_MAX_NUM> E_EncyclopediaBeastprivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastprivilege & msg);
		static ::proto_ff::Sheet_EncyclopediaBeastprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaBeastprivilege(); }
		static ::proto_ff::Sheet_EncyclopediaBeastprivilege make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaBeastprivilege(); }
	};
	typedef struct Sheet_EncyclopediaBeastprivilege_s Sheet_EncyclopediaBeastprivilege_t;

	struct E_EncyclopediaBeastexp_s : public NFDescStoreSeqOP {
		E_EncyclopediaBeastexp_s();
		virtual ~E_EncyclopediaBeastexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaBeastexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastexp & msg);
		static ::proto_ff::E_EncyclopediaBeastexp* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaBeastexp(); }
		static ::proto_ff::E_EncyclopediaBeastexp make_pbmsg(){ return ::proto_ff::E_EncyclopediaBeastexp(); }
	};
	typedef struct E_EncyclopediaBeastexp_s E_EncyclopediaBeastexp_t;

	struct Sheet_EncyclopediaBeastexp_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaBeastexp_s();
		virtual ~Sheet_EncyclopediaBeastexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaBeastexp_s, DEFINE_SHEET_ENCYCLOPEDIABEASTEXP_E_ENCYCLOPEDIABEASTEXP_LIST_MAX_NUM> E_EncyclopediaBeastexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastexp & msg);
		static ::proto_ff::Sheet_EncyclopediaBeastexp* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaBeastexp(); }
		static ::proto_ff::Sheet_EncyclopediaBeastexp make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaBeastexp(); }
	};
	typedef struct Sheet_EncyclopediaBeastexp_s Sheet_EncyclopediaBeastexp_t;

	struct E_EncyclopediaEmployLviattributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaEmployLviattributeDesc_s();
		virtual ~E_EncyclopediaEmployLviattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaEmployLviattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaEmployLviattributeDesc & msg);
		static ::proto_ff::E_EncyclopediaEmployLviattributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaEmployLviattributeDesc(); }
		static ::proto_ff::E_EncyclopediaEmployLviattributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaEmployLviattributeDesc(); }
	};
	typedef struct E_EncyclopediaEmployLviattributeDesc_s E_EncyclopediaEmployLviattributeDesc_t;

	struct E_EncyclopediaEmploy_s : public NFDescStoreSeqOP {
		E_EncyclopediaEmploy_s();
		virtual ~E_EncyclopediaEmploy_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_employID;//收录id
		int64_t m_type;//激活类型
		int64_t m_itemId;//激活条件
		NFShmString<64> m_employName;//收录名称
		int32_t m_employQuality;//收录品质
		int32_t m_employType;//收录类型
		NFShmString<64> m_employType_name;//收录类型名称
		int32_t m_employZ;//收录组
		NFShmString<64> m_employZName;//收录组名称
		NFShmVector<struct E_EncyclopediaEmployLviattributeDesc_s, DEFINE_E_ENCYCLOPEDIAEMPLOY_M_LVIATTRIBUTE_MAX_NUM> m_LvIattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaEmploy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaEmploy & msg);
		static ::proto_ff::E_EncyclopediaEmploy* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaEmploy(); }
		static ::proto_ff::E_EncyclopediaEmploy make_pbmsg(){ return ::proto_ff::E_EncyclopediaEmploy(); }
	};
	typedef struct E_EncyclopediaEmploy_s E_EncyclopediaEmploy_t;

	struct Sheet_EncyclopediaEmploy_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaEmploy_s();
		virtual ~Sheet_EncyclopediaEmploy_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaEmploy_s, DEFINE_SHEET_ENCYCLOPEDIAEMPLOY_E_ENCYCLOPEDIAEMPLOY_LIST_MAX_NUM> E_EncyclopediaEmploy_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaEmploy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaEmploy & msg);
		static ::proto_ff::Sheet_EncyclopediaEmploy* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaEmploy(); }
		static ::proto_ff::Sheet_EncyclopediaEmploy make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaEmploy(); }
	};
	typedef struct Sheet_EncyclopediaEmploy_s Sheet_EncyclopediaEmploy_t;

	struct E_EncyclopediaTableLviattributeDesc_s : public NFDescStoreSeqOP {
		E_EncyclopediaTableLviattributeDesc_s();
		virtual ~E_EncyclopediaTableLviattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaTableLviattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaTableLviattributeDesc & msg);
		static ::proto_ff::E_EncyclopediaTableLviattributeDesc* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaTableLviattributeDesc(); }
		static ::proto_ff::E_EncyclopediaTableLviattributeDesc make_pbmsg(){ return ::proto_ff::E_EncyclopediaTableLviattributeDesc(); }
	};
	typedef struct E_EncyclopediaTableLviattributeDesc_s E_EncyclopediaTableLviattributeDesc_t;

	struct E_EncyclopediaTable_s : public NFDescStoreSeqOP {
		E_EncyclopediaTable_s();
		virtual ~E_EncyclopediaTable_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//id
		int64_t m_tableid;//天机谱id
		NFShmString<64> m_tableName;//天机谱名称
		NFShmVector<struct E_EncyclopediaTableLviattributeDesc_s, DEFINE_E_ENCYCLOPEDIATABLE_M_LVIATTRIBUTE_MAX_NUM> m_LvIattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EncyclopediaTable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EncyclopediaTable & msg);
		static ::proto_ff::E_EncyclopediaTable* new_pbmsg(){ return new ::proto_ff::E_EncyclopediaTable(); }
		static ::proto_ff::E_EncyclopediaTable make_pbmsg(){ return ::proto_ff::E_EncyclopediaTable(); }
	};
	typedef struct E_EncyclopediaTable_s E_EncyclopediaTable_t;

	struct Sheet_EncyclopediaTable_s : public NFDescStoreSeqOP {
		Sheet_EncyclopediaTable_s();
		virtual ~Sheet_EncyclopediaTable_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EncyclopediaTable_s, DEFINE_SHEET_ENCYCLOPEDIATABLE_E_ENCYCLOPEDIATABLE_LIST_MAX_NUM> E_EncyclopediaTable_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EncyclopediaTable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaTable & msg);
		static ::proto_ff::Sheet_EncyclopediaTable* new_pbmsg(){ return new ::proto_ff::Sheet_EncyclopediaTable(); }
		static ::proto_ff::Sheet_EncyclopediaTable make_pbmsg(){ return ::proto_ff::Sheet_EncyclopediaTable(); }
	};
	typedef struct Sheet_EncyclopediaTable_s Sheet_EncyclopediaTable_t;

}

