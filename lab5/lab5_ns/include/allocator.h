#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <memory>
#include <utility>
#include <vector>


#define MAX_COUNT 50000
namespace lab5_ns {
	template <class T>
	class Allocator
	{
	private:
		std::vector<T> _used_blocks{MAX_COUNT};
		std::vector<void*> _free_blocks{MAX_COUNT};
		uint64_t _free_count;

	public:
		using value_type = T;
		using pointer = T *;
		using const_pointer = const T *;
		using size_type = std::size_t;

		Allocator();
		~Allocator();

		template <class U>
		struct rebind
		{
			using other = Allocator<U>;
		};

		T *allocate(size_t n);
		void deallocate(T *pointer, size_t n);

		template <typename U, typename... Args>
		void construct(U *p, Args &&...args)
		{
			new (p) U(std::forward<Args>(args)...);
		}

		void destroy(pointer p);
	};
	
	template <class T>
	Allocator<T>::Allocator()
	{
		for (uint64_t i = 0; i < MAX_COUNT; i++)
			_free_blocks[i] = &_used_blocks[i];
		_free_count = MAX_COUNT;
#ifdef DEBUG
		std::cout << "allocator: memory init" << std::endl;
#endif
	}

	template <class T>
	Allocator<T>::~Allocator()
	{
#ifdef DEBUG
		if (_free_count < max_count)
			std::cout << "allocator: Memory leak?" << std::endl;
		else
			std::cout << "allocator: Memory freed" << std::endl;
#endif
	}


	template <class T>
	T *Allocator<T>::allocate(size_t n)
	{
		T *result = nullptr;
		// проверяем есть ли свободные блоки
		if (_free_count > 0)
		{
			// если свободные блоки есть, то мы выделяем один свободный блок
			// и делаем его занятым, то есть убираем из списка свободных
			// возвращаем указатель на объект памяти
			_free_count -= n;
			result = (T*)_free_blocks[_free_count];
#ifdef DEBUG
			std::cout << "allocator: Allocate " << (MAX_COUNT - _free_count) << " of " << MAX_COUNT << " Address:" << result << std::endl;
#endif
		}
		else
		{
			std::cout << "allocator: No memory exception :-)" << std::endl;
		}
		return result;
	}

	template <class T>
	void Allocator<T>::deallocate(T *pointer, size_t n)
	{
#ifdef DEBUG
		std::cout << "allocator: Deallocate block " << std::endl;
#endif
		_free_blocks[_free_count] = pointer;
		_free_count += n;
	}

	
	template <class T>
	void Allocator<T>::destroy(pointer p)
	{
		p->~T();
	}

	template <class T, class U>
	constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) 
	{
		return true;
	}

	template <typename T, typename U, size_t BLOCK_COUNT>
	constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)  
	{
		return false;
	}
}

#endif