// -------------------------------------------------------------------------
//    @FileName         :    NFTimeUtil.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTimeUtil.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#include <stdlib.h>
#include <stdio.h>
#include "NFSocketLibFunction.h"


typedef struct timeval TTimeVal;

enum {
    LOCAL_TIME_CORRECTION_HOUR = 8,
    LOCAL_TIME_CORRECTION = LOCAL_TIME_CORRECTION_HOUR * 3600, //本地时间时区偏移
    SECONDS_ADAY = 24 * 3600, //1天的秒数
    SECONDS_AWEEK = 24 * 3600 * 7,//1礼拜的秒数
    SECONDS_AHOUR = 3600,
    SECONDS_HALF_AHOUR = 1800,
    HOURS_AWEEK = 24 * 7,
    SECONDS_AMONTH = 24 * 3600 * 30,
    GAME_RESET_HOUR_EVERYDAY = 0,//游戏里按天重置的时间，比如疲劳，日常...
    GAME_RESET_MIN_EVERYDAY = 0,
    GAME_RESET_SEC_EVERYDAY = 0,
};

inline bool operator<(const TTimeVal &lhs, const TTimeVal &rhs) {
    return ((lhs.tv_sec - rhs.tv_sec) * 1000000 + (lhs.tv_usec - rhs.tv_usec)) < 0;
}

inline bool operator<=(const TTimeVal &lhs, const TTimeVal &rhs) {
    return !(rhs < lhs);
}

inline bool operator==(const TTimeVal &lhs, const TTimeVal &rhs) {
    return (!(lhs < rhs) && !(rhs < lhs));
}

inline TTimeVal operator-(const TTimeVal &lhs, const TTimeVal &rhs) {
    TTimeVal tvGap;
    tvGap.tv_sec = lhs.tv_sec - rhs.tv_sec;
    tvGap.tv_usec = lhs.tv_usec - rhs.tv_usec;

    if (tvGap.tv_usec < 0) {
        tvGap.tv_usec += 1000000;
        tvGap.tv_sec -= 1;
    }

    return tvGap;
}

char *DateTimeToStr_R(time_t *mytime, char *s, int *pio, bool bOnlyDay = false);

const char *DateTimeToStrSimCN_R(time_t *mytime, char *s, int *pio);

char *SecondToStr(time_t mytime);

const char *DataTimeToStrSimCN(time_t tmytime);

char *USecondTimeToStr(const TTimeVal &tvTime, char *pszOut = NULL, int iOutLen = 128);

char *DateTimeToStr(time_t *mytime);

char *DateTimeToStr(time_t mytime, bool bOnlyDay = false);

char *DateTimeToStr(int imytime);

char *DateTimeToStrDw(uint32_t dwMytime);

char *DateTimeToStr(time_t *mytime, char *piIn);

char *CurTimeToStr(time_t tNow);

//xxxx 20160325 修改时间由外部传入，因为时间可能不是time（NULL）取到的当前时间
char *CurTimeToStr_R(time_t tNow, char *pszDateTime, int *piInOutLen);


/*
//note: rhs 应该是间隔,而不是实际的时间,否则出错
//因为返回值是32位。只能表示24天
inline unsigned int ToMs(const TTimeVal &rhs)
{
    unsigned int m_tmp =0;
    m_tmp = rhs.tv_sec * 1000;
    m_tmp = m_tmp + rhs.tv_usec / 1000;
    return m_tmp;
}
*/
inline void AddMsWithPointer(TTimeVal *plhs, int iMs) {
    plhs->tv_sec += (iMs / 1000);
    plhs->tv_usec += ((iMs % 1000) * 1000);
    plhs->tv_sec += (plhs->tv_usec / 1000000);
    plhs->tv_usec = plhs->tv_usec % 1000000;
}

inline void AddMs(TTimeVal &lhs, int iMs) {
    AddMsWithPointer(&lhs, iMs);
}


inline void AddUsWithPointer(TTimeVal *plhs, int iUs) {
    plhs->tv_usec += iUs;
    plhs->tv_sec += (plhs->tv_usec / 1000000);
    plhs->tv_usec = plhs->tv_usec % 1000000;
}

inline void AddUs(TTimeVal &lhs, int iUs) {
    AddUsWithPointer(&lhs, iUs);
}


//fmt YYYY-MM-DD HH:MM:SS
int StrToTime(const char *psztime, time_t *ptime);

time_t StrToTimePure(const char *psztime);

int SysTime(char *pszBuff, int iBuff);

time_t __DATE__TIME_toTime(const char *sz__DATE__, const char *sz__TIME__);

uint64_t GetCurrTimeUs();

inline unsigned int TimeMsPass(struct timeval *pstTv1, struct timeval *pstTv2) {
    int iSec;
    iSec = pstTv1->tv_sec - pstTv2->tv_sec;

    if (iSec < 0 || iSec > 100000) {
        iSec = 100000;
    }

    return iSec * 1000 + (pstTv1->tv_usec - pstTv2->tv_usec) / 1000;
}

inline int64_t TimeUsPass(struct timeval *pstTv1, struct timeval *pstTv2) {
    int iSec;
    iSec = pstTv1->tv_sec - pstTv2->tv_sec;

    if (iSec < 0 || iSec > 100000) {
        iSec = 100000;
    }

    return iSec * 1000000 + (pstTv1->tv_usec - pstTv2->tv_usec);
}

uint64_t GetTimeOfDayMS();

/* Time string format :yyyy-mm-dd hh:mm:ss */
long MakeTime(char *szTime);

char *TimeToStr(const TTimeVal *pstCurr, char *pszString = NULL, int iMaxLen = 64);

char *CurrTimeStr(const TTimeVal *pstCurr);

//前7位是年(从2000年开始)，中间4位是月份，最后5位是日
unsigned short MakeShortTime(time_t tTime);

bool IsSameDayByGameResetTime(time_t tCur, time_t tBefore);

uint32_t GetAbsWeek(time_t tTime);

uint32_t GetAbsDay(time_t tTime);

uint32_t GetThisWeekStartTime(time_t tTime);

bool IsSameMonthWithOffsetHour(time_t tTimeA, time_t tTimeB, int iOffsetHour);

bool IsSameMonth(time_t tTimeA, time_t tTimeB);


//根据周几和偏移时间值,拼接当前的绝对时间. bWeekDay 里 0 表示周一.
//xxxx ,2013-03-21
uint32_t GetAbsTimeByWeekDayAndTime(time_t tNow, uint8_t bWeekDay, uint32_t dwWeekTime);

// 获取自然年
uint16_t GetTimeYear(time_t tTime);

uint16_t GetWeekDay(time_t tTime);

uint16_t GetWeekDay();

uint16_t GetMonthDay(time_t tTime);

uint16_t GetMonthDay();

uint16_t GetMonth(time_t tTime);

uint16_t GetHour(time_t tTime);

uint32_t GetDayAbsSec(time_t tTime);

//fmt YYYY-MM-DD-HH-MM-SS
time_t time_str_to_utc(char *szInput);

time_t GetTodayStartTime(time_t tTimeNow, int iHour);

int DataStrToLocalTimeNew(const char *pStr, time_t *pTime);

int DateStrToLocalTime(const char *pStr, time_t *pTime);

int GetTimeSec(const char *pStr, time_t *pTime);

int GetTimeSecEx(const char *pStr, time_t *pTime);