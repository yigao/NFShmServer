// -------------------------------------------------------------------------
//    @FileName         :    NFTypeDefines.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFPlatform.h"

typedef enum
{
	EOT_OBJECT = 0,//0-100的是基础引擎共享内存ID
	EOT_GLOBAL_ID = 1, //位置不可修改
    EOT_TYPE_TIMER_OBJ = 2, //位置不可修改
    EOT_TYPE_TIMER_MNG = 3, //位置不可修改
    EOT_TRANS_BASE = 4,
    EOT_TRANS_MNG = 5,
    EOT_BASE_DB_OBJ = 6,
    EOT_TRANS_DB_OBJ = 7,
    EOT_TRANS_DB_OBJ_MGR = 8,
    EOT_RPC_TRANS_ID = 9,

	EOT_SERVER_FRAME_BEGIN_ID = 100,//100-199的是服务器架构共享内存ID
	EOT_SERVER_FRAME_END_ID = 299,

	EOT_SUB_GAME_BEGIN_ID = 300, //200-499的是子游戏共享内存ID
	EOT_SUB_GAME_END_ID = 499,

	EOT_MAX_TYPE = 500,
} EN_SHMOBJ_TYPE;

#define REGISTER_SHM_OBJ( ClassName, ClassType, ObjNum ) do{\
        ClassName::SetObjSeg(ClassType, sizeof(ClassName), (ObjNum), std::string(#ClassName), false, 0, 0);\
    }while(0)

#define REGISTER_SINGLETON_SHM_OBJ( ClassName, ClassType, ObjNum ) do{\
        ClassName::SetObjSeg(ClassType, sizeof(ClassName), (ObjNum), std::string(#ClassName), false, 0, 0, true);\
    }while(0)

#define REGISTER_SHM_OBJ_WITH_HASH( ClassName, ClassType, ObjNum ) do{\
        ClassName::SetObjSeg(ClassType, sizeof(ClassName), (ObjNum), std::string(#ClassName), true, 0, 0);\
    }while(0)

#define REGISTER_SHM_OBJ_WITH_EXTERNAL_DATA( ClassName, ClassType, ObjNum, externalObjNum ) do{\
        ClassName::SetObjSeg(ClassType, sizeof(ClassName), (ObjNum), std::string(#ClassName), false, ClassName::GetExternalDataSize(externalObjNum), externalObjNum, true);\
    }while(0)

