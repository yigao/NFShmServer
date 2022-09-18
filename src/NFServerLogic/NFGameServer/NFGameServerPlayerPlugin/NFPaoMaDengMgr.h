// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPaoMaDengMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPaoMaDengMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFMessageDefine/proto_cs_game.pb.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include <unordered_map>

class NFPaoMaDengMgr : public NFSingleton<NFPaoMaDengMgr>, NFTimerObj
{
public:
    NFPaoMaDengMgr();
    virtual ~NFPaoMaDengMgr();
public:
    int Init();
    virtual void OnTimer(uint32_t nTimerID);
    int AddPaoMaDeng(const proto_game::OnePaoMaDengInfo& notify);
public:
    std::unordered_multimap<uint64_t, proto_game::OnePaoMaDengInfo> m_notifyMgr;
};