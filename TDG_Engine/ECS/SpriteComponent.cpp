//
//  SpriteComponent.cpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(const char* path) {
    SetTexture(path);
}

void SpriteComponent::Init() {
    position = &entity->GetComponent<PositionComponent>();
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 32;
    
    destRect.w = destRect.h = 64;
    destRect.w = destRect.h = 64;
}

void SpriteComponent::Update() {
    destRect.x = position->GetXPos();
    destRect.y = position->GetYPos();
}

void SpriteComponent::Render() {
    TextureManager::Draw(texture, srcRect, destRect);
}

void SpriteComponent::SetTexture(const char *path) {
    texture = TextureManager::LoadTexture(path);
}
