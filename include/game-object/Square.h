#ifndef __SQUARE_H__
#define __SQUARE_H__
#define SIDE 4

#include <Polygon.h>

namespace GameObject {
    class Square : public Polygon {
        public:
            Square() : Polygon(SIDE) {}
            ~Square();
    };
};

#endif