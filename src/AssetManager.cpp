#include "AssetManager.hpp"

namespace Engine
{
    AssetManager::AssetManager()
    {
    }

    AssetManager::~AssetManager()
    {
    }

    void AssetManager::addTexture(int id, const std::string &file_path, bool repeated)
    {
        auto texture = std::make_unique<sf::Texture>();

        if (texture->loadFromFile(file_path))
        {
            texture->setRepeated(repeated);
            textures_[id] = std::move(texture);
        }
    }

    void AssetManager::addFont(int id, const std::string &file_path)
    {
        auto font = std::make_unique<sf::Font>();

        if (font->loadFromFile(file_path))
        {
            fonts_[id] = std::move(font);
        }
    }

    const sf::Texture &AssetManager::getTexture(int id) const
    {
        return *(textures_.at(id).get());
    }

    const sf::Font &AssetManager::getFont(int id) const
    {
        return *(fonts_.at(id).get());
    }
}