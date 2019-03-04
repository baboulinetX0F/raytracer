#include <iostream>
#include <fstream>
#include "rand.hpp"
#include "lambertian.hpp"
#include "metal.hpp"
#include "dielectric.hpp"
#include "sphere.hpp"
#include "hitable_list.hpp"

vec3 color(const ray& r, hitable* world, int depth) {
    hit_record hit;
    if (world->hit(r, 0.00001, 10000.0, hit))
    {
        // vec3 N = hit.normal;
        // return 0.5 *vec3(N.x() + 1, N.y() + 1, N.z() + 1);
        //vec3 target = hit.p + hit.normal + random_in_unit_sphere();
        //return 0.5*color(ray(hit.p, target-hit.p), world);
		vec3 attenuation;
		ray scattered;
		if (depth < 50 && hit.mat_ptr->scatter(r, hit, attenuation, scattered))
		{
			return attenuation * color(scattered, world, depth + 1);
		}
		else
		{
			return vec3(0.0, 0.0, 0.0);
		}
    }
	else
	{
		// fake sky gradient backgrounc
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

int main(int argc, char** argv)
{	
	const int RENDER_WIDTH = 200;
    const int RENDER_HEIGHT = 100;
    const int SAMPLE_NUMBER = 10;
    vec3 origin(0.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    std::ofstream file;
    file.open("output.ppm");
    hitable* list[5];
    list[0] = new sphere(vec3(0, 0,-1), 0.5, new lambertian(vec3(0.8, 0.1, 0.0)));	
    list[1] = new sphere(vec3(0, -100.5,-1), 100, new lambertian(vec3(0.0, 0.15, 0.8)));
	list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.0, 0.8, 0.1), 0.2));
	list[3] = new sphere(vec3(-1, 0, -1), 0.5, new dielectric(1.5));
	list[4] = new sphere(vec3(-1, 0, -1), -0.45, new dielectric(1.5));
    hitable* world = new hitable_list(list, 5);
    file << "P3\n" << RENDER_WIDTH << " " << RENDER_HEIGHT << "\n255\n";
    for(int y = RENDER_HEIGHT - 1; y >= 0; y--)
    {
        for(int x = 0; x < RENDER_WIDTH; x++)
        {            
            vec3 col = vec3(0.0, 0.0, 0.0);
            for (int s=0; s<SAMPLE_NUMBER; s++)
            {
                float u = float(x + rand_mt19937()) / float(RENDER_WIDTH);
                float v = float(y + rand_mt19937()) / float(RENDER_HEIGHT);
                ray r(origin, lower_left_corner + u*horizontal + v*vertical);
                col += color(r, world, 0);
            }
            col /= SAMPLE_NUMBER;
            col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99*col.r());
            int ig = int(255.99*col.g());
            int ib = int(255.99*col.b());
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();
    return 0;
}
