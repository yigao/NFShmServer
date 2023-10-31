#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Vip.pb.h"
#include "E_Vip_s.h"

#define DEFINE_SHEET_VIPVIP_E_VIPVIP_LIST_MAX_NUM 16
#define DEFINE_SHEET_VIPPRIVILEGE_E_VIPPRIVILEGE_LIST_MAX_NUM 512
#define DEFINE_SHEET_VIPCHAT_E_VIPCHAT_LIST_MAX_NUM 16
#define DEFINE_SHEET_VIPCOSNTANT_E_VIPCOSNTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_VIPEXPLIMIT_E_VIPEXPLIMIT_LIST_MAX_NUM 2048


namespace proto_ff_s {

	struct E_VipVip_s : public NFDescStoreSeqOP {
		E_VipVip_s();
		virtual ~E_VipVip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_level;//vip等级
		int32_t m_exp;//经验值
		int32_t m_privilege_group;//特权组
		int32_t m_dailyBox;//每日福利奖励
		int32_t m_vipGift;//专属礼包box
		int32_t m_priceType;//专属礼包价格类型
		int32_t m_originalPrice;//专属礼包原价
		int32_t m_price;//专属礼包价格

		virtual void write_to_pbmsg(::proto_ff::E_VipVip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipVip & msg);
		static ::proto_ff::E_VipVip* new_pbmsg(){ return new ::proto_ff::E_VipVip(); }
		static ::proto_ff::E_VipVip make_pbmsg(){ return ::proto_ff::E_VipVip(); }
	};
	typedef struct E_VipVip_s E_VipVip_t;

