#include <iostream>
#include <Engine.h>

using namespace std;

int main(int argc, char** argv) {
    GameEngine::Engine* engine = new GameEngine::Engine();
    engine->launch();
    delete(engine);
    return 0;
}