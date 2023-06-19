// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFTestObj.h"


bool NFCommLogicModule::Awake()
{
    SetTimer(0, 10000, 1);
    return true;
}

int NFCommLogicModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    return 0;
}

int NFCommLogicModule::OnTimer(uint32_t nTimerID)
{
    for(auto iter = NFTestObj::Begin(m_pObjPluginManager); iter != NFTestObj::End(m_pObjPluginManager);)
    {
        if (iter->id % 2 == 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "erase id = {}", iter->id);
            iter = NFTestObj::Erase(m_pObjPluginManager, iter);
        }
        else {
            iter++;
        }
    }

    NFTestObj::ClearAllObj(m_pObjPluginManager);

    for(int i = 0; i < 100; i++)
    {
        NFTestObj* pObj = FindModule<NFISharedMemModule>()->CreateObj<NFTestObj>();
        if (pObj)
        {
            pObj->id = i;
        }
    }
    for(auto iter = NFTestObj::Begin(m_pObjPluginManager); iter != NFTestObj::End(m_pObjPluginManager); iter++)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "id = {}", iter->id);
    }
    return 0;
}

