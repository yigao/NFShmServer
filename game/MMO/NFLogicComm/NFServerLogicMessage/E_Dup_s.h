#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Dup.pb.h"
#include "E_Dup_s.h"

#define DEFINE_E_DUPDUP_M_BOX_MAX_NUM 3
#define DEFINE_SHEET_DUPDUP_E_DUPDUP_LIST_MAX_NUM 2048
#define DEFINE_E_DUPBPLEVEL_M_BGDUP_MAX_NUM 5
#define DEFINE_E_DUPBPLEVEL_M_BGDUPSWEEP_MAX_NUM 5
#define DEFINE_SHEET_DUPBPLEVEL_E_DUPBPLEVEL_LIST_MAX_NUM 1024
#define DEFINE_E_DUPTTOWERWAVE_M_CLEAR_MAX_NUM 4
#define DEFINE_SHEET_DUPTTOWERWAVE_E_DUPTTOWERWAVE_LIST_MAX_NUM 1024
#define DEFINE_SHEET_DUPTOWERREWARD_E_DUPTOWERREWARD_LIST_MAX_NUM 256
#define DEFINE_SHEET_DUPGROUP_E_DUPGROUP_LIST_MAX_NUM 64
#define DEFINE_SHEET_DUPSWEEPMONSTERNUM_E_DUPSWEEPMONSTERNUM_LIST_MAX_NUM 64
#define DEFINE_E_DUPWORLDLVREWARD_M_BOX_MAX_NUM 3
#define DEFINE_SHEET_DUPWORLDLVREWARD_E_DUPWORLDLVREWARD_LIST_MAX_NUM 32
#define DEFINE_SHEET_DUPPLANES_E_DUPPLANES_LIST_MAX_NUM 64
#define DEFINE_E_DUPYT_DUP_M_CLEAR_MAX_NUM 4
#define DEFINE_SHEET_DUPYT_DUP_E_DUPYT_DUP_LIST_MAX_NUM 1024


namespace proto_ff_s {

	struct E_DupDup_s : public NFDescStoreSeqOP {
		E_DupDup_s();
		virtual ~E_DupDup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//副本ID
		int32_t m_scripid;//刷怪脚本ID
		int32_t m_scriptype;//刷怪脚本类型
		int32_t m_duplevel;//副本等级
		int32_t m_scripmontype;//脚本怪物类型
		NFShmString<64> m_scripmonid;//脚本怪物id
		int32_t m_groupid;//所属副本组ID
		int32_t m_subtype;//子类型
		int32_t m_layer;//层级
		int32_t m_duplicatetype;//副本内容类型
		int64_t m_mapid;//场景ID
		int32_t m_levellimit;//等级要求下限
		int32_t m_functionid;//额外功能开放要求
		int32_t m_pre;//前置副本要求
		int32_t m_isautofight;//是否允许自动战斗
		NFShmString<64> m_condition;//副本胜利条件类型
		int32_t m_revivemaxtimes;//复活次数上限
		int32_t m_teamobjectid;//组队目标ID
		NFShmString<64> m_gradecondition;//星级时间
		int64_t m_sweeprewardboxid;//扫荡奖励BOXID
		int32_t m_sweeprewardexp;//扫荡经验奖励
		int32_t m_sweepexptype;//扫荡经验类型
		NFShmString<64> m_trackpoint;//副本寻路点
		NFShmString<64> m_pathofmonster;//副本寻路点对应怪物
		int32_t m_ispatrol;//寻路前是否巡敌
		int32_t m_failurebox;//失败奖励
		int32_t m_planes;//位面
		NFShmVector<int32_t, DEFINE_E_DUPDUP_M_BOX_MAX_NUM> m_box;//奖励组

		virtual void write_to_pbmsg(::proto_ff::E_DupDup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupDup & msg);
		static ::proto_ff::E_DupDup* new_pbmsg(){ return new ::proto_ff::E_DupDup(); }
		static ::proto_ff::E_DupDup make_pbmsg(){ return ::proto_ff::E_DupDup(); }
	};
	typedef struct E_DupDup_s E_DupDup_t;

