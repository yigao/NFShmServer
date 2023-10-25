// -------------------------------------------------------------------------
//    @FileName         :    NFMagicTimeUtil.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMagicTimeUtil.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFTimeUtil.h"

class NFTimeUtility
{
public:
    // 获取时差（秒数）
    static uint32_t GetGMTSec();
    
    // 获取本地时间（经过的秒数）
    static uint32_t GetLocalTime();
    
    // 根据秒数（UTC，GetTime()返回）计算当地天数
    // 1970年1月1日 返回0
    // 1970年1月2日 返回1
    // 1970年1月3日 返回2
    // ……依此类推
    static uint32_t GetLocalDay();
    static uint32_t GetLocalDay(uint64_t unixSec);
    
    // 计算当地周数
    // 1970年1月1日 星期四 返回0
    // 1970年1月4日 星期日 返回0
    // 1970年1月5日 星期一 返回1
    static uint32_t GetLocalWeek();
    static uint32_t GetLocalWeek(uint64_t unixSec);
    
    // 计算当地月份
    static uint32_t GetLocalMonth(uint64_t unixSec);
    
    // 根据当地时间，计算当前是本周的哪一天（星期几）
    // 返回值  1 - 7(星期一到星期天）
    static uint32_t GetLocalWeekDay();
    
    //根据秒数（UTC，GetTime()）返回是一周的哪一天
    static uint32_t GetLocalWeekDay(uint64_t unixSec);
    
    // 根据当地时间，计算当前是本月的哪一天（几号）
    // 返回值  1-31
    static uint32_t GetLocalMonthDay();
    
    //判断闰年
    static bool IsLeapYear(uint32_t year) { return ((0 == year % 4 && 0 != year % 100) || 0 == year % 400); }
    // 根据当地时间，计算月有多少天
    // 返回值  1-31
    static uint32_t GetDaysOfMonth(int year, int month);
    static uint32_t GetDaysOfMonth();
    
    // 返回格式化的本地时间，fmt格式如%Y%m%d%H%M%S等
    static bool LocalDateFormat(const char* fmt, char* timeStr, size_t len);
    
    // 返回本地时间戳，格式如：20150911111926
    static std::string GetLocalTimeStamp();
    static std::string GetTimeStamp(uint64_t unixMSec);
    
    // 返回本地时间戳，格式如：2015_09_11 11:19:26
    static std::string GetLocalTimeStampPrint();
    static std::string GetTimeStampPrint(uint64_t unixMSec);
    
    // timestamp格式为：20150911111926
    static uint64_t LocalTimeStampToUnixSec(const char* timestamp);
    
    // format格式如 %d-%d-%d %d:%d:%d
    static uint64_t LocalTimeStampToUnixSec(const char* format, const char* timestamp);
    
    // 检查换天
    static bool CheckDayChange(uint64_t curUnixSec, uint64_t lastUnixSec, bool* isWeekChange);
    // 检查是否是同一周
    static bool CheckSameWeek(uint64_t curUnixSec, uint64_t lastUnixSec);
    // 检查是否是同一天
    static bool CheckSameDay(uint64_t curUnixSec, uint64_t lastUnixSec);
    // 检查是否同一个月
    static bool CheckSameMonth(uint64_t curUnixSec, uint64_t lastUnixSec);
    // 检查是否需要每日更新 返回值：true 需要每日更新，false 不需要每日更新
    static bool CheckDayUpdate(uint64_t curUnixSec, uint64_t lastUnixSec);
    //检查是否需要每周更新 返回值：true 需要每周更新，false 不需要每周更新
    static bool CheckWeekUpdate(uint64_t curUnixSec, uint64_t lastUnixSec);
    //通过当前时间获取每日更新的时间
    static uint64_t GetDayUpdateTime(uint64_t curUnixSec);
    //通过当前时间获取每周更新的时间
    static uint64_t GetWeekUpdateTime(uint64_t curUnixSec);
    //检查是否需要每周更新 返回值：true 需要每周更新，false 不需要每周更新
    static bool CheckWeekUpdate(uint64_t curUnixSec, uint64_t lastUnixSec, int32_t nHour);
    //检查是否需要每日更新 返回值：true 需要每日更新，false 不需要每日更新
    static bool CheckDayUpdate(uint64_t curUnixSec, uint64_t lastUnixSec, int32_t nHour);
    //判断当前时间是否落在某时间段范围内
    static bool BetweenDate(uint32_t startDate, uint32_t endData);
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

