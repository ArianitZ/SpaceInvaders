#pragma once

#include <memory>
#include <string>
#include "window.h"
#include "texture.h"

class Game
{
    public:
        Game(int p_windowWidth, int p_windowHeight, std::string p_title);
        void run();

    private:
        int width{0};
        int height{0};
        std::string title{""};

        bool gameRunning{false};

        std::unique_ptr<Window> window{};
        bool init();
        void handleEvents();
        void render();
        void close();
};
