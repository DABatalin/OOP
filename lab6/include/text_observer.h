#include <Ifight_observer.h>
#include <npc.h>

class TextObserver : public IFightObserver {
public:
    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};