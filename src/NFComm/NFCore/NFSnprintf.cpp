// -------------------------------------------------------------------------
//    @FileName         :    NFSnprintf.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFPlatform.h"
#include "NFSnprintf.h"

#if NF_PLATFORM_WIN == NF_PLATFORM
#include <stdarg.h>

# ifdef __STDC_WANT_SECURE_LIB__

int NFSafeSnprintf(char* buf, size_t size, const char* fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	int ret = NFSafeVsnprintf(buf, size, fmt, ap); // 调用 NFSafeVsnprintf
	va_end(ap);
	return ret;
}

int NFSafeVsnprintf(char* buf, size_t size, const char* fmt, va_list ap)
{
	if (size == 0)
	{
		buf[0] = 0;
		return -1;
	}

	int ret = ::_vsnprintf_s(buf, size, _TRUNCATE, fmt, ap);
	if (ret < 0)
		return -1;
	else
		return ret;
}

# else

int NFSafeSnprintf(char *buf, size_t size, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	int ret = NFSafeVsnprintf(buf, size, fmt, ap);  // 调用 NFSafeVsnprintf
	va_end(ap);
	return ret;
}

int NFSafeVsnprintf(char *buf, size_t size, const char *fmt, va_list ap)
{
	if (size == 0)
	{
		buf[0] = 0;
		return -1;
	}

	int   ret = ::_vsnprintf(buf, size, fmt, ap);
	if (ret < 0 || ret >= (int)size)
	{
		buf[size - 1] = 0;
		return -1;
	}
	else
		return ret;
}

# endif // __STDC_WANT_SECURE_LIB__


#else

int NFSafeSnprintf(char *buf, size_t size, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	int ret = NFSafeVsnprintf(buf, size, fmt, ap);  // 调用 NFSafeVsnprintf
	va_end(ap);
	return ret;
}

int NFSafeVsnprintf(char *buf, size_t size, const char *fmt, va_list ap)
{
	return ::vsnprintf(buf, size, fmt, ap);
}

#endif // !ACL_WINDOWS


