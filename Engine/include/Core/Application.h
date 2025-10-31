#pragma once

#include "Base.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"

namespace Engine
{

    class ENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

        inline static Application &Get() { return *s_Instance; }
        inline Window &GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent &event);

    private:
        bool m_Running = true;
        static Application *s_Instance;
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        ImGuiLayer *m_ImGuiLayer;
    };

    Application *CreateApplication();
}
