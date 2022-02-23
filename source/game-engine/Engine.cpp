#include <SDL.h>
#include <iostream>
#include <Engine.h>
#include <Square.h>

#define CENTERPOS SDL_WINDOWPOS_CENTERED
#define W 800
#define H 600
#define SPEED 100.0f
#define ROTATION_SPEED 150.0f
#define THETA 1.0f

GameEngine::Engine::Engine() {
    this->window = SDL_CreateWindow("SDL Game Engine", CENTERPOS, CENTERPOS, W, H, SDL_WINDOW_RESIZABLE);
    this->renderer = SDL_CreateRenderer(this->window, 0, SDL_RENDERER_ACCELERATED);
    this->fps = 60.0;   //  Frame per second
    this->tick = 1000.0;    //  1000 milliseconds <=> 1 second for time unit
}

GameEngine::Engine::~Engine() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
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

    GameObject::Square* square = new GameObject::Square();
    
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

        // Quit event handler and update the quit variable
        if (event.type == SDL_QUIT) quit = true;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT) square->translateX(-SPEED * this->deltaTime);
            if (event.key.keysym.sym == SDLK_RIGHT) square->translateX(SPEED * this->deltaTime);
            if (event.key.keysym.sym == SDLK_UP) square->translateY(-SPEED * this->deltaTime);
            if (event.key.keysym.sym == SDLK_DOWN) square->translateY(SPEED * this->deltaTime);
            if (event.key.keysym.sym == SDLK_r) square->rotate(ROTATION_SPEED * THETA * this->deltaTime);
            if (event.key.keysym.sym == SDLK_s) square->scale(1.02f);
        }
        square->draw(this->renderer);
        this->update();
    }
}

void GameEngine::Engine::launch() {
    this->init();   //  Initializes the game engine
    this->loop();   //  The main loop of the program
    this->~Engine();    //  Quit and destroy all stream in game engine
}

void GameEngine::Engine::update() {
    SDL_RenderPresent(this->renderer);
    this->clean();
}

void GameEngine::Engine::clean() {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

double GameEngine::Engine::getFPS() { return this->fps; }
double GameEngine::Engine::getTick() { return this->tick; }
double GameEngine::Engine::getDeltaTime() { return this->deltaTime; }

void GameEngine::Engine::setFPS(double fps) { this->fps = fps; }
void GameEngine::Engine::setTick(double tick) { this->tick = tick; }
void GameEngine::Engine::setDeltaTime(double deltaTime) { this->deltaTime = deltaTime; }