// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStore.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDescStore.h
//
// -------------------------------------------------------------------------

#include "NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFIDescStoreModule.h"

NFIDescStore::NFIDescStore(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFIDescStore::~NFIDescStore()
{
    if (m_bSaveTimer != INVALID_ID)
    {
        DeleteTimer(m_bSaveTimer);
        m_bSaveTimer = INVALID_ID;
    }
}

int NFIDescStore::CreateInit()
{
    m_bValid = false;
    m_bIsLoaded = false;
    m_bIsChecked = false;
    m_bSaveTimer = INVALID_ID;
    return 0;
}

int NFIDescStore::ResumeInit()
{
    return 0;
}

int NFIDescStore::SaveDescStoreToDB(const google::protobuf::Message *pMessage)
{
    if (!IsFileLoad())
    {
        return FindModule<NFIDescStoreModule>()->SaveDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
    }
    return 0;
}

int NFIDescStore::InsertDescStoreToDB(const google::protobuf::Message *pMessage)
{
    if (!IsFileLoad())
    {
        return FindModule<NFIDescStoreModule>()->InsertDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
    }
    return 0;
}

int NFIDescStore::DeleteDescStoreToDB(const google::protobuf::Message *pMessage)
{
    if (!IsFileLoad())
    {
        return FindModule<NFIDescStoreModule>()->DeleteDescStoreByFileName(GetDBName(), GetFileName(), pMessage);
    }
    return 0;
}

int NFIDescStore::StartSaveTimer()
{
    int rand = NFRandInt(1000, 10000);
    m_bSaveTimer = SetTimer(1*1000, 0, 0, 0, 0, rand);
    return 0;
}

//must be virtual
void NFIDescStore::OnTimer(int timeId, int callcount)
{
    if (m_bSaveTimer == timeId)
    {
        SaveDescStore();
    }
}



