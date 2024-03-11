#include "Listener.hpp"
#include "Dispatcher.hpp"

namespace event
{
    template <class T>
    Listener<T>::~Listener()
    {
        Dispatcher<T>::cleanup(this);
    }
}