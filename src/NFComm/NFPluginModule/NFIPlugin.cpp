// -------------------------------------------------------------------------
//    @FileName         :    NFIPlugin.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFIPlugin
//
// -------------------------------------------------------------------------

#include "NFIPlugin.h"
#include "NFLogMgr.h"

bool NFIPlugin::AfterLoadAllPlugin()
{
    for (size_t i = 0; i < m_vecModule.size(); i++)
    {
        NFIModule* pModule = m_vecModule[i];
        if (pModule)
        {
            bool bRet = pModule->AfterLoadAllPlugin();
            if (!bRet)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{} AfterLoadAllPlugin failed!", pModule->m_strName);
                assert(0);
            }
        }
    }
    return true;
}

bool NFIPlugin::AfterInitShmMem()
{
    for (size_t i = 0; i < m_vecModule.size(); i++)
    {
        NFIModule* pModule = m_vecModule[i];
        if (pModule)
        {
            bool bRet = pModule->AfterInitShmMem();
            if (!bRet)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{} AfterInitShmMem failed!", pModule->m_strName);
                assert(0);
            }
        }
    }
    return true;
}

bool NFIPlugin::Awake()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->Awake();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} Awake failed!", pModule->m_strName);
				assert(0);
			}
		}
	}
	return true;
}

bool NFIPlugin::Init()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->Init();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} Init failed!", pModule->m_strName);
				assert(0);
			}
		}
	}
	return true;
}

bool NFIPlugin::CheckConfig()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->CheckConfig();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} CheckConfig failed!", pModule->m_strName);
				assert(0);
			}
		}
	}

	return true;
}

bool NFIPlugin::ReadyExecute()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->ReadyExecute();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} ReadyExecute failed!", pModule->m_strName);
				assert(0);
			}
		}
	}

	return true;
}

bool NFIPlugin::Execute()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->Execute();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} Execute failed!", pModule->m_strName);
			}
		}
	}

	return true;
}

bool NFIPlugin::BeforeShut()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "{} BeforeShut................", pModule->m_strName);
			bool bRet = pModule->BeforeShut();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} BeforeShut failed!", pModule->m_strName);
			}
		}
	}
	return true;
}

bool NFIPlugin::Shut()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "{} Shut................", pModule->m_strName);
			bool bRet = pModule->Shut();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} Shut failed!", pModule->m_strName);
			}
		}
	}

	return true;
}

bool NFIPlugin::Finalize()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "{} Finalize................", pModule->m_strName);
			bool bRet = pModule->Finalize();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} Finalize failed!", pModule->m_strName);
			}
		}
	}

	return true;
}

bool NFIPlugin::OnReloadConfig()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->OnReloadConfig();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} OnReloadConfig failed!", pModule->m_strName);
			}
		}
	}

	return true;
}

bool NFIPlugin::AfterOnReloadConfig()
{
    for (size_t i = 0; i < m_vecModule.size(); i++)
    {
        NFIModule* pModule = m_vecModule[i];
        if (pModule)
        {
            bool bRet = pModule->AfterOnReloadConfig();
            if (!bRet)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{} AfterOnReloadConfig failed!", pModule->m_strName);
            }
        }
    }

    return true;
}

bool NFIPlugin::InitShmObjectRegister()
{
	return true;
}

void NFIPlugin::AddModule(const std::string& moduleName, NFIModule* pModule)
{
	if (m_mapModule.find(moduleName) != m_mapModule.end())
	{
		NF_ASSERT_MSG(false, moduleName + " Has Registerd! Exit!");
		exit(0);
	}

	m_mapModule.emplace(moduleName, pModule);
	m_vecModule.push_back(pModule);
}

void NFIPlugin::RemoveModule(const std::string& moduleName)
{
	auto it = m_mapModule.find(moduleName);
	if (it != m_mapModule.end())
	{
		for (auto vecIt = m_vecModule.begin(); vecIt != m_vecModule.end(); ++vecIt)
		{
			if (*vecIt == it->second)
			{
				m_vecModule.erase(vecIt);
				break;
			}
		}
		m_mapModule.erase(it);
	}
}

bool NFIPlugin::IsDynamicLoad()
{
	return true;
}

bool NFIPlugin::OnDynamicPlugin()
{
	for (size_t i = 0; i < m_vecModule.size(); i++)
	{
		NFIModule* pModule = m_vecModule[i];
		if (pModule)
		{
			bool bRet = pModule->OnDynamicPlugin();
			if (!bRet)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "{} OnDynamicPlugin failed!", pModule->m_strName);
			}
		}
	}

	return true;
}
