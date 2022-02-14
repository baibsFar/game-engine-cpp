#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <SDL.h>

namespace GameObject {
    class Square {
        private:
            SDL_FPoint A;
            SDL_FPoint B;
            SDL_FPoint C;
            SDL_FPoint D;
            SDL_FPoint I;
            SDL_Color color;

        public:
            Square(float, float, float);
            ~Square();
            void translateX(float);
            void translateY(float);
            void translate(float, float);
            void rotate(float);
            void scale(float, float);
            void scaleX(float);
            void scaleY(float);
            void draw(SDL_Renderer*);
    };
};

#endif