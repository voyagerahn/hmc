# hmc

#include <iostream>
using namespace std;

class Phone {
public:
	virtual void call()
	{
		cout << "CALL..\n";
	}
};

class SmartPhone : public Phone {
public:
	void call()
	{
		cout << "SMART PHONE CALL...\n";
	}
	void internet()
	{
		cout << "INTERNET\n";
	}
};

class BrickPhone : public Phone {
public:
	void call()
	{
		cout << "BRICKBRCIK CALL...\n";
	}
	void internet()
	{
		cout << "INTERNET\n";
	}
};

void call(string name)
{
	if (name == "brick")
	{
		BrickPhone* p = new BrickPhone();
		p->call();
	}
	if (name == "smart")
	{
		SmartPhone* p = new SmartPhone();
		p->call();
	}
}

void call2(Phone* phone)
{
	phone->call();
}

Phone* makePhone(string name)
{
	if (name == "brick") return new BrickPhone();
	if (name == "smart") return new SmartPhone();
	return nullptr;
}

int main(int argc, char* argv[])
{
	//다형성을 이용한 구현 방법 1
	//Dependency Injection 
	//call("smart");
	call2(new SmartPhone());

	//다형성을 이용한 구현 방법 2
	//Factory
	//Phone* g = new SmartPhone();
	Phone* g = makePhone("brick");

	//1번 + 2번
	call2(makePhone("brick"));
}
