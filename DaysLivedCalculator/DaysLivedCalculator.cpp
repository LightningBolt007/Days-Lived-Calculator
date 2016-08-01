
//Days Lived Calculator -- Calculates How Many Days Have You Lived To This Day

#include <iostream>
using namespace std;

//isLeapYear prototype
int isLeapYear(int);

//LeapYears prototype
int LeapYears();

//DaysLived prototypes
long DaysLived(int, int);
long DaysLived2(int, int);

//some global variables
int dayB, monthB, yearB;
int dayT, monthT, yearT;
int age, age2;

// main function 
int main()
{
	cout << "  Welcome to the \"years-to-days-Calculator\"!!!!!!" << endl << endl
		<< "  please enter your date of birth:" << endl
		<< "  (enter the information following the example: day month year --> DD MM AAAA)" << endl;

	cin >> dayB >> monthB >> yearB;

	cout << "  \nNow please enter the current date following the previous form:" << endl;
	cin >> dayT >> monthT >> yearT;

	cout << "\n  Calculating some stuff... please wait a moment..." << endl;

	age = yearT - yearB;
	age2 = age;
	cout << "  \n You are " << age << " years old." << endl
		<< "  And you lived " << DaysLived(monthB, dayB) << " days so far! Congratulations!" << endl
		<< endl;

	return 0;
}

//isLeapYear defenition -- finds out if the year inputed is a leap year or not 
int isLeapYear(int x)
{
	int leapControl = 0;
	int year1st = 0;

	while (0 == 0)
	{
		leapControl++;
		year1st += leapControl;

		if (year1st == x)
		{
			break;
			return leapControl;
		}

		if (leapControl == 4)
		{
			leapControl = 0;
		}
	}
	return leapControl;
}

//LeapYears defenition -- discoves how many leap years are beetwen the birth year and the current year
int LeapYears()
{

	int howManyLY = 0;
	int leapControl = 0;

	if (isLeapYear(yearB) == 4)
	{
		howManyLY++;

		while (yearB <= yearT)
		{
			leapControl++;
			if (leapControl == 4)
			{
				leapControl = 0;
				howManyLY++;
				yearB++;
			}
		}
	}
	else {
		leapControl = isLeapYear(yearB);
		while (yearB <= yearT)
		{
			leapControl++;
			if (leapControl == 4)
			{
				leapControl = 0;
				howManyLY++;
				yearB++;
			}
		}
	}
	return howManyLY;
}

//DaysLived2 Defenition
long DaysLived2(int x, int y)
{
	long daysLived = 0;
	switch (x)
	{
	case 1:
		daysLived += 31;
	case 2:
		daysLived += 28;
	case 3:
		daysLived += 31;
	case 4:
		daysLived += 30;
	case 5:
		daysLived += 31;
	case 6:
		daysLived += 30;
	case 7:
		daysLived += 31;
	case 8:
		daysLived += 31;
	case 9:
		daysLived += 30;
	case 10:
		daysLived += 31;
	case 11:
		daysLived += 30;
	case 12:
		daysLived += 31;
		break;
	}

	if (age <= 1)
	{
		return daysLived;
	}
	else
	{
		age2 -= 2;
		long daysLived3 = 365 * age2 + LeapYears();
		daysLived += daysLived3;
		return daysLived;
	}
}
//daysLived defenition -- With the help of DaysLived2 finds out how many days have you lived so far almost without errors.
long DaysLived(int x, int y)
{
	long daysLived2;
	daysLived2 = DaysLived2(monthB, dayB);

	switch (x)
	{
	case 1:
		daysLived2 -= 31;
	case 2:
		if (isLeapYear(yearT) == 4)
		{
			daysLived2 -= 29;
		}
		else
		{
			daysLived2 -= 28;
		}
	case 3:
		daysLived2 -= 31;
	case 4:
		daysLived2 -= 30;
	case 5:
		daysLived2 -= 31;
	case 6:
		daysLived2 -= 30;
	case 7:
		daysLived2 -= 31;
	case 8:
		daysLived2 -= 31;
	case 9:
		daysLived2 -= 30;
	case 10:
		daysLived2 -= 31;
	case 11:
		daysLived2 -= 30;
	case 12:
		daysLived2 -= 31;
		break;

		if (monthT == 2)
		{
			if (isLeapYear(yearT) == 4)
			{
				daysLived2 += (29 - dayT);
			}
			else
			{
				daysLived2 += (28 - dayT);
			}
		}

		if (monthT == 4 || monthT == 6 || monthT == 9 || monthT == 11)
		{
			daysLived2 += (31 - dayT);
		}
		else
		{
			daysLived2 += (30 - dayT);
		}
		return daysLived2;
	}
	return daysLived2;
}
