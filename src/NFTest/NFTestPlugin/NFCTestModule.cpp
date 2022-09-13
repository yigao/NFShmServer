// -------------------------------------------------------------------------
//    @FileName         :    NFCTestActorModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTestPlugin
//
// -------------------------------------------------------------------------

#include "NFCTestModule.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIBusModule.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFPluginModule/NFCoroutineTask.h"
#include "NFComm/NFPluginModule/NFIMysqlModule.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"

#include "NFComm/NFKernelMessage/yd_fieldoptions.pb.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFJson2PB/NFPbToJson.h"
#include "NFComm/NFPluginModule/NFJson2PB/NFJsonToPb.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"
#include <iostream>
#include <mutex>
#include <atomic>
#include "NFComm/NFPluginModule/NFProto/NFXmlMessageCodec.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFPluginModule/NFEmailSender.h"
#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

NFCTestModule::NFCTestModule(NFIPluginManager* p):NFIModule(p)
{
}

NFCTestModule::~NFCTestModule()
{
}

bool NFCTestModule::Init()
{
	SetTimer(1, 1000, 1);
	return true;
}


void NFCTestModule::OnTimer(uint32_t nTimerID)
{
    return;
}

bool NFCTestModule::Execute()
{
	return true;
}

bool NFCTestModule::BeforeShut()
{
	return true;
}

bool NFCTestModule::Shut()
{
	return true;
}
