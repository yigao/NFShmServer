// -------------------------------------------------------------------------
//    @FileName         :    NFFishWayBill.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishWayBill.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishCtrlCfgDef.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmStl/NFShmList.h"

#define MAX_FISH_WAY_BILL_COUNT 1000

class CFishWayBill;
class CFishWayBillData
{
    friend class CFishWayBill;
public:
    CFishWayBillData();
    ~CFishWayBillData();
    int CreateInit();
    int ResumeInit();
    void Clear();
public:
    int Init(const std::string & strWayBillFile);
    std::string GetFileName();
    std::string GetMD5();
    void SetFileName(const std::string& name);
    void SetMD5(const std::string& md5);

    int GetItemCount()const;
    int GetInterval()const;
    int GetDefaultGroupDelay() const;
protected:
    NFCommonStr m_strFileName;
    uint16_t    m_usInterval;  //两个点之间的时间间隔
    uint16_t    m_usDefaultGroupDelay;
    NFShmVector<FishWayBillItem, MAX_FISH_WAY_BILL_COUNT> m_ItemList;    //路单项列表
    NFCommonStr m_szMD5;
};

class CFishWayBill
{
public:
    CFishWayBill();
    virtual ~CFishWayBill();
    int CreateInit();
    int ResumeInit();
    void Clear();
    int GetInterval()const;
    int GetDefaultGroupDelay() const;
	int GetLeftCount() { return m_ItemList4Use.size(); }

    std::string GetFileName();
    void CopyFrom(const CFishWayBillData& data)
    {
        m_ItemList4Use.insert(m_ItemList4Use.end(), data.m_ItemList.begin(), data.m_ItemList.end());
        m_usInterval = data.m_usInterval;
        m_usDefaultGroupDelay = data.m_usDefaultGroupDelay;
        m_strFileName = data.m_strFileName;
    }
public:
	int  GetOneItem(FishWayBillItem & Item);
    bool ForcastOneItem(FishWayBillItem & Item);
    int  Reset(NFIPluginManager* pPluginManager, uint32_t roomId);
protected:
    NFShmList<FishWayBillItem, MAX_FISH_WAY_BILL_COUNT> m_ItemList4Use; //使用的路单项列表
    uint16_t    m_usInterval;  //两个点之间的时间间隔
    uint16_t    m_usDefaultGroupDelay;
    NFCommonStr m_strFileName;
};