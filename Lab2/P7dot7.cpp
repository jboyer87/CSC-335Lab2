#include "P7dot7.h"
#include <iostream>

namespace P7dot7 {
	FamilyMember::FamilyMember(std::string name)
	{
		m_name = name;
	}
	
	FamilyMember::~FamilyMember()
	{

	}

	const void FamilyMember::addChild(const FamilyMember &child)
	{
		this->m_children.push_front(child);
	}

	const std::string FamilyMember::getName()
	{
		return m_name;
	}

	const int FamilyMember::getNumberOfChildren()
	{
		return m_children.size();
	}

	const std::list<FamilyMember> FamilyMember::getChildren()
	{
		return m_children;
	}


	Tree::Tree()
	{
		// Start off with 0 family members in a family tree
		m_numberOfFamilyMembers = 0;
	}

	Tree::~Tree()
	{

	}

	void Tree::addFamilyMember(const FamilyMember &familyMember)
	{
		// Add the family member to the lst
		m_familyMembers.push_front(familyMember);
		
		// Increment the number of family members in the tree
		m_numberOfFamilyMembers++;
	}

	const void Tree::displayFamilyTree()
	{
		// For each family member, list them, and all of their children
		for (std::list<FamilyMember>::iterator familyIterator = m_familyMembers.begin(); familyIterator != m_familyMembers.end(); familyIterator++)
		{
			// Get the name and the number of children for this family member
			std::cout << familyIterator->getName() << " has " << familyIterator->getNumberOfChildren() << " child/children";
			
			// Check to see if they have children
			if (familyIterator->getNumberOfChildren() > 0)
			{
				// If they have children, get them and put them in a list
				std::list<FamilyMember> children = familyIterator->getChildren();

				std::cout << ": " << std::endl;

				// Iterate through each of the children in the list and output their name
				for (std::list<FamilyMember>::iterator childrenIterator = children.begin(); childrenIterator != children.end(); childrenIterator++)
				{
					std::cout << "\t" << childrenIterator->getName() << std::endl;
				}
			}

			std::cout << std::endl;
		}
	}

	void createCustomTree()
	{
		// Prompt the user for their own family
		std::cout << "Try your own family:" << std::endl;

		Tree customTree;

		std::string customTreeFamilyMember = "";

		// "done" is the sentinel value
		while (customTreeFamilyMember != "done")
		{
			// Prompt for a family member
			std::cout << "Enter a name, or \"done\" if finished: ";
			std::cin >> customTreeFamilyMember;

			// Only ask for children if we aren't done
			if (customTreeFamilyMember != "done")
			{
				// Create the family member
				FamilyMember familyToAdd = FamilyMember(customTreeFamilyMember);

				std::string customTreeChild = "";

				// Prompt for the child/children
				while (customTreeChild != "done")
				{
					std::cout << "Enter child's name, or \"done\" if finished (or no children): ";

					std::cin >> customTreeChild;

					// If it isn't the sentinel value
					if (customTreeChild != "done")
					{
						// Create the child
						FamilyMember childToAdd = FamilyMember(customTreeChild);

						// Add the child to the person's list of children
						familyToAdd.addChild(childToAdd);
					}
				}

				// Add to the tree
				customTree.addFamilyMember(familyToAdd);
			}
		}

		std::cout << std::endl << "Here is your family tree: " << std::endl;

		customTree.displayFamilyTree();
	}


	void run()
	{
		// Set up a new tree
		Tree familyTree = Tree();

		// Create a bunch of my family members
		FamilyMember me = FamilyMember("Jamie");
		FamilyMember wife = FamilyMember("Judy");
		FamilyMember mother = FamilyMember("Robin");
		FamilyMember father = FamilyMember("Terry");
		FamilyMember sister = FamilyMember("Brittany");
		FamilyMember brother = FamilyMember("Nicholas");
		FamilyMember halfBrother = FamilyMember("Michael");
		FamilyMember brotherInLaw = FamilyMember("Peter");
		FamilyMember niece = FamilyMember("Sydney");
		FamilyMember child1 = FamilyMember("Imaginary Child 1");
		FamilyMember child2 = FamilyMember("Imaginary Child 2");

		// Add the children to each of the family members
		me.addChild(child1);
		me.addChild(child2);

		wife.addChild(child1);
		wife.addChild(child2);

		mother.addChild(me);
		mother.addChild(sister);
		mother.addChild(brother);
		
		father.addChild(me);
		father.addChild(sister);
		father.addChild(brother);
		father.addChild(halfBrother);

		sister.addChild(niece);
		brotherInLaw.addChild(niece);

		// Add each of the family members to the tree
		familyTree.addFamilyMember(me);
		familyTree.addFamilyMember(wife);
		familyTree.addFamilyMember(mother);
		familyTree.addFamilyMember(father);
		familyTree.addFamilyMember(sister);
		familyTree.addFamilyMember(brother);
		familyTree.addFamilyMember(halfBrother);
		familyTree.addFamilyMember(brotherInLaw);
		familyTree.addFamilyMember(niece);
		familyTree.addFamilyMember(child1);
		familyTree.addFamilyMember(child2);

		// Display the family tree
		familyTree.displayFamilyTree();

		std::cout << std::endl;

		// Create a custom tree
		createCustomTree();
	}
}