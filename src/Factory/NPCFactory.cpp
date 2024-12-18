#include "../include/Factory/NPCFactory.h"
#include "../include/NPC/Orc.h"
#include "../include/NPC/Squirrel.h"
#include "../include/NPC/Druid.h"

std::unique_ptr<NPC> ConcreteNPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") {
        return std::make_unique<Orc>(name, x, y);
    } else if (type == "Squirrel") {
        return std::make_unique<Squirrel>(name, x, y);
    } else if (type == "Druid") {
        return std::make_unique<Druid>(name, x, y);
    }
    return nullptr;
}
