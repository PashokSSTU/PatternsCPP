#pragma once
#include <iostream>
#include <string>

class Window
{
public:
	virtual ~Window() {};
	virtual void show() = 0;
};

class Checkbox
{
public:
	virtual ~Checkbox() {}
	virtual void show() = 0;
};

class WinWindow : public Window
{
public:
	void show() { std::cout << "Windows window is showing" << std::endl; }
};

class WinCheckbox : public Checkbox
{
public:
	void show() { std::cout << "Windows checkbox is showing" << std::endl; }
};

class LinuxWindow : public Window
{
public:
	void show() { std::cout << "Linux window is showing" << std::endl; }
};

class LinuxCheckbox : public Checkbox
{
public:
	void show() { std::cout << "Linux checkbox is showing" << std::endl; }
};

class MacWindow : public Window
{
public:
	void show() { std::cout << "MacOS window is showing" << std::endl; }
};

class MacCheckbox : public Checkbox
{
public:
	void show() { std::cout << "MacOS checkbox is showing" << std::endl; }
};

class ElementCreator
{
public:
	virtual ~ElementCreator() {}
	virtual Window* createWindow() = 0;
	virtual Checkbox* createCheckbox() = 0;
};

class WinElementCreator : public ElementCreator
{
	Window* createWindow() { return new WinWindow(); }
	Checkbox* createCheckbox() { return new WinCheckbox(); }
};

class LinuxElementCreator : public ElementCreator
{
	Window* createWindow() { return new LinuxWindow(); }
	Checkbox* createCheckbox() { return new LinuxCheckbox(); }
};

class MacElementCreator : public ElementCreator
{
	Window* createWindow() { return new MacWindow(); }
	Checkbox* createCheckbox() { return new MacCheckbox(); }
};

//-----------------------------------//

enum TargetOS
{
	WINDOWS,
	LINUX,
	MAC_OS
};

class Application
{
	ElementCreator* m_factory;
	Window* m_window;
	Checkbox* m_checkbox;
public:
	Application(ElementCreator* factory) : m_factory(factory)
	{
		m_window = m_factory->createWindow();
		m_checkbox = m_factory->createCheckbox();

		m_window->show();
		m_checkbox->show();
	}

	~Application() { delete m_factory; delete m_window; delete m_checkbox; }
};

class ApplicationConfigure
{
	ElementCreator* factory;
public:
	ApplicationConfigure(const TargetOS os)
	{
		switch (os)
		{
		case WINDOWS:
			factory = new WinElementCreator();
			break;

		case LINUX:
			factory = new LinuxElementCreator();
			break;

		case MAC_OS:
			factory = new MacElementCreator();
			break;
		default:
			throw "Unsupporting OS!";
			break;
		}
	}

	ElementCreator* getElementCreator() { return factory; }
};