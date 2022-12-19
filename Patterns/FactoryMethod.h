#pragma once
#include <string>

class Product
{
public:
	virtual ~Product() {}
	virtual std::string Info() = 0;
};

class Creator
{
public:
	virtual ~Creator() {}
	virtual std::string Info() = 0;
	virtual Product* getInstance() = 0;
};

class ConcreteProduct1 : public Product
{
public:
	std::string Info() { return "We use \"ConcreteProduct1\""; }
};

class ConcreteProduct2 : public Product
{
public:
	std::string Info() { return "We use \"ConcreteProduct2\""; }
};

class CreatorProducts1 : public Creator
{
public:
	Product* getInstance() { return (new ConcreteProduct1()); }
	std::string Info() { return "Creator works with {ConcreteProduct1}"; }
};

class CreatorProducts2 : public Creator
{
public:
	Product* getInstance() { return (new ConcreteProduct2()); }
	std::string Info() { return "Creator works with {ConcreteProduct2}"; }
};

void Client(Creator* factory)
{
	std::cout << "Client::CreatorInfo::" << factory->Info() << std::endl;
}

void Client(Product* product)
{
	std::cout << "Client::ProductInfo::" << product->Info() << std::endl;
}