#pragma once

#include "Core/Base.h"
#include "Core/Layer.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include <imgui.h>

namespace Engine
{
    class ENGINE_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnRender() override;

        void Begin();
        void End();
    };

}
