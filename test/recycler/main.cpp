
#include <iostream>
#include "memory/recycler/Recycler.hpp"

using memory::recycler::Slot;
using memory::recycler::Recycler;

class Obj : public Recycler<Obj>
{
    private:

    public:
        Obj()
        {
            printf("%s\n", __func__);
        }

        ~Obj()
        {
            printf("%s\n", __func__);
        }
};

class Obj2 : public Recycler<Obj2>
{
    public:
        Obj2()
        {
            printf("%s\n", __func__);
        }

        ~Obj2()
        {
            printf("%s\n", __func__);
        }
};

int main()
{
    // auto slots = RecyclerManager<Obj>::slots;

    auto obj1 = new Obj();
    printf("obj1 = %p\n", obj1);
    auto obj2 = new Obj2();
    printf("obj2 = %p\n", obj2);
    delete(obj1);
    printf("Deleted obj1\n");
    auto obj3 = new Obj();
    printf("obj3 = %p\n", obj3);
    auto obj4 = new Obj();
    printf("obj4 = %p\n", obj4);
    auto obj5 = new Obj();
    printf("obj5 = %p\n", obj5);
    auto obj6 = new Obj();
    printf("obj6 = %p\n", obj6);
    delete(obj5);
    printf("Deleted obj5\n");
    auto obj7 = new Obj();
    printf("obj7 = %p\n", obj7);
}