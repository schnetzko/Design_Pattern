//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include <iostream>
#include <memory>
#include <string>

#include "Composite.h"
#include "Observer.h"

using namespace std;

void playWithComposite() {
	cout << "::: playWithComposite()\n";
	cout << "--------------------------\n";

	Composite* rootDirectory = new Composite("downloads");
	Composite* subDirectory = new Composite("\tpictures");
	Composite* leafDirectory = new Composite("\t\tvideos");

	const string commonFileName = "file";

	rootDirectory->addLeavesWithIndendation(3, 0, commonFileName);
	subDirectory->addLeavesWithIndendation(2, 1, commonFileName);
	leafDirectory->addLeavesWithIndendation(4, 2, commonFileName);

	// build a directory tree
	rootDirectory->add(subDirectory);
	subDirectory->add(leafDirectory);
	rootDirectory->traverse();

	delete rootDirectory; //TODO: still noch correct handling as sub-destructors are not called.

	cout << "--------------------------\n";
}

void playWithObserver() {
	cout << "::: playWithObserver()\n";
	cout << "--------------------------\n";

	shared_ptr<AbstractObserver> observerA(new ObserverA());
	shared_ptr<AbstractObserver> observerB(new ObserverB());

	Subject subject;
	subject.subscribe(observerA);
	subject.subscribe(observerB);
	subject.setId(1);
	cout << "\n";

	subject.unsubscribe(observerA);
	subject.setId(2);
	cout << "\n";

	subject.unsubscribe(observerB);
	subject.setId(3);
	cout << "--------------------------\n";
}

void playWithVistor() {
	cout << "::: playWithObserver()\n";
	cout << "--------------------------\n";

	cout << "--------------------------\n";
}

int main(){
	playWithComposite();

	playWithObserver();

	playWithVistor();

	return 0;
}
