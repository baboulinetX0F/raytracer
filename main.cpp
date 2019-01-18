#include <iostream>
#include <fstream>

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
	    float r = float(x) / float(RENDER_WIDTH);
	    float g = float(y) / float(RENDER_HEIGHT);
	    float b = 0.2;
	    int ir = int(255.99*r);
	    int ig = int(255.99*g);
	    int ib = int(255.99*b);
	    file << ir << " " << ig << " " << ib << "\n";
	}
    }
    file.close();
    return 0;
}
