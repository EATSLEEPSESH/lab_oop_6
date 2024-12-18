#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H
#include <memory>
#include "../NPC/NPC.h"

class BattleVisitor {
public:
    void startBattle(std::vector<std::unique_ptr<NPC>>& npcs, int range);
private:
    void fight(std::vector<std::unique_ptr<NPC>>& npcs, NPC& npc1, NPC& npc2);
    bool inRange(NPC& npc1, NPC& npc2, int range);
};

#endif // BATTLEVISITOR_H