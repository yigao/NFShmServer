// -------------------------------------------------------------------------
//    @FileName         :    NFRoute.h
//    @Author           :    gaoyi
//    @Date             :    23-12-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoute
//
// -------------------------------------------------------------------------

#pragma once

/**
 * @brief 路由分类
 * 1.本服路由  LOCAL_ROUTE              本服路由机制，除非明确表示要发往跨服服务器，否则就是本服路由(包过跨服服务器的本服路由) (需要保证本跨服服务器只能连接跨服route agent， 不跨服服务器只能连接不跨服的route agent.)
 * 2.区服路由  区服的zid(1-4096)         只有跨服route server服务器，才有区服路由的能力
 * 3.跨服路由 CROSS_ROUTE               明确指定要找跨服服务器， 才走跨服路由
 * 4.busid路由 服务器唯一ID
 */

/**
 * @brief
 */
#define LOCAL_ROUTE 0

/**
 * @brief 跨服路由 (最大分区4096， 所以10000不会是区服路由)
 */
#define CROSS_ROUTE 10000