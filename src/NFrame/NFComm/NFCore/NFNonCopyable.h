// -------------------------------------------------------------------------
//    @FileName         :    NFNonCopyable.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
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

