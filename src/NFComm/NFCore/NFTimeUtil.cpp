// -------------------------------------------------------------------------
//    @FileName         :    NFTimeUtil.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTimeUtil.cpp
//
// -------------------------------------------------------------------------

#include "NFTimeUtil.h"
#include "NFMagicTimeUtil.h"
#include "NFTime.h"
#include "NFSnprintf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#if NF_PLATFORM == NF_PLATFORM_WIN

char *
strsep(char **stringp, const char *delim)
{
	char *begin, *end;

	begin = *stringp;
	if (begin == NULL)
		return NULL;

	/* delim分隔符是单个字符的情况是非常频繁的，因此不需要使用代价昂贵的 strpbrk 函数
	   而只需要调用 strchr 就能解决  */
	if (delim[0] == '\0' || delim[1] == '\0')
	{
		char ch = delim[0];

		if (ch == '\0')
			end = NULL;
		else
		{
			if (*begin == ch)
				end = begin;
			else if (*begin == '\0')
				end = NULL;
			else
				end = strchr(begin + 1, ch);
		}
	}
	else
		/* delim 有两个字符以上，才调用strpbrk  */
		end = strpbrk(begin, delim);

	if (end)
	{
		/* 用0封闭这个token；返回stringp，指向一个null指针 */
		*end++ = '\0';
		*stringp = end;
	}
	else
		/* 没有出现delim，这是最后一个token  */
		*stringp = NULL;

	return begin;
}
#endif

int GetAbsDayOffSet()
{
    time_t tTime = 0;
    tm *ptm = localtime( &tTime );
    return ptm->tm_hour * 60 * 60;
}

//monday is a new week. not sunday
int GetAbsWeekOffSet()
{
    time_t tTime = 0;
    tm *ptm = localtime( &tTime );
    return ( ptm->tm_wday - 1 ) * 60 * 60 * 24 + ptm->tm_hour * 60 * 60;  //这里减1 是因为: 周四就是值4, 如果按周一为每周的起点的话, 要减1.
}

static int s_iTimeAbsDayOffSet  = GetAbsDayOffSet();
static int s_iTimeAbsWeekOffSet = GetAbsWeekOffSet();



uint32_t GetAbsDay( time_t tNow )
{
    return ( tNow + s_iTimeAbsDayOffSet )/(60*60*24);
}

uint64_t GetTimeOfDayMS()
{
	return NFGetTime();
}

bool IsSameMonthWithOffsetHour( time_t tTimeA, time_t tTimeB, int iOffsetHour )
{
    return IsSameMonth( tTimeA - iOffsetHour * 3600,  tTimeB - iOffsetHour * 3600 );
}





bool IsSameMonth( time_t tTimeA, time_t tTimeB )
{

    struct tm tmTimeA;
    localtime_r( &tTimeA, &tmTimeA );

    struct tm tmTimeB;
    localtime_r( &tTimeB, &tmTimeB );

    if ( tmTimeA.tm_year == tmTimeB.tm_year && tmTimeA.tm_mon == tmTimeB.tm_mon )
    {
        return true;
    }

    return false;
}

uint32_t GetAbsWeek( time_t tTime ) //从1970-01-05日开始计算,当前时间为第几周
{
    int iBaseTime = (int)tTime;
    //基准时间0  是 1970-01-01 08:00:00 , 目前不考虑其他时区的情况
    //1970-01-05 才是周一, 所以还要减 4天
    iBaseTime = iBaseTime + s_iTimeAbsWeekOffSet;

    if ( iBaseTime <= 0 ) //出错了. 时间少于 1970-01-05, 溢出了. 全部返回0
    {
        return 0;
    }

    uint32_t dwWeekIndex = iBaseTime / ( 7 *60 *60 * 24);

    return dwWeekIndex;
}


uint32_t GetAbsTimeByWeekDayAndTime( time_t tNow, uint8_t bWeekDay, uint32_t dwWeekTime )
{
    uint32_t dwThisWeekStartTime = GetThisWeekStartTime( tNow );

    return dwThisWeekStartTime + bWeekDay * (60*60*24) + dwWeekTime;
}


