// -------------------------------------------------------------------------
//    @FileName         :    NFSizeString.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFComm/NFCore/NFPlatform.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef WIN32
	#include <winsock2.h>
    #pragma comment(lib, "ws2_32.lib")

    // WIN32下没有PF_LOCAL，为了能编译，用PF_INET代替
    #ifndef PF_LOCAL
        #define PF_LOCAL  PF_INET
    #endif
#else
	#include <unistd.h>
	#include <fcntl.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/socket.h>
    #include <sys/un.h>
	#include <sys/ioctl.h>
	#include <netinet/in.h>
	#include <netinet/tcp.h>
	#include <arpa/inet.h>
#endif

/**
* Code队列.
* 如果这个queue只有两个对象单工使用, 那么可以不用互斥
*/
class NFCodeQueue
{
private:
	enum { SPACE = 8 };

public:
	NFCodeQueue() {}
	~NFCodeQueue() {}

	int Init(int len)
	{
		offset_ = sizeof(NFCodeQueue);
		size_ = len - sizeof(NFCodeQueue);
		read_ = 0;
		write_ = 0;
		create_time_ = (unsigned int) time(0);
		* (char*) GetBuffer() = 0;

		checksum_ = (unsigned int)offset_ ^ (unsigned int)size_ ^ (unsigned int) create_time_;
		return 0;
	}

	char* GetBuffer() const { return (char*)this + offset_; }
	int GetSize() const { return size_; }
	int GetFreeSize() const
	{
		if (read_ > write_)
		{
			return read_ - write_ - SPACE - sizeof(int);
		}
		else
		{
			return size_ - write_ + read_ - SPACE - sizeof(int);
		}
	}

    /**
    * 向队列放入一个Code
    * @param[in] p
    * @param[in] len
    * @return 0正确 -1参数错误 -2缓冲区满
    */
	int Put(const char* p, int len)
	{
		if (len == 0)
        {
			return 0;
        }

		// 每次放入的长度最大不能超过0xFFFFFF = 16M
		if (len < 0 || len > (size_ - SPACE - (int)sizeof(int)) || len > 0xFFFFFF)
        {
			return -1;
        }

		// newpos是完成Put后write_的位置
		// wrap表示是否换行了
		const int startpos = write_ + sizeof(int);
		const int minpos = (read_ < SPACE ? size_ : 0) + read_ - SPACE;
		int newpos = startpos + len;
		int wrap = 0;
		if (newpos >= size_)
		{
			newpos -= size_;
			wrap = 1;
		}

		// 判断是否会满
		if (write_ > minpos)
		{
			if (wrap && newpos > minpos) // 满
			{
				return -2;
			}
		}
		else
		{
			if (wrap || newpos > minpos) // 满
            {
				return -2;
            }
		}

		if (wrap)
		{
			// buf起始位置已经超过了size_
			if (startpos >= size_)
			{
				memcpy(GetBuffer() + startpos - size_, p, len);
			}
			else
			{
				memcpy(GetBuffer() + startpos, p, size_ - startpos );
				memcpy(GetBuffer(), p + size_ - startpos, len - size_ + startpos );
			}
		}
		else
		{
			memcpy(GetBuffer() + startpos, p, len);
		}

		// 预先把下个头部长度设为0
		*(char*)(GetBuffer() + newpos) = 0;

		// 调整write_指针
		wrap = write_;
		write_ = newpos;
		newpos = wrap;

		// 把长度写到头部
		len = ntohl(len);
		if (size_ - newpos < (int)sizeof(int))
		{
			memcpy(GetBuffer() + newpos, &len, size_ - newpos);
			memcpy(GetBuffer(), ((char*)&len) + size_ - newpos, sizeof(int) - size_ + newpos);
		}
		else
		{
			memcpy(GetBuffer() + newpos, &len, sizeof(int));
		}

		*(char*)(GetBuffer() + newpos) = 1;

		return 0;
	}

    /**
    * 把两块缓冲区合并成一个Code放入队列中.
    * 这个函数的作用是为了减少1次内存拷贝
    * @param[in] p
    * @param[in] len
    * @return 0正确 -1参数错误 -2缓冲区满
    */
    int Put(const char* p1, int len1, const char* p2, int len2)
    {
        if (p1 == NULL || p2 == NULL || len1 <= 0 || len2 <= 0)
        {
            return -1;
        }

        // 每次放入的长度最大不能超过0xFFFFFF = 16M
        int len = len1 + len2;
        if (len > (size_ - SPACE - (int)sizeof(int)) || len > 0xFFFFFF)
        {
            return -1;
        }

        // newpos是完成Put后write_的位置
        // wrap表示是否换行了
        // minpos是本次write的极限
        const int startpos = write_ + sizeof(int);
        const int minpos = read_ - SPACE + (read_ < SPACE ? size_ : 0);
        int newpos = startpos + len;
        int wrap = 0;
        if (newpos >= size_)
        {
            newpos -= size_;
            wrap = 1;
        }

        // 判断是否会满
        if (write_ > minpos)
        {
            if (wrap && newpos > minpos) // 满
            {
                return -2;
            }
        }
        else
        {
            if (wrap || newpos > minpos) // 满
            {
                return -2;
            }
        }

        if (wrap)
        {
            // buf起始位置已经超过了size_
            if (startpos >= size_)
            {
                memcpy(GetBuffer() + startpos - size_, p1, len1);
                memcpy(GetBuffer() + startpos - size_ + len1, p2, len2);
            }
            else
            {
                const int iLeft = size_ - startpos;
                if (iLeft >= len1)
                {
                    memcpy(GetBuffer() + startpos, p1, len1);
                    memcpy(GetBuffer() + startpos + len1, p2, iLeft - len1);
                    memcpy(GetBuffer(), p2 + iLeft - len1, len2 - iLeft + len1);
                }
                else
                {
                    memcpy(GetBuffer() + startpos, p1, iLeft);
                    memcpy(GetBuffer(), p1 + iLeft, len1 - iLeft);         //org: memcpy(GetBuffer(), p1, len1 - iLeft);  mod by will 2008-10-20
                    memcpy(GetBuffer() + len1 - iLeft, p2, len2);
                }
            }
        }
        else
        {
            memcpy(GetBuffer() + startpos, p1, len1);
            memcpy(GetBuffer() + startpos + len1, p2, len2);
        }

        // 预先把下个头部长度设为0
        *(char*)(GetBuffer() + newpos) = 0;

        // 调整write_指针
        wrap = write_;
        write_ = newpos;
        newpos = wrap;

        // 把长度写到头部
        len = ntohl(len);
        if (size_ - newpos < (int)sizeof(int))
        {
            memcpy(GetBuffer() + newpos, &len, size_ - newpos);
            memcpy(GetBuffer(), ((char*)&len) + size_ - newpos, sizeof(int) - size_ + newpos);
        }
        else
        {
            memcpy(GetBuffer() + newpos, &len, sizeof(int));
        }

        *(char*)(GetBuffer() + newpos) = 1;

        return 0;
    }

