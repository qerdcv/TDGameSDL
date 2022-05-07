//
//  SpriteComponent.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <SDL2/SDL.h>
#include "Components.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path);

    void Init() override;
    void Update() override;
    void Render() override;
    
    void SetTexture(const char *path);

private:
    PositionComponent* position;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
};

#endif /* SpriteComponent_hpp */
