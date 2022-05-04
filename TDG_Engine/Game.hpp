//
//  Game.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 04.05.2022.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp";

class Game {
public:
    Game(const char* title, int x, int y, int w, int h, bool fullscreen);
    ~Game();
    
    bool running() { return isRunning; };

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    static SDL_Renderer* renderer;
    
    static void scc(int code) {
        if (code < 0) {
            std::cout << "ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }
    
    template<typename T>
    static T* scp(T* ptr) {
        if (ptr == nullptr) {
            std::cout << "ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }
        
        return ptr;
    }

private:
    int y = 0;
    int cnt = 0;
    bool isRunning;

    SDL_Window* window;
    
};

#endif /* Game_hpp */
