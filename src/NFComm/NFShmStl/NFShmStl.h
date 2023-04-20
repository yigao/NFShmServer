// -------------------------------------------------------------------------
//    @FileName         :    NFShmStl.h
//    @Author           :    gaoyi
//    @Date             :    23-4-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmStl
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
namespace std
{
    ///////////////////////////stl_construct.h////////////////////////////
    /**
     * Constructs an object in existing memory by invoking an allocated
     * object's constructor with an initializer.
     */
#if __cplusplus >= 201103L
    template<typename _T1, typename... _Args>
    inline void
    _Construct(_T1* __p, _Args&&... __args)
    { ::new(static_cast<void*>(__p)) _T1(std::forward<_Args>(__args)...); }
#else
    template<typename _T1, typename _T2>
    inline void
    _Construct(_T1* __p, const _T2& __value)
    {
      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 402. wrong new expression in [some_]allocator::construct
      ::new(static_cast<void*>(__p)) _T1(__value);
    }
#endif

    /**
     * Destroy the object pointed to by a pointer type.
     */
    template<typename _Tp>
    inline void
    _Destroy(_Tp* __pointer)
    { __pointer->~_Tp(); }

    template<bool>
    struct _Destroy_aux
    {
        template<typename _ForwardIterator>
        static void
        __destroy(_ForwardIterator __first, _ForwardIterator __last)
        {
            for (; __first != __last; ++__first)
                std::_Destroy(std::__addressof(*__first));
        }
    };

    template<>
    struct _Destroy_aux<true>
    {
        template<typename _ForwardIterator>
        static void
        __destroy(_ForwardIterator, _ForwardIterator) { }
    };

    /**
     * Destroy a range of objects.  If the value_type of the object has
     * a trivial destructor, the compiler should optimize all of this
     * away, otherwise the objects' destructors must be invoked.
     */
    template<typename _ForwardIterator>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
    {
        typedef typename iterator_traits<_ForwardIterator>::value_type
                _Value_type;
        std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::
        __destroy(__first, __last);
    }

    /**
     * Destroy a range of objects using the supplied allocator.  For
     * nondefault allocators we do not optimize away invocation of
     * destroy() even if _Tp has a trivial destructor.
     */

    template<typename _ForwardIterator, typename _Allocator>
    void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
             _Allocator& __alloc)
    {
        typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
        for (; __first != __last; ++__first)
            __traits::destroy(__alloc, std::__addressof(*__first));
    }

    template<typename _ForwardIterator, typename _Tp>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
             allocator<_Tp>&)
    {
        _Destroy(__first, __last);
    }

    ///////////////////////////stl_function.h////////////////////////////
    template<typename _Arg, typename _Result>
    struct unary_function
    {
        /// @c argument_type is the type of the argument
        typedef _Arg 	argument_type;

        /// @c result_type is the return type
        typedef _Result 	result_type;
    };

    template<typename _Tp>
    struct _Identity
            : public unary_function<_Tp,_Tp>
    {
        _Tp&
        operator()(_Tp& __x) const
        { return __x; }

        const _Tp&
        operator()(const _Tp& __x) const
        { return __x; }
    };

    template<typename _Pair>
    struct _Select1st
            : public unary_function<_Pair, typename _Pair::first_type>
    {
        typename _Pair::first_type&
        operator()(_Pair& __x) const
        { return __x.first; }

        const typename _Pair::first_type&
        operator()(const _Pair& __x) const
        { return __x.first; }

#if __cplusplus >= 201103L
        template<typename _Pair2>
        typename _Pair2::first_type&
        operator()(_Pair2& __x) const
        { return __x.first; }

        template<typename _Pair2>
        const typename _Pair2::first_type&
        operator()(const _Pair2& __x) const
        { return __x.first; }
#endif
    };

    ///////////////////////cpp_type_traits.h////////////////////////////////////
    struct __true_type { };
    struct __false_type { };

    template<bool>
    struct __truth_type
    { typedef __false_type __type; };

    template<>
    struct __truth_type<true>
    { typedef __true_type __type; };

    // N.B. The conversions to bool are needed due to the issue
    // explained in c++/19404.
    template<class _Sp, class _Tp>
    struct __traitor
    {
        enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };
        typedef typename __truth_type<__value>::__type __type;
    };

    // Compare for equality of types.
    template<typename, typename>
    struct __are_same
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<typename _Tp>
    struct __are_same<_Tp, _Tp>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    // Holds if the template-argument is a void type.
    template<typename _Tp>
    struct __is_void
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<>
    struct __is_void<void>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // Integer types
    //
    template<typename _Tp>
    struct __is_integer
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    // Thirteen specializations (yes there are eleven standard integer
    // types; <em>long long</em> and <em>unsigned long long</em> are
    // supported as extensions)
    template<>
    struct __is_integer<bool>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<signed char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<unsigned char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

# ifdef _GLIBCXX_USE_WCHAR_T
    template<>
    struct __is_integer<wchar_t>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };
# endif

#if __cplusplus >= 201103L
    template<>
    struct __is_integer<char16_t>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<char32_t>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };
#endif

    template<>
    struct __is_integer<short>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<unsigned short>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<int>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<unsigned int>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<long>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<unsigned long>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<long long>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_integer<unsigned long long>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // Floating point types
    //
    template<typename _Tp>
    struct __is_floating
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    // three specializations (float, double and 'long double')
    template<>
    struct __is_floating<float>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_floating<double>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_floating<long double>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // Pointer types
    //
    template<typename _Tp>
    struct __is_pointer
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<typename _Tp>
    struct __is_pointer<_Tp*>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // Normal iterator type
    //
    template<typename _Tp>
    struct __is_normal_iterator
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<typename _Iterator, typename _Container>
    struct __is_normal_iterator< __gnu_cxx::__normal_iterator<_Iterator,
            _Container> >
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // An arithmetic type is an integer type or a floating point type
    //
    template<typename _Tp>
    struct __is_arithmetic
            : public __traitor<__is_integer<_Tp>, __is_floating<_Tp> >
    { };

    //
    // A fundamental type is `void' or and arithmetic type
    //
    template<typename _Tp>
    struct __is_fundamental
            : public __traitor<__is_void<_Tp>, __is_arithmetic<_Tp> >
    { };

    //
    // A scalar type is an arithmetic type or a pointer type
    //
    template<typename _Tp>
    struct __is_scalar
            : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp> >
    { };

    //
    // For use in std::copy and std::find overloads for streambuf iterators.
    //
    template<typename _Tp>
    struct __is_char
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<>
    struct __is_char<char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

#ifdef _GLIBCXX_USE_WCHAR_T
    template<>
    struct __is_char<wchar_t>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };
#endif

    template<typename _Tp>
    struct __is_byte
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

    template<>
    struct __is_byte<char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_byte<signed char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    template<>
    struct __is_byte<unsigned char>
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };

    //
    // Move iterator type
    //
    template<typename _Tp>
    struct __is_move_iterator
    {
        enum { __value = 0 };
        typedef __false_type __type;
    };

#if __cplusplus >= 201103L
    template<typename _Iterator>
    class move_iterator;

    template<typename _Iterator>
    struct __is_move_iterator< move_iterator<_Iterator> >
    {
        enum { __value = 1 };
        typedef __true_type __type;
    };
#endif
} // namespace std




#endif
