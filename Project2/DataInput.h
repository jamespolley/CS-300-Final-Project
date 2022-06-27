#pragma once
#include <iostream>

class DataInput {
	public:
		// DataInput();
		void header();
		void setInitialAmount();
		void setMonthlyDeposit();
		void setInterestRate();
		void setNumYears();
		double getInitialAmount();
		double getMonthlyDeposit();
		double getInterestRate();
		int getNumYears();

	private:
		double initialAmount;
		double monthlyDeposit;
		double interestRate;
		int numYears;

};