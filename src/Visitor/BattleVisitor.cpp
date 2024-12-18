#include "Visitor/BattleVisitor.h"
#include "NPC/Orc.h"
#include "NPC/Squirrel.h"
#include "NPC/Druid.h"
#include <cmath>
#include <algorithm>

void BattleVisitor::startBattle(std::vector<std::unique_ptr<NPC>>& npcs, int range) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (inRange(*npcs[i], *npcs[j], range)) {
                fight(npcs, *npcs[i], *npcs[j]);
            }
        }
    }
}

void BattleVisitor::fight(std::vector<std::unique_ptr<NPC>>& npcs, NPC& npc1, NPC& npc2) {
    if (npc1.getType() == "Orc" && npc2.getType() == "Druid") {
        // Орк убивает Друида
        npc2.setDead(true);
    } else if (npc1.getType() == "Druid" && npc2.getType() == "Squirrel") {
        // Друид убивает Белку
        npc2.setDead(true);
    }
}

bool BattleVisitor::inRange(NPC& npc1, NPC& npc2, int range) {
    int dx = npc1.getX() - npc2.getX();
    int dy = npc1.getY() - npc2.getY();
    return std::sqrt(dx * dx + dy * dy) <= range;
}
