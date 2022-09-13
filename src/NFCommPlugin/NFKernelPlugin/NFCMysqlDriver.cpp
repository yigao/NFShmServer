#include "NFCMysqlDriver.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

//m_pMysqlConnect在调用Connect会引发多线程的崩溃，必须枷锁
NFMutex NFCMysqlDriver::ConnectLock;

NFCMysqlDriver::NFCMysqlDriver(const int nReconnectTime/* = 60*/, const int nReconnectCount /*= -1*/)
{
	mfCheckReconnect = 0.0f;
	mnDBPort = 0;
	m_pMysqlConnect = nullptr;
	mnReconnectTime = nReconnectTime;
	mnReconnectCount = nReconnectCount;
}

NFCMysqlDriver::NFCMysqlDriver(const std::string& strDBName, const std::string& strDBHost, const int nDBPort,
                               const std::string& strDBUser, const std::string& strDBPwd)
{
	mfCheckReconnect = 0.0f;
	mnDBPort = 0;
	m_pMysqlConnect = nullptr;

	mnReconnectTime = 3;
	mnReconnectCount = -1;

	NFCMysqlDriver::Connect(strDBName, strDBHost, nDBPort, strDBUser, strDBPwd);
}

NFCMysqlDriver::~NFCMysqlDriver()
{
	NFCMysqlDriver::CloseConnection();
}

int NFCMysqlDriver::Connect(const std::string& strDBName, const std::string& strDBHost, const int nDBPort,
                             const std::string& strDBUser, const std::string& strDBPwd)
{
	mstrDBName = strDBName;
	mstrDBHost = strDBHost;
	mnDBPort = nDBPort;
	mstrDBUser = strDBUser;
	mstrDBPwd = strDBPwd;

	return Connect();
}

int NFCMysqlDriver::CheckConnect()
{
	if (IsNeedReconnect() && CanReconnect())
	{
		Connect(mstrDBName, mstrDBHost, mnDBPort, mstrDBUser, mstrDBPwd);
	}

	return 0;
}

int NFCMysqlDriver::Query(const std::string &qstr, mysqlpp::StoreQueryResult &queryResult, std::string &errormsg) {
    mysqlpp::Connection *pConection = GetConnection();
    if (pConection) {
        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", qstr);

        NFMYSQLTRYBEGIN
            mysqlpp::Query query = pConection->query(qstr);
            //query.execute();
            //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
            queryResult = query.store();

            query.reset();
        NFMYSQLTRYEND("Query Error")
        return 0;
    }

    return -1;
}

int NFCMysqlDriver::ExecuteOne(const std::string &qstr, std::map<std::string, std::string> &valueVec,
                               std::string &errormsg) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", qstr);

    mysqlpp::StoreQueryResult queryResult;
    if (NFCMysqlDriver::Query(qstr, queryResult, errormsg) == 0) {
        for (size_t i = 0; i < queryResult.num_rows(); ++i) {
            for (size_t j = 0; j < queryResult[i].size(); j++) {
                std::string value;
                queryResult[i][j].to_string(value);
                valueVec.emplace(queryResult.field_name(j), value);
            }
            return 0; //-V612
        }
        return 0;
    }
    return -1;
}

int NFCMysqlDriver::Execute(const storesvr_sqldata::storesvr_execute &select, storesvr_sqldata::storesvr_execute_res &select_res)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", select.execute_record());

    mysqlpp::StoreQueryResult queryResult;
    std::vector<std::map<std::string, std::string>> valueVec;
    std::string errormsg;
    if (ExecuteMore(select.execute_record(), valueVec, errormsg) == 0) {
        return 0;
    }
    select_res.mutable_exe_opres()->set_zdb_errmsg(errormsg);
    return -1;
}

int NFCMysqlDriver::ExecuteMore(const std::string &qstr, std::vector<std::map<std::string, std::string>> &valueVec,
                                std::string &errormsg) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", qstr);

    mysqlpp::StoreQueryResult queryResult;
    if (NFCMysqlDriver::Query(qstr, queryResult, errormsg) == 0) {
        for (size_t i = 0; i < queryResult.num_rows(); ++i) {
            valueVec.push_back(std::map<std::string, std::string>());
            std::map<std::string, std::string> &tmpVec = valueVec.back();
            for (size_t j = 0; j < queryResult[i].size(); j++) {
                std::string value;
                queryResult[i][j].to_string(value);
                tmpVec.emplace(queryResult.field_name(j), value);
            }
        }
        return 0;
    }
    return -1;
}

/**
 * @brief 执行sql语句, 把数据库配置表里的数据取出来
 *
 * @param  table 配置表表明
 * @param  sheet_fullname protobuf中代表一个表格的message
 * @param  pMessage sheet_fullname的protobuf的数据结构，携带返回数据
 *  比如 message Sheet_GameRoomDesc
 *		{
 *			repeated GameRoomDesc GameRoomDesc_List = 1  [(yd_fieldoptions.field_arysize)=100];
 *		}
 * 代表一个Excel表格GameRoomDesc, 同时数据库有一个表GameRoomDesc
 * 都用这个数据结构来表达，以及存取数据
 *
 *
 * @return bool 执行成功或失败
 */
