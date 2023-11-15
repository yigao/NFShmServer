#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class ChatDescEx : public NFShmObjGlobalTemplate<ChatDescEx, EOT_CONST_CHAT_DESC_EX_ID, NFIDescStoreEx>
{
public:
	ChatDescEx();
	virtual ~ChatDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
public:
	//获取世界聊天频道等级限制
	int64_t WorldLevLimit() { return m_worldLevLimit; }
	//获取跨服聊天频道等级限制
	int64_t CrossLevLimit() { return m_crossLevLimit; }
	//获取跨服聊天消耗绑钻
	int64_t CrossChatCostBDia() { return m_crossChatCostBDia; }
	//是否满足充值额度条件
	bool IsMeetPayRmbCond(uint32_t totalrmb);
	//创建工会是否满足充值额度
	bool IsMeetCreateUnionPayRmb(uint32_t totalrmb);
	//获取场景聊天频道等级限制
	int64_t SceneLevLimit() { return m_sceneLevLimit; }
	//发送组队招募扣除紫钻
	int64_t TeamEnlistCostBindDia() { return m_teamEnlistBindDia; }
private:
	bool Process();
	bool ProcessConst();
private:
	int64_t m_worldLevLimit;	//世界频道等级限制
	int64_t m_crossLevLimit;	//跨服频道等级限制
	int64_t m_crossChatCostBDia;//跨服聊天消耗的绑定钻石
	int32_t m_worldChatPay;		//世界频道开启需要充值的额度
	int32_t m_crateUnionPay;	//创建工会需要的充值额度
	int64_t m_sceneLevLimit;	//场景聊天等级限制
	int64_t m_teamEnlistBindDia;//发送组队招募扣除紫钻
};
