#include <iostream>

#include "P5dot10.h"

namespace P5dot10 {
	

	bool DLinkedList::empty() const // is list empty?
	{
		return (header->next == trailer);
	}
	const Elem& DLinkedList::front() const // get front element
	{
		return header->next->elem;
	}
	const Elem& DLinkedList::back() const // get back element
	{
		return trailer->prev->elem;
	}

	void run() {
	
	}
}