//
// Created by gaoyi on 2022/9/21.
//

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSingleton.hpp"

#define MAX_ZONE_COUNT 16383//1024*8 14bit表示 最大为2的14次方减1,这里不要随便修改

//原来：64位  zid bit[64-50] bit[50] =0  cid bit[1-49]
//由于客户端LUA 中 int64_t 类型最大只能表示 2的53次方，所以角色cid由原来的64位改成现在的51位表示(14位区服ID+37位序号)
//现在：51位  zid bit(38-51) cid bit[1-37]
#define CHAR_DB_UID(zid,idx) (( ((uint64_t)zid) << 37) | idx)
//通过玩家DB唯一ID获取区服ID
#define CHAR_DB_ZID(cid) (cid >> 37)
//通过玩家DB唯一ID获取DB索引
#define CHAR_DB_IDX(cid) (cid & 0x1FFFFFFFFF)


#define MAX_CHARACTER_COUNT 137438953471 //一个服角色CID最大索引值 2的37次方，这里不要随便修改
#define MAX_ZONE_CONNECT_TIME_SEC   60000  //客户端连接zone的最大时间间隔(1分钟,这里单位ms)
#define MAX_CENTER_LOGIN_TIME_SEC 60000  //客户端登陆center的最大时间间隔(1分钟,单位ms)

class NFLogicCommon {
public:
    NFLogicCommon();
    virtual ~NFLogicCommon();
public:
    /**
     * @brief 使用uid 以及 timeStamp 合同一个md5 的 token
     * @param uid
     * @param timeStamp
     * @return
     */
    static std::string MakeToken(uint32_t uid, uint64_t timeStamp);
};


