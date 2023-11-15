#include "ChatDescEx.h"

#include <ComDefine.pb.h>
#include <DescStore/ConstantConstantDesc.h>

ChatDescEx::ChatDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ChatDescEx::~ChatDescEx()
{
}

int ChatDescEx::CreateInit()
{
	m_worldLevLimit = 0;	//世界频道等级限制
	m_crossLevLimit = 0;	//跨服频道等级限制
	m_crossChatCostBDia = 0;//跨服聊天消耗的绑定钻石
	m_worldChatPay = 0;		//世界频道开启需要充值的额度
	m_crateUnionPay = 0;	//创建工会需要的充值额度
	m_sceneLevLimit = 0;	//场景聊天等级限制
	m_teamEnlistBindDia = 0;//发送组队招募扣除紫钻
	return 0;
}

int ChatDescEx::ResumeInit()
{
	return 0;
}

int ChatDescEx::Load()
{
	CHECK_EXPR(Process(), -1, "");
	CHECK_EXPR(ProcessConst(), -1, "");
	return 0;
}

int ChatDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

bool ChatDescEx::IsMeetPayRmbCond(uint32_t totalrmb)
{
	return ((int32_t)totalrmb >= m_worldChatPay);
}

bool ChatDescEx::IsMeetCreateUnionPayRmb(uint32_t totalrmb)
{
	return ((int32_t)totalrmb >= m_crateUnionPay);
}

bool ChatDescEx::Process()
{
	return true;
}

bool ChatDescEx::ProcessConst()
{
	//世界聊天频道等级限制
	auto pWorldChatLevCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_WorldChatLevLimit);
	if (nullptr != pWorldChatLevCfg)
	{
		m_worldLevLimit = pWorldChatLevCfg->m_constantdata;
	}
	//跨服聊天频道等级限制
	auto pCrossChatLevCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_CrossChatLevLimit);
	if (nullptr != pCrossChatLevCfg)
	{
		m_crossLevLimit = pCrossChatLevCfg->m_constantdata;
	}
	//跨服聊天消耗绑钻
	auto pCrossChatCostCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_CrossChatCost);
	if (nullptr != pCrossChatCostCfg)
	{
		m_crossChatCostBDia = pCrossChatCostCfg->m_constantdata;
	}

	//世界聊天频道需要的充值金额
	auto pWorldChatPayCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_WorldChannelNeedPay);
	if (nullptr != pWorldChatPayCfg)
	{
		m_worldChatPay = pWorldChatPayCfg->m_constantdata;
	}

	//创建工会需要的充值额度
	auto pCreateUnionPayCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_CreateUnionNeedPay);
	if (nullptr != pCreateUnionPayCfg)
	{
		m_crateUnionPay = pCreateUnionPayCfg->m_constantdata;
	}

	auto pSceneChatCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_SceneChatLevLimit);
	if (nullptr != pSceneChatCfg)
	{
		m_sceneLevLimit = pSceneChatCfg->m_constantdata;
	}

	//组队招募频道发消息扣除紫钻数量
	auto pTeamEnlistChatCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_TeamEnList_CostBindDia);
	if (nullptr != pTeamEnlistChatCfg)
	{
		m_teamEnlistBindDia = pTeamEnlistChatCfg->m_constantdata;
	}

	return true;
}

