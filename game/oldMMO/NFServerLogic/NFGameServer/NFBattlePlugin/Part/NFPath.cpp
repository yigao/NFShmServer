// -------------------------------------------------------------------------
//    @FileName         :    NFPath.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFPath
//
// -------------------------------------------------------------------------

#include "NFPath.h"
#include "NFLogicCommon/NFGameMath.h"

NFPath::NFPath()
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

NFPath::~NFPath()
{
}

int NFPath::CreateInit()
{
    m_nextIndex = 1;
    return 0;
}

int NFPath::ResumeInit()
{
    return 0;
}

bool NFPath::Init(VEC_POINT3 &path, NFPoint3<float> &curPos)
{
    if (path.size() <= 0)
    {
        return false;
    }
    //
    Clear();
    //
    NFPoint3<float> beginP(curPos.x, curPos.y, curPos.z);
    NFPoint3<float> endP;

    //当前点已经包含在路径中，这里不用再加入当前坐标
    //检验路径后面做
    for (uint32_t i = 0; i < path.size(); i++)
    {
        endP.x = path[i].x;
        endP.y = path[i].y;
        endP.z = path[i].z;
        if (m_path.size() >= m_path.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_path Space Not Enough");
        }
        m_path.push_back(endP);
        beginP = endP;
    }
    return true;
}

bool NFPath::GetLeftPath(VEC_POINT3 &leftPath)
{
    for (uint32_t i = m_nextIndex; i < (uint32_t)m_path.size(); ++i)
    {
        leftPath.push_back(m_path[i]);
    }
    return true;
}

void NFPath::UnInit()
{
    Clear();
}

void NFPath::Clear()
{
    m_path.clear();
    m_nextIndex = 1;
}

bool NFPath::MapPathDistanceToPoint(float setpDistance, NFPoint3<float> &retPos)
{
    float remaining = setpDistance;
    float segmentLen = 0.0f;
    float ratio = 0.0f;
    //
    for (; m_nextIndex < m_path.size(); m_nextIndex++)
    {
        segmentLen = point3Length(m_path[m_nextIndex], m_path[m_nextIndex - 1]);
        if (segmentLen < remaining)
        {
            remaining -= segmentLen;
            retPos = m_path[m_nextIndex];
        }
        else
        {
            ratio  = remaining / segmentLen;
            retPos = interpolate(ratio, m_path[m_nextIndex - 1], m_path[m_nextIndex]);
            m_path[m_nextIndex - 1] = retPos;
            break;
        }
    }
    //
    return (m_nextIndex >= (uint32_t)m_path.size());
}
