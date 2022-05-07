//
//  PositionComponent.cpp
//  TDG_Engine
//
//  Created by Vadym Tishchenko on 07.05.2022.
//

#include "PositionComponent.hpp"

void PositionComponent::Update() {
    xpos++;
    ypos++;
}

void PositionComponent::Render() {
    
}

int PositionComponent::GetXPos() { return xpos; }
int PositionComponent::GetYPos() { return ypos; }
void PositionComponent::SetXPos(int x) { xpos = x; }
void PositionComponent::SetYPos(int y) { ypos = y; }

void PositionComponent::SetPos(int x, int y) {
    xpos = x;
    ypos = y;
}
