#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "operate.pb.h"
#include "operate_s.h"

namespace proto_ff_s {

	struct operateoperate_s : public NFDescStoreSeqOP {
		operateoperate_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t huoDong;
		NFSizeString<32> name;
		int32_t nameId;
		NFSizeString<245> tiaoJian;
		int32_t servertype;
		NFSizeString<32> timeA;
		NFSizeString<32> timeB;
		int32_t timeType;
		NFSizeString<96> miaoSu;
		int32_t ifOpen;

		virtual void write_to_pbmsg(::proto_ff::operateoperate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateoperate & msg);
		static ::proto_ff::operateoperate* new_pbmsg(){ return new ::proto_ff::operateoperate(); }
		static ::proto_ff::operateoperate make_pbmsg(){ return ::proto_ff::operateoperate(); }
	};
	typedef struct operateoperate_s operateoperate_t;

	struct Sheet_operateoperate_s : public NFDescStoreSeqOP {
		Sheet_operateoperate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateoperate_s, 129> operateoperate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateoperate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateoperate & msg);
		static ::proto_ff::Sheet_operateoperate* new_pbmsg(){ return new ::proto_ff::Sheet_operateoperate(); }
		static ::proto_ff::Sheet_operateoperate make_pbmsg(){ return ::proto_ff::Sheet_operateoperate(); }
	};
	typedef struct Sheet_operateoperate_s Sheet_operateoperate_t;

	struct operatetutor_s : public NFDescStoreSeqOP {
		operatetutor_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t condition;
		int32_t conditionParam1;
		int32_t conditionParam2;
		int64_t boxId;
		int32_t teach;

		virtual void write_to_pbmsg(::proto_ff::operatetutor & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatetutor & msg);
		static ::proto_ff::operatetutor* new_pbmsg(){ return new ::proto_ff::operatetutor(); }
		static ::proto_ff::operatetutor make_pbmsg(){ return ::proto_ff::operatetutor(); }
	};
	typedef struct operatetutor_s operatetutor_t;

	struct Sheet_operatetutor_s : public NFDescStoreSeqOP {
		Sheet_operatetutor_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatetutor_s, 153> operatetutor_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatetutor & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatetutor & msg);
		static ::proto_ff::Sheet_operatetutor* new_pbmsg(){ return new ::proto_ff::Sheet_operatetutor(); }
		static ::proto_ff::Sheet_operatetutor make_pbmsg(){ return ::proto_ff::Sheet_operatetutor(); }
	};
	typedef struct Sheet_operatetutor_s Sheet_operatetutor_t;

	struct operatejiangli_s : public NFDescStoreSeqOP {
		operatejiangli_s();
		int CreateInit();
		int ResumeInit();
		int64_t tiaoJianId;
		NFSizeString<32> huoDong;
		NFSizeString<32> downNu;
		NFSizeString<32> upNu;
		NFSizeString<32> miaoshu;
		NFSizeString<34> miaoshuAdd;
		NFSizeString<64> tiaoJian;
		int64_t boxId;
		int64_t sdboxid;

		virtual void write_to_pbmsg(::proto_ff::operatejiangli & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatejiangli & msg);
		static ::proto_ff::operatejiangli* new_pbmsg(){ return new ::proto_ff::operatejiangli(); }
		static ::proto_ff::operatejiangli make_pbmsg(){ return ::proto_ff::operatejiangli(); }
	};
	typedef struct operatejiangli_s operatejiangli_t;

	struct Sheet_operatejiangli_s : public NFDescStoreSeqOP {
		Sheet_operatejiangli_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatejiangli_s, 282> operatejiangli_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatejiangli & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatejiangli & msg);
		static ::proto_ff::Sheet_operatejiangli* new_pbmsg(){ return new ::proto_ff::Sheet_operatejiangli(); }
		static ::proto_ff::Sheet_operatejiangli make_pbmsg(){ return ::proto_ff::Sheet_operatejiangli(); }
	};
	typedef struct Sheet_operatejiangli_s Sheet_operatejiangli_t;

	struct operatehoroscope_s : public NFDescStoreSeqOP {
		operatehoroscope_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t daojuId;
		int32_t daojuPrice;
		int32_t cycle;
		NFSizeString<32> poolid;
		int32_t wheelTime;
		NFSizeString<39> ExchangeGroupID;
		NFSizeString<141> boxid;
		int64_t luckid;
		NFSizeString<35> fateid;
		NFSizeString<47> felicityid;

		virtual void write_to_pbmsg(::proto_ff::operatehoroscope & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatehoroscope & msg);
		static ::proto_ff::operatehoroscope* new_pbmsg(){ return new ::proto_ff::operatehoroscope(); }
		static ::proto_ff::operatehoroscope make_pbmsg(){ return ::proto_ff::operatehoroscope(); }
	};
	typedef struct operatehoroscope_s operatehoroscope_t;

	struct Sheet_operatehoroscope_s : public NFDescStoreSeqOP {
		Sheet_operatehoroscope_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatehoroscope_s, 111> operatehoroscope_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatehoroscope & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscope & msg);
		static ::proto_ff::Sheet_operatehoroscope* new_pbmsg(){ return new ::proto_ff::Sheet_operatehoroscope(); }
		static ::proto_ff::Sheet_operatehoroscope make_pbmsg(){ return ::proto_ff::Sheet_operatehoroscope(); }
	};
	typedef struct Sheet_operatehoroscope_s Sheet_operatehoroscope_t;

	struct operatehoroscopePool_s : public NFDescStoreSeqOP {
		operatehoroscopePool_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemid;
		int32_t num;
		int32_t prof;
		int32_t levelLimitA;
		int32_t levelLimitB;
		int32_t type;
		int32_t typeParma;
		int32_t probability;
		int64_t groupID;
		int32_t order;

		virtual void write_to_pbmsg(::proto_ff::operatehoroscopePool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatehoroscopePool & msg);
		static ::proto_ff::operatehoroscopePool* new_pbmsg(){ return new ::proto_ff::operatehoroscopePool(); }
		static ::proto_ff::operatehoroscopePool make_pbmsg(){ return ::proto_ff::operatehoroscopePool(); }
	};
	typedef struct operatehoroscopePool_s operatehoroscopePool_t;

	struct Sheet_operatehoroscopePool_s : public NFDescStoreSeqOP {
		Sheet_operatehoroscopePool_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatehoroscopePool_s, 1037> operatehoroscopePool_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatehoroscopePool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscopePool & msg);
		static ::proto_ff::Sheet_operatehoroscopePool* new_pbmsg(){ return new ::proto_ff::Sheet_operatehoroscopePool(); }
		static ::proto_ff::Sheet_operatehoroscopePool make_pbmsg(){ return ::proto_ff::Sheet_operatehoroscopePool(); }
	};
	typedef struct Sheet_operatehoroscopePool_s Sheet_operatehoroscopePool_t;

	struct operatehoroscopeExchange_s : public NFDescStoreSeqOP {
		operatehoroscopeExchange_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t horoscopeId;
		int64_t prizeId;
		int32_t prof;
		int32_t prizeNum;
		int32_t luckNeed;
		int32_t times;

		virtual void write_to_pbmsg(::proto_ff::operatehoroscopeExchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatehoroscopeExchange & msg);
		static ::proto_ff::operatehoroscopeExchange* new_pbmsg(){ return new ::proto_ff::operatehoroscopeExchange(); }
		static ::proto_ff::operatehoroscopeExchange make_pbmsg(){ return ::proto_ff::operatehoroscopeExchange(); }
	};
	typedef struct operatehoroscopeExchange_s operatehoroscopeExchange_t;

	struct Sheet_operatehoroscopeExchange_s : public NFDescStoreSeqOP {
		Sheet_operatehoroscopeExchange_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatehoroscopeExchange_s, 222> operatehoroscopeExchange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatehoroscopeExchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscopeExchange & msg);
		static ::proto_ff::Sheet_operatehoroscopeExchange* new_pbmsg(){ return new ::proto_ff::Sheet_operatehoroscopeExchange(); }
		static ::proto_ff::Sheet_operatehoroscopeExchange make_pbmsg(){ return ::proto_ff::Sheet_operatehoroscopeExchange(); }
	};
	typedef struct Sheet_operatehoroscopeExchange_s Sheet_operatehoroscopeExchange_t;

	struct operateconst_s : public NFDescStoreSeqOP {
		operateconst_s();
		int CreateInit();
		int ResumeInit();
		int64_t constantid;
		int64_t constantdata;
		NFSizeString<99> stringdata;

		virtual void write_to_pbmsg(::proto_ff::operateconst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateconst & msg);
		static ::proto_ff::operateconst* new_pbmsg(){ return new ::proto_ff::operateconst(); }
		static ::proto_ff::operateconst make_pbmsg(){ return ::proto_ff::operateconst(); }
	};
	typedef struct operateconst_s operateconst_t;

	struct Sheet_operateconst_s : public NFDescStoreSeqOP {
		Sheet_operateconst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateconst_s, 161> operateconst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateconst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateconst & msg);
		static ::proto_ff::Sheet_operateconst* new_pbmsg(){ return new ::proto_ff::Sheet_operateconst(); }
		static ::proto_ff::Sheet_operateconst make_pbmsg(){ return ::proto_ff::Sheet_operateconst(); }
	};
	typedef struct Sheet_operateconst_s Sheet_operateconst_t;

	struct operateunlimited_s : public NFDescStoreSeqOP {
		operateunlimited_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t price;
		NFSizeString<32> severPrice;
		int64_t itemId;
		int64_t num;

		virtual void write_to_pbmsg(::proto_ff::operateunlimited & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateunlimited & msg);
		static ::proto_ff::operateunlimited* new_pbmsg(){ return new ::proto_ff::operateunlimited(); }
		static ::proto_ff::operateunlimited make_pbmsg(){ return ::proto_ff::operateunlimited(); }
	};
	typedef struct operateunlimited_s operateunlimited_t;

	struct Sheet_operateunlimited_s : public NFDescStoreSeqOP {
		Sheet_operateunlimited_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateunlimited_s, 107> operateunlimited_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateunlimited & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateunlimited & msg);
		static ::proto_ff::Sheet_operateunlimited* new_pbmsg(){ return new ::proto_ff::Sheet_operateunlimited(); }
		static ::proto_ff::Sheet_operateunlimited make_pbmsg(){ return ::proto_ff::Sheet_operateunlimited(); }
	};
	typedef struct Sheet_operateunlimited_s Sheet_operateunlimited_t;

	struct operaterand_s : public NFDescStoreSeqOP {
		operaterand_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t randtype;
		int64_t boxid;

		virtual void write_to_pbmsg(::proto_ff::operaterand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operaterand & msg);
		static ::proto_ff::operaterand* new_pbmsg(){ return new ::proto_ff::operaterand(); }
		static ::proto_ff::operaterand make_pbmsg(){ return ::proto_ff::operaterand(); }
	};
	typedef struct operaterand_s operaterand_t;

	struct Sheet_operaterand_s : public NFDescStoreSeqOP {
		Sheet_operaterand_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operaterand_s, 139> operaterand_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operaterand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operaterand & msg);
		static ::proto_ff::Sheet_operaterand* new_pbmsg(){ return new ::proto_ff::Sheet_operaterand(); }
		static ::proto_ff::Sheet_operaterand make_pbmsg(){ return ::proto_ff::Sheet_operaterand(); }
	};
	typedef struct Sheet_operaterand_s Sheet_operaterand_t;

	struct operatemooncard_s : public NFDescStoreSeqOP {
		operatemooncard_s();
		int CreateInit();
		int ResumeInit();
		int32_t dayNum;
		int32_t payBack;

		virtual void write_to_pbmsg(::proto_ff::operatemooncard & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatemooncard & msg);
		static ::proto_ff::operatemooncard* new_pbmsg(){ return new ::proto_ff::operatemooncard(); }
		static ::proto_ff::operatemooncard make_pbmsg(){ return ::proto_ff::operatemooncard(); }
	};
	typedef struct operatemooncard_s operatemooncard_t;

	struct Sheet_operatemooncard_s : public NFDescStoreSeqOP {
		Sheet_operatemooncard_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatemooncard_s, 135> operatemooncard_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatemooncard & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatemooncard & msg);
		static ::proto_ff::Sheet_operatemooncard* new_pbmsg(){ return new ::proto_ff::Sheet_operatemooncard(); }
		static ::proto_ff::Sheet_operatemooncard make_pbmsg(){ return ::proto_ff::Sheet_operatemooncard(); }
	};
	typedef struct Sheet_operatemooncard_s Sheet_operatemooncard_t;

	struct operatefund_s : public NFDescStoreSeqOP {
		operatefund_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t level;
		int32_t rebateS;
		int32_t rebateL;

		virtual void write_to_pbmsg(::proto_ff::operatefund & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatefund & msg);
		static ::proto_ff::operatefund* new_pbmsg(){ return new ::proto_ff::operatefund(); }
		static ::proto_ff::operatefund make_pbmsg(){ return ::proto_ff::operatefund(); }
	};
	typedef struct operatefund_s operatefund_t;

	struct Sheet_operatefund_s : public NFDescStoreSeqOP {
		Sheet_operatefund_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatefund_s, 143> operatefund_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatefund & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatefund & msg);
		static ::proto_ff::Sheet_operatefund* new_pbmsg(){ return new ::proto_ff::Sheet_operatefund(); }
		static ::proto_ff::Sheet_operatefund make_pbmsg(){ return ::proto_ff::Sheet_operatefund(); }
	};
	typedef struct Sheet_operatefund_s Sheet_operatefund_t;

	struct operatetask_s : public NFDescStoreSeqOP {
		operatetask_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t taskNan;
		int32_t taskType;
		NFSizeString<32> num;

		virtual void write_to_pbmsg(::proto_ff::operatetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatetask & msg);
		static ::proto_ff::operatetask* new_pbmsg(){ return new ::proto_ff::operatetask(); }
		static ::proto_ff::operatetask make_pbmsg(){ return ::proto_ff::operatetask(); }
	};
	typedef struct operatetask_s operatetask_t;

	struct Sheet_operatetask_s : public NFDescStoreSeqOP {
		Sheet_operatetask_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatetask_s, 175> operatetask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatetask & msg);
		static ::proto_ff::Sheet_operatetask* new_pbmsg(){ return new ::proto_ff::Sheet_operatetask(); }
		static ::proto_ff::Sheet_operatetask make_pbmsg(){ return ::proto_ff::Sheet_operatetask(); }
	};
	typedef struct Sheet_operatetask_s Sheet_operatetask_t;

	struct operateshop_s : public NFDescStoreSeqOP {
		operateshop_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemid;
		int32_t price;
		int32_t dPrice;
		int32_t moneyType;
		int32_t times;
		int32_t timeLimit;

		virtual void write_to_pbmsg(::proto_ff::operateshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateshop & msg);
		static ::proto_ff::operateshop* new_pbmsg(){ return new ::proto_ff::operateshop(); }
		static ::proto_ff::operateshop make_pbmsg(){ return ::proto_ff::operateshop(); }
	};
	typedef struct operateshop_s operateshop_t;

	struct Sheet_operateshop_s : public NFDescStoreSeqOP {
		Sheet_operateshop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateshop_s, 169> operateshop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateshop & msg);
		static ::proto_ff::Sheet_operateshop* new_pbmsg(){ return new ::proto_ff::Sheet_operateshop(); }
		static ::proto_ff::Sheet_operateshop make_pbmsg(){ return ::proto_ff::Sheet_operateshop(); }
	};
	typedef struct Sheet_operateshop_s Sheet_operateshop_t;

	struct operatewish_s : public NFDescStoreSeqOP {
		operatewish_s();
		int CreateInit();
		int ResumeInit();
		int32_t level;
		int64_t exp;

		virtual void write_to_pbmsg(::proto_ff::operatewish & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operatewish & msg);
		static ::proto_ff::operatewish* new_pbmsg(){ return new ::proto_ff::operatewish(); }
		static ::proto_ff::operatewish make_pbmsg(){ return ::proto_ff::operatewish(); }
	};
	typedef struct operatewish_s operatewish_t;

	struct Sheet_operatewish_s : public NFDescStoreSeqOP {
		Sheet_operatewish_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operatewish_s, 1604> operatewish_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operatewish & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operatewish & msg);
		static ::proto_ff::Sheet_operatewish* new_pbmsg(){ return new ::proto_ff::Sheet_operatewish(); }
		static ::proto_ff::Sheet_operatewish make_pbmsg(){ return ::proto_ff::Sheet_operatewish(); }
	};
	typedef struct Sheet_operatewish_s Sheet_operatewish_t;

	struct operateturntable_s : public NFDescStoreSeqOP {
		operateturntable_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t itemId;
		int32_t count;
		int32_t prof;
		int32_t prizeLevel;
		int32_t weight;
		int32_t broadcast;
		int32_t order;
		int64_t relation;

		virtual void write_to_pbmsg(::proto_ff::operateturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateturntable & msg);
		static ::proto_ff::operateturntable* new_pbmsg(){ return new ::proto_ff::operateturntable(); }
		static ::proto_ff::operateturntable make_pbmsg(){ return ::proto_ff::operateturntable(); }
	};
	typedef struct operateturntable_s operateturntable_t;

	struct Sheet_operateturntable_s : public NFDescStoreSeqOP {
		Sheet_operateturntable_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateturntable_s, 112> operateturntable_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateturntable & msg);
		static ::proto_ff::Sheet_operateturntable* new_pbmsg(){ return new ::proto_ff::Sheet_operateturntable(); }
		static ::proto_ff::Sheet_operateturntable make_pbmsg(){ return ::proto_ff::Sheet_operateturntable(); }
	};
	typedef struct Sheet_operateturntable_s Sheet_operateturntable_t;

	struct operateturntableTask_s : public NFDescStoreSeqOP {
		operateturntableTask_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t taskType;
		int32_t taskParam;
		int64_t itemId;
		int32_t itemCount;

		virtual void write_to_pbmsg(::proto_ff::operateturntableTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::operateturntableTask & msg);
		static ::proto_ff::operateturntableTask* new_pbmsg(){ return new ::proto_ff::operateturntableTask(); }
		static ::proto_ff::operateturntableTask make_pbmsg(){ return ::proto_ff::operateturntableTask(); }
	};
	typedef struct operateturntableTask_s operateturntableTask_t;

	struct Sheet_operateturntableTask_s : public NFDescStoreSeqOP {
		Sheet_operateturntableTask_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct operateturntableTask_s, 108> operateturntableTask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_operateturntableTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_operateturntableTask & msg);
		static ::proto_ff::Sheet_operateturntableTask* new_pbmsg(){ return new ::proto_ff::Sheet_operateturntableTask(); }
		static ::proto_ff::Sheet_operateturntableTask make_pbmsg(){ return ::proto_ff::Sheet_operateturntableTask(); }
	};
	typedef struct Sheet_operateturntableTask_s Sheet_operateturntableTask_t;

}

