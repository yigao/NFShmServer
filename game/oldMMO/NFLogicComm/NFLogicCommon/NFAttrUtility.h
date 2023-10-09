// -------------------------------------------------------------------------
//    @FileName         :    NFAttrUtility.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttrUtility
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

/*
*  属性计算工具
*/
namespace AttrOpt
{
    template<class T>
    inline static  void MergeAttr(T& src, T& dst)
    {
        for (auto& e : src)
        {
            dst[e.first] += e.second;
        }
    }

    inline static void MergeAttr(MAP_INT32_FLOAT& src, MAP_INT32_INT64& dst)
    {
        for (auto& e : src)
        {
            dst[e.first] += (int32_t)(floor(e.second));
        }
    }

    template<class T1,class T2>
    inline static void ScaleAttr(T1& dst, T2 scale)
    {
        for (auto& e : dst)
        {
            e.second *= scale;
        }
    }

    template<class T1, class T2, class T3>
    inline static void ScaleAttr(T1& src, T2&dst, T3 scale)
    {
        for (auto& e : src)
        {
            dst[e.first] += e.second * scale;
        }
    }


    inline static void PrintAttr(MAP_INT32_INT64& dst, const char* tagName)
    {
#if ATTR_OUT
        //打印属性
		string strLog;
		for (auto& e : dst)
		{
			char szTmp[50] = { '\0' };
			snprintf(szTmp, sizeof(szTmp), "[%d,%lu]", e.first, e.second);
			strLog += szTmp;
		}

		LogInfoFmtPrint("%s attrs:%s", tagName ? tagName : " ", strLog.c_str());
#endif
    }
};