#include "NFRecastUtility.h"
#include "NFComm/NFCore/NFFileUtility.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324) //structure was padded due to __declspec(align())
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4005)
#endif
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/error/en.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#ifdef _MSC_VER
#pragma warning(pop)
#endif

int NFRecastUtility::LoadNavMeshByJsonFile(const std::string& filePath, dtNavMesh** navMesh)
{
    NF_ASSERT(!filePath.empty());
    NF_ASSERT(navMesh != nullptr);

    bool result = false;
    int retCode = 0;

    std::string fileContent;
    result = NFFileUtility::ReadFileContent(filePath, fileContent);
    CHECK_EXPR(result, -1, "ReadFileContent Failed, filePath:{}", filePath);

	retCode = NFRecastUtility::LoadNavMeshByJsonStream(filePath, fileContent, navMesh);
    CHECK_RET(retCode, "ReadFileContent Failed, filePath:{}", filePath);

    return 0;
}

int NFRecastUtility::LoadNavMeshByJsonStream(const std::string& filePath, const std::string& jsonstr, dtNavMesh** navMesh)
{
    bool result = false;

    dtNavMesh* mesh = nullptr;
    NavMeshSetHeader header;
    char tileBuff[1024 * 200];
    unsigned char* tileData = nullptr;
    size_t tileLength = 0;
    dtStatus status;

    rapidjson::Document jsonBase;
    jsonBase.Parse(jsonstr.c_str());
	if (jsonBase.HasParseError())
	{
        NFLogError(NF_LOG_SYSTEMLOG, 0, "g_LoadNavMeshByJsonFile failed....path:{}, parse error: ({}:{}){}\n",
                   filePath, jsonBase.GetParseError(), jsonBase.GetErrorOffset(), rapidjson::GetParseError_En(jsonBase.GetParseError()));
		return -1;
	}
    
   // MMOLOG_PROCESS_ERROR(!jsonBase.IsNull());

    // navmesh header
    {
        rapidjson::Value& headerParam = jsonBase["Param"];
        header.magic             = NAVMESHSET_MAGIC;
        header.version           = NAVMESHSET_VERSION;
        header.numTiles          = jsonBase["NavMeshBuilders"].Size();

        rapidjson::Value& jsonOrig = headerParam["Orig"];
        header.params.orig[0]    = jsonOrig[0].GetDouble();
        header.params.orig[1]    = jsonOrig[1].GetDouble();
        header.params.orig[2]    = jsonOrig[2].GetDouble();

        header.params.tileWidth  = headerParam["TileWidth"].GetDouble();
        header.params.tileHeight = headerParam["TileHeight"].GetDouble();
        header.params.maxTiles   = headerParam["MaxTiles"].GetInt();
        header.params.maxPolys   = headerParam["MaxPolys"].GetInt();

        mesh = dtAllocNavMesh();
        CHECK_EXPR(mesh != nullptr, -1, "dtAllocNavMesh error");

        status = mesh->init(&header.params);
        CHECK_EXPR(dtStatusSucceed(status), -1, "mesh->init Failed");
    }

    // tile
    for (int tileCount = 0; tileCount < header.numTiles; ++tileCount) 
	{
        rapidjson::Value& jsonTile = jsonBase["NavMeshBuilders"][tileCount];
        if (jsonTile.IsNull()) 
		{
            break;
        }

        char* readPoint = tileBuff;
        tileLength = 0;

        // dtMeshHeader
        dtMeshHeader* meshHeader = (dtMeshHeader*)readPoint;
        rapidjson::Value& jsonMeshHeader = jsonTile["Header"];
        meshHeader->magic           = DT_NAVMESH_MAGIC;
        meshHeader->version         = DT_NAVMESH_VERSION;
        meshHeader->x               = jsonMeshHeader["X"].GetInt();
        meshHeader->y               = jsonMeshHeader["Y"].GetInt();
        meshHeader->layer           = jsonMeshHeader["Layer"].GetInt();
        meshHeader->userId          = jsonMeshHeader["UserId"].GetUint();
        meshHeader->polyCount       = jsonMeshHeader["PolyCount"].GetInt();
        meshHeader->vertCount       = jsonMeshHeader["VertCount"].GetInt();
        meshHeader->maxLinkCount    = jsonMeshHeader["MaxLinkCount"].GetInt();
        meshHeader->detailMeshCount = jsonMeshHeader["DetailMeshCount"].GetInt();
        meshHeader->detailVertCount = jsonMeshHeader["DetailVertCount"].GetInt();
        meshHeader->detailTriCount  = jsonMeshHeader["DetailTriCount"].GetInt();
        meshHeader->bvNodeCount     = jsonMeshHeader["BVNodeCount"].GetInt();
        meshHeader->offMeshConCount = jsonMeshHeader["OffMeshConCount"].GetInt();
        meshHeader->offMeshBase     = jsonMeshHeader["OffMeshBase"].GetInt();
        meshHeader->walkableHeight  = jsonMeshHeader["WalkableHeight"].GetDouble();
        meshHeader->walkableRadius  = jsonMeshHeader["WalkableRadius"].GetDouble();
        meshHeader->walkableClimb   = jsonMeshHeader["WalkableClimb"].GetDouble();

        rapidjson::Value& jsonMHBMin = jsonMeshHeader["BMin"];
        meshHeader->bmin[0]         = jsonMHBMin[0].GetDouble();
        meshHeader->bmin[1]         = jsonMHBMin[1].GetDouble();
        meshHeader->bmin[2]         = jsonMHBMin[2].GetDouble();

        rapidjson::Value& jsonMHBMax = jsonMeshHeader["BMax"];
        meshHeader->bmax[0]         = jsonMHBMax[0].GetDouble();
        meshHeader->bmax[1]         = jsonMHBMax[1].GetDouble();
        meshHeader->bmax[2]         = jsonMHBMax[2].GetDouble();

        meshHeader->bvQuantFactor   = jsonMeshHeader["BVQuantFactor"].GetDouble();

        readPoint += sizeof(dtMeshHeader);

        // cal length
        const int headerSize = dtAlign4(sizeof(dtMeshHeader));
        const int vertsSize = dtAlign4(sizeof(float)* 3 * meshHeader->vertCount);
        const int polysSize = dtAlign4(sizeof(dtPoly)*meshHeader->polyCount);
        const int linksSize = dtAlign4(sizeof(dtLink)*(meshHeader->maxLinkCount));
        const int detailMeshesSize = dtAlign4(sizeof(dtPolyDetail)*meshHeader->detailMeshCount);
        const int detailVertsSize = dtAlign4(sizeof(float)* 3 * meshHeader->detailVertCount);
        const int detailTrisSize = dtAlign4(sizeof(unsigned char)* 4 * meshHeader->detailTriCount);
        const int bvtreeSize = dtAlign4(sizeof(dtBVNode)*meshHeader->bvNodeCount);
        const int offMeshLinksSize = dtAlign4(sizeof(dtOffMeshConnection)*meshHeader->offMeshConCount);
        tileLength = headerSize + vertsSize + polysSize + linksSize + detailMeshesSize + detailVertsSize + detailTrisSize + bvtreeSize + offMeshLinksSize;
        CHECK_EXPR(tileLength + sizeof(dtMeshHeader) < sizeof(tileBuff), -1, "");

        {
            // verts
            rapidjson::Value& jsonVerts = jsonTile["NavVerts"];
            for (int count = 0; count < 3 * meshHeader->vertCount; ++count) {
                float* point = &(((float*)readPoint)[count]);
                *point = jsonVerts[count].GetDouble();
            }
            readPoint += vertsSize;

            // polys
            rapidjson::Value& jsonPolys = jsonTile["NavPolys"];
            for (int count = 0; count < meshHeader->polyCount; ++count) 
			{
                dtPoly* poly = &(((dtPoly*)readPoint)[count]);
                rapidjson::Value& jsonValue =  jsonPolys[count];

                poly->areaAndtype   = jsonValue["_areaAndType"].GetUint();
                poly->firstLink     = jsonValue["FirstLink"].GetUint();
                poly->flags         = jsonValue["Flags"].GetUint();
                poly->vertCount     = jsonValue["VertCount"].GetUint();

                for (int index = 0; index < DT_VERTS_PER_POLYGON; ++index) 
				{
                    poly->verts[index] = jsonValue["Verts"][index].GetUint();
                }

                for (int index = 0; index < DT_VERTS_PER_POLYGON; ++index) 
				{
                    poly->neis[index] = jsonValue["Neis"][index].GetUint();
                }
            }
            readPoint += polysSize;

            // links
            rapidjson::Value& jsonLinks = jsonTile["NavLinks"];
            for (int count = 0; count < meshHeader->maxLinkCount; ++count) 
			{
                dtLink* link = &(((dtLink*)readPoint)[count]);
                rapidjson::Value& jsonValue =  jsonLinks[count];

                link->ref = (dtPolyRef)(jsonValue["Ref"].GetUint64());
                link->next = (unsigned int)jsonValue["Next"].GetUint();
                link->edge = jsonValue["Edge"].GetUint();
                link->side = jsonValue["Side"].GetUint();
                link->bmin = jsonValue["BMin"].GetUint();
                link->bmax = jsonValue["BMax"].GetUint();
            }
            readPoint += linksSize;

            // detail mesh
            rapidjson::Value& jsonDetailMesh = jsonTile["NavDMeshes"];
            for (int count = 0; count < meshHeader->detailMeshCount; ++count) 
			{
                dtPolyDetail* detail = &((dtPolyDetail*)readPoint)[count];
                rapidjson::Value& jsonValue =  jsonDetailMesh[count];

                detail->vertBase    = jsonValue["VertBase"].GetUint();
                detail->triBase     = jsonValue["TriBase"].GetUint();
                detail->vertCount   = jsonValue["VertCount"].GetUint();
                detail->triCount    = jsonValue["TriCount"].GetUint();
            }
            readPoint += detailMeshesSize;

            // detail verts
            rapidjson::Value& jsonDetailVerts = jsonTile["NavDVerts"];
            for (int count = 0; count < 3 * meshHeader->detailVertCount; ++count) 
			{
                float* point = &((float*)readPoint)[count];
                *point = jsonDetailVerts[count].GetDouble();
            }
            readPoint += detailVertsSize;

            // detail tris
            rapidjson::Value& jsonDetailTris = jsonTile["NavDTris"];
            for (int count = 0; count < 4 * meshHeader->detailTriCount; ++count) 
			{
                unsigned char* point = &((unsigned char*)readPoint)[count];
                *point = jsonDetailTris[count].GetUint();
            }
            readPoint += detailTrisSize;

            // bv tree
            rapidjson::Value& jsonBVTree = jsonTile["NavBvTree"];
            for (int count = 0; count < meshHeader->bvNodeCount; ++count) 
			{
                dtBVNode* bvNode = &((dtBVNode*)readPoint)[count];
                rapidjson::Value& jsonValue =  jsonBVTree[count];
                rapidjson::Value& jsonBMin = jsonValue["BMin"];
                rapidjson::Value& jsonBMax = jsonValue["BMax"];

                bvNode->bmin[0] = jsonBMin[0].GetUint();
                bvNode->bmin[1] = jsonBMin[1].GetUint();
                bvNode->bmin[2] = jsonBMin[2].GetUint();
                bvNode->bmax[0] = jsonBMax[0].GetUint();
                bvNode->bmax[1] = jsonBMax[1].GetUint();
                bvNode->bmax[2] = jsonBMax[2].GetUint();
                bvNode->i       = jsonValue["I"].GetInt();
            }
            readPoint += bvtreeSize;

            // off mesh link
            rapidjson::Value& jsonOffMesh = jsonTile["OffMeshCons"];
            for (int count = 0; count < meshHeader->offMeshConCount; ++count) 
			{
                rapidjson::Value& jsonOffMeshData = jsonOffMesh[count];
                dtOffMeshConnection* offMeshLink = &((dtOffMeshConnection*)readPoint)[count];

                offMeshLink->rad = (float)jsonOffMeshData["Rad"].GetDouble();
                offMeshLink->poly = (unsigned short)jsonOffMeshData["Poly"].GetUint();
                offMeshLink->flags = (unsigned char)jsonOffMeshData["Flags"].GetUint();
                offMeshLink->side = (unsigned char)jsonOffMeshData["Side"].GetUint();
                offMeshLink->userId = (unsigned int)jsonOffMeshData["UserId"].GetUint();

                rapidjson::Value& jsonPos = jsonOffMeshData["Pos"];
                for (int i = 0; i < (int)NF_ARRAYSIZE(offMeshLink->pos); ++i)
				{
                    offMeshLink->pos[i] = (float)jsonPos[i].GetDouble();
                }
            }
            readPoint += offMeshLinksSize;

            NF_ASSERT((char*)meshHeader + tileLength== readPoint);

            // add tile
            tileData = (unsigned char*)dtAlloc(tileLength, DT_ALLOC_PERM);
            CHECK_EXPR(tileData != NULL, -1, "");
            memcpy(tileData, meshHeader, tileLength);

            status = mesh->addTile(tileData, tileLength, DT_TILE_FREE_DATA, 0, 0);
            CHECK_EXPR(dtStatusSucceed(status), -1, "");
        }
    }

    *navMesh = mesh;
    return 0;
}