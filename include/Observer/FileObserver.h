#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "Observer.h"
#include <fstream>

class FileObserver : public Observer {
public:
    FileObserver(const std::string& filename);
    void update(const NPC& npc1, const NPC& npc2) override;
private:
    std::ofstream logfile;
};

#endif // FILEOBSERVER_H
