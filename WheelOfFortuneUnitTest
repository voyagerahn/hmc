#include "pch.h"
#include "../Project5/wheel.cpp"

TEST(Wheel, input1)
{
	vector<string> strs = { "BUILDLEV","EATREALROBOT" };
	string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";
	int expected = 6500;

	Wheel* app = new Wheel();
	int actual = app->getTotalPrice(strs, userdata);
	EXPECT_EQ(expected, actual);
}

TEST(Wheel, input2)
{
	vector<string> strs = { "ABS","ABS","AAAAAKBA" };
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";
	int expected = 9500;

	Wheel* app = new Wheel();
	int actual = app->getTotalPrice(strs, userdata);
	EXPECT_EQ(expected, actual);
}

TEST(Wheel, input3)
{
	vector<string> strs = { "AJS","VOYAGER","NASA" };
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";
	int expected = 4800;

	Wheel* app = new Wheel();
	int actual = app->getTotalPrice(strs, userdata);
	EXPECT_EQ(expected, actual);
}

TEST(Wheel, input4)
{
	vector<string> strs = { "TSLA","APPL","SPACEX)" };
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";
	int expected = 3600;

	Wheel* app = new Wheel();
	int actual = app->getTotalPrice(strs, userdata);
	EXPECT_EQ(expected, actual);
}

