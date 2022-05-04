//
//  GameObject.cpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 05.05.2022.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y) {
    xpos = x;
    ypos = y;

    objTexture = Game::scp(TextureManager::LoadTexture(textureSheet));
}

void GameObject::Update() {
    xpos++;
    ypos++;

    src.h = src.w = 32;
    src.x = 0;
    src.y = 0;
    
    dest.x = xpos;
    dest.y = ypos;
    dest.w = src.w * 2;
    dest.h = src.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &src, &dest);
}
