// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFPlayerDefine.h"

class NFSnsPart;
class NFPlayerSimple;
class NFPlayerDetail : public NFShmObj, public NFSeqOP
{
public:
    NFPlayerDetail();

    virtual ~NFPlayerDetail();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetRoleId() const;

    void SetPlayerId(uint64_t roleId);

public:
    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    bool CanDelete();

public:
    int Init(const proto_ff::tbFishSnsPlayerData &data);
public:
    NFSnsPart *CreatePart(uint32_t partType, const ::proto_ff::tbFishSnsPlayerData &data);
    int RecylePart(NFSnsPart *pPart);
    //获取对应部件指针
    virtual NFSnsPart *GetPart(uint32_t partType);
public:
    NFPlayerSimple* GetRoleSimple() const;
private:
    /**
     * @brief
     */
    bool m_isInited;

    /**
     * @brief
     */
    uint64_t m_playerId;
public:
    NFShmVector<int, SNS_PART_MAX> m_pPart;
DECLARE_IDCREATE(NFPlayerDetail)
};