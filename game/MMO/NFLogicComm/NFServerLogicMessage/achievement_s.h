#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "achievement.pb.h"
#include "achievement_s.h"

namespace proto_ff_s {

	struct achievementachievementitemRewardDesc_s : public NFDescStoreSeqOP {
		achievementachievementitemRewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::achievementachievementitemRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::achievementachievementitemRewardDesc & msg);
		static ::proto_ff::achievementachievementitemRewardDesc* new_pbmsg(){ return new ::proto_ff::achievementachievementitemRewardDesc(); }
		static ::proto_ff::achievementachievementitemRewardDesc make_pbmsg(){ return ::proto_ff::achievementachievementitemRewardDesc(); }
	};
	typedef struct achievementachievementitemRewardDesc_s achievementachievementitemRewardDesc_t;

	struct achievementachievement_s : public NFDescStoreSeqOP {
		achievementachievement_s();
		int CreateInit();
		int ResumeInit();
		int64_t achievementId;
		int32_t achievementLevel;
		int32_t achievementDTP;
		int32_t achievementType;
		int32_t achievementSubType;
		int64_t achievementObjectID;
		NFSizeString<32> achievementObjectIDString;
		int32_t achievementObjectValue;
		int32_t achievementDia;
		int32_t achievementGod;
		int32_t achievementPoint;
		int32_t linkID;
		NFArray<struct achievementachievementitemRewardDesc_s, 2> itemReward;

		virtual void write_to_pbmsg(::proto_ff::achievementachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::achievementachievement & msg);
		static ::proto_ff::achievementachievement* new_pbmsg(){ return new ::proto_ff::achievementachievement(); }
		static ::proto_ff::achievementachievement make_pbmsg(){ return ::proto_ff::achievementachievement(); }
	};
	typedef struct achievementachievement_s achievementachievement_t;

	struct Sheet_achievementachievement_s : public NFDescStoreSeqOP {
		Sheet_achievementachievement_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct achievementachievement_s, 429> achievementachievement_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_achievementachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_achievementachievement & msg);
		static ::proto_ff::Sheet_achievementachievement* new_pbmsg(){ return new ::proto_ff::Sheet_achievementachievement(); }
		static ::proto_ff::Sheet_achievementachievement make_pbmsg(){ return ::proto_ff::Sheet_achievementachievement(); }
	};
	typedef struct Sheet_achievementachievement_s Sheet_achievementachievement_t;

	struct achievementachievementreward_s : public NFDescStoreSeqOP {
		achievementachievementreward_s();
		int CreateInit();
		int ResumeInit();
		int64_t achievementPrizeId;
		int32_t achievementType;
		int32_t achievementPointValue;
		int64_t achievementSkil;
		int32_t achievementDia;

		virtual void write_to_pbmsg(::proto_ff::achievementachievementreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::achievementachievementreward & msg);
		static ::proto_ff::achievementachievementreward* new_pbmsg(){ return new ::proto_ff::achievementachievementreward(); }
		static ::proto_ff::achievementachievementreward make_pbmsg(){ return ::proto_ff::achievementachievementreward(); }
	};
	typedef struct achievementachievementreward_s achievementachievementreward_t;

	struct Sheet_achievementachievementreward_s : public NFDescStoreSeqOP {
		Sheet_achievementachievementreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct achievementachievementreward_s, 110> achievementachievementreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_achievementachievementreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_achievementachievementreward & msg);
		static ::proto_ff::Sheet_achievementachievementreward* new_pbmsg(){ return new ::proto_ff::Sheet_achievementachievementreward(); }
		static ::proto_ff::Sheet_achievementachievementreward make_pbmsg(){ return ::proto_ff::Sheet_achievementachievementreward(); }
	};
	typedef struct Sheet_achievementachievementreward_s Sheet_achievementachievementreward_t;

}

