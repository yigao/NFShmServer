#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Pk3v3.pb.h"
#include "E_Pk3v3_s.h"

#define DEFINE_SHEET_PK3V3LEVEL_E_PK3V3LEVEL_LIST_MAX_NUM 32
#define DEFINE_E_PK3V3REWARD_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_PK3V3REWARD_E_PK3V3REWARD_LIST_MAX_NUM 32
#define DEFINE_E_PK3V3BADGE_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_PK3V3BADGE_E_PK3V3BADGE_LIST_MAX_NUM 16
#define DEFINE_E_PK3V3CONSTANT_M_SHOWREWARD_MAX_NUM 3
#define DEFINE_SHEET_PK3V3CONSTANT_E_PK3V3CONSTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_PK3V3EXP_E_PK3V3EXP_LIST_MAX_NUM 1024


namespace proto_ff_s {

	struct E_Pk3v3Level_s : public NFDescStoreSeqOP {
		E_Pk3v3Level_s();
		virtual ~E_Pk3v3Level_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一id
		int32_t m_type;//段位类型
		NFShmString<64> m_name;//段位名称
		int32_t m_starnum;//星星数量
		int32_t m_scoring;//积分值
		NFShmString<64> m_badge;//段位徽章
		NFShmString<64> m_showbadge;//展示段位徽章
		int32_t m_scoringadd;//胜场积分奖励
		int32_t m_scoringcut;//负场积分扣除

		virtual void write_to_pbmsg(::proto_ff::E_Pk3v3Level & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk3v3Level & msg);
		static ::proto_ff::E_Pk3v3Level* new_pbmsg(){ return new ::proto_ff::E_Pk3v3Level(); }
		static ::proto_ff::E_Pk3v3Level make_pbmsg(){ return ::proto_ff::E_Pk3v3Level(); }
	};
	typedef struct E_Pk3v3Level_s E_Pk3v3Level_t;

