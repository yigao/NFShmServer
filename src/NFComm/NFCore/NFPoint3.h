// -------------------------------------------------------------------------
//    @FileName         :    NFNFPoint3.h
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFNFPoint3
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"
#include <math.h>

template<typename TYPE = int>
class NFPoint3
{
public:
    TYPE  x, y, z;

public:
    inline NFPoint3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    inline NFPoint3(const TYPE& ValueX, const TYPE& ValueY, const TYPE& ValueZ)
            :x(ValueX), y(ValueY), z(ValueZ) {}

    inline explicit NFPoint3(const TYPE Value)
            :x(Value), y(Value), z(Value) {}

    inline explicit NFPoint3(const TYPE Vec[3])
            :x(Vec[0]), y(Vec[1]), z(Vec[2]) {}

    inline explicit NFPoint3(TYPE* const r)
            :x(r[0]), y(r[1]), z(r[2]) {}

    inline TYPE operator[] (const size_t i) const
    {
        NF_ASSERT(i < 3);
        return *(&x+i);
    }

    inline TYPE& operator[] (const size_t i)
    {
        NF_ASSERT(i < 3);
        return *(&x+i);
    }

    inline NFPoint3& operator = (const NFPoint3& Value)
    {
        x = Value.x;
        y = Value.y;
        z = Value.z;
        return (*this);
    }

    inline NFPoint3& operator = (const TYPE Value)
    {
        x = Value;
        y = Value;
        z = Value;
        return (*this);
    }

    inline bool operator == (const NFPoint3& Value) const
    {
        return (x == Value.x && y == Value.y && z == Value.z);
    }

    inline bool operator != (const NFPoint3& Value) const
    {
        return (x != Value.x || y != Value.y ||  z != Value.z);
    }

    inline NFPoint3 operator + (const NFPoint3& Value) const
    {
        return NFPoint3((x + Value.x), (y + Value.y), (z + Value.z));
    }

    inline NFPoint3 operator - (const NFPoint3& Value) const
    {
        return NFPoint3((x - Value.x), (y - Value.y), (z - Value.z));
    }

    inline NFPoint3 operator * (const TYPE Value) const
    {
        return NFPoint3((x * Value), (y * Value), (z * Value));
    }

    inline NFPoint3 operator * (const NFPoint3& Value) const
    {
        return NFPoint3((x * Value.x), (y * Value.y), (z * Value));
    }

    inline NFPoint3 operator / (const TYPE Value) const
    {
        MMO_ASSERT(Value != 0);
        return NFPoint3((x / Value), (y / Value), (z / Value));
    }

    inline NFPoint3 operator / ( NFPoint3& Value) const
    {
        MMO_ASSERT(Value.x != 0 && Value.y != 0 && Value.z != 0);
        return NFPoint3((x / Value.x), (y / Value.y), (z / Value.z));
    }

    inline const NFPoint3& operator + () const
    {
        return (*this);
    }

    inline NFPoint3 operator - () const
    {
        return NFPoint3(-x, -y, -z);
    }

    inline friend NFPoint3 operator * (const TYPE Value, const NFPoint3& point)
    {
        return NFPoint3((Value * point.x), (Value * point.y), (Value * point.z));
    }

    inline friend NFPoint3 operator / (const TYPE Value, const NFPoint3& point)
    {
        MMO_ASSERT(point.x != 0 && point.y != 0 && point.z != 0);
        return NFPoint3((Value / point.x), (Value / point.y), (Value / point.z));
    }

    inline friend NFPoint3 operator + (const NFPoint3& point, const TYPE Value)
    {
        return NFPoint3((point.x + Value), (point.y + Value), (point.z + Value));
    }

    inline friend NFPoint3 operator + (const TYPE Value, const NFPoint3& point)
    {
        return NFPoint3((Value + point.x), (Value + point.y), (Value + point.z));
    }

    inline friend NFPoint3 operator - (const NFPoint3& point, const TYPE Value)
    {
        return NFPoint3((point.x - Value), (point.y - Value), point.z - Value);
    }

