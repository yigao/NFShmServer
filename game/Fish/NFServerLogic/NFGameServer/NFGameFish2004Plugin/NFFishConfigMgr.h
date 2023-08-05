// -------------------------------------------------------------------------
//    @FileName         :    NFFishConfigDesc.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFFishConfigDesc.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFFishCtrlCfgDef.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include <map>
#include <algorithm>

#define MAX_FISH_CONFIG_FISH_KIND_NUM 50
#define MAX_FISH_CONFIG_FISH_KIND_CHILD_FISH_NUM 50
#define MAX_FISH_CONFIG_DAMAGE_FISH_NUM 50
#define MAX_FISH_CONFIG_FISHI_CONFIG_NUM 500

class FishConfig
{
public:
	FishConfig()
	{
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
	}

	~FishConfig()
	{

	}

    int CreateInit()
    {
        btFishKindId = 0;
        btFishType = 0;
        nRatioMin = 0;
        nRatioMax = 0;
        nRatioDeath = 0;
        nDoubleAwardMinRatio = 0;
        nChildFishCount = 0;
        nDamageRadius = 0;
        nFishOutTipsID = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
public:
	uint8_t             btFishKindId;               //鱼的种类 id
	//std::string         strFishName;              //鱼的名称 fishName
	uint8_t             btFishType;                 //鱼的类型 fishRuleType
	int                 nRatioMin;                  //浮动倍率最小值 ratioMin
	int                 nRatioMax;                  //浮动倍率最大值 ratioMax
	int                 nRatioDeath;                //打死倍率，当这个为非0时，用这个计算打死概率
	int                 nDoubleAwardMinRatio;       //可能触发双倍奖励所需最低倍率 doubleAwardMinRatio
	int                 nChildFishCount;            //组合鱼携带子鱼个数 childFishCount
    NFShmVector<NFShmVector<uint8_t, MAX_FISH_CONFIG_FISH_KIND_CHILD_FISH_NUM>, MAX_FISH_CONFIG_FISH_KIND_NUM> vecVecChildFishes; //组合鱼位置可选子鱼id列表-1-6 childFishIds_1-6
	int                 nDamageRadius;                 //鱼死亡伤害半径  damageRadius
    NFShmVector<uint8_t, MAX_FISH_CONFIG_DAMAGE_FISH_NUM>  vectDamageFishIds;           //子鱼ID鱼死亡可伤害的鱼id列表 damageFishIds
	int                 nFishOutTipsID;             //是否有出鱼提示 0-无  1-有

	//int                 nMiniGameId;                //触发小游戏ID

	int GetFishRatio()
	{
		if (nRatioMin == nRatioMax)
		{
			return nRatioMin;
		}

		int nBaseMul = 1;
		if (nRatioMin > 0 && nRatioMax > 0)
		{
			nBaseMul = nRatioMin;

			if (nRatioMax > nRatioMin)
			{
				//////////////////////////////////////////////////////////////////////////
				//nBaseMul = NFRandomInt(nRatioMin, nRatioMax);
				//===================
				int diffMul = nRatioMax - nRatioMin;
				int midMul  = nRatioMin + diffMul / 3;

				int iRand   = NFRandomInt(0, 100);
				if (iRand < 60)
				{
					nBaseMul = NFRandomInt(nRatioMin, midMul);
				}
				else
				{
					nBaseMul = NFRandomInt(midMul, nRatioMax);
				}
				//////////////////////////////////////////////////////////////////////////
			}
		}

		return nBaseMul;
	}

	int GetFishExclude(std::vector<uint8_t>& vecSrc, std::vector<uint8_t>& vecExclude)
	{
		random_shuffle(vecSrc.begin(), vecSrc.end());

		std::vector<uint8_t>::iterator iter = vecSrc.begin();
		for (; iter != vecSrc.end(); iter++)
		{
			if (!IsValueInVec(*iter, vecExclude))
			{
				return *iter;
			}
		}

		return *(vecSrc.begin());
	}

	bool IsValueInVec(int iVal, std::vector<uint8_t>& vecValues)
	{
		std::vector<uint8_t>::iterator iter = vecValues.begin();
		for (; iter != vecValues.end(); iter++)
		{
			if (*iter == iVal)
			{
				return true;
			}
		}

		return false;
	}
};

class NFFishConfigMgr: public NFShmObj
{
public:
	NFFishConfigMgr();
	virtual ~NFFishConfigMgr();
    int CreateInit();
    int ResumeInit();

public:
    int LoadConfig(uint32_t roomId);

	virtual int LoadConfig(const std::string& strFishKindCfgFile);

	virtual int LoadFishConfigCSV(const std::string& strFishKindCfgFile);

    int GetFileContainMD5(const std::string& strFileName, std::string& fileMd5);

	virtual FishConfig* GetFishBaseInfo(char btFishKind);
	virtual int GetFishKindMaxId();
public:
	std::vector<std::string> GetColVecByColName(std::map<std::string, std::vector<std::string> >& mapCols, std::string strColName);
	std::string GetValue(std::map<std::string, std::vector<std::string> >& mapCols, std::string strColName, int iIndex);
	std::map<std::string, std::vector<std::string> > ClassifyValues(std::vector<std::vector<std::string> >& values);
	int ReadCfg(const std::string & strFile, std::vector<std::vector<std::string> > & values);
private:
    uint32_t m_roomId;
    NFCommonStr m_szMD5;
	NFShmVector<FishConfig, MAX_FISH_CONFIG_FISHI_CONFIG_NUM> m_vectFishConfig;
DECLARE_IDCREATE(NFFishConfigMgr);
};
