#include <SDL.h>
#include <iostream>
#include <Engine.h>
#include <Entity.h>

#define CENTERPOS SDL_WINDOWPOS_CENTERED
#define W 800
#define H 600

GameEngine::Engine::Engine() {
    this->gameWindow = SDL_CreateWindow("SDL Game Engine", CENTERPOS, CENTERPOS, W, H, SDL_WINDOW_RESIZABLE);
    this->gameRenderer = SDL_CreateRenderer(this->gameWindow, 0, SDL_RENDERER_ACCELERATED);
    this->fps = 60.0;   //  Frame per second
    this->tick = 1000.0;    //  1000 milliseconds <=> 1 second for time unit
}

GameEngine::Engine::~Engine() {
    SDL_DestroyWindow(this->gameWindow);
    SDL_DestroyRenderer(this->gameRenderer);
    SDL_Quit();
}

void GameEngine::Engine::init() {
    // The function returns 0 if successful
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void GameEngine::Engine::loop() {
    bool quit = false;
    int currentTime = 0, pastTime = SDL_GetTicks();
    int past = 0;
    
    GameEngine::Entity* obj = new GameEngine::Entity(0, 0, 50, 50);
    
    while (!quit) {
        SDL_Event event;
        SDL_PollEvent(&event);
        pastTime = currentTime;
        currentTime = SDL_GetTicks();
        this->deltaTime = (currentTime - pastTime) / this->tick;
        int now = SDL_GetTicks() - past;
        if (now >= this->tick) {
            past = SDL_GetTicks();
        } else SDL_Delay(this->tick / this->fps);
        
        if (event.type == SDL_QUIT) quit = true;
        this->moves(event);
        this->update();
    }
}

void GameEngine::Engine::launch() {
    this->init();   //  Initializes the game engine
    this->loop();   //  The main loop of the program
    this->~Engine();    //  Quit and destroy all stream in game engine
}

void GameEngine::Engine::update() {
    SDL_RenderPresent(this->gameRenderer);
    this->clean();
}

void GameEngine::Engine::clean() {
    SDL_SetRenderDrawColor(this->gameRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->gameRenderer);
}

void GameEngine::Engine::drawEntity(GameEngine::Entity* entity) {
    entity->setColor(255, 255, 0, 255);
    entity->renderFill(this->gameRenderer);
}

void GameEngine::Engine::moves(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        std::cout << event.key.keysym.scancode << std::endl;
    }
}

double GameEngine::Engine::getFPS() { return this->fps; }
double GameEngine::Engine::getTick() { return this->tick; }
double GameEngine::Engine::getDeltaTime() { return this->deltaTime; }

void GameEngine::Engine::setFPS(double fps) { this->fps = fps; }
void GameEngine::Engine::setTick(double tick) { this->tick = tick; }
void GameEngine::Engine::setDeltaTime(double deltaTime) { this->deltaTime = deltaTime; }