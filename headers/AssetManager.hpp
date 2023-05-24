#ifndef __ASSET_MANAGER_H__
#define __ASSET_MANAGER_H__

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
class AssetManager
{
public:
    // Constructor and destructor
    AssetManager();
    ~AssetManager();

    // Member functions
    void addTexture(int id, const std::string &file_path, bool repeated = false);
    void addFont(int id, const std::string &file_path);
    const sf::Texture &getTexture(int id) const;
    const sf::Font &getFont(int id) const;

private:
    // Private variables
    std::map<int, std::unique_ptr<sf::Texture>> textures_;
    std::map<int, std::unique_ptr<sf::Font>> fonts_;
};
}

#endif // __ASSET_MANAGER_H__