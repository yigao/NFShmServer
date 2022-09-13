// -------------------------------------------------------------------------
//    @FileName         :    NFIFishAlgoMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIFishAlgoMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIFishAlgoModule.h"

/// 算法接口
class NFIAlgoTypeInterface {
public:
    virtual int
    Init(int iGameID, int iRoomID, int iDeskID, int iTotalFishKind, int iTotalConnonCount, int iMaxConnonVal) = 0;

    virtual void GameEnd() = 0;

    virtual bool OnRoomStartNotify() = 0;

    //设置抽水率和难度
    virtual void SetTypeDrawRateNandu(int iNanduSpec) = 0;

    //桌子号码
    virtual uint32_t GetDeskID() = 0;

    virtual int GetRoomID() = 0;

    //基础定时器
    virtual void OnBaseTime() = 0;
public:
    //检测状态
    virtual void CheckNewAlgoStatus() = 0;

    //检测初始是否需要重置为初始值
    virtual void CheckNeedInitStatus() = 0;

    // 获取条件控制值Y
    virtual int64_t GetCtrlAlgoY() = 0;

    //分配数据

    virtual bool
    AllocTypeAlgoHitCountCfg(int iConnonIndex,uint32_t btFishKind, uint32_t btFishKindGroup1,int nBaseMul,int& iHitCountCfg,double& dbConnonHitPool) = 0;

    virtual void
    GetYValueInfo(int64_t &llYValue, int64_t &llYValueA, int64_t &llYValueB, int64_t &llFreePool, int &nControlLevel) = 0;

    virtual void UpdateYValueB(const int64_t llGMWinMoney) = 0;

    virtual void InitFreePool(const int64_t llFreePool) = 0;
    // 数据保存和读取
public:
    virtual void ReadOneTypeAllAlgoData() = 0;

    // 保存基础重要信息

    virtual void SaveOneTypeAlgoBaseInfo() = 0;

    virtual void ReadOneTypeAlgoBaseInfo() = 0;

    // 保存算法文件当前索引

    virtual void SaveOneTypeAlgoNormalData() = 0;

    virtual void ReadOneTypeAlgoNormalData() = 0;
public:
    // 总发射炮弹富贵豆
    virtual int64_t GetTableOneTypeTotalShootMoney() = 0;

    virtual void SetTableOneTypeTotalShootMoney(int64_t iTotalShootMoney) = 0;

    virtual bool AddTableOneTypeTotalShootMoney(double dbShootMoney) = 0;

    virtual bool SubTableOneTypeTotalShootMoney(double dbShootMoney) = 0;



    // 总捕获富贵豆

    virtual int64_t GetTableOneTypeTotalCaptureMoney() = 0;

    virtual void SetTableOneTypeTotalCaptureMoney(int64_t iTotalCaptureMoney) = 0;

    virtual bool AddTableOneTypeTotalCaptureMoney(double dbCaptureMoney) = 0;


    virtual void SetTableOneTypeYValueInfo(int64_t llYValue, int64_t llYValueA, int64_t llYValueB, int64_t llFreePool,
                                           int nControlLevel) = 0;
    //当前场索引

    virtual void SetAlgoCurChang(unsigned short iAlgoCurChang) = 0;

    virtual unsigned short GetAlgoCurChang() = 0;
    //当前算法状态

    virtual void SetAlgoStatus(unsigned short iCurStatus) = 0;

    virtual unsigned short GetAlgoStatus() = 0;

    //获取算法控制信息

    virtual tagFishAlgoCtrlInfo GetTypeAlgoCtrlInfo() = 0;

    //获取算法类型

    virtual eFishAlgoTypeInter GetTypeFishAlgoType() = 0;

    //概率算法 获取概率

    virtual bool GetTypeRandAlgoRate(int iCannonIndex, int nBaseMul, double &dbRate) = 0;

    //日志
public:
    //打印基本信息到文件
    virtual void PirntOutAlgoData() = 0;
};


