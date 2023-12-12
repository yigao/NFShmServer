#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Ai.pb.h"
#include "E_Ai_s.h"

#define DEFINE_E_AIAI_M_HP_MAX_NUM 3
#define DEFINE_SHEET_AIAI_E_AIAI_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_AiAiHpDesc_s : public NFDescStoreSeqOP {
		E_AiAiHpDesc_s();
		virtual ~E_AiAiHpDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_chat;//场景广播
		int64_t m_skill;//技能
		int32_t m_percent;//百分比

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
		int64_t m_id;//表ID
		int32_t m_type;//ai类型
		NFShmString<64> m_deadHateRemain;//死亡仇恨保留
		NFShmString<64> m_invisibleRemain;//隐身仇恨保留
		int32_t m_isActive;//是否为主动怪
		int32_t m_returnType;//回归类型
		int32_t m_view;//视野
		int32_t m_isAttackedShowOff;//是否关闭受击表现
		int32_t m_pursueRange;//追击范围
		int32_t m_actionRange;//怪物活动范围
		int32_t m_wakeupRadius;//唤醒半径
		int32_t m_isAIWorkWhenNobody;//是否无人时启用AI
		int32_t m_bornEffectAIDelay;//出生AI延时
		NFShmString<128> m_initSkills;//技能池初始技能组
		NFShmVector<struct E_AiAiHpDesc_s, DEFINE_E_AIAI_M_HP_MAX_NUM> m_hp;//触发血量

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
		NFShmVector<struct E_AiAi_s, DEFINE_SHEET_AIAI_E_AIAI_LIST_MAX_NUM> E_AiAi_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AiAi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AiAi & msg);
		static ::proto_ff::Sheet_AiAi* new_pbmsg(){ return new ::proto_ff::Sheet_AiAi(); }
		static ::proto_ff::Sheet_AiAi make_pbmsg(){ return ::proto_ff::Sheet_AiAi(); }
	};
	typedef struct Sheet_AiAi_s Sheet_AiAi_t;

}

