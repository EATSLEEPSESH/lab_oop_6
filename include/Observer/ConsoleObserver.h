#ifndef CONSOLEOBSERVER_H
#define CONSOLEOBSERVER_H

#include "Observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void update(const NPC& npc1, const NPC& npc2) override;
};

#endif // CONSOLEOBSERVER_H
