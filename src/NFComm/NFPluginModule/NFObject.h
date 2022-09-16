// -------------------------------------------------------------------------
//    @FileName         :    NFPair.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFIPluginManager"
#include <stddef.h>
#include <string.h>

class NFObject
{
public:
    NFObject(NFIPluginManager *p):m_pPluginManager(p)
    {

    }

    virtual ~NFObject()
    {

    }

    template <typename T>
    T* FindModule() const
    {
        if (m_pPluginManager)
        {
            return m_pPluginManager->FindModule<T>();
        }
        return nullptr;
    }

    virtual NFIPluginManager* GetPluginManager() const
    {
        return m_pPluginManager;
    }
protected:
    NFIPluginManager* m_pPluginManager;
};