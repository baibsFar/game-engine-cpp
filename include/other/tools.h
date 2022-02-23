#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <SDL.h>

namespace Tools {
    void preciseF(float*, int);
    float radian(float);
    SDL_FPoint getImageByRotation(SDL_FPoint, SDL_FPoint, float);
    SDL_FPoint getIntersectionPoint(SDL_FPoint, SDL_FPoint, SDL_FPoint, SDL_FPoint);
};

#endif