// -------------------------------------------------------------------------
//    @FileName         :    NFCEventModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFCEventModule.h"

#include "NFComm/NFPluginModule/NFEventMgr.h"

NFCEventModule::NFCEventModule(NFIPluginManager* p):NFIEventModule(p)
{
	NFEventMgr::Instance()->Init(this);
}

NFCEventModule::~NFCEventModule()
{
	NFEventMgr::Instance()->UnInit();
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
void NFCEventModule::FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
	m_ExecuteCenter.Fire(nEventID, nSrcID, bySrcType, message);
}

//订阅执行事件
bool NFCEventModule::Subscribe(NFEventObj* pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string& desc)
{
	return m_ExecuteCenter.Subscribe(pSink, nEventID, nSrcID, bySrcType, desc);
}

//取消订阅执行事件
bool NFCEventModule::UnSubscribe(NFEventObj* pSink, uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
{
	return m_ExecuteCenter.UnSubscribe(pSink, nEventID, nSrcID, bySrcType);
}

//取消所有执行事件的订阅
bool NFCEventModule::UnSubscribeAll(NFEventObj* pSink)
{
	m_ExecuteCenter.UnSubscribeAll(pSink);
	return true;
}

