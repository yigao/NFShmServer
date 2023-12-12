#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Conflate.pb.h"
#include "E_Conflate_s.h"

#define DEFINE_E_CONFLATEEQUIP_M_ELEM_MAX_NUM 3
#define DEFINE_SHEET_CONFLATEEQUIP_E_CONFLATEEQUIP_LIST_MAX_NUM 2048
#define DEFINE_SHEET_CONFLATEGROUPTYPE_E_CONFLATEGROUPTYPE_LIST_MAX_NUM 64
#define DEFINE_SHEET_CONFLATESUBTYPE_E_CONFLATESUBTYPE_LIST_MAX_NUM 128
#define DEFINE_E_CONFLATEPROP_M_REPLACE_MAX_NUM 2
#define DEFINE_E_CONFLATEPROP_M_ELEM_MAX_NUM 4
#define DEFINE_SHEET_CONFLATEPROP_E_CONFLATEPROP_LIST_MAX_NUM 512
#define DEFINE_E_CONFLATEJEWELRY_SP_M_ELEM_MAX_NUM 4
#define DEFINE_SHEET_CONFLATEJEWELRY_SP_E_CONFLATEJEWELRY_SP_LIST_MAX_NUM 32
#define DEFINE_E_CONFLATEJEWELRY_ZL_M_ELEM_MAX_NUM 4
#define DEFINE_SHEET_CONFLATEJEWELRY_ZL_E_CONFLATEJEWELRY_ZL_LIST_MAX_NUM 64
#define DEFINE_E_CONFLATEJEWELRY_SJ_M_ELEM_MAX_NUM 4
#define DEFINE_SHEET_CONFLATEJEWELRY_SJ_E_CONFLATEJEWELRY_SJ_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_ConflateEquipElemDesc_s : public NFDescStoreSeqOP {
		E_ConflateEquipElemDesc_s();
		virtual ~E_ConflateEquipElemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ConflateEquipElemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateEquipElemDesc & msg);
		static ::proto_ff::E_ConflateEquipElemDesc* new_pbmsg(){ return new ::proto_ff::E_ConflateEquipElemDesc(); }
		static ::proto_ff::E_ConflateEquipElemDesc make_pbmsg(){ return ::proto_ff::E_ConflateEquipElemDesc(); }
	};
	typedef struct E_ConflateEquipElemDesc_s E_ConflateEquipElemDesc_t;

	struct E_ConflateEquip_s : public NFDescStoreSeqOP {
		E_ConflateEquip_s();
		virtual ~E_ConflateEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合成id
		int32_t m_openLv;//显示等级
		int32_t m_groupType;//装备类型
		int32_t m_subType;//装备组id
		int32_t m_needsameposition;//是否同部位
		int32_t m_star;//装备星级
		int32_t m_quality;//装备品质
		int32_t m_wearQuality;//装备品阶
		int32_t m_elemStar;//素材星级
		int32_t m_elemQuality;//素材品质
		int32_t m_elemWearQuality;//素材品阶
		int32_t m_minimum;//最小装备数量
		int32_t m_minisuccessrate;//最少装备成功率
		int32_t m_maxmum;//最大装备数量
		int32_t m_maxsuccessrate;//最大装备成功率
		int32_t m_mustStar;//同阶星级
		int32_t m_mustQuality;//同阶品质
		int32_t m_mustWearQuality;//同阶品阶
		int32_t m_mustNum;//同阶装备数量
		int32_t m_usemoney;//合成消耗货币
		int32_t m_cost;//货币数量
		NFShmVector<struct E_ConflateEquipElemDesc_s, DEFINE_E_CONFLATEEQUIP_M_ELEM_MAX_NUM> m_elem;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflateEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateEquip & msg);
		static ::proto_ff::E_ConflateEquip* new_pbmsg(){ return new ::proto_ff::E_ConflateEquip(); }
		static ::proto_ff::E_ConflateEquip make_pbmsg(){ return ::proto_ff::E_ConflateEquip(); }
	};
	typedef struct E_ConflateEquip_s E_ConflateEquip_t;

	struct Sheet_ConflateEquip_s : public NFDescStoreSeqOP {
		Sheet_ConflateEquip_s();
		virtual ~Sheet_ConflateEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateEquip_s, DEFINE_SHEET_CONFLATEEQUIP_E_CONFLATEEQUIP_LIST_MAX_NUM> E_ConflateEquip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateEquip & msg);
		static ::proto_ff::Sheet_ConflateEquip* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateEquip(); }
		static ::proto_ff::Sheet_ConflateEquip make_pbmsg(){ return ::proto_ff::Sheet_ConflateEquip(); }
	};
	typedef struct Sheet_ConflateEquip_s Sheet_ConflateEquip_t;

	struct E_ConflateGrouptype_s : public NFDescStoreSeqOP {
		E_ConflateGrouptype_s();
		virtual ~E_ConflateGrouptype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合成id
		NFShmString<64> m_position;//装备部位
		NFShmString<64> m_profession;//职业限制
		NFShmString<64> m_typeName;//类型名称
		int32_t m_unlockId;//开启条件
		int32_t m_entry;//入口id
		int32_t m_rule;//规则

		virtual void write_to_pbmsg(::proto_ff::E_ConflateGrouptype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateGrouptype & msg);
		static ::proto_ff::E_ConflateGrouptype* new_pbmsg(){ return new ::proto_ff::E_ConflateGrouptype(); }
		static ::proto_ff::E_ConflateGrouptype make_pbmsg(){ return ::proto_ff::E_ConflateGrouptype(); }
	};
	typedef struct E_ConflateGrouptype_s E_ConflateGrouptype_t;

	struct Sheet_ConflateGrouptype_s : public NFDescStoreSeqOP {
		Sheet_ConflateGrouptype_s();
		virtual ~Sheet_ConflateGrouptype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateGrouptype_s, DEFINE_SHEET_CONFLATEGROUPTYPE_E_CONFLATEGROUPTYPE_LIST_MAX_NUM> E_ConflateGrouptype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateGrouptype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateGrouptype & msg);
		static ::proto_ff::Sheet_ConflateGrouptype* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateGrouptype(); }
		static ::proto_ff::Sheet_ConflateGrouptype make_pbmsg(){ return ::proto_ff::Sheet_ConflateGrouptype(); }
	};
	typedef struct Sheet_ConflateGrouptype_s Sheet_ConflateGrouptype_t;

	struct E_ConflateSubtype_s : public NFDescStoreSeqOP {
		E_ConflateSubtype_s();
		virtual ~E_ConflateSubtype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//装备组id
		NFShmString<64> m_subName;//组名称
		int32_t m_groupid;//装备类型
		int32_t m_openLv;//显示等级

		virtual void write_to_pbmsg(::proto_ff::E_ConflateSubtype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateSubtype & msg);
		static ::proto_ff::E_ConflateSubtype* new_pbmsg(){ return new ::proto_ff::E_ConflateSubtype(); }
		static ::proto_ff::E_ConflateSubtype make_pbmsg(){ return ::proto_ff::E_ConflateSubtype(); }
	};
	typedef struct E_ConflateSubtype_s E_ConflateSubtype_t;

	struct Sheet_ConflateSubtype_s : public NFDescStoreSeqOP {
		Sheet_ConflateSubtype_s();
		virtual ~Sheet_ConflateSubtype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateSubtype_s, DEFINE_SHEET_CONFLATESUBTYPE_E_CONFLATESUBTYPE_LIST_MAX_NUM> E_ConflateSubtype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateSubtype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateSubtype & msg);
		static ::proto_ff::Sheet_ConflateSubtype* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateSubtype(); }
		static ::proto_ff::Sheet_ConflateSubtype make_pbmsg(){ return ::proto_ff::Sheet_ConflateSubtype(); }
	};
	typedef struct Sheet_ConflateSubtype_s Sheet_ConflateSubtype_t;

	struct E_ConflatePropReplaceDesc_s : public NFDescStoreSeqOP {
		E_ConflatePropReplaceDesc_s();
		virtual ~E_ConflatePropReplaceDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//素材数量
		int32_t m_id;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflatePropReplaceDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflatePropReplaceDesc & msg);
		static ::proto_ff::E_ConflatePropReplaceDesc* new_pbmsg(){ return new ::proto_ff::E_ConflatePropReplaceDesc(); }
		static ::proto_ff::E_ConflatePropReplaceDesc make_pbmsg(){ return ::proto_ff::E_ConflatePropReplaceDesc(); }
	};
	typedef struct E_ConflatePropReplaceDesc_s E_ConflatePropReplaceDesc_t;

	struct E_ConflatePropElemDesc_s : public NFDescStoreSeqOP {
		E_ConflatePropElemDesc_s();
		virtual ~E_ConflatePropElemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ConflatePropElemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflatePropElemDesc & msg);
		static ::proto_ff::E_ConflatePropElemDesc* new_pbmsg(){ return new ::proto_ff::E_ConflatePropElemDesc(); }
		static ::proto_ff::E_ConflatePropElemDesc make_pbmsg(){ return ::proto_ff::E_ConflatePropElemDesc(); }
	};
	typedef struct E_ConflatePropElemDesc_s E_ConflatePropElemDesc_t;

	struct E_ConflateProp_s : public NFDescStoreSeqOP {
		E_ConflateProp_s();
		virtual ~E_ConflateProp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_target;//合成目标
		int32_t m_openLv;//显示等级
		int32_t m_subType;//条目
		int32_t m_order;//排序
		int32_t m_activate;//是否激活后不可合成
		int32_t m_display;//是否显示合成数量
		int32_t m_replaceType;//是否可替代
		int32_t m_culture;//是否养成
		int32_t m_usemoney;//合成消耗货币
		int32_t m_cost;//货币数量
		NFShmVector<struct E_ConflatePropReplaceDesc_s, DEFINE_E_CONFLATEPROP_M_REPLACE_MAX_NUM> m_replace;//替换
		NFShmVector<struct E_ConflatePropElemDesc_s, DEFINE_E_CONFLATEPROP_M_ELEM_MAX_NUM> m_elem;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflateProp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateProp & msg);
		static ::proto_ff::E_ConflateProp* new_pbmsg(){ return new ::proto_ff::E_ConflateProp(); }
		static ::proto_ff::E_ConflateProp make_pbmsg(){ return ::proto_ff::E_ConflateProp(); }
	};
	typedef struct E_ConflateProp_s E_ConflateProp_t;

	struct Sheet_ConflateProp_s : public NFDescStoreSeqOP {
		Sheet_ConflateProp_s();
		virtual ~Sheet_ConflateProp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateProp_s, DEFINE_SHEET_CONFLATEPROP_E_CONFLATEPROP_LIST_MAX_NUM> E_ConflateProp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateProp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateProp & msg);
		static ::proto_ff::Sheet_ConflateProp* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateProp(); }
		static ::proto_ff::Sheet_ConflateProp make_pbmsg(){ return ::proto_ff::Sheet_ConflateProp(); }
	};
	typedef struct Sheet_ConflateProp_s Sheet_ConflateProp_t;

	struct E_ConflateJewelry_spElemDesc_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_spElemDesc_s();
		virtual ~E_ConflateJewelry_spElemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_spElemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_spElemDesc & msg);
		static ::proto_ff::E_ConflateJewelry_spElemDesc* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_spElemDesc(); }
		static ::proto_ff::E_ConflateJewelry_spElemDesc make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_spElemDesc(); }
	};
	typedef struct E_ConflateJewelry_spElemDesc_s E_ConflateJewelry_spElemDesc_t;

	struct E_ConflateJewelry_sp_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_sp_s();
		virtual ~E_ConflateJewelry_sp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合成id
		int32_t m_groupType;//组类型
		int32_t m_openwearQuality;//装备品阶要求
		int32_t m_openspecial;//真炼要求
		int32_t m_position;//装备位置
		int32_t m_quality;//装备品质要求
		int32_t m_star;//装备星级
		int32_t m_next;//下一级
		NFShmVector<struct E_ConflateJewelry_spElemDesc_s, DEFINE_E_CONFLATEJEWELRY_SP_M_ELEM_MAX_NUM> m_elem;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_sp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sp & msg);
		static ::proto_ff::E_ConflateJewelry_sp* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_sp(); }
		static ::proto_ff::E_ConflateJewelry_sp make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_sp(); }
	};
	typedef struct E_ConflateJewelry_sp_s E_ConflateJewelry_sp_t;

	struct Sheet_ConflateJewelry_sp_s : public NFDescStoreSeqOP {
		Sheet_ConflateJewelry_sp_s();
		virtual ~Sheet_ConflateJewelry_sp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateJewelry_sp_s, DEFINE_SHEET_CONFLATEJEWELRY_SP_E_CONFLATEJEWELRY_SP_LIST_MAX_NUM> E_ConflateJewelry_sp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_sp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_sp & msg);
		static ::proto_ff::Sheet_ConflateJewelry_sp* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateJewelry_sp(); }
		static ::proto_ff::Sheet_ConflateJewelry_sp make_pbmsg(){ return ::proto_ff::Sheet_ConflateJewelry_sp(); }
	};
	typedef struct Sheet_ConflateJewelry_sp_s Sheet_ConflateJewelry_sp_t;

	struct E_ConflateJewelry_zlElemDesc_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_zlElemDesc_s();
		virtual ~E_ConflateJewelry_zlElemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_zlElemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_zlElemDesc & msg);
		static ::proto_ff::E_ConflateJewelry_zlElemDesc* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_zlElemDesc(); }
		static ::proto_ff::E_ConflateJewelry_zlElemDesc make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_zlElemDesc(); }
	};
	typedef struct E_ConflateJewelry_zlElemDesc_s E_ConflateJewelry_zlElemDesc_t;

	struct E_ConflateJewelry_zl_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_zl_s();
		virtual ~E_ConflateJewelry_zl_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合成id
		int32_t m_openquality;//品质要求
		int32_t m_groupType;//组类型
		int32_t m_position;//装备部位
		int32_t m_Zllv;//真炼等级
		int32_t m_next;//下一级
		NFShmString<64> m_Zlname;//等级描述
		NFShmVector<struct E_ConflateJewelry_zlElemDesc_s, DEFINE_E_CONFLATEJEWELRY_ZL_M_ELEM_MAX_NUM> m_elem;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_zl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_zl & msg);
		static ::proto_ff::E_ConflateJewelry_zl* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_zl(); }
		static ::proto_ff::E_ConflateJewelry_zl make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_zl(); }
	};
	typedef struct E_ConflateJewelry_zl_s E_ConflateJewelry_zl_t;

	struct Sheet_ConflateJewelry_zl_s : public NFDescStoreSeqOP {
		Sheet_ConflateJewelry_zl_s();
		virtual ~Sheet_ConflateJewelry_zl_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateJewelry_zl_s, DEFINE_SHEET_CONFLATEJEWELRY_ZL_E_CONFLATEJEWELRY_ZL_LIST_MAX_NUM> E_ConflateJewelry_zl_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_zl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_zl & msg);
		static ::proto_ff::Sheet_ConflateJewelry_zl* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateJewelry_zl(); }
		static ::proto_ff::Sheet_ConflateJewelry_zl make_pbmsg(){ return ::proto_ff::Sheet_ConflateJewelry_zl(); }
	};
	typedef struct Sheet_ConflateJewelry_zl_s Sheet_ConflateJewelry_zl_t;

	struct E_ConflateJewelry_sjElemDesc_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_sjElemDesc_s();
		virtual ~E_ConflateJewelry_sjElemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_sjElemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sjElemDesc & msg);
		static ::proto_ff::E_ConflateJewelry_sjElemDesc* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_sjElemDesc(); }
		static ::proto_ff::E_ConflateJewelry_sjElemDesc make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_sjElemDesc(); }
	};
	typedef struct E_ConflateJewelry_sjElemDesc_s E_ConflateJewelry_sjElemDesc_t;

	struct E_ConflateJewelry_sj_s : public NFDescStoreSeqOP {
		E_ConflateJewelry_sj_s();
		virtual ~E_ConflateJewelry_sj_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合成id
		int32_t m_groupType;//组类型
		int32_t m_position;//装备位置
		int32_t m_wearQuality;//装备品阶
		int32_t m_next;//下一级
		int32_t m_openLv;//升阶等级
		NFShmVector<struct E_ConflateJewelry_sjElemDesc_s, DEFINE_E_CONFLATEJEWELRY_SJ_M_ELEM_MAX_NUM> m_elem;//素材

		virtual void write_to_pbmsg(::proto_ff::E_ConflateJewelry_sj & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sj & msg);
		static ::proto_ff::E_ConflateJewelry_sj* new_pbmsg(){ return new ::proto_ff::E_ConflateJewelry_sj(); }
		static ::proto_ff::E_ConflateJewelry_sj make_pbmsg(){ return ::proto_ff::E_ConflateJewelry_sj(); }
	};
	typedef struct E_ConflateJewelry_sj_s E_ConflateJewelry_sj_t;

	struct Sheet_ConflateJewelry_sj_s : public NFDescStoreSeqOP {
		Sheet_ConflateJewelry_sj_s();
		virtual ~Sheet_ConflateJewelry_sj_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConflateJewelry_sj_s, DEFINE_SHEET_CONFLATEJEWELRY_SJ_E_CONFLATEJEWELRY_SJ_LIST_MAX_NUM> E_ConflateJewelry_sj_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_sj & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_sj & msg);
		static ::proto_ff::Sheet_ConflateJewelry_sj* new_pbmsg(){ return new ::proto_ff::Sheet_ConflateJewelry_sj(); }
		static ::proto_ff::Sheet_ConflateJewelry_sj make_pbmsg(){ return ::proto_ff::Sheet_ConflateJewelry_sj(); }
	};
	typedef struct Sheet_ConflateJewelry_sj_s Sheet_ConflateJewelry_sj_t;

}

