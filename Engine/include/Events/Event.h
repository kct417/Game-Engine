#pragma once

#include "Core/Base.h"

namespace Engine
{

    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType GetStaticType() { return EventType::type; }                \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

    class ENGINE_API Event
    {
        friend class EventDispatcher;

    public:
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsHandled() const { return m_Handled; }
        inline bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event &event)
            : m_Event(event)
        {
        }

        template <typename Event, typename Function>
        bool Dispatch(const Function &function)
        {
            if (m_Event.GetEventType() == Event::GetStaticType())
            {
                m_Event.m_Handled = function(static_cast<Event &>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event &m_Event;
    };

    inline std::string format_as(const Event &event)
    {
        return event.ToString();
    }

}
