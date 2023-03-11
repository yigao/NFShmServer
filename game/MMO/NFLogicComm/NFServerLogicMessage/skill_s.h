#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "skill.pb.h"
#include "skill_s.h"

namespace proto_ff_s {

	struct E_SkillBuff_s : public NFDescStoreSeqOP {
		E_SkillBuff_s();
		virtual ~E_SkillBuff_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_buffid;
		NFShmString<60> m_buffname;
		NFShmString<60> m_bufficon;
		NFShmString<60> m_effectresources;
		int32_t m_showtpye;
		int32_t m_startprobability;
		int32_t m_probability_up;
		int32_t m_starttype;
		NFShmString<60> m_starttypevalue;
		int32_t m_endtype;
		NFShmString<60> m_endtypevalue;
		int32_t m_group;
		NFShmString<60> m_buffrule;
		NFShmString<60> m_immune;
		NFShmString<60> m_dispel;
		int32_t m_buffcd;
		int32_t m_effect_time;
		int32_t m_effect_type;
		NFShmString<60> m_effect_param;
		int32_t m_effect_up;

		virtual void write_to_pbmsg(::proto_ff::E_SkillBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillBuff & msg);
		static ::proto_ff::E_SkillBuff* new_pbmsg(){ return new ::proto_ff::E_SkillBuff(); }
		static ::proto_ff::E_SkillBuff make_pbmsg(){ return ::proto_ff::E_SkillBuff(); }
	};
	typedef struct E_SkillBuff_s E_SkillBuff_t;

