// -------------------------------------------------------------------------
//    @FileName         :    NFAutoFree.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

/**
* 一个非常简单的智能指针(free)
*/

#include <stdio.h>
#include <stdlib.h>

class NFAutoFree
{
public:
	NFAutoFree() : m_auto_ptr(0) {}
	NFAutoFree(void* ptr) : m_auto_ptr(ptr) {}
	NFAutoFree(const NFAutoFree& obj) : m_auto_ptr(obj.get()) {}
	~NFAutoFree() { reset (0); }

	NFAutoFree& operator= (const NFAutoFree& obj)
	{
		this->m_auto_ptr = obj.get();
		return *this;
	}

	void* get() const { return m_auto_ptr; }
	void* operator() () { return get(); }

	void reset(void* ptr)
	{
		if (m_auto_ptr == ptr)
		{
			return;
		}

		if (m_auto_ptr)
		{
			free(m_auto_ptr);
		}

		m_auto_ptr = ptr;
	}

private:
    void* m_auto_ptr;
};

