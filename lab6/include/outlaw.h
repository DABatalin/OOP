#pragma once

#include "npc.h"

class Outlaw : public NPC {
private:
    const static inline std::string name = "outlaw";

public:
    Outlaw(int x, int y);

    bool accept(const std::shared_ptr<NPC> &attacker) override;
    virtual bool fight(const Outlaw &defender) const override;
    virtual bool fight(const Werewolf &defender) const override;
    virtual bool fight(const Bear &defender) const override;

    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    friend std::ostream &operator<<(std::ostream &os, Outlaw &outlaw);
};