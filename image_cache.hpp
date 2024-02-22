#include <map>

#include "images.hpp"

namespace utility
{
    // Represents a cache for images
    class ImageCache
    {
    public:
        // Returns image by path. If image is not in cache, it will be loaded from remote storage
        // raise exception if image is not found
        some_library::images::Image *GetImage(const std::string n)
        {
            std::lock_guard<std::mutex> lock(m);
            for (auto item : storage)
            {
                if (item.first == n)
                {
                    return item.second;
                }
            }
            storage[n] = some_library::images::storage::LoadImage(n);
            if (storage[n] == nullptr)
            {
                throw std::runtime_error("image not found");
            }
            return storage[n];
        }

        // Clears the cache
        void Clear()
        {
            std::lock_guard<std::mutex> lock(m);
            for (auto item : storage)
            {
                some_library::images::storage::ReleaseImage(item.second);
            }
            storage.clear();
        }

        ~ImageCache()
        {
            Clear();
        }

    private:
        std::map<std::string, some_library::images::Image *> storage;
        std::mutex m;
    };

} // namespace utility