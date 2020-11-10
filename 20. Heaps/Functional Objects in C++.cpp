// Functor

#include <iostream>
using namespace std;

class Fun {
public:
	void operator()(string s) {
		cout << "Having fun with " << s << endl;
	}
};

int main() {

	Fun f; // Creates an object
	f("Manu"); // overloaded () operator ==> Seems like a function call

}
