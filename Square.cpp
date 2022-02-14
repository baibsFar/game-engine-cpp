#include <iostream>
#include <SDL.h>
#include <tools.h>
#include <Square.h>

#define DIGITS 2

GameObject::Square::Square(float x, float y, float size) {
    Tools::preciseF(&x, DIGITS);
    Tools::preciseF(&y, DIGITS);
    Tools::preciseF(&size, DIGITS);
    this->A.x = x;
    this->A.y = y;

    this->B.x = this->A.x + size;
    this->B.y = this->A.y;

    this->C.x = this->A.x + size;
    this->C.y = this->A.y + size;

    this->D.x = this->A.x;
    this->D.y = this->A.y + size;

    this->I = Tools::getIntersectionPoint(this->A, this->C, this->D, this->B);

    this->color.r = this->color.g = this->color.b = this->color.a = 255;
}

void GameObject::Square::translateX(float speedX) {
    Tools::preciseF(&speedX, DIGITS);
    this->A.x = this->A.x + speedX;
    this->B.x = this->B.x + speedX;
    this->C.x = this->C.x + speedX;
    this->D.x = this->D.x + speedX;
    this->I.x = this->I.x + speedX;
    std::cout << this->I.x << " ; " << this->I.y << std::endl;
}

void GameObject::Square::translateY(float speedY) {
    Tools::preciseF(&speedY, DIGITS);
    this->A.y = this->A.y + speedY;
    this->B.y = this->B.y + speedY;
    this->C.y = this->C.y + speedY;
    this->D.y = this->D.y + speedY;
    this->I.y = this->I.y + speedY;
    std::cout << this->I.x << " ; " << this->I.y << std::endl;
}

void GameObject::Square::translate(float speedX, float speedY) {
    this->translateX(speedX);
    this->translateY(speedY);
    std::cout << this->I.x << " ; " << this->I.y << std::endl;
}
/* 
*   Must not get all the time the intersection point
*/
void GameObject::Square::rotate(float theta){
    Tools::preciseF(&theta, DIGITS);
    theta = Tools::radian(theta);
    Tools::preciseF(&theta, DIGITS);
    SDL_FPoint  A2, B2, C2, D2;
    A2 = Tools::getImageByRotation(this->A, this->I, theta);
    B2 = Tools::getImageByRotation(this->B, this->I, theta);
    C2 = Tools::getImageByRotation(this->C, this->I, theta);
    D2 = Tools::getImageByRotation(this->D, this->I, theta);
    this->A = A2;
    this->B = B2;
    this->C = C2;
    this->D = D2;
}

void GameObject::Square::scale(float kx, float ky) {
    // A
    this->A.x = (kx * (this->A.x - this->I.x)) + this->I.x;
    this->A.y = (ky * (this->A.y - this->I.y)) + this->I.y;
    // B
    this->B.x = (kx * (this->B.x - this->I.x)) + this->I.x;
    this->B.y = (ky * (this->B.y - this->I.y)) + this->I.y;
    // C
    this->C.x = (kx * (this->C.x - this->I.x)) + this->I.x;
    this->C.y = (ky * (this->C.y - this->I.y)) + this->I.y;
    // D
    this->D.x = (kx * (this->D.x - this->I.x)) + this->I.x;
    this->D.y = (ky * (this->D.y - this->I.y)) + this->I.y;
}

void GameObject::Square::scaleX(float k) {
    // A
    this->A.x = (k * (this->A.x - this->I.x)) + this->I.x;
    // B
    this->B.x = (k * (this->B.x - this->I.x)) + this->I.x;
    // C
    this->C.x = (k * (this->C.x - this->I.x)) + this->I.x;
    // D
    this->D.x = (k * (this->D.x - this->I.x)) + this->I.x;
}

void GameObject::Square::scaleY(float k) {
    // A
    this->A.y = (k * (this->A.y - this->I.y)) + this->I.y;
    // B
    this->B.y = (k * (this->B.y - this->I.y)) + this->I.y;
    // C
    this->C.y = (k * (this->C.y - this->I.y)) + this->I.y;
    // D
    this->D.y = (k * (this->D.y - this->I.y)) + this->I.y;
}

void GameObject::Square::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_FPoint vertices[4];
    vertices[0] = this->A;
    vertices[1] = this->B;
    vertices[2] = this->C;
    vertices[3] = this->D;
    SDL_RenderDrawLinesF(renderer, vertices, 4);
    SDL_RenderDrawLineF(renderer, this->D.x, this->D.y, this->A.x, this->A.y);
    /* SDL_RenderDrawLineF(renderer, this->A.x, this->A.y, this->C.x, this->C.y);
    SDL_RenderDrawLineF(renderer, this->D.x, this->D.y, this->B.x, this->B.y); */
    /* SDL_SetRenderDrawColor(renderer, 0x00, 0x96, 0xff, 255);
    SDL_RenderDrawLineF(renderer, 0.0f, 0.0f, this->I.x, this->I.y);
    SDL_RenderDrawLineF(renderer, 0.0f, 600.0f, this->I.x, this->I.y);
    SDL_RenderDrawLineF(renderer, 800.0f, 0.0f, this->I.x, this->I.y);
    SDL_RenderDrawLineF(renderer, 800.0f, 600.0f, this->I.x, this->I.y); */
}