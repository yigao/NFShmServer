// -------------------------------------------------------------------------
//    @FileName         :    NFComTypeDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFComTypeDefine
//
// -------------------------------------------------------------------------

#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "NFPoint3.h"
#include "NFPoint2.h"
#include "Com.pb.h"

using namespace std;


//常用stl类型定义,避免代码中写很长一段
typedef std::vector<int8_t>			VEC_INT8;
typedef std::vector<uint8_t>		VEC_UINT8;
typedef std::vector<int16_t>		VEC_INT16;
typedef std::vector<uint16_t>		VEC_UINT16;
typedef std::vector<int32_t>		VEC_INT32;
typedef std::vector<uint32_t>		VEC_UINT32;
typedef std::vector<int64_t>		VEC_INT64;
typedef std::vector<uint64_t>		VEC_UINT64;
typedef std::vector<std::string>	VEC_STRING;
typedef std::vector<float>			VEC_FLOAT;
typedef std::vector< VEC_UINT64 >	VEC_VEC_UINT64;


typedef std::list<int8_t>		LIST_INT8;
typedef std::list<uint8_t>		LIST_UINT8;
typedef std::list<int16_t>		LIST_INT16;
typedef std::list<uint16_t>		LIST_UINT16;
typedef std::list<int32_t>		LIST_INT32;
typedef std::list<uint32_t>		LIST_UINT32;
typedef std::list<int64_t>		LIST_INT64;
typedef std::list<uint64_t>		LIST_UINT64;
typedef std::list<std::string>	LIST_STRING;
typedef std::list<float>		LIST_FLOAT;

typedef std::unordered_set<int8_t>			SET_INT8;
typedef std::unordered_set<uint8_t>			SET_UINT8;
typedef std::unordered_set<int16_t>			SET_INT16;
typedef std::unordered_set<uint16_t>		SET_UINT16;
typedef std::unordered_set<int32_t>			SET_INT32;
typedef std::unordered_set<uint32_t>		SET_UINT32;
typedef std::unordered_set<int64_t>			SET_INT64;
typedef std::unordered_set<uint64_t>		SET_UINT64;
typedef std::unordered_multiset<uint64_t>	MULTI_SET_UINT64;
typedef std::unordered_set<std::string>		SET_STRING;
typedef std::unordered_set<float>			SET_FLOAT;

//有序的set
typedef std::set<uint32_t>					ORDER_SET_UINT32;
typedef std::set<int32_t>					ORDER_SET_INT32;

typedef std::unordered_map<int32_t, int32_t> MAP_INT32_INT32;
typedef std::unordered_map<int32_t, uint32_t> MAP_INT32_UINT32;
typedef std::unordered_map<uint32_t, uint32_t> MAP_UINT32_UINT32;
typedef std::unordered_map<uint32_t, uint64_t> MAP_UINT32_UINT64;
typedef std::unordered_map<uint32_t, int64_t> MAP_UINT32_INT64;
typedef std::unordered_map<int32_t, uint64_t> MAP_INT32_UINT64;
typedef std::unordered_map<uint64_t, uint64_t> MAP_UINT64_UINT64;
typedef std::unordered_map<uint64_t, uint32_t> MAP_UINT64_UINT32;
typedef std::unordered_map<uint64_t, int32_t> MAP_UINT64_INT32;
typedef std::unordered_map<uint64_t, int64_t> MAP_UINT64_INT64;
typedef std::unordered_map<uint64_t, uint8_t> MAP_UINT64_UINT8;

