//============================================================================
// Name        : Oberserver.cpp
// Author      : schnetzko
// Version     :
// Copyright   : Your copyright notice
// Description : Observer Pattern in C++
//============================================================================

#include <memory>
#include <vector>

using namespace std;

class AbstractObserver{
	public:
		virtual void update(const int oberserverID) = 0;
};

class ObserverA : public AbstractObserver {
	public:
		void update(const int newValue) override;
};

class ObserverB : public AbstractObserver {
	public:
		void update(const int newValue) override;
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

		void subscribe (const shared_ptr<AbstractObserver> observer) override;

		void unsubscribe(const shared_ptr<AbstractObserver> observer) override;

		void setId(const int id);

	private:
		void signalObservers() override;
};
