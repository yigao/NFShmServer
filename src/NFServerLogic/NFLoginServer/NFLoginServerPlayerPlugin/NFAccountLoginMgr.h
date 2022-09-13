// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmHashObjectMgr.h"

class NFAccountLogin
{
public:
	NFAccountLogin();
	virtual ~NFAccountLogin();
    int CreateInit();
    int ResumeInit();

public:
    SZ_USER_ACCOUNT  mAccount;
    SZ_USER_ACCOUNT  mPassword;
    SZ_USER_ACCOUNT  mDeviceId;
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
    virtual void OnTimer(int timeId, int callcount);

    int Tick();

    int ClearOne();

	NFAccountLogin *FindAccount(const std::string& account);
	NFAccountLogin *CreateAccount(const std::string& account, const std::string& password, uint64_t playerId, uint32_t accountType, const std::string& deviceId, uint64_t phonenum);

	static int GetExternalDataSize(int objCount) { return NFHashObjectMgr<NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>, NFAccountLogin>::CountSize(objCount);}
private:
    int m_timerId;
    NFHashObjectMgr<SZ_USER_ACCOUNT, NFAccountLogin> m_oAccountHash;
	DECLARE_IDCREATE(NFAccountLoginMgr)
};