uint32_t GetThisWeekStartTime( time_t tTime ) //从1970-01-05日开始计算,获取当前周开始时的绝对时间值.
{
    int iBaseTime = (int)tTime;
    iBaseTime = iBaseTime + s_iTimeAbsWeekOffSet;

    uint32_t dwWeekIndex = iBaseTime / ( 7 *60 *60 * 24);

    if ( dwWeekIndex <= 0 ) //出错了. 时间少于 1970-01-05, 溢出了. 全部返回0
    {
        return 0;
    }

    uint32_t dwAbsTime = dwWeekIndex * ( 7 *60 *60 * 24 ) - s_iTimeAbsWeekOffSet;

    return dwAbsTime;
}



char *DateTimeToStr_R(time_t *mytime, char *s, int *pio, bool bOnlyDay)
{

    int len = 0;
    struct tm curr;
    localtime_r(mytime, &curr);

    if(bOnlyDay)
    {
        len = snprintf(s, *pio, "%02d:%02d:%02d",
                       curr.tm_hour, curr.tm_min, curr.tm_sec);
    }
    else if (curr.tm_year > 50)
    {
        len = snprintf(s, *pio, "%04d-%02d-%02d %02d:%02d:%02d",
                       curr.tm_year+1900, curr.tm_mon+1, curr.tm_mday,
                       curr.tm_hour, curr.tm_min, curr.tm_sec);
    }
    else
    {
        len = snprintf(s, *pio, "%04d-%02d-%02d %02d:%02d:%02d",
                       curr.tm_year+2000, curr.tm_mon+1, curr.tm_mday,
                       curr.tm_hour, curr.tm_min, curr.tm_sec);
    }

    *pio = len;

    return s;
}

char *SecondToStr(time_t mytime)
{
    static char s[50];

    snprintf(s, sizeof(s), "%02d:%02d:%02d",
             (int)mytime / 3600, (int)(mytime % 3600) / 60, (int)(mytime % 3600) % 60);

    return s;
}

const char *DateTimeToStrSimCN_R( time_t *mytime, char *s, int *pio )
{
    int len = 0;
    struct tm curr;
    localtime_r(mytime, &curr);

    if (curr.tm_year > 50)
    {
        len = snprintf(s, *pio, "%04d年%02d月%02d日",
                       curr.tm_year+1900, curr.tm_mon+1, curr.tm_mday);
    }
    else
    {
        len = snprintf(s, *pio, "%04d年%02d月%02d日",
                       curr.tm_year+2000, curr.tm_mon+1, curr.tm_mday);
    }

    *pio = len;

    return s;
}


const char *DataTimeToStrSimCN( time_t tmytime )
{
    static char s[50];
    int len = 50;
    return DateTimeToStrSimCN_R( &tmytime, s, &len);
}

char *USecondTimeToStr(const TTimeVal &tvTime, char *pszOut, int iOutLen)
{
    static  char szTime[128];

    if (!pszOut)
    {
        pszOut = szTime;
        iOutLen = sizeof(szTime);
    }

    snprintf(pszOut, iOutLen, "%ld:%ld",tvTime.tv_sec,tvTime.tv_usec);

    return pszOut;
}

char *DateTimeToStr( time_t mytime, bool bOnlyDay)
{
    static char s[50];
    int len = 50;
    return DateTimeToStr_R( &mytime, s, &len, bOnlyDay);
}

char *DateTimeToStrDw( uint32_t dwMytime )
{
    time_t mytime = dwMytime;
    static char s[50];
    int len = 50;
    return DateTimeToStr_R( &mytime, s, &len);
}


char *DateTimeToStr( int imytime )
{
    time_t mytime = imytime;

    static char s[50];
    int len = 50;

    return DateTimeToStr_R(&mytime, s, &len);
}


char *DateTimeToStr( time_t *mytime )
{
    static char s[50];
    int len = 50;

    return DateTimeToStr_R(mytime, s, &len);
}

char *DateTimeToStr(time_t *mytime, char *piIn)
{
    int len = 50;

    return DateTimeToStr_R(mytime, piIn, &len);
}

