#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <map>

#include "allocator.h"


using map_type_with_allocator =
	std::map<int, int, std::less<int>, lab5_ns::Allocator<std::pair<const int, int>>>;


namespace lab5_ns {
	template <int N>
	int factorial()
	{
		return N * factorial<N - 1>();
	}
	template <>
	int factorial<0>()
	{
		return 1;
	}

	template <int N>
	void fill_map(map_type_with_allocator &map)
	{
		map.insert(std::pair<int, int>(N, factorial<N>()));
		fill_map<N - 1>(map);
	}
	template <>
	void fill_map<0>(map_type_with_allocator &map)
	{
		map.insert(std::pair<int, int>(0, factorial<0>()));
	}
}

#endif