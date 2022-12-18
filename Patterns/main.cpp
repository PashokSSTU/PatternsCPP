#include <iostream>
#include "Singleton.h" 

using namespace std;

int main(int argc, char* argv[])
{
	SingletonTest* handle = SingletonTest::getInstance();
	handle->print();

	return 0;
}