    /**
    * 从队列中取出一个Code
    * @param[in] p
    * @param[in] buflen: 传入的是p的长度
    * @param[out] len: 传出的是获取数据的长度
    * @return 0正确 -1参数错误 -2缓冲区内容错误
    */
	int Get(char* p, int buflen, int& len)
	{
		if (buflen <= 0)
        {
			return -1;
        }

		if (read_ == write_)
		{
			len = 0;
			return 0;
		}

		int readlen = 0;
		const int startpos = read_ + sizeof(int);

		char flag = * (char*) (GetBuffer() + read_);
		if (flag != 1)
		{
			len = 0;
			return 0;
		}

		// 获取要读取的数据长度
		if (startpos > size_)
		{
			memcpy(&readlen, GetBuffer() + read_, size_ - read_);
			memcpy(((char*)&readlen) + size_ - read_, GetBuffer(), startpos - size_);
		}
		else
		{
			memcpy(&readlen, GetBuffer() + read_, sizeof(int));
		}
		readlen = htonl(readlen);
		readlen = readlen & 0x00FFFFFF;

		if (readlen == 0)
		{
			len = 0;
			return 0;
		}

		if (readlen > buflen || readlen < 0)
        {
			return -2;
        }

		if (startpos >= size_)
		{
			memcpy(p, GetBuffer() + startpos - size_, readlen);
		}
		else
		{
			if (startpos + readlen > size_)
			{
				memcpy(p, GetBuffer() + startpos, size_ - startpos);
				memcpy(p + size_ - startpos, GetBuffer(), readlen - size_ + startpos);
			}
			else
			{
				memcpy(p, GetBuffer() + startpos, readlen);
			}
		}

		len = readlen;
		read_ = (startpos + readlen) % size_;

		return 0;
	}

    /**
    * 返回最近一个Code的长度
    */
    int GetCodeLen() const
    {
        if (read_ == write_)
        {
            return 0;
        }

        int readlen = 0;
        const int startpos = read_ + sizeof(int);

        char flag = * (char*) (GetBuffer() + read_);
        if (flag != 1)
        {
            return 0;
        }

        // 获取要读取的数据长度
        if (startpos > size_)
        {
            memcpy(&readlen, GetBuffer() + read_, size_ - read_);
            memcpy(((char*)&readlen) + size_ - read_, GetBuffer(), startpos - size_);
        }
        else
        {
            memcpy(&readlen, GetBuffer() + read_, sizeof(int));
        }

        return htonl(readlen) & 0x00FFFFFF;
    }

	/**
	* 删除一个Code
	*/
	int Remove()
	{
		int readlen = 0;
		const int startpos = read_ + sizeof(int);

		if (read_ == write_)
        {
			return 0;
        }

		char flag = * (char*) (GetBuffer() + read_);
		if (flag != 1)
        {
			return 0;
        }

		// 获取要读取的数据长度
		if (startpos > size_)
		{
			memcpy(&readlen, GetBuffer() + read_, size_ - read_);
			memcpy(((char*)&readlen) + size_ - read_, GetBuffer(), startpos - size_);
		}
		else
		{
			memcpy(&readlen, GetBuffer() + read_, sizeof(int));
		}
		readlen = htonl(readlen);
		readlen = readlen & 0x00FFFFFF;

		if (readlen < 0)
        {
			return -2;
        }

		read_ = (startpos + readlen) % size_;
		return 0;
	}

    /**
	* 删除所有内容,只有接收方可以调用这个函数!!!
	*/
    int RemoveAll()
    {
        read_ = write_; //此处不能修改write_
        return 0;
    }

    /**
    * 用于在共享内存中创建时做校验
    * @return 0表示CTCodeQueue对象已创建, 否则表示对象未创建
    */
	int CheckSum() const
	{
		if (!offset_ || !size_ || !create_time_)
			return -1;

		unsigned int nTempInt = 0;
		nTempInt = (unsigned int)offset_ ^ (unsigned int)size_
					^ (unsigned int) create_time_ ^ (unsigned int) checksum_;

		return (nTempInt == 0) ? 0 : -1;
	}

	void Dump() const
	{
		CT_DEBUG(("this=%p offset=%d size=%d read=%d write=%d\n",
			this, offset_, size_, read_, write_));
	}

protected:
	int			offset_;
	int			size_;
	int			read_;	// 已用数据的开始
	int			write_;	// 已用数据的结束
	unsigned int create_time_;	// 创建时间
	unsigned int checksum_;	// 校验结果
};

