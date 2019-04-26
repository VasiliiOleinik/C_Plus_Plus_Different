// HelloPtr.cpp:
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using std::cin;
using std::cout;
using std::setw;

int rnd(int a, int b);
double rnd(double a, double b);

void init();

// Indicators * output parameters in C language
void Swap(int *a, int *b);
void Swap(double *a, double *b);

void Example01();
void Example02();

// Declare a function to pass an array
// 					array 			size
// type NameF (..., type * name, int n, ...);
void Fill(double *x, int n, double a = -12., double b = 23.);
void Fill(int *x, int n, int a = -12, int b = 23);
void Show(double *x, int n, char *t = "������ double x:\n");
void Show(int *x, int n, char *t = "������ int:\n");

int Max(int *x, int n);
void Sort(int *x, int n);

double Summa(double *x, int n);
int Summa(int *x, int n);

int _tmain(int argc, _TCHAR *argv[])
{
	init(); // preparation of the application for work

	Example01();
	Example02();
	cout << "\n\n-----------------------------------------------------------\n\n";

	// One-dimensional dynamic arrays:
	int n;
	double *x; // pointer to dynamic array

	cout << "\nArray size? ";
	cin >> n;

	// Create dynamic array (memory allocation)
	// nameUn = new Type [size];
	x = new double[n];

	// when called, only the name of the array
	Fill(x, n);
	Show(x, n);

	double s = Summa(x, n);
	cout << "\nSum of array elements x: " << s << "\n";
	// release of memory - if necessary or at the end of the program
	// delete [] username;
	delete[] x;
	x = 0; // for programmer, memory free indicator
		// if (x == 0) x = new double [n];
		// Fill (x, n);

	// not freeing memory - memory leak - HEAVY ERROR

	cout << "\ nSize of the array int?";
	cin >> n;

	int *y = new int[n];
	Fill(y, n);
	Show(y, n, "\nArray y (int)\n");

	int ss = Summa(y, n);
	cout << "\ nA sum of the elements of the array y:" << ss << "\ n";
	ss = max(y, n);
	cout << "Maximum array element:" << ss << "\ n";
	Sort(y, n);
	Show(y, n, "\ nSorted array y (int) \ n");

	delete[] y;

	// scalar dynamic variable
	// memory allocation
	// name = new type;
	// name = new type (value)
	x = new double;
	y = new int(234);

	*x = 12.6;
	cout << *x << "\t" << *y << "\n";

	// scalar dynamic variable
	// Freeing memory
	// delete name;
	// delete name1, name2, ..., nameN
	delete x, y;

	return 0;
} // _tmain

// Returns a random number of type int with a range of values from a to b
int rnd(int a, int b)
{
	return (a + rand() % (b - a + 1));
} // rnd

// Returns a random number of type double with a range of values from a to b
double rnd(double a, double b)
{
	return (a + (b - a) * rand() / (RAND_MAX + 1));
} // rnd

void Swap(int *a, int *b)
{
	// std::swap(a, b);
	int t = *a; // indirect addressing * a
	*a = *b;
	*b = t;
} // Swap

// An example of how not to code
void Swap(double *a, double *b)
{
	// std::swap(*a, *b);
	double *t = new double;
	*t = *a;
	*a = *b;
	*b = *t;
	delete t;
} // Swap

void init()
{
	SetConsoleOutputCP(1251);
	srand(GetTickCount());
} // init

void Example01()
{
	int x, y;
	x = rnd(-14, 45);
	y = rnd(-14, 45);
	cout << "\n\nx\ty\n";
	cout << x << "\t" << y << "\n";

	// !!!! Pointer to x - address x, ...
	Swap(&x, &y);
	cout << x << "\t" << y << "\n";
} // Example01

void Example02()
{
	double xx, yy;
	xx = rnd(-14., 45.);
	yy = rnd(-14., 45.);
	cout << "\n\nxx\tyy\n";
	cout << xx << "\t" << yy << "\n";

	// !!!! Pointer to xx - address xx, ...
	Swap(&xx, &yy);
	cout << xx << "\t" << yy << "\n";
} // Example02

//-----------------------------------------------------------------------
// An example of how not to code
void Fill(double *x, int n, double a, double b)
{
	int *i = new int;
	for (*i = 0; *i < n; (*i)++)
		x[*i] = rnd(a, b);
	delete i;
} // Fill

void Fill(int *x, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		x[i] = rnd(a, b);
} // Fill

void Show(double *x, int n, char *t)
{
	const int M = 7; // Number of elements per line
	cout << t;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << setw(10) << x[i];
		if ((i + 1) % M == 0)
			cout << "\n";
	} // for i
	if (n % M)
		cout << "\n";
} // Show

void Show(int *x, int n, char *t)
{
	const int M = 7; // Number of elements per line
	cout << t;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << setw(10) << x[i];
		if ((i + 1) % M == 0)
			cout << "\n";
	} // for i
	if (n % M)
		cout << "\n";
} // Show

double Summa(double *x, int n)
{
	double s;
	int i;

	s = 0.;
	for (i = 0; i < n; i++)
	{
		s += x[i];
	} // for i

	return s;
} // Summa

int Summa(int *x, int n)
{
	int s;
	int i;

	s = 0;
	for (i = 0; i < n; i++)
	{
		s += x[i];
		// s += *(x + i);
	} // for i

	return s;
} // Summa

int Max(int *x, int n)
{
	int i, imax;
	imax = 0;
	for (i = 1; i < n; i++)
		if (x[i] > x[imax])
			imax = i;
	return i;
} // Max

void Sort(int *x, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (x[j] > x[j + 1])
				std::swap(x[j], x[j + 1]);
		} // for j
	}	 // for i
} // Sort