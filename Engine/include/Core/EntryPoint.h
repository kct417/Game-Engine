#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Engine::Application *Engine::CreateApplication();

int main()
{
    Engine::Log::Init();
    GE_CORE_INFO("Core Logger Initialized");
    GE_INFO("Client Logger Initialized");

    auto application = Engine::CreateApplication();
    application->Run();
    delete application;
}

#endif
