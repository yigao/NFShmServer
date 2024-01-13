// -------------------------------------------------------------------------
//    @FileName         :    NFEventObj.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include <stdint.h>

#include "NFEventObj.h"
#include "NFIPluginManager.h"
#include "NFIEventModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"


NFEventObj::NFEventObj(NFIPluginManager* pPluginManager):NFObject(pPluginManager)
{
}

NFEventObj::~NFEventObj()
{
	UnSubscribeAll();
}

//发送执行事件
void NFEventObj::FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message& message)
{
    m_pObjPluginManager->FindModule<NFIEventModule>()->FireExecute(serverType, nEventID, bySrcType, nSrcID, message);

    auto pModule = m_pObjPluginManager->FindModule<NFISharedMemModule>();
    if (pModule)
    {
        pModule->FireExecute(serverType, nEventID, bySrcType, nSrcID, message);
    }
}

//订阅执行事件
bool NFEventObj::Subscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& desc)
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->Subscribe(this, serverType, nEventID, bySrcType, nSrcID, desc);
}

//取消订阅执行事件
bool NFEventObj::UnSubscribe(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID)
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribe(this, serverType, nEventID, bySrcType, nSrcID);
}

//取消所有执行事件的订阅
bool NFEventObj::UnSubscribeAll()
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribeAll(this);
}

