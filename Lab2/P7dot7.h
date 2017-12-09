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
		const void addChild(const FamilyMember &child);
		const std::string getName();
		const int getNumberOfChildren();
		const std::list<FamilyMember> getChildren();
	private:
		std::list<FamilyMember> m_children;
		std::string m_name;
	};

	class Tree {
	public:
		Tree();
		~Tree();
		void addFamilyMember(const FamilyMember &familyMember);
		const void displayFamilyTree();

	private:
		std::list<FamilyMember> m_familyMembers;
		int m_numberOfFamilyMembers;
		friend class FamilyMember;
	};

	void createCustomTree();
	void run();
}