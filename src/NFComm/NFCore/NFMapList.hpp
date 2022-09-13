// -------------------------------------------------------------------------
//    @FileName         :    NFMap.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//
// -------------------------------------------------------------------------

#pragma once

#include <map>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include "NFMapEx.hpp"

template <typename T, typename TD>
class NFMapList
{
public:
	typedef std::map<T, TD*> NFMapOBJECT;
	typedef std::vector<TD*> NFListOBJECT;

	NFMapList()
	{
	};

	virtual ~NFMapList()
	{
	};

	virtual bool AddElement(const T& name, TD* data)
	{
		typename NFMapOBJECT::iterator itr = mObjectMap.find(name);
		if (itr == mObjectMap.end())
		{
			mObjectMap.insert(typename NFMapOBJECT::value_type(name, data));
			mObjectList.push_back(data);
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
			for (auto iter = mObjectList.begin(); iter != mObjectList.end(); iter++)
			{
				if (*iter == pData)
				{
					mObjectList.erase(iter);
					break;
				}
			}
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

	TD* Index(int index) const
	{
		if (index >= 0 && index < (int)mObjectList.size())
		{
			return mObjectList[index];
		}
		return nullptr;
	}

	int Count()
	{
		//assert(mObjectMap.size() == mObjectList.size());
		return (int)mObjectMap.size();
	}

	bool ClearAll()
	{
		mObjectMap.clear();
		mObjectList.clear();
		return true;
	}

private:
	NFMapOBJECT mObjectMap;
	NFListOBJECT mObjectList;
	typename NFMapOBJECT::iterator mObjectCurIter;
};

