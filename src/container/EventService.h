#pragma once

#ifndef ENGINE_CONTAINER_EVENTSERVICE_H
#define ENGINE_CONTAINER_EVENTSERVICE_H

#include "Item.h"
#include "Container.h"

namespace engine::container
{
    template <class T>
    class EventService : Container<T> : Item
    {
        
    };
}

#endif