// -------------------------------------------------------------------------
//    @FileName         :    NFPair.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <stddef.h>
#include <string.h>

/**
* 用来对应std::pair
*/
template<class _T1, class _T2>
class NFPair
{
public:
	NFPair(_T1 _first = _T1(), _T2 _second = _T2()):first(_first), second(_second)
	{

	}
	NFPair(const NFPair& pair)
	{
		if (this != &pair)
		{
			first = pair.first;
			second = pair.second;
		}
	}

	NFPair& operator=(const NFPair& pair)
	{
		if (this != &pair)
		{
			first = pair.first;
			second = pair.second;
		}

		return *this;
	}

	_T1 first;                 /// @c first is a copy of the first object
	_T2 second;                /// @c second is a copy of the second object
};
