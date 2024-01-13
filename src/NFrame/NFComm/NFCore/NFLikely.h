#pragma once

#if __GNUC__
#define NF_DETAIL_BUILTIN_EXPECT(b, t) (__builtin_expect(b, t))
#else
#define NF_DETAIL_BUILTIN_EXPECT(b, t) b
#endif

//  Likeliness annotations
//
//  Useful when the author has better knowledge than the compiler of whether
//  the branch condition is overwhelmingly likely to take a specific value.
//
//  Useful when the author has better knowledge than the compiler of which code
//  paths are designed as the fast path and which are designed as the slow path,
//  and to force the compiler to optimize for the fast path, even when it is not
//  overwhelmingly likely.

#define NF_LIKELY(x) NF_DETAIL_BUILTIN_EXPECT((x), 1)
#define NF_UNLIKELY(x) NF_DETAIL_BUILTIN_EXPECT((x), 0)

//  Un-namespaced annotations

#undef LIKELY
#undef UNLIKELY

#if defined(__GNUC__)
#define LIKELY(x)   (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define LIKELY(x)   (x)
#define UNLIKELY(x) (x)
#endif

