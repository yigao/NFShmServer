#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "guild.pb.h"
#include "guild_s.h"

namespace proto_ff_s {

	struct E_GuildConstant_s : public NFDescStoreSeqOP {
		E_GuildConstant_s();
		virtual ~E_GuildConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_constantid;
		int32_t m_setitem;
		int32_t m_nameitem;
		int32_t m_editrequirelv;
		int32_t m_giftcd;
		int32_t m_dismiss;
		int32_t m_transferguild;
		int32_t m_territory;

		virtual void write_to_pbmsg(::proto_ff::E_GuildConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildConstant & msg);
		static ::proto_ff::E_GuildConstant* new_pbmsg(){ return new ::proto_ff::E_GuildConstant(); }
		static ::proto_ff::E_GuildConstant make_pbmsg(){ return ::proto_ff::E_GuildConstant(); }
	};
	typedef struct E_GuildConstant_s E_GuildConstant_t;

	struct Sheet_GuildConstant_s : public NFDescStoreSeqOP {
		Sheet_GuildConstant_s();
		virtual ~Sheet_GuildConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildConstant_s, 20> E_GuildConstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildConstant & msg);
		static ::proto_ff::Sheet_GuildConstant* new_pbmsg(){ return new ::proto_ff::Sheet_GuildConstant(); }
		static ::proto_ff::Sheet_GuildConstant make_pbmsg(){ return ::proto_ff::Sheet_GuildConstant(); }
	};
	typedef struct Sheet_GuildConstant_s Sheet_GuildConstant_t;

	struct E_GuildLevel_s : public NFDescStoreSeqOP {
		E_GuildLevel_s();
		virtual ~E_GuildLevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_guildlevel;
		int32_t m_guildlevel_exp;
		int32_t m_guildlevel_member;
		int32_t m_guildlevel_vp;
		int32_t m_guildlevel_np;
		int32_t m_guildlevel_g;

		virtual void write_to_pbmsg(::proto_ff::E_GuildLevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildLevel & msg);
		static ::proto_ff::E_GuildLevel* new_pbmsg(){ return new ::proto_ff::E_GuildLevel(); }
		static ::proto_ff::E_GuildLevel make_pbmsg(){ return ::proto_ff::E_GuildLevel(); }
	};
	typedef struct E_GuildLevel_s E_GuildLevel_t;

	struct Sheet_GuildLevel_s : public NFDescStoreSeqOP {
		Sheet_GuildLevel_s();
		virtual ~Sheet_GuildLevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildLevel_s, 20> E_GuildLevel_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildLevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildLevel & msg);
		static ::proto_ff::Sheet_GuildLevel* new_pbmsg(){ return new ::proto_ff::Sheet_GuildLevel(); }
		static ::proto_ff::Sheet_GuildLevel make_pbmsg(){ return ::proto_ff::Sheet_GuildLevel(); }
	};
	typedef struct Sheet_GuildLevel_s Sheet_GuildLevel_t;

	struct E_GuildPosition_s : public NFDescStoreSeqOP {
		E_GuildPosition_s();
		virtual ~E_GuildPosition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_positionid;
		int32_t m_admitnewcomer;
		int32_t m_appointandremovevp;
		int32_t m_appointandremoveelder;
		int32_t m_appointandremoveg;
		int32_t m_appointandremoveelite;
		int32_t m_expelvp;
		int32_t m_expelelder;
		int32_t m_expelg;
		int32_t m_expelmass;
		int32_t m_announcementediting;
		int32_t m_rname;
		int32_t m_joincondition;
		int32_t m_guildactivity;
		int32_t m_dissolveassignguild;
		int32_t m_changename;
		int32_t m_recruitchat;

		virtual void write_to_pbmsg(::proto_ff::E_GuildPosition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPosition & msg);
		static ::proto_ff::E_GuildPosition* new_pbmsg(){ return new ::proto_ff::E_GuildPosition(); }
		static ::proto_ff::E_GuildPosition make_pbmsg(){ return ::proto_ff::E_GuildPosition(); }
	};
	typedef struct E_GuildPosition_s E_GuildPosition_t;

	struct Sheet_GuildPosition_s : public NFDescStoreSeqOP {
		Sheet_GuildPosition_s();
		virtual ~Sheet_GuildPosition_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPosition_s, 20> E_GuildPosition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPosition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPosition & msg);
		static ::proto_ff::Sheet_GuildPosition* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPosition(); }
		static ::proto_ff::Sheet_GuildPosition make_pbmsg(){ return ::proto_ff::Sheet_GuildPosition(); }
	};
	typedef struct Sheet_GuildPosition_s Sheet_GuildPosition_t;

}

