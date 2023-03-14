#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "guild.pb.h"
#include "guild_s.h"

#define DEFINE_SHEET_GUILDCONSTANT_E_GUILDCONSTANT_LIST_MAX_NUM 20
#define DEFINE_SHEET_GUILDLEVEL_E_GUILDLEVEL_LIST_MAX_NUM 20
#define DEFINE_SHEET_GUILDPOSITION_E_GUILDPOSITION_LIST_MAX_NUM 20
#define DEFINE_E_GUILDSALARY_M_REWARD_MAX_NUM 3
#define DEFINE_SHEET_GUILDSALARY_E_GUILDSALARY_LIST_MAX_NUM 20
#define DEFINE_E_GUILDDONATE_M_REWARD_MAX_NUM 3
#define DEFINE_SHEET_GUILDDONATE_E_GUILDDONATE_LIST_MAX_NUM 20
#define DEFINE_SHEET_GUILDPACKET_E_GUILDPACKET_LIST_MAX_NUM 80
#define DEFINE_SHEET_GUILDPRESTIGETASK_E_GUILDPRESTIGETASK_LIST_MAX_NUM 20
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
		int32_t m_autominlv;
		int32_t m_autominbp;
		int32_t m_donatetimes;
		int32_t m_packetmaxd;
		int32_t m_packetmaxbd;
		int32_t m_packetmaxsend;
		int32_t m_packetvip;
		int32_t m_packetadd;
		int32_t m_prestigetasonekeyvip;
		int32_t m_prestigetasonekeylv;
		int32_t m_prestigetaskprivage;
		int32_t m_prestigetaskflash;
		int32_t m_prestigetaskflashprice;
		int32_t m_prestigetasktimes;

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
		NFShmVector<struct E_GuildConstant_s, DEFINE_SHEET_GUILDCONSTANT_E_GUILDCONSTANT_LIST_MAX_NUM> E_GuildConstant_List;

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
		NFShmVector<struct E_GuildLevel_s, DEFINE_SHEET_GUILDLEVEL_E_GUILDLEVEL_LIST_MAX_NUM> E_GuildLevel_List;

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
		int32_t m_guildpacket;

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
		NFShmVector<struct E_GuildPosition_s, DEFINE_SHEET_GUILDPOSITION_E_GUILDPOSITION_LIST_MAX_NUM> E_GuildPosition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPosition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPosition & msg);
		static ::proto_ff::Sheet_GuildPosition* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPosition(); }
		static ::proto_ff::Sheet_GuildPosition make_pbmsg(){ return ::proto_ff::Sheet_GuildPosition(); }
	};
	typedef struct Sheet_GuildPosition_s Sheet_GuildPosition_t;

	struct E_GuildSalaryRewardDesc_s : public NFDescStoreSeqOP {
		E_GuildSalaryRewardDesc_s();
		virtual ~E_GuildSalaryRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_item;
		int32_t m_num;

		virtual void write_to_pbmsg(::proto_ff::E_GuildSalaryRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildSalaryRewardDesc & msg);
		static ::proto_ff::E_GuildSalaryRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GuildSalaryRewardDesc(); }
		static ::proto_ff::E_GuildSalaryRewardDesc make_pbmsg(){ return ::proto_ff::E_GuildSalaryRewardDesc(); }
	};
	typedef struct E_GuildSalaryRewardDesc_s E_GuildSalaryRewardDesc_t;

	struct E_GuildSalary_s : public NFDescStoreSeqOP {
		E_GuildSalary_s();
		virtual ~E_GuildSalary_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_typearg;
		int32_t m_times;
		NFShmVector<struct E_GuildSalaryRewardDesc_s, DEFINE_E_GUILDSALARY_M_REWARD_MAX_NUM> m_reward;

		virtual void write_to_pbmsg(::proto_ff::E_GuildSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildSalary & msg);
		static ::proto_ff::E_GuildSalary* new_pbmsg(){ return new ::proto_ff::E_GuildSalary(); }
		static ::proto_ff::E_GuildSalary make_pbmsg(){ return ::proto_ff::E_GuildSalary(); }
	};
	typedef struct E_GuildSalary_s E_GuildSalary_t;

	struct Sheet_GuildSalary_s : public NFDescStoreSeqOP {
		Sheet_GuildSalary_s();
		virtual ~Sheet_GuildSalary_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildSalary_s, DEFINE_SHEET_GUILDSALARY_E_GUILDSALARY_LIST_MAX_NUM> E_GuildSalary_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildSalary & msg);
		static ::proto_ff::Sheet_GuildSalary* new_pbmsg(){ return new ::proto_ff::Sheet_GuildSalary(); }
		static ::proto_ff::Sheet_GuildSalary make_pbmsg(){ return ::proto_ff::Sheet_GuildSalary(); }
	};
	typedef struct Sheet_GuildSalary_s Sheet_GuildSalary_t;

	struct E_GuildDonateRewardDesc_s : public NFDescStoreSeqOP {
		E_GuildDonateRewardDesc_s();
		virtual ~E_GuildDonateRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_item;
		int32_t m_num;

		virtual void write_to_pbmsg(::proto_ff::E_GuildDonateRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildDonateRewardDesc & msg);
		static ::proto_ff::E_GuildDonateRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GuildDonateRewardDesc(); }
		static ::proto_ff::E_GuildDonateRewardDesc make_pbmsg(){ return ::proto_ff::E_GuildDonateRewardDesc(); }
	};
	typedef struct E_GuildDonateRewardDesc_s E_GuildDonateRewardDesc_t;

	struct E_GuildDonate_s : public NFDescStoreSeqOP {
		E_GuildDonate_s();
		virtual ~E_GuildDonate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_costitem;
		int32_t m_costnum;
		NFShmVector<struct E_GuildDonateRewardDesc_s, DEFINE_E_GUILDDONATE_M_REWARD_MAX_NUM> m_reward;

		virtual void write_to_pbmsg(::proto_ff::E_GuildDonate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildDonate & msg);
		static ::proto_ff::E_GuildDonate* new_pbmsg(){ return new ::proto_ff::E_GuildDonate(); }
		static ::proto_ff::E_GuildDonate make_pbmsg(){ return ::proto_ff::E_GuildDonate(); }
	};
	typedef struct E_GuildDonate_s E_GuildDonate_t;

	struct Sheet_GuildDonate_s : public NFDescStoreSeqOP {
		Sheet_GuildDonate_s();
		virtual ~Sheet_GuildDonate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildDonate_s, DEFINE_SHEET_GUILDDONATE_E_GUILDDONATE_LIST_MAX_NUM> E_GuildDonate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildDonate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildDonate & msg);
		static ::proto_ff::Sheet_GuildDonate* new_pbmsg(){ return new ::proto_ff::Sheet_GuildDonate(); }
		static ::proto_ff::Sheet_GuildDonate make_pbmsg(){ return ::proto_ff::Sheet_GuildDonate(); }
	};
	typedef struct Sheet_GuildDonate_s Sheet_GuildDonate_t;

	struct E_GuildPacket_s : public NFDescStoreSeqOP {
		E_GuildPacket_s();
		virtual ~E_GuildPacket_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_belongtype;
		int32_t m_type;
		int32_t m_typearg;
		int32_t m_itemid;
		int32_t m_itemnum;
		int32_t m_num;
		int32_t m_pre;
		int32_t m_daily;

		virtual void write_to_pbmsg(::proto_ff::E_GuildPacket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPacket & msg);
		static ::proto_ff::E_GuildPacket* new_pbmsg(){ return new ::proto_ff::E_GuildPacket(); }
		static ::proto_ff::E_GuildPacket make_pbmsg(){ return ::proto_ff::E_GuildPacket(); }
	};
	typedef struct E_GuildPacket_s E_GuildPacket_t;

	struct Sheet_GuildPacket_s : public NFDescStoreSeqOP {
		Sheet_GuildPacket_s();
		virtual ~Sheet_GuildPacket_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPacket_s, DEFINE_SHEET_GUILDPACKET_E_GUILDPACKET_LIST_MAX_NUM> E_GuildPacket_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPacket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPacket & msg);
		static ::proto_ff::Sheet_GuildPacket* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPacket(); }
		static ::proto_ff::Sheet_GuildPacket make_pbmsg(){ return ::proto_ff::Sheet_GuildPacket(); }
	};
	typedef struct Sheet_GuildPacket_s Sheet_GuildPacket_t;

	struct E_GuildPrestigetask_s : public NFDescStoreSeqOP {
		E_GuildPrestigetask_s();
		virtual ~E_GuildPrestigetask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_level;
		int32_t m_weight;
		int32_t m_taskpool;
		int32_t m_reward;

		virtual void write_to_pbmsg(::proto_ff::E_GuildPrestigetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPrestigetask & msg);
		static ::proto_ff::E_GuildPrestigetask* new_pbmsg(){ return new ::proto_ff::E_GuildPrestigetask(); }
		static ::proto_ff::E_GuildPrestigetask make_pbmsg(){ return ::proto_ff::E_GuildPrestigetask(); }
	};
	typedef struct E_GuildPrestigetask_s E_GuildPrestigetask_t;

	struct Sheet_GuildPrestigetask_s : public NFDescStoreSeqOP {
		Sheet_GuildPrestigetask_s();
		virtual ~Sheet_GuildPrestigetask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPrestigetask_s, DEFINE_SHEET_GUILDPRESTIGETASK_E_GUILDPRESTIGETASK_LIST_MAX_NUM> E_GuildPrestigetask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPrestigetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPrestigetask & msg);
		static ::proto_ff::Sheet_GuildPrestigetask* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPrestigetask(); }
		static ::proto_ff::Sheet_GuildPrestigetask make_pbmsg(){ return ::proto_ff::Sheet_GuildPrestigetask(); }
	};
	typedef struct Sheet_GuildPrestigetask_s Sheet_GuildPrestigetask_t;

}

