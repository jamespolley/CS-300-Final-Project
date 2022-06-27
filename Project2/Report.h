#pragma once
#include <string>
#include <iostream>
// #include <iomanip>
#include "Calculator.h"

using namespace std;

class Report {
	public:
		Report(Calculator calc);
		void header(bool includeMonthlyDeposits);
		void body(bool includeMonthlyDeposits);
		
	private:
		Calculator calculator;
		void year(int currYear);
		void yearEndBalance(double currYearEndBalance);
		void yearEndEarnedInterest(double currYearEndEarnedInterest);
		string formatInDollars(double amt);
};