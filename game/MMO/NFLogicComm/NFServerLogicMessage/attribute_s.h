#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "attribute.pb.h"
#include "attribute_s.h"

namespace proto_ff_s {

	struct E_AttributeAttribute_s : public NFDescStoreSeqOP {
		E_AttributeAttribute_s();
		virtual ~E_AttributeAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_percent;
		float m_power;

		virtual void write_to_pbmsg(::proto_ff::E_AttributeAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributeAttribute & msg);
		static ::proto_ff::E_AttributeAttribute* new_pbmsg(){ return new ::proto_ff::E_AttributeAttribute(); }
		static ::proto_ff::E_AttributeAttribute make_pbmsg(){ return ::proto_ff::E_AttributeAttribute(); }
	};
	typedef struct E_AttributeAttribute_s E_AttributeAttribute_t;

	struct Sheet_AttributeAttribute_s : public NFDescStoreSeqOP {
		Sheet_AttributeAttribute_s();
		virtual ~Sheet_AttributeAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributeAttribute_s, 200> E_AttributeAttribute_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributeAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributeAttribute & msg);
		static ::proto_ff::Sheet_AttributeAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_AttributeAttribute(); }
		static ::proto_ff::Sheet_AttributeAttribute make_pbmsg(){ return ::proto_ff::Sheet_AttributeAttribute(); }
	};
	typedef struct Sheet_AttributeAttribute_s Sheet_AttributeAttribute_t;

	struct E_AttributeSuppress_s : public NFDescStoreSeqOP {
		E_AttributeSuppress_s();
		virtual ~E_AttributeSuppress_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lvldiff;
		int32_t m_hitsuppve;
		int32_t m_critsuppve;
		int32_t m_killsuppve;
		int32_t m_statesuppve;
		int32_t m_lvsuppve;
		int32_t m_hitsuppvp;
		int32_t m_critsuppvp;
		int32_t m_killsuppvp;
		int32_t m_statesuppvp;
		int32_t m_lvsuppvp;

		virtual void write_to_pbmsg(::proto_ff::E_AttributeSuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributeSuppress & msg);
		static ::proto_ff::E_AttributeSuppress* new_pbmsg(){ return new ::proto_ff::E_AttributeSuppress(); }
		static ::proto_ff::E_AttributeSuppress make_pbmsg(){ return ::proto_ff::E_AttributeSuppress(); }
	};
	typedef struct E_AttributeSuppress_s E_AttributeSuppress_t;

	struct Sheet_AttributeSuppress_s : public NFDescStoreSeqOP {
		Sheet_AttributeSuppress_s();
		virtual ~Sheet_AttributeSuppress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributeSuppress_s, 600> E_AttributeSuppress_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributeSuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributeSuppress & msg);
		static ::proto_ff::Sheet_AttributeSuppress* new_pbmsg(){ return new ::proto_ff::Sheet_AttributeSuppress(); }
		static ::proto_ff::Sheet_AttributeSuppress make_pbmsg(){ return ::proto_ff::Sheet_AttributeSuppress(); }
	};
	typedef struct Sheet_AttributeSuppress_s Sheet_AttributeSuppress_t;

	struct E_AttributePowersup_s : public NFDescStoreSeqOP {
		E_AttributePowersup_s();
		virtual ~E_AttributePowersup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_powerdiff;
		int32_t m_powersuppve;
		int32_t m_powersuppvp;

		virtual void write_to_pbmsg(::proto_ff::E_AttributePowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributePowersup & msg);
		static ::proto_ff::E_AttributePowersup* new_pbmsg(){ return new ::proto_ff::E_AttributePowersup(); }
		static ::proto_ff::E_AttributePowersup make_pbmsg(){ return ::proto_ff::E_AttributePowersup(); }
	};
	typedef struct E_AttributePowersup_s E_AttributePowersup_t;

	struct Sheet_AttributePowersup_s : public NFDescStoreSeqOP {
		Sheet_AttributePowersup_s();
		virtual ~Sheet_AttributePowersup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributePowersup_s, 200> E_AttributePowersup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributePowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributePowersup & msg);
		static ::proto_ff::Sheet_AttributePowersup* new_pbmsg(){ return new ::proto_ff::Sheet_AttributePowersup(); }
		static ::proto_ff::Sheet_AttributePowersup make_pbmsg(){ return ::proto_ff::Sheet_AttributePowersup(); }
	};
	typedef struct Sheet_AttributePowersup_s Sheet_AttributePowersup_t;

}

