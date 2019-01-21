#include <iostream>
#include <fstream>
#include "ray.hpp"

int main(int argc, char** argv)
{
    const int RENDER_WIDTH = 800;
    const int RENDER_HEIGHT = 600;
    std::ofstream file;
    file.open("output.ppm");
    file << "P3\n" << RENDER_WIDTH << " " << RENDER_HEIGHT << "\n255\n";
    for(int y = RENDER_HEIGHT - 1; y >= 0; y--)
    {
        for(int x = 0; x < RENDER_WIDTH; x++)
        {
            // TODO : replace color values with a vec3 object
            vec3 color = vec3(float(x) / float(RENDER_WIDTH), float(y)
             / float(RENDER_HEIGHT), 0.2);
            int ir = int(255.99*color.r());
            int ig = int(255.99*color.g());
            int ib = int(255.99*color.b());
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();
    return 0;
}
