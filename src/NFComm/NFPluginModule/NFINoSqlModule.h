
#pragma once

#include "NFIRedisDriver.h"

class NFINoSqlModule
	: public NFIModule
{
public:
	NFINoSqlModule(NFIPluginManager* p) :NFIModule(p)
	{

	}
public:
	virtual int AddNoSqlServer(const std::string& strID, const std::string& ip) = 0;
	virtual int AddNoSqlServer(const std::string& strID, const std::string& ip, const int nPort) = 0;
	virtual int AddNoSqlServer(const std::string& strID, const std::string& ip, const int nPort, const std::string& strPass) = 0;
public:
    virtual int SelectObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select, storesvr_sqldata::storesvr_selobj_res &select_res) = 0;
    virtual int SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select,
                        storesvr_sqldata::storesvr_selobj_res &select_res) = 0;
    virtual int SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select) = 0;
    virtual int SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select) = 0;
    virtual int SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_updateobj &select) = 0;

    virtual int DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_delobj &select) = 0;
    virtual int DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select) = 0;
    virtual int DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select) = 0;
public:
	virtual NFIRedisDriver* GetNosqlDriver(const std::string& strID) = 0;
};
