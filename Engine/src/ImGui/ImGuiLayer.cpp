#include "gepch.h"
#include "ImGui/ImGuiLayer.h"

#include "Core/Application.h"

#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

namespace Engine
{

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        Application &app = Application::Get();
        GLFWwindow *window = static_cast<GLFWwindow *>(app.GetWindow().GetNativeWindow());
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(IMGUI_OPENGL_VERSION);
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnRender()
    {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }

    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

}
