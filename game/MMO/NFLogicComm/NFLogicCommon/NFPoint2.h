// -------------------------------------------------------------------------
//    @FileName         :    NFNFPoint2.h
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFNFPoint2
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

template<typename TYPE = int>
class NFPoint2
{
public:
    TYPE x, y;

public:
    inline NFPoint2()
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
        x = 0;
        y = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    inline NFPoint2(const TYPE ValueX, const TYPE ValueY)
            :x(ValueX), y(ValueY) {}

    inline explicit NFPoint2(const TYPE Value)
            :x(Value), y(Value) {}

    inline explicit NFPoint2(const TYPE Vec[2])
            :x(Vec[0]), y(Vec[1]) {}

    inline explicit NFPoint2(TYPE* const r)
            :x(r[0]), y(r[1]) {}

    inline TYPE operator[] (const size_t i) const
    {
        NF_ASSERT(i < 2);
        return *(&x+i);
    }

    inline TYPE& operator[] (const size_t i)
    {
        NF_ASSERT(i < 2);
        return *(&x+i);
    }

    inline NFPoint2& operator = (const NFPoint2& Value)
    {
        x = Value.x;
        y = Value.y;
        return (*this);
    }

    inline NFPoint2& operator = (const TYPE Value)
    {
        x = Value;
        y = Value;
        return (*this);
    }

    inline bool operator == (const NFPoint2& Value) const
    {
        return (x == Value.x && y == Value.y);
    }

    inline bool operator != (const NFPoint2& Value) const
    {
        return (x != Value.x || y != Value.y);
    }

    inline NFPoint2 operator + (const NFPoint2& Value) const
    {
        return NFPoint2((x + Value.x), (y + Value.y));
    }

    inline NFPoint2 operator - (const NFPoint2& Value) const
    {
        return NFPoint2((x - Value.x), (y - Value.y));
    }

    inline NFPoint2 operator * (const TYPE Value) const
    {
        return NFPoint2((x * Value), (y * Value));
    }

    inline NFPoint2 operator * (const NFPoint2& Value) const
    {
        return NFPoint2((x * Value.x), (y * Value.y));
    }

    inline NFPoint2 operator / (const TYPE Value) const
    {
        NF_ASSERT(Value != 0);
        return NFPoint2((x / Value), (y / Value));
    }

    inline NFPoint2 operator / (const NFPoint2& Value) const
    {
        NF_ASSERT(Value.x != 0 && Value.y != 0);
        return NFPoint2((x / Value.x), (y / Value.y));
    }

    inline const NFPoint2& operator + () const
    {
        return (*this);
    }

    inline NFPoint2 operator - () const
    {
        return NFPoint2(-x, -y);
    }

    inline friend NFPoint2 operator * (const TYPE Value, const NFPoint2& point)
    {
        return NFPoint2((Value * point.x), (Value * point.y));
    }

    inline friend NFPoint2 operator / (const TYPE Value, const NFPoint2& point)
    {
        NF_ASSERT(point.x != 0 && point.y != 0);
        return NFPoint2((Value / point.x), (Value / point.y));
    }

    inline friend NFPoint2 operator + (const NFPoint2& Value, const TYPE point)
    {
        return NFPoint2((point.x + Value), (point.y + Value));
    }

    inline friend NFPoint2 operator + (const TYPE Value, const NFPoint2& point)
    {
        return NFPoint2((Value + point.x), (Value + point.y));
    }

    inline friend NFPoint2 operator - (const NFPoint2& Value, const TYPE point)
    {
        return NFPoint2((point.x - Value), (point.y - Value));
    }

    inline friend NFPoint2 operator - (const TYPE Value, const NFPoint2& point)
    {
        return NFPoint2((Value - point.x), (Value - point.y));
    }

    inline friend NFPoint2 AbsSub(const NFPoint2& Value1, const NFPoint2& Value2) {
        return NFPoint2(abs(Value2.x - Value1.x), abs(Value2.y - Value1.y));
    }

    inline friend float Slope(const NFPoint2& Value1, const NFPoint2& Value2)
    {
        return ((float)(Value2.y - Value1.y) / (float)(Value2.x - Value1.x));
    }

    inline NFPoint2& operator += (const NFPoint2& Value)
    {
        x += Value.x;
        y += Value.y;
        return (*this);
    }

    inline NFPoint2& operator += (const TYPE Value)
    {
        x += Value;
        y += Value;
        return (*this);
    }

    inline NFPoint2& operator -= (const NFPoint2& Value)
    {
        x -= Value.x;
        y -= Value.y;
        return (*this);
    }

    inline NFPoint2& operator -= (const TYPE Value)
    {
        x -= Value;
        y -= Value;
        return (*this);
    }

    inline NFPoint2& operator *= (const TYPE Value)
    {
        x *= Value;
        y *= Value;
        return (*this);
    }

    inline NFPoint2& operator *= (const NFPoint2& Value)
    {
        x *= Value.x;
        y *= Value.y;
        return (*this);
    }

    inline NFPoint2& operator /= (const TYPE Value)
    {
        NF_ASSERT(Value != 0.0f);
        TYPE tempValue = 1.0f / Value;
        x *= tempValue;
        y *= tempValue;
        return (*this);
    }

    inline NFPoint2& operator /= (const NFPoint2& Value)
    {
        NF_ASSERT((Value.x != 0) && (Value.y != 0));
        x /= Value.x;
        y /= Value.y;
        return (*this);
    }
};

