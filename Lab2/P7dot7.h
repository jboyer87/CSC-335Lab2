#pragma once
#include <iostream>
#include <string>
#include <list>

// Write a program that can input and display a person's family tree.

namespace P7dot7 {
	class FamilyMember {
	public:
		FamilyMember(std::string name);
		~FamilyMember();

	private:
		std::list<FamilyMember> m_children;
	};

	class Tree {
	public:
		Tree();
		~Tree();
		void addFamilyMember(FamilyMember familyMember);
		void displayFamilyTree();

	private:
		std::list<FamilyMember> m_FamilyMembers;
		int m_numberOfFamilyMembers;
		friend class FamilyMember;
	};

	void run();
}