#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Tianxiafirst.pb.h"
#include "E_Tianxiafirst_s.h"

#define DEFINE_E_TIANXIAFIRSTACTIVATE_M_ATT_MAX_NUM 5
#define DEFINE_E_TIANXIAFIRSTACTIVATE_M_MODEL_MAX_NUM 6
#define DEFINE_SHEET_TIANXIAFIRSTACTIVATE_E_TIANXIAFIRSTACTIVATE_LIST_MAX_NUM 16
#define DEFINE_E_TIANXIAFIRSTSTRONG_M_TYPE_MAX_NUM 5
#define DEFINE_SHEET_TIANXIAFIRSTSTRONG_E_TIANXIAFIRSTSTRONG_LIST_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTSTRONGITEM_E_TIANXIAFIRSTSTRONGITEM_LIST_MAX_NUM 2
#define DEFINE_E_TIANXIAFIRSTREFINE_M_ATT_MAX_NUM 5
#define DEFINE_SHEET_TIANXIAFIRSTREFINE_E_TIANXIAFIRSTREFINE_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_TianxiafirstActivateAttDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstActivateAttDesc_s();
		virtual ~E_TianxiafirstActivateAttDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstActivateAttDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivateAttDesc & msg);
		static ::proto_ff::E_TianxiafirstActivateAttDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstActivateAttDesc(); }
		static ::proto_ff::E_TianxiafirstActivateAttDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstActivateAttDesc(); }
	};
	typedef struct E_TianxiafirstActivateAttDesc_s E_TianxiafirstActivateAttDesc_t;

	struct E_TianxiafirstActivateModelDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstActivateModelDesc_s();
		virtual ~E_TianxiafirstActivateModelDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_condition;//激活条件
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstActivateModelDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivateModelDesc & msg);
		static ::proto_ff::E_TianxiafirstActivateModelDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstActivateModelDesc(); }
		static ::proto_ff::E_TianxiafirstActivateModelDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstActivateModelDesc(); }
	};
	typedef struct E_TianxiafirstActivateModelDesc_s E_TianxiafirstActivateModelDesc_t;

	struct E_TianxiafirstActivate_s : public NFDescStoreSeqOP {
		E_TianxiafirstActivate_s();
		virtual ~E_TianxiafirstActivate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_artifactId;//神器id
		int32_t m_preId;//激活条件-前置id
		int32_t m_condition;//激活条件
		NFShmVector<struct E_TianxiafirstActivateAttDesc_s, DEFINE_E_TIANXIAFIRSTACTIVATE_M_ATT_MAX_NUM> m_att;//激活属性
		NFShmVector<struct E_TianxiafirstActivateModelDesc_s, DEFINE_E_TIANXIAFIRSTACTIVATE_M_MODEL_MAX_NUM> m_model;//神器外观

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstActivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivate & msg);
		static ::proto_ff::E_TianxiafirstActivate* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstActivate(); }
		static ::proto_ff::E_TianxiafirstActivate make_pbmsg(){ return ::proto_ff::E_TianxiafirstActivate(); }
	};
	typedef struct E_TianxiafirstActivate_s E_TianxiafirstActivate_t;

	struct Sheet_TianxiafirstActivate_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstActivate_s();
		virtual ~Sheet_TianxiafirstActivate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstActivate_s, DEFINE_SHEET_TIANXIAFIRSTACTIVATE_E_TIANXIAFIRSTACTIVATE_LIST_MAX_NUM> E_TianxiafirstActivate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstActivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstActivate & msg);
		static ::proto_ff::Sheet_TianxiafirstActivate* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstActivate(); }
		static ::proto_ff::Sheet_TianxiafirstActivate make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstActivate(); }
	};
	typedef struct Sheet_TianxiafirstActivate_s Sheet_TianxiafirstActivate_t;

	struct E_TianxiafirstStrongTypeDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstStrongTypeDesc_s();
		virtual ~E_TianxiafirstStrongTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstStrongTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongTypeDesc & msg);
		static ::proto_ff::E_TianxiafirstStrongTypeDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstStrongTypeDesc(); }
		static ::proto_ff::E_TianxiafirstStrongTypeDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstStrongTypeDesc(); }
	};
	typedef struct E_TianxiafirstStrongTypeDesc_s E_TianxiafirstStrongTypeDesc_t;

	struct E_TianxiafirstStrong_s : public NFDescStoreSeqOP {
		E_TianxiafirstStrong_s();
		virtual ~E_TianxiafirstStrong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_artifactId;//神器id
		int32_t m_strongUp;//强化上限
		NFShmString<64> m_exp;//强化所需经验
		NFShmVector<struct E_TianxiafirstStrongTypeDesc_s, DEFINE_E_TIANXIAFIRSTSTRONG_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrong & msg);
		static ::proto_ff::E_TianxiafirstStrong* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstStrong(); }
		static ::proto_ff::E_TianxiafirstStrong make_pbmsg(){ return ::proto_ff::E_TianxiafirstStrong(); }
	};
	typedef struct E_TianxiafirstStrong_s E_TianxiafirstStrong_t;

	struct Sheet_TianxiafirstStrong_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstStrong_s();
		virtual ~Sheet_TianxiafirstStrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstStrong_s, DEFINE_SHEET_TIANXIAFIRSTSTRONG_E_TIANXIAFIRSTSTRONG_LIST_MAX_NUM> E_TianxiafirstStrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrong & msg);
		static ::proto_ff::Sheet_TianxiafirstStrong* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstStrong(); }
		static ::proto_ff::Sheet_TianxiafirstStrong make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstStrong(); }
	};
	typedef struct Sheet_TianxiafirstStrong_s Sheet_TianxiafirstStrong_t;

	struct E_TianxiafirstStrongitem_s : public NFDescStoreSeqOP {
		E_TianxiafirstStrongitem_s();
		virtual ~E_TianxiafirstStrongitem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//强化道具id
		int32_t m_addExp;//增加强化经验

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstStrongitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongitem & msg);
		static ::proto_ff::E_TianxiafirstStrongitem* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstStrongitem(); }
		static ::proto_ff::E_TianxiafirstStrongitem make_pbmsg(){ return ::proto_ff::E_TianxiafirstStrongitem(); }
	};
	typedef struct E_TianxiafirstStrongitem_s E_TianxiafirstStrongitem_t;

	struct Sheet_TianxiafirstStrongitem_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstStrongitem_s();
		virtual ~Sheet_TianxiafirstStrongitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstStrongitem_s, DEFINE_SHEET_TIANXIAFIRSTSTRONGITEM_E_TIANXIAFIRSTSTRONGITEM_LIST_MAX_NUM> E_TianxiafirstStrongitem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrongitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrongitem & msg);
		static ::proto_ff::Sheet_TianxiafirstStrongitem* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstStrongitem(); }
		static ::proto_ff::Sheet_TianxiafirstStrongitem make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstStrongitem(); }
	};
	typedef struct Sheet_TianxiafirstStrongitem_s Sheet_TianxiafirstStrongitem_t;

	struct E_TianxiafirstRefineAttDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstRefineAttDesc_s();
		virtual ~E_TianxiafirstRefineAttDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstRefineAttDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefineAttDesc & msg);
		static ::proto_ff::E_TianxiafirstRefineAttDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstRefineAttDesc(); }
		static ::proto_ff::E_TianxiafirstRefineAttDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstRefineAttDesc(); }
	};
	typedef struct E_TianxiafirstRefineAttDesc_s E_TianxiafirstRefineAttDesc_t;

	struct E_TianxiafirstRefine_s : public NFDescStoreSeqOP {
		E_TianxiafirstRefine_s();
		virtual ~E_TianxiafirstRefine_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_artifactId;//神器id
		int32_t m_stage;//精炼阶级
		int32_t m_star;//精炼星数
		int32_t m_success;//成功率
		int32_t m_consumeItem;//消耗物品
		int32_t m_consumeNum;//消耗数量
		int32_t m_guarant;//保底次数
		NFShmVector<struct E_TianxiafirstRefineAttDesc_s, DEFINE_E_TIANXIAFIRSTREFINE_M_ATT_MAX_NUM> m_att;//精炼属性

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstRefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefine & msg);
		static ::proto_ff::E_TianxiafirstRefine* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstRefine(); }
		static ::proto_ff::E_TianxiafirstRefine make_pbmsg(){ return ::proto_ff::E_TianxiafirstRefine(); }
	};
	typedef struct E_TianxiafirstRefine_s E_TianxiafirstRefine_t;

	struct Sheet_TianxiafirstRefine_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstRefine_s();
		virtual ~Sheet_TianxiafirstRefine_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstRefine_s, DEFINE_SHEET_TIANXIAFIRSTREFINE_E_TIANXIAFIRSTREFINE_LIST_MAX_NUM> E_TianxiafirstRefine_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstRefine & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstRefine & msg);
		static ::proto_ff::Sheet_TianxiafirstRefine* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstRefine(); }
		static ::proto_ff::Sheet_TianxiafirstRefine make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstRefine(); }
	};
	typedef struct Sheet_TianxiafirstRefine_s Sheet_TianxiafirstRefine_t;

}

