#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Box.pb.h"
#include "E_Box_s.h"

#define DEFINE_E_BOXBOX_M_BOXDATA_MAX_NUM 12
#define DEFINE_SHEET_BOXBOX_E_BOXBOX_LIST_MAX_NUM 4096
#define DEFINE_E_BOXBOXDATA_M_EQUIP_MAX_NUM 21
#define DEFINE_E_BOXBOXDATA_M_ITEM_MAX_NUM 50
#define DEFINE_SHEET_BOXBOXDATA_E_BOXBOXDATA_LIST_MAX_NUM 4096


namespace proto_ff_s {

	struct E_BoxBoxBoxdataDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxBoxdataDesc_s();
		virtual ~E_BoxBoxBoxdataDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_mintimes;//次数下限
		int64_t m_id;//id
		int32_t m_maxtimes;//次数上限
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxBoxdataDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxBoxdataDesc & msg);
		static ::proto_ff::E_BoxBoxBoxdataDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxBoxdataDesc(); }
		static ::proto_ff::E_BoxBoxBoxdataDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxBoxdataDesc(); }
	};
	typedef struct E_BoxBoxBoxdataDesc_s E_BoxBoxBoxdataDesc_t;

	struct E_BoxBox_s : public NFDescStoreSeqOP {
		E_BoxBox_s();
		virtual ~E_BoxBox_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_type;//类型
		int32_t m_rate;//生效概率
		NFShmString<64> m_mask;//概率调整标签
		int32_t m_mintimes;//最小次数
		int32_t m_maxtimes;//最大次数
		NFShmVector<struct E_BoxBoxBoxdataDesc_s, DEFINE_E_BOXBOX_M_BOXDATA_MAX_NUM> m_boxdata;//掉落

		virtual void write_to_pbmsg(::proto_ff::E_BoxBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBox & msg);
		static ::proto_ff::E_BoxBox* new_pbmsg(){ return new ::proto_ff::E_BoxBox(); }
		static ::proto_ff::E_BoxBox make_pbmsg(){ return ::proto_ff::E_BoxBox(); }
	};
	typedef struct E_BoxBox_s E_BoxBox_t;

	struct Sheet_BoxBox_s : public NFDescStoreSeqOP {
		Sheet_BoxBox_s();
		virtual ~Sheet_BoxBox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BoxBox_s, DEFINE_SHEET_BOXBOX_E_BOXBOX_LIST_MAX_NUM> E_BoxBox_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BoxBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BoxBox & msg);
		static ::proto_ff::Sheet_BoxBox* new_pbmsg(){ return new ::proto_ff::Sheet_BoxBox(); }
		static ::proto_ff::Sheet_BoxBox make_pbmsg(){ return ::proto_ff::Sheet_BoxBox(); }
	};
	typedef struct Sheet_BoxBox_s Sheet_BoxBox_t;

	struct E_BoxBoxdataEquipDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxdataEquipDesc_s();
		virtual ~E_BoxBoxdataEquipDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_maxnum;//最大数量
		int32_t m_minnum;//最小数量
		int32_t m_isbind;//绑定
		NFShmString<64> m_id;//id
		int32_t m_rand;//概率百分比

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdataEquipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdataEquipDesc & msg);
		static ::proto_ff::E_BoxBoxdataEquipDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdataEquipDesc(); }
		static ::proto_ff::E_BoxBoxdataEquipDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxdataEquipDesc(); }
	};
	typedef struct E_BoxBoxdataEquipDesc_s E_BoxBoxdataEquipDesc_t;

	struct E_BoxBoxdataItemDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxdataItemDesc_s();
		virtual ~E_BoxBoxdataItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_rand;//权重
		int32_t m_maxnum;//最大数量
		int32_t m_minnum;//最小数量
		NFShmString<64> m_isbind;//标定标记
		NFShmString<64> m_id;//id
		int32_t m_rarerand;//概率百分比

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdataItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdataItemDesc & msg);
		static ::proto_ff::E_BoxBoxdataItemDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdataItemDesc(); }
		static ::proto_ff::E_BoxBoxdataItemDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxdataItemDesc(); }
	};
	typedef struct E_BoxBoxdataItemDesc_s E_BoxBoxdataItemDesc_t;

	struct E_BoxBoxdata_s : public NFDescStoreSeqOP {
		E_BoxBoxdata_s();
		virtual ~E_BoxBoxdata_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//掉落包ID
		int32_t m_drop_type;//掉落类型
		int32_t m_goldminnum;//金币下限
		int32_t m_goldmaxnum;//金币上限
		int32_t m_goldrand;//金币掉落率
		int32_t m_bindjewelminnum;//绑钻下限
		int32_t m_bindjewelmaxnum;//绑钻上限
		int32_t m_bindjewelrand;//绑钻掉落率
		int32_t m_jewelminnum;//钻石下限
		int32_t m_jewelmaxnum;//钻石上限
		int32_t m_jewelrand;//钻石掉落率
		NFShmString<64> m_eq_profession;//职业限制
		NFShmVector<struct E_BoxBoxdataEquipDesc_s, DEFINE_E_BOXBOXDATA_M_EQUIP_MAX_NUM> m_equip;//稀有装备
		NFShmVector<struct E_BoxBoxdataItemDesc_s, DEFINE_E_BOXBOXDATA_M_ITEM_MAX_NUM> m_item;//稀有物品

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdata & msg);
		static ::proto_ff::E_BoxBoxdata* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdata(); }
		static ::proto_ff::E_BoxBoxdata make_pbmsg(){ return ::proto_ff::E_BoxBoxdata(); }
	};
	typedef struct E_BoxBoxdata_s E_BoxBoxdata_t;

	struct Sheet_BoxBoxdata_s : public NFDescStoreSeqOP {
		Sheet_BoxBoxdata_s();
		virtual ~Sheet_BoxBoxdata_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BoxBoxdata_s, DEFINE_SHEET_BOXBOXDATA_E_BOXBOXDATA_LIST_MAX_NUM> E_BoxBoxdata_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BoxBoxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BoxBoxdata & msg);
		static ::proto_ff::Sheet_BoxBoxdata* new_pbmsg(){ return new ::proto_ff::Sheet_BoxBoxdata(); }
		static ::proto_ff::Sheet_BoxBoxdata make_pbmsg(){ return ::proto_ff::Sheet_BoxBoxdata(); }
	};
	typedef struct Sheet_BoxBoxdata_s Sheet_BoxBoxdata_t;

}

