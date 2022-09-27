#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "getTreasure.pb.h"
#include "getTreasure_s.h"

namespace proto_ff_s {

	struct getTreasurerareItem_s : public NFDescStoreSeqOP {
		getTreasurerareItem_s();
		int CreateInit();
		int ResumeInit();
		int64_t itemID;
		int32_t top;

		virtual void write_to_pbmsg(::proto_ff::getTreasurerareItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasurerareItem & msg);
		static ::proto_ff::getTreasurerareItem* new_pbmsg(){ return new ::proto_ff::getTreasurerareItem(); }
		static ::proto_ff::getTreasurerareItem make_pbmsg(){ return ::proto_ff::getTreasurerareItem(); }
	};
	typedef struct getTreasurerareItem_s getTreasurerareItem_t;

	struct Sheet_getTreasurerareItem_s : public NFDescStoreSeqOP {
		Sheet_getTreasurerareItem_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasurerareItem_s, 400> getTreasurerareItem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasurerareItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasurerareItem & msg);
		static ::proto_ff::Sheet_getTreasurerareItem* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasurerareItem(); }
		static ::proto_ff::Sheet_getTreasurerareItem make_pbmsg(){ return ::proto_ff::Sheet_getTreasurerareItem(); }
	};
	typedef struct Sheet_getTreasurerareItem_s Sheet_getTreasurerareItem_t;

	struct getTreasuretimesControlgroupDesc_s : public NFDescStoreSeqOP {
		getTreasuretimesControlgroupDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::getTreasuretimesControlgroupDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasuretimesControlgroupDesc & msg);
		static ::proto_ff::getTreasuretimesControlgroupDesc* new_pbmsg(){ return new ::proto_ff::getTreasuretimesControlgroupDesc(); }
		static ::proto_ff::getTreasuretimesControlgroupDesc make_pbmsg(){ return ::proto_ff::getTreasuretimesControlgroupDesc(); }
	};
	typedef struct getTreasuretimesControlgroupDesc_s getTreasuretimesControlgroupDesc_t;

	struct getTreasuretimesControl_s : public NFDescStoreSeqOP {
		getTreasuretimesControl_s();
		int CreateInit();
		int ResumeInit();
		int32_t bossType;
		int32_t mapType;
		int32_t functionId;
		int64_t duplicateGroupID;
		int32_t viptype;
		int64_t bossFlashItem;
		int32_t bossFlashItemNum;
		int64_t callingCardId;
		int32_t callingCardNum;
		int32_t times;
		int64_t costitem1;
		int32_t costnum1;
		int32_t canBuyFlag;
		int32_t canhelp;
		int32_t skill;
		NFArray<struct getTreasuretimesControlgroupDesc_s, 3> group;

		virtual void write_to_pbmsg(::proto_ff::getTreasuretimesControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasuretimesControl & msg);
		static ::proto_ff::getTreasuretimesControl* new_pbmsg(){ return new ::proto_ff::getTreasuretimesControl(); }
		static ::proto_ff::getTreasuretimesControl make_pbmsg(){ return ::proto_ff::getTreasuretimesControl(); }
	};
	typedef struct getTreasuretimesControl_s getTreasuretimesControl_t;

	struct Sheet_getTreasuretimesControl_s : public NFDescStoreSeqOP {
		Sheet_getTreasuretimesControl_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasuretimesControl_s, 20> getTreasuretimesControl_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasuretimesControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasuretimesControl & msg);
		static ::proto_ff::Sheet_getTreasuretimesControl* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasuretimesControl(); }
		static ::proto_ff::Sheet_getTreasuretimesControl make_pbmsg(){ return ::proto_ff::Sheet_getTreasuretimesControl(); }
	};
	typedef struct Sheet_getTreasuretimesControl_s Sheet_getTreasuretimesControl_t;

	struct getTreasureArrivalBossReward_s : public NFDescStoreSeqOP {
		getTreasureArrivalBossReward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t typeParam;
		int64_t boxID;

		virtual void write_to_pbmsg(::proto_ff::getTreasureArrivalBossReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasureArrivalBossReward & msg);
		static ::proto_ff::getTreasureArrivalBossReward* new_pbmsg(){ return new ::proto_ff::getTreasureArrivalBossReward(); }
		static ::proto_ff::getTreasureArrivalBossReward make_pbmsg(){ return ::proto_ff::getTreasureArrivalBossReward(); }
	};
	typedef struct getTreasureArrivalBossReward_s getTreasureArrivalBossReward_t;

	struct Sheet_getTreasureArrivalBossReward_s : public NFDescStoreSeqOP {
		Sheet_getTreasureArrivalBossReward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasureArrivalBossReward_s, 20> getTreasureArrivalBossReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasureArrivalBossReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasureArrivalBossReward & msg);
		static ::proto_ff::Sheet_getTreasureArrivalBossReward* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasureArrivalBossReward(); }
		static ::proto_ff::Sheet_getTreasureArrivalBossReward make_pbmsg(){ return ::proto_ff::Sheet_getTreasureArrivalBossReward(); }
	};
	typedef struct Sheet_getTreasureArrivalBossReward_s Sheet_getTreasureArrivalBossReward_t;

	struct getTreasureArrivalBossControl_s : public NFDescStoreSeqOP {
		getTreasureArrivalBossControl_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Arrival;
		int64_t costid;
		int64_t rewardID;
		int32_t rewardNum;
		int32_t timesMax;
		int32_t recovery;
		int64_t duplicateGroup;
		int64_t bossid;
		int64_t pathID;
		NFSizeString<60> radio;

		virtual void write_to_pbmsg(::proto_ff::getTreasureArrivalBossControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasureArrivalBossControl & msg);
		static ::proto_ff::getTreasureArrivalBossControl* new_pbmsg(){ return new ::proto_ff::getTreasureArrivalBossControl(); }
		static ::proto_ff::getTreasureArrivalBossControl make_pbmsg(){ return ::proto_ff::getTreasureArrivalBossControl(); }
	};
	typedef struct getTreasureArrivalBossControl_s getTreasureArrivalBossControl_t;

	struct Sheet_getTreasureArrivalBossControl_s : public NFDescStoreSeqOP {
		Sheet_getTreasureArrivalBossControl_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasureArrivalBossControl_s, 20> getTreasureArrivalBossControl_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasureArrivalBossControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasureArrivalBossControl & msg);
		static ::proto_ff::Sheet_getTreasureArrivalBossControl* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasureArrivalBossControl(); }
		static ::proto_ff::Sheet_getTreasureArrivalBossControl make_pbmsg(){ return ::proto_ff::Sheet_getTreasureArrivalBossControl(); }
	};
	typedef struct Sheet_getTreasureArrivalBossControl_s Sheet_getTreasureArrivalBossControl_t;

	struct getTreasurevipBossControl_s : public NFDescStoreSeqOP {
		getTreasurevipBossControl_s();
		int CreateInit();
		int ResumeInit();
		int32_t floor;
		int32_t minVipLvNeed;
		int32_t VipLvNeed;
		int32_t costnum;
		int64_t costid;

		virtual void write_to_pbmsg(::proto_ff::getTreasurevipBossControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasurevipBossControl & msg);
		static ::proto_ff::getTreasurevipBossControl* new_pbmsg(){ return new ::proto_ff::getTreasurevipBossControl(); }
		static ::proto_ff::getTreasurevipBossControl make_pbmsg(){ return ::proto_ff::getTreasurevipBossControl(); }
	};
	typedef struct getTreasurevipBossControl_s getTreasurevipBossControl_t;

	struct Sheet_getTreasurevipBossControl_s : public NFDescStoreSeqOP {
		Sheet_getTreasurevipBossControl_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasurevipBossControl_s, 20> getTreasurevipBossControl_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasurevipBossControl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasurevipBossControl & msg);
		static ::proto_ff::Sheet_getTreasurevipBossControl* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasurevipBossControl(); }
		static ::proto_ff::Sheet_getTreasurevipBossControl make_pbmsg(){ return ::proto_ff::Sheet_getTreasurevipBossControl(); }
	};
	typedef struct Sheet_getTreasurevipBossControl_s Sheet_getTreasurevipBossControl_t;

	struct getTreasureboss_s : public NFDescStoreSeqOP {
		getTreasureboss_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t bossType;
		int64_t monsterID;
		int32_t classOrder;
		int32_t sceneOrder;
		int64_t duplicateID;
		int64_t pathID;
		int32_t group_type;
		int32_t flashTime;

		virtual void write_to_pbmsg(::proto_ff::getTreasureboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasureboss & msg);
		static ::proto_ff::getTreasureboss* new_pbmsg(){ return new ::proto_ff::getTreasureboss(); }
		static ::proto_ff::getTreasureboss make_pbmsg(){ return ::proto_ff::getTreasureboss(); }
	};
	typedef struct getTreasureboss_s getTreasureboss_t;

	struct Sheet_getTreasureboss_s : public NFDescStoreSeqOP {
		Sheet_getTreasureboss_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasureboss_s, 800> getTreasureboss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasureboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasureboss & msg);
		static ::proto_ff::Sheet_getTreasureboss* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasureboss(); }
		static ::proto_ff::Sheet_getTreasureboss make_pbmsg(){ return ::proto_ff::Sheet_getTreasureboss(); }
	};
	typedef struct Sheet_getTreasureboss_s Sheet_getTreasureboss_t;

	struct getTreasurehelp_s : public NFDescStoreSeqOP {
		getTreasurehelp_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t down;
		int32_t up;
		NFArray<int64_t, 6> num;

		virtual void write_to_pbmsg(::proto_ff::getTreasurehelp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::getTreasurehelp & msg);
		static ::proto_ff::getTreasurehelp* new_pbmsg(){ return new ::proto_ff::getTreasurehelp(); }
		static ::proto_ff::getTreasurehelp make_pbmsg(){ return ::proto_ff::getTreasurehelp(); }
	};
	typedef struct getTreasurehelp_s getTreasurehelp_t;

	struct Sheet_getTreasurehelp_s : public NFDescStoreSeqOP {
		Sheet_getTreasurehelp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct getTreasurehelp_s, 20> getTreasurehelp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_getTreasurehelp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_getTreasurehelp & msg);
		static ::proto_ff::Sheet_getTreasurehelp* new_pbmsg(){ return new ::proto_ff::Sheet_getTreasurehelp(); }
		static ::proto_ff::Sheet_getTreasurehelp make_pbmsg(){ return ::proto_ff::Sheet_getTreasurehelp(); }
	};
	typedef struct Sheet_getTreasurehelp_s Sheet_getTreasurehelp_t;

}

