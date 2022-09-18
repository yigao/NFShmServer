// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFServerMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFServerMessageModule::NFServerMessageModule(NFIPluginManager* pPluginManager):NFIServerMessageModule(pPluginManager)
{

}

NFServerMessageModule::~NFServerMessageModule()
{

}

int NFServerMessageModule::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pServerData = FindModule<NFIMessageModule>()->GetMasterData(eSendType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) eSendType);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nMsgId, xData, nParam1, nParam2);
    return 0;
}