int NFCMysqlDriver::QueryDescStore(const std::string &table, google::protobuf::Message **pMessage) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --table:{}", table);
    int iRet = 0;
    std::string selectSql = "select * from " + table;
    std::vector<std::map<std::string, std::string>> resultVec;
    std::string errmsg;
    iRet = ExecuteMore(selectSql, resultVec, errmsg);
    CHECK_EXPR(iRet == 0, iRet, "ExecuteMore:{} Failed!", errmsg);

    if (resultVec.size() <= 0) {
        return 0;
    }

    //通过sheet_fullname名字，获得这个protobuf类的默认变量
    std::string sheet_fullname = "proto_ff.Sheet_" + table;
    const ::google::protobuf::Message *pSheetMessage = NFProtobufCommon::FindMessageTypeByName(sheet_fullname);

    CHECK_EXPR(pSheetMessage, -1,
               "NFProtobufCommon::GetDefaultMessageFromFullName:{} Failed", sheet_fullname);

    //通过protobuf默认便利new出来一个新的sheet_fullname变量
    ::google::protobuf::Message *pSheetMessageObject = pSheetMessage->New();
    CHECK_EXPR(pSheetMessageObject, -1, "{} New Failed", sheet_fullname);

    if (pMessage) {
        *pMessage = pSheetMessageObject;
    }

    const google::protobuf::Descriptor *pSheetFieldDesc = pSheetMessageObject->GetDescriptor();
    CHECK_EXPR(pSheetFieldDesc, -1, "pSheetFieldDesc == NULL");
    const google::protobuf::Reflection *pSheetReflect = pSheetMessageObject->GetReflection();
    CHECK_EXPR(pSheetReflect, -1, "pSheetFieldDesc == NULL");

    for (int sheet_field_index = 0; sheet_field_index < pSheetFieldDesc->field_count(); sheet_field_index++) {
        /*  比如 message Sheet_GameRoomDesc
        *		{
        *			repeated GameRoomDesc GameRoomDesc_List = 1  [(yd_fieldoptions.field_arysize)=100];
        *		}
        *		获得上面GameRoomDesc_List信息
        */
        const google::protobuf::FieldDescriptor *pSheetRepeatedFieldDesc = pSheetFieldDesc->field(sheet_field_index);
        if (pSheetRepeatedFieldDesc->is_repeated() &&
            pSheetRepeatedFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE) {
            //如果is_repeated 开始处理
            for (size_t result_i = 0; result_i < resultVec.size(); result_i++) {
                const std::map<std::string, std::string> &result = resultVec[result_i];
                ::google::protobuf::Message *pSheetRepeatedMessageObject = pSheetReflect->AddMessage(
                        pSheetMessageObject, pSheetRepeatedFieldDesc);
                NFProtobufCommon::GetMessageFromMapFields(result, pSheetRepeatedMessageObject);
            }
        }
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::QueryDescStore(const std::string &table, google::protobuf::Message *pSheetMessageObject)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --table:{}", table);
    CHECK_EXPR(pSheetMessageObject, -1, "pMessage == NULL");
    int iRet = 0;
    std::string selectSql = "select * from " + table;
    std::vector<std::map<std::string, std::string>> resultVec;
    std::string errmsg;
    iRet = ExecuteMore(selectSql, resultVec, errmsg);
    CHECK_EXPR(iRet == 0, iRet, "ExecuteMore:{} Failed!", errmsg);

    if (resultVec.size() <= 0) {
        return 0;
    }

    const google::protobuf::Descriptor *pSheetFieldDesc = pSheetMessageObject->GetDescriptor();
    CHECK_EXPR(pSheetFieldDesc, -1, "pSheetFieldDesc == NULL");
    const google::protobuf::Reflection *pSheetReflect = pSheetMessageObject->GetReflection();
    CHECK_EXPR(pSheetReflect, -1, "pSheetFieldDesc == NULL");

    for (int sheet_field_index = 0; sheet_field_index < pSheetFieldDesc->field_count(); sheet_field_index++) {
        /*  比如 message Sheet_GameRoomDesc
        *		{
        *			repeated GameRoomDesc GameRoomDesc_List = 1  [(yd_fieldoptions.field_arysize)=100];
        *		}
        *		获得上面GameRoomDesc_List信息
        */
        const google::protobuf::FieldDescriptor *pSheetRepeatedFieldDesc = pSheetFieldDesc->field(sheet_field_index);
        if (pSheetRepeatedFieldDesc->is_repeated() &&
            pSheetRepeatedFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE) {
            //如果is_repeated 开始处理
            for (size_t result_i = 0; result_i < resultVec.size(); result_i++) {
                const std::map<std::string, std::string> &result = resultVec[result_i];
                ::google::protobuf::Message *pSheetRepeatedMessageObject = pSheetReflect->AddMessage(
                        pSheetMessageObject, pSheetRepeatedFieldDesc);
                NFProtobufCommon::GetMessageFromMapFields(result, pSheetRepeatedMessageObject);
            }
        }
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::TransTableRowToMessage(const std::map<std::string, std::string> &result, const std::string &table,
                                           google::protobuf::Message **pMessage) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --table:{}", table);
    std::string proto_fullname = "proto_ff." + table;

    const ::google::protobuf::Message *pDefaultMessage = NFProtobufCommon::FindMessageTypeByName(proto_fullname);

    CHECK_EXPR(pDefaultMessage, -1,
               "NFProtobufCommon::FindMessageTypeByName:{} Failed", proto_fullname);

    //通过protobuf默认便利new出来一个新的proto_fullname变量
    ::google::protobuf::Message *pMessageObject = pDefaultMessage->New();
    CHECK_EXPR(pMessageObject, -1, "{} New Failed", proto_fullname);

    if (pMessage) {
        *pMessage = pMessageObject;
    }

    NFProtobufCommon::GetMessageFromMapFields(result, pMessageObject);
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::SelectByCond(const storesvr_sqldata::storesvr_sel &select, ::google::protobuf::RepeatedPtrField<storesvr_sqldata::storesvr_sel_res> &vecSelectRes)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string selectSql;
    int iRet = 0;
    iRet = CreateSql(select, selectSql);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}", selectSql);

    std::vector<std::map<std::string, std::string>> resultVec;
    std::string errmsg;
    iRet = ExecuteMore(selectSql, resultVec, errmsg);
    if (iRet != 0) {
        storesvr_sqldata::storesvr_sel_res* select_res = vecSelectRes.Add();
        select_res->mutable_sel_opres()->set_zdb_errmsg(errmsg);
        return -1;
    }

    storesvr_sqldata::storesvr_sel_res* select_res = vecSelectRes.Add();

    select_res->mutable_baseinfo()->CopyFrom(select.baseinfo());
    select_res->mutable_sel_opres()->set_mod_key(select.sel_cond().mod_key());
    select_res->set_is_lastbatch(false);

    int count = 0;
    for (size_t i = 0; i < resultVec.size(); i++) {
        const std::map<std::string, std::string> &result = resultVec[i];

        google::protobuf::Message *pMessage = NULL;
        iRet = TransTableRowToMessage(result, select.baseinfo().clname(), &pMessage);
        if (iRet == 0 && pMessage != NULL) {
            select_res->add_sel_records(pMessage->SerializeAsString());

            count++;
            select_res->set_row_count(count);
            if (select_res->sel_records_size() >= 100)
            {
                count = 0;
                select_res = vecSelectRes.Add();

                select_res->mutable_baseinfo()->CopyFrom(select.baseinfo());
                select_res->mutable_sel_opres()->set_mod_key(select.sel_cond().mod_key());
                select_res->set_is_lastbatch(false);
            }
            NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "{}", pMessage->Utf8DebugString());
        } else {
            NFLogError(NF_LOG_MYSQL_PLUGIN, 0, "TransTableRowToMessage Failed, result:{} tableName:{}",
                       NFCommon::tostr(result), select.baseinfo().tbname());
        }

        if (pMessage != NULL)
        {
            NF_SAFE_DELETE(pMessage);
        }
    }

    select_res->set_is_lastbatch(true);

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::SelectByCond(const storesvr_sqldata::storesvr_sel &select,
                                 storesvr_sqldata::storesvr_sel_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string selectSql;
    int iRet = 0;
    iRet = CreateSql(select, selectSql);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}", selectSql);

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_sel_opres()->set_mod_key(select.sel_cond().mod_key());
    std::vector<std::map<std::string, std::string>> resultVec;
    std::string errmsg;
    iRet = ExecuteMore(selectSql, resultVec, errmsg);
    if (iRet != 0) {
        select_res.mutable_sel_opres()->set_zdb_errmsg(errmsg);
        return -1;
    }

    select_res.set_is_lastbatch(true);

    int count = 0;
    for (size_t i = 0; i < resultVec.size(); i++) {
        const std::map<std::string, std::string> &result = resultVec[i];

        google::protobuf::Message *pMessage = NULL;
        iRet = TransTableRowToMessage(result, select.baseinfo().clname(), &pMessage);
        if (iRet == 0 && pMessage != NULL) {
            count++;
            select_res.add_sel_records(pMessage->SerializeAsString());
            NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "{}", pMessage->Utf8DebugString());
        } else {
            NFLogError(NF_LOG_MYSQL_PLUGIN, 0, "TransTableRowToMessage Failed, result:{} tableName:{}",
                       NFCommon::tostr(result), select.baseinfo().tbname());
        }
        if (pMessage != NULL)
        {
            NF_SAFE_DELETE(pMessage);
        }
    }

    select_res.set_row_count(count);
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::SelectObj(const std::string& tbName, google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --tbName:{} errMsg:{}", tbName, errMsg);
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    storesvr_sqldata::storesvr_selobj select;
    select.mutable_baseinfo()->set_tbname(tbName);
    select.set_sel_record(pMessage->SerializeAsString());

    storesvr_sqldata::storesvr_selobj_res select_res;

    int iRet = SelectObj(select, select_res);
    if (iRet == 0)
    {
        pMessage->ParseFromString(select_res.sel_record());
    }
    else
    {
        errMsg = select_res.sel_opres().zdb_errmsg();
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return iRet;
}

int NFCMysqlDriver::SelectObj(const storesvr_sqldata::storesvr_selobj &select,
                              storesvr_sqldata::storesvr_selobj_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}");

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_sel_opres()->set_mod_key(select.mod_key());
    std::map<std::string, std::string> result;
    std::string errmsg;
    iRet = QueryOne(select.baseinfo().tbname(), keyMap, result, errmsg);
    if (iRet != 0) {
        select_res.mutable_sel_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    google::protobuf::Message *pMessage = NULL;
    iRet = TransTableRowToMessage(result, select.baseinfo().clname(), &pMessage);
    if (iRet == 0 && pMessage != NULL) {
        select_res.set_sel_record(pMessage->SerializeAsString());
        NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "{}", pMessage->Utf8DebugString());
    } else {
        NFLogError(NF_LOG_MYSQL_PLUGIN, 0, "TransTableRowToMessage Failed, result:{} tableName:{}",
                   NFCommon::tostr(result), select.baseinfo().tbname());
    }
    if (pMessage != NULL)
    {
        NF_SAFE_DELETE(pMessage);
    }
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}


