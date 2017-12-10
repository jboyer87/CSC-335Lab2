#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <exception>

// Implement the Stack and Queue interfaces with a unique class that is derived from 
// class LinkedDeque (Code Fragment 5.21).

namespace P5dot10 {
	// Code fragment 3.22
	typedef std::string Element; // list element type
	class DNode { // doubly linked list node
	private:
		Element elem; // node element value
		DNode* prev; // previous node in list
		DNode* next; // next node in list
		friend class DLinkedList; // allow DLinkedList access
	};

	// Code fragment 3.23
	class DLinkedList { // doubly linked list
	public:
		DLinkedList(); // constructor
		~DLinkedList(); // destructor
		bool empty() const; // is list empty?
		const Element& front() const; // get front element
		const Element& back() const; // get back element
		void addFront(const Element& e); // add to front of list
		void addBack(const Element& e); // add to back of list
		void removeFront(); // remove from front
		void removeBack(); // remove from back
	private: // local type definitions
		DNode* header; // list sentinels
		DNode* trailer;
	protected: // local utilities
		void add(DNode* v, const Element& e); // insert new node before v
		void remove(DNode* v); // remove node v
	};

	// Code fragment 5.21
	typedef std::string Element; // deque element type
	class LinkedDeque { // deque as doubly linked list
	public:
		LinkedDeque(); // constructor
		int size() const; // number of items in the deque
		bool empty() const; // is the deque empty?
		const Element& front() const; // the first element
		const Element& back() const; // the last element
		void insertFront(const Element& e); // insert new first element
		void insertBack(const Element& e); // insert new last element
		void removeFront(); // remove first element
		void removeBack(); // remove last element
	private: // member data
		DLinkedList D; // linked list of elements
		int n; // number of elements
	};

	// My custom objects below
	typedef std::string ElementType;
	class LinkedDequeStack
	{
	public:
		LinkedDequeStack() : LinkedDequeObject () { };
		int size() const;
		bool empty() const;
		const ElementType& top() const;
		void push(const ElementType& element);
		void pop();

	private:
		LinkedDeque LinkedDequeObject;
	};

	typedef std::string ElementType;
	class LinkedDequeQueue
	{
	public:
		LinkedDequeQueue();
		int size() const;
		bool empty() const;
		const ElementType& front() const;
		void enqueue(const ElementType& element);
		void dequeue();

	private:
		LinkedDeque LinkedDequeObject;
	};

	void run();
}