#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "festival.pb.h"
#include "festival_s.h"

namespace proto_ff_s {

	struct festivalmuban_JFduihuan_s : public NFDescStoreSeqOP {
		festivalmuban_JFduihuan_s();
		int CreateInit();
		int ResumeInit();
		int32_t tiaoJianId;
		int64_t prizeId;
		int32_t prof;
		int32_t prizeNum;
		int64_t propId;
		int32_t propNum;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_JFduihuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_JFduihuan & msg);
		static ::proto_ff::festivalmuban_JFduihuan* new_pbmsg(){ return new ::proto_ff::festivalmuban_JFduihuan(); }
		static ::proto_ff::festivalmuban_JFduihuan make_pbmsg(){ return ::proto_ff::festivalmuban_JFduihuan(); }
	};
	typedef struct festivalmuban_JFduihuan_s festivalmuban_JFduihuan_t;

	struct Sheet_festivalmuban_JFduihuan_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_JFduihuan_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_JFduihuan_s, 120> festivalmuban_JFduihuan_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_JFduihuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_JFduihuan & msg);
		static ::proto_ff::Sheet_festivalmuban_JFduihuan* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_JFduihuan(); }
		static ::proto_ff::Sheet_festivalmuban_JFduihuan make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_JFduihuan(); }
	};
	typedef struct Sheet_festivalmuban_JFduihuan_s Sheet_festivalmuban_JFduihuan_t;

	struct festivalmuban_dingzhi_s : public NFDescStoreSeqOP {
		festivalmuban_dingzhi_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<32> des;
		int64_t mustBoxId;
		int32_t currencyType;
		int32_t price;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_dingzhi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_dingzhi & msg);
		static ::proto_ff::festivalmuban_dingzhi* new_pbmsg(){ return new ::proto_ff::festivalmuban_dingzhi(); }
		static ::proto_ff::festivalmuban_dingzhi make_pbmsg(){ return ::proto_ff::festivalmuban_dingzhi(); }
	};
	typedef struct festivalmuban_dingzhi_s festivalmuban_dingzhi_t;

	struct Sheet_festivalmuban_dingzhi_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_dingzhi_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_dingzhi_s, 110> festivalmuban_dingzhi_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_dingzhi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_dingzhi & msg);
		static ::proto_ff::Sheet_festivalmuban_dingzhi* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_dingzhi(); }
		static ::proto_ff::Sheet_festivalmuban_dingzhi make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_dingzhi(); }
	};
	typedef struct Sheet_festivalmuban_dingzhi_s Sheet_festivalmuban_dingzhi_t;

	struct festivalmuban_CZfanzuan_s : public NFDescStoreSeqOP {
		festivalmuban_CZfanzuan_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t rechargeId;
		int32_t repayType;
		int32_t repayNum;
		int32_t timesLimit;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_CZfanzuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_CZfanzuan & msg);
		static ::proto_ff::festivalmuban_CZfanzuan* new_pbmsg(){ return new ::proto_ff::festivalmuban_CZfanzuan(); }
		static ::proto_ff::festivalmuban_CZfanzuan make_pbmsg(){ return ::proto_ff::festivalmuban_CZfanzuan(); }
	};
	typedef struct festivalmuban_CZfanzuan_s festivalmuban_CZfanzuan_t;

	struct Sheet_festivalmuban_CZfanzuan_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_CZfanzuan_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_CZfanzuan_s, 111> festivalmuban_CZfanzuan_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_CZfanzuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_CZfanzuan & msg);
		static ::proto_ff::Sheet_festivalmuban_CZfanzuan* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_CZfanzuan(); }
		static ::proto_ff::Sheet_festivalmuban_CZfanzuan make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_CZfanzuan(); }
	};
	typedef struct Sheet_festivalmuban_CZfanzuan_s Sheet_festivalmuban_CZfanzuan_t;

	struct festivalmuban_lianxuCZ_s : public NFDescStoreSeqOP {
		festivalmuban_lianxuCZ_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Num;
		int32_t remarkId;
		NFSizeString<32> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_lianxuCZ & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_lianxuCZ & msg);
		static ::proto_ff::festivalmuban_lianxuCZ* new_pbmsg(){ return new ::proto_ff::festivalmuban_lianxuCZ(); }
		static ::proto_ff::festivalmuban_lianxuCZ make_pbmsg(){ return ::proto_ff::festivalmuban_lianxuCZ(); }
	};
	typedef struct festivalmuban_lianxuCZ_s festivalmuban_lianxuCZ_t;

	struct Sheet_festivalmuban_lianxuCZ_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_lianxuCZ_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_lianxuCZ_s, 111> festivalmuban_lianxuCZ_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_lianxuCZ & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_lianxuCZ & msg);
		static ::proto_ff::Sheet_festivalmuban_lianxuCZ* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_lianxuCZ(); }
		static ::proto_ff::Sheet_festivalmuban_lianxuCZ make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_lianxuCZ(); }
	};
	typedef struct Sheet_festivalmuban_lianxuCZ_s Sheet_festivalmuban_lianxuCZ_t;

	struct festivalmuban_prerecharge_s : public NFDescStoreSeqOP {
		festivalmuban_prerecharge_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t order;
		NFSizeString<32> des;
		int64_t boxid;
		int32_t rechargeId;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_prerecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_prerecharge & msg);
		static ::proto_ff::festivalmuban_prerecharge* new_pbmsg(){ return new ::proto_ff::festivalmuban_prerecharge(); }
		static ::proto_ff::festivalmuban_prerecharge make_pbmsg(){ return ::proto_ff::festivalmuban_prerecharge(); }
	};
	typedef struct festivalmuban_prerecharge_s festivalmuban_prerecharge_t;

	struct Sheet_festivalmuban_prerecharge_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_prerecharge_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_prerecharge_s, 124> festivalmuban_prerecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_prerecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_prerecharge & msg);
		static ::proto_ff::Sheet_festivalmuban_prerecharge* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_prerecharge(); }
		static ::proto_ff::Sheet_festivalmuban_prerecharge make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_prerecharge(); }
	};
	typedef struct Sheet_festivalmuban_prerecharge_s Sheet_festivalmuban_prerecharge_t;

	struct festivalmuban_doubleGift_s : public NFDescStoreSeqOP {
		festivalmuban_doubleGift_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t gear;
		int64_t boxId;
		int64_t freeBox;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_doubleGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_doubleGift & msg);
		static ::proto_ff::festivalmuban_doubleGift* new_pbmsg(){ return new ::proto_ff::festivalmuban_doubleGift(); }
		static ::proto_ff::festivalmuban_doubleGift make_pbmsg(){ return ::proto_ff::festivalmuban_doubleGift(); }
	};
	typedef struct festivalmuban_doubleGift_s festivalmuban_doubleGift_t;

	struct Sheet_festivalmuban_doubleGift_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_doubleGift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_doubleGift_s, 107> festivalmuban_doubleGift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_doubleGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_doubleGift & msg);
		static ::proto_ff::Sheet_festivalmuban_doubleGift* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_doubleGift(); }
		static ::proto_ff::Sheet_festivalmuban_doubleGift make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_doubleGift(); }
	};
	typedef struct Sheet_festivalmuban_doubleGift_s Sheet_festivalmuban_doubleGift_t;

	struct festivalbigyanhuarecharge_s : public NFDescStoreSeqOP {
		festivalbigyanhuarecharge_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int32_t recharge;

		virtual void write_to_pbmsg(::proto_ff::festivalbigyanhuarecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalbigyanhuarecharge & msg);
		static ::proto_ff::festivalbigyanhuarecharge* new_pbmsg(){ return new ::proto_ff::festivalbigyanhuarecharge(); }
		static ::proto_ff::festivalbigyanhuarecharge make_pbmsg(){ return ::proto_ff::festivalbigyanhuarecharge(); }
	};
	typedef struct festivalbigyanhuarecharge_s festivalbigyanhuarecharge_t;

	struct Sheet_festivalbigyanhuarecharge_s : public NFDescStoreSeqOP {
		Sheet_festivalbigyanhuarecharge_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalbigyanhuarecharge_s, 120> festivalbigyanhuarecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalbigyanhuarecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalbigyanhuarecharge & msg);
		static ::proto_ff::Sheet_festivalbigyanhuarecharge* new_pbmsg(){ return new ::proto_ff::Sheet_festivalbigyanhuarecharge(); }
		static ::proto_ff::Sheet_festivalbigyanhuarecharge make_pbmsg(){ return ::proto_ff::Sheet_festivalbigyanhuarecharge(); }
	};
	typedef struct Sheet_festivalbigyanhuarecharge_s Sheet_festivalbigyanhuarecharge_t;

	struct festivalbigyanhuacost_s : public NFDescStoreSeqOP {
		festivalbigyanhuacost_s();
		int CreateInit();
		int ResumeInit();
		int32_t times;
		int32_t singleCost;
		int32_t allCost;

		virtual void write_to_pbmsg(::proto_ff::festivalbigyanhuacost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalbigyanhuacost & msg);
		static ::proto_ff::festivalbigyanhuacost* new_pbmsg(){ return new ::proto_ff::festivalbigyanhuacost(); }
		static ::proto_ff::festivalbigyanhuacost make_pbmsg(){ return ::proto_ff::festivalbigyanhuacost(); }
	};
	typedef struct festivalbigyanhuacost_s festivalbigyanhuacost_t;

	struct Sheet_festivalbigyanhuacost_s : public NFDescStoreSeqOP {
		Sheet_festivalbigyanhuacost_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalbigyanhuacost_s, 114> festivalbigyanhuacost_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalbigyanhuacost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalbigyanhuacost & msg);
		static ::proto_ff::Sheet_festivalbigyanhuacost* new_pbmsg(){ return new ::proto_ff::Sheet_festivalbigyanhuacost(); }
		static ::proto_ff::Sheet_festivalbigyanhuacost make_pbmsg(){ return ::proto_ff::Sheet_festivalbigyanhuacost(); }
	};
	typedef struct Sheet_festivalbigyanhuacost_s Sheet_festivalbigyanhuacost_t;

	struct festivalmuban_bigyanhua_s : public NFDescStoreSeqOP {
		festivalmuban_bigyanhua_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemid;
		int32_t num;
		int32_t prof;
		int32_t type;
		int32_t order;
		int32_t probability;
		int64_t relation;
		int64_t modelid;
		int32_t modeltype;
		NFSizeString<32> scale;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_bigyanhua & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_bigyanhua & msg);
		static ::proto_ff::festivalmuban_bigyanhua* new_pbmsg(){ return new ::proto_ff::festivalmuban_bigyanhua(); }
		static ::proto_ff::festivalmuban_bigyanhua make_pbmsg(){ return ::proto_ff::festivalmuban_bigyanhua(); }
	};
	typedef struct festivalmuban_bigyanhua_s festivalmuban_bigyanhua_t;

	struct Sheet_festivalmuban_bigyanhua_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_bigyanhua_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_bigyanhua_s, 114> festivalmuban_bigyanhua_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_bigyanhua & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_bigyanhua & msg);
		static ::proto_ff::Sheet_festivalmuban_bigyanhua* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_bigyanhua(); }
		static ::proto_ff::Sheet_festivalmuban_bigyanhua make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_bigyanhua(); }
	};
	typedef struct Sheet_festivalmuban_bigyanhua_s Sheet_festivalmuban_bigyanhua_t;

	struct festivalfestival_s : public NFDescStoreSeqOP {
		festivalfestival_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t huoDongType;
		int32_t nameId;
		NFSizeString<37> name;
		int32_t servertype;
		NFSizeString<32> timeA;
		NFSizeString<32> timeB;
		int32_t timeType;
		int32_t Level;
		int32_t vipLevel;
		int32_t rechange;
		int32_t ifOpen;
		NFSizeString<739> list;
		NFSizeString<32> icon;
		int32_t loginPopPriority;
		int32_t belong;

		virtual void write_to_pbmsg(::proto_ff::festivalfestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalfestival & msg);
		static ::proto_ff::festivalfestival* new_pbmsg(){ return new ::proto_ff::festivalfestival(); }
		static ::proto_ff::festivalfestival make_pbmsg(){ return ::proto_ff::festivalfestival(); }
	};
	typedef struct festivalfestival_s festivalfestival_t;

	struct Sheet_festivalfestival_s : public NFDescStoreSeqOP {
		Sheet_festivalfestival_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalfestival_s, 188> festivalfestival_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalfestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalfestival & msg);
		static ::proto_ff::Sheet_festivalfestival* new_pbmsg(){ return new ::proto_ff::Sheet_festivalfestival(); }
		static ::proto_ff::Sheet_festivalfestival make_pbmsg(){ return ::proto_ff::Sheet_festivalfestival(); }
	};
	typedef struct Sheet_festivalfestival_s Sheet_festivalfestival_t;

	struct festivaltemplate_s : public NFDescStoreSeqOP {
		festivaltemplate_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t muBan;
		int32_t order;
		NFSizeString<593> list;
		int32_t nameId;
		NFSizeString<32> Name;
		NFSizeString<32> type;
		NFSizeString<32> timeA;
		NFSizeString<32> timeB;
		int32_t timeType;
		int32_t level;
		int32_t vipLevel;
		int32_t rechange;
		int32_t remarkId;
		NFSizeString<120> MiaoShu;
		int64_t jiangLi;
		NFSizeString<32> beiJing;
		NFSizeString<32> title;
		NFSizeString<41> desc;

		virtual void write_to_pbmsg(::proto_ff::festivaltemplate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivaltemplate & msg);
		static ::proto_ff::festivaltemplate* new_pbmsg(){ return new ::proto_ff::festivaltemplate(); }
		static ::proto_ff::festivaltemplate make_pbmsg(){ return ::proto_ff::festivaltemplate(); }
	};
	typedef struct festivaltemplate_s festivaltemplate_t;

	struct Sheet_festivaltemplate_s : public NFDescStoreSeqOP {
		Sheet_festivaltemplate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivaltemplate_s, 2043> festivaltemplate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivaltemplate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivaltemplate & msg);
		static ::proto_ff::Sheet_festivaltemplate* new_pbmsg(){ return new ::proto_ff::Sheet_festivaltemplate(); }
		static ::proto_ff::Sheet_festivaltemplate make_pbmsg(){ return ::proto_ff::Sheet_festivaltemplate(); }
	};
	typedef struct Sheet_festivaltemplate_s Sheet_festivaltemplate_t;

	struct festivalmuban_worldboss_s : public NFDescStoreSeqOP {
		festivalmuban_worldboss_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t bossid;
		int32_t sort;
		int32_t conditionType;
		int32_t condition;
		NFSizeString<53> des;
		int64_t boxId;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_worldboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_worldboss & msg);
		static ::proto_ff::festivalmuban_worldboss* new_pbmsg(){ return new ::proto_ff::festivalmuban_worldboss(); }
		static ::proto_ff::festivalmuban_worldboss make_pbmsg(){ return ::proto_ff::festivalmuban_worldboss(); }
	};
	typedef struct festivalmuban_worldboss_s festivalmuban_worldboss_t;

	struct Sheet_festivalmuban_worldboss_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_worldboss_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_worldboss_s, 119> festivalmuban_worldboss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_worldboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_worldboss & msg);
		static ::proto_ff::Sheet_festivalmuban_worldboss* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_worldboss(); }
		static ::proto_ff::Sheet_festivalmuban_worldboss make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_worldboss(); }
	};
	typedef struct Sheet_festivalmuban_worldboss_s Sheet_festivalmuban_worldboss_t;

	struct festivalmuban_libao_s : public NFDescStoreSeqOP {
		festivalmuban_libao_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t boxid;
		int32_t term;
		int32_t level;
		int32_t currencyType;
		int32_t price;
		int32_t backType;
		int32_t dayBack;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_libao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_libao & msg);
		static ::proto_ff::festivalmuban_libao* new_pbmsg(){ return new ::proto_ff::festivalmuban_libao(); }
		static ::proto_ff::festivalmuban_libao make_pbmsg(){ return ::proto_ff::festivalmuban_libao(); }
	};
	typedef struct festivalmuban_libao_s festivalmuban_libao_t;

	struct Sheet_festivalmuban_libao_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_libao_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_libao_s, 267> festivalmuban_libao_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_libao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_libao & msg);
		static ::proto_ff::Sheet_festivalmuban_libao* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_libao(); }
		static ::proto_ff::Sheet_festivalmuban_libao make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_libao(); }
	};
	typedef struct Sheet_festivalmuban_libao_s Sheet_festivalmuban_libao_t;

	struct festivalmuban_double_s : public NFDescStoreSeqOP {
		festivalmuban_double_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t gear;
		int64_t boxId;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_double & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_double & msg);
		static ::proto_ff::festivalmuban_double* new_pbmsg(){ return new ::proto_ff::festivalmuban_double(); }
		static ::proto_ff::festivalmuban_double make_pbmsg(){ return ::proto_ff::festivalmuban_double(); }
	};
	typedef struct festivalmuban_double_s festivalmuban_double_t;

	struct Sheet_festivalmuban_double_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_double_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_double_s, 111> festivalmuban_double_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_double & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_double & msg);
		static ::proto_ff::Sheet_festivalmuban_double* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_double(); }
		static ::proto_ff::Sheet_festivalmuban_double make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_double(); }
	};
	typedef struct Sheet_festivalmuban_double_s Sheet_festivalmuban_double_t;

	struct festivalmiaoshu_s : public NFDescStoreSeqOP {
		festivalmiaoshu_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<54> wenzi;

		virtual void write_to_pbmsg(::proto_ff::festivalmiaoshu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmiaoshu & msg);
		static ::proto_ff::festivalmiaoshu* new_pbmsg(){ return new ::proto_ff::festivalmiaoshu(); }
		static ::proto_ff::festivalmiaoshu make_pbmsg(){ return ::proto_ff::festivalmiaoshu(); }
	};
	typedef struct festivalmiaoshu_s festivalmiaoshu_t;

	struct Sheet_festivalmiaoshu_s : public NFDescStoreSeqOP {
		Sheet_festivalmiaoshu_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmiaoshu_s, 108> festivalmiaoshu_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmiaoshu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmiaoshu & msg);
		static ::proto_ff::Sheet_festivalmiaoshu* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmiaoshu(); }
		static ::proto_ff::Sheet_festivalmiaoshu make_pbmsg(){ return ::proto_ff::Sheet_festivalmiaoshu(); }
	};
	typedef struct Sheet_festivalmiaoshu_s Sheet_festivalmiaoshu_t;

	struct festivalmuban_denglu_s : public NFDescStoreSeqOP {
		festivalmuban_denglu_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Num;
		int32_t remarkId;
		NFSizeString<32> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_denglu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_denglu & msg);
		static ::proto_ff::festivalmuban_denglu* new_pbmsg(){ return new ::proto_ff::festivalmuban_denglu(); }
		static ::proto_ff::festivalmuban_denglu make_pbmsg(){ return ::proto_ff::festivalmuban_denglu(); }
	};
	typedef struct festivalmuban_denglu_s festivalmuban_denglu_t;

	struct Sheet_festivalmuban_denglu_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_denglu_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_denglu_s, 233> festivalmuban_denglu_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_denglu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_denglu & msg);
		static ::proto_ff::Sheet_festivalmuban_denglu* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_denglu(); }
		static ::proto_ff::Sheet_festivalmuban_denglu make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_denglu(); }
	};
	typedef struct Sheet_festivalmuban_denglu_s Sheet_festivalmuban_denglu_t;

	struct festivalmuban_touzi_s : public NFDescStoreSeqOP {
		festivalmuban_touzi_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t Num;
		int64_t addNum;
		int32_t remarkId;
		NFSizeString<33> miaoshu;
		int64_t jiangLi;
		int64_t linkId;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_touzi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_touzi & msg);
		static ::proto_ff::festivalmuban_touzi* new_pbmsg(){ return new ::proto_ff::festivalmuban_touzi(); }
		static ::proto_ff::festivalmuban_touzi make_pbmsg(){ return ::proto_ff::festivalmuban_touzi(); }
	};
	typedef struct festivalmuban_touzi_s festivalmuban_touzi_t;

	struct Sheet_festivalmuban_touzi_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_touzi_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_touzi_s, 405> festivalmuban_touzi_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_touzi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_touzi & msg);
		static ::proto_ff::Sheet_festivalmuban_touzi* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_touzi(); }
		static ::proto_ff::Sheet_festivalmuban_touzi make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_touzi(); }
	};
	typedef struct Sheet_festivalmuban_touzi_s Sheet_festivalmuban_touzi_t;

	struct festivalmuban_zhichong_s : public NFDescStoreSeqOP {
		festivalmuban_zhichong_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Num;
		NFSizeString<32> severNum;
		int32_t remarkId;
		NFSizeString<32> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_zhichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_zhichong & msg);
		static ::proto_ff::festivalmuban_zhichong* new_pbmsg(){ return new ::proto_ff::festivalmuban_zhichong(); }
		static ::proto_ff::festivalmuban_zhichong make_pbmsg(){ return ::proto_ff::festivalmuban_zhichong(); }
	};
	typedef struct festivalmuban_zhichong_s festivalmuban_zhichong_t;

	struct Sheet_festivalmuban_zhichong_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_zhichong_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_zhichong_s, 204> festivalmuban_zhichong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_zhichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_zhichong & msg);
		static ::proto_ff::Sheet_festivalmuban_zhichong* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_zhichong(); }
		static ::proto_ff::Sheet_festivalmuban_zhichong make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_zhichong(); }
	};
	typedef struct Sheet_festivalmuban_zhichong_s Sheet_festivalmuban_zhichong_t;

	struct festivalmuban_leichong_s : public NFDescStoreSeqOP {
		festivalmuban_leichong_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t Num;
		int32_t remarkId;
		NFSizeString<32> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_leichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_leichong & msg);
		static ::proto_ff::festivalmuban_leichong* new_pbmsg(){ return new ::proto_ff::festivalmuban_leichong(); }
		static ::proto_ff::festivalmuban_leichong make_pbmsg(){ return ::proto_ff::festivalmuban_leichong(); }
	};
	typedef struct festivalmuban_leichong_s festivalmuban_leichong_t;

	struct Sheet_festivalmuban_leichong_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_leichong_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_leichong_s, 822> festivalmuban_leichong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_leichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_leichong & msg);
		static ::proto_ff::Sheet_festivalmuban_leichong* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_leichong(); }
		static ::proto_ff::Sheet_festivalmuban_leichong make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_leichong(); }
	};
	typedef struct Sheet_festivalmuban_leichong_s Sheet_festivalmuban_leichong_t;

	struct festivalmuban_duihuan_s : public NFDescStoreSeqOP {
		festivalmuban_duihuan_s();
		int CreateInit();
		int ResumeInit();
		int32_t tiaoJianId;
		int64_t prizeId;
		int32_t prof;
		int32_t prizeNum;
		int64_t propId;
		int32_t propNum;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_duihuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_duihuan & msg);
		static ::proto_ff::festivalmuban_duihuan* new_pbmsg(){ return new ::proto_ff::festivalmuban_duihuan(); }
		static ::proto_ff::festivalmuban_duihuan make_pbmsg(){ return ::proto_ff::festivalmuban_duihuan(); }
	};
	typedef struct festivalmuban_duihuan_s festivalmuban_duihuan_t;

	struct Sheet_festivalmuban_duihuan_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_duihuan_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_duihuan_s, 571> festivalmuban_duihuan_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_duihuan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_duihuan & msg);
		static ::proto_ff::Sheet_festivalmuban_duihuan* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_duihuan(); }
		static ::proto_ff::Sheet_festivalmuban_duihuan make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_duihuan(); }
	};
	typedef struct Sheet_festivalmuban_duihuan_s Sheet_festivalmuban_duihuan_t;

	struct festivald_diaoluo_s : public NFDescStoreSeqOP {
		festivald_diaoluo_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t mixLevel;
		int32_t bossType;
		NFSizeString<32> dropNum;
		NFSizeString<32> dropRand;

		virtual void write_to_pbmsg(::proto_ff::festivald_diaoluo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivald_diaoluo & msg);
		static ::proto_ff::festivald_diaoluo* new_pbmsg(){ return new ::proto_ff::festivald_diaoluo(); }
		static ::proto_ff::festivald_diaoluo make_pbmsg(){ return ::proto_ff::festivald_diaoluo(); }
	};
	typedef struct festivald_diaoluo_s festivald_diaoluo_t;

	struct Sheet_festivald_diaoluo_s : public NFDescStoreSeqOP {
		Sheet_festivald_diaoluo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivald_diaoluo_s, 108> festivald_diaoluo_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivald_diaoluo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivald_diaoluo & msg);
		static ::proto_ff::Sheet_festivald_diaoluo* new_pbmsg(){ return new ::proto_ff::Sheet_festivald_diaoluo(); }
		static ::proto_ff::Sheet_festivald_diaoluo make_pbmsg(){ return ::proto_ff::Sheet_festivald_diaoluo(); }
	};
	typedef struct Sheet_festivald_diaoluo_s Sheet_festivald_diaoluo_t;

	struct festivalmuban_leixiao_s : public NFDescStoreSeqOP {
		festivalmuban_leixiao_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t xiaoFei;
		int32_t remarkId;
		NFSizeString<34> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_leixiao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_leixiao & msg);
		static ::proto_ff::festivalmuban_leixiao* new_pbmsg(){ return new ::proto_ff::festivalmuban_leixiao(); }
		static ::proto_ff::festivalmuban_leixiao make_pbmsg(){ return ::proto_ff::festivalmuban_leixiao(); }
	};
	typedef struct festivalmuban_leixiao_s festivalmuban_leixiao_t;

	struct Sheet_festivalmuban_leixiao_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_leixiao_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_leixiao_s, 145> festivalmuban_leixiao_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_leixiao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_leixiao & msg);
		static ::proto_ff::Sheet_festivalmuban_leixiao* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_leixiao(); }
		static ::proto_ff::Sheet_festivalmuban_leixiao make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_leixiao(); }
	};
	typedef struct Sheet_festivalmuban_leixiao_s Sheet_festivalmuban_leixiao_t;

	struct festivalmuban_shouchong_s : public NFDescStoreSeqOP {
		festivalmuban_shouchong_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_shouchong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_shouchong & msg);
		static ::proto_ff::festivalmuban_shouchong* new_pbmsg(){ return new ::proto_ff::festivalmuban_shouchong(); }
		static ::proto_ff::festivalmuban_shouchong make_pbmsg(){ return ::proto_ff::festivalmuban_shouchong(); }
	};
	typedef struct festivalmuban_shouchong_s festivalmuban_shouchong_t;

	struct Sheet_festivalmuban_shouchong_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_shouchong_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_shouchong_s, 105> festivalmuban_shouchong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shouchong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shouchong & msg);
		static ::proto_ff::Sheet_festivalmuban_shouchong* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_shouchong(); }
		static ::proto_ff::Sheet_festivalmuban_shouchong make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_shouchong(); }
	};
	typedef struct Sheet_festivalmuban_shouchong_s Sheet_festivalmuban_shouchong_t;

	struct festivalmuban_yanhua_s : public NFDescStoreSeqOP {
		festivalmuban_yanhua_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemid;
		int32_t num;
		int32_t prof;
		int32_t type;
		int32_t order;
		int32_t probability;
		int64_t relation;
		int64_t modelid;
		int32_t modeltype;
		NFSizeString<32> scale;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_yanhua & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_yanhua & msg);
		static ::proto_ff::festivalmuban_yanhua* new_pbmsg(){ return new ::proto_ff::festivalmuban_yanhua(); }
		static ::proto_ff::festivalmuban_yanhua make_pbmsg(){ return ::proto_ff::festivalmuban_yanhua(); }
	};
	typedef struct festivalmuban_yanhua_s festivalmuban_yanhua_t;

	struct Sheet_festivalmuban_yanhua_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_yanhua_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_yanhua_s, 2192> festivalmuban_yanhua_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_yanhua & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_yanhua & msg);
		static ::proto_ff::Sheet_festivalmuban_yanhua* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_yanhua(); }
		static ::proto_ff::Sheet_festivalmuban_yanhua make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_yanhua(); }
	};
	typedef struct Sheet_festivalmuban_yanhua_s Sheet_festivalmuban_yanhua_t;

	struct festivalyanhuaConstant_s : public NFDescStoreSeqOP {
		festivalyanhuaConstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t costItem;
		int32_t rewardPool;
		int32_t coinTye;
		int32_t number;

		virtual void write_to_pbmsg(::proto_ff::festivalyanhuaConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalyanhuaConstant & msg);
		static ::proto_ff::festivalyanhuaConstant* new_pbmsg(){ return new ::proto_ff::festivalyanhuaConstant(); }
		static ::proto_ff::festivalyanhuaConstant make_pbmsg(){ return ::proto_ff::festivalyanhuaConstant(); }
	};
	typedef struct festivalyanhuaConstant_s festivalyanhuaConstant_t;

	struct Sheet_festivalyanhuaConstant_s : public NFDescStoreSeqOP {
		Sheet_festivalyanhuaConstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalyanhuaConstant_s, 120> festivalyanhuaConstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalyanhuaConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalyanhuaConstant & msg);
		static ::proto_ff::Sheet_festivalyanhuaConstant* new_pbmsg(){ return new ::proto_ff::Sheet_festivalyanhuaConstant(); }
		static ::proto_ff::Sheet_festivalyanhuaConstant make_pbmsg(){ return ::proto_ff::Sheet_festivalyanhuaConstant(); }
	};
	typedef struct Sheet_festivalyanhuaConstant_s Sheet_festivalyanhuaConstant_t;

	struct festivalmuban_shop_s : public NFDescStoreSeqOP {
		festivalmuban_shop_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t itemid;
		int32_t prof;
		int32_t priceA;
		int32_t priceB;
		int32_t currency;
		int32_t discount;
		int32_t quantity;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_shop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_shop & msg);
		static ::proto_ff::festivalmuban_shop* new_pbmsg(){ return new ::proto_ff::festivalmuban_shop(); }
		static ::proto_ff::festivalmuban_shop make_pbmsg(){ return ::proto_ff::festivalmuban_shop(); }
	};
	typedef struct festivalmuban_shop_s festivalmuban_shop_t;

	struct Sheet_festivalmuban_shop_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_shop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_shop_s, 181> festivalmuban_shop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shop & msg);
		static ::proto_ff::Sheet_festivalmuban_shop* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_shop(); }
		static ::proto_ff::Sheet_festivalmuban_shop make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_shop(); }
	};
	typedef struct Sheet_festivalmuban_shop_s Sheet_festivalmuban_shop_t;

	struct festivalmuban_czjb_s : public NFDescStoreSeqOP {
		festivalmuban_czjb_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<32> RechargePoint;
		int32_t Perc;
		int32_t fristpresent;
		int32_t presenttype;
		int32_t Point;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_czjb & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_czjb & msg);
		static ::proto_ff::festivalmuban_czjb* new_pbmsg(){ return new ::proto_ff::festivalmuban_czjb(); }
		static ::proto_ff::festivalmuban_czjb make_pbmsg(){ return ::proto_ff::festivalmuban_czjb(); }
	};
	typedef struct festivalmuban_czjb_s festivalmuban_czjb_t;

	struct Sheet_festivalmuban_czjb_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_czjb_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_czjb_s, 111> festivalmuban_czjb_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_czjb & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_czjb & msg);
		static ::proto_ff::Sheet_festivalmuban_czjb* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_czjb(); }
		static ::proto_ff::Sheet_festivalmuban_czjb make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_czjb(); }
	};
	typedef struct Sheet_festivalmuban_czjb_s Sheet_festivalmuban_czjb_t;

	struct festivalmuban_scsb_s : public NFDescStoreSeqOP {
		festivalmuban_scsb_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<32> RechargePoint;
		int32_t fristpresent;
		int32_t presenttype;
		int32_t Point;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_scsb & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_scsb & msg);
		static ::proto_ff::festivalmuban_scsb* new_pbmsg(){ return new ::proto_ff::festivalmuban_scsb(); }
		static ::proto_ff::festivalmuban_scsb make_pbmsg(){ return ::proto_ff::festivalmuban_scsb(); }
	};
	typedef struct festivalmuban_scsb_s festivalmuban_scsb_t;

	struct Sheet_festivalmuban_scsb_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_scsb_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_scsb_s, 111> festivalmuban_scsb_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_scsb & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_scsb & msg);
		static ::proto_ff::Sheet_festivalmuban_scsb* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_scsb(); }
		static ::proto_ff::Sheet_festivalmuban_scsb make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_scsb(); }
	};
	typedef struct Sheet_festivalmuban_scsb_s Sheet_festivalmuban_scsb_t;

	struct festivalmuban_eggs_s : public NFDescStoreSeqOP {
		festivalmuban_eggs_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemid;
		int32_t num;
		int32_t prof;
		int32_t type;
		int32_t order;
		int32_t isnote;
		int32_t probability;
		int64_t relation;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_eggs & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_eggs & msg);
		static ::proto_ff::festivalmuban_eggs* new_pbmsg(){ return new ::proto_ff::festivalmuban_eggs(); }
		static ::proto_ff::festivalmuban_eggs make_pbmsg(){ return ::proto_ff::festivalmuban_eggs(); }
	};
	typedef struct festivalmuban_eggs_s festivalmuban_eggs_t;

	struct Sheet_festivalmuban_eggs_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_eggs_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_eggs_s, 206> festivalmuban_eggs_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_eggs & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_eggs & msg);
		static ::proto_ff::Sheet_festivalmuban_eggs* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_eggs(); }
		static ::proto_ff::Sheet_festivalmuban_eggs make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_eggs(); }
	};
	typedef struct Sheet_festivalmuban_eggs_s Sheet_festivalmuban_eggs_t;

	struct festivaleggConstant_s : public NFDescStoreSeqOP {
		festivaleggConstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<74> exReward;
		int64_t costItem;
		int32_t freeTime;
		NFSizeString<32> poolChange;
		int32_t specialRate;
		int32_t specialAddRate;
		NFSizeString<32> flashCost;
		int32_t limit;
		int32_t rewardPool;

		virtual void write_to_pbmsg(::proto_ff::festivaleggConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivaleggConstant & msg);
		static ::proto_ff::festivaleggConstant* new_pbmsg(){ return new ::proto_ff::festivaleggConstant(); }
		static ::proto_ff::festivaleggConstant make_pbmsg(){ return ::proto_ff::festivaleggConstant(); }
	};
	typedef struct festivaleggConstant_s festivaleggConstant_t;

	struct Sheet_festivaleggConstant_s : public NFDescStoreSeqOP {
		Sheet_festivaleggConstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivaleggConstant_s, 106> festivaleggConstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivaleggConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivaleggConstant & msg);
		static ::proto_ff::Sheet_festivaleggConstant* new_pbmsg(){ return new ::proto_ff::Sheet_festivaleggConstant(); }
		static ::proto_ff::Sheet_festivaleggConstant make_pbmsg(){ return ::proto_ff::Sheet_festivaleggConstant(); }
	};
	typedef struct Sheet_festivaleggConstant_s Sheet_festivaleggConstant_t;

	struct festivalconstant_s : public NFDescStoreSeqOP {
		festivalconstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t constantid;
		int64_t constantdata;
		NFSizeString<70> stringdata;

		virtual void write_to_pbmsg(::proto_ff::festivalconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalconstant & msg);
		static ::proto_ff::festivalconstant* new_pbmsg(){ return new ::proto_ff::festivalconstant(); }
		static ::proto_ff::festivalconstant make_pbmsg(){ return ::proto_ff::festivalconstant(); }
	};
	typedef struct festivalconstant_s festivalconstant_t;

	struct Sheet_festivalconstant_s : public NFDescStoreSeqOP {
		Sheet_festivalconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalconstant_s, 110> festivalconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalconstant & msg);
		static ::proto_ff::Sheet_festivalconstant* new_pbmsg(){ return new ::proto_ff::Sheet_festivalconstant(); }
		static ::proto_ff::Sheet_festivalconstant make_pbmsg(){ return ::proto_ff::Sheet_festivalconstant(); }
	};
	typedef struct Sheet_festivalconstant_s Sheet_festivalconstant_t;

	struct festivalmuban_shousha_s : public NFDescStoreSeqOP {
		festivalmuban_shousha_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t bossId;
		int64_t boxId;
		int64_t linkid;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_shousha & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_shousha & msg);
		static ::proto_ff::festivalmuban_shousha* new_pbmsg(){ return new ::proto_ff::festivalmuban_shousha(); }
		static ::proto_ff::festivalmuban_shousha make_pbmsg(){ return ::proto_ff::festivalmuban_shousha(); }
	};
	typedef struct festivalmuban_shousha_s festivalmuban_shousha_t;

	struct Sheet_festivalmuban_shousha_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_shousha_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_shousha_s, 116> festivalmuban_shousha_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shousha & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shousha & msg);
		static ::proto_ff::Sheet_festivalmuban_shousha* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_shousha(); }
		static ::proto_ff::Sheet_festivalmuban_shousha make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_shousha(); }
	};
	typedef struct Sheet_festivalmuban_shousha_s Sheet_festivalmuban_shousha_t;

	struct festivalmuban_huoyue_s : public NFDescStoreSeqOP {
		festivalmuban_huoyue_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t activity;
		NFSizeString<40> desc;
		int64_t boxId;

		virtual void write_to_pbmsg(::proto_ff::festivalmuban_huoyue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::festivalmuban_huoyue & msg);
		static ::proto_ff::festivalmuban_huoyue* new_pbmsg(){ return new ::proto_ff::festivalmuban_huoyue(); }
		static ::proto_ff::festivalmuban_huoyue make_pbmsg(){ return ::proto_ff::festivalmuban_huoyue(); }
	};
	typedef struct festivalmuban_huoyue_s festivalmuban_huoyue_t;

	struct Sheet_festivalmuban_huoyue_s : public NFDescStoreSeqOP {
		Sheet_festivalmuban_huoyue_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct festivalmuban_huoyue_s, 380> festivalmuban_huoyue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_festivalmuban_huoyue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_huoyue & msg);
		static ::proto_ff::Sheet_festivalmuban_huoyue* new_pbmsg(){ return new ::proto_ff::Sheet_festivalmuban_huoyue(); }
		static ::proto_ff::Sheet_festivalmuban_huoyue make_pbmsg(){ return ::proto_ff::Sheet_festivalmuban_huoyue(); }
	};
	typedef struct Sheet_festivalmuban_huoyue_s Sheet_festivalmuban_huoyue_t;

}

