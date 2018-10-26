#include "stdlib.h";
#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;

void InsertionSort(vector<float> Bucket, int n){
    int key, j;
    for(int i =1; i<n; i++){
        key = Bucket[i];
        j = i-1;
        while(j>=0 && Bucket[j]>key){
            Bucket[j+1] = Bucket[j];
            j=j-1;
        }
        Bucket[j+1] = key;
    }
}



void BucketSort(float arr[], int n){
vector<float> Bucket[n];

for(int i = 0; i<n; i++){
int bucketindex = n*arr[i];
Bucket[bucketindex].push_back(arr[i]);
}

for(int i = 0; i<n; i++){
    sort(Bucket[i].begin(), Bucket[i].end());
}



for(int i = 0; i<n; i++){
InsertionSort(Bucket[i], Bucket[i].size());
}

 int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < Bucket[i].size(); j++) 
          arr[index++] = Bucket[i][j]; 

}




int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    float arr[n]; 



    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    BucketSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << endl;

    }
    



    
    return 0;
}
