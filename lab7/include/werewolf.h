#pragma once
#include "npc.h"

class Werewolf : public NPC {
private:
    const static inline std::string name = "werewolf";
    const static inline int distance_move = 40;
    const static inline int distance_fight = 5;

public:
    Werewolf(int x, int y);

    // Драка
    bool accept(const std::shared_ptr<NPC> &attacker) override;
    virtual bool fight(const Outlaw &defender) const override;
    virtual bool fight(const Werewolf &defender) const override;
    virtual bool fight(const Bear &defender) const override;
    int getDistanceFight() const override;

    // Движение
    int getDistanceMove() const override;

    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    friend std::ostream &operator<<(std::ostream &os, Werewolf &werewolf);
};