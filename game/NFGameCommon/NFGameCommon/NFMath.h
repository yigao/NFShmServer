// -------------------------------------------------------------------------
//    @FileName         :    NFMath.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFMath
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFPoint2.h"
#include "NFPoint3.h"

#ifndef MMO_PI
#define MMO_PI    (3.1415926f)
#define MMO_PI2 (6.2831853f)            //MMO_PI * 2
#define MMO_PI8 (25.1327412f)            //MMO_PI * 8
#define MMO_PI_2 (1.570796325f)            //MMO_PI / 2	180
#define MMO_PI_3 (1.0471975512f)        //MMO_PI / 3	120
#define MMO_PI_4 (0.7853981625f)        //MMO_PI / 4	90
#define MMO_PI_6 (0.5235987756f)        //MMO_PI / 6	60
#endif

#ifndef EPS
#define EPS 0.000001f
#endif

class NFMath
{
public:
    NFMath();

    virtual ~NFMath();

public:
    static float AngleToRadian(float angle);

    static float RadianToAngle(float radian);

    static NFPoint3<float> AngleToDir(const NFPoint3<float> &pos, float angle);

    static double Distance2Dpow2(NFPoint2<float> &from, NFPoint2<float> &to);

    static float Distance2D(NFPoint2<float> &from, NFPoint2<float> &to);

    static float DistanceX(NFPoint2<float> &from, NFPoint2<float> &to);

    static float DistanceY(NFPoint2<float> &from, NFPoint2<float> &to);

    //以unity-z轴正方向为0度，正方向旋转角度
    static float Radian2D(const NFPoint2<float> &from, const NFPoint2<float> &to);

    static float Angle2D(const NFPoint2<float> &from, const NFPoint2<float> &to);

    static float VectorRadian2D(const NFPoint2<float> &from, const NFPoint2<float> &to);

    static float VectorAngle2D(NFPoint2<float> &from, NFPoint2<float> &to);

    static void FormulaPos(float dir, float length, NFPoint2<float> *pos);

    static float ReviseDir(float dir);

    static float FloorDir(float dir);

    static float DeltaAngle(float current, float target);

    static float DeltaMinAngle(float current, float target);

    static float CarmackSqrt(float number);

    static float NFPoint2Length(const NFPoint2<float> &Value1, const NFPoint2<float> &Value2);

    static float NFPoint2Length(const NFPoint3<float> &Value1, const NFPoint3<float> &Value2);

    static float NFPoint3Length(const NFPoint3<float> &Value1, const NFPoint3<float> &Value2);

    static float NFPoint2LengthSquare(const NFPoint3<float> &Value1, const NFPoint3<float> &Value2);

    static float NFPoint2LengthSimple(const NFPoint3<float> &Value1, const NFPoint3<float> &Value2);

    static float NFPoint3LengthSquare(const NFPoint3<float> &Value1, const NFPoint3<float> &Value2);

    static float triangleArea(float ax, float az, float bx, float bz, float cx, float cz);

    // 三角形的面积
    static float triangleArea(const NFPoint3<float> &a, const NFPoint3<float> &b, const NFPoint3<float> &c);

    /**
    * 是否再四边形内（只针对凸四边形）
    * 返回值：true:再四边形内，false：不再四边形内
    */
    static bool isInRect(const NFPoint3<float> &a, const NFPoint3<float> &b, const NFPoint3<float> &c, const NFPoint3<float> &d, const NFPoint3<float> &p);

    /*
    * 是否在圆内
    * midPos:圆心坐标
    * radius：半径
    * pos：外部坐标（判断用的）
    */
    static bool InCircle(const NFPoint3<float> &midPos, const NFPoint3<float> &pos, float radius);

    /*是否在扇形内
    * center: 圆心
    * targetPos：目标坐标
    * sectorR：半径
    */
    static bool InSector(const NFPoint3<float> &center, const NFPoint3<float> &vdir, const NFPoint3<float> &targetPos, float cosAngle, float sectorR);

    /*坐标是否在矩形内
    * position：坐标
    * center：矩形中点坐标
    * length：长
    * width：宽
    */
    static bool InRect(const NFPoint3<float> &position, const NFPoint3<float> &center, float length, float width, const NFPoint3<float> &dir);

    /*获取A点到B点的等分点
    */
    static void DivisionPoint(const NFPoint3<float> &from, const NFPoint3<float> &to, std::vector<NFPoint3<float> > &points, float division);

    //计算方向坐标 srcPos:源坐标，dstPos：目标坐标
    static NFPoint3<float> CalcDir(const NFPoint3<float> &srcPos, const NFPoint3<float> &dstPos);

    //计算单位方向坐标 dir:方向坐标
    static NFPoint3<float> CalcUnitDir(const NFPoint3<float> &dir);
};