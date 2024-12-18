#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
#include "Factory/NPCFactory.h"
#include "Visitor/BattleVisitor.h"
#include "Observer/ConsoleObserver.h"
#include "Observer/FileObserver.h"

void saveToFile(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& npc : npcs) {
        file << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
    }
}

std::vector<std::unique_ptr<NPC>> loadFromFile(const std::string& filename, NPCFactory& factory) {
    std::vector<std::unique_ptr<NPC>> npcs;
    std::ifstream file(filename);
    std::string type, name;
    int x, y;
    while (file >> type >> name >> x >> y) {
        npcs.push_back(factory.createNPC(type, name, x, y));
    }
    return npcs;
}

void printNPCs(const std::vector<std::unique_ptr<NPC>>& npcs) {
    std::cout << "========================================" << std::endl;
    std::cout << "NPC List:" << std::endl;
    for (const auto& npc : npcs) {
        std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName()
                  << ", Position: (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

void printNPCStatistics(const std::vector<std::unique_ptr<NPC>>& npcs) {
    int orcCount = 0;
    int squirrelCount = 0;
    int druidCount = 0;

    for (const auto& npc : npcs) {
        if (npc->getType() == "Orc") {
            orcCount++;
        } else if (npc->getType() == "Squirrel") {
            squirrelCount++;
        } else if (npc->getType() == "Druid") {
            druidCount++;
        }
    }

    std::cout << "========================================" << std::endl;
    std::cout << "NPC Statistics:" << std::endl;
    std::cout << "Orks: " << orcCount << std::endl;
    std::cout << "Squirrels: " << squirrelCount << std::endl;
    std::cout << "Druids: " << druidCount << std::endl;
    std::cout << "========================================" << std::endl;
}

void printAverageCoordinates(const std::vector<std::unique_ptr<NPC>>& npcs) {
    int totalX = 0, totalY = 0;
    int orcCount = 0, squirrelCount = 0, druidCount = 0;

    for (const auto& npc : npcs) {
        if (npc->getType() == "Orc") {
            totalX += npc->getX();
            totalY += npc->getY();
            orcCount++;
        } else if (npc->getType() == "Squirrel") {
            totalX += npc->getX();
            totalY += npc->getY();
            squirrelCount++;
        } else if (npc->getType() == "Druid") {
            totalX += npc->getX();
            totalY += npc->getY();
            druidCount++;
        }
    }

    std::cout << "========================================" << std::endl;
    std::cout << "Average Coordinates:" << std::endl;
    if (orcCount > 0) {
        std::cout << "Orks: (" << std::fixed << std::setprecision(2) << static_cast<double>(totalX) / orcCount
                  << ", " << static_cast<double>(totalY) / orcCount << ")" << std::endl;
    }
    if (squirrelCount > 0) {
        std::cout << "Squirrels: (" << std::fixed << std::setprecision(2) << static_cast<double>(totalX) / squirrelCount
                  << ", " << static_cast<double>(totalY) / squirrelCount << ")" << std::endl;
    }
    if (druidCount > 0) {
        std::cout << "Druids: (" << std::fixed << std::setprecision(2) << static_cast<double>(totalX) / druidCount
                  << ", " << static_cast<double>(totalY) / druidCount << ")" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

void printNPCsInRange(const std::vector<std::unique_ptr<NPC>>& npcs, int centerX, int centerY, int range) {
    std::cout << "========================================" << std::endl;
    std::cout << "NPCs in range (" << range << ") from (" << centerX << ", " << centerY << "):" << std::endl;
    for (const auto& npc : npcs) {
        int dx = npc->getX() - centerX;
        int dy = npc->getY() - centerY;
        if (std::sqrt(dx * dx + dy * dy) <= range) {
            std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName()
                      << ", Position: (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }
    std::cout << "========================================" << std::endl;
}

void printBattleStatistics(const std::vector<std::unique_ptr<NPC>>& npcs) {
    int orcVsDruid = 0;
    int druidVsSquirrel = 0;

    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (npcs[i]->getType() == "Orc" && npcs[j]->getType() == "Druid") {
                orcVsDruid++;
            } else if (npcs[i]->getType() == "Druid" && npcs[j]->getType() == "Squirrel") {
                druidVsSquirrel++;
            }
        }
    }

    std::cout << "========================================" << std::endl;
    std::cout << "Battle Statistics:" << std::endl;
    std::cout << "Orks vs Druids: " << orcVsDruid << std::endl;
    std::cout << "Druids vs Squirrels: " << druidVsSquirrel << std::endl;
    std::cout << "========================================" << std::endl;
}

void printDeadNPCs(const std::vector<std::unique_ptr<NPC>>& npcs) {
    std::cout << "========================================" << std::endl;
    std::cout << "Dead NPCs:" << std::endl;
    for (const auto& npc : npcs) {
        if (npc->isDead()) {
            std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName()
                      << ", Position: (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }
    std::cout << "========================================" << std::endl;
}

int main() {
    ConcreteNPCFactory factory;
    std::vector<std::unique_ptr<NPC>> npcs;

    // Создание NPC
    npcs.push_back(factory.createNPC("Orc", "Orc1", 100, 100));
    npcs.push_back(factory.createNPC("Squirrel", "Squirrel1", 200, 200));
    npcs.push_back(factory.createNPC("Druid", "Druid1", 300, 300));

    // Печать перечня объектов
    printNPCs(npcs);

    // Сохранение и загрузка объектов
    saveToFile(npcs, "npcs.txt");
    npcs = loadFromFile("npcs.txt", factory);

    // Боевой режим
    BattleVisitor battleVisitor;
    battleVisitor.startBattle(npcs, 150);

    // Дополнительные выводы
    printNPCStatistics(npcs);
    printAverageCoordinates(npcs);
    printNPCsInRange(npcs, 200, 200, 100);
    printBattleStatistics(npcs);

    return 0;
}
