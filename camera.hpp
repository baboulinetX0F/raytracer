#ifndef CAMERAH
#define CAMERAH

#include "ray.hpp"

// TODO : Resolve undefined reference to M_PI from cmath (_USE_MATH_DEFINES not working)
const float M_PI = 3.14159265358979323846;

class camera
{
public:
	camera(float p_vfov, float p_aspect)
	{
		float theta = p_vfov * M_PI / 180;
		float half_height = tan(theta / 2);
		float half_width = p_aspect * half_height;
		lower_left_corner = vec3(-half_width, -half_height, -1.0);
		horizontal = vec3(2 * half_width, 0.0, 0.0);
		vertical = vec3(0.0, 2 * half_height, 0.0);
		origin = vec3(0.0, 0.0, 0.0);
	}

	ray get_ray(float u, float v) { return ray(origin, lower_left_corner + u * horizontal + v * vertical); }

	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
};

#endif