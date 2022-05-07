//
//  PositionComponent.hpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "ECS.hpp"

class PositionComponent : public Component {
public:
    PositionComponent() {
        xpos = ypos = 0;
    }

    PositionComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }
    
    void Update() override;

    void Render() override;

    int GetXPos();
    int GetYPos();

    void SetXPos(int x);
    void SetYPos(int y);
    void SetPos(int x, int y);

private:
    int xpos, ypos;
};

#endif /* PositionComponent_hpp */
