#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Equipimprove.pb.h"
#include "E_Equipimprove_s.h"

#define DEFINE_E_EQUIPIMPROVEUPQUALITY_M_MATERIAL_MAX_NUM 2
#define DEFINE_E_EQUIPIMPROVEUPQUALITY_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_EQUIPIMPROVEUPQUALITY_E_EQUIPIMPROVEUPQUALITY_LIST_MAX_NUM 128
#define DEFINE_E_EQUIPIMPROVEAWAKEN_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_E_EQUIPIMPROVEAWAKEN_M_BREAK_MAX_NUM 4
#define DEFINE_SHEET_EQUIPIMPROVEAWAKEN_E_EQUIPIMPROVEAWAKEN_LIST_MAX_NUM 512
#define DEFINE_E_EQUIPIMPROVESOARING_M_ATTR_MAX_NUM 3
#define DEFINE_SHEET_EQUIPIMPROVESOARING_E_EQUIPIMPROVESOARING_LIST_MAX_NUM 32
#define DEFINE_E_EQUIPIMPROVESEAL_M_SEAL_MAX_NUM 3
#define DEFINE_SHEET_EQUIPIMPROVESEAL_E_EQUIPIMPROVESEAL_LIST_MAX_NUM 16
#define DEFINE_SHEET_EQUIPIMPROVESEALSLOT_E_EQUIPIMPROVESEALSLOT_LIST_MAX_NUM 64
#define DEFINE_E_EQUIPIMPROVESEALSUIT_M_SUIT_MAX_NUM 5
#define DEFINE_SHEET_EQUIPIMPROVESEALSUIT_E_EQUIPIMPROVESEALSUIT_LIST_MAX_NUM 1024


namespace proto_ff_s {

	struct E_EquipimproveUpqualityMaterialDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveUpqualityMaterialDesc_s();
		virtual ~E_EquipimproveUpqualityMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveUpqualityMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveUpqualityMaterialDesc & msg);
		static ::proto_ff::E_EquipimproveUpqualityMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveUpqualityMaterialDesc(); }
		static ::proto_ff::E_EquipimproveUpqualityMaterialDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveUpqualityMaterialDesc(); }
	};
	typedef struct E_EquipimproveUpqualityMaterialDesc_s E_EquipimproveUpqualityMaterialDesc_t;

	struct E_EquipimproveUpqualityAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveUpqualityAttributeDesc_s();
		virtual ~E_EquipimproveUpqualityAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveUpqualityAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveUpqualityAttributeDesc & msg);
		static ::proto_ff::E_EquipimproveUpqualityAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveUpqualityAttributeDesc(); }
		static ::proto_ff::E_EquipimproveUpqualityAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveUpqualityAttributeDesc(); }
	};
	typedef struct E_EquipimproveUpqualityAttributeDesc_s E_EquipimproveUpqualityAttributeDesc_t;

	struct E_EquipimproveUpquality_s : public NFDescStoreSeqOP {
		E_EquipimproveUpquality_s();
		virtual ~E_EquipimproveUpquality_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//品阶
		NFShmString<64> m_position;//装备部位
		int32_t m_wearQualityLimit;//装备品阶下限
		int32_t m_star;//星级等级
		int32_t m_starnum;//星级星数
		int32_t m_success;//升星基础成功率
		int32_t m_luckid;//幸运道具id
		int32_t m_lucksuccess;//加成成功率
		int32_t m_lucknum;//幸运道具数量
		int32_t m_qualityAtt;//品阶属性
		int32_t m_qualityValue;//品阶属性值
		NFShmVector<struct E_EquipimproveUpqualityMaterialDesc_s, DEFINE_E_EQUIPIMPROVEUPQUALITY_M_MATERIAL_MAX_NUM> m_material;//升星材料
		NFShmVector<struct E_EquipimproveUpqualityAttributeDesc_s, DEFINE_E_EQUIPIMPROVEUPQUALITY_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveUpquality & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveUpquality & msg);
		static ::proto_ff::E_EquipimproveUpquality* new_pbmsg(){ return new ::proto_ff::E_EquipimproveUpquality(); }
		static ::proto_ff::E_EquipimproveUpquality make_pbmsg(){ return ::proto_ff::E_EquipimproveUpquality(); }
	};
	typedef struct E_EquipimproveUpquality_s E_EquipimproveUpquality_t;

	struct Sheet_EquipimproveUpquality_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveUpquality_s();
		virtual ~Sheet_EquipimproveUpquality_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveUpquality_s, DEFINE_SHEET_EQUIPIMPROVEUPQUALITY_E_EQUIPIMPROVEUPQUALITY_LIST_MAX_NUM> E_EquipimproveUpquality_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveUpquality & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveUpquality & msg);
		static ::proto_ff::Sheet_EquipimproveUpquality* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveUpquality(); }
		static ::proto_ff::Sheet_EquipimproveUpquality make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveUpquality(); }
	};
	typedef struct Sheet_EquipimproveUpquality_s Sheet_EquipimproveUpquality_t;

	struct E_EquipimproveAwakenAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveAwakenAttributeDesc_s();
		virtual ~E_EquipimproveAwakenAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveAwakenAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveAwakenAttributeDesc & msg);
		static ::proto_ff::E_EquipimproveAwakenAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveAwakenAttributeDesc(); }
		static ::proto_ff::E_EquipimproveAwakenAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveAwakenAttributeDesc(); }
	};
	typedef struct E_EquipimproveAwakenAttributeDesc_s E_EquipimproveAwakenAttributeDesc_t;

	struct E_EquipimproveAwakenBreakDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveAwakenBreakDesc_s();
		virtual ~E_EquipimproveAwakenBreakDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveAwakenBreakDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveAwakenBreakDesc & msg);
		static ::proto_ff::E_EquipimproveAwakenBreakDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveAwakenBreakDesc(); }
		static ::proto_ff::E_EquipimproveAwakenBreakDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveAwakenBreakDesc(); }
	};
	typedef struct E_EquipimproveAwakenBreakDesc_s E_EquipimproveAwakenBreakDesc_t;

	struct E_EquipimproveAwaken_s : public NFDescStoreSeqOP {
		E_EquipimproveAwaken_s();
		virtual ~E_EquipimproveAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//品阶
		NFShmString<64> m_position;//装备部位
		int32_t m_wearQualityLimit;//装备品阶下限
		int32_t m_qualityLimit;//装备品质下限
		int32_t m_wearStarLimit;//装备星级下限
		int32_t m_awakenLv;//觉醒等级
		int32_t m_material_id;//觉醒材料ID
		int32_t m_material_num;//觉醒材料数量
		int32_t m_break_id;//突破材料ID
		int32_t m_break_num;//突破材料数量
		NFShmVector<struct E_EquipimproveAwakenAttributeDesc_s, DEFINE_E_EQUIPIMPROVEAWAKEN_M_ATTRIBUTE_MAX_NUM> m_attribute;//觉醒属性
		NFShmVector<struct E_EquipimproveAwakenBreakDesc_s, DEFINE_E_EQUIPIMPROVEAWAKEN_M_BREAK_MAX_NUM> m_break;//突破属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveAwaken & msg);
		static ::proto_ff::E_EquipimproveAwaken* new_pbmsg(){ return new ::proto_ff::E_EquipimproveAwaken(); }
		static ::proto_ff::E_EquipimproveAwaken make_pbmsg(){ return ::proto_ff::E_EquipimproveAwaken(); }
	};
	typedef struct E_EquipimproveAwaken_s E_EquipimproveAwaken_t;

	struct Sheet_EquipimproveAwaken_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveAwaken_s();
		virtual ~Sheet_EquipimproveAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveAwaken_s, DEFINE_SHEET_EQUIPIMPROVEAWAKEN_E_EQUIPIMPROVEAWAKEN_LIST_MAX_NUM> E_EquipimproveAwaken_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveAwaken & msg);
		static ::proto_ff::Sheet_EquipimproveAwaken* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveAwaken(); }
		static ::proto_ff::Sheet_EquipimproveAwaken make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveAwaken(); }
	};
	typedef struct Sheet_EquipimproveAwaken_s Sheet_EquipimproveAwaken_t;

	struct E_EquipimproveSoaringAttrDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveSoaringAttrDesc_s();
		virtual ~E_EquipimproveSoaringAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSoaringAttrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSoaringAttrDesc & msg);
		static ::proto_ff::E_EquipimproveSoaringAttrDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSoaringAttrDesc(); }
		static ::proto_ff::E_EquipimproveSoaringAttrDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveSoaringAttrDesc(); }
	};
	typedef struct E_EquipimproveSoaringAttrDesc_s E_EquipimproveSoaringAttrDesc_t;

	struct E_EquipimproveSoaring_s : public NFDescStoreSeqOP {
		E_EquipimproveSoaring_s();
		virtual ~E_EquipimproveSoaring_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvid;//飞升等级
		int32_t m_awaken;//觉醒品阶下限
		int32_t m_itemid;//飞升材料
		int32_t m_itemnum;//飞升材料数量
		NFShmString<64> m_position;//部位id
		NFShmVector<struct E_EquipimproveSoaringAttrDesc_s, DEFINE_E_EQUIPIMPROVESOARING_M_ATTR_MAX_NUM> m_attr;//飞升属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSoaring & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSoaring & msg);
		static ::proto_ff::E_EquipimproveSoaring* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSoaring(); }
		static ::proto_ff::E_EquipimproveSoaring make_pbmsg(){ return ::proto_ff::E_EquipimproveSoaring(); }
	};
	typedef struct E_EquipimproveSoaring_s E_EquipimproveSoaring_t;

	struct Sheet_EquipimproveSoaring_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveSoaring_s();
		virtual ~Sheet_EquipimproveSoaring_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveSoaring_s, DEFINE_SHEET_EQUIPIMPROVESOARING_E_EQUIPIMPROVESOARING_LIST_MAX_NUM> E_EquipimproveSoaring_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveSoaring & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSoaring & msg);
		static ::proto_ff::Sheet_EquipimproveSoaring* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveSoaring(); }
		static ::proto_ff::Sheet_EquipimproveSoaring make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveSoaring(); }
	};
	typedef struct Sheet_EquipimproveSoaring_s Sheet_EquipimproveSoaring_t;

	struct E_EquipimproveSealSealDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveSealSealDesc_s();
		virtual ~E_EquipimproveSealSealDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSealSealDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSealSealDesc & msg);
		static ::proto_ff::E_EquipimproveSealSealDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSealSealDesc(); }
		static ::proto_ff::E_EquipimproveSealSealDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveSealSealDesc(); }
	};
	typedef struct E_EquipimproveSealSealDesc_s E_EquipimproveSealSealDesc_t;

	struct E_EquipimproveSeal_s : public NFDescStoreSeqOP {
		E_EquipimproveSeal_s();
		virtual ~E_EquipimproveSeal_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//印符物品id
		NFShmString<64> m_sealPosition;//印符镶嵌部位
		int32_t m_seallv;//印符品阶
		int32_t m_preId;//上阶印符ID
		int32_t m_nextId;//下阶印符ID
		NFShmString<64> m_numb;//对应一阶印符数量
		int32_t m_nextValue;//下级差值
		NFShmVector<struct E_EquipimproveSealSealDesc_s, DEFINE_E_EQUIPIMPROVESEAL_M_SEAL_MAX_NUM> m_seal;//印符属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSeal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSeal & msg);
		static ::proto_ff::E_EquipimproveSeal* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSeal(); }
		static ::proto_ff::E_EquipimproveSeal make_pbmsg(){ return ::proto_ff::E_EquipimproveSeal(); }
	};
	typedef struct E_EquipimproveSeal_s E_EquipimproveSeal_t;

	struct Sheet_EquipimproveSeal_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveSeal_s();
		virtual ~Sheet_EquipimproveSeal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveSeal_s, DEFINE_SHEET_EQUIPIMPROVESEAL_E_EQUIPIMPROVESEAL_LIST_MAX_NUM> E_EquipimproveSeal_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveSeal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSeal & msg);
		static ::proto_ff::Sheet_EquipimproveSeal* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveSeal(); }
		static ::proto_ff::Sheet_EquipimproveSeal make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveSeal(); }
	};
	typedef struct Sheet_EquipimproveSeal_s Sheet_EquipimproveSeal_t;

	struct E_EquipimproveSealslot_s : public NFDescStoreSeqOP {
		E_EquipimproveSealslot_s();
		virtual ~E_EquipimproveSealslot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//槽位id
		int32_t m_quality;//所需装备品阶
		int32_t m_character;//所需装备品质
		int32_t m_star;//所需装备星数

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSealslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSealslot & msg);
		static ::proto_ff::E_EquipimproveSealslot* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSealslot(); }
		static ::proto_ff::E_EquipimproveSealslot make_pbmsg(){ return ::proto_ff::E_EquipimproveSealslot(); }
	};
	typedef struct E_EquipimproveSealslot_s E_EquipimproveSealslot_t;

	struct Sheet_EquipimproveSealslot_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveSealslot_s();
		virtual ~Sheet_EquipimproveSealslot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveSealslot_s, DEFINE_SHEET_EQUIPIMPROVESEALSLOT_E_EQUIPIMPROVESEALSLOT_LIST_MAX_NUM> E_EquipimproveSealslot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveSealslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSealslot & msg);
		static ::proto_ff::Sheet_EquipimproveSealslot* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveSealslot(); }
		static ::proto_ff::Sheet_EquipimproveSealslot make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveSealslot(); }
	};
	typedef struct Sheet_EquipimproveSealslot_s Sheet_EquipimproveSealslot_t;

	struct E_EquipimproveSealsuitSuitDesc_s : public NFDescStoreSeqOP {
		E_EquipimproveSealsuitSuitDesc_s();
		virtual ~E_EquipimproveSealsuitSuitDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSealsuitSuitDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSealsuitSuitDesc & msg);
		static ::proto_ff::E_EquipimproveSealsuitSuitDesc* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSealsuitSuitDesc(); }
		static ::proto_ff::E_EquipimproveSealsuitSuitDesc make_pbmsg(){ return ::proto_ff::E_EquipimproveSealsuitSuitDesc(); }
	};
	typedef struct E_EquipimproveSealsuitSuitDesc_s E_EquipimproveSealsuitSuitDesc_t;

	struct E_EquipimproveSealsuit_s : public NFDescStoreSeqOP {
		E_EquipimproveSealsuit_s();
		virtual ~E_EquipimproveSealsuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wearnum;//装配数量
		int32_t m_quality;//装配品阶
		NFShmString<64> m_position;//装备部位
		NFShmVector<struct E_EquipimproveSealsuitSuitDesc_s, DEFINE_E_EQUIPIMPROVESEALSUIT_M_SUIT_MAX_NUM> m_suit;//印符属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipimproveSealsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipimproveSealsuit & msg);
		static ::proto_ff::E_EquipimproveSealsuit* new_pbmsg(){ return new ::proto_ff::E_EquipimproveSealsuit(); }
		static ::proto_ff::E_EquipimproveSealsuit make_pbmsg(){ return ::proto_ff::E_EquipimproveSealsuit(); }
	};
	typedef struct E_EquipimproveSealsuit_s E_EquipimproveSealsuit_t;

	struct Sheet_EquipimproveSealsuit_s : public NFDescStoreSeqOP {
		Sheet_EquipimproveSealsuit_s();
		virtual ~Sheet_EquipimproveSealsuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipimproveSealsuit_s, DEFINE_SHEET_EQUIPIMPROVESEALSUIT_E_EQUIPIMPROVESEALSUIT_LIST_MAX_NUM> E_EquipimproveSealsuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipimproveSealsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSealsuit & msg);
		static ::proto_ff::Sheet_EquipimproveSealsuit* new_pbmsg(){ return new ::proto_ff::Sheet_EquipimproveSealsuit(); }
		static ::proto_ff::Sheet_EquipimproveSealsuit make_pbmsg(){ return ::proto_ff::Sheet_EquipimproveSealsuit(); }
	};
	typedef struct Sheet_EquipimproveSealsuit_s Sheet_EquipimproveSealsuit_t;

}

