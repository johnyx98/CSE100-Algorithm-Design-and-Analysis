#include "stdlib.h"
#include <iostream>;
#include <vector>;

using namespace std;

void CountingSort(vector<int> v[], int n, int digits){
vector<int> *C;
int Count[10] ={0};
int i;
C = new vector<int>[n];

for(i=0; i<n; i++) {
    Count[v[i][digits]]++;
}
for(i = 1; i<10; i++){
Count[i]+=Count[i-1];

}

for(i = n-1;i>=0;i--){
C[Count[v[i][digits]]-1] = v[i];
Count[v[i][digits]]--;
}

for(i = 0; i<n;i++){
    v[i] = C[i];
}

}


void RadixSort(vector<int>v[], int n){
for (int i = 9; i>=0; i--){

CountingSort(v, n, i);

}
    
}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

vector<int> *v;
v = new vector<int>[n];

for(int i = 0; i<n; i++){
for(int j=0; j<10; j++){
    int x;
    cin >> x;
    v[i].push_back(x);
}
}

RadixSort(v, n);

for(int i = 0; i<n; i++){
for(int j=0; j<10; j++){
    cout << v[i][j] << ";";
}
cout<<endl;
}

    return 0;
}
