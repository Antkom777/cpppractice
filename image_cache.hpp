#include <shared_mutex>
#include <future>
#include <stdexcept>
#include <memory>
#include <unordered_map>

#include "images.hpp"

namespace utility
{
    // Represents a cache for images
    class ImageCache
    {
    public:
        // Returns image by path. If image is not in cache, it will be loaded from remote storage
        // raise exception if image is not found
        std::shared_ptr<some_library::images::Image> GetImage(const std::string& name) {
            std::shared_lock<std::shared_mutex> ReadLock(m);
            auto it = storage.find(name);
            if (it != storage.end()) {
                return it->second; 
            }
            ReadLock.unlock(); 

            auto imgFuture = std::async(std::launch::async, [this, &name] {
                auto img = some_library::images::storage::LoadImage(name);
                if (!img) {
                    throw std::runtime_error("Image not found: " + name);
                }
                std::unique_lock<std::shared_mutex> writeLock(m); 
                return storage.emplace(name, std::shared_ptr<some_library::images::Image>(img)).first->second;
            });

            return imgFuture.get(); 
        }
        // Clears the cache
        void Clear() {
            std::unique_lock<std::shared_mutex> lock(m);
            storage.clear();
        }

    private:
        mutable std::unordered_map<std::string, std::shared_ptr<some_library::images::Image>> storage;
        mutable std::shared_mutex m; 
    };

} // namespace utility