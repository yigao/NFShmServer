// -------------------------------------------------------------------------
//    @FileName         :    NFMagicTimeUtil.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMagicTimeUtil.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFTimeUtil.h"

class NFMagicTimeUtil
{
public:
    static int GetCurDate(unsigned int iCurTime, int &iYear, int &iMonth, int &iMonthDay);
    static int GetCurTime( unsigned int iCurTime, int &week, int &hour, int &minute, int &second );
    static bool IsSameDayStd(time_t tCur, time_t tBefore); //标准时间，以零点算, 支持回调
    static bool IsSameWeekStd(time_t tNow,time_t tBeforeTime); //标准时间，以零点算，支持回调
    //以每天GAME_RESET_HOUR_EVERYDAY 点为准
    static bool IsSameDay(time_t tCur, time_t tBefore);
    static bool IsSameHour( time_t tCur, time_t tBefore );
    static time_t GetTodayStartTime( time_t tTimeNow );// 获取今天零点的绝对时间秒值;

    //static time_t MakeTimeBegin(time_t tNow,char chType, TIMEDETAIL * pstConfigTime);
    //static time_t MakeTimeEnd(time_t tNow,char chType, TIMEDETAIL * pstConfigTime);

    //获取时间是礼拜几，注意是 礼拜1到礼拜天
    static int GetWeekDay127(time_t tTime);
    static int GetMonthDay(time_t tTime);
    //获取这个礼拜开始时间，从礼拜1凌晨开始
    static time_t GetThisWeekStartTime1(time_t tTime,int iHour = 0);


    //justinzhu,begin
    //iOffset,偏移的秒数
    static time_t GetTodayStartTime2( time_t tTimeNow,int iOffset);
    //Offset，偏移的秒数
    static time_t GetThisWeekStartTime2(time_t tTime, int iOffset);
    //Offset，偏移的秒数
    static time_t GetWeekDay2(time_t tTime, int iOffset);
    //justinzhu,end

    //获取两个时间之间,相隔几周.
    static int GetOffsetWeeks( time_t tTime, time_t tNow );

    //获取这个礼拜结束时间，从礼拜天12点结束
    static time_t GetThisWeekEndTime(time_t tTime,int iHour = 0);

    //是否是同一个礼拜，从礼拜1凌晨开始
    static bool IsSameWeek127(time_t tNow,time_t tBeforeTime,int iHour = 0);

    //按周循环链功能
    static int GetWeekCycleChainIndex(time_t tNow,int iChainLength);

    //获取这个月开始和结束时间
    static void GetThisMonthStartEndTime(time_t tTime,time_t &tBegin,time_t &tEnd,int iHour = 0);

    //是一时段,什么意思呢?就是是否是同一天，同一礼拜,同一个月
    //要求逻辑上tCur 时候在tBefore之后，比如tCur是当前时间，tBefore是之前存的一个时间
    static bool IsSameTimePeroid(time_t tCur, time_t tBefore,char chType);

    /*
    现在是不是在tTime的后1~n天了,天的临界点时间按凌晨n点计算
    */
    static bool IsAfterDayByUTCTime(time_t tNow,time_t tTime,int iHour = 0);

    /*
    过去了多少天
    */
    static int GetDayElapse(time_t tNow,time_t tTime,int iHour = 0);

    /*
    计算天数，以iHour点为分界
    */
    static uint32_t GetAbsDay(time_t tNow, int iHour=0);

    /*
    以Hour为分界时间的今天
    */
    static time_t GetTodayStartTime( time_t tTimeNow,int iHour);
    static time_t GetTodayStartTimeByMin( time_t tTimeNow, int iHour , int iMin);
    /*
    tdr时间转换成秒
    H*3600+M*60+S
    */
    static time_t GetShiTuoFengYinBreakTime( time_t tBreakTime );

    static const char *GetWeekDayStringByStartZero( uint8_t bWeekDayIndex );

    static bool IsTimePassedS(time_t tNow, time_t tLast, int iGap)
    {
        return (tNow - tLast) >= iGap;
    }

    static bool IsTimePassedMS(struct timeval tvNow, struct timeval tvLast, int iGapMS)
    {
        int64_t i64RealGapMS = (tvNow.tv_sec - tvLast.tv_sec)*1000 + (tvNow.tv_usec - tvLast.tv_usec)/1000;
        return i64RealGapMS >= iGapMS;
    }

    static bool IsSameMonth(time_t tCur, time_t tBefore);

    static int GetWeekDayIndexWithStartHour( uint32_t dwTimeNow, uint8_t bStartHour );

    static bool IsOKWithWeekDayCtrl( uint8_t bWeekDayCtrlFlag, uint32_t dwTimeNow );

    static time_t ToTimestamp(int iYear, int iMon, int iMDay/*day of the month */, int iHour, int iMin, int iSec );

    // 获取月的天数
    static short GetCurMonthDay(int year, int month);
    static int64_t GetNextMonthDay(int year, int month, int day, int &nMonth);

    // 获取现在时间距离下一个小时整点的秒数
    static int GetOffsetToNextHour(time_t tCur);
    // 获取现在时间距离下一个半小时整点的秒数
    static int GetOffsetToNextHalfHour(time_t tCur);
    // 获取现在时间距离下一天零点的秒数
    static int GetOffsetToNextDay(time_t tCur);

    // 获取时间的实际年
    static int GetYearByTimestamp(time_t tCur);
    // 获取2个时间相隔的天数, 按0点算
    static int GetDaysDelta(time_t tOne, time_t tTwo);
    //获取本周某日的开始时间
    static time_t GetThisWeekDayTime(time_t tNow, int iWeekDay);

    static uint64_t GetTimeByWeekDay(uint64_t ullWeek, int iDay);
};

