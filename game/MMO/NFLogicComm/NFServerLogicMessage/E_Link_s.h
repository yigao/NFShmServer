#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Link.pb.h"
#include "E_Link_s.h"

#define DEFINE_SHEET_LINKLINK_E_LINKLINK_LIST_MAX_NUM 512
#define DEFINE_SHEET_LINKIMAGELINK_E_LINKIMAGELINK_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_LinkLink_s : public NFDescStoreSeqOP {
		E_LinkLink_s();
		virtual ~E_LinkLink_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//序号
		NFShmString<64> m_icon;//显示图标
		NFShmString<64> m_dbArgs;//主参数关联的配置表名称
		NFShmString<64> m_argsm;//备选参数
		int32_t m_functionUnlock;//关联功能开放
		NFShmString<64> m_linkNpc;//关联npc

		virtual void write_to_pbmsg(::proto_ff::E_LinkLink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_LinkLink & msg);
		static ::proto_ff::E_LinkLink* new_pbmsg(){ return new ::proto_ff::E_LinkLink(); }
		static ::proto_ff::E_LinkLink make_pbmsg(){ return ::proto_ff::E_LinkLink(); }
	};
	typedef struct E_LinkLink_s E_LinkLink_t;

	struct Sheet_LinkLink_s : public NFDescStoreSeqOP {
		Sheet_LinkLink_s();
		virtual ~Sheet_LinkLink_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_LinkLink_s, DEFINE_SHEET_LINKLINK_E_LINKLINK_LIST_MAX_NUM> E_LinkLink_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_LinkLink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_LinkLink & msg);
		static ::proto_ff::Sheet_LinkLink* new_pbmsg(){ return new ::proto_ff::Sheet_LinkLink(); }
		static ::proto_ff::Sheet_LinkLink make_pbmsg(){ return ::proto_ff::Sheet_LinkLink(); }
	};
	typedef struct Sheet_LinkLink_s Sheet_LinkLink_t;

	struct E_LinkImagelink_s : public NFDescStoreSeqOP {
		E_LinkImagelink_s();
		virtual ~E_LinkImagelink_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_closeType;//关闭条件类型
		int32_t m_closeArg;//关闭条件

		virtual void write_to_pbmsg(::proto_ff::E_LinkImagelink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_LinkImagelink & msg);
		static ::proto_ff::E_LinkImagelink* new_pbmsg(){ return new ::proto_ff::E_LinkImagelink(); }
		static ::proto_ff::E_LinkImagelink make_pbmsg(){ return ::proto_ff::E_LinkImagelink(); }
	};
	typedef struct E_LinkImagelink_s E_LinkImagelink_t;

	struct Sheet_LinkImagelink_s : public NFDescStoreSeqOP {
		Sheet_LinkImagelink_s();
		virtual ~Sheet_LinkImagelink_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_LinkImagelink_s, DEFINE_SHEET_LINKIMAGELINK_E_LINKIMAGELINK_LIST_MAX_NUM> E_LinkImagelink_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_LinkImagelink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_LinkImagelink & msg);
		static ::proto_ff::Sheet_LinkImagelink* new_pbmsg(){ return new ::proto_ff::Sheet_LinkImagelink(); }
		static ::proto_ff::Sheet_LinkImagelink make_pbmsg(){ return ::proto_ff::Sheet_LinkImagelink(); }
	};
	typedef struct Sheet_LinkImagelink_s Sheet_LinkImagelink_t;

}

