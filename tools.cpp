#include <SDL.h>
#include <cmath>
#include <tools.h>

#define DIGITS 2

void Tools::preciseF(float* number, int digitsPrecision) {
    *number = *number * pow(10, digitsPrecision);
    *number = truncf(*number);
    *number = *number / pow(10, digitsPrecision);
}

float Tools::radian(float degree) {
    Tools::preciseF(&degree, DIGITS);
    float radAngle = (M_PI * degree) / 180.0f;
    Tools::preciseF(&radAngle, DIGITS);
    return -radAngle;
}

SDL_FPoint Tools::getImageByRotation(SDL_FPoint point, SDL_FPoint center, float theta) {
    SDL_FPoint rotated;
    Tools::preciseF(&theta, DIGITS);
    float x, y;
    x = cos(-theta) * (point.x - center.x) - sin(-theta)* (point.y - center.y) + center.x;
    y = cos(-theta) * (point.y - center.y) + sin(-theta) * (point.x - center.x) + center.y;
    Tools::preciseF(&x, DIGITS);
    Tools::preciseF(&y, DIGITS);
    rotated.x = x;
    rotated.y = y;
    Tools::preciseF(&rotated.x, DIGITS);
    Tools::preciseF(&rotated.y, DIGITS);
    return rotated;
}

/* 
*   Returns the intersection point of (AB) and (CD)
*/
SDL_FPoint Tools::getIntersectionPoint(SDL_FPoint A, SDL_FPoint B, SDL_FPoint C, SDL_FPoint D) {
    SDL_FPoint I = {0.0f, 0.0f};
    float a1, b1, a2, b2;
    a1 = (B.y - A.y) / (B.x - A.x);
    b1 = A.y - (a1 * A.x);
    a2 = (D.y - C.y) / (D.x - C.x);
    b2 = D.y - (a2 * D.x);
    Tools::preciseF(&a1, DIGITS);
    Tools::preciseF(&b1, DIGITS);
    Tools::preciseF(&a2, DIGITS);
    Tools::preciseF(&b2, DIGITS);

    /* 
    *   Y = a1X + b1 => Y - a1X = b1 => |1  -a1| = |b1|
    *   Y = a2X + b2 => Y - a2X = b2 => |1  -a2| - |b2|
    *   delta = a1 - a2
    *   deltaX = -(b1 * a2) + (b2 * a1) = (a1 * b2) - (a2 * b1)
    *   deltaY = b2 - b1
    */
    float   delta = a1 - a2,
            deltaX = (a1 * b2) - (a2 * b1),
            deltaY = b2 - b1;
    Tools::preciseF(&delta, DIGITS);
    Tools::preciseF(&deltaX, DIGITS);
    Tools::preciseF(&deltaY, DIGITS);

    I.x = deltaX / delta;
    I.y = deltaY / delta;
    Tools::preciseF(&I.x, DIGITS);
    Tools::preciseF(&I.y, DIGITS);

    return I;
}