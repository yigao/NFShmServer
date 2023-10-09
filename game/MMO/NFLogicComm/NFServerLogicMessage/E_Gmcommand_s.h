#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Gmcommand.pb.h"
#include "E_Gmcommand_s.h"

#define DEFINE_SHEET_GMCOMMANDGMCOMMAND_E_GMCOMMANDGMCOMMAND_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_GmcommandGmcommand_s : public NFDescStoreSeqOP {
		E_GmcommandGmcommand_s();
		virtual ~E_GmcommandGmcommand_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//命令索引
		NFShmString<64> m_key;//命令关键字
		int32_t m_paramcount;//参数数量
		NFShmString<64> m_des;//描述

		virtual void write_to_pbmsg(::proto_ff::E_GmcommandGmcommand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GmcommandGmcommand & msg);
		static ::proto_ff::E_GmcommandGmcommand* new_pbmsg(){ return new ::proto_ff::E_GmcommandGmcommand(); }
		static ::proto_ff::E_GmcommandGmcommand make_pbmsg(){ return ::proto_ff::E_GmcommandGmcommand(); }
	};
	typedef struct E_GmcommandGmcommand_s E_GmcommandGmcommand_t;

	struct Sheet_GmcommandGmcommand_s : public NFDescStoreSeqOP {
		Sheet_GmcommandGmcommand_s();
		virtual ~Sheet_GmcommandGmcommand_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GmcommandGmcommand_s, DEFINE_SHEET_GMCOMMANDGMCOMMAND_E_GMCOMMANDGMCOMMAND_LIST_MAX_NUM> E_GmcommandGmcommand_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GmcommandGmcommand & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GmcommandGmcommand & msg);
		static ::proto_ff::Sheet_GmcommandGmcommand* new_pbmsg(){ return new ::proto_ff::Sheet_GmcommandGmcommand(); }
		static ::proto_ff::Sheet_GmcommandGmcommand make_pbmsg(){ return ::proto_ff::Sheet_GmcommandGmcommand(); }
	};
	typedef struct Sheet_GmcommandGmcommand_s Sheet_GmcommandGmcommand_t;

}

