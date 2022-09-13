#ifndef __HW_INFO_H__
#define __HW_INFO_H__
#include <string>

#include "NFComm/NFCore/NFPlatform.h"
#if NF_PLATFORM == NF_PLATFORM_WIN
#define _WIN32_DCOM
#include <Wbemidl.h>
#include <comdef.h>

extern HRESULT hres;
extern IWbemLocator*  pLoc;
extern IWbemServices* pSvc;
#endif

bool hw_init();
bool hw_cleanup();

bool get_board_serial_number(std::string & board_serial);

bool get_cpu_id(std::string & cpu_id);

bool get_disk_id(std::string & cpu_id);

bool get_mac_address(std::string & mac_address);


#endif