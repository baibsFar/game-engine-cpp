#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#define SIDE 50

#include <Polygon.h>

namespace GameObject {
    class Circle : public Polygon {
        public:
            Circle() : Polygon(SIDE) {}
            ~Circle();
    };
};


#endif