#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "duplicate.pb.h"
#include "duplicate_s.h"

namespace proto_ff_s {

	struct duplicateduplicate_s : public NFDescStoreSeqOP {
		duplicateduplicate_s();
		int CreateInit();
		int ResumeInit();
		int64_t duplicateID;
		NFSizeString<32> duplicateName;
		NFSizeString<32> duplicateTitlePic;
		int64_t groupID;
		int32_t duplicateType;
		int32_t playType;
		int64_t sceneResource;
		int32_t levelLimit;
		int64_t linkDuplicateRequest;
		int32_t isAutoFight;
		NFSizeString<32> duplicateConditionType;
		int32_t reviveMaxTimes;
		int64_t dropNormalMonster;
		int64_t dropEliteMonster;
		int64_t dropBossMonster;
		NFSizeString<32> sceneAIScript;
		NFSizeString<32> bossDesc;
		int32_t TeamObjectID;
		NFSizeString<32> gradeCondition;
		int64_t sweepRewardBoxID;
		int32_t sweepRewardExp;
		NFSizeString<119> trackpath;
		NFSizeString<121> pathOfmonster;
		int32_t isPatrol;
		int32_t sweepType;

		virtual void write_to_pbmsg(::proto_ff::duplicateduplicate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateduplicate & msg);
		static ::proto_ff::duplicateduplicate* new_pbmsg(){ return new ::proto_ff::duplicateduplicate(); }
		static ::proto_ff::duplicateduplicate make_pbmsg(){ return ::proto_ff::duplicateduplicate(); }
	};
	typedef struct duplicateduplicate_s duplicateduplicate_t;

