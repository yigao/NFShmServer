#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Title.pb.h"
#include "E_Title_s.h"

#define DEFINE_SHEET_TITLETYPE_E_TITLETYPE_LIST_MAX_NUM 8
#define DEFINE_E_TITLETITLE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_TITLETITLE_E_TITLETITLE_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_TitleType_s : public NFDescStoreSeqOP {
		E_TitleType_s();
		virtual ~E_TitleType_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//称号id

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
		NFShmVector<struct E_TitleType_s, DEFINE_SHEET_TITLETYPE_E_TITLETYPE_LIST_MAX_NUM> E_TitleType_List;//

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
		int32_t m_value;//值
		int32_t m_type;//类型

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
		int64_t m_id;//称号ID
		NFShmString<64> m_name;//称号名称
		int32_t m_type;//称号类型
		int32_t m_subType;//获取条件类型
		NFShmString<64> m_eventValue;//获取条件值
		NFShmString<256> m_describe;//获取条件描述
		int32_t m_addTime;//自动延期
		int32_t m_timeTpye;//时间类型
		int32_t m_lifeTime;//生效时间
		int64_t m_activationItem;//激活道具ID
		int32_t m_activationNum;//激活道具数量
		int64_t m_starId;//升星道具id
		NFShmString<256> m_starNum;//升星道具数量
		int32_t m_starUp;//升星等级上限
		int32_t m_starBer;//每次升星属性增加的万分比值
		NFShmVector<struct E_TitleTitleAttributeDesc_s, DEFINE_E_TITLETITLE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

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
		NFShmVector<struct E_TitleTitle_s, DEFINE_SHEET_TITLETITLE_E_TITLETITLE_LIST_MAX_NUM> E_TitleTitle_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TitleTitle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TitleTitle & msg);
		static ::proto_ff::Sheet_TitleTitle* new_pbmsg(){ return new ::proto_ff::Sheet_TitleTitle(); }
		static ::proto_ff::Sheet_TitleTitle make_pbmsg(){ return ::proto_ff::Sheet_TitleTitle(); }
	};
	typedef struct Sheet_TitleTitle_s Sheet_TitleTitle_t;

}

