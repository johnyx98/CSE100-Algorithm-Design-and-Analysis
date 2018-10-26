
#include <bits/stdc++.h> 
#include "stdlib.h"
#include <iostream>

using namespace std;
#define Table_Size 13
#define prime 11

/*
class HashNode{
public:
    int key;
    int v;
    HashNode(int key, int v){
        this->key = key;
        this->v = v;
    }

};
*/

class HashTable{
    int *table;
    int curr_size;

    public:
    bool Full(){
        return (curr_size == Table_Size);
    }

    
    
    int hashfunction1(int key){
       // cout << (key%Table_Size)<<endl;
       // cout<<key << endl;
        return (key%Table_Size);

    }
    int hashfunction2(int key){
        int h2 = 1 + (key%prime);
       // cout << h2<<endl;
       // cout<<key << endl;
        return h2;
    }


HashTable(){

        table = new int[Table_Size];
        curr_size = 0;
        for(int i = 0; i<Table_Size; i++){
            table[i] = -1;
        }

    }

    void insert(int key){
        if (Full()){
            return;
        }
        int index = hashfunction1(key);
        //cout << index;
        
        if(table[index] != -1){
            int index2 = hashfunction2(key);
            int i =1; 
            while(true) {
                int newIndex = (index + i*index2)%13;
                if (table[newIndex] == -1) {
                    table[newIndex] = key;
                    break;
                }
                i++;
            }
        } else {
            table[index] = key;
            curr_size++;
        }
        


    }
    void search(int key){
        //cout << "searching" << key << endl;
        for (int i = 0; i<Table_Size; i++){
            if(table[i] == key){
                cout << i << endl;
                return;
            }    
        }
        cout << "NOT_FOUND" << endl;
        


    }

    void deletekey(int key){
        for(int i = 0; i<13; i++){
            if(table[i] == key){
                table[i] = -1;
            }
        }



    }
    void printtable(){

        for(int i = 0; i<13; i++){
            if(table[i] != -1){
            cout << table[i] << endl;
            } else {
                cout << endl;
            }
        }
    }


};


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    HashTable htable;

    while(n != -1){
        htable.insert(n);
        cin >> n;
    }
    htable.printtable();
    cin >> n;
    while(n != -2){
        htable.search(n);
        cin >> n;
    }
    cin >> n;
    while(n != -3){
        htable.deletekey(n);
        cin >> n;
    }

    htable.printtable();

    return 0;
}