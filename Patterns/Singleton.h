#pragma once
#include <iostream>

class SingletonTest
{
	SingletonTest() {}

public:
	static SingletonTest* getInstance()
	{
		static SingletonTest instance;
		return &instance;
	}

	void print()
	{
		std::cout << "Singletom class created!" << std::endl;
	}
};