typedef std::unordered_map<uint32_t, int32_t> MAP_UINT32_INT32;
typedef std::unordered_map<uint16_t, int32_t> MAP_UINT16_INT32;
typedef std::unordered_map<uint16_t, int64_t> MAP_UINT16_INT64;
typedef std::unordered_map<uint32_t, uint16_t> MAP_UINT32_UINT16;
typedef std::unordered_map<uint32_t, uint8_t> MAP_UINT32_UINT8;
typedef std::unordered_map<uint32_t, int8_t> MAP_UINT32_INT8;
typedef std::unordered_map<uint64_t, int8_t> MAP_UINT64_INT8;
typedef std::unordered_map<uint8_t, uint16_t> MAP_UINT8_UINT16;
typedef std::unordered_map<uint8_t, uint32_t> MAP_UINT8_UINT32;
typedef std::unordered_map<int8_t, uint32_t> MAP_INT8_UINT32;
typedef std::unordered_map<int8_t, int32_t> MAP_INT8_INT32;
typedef std::unordered_map<int8_t, int8_t> MAP_INT8_INT8;
typedef std::unordered_map<int32_t, int64_t> MAP_INT32_INT64;
typedef std::unordered_map<int32_t, int8_t> MAP_INT32_INT8;
typedef std::unordered_map<int32_t, uint64_t> MAP_INT32_UINT64;
typedef std::unordered_map<int8_t, uint64_t> MAP_INT8_UINT64;
typedef std::unordered_map<std::string, int32_t> MAP_STRING_INT32;
typedef std::unordered_map<int8_t , std::string > MAP_INT8_STRING;
typedef std::unordered_map<std::string, uint64_t> MAP_STRING_UINT64;

typedef std::unordered_map<int64_t, int64_t> MAP_INT64_INT64;
typedef std::unordered_map<int64_t, int32_t> MAP_INT64_INT32;
typedef std::unordered_map<std::string, int64_t> MAP_STRING_INT64;
typedef std::unordered_map<uint32_t,std::string > MAP_UINT32_STRING;
typedef std::unordered_map<std::string, uint32_t> MAP_STRING_UINT32;


typedef std::vector< VEC_INT32 > VEC_VEC_INT32;

//有顺序的map
typedef std::map<int32_t, int32_t> ORDER_MAP_INT32_INT32;
typedef std::map<uint32_t, uint32_t> ORDER_MAP_UINT32_UINT32;
typedef std::map<int32_t, int64_t> ORDER_MAP_INT32_INT64;
typedef std::map<uint32_t, int64_t> ORDER_MAP_UINT32_INT64;
typedef std::map<std::string, int32_t> ORDER_MAP_STRING_INT32;
typedef std::map<int32_t, std::string> ORDER_MAP_INT32_STRING;


typedef std::map<int64_t, int64_t> ORDER_MAP_INT64_INT64;
typedef std::map<int64_t, uint64_t> ORDER_MAP_INT64_UINT64;
typedef std::map<int64_t, int32_t> ORDER_MAP_INT64_INT32;
typedef std::map<uint64_t, uint32_t> ORDER_MAP_UINT64_UINT32;
typedef std::map<std::string, int64_t> ORDER_MAP_STRING_INT64;

typedef std::unordered_map<uint64_t, string > MAP_UINT64_STRING;
typedef std::unordered_map<uint32_t, SET_UINT32 > MAP_UINT32_SET_UINT32;
typedef std::unordered_map<uint16_t, SET_UINT16 > MAP_UINT16_SET_UINT16;
typedef std::unordered_map<uint32_t, SET_UINT64 > MAP_UINT32_SET_UINT64;
typedef std::unordered_map<uint64_t, SET_UINT32 > MAP_UINT64_SET_UINT32;
typedef std::unordered_map<uint32_t, SET_INT32 > MAP_UINT32_SET_INT32;
typedef std::unordered_map<uint32_t, SET_INT8 > MAP_UINT32_SET_INT8;
typedef std::unordered_map<uint64_t, SET_UINT64 > MAP_UINT64_SET_UINT64;
typedef std::unordered_map<uint64_t, SET_INT64 > MAP_UINT64_SET_INT64;
typedef std::unordered_map<uint32_t, MULTI_SET_UINT64 > MAP_UINT32_MULTI_SET_UINT64;

