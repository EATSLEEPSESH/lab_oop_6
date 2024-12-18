#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>

class Observer;
class Visitor;

class NPC {
public:
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual bool isDead() const = 0;
    virtual void setDead(bool dead) = 0;
protected:
    std::vector<Observer*> observers;
};

#endif // NPC_H
