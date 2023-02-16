#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "boss.pb.h"
#include "boss_s.h"

namespace proto_ff_s {

	struct E_BossRareitem_s : public NFDescStoreSeqOP {
		E_BossRareitem_s();
		virtual ~E_BossRareitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_itemid;
		int32_t m_top;

		virtual void write_to_pbmsg(::proto_ff::E_BossRareitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossRareitem & msg);
		static ::proto_ff::E_BossRareitem* new_pbmsg(){ return new ::proto_ff::E_BossRareitem(); }
		static ::proto_ff::E_BossRareitem make_pbmsg(){ return ::proto_ff::E_BossRareitem(); }
	};
	typedef struct E_BossRareitem_s E_BossRareitem_t;

	struct Sheet_BossRareitem_s : public NFDescStoreSeqOP {
		Sheet_BossRareitem_s();
		virtual ~Sheet_BossRareitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossRareitem_s, 600> E_BossRareitem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossRareitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossRareitem & msg);
		static ::proto_ff::Sheet_BossRareitem* new_pbmsg(){ return new ::proto_ff::Sheet_BossRareitem(); }
		static ::proto_ff::Sheet_BossRareitem make_pbmsg(){ return ::proto_ff::Sheet_BossRareitem(); }
	};
	typedef struct Sheet_BossRareitem_s Sheet_BossRareitem_t;

	struct E_BossBoss_s : public NFDescStoreSeqOP {
		E_BossBoss_s();
		virtual ~E_BossBoss_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_bosstype;
		int32_t m_monsterid;
		int32_t m_classorder;
		int32_t m_sceneorder;
		int32_t m_duplicateid;
		int32_t m_peacemask;
		int32_t m_pointid;
		int32_t m_group_type;
		int32_t m_flashtime;
		int32_t m_retrievegiftid;
		int32_t m_notimes;

		virtual void write_to_pbmsg(::proto_ff::E_BossBoss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBoss & msg);
		static ::proto_ff::E_BossBoss* new_pbmsg(){ return new ::proto_ff::E_BossBoss(); }
		static ::proto_ff::E_BossBoss make_pbmsg(){ return ::proto_ff::E_BossBoss(); }
	};
	typedef struct E_BossBoss_s E_BossBoss_t;

	struct Sheet_BossBoss_s : public NFDescStoreSeqOP {
		Sheet_BossBoss_s();
		virtual ~Sheet_BossBoss_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossBoss_s, 80> E_BossBoss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossBoss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossBoss & msg);
		static ::proto_ff::Sheet_BossBoss* new_pbmsg(){ return new ::proto_ff::Sheet_BossBoss(); }
		static ::proto_ff::Sheet_BossBoss make_pbmsg(){ return ::proto_ff::Sheet_BossBoss(); }
	};
	typedef struct Sheet_BossBoss_s Sheet_BossBoss_t;

	struct E_BossBosstypeGroupDesc_s : public NFDescStoreSeqOP {
		E_BossBosstypeGroupDesc_s();
		virtual ~E_BossBosstypeGroupDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_times;

		virtual void write_to_pbmsg(::proto_ff::E_BossBosstypeGroupDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBosstypeGroupDesc & msg);
		static ::proto_ff::E_BossBosstypeGroupDesc* new_pbmsg(){ return new ::proto_ff::E_BossBosstypeGroupDesc(); }
		static ::proto_ff::E_BossBosstypeGroupDesc make_pbmsg(){ return ::proto_ff::E_BossBosstypeGroupDesc(); }
	};
	typedef struct E_BossBosstypeGroupDesc_s E_BossBosstypeGroupDesc_t;

	struct E_BossBosstype_s : public NFDescStoreSeqOP {
		E_BossBosstype_s();
		virtual ~E_BossBosstype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_bosstype;
		int32_t m_maptype;
		int32_t m_functionid;
		int32_t m_duplicategroupid;
		int32_t m_privilegetype;
		int64_t m_callingcardid;
		int32_t m_entertimes;
		int32_t m_costitem;
		NFShmString<60> m_costnum;
		int32_t m_bosstimes;
		int32_t m_additemid;
		int32_t m_canhelp;
		int32_t m_qkill;
		int32_t m_retrieveddays;
		int32_t m_skill;
		NFShmVector<struct E_BossBosstypeGroupDesc_s, 3> m_group;

		virtual void write_to_pbmsg(::proto_ff::E_BossBosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossBosstype & msg);
		static ::proto_ff::E_BossBosstype* new_pbmsg(){ return new ::proto_ff::E_BossBosstype(); }
		static ::proto_ff::E_BossBosstype make_pbmsg(){ return ::proto_ff::E_BossBosstype(); }
	};
	typedef struct E_BossBosstype_s E_BossBosstype_t;

	struct Sheet_BossBosstype_s : public NFDescStoreSeqOP {
		Sheet_BossBosstype_s();
		virtual ~Sheet_BossBosstype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossBosstype_s, 20> E_BossBosstype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossBosstype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossBosstype & msg);
		static ::proto_ff::Sheet_BossBosstype* new_pbmsg(){ return new ::proto_ff::Sheet_BossBosstype(); }
		static ::proto_ff::Sheet_BossBosstype make_pbmsg(){ return ::proto_ff::Sheet_BossBosstype(); }
	};
	typedef struct Sheet_BossBosstype_s Sheet_BossBosstype_t;

	struct E_BossLayer_s : public NFDescStoreSeqOP {
		E_BossLayer_s();
		virtual ~E_BossLayer_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_bosstype;
		int32_t m_order;
		NFShmString<60> m_name;
		NFShmString<60> m_entercondition;
		NFShmString<60> m_unlockcondition;
		int32_t m_mapid;

		virtual void write_to_pbmsg(::proto_ff::E_BossLayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BossLayer & msg);
		static ::proto_ff::E_BossLayer* new_pbmsg(){ return new ::proto_ff::E_BossLayer(); }
		static ::proto_ff::E_BossLayer make_pbmsg(){ return ::proto_ff::E_BossLayer(); }
	};
	typedef struct E_BossLayer_s E_BossLayer_t;

	struct Sheet_BossLayer_s : public NFDescStoreSeqOP {
		Sheet_BossLayer_s();
		virtual ~Sheet_BossLayer_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BossLayer_s, 20> E_BossLayer_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BossLayer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BossLayer & msg);
		static ::proto_ff::Sheet_BossLayer* new_pbmsg(){ return new ::proto_ff::Sheet_BossLayer(); }
		static ::proto_ff::Sheet_BossLayer make_pbmsg(){ return ::proto_ff::Sheet_BossLayer(); }
	};
	typedef struct Sheet_BossLayer_s Sheet_BossLayer_t;

}

