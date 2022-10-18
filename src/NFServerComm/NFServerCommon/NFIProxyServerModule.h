// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFServerComm/NFServerCommon/NFServerCommonDefine.h"

class NFIProxyServerModule : public NFIDynamicModule
{
public:
	NFIProxyServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIProxyServerModule()
	{
		
	}

    template<typename BaseType>
    void SetOtherServerMsgHandle(BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        SetOtherServerMsgHandle(functor);
    }

    virtual void SetOtherServerMsgHandle(const NET_RECEIVE_FUNCTOR& func) = 0;
};
