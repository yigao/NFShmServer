#pragma once

#if defined( __WIN32__ ) || defined( _WIN32 ) || defined(_WINDOWS) || defined(WIN) || defined(_WIN64) || defined( __WIN64__ )
#include "win32/sigar.h"
//////////////////////////////////////////////////////////////////////////
#else
#include "linux/sigar.h"
#endif