#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "mount.pb.h"
#include "mount_s.h"

namespace proto_ff_s {

	struct E_MountFragmentAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountFragmentAttributeDesc_s();
		virtual ~E_MountFragmentAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MountFragmentAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountFragmentAttributeDesc & msg);
		static ::proto_ff::E_MountFragmentAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountFragmentAttributeDesc(); }
		static ::proto_ff::E_MountFragmentAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountFragmentAttributeDesc(); }
	};
	typedef struct E_MountFragmentAttributeDesc_s E_MountFragmentAttributeDesc_t;

	struct E_MountFragment_s : public NFDescStoreSeqOP {
		E_MountFragment_s();
		virtual ~E_MountFragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fragmentid;
		int64_t m_item;
		int32_t m_itemnum;
		NFShmVector<struct E_MountFragmentAttributeDesc_s, 5> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_MountFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountFragment & msg);
		static ::proto_ff::E_MountFragment* new_pbmsg(){ return new ::proto_ff::E_MountFragment(); }
		static ::proto_ff::E_MountFragment make_pbmsg(){ return ::proto_ff::E_MountFragment(); }
	};
	typedef struct E_MountFragment_s E_MountFragment_t;

	struct Sheet_MountFragment_s : public NFDescStoreSeqOP {
		Sheet_MountFragment_s();
		virtual ~Sheet_MountFragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountFragment_s, 20> E_MountFragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountFragment & msg);
		static ::proto_ff::Sheet_MountFragment* new_pbmsg(){ return new ::proto_ff::Sheet_MountFragment(); }
		static ::proto_ff::Sheet_MountFragment make_pbmsg(){ return ::proto_ff::Sheet_MountFragment(); }
	};
	typedef struct Sheet_MountFragment_s Sheet_MountFragment_t;

	struct E_MountValueAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountValueAttributeDesc_s();
		virtual ~E_MountValueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MountValueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountValueAttributeDesc & msg);
		static ::proto_ff::E_MountValueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountValueAttributeDesc(); }
		static ::proto_ff::E_MountValueAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountValueAttributeDesc(); }
	};
	typedef struct E_MountValueAttributeDesc_s E_MountValueAttributeDesc_t;

	struct E_MountValue_s : public NFDescStoreSeqOP {
		E_MountValue_s();
		virtual ~E_MountValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_lv;
		int32_t m_exp;
		int32_t m_speed;
		NFShmVector<struct E_MountValueAttributeDesc_s, 9> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_MountValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountValue & msg);
		static ::proto_ff::E_MountValue* new_pbmsg(){ return new ::proto_ff::E_MountValue(); }
		static ::proto_ff::E_MountValue make_pbmsg(){ return ::proto_ff::E_MountValue(); }
	};
	typedef struct E_MountValue_s E_MountValue_t;

	struct Sheet_MountValue_s : public NFDescStoreSeqOP {
		Sheet_MountValue_s();
		virtual ~Sheet_MountValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountValue_s, 300> E_MountValue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountValue & msg);
		static ::proto_ff::Sheet_MountValue* new_pbmsg(){ return new ::proto_ff::Sheet_MountValue(); }
		static ::proto_ff::Sheet_MountValue make_pbmsg(){ return ::proto_ff::Sheet_MountValue(); }
	};
	typedef struct Sheet_MountValue_s Sheet_MountValue_t;

	struct E_MountDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountDisplayMaterialDesc_s();
		virtual ~E_MountDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_MountDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountDisplayMaterialDesc & msg);
		static ::proto_ff::E_MountDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountDisplayMaterialDesc(); }
		static ::proto_ff::E_MountDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountDisplayMaterialDesc(); }
	};
	typedef struct E_MountDisplayMaterialDesc_s E_MountDisplayMaterialDesc_t;

	struct E_MountDisplay_s : public NFDescStoreSeqOP {
		E_MountDisplay_s();
		virtual ~E_MountDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_speed;
		int32_t m_uplvtype;
		NFShmString<60> m_skillid;
		NFShmString<60> m_fxid;
		int32_t m_starup;
		int32_t m_lvmax;
		NFShmVector<struct E_MountDisplayMaterialDesc_s, 2> m_material;
		NFShmVector<int64_t, 3> m_fragmentid;

		virtual void write_to_pbmsg(::proto_ff::E_MountDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountDisplay & msg);
		static ::proto_ff::E_MountDisplay* new_pbmsg(){ return new ::proto_ff::E_MountDisplay(); }
		static ::proto_ff::E_MountDisplay make_pbmsg(){ return ::proto_ff::E_MountDisplay(); }
	};
	typedef struct E_MountDisplay_s E_MountDisplay_t;

	struct Sheet_MountDisplay_s : public NFDescStoreSeqOP {
		Sheet_MountDisplay_s();
		virtual ~Sheet_MountDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountDisplay_s, 20> E_MountDisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountDisplay & msg);
		static ::proto_ff::Sheet_MountDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_MountDisplay(); }
		static ::proto_ff::Sheet_MountDisplay make_pbmsg(){ return ::proto_ff::Sheet_MountDisplay(); }
	};
	typedef struct Sheet_MountDisplay_s Sheet_MountDisplay_t;

	struct E_MountUnlock_s : public NFDescStoreSeqOP {
		E_MountUnlock_s();
		virtual ~E_MountUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_lv;
		int32_t m_modelid;

		virtual void write_to_pbmsg(::proto_ff::E_MountUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountUnlock & msg);
		static ::proto_ff::E_MountUnlock* new_pbmsg(){ return new ::proto_ff::E_MountUnlock(); }
		static ::proto_ff::E_MountUnlock make_pbmsg(){ return ::proto_ff::E_MountUnlock(); }
	};
	typedef struct E_MountUnlock_s E_MountUnlock_t;

	struct Sheet_MountUnlock_s : public NFDescStoreSeqOP {
		Sheet_MountUnlock_s();
		virtual ~Sheet_MountUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountUnlock_s, 20> E_MountUnlock_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountUnlock & msg);
		static ::proto_ff::Sheet_MountUnlock* new_pbmsg(){ return new ::proto_ff::Sheet_MountUnlock(); }
		static ::proto_ff::Sheet_MountUnlock make_pbmsg(){ return ::proto_ff::Sheet_MountUnlock(); }
	};
	typedef struct Sheet_MountUnlock_s Sheet_MountUnlock_t;

	struct E_MountChangeAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountChangeAttributeDesc_s();
		virtual ~E_MountChangeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_upvalue;
		int32_t m_upber;

		virtual void write_to_pbmsg(::proto_ff::E_MountChangeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChangeAttributeDesc & msg);
		static ::proto_ff::E_MountChangeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountChangeAttributeDesc(); }
		static ::proto_ff::E_MountChangeAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountChangeAttributeDesc(); }
	};
	typedef struct E_MountChangeAttributeDesc_s E_MountChangeAttributeDesc_t;

	struct E_MountChangeMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountChangeMaterialDesc_s();
		virtual ~E_MountChangeMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_MountChangeMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChangeMaterialDesc & msg);
		static ::proto_ff::E_MountChangeMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountChangeMaterialDesc(); }
		static ::proto_ff::E_MountChangeMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountChangeMaterialDesc(); }
	};
	typedef struct E_MountChangeMaterialDesc_s E_MountChangeMaterialDesc_t;

	struct E_MountChange_s : public NFDescStoreSeqOP {
		E_MountChange_s();
		virtual ~E_MountChange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_speed;
		int32_t m_uplvtype;
		int32_t m_activeskill;
		NFShmString<60> m_skillid;
		NFShmString<60> m_fxid;
		int32_t m_starmax;
		int32_t m_lvmax;
		int32_t m_modelid;
		int32_t m_activationitem;
		int32_t m_activationnum;
		int32_t m_starid;
		NFShmString<60> m_starnum;
		int32_t m_starber;
		int32_t m_upattributeid;
		NFShmVector<struct E_MountChangeAttributeDesc_s, 4> m_attribute;
		NFShmVector<struct E_MountChangeMaterialDesc_s, 2> m_material;

		virtual void write_to_pbmsg(::proto_ff::E_MountChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChange & msg);
		static ::proto_ff::E_MountChange* new_pbmsg(){ return new ::proto_ff::E_MountChange(); }
		static ::proto_ff::E_MountChange make_pbmsg(){ return ::proto_ff::E_MountChange(); }
	};
	typedef struct E_MountChange_s E_MountChange_t;

	struct Sheet_MountChange_s : public NFDescStoreSeqOP {
		Sheet_MountChange_s();
		virtual ~Sheet_MountChange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountChange_s, 20> E_MountChange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountChange & msg);
		static ::proto_ff::Sheet_MountChange* new_pbmsg(){ return new ::proto_ff::Sheet_MountChange(); }
		static ::proto_ff::Sheet_MountChange make_pbmsg(){ return ::proto_ff::Sheet_MountChange(); }
	};
	typedef struct Sheet_MountChange_s Sheet_MountChange_t;

	struct E_MountAdvanceUpattributeDesc_s : public NFDescStoreSeqOP {
		E_MountAdvanceUpattributeDesc_s();
		virtual ~E_MountAdvanceUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MountAdvanceUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountAdvanceUpattributeDesc & msg);
		static ::proto_ff::E_MountAdvanceUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountAdvanceUpattributeDesc(); }
		static ::proto_ff::E_MountAdvanceUpattributeDesc make_pbmsg(){ return ::proto_ff::E_MountAdvanceUpattributeDesc(); }
	};
	typedef struct E_MountAdvanceUpattributeDesc_s E_MountAdvanceUpattributeDesc_t;

	struct E_MountAdvance_s : public NFDescStoreSeqOP {
		E_MountAdvance_s();
		virtual ~E_MountAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_upattributeid;
		int32_t m_starid;
		int32_t m_skillid;
		NFShmVector<struct E_MountAdvanceUpattributeDesc_s, 5> m_upattribute;

		virtual void write_to_pbmsg(::proto_ff::E_MountAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountAdvance & msg);
		static ::proto_ff::E_MountAdvance* new_pbmsg(){ return new ::proto_ff::E_MountAdvance(); }
		static ::proto_ff::E_MountAdvance make_pbmsg(){ return ::proto_ff::E_MountAdvance(); }
	};
	typedef struct E_MountAdvance_s E_MountAdvance_t;

	struct Sheet_MountAdvance_s : public NFDescStoreSeqOP {
		Sheet_MountAdvance_s();
		virtual ~Sheet_MountAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountAdvance_s, 20> E_MountAdvance_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountAdvance & msg);
		static ::proto_ff::Sheet_MountAdvance* new_pbmsg(){ return new ::proto_ff::Sheet_MountAdvance(); }
		static ::proto_ff::Sheet_MountAdvance make_pbmsg(){ return ::proto_ff::Sheet_MountAdvance(); }
	};
	typedef struct Sheet_MountAdvance_s Sheet_MountAdvance_t;

	struct E_MountHuakunMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountHuakunMaterialDesc_s();
		virtual ~E_MountHuakunMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakunMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakunMaterialDesc & msg);
		static ::proto_ff::E_MountHuakunMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakunMaterialDesc(); }
		static ::proto_ff::E_MountHuakunMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountHuakunMaterialDesc(); }
	};
	typedef struct E_MountHuakunMaterialDesc_s E_MountHuakunMaterialDesc_t;

	struct E_MountHuakun_s : public NFDescStoreSeqOP {
		E_MountHuakun_s();
		virtual ~E_MountHuakun_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_modelid;
		int32_t m_quality;
		int32_t m_speed;
		int32_t m_uplvtype;
		int32_t m_advancetype;
		int32_t m_starmax;
		NFShmString<60> m_upstarnum;
		int32_t m_starnumber;
		NFShmString<60> m_upstarbertype;
		int32_t m_activateitem;
		int32_t m_activateitemnum;
		NFShmString<60> m_skill_lg;
		NFShmString<60> m_skill_bd;
		NFShmVector<struct E_MountHuakunMaterialDesc_s, 3> m_material;
		NFShmVector<int32_t, 2> m_upstaritem;

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun & msg);
		static ::proto_ff::E_MountHuakun* new_pbmsg(){ return new ::proto_ff::E_MountHuakun(); }
		static ::proto_ff::E_MountHuakun make_pbmsg(){ return ::proto_ff::E_MountHuakun(); }
	};
	typedef struct E_MountHuakun_s E_MountHuakun_t;

	struct Sheet_MountHuakun_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_s();
		virtual ~Sheet_MountHuakun_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_s, 20> E_MountHuakun_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun & msg);
		static ::proto_ff::Sheet_MountHuakun* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun(); }
		static ::proto_ff::Sheet_MountHuakun make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun(); }
	};
	typedef struct Sheet_MountHuakun_s Sheet_MountHuakun_t;

	struct E_MountHuakun_advancevalueItemDesc_s : public NFDescStoreSeqOP {
		E_MountHuakun_advancevalueItemDesc_s();
		virtual ~E_MountHuakun_advancevalueItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalueItemDesc & msg);
		static ::proto_ff::E_MountHuakun_advancevalueItemDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advancevalueItemDesc(); }
		static ::proto_ff::E_MountHuakun_advancevalueItemDesc make_pbmsg(){ return ::proto_ff::E_MountHuakun_advancevalueItemDesc(); }
	};
	typedef struct E_MountHuakun_advancevalueItemDesc_s E_MountHuakun_advancevalueItemDesc_t;

	struct E_MountHuakun_advancevalue_s : public NFDescStoreSeqOP {
		E_MountHuakun_advancevalue_s();
		virtual ~E_MountHuakun_advancevalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_lv;
		int32_t m_lvtype;
		int32_t m_advancetype;
		int32_t m_winprob;
		NFShmVector<struct E_MountHuakun_advancevalueItemDesc_s, 3> m_item;

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalue & msg);
		static ::proto_ff::E_MountHuakun_advancevalue* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advancevalue(); }
		static ::proto_ff::E_MountHuakun_advancevalue make_pbmsg(){ return ::proto_ff::E_MountHuakun_advancevalue(); }
	};
	typedef struct E_MountHuakun_advancevalue_s E_MountHuakun_advancevalue_t;

	struct Sheet_MountHuakun_advancevalue_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_advancevalue_s();
		virtual ~Sheet_MountHuakun_advancevalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_advancevalue_s, 20> E_MountHuakun_advancevalue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_advancevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_advancevalue & msg);
		static ::proto_ff::Sheet_MountHuakun_advancevalue* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_advancevalue(); }
		static ::proto_ff::Sheet_MountHuakun_advancevalue make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_advancevalue(); }
	};
	typedef struct Sheet_MountHuakun_advancevalue_s Sheet_MountHuakun_advancevalue_t;

	struct E_MountBloodAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountBloodAttributeDesc_s();
		virtual ~E_MountBloodAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MountBloodAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBloodAttributeDesc & msg);
		static ::proto_ff::E_MountBloodAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountBloodAttributeDesc(); }
		static ::proto_ff::E_MountBloodAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountBloodAttributeDesc(); }
	};
	typedef struct E_MountBloodAttributeDesc_s E_MountBloodAttributeDesc_t;

	struct E_MountBlood_s : public NFDescStoreSeqOP {
		E_MountBlood_s();
		virtual ~E_MountBlood_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		NFShmVector<struct E_MountBloodAttributeDesc_s, 2> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_MountBlood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBlood & msg);
		static ::proto_ff::E_MountBlood* new_pbmsg(){ return new ::proto_ff::E_MountBlood(); }
		static ::proto_ff::E_MountBlood make_pbmsg(){ return ::proto_ff::E_MountBlood(); }
	};
	typedef struct E_MountBlood_s E_MountBlood_t;

	struct Sheet_MountBlood_s : public NFDescStoreSeqOP {
		Sheet_MountBlood_s();
		virtual ~Sheet_MountBlood_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountBlood_s, 300> E_MountBlood_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountBlood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountBlood & msg);
		static ::proto_ff::Sheet_MountBlood* new_pbmsg(){ return new ::proto_ff::Sheet_MountBlood(); }
		static ::proto_ff::Sheet_MountBlood make_pbmsg(){ return ::proto_ff::Sheet_MountBlood(); }
	};
	typedef struct Sheet_MountBlood_s Sheet_MountBlood_t;

	struct E_MountBaby_egg_s : public NFDescStoreSeqOP {
		E_MountBaby_egg_s();
		virtual ~E_MountBaby_egg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_item;
		int32_t m_time;
		int32_t m_itembox;

		virtual void write_to_pbmsg(::proto_ff::E_MountBaby_egg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBaby_egg & msg);
		static ::proto_ff::E_MountBaby_egg* new_pbmsg(){ return new ::proto_ff::E_MountBaby_egg(); }
		static ::proto_ff::E_MountBaby_egg make_pbmsg(){ return ::proto_ff::E_MountBaby_egg(); }
	};
	typedef struct E_MountBaby_egg_s E_MountBaby_egg_t;

	struct Sheet_MountBaby_egg_s : public NFDescStoreSeqOP {
		Sheet_MountBaby_egg_s();
		virtual ~Sheet_MountBaby_egg_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountBaby_egg_s, 20> E_MountBaby_egg_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountBaby_egg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountBaby_egg & msg);
		static ::proto_ff::Sheet_MountBaby_egg* new_pbmsg(){ return new ::proto_ff::Sheet_MountBaby_egg(); }
		static ::proto_ff::Sheet_MountBaby_egg make_pbmsg(){ return ::proto_ff::Sheet_MountBaby_egg(); }
	};
	typedef struct Sheet_MountBaby_egg_s Sheet_MountBaby_egg_t;

}

