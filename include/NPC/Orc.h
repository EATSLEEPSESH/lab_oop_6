#ifndef ORC_H
#define ORC_H

#include "NPC.h"

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y);
    std::string getType() const override;
    std::string getName() const override;
    int getX() const override;
    int getY() const override;
    bool isDead() const override;
    void setDead(bool dead) override;
private:
    std::string name;
    int x, y;
    bool dead = false;
};

#endif // ORC_H
