#pragma once

#include "Core/Base.h"
#include "Inputs/Input.h"

namespace Engine
{

    class WindowsInput : public Input
    {
    private:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };

}
