#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Tianxiafirst.pb.h"
#include "E_Tianxiafirst_s.h"

#define DEFINE_E_TIANXIAFIRSTCONSTANT_M_GROUP_MAX_NUM 4
#define DEFINE_SHEET_TIANXIAFIRSTCONSTANT_E_TIANXIAFIRSTCONSTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_TIANXIAFIRSTBATTLE_E_TIANXIAFIRSTBATTLE_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTARTIFACT_M_ATT_MAX_NUM 5
#define DEFINE_SHEET_TIANXIAFIRSTARTIFACT_E_TIANXIAFIRSTARTIFACT_LIST_MAX_NUM 4
#define DEFINE_E_TIANXIAFIRSTSTRONG_M_TYPE_MAX_NUM 5
#define DEFINE_SHEET_TIANXIAFIRSTSTRONG_E_TIANXIAFIRSTSTRONG_LIST_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTSTRONGITEM_E_TIANXIAFIRSTSTRONGITEM_LIST_MAX_NUM 4
#define DEFINE_E_TIANXIAFIRSTREFINE_M_ATT_MAX_NUM 5
#define DEFINE_SHEET_TIANXIAFIRSTREFINE_E_TIANXIAFIRSTREFINE_LIST_MAX_NUM 128
#define DEFINE_SHEET_TIANXIAFIRSTSQSKILL_E_TIANXIAFIRSTSQSKILL_LIST_MAX_NUM 64
#define DEFINE_SHEET_TIANXIAFIRSTGRADE_E_TIANXIAFIRSTGRADE_LIST_MAX_NUM 32
#define DEFINE_E_TIANXIAFIRSTGRADEREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTGRADEREWARD_E_TIANXIAFIRSTGRADEREWARD_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTRANKREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTRANKREWARD_E_TIANXIAFIRSTRANKREWARD_LIST_MAX_NUM 32
#define DEFINE_E_TIANXIAFIRSTWATCHREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTWATCHREWARD_E_TIANXIAFIRSTWATCHREWARD_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTLUCKYREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTLUCKYREWARD_E_TIANXIAFIRSTLUCKYREWARD_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTMATCHTIMESREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTMATCHTIMESREWARD_E_TIANXIAFIRSTMATCHTIMESREWARD_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTMATCHRESULTREWARD_M_REWARD_MAX_NUM 8
#define DEFINE_SHEET_TIANXIAFIRSTMATCHRESULTREWARD_E_TIANXIAFIRSTMATCHRESULTREWARD_LIST_MAX_NUM 8
#define DEFINE_E_TIANXIAFIRSTEXTRAADDATTR_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_TIANXIAFIRSTEXTRAADDATTR_E_TIANXIAFIRSTEXTRAADDATTR_LIST_MAX_NUM 64
#define DEFINE_E_TIANXIAFIRSTFIRSTADDATTR_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_TIANXIAFIRSTFIRSTADDATTR_E_TIANXIAFIRSTFIRSTADDATTR_LIST_MAX_NUM 2
#define DEFINE_SHEET_TIANXIAFIRSTSHOP_E_TIANXIAFIRSTSHOP_LIST_MAX_NUM 16
#define DEFINE_SHEET_TIANXIAFIRSTDANMAKU_E_TIANXIAFIRSTDANMAKU_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_TianxiafirstConstant_s : public NFDescStoreSeqOP {
		E_TianxiafirstConstant_s();
		virtual ~E_TianxiafirstConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_teamMember;//战队人数上限
		int32_t m_cedeTime;//转让队长次数
		int32_t m_punishTime;//离队惩罚时间
		int32_t m_breakTime;//战队解散时间
		int32_t m_unitName;//修改战队名称
		int32_t m_unitCost;//修改花费数量
		int32_t m_entrTimes;//积分赛参赛获奖次数
		int32_t m_mvpReward;//积分赛mvp奖励
		int32_t m_matchTime;//积分赛单场时间
		int32_t m_autoMatchTime;//积分赛自动匹配时间
		int32_t m_endTipsTime;//积分赛结束提示时间
		int32_t m_readyTime;//争夺赛准备时间
		int32_t m_summonItem;//召唤分身货币
		int32_t m_summonNum;//召唤分身货币数量
		int32_t m_showReward;//展示奖励
		NFShmString<64> m_robotName;//机器人名称
		int32_t m_mateTime;//匹配预计时间
		int32_t m_addTime;//匹配增量时间
		NFShmString<256> m_initialNotice;//初始公告
		int32_t m_freeTime;//免费供奉次数
		int32_t m_expendItem;//供奉消耗道具
		int32_t m_addServe;//供奉增加供奉值
		int32_t m_serveTitle;//供奉称号所需值
		int32_t m_guessLimit;//单个战团最大竞猜积分
		NFShmString<64> m_exchangeRatio;//积分兑换比例
		NFShmVector<NFShmString<64>, DEFINE_E_TIANXIAFIRSTCONSTANT_M_GROUP_MAX_NUM> m_group;//小组队伍

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstConstant & msg);
		static ::proto_ff::E_TianxiafirstConstant* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstConstant(); }
		static ::proto_ff::E_TianxiafirstConstant make_pbmsg(){ return ::proto_ff::E_TianxiafirstConstant(); }
	};
	typedef struct E_TianxiafirstConstant_s E_TianxiafirstConstant_t;

	struct Sheet_TianxiafirstConstant_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstConstant_s();
		virtual ~Sheet_TianxiafirstConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstConstant_s, DEFINE_SHEET_TIANXIAFIRSTCONSTANT_E_TIANXIAFIRSTCONSTANT_LIST_MAX_NUM> E_TianxiafirstConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstConstant & msg);
		static ::proto_ff::Sheet_TianxiafirstConstant* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstConstant(); }
		static ::proto_ff::Sheet_TianxiafirstConstant make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstConstant(); }
	};
	typedef struct Sheet_TianxiafirstConstant_s Sheet_TianxiafirstConstant_t;

	struct E_TianxiafirstBattle_s : public NFDescStoreSeqOP {
		E_TianxiafirstBattle_s();
		virtual ~E_TianxiafirstBattle_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_gamemod;//比赛模式
		int32_t m_matchTime;//单场时间
		int32_t m_revive;//复活次数

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstBattle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstBattle & msg);
		static ::proto_ff::E_TianxiafirstBattle* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstBattle(); }
		static ::proto_ff::E_TianxiafirstBattle make_pbmsg(){ return ::proto_ff::E_TianxiafirstBattle(); }
	};
	typedef struct E_TianxiafirstBattle_s E_TianxiafirstBattle_t;

	struct Sheet_TianxiafirstBattle_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstBattle_s();
		virtual ~Sheet_TianxiafirstBattle_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstBattle_s, DEFINE_SHEET_TIANXIAFIRSTBATTLE_E_TIANXIAFIRSTBATTLE_LIST_MAX_NUM> E_TianxiafirstBattle_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstBattle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstBattle & msg);
		static ::proto_ff::Sheet_TianxiafirstBattle* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstBattle(); }
		static ::proto_ff::Sheet_TianxiafirstBattle make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstBattle(); }
	};
	typedef struct Sheet_TianxiafirstBattle_s Sheet_TianxiafirstBattle_t;

	struct E_TianxiafirstArtifactAttDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstArtifactAttDesc_s();
		virtual ~E_TianxiafirstArtifactAttDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstArtifactAttDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstArtifactAttDesc & msg);
		static ::proto_ff::E_TianxiafirstArtifactAttDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstArtifactAttDesc(); }
		static ::proto_ff::E_TianxiafirstArtifactAttDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstArtifactAttDesc(); }
	};
	typedef struct E_TianxiafirstArtifactAttDesc_s E_TianxiafirstArtifactAttDesc_t;

	struct E_TianxiafirstArtifact_s : public NFDescStoreSeqOP {
		E_TianxiafirstArtifact_s();
		virtual ~E_TianxiafirstArtifact_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_artifactId;//神器id
		int32_t m_preId;//激活条件-前置id
		int32_t m_condition;//激活条件
		NFShmVector<struct E_TianxiafirstArtifactAttDesc_s, DEFINE_E_TIANXIAFIRSTARTIFACT_M_ATT_MAX_NUM> m_att;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstArtifact & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstArtifact & msg);
		static ::proto_ff::E_TianxiafirstArtifact* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstArtifact(); }
		static ::proto_ff::E_TianxiafirstArtifact make_pbmsg(){ return ::proto_ff::E_TianxiafirstArtifact(); }
	};
	typedef struct E_TianxiafirstArtifact_s E_TianxiafirstArtifact_t;

	struct Sheet_TianxiafirstArtifact_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstArtifact_s();
		virtual ~Sheet_TianxiafirstArtifact_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstArtifact_s, DEFINE_SHEET_TIANXIAFIRSTARTIFACT_E_TIANXIAFIRSTARTIFACT_LIST_MAX_NUM> E_TianxiafirstArtifact_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstArtifact & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstArtifact & msg);
		static ::proto_ff::Sheet_TianxiafirstArtifact* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstArtifact(); }
		static ::proto_ff::Sheet_TianxiafirstArtifact make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstArtifact(); }
	};
	typedef struct Sheet_TianxiafirstArtifact_s Sheet_TianxiafirstArtifact_t;

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

	struct E_TianxiafirstSqskill_s : public NFDescStoreSeqOP {
		E_TianxiafirstSqskill_s();
		virtual ~E_TianxiafirstSqskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_artifactId;//神器id
		int32_t m_skillId;//技能id
		int32_t m_level;//技能等级
		int32_t m_condition;//激活/升级条件
		int32_t m_score;//技能评分

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstSqskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstSqskill & msg);
		static ::proto_ff::E_TianxiafirstSqskill* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstSqskill(); }
		static ::proto_ff::E_TianxiafirstSqskill make_pbmsg(){ return ::proto_ff::E_TianxiafirstSqskill(); }
	};
	typedef struct E_TianxiafirstSqskill_s E_TianxiafirstSqskill_t;

	struct Sheet_TianxiafirstSqskill_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstSqskill_s();
		virtual ~Sheet_TianxiafirstSqskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstSqskill_s, DEFINE_SHEET_TIANXIAFIRSTSQSKILL_E_TIANXIAFIRSTSQSKILL_LIST_MAX_NUM> E_TianxiafirstSqskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstSqskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstSqskill & msg);
		static ::proto_ff::Sheet_TianxiafirstSqskill* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstSqskill(); }
		static ::proto_ff::Sheet_TianxiafirstSqskill make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstSqskill(); }
	};
	typedef struct Sheet_TianxiafirstSqskill_s Sheet_TianxiafirstSqskill_t;

	struct E_TianxiafirstGrade_s : public NFDescStoreSeqOP {
		E_TianxiafirstGrade_s();
		virtual ~E_TianxiafirstGrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一id
		int32_t m_grade;//段位类型
		NFShmString<64> m_name;//段位名称
		int32_t m_star;//星星数量
		int32_t m_score;//积分值
		int32_t m_scoreAdd;//胜场积分奖励
		int32_t m_scoringSub;//负场积分扣除
		int32_t m_Time;//跨池时间
		int32_t m_downLimit;//最小匹配段位
		int32_t m_upLimit;//最大匹配段位
		int32_t m_substituteTime;//机器人补位时间

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstGrade & msg);
		static ::proto_ff::E_TianxiafirstGrade* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstGrade(); }
		static ::proto_ff::E_TianxiafirstGrade make_pbmsg(){ return ::proto_ff::E_TianxiafirstGrade(); }
	};
	typedef struct E_TianxiafirstGrade_s E_TianxiafirstGrade_t;

	struct Sheet_TianxiafirstGrade_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstGrade_s();
		virtual ~Sheet_TianxiafirstGrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstGrade_s, DEFINE_SHEET_TIANXIAFIRSTGRADE_E_TIANXIAFIRSTGRADE_LIST_MAX_NUM> E_TianxiafirstGrade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstGrade & msg);
		static ::proto_ff::Sheet_TianxiafirstGrade* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstGrade(); }
		static ::proto_ff::Sheet_TianxiafirstGrade make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstGrade(); }
	};
	typedef struct Sheet_TianxiafirstGrade_s Sheet_TianxiafirstGrade_t;

	struct E_TianxiafirstGraderewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstGraderewardRewardDesc_s();
		virtual ~E_TianxiafirstGraderewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstGraderewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstGraderewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstGraderewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstGraderewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstGraderewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstGraderewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstGraderewardRewardDesc_s E_TianxiafirstGraderewardRewardDesc_t;

	struct E_TianxiafirstGradereward_s : public NFDescStoreSeqOP {
		E_TianxiafirstGradereward_s();
		virtual ~E_TianxiafirstGradereward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_scoreMin;//需要的积分
		int32_t m_matchTimes;//参赛场次
		NFShmVector<struct E_TianxiafirstGraderewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTGRADEREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstGradereward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstGradereward & msg);
		static ::proto_ff::E_TianxiafirstGradereward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstGradereward(); }
		static ::proto_ff::E_TianxiafirstGradereward make_pbmsg(){ return ::proto_ff::E_TianxiafirstGradereward(); }
	};
	typedef struct E_TianxiafirstGradereward_s E_TianxiafirstGradereward_t;

	struct Sheet_TianxiafirstGradereward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstGradereward_s();
		virtual ~Sheet_TianxiafirstGradereward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstGradereward_s, DEFINE_SHEET_TIANXIAFIRSTGRADEREWARD_E_TIANXIAFIRSTGRADEREWARD_LIST_MAX_NUM> E_TianxiafirstGradereward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstGradereward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstGradereward & msg);
		static ::proto_ff::Sheet_TianxiafirstGradereward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstGradereward(); }
		static ::proto_ff::Sheet_TianxiafirstGradereward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstGradereward(); }
	};
	typedef struct Sheet_TianxiafirstGradereward_s Sheet_TianxiafirstGradereward_t;

	struct E_TianxiafirstRankrewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstRankrewardRewardDesc_s();
		virtual ~E_TianxiafirstRankrewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstRankrewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstRankrewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstRankrewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstRankrewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstRankrewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstRankrewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstRankrewardRewardDesc_s E_TianxiafirstRankrewardRewardDesc_t;

	struct E_TianxiafirstRankreward_s : public NFDescStoreSeqOP {
		E_TianxiafirstRankreward_s();
		virtual ~E_TianxiafirstRankreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_rank;//排名
		NFShmVector<struct E_TianxiafirstRankrewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTRANKREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstRankreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstRankreward & msg);
		static ::proto_ff::E_TianxiafirstRankreward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstRankreward(); }
		static ::proto_ff::E_TianxiafirstRankreward make_pbmsg(){ return ::proto_ff::E_TianxiafirstRankreward(); }
	};
	typedef struct E_TianxiafirstRankreward_s E_TianxiafirstRankreward_t;

	struct Sheet_TianxiafirstRankreward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstRankreward_s();
		virtual ~Sheet_TianxiafirstRankreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstRankreward_s, DEFINE_SHEET_TIANXIAFIRSTRANKREWARD_E_TIANXIAFIRSTRANKREWARD_LIST_MAX_NUM> E_TianxiafirstRankreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstRankreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstRankreward & msg);
		static ::proto_ff::Sheet_TianxiafirstRankreward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstRankreward(); }
		static ::proto_ff::Sheet_TianxiafirstRankreward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstRankreward(); }
	};
	typedef struct Sheet_TianxiafirstRankreward_s Sheet_TianxiafirstRankreward_t;

	struct E_TianxiafirstWatchrewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstWatchrewardRewardDesc_s();
		virtual ~E_TianxiafirstWatchrewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstWatchrewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstWatchrewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstWatchrewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstWatchrewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstWatchrewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstWatchrewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstWatchrewardRewardDesc_s E_TianxiafirstWatchrewardRewardDesc_t;

	struct E_TianxiafirstWatchreward_s : public NFDescStoreSeqOP {
		E_TianxiafirstWatchreward_s();
		virtual ~E_TianxiafirstWatchreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_matchState;//比赛阶段
		NFShmVector<struct E_TianxiafirstWatchrewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTWATCHREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstWatchreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstWatchreward & msg);
		static ::proto_ff::E_TianxiafirstWatchreward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstWatchreward(); }
		static ::proto_ff::E_TianxiafirstWatchreward make_pbmsg(){ return ::proto_ff::E_TianxiafirstWatchreward(); }
	};
	typedef struct E_TianxiafirstWatchreward_s E_TianxiafirstWatchreward_t;

	struct Sheet_TianxiafirstWatchreward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstWatchreward_s();
		virtual ~Sheet_TianxiafirstWatchreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstWatchreward_s, DEFINE_SHEET_TIANXIAFIRSTWATCHREWARD_E_TIANXIAFIRSTWATCHREWARD_LIST_MAX_NUM> E_TianxiafirstWatchreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstWatchreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstWatchreward & msg);
		static ::proto_ff::Sheet_TianxiafirstWatchreward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstWatchreward(); }
		static ::proto_ff::Sheet_TianxiafirstWatchreward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstWatchreward(); }
	};
	typedef struct Sheet_TianxiafirstWatchreward_s Sheet_TianxiafirstWatchreward_t;

	struct E_TianxiafirstLuckyrewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstLuckyrewardRewardDesc_s();
		virtual ~E_TianxiafirstLuckyrewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstLuckyrewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstLuckyrewardRewardDesc_s E_TianxiafirstLuckyrewardRewardDesc_t;

	struct E_TianxiafirstLuckyreward_s : public NFDescStoreSeqOP {
		E_TianxiafirstLuckyreward_s();
		virtual ~E_TianxiafirstLuckyreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_numMin;//最小抽奖人数
		int32_t m_numMax;//最大抽奖人数
		NFShmVector<struct E_TianxiafirstLuckyrewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTLUCKYREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstLuckyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstLuckyreward & msg);
		static ::proto_ff::E_TianxiafirstLuckyreward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstLuckyreward(); }
		static ::proto_ff::E_TianxiafirstLuckyreward make_pbmsg(){ return ::proto_ff::E_TianxiafirstLuckyreward(); }
	};
	typedef struct E_TianxiafirstLuckyreward_s E_TianxiafirstLuckyreward_t;

	struct Sheet_TianxiafirstLuckyreward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstLuckyreward_s();
		virtual ~Sheet_TianxiafirstLuckyreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstLuckyreward_s, DEFINE_SHEET_TIANXIAFIRSTLUCKYREWARD_E_TIANXIAFIRSTLUCKYREWARD_LIST_MAX_NUM> E_TianxiafirstLuckyreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstLuckyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstLuckyreward & msg);
		static ::proto_ff::Sheet_TianxiafirstLuckyreward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstLuckyreward(); }
		static ::proto_ff::Sheet_TianxiafirstLuckyreward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstLuckyreward(); }
	};
	typedef struct Sheet_TianxiafirstLuckyreward_s Sheet_TianxiafirstLuckyreward_t;

	struct E_TianxiafirstMatchtimesrewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstMatchtimesrewardRewardDesc_s();
		virtual ~E_TianxiafirstMatchtimesrewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstMatchtimesrewardRewardDesc_s E_TianxiafirstMatchtimesrewardRewardDesc_t;

	struct E_TianxiafirstMatchtimesreward_s : public NFDescStoreSeqOP {
		E_TianxiafirstMatchtimesreward_s();
		virtual ~E_TianxiafirstMatchtimesreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_matchTimes;//参与比赛次数
		NFShmVector<struct E_TianxiafirstMatchtimesrewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTMATCHTIMESREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstMatchtimesreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchtimesreward & msg);
		static ::proto_ff::E_TianxiafirstMatchtimesreward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstMatchtimesreward(); }
		static ::proto_ff::E_TianxiafirstMatchtimesreward make_pbmsg(){ return ::proto_ff::E_TianxiafirstMatchtimesreward(); }
	};
	typedef struct E_TianxiafirstMatchtimesreward_s E_TianxiafirstMatchtimesreward_t;

	struct Sheet_TianxiafirstMatchtimesreward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstMatchtimesreward_s();
		virtual ~Sheet_TianxiafirstMatchtimesreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstMatchtimesreward_s, DEFINE_SHEET_TIANXIAFIRSTMATCHTIMESREWARD_E_TIANXIAFIRSTMATCHTIMESREWARD_LIST_MAX_NUM> E_TianxiafirstMatchtimesreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstMatchtimesreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstMatchtimesreward & msg);
		static ::proto_ff::Sheet_TianxiafirstMatchtimesreward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstMatchtimesreward(); }
		static ::proto_ff::Sheet_TianxiafirstMatchtimesreward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstMatchtimesreward(); }
	};
	typedef struct Sheet_TianxiafirstMatchtimesreward_s Sheet_TianxiafirstMatchtimesreward_t;

	struct E_TianxiafirstMatchresultrewardRewardDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstMatchresultrewardRewardDesc_s();
		virtual ~E_TianxiafirstMatchresultrewardRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_ID;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc & msg);
		static ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc(); }
		static ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc(); }
	};
	typedef struct E_TianxiafirstMatchresultrewardRewardDesc_s E_TianxiafirstMatchresultrewardRewardDesc_t;

	struct E_TianxiafirstMatchresultreward_s : public NFDescStoreSeqOP {
		E_TianxiafirstMatchresultreward_s();
		virtual ~E_TianxiafirstMatchresultreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_matchState;//比赛阶段
		int32_t m_result;//比赛结果
		NFShmVector<struct E_TianxiafirstMatchresultrewardRewardDesc_s, DEFINE_E_TIANXIAFIRSTMATCHRESULTREWARD_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstMatchresultreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchresultreward & msg);
		static ::proto_ff::E_TianxiafirstMatchresultreward* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstMatchresultreward(); }
		static ::proto_ff::E_TianxiafirstMatchresultreward make_pbmsg(){ return ::proto_ff::E_TianxiafirstMatchresultreward(); }
	};
	typedef struct E_TianxiafirstMatchresultreward_s E_TianxiafirstMatchresultreward_t;

	struct Sheet_TianxiafirstMatchresultreward_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstMatchresultreward_s();
		virtual ~Sheet_TianxiafirstMatchresultreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstMatchresultreward_s, DEFINE_SHEET_TIANXIAFIRSTMATCHRESULTREWARD_E_TIANXIAFIRSTMATCHRESULTREWARD_LIST_MAX_NUM> E_TianxiafirstMatchresultreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstMatchresultreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstMatchresultreward & msg);
		static ::proto_ff::Sheet_TianxiafirstMatchresultreward* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstMatchresultreward(); }
		static ::proto_ff::Sheet_TianxiafirstMatchresultreward make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstMatchresultreward(); }
	};
	typedef struct Sheet_TianxiafirstMatchresultreward_s Sheet_TianxiafirstMatchresultreward_t;

	struct E_TianxiafirstExtraaddattrAttributeDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstExtraaddattrAttributeDesc_s();
		virtual ~E_TianxiafirstExtraaddattrAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc & msg);
		static ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc(); }
		static ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc(); }
	};
	typedef struct E_TianxiafirstExtraaddattrAttributeDesc_s E_TianxiafirstExtraaddattrAttributeDesc_t;

	struct E_TianxiafirstExtraaddattr_s : public NFDescStoreSeqOP {
		E_TianxiafirstExtraaddattr_s();
		virtual ~E_TianxiafirstExtraaddattr_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_value;//供奉值
		NFShmVector<struct E_TianxiafirstExtraaddattrAttributeDesc_s, DEFINE_E_TIANXIAFIRSTEXTRAADDATTR_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstExtraaddattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstExtraaddattr & msg);
		static ::proto_ff::E_TianxiafirstExtraaddattr* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstExtraaddattr(); }
		static ::proto_ff::E_TianxiafirstExtraaddattr make_pbmsg(){ return ::proto_ff::E_TianxiafirstExtraaddattr(); }
	};
	typedef struct E_TianxiafirstExtraaddattr_s E_TianxiafirstExtraaddattr_t;

	struct Sheet_TianxiafirstExtraaddattr_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstExtraaddattr_s();
		virtual ~Sheet_TianxiafirstExtraaddattr_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstExtraaddattr_s, DEFINE_SHEET_TIANXIAFIRSTEXTRAADDATTR_E_TIANXIAFIRSTEXTRAADDATTR_LIST_MAX_NUM> E_TianxiafirstExtraaddattr_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstExtraaddattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstExtraaddattr & msg);
		static ::proto_ff::Sheet_TianxiafirstExtraaddattr* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstExtraaddattr(); }
		static ::proto_ff::Sheet_TianxiafirstExtraaddattr make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstExtraaddattr(); }
	};
	typedef struct Sheet_TianxiafirstExtraaddattr_s Sheet_TianxiafirstExtraaddattr_t;

	struct E_TianxiafirstFirstaddattrAttributeDesc_s : public NFDescStoreSeqOP {
		E_TianxiafirstFirstaddattrAttributeDesc_s();
		virtual ~E_TianxiafirstFirstaddattrAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc & msg);
		static ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc(); }
		static ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc make_pbmsg(){ return ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc(); }
	};
	typedef struct E_TianxiafirstFirstaddattrAttributeDesc_s E_TianxiafirstFirstaddattrAttributeDesc_t;

	struct E_TianxiafirstFirstaddattr_s : public NFDescStoreSeqOP {
		E_TianxiafirstFirstaddattr_s();
		virtual ~E_TianxiafirstFirstaddattr_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_value;//供奉值
		NFShmVector<struct E_TianxiafirstFirstaddattrAttributeDesc_s, DEFINE_E_TIANXIAFIRSTFIRSTADDATTR_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstFirstaddattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstFirstaddattr & msg);
		static ::proto_ff::E_TianxiafirstFirstaddattr* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstFirstaddattr(); }
		static ::proto_ff::E_TianxiafirstFirstaddattr make_pbmsg(){ return ::proto_ff::E_TianxiafirstFirstaddattr(); }
	};
	typedef struct E_TianxiafirstFirstaddattr_s E_TianxiafirstFirstaddattr_t;

	struct Sheet_TianxiafirstFirstaddattr_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstFirstaddattr_s();
		virtual ~Sheet_TianxiafirstFirstaddattr_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstFirstaddattr_s, DEFINE_SHEET_TIANXIAFIRSTFIRSTADDATTR_E_TIANXIAFIRSTFIRSTADDATTR_LIST_MAX_NUM> E_TianxiafirstFirstaddattr_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstFirstaddattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstFirstaddattr & msg);
		static ::proto_ff::Sheet_TianxiafirstFirstaddattr* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstFirstaddattr(); }
		static ::proto_ff::Sheet_TianxiafirstFirstaddattr make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstFirstaddattr(); }
	};
	typedef struct Sheet_TianxiafirstFirstaddattr_s Sheet_TianxiafirstFirstaddattr_t;

	struct E_TianxiafirstShop_s : public NFDescStoreSeqOP {
		E_TianxiafirstShop_s();
		virtual ~E_TianxiafirstShop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_itemId;//物品id
		int32_t m_costItem;//购买消耗物品id
		int32_t m_costNum;//购买消耗数量
		int32_t m_count;//限购数量
		int32_t m_limitType;//限购类型
		int32_t m_condition;//购买条件
		int32_t m_conditionParam;//购买条件参数

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstShop & msg);
		static ::proto_ff::E_TianxiafirstShop* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstShop(); }
		static ::proto_ff::E_TianxiafirstShop make_pbmsg(){ return ::proto_ff::E_TianxiafirstShop(); }
	};
	typedef struct E_TianxiafirstShop_s E_TianxiafirstShop_t;

	struct Sheet_TianxiafirstShop_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstShop_s();
		virtual ~Sheet_TianxiafirstShop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstShop_s, DEFINE_SHEET_TIANXIAFIRSTSHOP_E_TIANXIAFIRSTSHOP_LIST_MAX_NUM> E_TianxiafirstShop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstShop & msg);
		static ::proto_ff::Sheet_TianxiafirstShop* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstShop(); }
		static ::proto_ff::Sheet_TianxiafirstShop make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstShop(); }
	};
	typedef struct Sheet_TianxiafirstShop_s Sheet_TianxiafirstShop_t;

	struct E_TianxiafirstDanmaku_s : public NFDescStoreSeqOP {
		E_TianxiafirstDanmaku_s();
		virtual ~E_TianxiafirstDanmaku_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		NFShmString<64> m_danmaku;//弹幕内容

		virtual void write_to_pbmsg(::proto_ff::E_TianxiafirstDanmaku & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TianxiafirstDanmaku & msg);
		static ::proto_ff::E_TianxiafirstDanmaku* new_pbmsg(){ return new ::proto_ff::E_TianxiafirstDanmaku(); }
		static ::proto_ff::E_TianxiafirstDanmaku make_pbmsg(){ return ::proto_ff::E_TianxiafirstDanmaku(); }
	};
	typedef struct E_TianxiafirstDanmaku_s E_TianxiafirstDanmaku_t;

	struct Sheet_TianxiafirstDanmaku_s : public NFDescStoreSeqOP {
		Sheet_TianxiafirstDanmaku_s();
		virtual ~Sheet_TianxiafirstDanmaku_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TianxiafirstDanmaku_s, DEFINE_SHEET_TIANXIAFIRSTDANMAKU_E_TIANXIAFIRSTDANMAKU_LIST_MAX_NUM> E_TianxiafirstDanmaku_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TianxiafirstDanmaku & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstDanmaku & msg);
		static ::proto_ff::Sheet_TianxiafirstDanmaku* new_pbmsg(){ return new ::proto_ff::Sheet_TianxiafirstDanmaku(); }
		static ::proto_ff::Sheet_TianxiafirstDanmaku make_pbmsg(){ return ::proto_ff::Sheet_TianxiafirstDanmaku(); }
	};
	typedef struct Sheet_TianxiafirstDanmaku_s Sheet_TianxiafirstDanmaku_t;

}

