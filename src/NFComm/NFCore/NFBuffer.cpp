// -------------------------------------------------------------------------
//    @FileName         :    NFBuffer.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFBuffer.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cassert>

inline static std::size_t RoundUp2Power(std::size_t size)
{
	if (size == 0)
		return 0;

	std::size_t roundUp = 1;
	while (roundUp < size)
		roundUp *= 2;

	return roundUp;
}

const std::size_t NFBuffer::kMaxBufferSize = (std::numeric_limits<std::size_t>::max)() / 2;
const std::size_t NFBuffer::kDefaultSize = 128;

NFBuffer::NFBuffer() :
	_readPos(0),
	_writePos(0),
	_capacity(0),
	_buffer(nullptr),
	_highWaterPercent(50)
{
}

NFBuffer::~NFBuffer()
{
	delete[] _buffer;
}

std::size_t NFBuffer::PushData(char data)
{
	if (ReadableSize() + 1 >= kMaxBufferSize)
		return 0; // overflow

	AssureSpace(1);
	_buffer[_writePos] = data;
	Produce(1);

	return 1;
}

std::size_t NFBuffer::PushData(const void* data, std::size_t size)
{
	if (!data || size == 0)
		return 0;

	if (ReadableSize() + size >= kMaxBufferSize)
		return 0; // overflow

	AssureSpace(size);
	::memcpy(&_buffer[_writePos], data, size);
	Produce(size);

	return size;
}

void NFBuffer::Produce(std::size_t bytes)
{
	_writePos += bytes;
}

std::size_t NFBuffer::PopData(void* buf, std::size_t size)
{
	const std::size_t dataSize = ReadableSize();
	if (!buf ||
		size == 0 ||
		dataSize == 0)
		return 0;

	if (size > dataSize)
		size = dataSize; // truncate

	::memcpy(buf, &_buffer[_readPos], size);
	Consume(size);

	return size;
}

void NFBuffer::PeekData(void*& buf, std::size_t& size) const
{
	buf = ReadAddr();
	size = ReadableSize();
}

void NFBuffer::Consume(std::size_t bytes)
{
	assert(_readPos + bytes <= _writePos);

	_readPos += bytes;
	if (IsEmpty())
		Clear();
}

char* NFBuffer::ReadAddr() const
{
	return &_buffer[_readPos];
}

char* NFBuffer::WriteAddr() const
{
	return &_buffer[_writePos];
}

bool NFBuffer::IsEmpty() const
{
	return ReadableSize() == 0;
}

std::size_t NFBuffer::ReadableSize() const
{
	return _writePos - _readPos;
}

std::size_t NFBuffer::WritableSize() const
{
	return _capacity - _writePos;
}

void NFBuffer::AssureSpace(std::size_t needsize)
{
	if (WritableSize() >= needsize)
		return;

	const size_t dataSize = ReadableSize();
	const size_t oldCap = _capacity;

	while (WritableSize() + _readPos < needsize)
	{
		if (_capacity < kDefaultSize)
		{
			_capacity = kDefaultSize;
		}
		else if (_capacity <= kMaxBufferSize)
		{
			const size_t newCapcity = RoundUp2Power(_capacity);
			if (_capacity < newCapcity)
				_capacity = newCapcity;
			else
				_capacity = 2 * newCapcity;
		}
		else
		{
			assert(false);
		}
	}

	if (oldCap < _capacity)
	{
		char* tmp(new char[_capacity]);

		if (dataSize != 0)
			memcpy(&tmp[0], &_buffer[_readPos], dataSize);

		ResetBuffer(tmp);
	}
	else
	{
		assert(_readPos > 0);
		::memmove(&_buffer[0], &_buffer[_readPos], dataSize);
	}

	_readPos = 0;
	_writePos = dataSize;

	assert(needsize <= WritableSize());
}

std::size_t NFBuffer::Capacity() const
{
	return _capacity;
}

void NFBuffer::Shrink()
{
	if (IsEmpty())
	{
		Clear();
		_capacity = 0;
		ResetBuffer();
		return;
	}

	if (_capacity <= kDefaultSize)
		return;

	std::size_t oldCap = _capacity;
	std::size_t dataSize = ReadableSize();
	if (dataSize * 100 > oldCap * _highWaterPercent)
		return;

	std::size_t newCap = RoundUp2Power(dataSize);

	char* tmp(new char[newCap]);
	memcpy(&tmp[0], &_buffer[_readPos], dataSize);
	ResetBuffer(tmp);
	_capacity = newCap;

	_readPos = 0;
	_writePos = dataSize;
}

void NFBuffer::Clear()
{
	_readPos = _writePos = 0;
}

void NFBuffer::Swap(NFBuffer& buf)
{
	std::swap(_readPos, buf._readPos);
	std::swap(_writePos, buf._writePos);
	std::swap(_capacity, buf._capacity);
	std::swap(_buffer, buf._buffer);
}

void NFBuffer::ResetBuffer(void* ptr)
{
	delete[] _buffer;
	_buffer = reinterpret_cast<char*>(ptr);
}

void NFBuffer::SetHighWaterPercent(size_t percents)
{
	if (percents < 10 || percents >= 100)
		return;

	_highWaterPercent = percents;
}