	struct Sheet_VipVip_s : public NFDescStoreSeqOP {
		Sheet_VipVip_s();
		virtual ~Sheet_VipVip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipVip_s, DEFINE_SHEET_VIPVIP_E_VIPVIP_LIST_MAX_NUM> E_VipVip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipVip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipVip & msg);
		static ::proto_ff::Sheet_VipVip* new_pbmsg(){ return new ::proto_ff::Sheet_VipVip(); }
		static ::proto_ff::Sheet_VipVip make_pbmsg(){ return ::proto_ff::Sheet_VipVip(); }
	};
	typedef struct Sheet_VipVip_s Sheet_VipVip_t;

	struct E_VipPrivilege_s : public NFDescStoreSeqOP {
		E_VipPrivilege_s();
		virtual ~E_VipPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_group;//特权组
		int32_t m_type;//特权类型
		int32_t m_arg;//功能参数
		NFShmString<64> m_args;//整数功能参数

		virtual void write_to_pbmsg(::proto_ff::E_VipPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipPrivilege & msg);
		static ::proto_ff::E_VipPrivilege* new_pbmsg(){ return new ::proto_ff::E_VipPrivilege(); }
		static ::proto_ff::E_VipPrivilege make_pbmsg(){ return ::proto_ff::E_VipPrivilege(); }
	};
	typedef struct E_VipPrivilege_s E_VipPrivilege_t;

	struct Sheet_VipPrivilege_s : public NFDescStoreSeqOP {
		Sheet_VipPrivilege_s();
		virtual ~Sheet_VipPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipPrivilege_s, DEFINE_SHEET_VIPPRIVILEGE_E_VIPPRIVILEGE_LIST_MAX_NUM> E_VipPrivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipPrivilege & msg);
		static ::proto_ff::Sheet_VipPrivilege* new_pbmsg(){ return new ::proto_ff::Sheet_VipPrivilege(); }
		static ::proto_ff::Sheet_VipPrivilege make_pbmsg(){ return ::proto_ff::Sheet_VipPrivilege(); }
	};
	typedef struct Sheet_VipPrivilege_s Sheet_VipPrivilege_t;

	struct E_VipChat_s : public NFDescStoreSeqOP {
		E_VipChat_s();
		virtual ~E_VipChat_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_VipChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipChat & msg);
		static ::proto_ff::E_VipChat* new_pbmsg(){ return new ::proto_ff::E_VipChat(); }
		static ::proto_ff::E_VipChat make_pbmsg(){ return ::proto_ff::E_VipChat(); }
	};
	typedef struct E_VipChat_s E_VipChat_t;

	struct Sheet_VipChat_s : public NFDescStoreSeqOP {
		Sheet_VipChat_s();
		virtual ~Sheet_VipChat_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipChat_s, DEFINE_SHEET_VIPCHAT_E_VIPCHAT_LIST_MAX_NUM> E_VipChat_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipChat & msg);
		static ::proto_ff::Sheet_VipChat* new_pbmsg(){ return new ::proto_ff::Sheet_VipChat(); }
		static ::proto_ff::Sheet_VipChat make_pbmsg(){ return ::proto_ff::Sheet_VipChat(); }
	};
	typedef struct Sheet_VipChat_s Sheet_VipChat_t;

	struct E_VipCosntant_s : public NFDescStoreSeqOP {
		E_VipCosntant_s();
		virtual ~E_VipCosntant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_FVipPrice;//零元vip的价格
		int32_t m_FVipRtime;//零元vip的返还开服时间
		int32_t m_FVipPrivage;//零元VIP的特权
		int32_t m_Fviplv;//零元vip对应的vip等级
		int32_t m_Fvipexp;//获得的vip经验
		int32_t m_VipItemIcon;//vip道具图标
		int32_t m_foreverGuide;//永久玩法映射
		int32_t m_unActiveGuide;//临时玩法映射
		int32_t m_vipExp;//vip消费经验

		virtual void write_to_pbmsg(::proto_ff::E_VipCosntant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipCosntant & msg);
		static ::proto_ff::E_VipCosntant* new_pbmsg(){ return new ::proto_ff::E_VipCosntant(); }
		static ::proto_ff::E_VipCosntant make_pbmsg(){ return ::proto_ff::E_VipCosntant(); }
	};
	typedef struct E_VipCosntant_s E_VipCosntant_t;

	struct Sheet_VipCosntant_s : public NFDescStoreSeqOP {
		Sheet_VipCosntant_s();
		virtual ~Sheet_VipCosntant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipCosntant_s, DEFINE_SHEET_VIPCOSNTANT_E_VIPCOSNTANT_LIST_MAX_NUM> E_VipCosntant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipCosntant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipCosntant & msg);
		static ::proto_ff::Sheet_VipCosntant* new_pbmsg(){ return new ::proto_ff::Sheet_VipCosntant(); }
		static ::proto_ff::Sheet_VipCosntant make_pbmsg(){ return ::proto_ff::Sheet_VipCosntant(); }
	};
	typedef struct Sheet_VipCosntant_s Sheet_VipCosntant_t;

	struct E_VipExplimit_s : public NFDescStoreSeqOP {
		E_VipExplimit_s();
		virtual ~E_VipExplimit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int64_t m_limit;//经验上限

		virtual void write_to_pbmsg(::proto_ff::E_VipExplimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipExplimit & msg);
		static ::proto_ff::E_VipExplimit* new_pbmsg(){ return new ::proto_ff::E_VipExplimit(); }
		static ::proto_ff::E_VipExplimit make_pbmsg(){ return ::proto_ff::E_VipExplimit(); }
	};
	typedef struct E_VipExplimit_s E_VipExplimit_t;

	struct Sheet_VipExplimit_s : public NFDescStoreSeqOP {
		Sheet_VipExplimit_s();
		virtual ~Sheet_VipExplimit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipExplimit_s, DEFINE_SHEET_VIPEXPLIMIT_E_VIPEXPLIMIT_LIST_MAX_NUM> E_VipExplimit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipExplimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipExplimit & msg);
		static ::proto_ff::Sheet_VipExplimit* new_pbmsg(){ return new ::proto_ff::Sheet_VipExplimit(); }
		static ::proto_ff::Sheet_VipExplimit make_pbmsg(){ return ::proto_ff::Sheet_VipExplimit(); }
	};
	typedef struct Sheet_VipExplimit_s Sheet_VipExplimit_t;

}

