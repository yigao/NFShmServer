// -------------------------------------------------------------------------
//    @FileName         :    NFTutorialModule.h
//    @Author           :    gaoyi
//    @Date             :    24-1-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFTutorialModule
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFIDynamicModule.h>

class NFTutorialModule : public NFIDynamicModule
{
public:
    NFTutorialModule(NFIPluginManager* p);
    
    virtual ~NFTutorialModule();

    virtual bool Awake();

    virtual bool Init();

    virtual bool Execute();

    virtual bool Shut();

    virtual bool Finalize();

    /*
     * 动态热更dll/so之后，模块调用的函数
     * */
    virtual bool OnDynamicPlugin();

	/**
	 * \brief 
	 * \param nTimerID 定时器函数
	 * \return 
	 */
	virtual int OnTimer(uint32_t nTimerID) override;
private:
	uint32_t m_idCount;
};