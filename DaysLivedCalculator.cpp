
//Days Lived Calculator -- finds out how many days have you lived to this day

#include <iostream>
using namespace std;

//isLeapYear prototype
int isLeapYear(int);

//LeapYears prototype
int LeapYears();

//DaysLived prototypes
long DaysLived (int, int);
long DaysLived2(int, int);
int  DaysLived0(short, short, short, short, int, int);

//AjustDays prototype
int AjustDays(int, short, short, short);

//some global variables
unsigned short dayB, monthB, dayT, monthT;
unsigned int yearB, yearT;
unsigned int age;
unsigned int monthsLived;

// main function 
int main()
{
	cout << "  Welcome to the \"years-to-days-Calculator\"!!!!!!" << endl << endl
		<< "  please enter your date of birth:" << endl
		<< "  (enter the information following the example: day month year --> DD MM AAAA)" << endl;

	cin >> dayB >> monthB >> yearB;

	cout << "\n  Now please enter the current date following the previous form:" << endl;
	cin >> dayT >> monthT >> yearT;

	cout << "\n  Calculating some stuff... please wait a moment..." << endl;

	age = yearT - yearB;
	if (age == 0)
	{
		monthsLived = monthT - monthB;
		cout << " \n   You are " << monthsLived << " months old." << endl << "  And you lived "
			<< DaysLived0(monthB, dayB, monthT, dayT, yearB, yearT) << " days!\n  Congratulations!"
			<< endl << endl;
		return 0;
	}
	else
	{
		monthsLived = age * 12;

		cout << "  \n You are " << age << " years old." << endl
			<< "  And you lived " << DaysLived(monthB, dayB) << " days so far! " << "Which is equal to "
			<< monthsLived << " months!" << endl << "  Congratulations!" << endl
			<< endl << endl;
	}
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
	long daysLived3 = 365 * age + LeapYears();
	daysLived += daysLived3;
	return daysLived;
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

	daysLived2 += AjustDays(yearT, monthT, dayT, dayB);

	return daysLived2;
	}
	return daysLived2;
}
//DaysLived0 defenition -- if subject has less than 1 year this function is called instead of the others
int DaysLived0(short k, short y, short w, short z, int r, int t)
{
	short x = k;
	long daysLived = 0;
	switch (x)
	{
	case 1:
		if(x == w)
		{
			daysLived += (z - y);
			return daysLived;
		}
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 2:
		if (isLeapYear(yearB) == 4)
		{
			daysLived += 29;
		}
		else
		{
			daysLived += 28;
		}
		x++;
		if (x == w)
		{
			break;
		}
	case 3:
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 4:
		daysLived += 30;
		x++;
		if (x == w)
		{
			break;
		}
	case 5:
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 6:
		daysLived += 30;
		x++;
		if (x == w)
		{
			break;
		}
	case 7:
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 8:
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 9:
		daysLived += 30;
		x++;
		if (x == w)
		{
			break;
		}
	case 10:
		daysLived += 31;
		x++;
		if (x == w)
		{
			break;
		}
	case 11:
		daysLived += 30;
		x++;
		if (x == w)
		{
			break;
		}
	case 12:
		daysLived += 31;
		break;
	}
	daysLived += AjustDays(r, k, y, z);
	daysLived += AjustDays(t, w, z, y);

	return daysLived;
}

//AjustDays prototype -- does the final ajusts on the days you lived
int AjustDays(int w,short x,short y, short t)
{
	int ajustDays = 0;
	if (y == t)
	{
		return ajustDays;
	}
	if (x == 2)
	{
		if (isLeapYear(w) == 4)
		{
			ajustDays += (29 - y);
		}
		else
		{
			ajustDays += (28 - y);
		}
	}

	if (x == 4 || x == 6 || x == 9 || x == 11)
	{
		ajustDays += (31 - y);
	}
	else
	{
		ajustDays += (30 - y);
	}
	return ajustDays;
}