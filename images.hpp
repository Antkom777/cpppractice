#include <string>
#include <chrono>
#include <thread>

// This is a part of 3rdParty library that we are using in our project
// We can't change it
namespace some_library::images
{
    // Image class is a part of some library
    struct Image
    {
        explicit Image(std::string path) : path_(std::move(path)) {}

        std::string path_;
        /* data */
    };

    namespace storage
    {
        // Loads image from remove storage by path
        inline Image *LoadImage(const std::string &path)
        {
            using namespace std::chrono_literals;
            // Simulate long loading
            std::this_thread::sleep_for(2s);
            return new Image(path);
        }

        // Releases image from memory
        inline void ReleaseImage(Image *image)
        {
            delete image;
        }
    } // namespace storage
} // namespace some_library::images
