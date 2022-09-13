// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFDBObjMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmObj.h"
#include "NFShmStaticList.hpp"
#include "NFComm/NFPluginModule/NFServerDefine.h"

class NFBaseDBObj;
class NFDBObjTrans;
class NFDBObjMgr : public NFShmObj
{
public:
    NFDBObjMgr();
    virtual ~NFDBObjMgr();

    //非继承函数, 不要加virtual
    int CreateInit();
    //非继承函数, 不要加virtual
    int ResumeInit();

    //must be virtual
    virtual void OnTimer(int timeId, int callcount) override;
public:
    NFBaseDBObj* GetObj(int iObjID);
    int LoadFromDB(NFBaseDBObj* pObj);
    int OnDataLoaded(int iObjID, uint32_t err_code, const std::string* msg);
    int OnDataInserted(NFDBObjTrans* trans, bool success);
    int OnDataSaved(NFDBObjTrans* trans, bool success);
    int SaveToDB(NFBaseDBObj* pObj);
    int Tick();
private:
    int m_iLastSavingObjIndex;
    uint32_t m_iLastTickTime;
    int m_iTransMngObjID;
    int m_iTimer;
    NFShmStaticList<int, 1024> m_runningObjList;
    NFShmStaticList<int, 1024> m_failedObjList;
DECLARE_IDCREATE(NFDBObjMgr)
};
