#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "treasure.pb.h"
#include "treasure_s.h"

namespace proto_ff_s {

	struct treasuretreasureattributeDesc_s : public NFDescStoreSeqOP {
		treasuretreasureattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::treasuretreasureattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasuretreasureattributeDesc & msg);
		static ::proto_ff::treasuretreasureattributeDesc* new_pbmsg(){ return new ::proto_ff::treasuretreasureattributeDesc(); }
		static ::proto_ff::treasuretreasureattributeDesc make_pbmsg(){ return ::proto_ff::treasuretreasureattributeDesc(); }
	};
	typedef struct treasuretreasureattributeDesc_s treasuretreasureattributeDesc_t;

	struct treasuretreasure_s : public NFDescStoreSeqOP {
		treasuretreasure_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> resource;
		NFSizeString<32> name;
		NFSizeString<69> activeDesc;
		int32_t realLevel;
		int64_t materialID;
		int32_t materialEXP;
		int32_t exp;
		int64_t BreakMaterialID;
		int32_t BreakMaterialCost;
		int64_t skill;
		int64_t skillID;
		NFArray<struct treasuretreasureattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::treasuretreasure & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasuretreasure & msg);
		static ::proto_ff::treasuretreasure* new_pbmsg(){ return new ::proto_ff::treasuretreasure(); }
		static ::proto_ff::treasuretreasure make_pbmsg(){ return ::proto_ff::treasuretreasure(); }
	};
	typedef struct treasuretreasure_s treasuretreasure_t;

	struct Sheet_treasuretreasure_s : public NFDescStoreSeqOP {
		Sheet_treasuretreasure_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasuretreasure_s, 584> treasuretreasure_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasuretreasure & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasuretreasure & msg);
		static ::proto_ff::Sheet_treasuretreasure* new_pbmsg(){ return new ::proto_ff::Sheet_treasuretreasure(); }
		static ::proto_ff::Sheet_treasuretreasure make_pbmsg(){ return ::proto_ff::Sheet_treasuretreasure(); }
	};
	typedef struct Sheet_treasuretreasure_s Sheet_treasuretreasure_t;

	struct treasurechangeattributeDesc_s : public NFDescStoreSeqOP {
		treasurechangeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::treasurechangeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurechangeattributeDesc & msg);
		static ::proto_ff::treasurechangeattributeDesc* new_pbmsg(){ return new ::proto_ff::treasurechangeattributeDesc(); }
		static ::proto_ff::treasurechangeattributeDesc make_pbmsg(){ return ::proto_ff::treasurechangeattributeDesc(); }
	};
	typedef struct treasurechangeattributeDesc_s treasurechangeattributeDesc_t;

	struct treasurechange_s : public NFDescStoreSeqOP {
		treasurechange_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> resource;
		NFSizeString<32> name;
		NFSizeString<75> activeDesc;
		int32_t quality;
		int64_t starId;
		NFSizeString<151> starNum;
		int32_t starUp;
		int32_t starBer;
		int64_t occupation;
		int64_t skill;
		int64_t upAttributeId;
		NFArray<struct treasurechangeattributeDesc_s, 5> attribute;

		virtual void write_to_pbmsg(::proto_ff::treasurechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurechange & msg);
		static ::proto_ff::treasurechange* new_pbmsg(){ return new ::proto_ff::treasurechange(); }
		static ::proto_ff::treasurechange make_pbmsg(){ return ::proto_ff::treasurechange(); }
	};
	typedef struct treasurechange_s treasurechange_t;

	struct Sheet_treasurechange_s : public NFDescStoreSeqOP {
		Sheet_treasurechange_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasurechange_s, 110> treasurechange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasurechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasurechange & msg);
		static ::proto_ff::Sheet_treasurechange* new_pbmsg(){ return new ::proto_ff::Sheet_treasurechange(); }
		static ::proto_ff::Sheet_treasurechange make_pbmsg(){ return ::proto_ff::Sheet_treasurechange(); }
	};
	typedef struct Sheet_treasurechange_s Sheet_treasurechange_t;

	struct treasurestarUpupAttributeDesc_s : public NFDescStoreSeqOP {
		treasurestarUpupAttributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::treasurestarUpupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurestarUpupAttributeDesc & msg);
		static ::proto_ff::treasurestarUpupAttributeDesc* new_pbmsg(){ return new ::proto_ff::treasurestarUpupAttributeDesc(); }
		static ::proto_ff::treasurestarUpupAttributeDesc make_pbmsg(){ return ::proto_ff::treasurestarUpupAttributeDesc(); }
	};
	typedef struct treasurestarUpupAttributeDesc_s treasurestarUpupAttributeDesc_t;

	struct treasurestarUp_s : public NFDescStoreSeqOP {
		treasurestarUp_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t upAttributeId;
		int32_t starID;
		NFArray<struct treasurestarUpupAttributeDesc_s, 2> upAttribute;

		virtual void write_to_pbmsg(::proto_ff::treasurestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurestarUp & msg);
		static ::proto_ff::treasurestarUp* new_pbmsg(){ return new ::proto_ff::treasurestarUp(); }
		static ::proto_ff::treasurestarUp make_pbmsg(){ return ::proto_ff::treasurestarUp(); }
	};
	typedef struct treasurestarUp_s treasurestarUp_t;

	struct Sheet_treasurestarUp_s : public NFDescStoreSeqOP {
		Sheet_treasurestarUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasurestarUp_s, 116> treasurestarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasurestarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasurestarUp & msg);
		static ::proto_ff::Sheet_treasurestarUp* new_pbmsg(){ return new ::proto_ff::Sheet_treasurestarUp(); }
		static ::proto_ff::Sheet_treasurestarUp make_pbmsg(){ return ::proto_ff::Sheet_treasurestarUp(); }
	};
	typedef struct Sheet_treasurestarUp_s Sheet_treasurestarUp_t;

	struct treasurefragmentattributeDesc_s : public NFDescStoreSeqOP {
		treasurefragmentattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::treasurefragmentattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurefragmentattributeDesc & msg);
		static ::proto_ff::treasurefragmentattributeDesc* new_pbmsg(){ return new ::proto_ff::treasurefragmentattributeDesc(); }
		static ::proto_ff::treasurefragmentattributeDesc make_pbmsg(){ return ::proto_ff::treasurefragmentattributeDesc(); }
	};
	typedef struct treasurefragmentattributeDesc_s treasurefragmentattributeDesc_t;

	struct treasurefragment_s : public NFDescStoreSeqOP {
		treasurefragment_s();
		int CreateInit();
		int ResumeInit();
		int64_t fragmentID;
		int64_t item;
		int32_t itemNum;
		NFArray<struct treasurefragmentattributeDesc_s, 3> attribute;

		virtual void write_to_pbmsg(::proto_ff::treasurefragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurefragment & msg);
		static ::proto_ff::treasurefragment* new_pbmsg(){ return new ::proto_ff::treasurefragment(); }
		static ::proto_ff::treasurefragment make_pbmsg(){ return ::proto_ff::treasurefragment(); }
	};
	typedef struct treasurefragment_s treasurefragment_t;

	struct Sheet_treasurefragment_s : public NFDescStoreSeqOP {
		Sheet_treasurefragment_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasurefragment_s, 107> treasurefragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasurefragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasurefragment & msg);
		static ::proto_ff::Sheet_treasurefragment* new_pbmsg(){ return new ::proto_ff::Sheet_treasurefragment(); }
		static ::proto_ff::Sheet_treasurefragment make_pbmsg(){ return ::proto_ff::Sheet_treasurefragment(); }
	};
	typedef struct Sheet_treasurefragment_s Sheet_treasurefragment_t;

	struct treasureequipattributeDesc_s : public NFDescStoreSeqOP {
		treasureequipattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::treasureequipattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasureequipattributeDesc & msg);
		static ::proto_ff::treasureequipattributeDesc* new_pbmsg(){ return new ::proto_ff::treasureequipattributeDesc(); }
		static ::proto_ff::treasureequipattributeDesc make_pbmsg(){ return ::proto_ff::treasureequipattributeDesc(); }
	};
	typedef struct treasureequipattributeDesc_s treasureequipattributeDesc_t;

	struct treasureequip_s : public NFDescStoreSeqOP {
		treasureequip_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		NFArray<struct treasureequipattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::treasureequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasureequip & msg);
		static ::proto_ff::treasureequip* new_pbmsg(){ return new ::proto_ff::treasureequip(); }
		static ::proto_ff::treasureequip make_pbmsg(){ return ::proto_ff::treasureequip(); }
	};
	typedef struct treasureequip_s treasureequip_t;

	struct Sheet_treasureequip_s : public NFDescStoreSeqOP {
		Sheet_treasureequip_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasureequip_s, 124> treasureequip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasureequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasureequip & msg);
		static ::proto_ff::Sheet_treasureequip* new_pbmsg(){ return new ::proto_ff::Sheet_treasureequip(); }
		static ::proto_ff::Sheet_treasureequip make_pbmsg(){ return ::proto_ff::Sheet_treasureequip(); }
	};
	typedef struct Sheet_treasureequip_s Sheet_treasureequip_t;

	struct treasureslot_s : public NFDescStoreSeqOP {
		treasureslot_s();
		int CreateInit();
		int ResumeInit();
		int32_t position;
		int32_t refineLv;
		int32_t refineNum;

		virtual void write_to_pbmsg(::proto_ff::treasureslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasureslot & msg);
		static ::proto_ff::treasureslot* new_pbmsg(){ return new ::proto_ff::treasureslot(); }
		static ::proto_ff::treasureslot make_pbmsg(){ return ::proto_ff::treasureslot(); }
	};
	typedef struct treasureslot_s treasureslot_t;

	struct Sheet_treasureslot_s : public NFDescStoreSeqOP {
		Sheet_treasureslot_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasureslot_s, 108> treasureslot_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasureslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasureslot & msg);
		static ::proto_ff::Sheet_treasureslot* new_pbmsg(){ return new ::proto_ff::Sheet_treasureslot(); }
		static ::proto_ff::Sheet_treasureslot make_pbmsg(){ return ::proto_ff::Sheet_treasureslot(); }
	};
	typedef struct Sheet_treasureslot_s Sheet_treasureslot_t;

	struct treasurerefine_s : public NFDescStoreSeqOP {
		treasurerefine_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t refineId;
		int32_t refineNum;

		virtual void write_to_pbmsg(::proto_ff::treasurerefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasurerefine & msg);
		static ::proto_ff::treasurerefine* new_pbmsg(){ return new ::proto_ff::treasurerefine(); }
		static ::proto_ff::treasurerefine make_pbmsg(){ return ::proto_ff::treasurerefine(); }
	};
	typedef struct treasurerefine_s treasurerefine_t;

	struct Sheet_treasurerefine_s : public NFDescStoreSeqOP {
		Sheet_treasurerefine_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasurerefine_s, 204> treasurerefine_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasurerefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasurerefine & msg);
		static ::proto_ff::Sheet_treasurerefine* new_pbmsg(){ return new ::proto_ff::Sheet_treasurerefine(); }
		static ::proto_ff::Sheet_treasurerefine make_pbmsg(){ return ::proto_ff::Sheet_treasurerefine(); }
	};
	typedef struct Sheet_treasurerefine_s Sheet_treasurerefine_t;

}

