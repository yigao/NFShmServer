#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "activity.pb.h"
#include "activity_s.h"

namespace proto_ff_s {

	struct activitydaily_s : public NFDescStoreSeqOP {
		activitydaily_s();
		int CreateInit();
		int ResumeInit();
		int64_t activeId;
		NFSizeString<60> activeName;
		int32_t typeId;
		int32_t Descriptiontype;
		int64_t typeArgs;
		NFSizeString<140> involveMap;
		int32_t minlevel;
		NFSizeString<60> openCycle;
		NFSizeString<60> openTime;
		NFSizeString<60> pushTime;
		int32_t openingTime;
		int32_t advanceTime;
		int32_t intervalTime;
		NFSizeString<60> opeDay;
		NFSizeString<60> closeDay;
		int32_t isCross;
		int32_t serverTime;
		int32_t serverdelayTime;
		int32_t forwordEnterTime;

		virtual void write_to_pbmsg(::proto_ff::activitydaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitydaily & msg);
		static ::proto_ff::activitydaily* new_pbmsg(){ return new ::proto_ff::activitydaily(); }
		static ::proto_ff::activitydaily make_pbmsg(){ return ::proto_ff::activitydaily(); }
	};
	typedef struct activitydaily_s activitydaily_t;

	struct Sheet_activitydaily_s : public NFDescStoreSeqOP {
		Sheet_activitydaily_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitydaily_s, 20> activitydaily_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitydaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitydaily & msg);
		static ::proto_ff::Sheet_activitydaily* new_pbmsg(){ return new ::proto_ff::Sheet_activitydaily(); }
		static ::proto_ff::Sheet_activitydaily make_pbmsg(){ return ::proto_ff::Sheet_activitydaily(); }
	};
	typedef struct Sheet_activitydaily_s Sheet_activitydaily_t;

	struct activityactivitynotice_s : public NFDescStoreSeqOP {
		activityactivitynotice_s();
		int CreateInit();
		int ResumeInit();
		int64_t activeId;

		virtual void write_to_pbmsg(::proto_ff::activityactivitynotice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityactivitynotice & msg);
		static ::proto_ff::activityactivitynotice* new_pbmsg(){ return new ::proto_ff::activityactivitynotice(); }
		static ::proto_ff::activityactivitynotice make_pbmsg(){ return ::proto_ff::activityactivitynotice(); }
	};
	typedef struct activityactivitynotice_s activityactivitynotice_t;

	struct Sheet_activityactivitynotice_s : public NFDescStoreSeqOP {
		Sheet_activityactivitynotice_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activityactivitynotice_s, 20> activityactivitynotice_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activityactivitynotice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activityactivitynotice & msg);
		static ::proto_ff::Sheet_activityactivitynotice* new_pbmsg(){ return new ::proto_ff::Sheet_activityactivitynotice(); }
		static ::proto_ff::Sheet_activityactivitynotice make_pbmsg(){ return ::proto_ff::Sheet_activityactivitynotice(); }
	};
	typedef struct Sheet_activityactivitynotice_s Sheet_activityactivitynotice_t;

	struct activityscufflerewardDesc_s : public NFDescStoreSeqOP {
		activityscufflerewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Num;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::activityscufflerewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityscufflerewardDesc & msg);
		static ::proto_ff::activityscufflerewardDesc* new_pbmsg(){ return new ::proto_ff::activityscufflerewardDesc(); }
		static ::proto_ff::activityscufflerewardDesc make_pbmsg(){ return ::proto_ff::activityscufflerewardDesc(); }
	};
	typedef struct activityscufflerewardDesc_s activityscufflerewardDesc_t;

	struct activityscuffle_s : public NFDescStoreSeqOP {
		activityscuffle_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t typeArgs;
		int32_t level;
		int32_t stage;
		int64_t mapID;
		int64_t nextID;
		int32_t maxPoints;
		int32_t pvePoints;
		int32_t pvpPoints;
		int32_t pvpHelpPoints;
		NFArray<struct activityscufflerewardDesc_s, 3> reward;

		virtual void write_to_pbmsg(::proto_ff::activityscuffle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityscuffle & msg);
		static ::proto_ff::activityscuffle* new_pbmsg(){ return new ::proto_ff::activityscuffle(); }
		static ::proto_ff::activityscuffle make_pbmsg(){ return ::proto_ff::activityscuffle(); }
	};
	typedef struct activityscuffle_s activityscuffle_t;

	struct Sheet_activityscuffle_s : public NFDescStoreSeqOP {
		Sheet_activityscuffle_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activityscuffle_s, 20> activityscuffle_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activityscuffle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activityscuffle & msg);
		static ::proto_ff::Sheet_activityscuffle* new_pbmsg(){ return new ::proto_ff::Sheet_activityscuffle(); }
		static ::proto_ff::Sheet_activityscuffle make_pbmsg(){ return ::proto_ff::Sheet_activityscuffle(); }
	};
	typedef struct Sheet_activityscuffle_s Sheet_activityscuffle_t;

	struct activitychaosDragonsrewardDesc_s : public NFDescStoreSeqOP {
		activitychaosDragonsrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Num;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::activitychaosDragonsrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitychaosDragonsrewardDesc & msg);
		static ::proto_ff::activitychaosDragonsrewardDesc* new_pbmsg(){ return new ::proto_ff::activitychaosDragonsrewardDesc(); }
		static ::proto_ff::activitychaosDragonsrewardDesc make_pbmsg(){ return ::proto_ff::activitychaosDragonsrewardDesc(); }
	};
	typedef struct activitychaosDragonsrewardDesc_s activitychaosDragonsrewardDesc_t;

	struct activitychaosDragons_s : public NFDescStoreSeqOP {
		activitychaosDragons_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t reward_type;
		int32_t reward_param;
		int32_t rankmin;
		int32_t rankmax;
		int64_t getPoint;
		NFArray<struct activitychaosDragonsrewardDesc_s, 3> reward;

		virtual void write_to_pbmsg(::proto_ff::activitychaosDragons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitychaosDragons & msg);
		static ::proto_ff::activitychaosDragons* new_pbmsg(){ return new ::proto_ff::activitychaosDragons(); }
		static ::proto_ff::activitychaosDragons make_pbmsg(){ return ::proto_ff::activitychaosDragons(); }
	};
	typedef struct activitychaosDragons_s activitychaosDragons_t;

	struct Sheet_activitychaosDragons_s : public NFDescStoreSeqOP {
		Sheet_activitychaosDragons_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitychaosDragons_s, 20> activitychaosDragons_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitychaosDragons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitychaosDragons & msg);
		static ::proto_ff::Sheet_activitychaosDragons* new_pbmsg(){ return new ::proto_ff::Sheet_activitychaosDragons(); }
		static ::proto_ff::Sheet_activitychaosDragons make_pbmsg(){ return ::proto_ff::Sheet_activitychaosDragons(); }
	};
	typedef struct Sheet_activitychaosDragons_s Sheet_activitychaosDragons_t;

	struct activitycircus_s : public NFDescStoreSeqOP {
		activitycircus_s();
		int CreateInit();
		int ResumeInit();
		int64_t circusID;
		int64_t powerLow;
		int64_t powerUp;
		NFArray<int32_t, 32> circus_a;
		NFArray<int64_t, 32> circus_b;

		virtual void write_to_pbmsg(::proto_ff::activitycircus & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircus & msg);
		static ::proto_ff::activitycircus* new_pbmsg(){ return new ::proto_ff::activitycircus(); }
		static ::proto_ff::activitycircus make_pbmsg(){ return ::proto_ff::activitycircus(); }
	};
	typedef struct activitycircus_s activitycircus_t;

	struct Sheet_activitycircus_s : public NFDescStoreSeqOP {
		Sheet_activitycircus_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitycircus_s, 40> activitycircus_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitycircus & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitycircus & msg);
		static ::proto_ff::Sheet_activitycircus* new_pbmsg(){ return new ::proto_ff::Sheet_activitycircus(); }
		static ::proto_ff::Sheet_activitycircus make_pbmsg(){ return ::proto_ff::Sheet_activitycircus(); }
	};
	typedef struct Sheet_activitycircus_s Sheet_activitycircus_t;

	struct activitycircusNumitemDesc_s : public NFDescStoreSeqOP {
		activitycircusNumitemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::activitycircusNumitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircusNumitemDesc & msg);
		static ::proto_ff::activitycircusNumitemDesc* new_pbmsg(){ return new ::proto_ff::activitycircusNumitemDesc(); }
		static ::proto_ff::activitycircusNumitemDesc make_pbmsg(){ return ::proto_ff::activitycircusNumitemDesc(); }
	};
	typedef struct activitycircusNumitemDesc_s activitycircusNumitemDesc_t;

	struct activitycircusNum_s : public NFDescStoreSeqOP {
		activitycircusNum_s();
		int CreateInit();
		int ResumeInit();
		int32_t RankID;
		NFArray<struct activitycircusNumitemDesc_s, 3> item;

		virtual void write_to_pbmsg(::proto_ff::activitycircusNum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircusNum & msg);
		static ::proto_ff::activitycircusNum* new_pbmsg(){ return new ::proto_ff::activitycircusNum(); }
		static ::proto_ff::activitycircusNum make_pbmsg(){ return ::proto_ff::activitycircusNum(); }
	};
	typedef struct activitycircusNum_s activitycircusNum_t;

	struct Sheet_activitycircusNum_s : public NFDescStoreSeqOP {
		Sheet_activitycircusNum_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitycircusNum_s, 200> activitycircusNum_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitycircusNum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitycircusNum & msg);
		static ::proto_ff::Sheet_activitycircusNum* new_pbmsg(){ return new ::proto_ff::Sheet_activitycircusNum(); }
		static ::proto_ff::Sheet_activitycircusNum make_pbmsg(){ return ::proto_ff::Sheet_activitycircusNum(); }
	};
	typedef struct Sheet_activitycircusNum_s Sheet_activitycircusNum_t;

	struct activitycircusDanitemDesc_s : public NFDescStoreSeqOP {
		activitycircusDanitemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::activitycircusDanitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircusDanitemDesc & msg);
		static ::proto_ff::activitycircusDanitemDesc* new_pbmsg(){ return new ::proto_ff::activitycircusDanitemDesc(); }
		static ::proto_ff::activitycircusDanitemDesc make_pbmsg(){ return ::proto_ff::activitycircusDanitemDesc(); }
	};
	typedef struct activitycircusDanitemDesc_s activitycircusDanitemDesc_t;

	struct activitycircusDancircusDesc_s : public NFDescStoreSeqOP {
		activitycircusDancircusDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::activitycircusDancircusDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircusDancircusDesc & msg);
		static ::proto_ff::activitycircusDancircusDesc* new_pbmsg(){ return new ::proto_ff::activitycircusDancircusDesc(); }
		static ::proto_ff::activitycircusDancircusDesc make_pbmsg(){ return ::proto_ff::activitycircusDancircusDesc(); }
	};
	typedef struct activitycircusDancircusDesc_s activitycircusDancircusDesc_t;

	struct activitycircusDan_s : public NFDescStoreSeqOP {
		activitycircusDan_s();
		int CreateInit();
		int ResumeInit();
		int32_t changCiID;
		NFArray<struct activitycircusDanitemDesc_s, 3> item;
		NFArray<struct activitycircusDancircusDesc_s, 3> circus;

		virtual void write_to_pbmsg(::proto_ff::activitycircusDan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitycircusDan & msg);
		static ::proto_ff::activitycircusDan* new_pbmsg(){ return new ::proto_ff::activitycircusDan(); }
		static ::proto_ff::activitycircusDan make_pbmsg(){ return ::proto_ff::activitycircusDan(); }
	};
	typedef struct activitycircusDan_s activitycircusDan_t;

	struct Sheet_activitycircusDan_s : public NFDescStoreSeqOP {
		Sheet_activitycircusDan_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitycircusDan_s, 60> activitycircusDan_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitycircusDan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitycircusDan & msg);
		static ::proto_ff::Sheet_activitycircusDan* new_pbmsg(){ return new ::proto_ff::Sheet_activitycircusDan(); }
		static ::proto_ff::Sheet_activitycircusDan make_pbmsg(){ return ::proto_ff::Sheet_activitycircusDan(); }
	};
	typedef struct Sheet_activitycircusDan_s Sheet_activitycircusDan_t;

	struct activitymathrule_s : public NFDescStoreSeqOP {
		activitymathrule_s();
		int CreateInit();
		int ResumeInit();
		int64_t activeId;
		int32_t type;
		int64_t mapId;
		int64_t duplicateId;
		int32_t time;
		int32_t winnerPoints;
		int32_t loserPoints;
		int32_t drawPoints;
		int32_t rewardtype;

		virtual void write_to_pbmsg(::proto_ff::activitymathrule & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitymathrule & msg);
		static ::proto_ff::activitymathrule* new_pbmsg(){ return new ::proto_ff::activitymathrule(); }
		static ::proto_ff::activitymathrule make_pbmsg(){ return ::proto_ff::activitymathrule(); }
	};
	typedef struct activitymathrule_s activitymathrule_t;

	struct Sheet_activitymathrule_s : public NFDescStoreSeqOP {
		Sheet_activitymathrule_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitymathrule_s, 40> activitymathrule_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitymathrule & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitymathrule & msg);
		static ::proto_ff::Sheet_activitymathrule* new_pbmsg(){ return new ::proto_ff::Sheet_activitymathrule(); }
		static ::proto_ff::Sheet_activitymathrule make_pbmsg(){ return ::proto_ff::Sheet_activitymathrule(); }
	};
	typedef struct Sheet_activitymathrule_s Sheet_activitymathrule_t;

	struct activitymathrewardrewardDesc_s : public NFDescStoreSeqOP {
		activitymathrewardrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::activitymathrewardrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitymathrewardrewardDesc & msg);
		static ::proto_ff::activitymathrewardrewardDesc* new_pbmsg(){ return new ::proto_ff::activitymathrewardrewardDesc(); }
		static ::proto_ff::activitymathrewardrewardDesc make_pbmsg(){ return ::proto_ff::activitymathrewardrewardDesc(); }
	};
	typedef struct activitymathrewardrewardDesc_s activitymathrewardrewardDesc_t;

	struct activitymathreward_s : public NFDescStoreSeqOP {
		activitymathreward_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t rewardtype;
		int32_t rewardlevel;
		NFArray<struct activitymathrewardrewardDesc_s, 5> reward;
		NFArray<int64_t, 5> reward_ID;

		virtual void write_to_pbmsg(::proto_ff::activitymathreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitymathreward & msg);
		static ::proto_ff::activitymathreward* new_pbmsg(){ return new ::proto_ff::activitymathreward(); }
		static ::proto_ff::activitymathreward make_pbmsg(){ return ::proto_ff::activitymathreward(); }
	};
	typedef struct activitymathreward_s activitymathreward_t;

	struct Sheet_activitymathreward_s : public NFDescStoreSeqOP {
		Sheet_activitymathreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitymathreward_s, 20> activitymathreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitymathreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitymathreward & msg);
		static ::proto_ff::Sheet_activitymathreward* new_pbmsg(){ return new ::proto_ff::Sheet_activitymathreward(); }
		static ::proto_ff::Sheet_activitymathreward make_pbmsg(){ return ::proto_ff::Sheet_activitymathreward(); }
	};
	typedef struct Sheet_activitymathreward_s Sheet_activitymathreward_t;

	struct activitygvgConst_s : public NFDescStoreSeqOP {
		activitygvgConst_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t constantdata;
		NFSizeString<100> stringdata;

		virtual void write_to_pbmsg(::proto_ff::activitygvgConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgConst & msg);
		static ::proto_ff::activitygvgConst* new_pbmsg(){ return new ::proto_ff::activitygvgConst(); }
		static ::proto_ff::activitygvgConst make_pbmsg(){ return ::proto_ff::activitygvgConst(); }
	};
	typedef struct activitygvgConst_s activitygvgConst_t;

	struct Sheet_activitygvgConst_s : public NFDescStoreSeqOP {
		Sheet_activitygvgConst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitygvgConst_s, 160> activitygvgConst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitygvgConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitygvgConst & msg);
		static ::proto_ff::Sheet_activitygvgConst* new_pbmsg(){ return new ::proto_ff::Sheet_activitygvgConst(); }
		static ::proto_ff::Sheet_activitygvgConst make_pbmsg(){ return ::proto_ff::Sheet_activitygvgConst(); }
	};
	typedef struct Sheet_activitygvgConst_s Sheet_activitygvgConst_t;

	struct activitygvgRankRewardgMemberrewardDesc_s : public NFDescStoreSeqOP {
		activitygvgRankRewardgMemberrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::activitygvgRankRewardgMemberrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgRankRewardgMemberrewardDesc & msg);
		static ::proto_ff::activitygvgRankRewardgMemberrewardDesc* new_pbmsg(){ return new ::proto_ff::activitygvgRankRewardgMemberrewardDesc(); }
		static ::proto_ff::activitygvgRankRewardgMemberrewardDesc make_pbmsg(){ return ::proto_ff::activitygvgRankRewardgMemberrewardDesc(); }
	};
	typedef struct activitygvgRankRewardgMemberrewardDesc_s activitygvgRankRewardgMemberrewardDesc_t;

	struct activitygvgRankRewardgLeaderrewardDesc_s : public NFDescStoreSeqOP {
		activitygvgRankRewardgLeaderrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::activitygvgRankRewardgLeaderrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgRankRewardgLeaderrewardDesc & msg);
		static ::proto_ff::activitygvgRankRewardgLeaderrewardDesc* new_pbmsg(){ return new ::proto_ff::activitygvgRankRewardgLeaderrewardDesc(); }
		static ::proto_ff::activitygvgRankRewardgLeaderrewardDesc make_pbmsg(){ return ::proto_ff::activitygvgRankRewardgLeaderrewardDesc(); }
	};
	typedef struct activitygvgRankRewardgLeaderrewardDesc_s activitygvgRankRewardgLeaderrewardDesc_t;

	struct activitygvgRankReward_s : public NFDescStoreSeqOP {
		activitygvgRankReward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t gLeaderId;
		NFArray<struct activitygvgRankRewardgMemberrewardDesc_s, 4> gMemberreward;
		NFArray<struct activitygvgRankRewardgLeaderrewardDesc_s, 2> gLeaderreward;

		virtual void write_to_pbmsg(::proto_ff::activitygvgRankReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgRankReward & msg);
		static ::proto_ff::activitygvgRankReward* new_pbmsg(){ return new ::proto_ff::activitygvgRankReward(); }
		static ::proto_ff::activitygvgRankReward make_pbmsg(){ return ::proto_ff::activitygvgRankReward(); }
	};
	typedef struct activitygvgRankReward_s activitygvgRankReward_t;

	struct Sheet_activitygvgRankReward_s : public NFDescStoreSeqOP {
		Sheet_activitygvgRankReward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitygvgRankReward_s, 20> activitygvgRankReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitygvgRankReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitygvgRankReward & msg);
		static ::proto_ff::Sheet_activitygvgRankReward* new_pbmsg(){ return new ::proto_ff::Sheet_activitygvgRankReward(); }
		static ::proto_ff::Sheet_activitygvgRankReward make_pbmsg(){ return ::proto_ff::Sheet_activitygvgRankReward(); }
	};
	typedef struct Sheet_activitygvgRankReward_s Sheet_activitygvgRankReward_t;

	struct activitygvgRewardrewardDesc_s : public NFDescStoreSeqOP {
		activitygvgRewardrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::activitygvgRewardrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgRewardrewardDesc & msg);
		static ::proto_ff::activitygvgRewardrewardDesc* new_pbmsg(){ return new ::proto_ff::activitygvgRewardrewardDesc(); }
		static ::proto_ff::activitygvgRewardrewardDesc make_pbmsg(){ return ::proto_ff::activitygvgRewardrewardDesc(); }
	};
	typedef struct activitygvgRewardrewardDesc_s activitygvgRewardrewardDesc_t;

	struct activitygvgRewardfinalityDesc_s : public NFDescStoreSeqOP {
		activitygvgRewardfinalityDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;

		virtual void write_to_pbmsg(::proto_ff::activitygvgRewardfinalityDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgRewardfinalityDesc & msg);
		static ::proto_ff::activitygvgRewardfinalityDesc* new_pbmsg(){ return new ::proto_ff::activitygvgRewardfinalityDesc(); }
		static ::proto_ff::activitygvgRewardfinalityDesc make_pbmsg(){ return ::proto_ff::activitygvgRewardfinalityDesc(); }
	};
	typedef struct activitygvgRewardfinalityDesc_s activitygvgRewardfinalityDesc_t;

	struct activitygvgReward_s : public NFDescStoreSeqOP {
		activitygvgReward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t finalityskill;
		NFArray<struct activitygvgRewardrewardDesc_s, 5> reward;
		NFArray<struct activitygvgRewardfinalityDesc_s, 5> finality;
		NFArray<int64_t, 5> reward_id;
		NFArray<int64_t, 5> finality_id;

		virtual void write_to_pbmsg(::proto_ff::activitygvgReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitygvgReward & msg);
		static ::proto_ff::activitygvgReward* new_pbmsg(){ return new ::proto_ff::activitygvgReward(); }
		static ::proto_ff::activitygvgReward make_pbmsg(){ return ::proto_ff::activitygvgReward(); }
	};
	typedef struct activitygvgReward_s activitygvgReward_t;

	struct Sheet_activitygvgReward_s : public NFDescStoreSeqOP {
		Sheet_activitygvgReward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitygvgReward_s, 180> activitygvgReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitygvgReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitygvgReward & msg);
		static ::proto_ff::Sheet_activitygvgReward* new_pbmsg(){ return new ::proto_ff::Sheet_activitygvgReward(); }
		static ::proto_ff::Sheet_activitygvgReward make_pbmsg(){ return ::proto_ff::Sheet_activitygvgReward(); }
	};
	typedef struct Sheet_activitygvgReward_s Sheet_activitygvgReward_t;

	struct activityworldTreasureConst_s : public NFDescStoreSeqOP {
		activityworldTreasureConst_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t constantdata;

		virtual void write_to_pbmsg(::proto_ff::activityworldTreasureConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityworldTreasureConst & msg);
		static ::proto_ff::activityworldTreasureConst* new_pbmsg(){ return new ::proto_ff::activityworldTreasureConst(); }
		static ::proto_ff::activityworldTreasureConst make_pbmsg(){ return ::proto_ff::activityworldTreasureConst(); }
	};
	typedef struct activityworldTreasureConst_s activityworldTreasureConst_t;

	struct Sheet_activityworldTreasureConst_s : public NFDescStoreSeqOP {
		Sheet_activityworldTreasureConst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activityworldTreasureConst_s, 20> activityworldTreasureConst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureConst & msg);
		static ::proto_ff::Sheet_activityworldTreasureConst* new_pbmsg(){ return new ::proto_ff::Sheet_activityworldTreasureConst(); }
		static ::proto_ff::Sheet_activityworldTreasureConst make_pbmsg(){ return ::proto_ff::Sheet_activityworldTreasureConst(); }
	};
	typedef struct Sheet_activityworldTreasureConst_s Sheet_activityworldTreasureConst_t;

	struct activityworldTreasureMap_s : public NFDescStoreSeqOP {
		activityworldTreasureMap_s();
		int CreateInit();
		int ResumeInit();
		int64_t mapID;
		NFSizeString<600> pathID;

		virtual void write_to_pbmsg(::proto_ff::activityworldTreasureMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityworldTreasureMap & msg);
		static ::proto_ff::activityworldTreasureMap* new_pbmsg(){ return new ::proto_ff::activityworldTreasureMap(); }
		static ::proto_ff::activityworldTreasureMap make_pbmsg(){ return ::proto_ff::activityworldTreasureMap(); }
	};
	typedef struct activityworldTreasureMap_s activityworldTreasureMap_t;

	struct Sheet_activityworldTreasureMap_s : public NFDescStoreSeqOP {
		Sheet_activityworldTreasureMap_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activityworldTreasureMap_s, 20> activityworldTreasureMap_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureMap & msg);
		static ::proto_ff::Sheet_activityworldTreasureMap* new_pbmsg(){ return new ::proto_ff::Sheet_activityworldTreasureMap(); }
		static ::proto_ff::Sheet_activityworldTreasureMap make_pbmsg(){ return ::proto_ff::Sheet_activityworldTreasureMap(); }
	};
	typedef struct Sheet_activityworldTreasureMap_s Sheet_activityworldTreasureMap_t;

	struct activityworldTreasureMonster_s : public NFDescStoreSeqOP {
		activityworldTreasureMonster_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t monsterID;
		int32_t appearWeight;
		int64_t skillId;

		virtual void write_to_pbmsg(::proto_ff::activityworldTreasureMonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activityworldTreasureMonster & msg);
		static ::proto_ff::activityworldTreasureMonster* new_pbmsg(){ return new ::proto_ff::activityworldTreasureMonster(); }
		static ::proto_ff::activityworldTreasureMonster make_pbmsg(){ return ::proto_ff::activityworldTreasureMonster(); }
	};
	typedef struct activityworldTreasureMonster_s activityworldTreasureMonster_t;

	struct Sheet_activityworldTreasureMonster_s : public NFDescStoreSeqOP {
		Sheet_activityworldTreasureMonster_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activityworldTreasureMonster_s, 20> activityworldTreasureMonster_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureMonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureMonster & msg);
		static ::proto_ff::Sheet_activityworldTreasureMonster* new_pbmsg(){ return new ::proto_ff::Sheet_activityworldTreasureMonster(); }
		static ::proto_ff::Sheet_activityworldTreasureMonster make_pbmsg(){ return ::proto_ff::Sheet_activityworldTreasureMonster(); }
	};
	typedef struct Sheet_activityworldTreasureMonster_s Sheet_activityworldTreasureMonster_t;

	struct activitylosttempleConstant_s : public NFDescStoreSeqOP {
		activitylosttempleConstant_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t constantdata;
		NFSizeString<60> stringdata;

		virtual void write_to_pbmsg(::proto_ff::activitylosttempleConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::activitylosttempleConstant & msg);
		static ::proto_ff::activitylosttempleConstant* new_pbmsg(){ return new ::proto_ff::activitylosttempleConstant(); }
		static ::proto_ff::activitylosttempleConstant make_pbmsg(){ return ::proto_ff::activitylosttempleConstant(); }
	};
	typedef struct activitylosttempleConstant_s activitylosttempleConstant_t;

	struct Sheet_activitylosttempleConstant_s : public NFDescStoreSeqOP {
		Sheet_activitylosttempleConstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct activitylosttempleConstant_s, 20> activitylosttempleConstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_activitylosttempleConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_activitylosttempleConstant & msg);
		static ::proto_ff::Sheet_activitylosttempleConstant* new_pbmsg(){ return new ::proto_ff::Sheet_activitylosttempleConstant(); }
		static ::proto_ff::Sheet_activitylosttempleConstant make_pbmsg(){ return ::proto_ff::Sheet_activitylosttempleConstant(); }
	};
	typedef struct Sheet_activitylosttempleConstant_s Sheet_activitylosttempleConstant_t;

}

