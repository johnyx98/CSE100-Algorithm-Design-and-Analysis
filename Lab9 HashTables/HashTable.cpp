#include "stdlib.h"
#include <iostream>
#include <list>

using namespace std;

class HashTable{
    private:
    list<int> *Table;
    public:
    HashTable(){
        Table = NULL;
    };


    ~HashTable(){
        if(Table!=NULL){
            delete[]Table;
        }
    }




void create(int n){
    Table = new list<int>[n];

}

void insert(int key, int n){
    Table[key%n].push_front(key);
}

void searchkey(int key, int n){
    list<int> temp = Table[key%n];
    int index = 0;
    list<int>::iterator it;
    if(temp.empty()){
        cout<< key<< " :" << " NOT FOUND" << endl;
        cout << "++++++++++++++++++++" << endl;
    } else {
        for(it = temp.begin(); it!=temp.end(); ++it){
            if(*it == key){
                cout << key << " : FOUND AT " << (key%n) << "," << index << endl;
                cout << "++++++++++++++++++++" << endl;
                return;
            }
            index = index +1;
        }
        cout << key << " :" << " NOT FOUND" << endl;
        cout << "++++++++++++++++++++" << endl;
        }
    }

bool deletekey(int key, int n){
     list<int> temp = Table[key%n];
    list<int>::iterator it;
    if(temp.empty()){
        return false;
}   else {
    for (it=temp.begin(); it!=temp.end(); it++){
        if (*it == key){
            temp.erase(it);
            Table[key%n] = temp;
            return true;
        }
    } 
    return false;
}

}

void output( int n){
    list<int> thislist;
    int index = 0;
    for(int i = 0; i<n; i++){
    thislist = Table[i];
    
    if (thislist.empty()){
        cout<< i << " : " << endl;
    } else {
        cout<< i<< " : ";
        for(list<int>::iterator it=thislist.begin(); it!=thislist.end(); ++it){
            cout << *it;
            if( next(it) == thislist.end()){
                break;
            }
            cout << "->";
        }
        cout << endl;
        
    }
    }
    cout << "++++++++++++++++++++" << endl;

}

};


int main(int argc, char const *argv[])
{
int size,key;
cin>>size;
char x;

HashTable table;
table.create(size);
cin>>x;
while(true){
    if(x=='i'){
        cin>>key;
        table.insert(key,size);

    }else if(x=='s'){
        cin>>key;
        table.searchkey(key,size);  

    }else if(x=='d'){
        cin>>key;
        if(table.deletekey(key,size)) {
            cout<<key<<" : DELETED"<<endl;
            cout << "++++++++++++++++++++" << endl;
        }
        else{
            cout<<key<<" : DELETE FAILED"<<endl;
            cout << "++++++++++++++++++++" << endl;
        }
    }else if(x=='o'){
        table.output(size);

    } else if(x == 'e'){
        break;
    }
        cin>>x;
    }


return 0;
}