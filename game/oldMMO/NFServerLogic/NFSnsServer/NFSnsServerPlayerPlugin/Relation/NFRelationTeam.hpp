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
#include "NFComm/NFShmStl/NFShmHashMapWithList.h"

class NFRelationBaseTeam
{
public:
    NFRelationBaseTeam()
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

    virtual ~NFRelationBaseTeam()
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
    virtual uint32_t GetSize() = 0;

    virtual uint32_t GetMaxSize() = 0;

    //添加成员
    virtual NFRelationCommonPlayer* AddPlayer(uint64_t cid, bool autoErase = true) = 0;

    //判断是否已有某个成员
    virtual bool HavePlayer(uint64_t cid) = 0;

    virtual bool IsFull() = 0;

    //获取好友数据
    virtual NFRelationCommonPlayer *GetPlayer(uint64_t cid) = 0;

    virtual void Clear() = 0;

    virtual bool deleteRelation(uint64_t cid) = 0;
};

template<typename RelationPlayer, size_t max_size>
class NFRelationTeam : public NFRelationBaseTeam
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

    virtual uint32_t GetMaxSize()
    {
        return m_playerMap.max_size();
    }

    //添加成员
    virtual RelationPlayer* AddPlayer(uint64_t cid, bool autoErase = true)
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

                m_playerMap.auto_erase(1);
                if (IsFull())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_playerMap auto_erase fail, max_size:{} class:{}", GetMaxSize(), typeid(RelationPlayer).name());
                    return NULL;
                }
            }

            RelationPlayer& pPlayer = m_playerMap[cid];
            pPlayer.m_cid = cid;
            return &pPlayer;
        }

        return NULL;
    }

    //判断是否已有某个成员
    virtual bool HavePlayer(uint64_t cid)
    {
        auto iter = m_playerMap.find(cid);
        if (iter != m_playerMap.end())
        {
            return true;
        }
        return false;
    }

    virtual bool IsFull()
    {
        return m_playerMap.size() >= m_playerMap.max_size();
    }

    //获取好友列表数据
    NFShmHashMapWithList<uint64_t, RelationPlayer, max_size> &GetPlayerData()
    {
        return m_playerMap;
    }

    //获取好友数据
    virtual RelationPlayer *GetPlayer(uint64_t cid)
    {
        auto iter = m_playerMap.find(cid);
        if (iter != m_playerMap.end())
        {
            return &iter->second;
        }
        return NULL;
    }

    virtual void Clear()
    {
        m_playerMap.clear();
    }

    virtual bool deleteRelation(uint64_t cid)
    {
        auto iter = m_playerMap.find(cid);
        if (iter != m_playerMap.end())
        {
            m_playerMap.erase(iter);
            return true;
        }
        return false;
    }
protected:
    NFShmHashMapWithList<uint64_t, RelationPlayer, max_size> m_playerMap;
};