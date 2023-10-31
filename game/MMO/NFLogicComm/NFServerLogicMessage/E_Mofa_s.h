#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Mofa.pb.h"
#include "E_Mofa_s.h"

#define DEFINE_E_MOFASETUP_M_ZF_MAX_NUM 3
#define DEFINE_SHEET_MOFASETUP_E_MOFASETUP_LIST_MAX_NUM 16
#define DEFINE_E_MOFAYUANSU_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_E_MOFAYUANSU_M_AWAKEN_MAX_NUM 6
#define DEFINE_SHEET_MOFAYUANSU_E_MOFAYUANSU_LIST_MAX_NUM 64
#define DEFINE_SHEET_MOFADECOMPOSE_E_MOFADECOMPOSE_LIST_MAX_NUM 8
#define DEFINE_SHEET_MOFALVEXP_E_MOFALVEXP_LIST_MAX_NUM 128
#define DEFINE_E_MOFALVATT_M_ATT_MAX_NUM 100
#define DEFINE_SHEET_MOFALVATT_E_MOFALVATT_LIST_MAX_NUM 128
#define DEFINE_E_MOFAZYATT_M_ZY_MAX_NUM 2
#define DEFINE_SHEET_MOFAZYATT_E_MOFAZYATT_LIST_MAX_NUM 32
#define DEFINE_E_MOFAZYJXATT_M_ZYJX_MAX_NUM 3
#define DEFINE_SHEET_MOFAZYJXATT_E_MOFAZYJXATT_LIST_MAX_NUM 64
#define DEFINE_E_MOFAZYJXZFATT_M_ZYJXZF_MAX_NUM 3
#define DEFINE_SHEET_MOFAZYJXZFATT_E_MOFAZYJXZFATT_LIST_MAX_NUM 64
#define DEFINE_SHEET_MOFAEXCHANGE_E_MOFAEXCHANGE_LIST_MAX_NUM 32
#define DEFINE_SHEET_MOFANAME_E_MOFANAME_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_MofaSetupZfDesc_s : public NFDescStoreSeqOP {
		E_MofaSetupZfDesc_s();
		virtual ~E_MofaSetupZfDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MofaSetupZfDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaSetupZfDesc & msg);
		static ::proto_ff::E_MofaSetupZfDesc* new_pbmsg(){ return new ::proto_ff::E_MofaSetupZfDesc(); }
		static ::proto_ff::E_MofaSetupZfDesc make_pbmsg(){ return ::proto_ff::E_MofaSetupZfDesc(); }
	};
	typedef struct E_MofaSetupZfDesc_s E_MofaSetupZfDesc_t;

	struct E_MofaSetup_s : public NFDescStoreSeqOP {
		E_MofaSetup_s();
		virtual ~E_MofaSetup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//排序
		int32_t m_PositionID;//部位id
		int32_t m_Unlock;//解锁道具
		int32_t m_ZyAtt;//阵眼属性组
		int32_t m_Bless;//祝福道具
		int32_t m_BlessBonus;//祝福属性加成
		int32_t m_JxZyAtt;//觉醒阵眼属性组
		int32_t m_JxBlessBonus;//觉醒祝福属性加成
		int32_t m_JxBlessAtt;//觉醒祝福属性组
		NFShmVector<struct E_MofaSetupZfDesc_s, DEFINE_E_MOFASETUP_M_ZF_MAX_NUM> m_ZF;//祝福属性

		virtual void write_to_pbmsg(::proto_ff::E_MofaSetup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaSetup & msg);
		static ::proto_ff::E_MofaSetup* new_pbmsg(){ return new ::proto_ff::E_MofaSetup(); }
		static ::proto_ff::E_MofaSetup make_pbmsg(){ return ::proto_ff::E_MofaSetup(); }
	};
	typedef struct E_MofaSetup_s E_MofaSetup_t;

	struct Sheet_MofaSetup_s : public NFDescStoreSeqOP {
		Sheet_MofaSetup_s();
		virtual ~Sheet_MofaSetup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaSetup_s, DEFINE_SHEET_MOFASETUP_E_MOFASETUP_LIST_MAX_NUM> E_MofaSetup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaSetup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaSetup & msg);
		static ::proto_ff::Sheet_MofaSetup* new_pbmsg(){ return new ::proto_ff::Sheet_MofaSetup(); }
		static ::proto_ff::Sheet_MofaSetup make_pbmsg(){ return ::proto_ff::Sheet_MofaSetup(); }
	};
	typedef struct Sheet_MofaSetup_s Sheet_MofaSetup_t;

	struct E_MofaYuansuAttributeDesc_s : public NFDescStoreSeqOP {
		E_MofaYuansuAttributeDesc_s();
		virtual ~E_MofaYuansuAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MofaYuansuAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaYuansuAttributeDesc & msg);
		static ::proto_ff::E_MofaYuansuAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MofaYuansuAttributeDesc(); }
		static ::proto_ff::E_MofaYuansuAttributeDesc make_pbmsg(){ return ::proto_ff::E_MofaYuansuAttributeDesc(); }
	};
	typedef struct E_MofaYuansuAttributeDesc_s E_MofaYuansuAttributeDesc_t;

	struct E_MofaYuansuAwakenDesc_s : public NFDescStoreSeqOP {
		E_MofaYuansuAwakenDesc_s();
		virtual ~E_MofaYuansuAwakenDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lvAddratio;//升级属性加成百分比
		int32_t m_num;//材料数量

		virtual void write_to_pbmsg(::proto_ff::E_MofaYuansuAwakenDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaYuansuAwakenDesc & msg);
		static ::proto_ff::E_MofaYuansuAwakenDesc* new_pbmsg(){ return new ::proto_ff::E_MofaYuansuAwakenDesc(); }
		static ::proto_ff::E_MofaYuansuAwakenDesc make_pbmsg(){ return ::proto_ff::E_MofaYuansuAwakenDesc(); }
	};
	typedef struct E_MofaYuansuAwakenDesc_s E_MofaYuansuAwakenDesc_t;

	struct E_MofaYuansu_s : public NFDescStoreSeqOP {
		E_MofaYuansu_s();
		virtual ~E_MofaYuansu_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ItemID;//道具ID
		int32_t m_AttriType;//物品类型排序
		int32_t m_mosaic;//可镶嵌部位
		int32_t m_LvItem;//升级道具
		int32_t m_awaken_can;//是否可觉醒
		int32_t m_awaken_Lvmax;//觉醒上限
		int32_t m_awaken_item;//觉醒材料
		NFShmVector<struct E_MofaYuansuAttributeDesc_s, DEFINE_E_MOFAYUANSU_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_MofaYuansuAwakenDesc_s, DEFINE_E_MOFAYUANSU_M_AWAKEN_MAX_NUM> m_awaken;//觉醒

		virtual void write_to_pbmsg(::proto_ff::E_MofaYuansu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaYuansu & msg);
		static ::proto_ff::E_MofaYuansu* new_pbmsg(){ return new ::proto_ff::E_MofaYuansu(); }
		static ::proto_ff::E_MofaYuansu make_pbmsg(){ return ::proto_ff::E_MofaYuansu(); }
	};
	typedef struct E_MofaYuansu_s E_MofaYuansu_t;

	struct Sheet_MofaYuansu_s : public NFDescStoreSeqOP {
		Sheet_MofaYuansu_s();
		virtual ~Sheet_MofaYuansu_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaYuansu_s, DEFINE_SHEET_MOFAYUANSU_E_MOFAYUANSU_LIST_MAX_NUM> E_MofaYuansu_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaYuansu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaYuansu & msg);
		static ::proto_ff::Sheet_MofaYuansu* new_pbmsg(){ return new ::proto_ff::Sheet_MofaYuansu(); }
		static ::proto_ff::Sheet_MofaYuansu make_pbmsg(){ return ::proto_ff::Sheet_MofaYuansu(); }
	};
	typedef struct Sheet_MofaYuansu_s Sheet_MofaYuansu_t;

	struct E_MofaDecompose_s : public NFDescStoreSeqOP {
		E_MofaDecompose_s();
		virtual ~E_MofaDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Id;//id
		int32_t m_DpQua;//分解品质
		int32_t m_DpItem;//分解返还道具
		int32_t m_DpEss;//分解精华

		virtual void write_to_pbmsg(::proto_ff::E_MofaDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaDecompose & msg);
		static ::proto_ff::E_MofaDecompose* new_pbmsg(){ return new ::proto_ff::E_MofaDecompose(); }
		static ::proto_ff::E_MofaDecompose make_pbmsg(){ return ::proto_ff::E_MofaDecompose(); }
	};
	typedef struct E_MofaDecompose_s E_MofaDecompose_t;

	struct Sheet_MofaDecompose_s : public NFDescStoreSeqOP {
		Sheet_MofaDecompose_s();
		virtual ~Sheet_MofaDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaDecompose_s, DEFINE_SHEET_MOFADECOMPOSE_E_MOFADECOMPOSE_LIST_MAX_NUM> E_MofaDecompose_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaDecompose & msg);
		static ::proto_ff::Sheet_MofaDecompose* new_pbmsg(){ return new ::proto_ff::Sheet_MofaDecompose(); }
		static ::proto_ff::Sheet_MofaDecompose make_pbmsg(){ return ::proto_ff::Sheet_MofaDecompose(); }
	};
	typedef struct Sheet_MofaDecompose_s Sheet_MofaDecompose_t;

	struct E_MofaLvexp_s : public NFDescStoreSeqOP {
		E_MofaLvexp_s();
		virtual ~E_MofaLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_MofaLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaLvexp & msg);
		static ::proto_ff::E_MofaLvexp* new_pbmsg(){ return new ::proto_ff::E_MofaLvexp(); }
		static ::proto_ff::E_MofaLvexp make_pbmsg(){ return ::proto_ff::E_MofaLvexp(); }
	};
	typedef struct E_MofaLvexp_s E_MofaLvexp_t;

	struct Sheet_MofaLvexp_s : public NFDescStoreSeqOP {
		Sheet_MofaLvexp_s();
		virtual ~Sheet_MofaLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaLvexp_s, DEFINE_SHEET_MOFALVEXP_E_MOFALVEXP_LIST_MAX_NUM> E_MofaLvexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaLvexp & msg);
		static ::proto_ff::Sheet_MofaLvexp* new_pbmsg(){ return new ::proto_ff::Sheet_MofaLvexp(); }
		static ::proto_ff::Sheet_MofaLvexp make_pbmsg(){ return ::proto_ff::Sheet_MofaLvexp(); }
	};
	typedef struct Sheet_MofaLvexp_s Sheet_MofaLvexp_t;

	struct E_MofaLvatt_s : public NFDescStoreSeqOP {
		E_MofaLvatt_s();
		virtual ~E_MofaLvatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attId;//属性组id
		NFShmVector<int32_t, DEFINE_E_MOFALVATT_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_MofaLvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaLvatt & msg);
		static ::proto_ff::E_MofaLvatt* new_pbmsg(){ return new ::proto_ff::E_MofaLvatt(); }
		static ::proto_ff::E_MofaLvatt make_pbmsg(){ return ::proto_ff::E_MofaLvatt(); }
	};
	typedef struct E_MofaLvatt_s E_MofaLvatt_t;

	struct Sheet_MofaLvatt_s : public NFDescStoreSeqOP {
		Sheet_MofaLvatt_s();
		virtual ~Sheet_MofaLvatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaLvatt_s, DEFINE_SHEET_MOFALVATT_E_MOFALVATT_LIST_MAX_NUM> E_MofaLvatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaLvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaLvatt & msg);
		static ::proto_ff::Sheet_MofaLvatt* new_pbmsg(){ return new ::proto_ff::Sheet_MofaLvatt(); }
		static ::proto_ff::Sheet_MofaLvatt make_pbmsg(){ return ::proto_ff::Sheet_MofaLvatt(); }
	};
	typedef struct Sheet_MofaLvatt_s Sheet_MofaLvatt_t;

	struct E_MofaZyattZyDesc_s : public NFDescStoreSeqOP {
		E_MofaZyattZyDesc_s();
		virtual ~E_MofaZyattZyDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyattZyDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyattZyDesc & msg);
		static ::proto_ff::E_MofaZyattZyDesc* new_pbmsg(){ return new ::proto_ff::E_MofaZyattZyDesc(); }
		static ::proto_ff::E_MofaZyattZyDesc make_pbmsg(){ return ::proto_ff::E_MofaZyattZyDesc(); }
	};
	typedef struct E_MofaZyattZyDesc_s E_MofaZyattZyDesc_t;

	struct E_MofaZyatt_s : public NFDescStoreSeqOP {
		E_MofaZyatt_s();
		virtual ~E_MofaZyatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//排序
		int64_t m_AttID;//属性ID
		int32_t m_quality;//品质
		NFShmVector<struct E_MofaZyattZyDesc_s, DEFINE_E_MOFAZYATT_M_ZY_MAX_NUM> m_ZY;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyatt & msg);
		static ::proto_ff::E_MofaZyatt* new_pbmsg(){ return new ::proto_ff::E_MofaZyatt(); }
		static ::proto_ff::E_MofaZyatt make_pbmsg(){ return ::proto_ff::E_MofaZyatt(); }
	};
	typedef struct E_MofaZyatt_s E_MofaZyatt_t;

	struct Sheet_MofaZyatt_s : public NFDescStoreSeqOP {
		Sheet_MofaZyatt_s();
		virtual ~Sheet_MofaZyatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaZyatt_s, DEFINE_SHEET_MOFAZYATT_E_MOFAZYATT_LIST_MAX_NUM> E_MofaZyatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaZyatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaZyatt & msg);
		static ::proto_ff::Sheet_MofaZyatt* new_pbmsg(){ return new ::proto_ff::Sheet_MofaZyatt(); }
		static ::proto_ff::Sheet_MofaZyatt make_pbmsg(){ return ::proto_ff::Sheet_MofaZyatt(); }
	};
	typedef struct Sheet_MofaZyatt_s Sheet_MofaZyatt_t;

	struct E_MofaZyjxattZyjxDesc_s : public NFDescStoreSeqOP {
		E_MofaZyjxattZyjxDesc_s();
		virtual ~E_MofaZyjxattZyjxDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyjxattZyjxDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyjxattZyjxDesc & msg);
		static ::proto_ff::E_MofaZyjxattZyjxDesc* new_pbmsg(){ return new ::proto_ff::E_MofaZyjxattZyjxDesc(); }
		static ::proto_ff::E_MofaZyjxattZyjxDesc make_pbmsg(){ return ::proto_ff::E_MofaZyjxattZyjxDesc(); }
	};
	typedef struct E_MofaZyjxattZyjxDesc_s E_MofaZyjxattZyjxDesc_t;

	struct E_MofaZyjxatt_s : public NFDescStoreSeqOP {
		E_MofaZyjxatt_s();
		virtual ~E_MofaZyjxatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//排序
		int64_t m_AttID;//属性ID
		int32_t m_JxLv;//觉醒需求
		NFShmVector<struct E_MofaZyjxattZyjxDesc_s, DEFINE_E_MOFAZYJXATT_M_ZYJX_MAX_NUM> m_ZyJx;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyjxatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyjxatt & msg);
		static ::proto_ff::E_MofaZyjxatt* new_pbmsg(){ return new ::proto_ff::E_MofaZyjxatt(); }
		static ::proto_ff::E_MofaZyjxatt make_pbmsg(){ return ::proto_ff::E_MofaZyjxatt(); }
	};
	typedef struct E_MofaZyjxatt_s E_MofaZyjxatt_t;

	struct Sheet_MofaZyjxatt_s : public NFDescStoreSeqOP {
		Sheet_MofaZyjxatt_s();
		virtual ~Sheet_MofaZyjxatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaZyjxatt_s, DEFINE_SHEET_MOFAZYJXATT_E_MOFAZYJXATT_LIST_MAX_NUM> E_MofaZyjxatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaZyjxatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaZyjxatt & msg);
		static ::proto_ff::Sheet_MofaZyjxatt* new_pbmsg(){ return new ::proto_ff::Sheet_MofaZyjxatt(); }
		static ::proto_ff::Sheet_MofaZyjxatt make_pbmsg(){ return ::proto_ff::Sheet_MofaZyjxatt(); }
	};
	typedef struct Sheet_MofaZyjxatt_s Sheet_MofaZyjxatt_t;

	struct E_MofaZyjxzfattZyjxzfDesc_s : public NFDescStoreSeqOP {
		E_MofaZyjxzfattZyjxzfDesc_s();
		virtual ~E_MofaZyjxzfattZyjxzfDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyjxzfattZyjxzfDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyjxzfattZyjxzfDesc & msg);
		static ::proto_ff::E_MofaZyjxzfattZyjxzfDesc* new_pbmsg(){ return new ::proto_ff::E_MofaZyjxzfattZyjxzfDesc(); }
		static ::proto_ff::E_MofaZyjxzfattZyjxzfDesc make_pbmsg(){ return ::proto_ff::E_MofaZyjxzfattZyjxzfDesc(); }
	};
	typedef struct E_MofaZyjxzfattZyjxzfDesc_s E_MofaZyjxzfattZyjxzfDesc_t;

	struct E_MofaZyjxzfatt_s : public NFDescStoreSeqOP {
		E_MofaZyjxzfatt_s();
		virtual ~E_MofaZyjxzfatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//排序
		int64_t m_AttID;//属性ID
		int32_t m_JxLv;//觉醒需求
		NFShmVector<struct E_MofaZyjxzfattZyjxzfDesc_s, DEFINE_E_MOFAZYJXZFATT_M_ZYJXZF_MAX_NUM> m_ZyJxZf;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MofaZyjxzfatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaZyjxzfatt & msg);
		static ::proto_ff::E_MofaZyjxzfatt* new_pbmsg(){ return new ::proto_ff::E_MofaZyjxzfatt(); }
		static ::proto_ff::E_MofaZyjxzfatt make_pbmsg(){ return ::proto_ff::E_MofaZyjxzfatt(); }
	};
	typedef struct E_MofaZyjxzfatt_s E_MofaZyjxzfatt_t;

	struct Sheet_MofaZyjxzfatt_s : public NFDescStoreSeqOP {
		Sheet_MofaZyjxzfatt_s();
		virtual ~Sheet_MofaZyjxzfatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaZyjxzfatt_s, DEFINE_SHEET_MOFAZYJXZFATT_E_MOFAZYJXZFATT_LIST_MAX_NUM> E_MofaZyjxzfatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaZyjxzfatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaZyjxzfatt & msg);
		static ::proto_ff::Sheet_MofaZyjxzfatt* new_pbmsg(){ return new ::proto_ff::Sheet_MofaZyjxzfatt(); }
		static ::proto_ff::Sheet_MofaZyjxzfatt make_pbmsg(){ return ::proto_ff::Sheet_MofaZyjxzfatt(); }
	};
	typedef struct Sheet_MofaZyjxzfatt_s Sheet_MofaZyjxzfatt_t;

	struct E_MofaExchange_s : public NFDescStoreSeqOP {
		E_MofaExchange_s();
		virtual ~E_MofaExchange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ItemID;//道具ID
		int32_t m_quality;//品质
		int32_t m_EcItem;//兑换道具
		int32_t m_EcNum;//兑换道具数量

		virtual void write_to_pbmsg(::proto_ff::E_MofaExchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaExchange & msg);
		static ::proto_ff::E_MofaExchange* new_pbmsg(){ return new ::proto_ff::E_MofaExchange(); }
		static ::proto_ff::E_MofaExchange make_pbmsg(){ return ::proto_ff::E_MofaExchange(); }
	};
	typedef struct E_MofaExchange_s E_MofaExchange_t;

	struct Sheet_MofaExchange_s : public NFDescStoreSeqOP {
		Sheet_MofaExchange_s();
		virtual ~Sheet_MofaExchange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaExchange_s, DEFINE_SHEET_MOFAEXCHANGE_E_MOFAEXCHANGE_LIST_MAX_NUM> E_MofaExchange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaExchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaExchange & msg);
		static ::proto_ff::Sheet_MofaExchange* new_pbmsg(){ return new ::proto_ff::Sheet_MofaExchange(); }
		static ::proto_ff::Sheet_MofaExchange make_pbmsg(){ return ::proto_ff::Sheet_MofaExchange(); }
	};
	typedef struct Sheet_MofaExchange_s Sheet_MofaExchange_t;

	struct E_MofaName_s : public NFDescStoreSeqOP {
		E_MofaName_s();
		virtual ~E_MofaName_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionid;//功能id

		virtual void write_to_pbmsg(::proto_ff::E_MofaName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MofaName & msg);
		static ::proto_ff::E_MofaName* new_pbmsg(){ return new ::proto_ff::E_MofaName(); }
		static ::proto_ff::E_MofaName make_pbmsg(){ return ::proto_ff::E_MofaName(); }
	};
	typedef struct E_MofaName_s E_MofaName_t;

	struct Sheet_MofaName_s : public NFDescStoreSeqOP {
		Sheet_MofaName_s();
		virtual ~Sheet_MofaName_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MofaName_s, DEFINE_SHEET_MOFANAME_E_MOFANAME_LIST_MAX_NUM> E_MofaName_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MofaName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MofaName & msg);
		static ::proto_ff::Sheet_MofaName* new_pbmsg(){ return new ::proto_ff::Sheet_MofaName(); }
		static ::proto_ff::Sheet_MofaName make_pbmsg(){ return ::proto_ff::Sheet_MofaName(); }
	};
	typedef struct Sheet_MofaName_s Sheet_MofaName_t;

}

