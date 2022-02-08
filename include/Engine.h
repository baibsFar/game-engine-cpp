#include <SDL.h>
#include <Entity.h>

#ifndef __ENGINE_H__
#define __ENGINE_H__

namespace GameEngine {
    class Engine {
        private:
            SDL_Window* gameWindow;
            SDL_Renderer* gameRenderer;
            double fps;
            double tick;
            double deltaTime;
        public:
            Engine();
            ~Engine();
            void init();
            void loop();
            void launch();
            void update();
            void clean();
            void drawEntity(GameEngine::Entity*);
            void moves(SDL_Event);
            double getFPS();
            double getTick();
            double getDeltaTime();
            void setFPS(double);
            void setTick(double);
            void setDeltaTime(double);
    };
};

#endif