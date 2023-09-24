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
        std::vector<uint32_t> roomList4 = FindModule<NFIGameConfig>()->GetRoomList(2004);
        std::vector<uint32_t> roomList3 = FindModule<NFIGameConfig>()->GetRoomList(2003);
        std::vector<uint32_t> roomList2 = FindModule<NFIGameConfig>()->GetRoomList(2002);
        std::vector<uint32_t> roomList1 = FindModule<NFIGameConfig>()->GetRoomList(2001);

        for (int i = 0; i < (int) roomList4.size(); i++)
        {
            uint32_t roomId = roomList4[i];

            if (!NFFishConfigConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                NFFishConfigConfig *pFish = NFFishConfigConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pFish);
                pFish->LoadConfig(roomId);
            }

            if (!NFFishSettingConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                NFFishSettingConfig *pSetting = NFFishSettingConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pSetting);
                pSetting->LoadConfig(roomId);
            }

            if (!NFFishPromptConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                NFFishPromptConfig *pPrompt = NFFishPromptConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pPrompt);
                pPrompt->LoadConfig(roomId);
            }

            if (!NFFishWayBillConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                NFFishWayBillConfig *pWayBill = NFFishWayBillConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pWayBill);
                pWayBill->LoadConfig(roomId);
            }

            if (!NFFishTraceConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                //trace must load before the group
                NFFishTraceConfig *pTrace = NFFishTraceConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pTrace);
                pTrace->LoadConfig(roomId);
            }

            if (!NFFishGroupConfig::GetObjByHashKey(m_pObjPluginManager, roomId))
            {
                NFFishGroupConfig *pGroup = NFFishGroupConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
                NF_ASSERT(pGroup);
                pGroup->LoadConfig(roomId);
            }
        }
    }
    return 0;
}


