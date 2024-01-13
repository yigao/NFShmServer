// -------------------------------------------------------------------------
//    @FileName         :    NFIAsycModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFIAsycModule
//
//
//                    .::::.
//                  .::::::::.
//                 :::::::::::  FUCK YOU
//             ..:::::::::::'
//           '::::::::::::'
//             .::::::::::
//        '::::::::::::::..
//             ..::::::::::::.
//           ``::::::::::::::::
//            ::::``:::::::::'        .:::.
//           ::::'   ':::::'       .::::::::.
//         .::::'      ::::     .:::::::'::::.
//        .:::'       :::::  .:::::::::' ':::::.
//       .::'        :::::.:::::::::'      ':::::.
//      .::'         ::::::::::::::'         ``::::.
//  ...:::           ::::::::::::'              ``::.
// ```` ':.          ':::::::::'                  ::::..
//                    '.:::::'                    ':'````..
//
// -------------------------------------------------------------------------


#pragma once

#include "NFIModule.h"
#include <vector>
#include "NFITaskModule.h"
#include "NFTask.h"

#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFIConfigModule.h"

using SelectByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_sel_res &select_res)>;

using SelectObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_selobj_res &select_res)>;

using DeleteByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_del_res &select_res)>;

using DeleteObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_delobj_res &select_res)>;

using InsertObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_insertobj_res &select_res)>;

using ModifyByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_mod_res &select_res)>;

using ModifyObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_modobj_res &select_res)>;

using UpdateByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_update_res &select_res)>;
using UpdateObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_updateobj_res &select_res)>;

using Execute_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_execute_res &select_res)>;
using ExecuteMore_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_execute_more_res &select_res)>;

class NFIAsycModule : public NFIModule
{
public:
	NFIAsycModule(NFIPluginManager*p):NFIModule(p)
	{
		mInitActor = false;
	}

	virtual ~NFIAsycModule()
	{

	}

	virtual bool InitActorPool(int maxTaskGroup, int maxActorNum)
	{
        int maxThread = 1;
		if (!mInitActor)
		{
            /*
            启动多线程任务系统
            */
            if (m_pObjPluginManager->IsLoadAllServer())
            {
                maxThread = 1;
            }
            else
            {
                NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
                NF_ASSERT(pConfig);

                maxThread = pConfig->WorkThreadNum;
            }

            FindModule<NFITaskModule>()->InitActorThread(maxTaskGroup, maxThread);

            if (maxActorNum <= 0)
            {
                maxActorNum = maxThread * 2;
            }

            m_vecActorGroupPool.resize(maxTaskGroup);

            for(int taskGroup = 0; taskGroup < (int)m_vecActorGroupPool.size(); taskGroup++)
            {
                for (int i = 0; i < maxActorNum; i++)
                {
                    int actorId = FindModule<NFITaskModule>()->RequireActor(taskGroup);
                    if (actorId <= 0)
                    {
                        return false;
                    }

                    m_vecActorGroupPool[taskGroup].push_back(actorId);
                }
            }

			mInitActor = true;
		}
		return true;
	}

	virtual bool Exist(int taskGroup, int actorId)
	{
        CHECK_EXPR(taskGroup >= 0 && taskGroup < (int)m_vecActorGroupPool.size(), false, "taskGroup:{} error", taskGroup);
		for (size_t i = 0; i < m_vecActorGroupPool[taskGroup].size(); i++)
		{
			if (m_vecActorGroupPool[taskGroup][i] == actorId)
			{
				return true;
			}
		}
		return false;
	}

	/**
	* @brief 添加一个Actor组件
	*
	* @return
	*/
	virtual int AddActorComponent(int taskGroup, int actorId, NFITaskComponent* pComonnet)
	{
		return FindModule<NFITaskModule>()->AddActorComponent(taskGroup, actorId, pComonnet);
	}

	virtual NFITaskComponent* GetActorComponent(int taskGroup, int actorId)
	{
		return FindModule<NFITaskModule>()->GetTaskComponent(taskGroup, actorId);
	}

	/**
	* @brief 通过任务的动态均衡id，获得actor
	*		 为了防止数据库错乱，防止同时对数据库表中的一条数据，读取写入，
	*		 使用动态均衡id, 使得在某个时候只有一条线程对表中的一条数据，读取或写入
	* @param balanceId 动态均衡id
	* @return	一个actor索引
	*/
	int GetBalanceActor(int taskGroup, uint64_t balanceId)
	{
        CHECK_EXPR(taskGroup >= 0 && taskGroup < (int)m_vecActorGroupPool.size(), -1, "taskGroup:{} error", taskGroup);
		if (balanceId == 0)
		{
			return GetRandActor(taskGroup);
		}
		else
		{
			if (m_vecActorGroupPool[taskGroup].size() <= 0)
			{
				return -1;
			}
			mnSuitIndex = balanceId % m_vecActorGroupPool[taskGroup].size();
			return m_vecActorGroupPool[taskGroup][mnSuitIndex];
		}
	}

	/**
	* @brief 随机获得一个actor
	*
	* @return actor索引
	*/
	int GetRandActor(int taskGroup)
	{
        CHECK_EXPR(taskGroup >= 0 && taskGroup < (int)m_vecActorGroupPool.size(), -1, "taskGroup:{} error", taskGroup);
		if (m_vecActorGroupPool[taskGroup].size() <= 0)
		{
			return -1;
		}

		mnSuitIndex++;
		mnSuitIndex = mnSuitIndex % m_vecActorGroupPool[taskGroup].size();

		return m_vecActorGroupPool[taskGroup][mnSuitIndex];
	}

	/**
	* @brief 通过平衡ID添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	int AddTask(int taskGroup, NFTask* pTask)
	{
		if (pTask)
		{
			int actorId = GetBalanceActor(taskGroup, pTask->GetBalanceId());
			if (actorId > 0)
			{
				return FindModule<NFITaskModule>()->AddTask(taskGroup, actorId, pTask);
			}
		}

		return 0;
	}

protected:
	/**
	* @brief actor索引数组
	*/
	std::vector<std::vector<int>> m_vecActorGroupPool;

	/**
	* @brief 用来平衡随机获得actor
	*/
	size_t mnSuitIndex = 0;

	bool mInitActor;
};