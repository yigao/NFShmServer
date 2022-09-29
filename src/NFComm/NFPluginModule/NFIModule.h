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
    virtual bool HotfixExitApp()
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

    std::string m_strName;
};

