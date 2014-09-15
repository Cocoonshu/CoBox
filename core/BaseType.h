#ifndef BASETYPE_H
#define BASETYPE_H
#include <float.h>
#include <math.h>

namespace CoBox {

// 定义引擎精度
#ifdef HIGH_PRECISION
    #define Float    double
    #define ZERO     DBL_MIN
    #define ONE      1.0
    #define INF      DBL_MAX
    #define NaN      (0.0 / 0.0)
    #define PI       M_PIl
    #define PI_2     M_PI_2l
    #define PI_4     M_PI_4l
    #define REC_PI   M_1_PIl
    #define REC_PI_2 M_2_PIl
#else
    #define Float    float
    #define ZERO     FLT_MIN
    #define ONE      1.0f
    #define INF      FLT_MAX
    #define NaN      (0.0f / 0.0f)
    #define PI       M_PI
    #define PI_2     M_PI_2
    #define PI_4     M_PI_4
    #define REC_PI   M_1_PI
    #define REC_PI_2 M_2_PI
#endif

#define isEqual(f, ref)    (islessequal(f, ref) && isgreaterequal(f, ref))
#define isNotEqual(f, ref) islessgreater(f, ref)
#define isNaN(f)           isnan(f)
#define isINF(f)           isinf(f)

}

#endif // BASETYPE_H