typedef std::unordered_map<uint32_t, VEC_UINT32 > MAP_UINT32_VEC_UINT32;
typedef std::unordered_map<uint32_t, VEC_INT32 > MAP_UINT32_VEC_INT32;
typedef std::unordered_map<uint64_t, VEC_INT32 > MAP_UINT64_VEC_INT32;
typedef std::unordered_map<uint64_t, VEC_INT64 > MAP_UINT64_VEC_INT64;
typedef std::unordered_map<uint64_t, VEC_UINT64 > MAP_UINT64_VEC_UINT64;
typedef std::unordered_map<int32_t, VEC_INT32 > MAP_INT32_VEC_INT32;
typedef std::unordered_map<uint32_t, VEC_INT64 > MAP_UINT32_VEC_INT64;
typedef std::unordered_map<uint32_t, MAP_UINT32_UINT32 > MAP_UINT32_MAP_UINT32_UINT32;
typedef std::unordered_map<uint32_t, MAP_UINT32_INT8 > MAP_UINT32_MAP_UINT32_INT8;
typedef std::unordered_map<uint32_t, LIST_UINT64 > MAP_UINT32_LST_UINT64;
typedef std::unordered_map<uint32_t, LIST_UINT32 > MAP_UINT32_LST_UINT32;
typedef std::unordered_map<uint32_t, MAP_INT32_UINT64 > MAP_UINT32_MAP_INT32_UINT64;
typedef std::unordered_map<int8_t, SET_UINT32 > MAP_INT8_SET_UINT32;
typedef std::unordered_map<int32_t, SET_UINT32 > MAP_INT32_SET_UINT32;
typedef std::unordered_map<uint64_t, SET_INT32 > MAP_UINT64_SET_INT32;
typedef std::unordered_map<int32_t, SET_UINT64 > MAP_INT32_SET_UINT64;

typedef std::unordered_map<int8_t, VEC_INT32 > MAP_INT8_VEC_INT32;
typedef std::unordered_map<uint32_t, VEC_UINT64 > MAP_UINT32_VEC_UINT64;



typedef std::unordered_map<uint32_t, VEC_VEC_INT32 > MAP_UINT32_VEC_VEC_INT32;
typedef std::unordered_map<int8_t, VEC_UINT16 > MAP_INT8_VEC_UINT16;
typedef std::unordered_map<int8_t, VEC_UINT32 > MAP_INT8_VEC_UINT32;
typedef std::unordered_map<uint64_t, VEC_VEC_INT32 > MAP_UINT64_VEC_VEC_INT32;

typedef std::unordered_map<int8_t, MAP_UINT32_UINT32 > MAP_INT8_MAP_UINT32_UINT32;
typedef std::unordered_map<int8_t, MAP_UINT32_INT32 > MAP_INT8_MAP_UINT32_INT32;
typedef std::unordered_map<int8_t, MAP_UINT64_INT32 > MAP_INT8_MAP_UINT64_INT32;
typedef std::unordered_map<int8_t, MAP_UINT64_INT64 > MAP_INT8_MAP_UINT64_INT64;




typedef std::unordered_map<int8_t, MAP_INT32_INT64 > MAP_INT8_MAP_INT32_INT64;
typedef std::unordered_map<uint32_t, MAP_UINT32_INT64 > MAP_UINT32_MAP_UINT32_INT64;
typedef std::unordered_map<uint32_t, MAP_UINT64_INT32 > MAP_UINT32_MAP_UINT64_INT32;
typedef std::unordered_map<uint32_t, MAP_INT8_SET_UINT32 > MAP_UINT32_MAP_INT8_SET_UINT32;
typedef std::unordered_map<uint32_t, MAP_UINT32_MAP_UINT32_INT8 > MAP_UINT32_MAP_UINT32_MAP_UINT32_INT8;
typedef std::unordered_map<uint32_t, MAP_INT32_SET_UINT32 > MAP_UINT32_MAP_INT32_SET_UINT32;
typedef std::unordered_map<uint32_t, MAP_UINT32_MAP_INT32_SET_UINT32 > MAP_UINT32_MAP_UINT32_MAP_INT32_SET_UINT32;
typedef std::unordered_map<uint32_t, MAP_UINT32_SET_UINT32 > MAP_UINT32_MAP_UINT32_SET_UINT32;
typedef std::unordered_map<int8_t, MAP_INT8_INT8 > MAP_INT8_MAP_INT8_INT8;
typedef std::unordered_map<int8_t, MAP_UINT32_SET_UINT32 > MAP_INT8_MAP_UINT32_SET_UINT32;
typedef std::unordered_map<uint32_t, MAP_INT8_INT32> MAP_UINT32_MAP_INT8_INT32;
typedef std::unordered_map<int8_t, MAP_UINT32_MAP_INT8_INT32> MAP_INT8_MAP_UINT32_MAP_INT8_INT32;
typedef std::unordered_map<int8_t, MAP_UINT32_MAP_UINT32_UINT32> MAP_INT8_MAP_UINT32_MAP_UINT32_UINT32;
typedef std::unordered_map<uint64_t, MAP_UINT64_UINT64 > MAP_UINT64_MAP_UINT64_UINT64;
typedef std::unordered_map<uint64_t, MAP_UINT64_INT64 >  MAP_UINT64_MAP_UINT64_INT64;

