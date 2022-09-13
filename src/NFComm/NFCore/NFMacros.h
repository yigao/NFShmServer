// -------------------------------------------------------------------------
//    @FileName         :    NFMacros.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// ------------------------------------------------------------------------

#pragma once

#define NF_DISALLOW_EVIL_CONSTRUCTORS(TypeName)    \
  TypeName(const TypeName&);                           \
  void operator=(const TypeName&)

#define NF_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName();                                           \
  TypeName(const TypeName&);                            \
  void operator=(const TypeName&)

#define NF_ARRAYSIZE(Array) (sizeof(Array)/sizeof(Array[0]))

/*
优化分支预测，
编写代码时可以根据判断条件发生的概率来优化处理器的取指操作
unlikely 表示你可以确认该条件是极少发生的，相反likely表示该条件多数情况下会发生
*/
#if defined(__GNUC__)
#define likely(x) __builtin_expect ((x), 1)
#define unlikely(x) __builtin_expect ((x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#define __builtin_expect(expr, val)   (expr)
#endif
