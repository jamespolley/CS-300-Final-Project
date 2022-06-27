#include "Report.h"

Report::Report(Calculator calc) {
	calculator = calc;
}

void Report::header(bool includeMonthlyDeposits=false) {
	string withOrWithout;
	if (includeMonthlyDeposits) withOrWithout = "With";
	else withOrWithout = "Without";
	cout << "\nBalance and Interest " << withOrWithout << " Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << " Year     Year End Balance     Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
}

void Report::body(bool includeMonthlyDeposits){
	cout << fixed;
	for (int currYear = 1; currYear <= calculator.getNumYears(); currYear++) {
		calculator.advance(includeMonthlyDeposits);
		year(currYear);
		yearEndBalance(calculator.getCurrYearEndBalance());
		yearEndEarnedInterest(calculator.getCurrYearEndEarnedInterest());
	}
	calculator.reset();
}

void Report::year(int currYear) {
	cout.width(5);
	cout << currYear;
}

void Report::yearEndBalance(double currYearEndBalance) {
	
	cout.width(21);
	cout << formatInDollars(currYearEndBalance);
}

void Report::yearEndEarnedInterest(double currYearEndEarnedInterest) {
	cout.width(29);
	cout << formatInDollars(currYearEndEarnedInterest) << endl;
}

string Report::formatInDollars(double amt) {
	int intVal = int((amt * 100) + 0.5);
	string dollars = to_string(intVal / 100);
	int centsInt = intVal % 100;
	string cents = (centsInt < 10) ? ('0' + to_string(centsInt)) : to_string(centsInt);
	return ('$' + dollars + '.' + cents);
}
