// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIStoreServerModule.h"

class NFCStoreServerModule : public NFIStoreServerModule
{
public:
	explicit NFCStoreServerModule(NFIPluginManager* p);
	virtual ~NFCStoreServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual bool OnReloadConfig() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;

    /**
     * @brief 动态加载protobuf信息，并检查数据库，可能的话建立数据库，表格，列
     * @return
     */
    virtual bool LoadPbAndCheckDB();
public:
    /**
     * @brief 处理数据库请求
     * @param unLinkId
     * @param packet
     * @return
     */
	int OnHandleStoreReq(uint64_t unLinkId, NFDataPackage& packet);
public:
    /**
     * @brief Select Obj Rpc Service
     * @param request
     * @param respone
     * @return
     */
    int OnHandleSelectObjRpc(storesvr_sqldata::storesvr_selobj& request, storesvr_sqldata::storesvr_selobj_res& respone);

    /**
     * @brief Select Rpc Service
     * @param request
     * @param respone
     * @return
     */
    int OnHandleSelectRpc(storesvr_sqldata::storesvr_sel& request, storesvr_sqldata::storesvr_sel_res& respone, const std::function<void()>& cb);

    /**
     * @brief
     * @param request
     * @param respone
     * @return
     */
    int OnHandleInsertObjRpc(storesvr_sqldata::storesvr_insertobj& request, storesvr_sqldata::storesvr_insertobj_res& respone);
};
