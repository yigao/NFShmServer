// -------------------------------------------------------------------------
//    @FileName         :    NFMemoryPool.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFMemoryPool
//
// -------------------------------------------------------------------------

#pragma once

#include <climits>
#include <cstddef>

template<typename T, size_t BlockSize = 4096>
class NFMemoryPool
{
public:
    /* Member types */
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef const T *const_pointer;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::false_type propagate_on_container_copy_assignment;
    typedef std::true_type propagate_on_container_move_assignment;
    typedef std::true_type propagate_on_container_swap;

    template<typename U>
    struct rebind
    {
        typedef NFMemoryPool<U> other;
    };

    /* Member functions */
    NFMemoryPool() noexcept;

    NFMemoryPool(const NFMemoryPool &memoryPool) noexcept;

    NFMemoryPool(NFMemoryPool &&memoryPool) noexcept;

    template<class U>
    NFMemoryPool(const NFMemoryPool<U> &memoryPool) noexcept;

    ~NFMemoryPool() noexcept;

    NFMemoryPool &operator=(const NFMemoryPool &memoryPool) = delete;

    NFMemoryPool &operator=(NFMemoryPool &&memoryPool) noexcept;

    pointer Address(reference x) const noexcept;

    const_pointer Address(const_reference x) const noexcept;

    // Can only allocate one object at a time. n and hint are ignored
    pointer Alloc(size_type n = 1, const_pointer hint = 0);

    void Free(pointer p, size_type n = 1);

    size_type MaxSize() const noexcept;

    template<class U, class... Args>
    void Construct(U *p, Args &&... args);

    template<class U>
    void Destroy(U *p);

    template<class... Args>
    pointer NewElement(Args &&... args);

    void DeleteElement(pointer p);

private:
    union Slot_
    {
        value_type element;
        Slot_ *next;
    };

    typedef char *data_pointer_;
    typedef Slot_ slot_type_;
    typedef Slot_ *slot_pointer_;

    slot_pointer_ currentBlock_;
    slot_pointer_ currentSlot_;
    slot_pointer_ lastSlot_;
    slot_pointer_ freeSlots_;

    size_type padPointer(data_pointer_ p, size_type align) const noexcept;

    void allocateBlock();

    static_assert(BlockSize >= 2 * sizeof(slot_type_), "BlockSize too small.");
};


template<typename T, size_t BlockSize>
inline typename NFMemoryPool<T, BlockSize>::size_type
NFMemoryPool<T, BlockSize>::padPointer(data_pointer_ p, size_type align)
const noexcept
{
    uintptr_t result = reinterpret_cast<uintptr_t>(p);
    return ((align - result) % align);
}


template<typename T, size_t BlockSize>
NFMemoryPool<T, BlockSize>::NFMemoryPool()
noexcept
{
    currentBlock_ = nullptr;
    currentSlot_ = nullptr;
    lastSlot_ = nullptr;
    freeSlots_ = nullptr;
}


template<typename T, size_t BlockSize>
NFMemoryPool<T, BlockSize>::NFMemoryPool(const NFMemoryPool &memoryPool)
noexcept :
        NFMemoryPool() {}


template<typename T, size_t BlockSize>
NFMemoryPool<T, BlockSize>::NFMemoryPool(NFMemoryPool &&memoryPool)
noexcept
{
    currentBlock_ = memoryPool.currentBlock_;
    memoryPool.currentBlock_ = nullptr;
    currentSlot_ = memoryPool.currentSlot_;
    lastSlot_ = memoryPool.lastSlot_;
    freeSlots_ = memoryPool.freeSlots;
}


template<typename T, size_t BlockSize>
template<class U>
NFMemoryPool<T, BlockSize>::NFMemoryPool(const NFMemoryPool<U> &memoryPool)
noexcept :
        NFMemoryPool() {}


template<typename T, size_t BlockSize>
NFMemoryPool<T, BlockSize> &
NFMemoryPool<T, BlockSize>::operator=(NFMemoryPool &&memoryPool)
noexcept
{
    if (this != &memoryPool)
    {
        std::swap(currentBlock_, memoryPool.currentBlock_);
        currentSlot_ = memoryPool.currentSlot_;
        lastSlot_ = memoryPool.lastSlot_;
        freeSlots_ = memoryPool.freeSlots;
    }
    return *this;
}


