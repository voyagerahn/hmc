#include <iostream>
#define interface struct

using namespace std;

interface Socket {
	virtual void plugIn() = 0;
	virtual void unPlug() = 0;
}

class Samsang : public Socket
{
public:
	void plugIn() override
	{
		enable330V();
	}
	void unPlug() override
	{
		disable330V();
	}

	void enable330V()
	{
		cout << "WLWLR" << endl;
	}

	void disable330V()
	{
		cout << "Finish" << endl;
	}
};

class Dansang : public Socket
{
public:
	void plugIn() override
	{
		enable220V();
	}

	void unPlug() override
	{
		disable220V();
	}

	void enable220V()
	{
		cout << "WLWLR" << endl;
	}

	void disable220V()
	{
		cout << "Finish" << endl;
	}
};

class Factory
{
public:
	void* makeSocket(string name)
	{
		if (name == "dansang") return new Dansang();
		if (name == "samsang") return new Samsang();
		return nullptr;

	}
};

class House //단상, 삼상에 의존성 보이지 않도록 한다.
{
public:
	void tvOn(Socket* socket)
	{
		socket->plugIn();
		cout << "hi" << endl;
	}

	void tvOff(Socket* socket)
	{
		socket->unPlug();
		cout << "bye" << endl;
	}


};

int main()
{
	House* house = new House();
	Factory* fac = new Factory();
	//house->tvOn(mew Dansang());
	house->tvOn(((Socket*)fac->makeSocket("dansang")));


}
