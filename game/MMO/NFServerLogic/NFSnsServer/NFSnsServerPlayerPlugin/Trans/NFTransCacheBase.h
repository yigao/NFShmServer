// -------------------------------------------------------------------------
//    @FileName         :    NFTransCacheBase.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransCacheBase
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFQueryRole.h"

class NFTransCacheBase : public NFShmObjTemplate<NFTransCacheBase, EOT_SNS_TRANS_CACHE_BASE_ID, NFTransBase>
{
public:
    NFTransCacheBase();

    virtual ~NFTransCacheBase();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * @brief
     * @param reqTrans
     * @return
     */
    virtual int Init(int reqTrans = 0);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int OnTransFinished(int iRunLogicRetCode) { return 0; }

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int HandleTransFinished(int iRunLogicRetCode) { return 0; }

    /**
     * @brief
     * @return
     */
    virtual int OnTimeOut() { return 0; }

    /** 判断是否超时
     * @brief
     * @return
     */
    virtual bool IsTimeOut();

public:
    /**
     * @brief 查询详情数据
     * @return
     */
    int QueryRoleDetail();

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    virtual int HandleGetRoleDetailRes(int iRunLogicRetCode, uint64_t roleId);

public:
    /**
     * @brief 处理获取角色数据返回
     * @param iRunLogicRetCode
     * @param roleID
     * @return
     */
    virtual int HandleGetRoleSimpleRes(int iRunLogicRetCode, uint64_t roleId);

    /**
     * @brief 查询角色
     * @param query
     * @return
     */
    virtual int QueryRoleSimple(NFQueryRole& query);

    /**
     * @brief 查询角色
     * @param roleID
     * @return
     */
    virtual int QueryRoleSimple(uint64_t roleID);

    /**
     * @brief 查询角色
     * @return
     */
    virtual int QueryRoleSimple();

    /**
     * @brief 查询角色回调
     * @param query
     * @return
     */
    virtual int QueryRole_CallBack(NFQueryRole& query);
public:

    void SetNotify() { m_bNotify = true; }

    void AddQueryedSimpleNum() { m_query.m_queryedNum++; }

    bool IsQuerySimpleFinished() { return m_query.m_queryedNum >= (int)m_query.m_queryRoleList.size(); }

    void AddQueryedDetailNum() { m_query.m_queryedDetailNum++; }

    bool IsQueryDetailFinished() { return m_query.m_queryedDetailNum >= (int)m_query.m_queryRoleList.size(); }
protected:
    NFQueryRole m_query;
    bool m_bNotify;
    int m_reqTrans;
    bool m_bGetDetail;
};