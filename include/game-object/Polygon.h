#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <SDL.h>
#include <queue.h>

namespace GameObject {
    class Polygon {
        private:
            Queue<SDL_FPoint>* vertices;
            SDL_Color color;
            SDL_FPoint I;

        public:
            Polygon(int side);
            ~Polygon();
            SDL_FPoint getRotatedPoint(SDL_FPoint, SDL_FPoint, float);
            void draw(SDL_Renderer*);
            void translateX(float);
            void translateY(float);
            void translate(float, float);
            void rotate(float);
            void scaleX(float);
            void scaleY(float);
            void scale(float);
    };
};

#endif