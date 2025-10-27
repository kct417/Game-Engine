#include <Engine.h>

class Layer : public Engine::Layer
{
public:
    Layer()
        : Engine::Layer()
    {
    }

    void OnUpdate() override
    {
        GE_CORE_INFO("Layer Update");
    }

    void OnEvent(Engine::Event &event) override
    {
        GE_CORE_INFO("{0}", event);
    }
};

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new Layer());
    }

    ~Sandbox() {}
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}