char *CurTimeToStr(time_t tNow)
{
    return DateTimeToStr(&tNow);
}

char *CurTimeToStr_R(time_t tNow, char *pszDateTime, int *piInOutLen)
{
    assert(pszDateTime && piInOutLen);

    return DateTimeToStr_R(&tNow, pszDateTime, piInOutLen);

}

time_t StrToTimePure( const char *psztime )
{
    time_t tTime = 0;

    int iRetCode = StrToTime( psztime, &tTime );

    if ( iRetCode < 0 )
    {
        return 0;
    }

    return tTime;
}


int StrToTime(const char *psztime, time_t *ptime)
{
    if (!psztime || !ptime)
    {
        return -1;
    }

    struct tm lmt;

    int n;

    n = sscanf(psztime, "%04d-%02d-%02d %02d:%02d:%02d",
               &lmt.tm_year, &lmt.tm_mon, &lmt.tm_mday,
               &lmt.tm_hour, &lmt.tm_min, &lmt.tm_sec);

    if (6 != n)
    {
        return -1;
    }

    if(lmt.tm_mon < 1 || lmt.tm_mon > 12)
        return -1;
    if(lmt.tm_mday < 1 || lmt.tm_mday > 31)
        return -1;
    if(lmt.tm_hour < 0 || lmt.tm_hour > 23)
        return -1;
    if(lmt.tm_min < 0 || lmt.tm_min > 59)
        return -1;
    if(lmt.tm_sec < 0 || lmt.tm_sec > 59)
        return -1;

    lmt.tm_year -= 1900;
    lmt.tm_mon -= 1;
    lmt.tm_isdst = 0;
    *ptime = mktime(&lmt);

    return 0;
}

int SysTime(char *pszBuff, int iBuff)
{
#ifdef WIN32
    SYSTEMTIME stSys;

    if ( !pszBuff || iBuff<=0 )
    {
        return -1;
    }

    GetLocalTime(&stSys);

    snprintf(pszBuff, iBuff, "%04d-%02d-%02d %02d:%02d:%02d.%.6d",
             stSys.wYear, stSys.wMonth, stSys.wDay, stSys.wHour,
             stSys.wMinute, stSys.wSecond, stSys.wMilliseconds*1000);

    return 0;
#else
    struct timeval stTv;
    struct tm stTm;

    if ( !pszBuff || iBuff<=0 )
    {
        return -1;
    }

    gettimeofday(&stTv, NULL);
    localtime_r(&stTv.tv_sec, &stTm);

    snprintf(pszBuff, iBuff, "%04d-%02d-%02d %02d:%02d:%02d.%.6d",
             stTm.tm_year+1900, stTm.tm_mon+1, stTm.tm_mday,
             stTm.tm_hour, stTm.tm_min, stTm.tm_sec, (int)stTv.tv_usec);

    return 0;

#endif /* WIN32 */
}



//xxxx 20160325 ,时间线统一后，这个gettimeofday是否保留还存在一些问题，先暂时这么做吧
uint64_t GetCurrTimeUs()
{
	return NFGetMicroSecondTime();
}

/* Time string format :yyyy-mm-dd hh:mm:ss */
long MakeTime(char *szTime )
{
    char sTemp[20] , s1[5] ;
    struct tm tmTime;
    time_t lTime ;

    if ( strlen( szTime ) != 19 )
    {
        return 0 ;
    }

    snprintf( sTemp , sizeof(sTemp), "%s", szTime ) ;

    snprintf(s1, sizeof(s1), "%s",&sTemp[17]) ;
    sTemp[16]=0 ;
    tmTime.tm_sec = atoi(s1);

    snprintf(s1, sizeof(s1), "%s",&sTemp[14]) ;
    sTemp[13]=0 ;
    tmTime.tm_min = atoi(s1) ;

    snprintf(s1, sizeof(s1), "%s",&sTemp[11]);
    sTemp[10]=0;
    tmTime.tm_hour=atoi(s1) ;

    snprintf(s1, sizeof(s1), "%s",&sTemp[8]);
    sTemp[7]=0;
    tmTime.tm_mday=atoi(s1) ;

    snprintf(s1, sizeof(s1), "%s",&sTemp[5]);
    sTemp[4]=0;
    tmTime.tm_mon=atoi(s1) -1 ;

    tmTime.tm_year=atoi(sTemp)-1900;

    tmTime.tm_isdst=0; //标准时间，非夏令时
    lTime =mktime(&tmTime);

    return lTime ;
}

