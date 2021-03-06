#include "Resources.hpp"

void Resources::LoadROMFS(SDL_Renderer* renderer)
{
    //Cell textures
    std::vector<SDL_Texture*> closedVector;
    closedVector.push_back(LoadTexture(renderer, "closed"));
    _cellTextures.insert(std::make_pair(Closed, closedVector));
    
    std::vector<SDL_Texture*> openedVector;
    for (int i = 0; i < 10; i++)
        openedVector.push_back(LoadTexture(renderer, "cell" + std::to_string(i)));
    _cellTextures.insert(std::make_pair(Opened, openedVector));

    std::vector<SDL_Texture*> flaggedVector;
    flaggedVector.push_back(LoadTexture(renderer, "flagged"));
    _cellTextures.insert(std::make_pair(Flagged, flaggedVector));

    //Button textures
    _textures.insert(std::make_pair("flagOnButton", LoadTexture(renderer, "flagOnButton")));
    _textures.insert(std::make_pair("flagOffButton", LoadTexture(renderer, "flagOffButton")));
    _textures.insert(std::make_pair("restartButton", LoadTexture(renderer, "restartButton")));
    _textures.insert(std::make_pair("hardButton", LoadTexture(renderer, "hardButton")));
    _textures.insert(std::make_pair("mediumButton", LoadTexture(renderer, "mediumButton")));
    _textures.insert(std::make_pair("easyButton", LoadTexture(renderer, "easyButton")));
}

SDL_Texture* Resources::LoadTexture(SDL_Renderer* renderer, std::string image)
{
    char imagePath[50];
    sprintf(imagePath, "romfs:/%s.bmp", image.c_str());

    SDL_Surface* surface = SDL_LoadBMP(imagePath);
    return SDL_CreateTextureFromSurface(renderer, surface);
}

SDL_Texture* Resources::GetTexture(CellState state, int order)
{
    return _cellTextures[state].at(order);
}

SDL_Texture *Resources::GetTexture(std::string textureName)
{
    return _textures[textureName];
}