#pragma once
#include <string>
#include <iostream>



class CreditCard {
public:
	CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0);

	std::string getNumber() const { return number; }
	std::string getName() const { return name; }
	double getBalance() const { return balance; }
	int getLimit() const { return limit; }


private:
	std::string number;
	std::string name;
	int limit;
	double balance;




};
