// -------------------------------------------------------------------------
//    @FileName         :    NFStoreProtoCommon.h
//    @Author           :    gaoyi
//    @Date             :    23-3-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFStoreProtoCommon
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "storesvr_sqldata.pb.h"

class NFStoreProtoCommon
{
public:
    static std::string storesvr_selectbycond(const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const std::vector<std::string> &fields,
                                             const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                             const std::string &additional_conds = "", int maxRecords = 100, const std::string &cls_name = "",
                                             const std::string &package_name = "");

    static void storesvr_selectbycond(storesvr_sqldata::storesvr_sel &select, const std::string &dbname, const std::string &tbname,
                                      uint64_t mod_key, const std::vector<std::string> &fields,
                                      const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                      const std::string &additional_conds = "", int maxRecords = 100, const std::string &cls_name = "",
                                      const std::string &package_name = "");

    static void storesvr_selectobj(storesvr_sqldata::storesvr_selobj &select, const std::string &dbname, const std::string &tbname,
                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                   const std::string &package_name = "", const std::vector<std::string> &vecFields = std::vector<std::string>());

    // select对象查询，返回打包数据，该数据可直接网络发送
    static std::string storesvr_selectobj(const std::string &dbname, const std::string &tbname,
                                          uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                          const std::string &package_name = "",
                                          const std::vector<std::string> &vecFields = std::vector<std::string>());

    // insert对象插入，返回打包数据
    static std::string storesvr_insertobj(const std::string &dbname, const std::string &tbname, uint64_t mod_key,
                                          const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                          const std::string &package_name = "");

    static void
    storesvr_insertobj(storesvr_sqldata::storesvr_insertobj &select, const std::string &dbname, const std::string &tbname, uint64_t mod_key,
                       const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                       const std::string &package_name = "");

    // 按条件删除
    static std::string storesvr_deletebycond(const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                             const std::string &additional_conds = "", const std::string &cls_name = "",
                                             const std::string &package_name = "");

    static void storesvr_deletebycond(storesvr_sqldata::storesvr_del &select, const std::string &dbname, const std::string &tbname,
                                      uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                      const std::string &additional_conds = "", const std::string &cls_name = "",
                                      const std::string &package_name = "");

    // 按对象删除
    static std::string storesvr_deleteobj(const std::string &dbname, const std::string &tbname,
                                          uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                          const std::string &package_name = "");

    static void storesvr_deleteobj(storesvr_sqldata::storesvr_delobj &select, const std::string &dbname, const std::string &tbname,
                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                   const std::string &package_name = "");

    static std::string storesvr_modifybycond(const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                             const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                             const std::string &additional_conds = "", const std::string &cls_name = "",
                                             const std::string &package_name = "");

    static void storesvr_modifybycond(storesvr_sqldata::storesvr_mod& select, const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                             const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                             const std::string &additional_conds = "", const std::string &cls_name = "",
                                             const std::string &package_name = "");

    // 按对象修改
    static std::string storesvr_modifyobj(const std::string &dbname, const std::string &tbname,
                                          uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                          const std::string &package_name = "");

    static void storesvr_modifyobj(storesvr_sqldata::storesvr_modobj select, const std::string &dbname, const std::string &tbname,
                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                   const std::string &package_name = "");

    static std::string storesvr_updatebycond(const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                             const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                             const std::string &additional_conds = "", const std::string &cls_name = "",
                                             const std::string &package_name = "");

    static void storesvr_updatebycond(storesvr_sqldata::storesvr_update& select, const std::string &dbname, const std::string &tbname,
                                      uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                      const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                      const std::string &additional_conds = "", const std::string &cls_name = "",
                                      const std::string &package_name = "");

    // 修改插入
    static void storesvr_updateobj(storesvr_sqldata::storesvr_updateobj select, const std::string &dbname, const std::string &tbname,
                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                   const std::string &package_name = "");

    static std::string storesvr_updateobj(const std::string &dbname, const std::string &tbname,
                                          uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "",
                                          const std::string &package_name = "");

    // 按对象修改
    static std::string storesvr_execute(const std::string &dbname, const std::string &tbname,
                                        uint64_t mod_key, const std::string &msg);

    static void storesvr_execute(storesvr_sqldata::storesvr_execute& select, const std::string &dbname, const std::string &tbname,
                                        uint64_t mod_key, const std::string &msg);

    // 按对象修改
    static std::string storesvr_execute_more(const std::string &dbname, const std::string &tbname,
                                             uint64_t mod_key, const std::string &msg, int max_records, const std::string &cls_name);

public:
    static int get_proto_field_type(const google::protobuf::FieldDescriptor &fieldDesc);

    static int get_vk_list_from_proto(const google::protobuf::Message &message, std::vector<storesvr_sqldata::storesvr_vk> &vk_list);
};