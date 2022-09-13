// -------------------------------------------------------------------------
//    @FileName         :    NFAtomic.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"
#include <atomic>


template <typename Ty = int>
class NFAtomic
{
public:
	typedef Ty value_type;
private:
	::std::atomic<value_type> data_;
	NFAtomic(const NFAtomic &);
#ifndef _MSC_VER
	NFAtomic &operator=(const NFAtomic &);
	NFAtomic &operator=(const NFAtomic &) volatile;
#endif

public:
	NFAtomic() : data_() {}
	NFAtomic(value_type desired) : data_(desired) {}

	inline void store(value_type desired, std::memory_order order = std::memory_order_seq_cst)
	{
		data_.store(desired, order);
	}

	inline void store(value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		data_.store(desired, order);
	}

	inline value_type load(std::memory_order order = std::memory_order_seq_cst) const
	{
		return data_.load(order);
	}

	inline value_type load(std::memory_order order = std::memory_order_seq_cst) const volatile
	{
		return data_.load(order);
	}

	inline operator value_type() const { return load(); }
	inline operator value_type() const volatile { return load(); }

	inline value_type operator=(value_type desired)
	{
		store(desired);
		return desired;
	}

	inline value_type operator=(value_type desired) volatile
	{
		store(desired);
		return desired;
	}

	inline value_type operator++() { return ++data_; }
	inline value_type operator++() volatile { return ++data_; }
	inline value_type operator++(int) { return data_++; }
	inline value_type operator++(int) volatile { return data_++; }
	inline value_type operator--() { return --data_; }
	inline value_type operator--() volatile { return --data_; }
	inline value_type operator--(int) { return data_--; }
	inline value_type operator--(int) volatile { return data_--; }

	inline value_type exchange(value_type desired, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.exchange(desired, order);
	}

	inline value_type exchange(value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.exchange(desired, order);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure)
	{
		return data_.compare_exchange_weak(expected, desired, success, failure);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) volatile
	{
		return data_.compare_exchange_weak(expected, desired, success, failure);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.compare_exchange_weak(expected, desired, order);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.compare_exchange_weak(expected, desired, order);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure)
	{
		return data_.compare_exchange_strong(expected, desired, success, failure);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) volatile
	{
		return data_.compare_exchange_strong(expected, desired, success, failure);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.compare_exchange_strong(expected, desired, order);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.compare_exchange_strong(expected, desired, order);
	}

	inline value_type fetch_add(value_type arg, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.fetch_add(arg, order);
	}

	inline value_type fetch_add(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.fetch_add(arg, order);
	}

	inline value_type fetch_sub(value_type arg, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.fetch_sub(arg, order);
	}

	inline value_type fetch_sub(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.fetch_sub(arg, order);
	}

	inline value_type fetch_and(value_type arg, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.fetch_and(arg, order);
	}

	inline value_type fetch_and(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.fetch_and(arg, order);
	}

	inline value_type fetch_or(value_type arg, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.fetch_or(arg, order);
	}

	inline value_type fetch_or(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.fetch_or(arg, order);
	}

	inline value_type fetch_xor(value_type arg, std::memory_order order = std::memory_order_seq_cst)
	{
		return data_.fetch_xor(arg, order);
	}

	inline value_type fetch_xor(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile
	{
		return data_.fetch_xor(arg, order);
	}
};
