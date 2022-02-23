#ifndef __OCTAGON_H__
#define __OCTAGON_H__
#define SIDE 8

#include <Polygon.h>

namespace GameObject {
    class Octagon : public Polygon {
        public:
            Octagon() : Polygon(SIDE) {}
            ~Octagon();
    };
};

#endif