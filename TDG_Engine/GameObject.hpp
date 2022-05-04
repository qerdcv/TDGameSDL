//
//  GameObject.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 05.05.2022.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect src, dest;
};
#endif /* GameObject_hpp */
