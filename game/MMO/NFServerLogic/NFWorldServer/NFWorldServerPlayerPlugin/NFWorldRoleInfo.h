// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoleInfo.h
//    @Author           :    gaoyi
//    @Date             :    22-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoleInfo
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmString.h"
#include "Com_s.h"
#include "NFLogicCommon/NFPoint3.h"
#include "DBProto.pb.h"

class NFWorldRoleInfo
{
public:
    NFWorldRoleInfo();

    virtual ~NFWorldRoleInfo();

    int CreateInit();

    int ResumeInit();
public:
    void SetRoleInfo(const proto_ff::RoleDBData &dbproto);
public:
    uint64_t            m_cid;			//角色cid
    NFShmString<64>    m_name;				//角色名字
    uint32_t            m_prof;			//职业
    uint32_t            m_level;			//等级
    uint64_t            m_fight;			//战力
    uint64_t            m_createtime;	//创建时间
    proto_ff_s::RoleFacadeProto_s m_facade;		//外观
    uint64_t            m_sceneId;
    uint64_t            m_mapId;
    NFPoint3<float>     m_pos;
    uint64_t            m_lastSceneId;
    uint64_t            m_lastMapId;
    NFPoint3<float>     m_lastpos;
    uint32_t            m_logicId;
};