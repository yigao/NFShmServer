// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleList.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleList
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "Base/NFTransPlayerBase.h"

typedef enum
{
    EN_TGRL_INIT = 0,
    EN_TGRL_GET_ROLELIST = 1,
    EN_TGRL_FIN_OK = 2,
} ETransGetRoleListState;

class NFTransGetRoleList : public NFTransPlayerBase
{
public:
    NFTransGetRoleList(NFIPluginManager* pPluginManager);

    virtual ~NFTransGetRoleList();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param pCSMsgReq
     * @return
     */
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    /**
     * @brief
     * @param pSSMsgRes
     * @param cmd
     * @param table_id
     * @param seq
     * @param err_code
     * @return
     */
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int HandleTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_bornZid;
    uint64_t m_proxyId;
    uint64_t m_clientId;
DECLARE_IDCREATE(NFTransGetRoleList)
};