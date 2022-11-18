// -------------------------------------------------------------------------
//    @FileName         :    NFShmEventKey
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmEventKey
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include <NFComm/NFCore/NFHash.hpp>
#include "NFComm/NFShmCore/NFShmMgr.h"


#pragma pack(push)
#pragma pack(1)

class NFShmEventKey
{
public:
    NFShmEventKey()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        nSrcID = 0;
        nEventID = 0;
        bySrcType = 0;
        nServerType = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    /**
    *@brief 事件主要的key，主要指玩家，生物唯一id
    */
    uint64_t nSrcID;

    /**
    *@brief 事件Id
    */
    uint32_t nEventID;

    /**
    *@brief src类型, 用来区别玩家，怪物的类型
    */
    uint32_t bySrcType;

    /**
     * @brief 服务器类型，用来区分AllServer模式下，不同服务器的事件
     */
    uint32_t nServerType;

    /**
    *@brief 判断是否相等
    */
    bool operator==(const NFShmEventKey &eventKey) const
    {
        return ((nServerType == eventKey.nServerType) &&
                (nEventID == eventKey.nEventID) &&
                (bySrcType == eventKey.bySrcType) &&
                (nSrcID == eventKey.nSrcID));
    }

    /**
    *@brief 判断是否小于, 不知道有没有更好的判断小于的方法
    */
    bool operator<(const NFShmEventKey &eventKey) const
    {
        if (nServerType < eventKey.nServerType)
        {
            return true;
        }
        else if (nServerType > eventKey.nServerType)
        {
            return false;
        }
        else
        {
            if (nEventID < eventKey.nEventID)
            {
                return true;
            }
            else if (nEventID > eventKey.nEventID)
            {
                return false;
            }
            else
            {
                if (bySrcType < eventKey.bySrcType)
                {
                    return true;
                }
                else if (bySrcType > eventKey.bySrcType)
                {
                    return false;
                }
                else
                {
                    if (nSrcID < eventKey.nSrcID)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    std::string ToString() const
    {
        return NF_FORMAT("nServerType:{} nEventID:{}, nSrcID:{}, bySrcType:{}", nServerType, nEventID, nSrcID, bySrcType);
    }
};

#pragma pack(pop)

/**
*@brief 求hash值
*/
namespace std
{
    template<>
    struct hash<NFShmEventKey>
    {
        size_t operator()(const NFShmEventKey &eventKey) const
        {
            return NFHash::hash_combine(eventKey.nServerType, eventKey.nEventID, eventKey.bySrcType, eventKey.nSrcID);
        }
    };
}