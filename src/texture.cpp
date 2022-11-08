#include "texture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

Texture::Texture()
{
    width = 0;
    height = 0;
    texture = NULL;
}

bool Texture::loadFromFile(std::string p_path, SDL_Renderer* p_renderer)
{    
    // Get rid of pre-existing texture
    free();

    SDL_Surface* tmpSurface = IMG_Load(p_path.c_str());
    if(tmpSurface == NULL)
    {
        std::cout << "Failed to load image " << p_path << ". SDL Image error: " << IMG_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(p_renderer, tmpSurface);
    if(texture == NULL)
    {
        std::cout << "Failed to create texture from surface. SDL Image error: " << IMG_GetError() << std::endl;
        SDL_FreeSurface(tmpSurface);
        return false;
    }

    width = tmpSurface -> w;
    height = tmpSurface -> h;

    SDL_FreeSurface(tmpSurface);
    return true;
}

void Texture::free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

float Texture::getWidth()
{
    return width;
}

float Texture::getHeight()
{
    return height;
}