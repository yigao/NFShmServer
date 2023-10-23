// -------------------------------------------------------------------------
//    @FileName         :    NFMath.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFMath
//
// -------------------------------------------------------------------------

#include "NFMath.h"

NFMath::NFMath()
{
}

NFMath::~NFMath()
{
}

float NFMath::AngleToRadian(float angle)
{
    return (angle * MMO_PI / 180.0f);
}

float NFMath::RadianToAngle(float radian)
{
    return (radian * 180.0f / MMO_PI);
}

NFPoint3<float> NFMath::AngleToDir(const NFPoint3<float> &pos, float angle)
{
    return NFPoint3<float>(pos.x * sinf(angle), 0, pos.z * cosf(angle));
}

double NFMath::Distance2Dpow2(NFPoint2<float>& from, NFPoint2<float>& to)
{
    return pow((to.x - from.x), 2) + pow((to.x - from.x), 2);
}

float NFMath::Distance2D(NFPoint2<float>& from, NFPoint2<float>& to)
{
    return sqrt(pow((to.x - from.x), 2) + pow((to.x - from.x), 2));
}

float NFMath::DistanceX(NFPoint2<float>& from, NFPoint2<float>& to)
{
    return to.x - from.x;
}

float NFMath::DistanceY(NFPoint2<float>& from, NFPoint2<float>& to)
{
    return to.y - from.y;
}

//以unity-z轴正方向为0度，正方向旋转角度
float NFMath::Radian2D(const NFPoint2<float>& from, const NFPoint2<float>& to)
{
    NFPoint2<float> diff = to - from;
    float ret = 0.0f;
    if (fabs(diff.x) <= EPS && fabs(diff.y) <= EPS)
    {
        ret = 0.0f;
    }
    else if (fabs(diff.x) <= EPS && fabs(diff.y) > EPS)
    {
        if (diff.y > 0.0f)
        {
            ret = 0.0f;
        }
        else
        {
            ret = MMO_PI;
        }
    }
    else if (fabs(diff.x) > EPS && fabs(diff.y) <= EPS)
    {
        if (diff.x > 0.0f)
        {
            ret = MMO_PI / 2.0f;
        }
        else
        {
            ret = MMO_PI * 3.0f / 2.0f;
        }
    }
    else if (diff.x > 0.0f && diff.y > 0.0f)
    {
        ret = atanf(diff.x / diff.y);
    }
    else if (diff.x > 0.0f && diff.y < 0.0f)
    {
        ret = MMO_PI - atanf(-diff.x / diff.y);
    }
    else if (diff.x < 0.0f && diff.y < 0.0f)
    {
        ret = MMO_PI + atanf(diff.x / diff.y);
    }
    else if (diff.x < 0.0f && diff.y > 0.0f)
    {
        ret = MMO_PI * 3.0f / 2.0f + atanf(-diff.y / diff.x);
    }
    return ret;
}

float NFMath::Angle2D(const NFPoint2<float>& from, const NFPoint2<float>& to)
{
    return RadianToAngle(Radian2D(from, to));
}

float NFMath::VectorRadian2D(const NFPoint2<float>& from, const NFPoint2<float>& to)
{
    return acosf((to.x * from.x + to.y * from.y) / (sqrt(pow(from.x, 2) + pow(from.y, 2)) * sqrt(pow(to.x, 2) + pow(to.y, 2))));
}

float NFMath::VectorAngle2D(NFPoint2<float>& from, NFPoint2<float>& to)
{
    return RadianToAngle(VectorRadian2D(from, to));
}

void NFMath::FormulaPos(float dir, float length, NFPoint2<float>* pos)
{
    if (dir <= MMO_PI / 2.0f)
    {
        pos->x = length * sinf(dir);
        pos->y = length * cosf(dir);
    }
    else if (dir <= MMO_PI)
    {
        pos->x = length * sinf(MMO_PI - dir);
        pos->y = -length * cosf(MMO_PI - dir);
    }
    else if (dir <= MMO_PI * 3 / 2.0f)
    {
        pos->x = -length * sinf(dir - MMO_PI);
        pos->y = -length * cosf(dir - MMO_PI);
    }
    else if (dir <= MMO_PI * 2.0f)
    {
        pos->x = -length * sinf(2.0f * MMO_PI - dir);
        pos->y = length * cosf(2.0f * MMO_PI - dir);
    }
}

