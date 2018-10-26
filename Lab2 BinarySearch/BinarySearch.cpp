#include <stdio.h>
#include <iostream>
using namespace std;

int main () {

int n;

cin >> n;

int n1 = n;
n = n-1;
int key, j;

int arr[n];

for(int x = 0; x<=n; x++) {
cin >> arr[x];
}


for (int i = 1; i<n1; i++) {
	
	key = arr[i];
	j = i - 1;

		while(j>=0 && arr[j]<key) {
			arr[j+1] = arr[j];
			j = j-1;
	}
	arr[j+1] = key;
}

for (int k = 0; k<=n; k++){
cout<<arr[k]<<";";
}

return 0;

}
