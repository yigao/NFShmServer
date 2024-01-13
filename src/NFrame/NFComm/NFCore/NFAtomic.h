// -------------------------------------------------------------------------
//    @FileName         :    NFAtomic.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
	NFAtomic() noexcept  : data_() {}
	NFAtomic(value_type desired) noexcept : data_(desired) {}

	inline void store(value_type desired, std::memory_order order = std::memory_order_seq_cst) noexcept
    {
		data_.store(desired, order);
	}

	inline void store(value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		data_.store(desired, order);
	}

	inline value_type load(std::memory_order order = std::memory_order_seq_cst) const  noexcept
	{
		return data_.load(order);
	}

	inline value_type load(std::memory_order order = std::memory_order_seq_cst) const volatile noexcept
	{
		return data_.load(order);
	}

	inline operator value_type() const  noexcept { return load(); }
	inline operator value_type() const volatile  noexcept { return load(); }

	inline value_type operator=(value_type desired) noexcept
	{
		store(desired);
		return desired;
	}

	inline value_type operator=(value_type desired) volatile noexcept
	{
		store(desired);
		return desired;
	}

	inline value_type operator++()  noexcept { return ++data_; }
	inline value_type operator++() volatile  noexcept { return ++data_; }
	inline value_type operator++(int)  noexcept { return data_++; }
	inline value_type operator++(int) volatile  noexcept { return data_++; }
	inline value_type operator--()  noexcept { return --data_; }
	inline value_type operator--() volatile  noexcept { return --data_; }
	inline value_type operator--(int)  noexcept { return data_--; }
	inline value_type operator--(int) volatile  noexcept { return data_--; }

	inline value_type exchange(value_type desired, std::memory_order order = std::memory_order_seq_cst)  noexcept
	{
		return data_.exchange(desired, order);
	}

	inline value_type exchange(value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.exchange(desired, order);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) noexcept
	{
		return data_.compare_exchange_weak(expected, desired, success, failure);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) volatile noexcept
	{
		return data_.compare_exchange_weak(expected, desired, success, failure);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.compare_exchange_weak(expected, desired, order);
	}

	inline bool compare_exchange_weak(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.compare_exchange_weak(expected, desired, order);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) noexcept
	{
		return data_.compare_exchange_strong(expected, desired, success, failure);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order success, std::memory_order failure) volatile noexcept
	{
		return data_.compare_exchange_strong(expected, desired, success, failure);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.compare_exchange_strong(expected, desired, order);
	}

	inline bool compare_exchange_strong(value_type &expected, value_type desired, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.compare_exchange_strong(expected, desired, order);
	}

	inline value_type fetch_add(value_type arg, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.fetch_add(arg, order);
	}

	inline value_type fetch_add(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.fetch_add(arg, order);
	}

	inline value_type fetch_sub(value_type arg, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.fetch_sub(arg, order);
	}

	inline value_type fetch_sub(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.fetch_sub(arg, order);
	}

	inline value_type fetch_and(value_type arg, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.fetch_and(arg, order);
	}

	inline value_type fetch_and(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.fetch_and(arg, order);
	}

	inline value_type fetch_or(value_type arg, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.fetch_or(arg, order);
	}

	inline value_type fetch_or(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.fetch_or(arg, order);
	}

	inline value_type fetch_xor(value_type arg, std::memory_order order = std::memory_order_seq_cst) noexcept
	{
		return data_.fetch_xor(arg, order);
	}

	inline value_type fetch_xor(value_type arg, std::memory_order order = std::memory_order_seq_cst) volatile noexcept
	{
		return data_.fetch_xor(arg, order);
	}
};
