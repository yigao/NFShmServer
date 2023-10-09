#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "Detour/Include/DetourNavMesh.h"
#include "Detour/Include/DetourNavMeshQuery.h"
#include "RecastDemo/Include/MeshHeaderDef.h"
#include "Detour/Include/DetourCommon.h"

#define MMO_FREE_NAVMESH(p)    \
if (p != nullptr) {           \
    dtFreeNavMesh(p);         \
    p = nullptr;              \
}                               

#define MMO_FREE_NAVMESHQUERY(p) \
if (p != nullptr) {             \
    dtFreeNavMeshQuery(p);      \
    p = nullptr;                \
}

class NFRecastUtility
{
public:
    static int LoadNavMeshByJsonFile(const std::string& filePath, dtNavMesh** navMesh);

    static int LoadNavMeshByJsonStream(const std::string& filePath, const std::string& jsonstr, dtNavMesh** navMesh);
};