template<typename T, size_t BlockSize>
NFMemoryPool<T, BlockSize>::~NFMemoryPool()
noexcept
{
    slot_pointer_ curr = currentBlock_;
    while (curr != nullptr)
    {
        slot_pointer_ prev = curr->next;
        operator delete(reinterpret_cast<void *>(curr));
        curr = prev;
    }
}


template<typename T, size_t BlockSize>
inline typename NFMemoryPool<T, BlockSize>::pointer
NFMemoryPool<T, BlockSize>::Address(reference x)
const noexcept
{
    return &x;
}


template<typename T, size_t BlockSize>
inline typename NFMemoryPool<T, BlockSize>::const_pointer
NFMemoryPool<T, BlockSize>::Address(const_reference x)
const noexcept
{
    return &x;
}


template<typename T, size_t BlockSize>
void
NFMemoryPool<T, BlockSize>::allocateBlock()
{
    // Allocate space for the new block and store a pointer to the previous one
    data_pointer_ newBlock = reinterpret_cast<data_pointer_>
    (operator new(BlockSize));
    reinterpret_cast<slot_pointer_>(newBlock)->next = currentBlock_;
    currentBlock_ = reinterpret_cast<slot_pointer_>(newBlock);
    // Pad block body to staisfy the alignment requirements for elements
    data_pointer_ body = newBlock + sizeof(slot_pointer_);
    size_type bodyPadding = padPointer(body, alignof(slot_type_));
    currentSlot_ = reinterpret_cast<slot_pointer_>(body + bodyPadding);
    lastSlot_ = reinterpret_cast<slot_pointer_>
    (newBlock + BlockSize - sizeof(slot_type_) + 1);
}


template<typename T, size_t BlockSize>
inline typename NFMemoryPool<T, BlockSize>::pointer
NFMemoryPool<T, BlockSize>::Alloc(size_type n, const_pointer hint)
{
    if (freeSlots_ != nullptr)
    {
        pointer result = reinterpret_cast<pointer>(freeSlots_);
        freeSlots_ = freeSlots_->next;
        return result;
    } else
    {
        if (currentSlot_ >= lastSlot_)
            allocateBlock();
        return reinterpret_cast<pointer>(currentSlot_++);
    }
}


template<typename T, size_t BlockSize>
inline void
NFMemoryPool<T, BlockSize>::Free(pointer p, size_type n)
{
    if (p != nullptr)
    {
        reinterpret_cast<slot_pointer_>(p)->next = freeSlots_;
        freeSlots_ = reinterpret_cast<slot_pointer_>(p);
    }
}


template<typename T, size_t BlockSize>
inline typename NFMemoryPool<T, BlockSize>::size_type
NFMemoryPool<T, BlockSize>::MaxSize()
const noexcept
{
    size_type maxBlocks = -1 / BlockSize;
    return (BlockSize - sizeof(data_pointer_)) / sizeof(slot_type_) * maxBlocks;
}


template<typename T, size_t BlockSize>
template<class U, class... Args>
inline void
NFMemoryPool<T, BlockSize>::Construct(U *p, Args &&... args)
{
    new(p) U(std::forward<Args>(args)...);
}


template<typename T, size_t BlockSize>
template<class U>
inline void
NFMemoryPool<T, BlockSize>::Destroy(U *p)
{
    p->~U();
}


template<typename T, size_t BlockSize>
template<class... Args>
inline typename NFMemoryPool<T, BlockSize>::pointer
NFMemoryPool<T, BlockSize>::NewElement(Args &&... args)
{
    pointer result = Alloc();
    Construct<value_type>(result, std::forward<Args>(args)...);
    return result;
}


template<typename T, size_t BlockSize>
inline void
NFMemoryPool<T, BlockSize>::DeleteElement(pointer p)
{
    if (p != nullptr)
    {
        p->~value_type();
        Free(p);
    }
}



