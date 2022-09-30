// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFServerDefine.h>
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIWorldServerModule : public NFIDynamicModule
{
public:
    NFIWorldServerModule(NFIPluginManager *p) : NFIDynamicModule(p)
    {

    }

    virtual ~NFIWorldServerModule()
    {

    }

    /*
     * 检查网关消息
     * */
    template<typename BaseType>
    bool AddProxyMsgCheckCallBack(BaseType *pBase,
                                  int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddProxyMsgCheckCallBack(functor);
    }

    /*
     * 检查网关消息
     * */
    virtual bool AddProxyMsgCheckCallBack(const NET_RECEIVE_FUNCTOR &functor) = 0;
};

