#include <iostream>
#include "AbstractFactory.h"

using namespace std;

int main(int argc, char* argv[])
{

	ApplicationConfigure appConfig(MAC_OS);
	Application application(appConfig.getElementCreator());


	return 0;
}