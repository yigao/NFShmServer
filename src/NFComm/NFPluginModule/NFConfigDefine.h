// -------------------------------------------------------------------------
//    @FileName         :    NFConfigDefine.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include <unordered_map>
#include "NFComm/NFKernelMessage/proto_common_s.h"

#define DEFINE_LUA_STRING_LOAD_PLUGIN            "LoadPlugin"
#define DEFINE_LUA_STRING_FRAME_PLUGINS         "FramePlugins"
#define DEFINE_LUA_STRING_SERVER_PLUGINS        "ServerPlugins"
#define DEFINE_LUA_STRING_WORK_PLUGINS          "WorkPlugins"

#define DEFINE_LUA_STRING_LOG_LEVEL                "LogLevel"                    //log等级配置
#define DEFINE_LUA_STRING_LOG_FLUSH_LEVEL        "LogFlushLevel"                //log刷新等级配置

#define DEFINE_LUA_STRING_LOG_INFO                "LogInfo"            //log配置

enum EnumLogInfoLuaString
{
    LOG_INFO_LOG_ID = 0,
    LOG_INFO_DISPLAY = 1,
    LOG_INFO_LEVEL = 2,
    LOG_INFO_LOG_NAME = 3,
    LOG_INFO_LOG_GUID = 4,
};

typedef proto_ff_s::pbPluginConfig_s NFPluginConfig;

struct NFLogConfig
{
    NFLogConfig()
    {
        Clear();
    }
    
    void Clear()
    {
        mLogLevel = 0;
        mLogFlushLevel = 0;
        mLineConfigList.clear();
    }
    
    uint32_t mLogLevel;
    uint32_t mLogFlushLevel;
    std::vector<LogInfoConfig> mLineConfigList;
};

struct NFServerConfig : public proto_ff_s::pbNFServerConfig_s
{
public:
    NFServerConfig()
    {
        m_openZeroTime = 0;
        m_dayFromOpen = 1;
    }
    
    virtual void read_from_pbmsg(const ::proto_ff::pbNFServerConfig &msg) override
    {
        proto_ff_s::pbNFServerConfig_s::read_from_pbmsg(msg);
        for (int i = 0; i < (int) MysqlConfig.TBConfList.size(); i++)
        {
            struct proto_ff_s::pbTableConfig_s &tableConfig = MysqlConfig.TBConfList[i];
            mTBConfMap.emplace(tableConfig.TableName, tableConfig);
        }
        
        m_openZeroTime = NFTime::GetZeroTime(ServerOpenTime);
        CalcDayCountFromOpen(NFTime::Now().UnixSec());
    }
    
    void CalcDayCountFromOpen(uint64_t curTime)
    {
        //计算开服那一天还剩余的时间
        NFDate curDate = NFTime::GetLocalDate(ServerOpenTime);
        uint64_t openDaySec = curDate.hour * 3600 + curDate.min * 60 + curDate.sec;
        uint64_t dayLefSec = (24 * 3600) - openDaySec;
        
        m_dayFromOpen = 1;
        if (curTime >= (ServerOpenTime + dayLefSec))
        {
            uint64_t interSec = curTime - (ServerOpenTime + dayLefSec);
            uint32_t dayCount = 0;
            uint64_t daySec = 24 * 3600;
            dayCount = interSec / daySec;
            if (0 != (interSec % daySec))
            {
                dayCount += 1;
            }
            m_dayFromOpen += dayCount;
        }
    }
    
    //获取开服时间
    uint64_t GetOpenTime(uint32_t zid)
    {
        if (IsCrossServer())
        {
            auto iter = m_mapZidOpenTime.find(zid);
            return (iter != m_mapZidOpenTime.end()) ? iter->second : 0;
        }
        else {
            return GetOpenTime();
        }
    }
    
    //获取开服当天零点时间
    uint64_t GetOpenDayZeroTime(uint32_t zid)
    {
        if (IsCrossServer())
        {
            auto iter = m_mapZidOpenDayZeroTime.find(zid);
            return (iter != m_mapZidOpenDayZeroTime.end()) ? iter->second : 0;
        }
        else {
            return GetOpenDayZeroTime();
        }
    }
    
    //获取区服开服天数
    uint32_t GetDayFromOpen(uint32_t zid)
    {
        if (IsCrossServer())
        {
            auto iter = m_mapZidDayFromOpen.find(zid);
            return (iter != m_mapZidDayFromOpen.end()) ? iter->second : 0;
        }
        else {
            return GetDayFromOpen();
        }
    }
    
    //区服是否合服了
    bool IsMerged(uint32_t zid)
    {
        auto iter = m_mapZidMerge.find(zid);
        return (iter != m_mapZidMerge.end()) ? iter->second : false;
    }
    
    //是否返回了区服合服标记
    bool IsRetMerge(uint32_t zid, bool &ismerge)
    {
        auto iter = m_mapZidMerge.find(zid);
        if (iter != m_mapZidMerge.end())
        {
            ismerge = iter->second;
            return true;
        }
        return false;
    }
    
    //获取初始开服时间
    uint64_t GetInitOpenTime(uint32_t zid)
    {
        auto iter = m_mapZidInitOpenTime.find(zid);
        return (iter != m_mapZidInitOpenTime.end()) ? iter->second : 0;
    }
    
