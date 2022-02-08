#include <SDL.h>
#include <Entity.h>

GameEngine::Entity::Entity(int x, int y, int w, int h) {
    // Set the transform properties
    this->transform.x = x;
    this->transform.y = y;
    this->transform.w = w;
    this->transform.h = h;

    // Set the color
    this->color.r = 255;
    this->color.g = 255;
    this->color.b = 255;
    this->color.a = 255;
}

void GameEngine::Entity::translateX(int x) { this->transform.x = x; }
void GameEngine::Entity::translateY(int y) { this->transform.y = y; }

void GameEngine::Entity::translate(int x, int y) {
    this->transform.x = x;
    this->transform.y = y;
}

void GameEngine::Entity::setColor(SDL_Color color) {
    this->color.r = color.r;
    this->color.g = color.g;
    this->color.b = color.b;
    this->color.a = color.a;
}

void GameEngine::Entity::setColor(int r, int g, int b, int a) {
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = a;
}

void GameEngine::Entity::setOpactity(int opacity) { this->color.a = opacity; }

int GameEngine::Entity::getX() { return this->transform.x; }
int GameEngine::Entity::getY() { return this->transform.y; }
int GameEngine::Entity::getWidth() { return this->transform.w; }
int GameEngine::Entity::getHeight() { return this->transform.h; }

SDL_Color GameEngine::Entity::getColor() { return this->color; }

void GameEngine::Entity::renderFill(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_RenderFillRect(renderer, &this->transform);
}

void GameEngine::Entity::renderStroke(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_RenderDrawRect(renderer, &this->transform);
}