// -------------------------------------------------------------------------
//    @FileName         :    NFMonitorModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFMonitorPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFSystemInfo.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFEventMgr.h"

/**
* @brief 服务器监控模块
*/
class NFCMonitorModule : public NFIMonitorModule, public NFTimerObj, public NFEventObj
{
public:
	NFCMonitorModule(NFIPluginManager* p);

	virtual ~NFCMonitorModule();
public:
	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool Finalize() override;

	/**
	* @brief 处理定时器功能
	*
	* @return void
	*/
	virtual void OnTimer(uint32_t nTimerID);

	/**
	* @brief 处理事件
	*
	* @return void
	*/
	virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message);

	virtual const NFSystemInfo& GetSystemInfo() const;

	virtual uint32_t GetUserCount() const;
	virtual void SetUserCount(uint32_t count);

	virtual double GetCpuUsed();

	virtual uint64_t GetMemUsed();

    virtual void CountAndPrint();
private:
	NFSystemInfo mSystemInfo;
};
