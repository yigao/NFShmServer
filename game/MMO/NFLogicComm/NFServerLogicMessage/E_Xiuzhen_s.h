#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Xiuzhen.pb.h"
#include "E_Xiuzhen_s.h"

#define DEFINE_E_XIUZHENSTAGES_M_ITEM_MAX_NUM 3
#define DEFINE_E_XIUZHENSTAGES_M_SKILL_MAX_NUM 5
#define DEFINE_E_XIUZHENSTAGES_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_XIUZHENSTAGES_E_XIUZHENSTAGES_LIST_MAX_NUM 2048
#define DEFINE_SHEET_XIUZHENGB_AREAS_E_XIUZHENGB_AREAS_LIST_MAX_NUM 64
#define DEFINE_E_XIUZHENGB_AREA_EVENTS_M_ITEM_MAX_NUM 2
#define DEFINE_SHEET_XIUZHENGB_AREA_EVENTS_E_XIUZHENGB_AREA_EVENTS_LIST_MAX_NUM 32
#define DEFINE_E_XIUZHENGB_LVLUP_M_ITEM_MAX_NUM 1
#define DEFINE_E_XIUZHENGB_LVLUP_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_XIUZHENGB_LVLUP_E_XIUZHENGB_LVLUP_LIST_MAX_NUM 2048
#define DEFINE_E_XIUZHENEVOLVE_M_ITEM_MAX_NUM 3
#define DEFINE_E_XIUZHENEVOLVE_M_ATTRIBUTE_MAX_NUM 12
#define DEFINE_SHEET_XIUZHENEVOLVE_E_XIUZHENEVOLVE_LIST_MAX_NUM 512
#define DEFINE_E_XIUZHENLGTYPES_M_ATTRI_MAX_NUM 3
#define DEFINE_E_XIUZHENLGTYPES_M_LGATT_MAX_NUM 7
#define DEFINE_SHEET_XIUZHENLGTYPES_E_XIUZHENLGTYPES_LIST_MAX_NUM 8
#define DEFINE_SHEET_XIUZHENLGLVLUP_E_XIUZHENLGLVLUP_LIST_MAX_NUM 1024
#define DEFINE_E_XIUZHENLGPOTIONS_M_LG_MAX_NUM 5
#define DEFINE_SHEET_XIUZHENLGPOTIONS_E_XIUZHENLGPOTIONS_LIST_MAX_NUM 32
#define DEFINE_SHEET_XIUZHENGFTYPES_E_XIUZHENGFTYPES_LIST_MAX_NUM 32
#define DEFINE_E_XIUZHENGFLVLUP_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_XIUZHENGFLVLUP_E_XIUZHENGFLVLUP_LIST_MAX_NUM 16384
#define DEFINE_E_XIUZHENGFSTAGEUP_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_XIUZHENGFSTAGEUP_E_XIUZHENGFSTAGEUP_LIST_MAX_NUM 64
#define DEFINE_SHEET_XIUZHENJMTYPES_E_XIUZHENJMTYPES_LIST_MAX_NUM 16
#define DEFINE_E_XIUZHENJMLVLUP_M_ITEM_MAX_NUM 2
#define DEFINE_E_XIUZHENJMLVLUP_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_XIUZHENJMLVLUP_E_XIUZHENJMLVLUP_LIST_MAX_NUM 8192
#define DEFINE_E_XIUZHENJMSTAGEUP_M_ITEM_MAX_NUM 2
#define DEFINE_E_XIUZHENJMSTAGEUP_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_XIUZHENJMSTAGEUP_E_XIUZHENJMSTAGEUP_LIST_MAX_NUM 256
#define DEFINE_E_XIUZHENJMMERGEUP_M_CS_MAX_NUM 2
#define DEFINE_E_XIUZHENJMMERGEUP_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_XIUZHENJMMERGEUP_E_XIUZHENJMMERGEUP_LIST_MAX_NUM 32
#define DEFINE_E_XIUZHENPRIVILEGE_M_PTADD_MAX_NUM 3
#define DEFINE_E_XIUZHENPRIVILEGE_M_ATTRI_MAX_NUM 5
#define DEFINE_SHEET_XIUZHENPRIVILEGE_E_XIUZHENPRIVILEGE_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_XiuzhenStagesItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenStagesItemDesc_s();
		virtual ~E_XiuzhenStagesItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenStagesItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesItemDesc & msg);
		static ::proto_ff::E_XiuzhenStagesItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenStagesItemDesc(); }
		static ::proto_ff::E_XiuzhenStagesItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenStagesItemDesc(); }
	};
	typedef struct E_XiuzhenStagesItemDesc_s E_XiuzhenStagesItemDesc_t;

	struct E_XiuzhenStagesSkillDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenStagesSkillDesc_s();
		virtual ~E_XiuzhenStagesSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenStagesSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesSkillDesc & msg);
		static ::proto_ff::E_XiuzhenStagesSkillDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenStagesSkillDesc(); }
		static ::proto_ff::E_XiuzhenStagesSkillDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenStagesSkillDesc(); }
	};
	typedef struct E_XiuzhenStagesSkillDesc_s E_XiuzhenStagesSkillDesc_t;

	struct E_XiuzhenStagesAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenStagesAttributeDesc_s();
		virtual ~E_XiuzhenStagesAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenStagesAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenStagesAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenStagesAttributeDesc(); }
		static ::proto_ff::E_XiuzhenStagesAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenStagesAttributeDesc(); }
	};
	typedef struct E_XiuzhenStagesAttributeDesc_s E_XiuzhenStagesAttributeDesc_t;

	struct E_XiuzhenStages_s : public NFDescStoreSeqOP {
		E_XiuzhenStages_s();
		virtual ~E_XiuzhenStages_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int32_t m_success_rate;//成功率
		int32_t m_blessing;//失败增加祝福值
		NFShmVector<struct E_XiuzhenStagesItemDesc_s, DEFINE_E_XIUZHENSTAGES_M_ITEM_MAX_NUM> m_item;//材料
		NFShmVector<struct E_XiuzhenStagesSkillDesc_s, DEFINE_E_XIUZHENSTAGES_M_SKILL_MAX_NUM> m_skill;//技能
		NFShmVector<struct E_XiuzhenStagesAttributeDesc_s, DEFINE_E_XIUZHENSTAGES_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenStages & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenStages & msg);
		static ::proto_ff::E_XiuzhenStages* new_pbmsg(){ return new ::proto_ff::E_XiuzhenStages(); }
		static ::proto_ff::E_XiuzhenStages make_pbmsg(){ return ::proto_ff::E_XiuzhenStages(); }
	};
	typedef struct E_XiuzhenStages_s E_XiuzhenStages_t;

	struct Sheet_XiuzhenStages_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenStages_s();
		virtual ~Sheet_XiuzhenStages_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenStages_s, DEFINE_SHEET_XIUZHENSTAGES_E_XIUZHENSTAGES_LIST_MAX_NUM> E_XiuzhenStages_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenStages & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenStages & msg);
		static ::proto_ff::Sheet_XiuzhenStages* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenStages(); }
		static ::proto_ff::Sheet_XiuzhenStages make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenStages(); }
	};
	typedef struct Sheet_XiuzhenStages_s Sheet_XiuzhenStages_t;

	struct E_XiuzhenGb_areas_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_areas_s();
		virtual ~E_XiuzhenGb_areas_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//大陆名称
		NFShmString<64> m_subarea;//区域名
		int32_t m_body_lv;//大陆开启肉身等级
		int32_t m_enter_item;//进仙域消耗道具
		int32_t m_enter_item_num;//道具数量
		int32_t m_enter_rate;//进成功的概率
		int32_t m_energy_addmin;//每间隔提升修为最少值
		int32_t m_energy_addmax;//每间隔提升修为最多
		int32_t m_energy_min;//大陆获得的最小修为
		int32_t m_energy_max;//最大修为
		int32_t m_eventrate;//事件概率
		int32_t m_eventrateenergyadd;//事件修为爆增概率
		int32_t m_eventgetitemsrate;//事件获得道具的概率

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_areas & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_areas & msg);
		static ::proto_ff::E_XiuzhenGb_areas* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_areas(); }
		static ::proto_ff::E_XiuzhenGb_areas make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_areas(); }
	};
	typedef struct E_XiuzhenGb_areas_s E_XiuzhenGb_areas_t;

	struct Sheet_XiuzhenGb_areas_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGb_areas_s();
		virtual ~Sheet_XiuzhenGb_areas_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGb_areas_s, DEFINE_SHEET_XIUZHENGB_AREAS_E_XIUZHENGB_AREAS_LIST_MAX_NUM> E_XiuzhenGb_areas_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_areas & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_areas & msg);
		static ::proto_ff::Sheet_XiuzhenGb_areas* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGb_areas(); }
		static ::proto_ff::Sheet_XiuzhenGb_areas make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGb_areas(); }
	};
	typedef struct Sheet_XiuzhenGb_areas_s Sheet_XiuzhenGb_areas_t;

	struct E_XiuzhenGb_area_eventsItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_area_eventsItemDesc_s();
		virtual ~E_XiuzhenGb_area_eventsItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//Num
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_area_eventsItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_area_eventsItemDesc & msg);
		static ::proto_ff::E_XiuzhenGb_area_eventsItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_area_eventsItemDesc(); }
		static ::proto_ff::E_XiuzhenGb_area_eventsItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_area_eventsItemDesc(); }
	};
	typedef struct E_XiuzhenGb_area_eventsItemDesc_s E_XiuzhenGb_area_eventsItemDesc_t;

	struct E_XiuzhenGb_area_events_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_area_events_s();
		virtual ~E_XiuzhenGb_area_events_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//序号
		int64_t m_areaid;//所在区域
		int32_t m_rate;//随机概率
		int32_t m_type;//类型
		int32_t m_bodylvl;//需要肉身等级
		NFShmString<64> m_chattitle;//文字标题
		NFShmString<64> m_chats;//文字内容
		NFShmString<64> m_chatbgf;//文字背景女
		NFShmString<64> m_chatbgm;//文字背景男
		int32_t m_energyadd;//修为爆增百分比
		NFShmVector<struct E_XiuzhenGb_area_eventsItemDesc_s, DEFINE_E_XIUZHENGB_AREA_EVENTS_M_ITEM_MAX_NUM> m_item;//获得道具

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_area_events & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_area_events & msg);
		static ::proto_ff::E_XiuzhenGb_area_events* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_area_events(); }
		static ::proto_ff::E_XiuzhenGb_area_events make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_area_events(); }
	};
	typedef struct E_XiuzhenGb_area_events_s E_XiuzhenGb_area_events_t;

	struct Sheet_XiuzhenGb_area_events_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGb_area_events_s();
		virtual ~Sheet_XiuzhenGb_area_events_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGb_area_events_s, DEFINE_SHEET_XIUZHENGB_AREA_EVENTS_E_XIUZHENGB_AREA_EVENTS_LIST_MAX_NUM> E_XiuzhenGb_area_events_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_area_events & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_area_events & msg);
		static ::proto_ff::Sheet_XiuzhenGb_area_events* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGb_area_events(); }
		static ::proto_ff::Sheet_XiuzhenGb_area_events make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGb_area_events(); }
	};
	typedef struct Sheet_XiuzhenGb_area_events_s Sheet_XiuzhenGb_area_events_t;

	struct E_XiuzhenGb_lvlupItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_lvlupItemDesc_s();
		virtual ~E_XiuzhenGb_lvlupItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlupItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlupItemDesc & msg);
		static ::proto_ff::E_XiuzhenGb_lvlupItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_lvlupItemDesc(); }
		static ::proto_ff::E_XiuzhenGb_lvlupItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_lvlupItemDesc(); }
	};
	typedef struct E_XiuzhenGb_lvlupItemDesc_s E_XiuzhenGb_lvlupItemDesc_t;

	struct E_XiuzhenGb_lvlupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_lvlupAttributeDesc_s();
		virtual ~E_XiuzhenGb_lvlupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc(); }
	};
	typedef struct E_XiuzhenGb_lvlupAttributeDesc_s E_XiuzhenGb_lvlupAttributeDesc_t;

	struct E_XiuzhenGb_lvlup_s : public NFDescStoreSeqOP {
		E_XiuzhenGb_lvlup_s();
		virtual ~E_XiuzhenGb_lvlup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int32_t m_needenergy;//升级需要修为
		NFShmVector<struct E_XiuzhenGb_lvlupItemDesc_s, DEFINE_E_XIUZHENGB_LVLUP_M_ITEM_MAX_NUM> m_item;//材料
		NFShmVector<struct E_XiuzhenGb_lvlupAttributeDesc_s, DEFINE_E_XIUZHENGB_LVLUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlup & msg);
		static ::proto_ff::E_XiuzhenGb_lvlup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGb_lvlup(); }
		static ::proto_ff::E_XiuzhenGb_lvlup make_pbmsg(){ return ::proto_ff::E_XiuzhenGb_lvlup(); }
	};
	typedef struct E_XiuzhenGb_lvlup_s E_XiuzhenGb_lvlup_t;

	struct Sheet_XiuzhenGb_lvlup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGb_lvlup_s();
		virtual ~Sheet_XiuzhenGb_lvlup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGb_lvlup_s, DEFINE_SHEET_XIUZHENGB_LVLUP_E_XIUZHENGB_LVLUP_LIST_MAX_NUM> E_XiuzhenGb_lvlup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_lvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_lvlup & msg);
		static ::proto_ff::Sheet_XiuzhenGb_lvlup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGb_lvlup(); }
		static ::proto_ff::Sheet_XiuzhenGb_lvlup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGb_lvlup(); }
	};
	typedef struct Sheet_XiuzhenGb_lvlup_s Sheet_XiuzhenGb_lvlup_t;

	struct E_XiuzhenEvolveItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenEvolveItemDesc_s();
		virtual ~E_XiuzhenEvolveItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenEvolveItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolveItemDesc & msg);
		static ::proto_ff::E_XiuzhenEvolveItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenEvolveItemDesc(); }
		static ::proto_ff::E_XiuzhenEvolveItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenEvolveItemDesc(); }
	};
	typedef struct E_XiuzhenEvolveItemDesc_s E_XiuzhenEvolveItemDesc_t;

	struct E_XiuzhenEvolveAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenEvolveAttributeDesc_s();
		virtual ~E_XiuzhenEvolveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenEvolveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolveAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenEvolveAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenEvolveAttributeDesc(); }
		static ::proto_ff::E_XiuzhenEvolveAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenEvolveAttributeDesc(); }
	};
	typedef struct E_XiuzhenEvolveAttributeDesc_s E_XiuzhenEvolveAttributeDesc_t;

	struct E_XiuzhenEvolve_s : public NFDescStoreSeqOP {
		E_XiuzhenEvolve_s();
		virtual ~E_XiuzhenEvolve_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int64_t m_needxw;//升级消耗修为
		int32_t m_success_rate;//成功率
		int32_t m_blessing;//失败增加祝福值
		int32_t m_specialattriid;//特殊属性
		int64_t m_specialattrivalue;//特殊属性值
		int32_t m_linggen;//全灵根加成
		NFShmVector<struct E_XiuzhenEvolveItemDesc_s, DEFINE_E_XIUZHENEVOLVE_M_ITEM_MAX_NUM> m_item;//材料
		NFShmVector<struct E_XiuzhenEvolveAttributeDesc_s, DEFINE_E_XIUZHENEVOLVE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenEvolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolve & msg);
		static ::proto_ff::E_XiuzhenEvolve* new_pbmsg(){ return new ::proto_ff::E_XiuzhenEvolve(); }
		static ::proto_ff::E_XiuzhenEvolve make_pbmsg(){ return ::proto_ff::E_XiuzhenEvolve(); }
	};
	typedef struct E_XiuzhenEvolve_s E_XiuzhenEvolve_t;

	struct Sheet_XiuzhenEvolve_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenEvolve_s();
		virtual ~Sheet_XiuzhenEvolve_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenEvolve_s, DEFINE_SHEET_XIUZHENEVOLVE_E_XIUZHENEVOLVE_LIST_MAX_NUM> E_XiuzhenEvolve_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenEvolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenEvolve & msg);
		static ::proto_ff::Sheet_XiuzhenEvolve* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenEvolve(); }
		static ::proto_ff::Sheet_XiuzhenEvolve make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenEvolve(); }
	};
	typedef struct Sheet_XiuzhenEvolve_s Sheet_XiuzhenEvolve_t;

	struct E_XiuzhenLgtypesAttriDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenLgtypesAttriDesc_s();
		virtual ~E_XiuzhenLgtypesAttriDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_epa;//epa
		int32_t m_np;//np
		int32_t m_value;//value
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLgtypesAttriDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypesAttriDesc & msg);
		static ::proto_ff::E_XiuzhenLgtypesAttriDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLgtypesAttriDesc(); }
		static ::proto_ff::E_XiuzhenLgtypesAttriDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenLgtypesAttriDesc(); }
	};
	typedef struct E_XiuzhenLgtypesAttriDesc_s E_XiuzhenLgtypesAttriDesc_t;

	struct E_XiuzhenLgtypesLgattDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenLgtypesLgattDesc_s();
		virtual ~E_XiuzhenLgtypesLgattDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_lim;//阈值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLgtypesLgattDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypesLgattDesc & msg);
		static ::proto_ff::E_XiuzhenLgtypesLgattDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLgtypesLgattDesc(); }
		static ::proto_ff::E_XiuzhenLgtypesLgattDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenLgtypesLgattDesc(); }
	};
	typedef struct E_XiuzhenLgtypesLgattDesc_s E_XiuzhenLgtypesLgattDesc_t;

	struct E_XiuzhenLgtypes_s : public NFDescStoreSeqOP {
		E_XiuzhenLgtypes_s();
		virtual ~E_XiuzhenLgtypes_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//灵根类型
		NFShmString<64> m_name;//名称
		NFShmString<64> m_shortname;//名称
		NFShmString<64> m_namecolor;//tips信息中名称的颜色
		NFShmString<64> m_bookmodel;//锁模型
		NFShmString<64> m_bodymodel;//灵根模型
		int32_t m_unlockbook;//解锁需要的心法
		int32_t m_bookcount;//心法数量
		int32_t m_addpoints;//每升一级加多少点
		NFShmVector<struct E_XiuzhenLgtypesAttriDesc_s, DEFINE_E_XIUZHENLGTYPES_M_ATTRI_MAX_NUM> m_attri;//属性
		NFShmVector<struct E_XiuzhenLgtypesLgattDesc_s, DEFINE_E_XIUZHENLGTYPES_M_LGATT_MAX_NUM> m_lgatt;//灵根属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLgtypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypes & msg);
		static ::proto_ff::E_XiuzhenLgtypes* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLgtypes(); }
		static ::proto_ff::E_XiuzhenLgtypes make_pbmsg(){ return ::proto_ff::E_XiuzhenLgtypes(); }
	};
	typedef struct E_XiuzhenLgtypes_s E_XiuzhenLgtypes_t;

	struct Sheet_XiuzhenLgtypes_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenLgtypes_s();
		virtual ~Sheet_XiuzhenLgtypes_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenLgtypes_s, DEFINE_SHEET_XIUZHENLGTYPES_E_XIUZHENLGTYPES_LIST_MAX_NUM> E_XiuzhenLgtypes_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenLgtypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLgtypes & msg);
		static ::proto_ff::Sheet_XiuzhenLgtypes* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenLgtypes(); }
		static ::proto_ff::Sheet_XiuzhenLgtypes make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenLgtypes(); }
	};
	typedef struct Sheet_XiuzhenLgtypes_s Sheet_XiuzhenLgtypes_t;

	struct E_XiuzhenLglvlup_s : public NFDescStoreSeqOP {
		E_XiuzhenLglvlup_s();
		virtual ~E_XiuzhenLglvlup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//等级
		int64_t m_needxw;//消耗修为

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLglvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLglvlup & msg);
		static ::proto_ff::E_XiuzhenLglvlup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLglvlup(); }
		static ::proto_ff::E_XiuzhenLglvlup make_pbmsg(){ return ::proto_ff::E_XiuzhenLglvlup(); }
	};
	typedef struct E_XiuzhenLglvlup_s E_XiuzhenLglvlup_t;

	struct Sheet_XiuzhenLglvlup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenLglvlup_s();
		virtual ~Sheet_XiuzhenLglvlup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenLglvlup_s, DEFINE_SHEET_XIUZHENLGLVLUP_E_XIUZHENLGLVLUP_LIST_MAX_NUM> E_XiuzhenLglvlup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenLglvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLglvlup & msg);
		static ::proto_ff::Sheet_XiuzhenLglvlup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenLglvlup(); }
		static ::proto_ff::Sheet_XiuzhenLglvlup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenLglvlup(); }
	};
	typedef struct Sheet_XiuzhenLglvlup_s Sheet_XiuzhenLglvlup_t;

	struct E_XiuzhenLgpotionsLgDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenLgpotionsLgDesc_s();
		virtual ~E_XiuzhenLgpotionsLgDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLgpotionsLgDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLgpotionsLgDesc & msg);
		static ::proto_ff::E_XiuzhenLgpotionsLgDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLgpotionsLgDesc(); }
		static ::proto_ff::E_XiuzhenLgpotionsLgDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenLgpotionsLgDesc(); }
	};
	typedef struct E_XiuzhenLgpotionsLgDesc_s E_XiuzhenLgpotionsLgDesc_t;

	struct E_XiuzhenLgpotions_s : public NFDescStoreSeqOP {
		E_XiuzhenLgpotions_s();
		virtual ~E_XiuzhenLgpotions_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//物品id
		NFShmVector<struct E_XiuzhenLgpotionsLgDesc_s, DEFINE_E_XIUZHENLGPOTIONS_M_LG_MAX_NUM> m_lg;//加点

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenLgpotions & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenLgpotions & msg);
		static ::proto_ff::E_XiuzhenLgpotions* new_pbmsg(){ return new ::proto_ff::E_XiuzhenLgpotions(); }
		static ::proto_ff::E_XiuzhenLgpotions make_pbmsg(){ return ::proto_ff::E_XiuzhenLgpotions(); }
	};
	typedef struct E_XiuzhenLgpotions_s E_XiuzhenLgpotions_t;

	struct Sheet_XiuzhenLgpotions_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenLgpotions_s();
		virtual ~Sheet_XiuzhenLgpotions_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenLgpotions_s, DEFINE_SHEET_XIUZHENLGPOTIONS_E_XIUZHENLGPOTIONS_LIST_MAX_NUM> E_XiuzhenLgpotions_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenLgpotions & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLgpotions & msg);
		static ::proto_ff::Sheet_XiuzhenLgpotions* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenLgpotions(); }
		static ::proto_ff::Sheet_XiuzhenLgpotions make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenLgpotions(); }
	};
	typedef struct Sheet_XiuzhenLgpotions_s Sheet_XiuzhenLgpotions_t;

	struct E_XiuzhenGftypes_s : public NFDescStoreSeqOP {
		E_XiuzhenGftypes_s();
		virtual ~E_XiuzhenGftypes_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//功法类型
		NFShmString<64> m_name;//功法名称
		NFShmString<64> m_icon;//功法图标
		int32_t m_activationitem;//激活消耗道具
		int32_t m_itemnum;//道具数量
		int32_t m_buylv;//购买等级
		int32_t m_rechargeid;//充值id

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGftypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGftypes & msg);
		static ::proto_ff::E_XiuzhenGftypes* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGftypes(); }
		static ::proto_ff::E_XiuzhenGftypes make_pbmsg(){ return ::proto_ff::E_XiuzhenGftypes(); }
	};
	typedef struct E_XiuzhenGftypes_s E_XiuzhenGftypes_t;

	struct Sheet_XiuzhenGftypes_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGftypes_s();
		virtual ~Sheet_XiuzhenGftypes_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGftypes_s, DEFINE_SHEET_XIUZHENGFTYPES_E_XIUZHENGFTYPES_LIST_MAX_NUM> E_XiuzhenGftypes_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGftypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGftypes & msg);
		static ::proto_ff::Sheet_XiuzhenGftypes* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGftypes(); }
		static ::proto_ff::Sheet_XiuzhenGftypes make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGftypes(); }
	};
	typedef struct Sheet_XiuzhenGftypes_s Sheet_XiuzhenGftypes_t;

	struct E_XiuzhenGflvlupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenGflvlupAttributeDesc_s();
		virtual ~E_XiuzhenGflvlupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGflvlupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGflvlupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenGflvlupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGflvlupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenGflvlupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenGflvlupAttributeDesc(); }
	};
	typedef struct E_XiuzhenGflvlupAttributeDesc_s E_XiuzhenGflvlupAttributeDesc_t;

	struct E_XiuzhenGflvlup_s : public NFDescStoreSeqOP {
		E_XiuzhenGflvlup_s();
		virtual ~E_XiuzhenGflvlup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//功法类型
		int32_t m_first_level;//小周天等级
		int32_t m_middle_level;//大周天等级
		int32_t m_high_level;//几重天
		int32_t m_roushen_level;//所需肉身等级
		int32_t m_itemid;//材料ID
		int32_t m_itemnum;//数量
		int32_t m_xw;//需要修为
		int32_t m_awakeskill;//觉醒技能
		int32_t m_awakeskilllvl;//觉醒技能等级
		int32_t m_specialattriid;//specialAttriId
		int32_t m_specialattrivalue;//specialAttriValue
		NFShmVector<struct E_XiuzhenGflvlupAttributeDesc_s, DEFINE_E_XIUZHENGFLVLUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGflvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGflvlup & msg);
		static ::proto_ff::E_XiuzhenGflvlup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGflvlup(); }
		static ::proto_ff::E_XiuzhenGflvlup make_pbmsg(){ return ::proto_ff::E_XiuzhenGflvlup(); }
	};
	typedef struct E_XiuzhenGflvlup_s E_XiuzhenGflvlup_t;

	struct Sheet_XiuzhenGflvlup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGflvlup_s();
		virtual ~Sheet_XiuzhenGflvlup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGflvlup_s, DEFINE_SHEET_XIUZHENGFLVLUP_E_XIUZHENGFLVLUP_LIST_MAX_NUM> E_XiuzhenGflvlup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGflvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGflvlup & msg);
		static ::proto_ff::Sheet_XiuzhenGflvlup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGflvlup(); }
		static ::proto_ff::Sheet_XiuzhenGflvlup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGflvlup(); }
	};
	typedef struct Sheet_XiuzhenGflvlup_s Sheet_XiuzhenGflvlup_t;

	struct E_XiuzhenGfstageupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenGfstageupAttributeDesc_s();
		virtual ~E_XiuzhenGfstageupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGfstageupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGfstageupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenGfstageupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGfstageupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenGfstageupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenGfstageupAttributeDesc(); }
	};
	typedef struct E_XiuzhenGfstageupAttributeDesc_s E_XiuzhenGfstageupAttributeDesc_t;

	struct E_XiuzhenGfstageup_s : public NFDescStoreSeqOP {
		E_XiuzhenGfstageup_s();
		virtual ~E_XiuzhenGfstageup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//功法类型
		int32_t m_high_level;//阶级
		NFShmString<64> m_highlevel_icon;//阶级图标
		int32_t m_itemid;//材料ID
		int32_t m_itemnum;//数量
		int32_t m_awakeskill1;//觉醒技能
		int32_t m_awakeskilllvl1;//觉醒技能等级
		int32_t m_awakeskill2;//觉醒技能
		int32_t m_awakeskilllvl2;//觉醒技能等级
		NFShmVector<struct E_XiuzhenGfstageupAttributeDesc_s, DEFINE_E_XIUZHENGFSTAGEUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenGfstageup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenGfstageup & msg);
		static ::proto_ff::E_XiuzhenGfstageup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenGfstageup(); }
		static ::proto_ff::E_XiuzhenGfstageup make_pbmsg(){ return ::proto_ff::E_XiuzhenGfstageup(); }
	};
	typedef struct E_XiuzhenGfstageup_s E_XiuzhenGfstageup_t;

	struct Sheet_XiuzhenGfstageup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenGfstageup_s();
		virtual ~Sheet_XiuzhenGfstageup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenGfstageup_s, DEFINE_SHEET_XIUZHENGFSTAGEUP_E_XIUZHENGFSTAGEUP_LIST_MAX_NUM> E_XiuzhenGfstageup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenGfstageup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGfstageup & msg);
		static ::proto_ff::Sheet_XiuzhenGfstageup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenGfstageup(); }
		static ::proto_ff::Sheet_XiuzhenGfstageup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenGfstageup(); }
	};
	typedef struct Sheet_XiuzhenGfstageup_s Sheet_XiuzhenGfstageup_t;

	struct E_XiuzhenJmtypes_s : public NFDescStoreSeqOP {
		E_XiuzhenJmtypes_s();
		virtual ~E_XiuzhenJmtypes_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//类型
		int32_t m_gongfa;//对应功法

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmtypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmtypes & msg);
		static ::proto_ff::E_XiuzhenJmtypes* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmtypes(); }
		static ::proto_ff::E_XiuzhenJmtypes make_pbmsg(){ return ::proto_ff::E_XiuzhenJmtypes(); }
	};
	typedef struct E_XiuzhenJmtypes_s E_XiuzhenJmtypes_t;

	struct Sheet_XiuzhenJmtypes_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenJmtypes_s();
		virtual ~Sheet_XiuzhenJmtypes_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenJmtypes_s, DEFINE_SHEET_XIUZHENJMTYPES_E_XIUZHENJMTYPES_LIST_MAX_NUM> E_XiuzhenJmtypes_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmtypes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmtypes & msg);
		static ::proto_ff::Sheet_XiuzhenJmtypes* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenJmtypes(); }
		static ::proto_ff::Sheet_XiuzhenJmtypes make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenJmtypes(); }
	};
	typedef struct Sheet_XiuzhenJmtypes_s Sheet_XiuzhenJmtypes_t;

	struct E_XiuzhenJmlvlupItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmlvlupItemDesc_s();
		virtual ~E_XiuzhenJmlvlupItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlupItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlupItemDesc & msg);
		static ::proto_ff::E_XiuzhenJmlvlupItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmlvlupItemDesc(); }
		static ::proto_ff::E_XiuzhenJmlvlupItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmlvlupItemDesc(); }
	};
	typedef struct E_XiuzhenJmlvlupItemDesc_s E_XiuzhenJmlvlupItemDesc_t;

	struct E_XiuzhenJmlvlupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmlvlupAttributeDesc_s();
		virtual ~E_XiuzhenJmlvlupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenJmlvlupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmlvlupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenJmlvlupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmlvlupAttributeDesc(); }
	};
	typedef struct E_XiuzhenJmlvlupAttributeDesc_s E_XiuzhenJmlvlupAttributeDesc_t;

	struct E_XiuzhenJmlvlup_s : public NFDescStoreSeqOP {
		E_XiuzhenJmlvlup_s();
		virtual ~E_XiuzhenJmlvlup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//经脉类型
		int32_t m_lvl;//等级
		int64_t m_needxw;//消耗修为
		int32_t m_success_rate;//成功率
		int32_t m_specialattriid;//特殊属性id
		int32_t m_specialattrivalue;//特殊属性变量
		NFShmVector<struct E_XiuzhenJmlvlupItemDesc_s, DEFINE_E_XIUZHENJMLVLUP_M_ITEM_MAX_NUM> m_item;//材料
		NFShmVector<struct E_XiuzhenJmlvlupAttributeDesc_s, DEFINE_E_XIUZHENJMLVLUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlup & msg);
		static ::proto_ff::E_XiuzhenJmlvlup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmlvlup(); }
		static ::proto_ff::E_XiuzhenJmlvlup make_pbmsg(){ return ::proto_ff::E_XiuzhenJmlvlup(); }
	};
	typedef struct E_XiuzhenJmlvlup_s E_XiuzhenJmlvlup_t;

	struct Sheet_XiuzhenJmlvlup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenJmlvlup_s();
		virtual ~Sheet_XiuzhenJmlvlup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenJmlvlup_s, DEFINE_SHEET_XIUZHENJMLVLUP_E_XIUZHENJMLVLUP_LIST_MAX_NUM> E_XiuzhenJmlvlup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmlvlup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmlvlup & msg);
		static ::proto_ff::Sheet_XiuzhenJmlvlup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenJmlvlup(); }
		static ::proto_ff::Sheet_XiuzhenJmlvlup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenJmlvlup(); }
	};
	typedef struct Sheet_XiuzhenJmlvlup_s Sheet_XiuzhenJmlvlup_t;

	struct E_XiuzhenJmstageupItemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmstageupItemDesc_s();
		virtual ~E_XiuzhenJmstageupItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmstageupItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageupItemDesc & msg);
		static ::proto_ff::E_XiuzhenJmstageupItemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmstageupItemDesc(); }
		static ::proto_ff::E_XiuzhenJmstageupItemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmstageupItemDesc(); }
	};
	typedef struct E_XiuzhenJmstageupItemDesc_s E_XiuzhenJmstageupItemDesc_t;

	struct E_XiuzhenJmstageupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmstageupAttributeDesc_s();
		virtual ~E_XiuzhenJmstageupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmstageupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenJmstageupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmstageupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenJmstageupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmstageupAttributeDesc(); }
	};
	typedef struct E_XiuzhenJmstageupAttributeDesc_s E_XiuzhenJmstageupAttributeDesc_t;

	struct E_XiuzhenJmstageup_s : public NFDescStoreSeqOP {
		E_XiuzhenJmstageup_s();
		virtual ~E_XiuzhenJmstageup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//经脉类型
		int32_t m_stage;//品阶
		NFShmString<64> m_name;//名称
		int32_t m_needgfunlock;//需要解锁功法ID
		int32_t m_success_rate;//成功率
		int32_t m_blessing;//失败增加祝福值
		int32_t m_awakeskillid;//觉醒技能
		int32_t m_awakeskilllvl;//觉醒技能等级
		NFShmVector<struct E_XiuzhenJmstageupItemDesc_s, DEFINE_E_XIUZHENJMSTAGEUP_M_ITEM_MAX_NUM> m_item;//材料
		NFShmVector<struct E_XiuzhenJmstageupAttributeDesc_s, DEFINE_E_XIUZHENJMSTAGEUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmstageup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageup & msg);
		static ::proto_ff::E_XiuzhenJmstageup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmstageup(); }
		static ::proto_ff::E_XiuzhenJmstageup make_pbmsg(){ return ::proto_ff::E_XiuzhenJmstageup(); }
	};
	typedef struct E_XiuzhenJmstageup_s E_XiuzhenJmstageup_t;

	struct Sheet_XiuzhenJmstageup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenJmstageup_s();
		virtual ~Sheet_XiuzhenJmstageup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenJmstageup_s, DEFINE_SHEET_XIUZHENJMSTAGEUP_E_XIUZHENJMSTAGEUP_LIST_MAX_NUM> E_XiuzhenJmstageup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmstageup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmstageup & msg);
		static ::proto_ff::Sheet_XiuzhenJmstageup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenJmstageup(); }
		static ::proto_ff::Sheet_XiuzhenJmstageup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenJmstageup(); }
	};
	typedef struct Sheet_XiuzhenJmstageup_s Sheet_XiuzhenJmstageup_t;

	struct E_XiuzhenJmmergeupCsDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmmergeupCsDesc_s();
		virtual ~E_XiuzhenJmmergeupCsDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_stage;//品阶
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeupCsDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeupCsDesc & msg);
		static ::proto_ff::E_XiuzhenJmmergeupCsDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmmergeupCsDesc(); }
		static ::proto_ff::E_XiuzhenJmmergeupCsDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmmergeupCsDesc(); }
	};
	typedef struct E_XiuzhenJmmergeupCsDesc_s E_XiuzhenJmmergeupCsDesc_t;

	struct E_XiuzhenJmmergeupAttributeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenJmmergeupAttributeDesc_s();
		virtual ~E_XiuzhenJmmergeupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeupAttributeDesc & msg);
		static ::proto_ff::E_XiuzhenJmmergeupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmmergeupAttributeDesc(); }
		static ::proto_ff::E_XiuzhenJmmergeupAttributeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenJmmergeupAttributeDesc(); }
	};
	typedef struct E_XiuzhenJmmergeupAttributeDesc_s E_XiuzhenJmmergeupAttributeDesc_t;

	struct E_XiuzhenJmmergeup_s : public NFDescStoreSeqOP {
		E_XiuzhenJmmergeup_s();
		virtual ~E_XiuzhenJmmergeup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//合俱品级
		int32_t m_gf_type;//功法类型
		int32_t m_awakeskillid;//觉醒技能
		int32_t m_awakeskilllvl;//asdfas
		NFShmVector<struct E_XiuzhenJmmergeupCsDesc_s, DEFINE_E_XIUZHENJMMERGEUP_M_CS_MAX_NUM> m_cs;//需要品阶
		NFShmVector<struct E_XiuzhenJmmergeupAttributeDesc_s, DEFINE_E_XIUZHENJMMERGEUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeup & msg);
		static ::proto_ff::E_XiuzhenJmmergeup* new_pbmsg(){ return new ::proto_ff::E_XiuzhenJmmergeup(); }
		static ::proto_ff::E_XiuzhenJmmergeup make_pbmsg(){ return ::proto_ff::E_XiuzhenJmmergeup(); }
	};
	typedef struct E_XiuzhenJmmergeup_s E_XiuzhenJmmergeup_t;

	struct Sheet_XiuzhenJmmergeup_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenJmmergeup_s();
		virtual ~Sheet_XiuzhenJmmergeup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenJmmergeup_s, DEFINE_SHEET_XIUZHENJMMERGEUP_E_XIUZHENJMMERGEUP_LIST_MAX_NUM> E_XiuzhenJmmergeup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmmergeup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmmergeup & msg);
		static ::proto_ff::Sheet_XiuzhenJmmergeup* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenJmmergeup(); }
		static ::proto_ff::Sheet_XiuzhenJmmergeup make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenJmmergeup(); }
	};
	typedef struct Sheet_XiuzhenJmmergeup_s Sheet_XiuzhenJmmergeup_t;

	struct E_XiuzhenPrivilegePtaddDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenPrivilegePtaddDesc_s();
		virtual ~E_XiuzhenPrivilegePtaddDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_v;//变量
		NFShmString<64> m_n;//名称
		int32_t m_t;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenPrivilegePtaddDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilegePtaddDesc & msg);
		static ::proto_ff::E_XiuzhenPrivilegePtaddDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenPrivilegePtaddDesc(); }
		static ::proto_ff::E_XiuzhenPrivilegePtaddDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenPrivilegePtaddDesc(); }
	};
	typedef struct E_XiuzhenPrivilegePtaddDesc_s E_XiuzhenPrivilegePtaddDesc_t;

	struct E_XiuzhenPrivilegeAttriDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenPrivilegeAttriDesc_s();
		virtual ~E_XiuzhenPrivilegeAttriDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_v;//值
		int32_t m_t;//类型

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenPrivilegeAttriDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilegeAttriDesc & msg);
		static ::proto_ff::E_XiuzhenPrivilegeAttriDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenPrivilegeAttriDesc(); }
		static ::proto_ff::E_XiuzhenPrivilegeAttriDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenPrivilegeAttriDesc(); }
	};
	typedef struct E_XiuzhenPrivilegeAttriDesc_s E_XiuzhenPrivilegeAttriDesc_t;

	struct E_XiuzhenPrivilege_s : public NFDescStoreSeqOP {
		E_XiuzhenPrivilege_s();
		virtual ~E_XiuzhenPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//类型
		int32_t m_price;//价格
		int32_t m_activeavatar;//激活外观
		NFShmString<64> m_avatarname;//外观名
		NFShmVector<struct E_XiuzhenPrivilegePtaddDesc_s, DEFINE_E_XIUZHENPRIVILEGE_M_PTADD_MAX_NUM> m_ptadd;//修真曾益
		NFShmVector<struct E_XiuzhenPrivilegeAttriDesc_s, DEFINE_E_XIUZHENPRIVILEGE_M_ATTRI_MAX_NUM> m_attri;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilege & msg);
		static ::proto_ff::E_XiuzhenPrivilege* new_pbmsg(){ return new ::proto_ff::E_XiuzhenPrivilege(); }
		static ::proto_ff::E_XiuzhenPrivilege make_pbmsg(){ return ::proto_ff::E_XiuzhenPrivilege(); }
	};
	typedef struct E_XiuzhenPrivilege_s E_XiuzhenPrivilege_t;

	struct Sheet_XiuzhenPrivilege_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenPrivilege_s();
		virtual ~Sheet_XiuzhenPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenPrivilege_s, DEFINE_SHEET_XIUZHENPRIVILEGE_E_XIUZHENPRIVILEGE_LIST_MAX_NUM> E_XiuzhenPrivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenPrivilege & msg);
		static ::proto_ff::Sheet_XiuzhenPrivilege* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenPrivilege(); }
		static ::proto_ff::Sheet_XiuzhenPrivilege make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenPrivilege(); }
	};
	typedef struct Sheet_XiuzhenPrivilege_s Sheet_XiuzhenPrivilege_t;

}