	struct Sheet_Pk3v3Level_s : public NFDescStoreSeqOP {
		Sheet_Pk3v3Level_s();
		virtual ~Sheet_Pk3v3Level_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk3v3Level_s, DEFINE_SHEET_PK3V3LEVEL_E_PK3V3LEVEL_LIST_MAX_NUM> E_Pk3v3Level_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk3v3Level & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Level & msg);
		static ::proto_ff::Sheet_Pk3v3Level* new_pbmsg(){ return new ::proto_ff::Sheet_Pk3v3Level(); }
		static ::proto_ff::Sheet_Pk3v3Level make_pbmsg(){ return ::proto_ff::Sheet_Pk3v3Level(); }
	};
	typedef struct Sheet_Pk3v3Level_s Sheet_Pk3v3Level_t;

	struct E_Pk3v3Reward_s : public NFDescStoreSeqOP {
		E_Pk3v3Reward_s();
		virtual ~E_Pk3v3Reward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_type;//奖励类型
		int32_t m_condition;//领奖条件
		int64_t m_reward;//奖励ID
		NFShmVector<int32_t, DEFINE_E_PK3V3REWARD_M_PARAM_MAX_NUM> m_param;//参数

		virtual void write_to_pbmsg(::proto_ff::E_Pk3v3Reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk3v3Reward & msg);
		static ::proto_ff::E_Pk3v3Reward* new_pbmsg(){ return new ::proto_ff::E_Pk3v3Reward(); }
		static ::proto_ff::E_Pk3v3Reward make_pbmsg(){ return ::proto_ff::E_Pk3v3Reward(); }
	};
	typedef struct E_Pk3v3Reward_s E_Pk3v3Reward_t;

	struct Sheet_Pk3v3Reward_s : public NFDescStoreSeqOP {
		Sheet_Pk3v3Reward_s();
		virtual ~Sheet_Pk3v3Reward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk3v3Reward_s, DEFINE_SHEET_PK3V3REWARD_E_PK3V3REWARD_LIST_MAX_NUM> E_Pk3v3Reward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk3v3Reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Reward & msg);
		static ::proto_ff::Sheet_Pk3v3Reward* new_pbmsg(){ return new ::proto_ff::Sheet_Pk3v3Reward(); }
		static ::proto_ff::Sheet_Pk3v3Reward make_pbmsg(){ return ::proto_ff::Sheet_Pk3v3Reward(); }
	};
	typedef struct Sheet_Pk3v3Reward_s Sheet_Pk3v3Reward_t;

	struct E_Pk3v3Badge_s : public NFDescStoreSeqOP {
		E_Pk3v3Badge_s();
		virtual ~E_Pk3v3Badge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_name;//名称
		int32_t m_type;//条件类型
		NFShmVector<int32_t, DEFINE_E_PK3V3BADGE_M_PARAM_MAX_NUM> m_param;//参数

		virtual void write_to_pbmsg(::proto_ff::E_Pk3v3Badge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk3v3Badge & msg);
		static ::proto_ff::E_Pk3v3Badge* new_pbmsg(){ return new ::proto_ff::E_Pk3v3Badge(); }
		static ::proto_ff::E_Pk3v3Badge make_pbmsg(){ return ::proto_ff::E_Pk3v3Badge(); }
	};
	typedef struct E_Pk3v3Badge_s E_Pk3v3Badge_t;

	struct Sheet_Pk3v3Badge_s : public NFDescStoreSeqOP {
		Sheet_Pk3v3Badge_s();
		virtual ~Sheet_Pk3v3Badge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk3v3Badge_s, DEFINE_SHEET_PK3V3BADGE_E_PK3V3BADGE_LIST_MAX_NUM> E_Pk3v3Badge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk3v3Badge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Badge & msg);
		static ::proto_ff::Sheet_Pk3v3Badge* new_pbmsg(){ return new ::proto_ff::Sheet_Pk3v3Badge(); }
		static ::proto_ff::Sheet_Pk3v3Badge make_pbmsg(){ return ::proto_ff::Sheet_Pk3v3Badge(); }
	};
	typedef struct Sheet_Pk3v3Badge_s Sheet_Pk3v3Badge_t;

	struct E_Pk3v3Constant_s : public NFDescStoreSeqOP {
		E_Pk3v3Constant_s();
		virtual ~E_Pk3v3Constant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_teammember;//战队人数上限
		int32_t m_teamtoplimit;//战队上限
		int32_t m_cedetime;//转让队长时间
		int32_t m_punishtime;//离队惩罚时间
		int32_t m_breaktime;//战队解散时间
		int32_t m_entryreward;//参赛奖励
		int32_t m_entrtimes;//参赛获奖次数
		int32_t m_mvpreward;//mvp奖励
		int32_t m_mvptimes;//mvp奖励次数
		int32_t m_matchtime;//单场时间
		int32_t m_unitname;//修改战队名称
		int32_t m_unitcost;//修改花费数量
		int32_t m_initialzlid;//初始战令id
		NFShmString<64> m_initialzlname;//初始战令名称
		NFShmString<64> m_robotname;//机器人名称
		int32_t m_matetime;//匹配预计时间
		int32_t m_addtime;//匹配增量时间
		NFShmString<256> m_initialnotice;//初始公告
		NFShmVector<int32_t, DEFINE_E_PK3V3CONSTANT_M_SHOWREWARD_MAX_NUM> m_showreward;//展示奖励

		virtual void write_to_pbmsg(::proto_ff::E_Pk3v3Constant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk3v3Constant & msg);
		static ::proto_ff::E_Pk3v3Constant* new_pbmsg(){ return new ::proto_ff::E_Pk3v3Constant(); }
		static ::proto_ff::E_Pk3v3Constant make_pbmsg(){ return ::proto_ff::E_Pk3v3Constant(); }
	};
	typedef struct E_Pk3v3Constant_s E_Pk3v3Constant_t;

	struct Sheet_Pk3v3Constant_s : public NFDescStoreSeqOP {
		Sheet_Pk3v3Constant_s();
		virtual ~Sheet_Pk3v3Constant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk3v3Constant_s, DEFINE_SHEET_PK3V3CONSTANT_E_PK3V3CONSTANT_LIST_MAX_NUM> E_Pk3v3Constant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk3v3Constant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Constant & msg);
		static ::proto_ff::Sheet_Pk3v3Constant* new_pbmsg(){ return new ::proto_ff::Sheet_Pk3v3Constant(); }
		static ::proto_ff::Sheet_Pk3v3Constant make_pbmsg(){ return ::proto_ff::Sheet_Pk3v3Constant(); }
	};
	typedef struct Sheet_Pk3v3Constant_s Sheet_Pk3v3Constant_t;

	struct E_Pk3v3Exp_s : public NFDescStoreSeqOP {
		E_Pk3v3Exp_s();
		virtual ~E_Pk3v3Exp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_mateexp;//匹配经验

		virtual void write_to_pbmsg(::proto_ff::E_Pk3v3Exp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk3v3Exp & msg);
		static ::proto_ff::E_Pk3v3Exp* new_pbmsg(){ return new ::proto_ff::E_Pk3v3Exp(); }
		static ::proto_ff::E_Pk3v3Exp make_pbmsg(){ return ::proto_ff::E_Pk3v3Exp(); }
	};
	typedef struct E_Pk3v3Exp_s E_Pk3v3Exp_t;

	struct Sheet_Pk3v3Exp_s : public NFDescStoreSeqOP {
		Sheet_Pk3v3Exp_s();
		virtual ~Sheet_Pk3v3Exp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk3v3Exp_s, DEFINE_SHEET_PK3V3EXP_E_PK3V3EXP_LIST_MAX_NUM> E_Pk3v3Exp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk3v3Exp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Exp & msg);
		static ::proto_ff::Sheet_Pk3v3Exp* new_pbmsg(){ return new ::proto_ff::Sheet_Pk3v3Exp(); }
		static ::proto_ff::Sheet_Pk3v3Exp make_pbmsg(){ return ::proto_ff::Sheet_Pk3v3Exp(); }
	};
	typedef struct Sheet_Pk3v3Exp_s Sheet_Pk3v3Exp_t;

}

