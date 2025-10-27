#pragma once

#include "Base.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/ApplicationEvent.h"

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

    private:
        bool OnWindowClose(WindowCloseEvent &event);

    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
    };

    Application *CreateApplication();
}
