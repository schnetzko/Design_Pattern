//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include "Composite.h"

#include <iostream>

Component::~Component() {};

Leaf::Leaf(string name) {
	cout << "Leaf constructor called for object with name " << name << "\n";
	this->name = name;
};

Leaf::~Leaf() {
	cout << "Leaf destructor called for object with name " << name << "\n";
};

void Leaf::traverse(){
	cout << "Leaf::traverse() called\n" << this->name << "\n";
};


Composite::Composite(string name){
	cout << "Composite constructor called for object with name " << name << "\n";
	this->name = name;
};

Composite::~Composite(){
	cout << "Composite destructor called with object name " << name << "\n";
	for (auto iterator = container.begin(); iterator != container.end(); iterator++)
		delete (Component*)(*iterator);
};

void Composite::add(Component* component){
	container.push_back(component);
};

void Composite::remove(Component* component){
	container.remove(component);
};

void Composite::traverse(){
	cout << "Composite::traverse() called\n" << this->name << "\n";
	for (auto iterator = container.begin(); iterator != container.end(); iterator++){
		((Component*)*iterator)->traverse();
	}
};

void Composite::addLeavesWithIndendation(const int numberOfLeaves, const int numberOfIndentation, const string commonLeafName) {
	const string indendation = "\t";
	string indendation_prefix = "";
	for (int i = 0; i < numberOfIndentation; i++){
		indendation_prefix.append(indendation);
	}

	for (int i = 0; i < numberOfLeaves; i++) {
		string name = indendation_prefix;
		name.append(commonLeafName);
		name.append(to_string(i));
		add(new Leaf(name));
	}
};
