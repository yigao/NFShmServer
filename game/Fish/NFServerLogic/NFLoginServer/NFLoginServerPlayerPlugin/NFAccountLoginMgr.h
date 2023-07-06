// -------------------------------------------------------------------------
//    @FileName         :    NFAccountLoginMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFAccountLoginMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmString.h"
#include "NFComm/NFShmStl/NFShmHashMapWithList.h"
#include "NFLogicCommon/NFLoginDefine.h"


class NFAccountLogin
{
public:
	NFAccountLogin();
	virtual ~NFAccountLogin();
    int CreateInit();
    int ResumeInit();

public:
    NFCommonStr  mAccount;
    NFCommonStr  mPassword;
    NFCommonStr  mDeviceId;
    uint64_t mPhoneNum;
	uint64_t mPlayerId;
	uint64_t mLastLoginTime;
	uint32_t mAccountType;
};

class NFAccountLoginMgr: public NFShmObj
{
public:
	NFAccountLoginMgr();

	virtual ~NFAccountLoginMgr();

	int CreateInit();
	int ResumeInit();

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);

    int Tick();

    int ClearOne();

    /**
     * @brief 查找账号数据
     * @param account
     * @return
     */
    NFAccountLogin* FindAccount(const std::string& account);

    /**
     * @brief 创建账号
     * @param account
     * @param password
     * @param playerId
     * @param accountType
     * @param deviceId
     * @param phonenum
     * @return
     */
    NFAccountLogin *CreateAccount(const std::string& account, const std::string& password, uint64_t playerId, uint32_t accountType, const std::string& deviceId, uint64_t phonenum);
private:
    int m_timerId;
    NFShmHashMapWithList<NFCommonStr, NFAccountLogin, ONE_LOGIN_SERVER_MAX_LOGIN_ACCOUNT> m_accountMap;
	DECLARE_IDCREATE(NFAccountLoginMgr)
};
