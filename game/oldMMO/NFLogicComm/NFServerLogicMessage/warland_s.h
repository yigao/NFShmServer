#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "warland.pb.h"
#include "warland_s.h"

namespace proto_ff_s {

	struct warlandconstant_s : public NFDescStoreSeqOP {
		warlandconstant_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t winscore;
		int64_t scoreareaID;
		int32_t OccupyScore;
		int32_t OccupyContribution;
		int32_t KillArea;
		int32_t KillContribution;
		int32_t KillRangeContribution;
		int32_t KillRange;
		int64_t SkillIdA;
		int64_t SkillIdB;
		int64_t GuardskillId;
		NFSizeString<80> ContinuousKillBuffId;
		NFSizeString<80> WinReward;
		NFSizeString<80> LoseReward;
		int64_t PrepareBuff;
		int32_t PrepareTime;
		int64_t invincibleSkillId;
		int64_t allplayerSkillId;
		int32_t killHelpPoint;

		virtual void write_to_pbmsg(::proto_ff::warlandconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::warlandconstant & msg);
		static ::proto_ff::warlandconstant* new_pbmsg(){ return new ::proto_ff::warlandconstant(); }
		static ::proto_ff::warlandconstant make_pbmsg(){ return ::proto_ff::warlandconstant(); }
	};
	typedef struct warlandconstant_s warlandconstant_t;

	struct Sheet_warlandconstant_s : public NFDescStoreSeqOP {
		Sheet_warlandconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct warlandconstant_s, 20> warlandconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_warlandconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_warlandconstant & msg);
		static ::proto_ff::Sheet_warlandconstant* new_pbmsg(){ return new ::proto_ff::Sheet_warlandconstant(); }
		static ::proto_ff::Sheet_warlandconstant make_pbmsg(){ return ::proto_ff::Sheet_warlandconstant(); }
	};
	typedef struct Sheet_warlandconstant_s Sheet_warlandconstant_t;

	struct warlandmultiKill_s : public NFDescStoreSeqOP {
		warlandmultiKill_s();
		int CreateInit();
		int ResumeInit();
		int32_t multiKillNum;
		NFSizeString<60> multiKillIcon;
		int32_t endMultiKillscore;
		int32_t endMultiKillPoint;

		virtual void write_to_pbmsg(::proto_ff::warlandmultiKill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::warlandmultiKill & msg);
		static ::proto_ff::warlandmultiKill* new_pbmsg(){ return new ::proto_ff::warlandmultiKill(); }
		static ::proto_ff::warlandmultiKill make_pbmsg(){ return ::proto_ff::warlandmultiKill(); }
	};
	typedef struct warlandmultiKill_s warlandmultiKill_t;

	struct Sheet_warlandmultiKill_s : public NFDescStoreSeqOP {
		Sheet_warlandmultiKill_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct warlandmultiKill_s, 20> warlandmultiKill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_warlandmultiKill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_warlandmultiKill & msg);
		static ::proto_ff::Sheet_warlandmultiKill* new_pbmsg(){ return new ::proto_ff::Sheet_warlandmultiKill(); }
		static ::proto_ff::Sheet_warlandmultiKill make_pbmsg(){ return ::proto_ff::Sheet_warlandmultiKill(); }
	};
	typedef struct Sheet_warlandmultiKill_s Sheet_warlandmultiKill_t;

	struct warlandrankreward_s : public NFDescStoreSeqOP {
		warlandrankreward_s();
		int CreateInit();
		int ResumeInit();
		int32_t stageId;
		int32_t MinRanking;
		int32_t MaxRanking;
		NFSizeString<140> Reward;

		virtual void write_to_pbmsg(::proto_ff::warlandrankreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::warlandrankreward & msg);
		static ::proto_ff::warlandrankreward* new_pbmsg(){ return new ::proto_ff::warlandrankreward(); }
		static ::proto_ff::warlandrankreward make_pbmsg(){ return ::proto_ff::warlandrankreward(); }
	};
	typedef struct warlandrankreward_s warlandrankreward_t;

	struct Sheet_warlandrankreward_s : public NFDescStoreSeqOP {
		Sheet_warlandrankreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct warlandrankreward_s, 20> warlandrankreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_warlandrankreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_warlandrankreward & msg);
		static ::proto_ff::Sheet_warlandrankreward* new_pbmsg(){ return new ::proto_ff::Sheet_warlandrankreward(); }
		static ::proto_ff::Sheet_warlandrankreward make_pbmsg(){ return ::proto_ff::Sheet_warlandrankreward(); }
	};
	typedef struct Sheet_warlandrankreward_s Sheet_warlandrankreward_t;

}

