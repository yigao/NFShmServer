// -------------------------------------------------------------------------
//    @FileName         :    NFSnsUserSimpleUtil.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsUserSimpleUtil.cpp
//
// -------------------------------------------------------------------------

#include "NFSnsUserSimpleUtil.h"
#include "NFTransGetSnsUserSimple.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFTransSnsBase.h"
#include "NFSnsUserSimple.h"
#include "NFSnsUserSimpleMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsUserSimpleUtil, EOT_SNS_USER_SIMPLE_UTIL_ID, NFShmObj)

int SGetRoleCacheData::add(uint64_t rid, int rtrans, uint32_t rtime) {
    if (rtrans <= 0) {
        for (int i = 0; i < roleInfo.GetSize(); ++i) {
            if (rtrans == roleInfo[i].transID) {
                return 0;
            }
        }
    }

    roleID = rid;
    if (roleInfo.GetSize() >= 0 && !roleInfo.IsFull()) {
		auto pInfo = roleInfo.Add();
		pInfo->transID = rtrans;
		pInfo->getTime = rtime;
    } else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get role info trans cache full:{} {}", rid, roleInfo.GetSize());
        return -1;
    }

    return 0;
}


NFSnsUserSimpleUtil::NFSnsUserSimpleUtil() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFSnsUserSimpleUtil::~NFSnsUserSimpleUtil() {
    if (m_refreshTimer != INVALID_ID)
    {
        DeleteTimer(m_refreshTimer);
        m_refreshTimer = INVALID_ID;
    }
}

int NFSnsUserSimpleUtil::CreateInit() {
    flag = true;

    m_sRoleStatic.CreateInit();
    m_sGetRoleStatic.CreateInit();

    m_refreshTimer = SetTimer(100, 0, 0, 0, 1, 0);
    return 0;
}

int NFSnsUserSimpleUtil::ResumeInit() {
    return 0;
}

void NFSnsUserSimpleUtil::OnTimer(int timeId, int callcount) {
    if (timeId == m_refreshTimer)
    {
        RefreshQueue();
    }
}

int NFSnsUserSimpleUtil::GetRoleSimpleInfo(uint64_t roleID, int transID, uint32_t time) {
    if(roleID <= 0)
        return 0;

    if(transID <= 0)
    {
        transID = -1;
    }

    for(auto itr = m_sGetRoleStatic.Begin(); itr!=m_sGetRoleStatic.End(); ++itr)
    {
        if(roleID == itr->roleID)
        {
            itr->add(roleID, transID, time);
            return 0;
        }
    }

    if(m_sGetRoleStatic.Size() < SNS_GETTING_ROLE_SIZE && m_sRoleStatic.IsEmpty()
       && NFTransGetSnsUserSimple::GetFreeCount() > 0 && NFTransGetSnsUserSimple::GetUsedCount() < SNS_GETTING_ROLE_SIZE)
    {
        SGetRoleCacheData tmpData;

        tmpData.clear();
        if(tmpData.add(roleID, transID, time))
            return -1;

        m_sGetRoleStatic.PushBack(tmpData);
        if(TransGetRoleSimpleInfo(&tmpData))
        {
            return -1;
        }
    }
    else
    {
		SGetRoleCacheData *pstFind = m_sRoleStatic.Find(roleID);
        if( pstFind )
        {
            if(pstFind->roleID == roleID)
            {
                if(pstFind->add(roleID, transID, time))
                    return -1;
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "get role simpleinfo queue error {} {}", roleID, pstFind->roleID);
                return -1;
            }
        }
        else
        {
            if(m_sRoleStatic.IsFull())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "role simpleinfo queue full");
                return -1;
            }

            SGetRoleCacheData tmpData;

            tmpData.clear();
            if(tmpData.add(roleID, transID, time))
                return -1;

            int iRetCode = m_sRoleStatic.Insert(roleID, tmpData);
            if( iRetCode != 0 )
            {
				m_sRoleStatic.Erase(roleID);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "role simpleinfo queue err {}", roleID);
                return -1;
            }
        }
    }

    return 0;
}

int NFSnsUserSimpleUtil::GetCheckedRoleSimpleInfo(uint64_t roleID) {
    return 0;
}

