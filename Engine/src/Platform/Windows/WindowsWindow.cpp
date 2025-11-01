#include "gepch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include <glad/gl.h>

namespace Engine
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        GE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        GE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            GE_CORE_ASSERT(success, "Failed to intialize glfw");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        int version = gladLoadGL(glfwGetProcAddress);
        GE_CORE_ASSERT(version, "Failed to initialize glad");
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        glfwSetWindowSizeCallback(m_Window, WindowsWindow::OnWindowResizeEvent);
        glfwSetWindowCloseCallback(m_Window, WindowsWindow::OnWindowCloseEvent);
        glfwSetKeyCallback(m_Window, WindowsWindow::OnKeyPressedEvent);
        glfwSetCharCallback(m_Window, WindowsWindow::OnKeyTypedEvent);
        glfwSetMouseButtonCallback(m_Window, WindowsWindow::OnMouseButtonPressedEvent);
        glfwSetCursorPosCallback(m_Window, WindowsWindow::OnMouseMovedEvent);
        glfwSetScrollCallback(m_Window, WindowsWindow::OnMouseScrolledEvent);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

    void WindowsWindow::OnWindowResizeEvent(GLFWwindow *window, int width, int height)
    {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        data.Width = width;
        data.Height = height;

        WindowResizeEvent event(width, height);
        data.EventCallback(event);
    }

    void WindowsWindow::OnWindowCloseEvent(GLFWwindow *window)
    {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        WindowCloseEvent event;
        data.EventCallback(event);
    }

    void WindowsWindow::OnKeyPressedEvent(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        (void)scancode;
        (void)mods;
        switch (action)
        {
        case GLFW_PRESS:
        {
            KeyPressedEvent event(key, 0);
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.EventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            KeyReleasedEvent event(key);
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.EventCallback(event);
            break;
        }
        case GLFW_REPEAT:
        {
            KeyPressedEvent event(key, 1);
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.EventCallback(event);
            break;
        }
        }
    }

    void WindowsWindow::OnKeyTypedEvent(GLFWwindow *window, unsigned int keycode)
    {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        KeyTypedEvent event(keycode);
        data.EventCallback(event);
    }

    void WindowsWindow::OnMouseButtonPressedEvent(GLFWwindow *window, int button, int action, int mods)
    {
        (void)mods;
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        switch (action)
        {
        case GLFW_PRESS:
        {
            MouseButtonPressedEvent event(button);
            data.EventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            MouseButtonReleasedEvent event(button);
            data.EventCallback(event);
            break;
        }
        }
    }

    void WindowsWindow::OnMouseMovedEvent(GLFWwindow *window, double xPos, double yPos)
    {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        MouseMovedEvent event((float)xPos, (float)yPos);
        data.EventCallback(event);
    }

    void WindowsWindow::OnMouseScrolledEvent(GLFWwindow *window, double xOffset, double yOffset)
    {
        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
        MouseScrolledEvent event((float)xOffset, (float)yOffset);
        data.EventCallback(event);
    }

}
