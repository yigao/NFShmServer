// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorldPlayerMgr.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFCWorldPlayerModule : public NFIDynamicModule
{
public:
	explicit NFCWorldPlayerModule(NFIPluginManager* p);
	virtual ~NFCWorldPlayerModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;
};
