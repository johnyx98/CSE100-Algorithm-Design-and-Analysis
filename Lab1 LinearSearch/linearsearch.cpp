// Lab1.cpp : Defines the entry point for the console application.
// CSE100Lab1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdio.h>

using namespace std;


int linearsearch(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {

		if (x == arr[i]) {
			return i;

		}

	}
	return -1;

}



int main()
{

	int n;
	cin >> n;
	

	int a[n];

	int key;
	cin >> key;


	int x;
	for (x = 0; x < n; x++) {
		cin >> a[x];
	}

	
	
	cout << linearsearch(a, n, key) << endl;


	return 0;

}
