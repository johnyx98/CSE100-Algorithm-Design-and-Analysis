// Lab4.cpp : Defines the entry point for the console application.
//

#include<cmath>
#include <iostream>
#include <stdio.h>
#include <climits>
#include <cstdint>
using namespace std;

/*
int Max_Sum(int arr[], int x, int m, int n){
	int sum = 0;
	int leftsum = INT_MIN;
	int rightsum = INT_MAX;

	for (int j = m + 1; j <= n; j--) {

		sum += arr[j];

		if (sum > leftsum) {
			leftsum = sum;
		}

	}
	for(int k = m)




}
*/





int Max_Subarray(int arr[],int n) {
	if (n == 1) {
		return arr[0];

	}
	int mid = n/2;
	int left_array = Max_Subarray(arr, mid);
	int right_array = Max_Subarray(arr+mid, n - mid);
	int leftsum = INT_MIN;
	int rightsum = INT_MIN;
	int sum = 0;

	for (int j = mid; j < n; j++) {
		sum += arr[j];
		rightsum = max(rightsum, sum);

	}
	sum = 0;
	for (int i = mid-1; i >= 0; i--) {
		sum += arr[i];
		leftsum = max(leftsum, sum);

	}
	
	
	int Maximum = max(left_array, right_array);
	return max(Maximum, leftsum + rightsum);

}



int main()
{

	int n = 0;

	cin >> n;

	int arr[n];


	for (int x = 0; x < n; x++) {

		cin >> arr[x];

	}

	cout << Max_Subarray(arr, n);

    return 0;
}

