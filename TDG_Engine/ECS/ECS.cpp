//
//  ECS.cpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#include "ECS.hpp"

// Entity
void Entity::Update()  {
    for (auto& c: components) c->Update();
}

void Entity::Render() {
    for (auto& c: components) c->Render();
}

bool Entity::IsActive() {
   return active;
}



/*
 Manager
 */
void Manager::Update() {
    for (auto& e : entities) e->Update();
}

void Manager::Render() {
    for (auto& e : entities) e->Render();
}

void Manager::Refresh() {
    entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity){
        return !mEntity->IsActive();
    }), std::end(entities));

}

Entity& Manager::AddEntity() {
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr{ e };
    entities.emplace_back(std::move(uPtr));
    return *e;
}