	struct Sheet_SkillBuff_s : public NFDescStoreSeqOP {
		Sheet_SkillBuff_s();
		virtual ~Sheet_SkillBuff_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillBuff_s, 200> E_SkillBuff_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillBuff & msg);
		static ::proto_ff::Sheet_SkillBuff* new_pbmsg(){ return new ::proto_ff::Sheet_SkillBuff(); }
		static ::proto_ff::Sheet_SkillBuff make_pbmsg(){ return ::proto_ff::Sheet_SkillBuff(); }
	};
	typedef struct Sheet_SkillBuff_s Sheet_SkillBuff_t;

	struct E_SkillSkillAdvancetype1buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype1buffDesc_s();
		virtual ~E_SkillSkillAdvancetype1buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype1buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype1buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype1buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype1buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype1buffDesc_s E_SkillSkillAdvancetype1buffDesc_t;

	struct E_SkillSkillAdvancetype2buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype2buffDesc_s();
		virtual ~E_SkillSkillAdvancetype2buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype2buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype2buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype2buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype2buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype2buffDesc_s E_SkillSkillAdvancetype2buffDesc_t;

	struct E_SkillSkillAwakebuffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAwakebuffDesc_s();
		virtual ~E_SkillSkillAwakebuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAwakebuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAwakebuffDesc & msg);
		static ::proto_ff::E_SkillSkillAwakebuffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAwakebuffDesc(); }
		static ::proto_ff::E_SkillSkillAwakebuffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAwakebuffDesc(); }
	};
	typedef struct E_SkillSkillAwakebuffDesc_s E_SkillSkillAwakebuffDesc_t;

	struct E_SkillSkillAdvancetype3buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype3buffDesc_s();
		virtual ~E_SkillSkillAdvancetype3buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype3buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype3buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype3buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype3buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype3buffDesc_s E_SkillSkillAdvancetype3buffDesc_t;

	struct E_SkillSkillBuffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillBuffDesc_s();
		virtual ~E_SkillSkillBuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_target;
		int64_t m_id;
		int32_t m_point;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillBuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillBuffDesc & msg);
		static ::proto_ff::E_SkillSkillBuffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillBuffDesc(); }
		static ::proto_ff::E_SkillSkillBuffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillBuffDesc(); }
	};
	typedef struct E_SkillSkillBuffDesc_s E_SkillSkillBuffDesc_t;

	struct E_SkillSkill_s : public NFDescStoreSeqOP {
		E_SkillSkill_s();
		virtual ~E_SkillSkill_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_skillid;
		NFShmString<60> m_name;
		int32_t m_skilltype;
		int32_t m_group;
		int32_t m_position;
		int32_t m_displacetime;
		int32_t m_displacesign;
		NFShmString<60> m_displacespeed;
		NFShmString<60> m_distimes;
		int32_t m_breaktype;
		int32_t m_cdskill;
		int64_t m_relation;
		NFShmString<60> m_unlockcondition;
		int32_t m_type;
		int32_t m_cd;
		int32_t m_nolock;
		int32_t m_priority;
		int32_t m_fighting;
		float m_fightingparama;
		int32_t m_releasetype;
		int32_t m_processtypes;
		int32_t m_flyspeed;
		int32_t m_acttime;
		int32_t m_readytime;
		int32_t m_readytimeex;
		int32_t m_attacktime;
		NFShmString<60> m_damagetime;
		NFShmString<60> m_damagetimeex;
		int32_t m_attackdistance;
		int32_t m_rangetype;
		NFShmString<60> m_rangetypevalue;
		int32_t m_rangetypeex;
		NFShmString<60> m_rangetypevalueex;
		int32_t m_warn;
		int32_t m_dazetime;
		int32_t m_warntime;
		NFShmString<60> m_infomationid;
		int32_t m_attackmindistance;
		int32_t m_goalmaxnum;
		int32_t m_goalmaxnummonster;
		int32_t m_damagetype;
		int32_t m_damagerate;
		int32_t m_awakedamagerate;
		int32_t m_advancetype1damagerate;
		int32_t m_advancetype2damagerate;
		int32_t m_advancetype3damagerate;
		int32_t m_damagevalue;
		float m_damageparama;
		int32_t m_addhitrate;
		NFShmVector<struct E_SkillSkillAdvancetype1buffDesc_s, 3> m_advancetype1buff;
		NFShmVector<struct E_SkillSkillAdvancetype2buffDesc_s, 3> m_advancetype2buff;
		NFShmVector<struct E_SkillSkillAwakebuffDesc_s, 5> m_awakebuff;
		NFShmVector<struct E_SkillSkillAdvancetype3buffDesc_s, 3> m_advancetype3buff;
		NFShmVector<struct E_SkillSkillBuffDesc_s, 8> m_buff;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkill & msg);
		static ::proto_ff::E_SkillSkill* new_pbmsg(){ return new ::proto_ff::E_SkillSkill(); }
		static ::proto_ff::E_SkillSkill make_pbmsg(){ return ::proto_ff::E_SkillSkill(); }
	};
	typedef struct E_SkillSkill_s E_SkillSkill_t;

	struct Sheet_SkillSkill_s : public NFDescStoreSeqOP {
		Sheet_SkillSkill_s();
		virtual ~Sheet_SkillSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkill_s, 300> E_SkillSkill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkill & msg);
		static ::proto_ff::Sheet_SkillSkill* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkill(); }
		static ::proto_ff::Sheet_SkillSkill make_pbmsg(){ return ::proto_ff::Sheet_SkillSkill(); }
	};
	typedef struct Sheet_SkillSkill_s Sheet_SkillSkill_t;

	struct E_SkillBuffup_s : public NFDescStoreSeqOP {
		E_SkillBuffup_s();
		virtual ~E_SkillBuffup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_addstartprobability;
		int32_t m_attributeid;
		int32_t m_parama;

		virtual void write_to_pbmsg(::proto_ff::E_SkillBuffup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillBuffup & msg);
		static ::proto_ff::E_SkillBuffup* new_pbmsg(){ return new ::proto_ff::E_SkillBuffup(); }
		static ::proto_ff::E_SkillBuffup make_pbmsg(){ return ::proto_ff::E_SkillBuffup(); }
	};
	typedef struct E_SkillBuffup_s E_SkillBuffup_t;

	struct Sheet_SkillBuffup_s : public NFDescStoreSeqOP {
		Sheet_SkillBuffup_s();
		virtual ~Sheet_SkillBuffup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillBuffup_s, 60> E_SkillBuffup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillBuffup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillBuffup & msg);
		static ::proto_ff::Sheet_SkillBuffup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillBuffup(); }
		static ::proto_ff::Sheet_SkillBuffup make_pbmsg(){ return ::proto_ff::Sheet_SkillBuffup(); }
	};
	typedef struct Sheet_SkillBuffup_s Sheet_SkillBuffup_t;

	struct E_SkillSkillup_s : public NFDescStoreSeqOP {
		E_SkillSkillup_s();
		virtual ~E_SkillSkillup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_group;
		int32_t m_skilllv;
		NFShmString<140> m_skillids;
		int32_t m_rolelv;
		int64_t m_costitemid;
		int32_t m_costnum;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillup & msg);
		static ::proto_ff::E_SkillSkillup* new_pbmsg(){ return new ::proto_ff::E_SkillSkillup(); }
		static ::proto_ff::E_SkillSkillup make_pbmsg(){ return ::proto_ff::E_SkillSkillup(); }
	};
	typedef struct E_SkillSkillup_s E_SkillSkillup_t;

	struct Sheet_SkillSkillup_s : public NFDescStoreSeqOP {
		Sheet_SkillSkillup_s();
		virtual ~Sheet_SkillSkillup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkillup_s, 400> E_SkillSkillup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkillup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillup & msg);
		static ::proto_ff::Sheet_SkillSkillup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkillup(); }
		static ::proto_ff::Sheet_SkillSkillup make_pbmsg(){ return ::proto_ff::Sheet_SkillSkillup(); }
	};
	typedef struct Sheet_SkillSkillup_s Sheet_SkillSkillup_t;

	struct E_SkillSkillawake_s : public NFDescStoreSeqOP {
		E_SkillSkillawake_s();
		virtual ~E_SkillSkillawake_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_skillid;
		int32_t m_costitemid;
		int32_t m_costnum;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillawake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillawake & msg);
		static ::proto_ff::E_SkillSkillawake* new_pbmsg(){ return new ::proto_ff::E_SkillSkillawake(); }
		static ::proto_ff::E_SkillSkillawake make_pbmsg(){ return ::proto_ff::E_SkillSkillawake(); }
	};
	typedef struct E_SkillSkillawake_s E_SkillSkillawake_t;

	struct Sheet_SkillSkillawake_s : public NFDescStoreSeqOP {
		Sheet_SkillSkillawake_s();
		virtual ~Sheet_SkillSkillawake_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkillawake_s, 20> E_SkillSkillawake_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkillawake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillawake & msg);
		static ::proto_ff::Sheet_SkillSkillawake* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkillawake(); }
		static ::proto_ff::Sheet_SkillSkillawake make_pbmsg(){ return ::proto_ff::Sheet_SkillSkillawake(); }
	};
	typedef struct Sheet_SkillSkillawake_s Sheet_SkillSkillawake_t;

	struct E_SkillSkilladvance_s : public NFDescStoreSeqOP {
		E_SkillSkilladvance_s();
		virtual ~E_SkillSkilladvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_profession;
		int32_t m_type;
		int32_t m_advancelv;
		NFShmString<60> m_advancecondition;
		NFShmString<60> m_skillid;

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkilladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkilladvance & msg);
		static ::proto_ff::E_SkillSkilladvance* new_pbmsg(){ return new ::proto_ff::E_SkillSkilladvance(); }
		static ::proto_ff::E_SkillSkilladvance make_pbmsg(){ return ::proto_ff::E_SkillSkilladvance(); }
	};
	typedef struct E_SkillSkilladvance_s E_SkillSkilladvance_t;

	struct Sheet_SkillSkilladvance_s : public NFDescStoreSeqOP {
		Sheet_SkillSkilladvance_s();
		virtual ~Sheet_SkillSkilladvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkilladvance_s, 20> E_SkillSkilladvance_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkilladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkilladvance & msg);
		static ::proto_ff::Sheet_SkillSkilladvance* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkilladvance(); }
		static ::proto_ff::Sheet_SkillSkilladvance make_pbmsg(){ return ::proto_ff::Sheet_SkillSkilladvance(); }
	};
	typedef struct Sheet_SkillSkilladvance_s Sheet_SkillSkilladvance_t;

}