int NFSnsUserSimpleUtil::TransGetRoleSimpleInfo(SGetRoleCacheData *data)
{
    NFTransGetSnsUserSimple *pTransSnsBase = (NFTransGetSnsUserSimple *) NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_USER_SIMPLE);
    if(!pTransSnsBase)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans sns role simpleinfo Failed!UsedItem:{}", NFTransGetSnsUserSimple::GetUsedCount());
        return -1;
    }

    if(pTransSnsBase->QueryUser(data->roleID))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->roleID);
        pTransSnsBase->SetFinished(-1);
    }

    return 0;
}

void NFSnsUserSimpleUtil::RefreshQueue()
{
    uint32_t timeNow = NFTime::Now().UnixSec();

    for(auto itr = m_sGetRoleStatic.Begin(); itr!=m_sGetRoleStatic.End(); )
    {
        for(int i=0; i< itr->roleInfo.GetSize(); )
        {
            if((timeNow - itr->roleInfo[i].getTime) >= TRANS_SNS_BASE_TIMEOUT)
            {
				itr->roleInfo.MemShiftDel(i);
            }
            else
            {
                ++i;
            }
        }

        if(itr->roleInfo.GetSize() <= 0)
        {
            itr = m_sGetRoleStatic.Erase(itr);
        }
        else
        {
            ++itr;
        }
    }

    if (m_sGetRoleStatic.Size() < SNS_GETTING_ROLE_SIZE && m_sRoleStatic.GetUsedNum() > 0
        && NFTransGetSnsUserSimple::GetFreeCount() > 0 && NFTransGetSnsUserSimple::GetUsedCount() < SNS_GETTING_ROLE_SIZE) {
        std::vector<SGetRoleCacheData> vecData;
        int freeCount = 0;

		for (int i = 0; i < (int)m_sRoleStatic.GetSize(); i++)
		{
			if (m_sGetRoleStatic.Size() >= SNS_GETTING_ROLE_SIZE) break;

			auto pData = m_sRoleStatic.GetByIndex(i);
			if (pData == NULL) continue;

			vecData.push_back(*pData);
			m_sGetRoleStatic.PushBack(*pData);
			m_sRoleStatic.Erase(pData->roleID);

			++freeCount;
			if ((freeCount >= NFTransGetSnsUserSimple::GetFreeCount()) ||
				(NFTransGetSnsUserSimple::GetUsedCount() + freeCount >= SNS_GETTING_ROLE_SIZE))
				break;
		}

        for (size_t i = 0; i < vecData.size(); ++i) {
            if (TransGetRoleSimpleInfo(&vecData[i])) {
                return;
            }
        }
    }
}

int NFSnsUserSimpleUtil::HandleGetRoleTransFinished(int iRunLogicRetCode, uint64_t roleID) {
    uint32_t timeNow = NFTime::Now().UnixSec();
    bool isDel = false;
    SGetRoleCacheData tmpData;

    tmpData.clear();
    for (auto itr = m_sGetRoleStatic.Begin(); itr != m_sGetRoleStatic.End(); ++itr) {
        if (roleID == itr->roleID) {
            tmpData = *itr;
            isDel = true;
            m_sGetRoleStatic.Erase(itr);
            break;
        }
    }

    if (isDel) {
        for (int i = 0; i < tmpData.roleInfo.GetSize(); ++i) {
            // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
            if (tmpData.roleInfo[i].transID > 0 && (timeNow - tmpData.roleInfo[i].getTime) < TRANS_ACTIVE_TIMEOUT) {
                NFTransBase *pTransBase = NFShmMgr::Instance()->GetTrans(tmpData.roleInfo[i].transID);
                if (pTransBase) {
                    NFTransSnsBase *pTransRoleBase = dynamic_cast<NFTransSnsBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleRes(iRunLogicRetCode, roleID);
                }
            }
        }
    }

    RefreshQueue();

    return 0;
}

NFSnsUserSimple *NFSnsUserSimpleUtil::GetRoleSimpe(uint64_t role_id, bool query) {
    NFSnsUserSimple *pSimple = NFSnsUserSimpleMgr::GetInstance()->GetUser(role_id);
    if (pSimple) {
        if (query == true && !pSimple->IsSyncedRoleSimple()) {
            //GetRoleDetailInfo(role_id, 0);
            return NULL;
        }

        //访问记录
        return pSimple;
    }

    if (query == true) {
        GetRoleSimpleInfo(role_id, 0, NFTime::Now().UnixSec());
    }

    return NULL;
}

