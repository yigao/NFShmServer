// -------------------------------------------------------------------------
//    @FileName         :    NFIPlugin.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFIPlugin
//
// -------------------------------------------------------------------------

#ifndef NFI_PLUGIN_H
#define NFI_PLUGIN_H

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFIModule.h"
#include "NFIPluginManager.h"


//为什么要在这里加上pManager->InitSingleton()呢， 主要是为了在动态加载的情况下，在每个DLL中，都初始化一次单件系统
#define REGISTER_MODULE(pManager, classBaseName, className)  \
    assert((TIsDerived<classBaseName, NFIModule>::Result)); \
    assert((TIsDerived<className, classBaseName>::Result)); \
    NFIModule* pRegisterModule##className= new className(pManager); \
    pRegisterModule##className->strName = (#className); \
    pManager->AddModule( #classBaseName, pRegisterModule##className );AddModule( #classBaseName, pRegisterModule##className );

#define UNREGISTER_MODULE(pManager, classBaseName, className) \
   NFIModule* pUnRegisterModule##className =  dynamic_cast<NFIModule*>( pManager->FindModule( typeid(classBaseName).name() )); \
	pManager->RemoveModule( #classBaseName );RemoveModule(#classBaseName); delete pUnRegisterModule##className;

#define REGISTER_STATIC_PLUGIN(pManager, className)  pManager->RegisteredStaticPlugin(#className, [] (NFIPluginManager* pMan) ->NFIPlugin* { return NF_NEW className(pMan);});

#define CREATE_PLUGIN(pManager, className)  NFIPlugin* pCreatePlugin##className = new className(pManager); pManager->Registered( pCreatePlugin##className );

#define DESTROY_PLUGIN(pManager, className) pManager->UnRegistered( pManager->FindPlugin((#className)) );

class NFIPluginManager;

class NFIPlugin : public NFIModule
{
public:
	NFIPlugin(NFIPluginManager* p):NFIModule(p)
	{
	}

	virtual int GetPluginVersion() = 0;

	virtual std::string GetPluginName() = 0;

	virtual void Install() = 0;

    virtual bool AfterLoadAllPlugin() override;

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool CheckConfig() override;

	virtual bool ReadyExecute() override;

	virtual bool Execute() override;

	virtual bool BeforeShut() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;

	virtual bool OnReloadPlugin() override;

	virtual bool InitShmObjectRegister();

	virtual void Uninstall() = 0;

	virtual bool IsDynamicLoad();

	virtual bool OnDynamicPlugin() override;

	virtual void AddModule(const std::string& moduleName, NFIModule* pModule);

	virtual void RemoveModule(const std::string& moduleName);
protected:
	std::map<std::string, NFIModule*> m_mapModule;
	std::vector<NFIModule*> m_vecModule;
};


#endif

