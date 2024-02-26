#include <iostream>
#include "image_cache.hpp"

int main()
{
    utility::ImageCache cache;

    try {
        auto image1 = cache.GetImage("//folder1/folder2/smile.jpg");
        auto image2 = cache.GetImage("//folder1/folder2/smile.jpg");
        auto image3 = cache.GetImage("//folder1/folder2/cry.jpg");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}