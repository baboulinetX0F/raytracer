#include <iostream>
#include <fstream>
#include "ray.hpp"

bool hit_sphere(const vec3& center, float radius, const ray& r)
{
    // TODO : Implement function hit_sphere
    return false;
}

vec3 color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y()+1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(int argc, char** argv)
{
    const int RENDER_WIDTH = 200;
    const int RENDER_HEIGHT = 100;
    vec3 origin = vec3(0.0, 0.0, 0.0);
    vec3 vertical = vec3(0.0, 2.0, 0.0);
    vec3 horizontal = vec3(4.0, 0.0, 0.0);
    vec3 lower_left_corner = vec3(-2.0, -1.0, -1.0);
    std::ofstream file;
    file.open("output.ppm");
    file << "P3\n" << RENDER_WIDTH << " " << RENDER_HEIGHT << "\n255\n";
    for(int y = RENDER_HEIGHT - 1; y >= 0; y--)
    {
        for(int x = 0; x < RENDER_WIDTH; x++)
        {            
            float u = float(x) / float(RENDER_WIDTH);
            float v = float(y) / float(RENDER_HEIGHT);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.99*col.r());
            int ig = int(255.99*col.g());
            int ib = int(255.99*col.b());
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();
    return 0;
}
