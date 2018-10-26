// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <array>
#include <stdio.h>

using namespace std; 

void heapify(int arr[], int i, int x) {
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max = i;

	if (left < x && arr[left] > arr[max]) 
		max = left;
	
	if (right < x && arr[right] > arr[max]) 
		max = right;

	
	if (max != i) {
		swap(arr[i], arr[max]);
		heapify(arr, max, x);

	}

	}




void Build_Max_Heap(int arr[], int x) {
	int heapsize = x;
	for (int i = x / 2 - 1; i >= 0; i--) {
		heapify(arr, i, x);
	}  
}


void HeapSort(int arr[], int x) {

	Build_Max_Heap(arr, x);
		for (int i = x -1; i >= 0; i--) {
			swap(arr[0], arr[i]);
			heapify(arr, 0, i);

	}

}


int main()
{
  
	int x;

	cin >> x;

	int arr[x];

	for (int i = 0; i < x; i++) {
		cin >> arr[i];

	}

	HeapSort(arr, x);

	for (int j = 0; j < x; j++) {

		cout << arr[j]<< ";";

	}



	return 0;

}
