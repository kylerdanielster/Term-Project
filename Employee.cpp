#include "Employee.h"
#include <memory>
#include <iomanip>

using namespace std;

// Get Functions //

string Employee :: getName() const
{return name;}


string Employee :: getSsn() const
{return ssn;}

// Set Functions //

void Employee :: setSsn(string sNo)
{ssn = sNo;}

void Employee :: setName(string eName)
{name = eName;}

// Operator Overload //

bool Employee :: operator > ( Employee &right)
{
    string a, b;
    unsigned length;

    a = right.getName();
    b = getName();

	if (a.length() > b.length())
	{
		length = b.length();
	}

	for (unsigned count1 = 0; count1 <= length; count1++)
	{
		if (tolower(a[count1]) > tolower(b[count1]))
		{
			return true;
		}
	}

	return false;
}

bool Employee :: operator < ( Employee &right)
{
    string a, b;
    unsigned length;

    a = right.getName();
    b = getName();

	if (a.length() > b.length())
	{
		length = b.length();
	}

	for (unsigned count1 = 0; count1 <= length; count1++)
	{
		if (tolower(a[count1]) < tolower(b[count1]))
		{
			return true;
		}
	}

	return false;
}

bool Employee :: operator = ( Employee &right)
{
    string a, b;
    unsigned length;

    a = right.getName();
    b = getName();

	if (a.length() > b.length())
	{
		length = b.length();
	}

	for (unsigned count1 = 0; count1 <= length; count1++)
	{
		if (tolower(a[count1]) == tolower(b[count1]))
		{
			return true;
		}
	}

	return false;
}

bool Employee :: operator == ( Employee &right)
{
    string a, b;
    unsigned length;

    a = right.getName();
    b = getName();

	if (a.length() > b.length())
	{
		length = b.length();
	}

	for (unsigned count1 = 0; count1 <= length; count1++)
	{
		if (tolower(a[count1]) == tolower(b[count1]))
		{
			return true;
		}
	}

	return false;
}

// List Functions //

void Employee::addBankAccount(double b, int d, int w)
{
	BankAccount* ptr = new BankAccount(b,d,w);
	accounts.push_front(ptr);
}

void Employee::printAccountInfo()
{	
	list<BankAccount *> ::iterator iter;
	int count = 1;

	for (iter = accounts.begin(); iter != accounts.end(); iter++)
	{	
		cout << "Account # " << count << " Information: " << endl;
		cout << "Balance: $" << showpoint << fixed << setprecision(2) << (*iter)->getBalance() << endl;
		cout << "Number of Deposits: " << (*iter)->getDeposits() << endl;
		cout << "Number of Withdraws: " << (*iter)->getWithdraws() << endl;
		cout << "Account Type: " << (*iter)->type() << endl << endl;

		count++;
	}
}