float NFMath::ReviseDir(float dir)
{
    dir = (dir <= 0.0f) ? dir + 360.0f : dir;
    if (dir > 360.0f)
    {
        dir = fmod(dir, 360.0f);
    }
    return dir;
}

float NFMath::FloorDir(float dir)
{
    return floor(ReviseDir(dir));
}

float NFMath::DeltaAngle(float current, float target)
{
    if (current - target <=0.0001 )
    {
        return 0.0f;
    }
    current = ReviseDir(current);
    target = ReviseDir(target);
    return ReviseDir(target - current);
}

float NFMath::DeltaMinAngle(float current, float target)
{
    if (current - target <=0.0001 )
    {
        return 0.0f;
    }
    float delta = DeltaAngle(current, target);
    float minDelta =  delta > 360.0f - delta ? 360.0f - delta : delta;
    return ReviseDir(minDelta);
}

float NFMath::CarmackSqrt(float number)
{
    int i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(int *)&y;				// evil floating point bit level hacking
    i = 0x5f375a86 - (i >> 1);	// what the fuck?
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));
    return number*y;
}

float NFMath::NFPoint2Length(const NFPoint2<float>& Value1, const  NFPoint2<float>& Value2)
{
    return CarmackSqrt((Value1.x - Value2.x) * (Value1.x - Value2.x) + (Value1.y - Value2.y) * (Value1.y - Value2.y));
}

float NFMath::NFPoint2Length(const NFPoint3<float>& Value1, const NFPoint3<float>& Value2)
{
    return CarmackSqrt((Value1.x - Value2.x) * (Value1.x - Value2.x) + (Value1.z - Value2.z) * (Value1.z - Value2.z));
}

float NFMath::NFPoint3Length(const NFPoint3<float>& Value1, const NFPoint3<float>& Value2)
{
    return CarmackSqrt((Value1.x - Value2.x) * (Value1.x - Value2.x) + (Value1.y - Value2.y) * (Value1.y - Value2.y) + (Value1.z - Value2.z) * (Value1.z - Value2.z));
}

float NFMath::NFPoint2LengthSquare(const NFPoint3<float>& Value1, const NFPoint3<float>& Value2)
{
    return (Value1.x - Value2.x) * (Value1.x - Value2.x) + (Value1.z - Value2.z) * (Value1.z - Value2.z);
}

float NFMath::NFPoint2LengthSimple(const NFPoint3<float>& Value1, const NFPoint3<float>& Value2)
{
    float A = (float)(fabs(Value1.x-Value2.x));
    float B = (float)(fabs(Value1.z - Value2.z));
    return A > B ? A + B/2 : B + A/2;
}

float NFMath::NFPoint3LengthSquare(const NFPoint3<float>& Value1, const NFPoint3<float>& Value2)
{
    return (Value1.x - Value2.x) * (Value1.x - Value2.x) + (Value1.y - Value2.y) * (Value1.y - Value2.y) + (Value1.z - Value2.z) * (Value1.z - Value2.z);
}


float NFMath::triangleArea(float ax, float az, float bx, float bz, float cx, float cz)
{
    return abs(ax * bz + bx * cz + cx * az - bx * az - cx * bz - ax * cz);
}

// 三角形的面积
float NFMath::triangleArea(const NFPoint3<float>& a, const NFPoint3<float>& b, const NFPoint3<float>& c)
{
    float f = abs((a.x * b.z + b.x * c.z + c.x * a.z - b.x * a.z
                   - c.x * b.z - a.x * c.z) / 2);
    return f;
}

/**
* 是否再四边形内（只针对凸四边形）
* 返回值：true:再四边形内，false：不再四边形内
*/
bool NFMath::isInRect(const NFPoint3<float>& a, const NFPoint3<float>& b, const NFPoint3<float>& c, const NFPoint3<float>& d, const NFPoint3<float>& p)
{
    if ((abs(a.x - b.x) <= EPS && abs(a.x - c.x) <= EPS && abs(a.x - d.x) <= EPS)
        && (abs(a.z - b.z) <= EPS && abs(a.z - c.z) <= EPS && abs(a.z - d.z) <= EPS)
            )
    {
        //这里特殊处理下，如果一个区域的四个角的坐标都相同，表示这个区域是一个点
        return false;
    }
    float areav = 9.0f;
    float dTriangle = triangleArea(a, b, p) + triangleArea(b, c, p)	+ triangleArea(c, d, p) + triangleArea(d, a, p);
    float dQuadrangle = triangleArea(a, b, c) + triangleArea(c, d, a);
    return abs(dTriangle - dQuadrangle) < areav;
}

