// -------------------------------------------------------------------------
//    @FileName         :    NFShmIteratorBase.h
//    @Author           :    gaoyi
//    @Date             :    23-1-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmIteratorBase
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

struct NFShmInputIteratorTag
{
    NFShmInputIteratorTag()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

struct NFShmOutputIteratorTag
{
    NFShmOutputIteratorTag()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

struct NFShmForwardIteratorTag : public NFShmInputIteratorTag
{
    NFShmForwardIteratorTag()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

struct NFShmBidirectionalIteratorTag : public NFShmForwardIteratorTag
{
    NFShmBidirectionalIteratorTag()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

struct NFShmRandomAccessIteratorTag : public NFShmBidirectionalIteratorTag
{
    NFShmRandomAccessIteratorTag()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

template <class Tp, class Distance> struct NFShmInputIterator{
    typedef NFShmInputIteratorTag iterator_category;
    typedef Tp                value_type;
    typedef Distance          difference_type;
    typedef Tp*               pointer;
    typedef Tp&               reference;

    NFShmInputIterator()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

struct NFShmOutputIterator {
    typedef NFShmOutputIteratorTag iterator_category;
    typedef void                value_type;
    typedef void                difference_type;
    typedef void                pointer;
    typedef void                reference;

    NFShmOutputIterator()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

template <class Tp, class Distance> struct NFShmForwardIterator {
    typedef NFShmForwardIteratorTag iterator_category;
    typedef Tp                  value_type;
    typedef Distance            difference_type;
    typedef Tp*                 pointer;
    typedef Tp&                 reference;

    NFShmForwardIterator()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

template <class Tp, class Distance> struct NFShmBidirectionalIterator {
    typedef NFShmBidirectionalIteratorTag iterator_category;
    typedef Tp                  value_type;
    typedef Distance            difference_type;
    typedef Tp*                 pointer;
    typedef Tp&                 reference;

    NFShmBidirectionalIterator()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

template <class Tp, class Distance> struct NFShmRandomAccessIterator {
    typedef NFShmRandomAccessIteratorTag iterator_category;
    typedef Tp                  value_type;
    typedef Distance            difference_type;
    typedef Tp*                 pointer;
    typedef Tp&                 reference;

    NFShmRandomAccessIterator()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};