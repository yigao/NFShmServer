﻿// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFSTLMapEx.hpp"
#include "NFComm/NFCore/NFSTLMap.hpp"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"
#include "proto_svr_msg.pb.h"

class NFCWorldServerModule : public NFIWorldServerModule
{
public:
    explicit NFCWorldServerModule(NFIPluginManager *p);

    virtual ~NFCWorldServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;

    /**
     * @brief 接受来自MasterServer的其他服务器的报告
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleOtherServerReportFromMasterServer(const proto_ff::ServerInfoReport &xData) override;

    /**
     * @brief 处理逻辑服务器信息
     * @param xData
     * @return
     */
    virtual int OnHandleLogicReport(const proto_ff::ServerInfoReport& xData);
};
