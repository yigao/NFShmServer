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
        int objId = iter->GetObjId();
        int globalId = iter->GetGlobalId();
        NFTestObj* pObj = NFTestObj::GetObjByObjId(m_pObjPluginManager, objId);
        NFTestObj* pGlobalObj = NFTestObj::GetObjByGlobalId(m_pObjPluginManager, globalId);
        NF_ASSERT(pObj == iter.GetObj());
        NF_ASSERT(pObj == pGlobalObj);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "erase id = {}", iter->id);
        iter = NFTestObj::Erase(m_pObjPluginManager, iter);
        pObj = NFTestObj::GetObjByObjId(m_pObjPluginManager, objId);
        pGlobalObj = NFTestObj::GetObjByGlobalId(m_pObjPluginManager, globalId);
        NF_ASSERT(pObj == NULL);
        NF_ASSERT(pGlobalObj == NULL);
    }

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
    for(auto iter = NFTestObj::RBegin(m_pObjPluginManager); iter != NFTestObj::REnd(m_pObjPluginManager); iter++)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "id = {}", iter->id);
    }
    for(int i = 0; i < 100; i++)
    {
        NFTestObj* pObj = NFTestObj::GetObjByObjId(m_pObjPluginManager, i);
        if (pObj)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "id = {}", pObj->id);
        }
    }
    return 0;
}

