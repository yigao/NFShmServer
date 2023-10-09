// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoleInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoleInfo
//
// -------------------------------------------------------------------------

#include "NFWorldRoleInfo.h"

NFWorldRoleInfo::NFWorldRoleInfo()
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

NFWorldRoleInfo::~NFWorldRoleInfo()
{

}

int NFWorldRoleInfo::CreateInit()
{
    m_cid = 0;			//角色cid
    m_prof = 0;			//职业
    m_level = 0;			//等级
    m_fight = 0;			//战力
    m_createtime = 0;	//创建时间
    m_sceneId = 0;
    m_mapId = 0;
    m_lastSceneId = 0;
    m_lastMapId = 0;
    m_logicId = 0;
    return 0;
}

int NFWorldRoleInfo::ResumeInit()
{
    return 0;
}

void NFWorldRoleInfo::SetRoleInfo(const proto_ff::RoleDBData &dbproto)
{
    m_cid = dbproto.cid();
    m_level = dbproto.base().level();
    m_name = dbproto.base().name();
    m_prof = dbproto.base().prof();
    m_fight = dbproto.base().fight();
    m_createtime = dbproto.base().createtime();
    m_facade.read_from_pbmsg(dbproto.base().facade());

    m_sceneId = dbproto.base().enter_scene_id();
    m_mapId = dbproto.base().enter_map_id();
    m_pos.x = dbproto.base().enterposx();
    m_pos.y = dbproto.base().enterposy();
    m_pos.z = dbproto.base().enterposz();

    m_lastSceneId = dbproto.base().lastsceneid();
    m_lastMapId = dbproto.base().lastmapid();
    m_lastpos.x = dbproto.base().lastposx();
    m_lastpos.y = dbproto.base().lastposy();
    m_lastpos.z = dbproto.base().lastposz();
}
