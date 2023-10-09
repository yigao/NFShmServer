#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Dragonsoul.pb.h"
#include "E_Dragonsoul_s.h"

#define DEFINE_SHEET_DRAGONSOULHOLE_E_DRAGONSOULHOLE_LIST_MAX_NUM 16
#define DEFINE_E_DRAGONSOULOFFEREXP_M_QUALITY_MAX_NUM 2
#define DEFINE_SHEET_DRAGONSOULOFFEREXP_E_DRAGONSOULOFFEREXP_LIST_MAX_NUM 4
#define DEFINE_SHEET_DRAGONSOULSTRONGEXP_E_DRAGONSOULSTRONGEXP_LIST_MAX_NUM 2048
#define DEFINE_SHEET_DRAGONSOULFLYEXP_E_DRAGONSOULFLYEXP_LIST_MAX_NUM 64
#define DEFINE_E_DRAGONSOULFLYATT_M_ATT_MAX_NUM 11
#define DEFINE_SHEET_DRAGONSOULFLYATT_E_DRAGONSOULFLYATT_LIST_MAX_NUM 128
#define DEFINE_E_DRAGONSOULFLY_M_TYPE_MAX_NUM 2
#define DEFINE_E_DRAGONSOULFLY_M_FLYATT_MAX_NUM 32
#define DEFINE_SHEET_DRAGONSOULFLY_E_DRAGONSOULFLY_LIST_MAX_NUM 32
#define DEFINE_E_DRAGONSOULAWAKE_M_AWAKE_MAX_NUM 11
#define DEFINE_SHEET_DRAGONSOULAWAKE_E_DRAGONSOULAWAKE_LIST_MAX_NUM 16
#define DEFINE_SHEET_DRAGONSOULNAME_E_DRAGONSOULNAME_LIST_MAX_NUM 8
#define DEFINE_E_DRAGONSOULSTARCOLLECT_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_DRAGONSOULSTARCOLLECT_E_DRAGONSOULSTARCOLLECT_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_DragonsoulHole_s : public NFDescStoreSeqOP {
		E_DragonsoulHole_s();
		virtual ~E_DragonsoulHole_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_number;//激活个数
		int32_t m_type;//孔的类型
		NFShmString<64> m_position;//装备位置
		int32_t m_lv;//激活等级
		int64_t m_id;//激活道具id
		int32_t m_num;//激活道具数量

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulHole & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulHole & msg);
		static ::proto_ff::E_DragonsoulHole* new_pbmsg(){ return new ::proto_ff::E_DragonsoulHole(); }
		static ::proto_ff::E_DragonsoulHole make_pbmsg(){ return ::proto_ff::E_DragonsoulHole(); }
	};
	typedef struct E_DragonsoulHole_s E_DragonsoulHole_t;

	struct Sheet_DragonsoulHole_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulHole_s();
		virtual ~Sheet_DragonsoulHole_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulHole_s, DEFINE_SHEET_DRAGONSOULHOLE_E_DRAGONSOULHOLE_LIST_MAX_NUM> E_DragonsoulHole_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulHole & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulHole & msg);
		static ::proto_ff::Sheet_DragonsoulHole* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulHole(); }
		static ::proto_ff::Sheet_DragonsoulHole make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulHole(); }
	};
	typedef struct Sheet_DragonsoulHole_s Sheet_DragonsoulHole_t;

	struct E_DragonsoulOfferexpQualityDesc_s : public NFDescStoreSeqOP {
		E_DragonsoulOfferexpQualityDesc_s();
		virtual ~E_DragonsoulOfferexpQualityDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulOfferexpQualityDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulOfferexpQualityDesc & msg);
		static ::proto_ff::E_DragonsoulOfferexpQualityDesc* new_pbmsg(){ return new ::proto_ff::E_DragonsoulOfferexpQualityDesc(); }
		static ::proto_ff::E_DragonsoulOfferexpQualityDesc make_pbmsg(){ return ::proto_ff::E_DragonsoulOfferexpQualityDesc(); }
	};
	typedef struct E_DragonsoulOfferexpQualityDesc_s E_DragonsoulOfferexpQualityDesc_t;

	struct E_DragonsoulOfferexp_s : public NFDescStoreSeqOP {
		E_DragonsoulOfferexp_s();
		virtual ~E_DragonsoulOfferexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//材料类型
		NFShmString<64> m_position;//装备位置
		int32_t m_itemid;//道具id
		int32_t m_itemexp;//道具经验值
		NFShmVector<struct E_DragonsoulOfferexpQualityDesc_s, DEFINE_E_DRAGONSOULOFFEREXP_M_QUALITY_MAX_NUM> m_quality;//品质

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulOfferexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulOfferexp & msg);
		static ::proto_ff::E_DragonsoulOfferexp* new_pbmsg(){ return new ::proto_ff::E_DragonsoulOfferexp(); }
		static ::proto_ff::E_DragonsoulOfferexp make_pbmsg(){ return ::proto_ff::E_DragonsoulOfferexp(); }
	};
	typedef struct E_DragonsoulOfferexp_s E_DragonsoulOfferexp_t;

	struct Sheet_DragonsoulOfferexp_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulOfferexp_s();
		virtual ~Sheet_DragonsoulOfferexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulOfferexp_s, DEFINE_SHEET_DRAGONSOULOFFEREXP_E_DRAGONSOULOFFEREXP_LIST_MAX_NUM> E_DragonsoulOfferexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulOfferexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulOfferexp & msg);
		static ::proto_ff::Sheet_DragonsoulOfferexp* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulOfferexp(); }
		static ::proto_ff::Sheet_DragonsoulOfferexp make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulOfferexp(); }
	};
	typedef struct Sheet_DragonsoulOfferexp_s Sheet_DragonsoulOfferexp_t;

	struct E_DragonsoulStrongexp_s : public NFDescStoreSeqOP {
		E_DragonsoulStrongexp_s();
		virtual ~E_DragonsoulStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulStrongexp & msg);
		static ::proto_ff::E_DragonsoulStrongexp* new_pbmsg(){ return new ::proto_ff::E_DragonsoulStrongexp(); }
		static ::proto_ff::E_DragonsoulStrongexp make_pbmsg(){ return ::proto_ff::E_DragonsoulStrongexp(); }
	};
	typedef struct E_DragonsoulStrongexp_s E_DragonsoulStrongexp_t;

	struct Sheet_DragonsoulStrongexp_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulStrongexp_s();
		virtual ~Sheet_DragonsoulStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulStrongexp_s, DEFINE_SHEET_DRAGONSOULSTRONGEXP_E_DRAGONSOULSTRONGEXP_LIST_MAX_NUM> E_DragonsoulStrongexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulStrongexp & msg);
		static ::proto_ff::Sheet_DragonsoulStrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulStrongexp(); }
		static ::proto_ff::Sheet_DragonsoulStrongexp make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulStrongexp(); }
	};
	typedef struct Sheet_DragonsoulStrongexp_s Sheet_DragonsoulStrongexp_t;

	struct E_DragonsoulFlyexp_s : public NFDescStoreSeqOP {
		E_DragonsoulFlyexp_s();
		virtual ~E_DragonsoulFlyexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//阶级
		int32_t m_exp;//升级所需经验

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulFlyexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyexp & msg);
		static ::proto_ff::E_DragonsoulFlyexp* new_pbmsg(){ return new ::proto_ff::E_DragonsoulFlyexp(); }
		static ::proto_ff::E_DragonsoulFlyexp make_pbmsg(){ return ::proto_ff::E_DragonsoulFlyexp(); }
	};
	typedef struct E_DragonsoulFlyexp_s E_DragonsoulFlyexp_t;

	struct Sheet_DragonsoulFlyexp_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulFlyexp_s();
		virtual ~Sheet_DragonsoulFlyexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulFlyexp_s, DEFINE_SHEET_DRAGONSOULFLYEXP_E_DRAGONSOULFLYEXP_LIST_MAX_NUM> E_DragonsoulFlyexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulFlyexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFlyexp & msg);
		static ::proto_ff::Sheet_DragonsoulFlyexp* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulFlyexp(); }
		static ::proto_ff::Sheet_DragonsoulFlyexp make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulFlyexp(); }
	};
	typedef struct Sheet_DragonsoulFlyexp_s Sheet_DragonsoulFlyexp_t;

	struct E_DragonsoulFlyatt_s : public NFDescStoreSeqOP {
		E_DragonsoulFlyatt_s();
		virtual ~E_DragonsoulFlyatt_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//属性组id
		int64_t m_attid;//属性id
		int32_t m_count;//计算方式
		int32_t m_atttype;//属性类型
		NFShmVector<int32_t, DEFINE_E_DRAGONSOULFLYATT_M_ATT_MAX_NUM> m_att;//属性觉醒

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulFlyatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyatt & msg);
		static ::proto_ff::E_DragonsoulFlyatt* new_pbmsg(){ return new ::proto_ff::E_DragonsoulFlyatt(); }
		static ::proto_ff::E_DragonsoulFlyatt make_pbmsg(){ return ::proto_ff::E_DragonsoulFlyatt(); }
	};
	typedef struct E_DragonsoulFlyatt_s E_DragonsoulFlyatt_t;

	struct Sheet_DragonsoulFlyatt_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulFlyatt_s();
		virtual ~Sheet_DragonsoulFlyatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulFlyatt_s, DEFINE_SHEET_DRAGONSOULFLYATT_E_DRAGONSOULFLYATT_LIST_MAX_NUM> E_DragonsoulFlyatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulFlyatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFlyatt & msg);
		static ::proto_ff::Sheet_DragonsoulFlyatt* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulFlyatt(); }
		static ::proto_ff::Sheet_DragonsoulFlyatt make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulFlyatt(); }
	};
	typedef struct Sheet_DragonsoulFlyatt_s Sheet_DragonsoulFlyatt_t;

	struct E_DragonsoulFlyTypeDesc_s : public NFDescStoreSeqOP {
		E_DragonsoulFlyTypeDesc_s();
		virtual ~E_DragonsoulFlyTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulFlyTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyTypeDesc & msg);
		static ::proto_ff::E_DragonsoulFlyTypeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonsoulFlyTypeDesc(); }
		static ::proto_ff::E_DragonsoulFlyTypeDesc make_pbmsg(){ return ::proto_ff::E_DragonsoulFlyTypeDesc(); }
	};
	typedef struct E_DragonsoulFlyTypeDesc_s E_DragonsoulFlyTypeDesc_t;

	struct E_DragonsoulFly_s : public NFDescStoreSeqOP {
		E_DragonsoulFly_s();
		virtual ~E_DragonsoulFly_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//部位ID
		int32_t m_position;//装备部位
		int32_t m_offerexp;//提供经验值
		int32_t m_quality;//装备品质
		int32_t m_srtongup;//强化上限
		NFShmVector<struct E_DragonsoulFlyTypeDesc_s, DEFINE_E_DRAGONSOULFLY_M_TYPE_MAX_NUM> m_type;//属性
		NFShmVector<int32_t, DEFINE_E_DRAGONSOULFLY_M_FLYATT_MAX_NUM> m_flyatt;//飞升属性

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulFly & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulFly & msg);
		static ::proto_ff::E_DragonsoulFly* new_pbmsg(){ return new ::proto_ff::E_DragonsoulFly(); }
		static ::proto_ff::E_DragonsoulFly make_pbmsg(){ return ::proto_ff::E_DragonsoulFly(); }
	};
	typedef struct E_DragonsoulFly_s E_DragonsoulFly_t;

	struct Sheet_DragonsoulFly_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulFly_s();
		virtual ~Sheet_DragonsoulFly_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulFly_s, DEFINE_SHEET_DRAGONSOULFLY_E_DRAGONSOULFLY_LIST_MAX_NUM> E_DragonsoulFly_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulFly & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFly & msg);
		static ::proto_ff::Sheet_DragonsoulFly* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulFly(); }
		static ::proto_ff::Sheet_DragonsoulFly make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulFly(); }
	};
	typedef struct Sheet_DragonsoulFly_s Sheet_DragonsoulFly_t;

	struct E_DragonsoulAwakeAwakeDesc_s : public NFDescStoreSeqOP {
		E_DragonsoulAwakeAwakeDesc_s();
		virtual ~E_DragonsoulAwakeAwakeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_flyaddratio;//飞升属性加成百分比
		int32_t m_lvaddratio;//升级属性加成百分比
		int32_t m_value;//属性值
		int32_t m_att;//属性ID
		int32_t m_num;//材料数量

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulAwakeAwakeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulAwakeAwakeDesc & msg);
		static ::proto_ff::E_DragonsoulAwakeAwakeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonsoulAwakeAwakeDesc(); }
		static ::proto_ff::E_DragonsoulAwakeAwakeDesc make_pbmsg(){ return ::proto_ff::E_DragonsoulAwakeAwakeDesc(); }
	};
	typedef struct E_DragonsoulAwakeAwakeDesc_s E_DragonsoulAwakeAwakeDesc_t;

	struct E_DragonsoulAwake_s : public NFDescStoreSeqOP {
		E_DragonsoulAwake_s();
		virtual ~E_DragonsoulAwake_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//装备部位
		int32_t m_awakeitem;//觉醒材料
		int32_t m_awaketoplimit;//觉醒上限
		NFShmVector<struct E_DragonsoulAwakeAwakeDesc_s, DEFINE_E_DRAGONSOULAWAKE_M_AWAKE_MAX_NUM> m_awake;//觉醒

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulAwake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulAwake & msg);
		static ::proto_ff::E_DragonsoulAwake* new_pbmsg(){ return new ::proto_ff::E_DragonsoulAwake(); }
		static ::proto_ff::E_DragonsoulAwake make_pbmsg(){ return ::proto_ff::E_DragonsoulAwake(); }
	};
	typedef struct E_DragonsoulAwake_s E_DragonsoulAwake_t;

	struct Sheet_DragonsoulAwake_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulAwake_s();
		virtual ~Sheet_DragonsoulAwake_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulAwake_s, DEFINE_SHEET_DRAGONSOULAWAKE_E_DRAGONSOULAWAKE_LIST_MAX_NUM> E_DragonsoulAwake_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulAwake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulAwake & msg);
		static ::proto_ff::Sheet_DragonsoulAwake* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulAwake(); }
		static ::proto_ff::Sheet_DragonsoulAwake make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulAwake(); }
	};
	typedef struct Sheet_DragonsoulAwake_s Sheet_DragonsoulAwake_t;

	struct E_DragonsoulName_s : public NFDescStoreSeqOP {
		E_DragonsoulName_s();
		virtual ~E_DragonsoulName_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionid;//功能id

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulName & msg);
		static ::proto_ff::E_DragonsoulName* new_pbmsg(){ return new ::proto_ff::E_DragonsoulName(); }
		static ::proto_ff::E_DragonsoulName make_pbmsg(){ return ::proto_ff::E_DragonsoulName(); }
	};
	typedef struct E_DragonsoulName_s E_DragonsoulName_t;

	struct Sheet_DragonsoulName_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulName_s();
		virtual ~Sheet_DragonsoulName_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulName_s, DEFINE_SHEET_DRAGONSOULNAME_E_DRAGONSOULNAME_LIST_MAX_NUM> E_DragonsoulName_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulName & msg);
		static ::proto_ff::Sheet_DragonsoulName* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulName(); }
		static ::proto_ff::Sheet_DragonsoulName make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulName(); }
	};
	typedef struct Sheet_DragonsoulName_s Sheet_DragonsoulName_t;

	struct E_DragonsoulStarcollectAttributeDesc_s : public NFDescStoreSeqOP {
		E_DragonsoulStarcollectAttributeDesc_s();
		virtual ~E_DragonsoulStarcollectAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulStarcollectAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulStarcollectAttributeDesc & msg);
		static ::proto_ff::E_DragonsoulStarcollectAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DragonsoulStarcollectAttributeDesc(); }
		static ::proto_ff::E_DragonsoulStarcollectAttributeDesc make_pbmsg(){ return ::proto_ff::E_DragonsoulStarcollectAttributeDesc(); }
	};
	typedef struct E_DragonsoulStarcollectAttributeDesc_s E_DragonsoulStarcollectAttributeDesc_t;

	struct E_DragonsoulStarcollect_s : public NFDescStoreSeqOP {
		E_DragonsoulStarcollect_s();
		virtual ~E_DragonsoulStarcollect_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//星数
		NFShmVector<struct E_DragonsoulStarcollectAttributeDesc_s, DEFINE_E_DRAGONSOULSTARCOLLECT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_DragonsoulStarcollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DragonsoulStarcollect & msg);
		static ::proto_ff::E_DragonsoulStarcollect* new_pbmsg(){ return new ::proto_ff::E_DragonsoulStarcollect(); }
		static ::proto_ff::E_DragonsoulStarcollect make_pbmsg(){ return ::proto_ff::E_DragonsoulStarcollect(); }
	};
	typedef struct E_DragonsoulStarcollect_s E_DragonsoulStarcollect_t;

	struct Sheet_DragonsoulStarcollect_s : public NFDescStoreSeqOP {
		Sheet_DragonsoulStarcollect_s();
		virtual ~Sheet_DragonsoulStarcollect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DragonsoulStarcollect_s, DEFINE_SHEET_DRAGONSOULSTARCOLLECT_E_DRAGONSOULSTARCOLLECT_LIST_MAX_NUM> E_DragonsoulStarcollect_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DragonsoulStarcollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulStarcollect & msg);
		static ::proto_ff::Sheet_DragonsoulStarcollect* new_pbmsg(){ return new ::proto_ff::Sheet_DragonsoulStarcollect(); }
		static ::proto_ff::Sheet_DragonsoulStarcollect make_pbmsg(){ return ::proto_ff::Sheet_DragonsoulStarcollect(); }
	};
	typedef struct Sheet_DragonsoulStarcollect_s Sheet_DragonsoulStarcollect_t;

}

