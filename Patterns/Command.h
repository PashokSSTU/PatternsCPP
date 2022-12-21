#pragma once
#include <string>
#include <iostream>

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() const = 0;
};

class SimpleCommand : public Command
{
	std::string a_;
public:
	SimpleCommand(const std::string a) : a_(a)
	{}

	void Execute() const override
	{
		std::cout << "SimpleCommand: Doing simple command: " << a_ << std::endl;
	}
};

class Receiver
{
public:
	void DoingCommand(const std::string a)
	{
		std::cout << "Receiver: Doing command: " << a << std::endl;
	}

	void DoingAnotherCommand(const std::string b)
	{
		std::cout << "Receiver: Also receiver is doing command: " << b << std::endl;
	}
};

class ComplexCommand : public Command
{
	Receiver* receiver;

	std::string a_;
	std::string b_;
public:
	ComplexCommand(Receiver* receiver_, std::string a, std::string b) : receiver(receiver_), a_(a), b_(b)
	{}

	void Execute() const override
	{
		receiver->DoingCommand(a_);
		receiver->DoingAnotherCommand(b_);
	}
};

class Invoker
{
	Command* on_start;
	Command* on_finish;
public:
	Invoker() : on_start(nullptr), on_finish(nullptr)
	{}

	~Invoker() { delete on_start; delete on_finish; }

	void SetOnStart(Command* on_start)
	{
		this->on_start = on_start;
	}

	void SetOnFinish(Command* on_finish)
	{
		this->on_finish = on_finish;
	}

	void TransmitCommand()
	{
		if (on_start)
		{
			on_start->Execute();
			on_start = nullptr;
		}

		if (on_finish)
		{
			on_finish->Execute();
			on_finish = nullptr;
		}
	}
};