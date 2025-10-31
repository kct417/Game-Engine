#pragma once

#include "Core/Window.h"

#include <GLFW/glfw3.h>

namespace Engine
{

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps &props);
        virtual ~WindowsWindow();

        virtual void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        virtual void SetEventCallback(const EventCallbackFunction &callback) override { m_Data.EventCallback = callback; }
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;

        virtual void *GetNativeWindow() const override { return m_Window; }

    private:
        void Init(const WindowProps &props);
        void Shutdown();

        static void OnWindowResizeEvent(GLFWwindow *window, int width, int height);
        static void OnWindowCloseEvent(GLFWwindow *window);
        static void OnKeyPressedEvent(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void OnKeyTypedEvent(GLFWwindow *window, unsigned int codepoint);
        static void OnMouseButtonPressedEvent(GLFWwindow *window, int button, int action, int mods);
        static void OnMouseMovedEvent(GLFWwindow *window, double xpos, double ypos);
        static void OnMouseScrolledEvent(GLFWwindow *window, double xoffset, double yoffset);

    private:
        GLFWwindow *m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFunction EventCallback;
        };

        WindowData m_Data;
    };

}
