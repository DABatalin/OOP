#include <fight_manager.h>

FightManager& FightManager::get() {
    static FightManager instance;
    return instance;
} // это реализация паттерна сингл тон, то есть у нас во всем проекте только один 
  // объект и в гете всегда возвращается только доин объект

void FightManager::add_event(FightEvent &&event) {
    std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
}

void FightManager::operator()() {
    while (true) {
        std::optional<FightEvent> event; // может содержать в себе вместо объекта нулл

        {
            std::lock_guard<std::shared_mutex> lock(mtx); // шейрд мютекс в местах где мы общую память читаем мы делаемй шейрд лок мы делаем обычный лок. ЛОк гард
            // этон надстройка над обычным локом которая при создании объекта мютекс лочит при уничтожении разлочивает
            if (!events.empty()) {
                event = events.back();
                events.pop();
            }
        }

        if (event) { 
            if (event->attacker->isAlive() && event->defender->isAlive()) {
                event->defender->accept(event->attacker);
            }
        }
    }
}

bool FightManager::isWork() {
    return events.size();
}