typedef std::unordered_map<int32_t, MAP_UINT32_UINT64 > MAP_INT32_MAP_UINT32_UINT64;
typedef std::unordered_map<uint32_t, MAP_UINT64_VEC_UINT64 > MAP_UINT32_MAP_UINT64_VEC_UINT64;


typedef std::map<uint32_t, VEC_UINT32 > ORDER_MAP_UINT32_VEC_UINT32;
typedef std::map<uint32_t, VEC_UINT64 > ORDER_MAP_UINT32_VEC_UINT64;
typedef std::map<uint32_t, VEC_INT32 > ORDER_MAP_UINT32_VEC_INT32;


typedef std::map<uint32_t,SET_UINT32 > ORDER_MAP_UINT32_SET_UINT32;
typedef std::map<uint64_t, SET_UINT64 > ORDER_MAP_UINT64_SET_UINT64;
typedef std::map<uint32_t, ORDER_MAP_UINT32_UINT32 > OEDER_MAP_UINT32_ORDER_MAP_UINT32_UINT32;
typedef std::map<uint32_t, ORDER_MAP_UINT32_INT64 > OEDER_MAP_UINT32_ORDER_MAP_UINT32_INT64;
typedef std::map<uint32_t, ORDER_MAP_UINT32_VEC_UINT32 > OEDER_MAP_UINT32_ORDER_MAP_UINT32_VEC_UINT32;
typedef std::map<uint32_t, ORDER_MAP_UINT32_VEC_UINT64 > OEDER_MAP_UINT32_ORDER_MAP_UINT32_VEC_UINT64;
typedef std::map<uint32_t, ORDER_MAP_UINT32_VEC_INT32 > OEDER_MAP_UINT32_ORDER_MAP_UINT32_VEC_INT32;
typedef std::map<uint16_t, int32_t> ORDER_MAP_UINT16_INT32;
typedef std::map<uint16_t, int64_t> ORDER_MAP_UINT16_INT64;
typedef std::map<uint32_t, ORDER_MAP_UINT16_INT32> ORDER_MAP_UINT32_ORDER_MAP_UINT16_INT32;
typedef std::map<uint64_t, ORDER_MAP_UINT16_INT32> ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT32;
typedef std::map<uint64_t, ORDER_MAP_UINT16_INT64> ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT64;
typedef std::map<uint32_t, ORDER_MAP_UINT64_SET_UINT64 > ORDER_MAP_UINT32_ORDER_MAP_UINT64_SET_UINT64;
typedef std::vector< VEC_INT32 > VEC_VEC_INT32;
typedef std::vector< VEC_FLOAT > VEC_VEC_FLOAT;
typedef std::vector< MAP_UINT64_INT64 > VEC_MAP_UINT64_INT64;

typedef std::unordered_map<int32_t, float> MAP_INT32_FLOAT;
typedef std::unordered_map<int32_t, double> MAP_INT32_DOUBLE;
//定义坐标
typedef vector<NFPoint3<float> > VecPoint3;
typedef vector<NFPoint2<float> > VecPoint2;


struct stAttr64
{
    uint32_t id = 0;    //属性索引id
    int64_t val = 0;    //属性值
    stAttr64():id(0),val(0){}
    stAttr64(uint32_t _id,int64_t _val):id(_id),val(_val){}
};

typedef vector< stAttr64 > VEC_ATTR64;

