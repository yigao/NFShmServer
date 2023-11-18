// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTeamMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTeamMgr
//
// -------------------------------------------------------------------------

#include "NFSnsTeamMgr.h"

NFSnsTeamMgr::NFSnsTeamMgr()
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

NFSnsTeamMgr::~NFSnsTeamMgr()
{
}

int NFSnsTeamMgr::CreateInit()
{
    return 0;
}

int NFSnsTeamMgr::ResumeInit()
{
    return 0;
}

int NFSnsTeamMgr::LoadFromDB(const std::string& dbData)
{
    auto teamPb = m_teamData.make_pbmsg();
    teamPb.ParseFromString(dbData);
    m_teamData.read_from_pbmsg(teamPb);
    return 0;
}

int NFSnsTeamMgr::SaveToDB(std::string& dbData)
{
    auto teamPb = m_teamData.make_pbmsg();
    m_teamData.write_to_pbmsg(teamPb);

    dbData = teamPb.SerializeAsString();
    return 0;
}

int NFSnsTeamMgr::InitConfig()
{
    m_teamData.team_id = 1;
    MarkDirty();
    return 0;
}

