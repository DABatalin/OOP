#include <gtest/gtest.h>
#include <iostream>
#include <list>

#include "allocator.h"
#include "functions.h"
#include "queue.h"


TEST(functions, factorial) {
	size_t fact10 = lab5_ns::factorial<10>();
	size_t fact0 = lab5_ns::factorial<0>();
	size_t fact1 = lab5_ns::factorial<1>();

	ASSERT_EQ(fact10, 3628800);
	ASSERT_EQ(fact0, 1);
	ASSERT_EQ(fact1, 1);
}

TEST(functions, fill_map) {
	std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>> my_map;
    lab5_ns::fill_map<10>(my_map);

    lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue(11);
    
    for(const auto& [k,v]: my_map)
        queue.push(v);


    ASSERT_EQ(queue.front(), 1);
	queue.pop();
	int fact = 1;
    for (int i = 1; i < 11; i++) {
		fact = fact * i;
		ASSERT_EQ(queue.front(), fact);
        queue.pop();
    }
}

TEST(allocator, map_alloc) {
	std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>> my_map;
    lab5_ns::fill_map<10>(my_map);

    lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue(11);
    
    for(const auto& [k,v]: my_map)
        queue.push(v);


    ASSERT_EQ(queue.front(), 1);
	queue.pop();
	int fact = 1;
    for (int i = 1; i < 11; i++) {
		fact = fact * i;
		ASSERT_EQ(queue.front(), fact);
        queue.pop();
    }
}


TEST(queue, queue_with_alloc_size) {
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue2(11);
    queue2.push(10);
    queue2.push(11);
    queue2.push(12);
	ASSERT_EQ(queue2.size(), 3);
}


TEST(queue, queue_with_alloc_front) {
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue2(11);
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue3(11);
	
    queue2.push(10);
    queue2.push(11);
    queue2.push(12);
	
	ASSERT_EQ(queue2.front(), 10);
	EXPECT_THROW(queue3.front(), std::underflow_error);

}

TEST(queue, queue_with_alloc_back_and_pop) {
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue2(11);
    queue2.push(10);
    queue2.push(11);
    queue2.push(12);
	
	ASSERT_EQ(queue2.back(), 12);
	queue2.pop();
	ASSERT_EQ(queue2.back(), 12);
	queue2.pop();
	ASSERT_EQ(queue2.back(), 12);
	queue2.pop();
	EXPECT_THROW(queue2.back(), std::underflow_error);

}


struct SomeStruct
{
	char buffer[1024];
};

int test1()
{
	auto begin = std::chrono::high_resolution_clock::now();
	std::list<SomeStruct> my_list;
	for (int i = 0; i < 40000; i++)
		my_list.push_back(SomeStruct());
	for (int i = 0; i < 40000; i++)
		my_list.erase(my_list.begin());
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int test2()
{
	auto begin = std::chrono::high_resolution_clock::now();
	std::list<SomeStruct, lab5_ns::Allocator<SomeStruct>> my_list;
	for (int i = 0; i < 40000; i++)
		my_list.push_back(SomeStruct());
	for (int i = 0; i < 40000; i++)
		my_list.erase(my_list.begin());
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

TEST(allocator, list_check) {
	int test_1 = test1();
	int test_2 = test2();

	ASSERT_TRUE(test_1 > test_2);
}

TEST(iterator, begin) {
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue(11);
	std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>> my_map;
    lab5_ns::fill_map<10>(my_map);

	for(const auto& [k,v]: my_map)
        queue.push(v);
    
    ASSERT_EQ(*queue.begin(), 1);
	ASSERT_EQ(*++++queue.begin(), 2);
	ASSERT_EQ(*++++++queue.begin(), 6);
}

TEST(iterator, end) {
	lab5_ns::Queue<int, lab5_ns::Allocator<int>> queue(11);
	std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>> my_map;
    lab5_ns::fill_map<10>(my_map);

	for(const auto& [k,v]: my_map)
        queue.push(v);
    
    ASSERT_EQ(*queue.end(), 3628800);
	ASSERT_EQ(*++++queue.end(), 1);
	ASSERT_EQ(*++++++queue.end(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}