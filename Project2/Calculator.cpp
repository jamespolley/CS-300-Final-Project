#include "Calculator.h"

Calculator::Calculator() {
	//
}

Calculator::Calculator(DataInput input) {
	this->input = input;
	monthlyInterestRate = (input.getInterestRate()/100)/12;
}

void Calculator::advance(bool includeMonthlyDeposits) {
	double depositAmt;
	double runningTotalBalance = input.getInitialAmount();
	double runningTotalInterest = 0.0;

	if (currYear < 1) runningTotalBalance = input.getInitialAmount();
	else runningTotalBalance = currYearEndBalance;

	//openingAmt = runningTotalBalance;
	(includeMonthlyDeposits) ? depositAmt = input.getMonthlyDeposit() : depositAmt = 0.0;
	for (int i = 0; i < 12; i++) {
		// double openingAmt = runningTotalBalance;
		// double total = openingAmt + depositAmt;
		// double interest = total * monthlyInterest;
		double interest = (runningTotalBalance + depositAmt) * monthlyInterestRate;
		runningTotalBalance += (depositAmt + interest);
		runningTotalInterest += interest;
		// openingAmt = runningTotalBalance;
	}
	currYearEndBalance = runningTotalBalance;
	currYearEndEarnedInterest = runningTotalInterest;
	currYear++;
}

void Calculator::reset() {
	int currYear = 0;
	double currYearEndBalance = 0;
	double currYearEndEarnedInterest = 0;
}

int Calculator::getNumYears() { return input.getNumYears(); }

double Calculator::getCurrYearEndBalance() { return currYearEndBalance; }

double Calculator::getCurrYearEndEarnedInterest() { return currYearEndEarnedInterest; }
