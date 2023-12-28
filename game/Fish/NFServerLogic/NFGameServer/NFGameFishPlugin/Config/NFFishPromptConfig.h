#pragma once
#include <map>
#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

#define NF_FISH_PROMT_CFG_MAX_CHANGE_SCENE_TYPE 10

class NFFishPromptConfig : public NFShmObjTemplate<NFFishPromptConfig, EOT_GAME_FISH_PROMPT_CFG_DESC_ID, NFShmObj>
{
public:
	NFFishPromptConfig();
	~NFFishPromptConfig();
    int CreateInit();
    int ResumeInit();

	float GetChangeSceneSeconds(int iChangeType);
    int LoadConfig(uint32_t gameId, uint32_t roomId);
public:
    uint32_t m_roomId;
	int  m_iSceneCount;
	int  m_iYuChaoTipOn;
	NFShmHashMap<int, float, NF_FISH_PROMT_CFG_MAX_CHANGE_SCENE_TYPE> m_mapChangeSceneType_Time;
};