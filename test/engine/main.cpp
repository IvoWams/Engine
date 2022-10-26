#include "engine/Engine.h"
#include "engine/GameOperatorInterface.h"

using namespace engine;

struct TestGameOperator : public GameOperatorInterface
{
    void advance(long nanoSeconds)
    {
        // printf("We are advancing %d nsec!\n", nanoSeconds);

        double frequency = 1 / (0.000000001 * nanoSeconds);

        // printf("H=%fHz\n", frequency);
    }
};



int main()
{
    Engine *engine = Engine::getInstance();
    auto o = new TestGameOperator();
    engine->setGameOperator(o);

    printf("Go\n");

    for (int i = 0; i < 1000000; i++) {
        o->update();
        o->update();
        o->update();
    }

    printf("Finish\n");
}