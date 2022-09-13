// -------------------------------------------------------------------------
//    @FileName         :    NFSimpleBuffer.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include <string.h>
#include <assert.h>
#include <string>
#include "NFPlatform.h"

class NFSimpleBuffer
{
public:
	// Create an empty slice.
	NFSimpleBuffer() : data_(nullptr), size_(0)
	{
	}

	// Create a slice that refers to d[0,n-1].
	NFSimpleBuffer(const char* d, size_t n)
	{
		Init(d, n);
	}

	void Init(const char* d, size_t n)
	{
		clear();
		if (n > 0)
		{
			data_ = new char[n];
			size_ = n;
			memcpy(static_cast<void*>(data_), d, n);
		}
	}

	void Init(size_t n)
	{
		clear();
		if (n > 0)
		{
			data_ = new char[n];
			size_ = n;
		}
	}

	virtual ~NFSimpleBuffer()
	{
		clear();
	}

	// Return true if the length of the referenced data is zero
	bool empty() const
	{
		return data_ == nullptr;
	}

	void clear()
	{
		if (data_)
		{
			delete[] data_;
			size_ = 0;
			data_ = nullptr;
		}
	}

	// Return a pointer to the beginning of the referenced data
	char* data() const
	{
		return data_;
	}

	// Return the length (in bytes) of the referenced data
	size_t size() const
	{
		return size_;
	}

	// Return a string that contains the copy of the referenced data.
	std::string ToString() const
	{
		return std::string(data_, size_);
	}

private:
	char* data_;
	size_t size_;
};

