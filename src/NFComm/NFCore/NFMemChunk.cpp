// -------------------------------------------------------------------------
//    @FileName         :    NFMemChunk.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFMemChunk.h"

#include <cassert>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iterator>

NFMemChunk::NFMemChunk()
	: _pHead(NULL)
	, _pData(NULL)
{
}

size_t NFMemChunk::calcMemSize(size_t iBlockSize, size_t iBlockCount)
{
	return iBlockSize * iBlockCount + sizeof(tagChunkHead);
}

size_t NFMemChunk::calcBlockCount(size_t iMemSize, size_t iBlockSize)
{
	if (iMemSize <= sizeof(tagChunkHead))
	{
		return 0;
	}

	return (std::min)(((iMemSize - sizeof(tagChunkHead)) / iBlockSize), (size_t)(-1));
}

void NFMemChunk::create(void *pAddr, size_t iBlockSize, size_t iBlockCount)
{
	assert(iBlockSize > sizeof(size_t));

	init(pAddr);

	_pHead->_iBlockSize = iBlockSize;
	_pHead->_iBlockCount = iBlockCount;
	_pHead->_firstAvailableBlock = 0;
	_pHead->_blockAvailable = iBlockCount;

	memset(_pData, 0x00, iBlockCount*iBlockSize);

	unsigned char *pt = _pData;
	for (size_t i = 0; i != iBlockCount; pt += iBlockSize)
	{
		++i;
		memcpy(pt, &i, sizeof(size_t)); //每块第一个字节直接指向下一个可用的block编号, 变成一个链表
	}
}

void NFMemChunk::connect(void *pAddr)
{
	init(pAddr);
}

void NFMemChunk::init(void *pAddr)
{
	_pHead = static_cast<tagChunkHead*>(pAddr);
	_pData = (unsigned char*)((char*)_pHead + sizeof(tagChunkHead));
}

void* NFMemChunk::allocate()
{
	if (!isBlockAvailable()) return NULL;

	unsigned char *result = _pData + (_pHead->_firstAvailableBlock * _pHead->_iBlockSize);

	--_pHead->_blockAvailable;

	_pHead->_firstAvailableBlock = *((size_t *)result);

	memset(result, 0x00, sizeof(_pHead->_iBlockSize));

	return result;
}

void* NFMemChunk::allocate2(size_t &iIndex)
{
	iIndex = _pHead->_firstAvailableBlock + 1;

	void *pAddr = allocate();

	if (pAddr == NULL)
	{
		iIndex = 0;
		return NULL;
	}

	return pAddr;
}

void NFMemChunk::deallocate(void *pAddr)
{
	assert(pAddr >= _pData);

	unsigned char* prelease = static_cast<unsigned char*>(pAddr);

	assert((prelease - _pData) % _pHead->_iBlockSize == 0);

	memset(pAddr, 0x00, _pHead->_iBlockSize);

	*((size_t *)prelease) = _pHead->_firstAvailableBlock;

	_pHead->_firstAvailableBlock = static_cast<size_t>((prelease - _pData) / _pHead->_iBlockSize);

	assert(_pHead->_firstAvailableBlock == (prelease - _pData) / _pHead->_iBlockSize);

	++_pHead->_blockAvailable;
}

void NFMemChunk::deallocate2(size_t iIndex)
{
	assert(iIndex > 0 && iIndex <= _pHead->_iBlockCount);

	void *pAddr = _pData + (iIndex - 1) * _pHead->_iBlockSize;

	deallocate(pAddr);
}

void* NFMemChunk::getAbsolute(size_t iIndex)
{
	assert(iIndex > 0 && iIndex <= _pHead->_iBlockCount);

	void* pAddr = _pData + (iIndex - 1) * _pHead->_iBlockSize;

	return pAddr;
}

size_t NFMemChunk::getRelative(void *pAddr)
{
	assert((char*)pAddr >= (char*)_pData && ((char*)pAddr <= (char*)_pData + _pHead->_iBlockSize * _pHead->_iBlockCount));
	assert(((char*)pAddr - (char*)_pData) % _pHead->_iBlockSize == 0);

	return 1 + ((char*)pAddr - (char*)_pData) / _pHead->_iBlockSize;
}

