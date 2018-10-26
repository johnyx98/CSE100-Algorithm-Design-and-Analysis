#include "stdlib.h"
#include <iostream>
#include <sstream>

using namespace std;


    struct Node{
        int value;
        Node *right;
        Node *left;
        Node *parent;
};
   
Node* insert(Node *root, int value){

    if (root == NULL) {
        root = new Node();
        root -> value = value;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if(value <= root->value){
        root->left = insert(root->left, value);
        
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* Min(Node* root){
    while(root->left != NULL) {
            root = root->left;
        } 
        return root;
}

 Node* deletekey( Node *root, int value){
    if (root == NULL)
        return NULL;
    else if (value < root->value) 
        root->left = deletekey(root->left, value);
    else if(value>root->value)
        root->right = deletekey(root->right, value);
                           
else{
    if(root->left == NULL && root->right ==NULL){
        delete root;
        root = NULL;
    } else if(root->left == NULL){
         Node*temp = root;
        root = root->right;
        delete temp;
    }else if(root->right == NULL){
         Node*temp = root;
        root = root->left;
        delete temp;
    }  else {
         Node* temp = Min(root->right);
        root -> value = temp->value;
        root->right = deletekey(root->right, temp->value);
    }  
}
return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<< endl;
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->value << endl;
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->value << endl;
    preorder(root->left);
    preorder(root->right);
}



int main(int argc, char const *argv[])
{
    char x[50];
    Node* root = NULL;

    while(cin.getline(x, 50)){
        string temp(x);
        if(temp.size() == 0){
            continue;
        }
        if(temp[0] == 'e') {
            return 0;
        } else if(temp.substr(0,4)=="post"){
            postorder(root);
            cout << "++++++++++++++++++++" << endl;
        } else if(temp.substr(0,3)=="pre"){
            preorder(root);
            cout << "++++++++++++++++++++" << endl;
        } else if(temp.substr(0,2)=="in"){
            inorder(root);
            cout << "++++++++++++++++++++" << endl;
        }else {
            int n;
            stringstream convert_stm(temp.substr(2, temp.size()-1));
            if(!(convert_stm>>n)) 
            n = -1;

            if(temp.substr(0,1) == "i") {
                //cout<< temp.substr(0,3) << endl;
                root = insert(root, n);
                
            } else if(temp.substr(0,1) == "d"){
                root = deletekey(root, n);
            }
        }

    }



/*
    int n;
    cin >> n;
    stringstream convert_stm(x.substr(2, x.size()-1));
    Node* root = NULL;
    cout << x << n << endl;

    while(x = 'i'){
        root =insert(root, n);
        cin >> x;
        cin >> n; 
        cout << x << n << endl; 
    }
    cin >> x; 
    if(x == 'in'){
        inorder(root);

    }

*/
    

    return 0;
}
