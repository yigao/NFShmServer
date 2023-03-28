// -------------------------------------------------------------------------
//    @FileName         :    NFStoreProtoCommon.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFStoreProtoCommon
//
// -------------------------------------------------------------------------

#include "NFStoreProtoCommon.h"

std::string NFStoreProtoCommon::storesvr_selectbycond(const std::string &dbname, const std::string &tbname,
                                                      uint64_t mod_key, const std::vector<std::string> &fields,
                                                      const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                                      const std::string &additional_conds/* = ""*/, int maxRecords/* = 100*/,
                                                      const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_sel select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    for (int i = 0; i < (int) fields.size(); i++)
    {
        select.mutable_baseinfo()->add_sel_fields(fields[i]);
    }
    select.mutable_baseinfo()->set_max_records(maxRecords);

    select.mutable_sel_cond()->set_mod_key(mod_key);

    select.mutable_sel_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_sel_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}


void NFStoreProtoCommon::storesvr_selectobj(storesvr_sqldata::storesvr_selobj &select, const std::string &dbname, const std::string &tbname,
                                            uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/,
                                            const std::string &package_name/* = ""*/,
                                            const std::vector<std::string> &vecFields/* = std::vector<std::string>()*/)
{
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    select.mutable_baseinfo()->set_package_name(package_name);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_sel_record(msg_obj.SerializeAsString());
    if (vecFields.size() > 0)
    {
        for (int i = 0; i < (int) vecFields.size(); i++)
        {
            select.mutable_baseinfo()->add_sel_fields(vecFields[i]);
        }
    }
}

// select对象查询，返回打包数据，该数据可直接网络发送
std::string NFStoreProtoCommon::storesvr_selectobj(const std::string &dbname, const std::string &tbname,
                                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/,
                                                   const std::string &package_name/* = ""*/,
                                                   const std::vector<std::string> &vecFields/* = std::vector<std::string>()*/)
{
    storesvr_sqldata::storesvr_selobj select;
    storesvr_selectobj(select, dbname, tbname, mod_key, msg_obj, cls_name, package_name, vecFields);
    return select.SerializeAsString();
}


// insert对象插入，返回打包数据
std::string NFStoreProtoCommon::storesvr_insert(const std::string &dbname, const std::string &tbname,
                                                uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_ins select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_ins_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按条件删除
std::string NFStoreProtoCommon::storesvr_deletebycond(const std::string &dbname, const std::string &tbname,
                                                      uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                                      const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_del select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.mutable_del_cond()->set_mod_key(mod_key);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_del_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}

// 按对象删除
std::string NFStoreProtoCommon::storesvr_delete(const std::string &dbname, const std::string &tbname,
                                                uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_delobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_del_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

std::string NFStoreProtoCommon::storesvr_modifybycond(const std::string &dbname, const std::string &tbname,
                                                      uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                                      const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                                      const std::string &additional_conds/* = ""*/, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_mod select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }

    select.mutable_mod_cond()->set_mod_key(mod_key);

    select.mutable_mod_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按对象修改
std::string NFStoreProtoCommon::storesvr_modifyobj(const std::string &dbname, const std::string &tbname,
                                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_modobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}


std::string NFStoreProtoCommon::storesvr_modinsbycond(const std::string &dbname, const std::string &tbname,
                                                      uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                                      const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                                      const std::string &additional_conds/* = ""*/, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_modins select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }

    select.mutable_mod_cond()->set_mod_key(mod_key);

    select.mutable_mod_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 修改插入
std::string NFStoreProtoCommon::storesvr_modinsobj(const std::string &dbname, const std::string &tbname,
                                                   uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name/* = ""*/)
{
    storesvr_sqldata::storesvr_modinsobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_modins_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按对象修改
std::string NFStoreProtoCommon::storesvr_execute(const std::string &dbname, const std::string &tbname,
                                                 uint64_t mod_key, const std::string &msg, const std::string &cls_name)
{
    storesvr_sqldata::storesvr_execute select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_execute_record(msg + ";");
    return select.SerializeAsString();
}

// 按对象修改
std::string NFStoreProtoCommon::storesvr_execute_more(const std::string &dbname, const std::string &tbname,
                                                      uint64_t mod_key, const std::string &msg, int max_records, const std::string &cls_name)
{
    storesvr_sqldata::storesvr_execute_more select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.mutable_baseinfo()->set_max_records(max_records);
    select.set_mod_key(mod_key);
    select.set_execute_record(msg + ";");
    return select.SerializeAsString();
}