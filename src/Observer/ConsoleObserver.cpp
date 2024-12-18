#include "../include/Observer/ConsoleObserver.h"

void ConsoleObserver::update(const NPC& npc1, const NPC& npc2) {
    std::cout << npc1.getName() << " killed " << npc2.getName() << std::endl;
}
