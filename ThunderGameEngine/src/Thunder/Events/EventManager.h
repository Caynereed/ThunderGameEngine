// EventManager.h
#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <list>
#include "Event.h"
#include "EventListener.h"

namespace Thunder {

    class EventManager {
    private:
        std::list<EventListener*> listeners;

    public:
        void addListener(EventListener* listener) {
            listeners.push_back(listener);
        }

        void removeListener(EventListener* listener) {
            listeners.remove(listener);
        }

        void dispatchEvent(Event& event) {
            for (auto& listener : listeners) {
                if (!event.Handled) {
                    listener->onEvent(event);
                }
            }
        }
    };
}
#endif // EVENT_MANAGER_H
