#include "bear.h"
#include "outlaw.h"
#include "werewolf.h"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}

bool Bear::accept(const std::shared_ptr<NPC> &attacker) {
    if (isDead)
        return false;
    
    bool success = attacker->fight(*this);
    attacker->fight_notify(shared_from_this(), success);
    if (success)
        death();
    return success;
}
bool Bear::fight(const Outlaw &defender) const {
    return false;
};
bool Bear::fight(const Werewolf &defender) const {
    return true;
};
bool Bear::fight(const Bear &defender) const {
    return false;
};
int Bear::getDistanceFight() const {
    return distance_fight;
}

int Bear::getDistanceMove() const {
    return distance_move;
}

void Bear::print() {
    print(std::cout);
}
void Bear::print(std::ostream &os) {
    os << *this;
}
void Bear::save(std::ostream &os) {
    os << BearType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Bear &bear)
{
    os << Bear::name << " " << *static_cast<NPC*>(&bear) << std::endl;
    return os;
}