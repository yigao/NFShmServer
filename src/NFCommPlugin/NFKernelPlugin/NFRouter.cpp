// -------------------------------------------------------------------------
//    @FileName         :    NFRouter.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRouter.cpp
//
// -------------------------------------------------------------------------

#include "NFRouter.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"


NFRouter::NFRouter(const std::string& name_path)
        :   m_route_name(name_path), m_route_type(NF_ROUND_ROUTE),
            m_route_policy(NULL), m_naming(NULL)
{
    NFNaming::FormatNameStr(&m_route_name);
}

NFRouter::~NFRouter()
{
    if (NF_USER_ROUTE != m_route_type && NULL != m_route_policy) {
        delete m_route_policy;
        m_route_policy = NULL;
    }
    if (NULL != m_naming) {
        m_naming->UnWatchName(m_route_name);
        m_naming = NULL;
    }
}

int32_t NFRouter::Init(NFNaming* naming)
{
    if (NULL == naming) {
        return proto_ff::ERR_CODE_ROUTER_INVAILD_PARAM;
    }
    if (NULL != m_naming) {
        m_naming->UnWatchName(m_route_name);
    }
    m_naming = naming;
    NFNamingWatchFunc cob = std::bind(&NFRouter::NameWatch, this, std::placeholders::_1, std::placeholders::_2);
    int32_t ret = m_naming->WatchName(m_route_name, cob);
    if (0 != ret) {
        return proto_ff::ERR_CODE_ROUTER_INVAILD_PARAM;
    }
    return SetRoutePolicy(m_route_type, m_route_policy);
}

int32_t NFRouter::SetRoutePolicy(RoutePolicyType policy_type, NFIRoutePolicy* policy)
{
    switch (policy_type) {
        case NF_USER_ROUTE:
            if (policy == NULL) {
                return proto_ff::ERR_CODE_ROUTER_INVAILD_PARAM;
            }
            break;
        case NF_QUALITY_ROUTE:
            return proto_ff::ERR_CODE_ROUTER_NOT_SUPPORTTED;
        case NF_ROUND_ROUTE:
            policy = new NFRoundRoutePolicy;
            break;
        case NF_MOD_ROUTE:
            policy = new NFModRoutePolicy;
            break;
        default:
            return proto_ff::ERR_CODE_ROUTER_INVAILD_PARAM;
    }
    if (NF_USER_ROUTE != m_route_type && NULL != m_route_policy) {
        delete m_route_policy;
    }
    m_route_type = policy_type;
    m_route_policy = policy;
    return 0;
}

int64_t NFRouter::GetRoute(uint64_t key)
{
    if (NULL != m_route_policy) {
        return m_route_policy->GetRoute(key, m_route_handles);
    }
    return proto_ff::ERR_CODE_ROUTER_NOT_SUPPORTTED;
}

void NFRouter::NameWatch(const std::string& name, const std::vector<std::string>& urls)
{
    // TODO: 后续优化，目前实现有点粗暴
    for (uint32_t idx = 0 ; idx < m_route_handles.size() ; ++idx) {
        //Message::Close(m_route_handles[idx]);
    }
    m_route_handles.clear();

    for (uint32_t idx = 0 ; idx < urls.size() ; ++idx) {
        int64_t handle = -1; //Message::Connect(urls[idx]);
        if (handle < 0) {
            continue;
        }
        m_route_handles.push_back(handle);
    }

    if (m_on_address_changed) {
        m_on_address_changed(m_route_handles);
    }
}

void NFRouter::SetOnAddressChanged(const OnAddressChanged& on_address_changed)
{
    m_on_address_changed = on_address_changed;
    // 设置之后立即通知一次，避免router已经拿到handle列表后，后续不再变化，就无法通知了
    if (m_on_address_changed && !m_route_handles.empty()) {
        m_on_address_changed(m_route_handles);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 避免全局变量构造、析构顺序问题
static std::unordered_map<int32_t, std::shared_ptr<RouterFactory> > * g_router_factory_map = NULL;
struct RouterFactoryMapHolder {
    RouterFactoryMapHolder() {
        g_router_factory_map = &_router_factory_map;
    }
    ~RouterFactoryMapHolder() {
        g_router_factory_map = NULL;
    }
    std::unordered_map<int32_t, std::shared_ptr<RouterFactory> > _router_factory_map;
};

std::shared_ptr<RouterFactory> GetRouterFactory(int32_t type) {
    std::shared_ptr<RouterFactory> null_factory;
    if (!g_router_factory_map) {
        return null_factory;
    }

    std::unordered_map<int32_t, std::shared_ptr<RouterFactory> >::iterator it =
                                                                                   g_router_factory_map->find(type);
    if (it != g_router_factory_map->end()) {
        return it->second;
    }

    return null_factory;
}

int32_t SetRouterFactory(int32_t type, const std::shared_ptr<RouterFactory>& factory) {
    static RouterFactoryMapHolder fouter_factory_map_holder;
    if (!factory) {
        return proto_ff::ERR_CODE_ROUTER_INVAILD_PARAM;
    }
    if (g_router_factory_map == NULL) {
        return proto_ff::ERR_CODE_ROUTER_FACTORY_MAP_NULL;
    }
    if (false == g_router_factory_map->insert({type, factory}).second) {
        return proto_ff::ERR_CODE_ROUTER_FACTORY_EXISTED;
    }
    return 0;
}
