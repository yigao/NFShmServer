// -------------------------------------------------------------------------
//    @FileName         :    NFTestMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-2-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFComm/NFShmStl/NFShmList.h"

class NFTestData
{
public:
    NFTestData()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        a = 0;
        b = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int a;
    int b;
};

class NFTestMgr : public NFIDescStore
{
public:
    NFTestMgr();

    virtual ~NFTestMgr();

    int CreateInit();

    int ResumeInit();

private:
    NFShmVector<uint32_t, 10> m_vec;
    NFShmVector<NFTestData, 10> m_data;
    NFShmVector<NFShmPair<uint32_t, NFTestData>, 10> m_pair;
    NFShmList<uint32_t, 10> m_vecList;
    NFShmList<NFTestData, 10> m_dataList;
    NFShmHashMap<uint32_t, uint64_t, 10> m_map;
    NFShmHashMap<uint32_t, NFTestData, 10> m_mapData;
DECLARE_IDCREATE(NFTestMgr)
IMPL_RES_SIMPLE_DESC(NFTestMgr);
};