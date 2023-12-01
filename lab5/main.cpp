#include <iostream>
#include <memory>
#include <map>
#include <utility>
#include <queue>

#include "allocator.h"
#include "queue.h"
#include "functions.h"


struct SomeStruct
{
    char buffer[1024];
};


int main(int argc, char **argv)
{

    std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>> my_map;
    lab5_ns::fill_map<10>(my_map);

    lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue(11);
    
    for(const auto& [k,v]: my_map)
        queue.push(v);
    
    std::cout << "End: " << *queue.end() << std::endl;

    for (int i = 0; i < 11; i++) {
        std::cout << i << " " << queue.front() << std::endl;
        queue.pop();
    }

    // lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue2(11);
    // lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue3(5);

    // queue2.push(10);
    // queue2.push(11);
    // queue2.push(12);

    // queue3.push(0);
    // queue3.push(1);
    // queue3.push(2);
    // queue3.push(3);

    // queue2 = queue3;

    // queue2.pop();
    // for (int i = 0; i < 3; i++) {
    //     std::cout << i << " " << queue2.front() << std::endl;
    //     queue2.pop();
    // }

    // for (int i = 0; i < 4; i++) {
    //     std::cout << i << " " << queue3.front() << std::endl;
    //     queue3.pop();
    // }


    return 0;
}
