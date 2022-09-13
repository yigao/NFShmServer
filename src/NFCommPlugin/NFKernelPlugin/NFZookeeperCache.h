// -------------------------------------------------------------------------
//    @FileName         :    NFZookeeperCache.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFZookeeperCache.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFNamingHandle.h"
#include "NFZookeeperNaming.h"
#include <set>
#include <string>

class NFZookeeperCache
{
    struct CacheInfo {
        CacheInfo() : _is_watch(false) {}
        bool        _is_watch;
        std::string _name;
        NameInfo    _name_info;
    };
public:
    explicit NFZookeeperCache(NFZookeeperClient* zookeeper_client);
    ~NFZookeeperCache();

    int SetConfig(int32_t refresh_time_ms, int32_t invalid_time_ms);

    void Clear();

    void SetWatchFunc(const CbNodeChanged& change_cb) {
        m_value_change_cb = change_cb;
    }

    bool IsFullPath(const std::string& path) {
        return (m_cache_infos.end() != m_cache_infos.find(path));
    }

    int32_t Get(const std::string& name, std::vector<std::string>* urls);

    void OnDelete(const std::string& name);

    void OnGetCb(int rc, GetAllNameResults& results, const NFNamingCbReturnValue& cb); // NOLINT

    void OnUpdateCb(const std::string& req_name, bool is_watch,
                    int rc, GetAllNameResults& results, NFNamingCbReturnValue cb); // NOLINT

    void OnWatchCb(const std::string& req_name,
                   int rc, GetAllNameResults& results, NFNamingCbReturnCode cb); // NOLINT

    void Update();

private:
    void UpdateCache(GetAllNameResults& results, bool is_watch); // NOLINT

    NFZookeeperClient*        m_zk_client;
    CbNodeChanged           m_value_change_cb;

    int32_t                 m_refresh_time_ms; // cache刷新时间间隔，默认300s刷新一次
    int32_t                 m_invalid_time_ms; // cache数据失效时间间隔，默认700s失效

    int64_t                                 m_curr_time;
    int64_t                                 m_last_refresh;
    std::map<std::string, CacheInfo>        m_cache_infos;  // first : 展开后的路径
    std::map<std::string, bool>             m_cache_keys;   // first : 展开前的路径（请求路径）
};