// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int partition(int arr[], int start, int end) {
	srand(time(NULL));
	int r = start + rand() % (end - start);
	swap(arr[r], arr[end]);

	int x = arr[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++) {

		if (arr[j] <= x) {
			i = i + 1;
			swap(arr[i], arr[j]);

		}
	}
	swap(arr[i + 1], arr[end]);
	return i + 1;
}



void Quicksort(int arr[], int start, int end) {

	if (start < end) {
		int pivot = partition(arr, start, end);
		Quicksort(arr, start, pivot - 1);
		Quicksort(arr, pivot + 1, end);



	}



}



int main()
{
    
	int x;

	cin >> x;

	int arr[x];

	for (int i = 0; i <= x; i++) {
		cin >> arr[i];

	}

	Quicksort(arr, 0, x-1);

	for (int j = 0; j < x; j++) {
		cout << arr[j] << ";";
	}


}