int NFCMysqlDriver::DeleteByCond(const storesvr_sqldata::storesvr_del &select,
                                 storesvr_sqldata::storesvr_del_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string selectSql;
    int iRet = 0;
    iRet = CreateSql(select, selectSql);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}", selectSql);

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_del_opres()->set_mod_key(select.del_cond().mod_key());
    std::string errmsg;
    iRet = Delete(selectSql, errmsg);
    if (iRet != 0) {
        select_res.mutable_del_opres()->set_zdb_errmsg(errmsg);
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::DeleteObj(const storesvr_sqldata::storesvr_delobj &select,
                              storesvr_sqldata::storesvr_delobj_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_del_opres()->set_mod_key(select.mod_key());
    std::string errmsg;
    iRet = Delete(select.baseinfo().tbname(), keyMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_del_opres()->set_zdb_errmsg(errmsg);
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_delobj &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.del_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, true, true);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_mod &select, std::string &selectSql)
{
    if (select.has_mod_cond()) {
        selectSql = " ";
        const ::storesvr_sqldata::storesvr_wherecond &whereCond = select.mod_cond();
        for (int i = 0; i < whereCond.where_conds_size(); i++) {
            std::string sql;
            const ::storesvr_sqldata::storesvr_vk &vk = whereCond.where_conds(i);
            if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_EQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATER) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESS) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATEREQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESSEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_NOTEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "!='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "!=" + vk.column_value();
                }
            }

            if (sql.size() > 0 && i < whereCond.where_conds_size() - 1) {
                if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_AND) {
                    sql += " and ";
                } else if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_OR) {
                    sql += " or ";
                }
            }

            if (sql.size() > 0) {
                selectSql += sql;
            }
        }

        if (whereCond.where_additional_conds().size() > 0) {
            selectSql += " " + whereCond.where_additional_conds();
        }
    }

    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_modins &select, std::string &selectSql)
{
    if (select.has_mod_cond()) {
        selectSql = " ";
        const ::storesvr_sqldata::storesvr_wherecond &whereCond = select.mod_cond();
        for (int i = 0; i < whereCond.where_conds_size(); i++) {
            std::string sql;
            const ::storesvr_sqldata::storesvr_vk &vk = whereCond.where_conds(i);
            if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_EQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATER) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESS) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATEREQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESSEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_NOTEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "!='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "!=" + vk.column_value();
                }
            }

            if (sql.size() > 0 && i < whereCond.where_conds_size() - 1) {
                if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_AND) {
                    sql += " and ";
                } else if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_OR) {
                    sql += " or ";
                }
            }

            if (sql.size() > 0) {
                selectSql += sql;
            }
        }

        if (whereCond.where_additional_conds().size() > 0) {
            selectSql += " " + whereCond.where_additional_conds();
        }
    }

    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_del &select, std::string &selectSql) {
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    if (select.has_del_cond()) {
        selectSql = "delete from " + tableName + " where ";
        const ::storesvr_sqldata::storesvr_wherecond &whereCond = select.del_cond();
        for (int i = 0; i < whereCond.where_conds_size(); i++) {
            std::string sql;
            const ::storesvr_sqldata::storesvr_vk &vk = whereCond.where_conds(i);
            if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_EQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATER) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESS) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATEREQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESSEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_NOTEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "!='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "!=" + vk.column_value();
                }
            }

            if (sql.size() > 0 && i < whereCond.where_conds_size() - 1) {
                if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_AND) {
                    sql += " and ";
                } else if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_OR) {
                    sql += " or ";
                }
            }

            if (sql.size() > 0) {
                selectSql += sql;
            }
        }

        if (whereCond.where_additional_conds().size() > 0) {
            selectSql += " " + whereCond.where_additional_conds();
        }
    }

    return 0;
}

