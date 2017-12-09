#include "P6dot6.h"
#include <iostream>
#include <vector>

namespace P6dot6 {

	VectorSequence::VectorSequence()
	{
		// Nothing to do here...
	}

	VectorSequence::~VectorSequence()
	{
		// Nothing to do here...
	}

	int VectorSequence::size() const
	{
		return m_SequenceVector.size();
	}

	bool VectorSequence::empty() const
	{
		// Return the member vector's empty() function
		return m_SequenceVector.empty();
	}

	VectorSequence::Iterator VectorSequence::begin()
	{
		// Return the member vector's begin() function
		return m_SequenceVector.begin();
	}

	VectorSequence::Iterator VectorSequence::end()
	{
		// Return the member vector's end() function
		return m_SequenceVector.end();
	}

	void VectorSequence::insertFront(const Elem& element)
	{
		// Call the member vector's insert() function setting the position to the 
		// beginning
		m_SequenceVector.insert(this->begin(), element);
	}

	void VectorSequence::insertBack(const Elem& element)
	{
		// Call the member vector's insert() function setting the position to the end
		m_SequenceVector.insert(this->end(), element);

	}

	void VectorSequence::insert(const Iterator& position, const Elem& element)
	{
		// Call the member vector's insert() function passing the position parameter and 
		// the element parameter
		m_SequenceVector.insert(position, element);
	}

	void VectorSequence::removeFront()
	{
		// Instantiate an iterator at the beginning of the member vector
		Iterator position = m_SequenceVector.begin();
		// Erase the element at the position returned by the begin function
		m_SequenceVector.erase(position);
	}

	void VectorSequence::removeBack()
	{
		// Call pop_back() on the member vector
		m_SequenceVector.pop_back();
	}

	void VectorSequence::remove(const Iterator& position)
	{
		// Remove the element at the position specified of the member vector
		m_SequenceVector.erase(position);
	}

	VectorSequence::Iterator VectorSequence::atIndex(const int index)
	{
		Iterator position = m_SequenceVector.begin();

		for (int i = 0; i < index; i++)
		{
			position++;
		}

		return position;
	}

	int VectorSequence::indexOf(const Iterator& position)
	{
		int i = 0;

		for (Iterator iterator = m_SequenceVector.begin(); iterator < position; iterator++)
		{
			i++;
		}

		return i;
	}

	void run()
	{
		// Write some test functions to make sure it all works as expected


		// Instantiate a new VectorSequence to work with
		VectorSequence testSequence1;

		// Insert something at the beginning
		// 1
		testSequence1.insert(testSequence1.begin(), 1);

		// Insert something at the front
		// 0, 1
		testSequence1.insertFront(0);

		// Insert something at the back
		// 0, 1, 2
		testSequence1.insertBack(2);

		// See what is at the beginning
		// 0
		int beginning = testSequence1.indexOf(testSequence1.begin());
		
		// See what is at the end
		// 2
		int end = testSequence1.indexOf(testSequence1.end());

		// Test walking through with iterators
		std::vector<int>::iterator beginIterator = testSequence1.begin();

		std::vector<int>::iterator endIterator = testSequence1.end();
		
		for (int i = 0; beginIterator != endIterator; i++)
		{
			beginIterator++;
			std::cout << "At index " << i << std::endl;
		}

		// Check the size
		// 3
		std::cout << "Size is: " << testSequence1.size() << std::endl;

		// Empty the sequence and test the remove functions
		
		// Remove the back element
		testSequence1.removeBack();

		// Removes front
		testSequence1.removeFront();

		// Remove the element that the front points to now
		testSequence1.removeFront();

		// Check the size again
		std::cout << "Size is: " << testSequence1.size() << std::endl;

		if (testSequence1.empty())
		{
			std::cout << "It's empty now!" << std::endl;
		}
		else 
		{
			std::cout << "It's not empty, something went wrong!" << std::endl;
		}

	}
}