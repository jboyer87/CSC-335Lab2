#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <exception>

// Implement the Stack and Queue interfaces with a unique class that is derived from 
// class LinkedDeque (Code Fragment 5.21).

namespace P5dot10 {
	typedef std::string Elem; // list element type
	class DNode { // doubly linked list node
	private:
		Elem elem; // node element value
		DNode* prev; // previous node in list
		DNode* next; // next node in list
		friend class DLinkedList; // allow DLinkedList access
	};

	class DLinkedList { // doubly linked list
	public:
		DLinkedList(); // constructor
		~DLinkedList(); // destructor
		bool empty() const; // is list empty?
		const Elem& front() const; // get front element
		const Elem& back() const; // get back element
		void addFront(const Elem& e); // add to front of list
		void addBack(const Elem& e); // add to back of list
		void removeFront(); // remove from front
		void removeBack(); // remove from back
	private: // local type definitions
		DNode* header; // list sentinels
		DNode* trailer;
	protected: // local utilities
		void add(DNode* v, const Elem& e); // insert new node before v
		void remove(DNode* v); // remove node v
	};

	typedef std::string Elem; // deque element type
	class LinkedDeque { // deque as doubly linked list
	public:
		LinkedDeque(); // constructor
		int size() const; // number of items in the deque
		bool empty() const; // is the deque empty?
		const Elem& front() const; // the first element
		const Elem& back() const; // the last element
		void insertFront(const Elem& e); // insert new first element
		void insertBack(const Elem& e); // insert new last element
		void removeFront(); // remove first element
		void removeBack(); // remove last element
	private: // member data
		DLinkedList D; // linked list of elements
		int n; // number of elements
	};

	void run();
}