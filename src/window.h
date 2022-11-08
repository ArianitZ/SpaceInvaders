#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window
{
    public:
        Window(int p_width, int p_height, std::string p_title);

        bool init();
        void renderPresent();
        void renderClear();
        void render();
        void free();

    private:
        int width{};
        int height{};
        std::string title{};

        SDL_Renderer* renderer{NULL};
        SDL_Window* window{NULL};


};