#ifndef VEC3H
#define VEC3H
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{
public:
    vec3() { }
    vec3(float x, float y, float z) {e[0]=x; e[1]=y; e[2]=z; }
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float r() const { return e[0]; }
    inline float g() const { return e[1]; }
    inline float b() const { return e[2]; }

    inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    inline float operator[](int i) const { return e[i]; }
    
    inline vec3& operator+=(const vec3& v2);
    inline vec3& operator*=(const vec3& v2);
    inline vec3& operator/=(const vec3& v2);
    inline vec3& operator*(const float f);
    inline vec3& operator/(const float f);
    inline vec3& operator*=(const float f);
    inline vec3& operator/=(const float f);
    inline vec3& operator-=(const vec3& v2);

    inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
    inline float squared_length() const { return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);}
	
	float e[3];
};


inline vec3& vec3::operator+=(const vec3& v2)
{
    e[0]+=v2.e[0];
    e[1]+=v2.e[1];
    e[2]+=v2.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3& v2)
{
    e[0]*=v2.e[0];
    e[1]*=v2.e[1];
    e[2]*=v2.e[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v2)
{
    e[0]-=v2.e[0];
    e[1]-=v2.e[1];
    e[2]-=v2.e[2];
    return *this;
}

inline vec3& vec3::operator*(const float f)
{
    e[0]*=f;
    e[1]*=f;
    e[2]*=f;
    return *this;
}

inline vec3& vec3::operator*=(const float f)
{
    e[0]*=f;
    e[1]*=f;
    e[2]*=f;
    return *this;
}

inline vec3& vec3::operator/(const float f)
{
    e[0]/=f;
    e[1]/=f;
    e[2]/=f;
    return *this;
}

inline vec3& vec3::operator/=(const float f)
{
    float k = 1.0/f;

    e[0]*=k;
    e[1]*=k;
    e[2]*=k;
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v2)
{
    e[0]/=v2.e[0];
    e[1]/=v2.e[1];
    e[2]/=v2.e[2];
    return *this;
}

inline vec3 operator+(const vec3& v1, const vec3& v2)
{
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2)
{
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2)
{
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3& v1, const vec3& v2)
{
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator*(float f, const vec3& v)
{
    return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator*(const vec3& v, float f)
{
    return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator/(float f, const vec3& v)
{
    return vec3(v.e[0] / f,v.e[1] / f, v.e[2] / f);
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

inline float dot(const vec3& v1, const vec3& v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}


inline vec3 reflect(const vec3 & v, const vec3 & n)
{
	return v - 2 * dot(v, n)*n;
}

#endif