	struct Sheet_DupDup_s : public NFDescStoreSeqOP {
		Sheet_DupDup_s();
		virtual ~Sheet_DupDup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupDup_s, DEFINE_SHEET_DUPDUP_E_DUPDUP_LIST_MAX_NUM> E_DupDup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupDup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupDup & msg);
		static ::proto_ff::Sheet_DupDup* new_pbmsg(){ return new ::proto_ff::Sheet_DupDup(); }
		static ::proto_ff::Sheet_DupDup make_pbmsg(){ return ::proto_ff::Sheet_DupDup(); }
	};
	typedef struct Sheet_DupDup_s Sheet_DupDup_t;

	struct E_DupBplevel_s : public NFDescStoreSeqOP {
		E_DupBplevel_s();
		virtual ~E_DupBplevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		NFShmVector<int64_t, DEFINE_E_DUPBPLEVEL_M_BGDUP_MAX_NUM> m_bgdup;//八卦本
		NFShmVector<int64_t, DEFINE_E_DUPBPLEVEL_M_BGDUPSWEEP_MAX_NUM> m_bgdupsweep;//八卦本

		virtual void write_to_pbmsg(::proto_ff::E_DupBplevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupBplevel & msg);
		static ::proto_ff::E_DupBplevel* new_pbmsg(){ return new ::proto_ff::E_DupBplevel(); }
		static ::proto_ff::E_DupBplevel make_pbmsg(){ return ::proto_ff::E_DupBplevel(); }
	};
	typedef struct E_DupBplevel_s E_DupBplevel_t;

	struct Sheet_DupBplevel_s : public NFDescStoreSeqOP {
		Sheet_DupBplevel_s();
		virtual ~Sheet_DupBplevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupBplevel_s, DEFINE_SHEET_DUPBPLEVEL_E_DUPBPLEVEL_LIST_MAX_NUM> E_DupBplevel_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupBplevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupBplevel & msg);
		static ::proto_ff::Sheet_DupBplevel* new_pbmsg(){ return new ::proto_ff::Sheet_DupBplevel(); }
		static ::proto_ff::Sheet_DupBplevel make_pbmsg(){ return ::proto_ff::Sheet_DupBplevel(); }
	};
	typedef struct Sheet_DupBplevel_s Sheet_DupBplevel_t;

	struct E_DupTtowerwaveClearDesc_s : public NFDescStoreSeqOP {
		E_DupTtowerwaveClearDesc_s();
		virtual ~E_DupTtowerwaveClearDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_add;//增加关数
		int32_t m_time;//时间

		virtual void write_to_pbmsg(::proto_ff::E_DupTtowerwaveClearDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupTtowerwaveClearDesc & msg);
		static ::proto_ff::E_DupTtowerwaveClearDesc* new_pbmsg(){ return new ::proto_ff::E_DupTtowerwaveClearDesc(); }
		static ::proto_ff::E_DupTtowerwaveClearDesc make_pbmsg(){ return ::proto_ff::E_DupTtowerwaveClearDesc(); }
	};
	typedef struct E_DupTtowerwaveClearDesc_s E_DupTtowerwaveClearDesc_t;

	struct E_DupTtowerwave_s : public NFDescStoreSeqOP {
		E_DupTtowerwave_s();
		virtual ~E_DupTtowerwave_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//波id
		int32_t m_scripid;//刷怪脚本ID
		NFShmString<64> m_scripgid;//刷怪脚本类型
		int32_t m_scriptype;//刷怪脚本类型
		int32_t m_duplevel;//副本等级
		int32_t m_scripmontype;//脚本怪物类型
		NFShmString<64> m_scripmonid;//脚本怪物id
		int32_t m_recommendpower;//推荐战力
		int32_t m_reward;//结算奖励
		int32_t m_firstpass;//首通奖励
		int32_t m_bp;//平均战力
		NFShmVector<struct E_DupTtowerwaveClearDesc_s, DEFINE_E_DUPTTOWERWAVE_M_CLEAR_MAX_NUM> m_clear;//通关

		virtual void write_to_pbmsg(::proto_ff::E_DupTtowerwave & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupTtowerwave & msg);
		static ::proto_ff::E_DupTtowerwave* new_pbmsg(){ return new ::proto_ff::E_DupTtowerwave(); }
		static ::proto_ff::E_DupTtowerwave make_pbmsg(){ return ::proto_ff::E_DupTtowerwave(); }
	};
	typedef struct E_DupTtowerwave_s E_DupTtowerwave_t;

	struct Sheet_DupTtowerwave_s : public NFDescStoreSeqOP {
		Sheet_DupTtowerwave_s();
		virtual ~Sheet_DupTtowerwave_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupTtowerwave_s, DEFINE_SHEET_DUPTTOWERWAVE_E_DUPTTOWERWAVE_LIST_MAX_NUM> E_DupTtowerwave_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupTtowerwave & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupTtowerwave & msg);
		static ::proto_ff::Sheet_DupTtowerwave* new_pbmsg(){ return new ::proto_ff::Sheet_DupTtowerwave(); }
		static ::proto_ff::Sheet_DupTtowerwave make_pbmsg(){ return ::proto_ff::Sheet_DupTtowerwave(); }
	};
	typedef struct Sheet_DupTtowerwave_s Sheet_DupTtowerwave_t;

	struct E_DupTowerreward_s : public NFDescStoreSeqOP {
		E_DupTowerreward_s();
		virtual ~E_DupTowerreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_cond;//领取条件
		int32_t m_boxid;//box

		virtual void write_to_pbmsg(::proto_ff::E_DupTowerreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupTowerreward & msg);
		static ::proto_ff::E_DupTowerreward* new_pbmsg(){ return new ::proto_ff::E_DupTowerreward(); }
		static ::proto_ff::E_DupTowerreward make_pbmsg(){ return ::proto_ff::E_DupTowerreward(); }
	};
	typedef struct E_DupTowerreward_s E_DupTowerreward_t;

	struct Sheet_DupTowerreward_s : public NFDescStoreSeqOP {
		Sheet_DupTowerreward_s();
		virtual ~Sheet_DupTowerreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupTowerreward_s, DEFINE_SHEET_DUPTOWERREWARD_E_DUPTOWERREWARD_LIST_MAX_NUM> E_DupTowerreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupTowerreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupTowerreward & msg);
		static ::proto_ff::Sheet_DupTowerreward* new_pbmsg(){ return new ::proto_ff::Sheet_DupTowerreward(); }
		static ::proto_ff::Sheet_DupTowerreward make_pbmsg(){ return ::proto_ff::Sheet_DupTowerreward(); }
	};
	typedef struct Sheet_DupTowerreward_s Sheet_DupTowerreward_t;

	struct E_DupGroup_s : public NFDescStoreSeqOP {
		E_DupGroup_s();
		virtual ~E_DupGroup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//副本组ID
		NFShmString<64> m_name;//副本组名
		int32_t m_privilegetype;//特权类型
		int32_t m_dynamiclevel;//是否动态等级
		int32_t m_grouptimestype;//组次数类型
		int32_t m_resetcycle;//重置周期
		int32_t m_grouptimes;//次数上限值
		int32_t m_enteritemid;//副本进入道具
		int32_t m_sweeptype;//扫荡类型
		int32_t m_sweepcondition;//扫荡条件
		int32_t m_mergecondition;//合并条件
		int32_t m_additemid;//增加次数物品ID
		int32_t m_buytype;//购买次数消耗货币
		int32_t m_buyitemid;//购买次数消耗物品
		NFShmString<64> m_buycost;//购买进入次数消耗
		int32_t m_countdown;//倒计时时间
		int32_t m_enddown;//结束倒计时
		int32_t m_accountdown;//结算倒计时
		int32_t m_funcionid;//功能ID
		int32_t m_closefuncionid;//关闭功能ID
		int64_t m_link;//副本结束打开界面
		int32_t m_festvialtype;//活动id

		virtual void write_to_pbmsg(::proto_ff::E_DupGroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupGroup & msg);
		static ::proto_ff::E_DupGroup* new_pbmsg(){ return new ::proto_ff::E_DupGroup(); }
		static ::proto_ff::E_DupGroup make_pbmsg(){ return ::proto_ff::E_DupGroup(); }
	};
	typedef struct E_DupGroup_s E_DupGroup_t;

	struct Sheet_DupGroup_s : public NFDescStoreSeqOP {
		Sheet_DupGroup_s();
		virtual ~Sheet_DupGroup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupGroup_s, DEFINE_SHEET_DUPGROUP_E_DUPGROUP_LIST_MAX_NUM> E_DupGroup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupGroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupGroup & msg);
		static ::proto_ff::Sheet_DupGroup* new_pbmsg(){ return new ::proto_ff::Sheet_DupGroup(); }
		static ::proto_ff::Sheet_DupGroup make_pbmsg(){ return ::proto_ff::Sheet_DupGroup(); }
	};
	typedef struct Sheet_DupGroup_s Sheet_DupGroup_t;

	struct E_DupSweepmonsternum_s : public NFDescStoreSeqOP {
		E_DupSweepmonsternum_s();
		virtual ~E_DupSweepmonsternum_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_sweepexptype;//扫荡类型
		int32_t m_minlevel;//玩家等极下限
		int32_t m_maxlevel;//玩家等极上限
		int32_t m_killnumber;//杀怪标准数量
		int32_t m_monstervaluetype;//怪物数值类型

		virtual void write_to_pbmsg(::proto_ff::E_DupSweepmonsternum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupSweepmonsternum & msg);
		static ::proto_ff::E_DupSweepmonsternum* new_pbmsg(){ return new ::proto_ff::E_DupSweepmonsternum(); }
		static ::proto_ff::E_DupSweepmonsternum make_pbmsg(){ return ::proto_ff::E_DupSweepmonsternum(); }
	};
	typedef struct E_DupSweepmonsternum_s E_DupSweepmonsternum_t;

	struct Sheet_DupSweepmonsternum_s : public NFDescStoreSeqOP {
		Sheet_DupSweepmonsternum_s();
		virtual ~Sheet_DupSweepmonsternum_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupSweepmonsternum_s, DEFINE_SHEET_DUPSWEEPMONSTERNUM_E_DUPSWEEPMONSTERNUM_LIST_MAX_NUM> E_DupSweepmonsternum_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupSweepmonsternum & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupSweepmonsternum & msg);
		static ::proto_ff::Sheet_DupSweepmonsternum* new_pbmsg(){ return new ::proto_ff::Sheet_DupSweepmonsternum(); }
		static ::proto_ff::Sheet_DupSweepmonsternum make_pbmsg(){ return ::proto_ff::Sheet_DupSweepmonsternum(); }
	};
	typedef struct Sheet_DupSweepmonsternum_s Sheet_DupSweepmonsternum_t;

	struct E_DupWorldlvreward_s : public NFDescStoreSeqOP {
		E_DupWorldlvreward_s();
		virtual ~E_DupWorldlvreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//副本组id
		int32_t m_lvtype;//世界等级类型
		int32_t m_lvmin;//世界等级下限
		int32_t m_failurebox;//失败奖励
		NFShmVector<int32_t, DEFINE_E_DUPWORLDLVREWARD_M_BOX_MAX_NUM> m_box;//星奖励

		virtual void write_to_pbmsg(::proto_ff::E_DupWorldlvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupWorldlvreward & msg);
		static ::proto_ff::E_DupWorldlvreward* new_pbmsg(){ return new ::proto_ff::E_DupWorldlvreward(); }
		static ::proto_ff::E_DupWorldlvreward make_pbmsg(){ return ::proto_ff::E_DupWorldlvreward(); }
	};
	typedef struct E_DupWorldlvreward_s E_DupWorldlvreward_t;

	struct Sheet_DupWorldlvreward_s : public NFDescStoreSeqOP {
		Sheet_DupWorldlvreward_s();
		virtual ~Sheet_DupWorldlvreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupWorldlvreward_s, DEFINE_SHEET_DUPWORLDLVREWARD_E_DUPWORLDLVREWARD_LIST_MAX_NUM> E_DupWorldlvreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupWorldlvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupWorldlvreward & msg);
		static ::proto_ff::Sheet_DupWorldlvreward* new_pbmsg(){ return new ::proto_ff::Sheet_DupWorldlvreward(); }
		static ::proto_ff::Sheet_DupWorldlvreward make_pbmsg(){ return ::proto_ff::Sheet_DupWorldlvreward(); }
	};
	typedef struct Sheet_DupWorldlvreward_s Sheet_DupWorldlvreward_t;

	struct E_DupPlanes_s : public NFDescStoreSeqOP {
		E_DupPlanes_s();
		virtual ~E_DupPlanes_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//位面id
		int32_t m_planestype;//位面类型
		NFShmString<64> m_typeargs;//类型参数
		int32_t m_areaid;//区域id

		virtual void write_to_pbmsg(::proto_ff::E_DupPlanes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupPlanes & msg);
		static ::proto_ff::E_DupPlanes* new_pbmsg(){ return new ::proto_ff::E_DupPlanes(); }
		static ::proto_ff::E_DupPlanes make_pbmsg(){ return ::proto_ff::E_DupPlanes(); }
	};
	typedef struct E_DupPlanes_s E_DupPlanes_t;

	struct Sheet_DupPlanes_s : public NFDescStoreSeqOP {
		Sheet_DupPlanes_s();
		virtual ~Sheet_DupPlanes_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupPlanes_s, DEFINE_SHEET_DUPPLANES_E_DUPPLANES_LIST_MAX_NUM> E_DupPlanes_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupPlanes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupPlanes & msg);
		static ::proto_ff::Sheet_DupPlanes* new_pbmsg(){ return new ::proto_ff::Sheet_DupPlanes(); }
		static ::proto_ff::Sheet_DupPlanes make_pbmsg(){ return ::proto_ff::Sheet_DupPlanes(); }
	};
	typedef struct Sheet_DupPlanes_s Sheet_DupPlanes_t;

	struct E_DupYt_dupClearDesc_s : public NFDescStoreSeqOP {
		E_DupYt_dupClearDesc_s();
		virtual ~E_DupYt_dupClearDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_add;//增加关数
		int32_t m_time;//时间

		virtual void write_to_pbmsg(::proto_ff::E_DupYt_dupClearDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupYt_dupClearDesc & msg);
		static ::proto_ff::E_DupYt_dupClearDesc* new_pbmsg(){ return new ::proto_ff::E_DupYt_dupClearDesc(); }
		static ::proto_ff::E_DupYt_dupClearDesc make_pbmsg(){ return ::proto_ff::E_DupYt_dupClearDesc(); }
	};
	typedef struct E_DupYt_dupClearDesc_s E_DupYt_dupClearDesc_t;

	struct E_DupYt_dup_s : public NFDescStoreSeqOP {
		E_DupYt_dup_s();
		virtual ~E_DupYt_dup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//副本id
		int32_t m_layer;//所属层级
		int32_t m_stage;//关卡等级
		int32_t m_recommendlv;//推荐等级
		int32_t m_recommendyk;//推荐妖抗
		int32_t m_reward;//结算奖励
		int32_t m_firstpass;//首通奖励
		int32_t m_overlordbox;//霸主奖励
		int32_t m_overlordtime;//霸主时间
		NFShmVector<struct E_DupYt_dupClearDesc_s, DEFINE_E_DUPYT_DUP_M_CLEAR_MAX_NUM> m_clear;//通关

		virtual void write_to_pbmsg(::proto_ff::E_DupYt_dup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DupYt_dup & msg);
		static ::proto_ff::E_DupYt_dup* new_pbmsg(){ return new ::proto_ff::E_DupYt_dup(); }
		static ::proto_ff::E_DupYt_dup make_pbmsg(){ return ::proto_ff::E_DupYt_dup(); }
	};
	typedef struct E_DupYt_dup_s E_DupYt_dup_t;

	struct Sheet_DupYt_dup_s : public NFDescStoreSeqOP {
		Sheet_DupYt_dup_s();
		virtual ~Sheet_DupYt_dup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DupYt_dup_s, DEFINE_SHEET_DUPYT_DUP_E_DUPYT_DUP_LIST_MAX_NUM> E_DupYt_dup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DupYt_dup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DupYt_dup & msg);
		static ::proto_ff::Sheet_DupYt_dup* new_pbmsg(){ return new ::proto_ff::Sheet_DupYt_dup(); }
		static ::proto_ff::Sheet_DupYt_dup make_pbmsg(){ return ::proto_ff::Sheet_DupYt_dup(); }
	};
	typedef struct Sheet_DupYt_dup_s Sheet_DupYt_dup_t;

}

