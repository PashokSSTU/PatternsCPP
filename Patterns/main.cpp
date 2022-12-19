#include <iostream>
#include "FactoryMethod.h"

using namespace std;

int main(int argc, char* argv[])
{
	Creator* factory1 = new CreatorProducts1();
	Client(factory1);
	Product* product1 = factory1->getInstance();
	Client(product1);

	Creator* factory2 = new CreatorProducts2();
	Client(factory2);
	Product* product2 = factory2->getInstance();
	Client(product2);

	delete product1;
	delete product2;
	delete factory1;
	delete factory2;

	return 0;
}