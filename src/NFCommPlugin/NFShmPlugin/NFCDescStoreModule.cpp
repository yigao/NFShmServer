// -------------------------------------------------------------------------
//    @FileName         :    NFCDescStoreModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCDescStoreModule
//
// -------------------------------------------------------------------------

#include "NFCDescStoreModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFCommPlugin/NFKernelPlugin/NFResFileDb.h"
#include "NFComm/NFPluginModule/NFIMysqlModule.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFCommPlugin/NFKernelPlugin/NFResMysqlDb.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"


NFCDescStoreModule::NFCDescStoreModule(NFIPluginManager *p) : NFIDescStoreModule(p) {
    m_pResFileDB = NULL;
    m_pResSqlDB = NULL;
    m_bStartInit = false;
    m_bFinishAllLoaded = false;
}

NFCDescStoreModule::~NFCDescStoreModule() {
    if (m_pResFileDB) {
        NF_SAFE_DELETE(m_pResFileDB);
    }
    if (m_pResSqlDB) {
        NF_SAFE_DELETE(m_pResSqlDB);
    }
}

bool NFCDescStoreModule::Awake() {
    m_pPluginManager->RegisterAppTask(NF_ST_NONE, APP_INIT_DESC_STORE_LOAD, "Load Desc Store", APP_INIT_STATUS_SERVER_LOAD_DESC_STORE);
    Subscribe(proto_ff::NF_EVENT_SERVER_APP_TASK_FINISH, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    return true;
}

int NFCDescStoreModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_APP_TASK_FINISH)
        {
            LoadDestSotre();
        }
    }
    return 0;
}

bool NFCDescStoreModule::Execute() {
    if (m_bStartInit && m_bFinishAllLoaded == false)
    {
        if (IsAllDescStoreLoad())
        {
            m_pPluginManager->FinishAppTask(NF_ST_NONE, APP_INIT_DESC_STORE_LOAD, APP_INIT_STATUS_SERVER_LOAD_DESC_STORE);

            m_bFinishAllLoaded = true;
        }
    }

    return true;
}

bool NFCDescStoreModule::OnReloadPlugin() {
    Reload();
    return true;
}

int NFCDescStoreModule::InitDestStoreDB(const std::string &serverId, const std::string &hostip, int port, const std::string &dbname, const std::string &user,
                                        const std::string &pass) {
	NFIAsyMysqlModule *pAsyMysqlModule = NFIPluginManager::Instance()->FindModule<NFIAsyMysqlModule>();
	CHECK_EXPR(pAsyMysqlModule, -1, "NFIPluginManager::Instance()->FindModule<NFIAsyMysqlModule>() == NULL");
	
	int iRet = pAsyMysqlModule->AddMysqlServer(serverId, hostip, port, dbname, user, pass);
	CHECK_EXPR(iRet == 0, -1, "pAsyMysqlModule->AddMysqlServer(serverId:{}, hostip:{}, port:{}, dbname:{}, user:{}, pass:{}) Failed!", serverId, hostip, port, dbname, user, pass);
    return 0;
}

int NFCDescStoreModule::Initialize() {
    m_pResFileDB = CreateResDBFromFiles(m_pPluginManager->GetConfigPath() + "/Data");
    m_pResSqlDB = CreateResDBFromRealDB();

    InitAllDescStore();

    return 0;
}

int NFCDescStoreModule::LoadDestSotre() {
    if (m_bStartInit) return 0;

    int iRet = -1;
    if (NFShmMgr::Instance()->GetInitMode() == EN_OBJ_MODE_INIT) {
        int iRet = Load();
        NF_ASSERT_MSG(iRet == 0, "Load Desc Store Failed!");
    } else {
        iRet = ExtraInitializeWhenRecover();
    }

    m_bStartInit = true;
    return iRet;
}

void NFCDescStoreModule::InitAllDescStore()
{
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
	for (auto iter = mDescStoreRegister.begin(); iter != mDescStoreRegister.end(); iter++)
	{
		NFIDescStore* pDescStore = dynamic_cast<NFIDescStore*>(NFShmMgr::Instance()->GetHeadObj(iter->second));
		CHECK_EXPR_CONTINUE(pDescStore, "can' get NFIDescStore:{} ptr from shm", iter->first);

		int iRet = InitDescStore(iter->first, pDescStore);
		CHECK_EXPR_CONTINUE(iRet == 0, "InitDescStore:{} Failed!", iter->first);

		NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "Init Desc Store:{} Success", iter->first);
	}
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
}

