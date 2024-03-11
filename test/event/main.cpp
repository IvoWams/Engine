#include "event/Listener.cpp"
#include "event/Dispatcher.hpp"
#include "event/Event.hpp"

using namespace ::event;

class TestEvent1 : Event
{
    public:
        TestEvent1(){ printf("%s\n", __func__); }
        ~TestEvent1(){ printf("%s\n", __func__); }
};

class TestEvent2 : Event
{
    public:
        TestEvent2(){ printf("%s\n", __func__); }
        ~TestEvent2(){ printf("%s\n", __func__); }
};

class TestEvent3 : Event
{
    public:
        TestEvent3(){ printf("%s\n", __func__); }
        ~TestEvent3(){ printf("%s\n", __func__); }
};

class TestEventListener1 : public Listener<TestEvent1>
{
    public:
        TestEventListener1(){ printf("%s\n", __func__); }
        ~TestEventListener1(){ printf("%s\n", __func__); }

        void onEvent(TestEvent1* e){ printf("%s\n", __func__); }
};


class TestEventListener23 : public Listener<TestEvent2>, public Listener<TestEvent3>
{
    public:
        TestEventListener23(){ printf("%s\n", __func__); }
        ~TestEventListener23(){ printf("%s\n", __func__); }

        void onEvent(TestEvent2* e){ printf("%s2\n", __func__); }
        void onEvent(TestEvent3* e){ printf("%s3\n", __func__); }
};

class TestEventDispatcher1 : public Dispatcher<TestEvent1>
{
    public:
        TestEventDispatcher1(){ printf("%s\n", __func__); }
        ~TestEventDispatcher1(){ printf("%s\n", __func__); }

};

class TestEventDispatcher2 : public Dispatcher<TestEvent2>
{
    public:
        TestEventDispatcher2(){ printf("%s\n", __func__); }
        ~TestEventDispatcher2(){ printf("%s\n", __func__); }
};

class TestEventDispatcher3 : public Dispatcher<TestEvent3>
{
    public:
        TestEventDispatcher3(){ printf("%s\n", __func__); }
        ~TestEventDispatcher3(){ printf("%s\n", __func__); }
};


int main()
{
    auto le1 = new TestEventListener1();
    auto le23 = new TestEventListener23();

    auto de1 = new TestEventDispatcher1();
    auto de2 = new TestEventDispatcher2();
    auto de3 = new TestEventDispatcher3();

    de1->addListener(le1);
    de2->addListener(le23);
    de3->addListener(le23);

    de1->dispatch(new TestEvent1());
    de2->dispatch(new TestEvent2());
    de3->dispatch(new TestEvent3());

    // Cleaning up a listener should clear the dispatcher
    delete(le23);

    // No errors?
    de1->dispatch(new TestEvent1());    // Should see
    de2->dispatch(new TestEvent2());    // Should not see
    de3->dispatch(new TestEvent3());    // Should not see
}