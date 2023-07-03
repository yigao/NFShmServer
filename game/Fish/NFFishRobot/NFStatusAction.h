// -------------------------------------------------------------------------
//    @FileName         :    NFStatusAction.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFStatusAction.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"

class NFTestRobot;
class StatusAction : public NFIDynamicModule
{
public:
    StatusAction(NFIPluginManager* pPluginManager, NFTestRobot* p) :NFIDynamicModule(pPluginManager), m_pRobot(p)
    {

    }

    virtual ~StatusAction()
    {

    }

    virtual bool Awake()
    {
        return true;
    }

    virtual bool Finalize()
    {
        return true;
    }

    virtual int OnHandleAction() = 0;
    virtual int OnHandleMessage(uint64_t unLinkId, uint64_t playerId,  uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen) = 0;
    NFTestRobot* m_pRobot;
};