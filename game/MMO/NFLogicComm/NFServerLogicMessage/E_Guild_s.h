#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Guild.pb.h"
#include "E_Guild_s.h"

#define DEFINE_SHEET_GUILDCONSTANT_E_GUILDCONSTANT_LIST_MAX_NUM 128
#define DEFINE_SHEET_GUILDLEVEL_E_GUILDLEVEL_LIST_MAX_NUM 16
#define DEFINE_SHEET_GUILDPOSITION_E_GUILDPOSITION_LIST_MAX_NUM 8
#define DEFINE_E_GUILDSALARY_M_REWARD_MAX_NUM 3
#define DEFINE_SHEET_GUILDSALARY_E_GUILDSALARY_LIST_MAX_NUM 8
#define DEFINE_E_GUILDDONATE_M_REWARD_MAX_NUM 3
#define DEFINE_SHEET_GUILDDONATE_E_GUILDDONATE_LIST_MAX_NUM 4
#define DEFINE_SHEET_GUILDPACKET_E_GUILDPACKET_LIST_MAX_NUM 128
#define DEFINE_SHEET_GUILDPRESTIGETASK_E_GUILDPRESTIGETASK_LIST_MAX_NUM 16
#define DEFINE_SHEET_GUILDLVREWARD_E_GUILDLVREWARD_LIST_MAX_NUM 512
#define DEFINE_E_GUILDCOLLEGE_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_GUILDCOLLEGE_E_GUILDCOLLEGE_LIST_MAX_NUM 16384
#define DEFINE_SHEET_GUILDANSWER_E_GUILDANSWER_LIST_MAX_NUM 64
#define DEFINE_SHEET_GUILDRANK_REWARD_E_GUILDRANK_REWARD_LIST_MAX_NUM 256
#define DEFINE_E_GUILDSHOUHSKILL_M_REWARD_MAX_NUM 2
#define DEFINE_SHEET_GUILDSHOUHSKILL_E_GUILDSHOUHSKILL_LIST_MAX_NUM 8
#define DEFINE_E_GUILDGWREWARD_M_ARG_MAX_NUM 3
#define DEFINE_SHEET_GUILDGWREWARD_E_GUILDGWREWARD_LIST_MAX_NUM 128
#define DEFINE_SHEET_GUILDGWWINSTREAK_E_GUILDGWWINSTREAK_LIST_MAX_NUM 32
#define DEFINE_SHEET_GUILDTTOWER_E_GUILDTTOWER_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_GuildConstant_s : public NFDescStoreSeqOP {
		E_GuildConstant_s();
		virtual ~E_GuildConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_constantid;//配置id
		int32_t m_setitem;//创建公会需要道具ID
		int32_t m_nameitem;//公会改名需要道具ID
		int32_t m_editrequirelv;//修改公会公告要求公告等级
		int32_t m_giftcd;//红包清理时间
		int32_t m_dismiss;//解散公会时间
		int32_t m_transferguild;//代理会长可申请时间
		int32_t m_territory;//公会领地场景id
		int32_t m_autominlv;//自动审批最低等级
		int32_t m_autominbp;//自动审批最低战力
		int32_t m_donatetimes;//捐款次数
		int32_t m_packetmaxd;//红包绑钻每日限制
		int32_t m_packetmaxbd;//红包魔晶每日限制
		int32_t m_packetmaxsend;//自费红包限制
		int32_t m_packetvip;//红包加成的vip等级
		int32_t m_packetadd;//红包加成比例
		int32_t m_prestigetasonekeyvip;//声望任务一键vip
		int32_t m_prestigetasonekeylv;//声望任务一键viplv
		int32_t m_prestigetaskprivage;//声望任务特权id
		int32_t m_prestigetaskflash;//声望任务免费刷新次数
		int32_t m_prestigetaskflashprice;//声望任务付费刷新价格
		int32_t m_prestigetasktimes;//声望任务每日次数
		int32_t m_rewardcd;//晚宴持续收益间隔
		int32_t m_answerdelay;//晚宴答题间隔
		int32_t m_answernum;//题目数
		int32_t m_answertime;//每道题的最长作答事件
		int32_t m_answerresulttime;//每道题的答案时间
		int32_t m_answerlimit;//答题限时奖励
		int32_t m_answerfirst;//答题首答奖励
		int32_t m_answersuccess;//答题答对奖励
		int32_t m_answebasics;//答题安慰奖励
		int32_t m_linklvupper;//传功每级提高经验万分比
		int32_t m_linklvupmax;//传功提高经验上限
		int32_t m_linktime;//传功的行为时间
		int32_t m_monsterid;//采集物id
		int32_t m_point;//采集物刷新点
		int32_t m_collecttimes;//每次开启可采集次数
		int32_t m_shens_daytimes;//神兽每日次数
		int32_t m_shens_weektimes;//神兽每周次数
		int32_t m_shens_dup;//神兽副本id
		int32_t m_shensitem;//神兽祭品id
		int32_t m_shenscost;//神兽祭品消耗
		int32_t m_shenscostactive;//神兽祭品消耗
		int32_t m_shouh_dup;//守护副本id
		int32_t m_shouhexpskill;//守护副本技能
		NFShmString<64> m_shouhmosid;//守护npcid
		int32_t m_gwdupid;//帮派战副本id
		int32_t m_gwbattletime;//帮派战单场时间
		int32_t m_gwresttime;//帮派战休息时间
		int32_t m_gwcentermid;//帮派战水晶怪物id
		int32_t m_gwtowermid;//帮派战塔怪物id
		int32_t m_gwtankmid;//帮派战车怪物id
		int32_t m_gwbornrpoint;//帮派战红出生point
		int32_t m_gwcenterrpoint;//帮派战红水晶point
		NFShmString<64> m_gwtowerrpoint;//帮派战红塔point
		int32_t m_gwtankrpoint;//帮派红战车point
		int32_t m_gwbornbpoint;//帮派战蓝出生point
		int32_t m_gwcenterbpoint;//帮派战蓝水晶point
		NFShmString<64> m_gwtowerbpoint;//帮派战蓝塔point
		int32_t m_gwtankbpoint;//帮派蓝战车point
		int32_t m_tanknum;//战车初始数量
		int32_t m_tankresttime;//战车补充间隔
		int32_t m_tankrestnum;//战车补充数量
		int32_t m_dominatedaily;//主宰神殿每日奖励
		int32_t m_dominatebossreward;//主宰神殿会长临时奖励
		int32_t m_freepoint;//每次获得的积分
		int32_t m_deffreepoint;//处于防御塔范围额外积分
		int32_t m_playerpoint;//击杀玩家积分
		int32_t m_tankpoint;//击杀工程车积分
		int32_t m_towerpoint;//机破防御塔积分
		int32_t m_centerpoint;//水晶积分
		int32_t m_assistradio;//助攻的积分系数
		int32_t m_tteamdamageadd;//组队增加伤害
		int32_t m_tweekclosetime;//周结算前关闭时间
		int32_t m_cyclicreward;//周环任务普通奖励
		int32_t m_tencyclicreward;//周环任务十环奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildConstant & msg);
		static ::proto_ff::E_GuildConstant* new_pbmsg(){ return new ::proto_ff::E_GuildConstant(); }
		static ::proto_ff::E_GuildConstant make_pbmsg(){ return ::proto_ff::E_GuildConstant(); }
	};
	typedef struct E_GuildConstant_s E_GuildConstant_t;

	struct Sheet_GuildConstant_s : public NFDescStoreSeqOP {
		Sheet_GuildConstant_s();
		virtual ~Sheet_GuildConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildConstant_s, DEFINE_SHEET_GUILDCONSTANT_E_GUILDCONSTANT_LIST_MAX_NUM> E_GuildConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildConstant & msg);
		static ::proto_ff::Sheet_GuildConstant* new_pbmsg(){ return new ::proto_ff::Sheet_GuildConstant(); }
		static ::proto_ff::Sheet_GuildConstant make_pbmsg(){ return ::proto_ff::Sheet_GuildConstant(); }
	};
	typedef struct Sheet_GuildConstant_s Sheet_GuildConstant_t;

	struct E_GuildLevel_s : public NFDescStoreSeqOP {
		E_GuildLevel_s();
		virtual ~E_GuildLevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_guildlevel;//公会等级
		int32_t m_guildlevel_exp;//公会升级经验
		int32_t m_guildlevel_member;//公会成员总人数
		int32_t m_guildlevel_vp;//公会副会长人数
		int32_t m_guildlevel_np;//公会长老数
		int32_t m_guildlevel_g;//护法人数

		virtual void write_to_pbmsg(::proto_ff::E_GuildLevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildLevel & msg);
		static ::proto_ff::E_GuildLevel* new_pbmsg(){ return new ::proto_ff::E_GuildLevel(); }
		static ::proto_ff::E_GuildLevel make_pbmsg(){ return ::proto_ff::E_GuildLevel(); }
	};
	typedef struct E_GuildLevel_s E_GuildLevel_t;

	struct Sheet_GuildLevel_s : public NFDescStoreSeqOP {
		Sheet_GuildLevel_s();
		virtual ~Sheet_GuildLevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildLevel_s, DEFINE_SHEET_GUILDLEVEL_E_GUILDLEVEL_LIST_MAX_NUM> E_GuildLevel_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildLevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildLevel & msg);
		static ::proto_ff::Sheet_GuildLevel* new_pbmsg(){ return new ::proto_ff::Sheet_GuildLevel(); }
		static ::proto_ff::Sheet_GuildLevel make_pbmsg(){ return ::proto_ff::Sheet_GuildLevel(); }
	};
	typedef struct Sheet_GuildLevel_s Sheet_GuildLevel_t;

	struct E_GuildPosition_s : public NFDescStoreSeqOP {
		E_GuildPosition_s();
		virtual ~E_GuildPosition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_positionid;//职位ID
		int32_t m_admitnewcomer;//接收新成员
		int32_t m_appointandremovevp;//任命/解除副会长
		int32_t m_appointandremoveelder;//任命/解除长老
		int32_t m_appointandremoveg;//任命/解除护法
		int32_t m_appointandremoveelite;//任命/解除精英
		int32_t m_expelvp;//踢出副会长
		int32_t m_expelelder;//踢出长老
		int32_t m_expelg;//踢出护法
		int32_t m_expelmass;//踢出普通成员
		int32_t m_announcementediting;//编辑公告
		int32_t m_rname;//修改名字
		int32_t m_joincondition;//设置加入方式
		int32_t m_guildactivity;//开启公会玩法
		int32_t m_dissolveassignguild;//解散/转让公会
		int32_t m_changename;//改名权限
		int32_t m_recruitchat;//发布招贤纳士
		int32_t m_guildpacket;//发送公会玩法红包

		virtual void write_to_pbmsg(::proto_ff::E_GuildPosition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPosition & msg);
		static ::proto_ff::E_GuildPosition* new_pbmsg(){ return new ::proto_ff::E_GuildPosition(); }
		static ::proto_ff::E_GuildPosition make_pbmsg(){ return ::proto_ff::E_GuildPosition(); }
	};
	typedef struct E_GuildPosition_s E_GuildPosition_t;

	struct Sheet_GuildPosition_s : public NFDescStoreSeqOP {
		Sheet_GuildPosition_s();
		virtual ~Sheet_GuildPosition_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPosition_s, DEFINE_SHEET_GUILDPOSITION_E_GUILDPOSITION_LIST_MAX_NUM> E_GuildPosition_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPosition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPosition & msg);
		static ::proto_ff::Sheet_GuildPosition* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPosition(); }
		static ::proto_ff::Sheet_GuildPosition make_pbmsg(){ return ::proto_ff::Sheet_GuildPosition(); }
	};
	typedef struct Sheet_GuildPosition_s Sheet_GuildPosition_t;

	struct E_GuildSalaryRewardDesc_s : public NFDescStoreSeqOP {
		E_GuildSalaryRewardDesc_s();
		virtual ~E_GuildSalaryRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//物品

		virtual void write_to_pbmsg(::proto_ff::E_GuildSalaryRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildSalaryRewardDesc & msg);
		static ::proto_ff::E_GuildSalaryRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GuildSalaryRewardDesc(); }
		static ::proto_ff::E_GuildSalaryRewardDesc make_pbmsg(){ return ::proto_ff::E_GuildSalaryRewardDesc(); }
	};
	typedef struct E_GuildSalaryRewardDesc_s E_GuildSalaryRewardDesc_t;

	struct E_GuildSalary_s : public NFDescStoreSeqOP {
		E_GuildSalary_s();
		virtual ~E_GuildSalary_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_type;//任务类型
		int32_t m_typearg;//类型参数
		int32_t m_times;//次数参数
		NFShmVector<struct E_GuildSalaryRewardDesc_s, DEFINE_E_GUILDSALARY_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildSalary & msg);
		static ::proto_ff::E_GuildSalary* new_pbmsg(){ return new ::proto_ff::E_GuildSalary(); }
		static ::proto_ff::E_GuildSalary make_pbmsg(){ return ::proto_ff::E_GuildSalary(); }
	};
	typedef struct E_GuildSalary_s E_GuildSalary_t;

	struct Sheet_GuildSalary_s : public NFDescStoreSeqOP {
		Sheet_GuildSalary_s();
		virtual ~Sheet_GuildSalary_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildSalary_s, DEFINE_SHEET_GUILDSALARY_E_GUILDSALARY_LIST_MAX_NUM> E_GuildSalary_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildSalary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildSalary & msg);
		static ::proto_ff::Sheet_GuildSalary* new_pbmsg(){ return new ::proto_ff::Sheet_GuildSalary(); }
		static ::proto_ff::Sheet_GuildSalary make_pbmsg(){ return ::proto_ff::Sheet_GuildSalary(); }
	};
	typedef struct Sheet_GuildSalary_s Sheet_GuildSalary_t;

	struct E_GuildDonateRewardDesc_s : public NFDescStoreSeqOP {
		E_GuildDonateRewardDesc_s();
		virtual ~E_GuildDonateRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//物品

		virtual void write_to_pbmsg(::proto_ff::E_GuildDonateRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildDonateRewardDesc & msg);
		static ::proto_ff::E_GuildDonateRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GuildDonateRewardDesc(); }
		static ::proto_ff::E_GuildDonateRewardDesc make_pbmsg(){ return ::proto_ff::E_GuildDonateRewardDesc(); }
	};
	typedef struct E_GuildDonateRewardDesc_s E_GuildDonateRewardDesc_t;

	struct E_GuildDonate_s : public NFDescStoreSeqOP {
		E_GuildDonate_s();
		virtual ~E_GuildDonate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_costitem;//花费物品id
		int32_t m_costnum;//花费物品数量
		NFShmVector<struct E_GuildDonateRewardDesc_s, DEFINE_E_GUILDDONATE_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildDonate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildDonate & msg);
		static ::proto_ff::E_GuildDonate* new_pbmsg(){ return new ::proto_ff::E_GuildDonate(); }
		static ::proto_ff::E_GuildDonate make_pbmsg(){ return ::proto_ff::E_GuildDonate(); }
	};
	typedef struct E_GuildDonate_s E_GuildDonate_t;

	struct Sheet_GuildDonate_s : public NFDescStoreSeqOP {
		Sheet_GuildDonate_s();
		virtual ~Sheet_GuildDonate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildDonate_s, DEFINE_SHEET_GUILDDONATE_E_GUILDDONATE_LIST_MAX_NUM> E_GuildDonate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildDonate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildDonate & msg);
		static ::proto_ff::Sheet_GuildDonate* new_pbmsg(){ return new ::proto_ff::Sheet_GuildDonate(); }
		static ::proto_ff::Sheet_GuildDonate make_pbmsg(){ return ::proto_ff::Sheet_GuildDonate(); }
	};
	typedef struct Sheet_GuildDonate_s Sheet_GuildDonate_t;

	struct E_GuildPacket_s : public NFDescStoreSeqOP {
		E_GuildPacket_s();
		virtual ~E_GuildPacket_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//红包ID
		int32_t m_belongtype;//红包归属类型
		int32_t m_type;//红包触发类型
		int32_t m_typearg;//类型参数
		int32_t m_itemid;//红包领取类型
		int32_t m_itemnum;//红包金额
		int32_t m_num;//红包份数
		int32_t m_pre;//前置红包
		int32_t m_daily;//每日限制触发次数

		virtual void write_to_pbmsg(::proto_ff::E_GuildPacket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPacket & msg);
		static ::proto_ff::E_GuildPacket* new_pbmsg(){ return new ::proto_ff::E_GuildPacket(); }
		static ::proto_ff::E_GuildPacket make_pbmsg(){ return ::proto_ff::E_GuildPacket(); }
	};
	typedef struct E_GuildPacket_s E_GuildPacket_t;

	struct Sheet_GuildPacket_s : public NFDescStoreSeqOP {
		Sheet_GuildPacket_s();
		virtual ~Sheet_GuildPacket_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPacket_s, DEFINE_SHEET_GUILDPACKET_E_GUILDPACKET_LIST_MAX_NUM> E_GuildPacket_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPacket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPacket & msg);
		static ::proto_ff::Sheet_GuildPacket* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPacket(); }
		static ::proto_ff::Sheet_GuildPacket make_pbmsg(){ return ::proto_ff::Sheet_GuildPacket(); }
	};
	typedef struct Sheet_GuildPacket_s Sheet_GuildPacket_t;

	struct E_GuildPrestigetask_s : public NFDescStoreSeqOP {
		E_GuildPrestigetask_s();
		virtual ~E_GuildPrestigetask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_level;//任务分级
		int32_t m_lvmin;//等级下限
		int32_t m_lvmax;//等级上限
		int32_t m_weight;//权重
		int32_t m_taskpool;//随机的任务池id
		int32_t m_reward;//任务奖励类型id

		virtual void write_to_pbmsg(::proto_ff::E_GuildPrestigetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildPrestigetask & msg);
		static ::proto_ff::E_GuildPrestigetask* new_pbmsg(){ return new ::proto_ff::E_GuildPrestigetask(); }
		static ::proto_ff::E_GuildPrestigetask make_pbmsg(){ return ::proto_ff::E_GuildPrestigetask(); }
	};
	typedef struct E_GuildPrestigetask_s E_GuildPrestigetask_t;

	struct Sheet_GuildPrestigetask_s : public NFDescStoreSeqOP {
		Sheet_GuildPrestigetask_s();
		virtual ~Sheet_GuildPrestigetask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildPrestigetask_s, DEFINE_SHEET_GUILDPRESTIGETASK_E_GUILDPRESTIGETASK_LIST_MAX_NUM> E_GuildPrestigetask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildPrestigetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildPrestigetask & msg);
		static ::proto_ff::Sheet_GuildPrestigetask* new_pbmsg(){ return new ::proto_ff::Sheet_GuildPrestigetask(); }
		static ::proto_ff::Sheet_GuildPrestigetask make_pbmsg(){ return ::proto_ff::Sheet_GuildPrestigetask(); }
	};
	typedef struct Sheet_GuildPrestigetask_s Sheet_GuildPrestigetask_t;

	struct E_GuildLvreward_s : public NFDescStoreSeqOP {
		E_GuildLvreward_s();
		virtual ~E_GuildLvreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_partyexp;//晚宴经验
		int32_t m_partyeontribution;//晚宴贡献
		int32_t m_linkexp;//链接经验

		virtual void write_to_pbmsg(::proto_ff::E_GuildLvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildLvreward & msg);
		static ::proto_ff::E_GuildLvreward* new_pbmsg(){ return new ::proto_ff::E_GuildLvreward(); }
		static ::proto_ff::E_GuildLvreward make_pbmsg(){ return ::proto_ff::E_GuildLvreward(); }
	};
	typedef struct E_GuildLvreward_s E_GuildLvreward_t;

	struct Sheet_GuildLvreward_s : public NFDescStoreSeqOP {
		Sheet_GuildLvreward_s();
		virtual ~Sheet_GuildLvreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildLvreward_s, DEFINE_SHEET_GUILDLVREWARD_E_GUILDLVREWARD_LIST_MAX_NUM> E_GuildLvreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildLvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildLvreward & msg);
		static ::proto_ff::Sheet_GuildLvreward* new_pbmsg(){ return new ::proto_ff::Sheet_GuildLvreward(); }
		static ::proto_ff::Sheet_GuildLvreward make_pbmsg(){ return ::proto_ff::Sheet_GuildLvreward(); }
	};
	typedef struct Sheet_GuildLvreward_s Sheet_GuildLvreward_t;

	struct E_GuildCollegeAttributeDesc_s : public NFDescStoreSeqOP {
		E_GuildCollegeAttributeDesc_s();
		virtual ~E_GuildCollegeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_GuildCollegeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildCollegeAttributeDesc & msg);
		static ::proto_ff::E_GuildCollegeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_GuildCollegeAttributeDesc(); }
		static ::proto_ff::E_GuildCollegeAttributeDesc make_pbmsg(){ return ::proto_ff::E_GuildCollegeAttributeDesc(); }
	};
	typedef struct E_GuildCollegeAttributeDesc_s E_GuildCollegeAttributeDesc_t;

	struct E_GuildCollege_s : public NFDescStoreSeqOP {
		E_GuildCollege_s();
		virtual ~E_GuildCollege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_uid;//唯一id
		int32_t m_skillid;//技能id
		int32_t m_skilllv;//心法等级
		int32_t m_guildlv;//开放学习需求公会等级
		int32_t m_playerlvlimit;//要求玩家等级
		int32_t m_preskillid;//要求前置技能ID
		int32_t m_preskilllv;//要求前置技能等级
		int32_t m_costcontribute;//心法消耗贡献
		NFShmVector<struct E_GuildCollegeAttributeDesc_s, DEFINE_E_GUILDCOLLEGE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_GuildCollege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildCollege & msg);
		static ::proto_ff::E_GuildCollege* new_pbmsg(){ return new ::proto_ff::E_GuildCollege(); }
		static ::proto_ff::E_GuildCollege make_pbmsg(){ return ::proto_ff::E_GuildCollege(); }
	};
	typedef struct E_GuildCollege_s E_GuildCollege_t;

	struct Sheet_GuildCollege_s : public NFDescStoreSeqOP {
		Sheet_GuildCollege_s();
		virtual ~Sheet_GuildCollege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildCollege_s, DEFINE_SHEET_GUILDCOLLEGE_E_GUILDCOLLEGE_LIST_MAX_NUM> E_GuildCollege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildCollege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildCollege & msg);
		static ::proto_ff::Sheet_GuildCollege* new_pbmsg(){ return new ::proto_ff::Sheet_GuildCollege(); }
		static ::proto_ff::Sheet_GuildCollege make_pbmsg(){ return ::proto_ff::Sheet_GuildCollege(); }
	};
	typedef struct Sheet_GuildCollege_s Sheet_GuildCollege_t;

	struct E_GuildAnswer_s : public NFDescStoreSeqOP {
		E_GuildAnswer_s();
		virtual ~E_GuildAnswer_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		NFShmString<64> m_answer;//答案

		virtual void write_to_pbmsg(::proto_ff::E_GuildAnswer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildAnswer & msg);
		static ::proto_ff::E_GuildAnswer* new_pbmsg(){ return new ::proto_ff::E_GuildAnswer(); }
		static ::proto_ff::E_GuildAnswer make_pbmsg(){ return ::proto_ff::E_GuildAnswer(); }
	};
	typedef struct E_GuildAnswer_s E_GuildAnswer_t;

	struct Sheet_GuildAnswer_s : public NFDescStoreSeqOP {
		Sheet_GuildAnswer_s();
		virtual ~Sheet_GuildAnswer_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildAnswer_s, DEFINE_SHEET_GUILDANSWER_E_GUILDANSWER_LIST_MAX_NUM> E_GuildAnswer_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildAnswer & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildAnswer & msg);
		static ::proto_ff::Sheet_GuildAnswer* new_pbmsg(){ return new ::proto_ff::Sheet_GuildAnswer(); }
		static ::proto_ff::Sheet_GuildAnswer make_pbmsg(){ return ::proto_ff::Sheet_GuildAnswer(); }
	};
	typedef struct Sheet_GuildAnswer_s Sheet_GuildAnswer_t;

	struct E_GuildRank_reward_s : public NFDescStoreSeqOP {
		E_GuildRank_reward_s();
		virtual ~E_GuildRank_reward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		NFShmString<64> m_note;//备注
		int32_t m_rankmin;//排名下限
		int32_t m_rankmax;//排名上限
		int32_t m_lvmin;//跨服世界等级下限
		int32_t m_rewards;//服务器奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildRank_reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildRank_reward & msg);
		static ::proto_ff::E_GuildRank_reward* new_pbmsg(){ return new ::proto_ff::E_GuildRank_reward(); }
		static ::proto_ff::E_GuildRank_reward make_pbmsg(){ return ::proto_ff::E_GuildRank_reward(); }
	};
	typedef struct E_GuildRank_reward_s E_GuildRank_reward_t;

	struct Sheet_GuildRank_reward_s : public NFDescStoreSeqOP {
		Sheet_GuildRank_reward_s();
		virtual ~Sheet_GuildRank_reward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildRank_reward_s, DEFINE_SHEET_GUILDRANK_REWARD_E_GUILDRANK_REWARD_LIST_MAX_NUM> E_GuildRank_reward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildRank_reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildRank_reward & msg);
		static ::proto_ff::Sheet_GuildRank_reward* new_pbmsg(){ return new ::proto_ff::Sheet_GuildRank_reward(); }
		static ::proto_ff::Sheet_GuildRank_reward make_pbmsg(){ return ::proto_ff::Sheet_GuildRank_reward(); }
	};
	typedef struct Sheet_GuildRank_reward_s Sheet_GuildRank_reward_t;

	struct E_GuildShouhskillRewardDesc_s : public NFDescStoreSeqOP {
		E_GuildShouhskillRewardDesc_s();
		virtual ~E_GuildShouhskillRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_GuildShouhskillRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildShouhskillRewardDesc & msg);
		static ::proto_ff::E_GuildShouhskillRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GuildShouhskillRewardDesc(); }
		static ::proto_ff::E_GuildShouhskillRewardDesc make_pbmsg(){ return ::proto_ff::E_GuildShouhskillRewardDesc(); }
	};
	typedef struct E_GuildShouhskillRewardDesc_s E_GuildShouhskillRewardDesc_t;

	struct E_GuildShouhskill_s : public NFDescStoreSeqOP {
		E_GuildShouhskill_s();
		virtual ~E_GuildShouhskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名称
		int32_t m_costid;//花费id
		int32_t m_costnum;//花费数量
		int32_t m_skillid;//技能id
		int32_t m_times;//次数
		NFShmVector<struct E_GuildShouhskillRewardDesc_s, DEFINE_E_GUILDSHOUHSKILL_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildShouhskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildShouhskill & msg);
		static ::proto_ff::E_GuildShouhskill* new_pbmsg(){ return new ::proto_ff::E_GuildShouhskill(); }
		static ::proto_ff::E_GuildShouhskill make_pbmsg(){ return ::proto_ff::E_GuildShouhskill(); }
	};
	typedef struct E_GuildShouhskill_s E_GuildShouhskill_t;

	struct Sheet_GuildShouhskill_s : public NFDescStoreSeqOP {
		Sheet_GuildShouhskill_s();
		virtual ~Sheet_GuildShouhskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildShouhskill_s, DEFINE_SHEET_GUILDSHOUHSKILL_E_GUILDSHOUHSKILL_LIST_MAX_NUM> E_GuildShouhskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildShouhskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildShouhskill & msg);
		static ::proto_ff::Sheet_GuildShouhskill* new_pbmsg(){ return new ::proto_ff::Sheet_GuildShouhskill(); }
		static ::proto_ff::Sheet_GuildShouhskill make_pbmsg(){ return ::proto_ff::Sheet_GuildShouhskill(); }
	};
	typedef struct Sheet_GuildShouhskill_s Sheet_GuildShouhskill_t;

	struct E_GuildGwreward_s : public NFDescStoreSeqOP {
		E_GuildGwreward_s();
		virtual ~E_GuildGwreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_type;//类型
		NFShmString<256> m_reward;//本服奖励
		NFShmString<256> m_crossreward;//跨服奖励
		NFShmVector<int32_t, DEFINE_E_GUILDGWREWARD_M_ARG_MAX_NUM> m_arg;//参数

		virtual void write_to_pbmsg(::proto_ff::E_GuildGwreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildGwreward & msg);
		static ::proto_ff::E_GuildGwreward* new_pbmsg(){ return new ::proto_ff::E_GuildGwreward(); }
		static ::proto_ff::E_GuildGwreward make_pbmsg(){ return ::proto_ff::E_GuildGwreward(); }
	};
	typedef struct E_GuildGwreward_s E_GuildGwreward_t;

	struct Sheet_GuildGwreward_s : public NFDescStoreSeqOP {
		Sheet_GuildGwreward_s();
		virtual ~Sheet_GuildGwreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildGwreward_s, DEFINE_SHEET_GUILDGWREWARD_E_GUILDGWREWARD_LIST_MAX_NUM> E_GuildGwreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildGwreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildGwreward & msg);
		static ::proto_ff::Sheet_GuildGwreward* new_pbmsg(){ return new ::proto_ff::Sheet_GuildGwreward(); }
		static ::proto_ff::Sheet_GuildGwreward make_pbmsg(){ return ::proto_ff::Sheet_GuildGwreward(); }
	};
	typedef struct Sheet_GuildGwreward_s Sheet_GuildGwreward_t;

	struct E_GuildGwwinstreak_s : public NFDescStoreSeqOP {
		E_GuildGwwinstreak_s();
		virtual ~E_GuildGwwinstreak_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_winstreak;//连胜数
		int32_t m_winreward;//连胜奖励
		int32_t m_endreward;//终结奖励
		int32_t m_challengeskill;//士气技能

		virtual void write_to_pbmsg(::proto_ff::E_GuildGwwinstreak & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildGwwinstreak & msg);
		static ::proto_ff::E_GuildGwwinstreak* new_pbmsg(){ return new ::proto_ff::E_GuildGwwinstreak(); }
		static ::proto_ff::E_GuildGwwinstreak make_pbmsg(){ return ::proto_ff::E_GuildGwwinstreak(); }
	};
	typedef struct E_GuildGwwinstreak_s E_GuildGwwinstreak_t;

	struct Sheet_GuildGwwinstreak_s : public NFDescStoreSeqOP {
		Sheet_GuildGwwinstreak_s();
		virtual ~Sheet_GuildGwwinstreak_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildGwwinstreak_s, DEFINE_SHEET_GUILDGWWINSTREAK_E_GUILDGWWINSTREAK_LIST_MAX_NUM> E_GuildGwwinstreak_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildGwwinstreak & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildGwwinstreak & msg);
		static ::proto_ff::Sheet_GuildGwwinstreak* new_pbmsg(){ return new ::proto_ff::Sheet_GuildGwwinstreak(); }
		static ::proto_ff::Sheet_GuildGwwinstreak make_pbmsg(){ return ::proto_ff::Sheet_GuildGwwinstreak(); }
	};
	typedef struct Sheet_GuildGwwinstreak_s Sheet_GuildGwwinstreak_t;

	struct E_GuildTtower_s : public NFDescStoreSeqOP {
		E_GuildTtower_s();
		virtual ~E_GuildTtower_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_dupid;//副本id
		int32_t m_breakbox;//通关奖励
		int32_t m_clearbox;//单次结算奖励

		virtual void write_to_pbmsg(::proto_ff::E_GuildTtower & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GuildTtower & msg);
		static ::proto_ff::E_GuildTtower* new_pbmsg(){ return new ::proto_ff::E_GuildTtower(); }
		static ::proto_ff::E_GuildTtower make_pbmsg(){ return ::proto_ff::E_GuildTtower(); }
	};
	typedef struct E_GuildTtower_s E_GuildTtower_t;

	struct Sheet_GuildTtower_s : public NFDescStoreSeqOP {
		Sheet_GuildTtower_s();
		virtual ~Sheet_GuildTtower_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GuildTtower_s, DEFINE_SHEET_GUILDTTOWER_E_GUILDTTOWER_LIST_MAX_NUM> E_GuildTtower_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GuildTtower & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GuildTtower & msg);
		static ::proto_ff::Sheet_GuildTtower* new_pbmsg(){ return new ::proto_ff::Sheet_GuildTtower(); }
		static ::proto_ff::Sheet_GuildTtower make_pbmsg(){ return ::proto_ff::Sheet_GuildTtower(); }
	};
	typedef struct Sheet_GuildTtower_s Sheet_GuildTtower_t;

}

