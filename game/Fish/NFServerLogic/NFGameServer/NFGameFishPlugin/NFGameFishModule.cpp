// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Module.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Module
//
// -------------------------------------------------------------------------

#include "NFGameFishModule.h"
#include "NFLogicCommon/NFIGameRoomModule.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFLogicCommon/NFIGameDeskImpl.h"
#include "NFGameFishDefine.h"
#include "NFLogicCommon/NFIGameConfig.h"
#include "Config/NFFishGroupConfig.h"
#include "Config/NFFishTraceConfig.h"
#include "Config/NFFishConfigConfig.h"
#include "Config/NFFishWayBillConfig.h"
#include "Config/NFFishSettingConfig.h"
#include "Config/NFFishPromptConfig.h"
#include "Desk/NFGameFishDesk.h"

NFGameFishModule::NFGameFishModule(NFIPluginManager *p) : NFISubGameModule(p)
{

}

NFGameFishModule::~NFGameFishModule()
{
}

bool NFGameFishModule::Awake()
{
    CreateDeskFunction createFunc = [](NFIPluginManager* pPluginManager, uint32_t gameId) -> NFIGameDeskImpl *
    {
        return NFGameFishDesk::CreateObj(pPluginManager);
    };
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(GAME_ID_FISH_HAIWANG_2004, createFunc);
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(2003, createFunc);
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(2002, createFunc);
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(2001, createFunc);

    //////register client msg////////////////////
    RegisterClientMessage(NF_FISH_CMD_GAMESTATUS);
    RegisterClientMessage(NF_FISH_CMD_SHOOTBULLET);
    RegisterClientMessage(NF_FISH_CMD_BULLETSPEED);
    RegisterClientMessage(NF_FISH_CMD_HITFISH);
    RegisterClientMessage(NF_FISH_CMD_AUTOSHOOT);
    RegisterClientMessage(NF_FISH_CMD_LOCKONOFF);
    RegisterClientMessage(NF_FISH_CMD_LOCKFISH);
    RegisterClientMessage(NF_FISH_CMD_CHANGECANNON);
    RegisterClientMessage(proto_ff::NF_CS_MSG_UserStatusReq);

    RegisterClientMessage(NF_FISH_CMD_DIANCICANNONAIM_REQ);
    RegisterClientMessage(NF_FISH_CMD_DIANCICANNONSHOOT_REQ);
    RegisterClientMessage(NF_FISH_CMD_DIANCICANNONHITFISH_REQ);

    RegisterClientMessage(NF_FISH_CMD_ZUANTOUAIM_REQ);
    RegisterClientMessage(NF_FISH_CMD_ZUANTOUSHOOT_REQ);
    RegisterClientMessage(NF_FISH_CMD_ZUANTOUHITFISH_REQ);

    RegisterClientMessage(NF_FISH_CMD_SOMEZUANTOUHITFISH_REQ);
    RegisterClientMessage(NF_FISH_CMD_HAIWANGCRABHITPART_REQ);

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE,
              APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE, __FUNCTION__);
    return true;
}

int NFGameFishModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    if (serverType == NF_ST_GAME_SERVER && nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE &&
        nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE)
    {
        std::unordered_map<uint32_t, std::vector<uint32_t>> gameRoomMap = FindModule<NFIGameConfig>()->GetGameRoomList();

        for(auto iter = gameRoomMap.begin(); iter != gameRoomMap.end(); iter++)
        {
            uint32_t gameId = iter->first;
            std::vector<uint32_t>& roomList = iter->second;
            for (int i = 0; i < (int) roomList.size(); i++)
            {
                uint32_t roomId = roomList[i];

                uint64_t comKey = gameId*100+roomId;

                if (!NFFishConfigConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishConfigConfig *pFish = NFFishConfigConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pFish);
                    int iRet = pFish->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishConfigConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }

                if (!NFFishSettingConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishSettingConfig *pSetting = NFFishSettingConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pSetting);
                    int iRet = pSetting->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishSettingConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }

                if (!NFFishPromptConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishPromptConfig *pPrompt = NFFishPromptConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pPrompt);
                    int iRet = pPrompt->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishPromptConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }

                if (!NFFishWayBillConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishWayBillConfig *pWayBill = NFFishWayBillConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pWayBill);
                    int iRet = pWayBill->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishWayBillConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }

                if (!NFFishTraceConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishTraceConfig *pTrace = NFFishTraceConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pTrace);
                    int iRet = pTrace->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishWayBillConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }

                if (!NFFishGroupConfig::GetObjByHashKey(m_pObjPluginManager, comKey))
                {
                    NFFishGroupConfig *pGroup = NFFishGroupConfig::CreateObjByHashKey(m_pObjPluginManager, comKey);
                    NF_ASSERT(pGroup);
                    int iRet = pGroup->LoadConfig(gameId, roomId);
                    CHECK_EXPR_ASSERT(iRet == 0, -1, "NFFishWayBillConfig LoadConfig Failed, gameId:{} roomId:{}", gameId, roomId);
                }
            }
        }
    }
    return 0;
}


