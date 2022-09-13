// -------------------------------------------------------------------------
//    @FileName         :    NFShmDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#define OBJECT_MAGIC_CHECK_NUMBER 1234567890
const int INVALID_ID = -1;
const int MAX_PATH_LEN = 192;
const uint64_t ULL_MAX = 0xffffffff;

const int C_I_MAX_OBJSEG_COUNT = 255;

// 2的指数
#ifndef MAX_GLOBALID_NUM
#define MAX_GLOBALID_NUM 1048576
//#define MAX_GLOBALID_NUM 131072
#endif

//MAX_GLOBALID_NUM -1  = 1111111...
#define MAX_GLOBALID_NUM_MASK (MAX_GLOBALID_NUM-1)
#define MAX_GLOBALID_QUEUESIZE (MAX_GLOBALID_NUM+1)  //等与MAXIDNUM 的数值+1


#define BUFFSIZE 1024
#define GLOBALID_LOOP_BACK 2000

typedef enum
{
	EN_OBJ_MODE_INIT = 1,
	EN_OBJ_MODE_RECOVER = 2,
} EN_OBJ_MODE;

inline void debug_assert()
{
#if defined(_DEBUG) | defined(_DEBUG_)
	assert(0);
#endif
}

class NFShmObj;
typedef std::function<bool(NFShmObj* pObj)> DESTROY_SHM_AUTO_ERASE_FUNCTION;
