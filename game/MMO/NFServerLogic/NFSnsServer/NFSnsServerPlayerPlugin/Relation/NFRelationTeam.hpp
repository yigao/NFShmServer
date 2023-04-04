// -------------------------------------------------------------------------
//    @FileName         :    NFRelationTeam.h
//    @Author           :    gaoyi
//    @Date             :    23-4-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFRelationTeam
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFRelationPlayer.h"
#include "NFComm/NFShmStl/NFShmHashTableWithList.h"

template<typename RelationPlayer, size_t max_size>
class NFRelationTeam
{
    static_assert((TIsDerived<RelationPlayer, NFRelationCommonPlayer>::Result), "the class must inherit NFRelationCommonPlayer");
public:
    NFRelationTeam()
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

    virtual ~NFRelationTeam()
    {

    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    //获取大小
    uint32_t GetSize()
    {
        return m_playerMap.size();
    }

    uint32_t GetMaxSize()
    {
        return m_playerMap.max_size();
    }

    //添加成员
    RelationPlayer* AddPlayer(uint64_t cid, bool autoErase = false;)
    {
        if (!HavePlayer(cid))
        {
            if (IsFull())
            {
                if (!autoErase)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_playerMap Not Enough Space, max_size:{} class:{}", GetMaxSize(), typeid(RelationPlayer).name());
                    return NULL;
                }

                uint32_t pos = m_playerList.front();

                m_playerList.pop_front();
            }

            RelationPlayer player;
            player.m_cid = cid;
            auto iter = m_playerMap.emplace_hint(cid, player);
            if (iter != m_playerMap.end())
            {
                m_playerList.push_back(iter.m_curNode->m_self);
                return &iter->second;
            }
        }

        return NULL;
    }

    //判断是否已有某个成员
    bool HavePlayer(uint64_t cid)
    {
        auto iter = m_playerMap.find(cid);
        if (iter != m_playerMap.end())
        {
            return true;
        }
        return false;
    }

    bool IsFull()
    {
        return m_playerMap.size() >= m_playerMap.max_size();
    }

    //获取好友列表数据
    NFShmHashMap<uint64_t, RelationPlayer, max_size> &GetPlayerData()
    {
        return m_playerMap;
    }

    //获取好友数据
    RelationPlayer *GetPlayer(uint64_t cid)
    {
        auto iter = m_playerMap.find(cid);
        if (iter != m_playerMap.end())
        {
            return &iter->second;
        }
        return NULL;
    }

protected:
    NFShmHashMap<uint64_t, RelationPlayer, max_size> m_playerMap;
    NFShmList<uint32_t, max_size> m_playerList;
};