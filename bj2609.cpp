#include <iostream>
#include <algorithm>
using namespace std;

int euc(int a, int b);
int main(){
    int a, b;
    cin >> a >> b;
    if(b>a)
        swap(a,b);
    cout << euc(a,b) << endl; 
    cout << a / euc(a,b)*b;
}
int euc(int a, int b){
    while((a % b !=0 && a != 0 && b != 0)){
        int lest = a % b;
        a=b;
        b=lest;
    }
    return b;

}