/*
* 是否在圆内
* midPos:圆心坐标
* radius：半径
* pos：外部坐标（判断用的）
*/
bool NFMath::InCircle(const NFPoint3<float> &midPos, const NFPoint3<float>& pos, float radius)
{
    float vx = pos.x - midPos.x;
    float vz = pos.z - midPos.z;
    return (vx * vx + vz * vz) <= ((radius + 0.5) * (radius + 0.5)); //半径扩大0.5m,允许有一定的误差范围
}

/*是否在扇形内
* center: 圆心
* targetPos：目标坐标
* sectorR：半径
*/
bool NFMath::InSector(const NFPoint3<float>& center, const NFPoint3<float>& vdir, const NFPoint3<float>& targetPos, float cosAngle, float sectorR)
{
    // D = P - C
    float dx = targetPos.x - center.x;
    float dz = targetPos.z - center.z;
    float squaredR = sectorR * sectorR;
    // |D|^2 = (dx^2 + dy^2)
    float squaredLength = dx * dx + dz * dz;
    //如果两点相距比较近，则不走扇形判断
    if (abs(squaredLength) < 0.5) return true;
    // |D|^2 > r^2
    if (squaredLength > squaredR + 1) return false;
    // D dot U
    float DdotU = dx * vdir.x + dz * vdir.z;

    // D dot U > |D| cos(theta)
    // <=>
    // (D dot U)^2 > |D|^2 (cos(theta))^2 if D dot U >= 0 and cos(theta) >= 0
    // (D dot U)^2 < |D|^2 (cos(theta))^2 if D dot U <  0 and cos(theta) <  0
    // true                               if D dot U >= 0 and cos(theta) <  0
    // false                              if D dot U <  0 and cos(theta) >= 0

    //做下处理，如果相距非常近，不在这范围，也要找到他，因为玩家看起来好像在一起。
    if (DdotU > 0 && cosAngle >= 0)
    {
        return DdotU * DdotU - squaredLength * cosAngle * cosAngle >= 0;
    }
    else if (DdotU < 0 && cosAngle <= 0)
    {
        return DdotU * DdotU - squaredLength * cosAngle * cosAngle <= 0;
    }
    return DdotU >= 0;
}

/*坐标是否在矩形内
* position：坐标
* center：矩形中点坐标
* length：长
* width：宽
*/
bool NFMath::InRect(const NFPoint3<float>& position, const NFPoint3<float>& center, float length, float width, const NFPoint3<float>& dir)
{
    NFPoint3<float> f2 = position - center;
    float totLen = sqrt(f2.x * f2.x + f2.z * f2.z);
    float dirLen = sqrt(dir.x * dir.x + dir.z * dir.z);
    if (dirLen <= EPS) return false;
    //这是算出cosA  A是夹角
    float angle = ((f2.x * dir.x) + (f2.z * dir.z)) / (totLen * dirLen);
    //这是长判断 totlen*cosA
    float curLength = totLen * fabs(angle);
    if (curLength * 2 + 0.5 > length)  return false;
    //这是宽不超过  totlen*sinA
    float curWidth = totLen * sqrt(1 - angle * angle);
    if (curWidth * 2 + 0.5 > width) return false;
    return true;
}

/*获取A点到B点的等分点
*/
void NFMath::DivisionPoint(const NFPoint3<float>& from, const NFPoint3<float>& to, std::vector< NFPoint3<float> >& points, float division)
{
    for (float i = 1; i <= division; i++)
    {
        NFPoint3<float> point;
        point.x = from.x * (i / division) + to.x * (1 - i / division);
        point.y = from.y * (i / division) + to.y * (1 - i / division);
        point.z = from.z * (i / division) + to.z * (1 - i / division);
        points.push_back(point);
    }
}

//计算方向坐标 srcPos:源坐标，dstPos：目标坐标
NFPoint3<float> NFMath::CalcDir(const NFPoint3<float> &srcPos, const NFPoint3<float> &dstPos)
{
    NFPoint3<float> dir = dstPos - srcPos;
    dir.y = 0;
    return dir;
}

//计算单位方向坐标 dir:方向坐标
NFPoint3<float> NFMath::CalcUnitDir(const NFPoint3<float> &dir)
{
    float flen = CarmackSqrt((dir.x * dir.x + dir.z * dir.z));
    NFPoint3<float> dot;
    if (flen > EPS)
    {
        dot = dir / flen;
    }
    return dot;
}