	struct Sheet_duplicateduplicate_s : public NFDescStoreSeqOP {
		Sheet_duplicateduplicate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateduplicate_s, 911> duplicateduplicate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateduplicate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateduplicate & msg);
		static ::proto_ff::Sheet_duplicateduplicate* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateduplicate(); }
		static ::proto_ff::Sheet_duplicateduplicate make_pbmsg(){ return ::proto_ff::Sheet_duplicateduplicate(); }
	};
	typedef struct Sheet_duplicateduplicate_s Sheet_duplicateduplicate_t;

	struct duplicateconstant_s : public NFDescStoreSeqOP {
		duplicateconstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t constantid;
		int64_t constantdata;
		NFSizeString<32> stringdata;

		virtual void write_to_pbmsg(::proto_ff::duplicateconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateconstant & msg);
		static ::proto_ff::duplicateconstant* new_pbmsg(){ return new ::proto_ff::duplicateconstant(); }
		static ::proto_ff::duplicateconstant make_pbmsg(){ return ::proto_ff::duplicateconstant(); }
	};
	typedef struct duplicateconstant_s duplicateconstant_t;

	struct Sheet_duplicateconstant_s : public NFDescStoreSeqOP {
		Sheet_duplicateconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateconstant_s, 106> duplicateconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateconstant & msg);
		static ::proto_ff::Sheet_duplicateconstant* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateconstant(); }
		static ::proto_ff::Sheet_duplicateconstant make_pbmsg(){ return ::proto_ff::Sheet_duplicateconstant(); }
	};
	typedef struct Sheet_duplicateconstant_s Sheet_duplicateconstant_t;

	struct duplicateendlessMaze_s : public NFDescStoreSeqOP {
		duplicateendlessMaze_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t level;
		NFSizeString<224> duplicateID;
		int32_t CreateRate;
		int64_t rewardID;

		virtual void write_to_pbmsg(::proto_ff::duplicateendlessMaze & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateendlessMaze & msg);
		static ::proto_ff::duplicateendlessMaze* new_pbmsg(){ return new ::proto_ff::duplicateendlessMaze(); }
		static ::proto_ff::duplicateendlessMaze make_pbmsg(){ return ::proto_ff::duplicateendlessMaze(); }
	};
	typedef struct duplicateendlessMaze_s duplicateendlessMaze_t;

	struct Sheet_duplicateendlessMaze_s : public NFDescStoreSeqOP {
		Sheet_duplicateendlessMaze_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateendlessMaze_s, 117> duplicateendlessMaze_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateendlessMaze & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateendlessMaze & msg);
		static ::proto_ff::Sheet_duplicateendlessMaze* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateendlessMaze(); }
		static ::proto_ff::Sheet_duplicateendlessMaze make_pbmsg(){ return ::proto_ff::Sheet_duplicateendlessMaze(); }
	};
	typedef struct Sheet_duplicateendlessMaze_s Sheet_duplicateendlessMaze_t;

	struct duplicatetowerReward_s : public NFDescStoreSeqOP {
		duplicatetowerReward_s();
		int CreateInit();
		int ResumeInit();
		int64_t floorMin;
		int64_t floormax;
		int64_t BOXID;
		int64_t itemId;
		int32_t itemNum;

		virtual void write_to_pbmsg(::proto_ff::duplicatetowerReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicatetowerReward & msg);
		static ::proto_ff::duplicatetowerReward* new_pbmsg(){ return new ::proto_ff::duplicatetowerReward(); }
		static ::proto_ff::duplicatetowerReward make_pbmsg(){ return ::proto_ff::duplicatetowerReward(); }
	};
	typedef struct duplicatetowerReward_s duplicatetowerReward_t;

	struct Sheet_duplicatetowerReward_s : public NFDescStoreSeqOP {
		Sheet_duplicatetowerReward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicatetowerReward_s, 145> duplicatetowerReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicatetowerReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicatetowerReward & msg);
		static ::proto_ff::Sheet_duplicatetowerReward* new_pbmsg(){ return new ::proto_ff::Sheet_duplicatetowerReward(); }
		static ::proto_ff::Sheet_duplicatetowerReward make_pbmsg(){ return ::proto_ff::Sheet_duplicatetowerReward(); }
	};
	typedef struct Sheet_duplicatetowerReward_s Sheet_duplicatetowerReward_t;

	struct duplicatedungeonRewardrewardDesc_s : public NFDescStoreSeqOP {
		duplicatedungeonRewardrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t ItemNum;
		int64_t Item;
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::duplicatedungeonRewardrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicatedungeonRewardrewardDesc & msg);
		static ::proto_ff::duplicatedungeonRewardrewardDesc* new_pbmsg(){ return new ::proto_ff::duplicatedungeonRewardrewardDesc(); }
		static ::proto_ff::duplicatedungeonRewardrewardDesc make_pbmsg(){ return ::proto_ff::duplicatedungeonRewardrewardDesc(); }
	};
	typedef struct duplicatedungeonRewardrewardDesc_s duplicatedungeonRewardrewardDesc_t;

	struct duplicatedungeonReward_s : public NFDescStoreSeqOP {
		duplicatedungeonReward_s();
		int CreateInit();
		int ResumeInit();
		int32_t levelID;
		int32_t rewardTime;
		int32_t passReceiveTime;
		NFArray<struct duplicatedungeonRewardrewardDesc_s, 10> reward;

		virtual void write_to_pbmsg(::proto_ff::duplicatedungeonReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicatedungeonReward & msg);
		static ::proto_ff::duplicatedungeonReward* new_pbmsg(){ return new ::proto_ff::duplicatedungeonReward(); }
		static ::proto_ff::duplicatedungeonReward make_pbmsg(){ return ::proto_ff::duplicatedungeonReward(); }
	};
	typedef struct duplicatedungeonReward_s duplicatedungeonReward_t;

	struct Sheet_duplicatedungeonReward_s : public NFDescStoreSeqOP {
		Sheet_duplicatedungeonReward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicatedungeonReward_s, 304> duplicatedungeonReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicatedungeonReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicatedungeonReward & msg);
		static ::proto_ff::Sheet_duplicatedungeonReward* new_pbmsg(){ return new ::proto_ff::Sheet_duplicatedungeonReward(); }
		static ::proto_ff::Sheet_duplicatedungeonReward make_pbmsg(){ return ::proto_ff::Sheet_duplicatedungeonReward(); }
	};
	typedef struct Sheet_duplicatedungeonReward_s Sheet_duplicatedungeonReward_t;

	struct duplicategroup_s : public NFDescStoreSeqOP {
		duplicategroup_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> name;
		NFSizeString<32> duplicateTitlePic;
		int32_t unlockLevel;
		int32_t belongToType;
		int32_t viptype;
		int32_t dynamiclevel;
		NFSizeString<32> timesRes;
		int32_t groupTimesType;
		int32_t groupTimes;
		int32_t refreshType;
		int64_t enterItemID;
		int32_t reliveTpye;
		NFSizeString<32> sweepCondition;
		int32_t buyEnterTimesCostType;
		int32_t buyEnterTimesCost;
		int32_t countDown;
		int32_t pathfindingtype;

		virtual void write_to_pbmsg(::proto_ff::duplicategroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicategroup & msg);
		static ::proto_ff::duplicategroup* new_pbmsg(){ return new ::proto_ff::duplicategroup(); }
		static ::proto_ff::duplicategroup make_pbmsg(){ return ::proto_ff::duplicategroup(); }
	};
	typedef struct duplicategroup_s duplicategroup_t;

	struct Sheet_duplicategroup_s : public NFDescStoreSeqOP {
		Sheet_duplicategroup_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicategroup_s, 133> duplicategroup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicategroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicategroup & msg);
		static ::proto_ff::Sheet_duplicategroup* new_pbmsg(){ return new ::proto_ff::Sheet_duplicategroup(); }
		static ::proto_ff::Sheet_duplicategroup make_pbmsg(){ return ::proto_ff::Sheet_duplicategroup(); }
	};
	typedef struct Sheet_duplicategroup_s Sheet_duplicategroup_t;

	struct duplicatesweepmonsterNum_s : public NFDescStoreSeqOP {
		duplicatesweepmonsterNum_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t sweepType;
		int32_t minLevel;
		int32_t maxLevel;
		int32_t killNumber;
		int32_t monstervaluetype;

		virtual void write_to_pbmsg(::proto_ff::duplicatesweepmonsterNum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicatesweepmonsterNum & msg);
		static ::proto_ff::duplicatesweepmonsterNum* new_pbmsg(){ return new ::proto_ff::duplicatesweepmonsterNum(); }
		static ::proto_ff::duplicatesweepmonsterNum make_pbmsg(){ return ::proto_ff::duplicatesweepmonsterNum(); }
	};
	typedef struct duplicatesweepmonsterNum_s duplicatesweepmonsterNum_t;

	struct Sheet_duplicatesweepmonsterNum_s : public NFDescStoreSeqOP {
		Sheet_duplicatesweepmonsterNum_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicatesweepmonsterNum_s, 155> duplicatesweepmonsterNum_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicatesweepmonsterNum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicatesweepmonsterNum & msg);
		static ::proto_ff::Sheet_duplicatesweepmonsterNum* new_pbmsg(){ return new ::proto_ff::Sheet_duplicatesweepmonsterNum(); }
		static ::proto_ff::Sheet_duplicatesweepmonsterNum make_pbmsg(){ return ::proto_ff::Sheet_duplicatesweepmonsterNum(); }
	};
	typedef struct Sheet_duplicatesweepmonsterNum_s Sheet_duplicatesweepmonsterNum_t;

	struct duplicateGuildbosstime_s : public NFDescStoreSeqOP {
		duplicateGuildbosstime_s();
		int CreateInit();
		int ResumeInit();
		int64_t duplicateID;
		int32_t openCycle;
		NFSizeString<32> openTime;
		int32_t bossGroup;
		int32_t relevance;

		virtual void write_to_pbmsg(::proto_ff::duplicateGuildbosstime & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateGuildbosstime & msg);
		static ::proto_ff::duplicateGuildbosstime* new_pbmsg(){ return new ::proto_ff::duplicateGuildbosstime(); }
		static ::proto_ff::duplicateGuildbosstime make_pbmsg(){ return ::proto_ff::duplicateGuildbosstime(); }
	};
	typedef struct duplicateGuildbosstime_s duplicateGuildbosstime_t;

	struct Sheet_duplicateGuildbosstime_s : public NFDescStoreSeqOP {
		Sheet_duplicateGuildbosstime_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateGuildbosstime_s, 325> duplicateGuildbosstime_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateGuildbosstime & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildbosstime & msg);
		static ::proto_ff::Sheet_duplicateGuildbosstime* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateGuildbosstime(); }
		static ::proto_ff::Sheet_duplicateGuildbosstime make_pbmsg(){ return ::proto_ff::Sheet_duplicateGuildbosstime(); }
	};
	typedef struct Sheet_duplicateGuildbosstime_s Sheet_duplicateGuildbosstime_t;

	struct duplicateGuildbosskillDesc_s : public NFDescStoreSeqOP {
		duplicateGuildbosskillDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t small;
		int32_t large;
		int32_t weaken;

		virtual void write_to_pbmsg(::proto_ff::duplicateGuildbosskillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateGuildbosskillDesc & msg);
		static ::proto_ff::duplicateGuildbosskillDesc* new_pbmsg(){ return new ::proto_ff::duplicateGuildbosskillDesc(); }
		static ::proto_ff::duplicateGuildbosskillDesc make_pbmsg(){ return ::proto_ff::duplicateGuildbosskillDesc(); }
	};
	typedef struct duplicateGuildbosskillDesc_s duplicateGuildbosskillDesc_t;

	struct duplicateGuildboss_s : public NFDescStoreSeqOP {
		duplicateGuildboss_s();
		int CreateInit();
		int ResumeInit();
		int64_t duplicateID;
		int64_t rewardId;
		NFArray<struct duplicateGuildbosskillDesc_s, 6> kill;

		virtual void write_to_pbmsg(::proto_ff::duplicateGuildboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateGuildboss & msg);
		static ::proto_ff::duplicateGuildboss* new_pbmsg(){ return new ::proto_ff::duplicateGuildboss(); }
		static ::proto_ff::duplicateGuildboss make_pbmsg(){ return ::proto_ff::duplicateGuildboss(); }
	};
	typedef struct duplicateGuildboss_s duplicateGuildboss_t;

	struct Sheet_duplicateGuildboss_s : public NFDescStoreSeqOP {
		Sheet_duplicateGuildboss_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateGuildboss_s, 325> duplicateGuildboss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateGuildboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildboss & msg);
		static ::proto_ff::Sheet_duplicateGuildboss* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateGuildboss(); }
		static ::proto_ff::Sheet_duplicateGuildboss make_pbmsg(){ return ::proto_ff::Sheet_duplicateGuildboss(); }
	};
	typedef struct Sheet_duplicateGuildboss_s Sheet_duplicateGuildboss_t;

	struct duplicateGuildDuplicate_s : public NFDescStoreSeqOP {
		duplicateGuildDuplicate_s();
		int CreateInit();
		int ResumeInit();
		int32_t level;
		int64_t monsterExp;
		int64_t bossExp;

		virtual void write_to_pbmsg(::proto_ff::duplicateGuildDuplicate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duplicateGuildDuplicate & msg);
		static ::proto_ff::duplicateGuildDuplicate* new_pbmsg(){ return new ::proto_ff::duplicateGuildDuplicate(); }
		static ::proto_ff::duplicateGuildDuplicate make_pbmsg(){ return ::proto_ff::duplicateGuildDuplicate(); }
	};
	typedef struct duplicateGuildDuplicate_s duplicateGuildDuplicate_t;

	struct Sheet_duplicateGuildDuplicate_s : public NFDescStoreSeqOP {
		Sheet_duplicateGuildDuplicate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct duplicateGuildDuplicate_s, 1604> duplicateGuildDuplicate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duplicateGuildDuplicate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildDuplicate & msg);
		static ::proto_ff::Sheet_duplicateGuildDuplicate* new_pbmsg(){ return new ::proto_ff::Sheet_duplicateGuildDuplicate(); }
		static ::proto_ff::Sheet_duplicateGuildDuplicate make_pbmsg(){ return ::proto_ff::Sheet_duplicateGuildDuplicate(); }
	};
	typedef struct Sheet_duplicateGuildDuplicate_s Sheet_duplicateGuildDuplicate_t;

}

