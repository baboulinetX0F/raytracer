#ifndef METALH
#define METALH

#include "material.h"


class metal : public material {
public:
	metal(vec3 p_albedo) : albedo(p_albedo) {}
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
	{
		// TODO : Implement scatter function for metal material
		vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected);
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}
	vec3 albedo;
};


#endif