void NFMemChunk::rebuild()
{
	assert(_pHead);

	_pHead->_firstAvailableBlock = 0;
	_pHead->_blockAvailable = _pHead->_iBlockCount;

	memset(_pData, 0x00, _pHead->_iBlockCount*_pHead->_iBlockSize);

	unsigned char *pt = _pData;
	for (size_t i = 0; i != _pHead->_iBlockCount; pt += _pHead->_iBlockSize)
	{
		++i;
		memcpy(pt, &i, sizeof(size_t)); //每块第一个直接指向下一个可用的block编号, 变成一个链表
	}
}

NFMemChunk::tagChunkHead NFMemChunk::getChunkHead() const
{
	return *_pHead;
}

////////////////////////////////////////////////////////////////////
//

NFMemChunkAllocator::NFMemChunkAllocator()
	: _pHead(NULL), _pChunk(NULL)
{
}

void NFMemChunkAllocator::init(void *pAddr)
{
	_pHead = static_cast<tagChunkAllocatorHead*>(pAddr);
	_pChunk = (char*)_pHead + sizeof(tagChunkAllocatorHead);
}

void NFMemChunkAllocator::initChunk()
{
	assert(_pHead->_iSize > sizeof(tagChunkAllocatorHead));

	size_t iChunkCapacity = _pHead->_iSize - sizeof(tagChunkAllocatorHead);

	assert(iChunkCapacity > NFMemChunk::getHeadSize());

	size_t  iBlockCount = (iChunkCapacity - NFMemChunk::getHeadSize()) / _pHead->_iBlockSize;

	assert(iBlockCount > 0);

	_chunk.create((void*)((char *)_pChunk), _pHead->_iBlockSize, iBlockCount);
}

void NFMemChunkAllocator::create(void *pAddr, size_t iSize, size_t iBlockSize)
{
	init(pAddr);

	_pHead->_iSize = iSize;
	_pHead->_iBlockSize = iBlockSize;

	initChunk();
}

void NFMemChunkAllocator::connectChunk()
{
	assert(_pHead->_iSize > sizeof(tagChunkAllocatorHead));

	//size_t iChunkCapacity = _pHead->_iSize - sizeof(tagChunkAllocatorHead);

	//assert(iChunkCapacity > NFMemChunk::getHeadSize());

	_chunk.connect((void*)((char *)_pChunk));
}

void NFMemChunkAllocator::connect(void *pAddr)
{
	init(pAddr);

	connectChunk();
}

void NFMemChunkAllocator::rebuild()
{
	_chunk.rebuild();
}

void* NFMemChunkAllocator::allocate()
{
	return _chunk.allocate();
}

void* NFMemChunkAllocator::allocate2(size_t &iIndex)
{
	return _chunk.allocate2(iIndex);
}

void NFMemChunkAllocator::deallocate(void *pAddr)
{
	assert(pAddr >= _pChunk);

	_chunk.deallocate(pAddr);
}

void NFMemChunkAllocator::deallocate2(size_t iIndex)
{
	_chunk.deallocate2(iIndex);
}

