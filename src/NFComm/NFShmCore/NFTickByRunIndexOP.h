// -------------------------------------------------------------------------
//    @FileName         :    NFTickByRunIndexOP.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTickByRunIndexOP.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

class NFTickByRunIndexOP
{
public:
    NFTickByRunIndexOP(): m_dwLastTickRunIndex( 0 ), m_iLastTickIndex( 0 ), m_iTickedNum( 0 ), m_dwWaitTickIndex(0), m_iNumPerTick(0), m_bIsTickFinished( false ) {}
    NFTickByRunIndexOP( uint32_t dwWaitTickIndex, int iNumPerTick )
    {
        Init( dwWaitTickIndex, iNumPerTick );
    }
    void Init( uint32_t dwWaitTickIndex, int iNumPerTick )
    {
        m_dwLastTickRunIndex = 0;
        m_iLastTickIndex = 0;
        m_iTickedNum    = 0;
        m_dwWaitTickIndex = dwWaitTickIndex;
        m_iNumPerTick   = iNumPerTick;
        m_bIsTickFinished = false;
    }
    virtual ~NFTickByRunIndexOP() {}
    int TickNow( uint32_t dwCurRunIndex );
    int TickAllWhenStop( uint32_t dwCurRunIndex );
protected:
    virtual int DoTick( uint32_t dwCurRunIndex, bool bIsTickAll = false ) = 0;
    void ResetPerTick( uint32_t dwCurRunIndex )
    {
        if ( m_bIsTickFinished )
        {
            m_iLastTickIndex = 0;
            m_dwLastTickRunIndex  = dwCurRunIndex;
            m_bIsTickFinished = false;
        }

        m_iTickedNum = 0;
    }
    bool IsNeedTick( uint32_t dwCurRunIndex ) const
    {
        return ( ( m_dwLastTickRunIndex + m_dwWaitTickIndex ) <= dwCurRunIndex || ( dwCurRunIndex < m_dwLastTickRunIndex ) );
    }
protected:
    uint32_t m_dwLastTickRunIndex;
    int m_iLastTickIndex;
    int m_iTickedNum;
    uint32_t m_dwWaitTickIndex;
    int m_iNumPerTick;
    bool m_bIsTickFinished;
};

