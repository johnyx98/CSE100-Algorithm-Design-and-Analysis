// Lab3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
using namespace std;

void Merge(int arr[], int low, int high, int mid) {
	int n1, n2, n3;
	int arr2[high];
	n1 = low;
	n2 = low;
	n3 = mid + 1;

	while (n1 <= mid && n3 <= high) {
		if (arr[n1] < arr[n3]) {
			arr2[n2] = arr[n1];
			n1++;
			n2++;

		}
		else {
			arr2[n2] = arr[n3];
			n2++;
			n3++;
		}

	}
	while (n1 <= mid) {
		arr2[n2] = arr[n1];
		n2++;
		n1++;
	}
	while (n3 <= high) {
		arr2[n2] = arr[n3];
		n2++;
		n3++;
	}

	for (n1 = low; n1 < n2; n1++) {
		arr[n1] = arr2[n1];
	}







	/*n1 = mid - low + 1;
	n2 = high - mid;

	i = 0;
	j = 0;
	k = 0;

	//declaring right and left arrays
	int L[n1], R[n2];
	for (i = 1; i <= n1; i++) {

		L[i] = arr[low + i - 1];

	}


	for (j = 1; j <= n2; j++) {

		R[j] = arr[mid + j];

	}

	for (k = low; k < high; k++) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		
	} */

} 


void MergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid;
		mid = (low + high) / 2;

		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		Merge(arr, low, high, mid);




	}

	return;

}




int main()
{
	int n;
	cin >> n;
	int arr[n];

	int x;

	for (x = 0; x < n; x++) {

		cin >> arr[x];

	}

	MergeSort(arr, 0, n-1);


	for (int i = 0; i < n; i++) {

		cout << arr[i] << ";";

	}




    return 0;
}