int
NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_selobj &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.sel_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, true, false);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_sel &select, std::string &selectSql) {
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    if (!select.has_sel_cond()) {
        selectSql = "select * from " + tableName;
    } else {
        selectSql = "select * from " + tableName;

        const ::storesvr_sqldata::storesvr_wherecond &whereCond = select.sel_cond();
        if (whereCond.where_conds_size() > 0)
        {
            selectSql += " where ";
        }
        for (int i = 0; i < whereCond.where_conds_size(); i++) {
            std::string sql;
            const ::storesvr_sqldata::storesvr_vk &vk = whereCond.where_conds(i);
            if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_EQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATER) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESS) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<'" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_GREATEREQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + ">='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + ">=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_LESSEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "<='" + vk.column_value() + "'";
                } else {
                    sql += vk.column_name() + "<=" + vk.column_value();
                }
            } else if (vk.cmp_operator() == ::storesvr_sqldata::E_CMPOP_NOTEQUAL) {
                if (vk.column_type() == ::storesvr_sqldata::E_COLUMNTYPE_STRING) {
                    sql += vk.column_name() + "!='" + vk.column_value() + "'";
                } else
				{
					sql += vk.column_name() + "!=" + vk.column_value();
				}
			}

			if (sql.size() > 0 && i < whereCond.where_conds_size() -1)
			{
				if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_AND)
				{
					sql += " and ";
				}
				else if (vk.logic_operator() == ::storesvr_sqldata::E_LOGICOP_OR)
				{
					sql += " or ";
				}
			}

			if (sql.size() > 0)
			{
				selectSql += sql;
			}
		}

		if (whereCond.where_additional_conds().size() > 0)
		{
			selectSql += " " + whereCond.where_additional_conds();
		}
	}

	return 0;
}

