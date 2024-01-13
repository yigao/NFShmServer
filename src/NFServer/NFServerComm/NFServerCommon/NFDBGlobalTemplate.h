// -------------------------------------------------------------------------
//    @FileName         :    NFDBGlobalTemplate.h
//    @Author           :    gaoyi
//    @Date             :    23-11-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDBGlobalTemplate
//
// -------------------------------------------------------------------------

#pragma once

#include "NFBaseDBObj.h"

template<typename className, typename pbClass, int classType>
class NFDBGlobalTemplate : public NFShmObjTemplate<className, classType, NFBaseDBObj>
{
public:
    NFDBGlobalTemplate()
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
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    virtual ~NFDBGlobalTemplate()
    {

    }

    virtual int MakeLoadData(google::protobuf::Message* data)
    {
        CHECK_NULL(data);
        pbClass* p = dynamic_cast<pbClass *>(data);
        CHECK_NULL(p);

        p->set_id(GetDbId());

        return 0;
    }

    virtual int MakeSaveData(google::protobuf::Message* data)
    {
        if (!this->m_bDataInited)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "not inited !");
            return -1;
        }
        CHECK_NULL(data);

        pbClass* p = dynamic_cast<pbClass *>(data);
        CHECK_NULL(p);

        p->set_id(GetDbId());

        return SaveToDB(*p->mutable_data());
    }

    virtual int InitWithDBData(const google::protobuf::Message* pData)
    {
        const pbClass* pGlobal = dynamic_cast<const pbClass*>(pData);
        CHECK_NULL(pGlobal);

        CHECK_EXPR(pGlobal->id() == GetDbId(), -1, "invalid data!");
        int iRet = LoadFromDB(pGlobal->data());
        CHECK_EXPR(iRet == 0, -1, "parse failed!");

        iRet = InitConfig();
        CHECK_EXPR(iRet == 0, -1, "InitConfig failed!");
        this->m_bDataInited = true;
        return 0;
    }

    virtual int InitWithoutDBData()
    {
        int iRet = InitConfig();
        CHECK_EXPR(iRet == 0, -1, "InitConfig failed!");
        this->m_bDataInited = true;
        return 0;
    }

    virtual int LoadFromDB(const std::string& dbData) = 0;

    virtual int SaveToDB(std::string& dbData) = 0;

    virtual int InitConfig() = 0;

    virtual int GetDbId() = 0;

    virtual google::protobuf::Message* CreateTempProtobufData() { return new pbClass(); }
    virtual uint32_t GetSaveDis() { return 60; }
    virtual eDealWithLoadFailed DealWithFailed() { return EN_DW_SHUTDOWN; }
};
