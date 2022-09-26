#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "worldmapboss.pb.h"
#include "worldmapboss_s.h"

namespace proto_ff_s {

	struct worldmapbossworldbossbornDesc_s : public NFDescStoreSeqOP {
		worldmapbossworldbossbornDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<60> Time;

		virtual void write_to_pbmsg(::proto_ff::worldmapbossworldbossbornDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::worldmapbossworldbossbornDesc & msg);
		static ::proto_ff::worldmapbossworldbossbornDesc* new_pbmsg(){ return new ::proto_ff::worldmapbossworldbossbornDesc(); }
		static ::proto_ff::worldmapbossworldbossbornDesc make_pbmsg(){ return ::proto_ff::worldmapbossworldbossbornDesc(); }
	};
	typedef struct worldmapbossworldbossbornDesc_s worldmapbossworldbossbornDesc_t;

	struct worldmapbossworldboss_s : public NFDescStoreSeqOP {
		worldmapbossworldboss_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t bossId;
		int32_t miniLevel;
		int32_t unLockLevel;
		int32_t levelCheck;
		NFSizeString<60> pathId;
		int32_t specNoticeHP;
		int32_t bornSpaceTime;
		NFArray<struct worldmapbossworldbossbornDesc_s, 6> born;

		virtual void write_to_pbmsg(::proto_ff::worldmapbossworldboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::worldmapbossworldboss & msg);
		static ::proto_ff::worldmapbossworldboss* new_pbmsg(){ return new ::proto_ff::worldmapbossworldboss(); }
		static ::proto_ff::worldmapbossworldboss make_pbmsg(){ return ::proto_ff::worldmapbossworldboss(); }
	};
	typedef struct worldmapbossworldboss_s worldmapbossworldboss_t;

	struct Sheet_worldmapbossworldboss_s : public NFDescStoreSeqOP {
		Sheet_worldmapbossworldboss_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct worldmapbossworldboss_s, 300> worldmapbossworldboss_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_worldmapbossworldboss & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossworldboss & msg);
		static ::proto_ff::Sheet_worldmapbossworldboss* new_pbmsg(){ return new ::proto_ff::Sheet_worldmapbossworldboss(); }
		static ::proto_ff::Sheet_worldmapbossworldboss make_pbmsg(){ return ::proto_ff::Sheet_worldmapbossworldboss(); }
	};
	typedef struct Sheet_worldmapbossworldboss_s Sheet_worldmapbossworldboss_t;

	struct worldmapbossdroplist_s : public NFDescStoreSeqOP {
		worldmapbossdroplist_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t monsterId;
		int32_t bossLevel;
		int64_t dropId;

		virtual void write_to_pbmsg(::proto_ff::worldmapbossdroplist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::worldmapbossdroplist & msg);
		static ::proto_ff::worldmapbossdroplist* new_pbmsg(){ return new ::proto_ff::worldmapbossdroplist(); }
		static ::proto_ff::worldmapbossdroplist make_pbmsg(){ return ::proto_ff::worldmapbossdroplist(); }
	};
	typedef struct worldmapbossdroplist_s worldmapbossdroplist_t;

	struct Sheet_worldmapbossdroplist_s : public NFDescStoreSeqOP {
		Sheet_worldmapbossdroplist_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct worldmapbossdroplist_s, 4000> worldmapbossdroplist_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_worldmapbossdroplist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossdroplist & msg);
		static ::proto_ff::Sheet_worldmapbossdroplist* new_pbmsg(){ return new ::proto_ff::Sheet_worldmapbossdroplist(); }
		static ::proto_ff::Sheet_worldmapbossdroplist make_pbmsg(){ return ::proto_ff::Sheet_worldmapbossdroplist(); }
	};
	typedef struct Sheet_worldmapbossdroplist_s Sheet_worldmapbossdroplist_t;

	struct worldmapbossfestival_s : public NFDescStoreSeqOP {
		worldmapbossfestival_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t bossId;
		int32_t across;

		virtual void write_to_pbmsg(::proto_ff::worldmapbossfestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::worldmapbossfestival & msg);
		static ::proto_ff::worldmapbossfestival* new_pbmsg(){ return new ::proto_ff::worldmapbossfestival(); }
		static ::proto_ff::worldmapbossfestival make_pbmsg(){ return ::proto_ff::worldmapbossfestival(); }
	};
	typedef struct worldmapbossfestival_s worldmapbossfestival_t;

	struct Sheet_worldmapbossfestival_s : public NFDescStoreSeqOP {
		Sheet_worldmapbossfestival_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct worldmapbossfestival_s, 300> worldmapbossfestival_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_worldmapbossfestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossfestival & msg);
		static ::proto_ff::Sheet_worldmapbossfestival* new_pbmsg(){ return new ::proto_ff::Sheet_worldmapbossfestival(); }
		static ::proto_ff::Sheet_worldmapbossfestival make_pbmsg(){ return ::proto_ff::Sheet_worldmapbossfestival(); }
	};
	typedef struct Sheet_worldmapbossfestival_s Sheet_worldmapbossfestival_t;

}

