#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Item.pb.h"
#include "E_Item_s.h"

#define DEFINE_SHEET_ITEMITEM_E_ITEMITEM_LIST_MAX_NUM 4096


namespace proto_ff_s {

	struct E_ItemItem_s : public NFDescStoreSeqOP {
		E_ItemItem_s();
		virtual ~E_ItemItem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//物品ID
		NFShmString<64> m_name;//物品名称
		int32_t m_itemtype;//物品类型
		int32_t m_subtype;//子类型
		int32_t m_functiontype;//物品功能类型
		NFShmString<64> m_functionvalue;//物品功能参数
		NFShmString<64> m_usecondition;//使用条件
		int64_t m_waiguanlink;//外观id
		int32_t m_level;//物品等级
		int32_t m_quality;//物品品质
		int32_t m_levelrequest;//使用等级
		NFShmString<64> m_profession;//使用职业
		int32_t m_bindtype;//绑定类型
		int32_t m_istradebind;//是否交易绑定
		int32_t m_dropnum;//每日掉落上限
		int32_t m_stacklimit;//堆叠上限
		int32_t m_sellprice;//出售价格
		int64_t m_sellbox;//出售掉落
		int32_t m_broadcast;//是否跑马灯广播
		int32_t m_iscanbatchuse;//是否可批量使用
		int32_t m_dayuse;//每日使用次数
		int32_t m_time;//限时道具
		NFShmString<64> m_uselimit;//禁用本道具地图

		virtual void write_to_pbmsg(::proto_ff::E_ItemItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ItemItem & msg);
		static ::proto_ff::E_ItemItem* new_pbmsg(){ return new ::proto_ff::E_ItemItem(); }
		static ::proto_ff::E_ItemItem make_pbmsg(){ return ::proto_ff::E_ItemItem(); }
	};
	typedef struct E_ItemItem_s E_ItemItem_t;

	struct Sheet_ItemItem_s : public NFDescStoreSeqOP {
		Sheet_ItemItem_s();
		virtual ~Sheet_ItemItem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ItemItem_s, DEFINE_SHEET_ITEMITEM_E_ITEMITEM_LIST_MAX_NUM> E_ItemItem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ItemItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ItemItem & msg);
		static ::proto_ff::Sheet_ItemItem* new_pbmsg(){ return new ::proto_ff::Sheet_ItemItem(); }
		static ::proto_ff::Sheet_ItemItem make_pbmsg(){ return ::proto_ff::Sheet_ItemItem(); }
	};
	typedef struct Sheet_ItemItem_s Sheet_ItemItem_t;

}