char *TimeToStr(const TTimeVal *pstCurr, char *pszString, int iMaxLen)
{
    static char szBuff[64];

    if (NULL == pszString)
    {
        pszString = szBuff;
        iMaxLen = sizeof(szBuff);
    }

    struct tm *pszTime = localtime((time_t*)&pstCurr->tv_sec);

    size_t iLen = ::strftime(pszString, iMaxLen, "%Y-%m-%d %H:%M:%S", pszTime);

    NFSafeSnprintf(pszString+iLen, iMaxLen-iLen, ".%06d", (int)pstCurr->tv_usec);

    return pszString;
}

char *CurrTimeStr(const TTimeVal *pstCurr)
{
    static char szBuff[64];

    struct tm *pszTime = localtime((time_t*)&pstCurr->tv_sec);
    ::strftime(szBuff, sizeof(szBuff), "%Y-%m-%d %H:%M:%S", pszTime);

    size_t iLen = ::strlen(szBuff);
    NFSafeSnprintf(szBuff+iLen, sizeof(szBuff)-iLen, ".%06d", (int)pstCurr->tv_usec);

    return szBuff;
}

unsigned short MakeShortTime(time_t tTime)
{
    tm *ptmCur = localtime(&tTime);
    return (((unsigned short)(1900+ptmCur->tm_year-2000))<<9)|(((unsigned short)(ptmCur->tm_mon+1))<<5)|((unsigned short)ptmCur->tm_mday);
}

bool IsSameDayByGameResetTime(time_t tCur, time_t tBefore)
{
    return NFMagicTimeUtil::IsSameDay(tCur,tBefore);
}


/*

uint32_t GetAbsWeek( time_t tTime ) //从1970-01-05日开始计算,当前时间为第几周
{
    int iBaseTime = (int)tTime;
    //基准时间0  是 1970-01-01 08:00:00 , 目前不考虑其他时区的情况
    //1970-01-05 才是周一, 所以还要减 4天
    iBaseTime = iBaseTime - 8*60*60 - 4*60*60*24;

    if( iBaseTime <= 0 ) //出错了. 时间少于 1970-01-05, 溢出了. 全部返回0
    {
        return 0;
    }

    uint32_t dwWeekIndex = iBaseTime / ( 7 *60 *60 * 24);

    return dwWeekIndex;
}
*/

uint16_t GetTimeYear( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_year + 1970;
}

uint16_t GetWeekDay( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_wday;
}

uint16_t GetWeekDay( )
{
    time_t tTime = time(NULL);
    tm *ptm = localtime(&tTime);
    return ptm->tm_wday;
}


uint16_t GetMonthDay( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_mday;
}

uint16_t GetHour( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_hour;
}

uint32_t GetDayAbsSec( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_hour * 3600 + ptm->tm_min * 60 + ptm->tm_sec;
}


uint16_t GetMonthDay( )
{
    time_t tTime = time(NULL);
    tm *ptm = localtime(&tTime);
    return ptm->tm_mday;
}

uint16_t GetMonth( time_t tTime )
{
    tm *ptm = localtime(&tTime);
    return ptm->tm_mon;
}

time_t __DATE__TIME_toTime(const char *sz__DATE__,const char *sz__TIME__)
{
    char s_month[5];
    int month, day, year;
    int hour, min, sec;
    struct tm _Tm;
    memset(&_Tm,0,sizeof(_Tm));
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

    sscanf(sz__DATE__, "%s %d %d", s_month, &day, &year);

    month = (strstr(month_names, s_month)-month_names)/3;

    sscanf(sz__TIME__, "%d:%d:%d", &hour, &min, &sec);

    _Tm.tm_mon = month-1;
    _Tm.tm_mday = day;
    _Tm.tm_year = year - 1900;
    _Tm.tm_isdst = -1;
    _Tm.tm_hour = hour;
    _Tm.tm_min = min;
    _Tm.tm_sec = sec;

    return mktime(&_Tm);
}

