// -------------------------------------------------------------------------
//    @FileName         :    NFCEventModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFCEventModule.h"

NFCEventModule::NFCEventModule(NFIPluginManager* p):NFIEventModule(p)
{
}

NFCEventModule::~NFCEventModule()
{
}

bool NFCEventModule::BeforeShut()
{
	return true;
}

bool NFCEventModule::Shut()
{
	return true;
}

bool NFCEventModule::Execute()
{
	return true;
}

//发送执行事件
void NFCEventModule::FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message& message)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

    /**
    * @brief 先执行完全匹配的
    */
    if (skey.nSrcID != 0) {
        bool bRes = m_ExecuteCenter.Fire(skey, message);
        if (!bRes) {
            return;
        }
    }

    /**
    * @brief 再执行， 针对整个事件nEventID,类型为bySrcType
    * 比如订阅时，订阅了所有玩家类的事件，而不是对一个玩家的事件，
    * 订阅时将nSrcId=0，会受到所有玩家产生的该类事件
    */
    skey.nSrcID = 0;
    bool bRes = m_ExecuteCenter.Fire(skey, message);
    if (!bRes)
    {
        return;
    }
}

//订阅执行事件
bool NFCEventModule::Subscribe(NFEventObjBase* pSink, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const std::string& desc)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

	return m_ExecuteCenter.Subscribe(pSink, skey, desc);
}

//取消订阅执行事件
bool NFCEventModule::UnSubscribe(NFEventObjBase* pSink, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID)
{
    SEventKey skey;
    skey.nServerType = serverType;
    skey.nEventID = nEventID;
    skey.bySrcType = bySrcType;
    skey.nSrcID = nSrcID;

	return m_ExecuteCenter.UnSubscribe(pSink, skey);
}

//取消所有执行事件的订阅
bool NFCEventModule::UnSubscribeAll(NFEventObjBase* pSink)
{
	m_ExecuteCenter.UnSubscribeAll(pSink);
	return true;
}

