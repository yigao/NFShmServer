// -------------------------------------------------------------------------
//    @FileName         :    NFException.hpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFException
//
// -------------------------------------------------------------------------

#ifndef NF_EXCEPTION_HPP
#define NF_EXCEPTION_HPP

#include <string>
#include <exception>
#include "NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <execinfo.h>
#include <string.h>
#include <stdlib.h>
#include <cerrno>
#endif

/**
* @brief 异常类.
*/
class NFException : public std::exception
{
public:
	/**
	* @brief 构造函数，提供了一个可以传入errno的构造函数，
	*
	*        异常抛出时直接获取的错误信息
	*
	* @param buffer 异常的告警信息
	*/
	explicit NFException(const std::string &buffer)
		:_buffer(buffer), _code(0)
	{
		//    getBacktrace();
	}

	/**
	* @brief 构造函数,提供了一个可以传入errno的构造函数，
	*
	*        异常抛出时直接获取的错误信息
	*
	* @param buffer 异常的告警信息
	* @param err    错误码, 可用strerror获取错误信息
	*/
	NFException(const std::string &buffer, int err)
	{
		_buffer = buffer + " :" + strerror(err);
		_code = err;
		//    getBacktrace();
	}

	/**
	* @brief 析够数函
	*/
	virtual ~NFException() throw()
	{

	}

	/**
	* @brief 错误信息.
	*
	* @return const char*
	*/
	virtual const char* what() const throw()
	{
		return _buffer.c_str();
	}

	/**
	* @brief 获取错误码
	*
	* @return 成功获取返回0
	*/
	int getErrCode() { return _code; }
private:
	void getBacktrace()
	{
#if NF_PLATFORM == NF_PLATFORM_LINUX
		void * array[64];
		int nSize = backtrace(array, 64);
		char ** symbols = backtrace_symbols(array, nSize);

		for (int i = 0; i < nSize; i++)
		{
			_buffer += symbols[i];
			_buffer += "\n";
		}
		free(symbols);
#endif
	}
private:
	/**
	* 异常的相关信息
	*/
	std::string  _buffer;

	/**
	* 错误码
	*/
	int     _code;
};

#endif

