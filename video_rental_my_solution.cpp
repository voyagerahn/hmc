#pragma once

#include <vector>
#include "Movie.cpp"
#include "Rental.cpp"

using std::string;
using std::vector;
class Customer {

public:
	double totalPrice = 0;
	int totalCardPoint = 0;

	Customer(const string& name) : name(name) {}

	double getTotalPrice(string& result)
	{
		double price = 0;
		for (Rental videoInfo : rentals) {
			double eachPrice = 0;

			//determine amounts for rental
			eachPrice += calculateRentalPrice(videoInfo);

			// totalCardPoint += getCardPoints(videoInfo);

			// show figures for this rental
			result += "\t" + videoInfo.getMovie().getTitle() + "\t" + to_string_with_short_precision(eachPrice) + "\n";
			price += eachPrice;
		}
		return price;
	}

	int getTotalPoints()
	{
		int cardpoints = 0;
		for (Rental videoInfo : rentals)
		{
			cardpoints += getCardPoints(videoInfo);

		}
		return cardpoints;
	}

	string getStatement()
	{
		string result = "Rental Record for " + name + "\n";

		totalPrice += getTotalPrice(result);
		totalCardPoint += getTotalPoints();

		result += "Amount owed is " + to_string_with_short_precision(totalPrice) + "\n";
		result += "You earned " + std::to_string(totalCardPoint) + " frequent renter points";

		return result;
	}

	string getName() {
		return name;
	}

	void addRental(Rental arg)
	{
		rentals.push_back(arg);
	}

	double calculateRentalPrice(Rental videoInfo)
	{
		double price = 0;
		switch (videoInfo.getMovie().getPriceCode())
		{
		case Movie::REGULAR:
			price += 2;
			if (videoInfo.getDaysRented() > 2)
				price += (videoInfo.getDaysRented() - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			price += videoInfo.getDaysRented() * 3;
			break;
		case Movie::CHILDRENS:
			price += 1.5;
			if (videoInfo.getDaysRented() > 3)
				price += (videoInfo.getDaysRented() - 3) * 1.5;
			break;
		}
		return price;
	}


	int getCardPoints(Rental videoInfo)
	{
		int points = 0;
		points++;
		// add bonus for a two day new release rental
		if (videoInfo.getMovie().getPriceCode() == Movie::NEW_RELEASE && videoInfo.getDaysRented() > 1) {
			points++;
		}
		return points;
	}

private:
	string name;
	vector<Rental> rentals;

	string to_string_with_short_precision(double tar)
	{
		char buf[20] = { 0 };
		sprintf_s(buf, sizeof(buf), "%.1f", tar);
		return string(buf);
	}
};
