#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "box.pb.h"
#include "box_s.h"

namespace proto_ff_s {

	struct E_BoxBoxBoxdataDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxBoxdataDesc_s();
		virtual ~E_BoxBoxBoxdataDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_maxtimes;
		int64_t m_id;
		int32_t m_weight;
		int32_t m_mintimes;

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxBoxdataDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxBoxdataDesc & msg);
		static ::proto_ff::E_BoxBoxBoxdataDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxBoxdataDesc(); }
		static ::proto_ff::E_BoxBoxBoxdataDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxBoxdataDesc(); }
	};
	typedef struct E_BoxBoxBoxdataDesc_s E_BoxBoxBoxdataDesc_t;

	struct E_BoxBox_s : public NFDescStoreSeqOP {
		E_BoxBox_s();
		virtual ~E_BoxBox_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_type;
		int32_t m_rate;
		int32_t m_mask;
		int32_t m_mintimes;
		int32_t m_maxtimes;
		NFShmVector<struct E_BoxBoxBoxdataDesc_s, 8> m_boxdata;

		virtual void write_to_pbmsg(::proto_ff::E_BoxBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBox & msg);
		static ::proto_ff::E_BoxBox* new_pbmsg(){ return new ::proto_ff::E_BoxBox(); }
		static ::proto_ff::E_BoxBox make_pbmsg(){ return ::proto_ff::E_BoxBox(); }
	};
	typedef struct E_BoxBox_s E_BoxBox_t;

	struct Sheet_BoxBox_s : public NFDescStoreSeqOP {
		Sheet_BoxBox_s();
		virtual ~Sheet_BoxBox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BoxBox_s, 20> E_BoxBox_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BoxBox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BoxBox & msg);
		static ::proto_ff::Sheet_BoxBox* new_pbmsg(){ return new ::proto_ff::Sheet_BoxBox(); }
		static ::proto_ff::Sheet_BoxBox make_pbmsg(){ return ::proto_ff::Sheet_BoxBox(); }
	};
	typedef struct Sheet_BoxBox_s Sheet_BoxBox_t;

	struct E_BoxBoxdataEquipDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxdataEquipDesc_s();
		virtual ~E_BoxBoxdataEquipDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_rand;
		int32_t m_minnum;
		int32_t m_isbind;
		int32_t m_maxnum;
		NFShmString<60> m_id;

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdataEquipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdataEquipDesc & msg);
		static ::proto_ff::E_BoxBoxdataEquipDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdataEquipDesc(); }
		static ::proto_ff::E_BoxBoxdataEquipDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxdataEquipDesc(); }
	};
	typedef struct E_BoxBoxdataEquipDesc_s E_BoxBoxdataEquipDesc_t;

	struct E_BoxBoxdataItemDesc_s : public NFDescStoreSeqOP {
		E_BoxBoxdataItemDesc_s();
		virtual ~E_BoxBoxdataItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<60> m_rand;
		int32_t m_maxnum;
		int32_t m_rarerand;
		int32_t m_minnum;
		NFShmString<60> m_isbind;
		NFShmString<60> m_id;

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdataItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdataItemDesc & msg);
		static ::proto_ff::E_BoxBoxdataItemDesc* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdataItemDesc(); }
		static ::proto_ff::E_BoxBoxdataItemDesc make_pbmsg(){ return ::proto_ff::E_BoxBoxdataItemDesc(); }
	};
	typedef struct E_BoxBoxdataItemDesc_s E_BoxBoxdataItemDesc_t;

	struct E_BoxBoxdata_s : public NFDescStoreSeqOP {
		E_BoxBoxdata_s();
		virtual ~E_BoxBoxdata_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_drop_type;
		int32_t m_goldminnum;
		int32_t m_goldmaxnum;
		int32_t m_goldrand;
		int32_t m_bindjewelminnum;
		int32_t m_bindjewelmaxnum;
		int32_t m_bindjewelrand;
		int32_t m_jewelminnum;
		int32_t m_jewelmaxnum;
		int32_t m_jewelrand;
		NFShmString<60> m_eq_profession;
		NFShmVector<struct E_BoxBoxdataEquipDesc_s, 8> m_equip;
		NFShmVector<struct E_BoxBoxdataItemDesc_s, 50> m_item;

		virtual void write_to_pbmsg(::proto_ff::E_BoxBoxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BoxBoxdata & msg);
		static ::proto_ff::E_BoxBoxdata* new_pbmsg(){ return new ::proto_ff::E_BoxBoxdata(); }
		static ::proto_ff::E_BoxBoxdata make_pbmsg(){ return ::proto_ff::E_BoxBoxdata(); }
	};
	typedef struct E_BoxBoxdata_s E_BoxBoxdata_t;

	struct Sheet_BoxBoxdata_s : public NFDescStoreSeqOP {
		Sheet_BoxBoxdata_s();
		virtual ~Sheet_BoxBoxdata_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BoxBoxdata_s, 40> E_BoxBoxdata_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BoxBoxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BoxBoxdata & msg);
		static ::proto_ff::Sheet_BoxBoxdata* new_pbmsg(){ return new ::proto_ff::Sheet_BoxBoxdata(); }
		static ::proto_ff::Sheet_BoxBoxdata make_pbmsg(){ return ::proto_ff::Sheet_BoxBoxdata(); }
	};
	typedef struct Sheet_BoxBoxdata_s Sheet_BoxBoxdata_t;

}

