#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Offline.pb.h"
#include "E_Offline_s.h"

#define DEFINE_SHEET_OFFLINEOFFLINE_E_OFFLINEOFFLINE_LIST_MAX_NUM 2048
#define DEFINE_E_OFFLINEITEMLIST_M_ITEM_MAX_NUM 22
#define DEFINE_SHEET_OFFLINEITEMLIST_E_OFFLINEITEMLIST_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_OfflineOffline_s : public NFDescStoreSeqOP {
		E_OfflineOffline_s();
		virtual ~E_OfflineOffline_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//角色等级
		int64_t m_offlineexp;//离线基础经验

		virtual void write_to_pbmsg(::proto_ff::E_OfflineOffline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OfflineOffline & msg);
		static ::proto_ff::E_OfflineOffline* new_pbmsg(){ return new ::proto_ff::E_OfflineOffline(); }
		static ::proto_ff::E_OfflineOffline make_pbmsg(){ return ::proto_ff::E_OfflineOffline(); }
	};
	typedef struct E_OfflineOffline_s E_OfflineOffline_t;

	struct Sheet_OfflineOffline_s : public NFDescStoreSeqOP {
		Sheet_OfflineOffline_s();
		virtual ~Sheet_OfflineOffline_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OfflineOffline_s, DEFINE_SHEET_OFFLINEOFFLINE_E_OFFLINEOFFLINE_LIST_MAX_NUM> E_OfflineOffline_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OfflineOffline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OfflineOffline & msg);
		static ::proto_ff::Sheet_OfflineOffline* new_pbmsg(){ return new ::proto_ff::Sheet_OfflineOffline(); }
		static ::proto_ff::Sheet_OfflineOffline make_pbmsg(){ return ::proto_ff::Sheet_OfflineOffline(); }
	};
	typedef struct Sheet_OfflineOffline_s Sheet_OfflineOffline_t;

	struct E_OfflineItemlistItemDesc_s : public NFDescStoreSeqOP {
		E_OfflineItemlistItemDesc_s();
		virtual ~E_OfflineItemlistItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_vle;//权重
		int32_t m_num;//数量
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_OfflineItemlistItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OfflineItemlistItemDesc & msg);
		static ::proto_ff::E_OfflineItemlistItemDesc* new_pbmsg(){ return new ::proto_ff::E_OfflineItemlistItemDesc(); }
		static ::proto_ff::E_OfflineItemlistItemDesc make_pbmsg(){ return ::proto_ff::E_OfflineItemlistItemDesc(); }
	};
	typedef struct E_OfflineItemlistItemDesc_s E_OfflineItemlistItemDesc_t;

	struct E_OfflineItemlist_s : public NFDescStoreSeqOP {
		E_OfflineItemlist_s();
		virtual ~E_OfflineItemlist_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_lvdown;//等级下限
		int32_t m_lvup;//等级上限
		int32_t m_daoju;//道具类型库
		NFShmVector<struct E_OfflineItemlistItemDesc_s, DEFINE_E_OFFLINEITEMLIST_M_ITEM_MAX_NUM> m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_OfflineItemlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OfflineItemlist & msg);
		static ::proto_ff::E_OfflineItemlist* new_pbmsg(){ return new ::proto_ff::E_OfflineItemlist(); }
		static ::proto_ff::E_OfflineItemlist make_pbmsg(){ return ::proto_ff::E_OfflineItemlist(); }
	};
	typedef struct E_OfflineItemlist_s E_OfflineItemlist_t;

	struct Sheet_OfflineItemlist_s : public NFDescStoreSeqOP {
		Sheet_OfflineItemlist_s();
		virtual ~Sheet_OfflineItemlist_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OfflineItemlist_s, DEFINE_SHEET_OFFLINEITEMLIST_E_OFFLINEITEMLIST_LIST_MAX_NUM> E_OfflineItemlist_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OfflineItemlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OfflineItemlist & msg);
		static ::proto_ff::Sheet_OfflineItemlist* new_pbmsg(){ return new ::proto_ff::Sheet_OfflineItemlist(); }
		static ::proto_ff::Sheet_OfflineItemlist make_pbmsg(){ return ::proto_ff::Sheet_OfflineItemlist(); }
	};
	typedef struct Sheet_OfflineItemlist_s Sheet_OfflineItemlist_t;

}

