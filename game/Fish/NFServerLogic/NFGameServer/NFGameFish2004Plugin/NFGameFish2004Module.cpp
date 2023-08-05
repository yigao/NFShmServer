// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Module.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Module
//
// -------------------------------------------------------------------------

#include "NFGameFish2004Module.h"
#include "NFLogicCommon/NFIGameRoomModule.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFLogicCommon/NFIGameDeskImpl.h"
#include "NFGameFishDefine.h"
#include "NFLogicCommon/NFIGameConfig.h"
#include "NFFishGroupConfig.h"
#include "NFFishTraceConfig.h"
#include "NFFishConfigConfig.h"
#include "NFFishWayBillConfig.h"

NFGameFish2004Module::NFGameFish2004Module(NFIPluginManager *p):NFISubGameModule(p)
{

}

NFGameFish2004Module::~NFGameFish2004Module()
{
}

bool NFGameFish2004Module::Awake()
{
    CreateDeskFunction createFunc = [](uint32_t gameId) -> NFIGameDeskImpl*
    {
        NF_ASSERT(gameId == GAME_ID_FISH_HAIWANG_2004);
        return NULL;
    };
    FindModule<NFIGameRoomModule>()->RegisterCreateDeskFunction(GAME_ID_FISH_HAIWANG_2004, createFunc);

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

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    return true;
}

int NFGameFish2004Module::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    if (serverType == NF_ST_GAME_SERVER && nEventID == proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        std::vector<uint32_t> roomList = FindModule<NFIGameConfig>()->GetRoomList(GAME_ID_FISH_HAIWANG_2004);


        for(int i = 0; i < (int)roomList.size(); i++)
        {
            uint32_t roomId = roomList[i];

            NFFishConfigConfig* pFish = NFFishConfigConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
            NF_ASSERT(pFish);
            pFish->LoadConfig(roomId);

            NFFishWayBillConfig* pWayBill = NFFishWayBillConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
            NF_ASSERT(pWayBill);
            pWayBill->LoadConfig(roomId);

            //trace must load before the group
            NFFishTraceConfig* pTrace = NFFishTraceConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
            NF_ASSERT(pTrace);
            pTrace->LoadConfig(roomId);

            NFFishGroupConfig* pGroup = NFFishGroupConfig::CreateObjByHashKey(m_pObjPluginManager, roomId);
            NF_ASSERT(pGroup);
            pGroup->LoadConfig(roomId);
        }
    }
    return 0;
}


