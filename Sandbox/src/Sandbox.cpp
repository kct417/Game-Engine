#include <Engine.h>

class ExampleLayer : public Engine::Layer
{
public:
    ExampleLayer()
        : Engine::Layer("ExampleLayer")
    {
    }

    virtual void OnUpdate() override
    {
        if (Engine::Input::IsKeyPressed(GE_KEY_TAB))
            GE_INFO("Tab");
    }

    virtual void OnEvent(Engine::Event &event) override
    {
        (void)event;
    }
};

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}
