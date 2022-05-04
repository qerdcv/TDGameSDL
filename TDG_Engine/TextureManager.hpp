//
//  TextureManager.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 05.05.2022.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include "Game.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char *texture);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
private:
};
#endif /* TextureManager_hpp */
