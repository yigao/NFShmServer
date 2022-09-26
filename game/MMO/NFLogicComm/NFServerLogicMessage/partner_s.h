#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "partner.pb.h"
#include "partner_s.h"

namespace proto_ff_s {

	struct partnerpartnerattributeDesc_s : public NFDescStoreSeqOP {
		partnerpartnerattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerpartnerattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerpartnerattributeDesc & msg);
		static ::proto_ff::partnerpartnerattributeDesc* new_pbmsg(){ return new ::proto_ff::partnerpartnerattributeDesc(); }
		static ::proto_ff::partnerpartnerattributeDesc make_pbmsg(){ return ::proto_ff::partnerpartnerattributeDesc(); }
	};
	typedef struct partnerpartnerattributeDesc_s partnerpartnerattributeDesc_t;

	struct partnerpartner_s : public NFDescStoreSeqOP {
		partnerpartner_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> resource;
		NFSizeString<60> name;
		NFSizeString<140> activeDesc;
		NFSizeString<60> partnerSkill;
		int32_t realLevel;
		int64_t materialID;
		int32_t materialEXP;
		int32_t exp;
		int64_t BreakMaterialID;
		int32_t BreakMaterialCost;
		int64_t skillID;
		int64_t aiId;
		NFArray<struct partnerpartnerattributeDesc_s, 4> attribute;
		NFArray<int64_t, 3> fragmentID;

		virtual void write_to_pbmsg(::proto_ff::partnerpartner & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerpartner & msg);
		static ::proto_ff::partnerpartner* new_pbmsg(){ return new ::proto_ff::partnerpartner(); }
		static ::proto_ff::partnerpartner make_pbmsg(){ return ::proto_ff::partnerpartner(); }
	};
	typedef struct partnerpartner_s partnerpartner_t;

	struct Sheet_partnerpartner_s : public NFDescStoreSeqOP {
		Sheet_partnerpartner_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerpartner_s, 500> partnerpartner_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerpartner & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerpartner & msg);
		static ::proto_ff::Sheet_partnerpartner* new_pbmsg(){ return new ::proto_ff::Sheet_partnerpartner(); }
		static ::proto_ff::Sheet_partnerpartner make_pbmsg(){ return ::proto_ff::Sheet_partnerpartner(); }
	};
	typedef struct Sheet_partnerpartner_s Sheet_partnerpartner_t;

	struct partnerchangeattributeDesc_s : public NFDescStoreSeqOP {
		partnerchangeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerchangeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerchangeattributeDesc & msg);
		static ::proto_ff::partnerchangeattributeDesc* new_pbmsg(){ return new ::proto_ff::partnerchangeattributeDesc(); }
		static ::proto_ff::partnerchangeattributeDesc make_pbmsg(){ return ::proto_ff::partnerchangeattributeDesc(); }
	};
	typedef struct partnerchangeattributeDesc_s partnerchangeattributeDesc_t;

	struct partnerchange_s : public NFDescStoreSeqOP {
		partnerchange_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> resource;
		NFSizeString<60> name;
		NFSizeString<120> activeDesc;
		int32_t quality;
		int64_t starId;
		NFSizeString<200> starNum;
		int32_t starUp;
		NFSizeString<80> partnerSkill;
		int32_t starBer;
		int64_t occupation;
		int64_t aiId;
		int64_t upAttributeId;
		NFArray<struct partnerchangeattributeDesc_s, 5> attribute;

		virtual void write_to_pbmsg(::proto_ff::partnerchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerchange & msg);
		static ::proto_ff::partnerchange* new_pbmsg(){ return new ::proto_ff::partnerchange(); }
		static ::proto_ff::partnerchange make_pbmsg(){ return ::proto_ff::partnerchange(); }
	};
	typedef struct partnerchange_s partnerchange_t;

	struct Sheet_partnerchange_s : public NFDescStoreSeqOP {
		Sheet_partnerchange_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerchange_s, 40> partnerchange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerchange & msg);
		static ::proto_ff::Sheet_partnerchange* new_pbmsg(){ return new ::proto_ff::Sheet_partnerchange(); }
		static ::proto_ff::Sheet_partnerchange make_pbmsg(){ return ::proto_ff::Sheet_partnerchange(); }
	};
	typedef struct Sheet_partnerchange_s Sheet_partnerchange_t;

	struct partnerstarUpupAttributeDesc_s : public NFDescStoreSeqOP {
		partnerstarUpupAttributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerstarUpupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerstarUpupAttributeDesc & msg);
		static ::proto_ff::partnerstarUpupAttributeDesc* new_pbmsg(){ return new ::proto_ff::partnerstarUpupAttributeDesc(); }
		static ::proto_ff::partnerstarUpupAttributeDesc make_pbmsg(){ return ::proto_ff::partnerstarUpupAttributeDesc(); }
	};
	typedef struct partnerstarUpupAttributeDesc_s partnerstarUpupAttributeDesc_t;

	struct partnerstarUp_s : public NFDescStoreSeqOP {
		partnerstarUp_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t upAttributeId;
		int32_t starID;
		NFArray<struct partnerstarUpupAttributeDesc_s, 2> upAttribute;

		virtual void write_to_pbmsg(::proto_ff::partnerstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerstarUp & msg);
		static ::proto_ff::partnerstarUp* new_pbmsg(){ return new ::proto_ff::partnerstarUp(); }
		static ::proto_ff::partnerstarUp make_pbmsg(){ return ::proto_ff::partnerstarUp(); }
	};
	typedef struct partnerstarUp_s partnerstarUp_t;

	struct Sheet_partnerstarUp_s : public NFDescStoreSeqOP {
		Sheet_partnerstarUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerstarUp_s, 40> partnerstarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerstarUp & msg);
		static ::proto_ff::Sheet_partnerstarUp* new_pbmsg(){ return new ::proto_ff::Sheet_partnerstarUp(); }
		static ::proto_ff::Sheet_partnerstarUp make_pbmsg(){ return ::proto_ff::Sheet_partnerstarUp(); }
	};
	typedef struct Sheet_partnerstarUp_s Sheet_partnerstarUp_t;

	struct partnerfragmentattributeDesc_s : public NFDescStoreSeqOP {
		partnerfragmentattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerfragmentattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerfragmentattributeDesc & msg);
		static ::proto_ff::partnerfragmentattributeDesc* new_pbmsg(){ return new ::proto_ff::partnerfragmentattributeDesc(); }
		static ::proto_ff::partnerfragmentattributeDesc make_pbmsg(){ return ::proto_ff::partnerfragmentattributeDesc(); }
	};
	typedef struct partnerfragmentattributeDesc_s partnerfragmentattributeDesc_t;

	struct partnerfragment_s : public NFDescStoreSeqOP {
		partnerfragment_s();
		int CreateInit();
		int ResumeInit();
		int64_t fragmentID;
		int64_t item;
		int32_t itemNum;
		NFArray<struct partnerfragmentattributeDesc_s, 3> attribute;

		virtual void write_to_pbmsg(::proto_ff::partnerfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerfragment & msg);
		static ::proto_ff::partnerfragment* new_pbmsg(){ return new ::proto_ff::partnerfragment(); }
		static ::proto_ff::partnerfragment make_pbmsg(){ return ::proto_ff::partnerfragment(); }
	};
	typedef struct partnerfragment_s partnerfragment_t;

	struct Sheet_partnerfragment_s : public NFDescStoreSeqOP {
		Sheet_partnerfragment_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerfragment_s, 20> partnerfragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerfragment & msg);
		static ::proto_ff::Sheet_partnerfragment* new_pbmsg(){ return new ::proto_ff::Sheet_partnerfragment(); }
		static ::proto_ff::Sheet_partnerfragment make_pbmsg(){ return ::proto_ff::Sheet_partnerfragment(); }
	};
	typedef struct Sheet_partnerfragment_s Sheet_partnerfragment_t;

	struct partnerattributeattributeDesc_s : public NFDescStoreSeqOP {
		partnerattributeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerattributeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerattributeattributeDesc & msg);
		static ::proto_ff::partnerattributeattributeDesc* new_pbmsg(){ return new ::proto_ff::partnerattributeattributeDesc(); }
		static ::proto_ff::partnerattributeattributeDesc make_pbmsg(){ return ::proto_ff::partnerattributeattributeDesc(); }
	};
	typedef struct partnerattributeattributeDesc_s partnerattributeattributeDesc_t;

	struct partnerattribute_s : public NFDescStoreSeqOP {
		partnerattribute_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t exp;
		NFArray<struct partnerattributeattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::partnerattribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerattribute & msg);
		static ::proto_ff::partnerattribute* new_pbmsg(){ return new ::proto_ff::partnerattribute(); }
		static ::proto_ff::partnerattribute make_pbmsg(){ return ::proto_ff::partnerattribute(); }
	};
	typedef struct partnerattribute_s partnerattribute_t;

	struct Sheet_partnerattribute_s : public NFDescStoreSeqOP {
		Sheet_partnerattribute_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerattribute_s, 2000> partnerattribute_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerattribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerattribute & msg);
		static ::proto_ff::Sheet_partnerattribute* new_pbmsg(){ return new ::proto_ff::Sheet_partnerattribute(); }
		static ::proto_ff::Sheet_partnerattribute make_pbmsg(){ return ::proto_ff::Sheet_partnerattribute(); }
	};
	typedef struct Sheet_partnerattribute_s Sheet_partnerattribute_t;

	struct partnerexp_s : public NFDescStoreSeqOP {
		partnerexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t exp;
		int32_t wearQuality;
		int32_t quality;

		virtual void write_to_pbmsg(::proto_ff::partnerexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerexp & msg);
		static ::proto_ff::partnerexp* new_pbmsg(){ return new ::proto_ff::partnerexp(); }
		static ::proto_ff::partnerexp make_pbmsg(){ return ::proto_ff::partnerexp(); }
	};
	typedef struct partnerexp_s partnerexp_t;

	struct Sheet_partnerexp_s : public NFDescStoreSeqOP {
		Sheet_partnerexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerexp_s, 200> partnerexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerexp & msg);
		static ::proto_ff::Sheet_partnerexp* new_pbmsg(){ return new ::proto_ff::Sheet_partnerexp(); }
		static ::proto_ff::Sheet_partnerexp make_pbmsg(){ return ::proto_ff::Sheet_partnerexp(); }
	};
	typedef struct Sheet_partnerexp_s Sheet_partnerexp_t;

	struct partnerequipattributeDesc_s : public NFDescStoreSeqOP {
		partnerequipattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::partnerequipattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerequipattributeDesc & msg);
		static ::proto_ff::partnerequipattributeDesc* new_pbmsg(){ return new ::proto_ff::partnerequipattributeDesc(); }
		static ::proto_ff::partnerequipattributeDesc make_pbmsg(){ return ::proto_ff::partnerequipattributeDesc(); }
	};
	typedef struct partnerequipattributeDesc_s partnerequipattributeDesc_t;

	struct partnerequip_s : public NFDescStoreSeqOP {
		partnerequip_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t position;
		int32_t refineLv;
		int32_t refineNum;
		NFArray<struct partnerequipattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::partnerequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerequip & msg);
		static ::proto_ff::partnerequip* new_pbmsg(){ return new ::proto_ff::partnerequip(); }
		static ::proto_ff::partnerequip make_pbmsg(){ return ::proto_ff::partnerequip(); }
	};
	typedef struct partnerequip_s partnerequip_t;

	struct Sheet_partnerequip_s : public NFDescStoreSeqOP {
		Sheet_partnerequip_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerequip_s, 40> partnerequip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerequip & msg);
		static ::proto_ff::Sheet_partnerequip* new_pbmsg(){ return new ::proto_ff::Sheet_partnerequip(); }
		static ::proto_ff::Sheet_partnerequip make_pbmsg(){ return ::proto_ff::Sheet_partnerequip(); }
	};
	typedef struct Sheet_partnerequip_s Sheet_partnerequip_t;

	struct partnerrefine_s : public NFDescStoreSeqOP {
		partnerrefine_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t refineId;
		int32_t refineNum;

		virtual void write_to_pbmsg(::proto_ff::partnerrefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerrefine & msg);
		static ::proto_ff::partnerrefine* new_pbmsg(){ return new ::proto_ff::partnerrefine(); }
		static ::proto_ff::partnerrefine make_pbmsg(){ return ::proto_ff::partnerrefine(); }
	};
	typedef struct partnerrefine_s partnerrefine_t;

	struct Sheet_partnerrefine_s : public NFDescStoreSeqOP {
		Sheet_partnerrefine_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerrefine_s, 200> partnerrefine_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerrefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerrefine & msg);
		static ::proto_ff::Sheet_partnerrefine* new_pbmsg(){ return new ::proto_ff::Sheet_partnerrefine(); }
		static ::proto_ff::Sheet_partnerrefine make_pbmsg(){ return ::proto_ff::Sheet_partnerrefine(); }
	};
	typedef struct Sheet_partnerrefine_s Sheet_partnerrefine_t;

	struct partnerslot_s : public NFDescStoreSeqOP {
		partnerslot_s();
		int CreateInit();
		int ResumeInit();
		int32_t position;
		int32_t refineLv;
		int32_t refineNum;

		virtual void write_to_pbmsg(::proto_ff::partnerslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::partnerslot & msg);
		static ::proto_ff::partnerslot* new_pbmsg(){ return new ::proto_ff::partnerslot(); }
		static ::proto_ff::partnerslot make_pbmsg(){ return ::proto_ff::partnerslot(); }
	};
	typedef struct partnerslot_s partnerslot_t;

	struct Sheet_partnerslot_s : public NFDescStoreSeqOP {
		Sheet_partnerslot_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct partnerslot_s, 20> partnerslot_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_partnerslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_partnerslot & msg);
		static ::proto_ff::Sheet_partnerslot* new_pbmsg(){ return new ::proto_ff::Sheet_partnerslot(); }
		static ::proto_ff::Sheet_partnerslot make_pbmsg(){ return ::proto_ff::Sheet_partnerslot(); }
	};
	typedef struct Sheet_partnerslot_s Sheet_partnerslot_t;

}