bool NFCDescStoreModule::IsAllDescStoreLoad()
{
	for (auto iter = mDescStoreMap.begin(); iter != mDescStoreMap.end(); iter++) {
		NFIDescStore *pDescStore = iter->second;
		if (!pDescStore->IsLoaded())
		{
			return false;
		}
	}
	return true;
}

int NFCDescStoreModule::InitDescStore(const std::string& descClass, NFIDescStore* pDescStore)
{
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(pDescStore, -1, "pDescStore = NULL");

	pDescStore->SetValid();
	AddDescStore(descClass, pDescStore);

	if (NFShmMgr::Instance()->GetInitMode() == EN_OBJ_MODE_INIT)
	{
		int iRet = pDescStore->Initialize();
		assert(iRet == 0);
	}
	else
	{
		int iRet = pDescStore->Resume();
		assert(iRet == 0);
	}

	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCDescStoreModule::ExtraInitializeWhenRecover()
{
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
    //Reload(m_pResDB);

	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCDescStoreModule::LoadDescStore(NFIDescStore *pDescStore)
{
	CHECK_NULL(pDescStore);

	int iRet = 0;
	std::string filePathName = pDescStore->GetFilePathName();
	if (filePathName.empty())
	{
		filePathName = m_pPluginManager->GetConfigPath() + "/Data/" + pDescStore->GetFileName() + ".bin";
		pDescStore->SetFilePathName(filePathName);
	}

	if (pDescStore->IsFileLoad())
	{
		iRet = pDescStore->Load(m_pResFileDB);
		CHECK_EXPR(iRet == 0, iRet, "Desc Store:{} Load Failed!", pDescStore->GetFileName());
	}
	else {
        iRet = pDescStore->Load(m_pResSqlDB);
        CHECK_EXPR(iRet == 0, iRet, "Desc Store:{} Load Failed!", pDescStore->GetFileName());
	}

	pDescStore->SetLoaded(true);
	pDescStore->SetChecked(false);

	if (pDescStore->IsFileLoad())
	{
		std::string fileMd5;
		iRet = GetFileContainMD5(pDescStore->GetFilePathName(), fileMd5);
		CHECK_EXPR(iRet == 0, iRet, "GetFileContainMD5 Failed, file:{}.bin", pDescStore->GetFileName());

		pDescStore->SetMD5(fileMd5.c_str());
		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store End Load:{}, iRet={}, fileMd5:{}", pDescStore->GetFileName(), iRet, fileMd5);
#if NF_PLATFORM != NF_PLATFORM_WIN
#ifndef NF_DEBUG_MODE
		//NFFileUtility::Remove(pDescStore->GetFilePathName());
#endif
#endif
	}
	else
    {
	    pDescStore->StartSaveTimer();
    }

	return 0;
}

int NFCDescStoreModule::Load() {
    NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");

    for (auto iter = mDescStoreMap.begin(); iter != mDescStoreMap.end(); iter++) {
        NFIDescStore *pDescStore = iter->second;
        assert(pDescStore);
        NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Begin Load:{}", pDescStore->GetFileName());

		NFCoMgr::Instance()->MakeCoroutine([pDescStore, this] {
			int ret = LoadDescStore(pDescStore);
			NF_ASSERT_MSG(ret == 0, "Load Desc Store:" + pDescStore->GetFileName() + " Failed!");
            NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Load:{} Sucess", pDescStore->GetFileName());
		});
    }
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCDescStoreModule::ReLoadDescStore(NFIDescStore *pDescStore)
{
	CHECK_NULL(pDescStore);

	int iRet = 0;
	if (pDescStore->IsFileLoad())
	{
	    if (!NFFileUtility::IsFileExist(pDescStore->GetFilePathName())) {
            return 0;
        }

		std::string fileMd5;
		iRet = GetFileContainMD5(pDescStore->GetFilePathName(), fileMd5);
		if (iRet == 0 && fileMd5 == std::string(pDescStore->GetFileMD5())) {
			return 0;
		}

		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "File {}.bin Changed, Reload.", pDescStore->GetFileName());
		iRet = pDescStore->Reload(m_pResFileDB);
		CHECK_EXPR(iRet == 0, iRet, "Desc Store Reload table:{} error", pDescStore->GetFileName());

		pDescStore->SetLoaded(true);
		pDescStore->SetChecked(false);

		if (fileMd5.size() > 0) {
			pDescStore->SetMD5(fileMd5.c_str());
		}
	}
	else {
        NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "db table:{} Changed, Reload.", pDescStore->GetFileName());
        iRet = pDescStore->Reload(m_pResSqlDB);
        CHECK_EXPR(iRet == 0, iRet, "Desc Store:{} Reload Failed!", pDescStore->GetFileName());

        pDescStore->SetLoaded(true);
        pDescStore->SetChecked(false);
	}

	NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store End Reload:{}", pDescStore->GetFileName());
	return 0;
}

int NFCDescStoreModule::Reload() {
    NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
//    int iRet = 0;
    for (auto iter = mDescStoreMap.begin(); iter != mDescStoreMap.end(); iter++) {
        NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Begin Reload:{}", iter->first);
        NFIDescStore *pDescStore = iter->second;
        assert(pDescStore);

		NFCoMgr::Instance()->MakeCoroutine([pDescStore, this] {
			int ret = ReLoadDescStore(pDescStore);
			NF_ASSERT_MSG(ret == 0, "ReLoad Desc Store Failed!");
		});
    }

// 	for (auto iter = mDescStoreMap.begin(); iter != mDescStoreMap.end(); iter++)
// 	{
// 		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Begin CheckWhenAllDataLoaded:{}", iter->first);
// 		NFIDescStore* pDescStore = iter->second;
// 		assert(pDescStore);
//
// 		if ((pDescStore->IsLoaded() && !pDescStore->IsChecked()) || pDescStore->IsNeedSpecialCheck())
// 		{
//
// 			NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Need Check:{}", iter->first);
// 			iRet = pDescStore->CheckWhenAllDataLoaded();
// 			CHECK_EXPR(iRet == 0, iRet, "CheckWhenAllDataLoaded Failed:{}", iter->first);
// 			pDescStore->SetChecked(true);
// 		}
//
// 		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store End CheckWhenAllDataLoaded:{}", iter->first);
// 	}
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCDescStoreModule::CheckWhenAllDataLoaded()
{
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");

	int iRet = 0;
	for (auto iter = mDescStoreMap.begin(); iter != mDescStoreMap.end(); iter++)
	{
		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store Begin CheckWhenAllDataLoaded:{}", iter->first);
		NFIDescStore* pDescStore = iter->second;
		assert(pDescStore);
		iRet = pDescStore->CheckWhenAllDataLoaded();

		CHECK_EXPR(iRet == 0, iRet, "Desc Store:{} CheckWhenAllDataLoaded Failed!", iter->first);

		pDescStore->SetChecked(true);
		NFLogInfo(NF_LOG_KERNEL_PLUGIN, 0, "Desc Store End CheckWhenAllDataLoaded:{}", iter->first);
	}
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCDescStoreModule::GetFileContainMD5(const std::string& strFileName, std::string& fileMd5)
{
	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
	
	bool exist = NFFileUtility::IsFileExist(strFileName);
	CHECK_EXPR(exist, -1, "strFileName:{} not exist", strFileName);

	fileMd5 = NFMD5::md5file(strFileName);

	NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
	return 0;
}

void NFCDescStoreModule::RegisterDescStore(const std::string& strDescName, int objType, const std::string& dbName)
{
	mDescStoreRegister.insert(std::make_pair(strDescName, objType));
    mDescStoreDBNameMap.insert(std::make_pair(strDescName, dbName));
}

void NFCDescStoreModule::AddDescStore(const std::string& strDescName, NFIDescStore* pDesc)
{
	mDescStoreMap.insert(std::make_pair(strDescName, pDesc));
    mDescStoreFileMap.insert(std::make_pair(pDesc->GetFileName(), pDesc));
    auto it = mDescStoreDBNameMap.find(strDescName);
    if (it != mDescStoreDBNameMap.end())
    {
        pDesc->SetDBName(it->second);
    }
}

int NFCDescStoreModule::SaveDescStoreByFileName(const std::string& dbName, const std::string& strDescFileName, const google::protobuf::Message *pMessage)
{
    NFIDescStore* pDescStore = FindDescStoreByFileName(strDescFileName);
    CHECK_EXPR(pDescStore, -1, "FindDescStoreByFileName(strDescName) Failed! strDescName:{}", strDescFileName);
    if (pDescStore->IsFileLoad() == false)
    {
        NFResTable* pResTable = m_pResSqlDB->GetTable(pDescStore->GetFileName());
        CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", pDescStore->GetFileName());

        int iRet = pResTable->SaveOneRecord(pDescStore->GetDBName(), pMessage);
        CHECK_EXPR(iRet == 0, -1, "pResTable->SaveDescStore Failed!");
        return 0;
    }
    return 0;
}

int NFCDescStoreModule::InsertDescStoreByFileName(const std::string& dbName, const std::string& strDescFileName, const google::protobuf::Message *pMessage)
{
    NFIDescStore* pDescStore = FindDescStoreByFileName(strDescFileName);
    CHECK_EXPR(pDescStore, -1, "FindDescStoreByFileName(strDescName) Failed! strDescName:{}", strDescFileName);
    if (pDescStore->IsFileLoad() == false)
    {
        NFResTable* pResTable = m_pResSqlDB->GetTable(pDescStore->GetFileName());
        CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", pDescStore->GetFileName());

        int iRet = pResTable->InsertOneRecord(pDescStore->GetDBName(), pMessage);
        CHECK_EXPR(iRet == 0, -1, "pResTable->SaveDescStore Failed!");
        return 0;
    }
    return 0;
}

int NFCDescStoreModule::DeleteDescStoreByFileName(const std::string& dbName, const std::string& strDescFileName, const google::protobuf::Message *pMessage)
{
    NFIDescStore* pDescStore = FindDescStoreByFileName(strDescFileName);
    CHECK_EXPR(pDescStore, -1, "FindDescStoreByFileName(strDescName) Failed! strDescName:{}", strDescFileName);
    if (pDescStore->IsFileLoad() == false)
    {
        NFResTable* pResTable = m_pResSqlDB->GetTable(pDescStore->GetFileName());
        CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", pDescStore->GetFileName());

        int iRet = pResTable->DeleteOneRecord(pDescStore->GetDBName(), pMessage);
        CHECK_EXPR(iRet == 0, -1, "pResTable->SaveDescStore Failed!");
        return 0;
    }
    return 0;
}

void NFCDescStoreModule::RemoveDescStore(const std::string& strDescName)
{
	auto iter = mDescStoreMap.find(strDescName);
	if (iter != mDescStoreMap.end())
	{
		mDescStoreMap.erase(strDescName);
	}
}

NFIDescStore* NFCDescStoreModule::FindDescStoreByFileName(const std::string& strDescName)
{
    auto it = mDescStoreFileMap.find(strDescName);
    if (it != mDescStoreFileMap.end()) {
        return it->second;
    }

    return nullptr;
}

NFIDescStore* NFCDescStoreModule::FindDescStore(const std::string& strDescName)
{
	std::string strSubDescName = strDescName;

#if NF_PLATFORM == NF_PLATFORM_WIN
	std::size_t position = strSubDescName.find(' ');
	if (string::npos != position)
	{
		strSubDescName = strSubDescName.substr(position + 1, strSubDescName.length());
	}
#else
	for (int i = 0; i < (int)strSubDescName.length(); i++)
	{
        std::string s = strSubDescName.substr(0, i + 1);
        int n = atof(s.c_str());
        if ((int) strSubDescName.length() == i + 1 + n) {
            strSubDescName = strSubDescName.substr(i + 1, strSubDescName.length());
            break;
        }
    }
#endif

    auto it = mDescStoreMap.find(strSubDescName);
    if (it != mDescStoreMap.end()) {
        return it->second;
    }

    return nullptr;
}

NFResDB *
NFCDescStoreModule::CreateResDBFromRealDB() {
    return new NFResMysqlDB();
}

NFResDB *NFCDescStoreModule::CreateResDBFromFiles(const std::string &dir) {
    return new NFFileResDB(dir);
}


