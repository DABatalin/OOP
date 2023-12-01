#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <memory>

namespace lab5_ns {
	template <class T, class U>
	class Queue
	{
	private:
		T *_data;
		size_t _capacity;
		size_t _size;
		size_t _front;
		size_t _rear;
		U _allocator;

	public:
		template <class I, class F>
		class QueueIterator {
		private:
			const Queue<I, F>& queue;
			size_t index;

		public:
			using difference_type = int;
			using value_type = I;
			using reference =I&;
			using pointer = I*;
			using iterator_category = std::forward_iterator_tag;

			QueueIterator(const Queue<I, F>& q, size_t i) : queue(q), index(i) {}

			// Операторы сравнения
			bool operator==(const QueueIterator& other) const {
				return &queue == &other.queue && index == other.index;
			}

			bool operator!=(const QueueIterator& other) const {
				return !(*this == other);
			}

			// Операторы для перемещения итератора вперед
			QueueIterator& operator++() {
				index = (index + 1) % queue._capacity;
				return *this;
			}

			QueueIterator operator++(int) {
				QueueIterator tmp = *this;
				++(*this);
				return tmp;
			}

			// Оператор разыменования
			reference operator*() const {
				return queue._data[index];
			}

			pointer operator->() const {
				return &queue._data[index];
			}
		};
		
		using value_type = T;
		Queue(size_t capacity);
		~Queue();
		using iterator = QueueIterator<T, U>;
    	using const_iterator = QueueIterator<const T, U>;

		iterator begin() {
			return iterator(*this, _front);
		}

		iterator end() {
			return iterator(*this, (_rear == 0) ? _capacity - 1 : _rear - 1); // указывает за последний элемент
		}

		const_iterator begin() const {
			return const_iterator(*this, _front);
		}

		const_iterator end() const {
			return const_iterator(*this, (_rear == 0) ? _capacity - 1 : _rear - 1);
		}

		void push(const T &element);
		void pop();
		T front() const;
		T back() const;
		bool empty() const;
		size_t size() const;

		Queue<T, U>& operator=(const Queue<T, U> &other);
	};

	template <class T, class U>
	Queue<T, U>::Queue(size_t capacity) : _capacity(capacity), _size(0), _front(0), _rear(0)
	{
		_data = _allocator.allocate(capacity);
	}

	template <class T, class U>
	Queue<T, U>::~Queue()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			_allocator.destroy(_data + i);
		}

		_allocator.deallocate(_data, _capacity);
	}

	template <class T, class U>
	void Queue<T, U>::push(const T &element)
	{
		if (_size == _capacity)
		{
			throw std::overflow_error("Queue is full");
		}

		_allocator.construct(_data + _rear, element);
		_rear = (_rear + 1) % _capacity;
		_size++;
	}

	template <class T, class U>
	void Queue<T, U>::pop()
	{
		if (_size == 0)
		{
			throw std::underflow_error("Queue is empty");
		}

		_allocator.destroy(_data + _front);
		_front = (_front + 1) % _capacity;
		_size--;
	}

	template <class T, class U>
	T Queue<T, U>::front() const
	{
		if (_size == 0)
		{
			throw std::underflow_error("Queue is empty");
		}

		return _data[_front];
	}

	template <class T, class U>
	T Queue<T, U>::back() const
	{
		if (_size == 0)
		{
			throw std::underflow_error("Queue is empty");
		}

		// Поскольку _rear указывает на следующую позицию после последнего элемента,
		// нужно вернуть элемент, находящийся перед _rear в круговом буфере.
		size_t back_index = (_rear == 0) ? _capacity - 1 : _rear - 1;

		return _data[back_index];
	}

	template <class T, class U>
	bool Queue<T, U>::empty() const
	{
		return _size == 0;
	}

	template <class T, class U>
	size_t Queue<T, U>::size() const
	{
		return _size;
	}
	
	template <class T, class U>
	Queue<T, U>& Queue<T, U>::operator=(const Queue<T, U> &other) 
	{
		_data = other._data;
		_capacity = other._capacity;
		_size = other._size;
		_front = other._front;
		_rear = other._rear;
		_allocator = other._allocator;
		return *this;
	}
}
#endif