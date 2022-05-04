//
//  Map.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#ifndef Map_hpp
#define Map_hpp

#include <map>

#include "Game.hpp"
#include "TextureManager.hpp"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void Render();
private:
    SDL_Rect src, dest;

    std::map<int, SDL_Texture*> surfaceMap;

    int map[20][25];
};

#endif /* Map_hpp */
