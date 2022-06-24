#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
}node;
vector<int> arr;
void find_spot(node* root, int value);
void print_tree(node* root);
int main(){
    node * a = NULL;
    int tmp;
    while(cin >> tmp)
    {
        arr.push_back(tmp);
    }
    for(int i=0;i<arr.size();i++){
        if(a == NULL){
            a = new node(arr[i]);
        }else{
            find_spot(a,arr[i]);
        }
    }
    print_tree(a);
    
    return 0;
}
void print_tree(node* root){
    if(root->left != NULL)
        print_tree(root->left);
    if(root->right != NULL)
        print_tree(root->right);
    cout << root->value << '\n';
}
void find_spot(node* root, int value){
    fflush(stdout);
    if(value < root->value){
        if(root->left == NULL){
            node* tmp = new node(value);
            root->left = tmp;
        }else {
            find_spot(root->left, value);
        }
    }
    else if(value > root->value){
        if(root->right == NULL){
            node* tmp = new node(value);
            root->right = tmp;
        }else{
            find_spot(root->right,value);
        }
    }
}
