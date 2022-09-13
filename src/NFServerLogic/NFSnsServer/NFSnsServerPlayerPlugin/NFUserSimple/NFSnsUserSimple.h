// -------------------------------------------------------------------------
//    @FileName         :    NFSnsUserSimple.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsUserSimple.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFSeqOP.h"

class NFSnsUserSimple : public NFShmObj, public NFSeqOP {
public:
    NFSnsUserSimple();

    virtual ~NFSnsUserSimple();

    int CreateInit();

    int ResumeInit();
public:
    int InitWithSnsRoleSimpleInfo(const proto_ff::tbUserSimpleData *rolesimple);
	int MakeUserDataCS(proto_ff::tbUserSimpleData& data);
	int SetLogicRoleSimpleInfo(const proto_ff_s::UserSimpleData_s& rolesimple);
    int GetLogicRoleSimpleInfo(proto_ff_s::UserSimpleData_s& rolesimple);
    int GetLogicRoleSimpleInfo(proto_ff::UserSimpleData& rolesimple);

	int UserLogout();
public:
    uint64_t GetUserId() const { return m_userData.userid; }
	bool CanDelete();

    std::string GetNickName() const { return m_userData.nickname.GetString(); }

    uint32_t GetFace() const { return m_userData.face; }

    proto_ff_s::tbUserSimpleData_s* GetSimpleData() { return &m_userData; }

    bool IsSyncedRoleSimple() { return m_bSimpleInited; }

	int SaveToDB(bool bForce);

	int SaveUserSimpleToDB();

	int OnUserSimpleSaved(bool success, uint32_t seq);
public:
    proto_ff_s::tbUserSimpleData_s m_userData;
private:
    bool m_bSimpleInited;
	int m_iSaveTransID;
	uint32_t m_dwRoleSimpleInfoSavingDBTime;
DECLARE_IDCREATE(NFSnsUserSimple)
};