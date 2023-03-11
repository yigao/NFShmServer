#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "shenequip.pb.h"
#include "shenequip_s.h"

namespace proto_ff_s {

	struct E_ShenequipEquip_s : public NFDescStoreSeqOP {
		E_ShenequipEquip_s();
		virtual ~E_ShenequipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;
		int32_t m_type;
		int32_t m_grade;
		int32_t m_subtype;
		int32_t m_level;
		int32_t m_quality;
		int32_t m_star;
		int32_t m_attributeid;
		NFShmString<60> m_decompose;
		int32_t m_iscanbind;
		int32_t m_istradebind;
		int32_t m_time;
		int32_t m_broadcast;
		int32_t m_exclusiveid;
		NFShmString<60> m_secretskill;
		NFShmString<60> m_crypticskill;
		NFShmString<80> m_passiveskill;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipEquip & msg);
		static ::proto_ff::E_ShenequipEquip* new_pbmsg(){ return new ::proto_ff::E_ShenequipEquip(); }
		static ::proto_ff::E_ShenequipEquip make_pbmsg(){ return ::proto_ff::E_ShenequipEquip(); }
	};
	typedef struct E_ShenequipEquip_s E_ShenequipEquip_t;

	struct Sheet_ShenequipEquip_s : public NFDescStoreSeqOP {
		Sheet_ShenequipEquip_s();
		virtual ~Sheet_ShenequipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipEquip_s, 20> E_ShenequipEquip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipEquip & msg);
		static ::proto_ff::Sheet_ShenequipEquip* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipEquip(); }
		static ::proto_ff::Sheet_ShenequipEquip make_pbmsg(){ return ::proto_ff::Sheet_ShenequipEquip(); }
	};
	typedef struct Sheet_ShenequipEquip_s Sheet_ShenequipEquip_t;

	struct E_ShenequipAttAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAttAttributeDesc_s();
		virtual ~E_ShenequipAttAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAttAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAttAttributeDesc & msg);
		static ::proto_ff::E_ShenequipAttAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAttAttributeDesc(); }
		static ::proto_ff::E_ShenequipAttAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAttAttributeDesc(); }
	};
	typedef struct E_ShenequipAttAttributeDesc_s E_ShenequipAttAttributeDesc_t;

	struct E_ShenequipAttStarDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAttStarDesc_s();
		virtual ~E_ShenequipAttStarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAttStarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAttStarDesc & msg);
		static ::proto_ff::E_ShenequipAttStarDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAttStarDesc(); }
		static ::proto_ff::E_ShenequipAttStarDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAttStarDesc(); }
	};
	typedef struct E_ShenequipAttStarDesc_s E_ShenequipAttStarDesc_t;

	struct E_ShenequipAtt_s : public NFDescStoreSeqOP {
		E_ShenequipAtt_s();
		virtual ~E_ShenequipAtt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmVector<struct E_ShenequipAttAttributeDesc_s, 4> m_attribute;
		NFShmVector<struct E_ShenequipAttStarDesc_s, 7> m_star;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAtt & msg);
		static ::proto_ff::E_ShenequipAtt* new_pbmsg(){ return new ::proto_ff::E_ShenequipAtt(); }
		static ::proto_ff::E_ShenequipAtt make_pbmsg(){ return ::proto_ff::E_ShenequipAtt(); }
	};
	typedef struct E_ShenequipAtt_s E_ShenequipAtt_t;

	struct Sheet_ShenequipAtt_s : public NFDescStoreSeqOP {
		Sheet_ShenequipAtt_s();
		virtual ~Sheet_ShenequipAtt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipAtt_s, 11000> E_ShenequipAtt_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAtt & msg);
		static ::proto_ff::Sheet_ShenequipAtt* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipAtt(); }
		static ::proto_ff::Sheet_ShenequipAtt make_pbmsg(){ return ::proto_ff::Sheet_ShenequipAtt(); }
	};
	typedef struct Sheet_ShenequipAtt_s Sheet_ShenequipAtt_t;

	struct E_ShenequipLvup_s : public NFDescStoreSeqOP {
		E_ShenequipLvup_s();
		virtual ~E_ShenequipLvup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_itemid;
		int32_t m_num;
		int32_t m_advanceitem;
		int32_t m_advancenum;
		int32_t m_attributeid;
		int32_t m_stepid;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipLvup & msg);
		static ::proto_ff::E_ShenequipLvup* new_pbmsg(){ return new ::proto_ff::E_ShenequipLvup(); }
		static ::proto_ff::E_ShenequipLvup make_pbmsg(){ return ::proto_ff::E_ShenequipLvup(); }
	};
	typedef struct E_ShenequipLvup_s E_ShenequipLvup_t;

	struct Sheet_ShenequipLvup_s : public NFDescStoreSeqOP {
		Sheet_ShenequipLvup_s();
		virtual ~Sheet_ShenequipLvup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipLvup_s, 40> E_ShenequipLvup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipLvup & msg);
		static ::proto_ff::Sheet_ShenequipLvup* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipLvup(); }
		static ::proto_ff::Sheet_ShenequipLvup make_pbmsg(){ return ::proto_ff::Sheet_ShenequipLvup(); }
	};
	typedef struct Sheet_ShenequipLvup_s Sheet_ShenequipLvup_t;

	struct E_ShenequipClear_s : public NFDescStoreSeqOP {
		E_ShenequipClear_s();
		virtual ~E_ShenequipClear_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_lv;
		int32_t m_itemid;
		int32_t m_num;
		int32_t m_breakitem;
		int32_t m_breaknum;
		int32_t m_breakprogress;
		int32_t m_randomcounts;
		int32_t m_minus;
		int32_t m_nextid;
		NFShmVector<int32_t, 2> m_percent;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipClear & msg);
		static ::proto_ff::E_ShenequipClear* new_pbmsg(){ return new ::proto_ff::E_ShenequipClear(); }
		static ::proto_ff::E_ShenequipClear make_pbmsg(){ return ::proto_ff::E_ShenequipClear(); }
	};
	typedef struct E_ShenequipClear_s E_ShenequipClear_t;

	struct Sheet_ShenequipClear_s : public NFDescStoreSeqOP {
		Sheet_ShenequipClear_s();
		virtual ~Sheet_ShenequipClear_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipClear_s, 140> E_ShenequipClear_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipClear & msg);
		static ::proto_ff::Sheet_ShenequipClear* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipClear(); }
		static ::proto_ff::Sheet_ShenequipClear make_pbmsg(){ return ::proto_ff::Sheet_ShenequipClear(); }
	};
	typedef struct Sheet_ShenequipClear_s Sheet_ShenequipClear_t;

	struct E_ShenequipAwakenAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAwakenAttributeDesc_s();
		virtual ~E_ShenequipAwakenAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAwakenAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAwakenAttributeDesc & msg);
		static ::proto_ff::E_ShenequipAwakenAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAwakenAttributeDesc(); }
		static ::proto_ff::E_ShenequipAwakenAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAwakenAttributeDesc(); }
	};
	typedef struct E_ShenequipAwakenAttributeDesc_s E_ShenequipAwakenAttributeDesc_t;

	struct E_ShenequipAwaken_s : public NFDescStoreSeqOP {
		E_ShenequipAwaken_s();
		virtual ~E_ShenequipAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_lv;
		int32_t m_itemid;
		int32_t m_num;
		int32_t m_awakeskillid;
		NFShmVector<struct E_ShenequipAwakenAttributeDesc_s, 6> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAwaken & msg);
		static ::proto_ff::E_ShenequipAwaken* new_pbmsg(){ return new ::proto_ff::E_ShenequipAwaken(); }
		static ::proto_ff::E_ShenequipAwaken make_pbmsg(){ return ::proto_ff::E_ShenequipAwaken(); }
	};
	typedef struct E_ShenequipAwaken_s E_ShenequipAwaken_t;

	struct Sheet_ShenequipAwaken_s : public NFDescStoreSeqOP {
		Sheet_ShenequipAwaken_s();
		virtual ~Sheet_ShenequipAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipAwaken_s, 20> E_ShenequipAwaken_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAwaken & msg);
		static ::proto_ff::Sheet_ShenequipAwaken* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipAwaken(); }
		static ::proto_ff::Sheet_ShenequipAwaken make_pbmsg(){ return ::proto_ff::Sheet_ShenequipAwaken(); }
	};
	typedef struct Sheet_ShenequipAwaken_s Sheet_ShenequipAwaken_t;

	struct E_ShenequipStarupMaterialDesc_s : public NFDescStoreSeqOP {
		E_ShenequipStarupMaterialDesc_s();
		virtual ~E_ShenequipStarupMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_grade;
		int32_t m_quality;
		int32_t m_num;
		int32_t m_type;
		int32_t m_star;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipStarupMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipStarupMaterialDesc & msg);
		static ::proto_ff::E_ShenequipStarupMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipStarupMaterialDesc(); }
		static ::proto_ff::E_ShenequipStarupMaterialDesc make_pbmsg(){ return ::proto_ff::E_ShenequipStarupMaterialDesc(); }
	};
	typedef struct E_ShenequipStarupMaterialDesc_s E_ShenequipStarupMaterialDesc_t;

	struct E_ShenequipStarup_s : public NFDescStoreSeqOP {
		E_ShenequipStarup_s();
		virtual ~E_ShenequipStarup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_grade;
		int32_t m_quality;
		int32_t m_stars;
		int32_t m_nextid;
		int32_t m_lastid;
		int32_t m_percent;
		NFShmVector<struct E_ShenequipStarupMaterialDesc_s, 2> m_material;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipStarup & msg);
		static ::proto_ff::E_ShenequipStarup* new_pbmsg(){ return new ::proto_ff::E_ShenequipStarup(); }
		static ::proto_ff::E_ShenequipStarup make_pbmsg(){ return ::proto_ff::E_ShenequipStarup(); }
	};
	typedef struct E_ShenequipStarup_s E_ShenequipStarup_t;

	struct Sheet_ShenequipStarup_s : public NFDescStoreSeqOP {
		Sheet_ShenequipStarup_s();
		virtual ~Sheet_ShenequipStarup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipStarup_s, 80> E_ShenequipStarup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipStarup & msg);
		static ::proto_ff::Sheet_ShenequipStarup* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipStarup(); }
		static ::proto_ff::Sheet_ShenequipStarup make_pbmsg(){ return ::proto_ff::Sheet_ShenequipStarup(); }
	};
	typedef struct Sheet_ShenequipStarup_s Sheet_ShenequipStarup_t;

	struct E_ShenequipPreposeRewardDesc_s : public NFDescStoreSeqOP {
		E_ShenequipPreposeRewardDesc_s();
		virtual ~E_ShenequipPreposeRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_item;
		int32_t m_num;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPreposeRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPreposeRewardDesc & msg);
		static ::proto_ff::E_ShenequipPreposeRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipPreposeRewardDesc(); }
		static ::proto_ff::E_ShenequipPreposeRewardDesc make_pbmsg(){ return ::proto_ff::E_ShenequipPreposeRewardDesc(); }
	};
	typedef struct E_ShenequipPreposeRewardDesc_s E_ShenequipPreposeRewardDesc_t;

	struct E_ShenequipPrepose_s : public NFDescStoreSeqOP {
		E_ShenequipPrepose_s();
		virtual ~E_ShenequipPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_condition;
		int32_t m_value;
		NFShmVector<struct E_ShenequipPreposeRewardDesc_s, 5> m_reward;

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPrepose & msg);
		static ::proto_ff::E_ShenequipPrepose* new_pbmsg(){ return new ::proto_ff::E_ShenequipPrepose(); }
		static ::proto_ff::E_ShenequipPrepose make_pbmsg(){ return ::proto_ff::E_ShenequipPrepose(); }
	};
	typedef struct E_ShenequipPrepose_s E_ShenequipPrepose_t;

	struct Sheet_ShenequipPrepose_s : public NFDescStoreSeqOP {
		Sheet_ShenequipPrepose_s();
		virtual ~Sheet_ShenequipPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipPrepose_s, 20> E_ShenequipPrepose_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipPrepose & msg);
		static ::proto_ff::Sheet_ShenequipPrepose* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipPrepose(); }
		static ::proto_ff::Sheet_ShenequipPrepose make_pbmsg(){ return ::proto_ff::Sheet_ShenequipPrepose(); }
	};
	typedef struct Sheet_ShenequipPrepose_s Sheet_ShenequipPrepose_t;

}

