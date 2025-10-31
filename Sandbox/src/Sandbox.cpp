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
        GE_CORE_INFO("Layer Update");
    }

    virtual void OnEvent(Engine::Event &event) override
    {
        GE_CORE_INFO("{0}", event);
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
