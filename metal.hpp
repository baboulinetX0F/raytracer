#ifndef METALH
#define METALH

#include "material.h"
#include "rand.hpp"

class metal : public material {
public:
	metal(vec3 p_albedo, float p_fuzzy) : albedo(p_albedo) { if (p_fuzzy < 1) fuzzy = p_fuzzy; else fuzzy = 1; }
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
	{
		// TODO : Implement scatter function for metal material
		vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected + fuzzy*random_in_unit_sphere());
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}

	float fuzzy;
	vec3 albedo;
};


#endif
