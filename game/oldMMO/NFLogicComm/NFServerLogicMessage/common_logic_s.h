#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "common_logic.pb.h"
#include "common_logic_s.h"

namespace proto_ff_s {

	struct PacketMsg_s {
		PacketMsg_s();
		int CreateInit();
		int ResumeInit();
		uint32_t cmd;
		uint32_t serverType;
		uint32_t upper_limit;
		uint32_t min_interval;
		uint32_t control_time;

		virtual void write_to_pbmsg(::proto_ff::PacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PacketMsg & msg);
		static ::proto_ff::PacketMsg* new_pbmsg(){ return new ::proto_ff::PacketMsg(); }
		static ::proto_ff::PacketMsg make_pbmsg(){ return ::proto_ff::PacketMsg(); }
	};
	typedef struct PacketMsg_s PacketMsg_t;

	struct ServerPacketMsg_s {
		ServerPacketMsg_s();
		int CreateInit();
		int ResumeInit();
		std::vector<struct PacketMsg_s> PacketMsg;

		virtual void write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg);
		static ::proto_ff::ServerPacketMsg* new_pbmsg(){ return new ::proto_ff::ServerPacketMsg(); }
		static ::proto_ff::ServerPacketMsg make_pbmsg(){ return ::proto_ff::ServerPacketMsg(); }
	};
	typedef struct ServerPacketMsg_s ServerPacketMsg_t;

	struct WorldExternalConfig_s {
		WorldExternalConfig_s();
		int CreateInit();
		int ResumeInit();
		bool TokenTimeCheck;

		virtual void write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg);
		static ::proto_ff::WorldExternalConfig* new_pbmsg(){ return new ::proto_ff::WorldExternalConfig(); }
		static ::proto_ff::WorldExternalConfig make_pbmsg(){ return ::proto_ff::WorldExternalConfig(); }
	};
	typedef struct WorldExternalConfig_s WorldExternalConfig_t;

	struct CharFacadeProto_s : public NFDescStoreSeqOP {
		CharFacadeProto_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cur_mount_id;
		uint64_t wing_id;
		uint64_t fashion_clothes_id;
		uint64_t fashion_weapon_id;
		uint64_t occupationId;
		uint64_t treasure_id;
		int32_t treasure_type;
		uint64_t artifact_id;
		uint64_t cur_select_mount_id;
		uint64_t partner_id;
		uint64_t head_id;
		uint64_t frame_id;
		uint64_t bubble_id;

		virtual void write_to_pbmsg(::proto_ff::CharFacadeProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharFacadeProto & msg);
		static ::proto_ff::CharFacadeProto* new_pbmsg(){ return new ::proto_ff::CharFacadeProto(); }
		static ::proto_ff::CharFacadeProto make_pbmsg(){ return ::proto_ff::CharFacadeProto(); }
	};
	typedef struct CharFacadeProto_s CharFacadeProto_t;

	struct CharTrimProto_s : public NFDescStoreSeqOP {
		CharTrimProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t trim_type;
		int32_t trim_level;

		virtual void write_to_pbmsg(::proto_ff::CharTrimProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharTrimProto & msg);
		static ::proto_ff::CharTrimProto* new_pbmsg(){ return new ::proto_ff::CharTrimProto(); }
		static ::proto_ff::CharTrimProto make_pbmsg(){ return ::proto_ff::CharTrimProto(); }
	};
	typedef struct CharTrimProto_s CharTrimProto_t;

	struct ForceDupProto_s : public NFDescStoreSeqOP {
		ForceDupProto_s();
		int CreateInit();
		int ResumeInit();
		int32_t treasure_state;
		int32_t ladder_state;

		virtual void write_to_pbmsg(::proto_ff::ForceDupProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ForceDupProto & msg);
		static ::proto_ff::ForceDupProto* new_pbmsg(){ return new ::proto_ff::ForceDupProto(); }
		static ::proto_ff::ForceDupProto make_pbmsg(){ return ::proto_ff::ForceDupProto(); }
	};
	typedef struct ForceDupProto_s ForceDupProto_t;

	struct CharMultTrimProto_s : public NFDescStoreSeqOP {
		CharMultTrimProto_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct CharTrimProto_s, 128> trim_lst;

		virtual void write_to_pbmsg(::proto_ff::CharMultTrimProto & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharMultTrimProto & msg);
		static ::proto_ff::CharMultTrimProto* new_pbmsg(){ return new ::proto_ff::CharMultTrimProto(); }
		static ::proto_ff::CharMultTrimProto make_pbmsg(){ return ::proto_ff::CharMultTrimProto(); }
	};
	typedef struct CharMultTrimProto_s CharMultTrimProto_t;

	struct CharacterDBBaseInfo_s : public NFDescStoreSeqOP {
		CharacterDBBaseInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t createTime;
		uint64_t lastSaveTime;
		uint64_t onlineTime;
		uint64_t loginTime;
		uint64_t logoutTime;
		NFSizeString<128> name;
		uint32_t sex;
		uint32_t prof;
		uint32_t level;
		int64_t exp;
		int64_t hp;
		int64_t fight;
		uint64_t gold;
		uint64_t diamond;
		uint64_t binddiamond;
		uint64_t enter_scene_id;
		uint64_t enter_map_id;
		float enterPosX;
		float enterPosY;
		float enterPosZ;
		uint64_t lastSceneId;
		uint64_t lastMapId;
		float lastPosX;
		float lastPosY;
		float lastPosZ;
		uint64_t lastReviveTime;
		uint32_t curState;
		float clx;
		float cly;
		float clz;
		uint64_t occupation;
		uint64_t aptitude;
		struct CharFacadeProto_s facade;
		int64_t arenacoin;
		int64_t starEssence;
		int64_t starExp;
		int64_t starFragment;
		int64_t hangUpTime;
		uint32_t active_num;
		int64_t vipLevel;
		int64_t godhoodExp;
		int64_t smallSpirit;
		int64_t bigSpirit;
		struct CharMultTrimProto_s trim;
		int32_t finish_flag;
		NFSizeString<128> guide;
		struct ForceDupProto_s force;
		int64_t useTitle;
		int32_t subpack_type;
		int32_t subpack_fetch;
		int32_t rechargeDiscountDate;
		int32_t friendNum;
		NFSizeString<128> platid;
		int32_t solo_score;
		int32_t solo_prv_score;
		int32_t dragons_num;
		uint32_t total_login_day;
		uint64_t login_day_time;
		int32_t login_gift;
		int64_t vipCardDiamond;
		uint64_t holydia;
		int32_t relive_num;
		int64_t last_relive_time;
		int64_t dead_static_map_id;
		int32_t dead_static_num;
		int64_t dead_static_cd;
		int32_t fushi_time;
		int64_t starStone;
		int64_t voucher;
		int64_t waiguan;
		int64_t gmpoint;
		int64_t gmpoint_limit;

		virtual void write_to_pbmsg(::proto_ff::CharacterDBBaseInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::CharacterDBBaseInfo & msg);
		static ::proto_ff::CharacterDBBaseInfo* new_pbmsg(){ return new ::proto_ff::CharacterDBBaseInfo(); }
		static ::proto_ff::CharacterDBBaseInfo make_pbmsg(){ return ::proto_ff::CharacterDBBaseInfo(); }
	};
	typedef struct CharacterDBBaseInfo_s CharacterDBBaseInfo_t;

	struct tbRoleInfo_s : public NFDescStoreSeqOP {
		tbRoleInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t charId;
		uint64_t playerId;
		uint64_t bornZoneId;
		NFSizeString<128> charName;
		NFSizeString<128> platId;
		struct CharacterDBBaseInfo_s baseData;

		virtual void write_to_pbmsg(::proto_ff::tbRoleInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbRoleInfo & msg);
		static ::proto_ff::tbRoleInfo* new_pbmsg(){ return new ::proto_ff::tbRoleInfo(); }
		static ::proto_ff::tbRoleInfo make_pbmsg(){ return ::proto_ff::tbRoleInfo(); }
	};
	typedef struct tbRoleInfo_s tbRoleInfo_t;

}

