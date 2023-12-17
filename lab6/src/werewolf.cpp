#include "outlaw.h"
#include "werewolf.h"
#include "bear.h"

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {}

bool Werewolf::accept(const std::shared_ptr<NPC> &attacker) {
    if (isDeath)
        return false;
    
    bool success = attacker->fight(*this);
    if (success)
        death();
    return success;
}
bool Werewolf::fight(const Outlaw &defender) const {
    return true;
};
bool Werewolf::fight(const Werewolf &defender) const {
    return false;
};
bool Werewolf::fight(const Bear &defender) const {
    return false;
};

void Werewolf::print() {
    print(std::cout);
}
void Werewolf::print(std::ostream &os) {
    os << *this;
}
void Werewolf::save(std::ostream &os) {
    os << WerewolfType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Werewolf &werewolf)
{
    os << Werewolf::name << " " << *static_cast<NPC*>(&werewolf) << std::endl;
    return os;
}