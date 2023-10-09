#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ai.pb.h"
#include "ai_s.h"

#define DEFINE_E_AIAI_M_HP_MAX_NUM 2
#define DEFINE_SHEET_AIAI_E_AIAI_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_AiAiHpDesc_s : public NFDescStoreSeqOP {
		E_AiAiHpDesc_s();
		virtual ~E_AiAiHpDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_skill;
		int32_t m_percent;
		int64_t m_chat;

		virtual void write_to_pbmsg(::proto_ff::E_AiAiHpDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AiAiHpDesc & msg);
		static ::proto_ff::E_AiAiHpDesc* new_pbmsg(){ return new ::proto_ff::E_AiAiHpDesc(); }
		static ::proto_ff::E_AiAiHpDesc make_pbmsg(){ return ::proto_ff::E_AiAiHpDesc(); }
	};
	typedef struct E_AiAiHpDesc_s E_AiAiHpDesc_t;

	struct E_AiAi_s : public NFDescStoreSeqOP {
		E_AiAi_s();
		virtual ~E_AiAi_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_type;
		NFShmString<60> m_deadhateremain;
		NFShmString<60> m_invisibleremain;
		int32_t m_isactive;
		int32_t m_returntype;
		int32_t m_view;
		int32_t m_isattackedshowoff;
		int32_t m_pursuerange;
		int32_t m_actionrange;
		int32_t m_wakeupradius;
		int32_t m_isaiworkwhennobody;
		int32_t m_borneffectaidelay;
		NFShmString<60> m_initskills;
		NFShmVector<struct E_AiAiHpDesc_s, DEFINE_E_AIAI_M_HP_MAX_NUM> m_hp;

		virtual void write_to_pbmsg(::proto_ff::E_AiAi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AiAi & msg);
		static ::proto_ff::E_AiAi* new_pbmsg(){ return new ::proto_ff::E_AiAi(); }
		static ::proto_ff::E_AiAi make_pbmsg(){ return ::proto_ff::E_AiAi(); }
	};
	typedef struct E_AiAi_s E_AiAi_t;

	struct Sheet_AiAi_s : public NFDescStoreSeqOP {
		Sheet_AiAi_s();
		virtual ~Sheet_AiAi_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AiAi_s, DEFINE_SHEET_AIAI_E_AIAI_LIST_MAX_NUM> E_AiAi_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AiAi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AiAi & msg);
		static ::proto_ff::Sheet_AiAi* new_pbmsg(){ return new ::proto_ff::Sheet_AiAi(); }
		static ::proto_ff::Sheet_AiAi make_pbmsg(){ return ::proto_ff::Sheet_AiAi(); }
	};
	typedef struct Sheet_AiAi_s Sheet_AiAi_t;

}

