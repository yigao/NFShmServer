#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "element.pb.h"
#include "element_s.h"

namespace proto_ff_s {

	struct elementelementattributeDesc_s : public NFDescStoreSeqOP {
		elementelementattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::elementelementattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementelementattributeDesc & msg);
		static ::proto_ff::elementelementattributeDesc* new_pbmsg(){ return new ::proto_ff::elementelementattributeDesc(); }
		static ::proto_ff::elementelementattributeDesc make_pbmsg(){ return ::proto_ff::elementelementattributeDesc(); }
	};
	typedef struct elementelementattributeDesc_s elementelementattributeDesc_t;

	struct elementelementmaterialDesc_s : public NFDescStoreSeqOP {
		elementelementmaterialDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::elementelementmaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementelementmaterialDesc & msg);
		static ::proto_ff::elementelementmaterialDesc* new_pbmsg(){ return new ::proto_ff::elementelementmaterialDesc(); }
		static ::proto_ff::elementelementmaterialDesc make_pbmsg(){ return ::proto_ff::elementelementmaterialDesc(); }
	};
	typedef struct elementelementmaterialDesc_s elementelementmaterialDesc_t;

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
		NFArray<struct elementelementattributeDesc_s, 2> attribute;
		NFArray<struct elementelementmaterialDesc_s, 3> material;
		NFArray<int64_t, 3> fragmentID;

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

	struct elementfragmentattributeDesc_s : public NFDescStoreSeqOP {
		elementfragmentattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::elementfragmentattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::elementfragmentattributeDesc & msg);
		static ::proto_ff::elementfragmentattributeDesc* new_pbmsg(){ return new ::proto_ff::elementfragmentattributeDesc(); }
		static ::proto_ff::elementfragmentattributeDesc make_pbmsg(){ return ::proto_ff::elementfragmentattributeDesc(); }
	};
	typedef struct elementfragmentattributeDesc_s elementfragmentattributeDesc_t;

	struct elementfragment_s : public NFDescStoreSeqOP {
		elementfragment_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int64_t itemID;
		int32_t itemNum;
		NFArray<struct elementfragmentattributeDesc_s, 3> attribute;

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

