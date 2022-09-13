// -------------------------------------------------------------------------
//    @FileName         :    NFSingleton.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFSingleton
//
// -------------------------------------------------------------------------

#ifndef NF_SINGLETON_H
#define NF_SINGLETON_H

#include <iostream>

template <class T>
class NFSingleton
{
public:

	NFSingleton()
	{
		//assert( !m_instance );

#if defined( _MSC_VER ) && _MSC_VER < 1200
		int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
		m_pInstance = (T*)((int)this + offset);
#else
		m_pInstance = static_cast<T*>(this);
#endif
	}

	virtual ~NFSingleton()
	{
	}

public:

	static T* GetSingletonPtr()
	{
		if (nullptr == m_pInstance)
		{
			m_pInstance = new T;
		}

		return m_pInstance;
	}

	static T& GetSingletonRef()
	{
		return *GetSingletonPtr();
	}

	static T* Instance()
	{
		return GetSingletonPtr();
	}

	static T& InstanceRef()
	{
		return GetSingletonRef();
	}

	static void ReleaseInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

private:
	static T* m_pInstance;
};

template <class T>
T* NFSingleton<T>::m_pInstance = nullptr;

#endif

