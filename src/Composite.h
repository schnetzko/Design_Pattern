//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include <list>
#include <string>

using namespace std;

class Component{
	public:
		virtual ~Component() = 0;
		virtual void traverse() = 0;
};

class Leaf: public Component{
	private:
		string name;

	public:
		Leaf(string name);

		~Leaf();

		void traverse();
};

class Composite : public Component {
	private:
		list<Component*> container;
		string name;

	public:
		Composite(string name);

		~Composite();

		void add(Component* component);

		void remove(Component* component);

		void traverse();

		void addLeavesWithIndendation(const int numberOfLeaves, const int numberOfIndentation, const string commonLeafName);
};


