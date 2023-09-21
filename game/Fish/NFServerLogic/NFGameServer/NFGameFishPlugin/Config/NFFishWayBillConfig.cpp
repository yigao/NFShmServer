
#include "NFFishWayBillConfig.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include <algorithm>

#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFIniReader.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFComm/NFCore/NFCommon.h"
#include <stdlib.h>

IMPLEMENT_IDCREATE_WITHTYPE(NFFishWayBillConfig, EOT_GAME_FISH_WAY_BILL_DESC_ID, NFShmObj)

NFFishWayBillConfig::NFFishWayBillConfig()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFFishWayBillConfig::~NFFishWayBillConfig()
{

}

int NFFishWayBillConfig::CreateInit()
{
    m_roomId = 0;
    return 0;
}

int NFFishWayBillConfig::ResumeInit()
{
    return 0;
}

void NFFishWayBillConfig::LoadWayBills(const std::string& strWayBillPath, NFShmVector<CFishWayBillData, MAX_WAYBILL_FILE_COUNT>& vecWayBills)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishWayBillMgr::LoadWayBills() {}", strWayBillPath);

    std::list<std::string> FilesList;

    std::string strPath = NFFileUtility::NormalizePath(strWayBillPath);
    NFFileUtility::GetFiles(strPath, FilesList, 0, "*.bill");

    std::list<std::string>::iterator iter = FilesList.begin();
    for (; iter!=FilesList.end(); iter++)
    {
        std::string fileName = NFFileUtility::GetFileName(*iter);
        std::string fileMd5;
        int iRet = NFFileUtility::GetFileContainMD5(*iter, fileMd5);
        if (iRet != 0) continue;

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadWayBills() File: {}", *iter);

        bool find = false;
        for(int i = 0; i < (int)vecWayBills.size(); i++)
        {
            CFishWayBillData* pFishWayBill = &vecWayBills[i];
            if (pFishWayBill->GetFileName() == fileName)
            {
                find = true;
                if (pFishWayBill->GetMD5() != fileMd5)
                {
                    pFishWayBill->Clear();
                    pFishWayBill->Init(*iter);
                    pFishWayBill->SetMD5(fileMd5);
                }
                break;
            }
        }

        if (!find)
        {
            if (vecWayBills.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "vecWayBills full");
                NFSLEEP(1000);
                exit(0);
            }

            vecWayBills.push_back();
            CFishWayBillData* pFishWayBill = &vecWayBills.back();
            CHECK_EXPR(pFishWayBill, , "Way Bills Add Failed!");
            pFishWayBill->Init(*iter);
            pFishWayBill->SetMD5(fileMd5);
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "LoadWayBills() FileCount: {}", vecWayBills.size());
}

int NFFishWayBillConfig::LoadConfig(uint32_t roomId)
{
    m_roomId = roomId;
    std::string strConfigPath = NFFileUtility::NormalizePath(m_pObjPluginManager->GetConfigPath() + "/Config" + NFCommon::tostr(GAME_ID_FISH_HAIWANG_2004) + "_" + NFCommon::tostr(m_roomId));
    LoadWayBills(strConfigPath + NFFileUtility::Clean("WayBill"), m_vecWayBills);
    LoadWayBills(strConfigPath + NFFileUtility::Clean("WayBillExt"), m_vecWayBillExts);
    return 0;
}

CFishWayBillData* NFFishWayBillConfig::GetFishWayBillByFileName(const std::string& fileName)
{
    for(int i = 0; i < (int)m_vecWayBills.size(); i++)
    {
        if (fileName == m_vecWayBills[i].GetFileName())
        {
            return &m_vecWayBills[i];
        }
    }

    for(int i = 0; i < (int)m_vecWayBillExts.size(); i++)
    {
        if (fileName == m_vecWayBillExts[i].GetFileName())
        {
            return &m_vecWayBillExts[i];
        }
    }

    return NULL;
}