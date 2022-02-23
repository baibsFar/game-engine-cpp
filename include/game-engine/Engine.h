#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <SDL.h>

namespace GameEngine {
    class Engine {
        private:
            SDL_Window* window;
            SDL_Renderer* renderer;
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
            double getFPS();
            double getTick();
            double getDeltaTime();
            void setFPS(double);
            void setTick(double);
            void setDeltaTime(double);
    };
};

#endif