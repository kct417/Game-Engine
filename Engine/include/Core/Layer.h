#pragma once

#include "Base.h"
#include "Events/Event.h"

namespace Engine
{

    class ENGINE_API Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) { (void)event; }

        inline const std::string &GetName() const { return m_Name; }

    protected:
        std::string m_Name;
    };

}
