#include <iostream>
#include <list>
#include <string>

using namespace std;

class Component{
	public:
		virtual void traverse() = 0;
};

class Leaf: public Component{
	private:
		string name;

	public:
		Leaf(string name) {
			cout << "Leaf constructor called for object with name " << name << "\n";
			this->name = name;
		};

		~Leaf() {
			cout << "Leaf destructor called for object with name " << name << "\n";
		}

		void traverse(){
			cout << "Leaf::traverse() called\n" << this->name << "\n";
		}
};

class Composite : public Component {
	private:
		list<Component*> container;
		string name;

	public:
		Composite(string name){
			cout << "Composite constructor called for object with name " << name << "\n";
			this->name = name;
		};

		~Composite(){
			cout << "Composite destructor called with object name " << name << "\n";
			for (auto iterator = container.begin(); iterator != container.end(); iterator++)
				delete (Component*)(*iterator);
		}

		void add(Component* component){
			container.push_back(component);
		}

		void remove(Component* component){
			container.remove(component);
		}

		void traverse(){
			cout << "Composite::traverse() called\n" << this->name << "\n";
			for (auto iterator = container.begin(); iterator != container.end(); iterator++){
				((Component*)*iterator)->traverse();
			}
		}

		void addLeavesWithIndendation(const int numberOfLeaves, const int numberOfIndentation, const string commonLeafName) {
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
		}
};

int main(){
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

	delete rootDirectory;

	return 0;
}

