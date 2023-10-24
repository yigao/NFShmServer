// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFMMODynamicModule.h"


class NFMMOCommonModule : public NFMMODynamicModule
{
public:
	NFMMOCommonModule(NFIPluginManager* p) : NFMMODynamicModule(p)
	{

	}

	virtual ~NFMMOCommonModule()
	{

	}

    virtual bool Awake();
    
    /**
     * @brief 响应注册事件
     * @param nEventID
     * @param nSrcID
     * @param bySrcType
     * @param message
     * @return
     */
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
};