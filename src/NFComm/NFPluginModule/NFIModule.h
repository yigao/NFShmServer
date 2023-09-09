// -------------------------------------------------------------------------
//    @FileName         :    NFIModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFIModule
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include "NFObject.h"

class NFIModule : public NFObject
{
public:
    NFIModule(NFIPluginManager *p) : NFObject(p)
    {

    }

    virtual ~NFIModule()
    {
    }

    virtual bool AfterLoadAllPlugin()
    {
        return true;
    }

    virtual bool AfterInitShmMem()
    {
        return true;
    }

    virtual bool Awake()
    {
        return true;
    }

    virtual bool Init()
    {
        return true;
    }

    virtual bool CheckConfig()
    {
        return true;
    }

    virtual bool ReadyExecute()
    {
        return true;
    }

    virtual bool Execute()
    {
        return true;
    }

    virtual bool BeforeShut()
    {
        return true;
    }

    virtual bool Shut()
    {
        return true;
    }

    virtual bool Finalize()
    {
        return true;
    }

    /*
     * 热更完所有配置后，模块调用的函数
     * */
    virtual bool OnReloadConfig()
    {
        return true;
    }

    /*
     * 热更配置时，模块热更的调用的函数
     * */
    virtual bool AfterOnReloadConfig()
    {
        return true;
    }

    /*
     * 动态热更dll/so之后，模块调用的函数
     * */
    virtual bool OnDynamicPlugin()
    {
        return true;
    }

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    virtual bool HotfixServer()
    {
        return true;
    }

    /*
     * 停服之前，检查服务器是否满足停服条件
     * */
    virtual bool CheckStopServer()
    {
        return true;
    }

    /*
     * 停服之前，做一些操作，满足停服条件
     * */
    virtual bool OnStopServer()
    {
        return true;
    }

    /*
     * 满足停服条件, 停服之前保存需要的数据
     * */
    virtual bool SaveDB()
    {
        return true;
    }

    /**
     * @brief 服务器连接完成后
     * @return
     */
    virtual bool AfterAllConnectFinish()
    {
        return true;
    }

    /**
     * @brief 加载完服务器数据，包过excel, 以及从数据拉取的数据
     * @return
     */
    virtual bool AfterAllDescStoreLoaded()
    {
        return true;
    }

    /**
     * @brief 从db加载全局数据, 这个加载一定在完成连接后，有可能依赖descstore数据，也可能不依赖
     * @return
     */
    virtual bool AfterObjFromDBLoaded()
    {
        return true;
    }

    /**
     * @brief 完成服务器之间的注册
     * @return
     */
    virtual bool AfterServerRegisterFinish()
    {
        return true;
    }

    /**
     * @brief  服务器完成初始化之后
     * @return
     */
    virtual bool AfterAppInitFinish()
    {
        return true;
    }

    std::string m_strName;
};

