#ifndef RECASTNAVIGATION_MESHHEADER_DEF_H_
#define RECASTNAVIGATION_MESHHEADER_DEF_H_

static const int NAVMESHSET_MAGIC = 'M' << 24 | 'S' << 16 | 'E' << 8 | 'T'; //'MSET';
static const int NAVMESHSET_VERSION = 1;

struct NavMeshSetHeader {
    int magic;
    int version;
    int numTiles;
    dtNavMeshParams params;
};

struct NavMeshTileHeader {
    dtTileRef tileRef;
    int dataSize;
};

#endif  //#ifndef RECASTNAVIGATION_MESHHEADER_DEF_H_
