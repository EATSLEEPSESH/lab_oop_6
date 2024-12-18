#include "../include/Observer/FileObserver.h"

FileObserver::FileObserver(const std::string& filename) : logfile(filename, std::ios::app) {}

void FileObserver::update(const NPC& npc1, const NPC& npc2) {
    logfile << npc1.getName() << " killed " << npc2.getName() << std::endl;
}
