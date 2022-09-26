#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "guild.pb.h"
#include "guild_s.h"

namespace proto_ff_s {

	struct guildconstant_s : public NFDescStoreSeqOP {
		guildconstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t constantid;
		int32_t setDiamond;
		int32_t offlineTime;
		int32_t EditRequireLV;
		int32_t leaveCoolingtime;
		int32_t houseLimit;
		int64_t expID;
		int32_t houseScore;
		int32_t giftCD;
		int32_t autoCleanCellNum;
		int32_t dismiss;
		int32_t transferGuild;

		virtual void write_to_pbmsg(::proto_ff::guildconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildconstant & msg);
		static ::proto_ff::guildconstant* new_pbmsg(){ return new ::proto_ff::guildconstant(); }
		static ::proto_ff::guildconstant make_pbmsg(){ return ::proto_ff::guildconstant(); }
	};
	typedef struct guildconstant_s guildconstant_t;

	struct Sheet_guildconstant_s : public NFDescStoreSeqOP {
		Sheet_guildconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildconstant_s, 105> guildconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildconstant & msg);
		static ::proto_ff::Sheet_guildconstant* new_pbmsg(){ return new ::proto_ff::Sheet_guildconstant(); }
		static ::proto_ff::Sheet_guildconstant make_pbmsg(){ return ::proto_ff::Sheet_guildconstant(); }
	};
	typedef struct Sheet_guildconstant_s Sheet_guildconstant_t;

	struct guildlevel_s : public NFDescStoreSeqOP {
		guildlevel_s();
		int CreateInit();
		int ResumeInit();
		int32_t guildLevel;
		int32_t guildLevel_EXP;
		int32_t guildLevel_member;
		int32_t guildLevel_VP;
		int32_t guildLevel_NP;

		virtual void write_to_pbmsg(::proto_ff::guildlevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildlevel & msg);
		static ::proto_ff::guildlevel* new_pbmsg(){ return new ::proto_ff::guildlevel(); }
		static ::proto_ff::guildlevel make_pbmsg(){ return ::proto_ff::guildlevel(); }
	};
	typedef struct guildlevel_s guildlevel_t;

	struct Sheet_guildlevel_s : public NFDescStoreSeqOP {
		Sheet_guildlevel_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildlevel_s, 119> guildlevel_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildlevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildlevel & msg);
		static ::proto_ff::Sheet_guildlevel* new_pbmsg(){ return new ::proto_ff::Sheet_guildlevel(); }
		static ::proto_ff::Sheet_guildlevel make_pbmsg(){ return ::proto_ff::Sheet_guildlevel(); }
	};
	typedef struct Sheet_guildlevel_s Sheet_guildlevel_t;

	struct guildcollege_s : public NFDescStoreSeqOP {
		guildcollege_s();
		int CreateInit();
		int ResumeInit();
		int64_t practiceId;
		int32_t practiceType;
		int32_t learningNeed;
		int32_t practiceLevel;
		int32_t playerLevelLimit;
		int32_t attributeId;
		int32_t attributeGain;
		int32_t CostContribute;

		virtual void write_to_pbmsg(::proto_ff::guildcollege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildcollege & msg);
		static ::proto_ff::guildcollege* new_pbmsg(){ return new ::proto_ff::guildcollege(); }
		static ::proto_ff::guildcollege make_pbmsg(){ return ::proto_ff::guildcollege(); }
	};
	typedef struct guildcollege_s guildcollege_t;

	struct Sheet_guildcollege_s : public NFDescStoreSeqOP {
		Sheet_guildcollege_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildcollege_s, 5104> guildcollege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildcollege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildcollege & msg);
		static ::proto_ff::Sheet_guildcollege* new_pbmsg(){ return new ::proto_ff::Sheet_guildcollege(); }
		static ::proto_ff::Sheet_guildcollege make_pbmsg(){ return ::proto_ff::Sheet_guildcollege(); }
	};
	typedef struct Sheet_guildcollege_s Sheet_guildcollege_t;

	struct guildposition_s : public NFDescStoreSeqOP {
		guildposition_s();
		int CreateInit();
		int ResumeInit();
		int64_t positionId;
		int32_t positionType;
		int32_t allotMaterials;
		int32_t admitNewcomer;
		int32_t appointAndRemoveVP;
		int32_t appointAndRemoveElder;
		int32_t expelVP;
		int32_t expelElder;
		int32_t expelMass;
		int32_t announcementEditing;
		int32_t joinCondition;
		int32_t guildActivity;
		int32_t dissolveAssignGuild;
		int32_t clear;
		int32_t changeName;
		int32_t automaticCleanDisplay;

		virtual void write_to_pbmsg(::proto_ff::guildposition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildposition & msg);
		static ::proto_ff::guildposition* new_pbmsg(){ return new ::proto_ff::guildposition(); }
		static ::proto_ff::guildposition make_pbmsg(){ return ::proto_ff::guildposition(); }
	};
	typedef struct guildposition_s guildposition_t;

	struct Sheet_guildposition_s : public NFDescStoreSeqOP {
		Sheet_guildposition_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildposition_s, 108> guildposition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildposition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildposition & msg);
		static ::proto_ff::Sheet_guildposition* new_pbmsg(){ return new ::proto_ff::Sheet_guildposition(); }
		static ::proto_ff::Sheet_guildposition make_pbmsg(){ return ::proto_ff::Sheet_guildposition(); }
	};
	typedef struct Sheet_guildposition_s Sheet_guildposition_t;

	struct guildhouse_s : public NFDescStoreSeqOP {
		guildhouse_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t wearQuality;
		int32_t quality;
		int32_t houseScore;

		virtual void write_to_pbmsg(::proto_ff::guildhouse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildhouse & msg);
		static ::proto_ff::guildhouse* new_pbmsg(){ return new ::proto_ff::guildhouse(); }
		static ::proto_ff::guildhouse make_pbmsg(){ return ::proto_ff::guildhouse(); }
	};
	typedef struct guildhouse_s guildhouse_t;

	struct Sheet_guildhouse_s : public NFDescStoreSeqOP {
		Sheet_guildhouse_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildhouse_s, 209> guildhouse_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildhouse & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildhouse & msg);
		static ::proto_ff::Sheet_guildhouse* new_pbmsg(){ return new ::proto_ff::Sheet_guildhouse(); }
		static ::proto_ff::Sheet_guildhouse make_pbmsg(){ return ::proto_ff::Sheet_guildhouse(); }
	};
	typedef struct Sheet_guildhouse_s Sheet_guildhouse_t;

	struct guildgift_s : public NFDescStoreSeqOP {
		guildgift_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t type;
		int32_t money;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::guildgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildgift & msg);
		static ::proto_ff::guildgift* new_pbmsg(){ return new ::proto_ff::guildgift(); }
		static ::proto_ff::guildgift make_pbmsg(){ return ::proto_ff::guildgift(); }
	};
	typedef struct guildgift_s guildgift_t;

	struct Sheet_guildgift_s : public NFDescStoreSeqOP {
		Sheet_guildgift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildgift_s, 128> guildgift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildgift & msg);
		static ::proto_ff::Sheet_guildgift* new_pbmsg(){ return new ::proto_ff::Sheet_guildgift(); }
		static ::proto_ff::Sheet_guildgift make_pbmsg(){ return ::proto_ff::Sheet_guildgift(); }
	};
	typedef struct Sheet_guildgift_s Sheet_guildgift_t;

	struct guildguildance_s : public NFDescStoreSeqOP {
		guildguildance_s();
		int CreateInit();
		int ResumeInit();
		int32_t guidanceId;
		int32_t guidanceType;
		int32_t levelLimit;
		int32_t triggerTpye;
		int32_t cognateNpcId;
		int32_t cognateUI;
		int32_t cognateActiveId;

		virtual void write_to_pbmsg(::proto_ff::guildguildance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildguildance & msg);
		static ::proto_ff::guildguildance* new_pbmsg(){ return new ::proto_ff::guildguildance(); }
		static ::proto_ff::guildguildance make_pbmsg(){ return ::proto_ff::guildguildance(); }
	};
	typedef struct guildguildance_s guildguildance_t;

	struct Sheet_guildguildance_s : public NFDescStoreSeqOP {
		Sheet_guildguildance_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildguildance_s, 111> guildguildance_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildguildance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildguildance & msg);
		static ::proto_ff::Sheet_guildguildance* new_pbmsg(){ return new ::proto_ff::Sheet_guildguildance(); }
		static ::proto_ff::Sheet_guildguildance make_pbmsg(){ return ::proto_ff::Sheet_guildguildance(); }
	};
	typedef struct Sheet_guildguildance_s Sheet_guildguildance_t;

	struct guildwarconstant_s : public NFDescStoreSeqOP {
		guildwarconstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t warid;
		int32_t signopenCycle;
		NFSizeString<32> signopenTime;
		int32_t signclosedCycle;
		NFSizeString<32> signclosedTime;
		int32_t guildPosition;
		int32_t guildNum;
		int32_t guildLevel;
		int32_t enteropenCycle;
		NFSizeString<32> enteropenTime;
		int32_t enterclosedCycle;
		NFSizeString<32> enterclosedTime;
		int32_t guildwarBaseScore;
		int32_t guildwarWinScore;
		int32_t guildwarLoseScore;
		int32_t guildwarDrawScore;
		int32_t maxMaterial;
		int32_t soldierCostMaterial;
		int32_t soldierNum;
		int32_t soldierCD;
		int32_t renewBaseCost;
		int32_t renewBaseHP;
		int32_t renewBaseCD;
		int32_t reviveCD;
		int64_t guildwarWinItem;
		int32_t guildwarWinNum;
		int64_t guildwarLoseItem;
		int32_t guildwarLoseNum;
		int64_t guildwarDrawItem;
		int32_t guildwarDrawNum;
		int64_t MaterialId;
		int32_t MaterialConversion;
		int32_t GuildWarExp;

		virtual void write_to_pbmsg(::proto_ff::guildwarconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildwarconstant & msg);
		static ::proto_ff::guildwarconstant* new_pbmsg(){ return new ::proto_ff::guildwarconstant(); }
		static ::proto_ff::guildwarconstant make_pbmsg(){ return ::proto_ff::guildwarconstant(); }
	};
	typedef struct guildwarconstant_s guildwarconstant_t;

	struct Sheet_guildwarconstant_s : public NFDescStoreSeqOP {
		Sheet_guildwarconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildwarconstant_s, 105> guildwarconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildwarconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildwarconstant & msg);
		static ::proto_ff::Sheet_guildwarconstant* new_pbmsg(){ return new ::proto_ff::Sheet_guildwarconstant(); }
		static ::proto_ff::Sheet_guildwarconstant make_pbmsg(){ return ::proto_ff::Sheet_guildwarconstant(); }
	};
	typedef struct Sheet_guildwarconstant_s Sheet_guildwarconstant_t;

	struct guildwarmorale_s : public NFDescStoreSeqOP {
		guildwarmorale_s();
		int CreateInit();
		int ResumeInit();
		int64_t moraleLevel;
		int32_t costMaterial;
		int64_t skillId;
		int32_t skillLevel;

		virtual void write_to_pbmsg(::proto_ff::guildwarmorale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildwarmorale & msg);
		static ::proto_ff::guildwarmorale* new_pbmsg(){ return new ::proto_ff::guildwarmorale(); }
		static ::proto_ff::guildwarmorale make_pbmsg(){ return ::proto_ff::guildwarmorale(); }
	};
	typedef struct guildwarmorale_s guildwarmorale_t;

	struct Sheet_guildwarmorale_s : public NFDescStoreSeqOP {
		Sheet_guildwarmorale_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildwarmorale_s, 114> guildwarmorale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildwarmorale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildwarmorale & msg);
		static ::proto_ff::Sheet_guildwarmorale* new_pbmsg(){ return new ::proto_ff::Sheet_guildwarmorale(); }
		static ::proto_ff::Sheet_guildwarmorale make_pbmsg(){ return ::proto_ff::Sheet_guildwarmorale(); }
	};
	typedef struct Sheet_guildwarmorale_s Sheet_guildwarmorale_t;

	struct guildwarrevive_s : public NFDescStoreSeqOP {
		guildwarrevive_s();
		int CreateInit();
		int ResumeInit();
		int32_t reviveNum;
		int32_t reviveCost;

		virtual void write_to_pbmsg(::proto_ff::guildwarrevive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::guildwarrevive & msg);
		static ::proto_ff::guildwarrevive* new_pbmsg(){ return new ::proto_ff::guildwarrevive(); }
		static ::proto_ff::guildwarrevive make_pbmsg(){ return ::proto_ff::guildwarrevive(); }
	};
	typedef struct guildwarrevive_s guildwarrevive_t;

	struct Sheet_guildwarrevive_s : public NFDescStoreSeqOP {
		Sheet_guildwarrevive_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct guildwarrevive_s, 114> guildwarrevive_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_guildwarrevive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_guildwarrevive & msg);
		static ::proto_ff::Sheet_guildwarrevive* new_pbmsg(){ return new ::proto_ff::Sheet_guildwarrevive(); }
		static ::proto_ff::Sheet_guildwarrevive make_pbmsg(){ return ::proto_ff::Sheet_guildwarrevive(); }
	};
	typedef struct Sheet_guildwarrevive_s Sheet_guildwarrevive_t;

}

