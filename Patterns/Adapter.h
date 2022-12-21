#pragma once
#include <iostream>
#include <string>
#include <algorithm>


class Target
{
public:
	virtual ~Target() = default;
	virtual std::string Request() const
	{
		return "TARGET::REQUEST::Calling of target operation";
	}
};

class Adaptee
{
public:
	std::string specificExtensionRequest() const
	{
		return "dohtem ssalc ngierof a gnillac";
	}
};

class Adapter : public Target
{
	Adaptee* adaptee;
public:
	Adapter(Adaptee* _adaptee) : adaptee(_adaptee) {}
	std::string Request() const override
	{
		std::string to_reverse = adaptee->specificExtensionRequest();
		std::reverse(to_reverse.begin(), to_reverse.end());
		return "ADAPTER::TRANSLATED_REQUEST::" + to_reverse;
	}
};

void ClientCode(Target* requestManager)
{
	std::cout << requestManager->Request() << std::endl;
}