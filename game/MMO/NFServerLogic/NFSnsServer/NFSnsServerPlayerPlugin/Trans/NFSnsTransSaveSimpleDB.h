// -------------------------------------------------------------------------
//    @FileName         :    NFTransLogicUserBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransLogicUserBase.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"

class NFPlayerSimple;
class NFSnsTransSaveSimpleDB : public NFTransBase {
public:
    NFSnsTransSaveSimpleDB();

    virtual ~NFSnsTransSaveSimpleDB();

    int CreateInit();

    int ResumeInit();

    virtual int HandleTransFinished(int iRunLogicRetCode);
public:
    int SaveDB(NFPlayerSimple* pPlayer);
private:
    uint32_t m_curSeq;
    uint32_t m_cid;
DECLARE_IDCREATE(NFSnsTransSaveSimpleDB)
};
