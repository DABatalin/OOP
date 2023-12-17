#include "npc.h"
#include "outlaw.h"
#include "werewolf.h"
#include "bear.h"
#include "serialization.h"
#include "text_observer.h"
#include "file_observer.h"

#include <algorithm>

using namespace std;

// print to screen
std::ostream &operator<<(std::ostream &os, const vector_NPC &array) {
    for (auto ptr : array)
        ptr->print();
    return os;
}

vector_NPC fight(const vector_NPC &array, size_t distance) {
    vector_NPC dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {\
                bool success = defender->accept(attacker);
                // если это разные чуваки и расстояние позволяет то начинаем битву

                if (success) {
                    dead_list.push_back(defender);
                    std::cout << "Есть убийство - защитник и аткаующий:" << std::endl;
                    defender->print();
                    attacker->print();
                }
            }

    return dead_list;
}

int main()
{
    vector_NPC array; // нпс
    Factory factory;
    shared_ptr<IFightObserver> tobserver = make_shared<TextObserver>();
    shared_ptr<IFightObserver> fobserver = make_shared<FileObserver>();
    vector<shared_ptr<IFightObserver>> observers{tobserver, fobserver};
    // Гененрируем начальное распределение монстров
    std::cout << "Генерирую" << std::endl;
    srand(40);
    for (size_t i = 0; i < 10; ++i)
        array.push_back(factory.factory(NpcType(std::rand() % 3), std::rand() % 100, std::rand() % 100, observers));
    
    // сериалищация
    std::cout << "Сохраняю" << std::endl;
    save(array, "../npc.txt");

    // десериализация
    std::cout << "Загружаю" << std::endl;
    array = load("../npc.txt");

    std::cout << "Генерация:" << std::endl << array << std::endl;

    std::cout << "Начинаем бои" << std::endl << std::endl;
    int i = 0;
    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10) {
        // distance - радиус удара
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase( find(array.begin(), array.end(), d) );
        
        std::cout << "Текущий статус битвы: " << std::endl
                  << "Дистанция: " << distance << std::endl
                  << "Убито: " << dead_list.size() << std::endl
                  << std::endl;
    }

    std::cout << "Выжившие:" << std::endl << array;
    return 0;
}