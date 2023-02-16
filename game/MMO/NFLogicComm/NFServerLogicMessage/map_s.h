#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "map.pb.h"
#include "map_s.h"

namespace proto_ff_s {

	struct E_MapMap_s : public NFDescStoreSeqOP {
		E_MapMap_s();
		virtual ~E_MapMap_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_mapid;
		int32_t m_levellimit;
		NFShmString<60> m_advicelv;
		int32_t m_maptype;
		int32_t m_mapsubtype;
		int32_t m_clearancetime;
		int32_t m_mappkmode;
		int32_t m_pklock;
		int32_t m_pk;
		int32_t m_killvalue;
		int32_t m_bangroup;
		int32_t m_revivetime;
		int32_t m_mapwide;
		int32_t m_mapheight;
		NFShmString<60> m_mapresources;
		int64_t m_reviveskill;
		int32_t m_reviveinplacetype;
		int32_t m_ishangup;
		int32_t m_itemdroptype;
		NFShmString<60> m_itemdropid;
		int64_t m_linkoffline;
		int32_t m_banonhook;
		int32_t m_rewait;
		int32_t m_retime;
		int32_t m_hreban;
		int32_t m_retiered;
		int32_t m_reskillid;
		int32_t m_reteimes;
		int32_t m_drivepoint;
		int32_t m_diedp;
		int32_t m_timedp;
		int32_t m_meditation;

		virtual void write_to_pbmsg(::proto_ff::E_MapMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapMap & msg);
		static ::proto_ff::E_MapMap* new_pbmsg(){ return new ::proto_ff::E_MapMap(); }
		static ::proto_ff::E_MapMap make_pbmsg(){ return ::proto_ff::E_MapMap(); }
	};
	typedef struct E_MapMap_s E_MapMap_t;

	struct Sheet_MapMap_s : public NFDescStoreSeqOP {
		Sheet_MapMap_s();
		virtual ~Sheet_MapMap_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapMap_s, 40> E_MapMap_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapMap & msg);
		static ::proto_ff::Sheet_MapMap* new_pbmsg(){ return new ::proto_ff::Sheet_MapMap(); }
		static ::proto_ff::Sheet_MapMap make_pbmsg(){ return ::proto_ff::Sheet_MapMap(); }
	};
	typedef struct Sheet_MapMap_s Sheet_MapMap_t;

	struct E_MapItemdrop_s : public NFDescStoreSeqOP {
		E_MapItemdrop_s();
		virtual ~E_MapItemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_itemdropid;
		int32_t m_droptype;
		int32_t m_odds;
		int32_t m_dropvaluea;
		int32_t m_dropvalueb;
		int32_t m_dropvaluec;
		int32_t m_dropvalued;
		int32_t m_dropvaluee;
		int32_t m_dropvaluef;

		virtual void write_to_pbmsg(::proto_ff::E_MapItemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapItemdrop & msg);
		static ::proto_ff::E_MapItemdrop* new_pbmsg(){ return new ::proto_ff::E_MapItemdrop(); }
		static ::proto_ff::E_MapItemdrop make_pbmsg(){ return ::proto_ff::E_MapItemdrop(); }
	};
	typedef struct E_MapItemdrop_s E_MapItemdrop_t;

	struct Sheet_MapItemdrop_s : public NFDescStoreSeqOP {
		Sheet_MapItemdrop_s();
		virtual ~Sheet_MapItemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapItemdrop_s, 40> E_MapItemdrop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapItemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapItemdrop & msg);
		static ::proto_ff::Sheet_MapItemdrop* new_pbmsg(){ return new ::proto_ff::Sheet_MapItemdrop(); }
		static ::proto_ff::Sheet_MapItemdrop make_pbmsg(){ return ::proto_ff::Sheet_MapItemdrop(); }
	};
	typedef struct Sheet_MapItemdrop_s Sheet_MapItemdrop_t;

	struct E_MapDestroyitem_s : public NFDescStoreSeqOP {
		E_MapDestroyitem_s();
		virtual ~E_MapDestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_destroyitemid;

		virtual void write_to_pbmsg(::proto_ff::E_MapDestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapDestroyitem & msg);
		static ::proto_ff::E_MapDestroyitem* new_pbmsg(){ return new ::proto_ff::E_MapDestroyitem(); }
		static ::proto_ff::E_MapDestroyitem make_pbmsg(){ return ::proto_ff::E_MapDestroyitem(); }
	};
	typedef struct E_MapDestroyitem_s E_MapDestroyitem_t;

	struct Sheet_MapDestroyitem_s : public NFDescStoreSeqOP {
		Sheet_MapDestroyitem_s();
		virtual ~Sheet_MapDestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapDestroyitem_s, 200> E_MapDestroyitem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapDestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapDestroyitem & msg);
		static ::proto_ff::Sheet_MapDestroyitem* new_pbmsg(){ return new ::proto_ff::Sheet_MapDestroyitem(); }
		static ::proto_ff::Sheet_MapDestroyitem make_pbmsg(){ return ::proto_ff::Sheet_MapDestroyitem(); }
	};
	typedef struct Sheet_MapDestroyitem_s Sheet_MapDestroyitem_t;

}