    inline friend NFPoint3 operator - (const TYPE Value, const NFPoint3& point)
    {
        return NFPoint3((Value - point.x), (Value - point.y), (Value - point.z));
    }

    inline friend NFPoint3 AbsSub(const NFPoint3& Value1, const NFPoint3& Value2)
    {
        return NFPoint3(abs(Value2.x - Value1.x), abs(Value2.y - Value1.y), abs(Value2.z - Value1.z));
    }

    inline friend NFPoint3 interpolate(const float alpha, const NFPoint3& Value1, const NFPoint3& Value2)
    {
        return Value1 + ((Value2 - Value1) * alpha);
    }

    inline float length() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    inline NFPoint3& operator += (const NFPoint3& Value)
    {
        x += Value.x;
        y += Value.y;
        z += Value.z;
        return (*this);
    }

    inline NFPoint3& operator += (const TYPE Value)
    {
        x += Value;
        y += Value;
        z += Value;
        return (*this);
    }

    inline NFPoint3& operator -= (const NFPoint3& Value)
    {
        x -= Value.x;
        y -= Value.y;
        z -= Value.z;
        return (*this);
    }

    inline NFPoint3& operator -= (const TYPE Value)
    {
        x -= Value;
        y -= Value;
        z -= Value;
        return (*this);
    }

    inline NFPoint3& operator *= (const TYPE Value)
    {
        x *= Value;
        y *= Value;
        z *= Value;
        return (*this);
    }

    inline NFPoint3& operator *= (const NFPoint3& Value)
    {
        x *= Value.x;
        y *= Value.y;
        z *= Value.z;
        return (*this);
    }

    inline NFPoint3& operator /= (const TYPE Value)
    {
        MMO_ASSERT(Value != 0.0f);
        TYPE tempValue = 1.0f / Value;
        x *= tempValue;
        y *= tempValue;
        z *= tempValue;
        return (*this);
    }

    inline NFPoint3& operator /= (const NFPoint3& Value)
    {
        MMO_ASSERT((Value.x != 0) && (Value.y != 0));
        x /= Value.x;
        y /= Value.y;
        z /= Value.z;
        return (*this);
    }

    inline operator TYPE* ()
    {
        return &x;
    }

    inline operator const TYPE* () const
    {
        return &x;
    }
};


template<>
inline bool NFPoint3<float>::operator == (const NFPoint3<float>& Value) const
{
    return fabsf(x - Value.x) <= 0.000001 && fabsf(y - Value.y) <= 0.000001 && fabsf(z - Value.z) <= 0.000001;
}

template<>
inline bool NFPoint3<float>::operator != (const NFPoint3<float>& Value) const
{
    return fabsf(x - Value.x) > 0.000001 || fabsf(y - Value.y) > 0.000001 || fabsf(z - Value.z) > 0.000001;
}

template<>
inline NFPoint3<float> NFPoint3<float>::operator / (const float Value) const
{
    if (fabsf(Value) < 0.001f)
    {
        if (Value>0)
        {
            return NFPoint3((x / 0.001f), (y / 0.001f), (z / 0.001f));
        }
        else
        {
            return NFPoint3((x / -0.001f), (y / -0.001f), (z / -0.001f));
        }
    }
    else
    {
        return NFPoint3((x / Value), (y / Value), (z / Value));
    }
}

template<>
inline NFPoint3<float> NFPoint3<float>::operator / ( NFPoint3<float>& Value) const
{
    if (fabsf(Value.x) < 0.001)
    {
        if (Value.x >= 0)
        {
            Value.x = 0.001f;
        }
        else
        {
            Value.x = -0.001f;
        }
    }

    if (fabsf(Value.y) < 0.001)
    {
        if (Value.y >= 0)
        {
            Value.y = 0.001f;
        }
        else
        {
            Value.y = -0.001f;
        }
    }


    if (fabsf(Value.z) < 0.001)
    {
        if (Value.z >= 0)
        {
            Value.z = 0.001f;
        }
        else
        {
            Value.z = -0.001f;
        }
    }
    return NFPoint3((x / Value.x), (y / Value.y), (z / Value.z));
}
