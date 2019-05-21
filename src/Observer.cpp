//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include "Observer.h"

#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

void ObserverA::update(const int newValue) {
	cout << "ObserverA was informed about the new value " << newValue << ".\n";
};

void ObserverB::update(const int newValue) {
	cout << "ObserverB was informed about the new value " << newValue << ".\n";
};

void Subject::subscribe (const shared_ptr<AbstractObserver> observer)  {
	observers.push_back(observer);
};

void Subject::unsubscribe(const shared_ptr<AbstractObserver> observer)  {
	// http://www.cplusplus.com/reference/algorithm/find_if/
	auto pos = find_if(	observers.begin(),
						observers.end(),
					   [&](const shared_ptr<AbstractObserver> & oberserverElement) {
							return oberserverElement.get() == observer.get();
						}
				);
	if (pos != observers.end()) observers.erase(pos);
};

void Subject::setId(const int id){
	this->anyMember = id;
	signalObservers();
}
void Subject::signalObservers(){
	for (auto& observer : observers){
		observer->update(anyMember);
	}
};
