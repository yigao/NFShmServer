// -------------------------------------------------------------------------
//    @FileName         :    NFFishTrace.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishTrace.h
//
// -------------------------------------------------------------------------

#pragma once

#include <vector>
#include "NFComm/NFShmCore/NFShmMgr.h"

#ifdef _WIN32
#pragma pack(push,1)
#else
#pragma pack(1)
#endif

struct TRACEHEADER {
    TRACEHEADER()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        sPointCount = 0;
        sTime = 0;
        byType = 0;
        iCenterX = 0;
        iCenterY = 0;
        uTraceId = 0;
        memset(byReserved, 0, sizeof(byReserved));
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    unsigned short sPointCount;
    unsigned short sTime;
    unsigned char byType;
    signed int iCenterX;
    signed int iCenterY;
    unsigned int uTraceId;
    unsigned char byReserved[15];
};

struct HMPOINT {
    HMPOINT()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        iPosX = 0;
        iPosY = 0;
        iDirX = 0;
        iDirY = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
    signed int iPosX;//INT32
    signed int iPosY;//INT32
    signed int iDirX;//INT32
    signed int iDirY;//INT32
};


#ifdef _WIN32
#pragma pack(pop)
#else
#pragma pack()
#endif


