//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class AbstractObserver{
	public:
		virtual void update(const int oberserverID) = 0;
};

class ObserverA : public AbstractObserver {
	public:
		void update(const int newValue) override {
			cout << "ObserverA was informed about the new value " << newValue << ".\n";
		}
};

class ObserverB : public AbstractObserver {
	public:
		void update(const int newValue) override {
			cout << "ObserverB was informed about the new value " << newValue << ".\n";
		}
};

class AbstractSubject{
	public:
		virtual void subscribe(const shared_ptr<AbstractObserver> oberserver) = 0;
		virtual void unsubscribe(const shared_ptr<AbstractObserver> oberserver) = 0;

	private:
		virtual void signalObservers() = 0;
};

class Subject : public AbstractSubject{
	private:
		int anyMember;
		vector<shared_ptr<AbstractObserver>> observers;

	public:
		Subject() : anyMember (0){};

		void subscribe (const shared_ptr<AbstractObserver> observer) override {
			observers.push_back(observer);
		};

		void unsubscribe(const shared_ptr<AbstractObserver> observer) override {
			// http://www.cplusplus.com/reference/algorithm/find_if/
			auto pos = find_if(	observers.begin(),
								observers.end(),
							   [&](const shared_ptr<AbstractObserver> & oberserverElement) {
									return oberserverElement.get() == observer.get();
								}
						);
			if (pos != observers.end()) observers.erase(pos);
		};

		void setId(const int id){
			this->anyMember = id;
			signalObservers();
		}

	private:
		void signalObservers() override {
			for (auto& observer : observers){
				observer->update(anyMember);
			}
		};
};

//int main() {
//	shared_ptr<AbstractObserver> observerA(new ObserverA());
//	shared_ptr<AbstractObserver> observerB(new ObserverB());
//
//    Subject subject;
//	subject.subscribe(observerA);
//	subject.subscribe(observerB);
//	subject.setId(1);
//
//	cout << "\n";
//
//	subject.unsubscribe(observerA);
//	subject.setId(2);
//
//	cout << "\n";
//
//	subject.unsubscribe(observerB);
//	subject.setId(3);
//
//	return 0;
//}
