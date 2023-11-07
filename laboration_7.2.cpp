#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Find_Largest_From_Min(int** a, const int rowCount, const int colCount);

int main() {
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 50;

	int colCount;
	cout << "colCount = "; cin >> colCount;

	int rowCount;
	cout << "rowCount = "; cin >> rowCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	int largest_from_min = Find_Largest_From_Min(a, rowCount, colCount);
	cout << "Largest From Min = " << largest_from_min << endl;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Find_Largest_From_Min(int** a, const int rowCount, const int colCount)
{
	int min, max;
	for (int j = 0; j < colCount; j += 2) 
	{
		min = a[0][j];
		for (int i = 1; i < rowCount; i++)
		{
			if (a[i][j] < min)
				min = a[i][j];
		}
		if (j == 0)
			max = min;
		if (min > max)
			max = min;
	}
	return max;
}