mysqlpp::Connection* NFCMysqlDriver::GetConnection()
{
	return m_pMysqlConnect;
}

void NFCMysqlDriver::CloseConnection()
{
    if (m_pMysqlConnect)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CloseConnection dbName:{} dbHost:{} dbPort:{}", mstrDBName, mstrDBHost, mnDBPort);
        delete m_pMysqlConnect;
        m_pMysqlConnect = nullptr;
    }
}

bool NFCMysqlDriver::Enable()
{
	return !IsNeedReconnect();
}

bool NFCMysqlDriver::CanReconnect()
{
	mfCheckReconnect += 0.1f;

	//30检查断线重连
	if (mfCheckReconnect < mnReconnectTime)
	{
		return false;
	}

	if (mnReconnectCount == 0)
	{
		return false;
	}

	mfCheckReconnect = 0.0f;

	return true;
}

int NFCMysqlDriver::Reconnect()
{
	CloseConnection();
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Start Reconnect nServerID:{}, strIP:{}, nPort{}, strDBName:{}, strDBUser:{}, strDBPwd:{}",
              mstrDBName, mstrDBHost, mnDBPort, mstrDBName, mstrDBUser, mstrDBPwd);
    int iRet = Connect(mstrDBName, mstrDBHost, mnDBPort, mstrDBUser, mstrDBPwd);
	if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                  "Reconnect Failed!:nServerID:{}, strIP:{}, nPort{}, strDBName:{}, strDBUser:{}, strDBPwd:{}",
                   mstrDBName, mstrDBHost, mnDBPort, mstrDBName, mstrDBUser, mstrDBPwd);
    }
	else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0,
                   "Reconnect Success!:nServerID:{}, strIP:{}, nPort{}, strDBName:{}, strDBUser:{}, strDBPwd:{}",
                   mstrDBName, mstrDBHost, mnDBPort, mstrDBName, mstrDBUser, mstrDBPwd);
    }

	if (mnReconnectCount > 0)
	{
		mnReconnectCount--;
	}

	return 0;
}

bool NFCMysqlDriver::IsNeedReconnect()
{
	//没有配置表
	if (mstrDBHost.length() < 1 || mstrDBUser.length() < 1)
	{
		return false;
	}

	if (nullptr == m_pMysqlConnect)
	{
		return true;
	}

	if (!m_pMysqlConnect->connected())
	{
		CloseConnection();
		return true;
	}

	if (!m_pMysqlConnect->ping())
	{
		CloseConnection();
		return true;
	}

	return false;
}

