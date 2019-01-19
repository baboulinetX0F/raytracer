#include <math.h>
#include <iostream>

class vec3
{
public:
    vec3() {e[0] = e[1] = e[2] = 0.0;}
    vec3(float x, float y, float z) {e[0]=x; e[1]=y; e[2]=z; }
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float r() const { return e[0]; }
    inline float g() const { return e[1]; }
    inline float b() const { return e[2]; }

    float e[3];
};