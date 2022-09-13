// -------------------------------------------------------------------------
//    @FileName         :    NFMap.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//
// -------------------------------------------------------------------------

#pragma once

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <typeinfo>
#include "NFMapEx.hpp"

template <typename T, typename TD>
class NFMap
{
public:
	typedef std::map<T, TD*> NFMapOBJECT;

	NFMap()
	{
	};

	virtual ~NFMap()
	{
		//mObjectList.clear();
		//DeleteAllElement();
	};

	virtual bool AddElement(const T& name, TD* data)
	{
		typename NFMapOBJECT::iterator itr = mObjectMap.find(name);
		if (itr == mObjectMap.end())
		{
			mObjectMap.insert(typename NFMapOBJECT::value_type(name, data));
			// mObjectList[name] = data;
			return true;
		}

		return false;
	}

	virtual TD* RemoveElement(const T& name)
	{
		TD* pData = nullptr;
		typename NFMapOBJECT::iterator itr = mObjectMap.find(name);
		if (itr != mObjectMap.end())
		{
			pData = itr->second;
			mObjectMap.erase(itr);
		}

		return pData;
	}

	virtual TD* GetElement(const T& name)
	{
		typename NFMapOBJECT::iterator itr = mObjectMap.find(name);
		if (itr != mObjectMap.end())
		{
			return itr->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual TD* First()
	{
		if (mObjectMap.size() <= 0)
		{
			return nullptr;
		}

		mObjectCurIter = mObjectMap.begin();
		if (mObjectCurIter != mObjectMap.end())
		{
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual TD* Next()
	{
		if (mObjectCurIter == mObjectMap.end())
		{
			return nullptr;
		}

		++mObjectCurIter;
		if (mObjectCurIter != mObjectMap.end())
		{
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual TD* First(T& name)
	{
		if (mObjectMap.size() <= 0)
		{
			return nullptr;
		}

		mObjectCurIter = mObjectMap.begin();
		if (mObjectCurIter != mObjectMap.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	virtual TD* Next(T& name)
	{
		if (mObjectCurIter == mObjectMap.end())
		{
			return nullptr;
		}

		++mObjectCurIter;
		if (mObjectCurIter != mObjectMap.end())
		{
			name = mObjectCurIter->first;
			return mObjectCurIter->second;
		}
		else
		{
			return nullptr;
		}
	}

	int Count()
	{
		return mObjectMap.size();
	}

	bool ClearAll()
	{
		mObjectMap.clear();
		return true;
	}

private:
	NFMapOBJECT mObjectMap;
	typename NFMapOBJECT::iterator mObjectCurIter;
};

