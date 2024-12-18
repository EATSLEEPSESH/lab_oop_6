#include <utility>

#include "../include/NPC/Orc.h"
#include "Observer/Observer.h"

Orc::Orc(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string Orc::getType() const {
    return "Orc";
}

std::string Orc::getName() const {
    return name;
}

int Orc::getX() const {
    return x;
}

int Orc::getY() const {
    return y;
}

bool Orc::isDead() const {
    return dead;
}

void Orc::setDead(bool dead) {
    this->dead = dead;
}

