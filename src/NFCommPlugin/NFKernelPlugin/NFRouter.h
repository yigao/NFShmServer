// -------------------------------------------------------------------------
//    @FileName         :    NFRouter.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRouter.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFNaming.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

typedef enum {
    NF_USER_ROUTE,        ///< 用户自定义路由类型
    NF_QUALITY_ROUTE,     ///< 根据访问质量的路由类型
    NF_ROUND_ROUTE,       ///< 轮询路由类型
    NF_MOD_ROUTE,         ///< 取模路由类型
    NF_HASH_ROUTE = NF_MOD_ROUTE,   ///< 哈希路由类型，由外部传入hash_key，因此等价于NF_MOD_ROUTE
}RoutePolicyType;

class NFIRoutePolicy
{
public:
    virtual ~NFIRoutePolicy() {}
    virtual int64_t GetRoute(uint64_t key, const std::vector<int64_t>& handles) = 0;
};

class NFRoundRoutePolicy      : public NFIRoutePolicy
{
public:
    NFRoundRoutePolicy() : m_round(0) {}
    int64_t GetRoute(uint64_t key, const std::vector<int64_t>& handles)
    {
        if (0 == handles.size()) {
            return proto_ff::ERR_CODE_ROUTER_NONE_VALID_HANDLE;
        }
        return handles[(m_round++) % handles.size()];
    }
private:
    uint32_t    m_round;
};

class NFModRoutePolicy        : public NFIRoutePolicy
{
public:
    int64_t GetRoute(uint64_t key, const std::vector<int64_t>& handles)
    {
        if (0 == handles.size()) {
            return proto_ff::ERR_CODE_ROUTER_NONE_VALID_HANDLE;
        }
        return handles[key % handles.size()];
    }
};

/// @brief 目标地址列表变化回调函数
/// @param handles 变化后的全量handle列表
typedef std::function<void(const std::vector<int64_t>& handles)> OnAddressChanged;

class NFRouter
{
public:
    /// @brief 根据名字来生成路由
    /// @param name_path 名字的绝对路径，同@see Naming中的name_path
    explicit NFRouter(const std::string& name_path);

    virtual ~NFRouter();

    /// @brief 初始化
    /// @param naming 提供的Naming
    /// @return 0 成功，其它失败@see RouterErrorCode
    /// @note 具体的地址列表由Router从naming中获取，地址的变化也在Router中内部处理
    virtual int32_t Init(NFNaming* naming);

    /// @brief 设置路由策略
    /// @param route_policy 用户路由策略类型
    /// @param policy 用户自定义路由策略，仅当route_policy为kUSER_ROUTE时有效
    /// @return 0 成功，其它失败@see RouterErrorCode
    virtual int32_t SetRoutePolicy(RoutePolicyType policy_type, NFIRoutePolicy* policy);

    /// @brief 根据key获取路由
    /// @param key 传入的key
    /// @return 非负数 - 成功，其它失败@see RouterErrorCode
    virtual int64_t GetRoute(uint64_t key = 0);

    /// @brief 设置router监测到地址列表发生变化时的回调函数
    /// @param on_address_changed 当地址列表发生变化时，调用此函数
    virtual void SetOnAddressChanged(const OnAddressChanged& on_address_changed);

protected:
    void NameWatch(const std::string& name, const std::vector<std::string>& urls);

    std::string             m_route_name;
    RoutePolicyType         m_route_type;
    NFIRoutePolicy*           m_route_policy;
    NFNaming*                 m_naming;
    std::vector<int64_t>    m_route_handles;
    OnAddressChanged        m_on_address_changed;
};

class RouterFactory {
public:
    RouterFactory() {}
    virtual ~RouterFactory() {}
    virtual NFRouter* GetRouter(const std::string& name_path) {
        return new NFRouter(name_path);
    }
};

/// @brief 设置指定类型的路由器工厂
/// @param type 路由器的类型
/// @param factory 路由器的工厂实例
/// @return 0成功，非0失败
int32_t SetRouterFactory(int32_t type, const std::shared_ptr<RouterFactory>& factory);

/// @brief 获取指定类型的路由器工厂
/// @param type 路由器的类型
/// @return 路由器的工厂实例，为NULL时说明未set这种类型的工厂
std::shared_ptr<RouterFactory> GetRouterFactory(int32_t type);