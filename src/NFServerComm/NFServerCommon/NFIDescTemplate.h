// -------------------------------------------------------------------------
//    @FileName         :    NFIDescTemplate.h
//    @Author           :    gaoyi
//    @Date             :    23-10-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDescTemplate
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFCore/NFStringUtility.h"

template<typename className, typename className_s, int classType, int DescNum>
class NFIDescTemplate : public NFShmObjGlobalTemplate<className, classType, NFIDescStore>
{
public:
    NFIDescTemplate()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        m_minId = INVALID_ID;
        m_astDescIndex.resize(DescNum*2);
        for(int i = 0; i < (int)m_astDescIndex.size(); i++)
        {
            m_astDescIndex[i] = INVALID_ID;
        }
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
public:
    virtual int GetResNum() const override { return m_astDescMap.size(); }
    NFShmHashMap<uint64_t, className_s, DescNum> &GetResDesc() { return m_astDescMap; }
    const NFShmHashMap<uint64_t, className_s, DescNum> &GetResDesc() const { return m_astDescMap; }
    NFShmHashMap<uint64_t, className_s, DescNum> *GetResDescPtr() { return &m_astDescMap; }
    const NFShmHashMap<uint64_t, className_s, DescNum> *GetResDescPtr() const { return &m_astDescMap; }
    
    const className_s* GetDesc(int64_t id) const
    {
        int64_t index = id - (int64_t)m_minId;
        if (index >= 0 && index < (int64_t)m_astDescIndex.size())
        {
            auto iter = m_astDescMap.get_iterator(m_astDescIndex[index]);
            if (iter != m_astDescMap.end())
            {
                return &iter->second;
            }
        }

        auto iter = m_astDescMap.find(id);
        if (iter != m_astDescMap.end())
        {
            return &iter->second;
        }
        
        return NULL;
    }
    
    className_s* GetDesc(int64_t id)
    {
        return const_cast<className_s *>((static_cast<const className*>(this))->GetDesc(id));
    }
    
public:
    virtual int Initialize() { return 0; }
    
    virtual int Load(NFResDB *pDB) { return 0; }
    
    virtual int CheckWhenAllDataLoaded() { return 0; }
    
    virtual int Reload(NFResDB *pDB) override
    {
        this->PrepareReload();
        int iRetCode = this->Load(pDB);
        return iRetCode;
    }
    
    virtual std::string GetFileName() override
    {
        std::string strSubModuleName = typeid(className).name();

#if NF_PLATFORM == NF_PLATFORM_WIN
        
        std::size_t position = strSubModuleName.find(' ');
        if (string::npos != position)
        {
            strSubModuleName = strSubModuleName.substr(position + 1, strSubModuleName.length());
        }
#else
        for (int i = 0; i < (int) strSubModuleName.length(); i++)
        {
            std::string s = strSubModuleName.substr(0, i + 1);
            int n = atof(s.c_str());
            if ((int) strSubModuleName.length() == i + 1 + n)
            {
                strSubModuleName = strSubModuleName.substr(i + 1, strSubModuleName.length());
                break;
            }
        }
#endif
        int pos = strSubModuleName.rfind("Desc");
        if (pos != std::string::npos)
        {
            strSubModuleName = strSubModuleName.substr(0, pos);
        }
        strSubModuleName = "E_" + strSubModuleName;
        return strSubModuleName;
    }
    
    virtual int CalcUseRatio() override
    {
        return m_astDescMap.size() * 100 / m_astDescMap.max_size();
    }
    
    virtual int SaveDescStore() override
    {
        if (!this->IsLoaded())
            return 0;
        for (auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
        {
            auto pDesc = &iter->second;
            if (pDesc->IsUrgentNeedSave())
            {
                auto pb = className_s::make_pbmsg();
                pDesc->write_to_pbmsg(pb);
                this->SaveDescStoreToDB(&pb);
                pDesc->ClearUrgent();
            }
        }
        return 0;
    }
    
    int InsertDescStore(const className_s &desc)
    {
        auto pb = className_s::make_pbmsg();
        desc.write_to_pbmsg(pb);
        this->InsertDescStoreToDB(&pb);
        return 0;
    }
    
    int DeleteDescStore(const className_s &desc)
    {
        auto pb = className_s::make_pbmsg();
        desc.write_to_pbmsg(pb);
        this->DeleteDescStoreToDB(&pb);
        return 0;
    }
protected:
    NFShmHashMap<uint64_t, className_s, DescNum> m_astDescMap;
    NFShmVector<int, DescNum*2> m_astDescIndex;
    int64_t m_minId;
};