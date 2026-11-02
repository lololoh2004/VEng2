#pragma once

#include "cglm/struct/vec2.h"


class inputSys{
    float m_mouseX;
    float m_mouseY;
public:
    inputSys()  = default;
    ~inputSys() = default;

    // Keyboard
    bool isKeyScanCodeDown(int key);

    // Mouse
    void updateMouse();

    [[nodiscard]] float getMouseX()   const { return m_mouseX; }
    [[nodiscard]] float getMouseY()   const { return m_mouseY; }
    [[nodiscard]] vec2s getMousePos() const { return {m_mouseX, m_mouseY}; }

    bool isMousePressed(int sdlButton);
    bool IsMouseReleased(int sdlButton);
    bool IsMouseDown(int sdlButton);
    bool IsMouseUp(int sdlButton);
};
