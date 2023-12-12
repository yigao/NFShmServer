#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Dragon.pb.h"
#include "E_Dragon_s.h"

#define DEFINE_E_DRAGONFRAGMENT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_DRAGONFRAGMENT_E_DRAGONFRAGMENT_LIST_MAX_NUM 16
#define DEFINE_E_DRAGONDISPLAY_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_DRAGONDISPLAY_M_FRAGMENTID_MAX_NUM 3
#define DEFINE_SHEET_DRAGONDISPLAY_E_DRAGONDISPLAY_LIST_MAX_NUM 32
#define DEFINE_SHEET_DRAGONCHANGE_E_DRAGONCHANGE_LIST_MAX_NUM 8
#define DEFINE_E_DRAGONLVVALUE_M_ATTRIBUTE_MAX_NUM 9
#define DEFINE_SHEET_DRAGONLVVALUE_E_DRAGONLVVALUE_LIST_MAX_NUM 1024
#define DEFINE_E_DRAGONSTARVALUE_M_ATTRIBUTE_MAX_NUM 9
#define DEFINE_SHEET_DRAGONSTARVALUE_E_DRAGONSTARVALUE_LIST_MAX_NUM 2048


namespace proto_ff_s {

	struct E_DragonFragmentAttributeDesc_s : public NFDescStoreSeqOP {
		E_DragonFragmentAttributeDesc_s();
		virtual ~E_DragonFragmentAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_DragonFragmentAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonFragmentAttributeDesc & msg);
		static ::proto_ff::E_DragonFragmentAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonFragmentAttributeDesc(); }
		static ::proto_ff::E_DragonFragmentAttributeDesc make_pbmsg(){ return ::proto_ff::E_DragonFragmentAttributeDesc(); }
	};
	typedef struct E_DragonFragmentAttributeDesc_s E_DragonFragmentAttributeDesc_t;

	struct E_DragonFragment_s : public NFDescStoreSeqOP {
		E_DragonFragment_s();
		virtual ~E_DragonFragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fragmentID;//碎片ID
		int64_t m_item;//物品ID
		int32_t m_itemNum;//碎片使用上限
		NFShmVector<struct E_DragonFragmentAttributeDesc_s, DEFINE_E_DRAGONFRAGMENT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_DragonFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonFragment & msg);
		static ::proto_ff::E_DragonFragment* new_pbmsg(){ return new ::proto_ff::E_DragonFragment(); }
		static ::proto_ff::E_DragonFragment make_pbmsg(){ return ::proto_ff::E_DragonFragment(); }
	};
	typedef struct E_DragonFragment_s E_DragonFragment_t;

	struct Sheet_DragonFragment_s : public NFDescStoreSeqOP {
		Sheet_DragonFragment_s();
		virtual ~Sheet_DragonFragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonFragment_s, DEFINE_SHEET_DRAGONFRAGMENT_E_DRAGONFRAGMENT_LIST_MAX_NUM> E_DragonFragment_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonFragment & msg);
		static ::proto_ff::Sheet_DragonFragment* new_pbmsg(){ return new ::proto_ff::Sheet_DragonFragment(); }
		static ::proto_ff::Sheet_DragonFragment make_pbmsg(){ return ::proto_ff::Sheet_DragonFragment(); }
	};
	typedef struct Sheet_DragonFragment_s Sheet_DragonFragment_t;

	struct E_DragonDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_DragonDisplayMaterialDesc_s();
		virtual ~E_DragonDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_DragonDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonDisplayMaterialDesc & msg);
		static ::proto_ff::E_DragonDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_DragonDisplayMaterialDesc(); }
		static ::proto_ff::E_DragonDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_DragonDisplayMaterialDesc(); }
	};
	typedef struct E_DragonDisplayMaterialDesc_s E_DragonDisplayMaterialDesc_t;

	struct E_DragonDisplay_s : public NFDescStoreSeqOP {
		E_DragonDisplay_s();
		virtual ~E_DragonDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_funId;//功能开放
		int32_t m_UpLvType;//升级参考类型
		int32_t m_LvMax;//等级上限
		NFShmString<64> m_skillID;//解锁技能组
		NFShmString<64> m_exSkillID;//解锁专属技能组
		int32_t m_starItem;//升星道具
		int32_t m_UpStarType;//升星参考类型
		int32_t m_starUp;//星星上限
		int32_t m_luck;//每幸运值增加的成功率
		NFShmVector<struct E_DragonDisplayMaterialDesc_s, DEFINE_E_DRAGONDISPLAY_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_DRAGONDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentID;//关联碎片ID

		virtual void write_to_pbmsg(::proto_ff::E_DragonDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonDisplay & msg);
		static ::proto_ff::E_DragonDisplay* new_pbmsg(){ return new ::proto_ff::E_DragonDisplay(); }
		static ::proto_ff::E_DragonDisplay make_pbmsg(){ return ::proto_ff::E_DragonDisplay(); }
	};
	typedef struct E_DragonDisplay_s E_DragonDisplay_t;

	struct Sheet_DragonDisplay_s : public NFDescStoreSeqOP {
		Sheet_DragonDisplay_s();
		virtual ~Sheet_DragonDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonDisplay_s, DEFINE_SHEET_DRAGONDISPLAY_E_DRAGONDISPLAY_LIST_MAX_NUM> E_DragonDisplay_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonDisplay & msg);
		static ::proto_ff::Sheet_DragonDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_DragonDisplay(); }
		static ::proto_ff::Sheet_DragonDisplay make_pbmsg(){ return ::proto_ff::Sheet_DragonDisplay(); }
	};
	typedef struct Sheet_DragonDisplay_s Sheet_DragonDisplay_t;

	struct E_DragonChange_s : public NFDescStoreSeqOP {
		E_DragonChange_s();
		virtual ~E_DragonChange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_funid;//功能开放
		NFShmString<64> m_skillID;//解锁技能组
		NFShmString<64> m_exSkillID;//解锁专属技能组
		NFShmString<64> m_fxID;//幻化特效
		int32_t m_starMax;//星星上限
		int32_t m_starType;//星级数值类型
		int32_t m_activationItem;//激活需要的道具
		int32_t m_activationNum;//激活需要的道具数量
		int32_t m_starId;//升星需要道具ID

		virtual void write_to_pbmsg(::proto_ff::E_DragonChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonChange & msg);
		static ::proto_ff::E_DragonChange* new_pbmsg(){ return new ::proto_ff::E_DragonChange(); }
		static ::proto_ff::E_DragonChange make_pbmsg(){ return ::proto_ff::E_DragonChange(); }
	};
	typedef struct E_DragonChange_s E_DragonChange_t;

	struct Sheet_DragonChange_s : public NFDescStoreSeqOP {
		Sheet_DragonChange_s();
		virtual ~Sheet_DragonChange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonChange_s, DEFINE_SHEET_DRAGONCHANGE_E_DRAGONCHANGE_LIST_MAX_NUM> E_DragonChange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonChange & msg);
		static ::proto_ff::Sheet_DragonChange* new_pbmsg(){ return new ::proto_ff::Sheet_DragonChange(); }
		static ::proto_ff::Sheet_DragonChange make_pbmsg(){ return ::proto_ff::Sheet_DragonChange(); }
	};
	typedef struct Sheet_DragonChange_s Sheet_DragonChange_t;

	struct E_DragonLvvalueAttributeDesc_s : public NFDescStoreSeqOP {
		E_DragonLvvalueAttributeDesc_s();
		virtual ~E_DragonLvvalueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_DragonLvvalueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonLvvalueAttributeDesc & msg);
		static ::proto_ff::E_DragonLvvalueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonLvvalueAttributeDesc(); }
		static ::proto_ff::E_DragonLvvalueAttributeDesc make_pbmsg(){ return ::proto_ff::E_DragonLvvalueAttributeDesc(); }
	};
	typedef struct E_DragonLvvalueAttributeDesc_s E_DragonLvvalueAttributeDesc_t;

	struct E_DragonLvvalue_s : public NFDescStoreSeqOP {
		E_DragonLvvalue_s();
		virtual ~E_DragonLvvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_Exp;//升级需要经验
		int32_t m_gold;//花费金币
		int32_t m_starLimit;//星级要求
		NFShmVector<struct E_DragonLvvalueAttributeDesc_s, DEFINE_E_DRAGONLVVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_DragonLvvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonLvvalue & msg);
		static ::proto_ff::E_DragonLvvalue* new_pbmsg(){ return new ::proto_ff::E_DragonLvvalue(); }
		static ::proto_ff::E_DragonLvvalue make_pbmsg(){ return ::proto_ff::E_DragonLvvalue(); }
	};
	typedef struct E_DragonLvvalue_s E_DragonLvvalue_t;

	struct Sheet_DragonLvvalue_s : public NFDescStoreSeqOP {
		Sheet_DragonLvvalue_s();
		virtual ~Sheet_DragonLvvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonLvvalue_s, DEFINE_SHEET_DRAGONLVVALUE_E_DRAGONLVVALUE_LIST_MAX_NUM> E_DragonLvvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonLvvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonLvvalue & msg);
		static ::proto_ff::Sheet_DragonLvvalue* new_pbmsg(){ return new ::proto_ff::Sheet_DragonLvvalue(); }
		static ::proto_ff::Sheet_DragonLvvalue make_pbmsg(){ return ::proto_ff::Sheet_DragonLvvalue(); }
	};
	typedef struct Sheet_DragonLvvalue_s Sheet_DragonLvvalue_t;

	struct E_DragonStarvalueAttributeDesc_s : public NFDescStoreSeqOP {
		E_DragonStarvalueAttributeDesc_s();
		virtual ~E_DragonStarvalueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_DragonStarvalueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonStarvalueAttributeDesc & msg);
		static ::proto_ff::E_DragonStarvalueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonStarvalueAttributeDesc(); }
		static ::proto_ff::E_DragonStarvalueAttributeDesc make_pbmsg(){ return ::proto_ff::E_DragonStarvalueAttributeDesc(); }
	};
	typedef struct E_DragonStarvalueAttributeDesc_s E_DragonStarvalueAttributeDesc_t;

	struct E_DragonStarvalue_s : public NFDescStoreSeqOP {
		E_DragonStarvalue_s();
		virtual ~E_DragonStarvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_star;//星级
		int32_t m_gold;//金币
		int32_t m_starNum;//升星消耗
		int32_t m_sucess;//升级基础成功率
		int32_t m_luckMax;//幸运值上限
		int32_t m_failluck;//失败幸运值
		int32_t m_model;//模型
		NFShmVector<struct E_DragonStarvalueAttributeDesc_s, DEFINE_E_DRAGONSTARVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_DragonStarvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonStarvalue & msg);
		static ::proto_ff::E_DragonStarvalue* new_pbmsg(){ return new ::proto_ff::E_DragonStarvalue(); }
		static ::proto_ff::E_DragonStarvalue make_pbmsg(){ return ::proto_ff::E_DragonStarvalue(); }
	};
	typedef struct E_DragonStarvalue_s E_DragonStarvalue_t;

	struct Sheet_DragonStarvalue_s : public NFDescStoreSeqOP {
		Sheet_DragonStarvalue_s();
		virtual ~Sheet_DragonStarvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonStarvalue_s, DEFINE_SHEET_DRAGONSTARVALUE_E_DRAGONSTARVALUE_LIST_MAX_NUM> E_DragonStarvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonStarvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonStarvalue & msg);
		static ::proto_ff::Sheet_DragonStarvalue* new_pbmsg(){ return new ::proto_ff::Sheet_DragonStarvalue(); }
		static ::proto_ff::Sheet_DragonStarvalue make_pbmsg(){ return ::proto_ff::Sheet_DragonStarvalue(); }
	};
	typedef struct Sheet_DragonStarvalue_s Sheet_DragonStarvalue_t;

}

