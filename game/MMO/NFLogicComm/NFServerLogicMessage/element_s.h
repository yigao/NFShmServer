#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "element.pb.h"
#include "element_s.h"

namespace proto_ff_s {

	struct elementelement_s : public NFDescStoreSeqOP {
		elementelement_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> resource;
		int32_t type;
		int32_t level;
		int32_t exp;
		int64_t skillID;
		NFArray<int32_t, 2> attribute_type;
		NFArray<int32_t, 3> material_exp;
		NFArray<int64_t, 3> fragmentID;
		NFArray<int64_t, 3> material_id;
		NFArray<int32_t, 2> attribute_value;

		virtual void write_to_pbmsg(::proto_ff::elementelement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementelement & msg);
		static ::proto_ff::elementelement* new_pbmsg(){ return new ::proto_ff::elementelement(); }
		static ::proto_ff::elementelement make_pbmsg(){ return ::proto_ff::elementelement(); }
	};
	typedef struct elementelement_s elementelement_t;

	struct Sheet_elementelement_s : public NFDescStoreSeqOP {
		Sheet_elementelement_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct elementelement_s, 2000> elementelement_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_elementelement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_elementelement & msg);
		static ::proto_ff::Sheet_elementelement* new_pbmsg(){ return new ::proto_ff::Sheet_elementelement(); }
		static ::proto_ff::Sheet_elementelement make_pbmsg(){ return ::proto_ff::Sheet_elementelement(); }
	};
	typedef struct Sheet_elementelement_s Sheet_elementelement_t;

	struct elementfragment_s : public NFDescStoreSeqOP {
		elementfragment_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int64_t itemID;
		int32_t itemNum;
		NFArray<int32_t, 3> attribute_type;
		NFArray<int32_t, 3> attribute_value;

		virtual void write_to_pbmsg(::proto_ff::elementfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementfragment & msg);
		static ::proto_ff::elementfragment* new_pbmsg(){ return new ::proto_ff::elementfragment(); }
		static ::proto_ff::elementfragment make_pbmsg(){ return ::proto_ff::elementfragment(); }
	};
	typedef struct elementfragment_s elementfragment_t;

	struct Sheet_elementfragment_s : public NFDescStoreSeqOP {
		Sheet_elementfragment_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct elementfragment_s, 20> elementfragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_elementfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_elementfragment & msg);
		static ::proto_ff::Sheet_elementfragment* new_pbmsg(){ return new ::proto_ff::Sheet_elementfragment(); }
		static ::proto_ff::Sheet_elementfragment make_pbmsg(){ return ::proto_ff::Sheet_elementfragment(); }
	};
	typedef struct Sheet_elementfragment_s Sheet_elementfragment_t;

	struct elementelementUI_s : public NFDescStoreSeqOP {
		elementelementUI_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::elementelementUI & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementelementUI & msg);
		static ::proto_ff::elementelementUI* new_pbmsg(){ return new ::proto_ff::elementelementUI(); }
		static ::proto_ff::elementelementUI make_pbmsg(){ return ::proto_ff::elementelementUI(); }
	};
	typedef struct elementelementUI_s elementelementUI_t;

	struct Sheet_elementelementUI_s : public NFDescStoreSeqOP {
		Sheet_elementelementUI_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct elementelementUI_s, 20> elementelementUI_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_elementelementUI & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_elementelementUI & msg);
		static ::proto_ff::Sheet_elementelementUI* new_pbmsg(){ return new ::proto_ff::Sheet_elementelementUI(); }
		static ::proto_ff::Sheet_elementelementUI make_pbmsg(){ return ::proto_ff::Sheet_elementelementUI(); }
	};
	typedef struct Sheet_elementelementUI_s Sheet_elementelementUI_t;

}

