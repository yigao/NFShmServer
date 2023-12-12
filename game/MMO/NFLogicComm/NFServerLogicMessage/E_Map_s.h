#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Map.pb.h"
#include "E_Map_s.h"

#define DEFINE_SHEET_MAPMAP_E_MAPMAP_LIST_MAX_NUM 256
#define DEFINE_SHEET_MAPITEMDROP_E_MAPITEMDROP_LIST_MAX_NUM 4
#define DEFINE_SHEET_MAPDESTROYITEM_E_MAPDESTROYITEM_LIST_MAX_NUM 256
#define DEFINE_SHEET_MAPBUTTON_E_MAPBUTTON_LIST_MAX_NUM 32
#define DEFINE_E_MAPINSPIRE_M_REWARD_MAX_NUM 2
#define DEFINE_SHEET_MAPINSPIRE_E_MAPINSPIRE_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_MapMap_s : public NFDescStoreSeqOP {
		E_MapMap_s();
		virtual ~E_MapMap_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_mapId;//地图id
		int32_t m_levelLimit;//地图等级限制
		NFShmString<64> m_adviceLv;//地图推荐等级段
		int32_t m_isDyn;//是否动态地图
		int32_t m_mapType;//地图类型
		int32_t m_mapSubType;//地图子类型
		int32_t m_clearanceTime;//地图清场时间（秒）
		int32_t m_mapPkmode;//地图pk模式
		NFShmString<64> m_mapPkValue;//地图可用的PK模式
		int32_t m_pklock;//地图是否允许切换PK模式
		int32_t m_pk;//地图是否允许pk
		int32_t m_killValue;//地图杀人是否增加杀戮值且地图死亡后是否清除杀戮值
		int32_t m_BanGroup;//禁止组队进入邀请
		int32_t m_reviveTime;//场景复活倒计时长
		int32_t m_mapWide;//地图宽度
		int32_t m_mapHeight;//地图高度
		NFShmString<64> m_mapResources;//地图资源名
		int64_t m_reviveSkill;//复活无敌
		int32_t m_reviveInPlaceType;//原地复活类型
		int32_t m_isHangUp;//是否能自动挂机
		int32_t m_itemDropType;//死亡掉落类型
		NFShmString<64> m_itemDropID;//触发掉落组ID
		int64_t m_linkOffLine;//下线后回到地图
		int32_t m_banOnHook;//是否禁止原地挂机
		int32_t m_Rewait;//普通复活等待时间
		int32_t m_REtime;//自动普通复活倒计时
		int32_t m_HREBan;//禁止原地复活
		int32_t m_Retiered;//是否疲劳复活
		int32_t m_REskillid;//复活后获得的技能
		int32_t m_Reteimes;//复活次数限制
		int32_t m_drivePoint;//驱赶值
		int32_t m_dieDP;//死亡增加驱赶值
		int32_t m_timeDP;//每分钟增加驱赶值
		int32_t m_meditation;//是否允许打坐
		NFShmString<64> m_mapButton;//地图按钮
		int32_t m_banMount;//禁用坐骑
		int32_t m_banLink;//禁用link
		int32_t m_lvSupPvp;//等级压制
		int32_t m_powerSupPvp;//战力压制

		virtual void write_to_pbmsg(::proto_ff::E_MapMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapMap & msg);
		static ::proto_ff::E_MapMap* new_pbmsg(){ return new ::proto_ff::E_MapMap(); }
		static ::proto_ff::E_MapMap make_pbmsg(){ return ::proto_ff::E_MapMap(); }
	};
	typedef struct E_MapMap_s E_MapMap_t;

	struct Sheet_MapMap_s : public NFDescStoreSeqOP {
		Sheet_MapMap_s();
		virtual ~Sheet_MapMap_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapMap_s, DEFINE_SHEET_MAPMAP_E_MAPMAP_LIST_MAX_NUM> E_MapMap_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapMap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapMap & msg);
		static ::proto_ff::Sheet_MapMap* new_pbmsg(){ return new ::proto_ff::Sheet_MapMap(); }
		static ::proto_ff::Sheet_MapMap make_pbmsg(){ return ::proto_ff::Sheet_MapMap(); }
	};
	typedef struct Sheet_MapMap_s Sheet_MapMap_t;

	struct E_MapItemdrop_s : public NFDescStoreSeqOP {
		E_MapItemdrop_s();
		virtual ~E_MapItemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_itemDropID;//掉落ID
		int32_t m_dropType;//掉落类型
		int32_t m_odds;//触发几率
		int32_t m_ownProtect;//归属保护
		int32_t m_belongType;//归属类型
		int32_t m_numMax;//掉落最大数量
		int32_t m_dropvaluea;//掉落参数a
		int32_t m_dropvalueb;//掉落参数b
		int32_t m_dropvaluec;//掉落参数c
		int32_t m_dropvalued;//掉落参数d
		int32_t m_dropvaluee;//掉落参数e
		int32_t m_dropvaluef;//掉落参数f

		virtual void write_to_pbmsg(::proto_ff::E_MapItemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapItemdrop & msg);
		static ::proto_ff::E_MapItemdrop* new_pbmsg(){ return new ::proto_ff::E_MapItemdrop(); }
		static ::proto_ff::E_MapItemdrop make_pbmsg(){ return ::proto_ff::E_MapItemdrop(); }
	};
	typedef struct E_MapItemdrop_s E_MapItemdrop_t;

	struct Sheet_MapItemdrop_s : public NFDescStoreSeqOP {
		Sheet_MapItemdrop_s();
		virtual ~Sheet_MapItemdrop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapItemdrop_s, DEFINE_SHEET_MAPITEMDROP_E_MAPITEMDROP_LIST_MAX_NUM> E_MapItemdrop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapItemdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapItemdrop & msg);
		static ::proto_ff::Sheet_MapItemdrop* new_pbmsg(){ return new ::proto_ff::Sheet_MapItemdrop(); }
		static ::proto_ff::Sheet_MapItemdrop make_pbmsg(){ return ::proto_ff::Sheet_MapItemdrop(); }
	};
	typedef struct Sheet_MapItemdrop_s Sheet_MapItemdrop_t;

	struct E_MapDestroyitem_s : public NFDescStoreSeqOP {
		E_MapDestroyitem_s();
		virtual ~E_MapDestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_destroyitemID;//触发摧毁道具ID

		virtual void write_to_pbmsg(::proto_ff::E_MapDestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapDestroyitem & msg);
		static ::proto_ff::E_MapDestroyitem* new_pbmsg(){ return new ::proto_ff::E_MapDestroyitem(); }
		static ::proto_ff::E_MapDestroyitem make_pbmsg(){ return ::proto_ff::E_MapDestroyitem(); }
	};
	typedef struct E_MapDestroyitem_s E_MapDestroyitem_t;

	struct Sheet_MapDestroyitem_s : public NFDescStoreSeqOP {
		Sheet_MapDestroyitem_s();
		virtual ~Sheet_MapDestroyitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapDestroyitem_s, DEFINE_SHEET_MAPDESTROYITEM_E_MAPDESTROYITEM_LIST_MAX_NUM> E_MapDestroyitem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapDestroyitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapDestroyitem & msg);
		static ::proto_ff::Sheet_MapDestroyitem* new_pbmsg(){ return new ::proto_ff::Sheet_MapDestroyitem(); }
		static ::proto_ff::Sheet_MapDestroyitem make_pbmsg(){ return ::proto_ff::Sheet_MapDestroyitem(); }
	};
	typedef struct Sheet_MapDestroyitem_s Sheet_MapDestroyitem_t;

	struct E_MapButton_s : public NFDescStoreSeqOP {
		E_MapButton_s();
		virtual ~E_MapButton_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//功能类型
		int32_t m_arg1;//参数
		int32_t m_arg2;//参数

		virtual void write_to_pbmsg(::proto_ff::E_MapButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapButton & msg);
		static ::proto_ff::E_MapButton* new_pbmsg(){ return new ::proto_ff::E_MapButton(); }
		static ::proto_ff::E_MapButton make_pbmsg(){ return ::proto_ff::E_MapButton(); }
	};
	typedef struct E_MapButton_s E_MapButton_t;

	struct Sheet_MapButton_s : public NFDescStoreSeqOP {
		Sheet_MapButton_s();
		virtual ~Sheet_MapButton_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapButton_s, DEFINE_SHEET_MAPBUTTON_E_MAPBUTTON_LIST_MAX_NUM> E_MapButton_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapButton & msg);
		static ::proto_ff::Sheet_MapButton* new_pbmsg(){ return new ::proto_ff::Sheet_MapButton(); }
		static ::proto_ff::Sheet_MapButton make_pbmsg(){ return ::proto_ff::Sheet_MapButton(); }
	};
	typedef struct Sheet_MapButton_s Sheet_MapButton_t;

	struct E_MapInspireRewardDesc_s : public NFDescStoreSeqOP {
		E_MapInspireRewardDesc_s();
		virtual ~E_MapInspireRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int32_t m_Id;//id

		virtual void write_to_pbmsg(::proto_ff::E_MapInspireRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapInspireRewardDesc & msg);
		static ::proto_ff::E_MapInspireRewardDesc* new_pbmsg(){ return new ::proto_ff::E_MapInspireRewardDesc(); }
		static ::proto_ff::E_MapInspireRewardDesc make_pbmsg(){ return ::proto_ff::E_MapInspireRewardDesc(); }
	};
	typedef struct E_MapInspireRewardDesc_s E_MapInspireRewardDesc_t;

	struct E_MapInspire_s : public NFDescStoreSeqOP {
		E_MapInspire_s();
		virtual ~E_MapInspire_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_group;//组
		NFShmString<64> m_name;//名称
		int32_t m_costId;//花费id
		int32_t m_costNum;//花费数量
		int32_t m_skillid;//技能id
		int32_t m_times;//次数
		NFShmVector<struct E_MapInspireRewardDesc_s, DEFINE_E_MAPINSPIRE_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_MapInspire & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MapInspire & msg);
		static ::proto_ff::E_MapInspire* new_pbmsg(){ return new ::proto_ff::E_MapInspire(); }
		static ::proto_ff::E_MapInspire make_pbmsg(){ return ::proto_ff::E_MapInspire(); }
	};
	typedef struct E_MapInspire_s E_MapInspire_t;

	struct Sheet_MapInspire_s : public NFDescStoreSeqOP {
		Sheet_MapInspire_s();
		virtual ~Sheet_MapInspire_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MapInspire_s, DEFINE_SHEET_MAPINSPIRE_E_MAPINSPIRE_LIST_MAX_NUM> E_MapInspire_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MapInspire & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MapInspire & msg);
		static ::proto_ff::Sheet_MapInspire* new_pbmsg(){ return new ::proto_ff::Sheet_MapInspire(); }
		static ::proto_ff::Sheet_MapInspire make_pbmsg(){ return ::proto_ff::Sheet_MapInspire(); }
	};
	typedef struct Sheet_MapInspire_s Sheet_MapInspire_t;

}