NFMemChunk::tagChunkHead NFMemChunkAllocator::getBlockDetail() const
{
	return _chunk.getChunkHead();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
NFMemMultiChunkAllocator::NFMemMultiChunkAllocator()
	: _pHead(NULL), _pChunk(NULL), _iBlockCount(0), _iAllIndex(0), _nallocator(NULL)
{
}

NFMemMultiChunkAllocator::~NFMemMultiChunkAllocator()
{
	clear();
}

void NFMemMultiChunkAllocator::clear()
{
	for (size_t i = 0; i < _allocator.size(); i++)
	{
		delete _allocator[i];
	}
	_allocator.clear();

	if (_nallocator)
	{
		_nallocator->clear();
		delete _nallocator;
		_nallocator = NULL;
	}

	_vBlockSize.clear();

	_pHead = NULL;
	_pChunk = NULL;
	_iBlockCount = 0;
	_iAllIndex = 0;
}

std::vector<size_t> NFMemMultiChunkAllocator::getBlockSize()  const
{
	std::vector<size_t> v = _vBlockSize;
	if (_nallocator)
	{
		std::vector<size_t> vNext = _nallocator->getBlockSize();
		std::copy(vNext.begin(), vNext.end(), std::inserter(v, v.end()));
	}

	return v;
}

size_t NFMemMultiChunkAllocator::getCapacity() const
{
	size_t iCapacity = 0;
	for (size_t i = 0; i < _allocator.size(); i++)
	{
		iCapacity += _allocator[i]->getCapacity();
	}

	if (_nallocator)
	{
		iCapacity += _nallocator->getCapacity();
	}

	return iCapacity;
}

std::vector<NFMemChunk::tagChunkHead> NFMemMultiChunkAllocator::getBlockDetail() const
{
	std::vector<NFMemChunk::tagChunkHead> vt;
	for (size_t i = 0; i < _allocator.size(); i++)
	{
		vt.push_back(_allocator[i]->getBlockDetail());
	}

	if (_nallocator)
	{
		std::vector<NFMemChunk::tagChunkHead> v = _nallocator->getBlockDetail();

		std::copy(v.begin(), v.end(), std::inserter(vt, vt.end()));
	}

	return vt;
}

std::vector<size_t> NFMemMultiChunkAllocator::singleBlockChunkCount() const
{
	std::vector<size_t> vv;
	vv.push_back(_iBlockCount);

	if (_nallocator)
	{
		std::vector<size_t> v = _nallocator->singleBlockChunkCount();
		std::copy(v.begin(), v.end(), std::inserter(vv, vv.end()));
	}

	return vv;
}

size_t NFMemMultiChunkAllocator::allBlockChunkCount() const
{
	size_t n = _iBlockCount * _vBlockSize.size();

	if (_nallocator)
	{
		n += _nallocator->allBlockChunkCount();
	}

	return n;
}

void NFMemMultiChunkAllocator::init(void *pAddr)
{
	_pHead = static_cast<tagChunkAllocatorHead*>(pAddr);
	_pChunk = (char*)_pHead + sizeof(tagChunkAllocatorHead);
}

void NFMemMultiChunkAllocator::calc()
{
	_vBlockSize.clear();

	//每种block大小总和
	size_t sum = 0;
	for (size_t n = _pHead->_iMinBlockSize; n < _pHead->_iMaxBlockSize; )
	{
		sum += n;
		_vBlockSize.push_back(n);

		if (_pHead->_iMaxBlockSize > _pHead->_iMinBlockSize)
		{
			n = (std::max)((size_t)(n*_pHead->_fFactor), n + 1);    //至少内存块大小要+1
		}
	}

	sum += _pHead->_iMaxBlockSize;
	_vBlockSize.push_back(_pHead->_iMaxBlockSize);

	assert(_pHead->_iSize > (NFMemMultiChunkAllocator::getHeadSize() + NFMemChunkAllocator::getHeadSize()*_vBlockSize.size() + NFMemChunk::getHeadSize()*_vBlockSize.size()));

	//计算块的个数
	_iBlockCount = (_pHead->_iSize
		- NFMemMultiChunkAllocator::getHeadSize()
		- NFMemChunkAllocator::getHeadSize() * _vBlockSize.size()
		- NFMemChunk::getHeadSize() * _vBlockSize.size()) / sum;

	assert(_iBlockCount >= 1);
}

void NFMemMultiChunkAllocator::create(void *pAddr, size_t iSize, size_t iMinBlockSize, size_t iMaxBlockSize, float fFactor)
{
	assert(iMaxBlockSize >= iMinBlockSize);
	assert(fFactor >= 1.0);

	init(pAddr);

	_pHead->_iSize = iSize;
	_pHead->_iTotalSize = iSize;
	_pHead->_iMinBlockSize = iMinBlockSize;
	_pHead->_iMaxBlockSize = iMaxBlockSize;
	_pHead->_fFactor = fFactor;
	_pHead->_iNext = 0;

	calc();

	//初始化每种快的分配器
	char *pChunkBegin = (char*)_pChunk;
	for (size_t i = 0; i < _vBlockSize.size(); i++)
	{
		NFMemChunkAllocator *p = new NFMemChunkAllocator;
		size_t iAllocSize = NFMemChunkAllocator::getHeadSize() + NFMemChunk::calcMemSize(_vBlockSize[i], _iBlockCount);
		p->create(pChunkBegin, iAllocSize, _vBlockSize[i]);
		pChunkBegin += iAllocSize;
		_allocator.push_back(p);
	}

	_iAllIndex = _allocator.size() * getBlockCount();
}

void NFMemMultiChunkAllocator::connect(void *pAddr)
{
	clear();

	init(pAddr);

	calc();

	//初始化每种块的分配器
	char *pChunkBegin = (char*)_pChunk;
	for (size_t i = 0; i < _vBlockSize.size(); i++)
	{
		NFMemChunkAllocator *p = new NFMemChunkAllocator;

		p->connect(pChunkBegin);
		pChunkBegin += NFMemChunkAllocator::getHeadSize() + NFMemChunk::calcMemSize(_vBlockSize[i], _iBlockCount);
		_allocator.push_back(p);
	}

	_iAllIndex = _allocator.size() * getBlockCount();

	//没有后续的空间了
	if (_pHead->_iNext == 0)
	{
		return;
	}

	assert(_pHead->_iNext == _pHead->_iSize);
	assert(_nallocator == NULL);

	//下一块地址, 注意这里是嵌套的, 扩展分配空间的时候注意 
	tagChunkAllocatorHead   *pNextHead = (tagChunkAllocatorHead   *)((char*)_pHead + _pHead->_iNext);
	_nallocator = new NFMemMultiChunkAllocator();
	_nallocator->connect(pNextHead);
}

void NFMemMultiChunkAllocator::rebuild()
{
	for (size_t i = 0; i < _allocator.size(); i++)
	{
		_allocator[i]->rebuild();
	}

	if (_nallocator)
	{
		_nallocator->rebuild();
	}
}

NFMemMultiChunkAllocator *NFMemMultiChunkAllocator::lastAlloc()
{
	if (_nallocator == NULL)
		return NULL;

	NFMemMultiChunkAllocator *p = _nallocator;

	while (p && p->_nallocator)
	{
		p = p->_nallocator;
	}

	return p;
}

void NFMemMultiChunkAllocator::append(void *pAddr, size_t iSize)
{
	connect(pAddr);

	//扩展后的空间地址一定需要>开始的空间
	assert(iSize > _pHead->_iTotalSize);

	//扩展空间部分的真实起始地址
	void *pAppendAddr = (char*)pAddr + _pHead->_iTotalSize;

	//扩展的部分初始化, 注意这里p不用delete, 最后系统的时候会循环delete所有分配器
	NFMemMultiChunkAllocator *p = new NFMemMultiChunkAllocator();
	p->create(pAppendAddr, iSize - _pHead->_iTotalSize, _pHead->_iMinBlockSize, _pHead->_iMaxBlockSize, _pHead->_fFactor);

	//扩展部分连接到最后一个分配块最后
	NFMemMultiChunkAllocator *palloc = lastAlloc();
	if (palloc)
	{
		palloc->_pHead->_iNext = (char*)pAppendAddr - (char*)palloc->_pHead;
		palloc->_nallocator = p;
	}
	else
	{
		_pHead->_iNext = (char*)pAppendAddr - (char*)_pHead;
		_nallocator = p;
	}

	assert(_pHead->_iNext == _pHead->_iSize);

	//总计大小
	_pHead->_iTotalSize = iSize;
}

void* NFMemMultiChunkAllocator::allocate(size_t iNeedSize, size_t &iAllocSize)
{
	size_t iIndex;
	return allocate2(iNeedSize, iAllocSize, iIndex);
}

void *NFMemMultiChunkAllocator::allocate2(size_t iNeedSize, size_t &iAllocSize, size_t &iIndex)
{
	void *p = NULL;
	iIndex = 0;

	for (size_t i = 0; i < _allocator.size(); i++)
	{
		//首先分配大小刚刚超过的
		if (_allocator[i]->getBlockSize() >= iNeedSize)
		{
			size_t n;
			p = _allocator[i]->allocate2(n);
			if (p != NULL)
			{
				iAllocSize = _vBlockSize[i];
				iIndex += i * getBlockCount() + n;
				return p;
			}
		}
	}

	//没有比数据更大的数据块了
	for (size_t i = _allocator.size(); i != 0; i--)
	{
		//首先分配大小刚刚小于的
		if (_allocator[i - 1]->getBlockSize() < iNeedSize)
		{
			size_t n;
			p = _allocator[i - 1]->allocate2(n);
			if (p != NULL)
			{
				iAllocSize = _vBlockSize[i - 1];
				iIndex += (i - 1) * getBlockCount() + n;
				return p;
			}
		}
	}

	//后续的扩展块分配空间, 注意对象是递归的, 因此只需要分配一个块就可以了
	if (_nallocator)
	{
		p = _nallocator->allocate2(iNeedSize, iAllocSize, iIndex);
		if (p != NULL)
		{
			iIndex += _iAllIndex;
			return p;
		}
	}

	return NULL;
}

void NFMemMultiChunkAllocator::deallocate(void *pAddr)
{
	if (pAddr < (void*)((char*)_pHead + _pHead->_iSize))
	{
		char *pChunkBegin = (char*)_pChunk;

		for (size_t i = 0; i < _vBlockSize.size(); i++)
		{
			pChunkBegin += _allocator[i]->getMemSize();
			//            pChunkBegin += TC_MemChunkAllocator::getHeadSize() + TC_MemChunk::calcMemSize(_vBlockSize[i], _iBlockCount);

			if ((char*)pAddr < pChunkBegin)
			{
				_allocator[i]->deallocate(pAddr);
				return;
			}
		}

		assert(false);
	}
	else
	{
		if (_nallocator)
		{
			_nallocator->deallocate(pAddr);
			return;
		}
	}

	assert(false);
}

void NFMemMultiChunkAllocator::deallocate2(size_t iIndex)
{
	for (size_t i = 0; i < _allocator.size(); i++)
	{
		if (iIndex <= getBlockCount())
		{
			_allocator[i]->deallocate2(iIndex);
			return;
		}
		iIndex -= getBlockCount();
	}

	if (_nallocator)
	{
		_nallocator->deallocate2(iIndex);
		return;
	}

	assert(false);
}

void* NFMemMultiChunkAllocator::getAbsolute(size_t iIndex)
{
	if (iIndex == 0)
	{
		return NULL;
	}

	size_t n = _iAllIndex;
	if (iIndex <= n)
	{
		size_t i = (iIndex - 1) / getBlockCount();
		iIndex -= i * getBlockCount();
		return _allocator[i]->getAbsolute(iIndex);
	}
	else
	{
		iIndex -= n;
	}

	if (_nallocator)
	{
		return _nallocator->getAbsolute(iIndex);
	}

	assert(false);

	return NULL;
}

size_t NFMemMultiChunkAllocator::getRelative(void *pAddr)
{
	if (pAddr == NULL)
	{
		return 0;
	}

	if (pAddr < (char*)_pHead + _pHead->_iSize)
	{
		for (size_t i = 0; i < _vBlockSize.size(); i++)
		{
			if ((char*)pAddr < ((char*)_allocator[i]->getHead() + _allocator[i]->getMemSize()))
			{
				//注意:索引从1开始计数
				return i * getBlockCount() + _allocator[i]->getRelative(pAddr);
			}
		}
		assert(false);
	}
	else
	{
		if (_nallocator)
		{
			return _iAllIndex + _nallocator->getRelative((char*)pAddr);
		}
	}

	return 0;
}