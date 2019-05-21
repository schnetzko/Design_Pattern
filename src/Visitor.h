#include "Composite.h";

using namespace std;

class Visitor {
	public:
		virtual ~Visitor() = 0;
		virtual void visit(Composite *) = 0;
		virtual void visit(Leaf *) = 0;
};
