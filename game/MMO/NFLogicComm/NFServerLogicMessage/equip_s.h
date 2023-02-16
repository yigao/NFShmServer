#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "equip.pb.h"
#include "equip_s.h"

namespace proto_ff_s {

	struct E_EquipEquipAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipEquipAttributeDesc_s();
		virtual ~E_EquipEquipAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_valuemin;
		int32_t m_type;
		int32_t m_valuemax;

		virtual void write_to_pbmsg(::proto_ff::E_EquipEquipAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipEquipAttributeDesc & msg);
		static ::proto_ff::E_EquipEquipAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipEquipAttributeDesc(); }
		static ::proto_ff::E_EquipEquipAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipEquipAttributeDesc(); }
	};
	typedef struct E_EquipEquipAttributeDesc_s E_EquipEquipAttributeDesc_t;

	struct E_EquipEquipGodattributeDesc_s : public NFDescStoreSeqOP {
		E_EquipEquipGodattributeDesc_s();
		virtual ~E_EquipEquipGodattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_valuemin;
		int32_t m_type;
		int32_t m_valuemax;

		virtual void write_to_pbmsg(::proto_ff::E_EquipEquipGodattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipEquipGodattributeDesc & msg);
		static ::proto_ff::E_EquipEquipGodattributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipEquipGodattributeDesc(); }
		static ::proto_ff::E_EquipEquipGodattributeDesc make_pbmsg(){ return ::proto_ff::E_EquipEquipGodattributeDesc(); }
	};
	typedef struct E_EquipEquipGodattributeDesc_s E_EquipEquipGodattributeDesc_t;

	struct E_EquipEquip_s : public NFDescStoreSeqOP {
		E_EquipEquip_s();
		virtual ~E_EquipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_name;
		int32_t m_wearquality;
		int32_t m_position;
		NFShmString<60> m_profession;
		int32_t m_professionlv;
		int32_t m_level;
		int32_t m_quality;
		int32_t m_star;
		int32_t m_refineattributedown;
		int32_t m_refineattributeup;
		NFShmString<60> m_refineattribute_typelibrary;
		NFShmString<60> m_refineattribute_valuemin;
		NFShmString<60> m_refineattribute_valuemax;
		int32_t m_bluestarnum;
		NFShmString<60> m_bluestar_type;
		NFShmString<60> m_bluestar_lv;
		NFShmString<60> m_bluestar_number;
		int32_t m_iscanbind;
		int32_t m_istradebind;
		int32_t m_sellprice;
		NFShmString<60> m_icon;
		int32_t m_time;
		int32_t m_broadcast;
		NFShmString<60> m_meltingresult;
		int32_t m_specialattributedown;
		int32_t m_specialattributeup;
		NFShmString<60> m_specialattribute_typelibrary;
		NFShmString<60> m_specialattribute_valuemin;
		NFShmString<60> m_specialattribute_valuemax;
		NFShmString<60> m_skillid;
		NFShmVector<struct E_EquipEquipAttributeDesc_s, 3> m_attribute;
		NFShmVector<struct E_EquipEquipGodattributeDesc_s, 2> m_godattribute;

		virtual void write_to_pbmsg(::proto_ff::E_EquipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipEquip & msg);
		static ::proto_ff::E_EquipEquip* new_pbmsg(){ return new ::proto_ff::E_EquipEquip(); }
		static ::proto_ff::E_EquipEquip make_pbmsg(){ return ::proto_ff::E_EquipEquip(); }
	};
	typedef struct E_EquipEquip_s E_EquipEquip_t;

	struct Sheet_EquipEquip_s : public NFDescStoreSeqOP {
		Sheet_EquipEquip_s();
		virtual ~Sheet_EquipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipEquip_s, 20> E_EquipEquip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipEquip & msg);
		static ::proto_ff::Sheet_EquipEquip* new_pbmsg(){ return new ::proto_ff::Sheet_EquipEquip(); }
		static ::proto_ff::Sheet_EquipEquip make_pbmsg(){ return ::proto_ff::Sheet_EquipEquip(); }
	};
	typedef struct Sheet_EquipEquip_s Sheet_EquipEquip_t;

	struct E_EquipStrongTypeDesc_s : public NFDescStoreSeqOP {
		E_EquipStrongTypeDesc_s();
		virtual ~E_EquipStrongTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<60> m_num;
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongTypeDesc & msg);
		static ::proto_ff::E_EquipStrongTypeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStrongTypeDesc(); }
		static ::proto_ff::E_EquipStrongTypeDesc make_pbmsg(){ return ::proto_ff::E_EquipStrongTypeDesc(); }
	};
	typedef struct E_EquipStrongTypeDesc_s E_EquipStrongTypeDesc_t;

	struct E_EquipStrong_s : public NFDescStoreSeqOP {
		E_EquipStrong_s();
		virtual ~E_EquipStrong_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_position;
		int32_t m_wearquality;
		int32_t m_srtongup;
		NFShmVector<struct E_EquipStrongTypeDesc_s, 2> m_type;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrong & msg);
		static ::proto_ff::E_EquipStrong* new_pbmsg(){ return new ::proto_ff::E_EquipStrong(); }
		static ::proto_ff::E_EquipStrong make_pbmsg(){ return ::proto_ff::E_EquipStrong(); }
	};
	typedef struct E_EquipStrong_s E_EquipStrong_t;

	struct Sheet_EquipStrong_s : public NFDescStoreSeqOP {
		Sheet_EquipStrong_s();
		virtual ~Sheet_EquipStrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrong_s, 400> E_EquipStrong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrong & msg);
		static ::proto_ff::Sheet_EquipStrong* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrong(); }
		static ::proto_ff::Sheet_EquipStrong make_pbmsg(){ return ::proto_ff::Sheet_EquipStrong(); }
	};
	typedef struct Sheet_EquipStrong_s Sheet_EquipStrong_t;

	struct E_EquipStrongexp_s : public NFDescStoreSeqOP {
		E_EquipStrongexp_s();
		virtual ~E_EquipStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_gold;
		NFShmVector<int32_t, 2> m_costitem;
		NFShmVector<NFShmString<60>, 2> m_positiontype;
		NFShmVector<int32_t, 2> m_costnum;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongexp & msg);
		static ::proto_ff::E_EquipStrongexp* new_pbmsg(){ return new ::proto_ff::E_EquipStrongexp(); }
		static ::proto_ff::E_EquipStrongexp make_pbmsg(){ return ::proto_ff::E_EquipStrongexp(); }
	};
	typedef struct E_EquipStrongexp_s E_EquipStrongexp_t;

	struct Sheet_EquipStrongexp_s : public NFDescStoreSeqOP {
		Sheet_EquipStrongexp_s();
		virtual ~Sheet_EquipStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrongexp_s, 800> E_EquipStrongexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongexp & msg);
		static ::proto_ff::Sheet_EquipStrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrongexp(); }
		static ::proto_ff::Sheet_EquipStrongexp make_pbmsg(){ return ::proto_ff::Sheet_EquipStrongexp(); }
	};
	typedef struct Sheet_EquipStrongexp_s Sheet_EquipStrongexp_t;

	struct E_EquipStrongtotalAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipStrongtotalAttributeDesc_s();
		virtual ~E_EquipStrongtotalAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongtotalAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongtotalAttributeDesc & msg);
		static ::proto_ff::E_EquipStrongtotalAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStrongtotalAttributeDesc(); }
		static ::proto_ff::E_EquipStrongtotalAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipStrongtotalAttributeDesc(); }
	};
	typedef struct E_EquipStrongtotalAttributeDesc_s E_EquipStrongtotalAttributeDesc_t;

	struct E_EquipStrongtotal_s : public NFDescStoreSeqOP {
		E_EquipStrongtotal_s();
		virtual ~E_EquipStrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_idtype;
		int32_t m_idnum;
		NFShmVector<struct E_EquipStrongtotalAttributeDesc_s, 4> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongtotal & msg);
		static ::proto_ff::E_EquipStrongtotal* new_pbmsg(){ return new ::proto_ff::E_EquipStrongtotal(); }
		static ::proto_ff::E_EquipStrongtotal make_pbmsg(){ return ::proto_ff::E_EquipStrongtotal(); }
	};
	typedef struct E_EquipStrongtotal_s E_EquipStrongtotal_t;

	struct Sheet_EquipStrongtotal_s : public NFDescStoreSeqOP {
		Sheet_EquipStrongtotal_s();
		virtual ~Sheet_EquipStrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrongtotal_s, 300> E_EquipStrongtotal_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongtotal & msg);
		static ::proto_ff::Sheet_EquipStrongtotal* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrongtotal(); }
		static ::proto_ff::Sheet_EquipStrongtotal make_pbmsg(){ return ::proto_ff::Sheet_EquipStrongtotal(); }
	};
	typedef struct Sheet_EquipStrongtotal_s Sheet_EquipStrongtotal_t;

	struct E_EquipGem_s : public NFDescStoreSeqOP {
		E_EquipGem_s();
		virtual ~E_EquipGem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;
		NFShmString<60> m_gemtype;
		int32_t m_speciallygemtype;
		int32_t m_payunlockitem;
		int32_t m_payunlocknnm;
		NFShmVector<int32_t, 5> m_gemunlock;

		virtual void write_to_pbmsg(::proto_ff::E_EquipGem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipGem & msg);
		static ::proto_ff::E_EquipGem* new_pbmsg(){ return new ::proto_ff::E_EquipGem(); }
		static ::proto_ff::E_EquipGem make_pbmsg(){ return ::proto_ff::E_EquipGem(); }
	};
	typedef struct E_EquipGem_s E_EquipGem_t;

	struct Sheet_EquipGem_s : public NFDescStoreSeqOP {
		Sheet_EquipGem_s();
		virtual ~Sheet_EquipGem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipGem_s, 20> E_EquipGem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipGem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipGem & msg);
		static ::proto_ff::Sheet_EquipGem* new_pbmsg(){ return new ::proto_ff::Sheet_EquipGem(); }
		static ::proto_ff::Sheet_EquipGem make_pbmsg(){ return ::proto_ff::Sheet_EquipGem(); }
	};
	typedef struct Sheet_EquipGem_s Sheet_EquipGem_t;

	struct E_EquipStoveattAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipStoveattAttributeDesc_s();
		virtual ~E_EquipStoveattAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveattAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveattAttributeDesc & msg);
		static ::proto_ff::E_EquipStoveattAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStoveattAttributeDesc(); }
		static ::proto_ff::E_EquipStoveattAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipStoveattAttributeDesc(); }
	};
	typedef struct E_EquipStoveattAttributeDesc_s E_EquipStoveattAttributeDesc_t;

	struct E_EquipStoveatt_s : public NFDescStoreSeqOP {
		E_EquipStoveatt_s();
		virtual ~E_EquipStoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int64_t m_exp;
		NFShmVector<struct E_EquipStoveattAttributeDesc_s, 4> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveatt & msg);
		static ::proto_ff::E_EquipStoveatt* new_pbmsg(){ return new ::proto_ff::E_EquipStoveatt(); }
		static ::proto_ff::E_EquipStoveatt make_pbmsg(){ return ::proto_ff::E_EquipStoveatt(); }
	};
	typedef struct E_EquipStoveatt_s E_EquipStoveatt_t;

	struct Sheet_EquipStoveatt_s : public NFDescStoreSeqOP {
		Sheet_EquipStoveatt_s();
		virtual ~Sheet_EquipStoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStoveatt_s, 2000> E_EquipStoveatt_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveatt & msg);
		static ::proto_ff::Sheet_EquipStoveatt* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStoveatt(); }
		static ::proto_ff::Sheet_EquipStoveatt make_pbmsg(){ return ::proto_ff::Sheet_EquipStoveatt(); }
	};
	typedef struct Sheet_EquipStoveatt_s Sheet_EquipStoveatt_t;

	struct E_EquipStoveexp_s : public NFDescStoreSeqOP {
		E_EquipStoveexp_s();
		virtual ~E_EquipStoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_exp;
		int32_t m_wearquality;
		int32_t m_quality;

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveexp & msg);
		static ::proto_ff::E_EquipStoveexp* new_pbmsg(){ return new ::proto_ff::E_EquipStoveexp(); }
		static ::proto_ff::E_EquipStoveexp make_pbmsg(){ return ::proto_ff::E_EquipStoveexp(); }
	};
	typedef struct E_EquipStoveexp_s E_EquipStoveexp_t;

	struct Sheet_EquipStoveexp_s : public NFDescStoreSeqOP {
		Sheet_EquipStoveexp_s();
		virtual ~Sheet_EquipStoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStoveexp_s, 200> E_EquipStoveexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveexp & msg);
		static ::proto_ff::Sheet_EquipStoveexp* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStoveexp(); }
		static ::proto_ff::Sheet_EquipStoveexp make_pbmsg(){ return ::proto_ff::Sheet_EquipStoveexp(); }
	};
	typedef struct Sheet_EquipStoveexp_s Sheet_EquipStoveexp_t;

	struct E_EquipGrade_s : public NFDescStoreSeqOP {
		E_EquipGrade_s();
		virtual ~E_EquipGrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_EquipGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipGrade & msg);
		static ::proto_ff::E_EquipGrade* new_pbmsg(){ return new ::proto_ff::E_EquipGrade(); }
		static ::proto_ff::E_EquipGrade make_pbmsg(){ return ::proto_ff::E_EquipGrade(); }
	};
	typedef struct E_EquipGrade_s E_EquipGrade_t;

	struct Sheet_EquipGrade_s : public NFDescStoreSeqOP {
		Sheet_EquipGrade_s();
		virtual ~Sheet_EquipGrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipGrade_s, 40> E_EquipGrade_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipGrade & msg);
		static ::proto_ff::Sheet_EquipGrade* new_pbmsg(){ return new ::proto_ff::Sheet_EquipGrade(); }
		static ::proto_ff::Sheet_EquipGrade make_pbmsg(){ return ::proto_ff::Sheet_EquipGrade(); }
	};
	typedef struct Sheet_EquipGrade_s Sheet_EquipGrade_t;

}

