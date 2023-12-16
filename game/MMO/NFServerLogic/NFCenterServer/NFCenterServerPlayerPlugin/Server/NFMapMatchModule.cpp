// -------------------------------------------------------------------------
//    @FileName         :    NFMapMatchModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapMatchModule
//
// -------------------------------------------------------------------------

#include "NFMapMatchModule.h"
#include "NFServerAddrMgr.h"
#include "NFGameCommon/NFPoint3.h"

NFMapMatchModule::NFMapMatchModule(NFIPluginManager* p):NFMMODynamicModule(p)
{

}

NFMapMatchModule::~NFMapMatchModule()
{
}

bool NFMapMatchModule::Awake()
{
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::STS_ENTER_SCENE_REQ>(NF_ST_CENTER_SERVER, this,
                                                                             &NFMapMatchModule::OnRpcServiceEnterScene, true);
    return true;
}

bool NFMapMatchModule::Execute()
{
    return NFIModule::Execute();
}

bool NFMapMatchModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFMapMatchModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    return NFIDynamicModule::OnExecute(serverType, nEventID, bySrcType, nSrcID, pMessage);
}

int NFMapMatchModule::OnRpcServiceEnterScene(proto_ff::EnterSceneReq& request, proto_ff::EnterSceneRsp& respone)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_CENTER_SERVER);
    CHECK_NULL(pConfig);
    
    uint32_t gameId = NFServerAddrMgr::Instance(m_pObjPluginManager)->GetSuitGameIdByZid(request.dst_map_id(), pConfig->GetZoneId());
    if (gameId == 0)
    {
        gameId = NFServerAddrMgr::Instance(m_pObjPluginManager)->GetSuitGameIdByCross(request.dst_map_id(), !pConfig->IsCrossServer());
        if (gameId == 0)
        {
            respone.set_ret_code(proto_ff::RET_SCENE_DST_NOT_EXIST);
            return 0;
        }
    }
    
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::STS_ENTER_SCENE_REQ>(NF_ST_CENTER_SERVER, NF_ST_GAME_SERVER, gameId, request, respone);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, request.cid(), "GetRpcService<proto_ff::STS_ENTER_SCENE_REQ> rpc error:{}, gameId:{}", GetErrorStr(iRet), gameId);
        return iRet;
    }
    return 0;
}
