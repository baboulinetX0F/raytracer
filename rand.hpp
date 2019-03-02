#ifndef RANDH
#define RANDH

#include <random>
#include "vec3.hpp"

float rand_mt19937() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

vec3 random_in_unit_sphere()
{
    vec3 p;
    do {
        p = 2*vec3(rand_mt19937(), rand_mt19937(), rand_mt19937()) - vec3(1,1,1);
    } while(p.squared_length() >= 1.0);
    return p;
}

#endif
