// -------------------------------------------------------------------------
//    @FileName         :    NFCDynLibMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCDynLibMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include <unordered_map>

class NFCSharedMem;
class NFCDynLibMgr : public NFSingleton<NFCDynLibMgr>
{
public:
    NFCDynLibMgr();
    virtual ~NFCDynLibMgr();
public:
    int Load();
    int Save();

    int GetLibSize(const std::string& md5);
    int AddLib(const std::string& fileMd5, int fileSize, const std::string& content);
    int AddLib(const std::string& fileMd5, int fileSize, const char* data, int length);
    int GetLib(const string &fileMd5, int fileSize, string &content);
    int DelLib(const std::string& fileMd5);
private:
    static NFCSharedMem* CreateShareMem(int iKey, size_t siSize, int enInitFlag);
    static bool ShmExist(int iKey);
    static bool ShmDestroy(int iKey);
private:
    std::string m_filePath;
    proto_ff::DynLibFileInfoArray m_fileInfoArray;
    std::unordered_map<uint32_t, NFCSharedMem*> m_sharedMemMap;
};


