// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsBase.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFKernelMessage/storesvr_sqldata.pb.h>
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFArray.h"

#define MAX_QUERY_ROLE  120
#define TRANS_SNS_BASE_TIMEOUT 60

struct tagQueryRole
{
	NFArray<uint64_t, MAX_QUERY_ROLE> query_role;
    int		queryed_num;
    uint64_t userId;
public:
	tagQueryRole()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	int CreateInit()
	{
		queryed_num = 0;
        userId = 0;
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

    int Add(uint64_t role_id)
    {
        if( role_id == 0 || query_role.GetSize() >= MAX_QUERY_ROLE )
            return -1;
		query_role.Add(role_id);
        return 0;
    }

    void Reset()
    {
        memset( this, 0, sizeof( tagQueryRole ) );
        queryed_num = 0;
        userId = 0;
    }
} ;

class NFTransSnsBase : public NFTransBase {
public:
    NFTransSnsBase();

    virtual ~NFTransSnsBase();

    int CreateInit();

    int ResumeInit();

    virtual int Init(int reqTrans = 0);

    int OnTransFinished(int iRunLogicRetCode) { return 0; }
    int HandleTransFinished(int iRunLogicRetCode) { return 0; }
    virtual int OnTimeOut() { return 0;}
    virtual bool IsTimeOut();

    virtual int HandleGetRoleRes(int iRunLogicRetCode, uint64_t roleID);
public:
    virtual int QueryRole(tagQueryRole& query);
    virtual int QueryRole(uint64_t roleID);
    virtual int QueryRole();
    virtual int QueryRole_CallBack(tagQueryRole& query);
    void SetNotify() { m_bNotify = true; }
protected:
    tagQueryRole	m_query;
    bool			m_bNotify;
    int             m_reqTrans;
DECLARE_IDCREATE(NFTransSnsBase)
};