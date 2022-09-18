// -------------------------------------------------------------------------
//    @FileName         :    NFTickByRunIndexOP.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTickByRunIndexOP.cpp
//
// -------------------------------------------------------------------------

#include "NFTickByRunIndexOP.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

int NFTickByRunIndexOP::TickNow(uint32_t dwCurRunIndex)
{
    int iRetCode = 0;

    if ( IsNeedTick( dwCurRunIndex ) == false )
    {
        return 0;
    }

    m_iTickedNum = 0;
    iRetCode = DoTick(dwCurRunIndex, true);

    if ( iRetCode != 0 )
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,  "DoTick Failed" );
    }

    ResetPerTick( dwCurRunIndex );

    return 0;
}

int NFTickByRunIndexOP::TickAllWhenStop( uint32_t dwCurRunIndex )
{
    int iRetCode = 0;
    iRetCode = DoTick( dwCurRunIndex, true );
    m_iTickedNum = 0;

    if ( iRetCode != 0 )
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,   "DoTick Failed" );
    }

    ResetPerTick( dwCurRunIndex );

    return 0;
}