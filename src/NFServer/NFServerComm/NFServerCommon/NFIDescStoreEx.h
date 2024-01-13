// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    23-9-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFIDescStoreEx : public NFShmObj
{
public:
    NFIDescStoreEx();

    virtual ~NFIDescStoreEx();

    int CreateInit();

    int ResumeInit();
public:
    virtual int Load();

    virtual int Reload();

    virtual int CheckWhenAllDataLoaded();
public:
    void SetValid()
    {
        m_bValid = true;
    }

    bool IsValid()
    {
        return m_bValid;
    }

    void SetLoaded(bool bIsLoaded)
    {
        m_bIsLoaded = bIsLoaded;
    }

    bool IsLoaded()
    {
        return m_bIsLoaded;
    }

    void SetChecked(bool bIsChecked)
    {
        m_bIsChecked = bIsChecked;
    }

    bool IsChecked()
    {
        return m_bIsChecked;
    }

    virtual int PrepareReload()
    {
        return 0;
    }
private:
    bool m_bValid;
    bool m_bIsLoaded;
    bool m_bIsChecked;
};