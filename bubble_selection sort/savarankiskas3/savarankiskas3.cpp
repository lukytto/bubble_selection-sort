// savarankiskas3.cpp : Defines the entry point for the console application.
//Bubble and selection sort with file I/O

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
ofstream rezfile("rezultatai.txt");


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSortMax(int arr[], int n) {
	int temp;
	for (int c = 0; c < (n - 1); c++)
	{
		for (int d = 0; d < n - c - 1; d++)
		{
			if (arr[d] < arr[d + 1])
			{
				temp = arr[d];
				arr[d] = arr[d + 1];
				arr[d + 1] = temp;
			}
		}
	}

}

void bubbleSortMin(int arr[], int n) {
	int temp;
	for (int c = 0; c < (n - 1); c++)
	{
		for (int d = 0; d < n - c - 1; d++)
		{
			if (arr[d] > arr[d + 1])
			{
				temp = arr[d];
				arr[d] = arr[d + 1];
				arr[d + 1] = temp;
			}
		}
	}

}

void selectionSortMin(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}

void selectionSortMax(int arr[], int n)
{
	int i, j, max_idx;

	for (i = 0; i < n - 1; i++)
	{
		max_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] > arr[max_idx])
				max_idx = j;

		swap(&arr[max_idx], &arr[i]);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	for (int i = 0; i < size; ++i)
	{
		rezfile << arr[i] << " ";
	}
}
int main()
{
	int arr[50000];
	int n; 
	int t;
	
	ifstream listfile("prad_duom.txt");
	if (listfile.fail()) { cout << "error"; }
	listfile >> n;
	for (int i = 0; i < n; ++i)
	{
		listfile >> arr[i];
	}
	cout << "Pasirinkite algoritma ir kokia tvarka rusiuoti:" << endl << "1. Selection sort Min to Max" << endl << "2. Selection sort Max to Min"<<endl;
	cout <<"3. Bubble sort Min to Max" << endl << "4. Bubble sort Max to Min" << endl;
	cin >> t;
	
	if (t==1){ selectionSortMin(arr, n); }
	else if (t==2){ selectionSortMax(arr, n); }
	else if (t == 3) { bubbleSortMin(arr, n); }
	else if (t == 4) { bubbleSortMax(arr, n); }
	else { cout << "error"; }
	
	listfile.close();

	if (rezfile.fail()) { cout << "errorrez"; }
	cout<<"Sorted array: \n";
	printArray(arr, n);
	rezfile.close();
    return 0;
}

