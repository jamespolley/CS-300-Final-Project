#include "Calculator.h"
#include "DataInput.h"
#include "Report.h"
#include <iostream>


using namespace std;

int main() {
	DataInput input;

	// Get input from user
	input.header();
	input.setInitialAmount();
	input.setMonthlyDeposit();
	input.setInterestRate();
	input.setNumYears();

	// Create Calculator and Report instances
	Calculator calc = Calculator(input);
	Report report = Report(calc);

	// Generate report WITHOUT additional monthly deposits
	report.header(false);
	report.body(false);

	// Generate report WITH additional monthly deposits
	report.header(true);
	report.body(true);

	return 1;
}