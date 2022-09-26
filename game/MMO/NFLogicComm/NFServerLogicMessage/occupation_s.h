#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "occupation.pb.h"
#include "occupation_s.h"

namespace proto_ff_s {

	struct occupationoccupationattributeDesc_s : public NFDescStoreSeqOP {
		occupationoccupationattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;

		virtual void write_to_pbmsg(::proto_ff::occupationoccupationattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationoccupationattributeDesc & msg);
		static ::proto_ff::occupationoccupationattributeDesc* new_pbmsg(){ return new ::proto_ff::occupationoccupationattributeDesc(); }
		static ::proto_ff::occupationoccupationattributeDesc make_pbmsg(){ return ::proto_ff::occupationoccupationattributeDesc(); }
	};
	typedef struct occupationoccupationattributeDesc_s occupationoccupationattributeDesc_t;

	struct occupationoccupationdelSkillDesc_s : public NFDescStoreSeqOP {
		occupationoccupationdelSkillDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::occupationoccupationdelSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationoccupationdelSkillDesc & msg);
		static ::proto_ff::occupationoccupationdelSkillDesc* new_pbmsg(){ return new ::proto_ff::occupationoccupationdelSkillDesc(); }
		static ::proto_ff::occupationoccupationdelSkillDesc make_pbmsg(){ return ::proto_ff::occupationoccupationdelSkillDesc(); }
	};
	typedef struct occupationoccupationdelSkillDesc_s occupationoccupationdelSkillDesc_t;

	struct occupationoccupationskillDesc_s : public NFDescStoreSeqOP {
		occupationoccupationskillDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::occupationoccupationskillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationoccupationskillDesc & msg);
		static ::proto_ff::occupationoccupationskillDesc* new_pbmsg(){ return new ::proto_ff::occupationoccupationskillDesc(); }
		static ::proto_ff::occupationoccupationskillDesc make_pbmsg(){ return ::proto_ff::occupationoccupationskillDesc(); }
	};
	typedef struct occupationoccupationskillDesc_s occupationoccupationskillDesc_t;

	struct occupationoccupation_s : public NFDescStoreSeqOP {
		occupationoccupation_s();
		int CreateInit();
		int ResumeInit();
		int64_t occupationID;
		int32_t id;
		int32_t grade;
		NFSizeString<75> activeDesc;
		int32_t level;
		int64_t aptitude;
		NFSizeString<32> taskID;
		NFSizeString<32> equip;
		NFSizeString<32> modelID;
		NFArray<struct occupationoccupationattributeDesc_s, 4> attribute;
		NFArray<struct occupationoccupationdelSkillDesc_s, 3> delSkill;
		NFArray<struct occupationoccupationskillDesc_s, 3> skill;

		virtual void write_to_pbmsg(::proto_ff::occupationoccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationoccupation & msg);
		static ::proto_ff::occupationoccupation* new_pbmsg(){ return new ::proto_ff::occupationoccupation(); }
		static ::proto_ff::occupationoccupation make_pbmsg(){ return ::proto_ff::occupationoccupation(); }
	};
	typedef struct occupationoccupation_s occupationoccupation_t;

	struct Sheet_occupationoccupation_s : public NFDescStoreSeqOP {
		Sheet_occupationoccupation_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct occupationoccupation_s, 132> occupationoccupation_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_occupationoccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_occupationoccupation & msg);
		static ::proto_ff::Sheet_occupationoccupation* new_pbmsg(){ return new ::proto_ff::Sheet_occupationoccupation(); }
		static ::proto_ff::Sheet_occupationoccupation make_pbmsg(){ return ::proto_ff::Sheet_occupationoccupation(); }
	};
	typedef struct Sheet_occupationoccupation_s Sheet_occupationoccupation_t;

	struct occupationaptitudeattributeDesc_s : public NFDescStoreSeqOP {
		occupationaptitudeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;

		virtual void write_to_pbmsg(::proto_ff::occupationaptitudeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationaptitudeattributeDesc & msg);
		static ::proto_ff::occupationaptitudeattributeDesc* new_pbmsg(){ return new ::proto_ff::occupationaptitudeattributeDesc(); }
		static ::proto_ff::occupationaptitudeattributeDesc make_pbmsg(){ return ::proto_ff::occupationaptitudeattributeDesc(); }
	};
	typedef struct occupationaptitudeattributeDesc_s occupationaptitudeattributeDesc_t;

	struct occupationaptitude_s : public NFDescStoreSeqOP {
		occupationaptitude_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t grade;
		int32_t level;
		int64_t requirement;
		int64_t material;
		int32_t num;
		NFSizeString<32> conditionId;
		NFArray<struct occupationaptitudeattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::occupationaptitude & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationaptitude & msg);
		static ::proto_ff::occupationaptitude* new_pbmsg(){ return new ::proto_ff::occupationaptitude(); }
		static ::proto_ff::occupationaptitude make_pbmsg(){ return ::proto_ff::occupationaptitude(); }
	};
	typedef struct occupationaptitude_s occupationaptitude_t;

	struct Sheet_occupationaptitude_s : public NFDescStoreSeqOP {
		Sheet_occupationaptitude_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct occupationaptitude_s, 146> occupationaptitude_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_occupationaptitude & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_occupationaptitude & msg);
		static ::proto_ff::Sheet_occupationaptitude* new_pbmsg(){ return new ::proto_ff::Sheet_occupationaptitude(); }
		static ::proto_ff::Sheet_occupationaptitude make_pbmsg(){ return ::proto_ff::Sheet_occupationaptitude(); }
	};
	typedef struct Sheet_occupationaptitude_s Sheet_occupationaptitude_t;

	struct occupationconditionList_s : public NFDescStoreSeqOP {
		occupationconditionList_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t type;
		int64_t conditionValue;
		int32_t conditionNum;

		virtual void write_to_pbmsg(::proto_ff::occupationconditionList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::occupationconditionList & msg);
		static ::proto_ff::occupationconditionList* new_pbmsg(){ return new ::proto_ff::occupationconditionList(); }
		static ::proto_ff::occupationconditionList make_pbmsg(){ return ::proto_ff::occupationconditionList(); }
	};
	typedef struct occupationconditionList_s occupationconditionList_t;

	struct Sheet_occupationconditionList_s : public NFDescStoreSeqOP {
		Sheet_occupationconditionList_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct occupationconditionList_s, 159> occupationconditionList_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_occupationconditionList & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_occupationconditionList & msg);
		static ::proto_ff::Sheet_occupationconditionList* new_pbmsg(){ return new ::proto_ff::Sheet_occupationconditionList(); }
		static ::proto_ff::Sheet_occupationconditionList make_pbmsg(){ return ::proto_ff::Sheet_occupationconditionList(); }
	};
	typedef struct Sheet_occupationconditionList_s Sheet_occupationconditionList_t;

}

