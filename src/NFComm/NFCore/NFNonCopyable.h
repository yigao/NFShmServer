// -------------------------------------------------------------------------
//    @FileName         :    NFNonCopyable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

class NFNonCopyable
{
protected:
	NFNonCopyable()
	{
	}

	~NFNonCopyable()
	{
	}

private:
	NFNonCopyable(const NFNonCopyable&);
	const NFNonCopyable& operator=(const NFNonCopyable&);
};

