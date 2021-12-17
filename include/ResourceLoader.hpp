#include "Utils.hpp"
#include <array>
#include <string_view>
#include <unordered_map>
#include <map>
#include <variant>
#include <vector>

template <class... LoadableTypes>
class ResourceLoader
{
private:
    std::unordered_map<std::string,std::variant<LoadableTypes...>> resources;
    std::vector<std::string> search_directories;
public:
    ResourceLoader(const std::vector<std::string>& new_search_directories): search_directories(new_search_directories) {}
    template <class LoadableType>
    void load(std::string resource_name)
    {
        const std::map<std::string_view,std::string_view> resources_paths = {
            std::pair<std::string_view,std::string_view>{"icon","assets/logo_bg-true_resized.png"},
            std::pair<std::string_view,std::string_view>{"font","PublicSans-Regular.ttf"}
        };
        std::string_view resource_path = resources_paths.at(resource_name);
        this->resources[resource_name] = loadFromFileWithFallbacks<LoadableType>(std::string(resource_path.begin(),resource_path.end()),this->search_directories);
    }
    template <class T>
    const T& get(std::string resource_name) const
    {
        return std::get<T>(this->resources.at(resource_name));
    }
    void unload(std::string resource_name)
    {
        this->resources.erase(this->resources.find(resource_name));
    }
};