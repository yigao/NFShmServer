#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "title.pb.h"
#include "title_s.h"

#define DEFINE_SHEET_TITLETYPE_E_TITLETYPE_LIST_MAX_NUM 20
#define DEFINE_E_TITLETITLE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_TITLETITLE_E_TITLETITLE_LIST_MAX_NUM 40
namespace proto_ff_s {

	struct E_TitleType_s : public NFDescStoreSeqOP {
		E_TitleType_s();
		virtual ~E_TitleType_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_TitleType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TitleType & msg);
		static ::proto_ff::E_TitleType* new_pbmsg(){ return new ::proto_ff::E_TitleType(); }
		static ::proto_ff::E_TitleType make_pbmsg(){ return ::proto_ff::E_TitleType(); }
	};
	typedef struct E_TitleType_s E_TitleType_t;

	struct Sheet_TitleType_s : public NFDescStoreSeqOP {
		Sheet_TitleType_s();
		virtual ~Sheet_TitleType_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TitleType_s, DEFINE_SHEET_TITLETYPE_E_TITLETYPE_LIST_MAX_NUM> E_TitleType_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TitleType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TitleType & msg);
		static ::proto_ff::Sheet_TitleType* new_pbmsg(){ return new ::proto_ff::Sheet_TitleType(); }
		static ::proto_ff::Sheet_TitleType make_pbmsg(){ return ::proto_ff::Sheet_TitleType(); }
	};
	typedef struct Sheet_TitleType_s Sheet_TitleType_t;

	struct E_TitleTitleAttributeDesc_s : public NFDescStoreSeqOP {
		E_TitleTitleAttributeDesc_s();
		virtual ~E_TitleTitleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_TitleTitleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TitleTitleAttributeDesc & msg);
		static ::proto_ff::E_TitleTitleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_TitleTitleAttributeDesc(); }
		static ::proto_ff::E_TitleTitleAttributeDesc make_pbmsg(){ return ::proto_ff::E_TitleTitleAttributeDesc(); }
	};
	typedef struct E_TitleTitleAttributeDesc_s E_TitleTitleAttributeDesc_t;

	struct E_TitleTitle_s : public NFDescStoreSeqOP {
		E_TitleTitle_s();
		virtual ~E_TitleTitle_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_name;
		int32_t m_type;
		int32_t m_subtype;
		NFShmString<60> m_eventvalue;
		NFShmString<80> m_describe;
		int32_t m_addtime;
		int32_t m_timetpye;
		int32_t m_lifetime;
		int64_t m_activationitem;
		int32_t m_activationnum;
		int64_t m_starid;
		NFShmString<300> m_starnum;
		int32_t m_starup;
		int32_t m_starber;
		NFShmVector<struct E_TitleTitleAttributeDesc_s, DEFINE_E_TITLETITLE_M_ATTRIBUTE_MAX_NUM> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_TitleTitle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TitleTitle & msg);
		static ::proto_ff::E_TitleTitle* new_pbmsg(){ return new ::proto_ff::E_TitleTitle(); }
		static ::proto_ff::E_TitleTitle make_pbmsg(){ return ::proto_ff::E_TitleTitle(); }
	};
	typedef struct E_TitleTitle_s E_TitleTitle_t;

	struct Sheet_TitleTitle_s : public NFDescStoreSeqOP {
		Sheet_TitleTitle_s();
		virtual ~Sheet_TitleTitle_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TitleTitle_s, DEFINE_SHEET_TITLETITLE_E_TITLETITLE_LIST_MAX_NUM> E_TitleTitle_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TitleTitle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TitleTitle & msg);
		static ::proto_ff::Sheet_TitleTitle* new_pbmsg(){ return new ::proto_ff::Sheet_TitleTitle(); }
		static ::proto_ff::Sheet_TitleTitle make_pbmsg(){ return ::proto_ff::Sheet_TitleTitle(); }
	};
	typedef struct Sheet_TitleTitle_s Sheet_TitleTitle_t;

}

