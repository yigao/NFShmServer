#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "collect.pb.h"
#include "collect_s.h"

namespace proto_ff_s {

	struct E_CollectCollectAttributDesc_s : public NFDescStoreSeqOP {
		E_CollectCollectAttributDesc_s();
		virtual ~E_CollectCollectAttributDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_CollectCollectAttributDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectCollectAttributDesc & msg);
		static ::proto_ff::E_CollectCollectAttributDesc* new_pbmsg(){ return new ::proto_ff::E_CollectCollectAttributDesc(); }
		static ::proto_ff::E_CollectCollectAttributDesc make_pbmsg(){ return ::proto_ff::E_CollectCollectAttributDesc(); }
	};
	typedef struct E_CollectCollectAttributDesc_s E_CollectCollectAttributDesc_t;

	struct E_CollectCollect_s : public NFDescStoreSeqOP {
		E_CollectCollect_s();
		virtual ~E_CollectCollect_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;
		int32_t m_lv;
		int32_t m_group;
		NFShmString<60> m_stagetitle;
		NFShmString<60> m_position;
		int32_t m_grade;
		int32_t m_quality;
		int32_t m_star;
		int32_t m_skillid;
		NFShmVector<struct E_CollectCollectAttributDesc_s, 4> m_attribut;

		virtual void write_to_pbmsg(::proto_ff::E_CollectCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectCollect & msg);
		static ::proto_ff::E_CollectCollect* new_pbmsg(){ return new ::proto_ff::E_CollectCollect(); }
		static ::proto_ff::E_CollectCollect make_pbmsg(){ return ::proto_ff::E_CollectCollect(); }
	};
	typedef struct E_CollectCollect_s E_CollectCollect_t;

	struct Sheet_CollectCollect_s : public NFDescStoreSeqOP {
		Sheet_CollectCollect_s();
		virtual ~Sheet_CollectCollect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CollectCollect_s, 60> E_CollectCollect_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_CollectCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CollectCollect & msg);
		static ::proto_ff::Sheet_CollectCollect* new_pbmsg(){ return new ::proto_ff::Sheet_CollectCollect(); }
		static ::proto_ff::Sheet_CollectCollect make_pbmsg(){ return ::proto_ff::Sheet_CollectCollect(); }
	};
	typedef struct Sheet_CollectCollect_s Sheet_CollectCollect_t;

	struct E_CollectAttributetpyeAttributeDesc_s : public NFDescStoreSeqOP {
		E_CollectAttributetpyeAttributeDesc_s();
		virtual ~E_CollectAttributetpyeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_CollectAttributetpyeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectAttributetpyeAttributeDesc & msg);
		static ::proto_ff::E_CollectAttributetpyeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CollectAttributetpyeAttributeDesc(); }
		static ::proto_ff::E_CollectAttributetpyeAttributeDesc make_pbmsg(){ return ::proto_ff::E_CollectAttributetpyeAttributeDesc(); }
	};
	typedef struct E_CollectAttributetpyeAttributeDesc_s E_CollectAttributetpyeAttributeDesc_t;

	struct E_CollectAttributetpye_s : public NFDescStoreSeqOP {
		E_CollectAttributetpye_s();
		virtual ~E_CollectAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmVector<struct E_CollectAttributetpyeAttributeDesc_s, 3> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_CollectAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectAttributetpye & msg);
		static ::proto_ff::E_CollectAttributetpye* new_pbmsg(){ return new ::proto_ff::E_CollectAttributetpye(); }
		static ::proto_ff::E_CollectAttributetpye make_pbmsg(){ return ::proto_ff::E_CollectAttributetpye(); }
	};
	typedef struct E_CollectAttributetpye_s E_CollectAttributetpye_t;

	struct Sheet_CollectAttributetpye_s : public NFDescStoreSeqOP {
		Sheet_CollectAttributetpye_s();
		virtual ~Sheet_CollectAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CollectAttributetpye_s, 200> E_CollectAttributetpye_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_CollectAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CollectAttributetpye & msg);
		static ::proto_ff::Sheet_CollectAttributetpye* new_pbmsg(){ return new ::proto_ff::Sheet_CollectAttributetpye(); }
		static ::proto_ff::Sheet_CollectAttributetpye make_pbmsg(){ return ::proto_ff::Sheet_CollectAttributetpye(); }
	};
	typedef struct Sheet_CollectAttributetpye_s Sheet_CollectAttributetpye_t;

}

