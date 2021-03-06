//
//  ECS.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

inline ComponentID getComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
};

template <typename T>
inline ComponentID getComponentTypeID() noexcept {
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

class Component {
public:
    Entity* entity;

    virtual ~Component() {};
    virtual void Init() {};
    virtual void Update() {};
    virtual void Render() {};
private:
};

class Entity {
public:
    void Update();
    void Render();
    bool IsActive();

    void Destroy() {
        active = false;
    }
    
    template<typename T>
    bool HasComponent() {
        return componentBitset[getComponentID<T>()];
    }


    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));
        
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;
        
        c->Init();
        
        return *c;
    }


    template<typename T>
    T& GetComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitset;
    
};

class Manager {
public:
    
    void Update();

    void Render();
    
    void Refresh();
    
    Entity& AddEntity();

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
#endif /* ECS_hpp */
