// -------------------------------------------------------------------------
//    @FileName         :    NFICommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"

class NFICommLogicModule : public NFIDynamicModule
{
public:
	NFICommLogicModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFICommLogicModule()
	{

	}

	virtual std::string GetConstValue(proto_ff::enConstType type) const = 0;

    virtual std::string GetRandomName() const = 0;
};

