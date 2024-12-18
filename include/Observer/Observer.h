#ifndef OBSERVER_H
#define OBSERVER_H

#include "../NPC/NPC.h"

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const NPC& npc1, const NPC& npc2) = 0;
};

#endif // OBSERVER_H
