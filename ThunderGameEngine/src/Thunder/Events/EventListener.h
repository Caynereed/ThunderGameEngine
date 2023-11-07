// EventListener.h
#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "Event.h"

namespace Thunder {

    class EventListener {
    public:
        virtual ~EventListener() = default;
        virtual void onEvent(Event& event) = 0;
    };
} // namespace Thunder
#endif // EVENT_LISTENER_H