time_t time_str_to_utc(char *szInput)
{
    if (!szInput)
    {
        return 0;
    }

    char *szNumber = NULL;
    struct tm tmTime;

    // ---年---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_year = atoi(szNumber) - 1900;

    // ---月---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_mon = atoi(szNumber) - 1;

    // ---日---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_mday = atoi(szNumber);

    // ---时---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_hour = atoi(szNumber);

    // ---分---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_min = atoi(szNumber);

    // ---秒---
    if (!(szNumber = strsep(&szInput, "-")))
    {
        return 0;
    }

    tmTime.tm_sec = atoi(szNumber);

    return mktime(&tmTime);
}

time_t GetTodayStartTime( time_t tTimeNow, int iHour )
{
    int iHourSecond = iHour * 3600;
    //UTC转成本地时间
    time_t tNowLocal = tTimeNow + LOCAL_TIME_CORRECTION - iHourSecond;
    time_t tNowDays =  tNowLocal / SECONDS_ADAY;
    time_t tNowDayStart = tNowDays * SECONDS_ADAY;
    tNowDayStart = tNowDayStart - LOCAL_TIME_CORRECTION + iHourSecond;
    return tNowDayStart;
}

int DataStrToLocalTimeNew(const char* pStr, time_t* pTime)
{
    if(!pStr || !pTime)
    {
        return -1;
    }

    struct tm lmt;
    memset(&lmt, 0, sizeof(lmt));

    int n = sscanf(pStr, "%04d-%02d-%02d %02d:%02d:%02d",
                   &lmt.tm_year, &lmt.tm_mon, &lmt.tm_mday,
                   &lmt.tm_hour, &lmt.tm_min, &lmt.tm_sec);

    if(n < 3 || n > 6)
    {
        return -1;
    }

    lmt.tm_year -= 1900;
    lmt.tm_mon -= 1;
    lmt.tm_isdst = 0;
    *pTime = mktime(&lmt);

    return 0;
}

int DateStrToLocalTime(const char* pStr, time_t* pTime)
{
    if (!pStr || !pTime)
        return -1;

    struct tm lmt;

    int n = sscanf(pStr, "%04d-%02d-%02d %02d:%02d:%02d",
                   &lmt.tm_year, &lmt.tm_mon, &lmt.tm_mday,
                   &lmt.tm_hour, &lmt.tm_min, &lmt.tm_sec);

    if (3 != n && 6 != n)
    {
        return -1;
    }

    if ( n == 3 ) {
        lmt.tm_hour = 0;
        lmt.tm_min = 0;
        lmt.tm_sec = 0;
    }

    lmt.tm_year -= 1900;
    lmt.tm_mon -= 1;
    lmt.tm_isdst = 0;
    *pTime = mktime(&lmt);

    return 0;
}

int GetTimeSecEx(const char* pStr, time_t* pTime)
{
    if(!pStr || !pTime)
    {
        return -1;
    }

    int iHour = 0;
    int iMin = 0;

    int n = sscanf(pStr, "%02d:%02d",
                   &iHour, &iMin);

    if(n < 1 || iHour < 0 || iHour > 23 || iMin < 0 || iMin > 59)
    {
        return -1;
    }

    *pTime = 3600 * iHour + 60 * iMin;

    return 0;
}

int GetTimeSec(const char* pStr, time_t* pTime)
{
    if(!pStr || !pTime)
    {
        return -1;
    }

    int iHour = 0;
    int iMin = 0;
    int iSec = 0;

    int n = sscanf(pStr, "%02d:%02d:%02d",
                   &iHour, &iMin, &iSec);

    if(n < 1)
    {
        return -1;
    }

    *pTime = 3600 * iHour + 60 * iMin + iSec;

    return 0;
}


