#include "gepch.h"
#include "Platform/Windows/WindowsInput.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace Engine
{
    Input *Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos};
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto [xpos, ypos] = GetMousePositionImpl();
        return xpos;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [xpos, ypos] = GetMousePositionImpl();
        return ypos;
    }

}
