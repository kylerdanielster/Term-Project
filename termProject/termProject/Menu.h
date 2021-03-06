#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <string.h>

#include "Exceptions.h"
#include "AddRemoveEmployee.h"
#include "InterfaceBasics.h"
#include "AddAccounts.h"

using namespace std;

// Main Menu //

unsigned menuOptions(Bank* bnk)
{	
	bankFace();

	int answer = 0;

	cout << "   What you want to do today?\n\n";

	cout << "   1- Add or Remove Customers" << endl;
	cout << "   2- See customers list - by name" << endl;
	cout << "   3- See customers list - by balance" << endl;
	cout << "   4- See customers list - last modifications" << endl;
	cout << "\n\n   Press 5 to exit the program" << endl;

	cout << "\n   Option: ";

	answer = whileValidation();

	switch (answer){
	case 1: addCustomer(bnk); break;
	case 2: bnk->sortByName(); printInfo(bnk); break;
	case 3: bnk->sortByBalance(); printInfo(bnk); break;
	case 4: printInfo(bnk); break;
	default: break;
	}

	return answer;
}

void mainMenu(Bank * bnk)
{
	unsigned exit = 0;

	do{
		exit = menuOptions(bnk);
	} while (exit < 5);

	exitProgram();
}
#endif