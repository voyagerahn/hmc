#pragma once

#include <vector>
#include "Movie.cpp"
#include "Rental.cpp"
#define interface struct
using std::string;
using std::vector;

interface Genre {
	virtual double getPrice(int rentalDays) = 0;
	virtual int getPoint(int rentalDays) = 0;
};

class Regular : public Genre {
public:
	double getPrice(int rentalDays) override {
		double thisPrice = 2;
		if (rentalDays > 2)
			thisPrice += (rentalDays - 2) * 1.5;
		return thisPrice;
	}

	int getPoint(int rentalDays) override {
		return 1;
	}
};

class Childrens : public Genre {
public:
	double getPrice(int rentalDays) override {
		double thisPrice = 1.5;
		if (rentalDays > 3)
			thisPrice += (rentalDays - 3) * 1.5;
		return thisPrice;
	}

	int getPoint(int rentalDays) override {
		return 1;
	}
};

class NewRelease : public Genre {
public:
	double getPrice(int rentalDays) override {
		double thisPrice = 0;
		thisPrice += rentalDays * 3;
		return thisPrice;
	}

	int getPoint(int rentalDays) override {
		if (rentalDays > 1) {
			return 2;
		}
		return 1;
	}
};

class Factory {
	//Singleton pattern
private:
	static Factory* myInstance = nullptr;
	Factory() = default;

public:
	static Factory *getInstance() {
		if (myInstance == nullptr) myInstance = new Factory();
		return myInstance;
	}

	Genre* getGenre(Rental videoInfo) {
		Genre* genre = nullptr;
		int genreValue = videoInfo.getMovie().getPriceCode();
		if (genreValue == Movie::REGULAR) return new Regular();
		if (genreValue == Movie::NEW_RELEASE) return new NewRelease();
		if (genreValue == Movie::CHILDRENS) return new Childrens();
		return nullptr;
	}
};

class Customer {
public:
    Customer(const string& name) : name(name) {}

    string statement()
    {
	    vector<double> priceList = getPriceList();
	    double totalPrice = getTotalPrice(priceList);
	    int totalCardPoint = getTotalCardPoint();

	    return getBill(totalPrice, totalCardPoint, priceList);
    }

	void addRental(Rental arg)
	{
		rentals.push_back(arg);
	}

	string getName() {
		return name;
	}

private:

    double getTotalPrice(vector<double> priceList) {
        double result = 0;
        for (double price : priceList) {
            result += price;
        }
        return result;
    }

    int getTotalCardPoint() {
		int result = 0;
		for (Rental videoInfo : rentals) {
			Genre* genre = Factory::getInstance()->getGenre(videoInfo);
			result += genre->getPoint(videoInfo.getDaysRented());
		}
		return result;
    }

    vector<double> getPriceList() {
        vector<double> result;
	    for (Rental videoInfo : rentals) {
			Genre *genre = Factory::getInstance()->getGenre(videoInfo);
		    result.push_back(genre->getPrice(videoInfo.getDaysRented()));
	    }
        return result;
    }

    string getBill(double totalPrice, int totalCardPoint, vector<double> priceList) {
        string result = "Rental Record for " + getName() + "\n";

	    int i = 0;
	    for (Rental videoInfo : rentals) {
		    double thisPrice = priceList[i];

			result += "\t" + videoInfo.getMovie().getTitle() + "\t";
	    	result += to_string_with_short_precision(thisPrice) + "\n";
		    i++;
	    }
	    // add footer lines
	    result += "Amount owed is " + to_string_with_short_precision(totalPrice) + "\n";
	    result += "You earned " + std::to_string(totalCardPoint) + " frequent renter points";
        return result;
    }

    string to_string_with_short_precision(double tar) {
	    char buf[20] = { 0 };
	    sprintf_s(buf, sizeof(buf), "%.1f", tar);
	    return string(buf);
    }

    string name;
    vector<Rental> rentals;
};
