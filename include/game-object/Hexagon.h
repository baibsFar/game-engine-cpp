#ifndef __HEXAGON_H__
#define __HEXAGON_H__
#define SIDE 6

#include <Polygon.h>

namespace GameObject {
    class Hexagon : public Polygon {
        public:
            Hexagon() : Polygon(SIDE) {}
            ~Hexagon();
    };
};

#endif