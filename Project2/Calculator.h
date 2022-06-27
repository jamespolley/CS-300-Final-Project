#pragma once
#include "DataInput.h"
#include <vector>
using namespace std;

class Calculator {
	public:
		Calculator();
		Calculator(DataInput input);
		void advance(bool includeMonthlyDeposits);
		void reset();
		int getNumYears();
		double getCurrYearEndBalance();
		double getCurrYearEndEarnedInterest();
		

	private:
		DataInput input;
		double monthlyInterestRate = 0.0;
		int currYear = 0;
		double currYearEndBalance = 0.0;
		double currYearEndEarnedInterest = 0.0;
		/*
		double initialAmount;
		double monthlyDeposit;
		double annualInterest;
		int numYears;
		vector<double> balancesNoDeposits;
		vector<double> interestNoDeposits;
		vector<double> balancesWithDeposits;
		vector<double> interestWithDeposits;
		*/
};