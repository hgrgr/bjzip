#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int l,c;
vector<char> alpa;
vector<char> temp;
int a[5] = {'a','e','i','o','u'};
int ck_a = 0;
int ck_b = 0;
bool print_sec(int pos,int num);
int main(){
    cin >> l >> c;
    alpa.resize(c);
    temp.resize(c);
    for(int i=0;i<c;i++)
        cin >> alpa[i];
    sort(alpa.begin(),alpa.end());
    print_sec(0,0);
    return 0;
}
bool print_sec(int pos,int num){
    if(pos > l)
        return false;
    if(pos == l && ck_a >=1 && ck_b >=2){
        for(int i=0;i<l;i++)
            cout << temp[i];
        cout<< endl;
        return true;
    }
    for(int next=num;next < c;next++){
        int ck_bit=0;
        temp[pos] = alpa[next];    
        for(int i=0;i<5;i++){
            if(temp[pos] == a[i]){
                ck_a++;
                ck_bit = 1;
            }
        }
        if(ck_bit == 0)
        {
            ck_b++;
            ck_bit = 2;
        }
        print_sec(pos+1,next+1);
        if(ck_bit == 1)
            ck_a--;
        else if(ck_bit == 2)
            ck_b--;
    }
    return true;

}
