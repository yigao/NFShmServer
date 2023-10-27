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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
public:
    virtual int GetResNum() const override { return m_astDesc.size(); }
    NFShmVector<className_s, DescNum> &GetResDesc() { return m_astDesc; }
    const NFShmVector<className_s, DescNum> &GetResDesc() const { return m_astDesc; }
    NFShmVector<className_s, DescNum> *GetResDescPtr() { return &m_astDesc; }
    const NFShmVector<className_s, DescNum> *GetResDescPtr() const { return &m_astDesc; }
    
    const className_s* GetDesc(int64_t id) const
    {
        auto iter = m_astDescMap.find(id);
        if (iter != m_astDescMap.end())
        {
            int index = iter->second;
            CHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
            return &m_astDesc[index];
        }
        
        return NULL;
    }
    
    className_s* GetDesc(int64_t id)
    {
        return const_cast<className_s *>((static_cast<const className*>(this))->GetDesc(id));
    }
    
    int GetDescIndex(int id) const
    {
        auto iter = m_astDescMap.find(id);
        if (iter != m_astDescMap.end())
        {
            return iter->second;
        }
        
        return -1;
    }
    
    const className_s* GetDescByIndex(int index) const
    {
        CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
        return &m_astDesc[index];
    }
    
    className_s* GetDescByIndex(int index)
    {
        CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
        return &m_astDesc[index];
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
        return m_astDesc.size() * 100 / m_astDesc.max_size();
    }
    
    virtual int SaveDescStore() override
    {
        if (!this->IsLoaded())
            return 0;
        for (int i = 0; i < (int) m_astDesc.size(); i++)
        {
            if (m_astDesc[i].IsUrgentNeedSave())
            {
                auto pb = className_s::make_pbmsg();
                m_astDesc[i].write_to_pbmsg(pb);
                this->SaveDescStoreToDB(&pb);
                m_astDesc[i].ClearUrgent();
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
    NFShmVector<className_s, DescNum> m_astDesc;
    NFShmHashMap<uint64_t, int, DescNum> m_astDescMap;
};