int NFCMysqlDriver::Connect() {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    m_pMysqlConnect = new mysqlpp::Connection();
    if (nullptr == m_pMysqlConnect) {
        return -1;
    }
    std::string errormsg;
    NFMYSQLTRYBEGIN
        m_pMysqlConnect->set_option(new mysqlpp::MultiStatementsOption(true));
        m_pMysqlConnect->set_option(new mysqlpp::SetCharsetNameOption("utf8mb4"));
        m_pMysqlConnect->set_option(new mysqlpp::ReconnectOption(true));
        m_pMysqlConnect->set_option(new mysqlpp::ConnectTimeoutOption(60));
        m_pMysqlConnect->set_option(new mysqlpp::ReadTimeoutOption(1));

        {
            //m_pMysqlConnect在调用Connect会引发多线程的崩溃，必须枷锁
            NFLock lock(ConnectLock);
            if (!m_pMysqlConnect->connect(mstrDBName.c_str(), mstrDBHost.c_str(), mstrDBUser.c_str(), mstrDBPwd.c_str(),
                                          mnDBPort)) {
                CloseConnection();
                // 连接失败
                return -1;
            }
        }

        // 设置超时时间为24小时
        mysqlpp::Query query = m_pMysqlConnect->query("set interactive_timeout = 24*3600");
        query.execute();
        query.reset();
    NFMYSQLTRYEND("Connect faild")
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Update(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                           const std::map<std::string, std::string> &keyvalueMap,
                           std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }

    bool bExist = false;
    if (Exists(strTableName, keyMap, bExist) != 0) {
        return -1;
    }

    int iRet = 0;
    if (bExist) {
        iRet = Modify(strTableName, keyMap, keyvalueMap, errormsg);
    } else {
        std::map<std::string, std::string> insertMap = keyvalueMap;
        for(auto iter = keyMap.begin(); iter != keyMap.end(); iter++)
        {
            insertMap.emplace(iter->first, iter->second);
        }
        iRet = Insert(strTableName, insertMap, errormsg);
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return iRet;
}

int NFCMysqlDriver::Modify(const std::string &strTableName, const std::string& where,
           const std::map<std::string, std::string> &keyvalueMap, std::string &errormsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }

    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        // update
        query << "UPDATE " << strTableName << " SET ";
        int i = 0;
        for (auto iter = keyvalueMap.begin(); iter != keyvalueMap.end(); ++iter) {
            if (i == 0) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << "," << iter->first << " = " << mysqlpp::quote << iter->second;
            }
            i++;
        }

        if (!where.empty())
        {
            query << " WHERE " << where;
        }
        query << ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        query.execute();
        query.reset();
    NFMYSQLTRYEND("modify error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Modify(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                           const std::map<std::string, std::string> &keyvalueMap, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }

    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        // update
        query << "UPDATE " << strTableName << " SET ";
        int i = 0;
        for (auto iter = keyvalueMap.begin(); iter != keyvalueMap.end(); ++iter) {
            if (i == 0) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << "," << iter->first << " = " << mysqlpp::quote << iter->second;
            }
            i++;
        }

        query << " WHERE ";
        i = 0;
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (i == 0) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
            i++;
        }
        query << ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        query.execute();
        query.reset();
    NFMYSQLTRYEND("modify error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Insert(const std::string &strTableName, const std::map<std::string, std::string> &keyvalueMap,
                           std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        // insert
        query << "INSERT INTO " << strTableName << "(";
        int i = 0;
        for (auto iter = keyvalueMap.begin(); iter != keyvalueMap.end(); ++iter) {
            if (i == 0) {
                query << iter->first;
            } else {
                query << ", " << iter->first;
            }
            i++;
        }

        query << ") VALUES (";
        i = 0;
        for (auto iter = keyvalueMap.begin(); iter != keyvalueMap.end(); ++iter) {
            if (i == 0) {
                query << mysqlpp::quote << iter->second;
            } else {
                query << ", " << mysqlpp::quote << iter->second;
            }
            i++;
        }

        query << ");";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        query.execute();
        query.reset();
    NFMYSQLTRYEND("error")
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::QueryOne(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                             std::map<std::string, std::string> &valueVec, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    valueVec.clear();
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "SELECT * ";

        query << " FROM " << strTableName << " WHERE ";
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (iter == keyMap.begin()) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
        }
        query << " limit 1;";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        //query.execute(); // 官网例子不需要execute
        mysqlpp::StoreQueryResult xResult = query.store();
        query.reset();

        if (xResult.empty() || !xResult) {
            return proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY;
        }

        for (size_t i = 0; i < xResult.num_rows(); ++i) {
            for (size_t j = 0; j < xResult[i].size(); j++) {
                std::string value;
                xResult[i][j].to_string(value);
                valueVec.emplace(xResult.field_name(j), value);
            }
        }
    NFMYSQLTRYEND("query error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::QueryOne(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                             const std::vector<std::string> &fieldVec,
                             std::map<std::string, std::string> &valueVec, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    valueVec.clear();
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "SELECT ";
        for (auto iter = fieldVec.begin(); iter != fieldVec.end(); ++iter) {
            if (iter == fieldVec.begin()) {
                query << *iter;
            } else {
                query << "," << *iter;
            }
        }

        query << " FROM " << strTableName << " WHERE ";
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (iter == keyMap.begin()) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
        }
        query << " limit 1;";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());

        //query.execute(); // 官网例子不需要execute
        mysqlpp::StoreQueryResult xResult = query.store();
        query.reset();

        if (xResult.empty() || !xResult) {
            return proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY;
        }

        for (size_t i = 0; i < xResult.num_rows(); ++i) {
            for (size_t j = 0; j < xResult[i].size(); j++) {
                std::string value;
                xResult[i][j].to_string(value);
                valueVec.emplace(xResult.field_name(j), value);
            }
        }
    NFMYSQLTRYEND("query error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::QueryMore(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                              const std::vector<std::string> &fieldVec,
                              std::vector<std::map<std::string, std::string>> &valueVec, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    valueVec.clear();
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "SELECT ";
        for (std::vector<std::string>::const_iterator iter = fieldVec.begin(); iter != fieldVec.end(); ++iter) {
            if (iter == fieldVec.begin()) {
                query << *iter;
            } else {
                query << "," << *iter;
            }
        }

        query << " FROM " << strTableName << " WHERE ";
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (iter == keyMap.begin()) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
        }
        query << ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());

        //query.execute(); // 官网例子不需要execute
        mysqlpp::StoreQueryResult xResult = query.store();
        query.reset();

        if (xResult.empty() || !xResult) {
            return proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY;
        }

        for (size_t i = 0; i < xResult.num_rows(); ++i) {
            valueVec.push_back(std::map<std::string, std::string>());
            std::map<std::string, std::string> &tmpVec = valueVec.back();
            for (size_t j = 0; j < xResult[i].size(); j++) {
                std::string value;
                xResult[i][j].to_string(value);
                tmpVec.emplace(xResult.field_name(j), value);
            }
        }
    NFMYSQLTRYEND("query error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Delete(const std::string &strTableName, const std::map<std::string, std::string> &keyMap, std::string &errormsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "DELETE FROM " << strTableName << " WHERE ";
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (iter == keyMap.begin()) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
        }
        query << ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        query.execute();
        query.reset();

    NFMYSQLTRYEND("delete error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Delete(const std::string &strTableName, const std::string &strKeyColName,
                           const std::string &strKey, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "DELETE FROM " << strTableName << " WHERE " << strKeyColName << " = " << mysqlpp::quote << strKey <<
              ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());

        query.execute();
        query.reset();

    NFMYSQLTRYEND("delete error")

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Delete(const std::string &sql, std::string &errormsg) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }

    std::string msg = "delete error";
    try {
        mysqlpp::Query query = pConnection->query();
        query << sql << ";";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());
        query.execute();
        query.reset();

    }
    catch (mysqlpp::BadQuery er) {
        errormsg = er.what();
        NFLogError(NF_LOG_SYSTEMLOG, 0, "BadQuery [{}] Error:{}", msg, er.what());
        return -1;
    }
    catch (const mysqlpp::BadConversion &er) {
        errormsg = er.what();
        NFLogError(NF_LOG_SYSTEMLOG, 0, "BadConversion [{}] Error:{} retrieved data size:{}, actual size:{}", msg,
                   er.what(), er.retrieved, er.actual_size);
        return -1;
    }
    catch (const mysqlpp::Exception &er) {
        errormsg = er.what();
        NFLogError(NF_LOG_SYSTEMLOG, 0, "mysqlpp::Exception [{}] Error:{}", msg, er.what());
        return -1;
    }
    catch (...) {
        errormsg = "Unknown Error";
        NFLogError(NF_LOG_SYSTEMLOG, 0, "std::exception [{}] Error:Error:Unknown", msg);
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Exists(const std::string &strTableName, const std::map<std::string, std::string> &keyMap,
                           bool &bExit) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }

    if (keyMap.empty())
    {
        bExit = false;
        return 0;
    }

    std::string errormsg;
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "SELECT 1 FROM " << strTableName << " WHERE ";
        int i = 0;
        for (auto iter = keyMap.begin(); iter != keyMap.end(); ++iter) {
            if (i == 0) {
                query << iter->first << " = " << mysqlpp::quote << iter->second;
            } else {
                query << " and " << iter->first << " = " << mysqlpp::quote << iter->second;
            }
            i++;
        }
        query << " limit 1;";

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", query.str());

        //query.execute();
        mysqlpp::StoreQueryResult result = query.store();
        query.reset();

        if (!result || result.empty()) {
            bExit = false;
            return 0;
        }

    NFMYSQLTRYEND("exist error")

    bExit = true;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::Exists(const std::string &strTableName, const std::string &strKeyColName,
                           const std::string &strKey, bool &bExit) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    mysqlpp::Connection *pConnection = GetConnection();
    if (nullptr == pConnection) {
        return -1;
    }
    std::string errormsg;
    NFMYSQLTRYBEGIN
        mysqlpp::Query query = pConnection->query();
        query << "SELECT 1 FROM " << strTableName << " WHERE " << strKeyColName << " = " << mysqlpp::quote << strKey <<
              " LIMIT 1;";

        mysqlpp::StoreQueryResult result = query.store();
        query.reset();

        if (!result || result.empty()) {
            bExit = false;
            return 0;
        }

    NFMYSQLTRYEND("exist error")

    bExit = true;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::InsertObj(const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    storesvr_sqldata::storesvr_ins select;
    select.mutable_baseinfo()->set_tbname(tbName);
    select.set_ins_record(pMessage->SerializeAsString());

    storesvr_sqldata::storesvr_ins_res select_res;
    int iRet = InsertObj(select, select_res);
    if (iRet != 0)
    {
        errMsg = select_res.ins_opres().zdb_errmsg();
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return iRet;
}

int NFCMysqlDriver::InsertObj(const storesvr_sqldata::storesvr_ins &select,
                              storesvr_sqldata::storesvr_ins_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> resultMap;
    iRet = CreateSql(select, resultMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_ins_opres()->set_mod_key(select.mod_key());
    std::string errmsg;
    iRet = Insert(select.baseinfo().tbname(), resultMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_ins_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int
NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_ins &select, std::map<std::string, std::string> &resultMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().clname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.ins_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, resultMap, false, false);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::ModifyObj(const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    storesvr_sqldata::storesvr_modobj select;
    select.mutable_baseinfo()->set_tbname(tbName);
    select.set_mod_record(pMessage->SerializeAsString());

    storesvr_sqldata::storesvr_modobj_res select_res;
    int iRet = ModifyObj(select, select_res);
    if (iRet != 0)
    {
        errMsg = select_res.mod_opres().zdb_errmsg();
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return iRet;
}

int NFCMysqlDriver::ModifyByCond(const storesvr_sqldata::storesvr_mod &select, storesvr_sqldata::storesvr_mod_res &select_res)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    std::map<std::string, std::string> keyValueMap;
    iRet = CreateSql(select, keyMap, keyValueMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    std::string where;
    CreateSql(select, where);

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_mod_opres()->set_mod_key(select.mod_cond().mod_key());
    std::string errmsg;
    iRet = Modify(select.baseinfo().tbname(), where, keyValueMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_mod_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}


int NFCMysqlDriver::ModifyObj(const storesvr_sqldata::storesvr_modobj &select,
                              storesvr_sqldata::storesvr_modobj_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    std::map<std::string, std::string> keyValueMap;
    iRet = CreateSql(select, keyMap, keyValueMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_mod_opres()->set_mod_key(select.mod_key());
    std::string errmsg;
    iRet = Modify(select.baseinfo().tbname(), keyMap, keyValueMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_mod_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_mod &select, std::map<std::string, std::string> &keyMap, std::map<std::string, std::string> &kevValueMap)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().clname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.mod_record()), -1, "ParseFromString Failed:{}", full_name);
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "CreateSql From message:{}", pMessageObject->DebugString());

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, kevValueMap, false);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_modins &select, std::map<std::string, std::string> &keyMap, std::map<std::string, std::string> &kevValueMap)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().clname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.mod_record()), -1, "ParseFromString Failed:{}", full_name);
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "CreateSql From message:{}", pMessageObject->DebugString());

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, kevValueMap, false);
    delete pMessageObject;

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_modobj &select, std::map<std::string, std::string> &keyMap,
                              std::map<std::string, std::string> &kevValueMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().clname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.mod_record()), -1, "ParseFromString Failed:{}", full_name);
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "CreateSql From message:{}", pMessageObject->DebugString());

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, kevValueMap, false);
    delete pMessageObject;

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::UpdateObj(const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pMessage, -1, "pMessage == NULL");

    storesvr_sqldata::storesvr_modinsobj select;
    select.mutable_baseinfo()->set_tbname(tbName);
    select.set_modins_record(pMessage->SerializeAsString());

    storesvr_sqldata::storesvr_modinsobj_res select_res;
    int iRet = UpdateObj(select, select_res);
    if (iRet != 0)
    {
        errMsg = select_res.modins_opres().zdb_errmsg();
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return iRet;
}

