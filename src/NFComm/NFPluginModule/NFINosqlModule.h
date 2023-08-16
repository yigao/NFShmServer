
#pragma once

#include "NFINosqlDriver.h"

class NFINosqlModule
	: public NFIModule
{
public:
	NFINosqlModule(NFIPluginManager* p) : NFIModule(p)
	{

	}
public:
	virtual int AddNosqlServer(const std::string& strID, const std::string& ip) = 0;
	virtual int AddNosqlServer(const std::string& strID, const std::string& ip, const int nPort) = 0;
	virtual int AddNosqlServer(const std::string& strID, const std::string& ip, const int nPort, const std::string& strPass) = 0;
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
	virtual NFINosqlDriver* GetNosqlDriver(const std::string& strID) = 0;
};
