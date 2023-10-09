#include "RecastConverter.h"
#include <assert.h>
#include "InputGeom.h"
#include "Sample_TileMesh.h"


int ConvertMeshToTileFile(char* srcFilePath, char* desFilePath) {
    assert(srcFilePath);
    assert(desFilePath);

    BuildContext  context;
    InputGeom* geom = new InputGeom();
    Sample_TileMesh* tileMesh = new Sample_TileMesh();

    geom->loadMesh(&context, srcFilePath);
    tileMesh->setContext(&context);
    tileMesh->handleMeshChanged(geom);
    tileMesh->handleSettings();
    tileMesh->handleBuild();
    tileMesh->saveAll(desFilePath);

    return 0;
}
