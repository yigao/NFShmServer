#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Button.pb.h"
#include "E_Button_s.h"

#define DEFINE_SHEET_BUTTONBUTTON_E_BUTTONBUTTON_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_ButtonButton_s : public NFDescStoreSeqOP {
		E_ButtonButton_s();
		virtual ~E_ButtonButton_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//按钮id
		int32_t m_time;//读条时间

		virtual void write_to_pbmsg(::proto_ff::E_ButtonButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ButtonButton & msg);
		static ::proto_ff::E_ButtonButton* new_pbmsg(){ return new ::proto_ff::E_ButtonButton(); }
		static ::proto_ff::E_ButtonButton make_pbmsg(){ return ::proto_ff::E_ButtonButton(); }
	};
	typedef struct E_ButtonButton_s E_ButtonButton_t;

	struct Sheet_ButtonButton_s : public NFDescStoreSeqOP {
		Sheet_ButtonButton_s();
		virtual ~Sheet_ButtonButton_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ButtonButton_s, DEFINE_SHEET_BUTTONBUTTON_E_BUTTONBUTTON_LIST_MAX_NUM> E_ButtonButton_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ButtonButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ButtonButton & msg);
		static ::proto_ff::Sheet_ButtonButton* new_pbmsg(){ return new ::proto_ff::Sheet_ButtonButton(); }
		static ::proto_ff::Sheet_ButtonButton make_pbmsg(){ return ::proto_ff::Sheet_ButtonButton(); }
	};
	typedef struct Sheet_ButtonButton_s Sheet_ButtonButton_t;

}

