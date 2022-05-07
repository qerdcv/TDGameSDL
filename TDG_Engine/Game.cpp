//
//  Game.cpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 04.05.2022.
//
#include "Game.hpp"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.AddEntity());

Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
    isRunning = false;

    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    Game::scc(SDL_Init(SDL_INIT_EVERYTHING));

    window = Game::scp(SDL_CreateWindow(title, x, y, w, h, flags));
    renderer = Game::scp(SDL_CreateRenderer(window, -1, 0));
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    isRunning = true;
    map = new Map();

    player.AddComponent<PositionComponent>(100, 100);
    player.AddComponent<SpriteComponent>("assets/player.png");
    
}

void Game::HandleEvents() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }
}

void Game::Update() {
    manager.Refresh();
    manager.Update();
    
    if (player.GetComponent<PositionComponent>().GetXPos() > 200) {
        player.GetComponent<SpriteComponent>().SetTexture("assets/enemy.png");
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);

    map->Render();
    manager.Render();

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    SDL_Quit();
}
