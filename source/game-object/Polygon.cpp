#include <SDL.h>
#include <cmath>
#include <iostream>
#include <Polygon.h>
#include <tools.h>

#define DIGITS 2

GameObject::Polygon::Polygon(int side) {
    float theta = 0.0f;
    if (side > 2) theta = (2.0f * M_PI) / (float)side;
    //  Triangle by default if side is lesser or equal than 2
    else theta = (2.0f * M_PI) / 3.0f;
    this->vertices = new Queue<SDL_FPoint>();

    // Default starting point: A(0;2)
    SDL_FPoint A = {0.0f, 50.0f};
    this->vertices->push(A);
    for (int i = 0; i < side; i++) {
        // The center of the cirlce is the point O(0;0)
        SDL_FPoint center = {0.0f, 0.0f};
        SDL_FPoint rotated = this->getRotatedPoint(this->vertices->getTail()->getValue(), center, theta);
        this->vertices->push(rotated);
    }

    this->I.x = 0.0f;
    this->I.y = 0.0f;

    this->color.r = 255;
    this->color.g = 255;
    this->color.b = 0;
    this->color.a = 255;
}

SDL_FPoint GameObject::Polygon::getRotatedPoint(SDL_FPoint point, SDL_FPoint center, float theta) {
    SDL_FPoint rotated = {0.0f, 0.0f};
    rotated.x = cos(theta) * (point.x - center.x) - sin(theta) * (point.y - center.y) + center.x;
    rotated.y = cos(theta) * (point.y - center.y) + sin(theta) * (point.x - center.x) + center.y;
    return rotated;
}

void GameObject::Polygon::draw(SDL_Renderer* renderer) {
    if (!this->vertices->isEmpty()) {
        SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp->getNext() != NULL) {
            SDL_FPoint from = tmp->getValue();
            SDL_FPoint to = tmp->getNext()->getValue();
            SDL_RenderDrawLineF(renderer, from.x, from.y, to.x, to.y);
            tmp = tmp->getNext();
        }
    }
}

void GameObject::Polygon::translateX(float x) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {tmp->getValue().x + x, tmp->getValue().y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
        // Translate the center on X axis
        this->I.x += x;
    }
}

void GameObject::Polygon::translateY(float y) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {tmp->getValue().x, tmp->getValue().y + y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
        // Translate the center on Y axis
        this->I.y += y;
    }
}

void GameObject::Polygon::translate(float x, float y) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {tmp->getValue().x + x, tmp->getValue().y + y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
        // Translate the center on both the X axis and Y axis
        this->I.x += x;
        this->I.y += y;
    }
}

void GameObject::Polygon::rotate(float theta) {
    if (!this->vertices->isEmpty()) {
        Tools::preciseF(&theta, DIGITS);
        theta = Tools::radian(theta);
        Tools::preciseF(&theta, DIGITS);
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = Tools::getImageByRotation(tmp->getValue(), this->I, theta);
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
    }
}

void GameObject::Polygon::scaleX(float k) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {(k * (tmp->getValue().x - this->I.x)) + this->I.x, tmp->getValue().y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
    }
}

void GameObject::Polygon::scaleY(float k) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {tmp->getValue().x, (k * (tmp->getValue().y - this->I.y)) + this->I.y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
    }
}

void GameObject::Polygon::scale(float k) {
    if (!this->vertices->isEmpty()) {
        Node<SDL_FPoint>* tmp = this->vertices->getHead();
        while (tmp != NULL) {
            SDL_FPoint newPoint = {(k * (tmp->getValue().x - this->I.x)) + this->I.x, (k * (tmp->getValue().y - this->I.y)) + this->I.y};
            tmp->setValue(newPoint);
            tmp = tmp->getNext();
        }
    }
}