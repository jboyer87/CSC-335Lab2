#pragma once

#include <iostream>
#include <vector>
#include <iterator>

// Write a complete adapter class that implements the sequence ADT using an STL vector
// object.

namespace P6dot6 {
	typedef int Elem;
	//template <class T>
	class VectorSequence {
	public:
		typedef std::vector<int>::iterator Iterator;

		VectorSequence();
		~VectorSequence();

		int size() const;

		bool empty() const;

		Iterator begin();
		Iterator end();

		void insertFront(const Elem& element);
		void insertBack(const Elem& element);

		void insert(const Iterator& position, const Elem& element);

		void removeFront();
		void removeBack();

		void remove(const Iterator& position);

		Iterator atIndex(const int index);
		int indexOf(const Iterator& position);

	private:
		std::vector<int> m_SequenceVector;
		//std::vector<T> m_SequenceVector;
	};

	void run();
}