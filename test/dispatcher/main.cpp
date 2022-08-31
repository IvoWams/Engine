#include "TestDispatcher.h"
#include "TestListener.h"
#include "TestEvent.h"
#include "AnotherEvent.h"
#include "TestPropagator.h"

using namespace app::test;

int main()
{
    auto dispatcher = new TestDispatcher();
    auto listener = new TestListener();
    ((Dispatcher<TestEvent> *)dispatcher)->addListener(listener);
    ((Dispatcher<AnotherEvent> *)dispatcher)->addListener(listener);

    TestDispatcher staticDispatcher;
    ((Dispatcher<TestEvent>)staticDispatcher).addListener(listener);

    auto e = new TestEvent("Dit is een testevent\n");
    dispatcher->dispatch(e);    // Runs through te handling stack with this message
    delete e;                   // main is owner of e, and cleans the event

    auto propagator = new TestPropagator();
    propagator->addListener(listener);
    dispatcher->addListener(propagator);
    dispatcher->dispatch(new TestEvent("This should be double\n"));

    auto anotherevent = new AnotherEvent("This is another event", 123);
    dispatcher->dispatch(anotherevent);
}