    //获取初始开服当天零点时间
    uint64_t GetInitOpenDayZeroTime(uint32_t zid)
    {
        auto iter = m_mapZidInitOpenDayZeroTime.find(zid);
        return (iter != m_mapZidInitOpenDayZeroTime.end()) ? iter->second : 0;
    }
    
    //获取区服初始开服天数
    uint32_t GetInitDayFromOpen(uint32_t zid)
    {
        auto iter = m_mapZidInitDayFromOpen.find(zid);
        return (iter != m_mapZidInitDayFromOpen.end()) ? iter->second : 0;
    }
    
    void DailyZeroUpdate(uint64_t unixSec)
    {
        string strlog;
        for (auto &iter : m_mapZidOpenTime)
        {
            uint64_t opentime = GetOpenTime(iter.first);
            uint32_t days = CalcDayFromOpen(iter.first, unixSec, opentime);
            m_mapZidDayFromOpen[iter.first] = days;
            //
            strlog += ",";
            strlog += std::to_string(iter.first);
            strlog += ":";
            strlog += std::to_string(days);
        }
        string strinitlog;
        for (auto &iter : m_mapZidInitOpenTime)
        {
            uint64_t opentime = GetInitOpenTime(iter.first);
            uint32_t days = CalcDayFromOpen(iter.first, unixSec, opentime);
            m_mapZidInitDayFromOpen[iter.first] = days;
            //
            strinitlog += ",";
            strinitlog += std::to_string(iter.first);
            strinitlog += ":";
            strinitlog += std::to_string(days);
        }
    }
    
    uint32_t CalcDayFromOpen(uint32_t zid, uint64_t curTime, uint64_t opentime)
    {
        //计算开服那一天还剩余的时间
        NFDate curDate = NFTime::GetLocalDate(opentime);
        uint64_t openDaySec = curDate.hour * 3600 + curDate.min * 60 + curDate.sec;
        uint64_t dayLefSec = (24 * 3600) - openDaySec;
        //
        uint32_t days = 1;
        if (curTime >= (opentime + dayLefSec))
        {
            uint64_t interSec = curTime - (opentime + dayLefSec);
            uint32_t dayCount = 0;
            uint64_t daySec = 24 * 3600;
            dayCount = interSec / daySec;
            if (0 != (interSec % daySec))
            {
                dayCount += 1;
            }
            days += dayCount;
        }
        //
        return days;
    }
    
    //获取开服时间
    uint64_t GetOpenTime() const { return ServerOpenTime; }
    uint64_t GetServerOpenTime() const { return ServerOpenTime; }
    
    //获取开服当天零点时间
    uint64_t GetOpenDayZeroTime() { return m_openZeroTime; }
    
    //获取区服开服天数
    uint32_t GetDayFromOpen() { return m_dayFromOpen; }
    
    std::string GetServerId() const { return ServerId; }
    
    std::string GetServerName() const { return ServerName; }
    
    uint32_t GetBusId() const { return BusId; }
    
    uint32_t GetZoneId() const { return NFServerIDUtil::GetZoneID(BusId); }
    
    uint32_t GetWorldId() const { return NFServerIDUtil::GetWorldID(BusId); }
    
    std::string GetDefaultDBName() const { return DefaultDBName; }
    
    std::string GetCrossDBName() const { return CrossDBName; }
    
    uint32_t GetMaxOnlinePlayerNum() const { return MaxOnlinePlayerNum; }
    
    uint32_t GetHeartBeatTimeout() const { return HeartBeatTimeout; }
    
    uint32_t GetClientKeepAliveTimeout() const { return ClientKeepAliveTimeout; }
    
    bool IsCrossServer() const { return CrossServer; }
    
    std::unordered_map<std::string, proto_ff_s::pbTableConfig_s> mTBConfMap;
    uint64_t m_openZeroTime;            //开服那天的0点时间
    uint32_t m_dayFromOpen;            //当前是开服的第几天
    std::unordered_map<uint32_t, uint64_t> m_mapZidOpenTime;        //区服开服时间(跨服逻辑服中需要存储各个区服的开服时间)
    std::unordered_map<uint32_t, uint32_t> m_mapZidDayFromOpen;    //区服当前是开服的第几天(跨服逻辑服中需要存储各个区服的开服时间)
    std::unordered_map<uint32_t, uint64_t> m_mapZidOpenDayZeroTime;//区服开服时间那一天零点的unix时间((跨服逻辑服中需要存储各个区服的时间))
    std::unordered_map<uint32_t, uint32_t> m_mapZidMerge;            //区服是否合服 zid-合服标记
    std::unordered_map<uint32_t, uint64_t> m_mapZidInitOpenTime;        //区服初始的开服时间(跨服逻辑服中需要存储各个区服的开服时间)
    std::unordered_map<uint32_t, uint32_t> m_mapZidInitDayFromOpen;    //区服初始的开服时间 当前是第几天(跨服逻辑服中需要存储各个区服的初始开服时间)
    std::unordered_map<uint32_t, uint64_t> m_mapZidInitOpenDayZeroTime;//区服初始开服时间那一天零点的unix时间((跨服逻辑服中需要存储各个区服的初始开服时间))
};
