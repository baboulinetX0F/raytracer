#ifndef SPHEREH
#define SPHEREH

#include "hitable.h"
#include "material.h"

class sphere: public hitable
{
public:
    sphere() { }
    sphere(vec3 p_center, float p_radius, material* p_material) : center(p_center), radius(p_radius), mat(p_material) {};
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

    vec3 center;
    float radius;
	material* mat;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discri = b*b - a*c;
    if (discri > 0)
    {
        float temp = (-b-sqrt(b*b - a*c))/a;
        if (temp < t_max && temp > t_min)
        {            
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
            return true;
        }

        temp = (-b+sqrt(b*b - a*c))/a;
        if (temp < t_max && temp > t_min)
        {            
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
			return true;
        }
    }
    
    return false;  
}

#endif