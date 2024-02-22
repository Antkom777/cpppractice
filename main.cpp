#include "image_cache.hpp"

int main()
{
    utility::ImageCache cache;
    auto image1 = cache.GetImage("//folder1/folder2/smile.jpg");
    auto image2 = cache.GetImage("//folder1/folder2/smile.jpg");
    auto image3 = cache.GetImage("//folder1/folder2/cry.jpg");
    return 0;
}