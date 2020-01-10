#pragma once
#include "BMessage.hpp"


class BMessage_Handler
{

    struct Listener
    {
        virtual void handle_message(const BMessage& message) = 0;
    };

    map< string, list< Listener* > > listeners;

public:

    void register_listener(const string& message_id, Listener& listener)
    {
        listeners[message_id].push_back(&listener);
    }

    void unregister_listener(const string& message_id, Listener& listener)
    {
        // ...
    }

    // Enviar a todos los listeners.
    void multicast(const BMessage& message)
    {
        if (listeners.count(message.id) > 0)
        {
            for (auto listener : listeners[message.id])
            {
                listener->handle_message(message);
            }
        }
    }


};

