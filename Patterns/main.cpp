#include <iostream>
#include "Adapter.h"

using namespace std;

int main(int argc, char* argv[])
{
	Target* target = new Target();
	ClientCode(target);
	cout << "What a request looks like from an extension with an unsupported interface: ";
	Adaptee* adaptee = new Adaptee();
	cout << adaptee->specificExtensionRequest() << endl;
	cout << "Request from extension after translating: ";
	Target* adapter = new Adapter(adaptee);
	ClientCode(adapter);

	delete target;

	return 0;
}