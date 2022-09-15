// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFServerMessageMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"

NFServerMessageMgr::NFServerMessageMgr()
{

}

NFServerMessageMgr::~NFServerMessageMgr()
{

}

int NFServerMessageMgr::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pServerData = NFMessageMgr::Instance()->GetMasterData(eSendType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) eSendType);

    NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, xData, nParam1, nParam2);
    return 0;
}