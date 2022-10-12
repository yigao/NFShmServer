#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "field.pb.h"
#include "field_s.h"

namespace proto_ff_s {

	struct fieldfieldfieldDesc_s : public NFDescStoreSeqOP {
		fieldfieldfieldDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t att;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::fieldfieldfieldDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldfieldfieldDesc & msg);
		static ::proto_ff::fieldfieldfieldDesc* new_pbmsg(){ return new ::proto_ff::fieldfieldfieldDesc(); }
		static ::proto_ff::fieldfieldfieldDesc make_pbmsg(){ return ::proto_ff::fieldfieldfieldDesc(); }
	};
	typedef struct fieldfieldfieldDesc_s fieldfieldfieldDesc_t;

	struct fieldfield_s : public NFDescStoreSeqOP {
		fieldfield_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> name;
		int32_t quality;
		NFArray<struct fieldfieldfieldDesc_s, 4> field;
		NFArray<int64_t, 3> skill;
		NFArray<int32_t, 5> num;
		NFArray<int32_t, 5> pos;

		virtual void write_to_pbmsg(::proto_ff::fieldfield & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldfield & msg);
		static ::proto_ff::fieldfield* new_pbmsg(){ return new ::proto_ff::fieldfield(); }
		static ::proto_ff::fieldfield make_pbmsg(){ return ::proto_ff::fieldfield(); }
	};
	typedef struct fieldfield_s fieldfield_t;

	struct Sheet_fieldfield_s : public NFDescStoreSeqOP {
		Sheet_fieldfield_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldfield_s, 60> fieldfield_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldfield & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldfield & msg);
		static ::proto_ff::Sheet_fieldfield* new_pbmsg(){ return new ::proto_ff::Sheet_fieldfield(); }
		static ::proto_ff::Sheet_fieldfield make_pbmsg(){ return ::proto_ff::Sheet_fieldfield(); }
	};
	typedef struct Sheet_fieldfield_s Sheet_fieldfield_t;

	struct fieldreikirefineDesc_s : public NFDescStoreSeqOP {
		fieldreikirefineDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::fieldreikirefineDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldreikirefineDesc & msg);
		static ::proto_ff::fieldreikirefineDesc* new_pbmsg(){ return new ::proto_ff::fieldreikirefineDesc(); }
		static ::proto_ff::fieldreikirefineDesc make_pbmsg(){ return ::proto_ff::fieldreikirefineDesc(); }
	};
	typedef struct fieldreikirefineDesc_s fieldreikirefineDesc_t;

	struct fieldreiki_s : public NFDescStoreSeqOP {
		fieldreiki_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> name;
		int32_t quality;
		int32_t field;
		int32_t Lv;
		int32_t star;
		NFSizeString<60> refineAttribute;
		NFSizeString<60> refineAttributeValue;
		int32_t blueStarNum;
		NFSizeString<60> blueStar_type;
		NFSizeString<60> blueStar_value;
		int32_t exp;
		int64_t link;
		NFArray<struct fieldreikirefineDesc_s, 2> refine;

		virtual void write_to_pbmsg(::proto_ff::fieldreiki & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldreiki & msg);
		static ::proto_ff::fieldreiki* new_pbmsg(){ return new ::proto_ff::fieldreiki(); }
		static ::proto_ff::fieldreiki make_pbmsg(){ return ::proto_ff::fieldreiki(); }
	};
	typedef struct fieldreiki_s fieldreiki_t;

	struct Sheet_fieldreiki_s : public NFDescStoreSeqOP {
		Sheet_fieldreiki_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldreiki_s, 200> fieldreiki_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldreiki & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldreiki & msg);
		static ::proto_ff::Sheet_fieldreiki* new_pbmsg(){ return new ::proto_ff::Sheet_fieldreiki(); }
		static ::proto_ff::Sheet_fieldreiki make_pbmsg(){ return ::proto_ff::Sheet_fieldreiki(); }
	};
	typedef struct Sheet_fieldreiki_s Sheet_fieldreiki_t;

	struct fieldexp_s : public NFDescStoreSeqOP {
		fieldexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::fieldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldexp & msg);
		static ::proto_ff::fieldexp* new_pbmsg(){ return new ::proto_ff::fieldexp(); }
		static ::proto_ff::fieldexp make_pbmsg(){ return ::proto_ff::fieldexp(); }
	};
	typedef struct fieldexp_s fieldexp_t;

	struct Sheet_fieldexp_s : public NFDescStoreSeqOP {
		Sheet_fieldexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldexp_s, 200> fieldexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldexp & msg);
		static ::proto_ff::Sheet_fieldexp* new_pbmsg(){ return new ::proto_ff::Sheet_fieldexp(); }
		static ::proto_ff::Sheet_fieldexp make_pbmsg(){ return ::proto_ff::Sheet_fieldexp(); }
	};
	typedef struct Sheet_fieldexp_s Sheet_fieldexp_t;

	struct fieldvalue_s : public NFDescStoreSeqOP {
		fieldvalue_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFArray<int32_t, 150> lvValue;

		virtual void write_to_pbmsg(::proto_ff::fieldvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldvalue & msg);
		static ::proto_ff::fieldvalue* new_pbmsg(){ return new ::proto_ff::fieldvalue(); }
		static ::proto_ff::fieldvalue make_pbmsg(){ return ::proto_ff::fieldvalue(); }
	};
	typedef struct fieldvalue_s fieldvalue_t;

	struct Sheet_fieldvalue_s : public NFDescStoreSeqOP {
		Sheet_fieldvalue_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldvalue_s, 140> fieldvalue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldvalue & msg);
		static ::proto_ff::Sheet_fieldvalue* new_pbmsg(){ return new ::proto_ff::Sheet_fieldvalue(); }
		static ::proto_ff::Sheet_fieldvalue make_pbmsg(){ return ::proto_ff::Sheet_fieldvalue(); }
	};
	typedef struct Sheet_fieldvalue_s Sheet_fieldvalue_t;

	struct fieldexpand_s : public NFDescStoreSeqOP {
		fieldexpand_s();
		int CreateInit();
		int ResumeInit();
		int32_t number;
		int32_t lv;
		int64_t id;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::fieldexpand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldexpand & msg);
		static ::proto_ff::fieldexpand* new_pbmsg(){ return new ::proto_ff::fieldexpand(); }
		static ::proto_ff::fieldexpand make_pbmsg(){ return ::proto_ff::fieldexpand(); }
	};
	typedef struct fieldexpand_s fieldexpand_t;

	struct Sheet_fieldexpand_s : public NFDescStoreSeqOP {
		Sheet_fieldexpand_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldexpand_s, 60> fieldexpand_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldexpand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldexpand & msg);
		static ::proto_ff::Sheet_fieldexpand* new_pbmsg(){ return new ::proto_ff::Sheet_fieldexpand(); }
		static ::proto_ff::Sheet_fieldexpand make_pbmsg(){ return ::proto_ff::Sheet_fieldexpand(); }
	};
	typedef struct Sheet_fieldexpand_s Sheet_fieldexpand_t;

	struct fieldstong_s : public NFDescStoreSeqOP {
		fieldstong_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t stongId;
		int64_t fenJieId;
		int32_t fenJieNum;

		virtual void write_to_pbmsg(::proto_ff::fieldstong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fieldstong & msg);
		static ::proto_ff::fieldstong* new_pbmsg(){ return new ::proto_ff::fieldstong(); }
		static ::proto_ff::fieldstong make_pbmsg(){ return ::proto_ff::fieldstong(); }
	};
	typedef struct fieldstong_s fieldstong_t;

	struct Sheet_fieldstong_s : public NFDescStoreSeqOP {
		Sheet_fieldstong_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct fieldstong_s, 100> fieldstong_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fieldstong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fieldstong & msg);
		static ::proto_ff::Sheet_fieldstong* new_pbmsg(){ return new ::proto_ff::Sheet_fieldstong(); }
		static ::proto_ff::Sheet_fieldstong make_pbmsg(){ return ::proto_ff::Sheet_fieldstong(); }
	};
	typedef struct Sheet_fieldstong_s Sheet_fieldstong_t;

}

