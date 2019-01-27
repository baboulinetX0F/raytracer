#include <iostream>
#include <fstream>
#include "ray.hpp"

// TODO : replace return value with nearest point
float hit_sphere(const vec3& center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discri = b*b - 4*a*c;
    if (discri < 0)
    {
        return -1.0;
    }
    else
    {
        return (-b-sqrt(discri)) / (2.0*a);
    }   
}

vec3 color(const ray& r) {
    float t = hit_sphere(vec3(0, 0,-1), 0.5, r);
    if (t > 0.0)
    {
        vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0,0,-1));
        return 0.5 *vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5 * (unit_direction.y()+1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(int argc, char** argv)
{
    const int RENDER_WIDTH = 200;
    const int RENDER_HEIGHT = 100;
    vec3 origin(0.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
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
