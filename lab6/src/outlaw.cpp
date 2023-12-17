#include "outlaw.h"
#include "werewolf.h"
#include "bear.h"

Outlaw::Outlaw(int x, int y) : NPC(OutlawType, x, y) {}

bool Outlaw::accept(const std::shared_ptr<NPC> &attacker) { // be_written из примера
    if (isDeath) // если мертв разбойник
        return false;
    
    bool success = attacker->fight(*this); // решаем можно ли нам драться с таким npc
    if (success)
        death();
    return success;
}
bool Outlaw::fight(const Outlaw &defender) const {
    return false;
};
bool Outlaw::fight(const Werewolf &defender) const {
    return false;
};
bool Outlaw::fight(const Bear &defender) const {
    return true;
};

void Outlaw::print() {
    print(std::cout);
}
void Outlaw::print(std::ostream &os) {
    os << *this;
}
void Outlaw::save(std::ostream &os) {
    os << OutlawType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Outlaw &Outlaw)
{
    os << Outlaw::name << " " << *static_cast<NPC*>(&Outlaw) << std::endl;
    return os;
}