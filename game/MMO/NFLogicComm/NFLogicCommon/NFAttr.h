// -------------------------------------------------------------------------
//    @FileName         :    NFAttr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Com.pb.h"
#include <unordered_map>

#pragma pack(push)
#pragma pack(1)

//通用 战斗属性结束ID
const uint32_t COMMON_FIGHT_ATTR_END = 72;
//通用 战斗属性组结束ID
const uint32_t COMMON_FIGHT_ATTR_GROUP_END = 4;

//通用 普通属性结束ID
const uint32_t COMMON_ATTR_END = 20;



//角色 战斗属性结束ID
const uint32_t ROLE_FIGHT_ATTR_END = 201;
//角色 战斗属性 结束组ID
const uint32_t ROLE_FIGHT_ATTR_GROUP_END = (uint32_t)proto_ff::EAttrGroup_ARRAYSIZE;


//角色 普通属性结束ID
const uint32_t ROLE_ATTR_END = 200;

//属性类型
enum class EAttrType
{
    none = 0,		//无
    common = 1,		//通用属性
    role = 2,		//角色属性
};

class IFightAttr : public NFShmObj
{
public:
    virtual ~IFightAttr() {}
    virtual EAttrType GetType() { return EAttrType::none; }
    //是否有效的战斗属性ID
    virtual bool ValidAttr(uint32_t ANum) = 0;
    //是否是有效的属性数组索引
    virtual bool ValidIndex(uint8_t index) = 0;
    //是否是有效的战斗属性组ID
    virtual bool ValidAttrGroup(uint32_t groupid) = 0;
    //获取总属性值
    virtual int64_t GetAttr(uint32_t ANum) = 0;
    //获取所有的总属性
    virtual void GetAttr(std::unordered_map<uint32_t, int64_t>& mapattr) = 0;
    //计算总属性值
    virtual void CalcAttr(std::unordered_map<uint32_t, int64_t> &mapchg) = 0;
    //计算指定ID的总属性值
    virtual bool CalcAttr(uint32_t ANum, bool* chgflag = nullptr) = 0;
    //获取指定属性组中指定ID的属性值
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum) = 0;
    //增加指定属性组中指定ID的属性值
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag = nullptr) = 0;
    //设置指定属性组中指定ID的属性值
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool* chgflag = nullptr) = 0;
    //清空指定属性组的属性值
    virtual bool ClearAttrGroup(uint32_t groupid, bool* chgflag = nullptr) = 0;
};


//通用战斗属性
class ComFightAttr : public IFightAttr
{
public:
    ComFightAttr();
    virtual ~ComFightAttr();
    int CreateInit();
    int ResumeInit();
public:
    virtual EAttrType GetType() { return EAttrType::common; }
    virtual bool ValidAttr(uint32_t ANum);
    virtual bool ValidAttrGroup(uint32_t groupid);
    virtual bool ValidIndex(uint8_t index);
    virtual int64_t GetAttr(uint32_t ANum);
    virtual void GetAttr(std::unordered_map<uint32_t, int64_t> &mapattr);
    virtual void CalcAttr(std::unordered_map<uint32_t, int64_t>& mapchg);
    virtual bool CalcAttr(uint32_t ANum, bool* chgflag = nullptr);
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum);
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool ClearAttrGroup(uint32_t groupid, bool* chgflag = nullptr);
private:
    //战斗属性, ID为0的属性组表示总属性
    int64_t m_attr[COMMON_FIGHT_ATTR_GROUP_END][COMMON_FIGHT_ATTR_END];
DECLARE_IDCREATE(ComFightAttr)
};


//角色战斗属性
class RoleFightAttr : public IFightAttr
{
public:
    RoleFightAttr();
    virtual ~RoleFightAttr();
    int CreateInit();
    int ResumeInit();

    virtual EAttrType GetType() { return EAttrType::role; }
    virtual bool ValidAttr(uint32_t ANum);
    virtual bool ValidIndex(uint8_t index);
    virtual bool ValidAttrGroup(uint32_t groupid);
    virtual int64_t GetAttr(uint32_t ANum);
    virtual void GetAttr(std::unordered_map<uint32_t, int64_t>& mapattr);
    virtual void CalcAttr(std::unordered_map<uint32_t, int64_t>& mapchg);
    virtual bool CalcAttr(uint32_t ANum, bool* chgflag = nullptr);
    virtual int64_t GetAttrGroup(uint32_t groupid, uint32_t ANum);
    virtual bool AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool ClearAttrGroup(uint32_t groupid, bool* chgflag = nullptr);
private:
    //战斗属性, ID为0的属性组表示总属性
    int64_t m_attr[ROLE_FIGHT_ATTR_GROUP_END][ROLE_FIGHT_ATTR_END];
DECLARE_IDCREATE(RoleFightAttr)
};

class IAttr : public NFShmObj
{
public:
    virtual ~IAttr() {};
    virtual EAttrType GetType() { return EAttrType::none; }
    //是否有效的属性ID
    virtual bool ValidAttr(uint32_t ANum) = 0;
    //是否是有效的属性数组索引
    virtual bool ValidIndex(uint16_t index) = 0;
    //获取属性值
    virtual int64_t GetAttr(uint32_t ANum) = 0;
    //增加属性值
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr) = 0;
    //设置属性值
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr) = 0;
};

//通用属性
class ComAttr : public IAttr
{
public:
    ComAttr();
    virtual ~ComAttr();
    int CreateInit();
    int ResumeInit();
    virtual EAttrType GetType() { return EAttrType::common; }
    virtual bool ValidAttr(uint32_t ANum);
    virtual bool ValidIndex(uint16_t index);
    virtual int64_t GetAttr(uint32_t ANum);
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr);
private:
    int64_t m_attr[COMMON_ATTR_END];
DECLARE_IDCREATE(ComAttr)
};


//角色属性
class RoleAttr : public IAttr
{
public:
    RoleAttr();
    virtual ~RoleAttr();
    int CreateInit();
    int ResumeInit();
    virtual EAttrType GetType() { return EAttrType::role; }
    virtual bool ValidAttr(uint32_t ANum);
    virtual bool ValidIndex(uint16_t index);
    virtual int64_t GetAttr(uint32_t ANum);
    virtual bool AddAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr);
    virtual bool SetAttr(uint32_t ANum, int64_t val, bool* chgflag = nullptr);
private:
    int64_t m_attr[ROLE_ATTR_END];
DECLARE_IDCREATE(RoleAttr)
};

#pragma pack(pop)