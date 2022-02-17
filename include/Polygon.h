#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <SDL.h>
#include <queue.h>

namespace GameObject {
    class Polygon {
        private:
            SDL_FPoint* vertices;
            SDL_Color color;

        public:
            Polygon(int side);
            ~Polygon();

    };
};

#endif