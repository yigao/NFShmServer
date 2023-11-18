#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Chat.pb.h"
#include "E_Chat_s.h"

#define DEFINE_SHEET_CHATCHAT_E_CHATCHAT_LIST_MAX_NUM 512
#define DEFINE_SHEET_CHATSPECIALCHAT_E_CHATSPECIALCHAT_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_ChatChat_s : public NFDescStoreSeqOP {
		E_ChatChat_s();
		virtual ~E_ChatChat_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_chatId;//传闻ID
		int32_t m_chatType;//传闻类型
		int32_t m_showTime;//活动提示显示时间
		NFShmString<256> m_chatContent;//传闻内容
		int32_t m_channel;//显示频道
		int32_t m_CrossService;//是否跨服广播

		virtual void write_to_pbmsg(::proto_ff::E_ChatChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ChatChat & msg);
		static ::proto_ff::E_ChatChat* new_pbmsg(){ return new ::proto_ff::E_ChatChat(); }
		static ::proto_ff::E_ChatChat make_pbmsg(){ return ::proto_ff::E_ChatChat(); }
	};
	typedef struct E_ChatChat_s E_ChatChat_t;

	struct Sheet_ChatChat_s : public NFDescStoreSeqOP {
		Sheet_ChatChat_s();
		virtual ~Sheet_ChatChat_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ChatChat_s, DEFINE_SHEET_CHATCHAT_E_CHATCHAT_LIST_MAX_NUM> E_ChatChat_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ChatChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ChatChat & msg);
		static ::proto_ff::Sheet_ChatChat* new_pbmsg(){ return new ::proto_ff::Sheet_ChatChat(); }
		static ::proto_ff::Sheet_ChatChat make_pbmsg(){ return ::proto_ff::Sheet_ChatChat(); }
	};
	typedef struct Sheet_ChatChat_s Sheet_ChatChat_t;

	struct E_ChatSpecialchat_s : public NFDescStoreSeqOP {
		E_ChatSpecialchat_s();
		virtual ~E_ChatSpecialchat_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;//事件类型
		NFShmString<64> m_parama;//事件参数a
		NFShmString<128> m_paramb;//事件参数b
		int64_t m_chat_Id;//触发关联的跑马灯内容id

		virtual void write_to_pbmsg(::proto_ff::E_ChatSpecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ChatSpecialchat & msg);
		static ::proto_ff::E_ChatSpecialchat* new_pbmsg(){ return new ::proto_ff::E_ChatSpecialchat(); }
		static ::proto_ff::E_ChatSpecialchat make_pbmsg(){ return ::proto_ff::E_ChatSpecialchat(); }
	};
	typedef struct E_ChatSpecialchat_s E_ChatSpecialchat_t;

	struct Sheet_ChatSpecialchat_s : public NFDescStoreSeqOP {
		Sheet_ChatSpecialchat_s();
		virtual ~Sheet_ChatSpecialchat_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ChatSpecialchat_s, DEFINE_SHEET_CHATSPECIALCHAT_E_CHATSPECIALCHAT_LIST_MAX_NUM> E_ChatSpecialchat_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ChatSpecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ChatSpecialchat & msg);
		static ::proto_ff::Sheet_ChatSpecialchat* new_pbmsg(){ return new ::proto_ff::Sheet_ChatSpecialchat(); }
		static ::proto_ff::Sheet_ChatSpecialchat make_pbmsg(){ return ::proto_ff::Sheet_ChatSpecialchat(); }
	};
	typedef struct Sheet_ChatSpecialchat_s Sheet_ChatSpecialchat_t;

}