int NFCMysqlDriver::UpdateByCond(const storesvr_sqldata::storesvr_modins &select, storesvr_sqldata::storesvr_modins_res &select_res)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    std::map<std::string, std::string> keyValueMap;
    iRet = CreateSql(select, keyMap, keyValueMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    std::string where;
    CreateSql(select, where);

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_mod_opres()->set_mod_key(select.mod_cond().mod_key());
    std::string errmsg;
    iRet = Modify(select.baseinfo().tbname(), where, keyValueMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_mod_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMysqlDriver::UpdateObj(const storesvr_sqldata::storesvr_modinsobj &select,
                              storesvr_sqldata::storesvr_modinsobj_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    std::map<std::string, std::string> keyValueMap;
    iRet = CreateSql(select, keyMap, keyValueMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_modins_opres()->set_mod_key(select.mod_key());
    std::string errmsg;
    iRet = Update(select.baseinfo().tbname(), keyMap, keyValueMap, errmsg);
    if (iRet != 0) {
        select_res.mutable_modins_opres()->set_zdb_errmsg(errmsg);
        return iRet;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int
NFCMysqlDriver::CreateSql(const storesvr_sqldata::storesvr_modinsobj &select, std::map<std::string, std::string> &keyMap,
                          std::map<std::string, std::string> &kevValueMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().clname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.modins_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, kevValueMap, false);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}
