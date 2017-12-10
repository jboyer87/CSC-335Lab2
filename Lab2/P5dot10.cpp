#include <iostream>

#include "P5dot10.h"

namespace P5dot10 {
	// Code fragment 3.24
	DLinkedList::DLinkedList() { // constructor
		header = new DNode; // create sentinels
		trailer = new DNode;
		header->next = trailer; // have them point to each other
		trailer->prev = header;
	}
	DLinkedList::~DLinkedList() { // destructor
		while (!empty()) removeFront(); // remove all but sentinels
		delete header; // remove the sentinels
		delete trailer;
	}

	// Code fragment 3.25
	bool DLinkedList::empty() const // is list empty?
	{
		return (header->next == trailer);
	}
	const Element& DLinkedList::front() const // get front element
	{
		return header->next->elem;
	}

	const Element& DLinkedList::back() const // get back element
	{
		return trailer->prev->elem;
	}

	// Code fragment 3.26
	void DLinkedList::add(DNode* v, const Element& e) {
		DNode* u = new DNode; u->elem = e; // create a new node for e
		u->next = v; // link u in between v
		u->prev = v->prev; // . . .and v->prev
		v->prev->next = v->prev = u;
	}
	void DLinkedList::addFront(const Element& e) // add to front of list
	{
		add(header->next, e);
	}
	void DLinkedList::addBack(const Element& e) // add to back of list
	{
		add(trailer, e);
	}

	// Code fragment 3.27
	void DLinkedList::remove(DNode* v) { // remove node v
		DNode* u = v->prev; // predecessor
		DNode* w = v->next; // successor
		u->next = w; // unlink v from list
		w->prev = u;
		delete v;
	}
	void DLinkedList::removeFront() // remove from font
	{
		remove(header->next);
	}
	void DLinkedList::removeBack() // remove from back
	{
		remove(trailer->prev);
	}

	// My implementations (missing from the book?)

	LinkedDeque::LinkedDeque()
	{
		// nothing to do here...
	}

	const Element& LinkedDeque::front() const
	{
		return D.front();
	}

	const Element& LinkedDeque::back() const
	{
		return D.back();
	}

	int LinkedDeque::size() const
	{
		return n;
	}

	bool LinkedDeque::empty() const
	{
		return D.empty();
	}

	// Code fragment 5.22
	void LinkedDeque::insertFront(const Element& e) {
		D.addFront(e);
		n++;
	} // insert new last element
	void LinkedDeque::insertBack(const Element& e) {
		D.addBack(e);
		n++;
	} // remove first element
	void LinkedDeque::removeFront() {
		D.removeFront();
		n--;
	} // remove last element
	void LinkedDeque::removeBack() {
		D.removeBack();
		n--;
	}

	// My custom object implementations for stack
	int LinkedDequeStack::size() const
	{
		return LinkedDequeObject.size();
	}

	bool LinkedDequeStack::empty() const
	{
		return LinkedDequeObject.empty();
	}

	const ElementType& LinkedDequeStack::top() const
	{
		return LinkedDequeObject.back();
	}

	void LinkedDequeStack::push(const ElementType& element)
	{
		LinkedDequeObject.insertBack(element);
	}

	void LinkedDequeStack::pop()
	{
		LinkedDequeObject.removeBack();
	}

	// My custom object implementations for queue
	LinkedDequeQueue::LinkedDequeQueue()
	{
		// nothing to do here...
	}

	int LinkedDequeQueue::size() const
	{
		return LinkedDequeObject.size();
	}

	bool LinkedDequeQueue::empty() const
	{
		return LinkedDequeObject.empty();
	}

	const ElementType& LinkedDequeQueue::front() const
	{
		return LinkedDequeObject.back();
	}

	void LinkedDequeQueue::enqueue(const ElementType& element)
	{
		LinkedDequeObject.insertBack(element);
	}

	void LinkedDequeQueue::dequeue()
	{
		LinkedDequeObject.removeFront();
	}

	void run() {
		std::cout << "Nothing to output here according to the project, just the implementations...";
	}
}