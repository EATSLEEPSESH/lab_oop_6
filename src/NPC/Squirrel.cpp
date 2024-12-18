#include "../include/NPC/Squirrel.h"

Squirrel::Squirrel(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string Squirrel::getType() const {
    return "Squirrel";
}

std::string Squirrel::getName() const {
    return name;
}

int Squirrel::getX() const {
    return x;
}

int Squirrel::getY() const {
    return y;
}

bool Squirrel::isDead() const {
    return dead;
}

void Squirrel::setDead(bool dead) {
    this->dead = dead;
}
