#include <iostream>
#include <fstream>
#include "sphere.hpp"
#include "hitable_list.hpp"


vec3 color(const ray& r, hitable* world) {
    hit_record hit;
    if (world->hit(r, 0.0, 10000.0, hit))
    {
        vec3 N = hit.normal;
        return 0.5 *vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    // fake sky gradient backgrounc
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y()+1.0);
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
    hitable* list[2];
    list[0] = new sphere(vec3(0, 0,-1), 0.5);
    list[1] = new sphere(vec3(0, -100.5,-1), 100);
    hitable* world = new hitable_list(list, 2);
    file << "P3\n" << RENDER_WIDTH << " " << RENDER_HEIGHT << "\n255\n";
    for(int y = RENDER_HEIGHT - 1; y >= 0; y--)
    {
        for(int x = 0; x < RENDER_WIDTH; x++)
        {            
            float u = float(x) / float(RENDER_WIDTH);
            float v = float(y) / float(RENDER_HEIGHT);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r, world);
            int ir = int(255.99*col.r());
            int ig = int(255.99*col.g());
            int ib = int(255.99*col.b());
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();
    return 0;
}
