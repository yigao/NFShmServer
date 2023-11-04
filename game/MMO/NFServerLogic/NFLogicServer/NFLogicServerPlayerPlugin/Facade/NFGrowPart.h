// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Grow.pb.h"

class NFGrowPart : public NFShmObjTemplate<NFGrowPart, EOT_LOGIC_PART_ID+PART_GROW, NFPart>
{
public:
    //部件元素
    struct GrowPartEntry
    {
        GrowPartEntry()
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
            id = 0;
            lv = 0;
            return 0;
        }
        
        int ResumeInit()
        {
            return 0;
        }
        
        int64_t id = 0;
        int32_t lv = 0;
    };
    
    typedef NFShmHashMap<int64_t, GrowPartEntry, 10> GrowPartEntryMap;
    
    //养成部件
    struct GrowPartData
    {
        GrowPartData()
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
            type = 0;
            curId = 0;
            return 0;
        }
        
        int ResumeInit()
        {
            return 0;
        }
        
        int32_t type;
        GrowPartEntryMap entryMap;
        int64_t curId;
        
        GrowPartEntry *GetPartEntry(int64_t id);
        
        void SetPartEntry(GrowPartEntry &entry);
    };
    
    typedef NFShmHashMap<int32_t, GrowPartData, proto_ff::GrowType_MAX> GrowPartMap;
public:
    NFGrowPart();

    virtual ~NFGrowPart();

    int CreateInit();

    int ResumeInit();

public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData& data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData& data);
    
    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();
    virtual int OnLogin(proto_ff::PlayerInfoRsp& playerInfo) { return 0; }
    
    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }
    
    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }
    
    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto& outproto);
    //填充头像数据
    void FillHeadProto(proto_ff::RoleHeadPicProto& proto);
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();
public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);
public:
    int HanlderLvUpReq(uint32_t msgId, NFDataPackage &packet);        //升级
    int HanlderDressReq(uint32_t msgId, NFDataPackage &packet);        //穿戴
    int HanlderUnDressReq(uint32_t msgId, NFDataPackage &packet);        //卸载
public:
    int OnActivePartEntry(int64_t id);                            //处理激活
    int OnLvupPartEntry(int64_t id);                            //处理升级
public:
    int FillProto(const GrowPartData &part, proto_ff::GrowSubInfo &proto);
    
    GrowPartData *getPart(int32_t type);

public:
    int SendAllGrowData();                                        //发送全部数据
    int SendGrowPartData(int32_t type);                        //发送某个部件数据
public:
    void calcAttr(bool sync);
    
    void calcAttr(int32_t type, MAP_INT32_INT64 &outAttr);        //计算养成部件属性
    void MergeAttr(MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst);
    
    void PrintAttr(int32_t type, MAP_INT32_INT64 &attr);

private:
    void initParts();

protected:
    GrowPartMap m_partsMap;                    //所有养成的部件
};