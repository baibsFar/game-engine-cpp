#include <SDL.h>

#ifndef __ENTITY_H__
#define __ENTITY_H__

namespace GameEngine {
    class Entity {
        private:
            SDL_Rect transform;
            SDL_Color color;
        public:
            Entity(int, int, int, int);
            ~Entity();
            void translateX(int);
            void translateY(int);
            void translate(int, int);
            void rotate(double );   // Rotate the entity with the degree wanted passed as paramater(double)
            void setColor(SDL_Color);
            void setColor(int, int, int, int);
            void setOpactity(int);
            int getX();
            int getY();
            int getWidth();
            int getHeight();
            SDL_Color getColor();
            void renderFill(SDL_Renderer*);
            void renderStroke(SDL_Renderer*);
    };
};

#endif