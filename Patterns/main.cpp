#include <iostream>
#include "Command.h"

using namespace std;

int main(int argc, char* argv[])
{
	Invoker* invoker = new Invoker();
	invoker->SetOnStart(new SimpleCommand("Print ESC"));
	Receiver* receiver = new Receiver;
	invoker->SetOnFinish(new ComplexCommand(receiver, "Clear database", "Send bit in processor"));
	invoker->TransmitCommand();

	delete receiver;
	delete invoker;

	return 0;
}