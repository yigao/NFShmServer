#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Xingchen.pb.h"
#include "E_Xingchen_s.h"

#define DEFINE_SHEET_XINGCHENXCSETUP_E_XINGCHENXCSETUP_LIST_MAX_NUM 32
#define DEFINE_SHEET_XINGCHENXCMOSAIC_E_XINGCHENXCMOSAIC_LIST_MAX_NUM 16
#define DEFINE_E_XINGCHENXCMATERIAL_M_QUALITY_MAX_NUM 2
#define DEFINE_SHEET_XINGCHENXCMATERIAL_E_XINGCHENXCMATERIAL_LIST_MAX_NUM 8
#define DEFINE_E_XINGCHENXINCHEN_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_XINGCHENXINCHEN_E_XINGCHENXINCHEN_LIST_MAX_NUM 64
#define DEFINE_E_XINGCHENXCLVATT_M_ATT_MAX_NUM 100
#define DEFINE_SHEET_XINGCHENXCLVATT_E_XINGCHENXCLVATT_LIST_MAX_NUM 64
#define DEFINE_SHEET_XINGCHENXCLVEXP_E_XINGCHENXCLVEXP_LIST_MAX_NUM 128
#define DEFINE_E_XINGCHENXCTP_M_TP_MAX_NUM 2
#define DEFINE_E_XINGCHENXCTP_M_ATTR_MAX_NUM 20
#define DEFINE_SHEET_XINGCHENXCTP_E_XINGCHENXCTP_LIST_MAX_NUM 32
#define DEFINE_SHEET_XINGCHENXCTPEXP_E_XINGCHENXCTPEXP_LIST_MAX_NUM 32
#define DEFINE_SHEET_XINGCHENXCTPADDI_E_XINGCHENXCTPADDI_LIST_MAX_NUM 128
#define DEFINE_E_XINGCHENXCTPATT_M_ATT_MAX_NUM 16
#define DEFINE_SHEET_XINGCHENXCTPATT_E_XINGCHENXCTPATT_LIST_MAX_NUM 16
#define DEFINE_E_XINGCHENXCSTAR_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_XINGCHENXCSTAR_E_XINGCHENXCSTAR_LIST_MAX_NUM 16
#define DEFINE_E_XINGCHENXCAWAKEN_M_AWAKEN_MAX_NUM 3
#define DEFINE_SHEET_XINGCHENXCAWAKEN_E_XINGCHENXCAWAKEN_LIST_MAX_NUM 32
#define DEFINE_E_XINGCHENXCMAGICAL_M_HH_MAX_NUM 6
#define DEFINE_SHEET_XINGCHENXCMAGICAL_E_XINGCHENXCMAGICAL_LIST_MAX_NUM 32
#define DEFINE_E_XINGCHENXCMAGATT_M_ATT_MAX_NUM 11
#define DEFINE_SHEET_XINGCHENXCMAGATT_E_XINGCHENXCMAGATT_LIST_MAX_NUM 16
#define DEFINE_E_XINGCHENXCADVATT_M_UPATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_XINGCHENXCADVATT_E_XINGCHENXCADVATT_LIST_MAX_NUM 4
#define DEFINE_E_XINGCHENXCGUIZHEN_M_XX_MAX_NUM 8
#define DEFINE_E_XINGCHENXCGUIZHEN_M_GZ_MAX_NUM 8
#define DEFINE_SHEET_XINGCHENXCGUIZHEN_E_XINGCHENXCGUIZHEN_LIST_MAX_NUM 32
#define DEFINE_E_XINGCHENXINGJUN_M_ACT_MAX_NUM 4
#define DEFINE_SHEET_XINGCHENXINGJUN_E_XINGCHENXINGJUN_LIST_MAX_NUM 8
#define DEFINE_E_XINGCHENXJATT_M_XJ_MAX_NUM 5
#define DEFINE_SHEET_XINGCHENXJATT_E_XINGCHENXJATT_LIST_MAX_NUM 32
#define DEFINE_E_XINGCHENXINGJI_M_UNLOCK_MAX_NUM 3
#define DEFINE_E_XINGCHENXINGJI_M_UNLOCKLV_MAX_NUM 3
#define DEFINE_SHEET_XINGCHENXINGJI_E_XINGCHENXINGJI_LIST_MAX_NUM 64
#define DEFINE_SHEET_XINGCHENXJCW_E_XINGCHENXJCW_LIST_MAX_NUM 4
#define DEFINE_SHEET_XINGCHENXJLVEXP_E_XINGCHENXJLVEXP_LIST_MAX_NUM 32
#define DEFINE_SHEET_XINGCHENZBSHOP_E_XINGCHENZBSHOP_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_XingchenXcsetup_s : public NFDescStoreSeqOP {
		E_XingchenXcsetup_s();
		virtual ~E_XingchenXcsetup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_xsid;//星宿id
		int32_t m_unlockdj;//解锁条件天数
		int32_t m_unlockpf;//解锁条件评分
		int32_t m_xstype;//星宿类型
		int32_t m_xssubtype;//星宿子类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcsetup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcsetup & msg);
		static ::proto_ff::E_XingchenXcsetup* new_pbmsg(){ return new ::proto_ff::E_XingchenXcsetup(); }
		static ::proto_ff::E_XingchenXcsetup make_pbmsg(){ return ::proto_ff::E_XingchenXcsetup(); }
	};
	typedef struct E_XingchenXcsetup_s E_XingchenXcsetup_t;

	struct Sheet_XingchenXcsetup_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcsetup_s();
		virtual ~Sheet_XingchenXcsetup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcsetup_s, DEFINE_SHEET_XINGCHENXCSETUP_E_XINGCHENXCSETUP_LIST_MAX_NUM> E_XingchenXcsetup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcsetup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcsetup & msg);
		static ::proto_ff::Sheet_XingchenXcsetup* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcsetup(); }
		static ::proto_ff::Sheet_XingchenXcsetup make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcsetup(); }
	};
	typedef struct Sheet_XingchenXcsetup_s Sheet_XingchenXcsetup_t;

	struct E_XingchenXcmosaic_s : public NFDescStoreSeqOP {
		E_XingchenXcmosaic_s();
		virtual ~E_XingchenXcmosaic_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_positionnum;//部位序号
		int32_t m_positionid;//部位ID
		int32_t m_posx;//当前位置X
		int32_t m_posy;//当前位置Y
		int32_t m_next_posx;//下个位置X
		int32_t m_next_posy;//下个位置Y

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmosaic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmosaic & msg);
		static ::proto_ff::E_XingchenXcmosaic* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmosaic(); }
		static ::proto_ff::E_XingchenXcmosaic make_pbmsg(){ return ::proto_ff::E_XingchenXcmosaic(); }
	};
	typedef struct E_XingchenXcmosaic_s E_XingchenXcmosaic_t;

	struct Sheet_XingchenXcmosaic_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcmosaic_s();
		virtual ~Sheet_XingchenXcmosaic_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcmosaic_s, DEFINE_SHEET_XINGCHENXCMOSAIC_E_XINGCHENXCMOSAIC_LIST_MAX_NUM> E_XingchenXcmosaic_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcmosaic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmosaic & msg);
		static ::proto_ff::Sheet_XingchenXcmosaic* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcmosaic(); }
		static ::proto_ff::Sheet_XingchenXcmosaic make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcmosaic(); }
	};
	typedef struct Sheet_XingchenXcmosaic_s Sheet_XingchenXcmosaic_t;

	struct E_XingchenXcmaterialQualityDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcmaterialQualityDesc_s();
		virtual ~E_XingchenXcmaterialQualityDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmaterialQualityDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmaterialQualityDesc & msg);
		static ::proto_ff::E_XingchenXcmaterialQualityDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmaterialQualityDesc(); }
		static ::proto_ff::E_XingchenXcmaterialQualityDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcmaterialQualityDesc(); }
	};
	typedef struct E_XingchenXcmaterialQualityDesc_s E_XingchenXcmaterialQualityDesc_t;

	struct E_XingchenXcmaterial_s : public NFDescStoreSeqOP {
		E_XingchenXcmaterial_s();
		virtual ~E_XingchenXcmaterial_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_materialtype;//材料类型
		int32_t m_functiontype;//功能类型
		NFShmString<64> m_xcposition;//星辰位置
		int32_t m_itemid;//道具id
		int32_t m_itemexp;//道具经验值
		NFShmVector<struct E_XingchenXcmaterialQualityDesc_s, DEFINE_E_XINGCHENXCMATERIAL_M_QUALITY_MAX_NUM> m_quality;//品质

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmaterial & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmaterial & msg);
		static ::proto_ff::E_XingchenXcmaterial* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmaterial(); }
		static ::proto_ff::E_XingchenXcmaterial make_pbmsg(){ return ::proto_ff::E_XingchenXcmaterial(); }
	};
	typedef struct E_XingchenXcmaterial_s E_XingchenXcmaterial_t;

	struct Sheet_XingchenXcmaterial_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcmaterial_s();
		virtual ~Sheet_XingchenXcmaterial_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcmaterial_s, DEFINE_SHEET_XINGCHENXCMATERIAL_E_XINGCHENXCMATERIAL_LIST_MAX_NUM> E_XingchenXcmaterial_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcmaterial & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmaterial & msg);
		static ::proto_ff::Sheet_XingchenXcmaterial* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcmaterial(); }
		static ::proto_ff::Sheet_XingchenXcmaterial make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcmaterial(); }
	};
	typedef struct Sheet_XingchenXcmaterial_s Sheet_XingchenXcmaterial_t;

	struct E_XingchenXinchenAttributeDesc_s : public NFDescStoreSeqOP {
		E_XingchenXinchenAttributeDesc_s();
		virtual ~E_XingchenXinchenAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXinchenAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXinchenAttributeDesc & msg);
		static ::proto_ff::E_XingchenXinchenAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXinchenAttributeDesc(); }
		static ::proto_ff::E_XingchenXinchenAttributeDesc make_pbmsg(){ return ::proto_ff::E_XingchenXinchenAttributeDesc(); }
	};
	typedef struct E_XingchenXinchenAttributeDesc_s E_XingchenXinchenAttributeDesc_t;

	struct E_XingchenXinchen_s : public NFDescStoreSeqOP {
		E_XingchenXinchen_s();
		virtual ~E_XingchenXinchen_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_xcequip;//装备id
		NFShmVector<struct E_XingchenXinchenAttributeDesc_s, DEFINE_E_XINGCHENXINCHEN_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXinchen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXinchen & msg);
		static ::proto_ff::E_XingchenXinchen* new_pbmsg(){ return new ::proto_ff::E_XingchenXinchen(); }
		static ::proto_ff::E_XingchenXinchen make_pbmsg(){ return ::proto_ff::E_XingchenXinchen(); }
	};
	typedef struct E_XingchenXinchen_s E_XingchenXinchen_t;

	struct Sheet_XingchenXinchen_s : public NFDescStoreSeqOP {
		Sheet_XingchenXinchen_s();
		virtual ~Sheet_XingchenXinchen_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXinchen_s, DEFINE_SHEET_XINGCHENXINCHEN_E_XINGCHENXINCHEN_LIST_MAX_NUM> E_XingchenXinchen_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXinchen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXinchen & msg);
		static ::proto_ff::Sheet_XingchenXinchen* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXinchen(); }
		static ::proto_ff::Sheet_XingchenXinchen make_pbmsg(){ return ::proto_ff::Sheet_XingchenXinchen(); }
	};
	typedef struct Sheet_XingchenXinchen_s Sheet_XingchenXinchen_t;

	struct E_XingchenXclvatt_s : public NFDescStoreSeqOP {
		E_XingchenXclvatt_s();
		virtual ~E_XingchenXclvatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attid;//属性组id
		NFShmVector<int32_t, DEFINE_E_XINGCHENXCLVATT_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXclvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXclvatt & msg);
		static ::proto_ff::E_XingchenXclvatt* new_pbmsg(){ return new ::proto_ff::E_XingchenXclvatt(); }
		static ::proto_ff::E_XingchenXclvatt make_pbmsg(){ return ::proto_ff::E_XingchenXclvatt(); }
	};
	typedef struct E_XingchenXclvatt_s E_XingchenXclvatt_t;

	struct Sheet_XingchenXclvatt_s : public NFDescStoreSeqOP {
		Sheet_XingchenXclvatt_s();
		virtual ~Sheet_XingchenXclvatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXclvatt_s, DEFINE_SHEET_XINGCHENXCLVATT_E_XINGCHENXCLVATT_LIST_MAX_NUM> E_XingchenXclvatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXclvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXclvatt & msg);
		static ::proto_ff::Sheet_XingchenXclvatt* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXclvatt(); }
		static ::proto_ff::Sheet_XingchenXclvatt make_pbmsg(){ return ::proto_ff::Sheet_XingchenXclvatt(); }
	};
	typedef struct Sheet_XingchenXclvatt_s Sheet_XingchenXclvatt_t;

	struct E_XingchenXclvexp_s : public NFDescStoreSeqOP {
		E_XingchenXclvexp_s();
		virtual ~E_XingchenXclvexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXclvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXclvexp & msg);
		static ::proto_ff::E_XingchenXclvexp* new_pbmsg(){ return new ::proto_ff::E_XingchenXclvexp(); }
		static ::proto_ff::E_XingchenXclvexp make_pbmsg(){ return ::proto_ff::E_XingchenXclvexp(); }
	};
	typedef struct E_XingchenXclvexp_s E_XingchenXclvexp_t;

	struct Sheet_XingchenXclvexp_s : public NFDescStoreSeqOP {
		Sheet_XingchenXclvexp_s();
		virtual ~Sheet_XingchenXclvexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXclvexp_s, DEFINE_SHEET_XINGCHENXCLVEXP_E_XINGCHENXCLVEXP_LIST_MAX_NUM> E_XingchenXclvexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXclvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXclvexp & msg);
		static ::proto_ff::Sheet_XingchenXclvexp* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXclvexp(); }
		static ::proto_ff::Sheet_XingchenXclvexp make_pbmsg(){ return ::proto_ff::Sheet_XingchenXclvexp(); }
	};
	typedef struct Sheet_XingchenXclvexp_s Sheet_XingchenXclvexp_t;

	struct E_XingchenXctpTpDesc_s : public NFDescStoreSeqOP {
		E_XingchenXctpTpDesc_s();
		virtual ~E_XingchenXctpTpDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXctpTpDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXctpTpDesc & msg);
		static ::proto_ff::E_XingchenXctpTpDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXctpTpDesc(); }
		static ::proto_ff::E_XingchenXctpTpDesc make_pbmsg(){ return ::proto_ff::E_XingchenXctpTpDesc(); }
	};
	typedef struct E_XingchenXctpTpDesc_s E_XingchenXctpTpDesc_t;

	struct E_XingchenXctp_s : public NFDescStoreSeqOP {
		E_XingchenXctp_s();
		virtual ~E_XingchenXctp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_positionid;//部位ID
		int32_t m_xcquality;//星辰品质
		int32_t m_xclvmax;//突破上限
		NFShmVector<struct E_XingchenXctpTpDesc_s, DEFINE_E_XINGCHENXCTP_M_TP_MAX_NUM> m_tp;//属性
		NFShmVector<int32_t, DEFINE_E_XINGCHENXCTP_M_ATTR_MAX_NUM> m_attr;//突破属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXctp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXctp & msg);
		static ::proto_ff::E_XingchenXctp* new_pbmsg(){ return new ::proto_ff::E_XingchenXctp(); }
		static ::proto_ff::E_XingchenXctp make_pbmsg(){ return ::proto_ff::E_XingchenXctp(); }
	};
	typedef struct E_XingchenXctp_s E_XingchenXctp_t;

	struct Sheet_XingchenXctp_s : public NFDescStoreSeqOP {
		Sheet_XingchenXctp_s();
		virtual ~Sheet_XingchenXctp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXctp_s, DEFINE_SHEET_XINGCHENXCTP_E_XINGCHENXCTP_LIST_MAX_NUM> E_XingchenXctp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXctp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctp & msg);
		static ::proto_ff::Sheet_XingchenXctp* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXctp(); }
		static ::proto_ff::Sheet_XingchenXctp make_pbmsg(){ return ::proto_ff::Sheet_XingchenXctp(); }
	};
	typedef struct Sheet_XingchenXctp_s Sheet_XingchenXctp_t;

	struct E_XingchenXctpexp_s : public NFDescStoreSeqOP {
		E_XingchenXctpexp_s();
		virtual ~E_XingchenXctpexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//下个等级
		NFShmString<64> m_lvdisplay;//等级显示
		int32_t m_exp;//突破所需经验

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXctpexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXctpexp & msg);
		static ::proto_ff::E_XingchenXctpexp* new_pbmsg(){ return new ::proto_ff::E_XingchenXctpexp(); }
		static ::proto_ff::E_XingchenXctpexp make_pbmsg(){ return ::proto_ff::E_XingchenXctpexp(); }
	};
	typedef struct E_XingchenXctpexp_s E_XingchenXctpexp_t;

	struct Sheet_XingchenXctpexp_s : public NFDescStoreSeqOP {
		Sheet_XingchenXctpexp_s();
		virtual ~Sheet_XingchenXctpexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXctpexp_s, DEFINE_SHEET_XINGCHENXCTPEXP_E_XINGCHENXCTPEXP_LIST_MAX_NUM> E_XingchenXctpexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXctpexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpexp & msg);
		static ::proto_ff::Sheet_XingchenXctpexp* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXctpexp(); }
		static ::proto_ff::Sheet_XingchenXctpexp make_pbmsg(){ return ::proto_ff::Sheet_XingchenXctpexp(); }
	};
	typedef struct Sheet_XingchenXctpexp_s Sheet_XingchenXctpexp_t;

	struct E_XingchenXctpaddi_s : public NFDescStoreSeqOP {
		E_XingchenXctpaddi_s();
		virtual ~E_XingchenXctpaddi_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//属性组id
		int64_t m_attid;//属性id
		int32_t m_count;//计算方式
		int32_t m_atttype;//属性类型
		int32_t m_att;//属性突破

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXctpaddi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXctpaddi & msg);
		static ::proto_ff::E_XingchenXctpaddi* new_pbmsg(){ return new ::proto_ff::E_XingchenXctpaddi(); }
		static ::proto_ff::E_XingchenXctpaddi make_pbmsg(){ return ::proto_ff::E_XingchenXctpaddi(); }
	};
	typedef struct E_XingchenXctpaddi_s E_XingchenXctpaddi_t;

	struct Sheet_XingchenXctpaddi_s : public NFDescStoreSeqOP {
		Sheet_XingchenXctpaddi_s();
		virtual ~Sheet_XingchenXctpaddi_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXctpaddi_s, DEFINE_SHEET_XINGCHENXCTPADDI_E_XINGCHENXCTPADDI_LIST_MAX_NUM> E_XingchenXctpaddi_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXctpaddi & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpaddi & msg);
		static ::proto_ff::Sheet_XingchenXctpaddi* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXctpaddi(); }
		static ::proto_ff::Sheet_XingchenXctpaddi make_pbmsg(){ return ::proto_ff::Sheet_XingchenXctpaddi(); }
	};
	typedef struct Sheet_XingchenXctpaddi_s Sheet_XingchenXctpaddi_t;

	struct E_XingchenXctpatt_s : public NFDescStoreSeqOP {
		E_XingchenXctpatt_s();
		virtual ~E_XingchenXctpatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attid;//属性组id
		NFShmVector<int32_t, DEFINE_E_XINGCHENXCTPATT_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXctpatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXctpatt & msg);
		static ::proto_ff::E_XingchenXctpatt* new_pbmsg(){ return new ::proto_ff::E_XingchenXctpatt(); }
		static ::proto_ff::E_XingchenXctpatt make_pbmsg(){ return ::proto_ff::E_XingchenXctpatt(); }
	};
	typedef struct E_XingchenXctpatt_s E_XingchenXctpatt_t;

	struct Sheet_XingchenXctpatt_s : public NFDescStoreSeqOP {
		Sheet_XingchenXctpatt_s();
		virtual ~Sheet_XingchenXctpatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXctpatt_s, DEFINE_SHEET_XINGCHENXCTPATT_E_XINGCHENXCTPATT_LIST_MAX_NUM> E_XingchenXctpatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXctpatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpatt & msg);
		static ::proto_ff::Sheet_XingchenXctpatt* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXctpatt(); }
		static ::proto_ff::Sheet_XingchenXctpatt make_pbmsg(){ return ::proto_ff::Sheet_XingchenXctpatt(); }
	};
	typedef struct Sheet_XingchenXctpatt_s Sheet_XingchenXctpatt_t;

	struct E_XingchenXcstarAttributeDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcstarAttributeDesc_s();
		virtual ~E_XingchenXcstarAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcstarAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcstarAttributeDesc & msg);
		static ::proto_ff::E_XingchenXcstarAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcstarAttributeDesc(); }
		static ::proto_ff::E_XingchenXcstarAttributeDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcstarAttributeDesc(); }
	};
	typedef struct E_XingchenXcstarAttributeDesc_s E_XingchenXcstarAttributeDesc_t;

	struct E_XingchenXcstar_s : public NFDescStoreSeqOP {
		E_XingchenXcstar_s();
		virtual ~E_XingchenXcstar_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_starlv;//等级
		int32_t m_id;//星数
		NFShmVector<struct E_XingchenXcstarAttributeDesc_s, DEFINE_E_XINGCHENXCSTAR_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcstar & msg);
		static ::proto_ff::E_XingchenXcstar* new_pbmsg(){ return new ::proto_ff::E_XingchenXcstar(); }
		static ::proto_ff::E_XingchenXcstar make_pbmsg(){ return ::proto_ff::E_XingchenXcstar(); }
	};
	typedef struct E_XingchenXcstar_s E_XingchenXcstar_t;

	struct Sheet_XingchenXcstar_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcstar_s();
		virtual ~Sheet_XingchenXcstar_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcstar_s, DEFINE_SHEET_XINGCHENXCSTAR_E_XINGCHENXCSTAR_LIST_MAX_NUM> E_XingchenXcstar_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcstar & msg);
		static ::proto_ff::Sheet_XingchenXcstar* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcstar(); }
		static ::proto_ff::Sheet_XingchenXcstar make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcstar(); }
	};
	typedef struct Sheet_XingchenXcstar_s Sheet_XingchenXcstar_t;

	struct E_XingchenXcawakenAwakenDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcawakenAwakenDesc_s();
		virtual ~E_XingchenXcawakenAwakenDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_tpaddratio;//突破属性加成百分比
		int32_t m_lvaddratio;//升级属性加成百分比
		int32_t m_num;//材料数量

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcawakenAwakenDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcawakenAwakenDesc & msg);
		static ::proto_ff::E_XingchenXcawakenAwakenDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcawakenAwakenDesc(); }
		static ::proto_ff::E_XingchenXcawakenAwakenDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcawakenAwakenDesc(); }
	};
	typedef struct E_XingchenXcawakenAwakenDesc_s E_XingchenXcawakenAwakenDesc_t;

	struct E_XingchenXcawaken_s : public NFDescStoreSeqOP {
		E_XingchenXcawaken_s();
		virtual ~E_XingchenXcawaken_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_positionnum;//部位序号
		int32_t m_positionid;//部位ID
		int32_t m_awaken_quality;//品质
		int32_t m_awaken_lvmax;//觉醒上限
		int32_t m_awaken_item;//觉醒材料
		NFShmVector<struct E_XingchenXcawakenAwakenDesc_s, DEFINE_E_XINGCHENXCAWAKEN_M_AWAKEN_MAX_NUM> m_awaken;//觉醒

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcawaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcawaken & msg);
		static ::proto_ff::E_XingchenXcawaken* new_pbmsg(){ return new ::proto_ff::E_XingchenXcawaken(); }
		static ::proto_ff::E_XingchenXcawaken make_pbmsg(){ return ::proto_ff::E_XingchenXcawaken(); }
	};
	typedef struct E_XingchenXcawaken_s E_XingchenXcawaken_t;

	struct Sheet_XingchenXcawaken_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcawaken_s();
		virtual ~Sheet_XingchenXcawaken_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcawaken_s, DEFINE_SHEET_XINGCHENXCAWAKEN_E_XINGCHENXCAWAKEN_LIST_MAX_NUM> E_XingchenXcawaken_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcawaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcawaken & msg);
		static ::proto_ff::Sheet_XingchenXcawaken* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcawaken(); }
		static ::proto_ff::Sheet_XingchenXcawaken make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcawaken(); }
	};
	typedef struct Sheet_XingchenXcawaken_s Sheet_XingchenXcawaken_t;

	struct E_XingchenXcmagicalHhDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcmagicalHhDesc_s();
		virtual ~E_XingchenXcmagicalHhDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmagicalHhDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmagicalHhDesc & msg);
		static ::proto_ff::E_XingchenXcmagicalHhDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmagicalHhDesc(); }
		static ::proto_ff::E_XingchenXcmagicalHhDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcmagicalHhDesc(); }
	};
	typedef struct E_XingchenXcmagicalHhDesc_s E_XingchenXcmagicalHhDesc_t;

	struct E_XingchenXcmagical_s : public NFDescStoreSeqOP {
		E_XingchenXcmagical_s();
		virtual ~E_XingchenXcmagical_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_hhquality;//品质
		int32_t m_isadvanced;//是否可进阶
		int32_t m_hhact;//激活消耗
		int32_t m_hhstar;//升星消耗
		int32_t m_advskill;//进阶组
		NFShmVector<struct E_XingchenXcmagicalHhDesc_s, DEFINE_E_XINGCHENXCMAGICAL_M_HH_MAX_NUM> m_hh;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmagical & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmagical & msg);
		static ::proto_ff::E_XingchenXcmagical* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmagical(); }
		static ::proto_ff::E_XingchenXcmagical make_pbmsg(){ return ::proto_ff::E_XingchenXcmagical(); }
	};
	typedef struct E_XingchenXcmagical_s E_XingchenXcmagical_t;

	struct Sheet_XingchenXcmagical_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcmagical_s();
		virtual ~Sheet_XingchenXcmagical_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcmagical_s, DEFINE_SHEET_XINGCHENXCMAGICAL_E_XINGCHENXCMAGICAL_LIST_MAX_NUM> E_XingchenXcmagical_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcmagical & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmagical & msg);
		static ::proto_ff::Sheet_XingchenXcmagical* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcmagical(); }
		static ::proto_ff::Sheet_XingchenXcmagical make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcmagical(); }
	};
	typedef struct Sheet_XingchenXcmagical_s Sheet_XingchenXcmagical_t;

	struct E_XingchenXcmagatt_s : public NFDescStoreSeqOP {
		E_XingchenXcmagatt_s();
		virtual ~E_XingchenXcmagatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attid;//属性组id
		NFShmVector<int32_t, DEFINE_E_XINGCHENXCMAGATT_M_ATT_MAX_NUM> m_att;//属性等级

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcmagatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcmagatt & msg);
		static ::proto_ff::E_XingchenXcmagatt* new_pbmsg(){ return new ::proto_ff::E_XingchenXcmagatt(); }
		static ::proto_ff::E_XingchenXcmagatt make_pbmsg(){ return ::proto_ff::E_XingchenXcmagatt(); }
	};
	typedef struct E_XingchenXcmagatt_s E_XingchenXcmagatt_t;

	struct Sheet_XingchenXcmagatt_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcmagatt_s();
		virtual ~Sheet_XingchenXcmagatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcmagatt_s, DEFINE_SHEET_XINGCHENXCMAGATT_E_XINGCHENXCMAGATT_LIST_MAX_NUM> E_XingchenXcmagatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcmagatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmagatt & msg);
		static ::proto_ff::Sheet_XingchenXcmagatt* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcmagatt(); }
		static ::proto_ff::Sheet_XingchenXcmagatt make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcmagatt(); }
	};
	typedef struct Sheet_XingchenXcmagatt_s Sheet_XingchenXcmagatt_t;

	struct E_XingchenXcadvattUpattributeDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcadvattUpattributeDesc_s();
		virtual ~E_XingchenXcadvattUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcadvattUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcadvattUpattributeDesc & msg);
		static ::proto_ff::E_XingchenXcadvattUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcadvattUpattributeDesc(); }
		static ::proto_ff::E_XingchenXcadvattUpattributeDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcadvattUpattributeDesc(); }
	};
	typedef struct E_XingchenXcadvattUpattributeDesc_s E_XingchenXcadvattUpattributeDesc_t;

	struct E_XingchenXcadvatt_s : public NFDescStoreSeqOP {
		E_XingchenXcadvatt_s();
		virtual ~E_XingchenXcadvatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一ID
		int64_t m_upattributeid;//进阶属性组ID
		int32_t m_classlv;//阶级等级
		int32_t m_starid;//星级
		int32_t m_skillid;//技能id
		int32_t m_activeskillidlv;//技能等级
		NFShmVector<struct E_XingchenXcadvattUpattributeDesc_s, DEFINE_E_XINGCHENXCADVATT_M_UPATTRIBUTE_MAX_NUM> m_upattribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcadvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcadvatt & msg);
		static ::proto_ff::E_XingchenXcadvatt* new_pbmsg(){ return new ::proto_ff::E_XingchenXcadvatt(); }
		static ::proto_ff::E_XingchenXcadvatt make_pbmsg(){ return ::proto_ff::E_XingchenXcadvatt(); }
	};
	typedef struct E_XingchenXcadvatt_s E_XingchenXcadvatt_t;

	struct Sheet_XingchenXcadvatt_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcadvatt_s();
		virtual ~Sheet_XingchenXcadvatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcadvatt_s, DEFINE_SHEET_XINGCHENXCADVATT_E_XINGCHENXCADVATT_LIST_MAX_NUM> E_XingchenXcadvatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcadvatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcadvatt & msg);
		static ::proto_ff::Sheet_XingchenXcadvatt* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcadvatt(); }
		static ::proto_ff::Sheet_XingchenXcadvatt make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcadvatt(); }
	};
	typedef struct Sheet_XingchenXcadvatt_s Sheet_XingchenXcadvatt_t;

	struct E_XingchenXcguizhenXxDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcguizhenXxDesc_s();
		virtual ~E_XingchenXcguizhenXxDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcguizhenXxDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhenXxDesc & msg);
		static ::proto_ff::E_XingchenXcguizhenXxDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcguizhenXxDesc(); }
		static ::proto_ff::E_XingchenXcguizhenXxDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcguizhenXxDesc(); }
	};
	typedef struct E_XingchenXcguizhenXxDesc_s E_XingchenXcguizhenXxDesc_t;

	struct E_XingchenXcguizhenGzDesc_s : public NFDescStoreSeqOP {
		E_XingchenXcguizhenGzDesc_s();
		virtual ~E_XingchenXcguizhenGzDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcguizhenGzDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhenGzDesc & msg);
		static ::proto_ff::E_XingchenXcguizhenGzDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXcguizhenGzDesc(); }
		static ::proto_ff::E_XingchenXcguizhenGzDesc make_pbmsg(){ return ::proto_ff::E_XingchenXcguizhenGzDesc(); }
	};
	typedef struct E_XingchenXcguizhenGzDesc_s E_XingchenXcguizhenGzDesc_t;

	struct E_XingchenXcguizhen_s : public NFDescStoreSeqOP {
		E_XingchenXcguizhen_s();
		virtual ~E_XingchenXcguizhen_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_xsid;//星宿id
		int32_t m_gzquality;//激活所需品质
		int32_t m_gznum;//激活所需数量
		int32_t m_gzxh;//归真消耗
		NFShmVector<struct E_XingchenXcguizhenXxDesc_s, DEFINE_E_XINGCHENXCGUIZHEN_M_XX_MAX_NUM> m_xx;//属性
		NFShmVector<struct E_XingchenXcguizhenGzDesc_s, DEFINE_E_XINGCHENXCGUIZHEN_M_GZ_MAX_NUM> m_gz;//归真

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXcguizhen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhen & msg);
		static ::proto_ff::E_XingchenXcguizhen* new_pbmsg(){ return new ::proto_ff::E_XingchenXcguizhen(); }
		static ::proto_ff::E_XingchenXcguizhen make_pbmsg(){ return ::proto_ff::E_XingchenXcguizhen(); }
	};
	typedef struct E_XingchenXcguizhen_s E_XingchenXcguizhen_t;

	struct Sheet_XingchenXcguizhen_s : public NFDescStoreSeqOP {
		Sheet_XingchenXcguizhen_s();
		virtual ~Sheet_XingchenXcguizhen_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXcguizhen_s, DEFINE_SHEET_XINGCHENXCGUIZHEN_E_XINGCHENXCGUIZHEN_LIST_MAX_NUM> E_XingchenXcguizhen_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXcguizhen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcguizhen & msg);
		static ::proto_ff::Sheet_XingchenXcguizhen* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXcguizhen(); }
		static ::proto_ff::Sheet_XingchenXcguizhen make_pbmsg(){ return ::proto_ff::Sheet_XingchenXcguizhen(); }
	};
	typedef struct Sheet_XingchenXcguizhen_s Sheet_XingchenXcguizhen_t;

	struct E_XingchenXingjunActDesc_s : public NFDescStoreSeqOP {
		E_XingchenXingjunActDesc_s();
		virtual ~E_XingchenXingjunActDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_num;//所需数量

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXingjunActDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXingjunActDesc & msg);
		static ::proto_ff::E_XingchenXingjunActDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXingjunActDesc(); }
		static ::proto_ff::E_XingchenXingjunActDesc make_pbmsg(){ return ::proto_ff::E_XingchenXingjunActDesc(); }
	};
	typedef struct E_XingchenXingjunActDesc_s E_XingchenXingjunActDesc_t;

	struct E_XingchenXingjun_s : public NFDescStoreSeqOP {
		E_XingchenXingjun_s();
		virtual ~E_XingchenXingjun_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_xstype;//星宿类型
		int32_t m_xjquality;//激活所需品质
		NFShmVector<struct E_XingchenXingjunActDesc_s, DEFINE_E_XINGCHENXINGJUN_M_ACT_MAX_NUM> m_act;//激活

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXingjun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXingjun & msg);
		static ::proto_ff::E_XingchenXingjun* new_pbmsg(){ return new ::proto_ff::E_XingchenXingjun(); }
		static ::proto_ff::E_XingchenXingjun make_pbmsg(){ return ::proto_ff::E_XingchenXingjun(); }
	};
	typedef struct E_XingchenXingjun_s E_XingchenXingjun_t;

	struct Sheet_XingchenXingjun_s : public NFDescStoreSeqOP {
		Sheet_XingchenXingjun_s();
		virtual ~Sheet_XingchenXingjun_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXingjun_s, DEFINE_SHEET_XINGCHENXINGJUN_E_XINGCHENXINGJUN_LIST_MAX_NUM> E_XingchenXingjun_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXingjun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXingjun & msg);
		static ::proto_ff::Sheet_XingchenXingjun* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXingjun(); }
		static ::proto_ff::Sheet_XingchenXingjun make_pbmsg(){ return ::proto_ff::Sheet_XingchenXingjun(); }
	};
	typedef struct Sheet_XingchenXingjun_s Sheet_XingchenXingjun_t;

	struct E_XingchenXjattXjDesc_s : public NFDescStoreSeqOP {
		E_XingchenXjattXjDesc_s();
		virtual ~E_XingchenXjattXjDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXjattXjDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXjattXjDesc & msg);
		static ::proto_ff::E_XingchenXjattXjDesc* new_pbmsg(){ return new ::proto_ff::E_XingchenXjattXjDesc(); }
		static ::proto_ff::E_XingchenXjattXjDesc make_pbmsg(){ return ::proto_ff::E_XingchenXjattXjDesc(); }
	};
	typedef struct E_XingchenXjattXjDesc_s E_XingchenXjattXjDesc_t;

	struct E_XingchenXjatt_s : public NFDescStoreSeqOP {
		E_XingchenXjatt_s();
		virtual ~E_XingchenXjatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_attid;//属性组id
		NFShmVector<struct E_XingchenXjattXjDesc_s, DEFINE_E_XINGCHENXJATT_M_XJ_MAX_NUM> m_xj;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXjatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXjatt & msg);
		static ::proto_ff::E_XingchenXjatt* new_pbmsg(){ return new ::proto_ff::E_XingchenXjatt(); }
		static ::proto_ff::E_XingchenXjatt make_pbmsg(){ return ::proto_ff::E_XingchenXjatt(); }
	};
	typedef struct E_XingchenXjatt_s E_XingchenXjatt_t;

	struct Sheet_XingchenXjatt_s : public NFDescStoreSeqOP {
		Sheet_XingchenXjatt_s();
		virtual ~Sheet_XingchenXjatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXjatt_s, DEFINE_SHEET_XINGCHENXJATT_E_XINGCHENXJATT_LIST_MAX_NUM> E_XingchenXjatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXjatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjatt & msg);
		static ::proto_ff::Sheet_XingchenXjatt* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXjatt(); }
		static ::proto_ff::Sheet_XingchenXjatt make_pbmsg(){ return ::proto_ff::Sheet_XingchenXjatt(); }
	};
	typedef struct Sheet_XingchenXjatt_s Sheet_XingchenXjatt_t;

	struct E_XingchenXingji_s : public NFDescStoreSeqOP {
		E_XingchenXingji_s();
		virtual ~E_XingchenXingji_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_xjid;//id
		int32_t m_xjclass;//星技分类
		int32_t m_xjskill;//星技技能
		int32_t m_skillid;//技能id
		NFShmVector<int32_t, DEFINE_E_XINGCHENXINGJI_M_UNLOCK_MAX_NUM> m_unlock;//解锁条件
		NFShmVector<int32_t, DEFINE_E_XINGCHENXINGJI_M_UNLOCKLV_MAX_NUM> m_unlocklv;//解锁技能等级

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXingji & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXingji & msg);
		static ::proto_ff::E_XingchenXingji* new_pbmsg(){ return new ::proto_ff::E_XingchenXingji(); }
		static ::proto_ff::E_XingchenXingji make_pbmsg(){ return ::proto_ff::E_XingchenXingji(); }
	};
	typedef struct E_XingchenXingji_s E_XingchenXingji_t;

	struct Sheet_XingchenXingji_s : public NFDescStoreSeqOP {
		Sheet_XingchenXingji_s();
		virtual ~Sheet_XingchenXingji_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXingji_s, DEFINE_SHEET_XINGCHENXINGJI_E_XINGCHENXINGJI_LIST_MAX_NUM> E_XingchenXingji_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXingji & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXingji & msg);
		static ::proto_ff::Sheet_XingchenXingji* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXingji(); }
		static ::proto_ff::Sheet_XingchenXingji make_pbmsg(){ return ::proto_ff::Sheet_XingchenXingji(); }
	};
	typedef struct Sheet_XingchenXingji_s Sheet_XingchenXingji_t;

	struct E_XingchenXjcw_s : public NFDescStoreSeqOP {
		E_XingchenXjcw_s();
		virtual ~E_XingchenXjcw_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_xjslot;//星技槽位
		int32_t m_unlock;//解锁货币
		int32_t m_num;//消耗数量

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXjcw & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXjcw & msg);
		static ::proto_ff::E_XingchenXjcw* new_pbmsg(){ return new ::proto_ff::E_XingchenXjcw(); }
		static ::proto_ff::E_XingchenXjcw make_pbmsg(){ return ::proto_ff::E_XingchenXjcw(); }
	};
	typedef struct E_XingchenXjcw_s E_XingchenXjcw_t;

	struct Sheet_XingchenXjcw_s : public NFDescStoreSeqOP {
		Sheet_XingchenXjcw_s();
		virtual ~Sheet_XingchenXjcw_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXjcw_s, DEFINE_SHEET_XINGCHENXJCW_E_XINGCHENXJCW_LIST_MAX_NUM> E_XingchenXjcw_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXjcw & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjcw & msg);
		static ::proto_ff::Sheet_XingchenXjcw* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXjcw(); }
		static ::proto_ff::Sheet_XingchenXjcw make_pbmsg(){ return ::proto_ff::Sheet_XingchenXjcw(); }
	};
	typedef struct Sheet_XingchenXjcw_s Sheet_XingchenXjcw_t;

	struct E_XingchenXjlvexp_s : public NFDescStoreSeqOP {
		E_XingchenXjlvexp_s();
		virtual ~E_XingchenXjlvexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需货币
		int32_t m_time;//时间

		virtual void write_to_pbmsg(::proto_ff::E_XingchenXjlvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenXjlvexp & msg);
		static ::proto_ff::E_XingchenXjlvexp* new_pbmsg(){ return new ::proto_ff::E_XingchenXjlvexp(); }
		static ::proto_ff::E_XingchenXjlvexp make_pbmsg(){ return ::proto_ff::E_XingchenXjlvexp(); }
	};
	typedef struct E_XingchenXjlvexp_s E_XingchenXjlvexp_t;

	struct Sheet_XingchenXjlvexp_s : public NFDescStoreSeqOP {
		Sheet_XingchenXjlvexp_s();
		virtual ~Sheet_XingchenXjlvexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenXjlvexp_s, DEFINE_SHEET_XINGCHENXJLVEXP_E_XINGCHENXJLVEXP_LIST_MAX_NUM> E_XingchenXjlvexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenXjlvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjlvexp & msg);
		static ::proto_ff::Sheet_XingchenXjlvexp* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenXjlvexp(); }
		static ::proto_ff::Sheet_XingchenXjlvexp make_pbmsg(){ return ::proto_ff::Sheet_XingchenXjlvexp(); }
	};
	typedef struct Sheet_XingchenXjlvexp_s Sheet_XingchenXjlvexp_t;

	struct E_XingchenZbshop_s : public NFDescStoreSeqOP {
		E_XingchenZbshop_s();
		virtual ~E_XingchenZbshop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_shopid;//id
		int32_t m_shopitem;//物品ID
		int32_t m_shopquota;//限购
		int32_t m_shopnum;//可购买次数
		int32_t m_buyconsume;//消耗道具
		int32_t m_buynum;//消耗数量

		virtual void write_to_pbmsg(::proto_ff::E_XingchenZbshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XingchenZbshop & msg);
		static ::proto_ff::E_XingchenZbshop* new_pbmsg(){ return new ::proto_ff::E_XingchenZbshop(); }
		static ::proto_ff::E_XingchenZbshop make_pbmsg(){ return ::proto_ff::E_XingchenZbshop(); }
	};
	typedef struct E_XingchenZbshop_s E_XingchenZbshop_t;

	struct Sheet_XingchenZbshop_s : public NFDescStoreSeqOP {
		Sheet_XingchenZbshop_s();
		virtual ~Sheet_XingchenZbshop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XingchenZbshop_s, DEFINE_SHEET_XINGCHENZBSHOP_E_XINGCHENZBSHOP_LIST_MAX_NUM> E_XingchenZbshop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XingchenZbshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XingchenZbshop & msg);
		static ::proto_ff::Sheet_XingchenZbshop* new_pbmsg(){ return new ::proto_ff::Sheet_XingchenZbshop(); }
		static ::proto_ff::Sheet_XingchenZbshop make_pbmsg(){ return ::proto_ff::Sheet_XingchenZbshop(); }
	};
	typedef struct Sheet_XingchenZbshop_s Sheet_XingchenZbshop_t;

}

