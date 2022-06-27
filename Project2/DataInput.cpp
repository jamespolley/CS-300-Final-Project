#include "DataInput.h"


static void DataInput::header(){
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
}

static double DataInput::initialInvestmentAmount(){
	cout << "Initial Investment Amount:  ";
	return 2.0;
}

static void DataInput::monthlyDeposit(){
	cout << "Monthly Deposit:  ";
}

void DataInput::numberOfYears(){
	cout << "Number of Years:  ";
}

void DataInput::continuePrompt()
{
}

