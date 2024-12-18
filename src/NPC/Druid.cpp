#include "../include/NPC/Druid.h"

Druid::Druid(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string Druid::getType() const {
    return "Druid";
}

std::string Druid::getName() const {
    return name;
}

int Druid::getX() const {
    return x;
}

int Druid::getY() const {
    return y;
}

bool Druid::isDead() const {
    return dead;
}

void Druid::setDead(bool dead) {
    this->dead = dead;
}
