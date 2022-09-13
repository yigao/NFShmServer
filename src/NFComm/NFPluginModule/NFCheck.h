// -------------------------------------------------------------------------
//    @FileName         :    NFCheck.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFLogMgr.h"
#include "NFComm/NFCore/NFPlatform.h"

#ifndef _USE_ASSERT_
#define _USE_ASSERT_ 0
#endif

#if _USE_ASSERT_
#define assert_i(exp) NF_ASSERT(exp)
#else
#define assert_i(exp)
#endif

#ifndef CHECK_EXPR
#define CHECK_EXPR(expr, ret, format, ...)\
    do {\
        if (unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
			assert_i(expr);\
			return ret;\
        }\
    }while(0)
#endif//CHECK_EXPR

#ifndef CHECK_EXPR_NOT_RET
#define CHECK_EXPR_NOT_RET(expr, format, ...)\
    do {\
        if (unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
        }\
    }while(0)
#endif//CHECK_EXPR_NOT_RET

#ifndef CHECK_EXPR_ASSERT
#define CHECK_EXPR_ASSERT(expr, ret, format, ...)\
    do {\
        if (unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
			NF_ASSERT(expr);\
			return ret;\
        }\
    }while(0)
#endif//CHECK_EXPR

#ifndef CHECK_RET
#define CHECK_RET(ret, format, ...) CHECK_EXPR(0 == ret, ret, format, ##__VA_ARGS__) 
#endif//CHECK_RET

#ifndef CHECK_RET_ASSERT
#define CHECK_RET_ASSERT(ret, format, ...) CHECK_EXPR_ASSERT(0 == ret, ret, format, ##__VA_ARGS__)
#endif//CHECK_RET

#ifndef CHECK_PLAYER_EXPR
#define CHECK_PLAYER_EXPR(id, expr, ret, format, ...)\
    do {\
        if (unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, id, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
			assert_i(expr);\
			return ret;\
        }\
    }while(0)
#endif//CHECK_PLAYER_EXPR

#ifndef CHECK_PLAYER_RET
#define CHECK_PLAYER_RET(id, ret, format, ...) CHECK_PLAYER_EXPR(id, 0 == ret, ret, format, ##__VA_ARGS__) 
#endif//CHECK_PLAYER_RET

#ifndef CHECK_NULL
#define CHECK_NULL(ptr) CHECK_EXPR(ptr, -1, "");
#endif //CHECK_NULL

#ifndef CHECK_NULL_ASSERT
#define CHECK_NULL_ASSERT(ptr) CHECK_EXPR_ASSERT(ptr, -1, "");
#endif //CHECK_NULL

#ifndef CHECK_PLAYER_NULL
#define CHECK_PLAYER_NULL(id, ptr) CHECK_PLAYER_EXPR(id, ptr, -1, "")
#endif//CHECK_PLAYER_NULL

template<bool> struct CompileTimeError;
template<> struct CompileTimeError<true> {};

#ifndef COMPILE_TIME_ASSERT
#define COMPILE_TIME_ASSERT(expr) \
    (CompileTimeError<(expr) != 0> ())
#endif //COMPILE_TIME_ASSERT

#ifndef CHECK_EXPR_BREAK
#define CHECK_EXPR_BREAK(expr, format, ...)\
    {\
        if(unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
            break;\
		}\
	}
#endif//CHECK_EXPR_CONTINUE

#ifndef CHECK_NULL_BREAK
#define CHECK_NULL_BREAK(ptr) CHECK_EXPR_CONTINUE(ptr)
#endif//CHECK_NULL_CONTINUE

#ifndef CHECK_EXPR_CONTINUE
#define CHECK_EXPR_CONTINUE(expr, format, ...)\
    {\
        if(unlikely(!(expr)))\
        {\
           try {\
                std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
			    NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK {} failed:{}", #expr, log_event);\
            }\
            catch (fmt::v5::format_error& error) {\
                NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", error.what());\
            }\
            continue;\
		}\
	}
#endif//CHECK_EXPR_CONTINUE

#ifndef CHECK_NULL_CONTINUE
#define CHECK_NULL_CONTINUE(ptr) CHECK_EXPR_CONTINUE(ptr)
#endif//CHECK_NULL_CONTINUE

#ifndef CHECK_EXPR_RETURN
#define CHECK_EXPR_RETURN(expr)\
    do {\
        if(unlikely(!(expr)))\
        {\
            return 0;\
        }\
    }while(0)
#endif//CHECK_EXPR_RETURN

#ifndef CHECK_NULL_RETURN
#define CHECK_NULL_RETURN(ptr) CHECK_EXPR_RETURN(ptr)
#endif//CHECK_NULL_RETURN


