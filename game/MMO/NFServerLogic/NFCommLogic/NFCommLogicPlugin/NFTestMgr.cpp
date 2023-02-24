// -------------------------------------------------------------------------
//    @FileName         :    NFTestMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestMgr
//
// -------------------------------------------------------------------------

#include "NFTestMgr.h"
#include "NFComm/NFCore/NFCommon.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTestMgr, EOT_NFTestMgr_ID, NFShmObj)

NFTestMgr::NFTestMgr()
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

NFTestMgr::~NFTestMgr()
{
}

int NFTestMgr::CreateInit()
{
    return 0;
}

int NFTestMgr::ResumeInit()
{
    return 0;
}

int NFTestMgr::Load(NFResDB *pDB)
{
    for(int i = 0; i < (int)10; i++)
    {
        m_vec.push_back(i);
        m_vecList.push_back(i);
        NFTestData data;
        data.a = i;
        data.b = i+1;
        m_data.push_back(data);
        m_dataList.push_back(data);
        NFShmPair<uint32_t, NFTestData> pair;
        pair.first = i;
        pair.second = data;
        m_pair.push_back(pair);

        m_map.emplace_hint(i, i*100);
        m_mapData.emplace_hint(i, data);
    }
    return 0;
}

int NFTestMgr::CheckWhenAllDataLoaded()
{
    std::string strVec;
    for(int i = 0; i < (int)m_vec.size(); i++)
    {
        strVec += NFCommon::tostr(m_vec[i]) + " ";
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "vec:{}", strVec);

    std::string strData;

    for(int i = 0; i < (int)m_data.size(); i++)
    {
        strData += NF_FORMAT("(a={},b={})", m_data[i].a, m_data[i].b);
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "data:{}", strData);

    std::string strPair;

    for(int i = 0; i < (int)m_pair.size(); i++)
    {
        strPair += NF_FORMAT("(key:{},a={},b={})", m_pair[i].first, m_pair[i].second.a, m_pair[i].second.b);
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "pair:{}", strPair);

    std::string strList;
    for(auto iter = m_vecList.begin(); iter != m_vecList.end(); iter++)
    {
        strList += NFCommon::tostr(*iter) + " ";
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "strList:{}", strList);

    std::string strDataList;

    for(auto iter = m_dataList.begin(); iter != m_dataList.end(); iter++)
    {
        strDataList += NF_FORMAT("(a={},b={})", iter->a, iter->b);
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "strDataList:{}", strDataList);

    std::string strMap;
    for(auto iter = m_map.begin(); iter != m_map.end(); iter++)
    {
        strMap += NF_FORMAT("(first={},second={})", iter->first, iter->second);
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "strMap:{}", strMap);

    std::string strMapData;

    for(auto iter = m_mapData.begin(); iter != m_mapData.end(); iter++)
    {
        strMapData += NF_FORMAT("(first={},second=(a={},b={}))", iter->first, iter->second.a, iter->second.b);
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "strMapData:{}", strMapData);
    return 0;
}