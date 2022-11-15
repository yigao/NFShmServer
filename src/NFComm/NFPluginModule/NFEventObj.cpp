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


NFEventObj::NFEventObj(NFIPluginManager* pPluginManager):NFObject(pPluginManager)
{
}

NFEventObj::~NFEventObj()
{
	UnSubscribeAll();
}

//发送执行事件
void NFEventObj::FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    m_pObjPluginManager->FindModule<NFIEventModule>()->FireExecute(nEventID, nSrcID, bySrcType, message);
}

//订阅执行事件
bool NFEventObj::Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string& desc)
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->Subscribe(this, nEventID, nSrcID, bySrcType, desc);
}

//取消订阅执行事件
bool NFEventObj::UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribe(this, nEventID, nSrcID, bySrcType);
}

//取消所有执行事件的订阅
bool NFEventObj::UnSubscribeAll()
{
	return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribeAll(this);
}

