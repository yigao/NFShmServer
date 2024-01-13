// -------------------------------------------------------------------------
//    @FileName         :    NFTutorialModule.cpp
//    @Author           :    gaoyi
//    @Date             :    24-1-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFTutorialModule
//
// -------------------------------------------------------------------------

#include "NFTutorialModule.h"

#define TUTORIAL_TIMER_ID 10

NFTutorialModule::NFTutorialModule(NFIPluginManager* p): NFIDynamicModule(p)
{
	m_idCount = 0;
}

NFTutorialModule::~NFTutorialModule()
{
}

bool NFTutorialModule::Awake()
{
	NFLogError(NF_LOG_SYSTEMLOG, 0, "tutorial awake...........");
	/**
	 * 定一个10秒执行一次的定时器
	 */
	SetTimer(TUTORIAL_TIMER_ID, 10000);
	return NFIDynamicModule::Awake();
}

bool NFTutorialModule::Init()
{
	NFLogError(NF_LOG_SYSTEMLOG, 0, "tutorial init...........");
	return NFIDynamicModule::Init();
}

bool NFTutorialModule::Execute()
{
	return NFIDynamicModule::Execute();
}

bool NFTutorialModule::Shut()
{
	NFLogError(NF_LOG_SYSTEMLOG, 0, "tutorial shut...........");
	return NFIDynamicModule::Shut();
}

bool NFTutorialModule::Finalize()
{
	NFLogError(NF_LOG_SYSTEMLOG, 0, "tutorial finalize...........");
	return NFIDynamicModule::Finalize();
}

bool NFTutorialModule::OnDynamicPlugin()
{
	NFLogError(NF_LOG_SYSTEMLOG, 0, "tutorial OnDynamicPlugin...........");
	return NFIDynamicModule::OnDynamicPlugin();
}

int NFTutorialModule::OnTimer(uint32_t nTimerID)
{
	if (nTimerID == TUTORIAL_TIMER_ID)
	{
		m_idCount++;
		NFLogError(NF_LOG_SYSTEMLOG, 0, "id count:{}.......", m_idCount);
		//NFLogError(NF_LOG_SYSTEMLOG, 0, "xxxxxxxxxxxxxxxxxxxxx");
	}
	return 0;
}
