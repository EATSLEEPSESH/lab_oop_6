#ifndef NPCFACTORY_H
#define NPCFACTORY_H

#include <memory>
#include "NPC/NPC.h"

class NPCFactory {
public:
    virtual ~NPCFactory() = default;
    virtual std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) = 0;
};

class ConcreteNPCFactory : public NPCFactory {
public:
    std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) override;
};

#endif // NPCFACTORY_H
