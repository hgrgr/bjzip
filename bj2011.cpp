#include <iostream>
#include <cstring>
#define MOD 1000000
using namespace std;
int cache[5001];
int arr[5001];
string tmp;
int cal_min(int here);
int main(){
    cin >> tmp;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<tmp.length();i++)
        arr[i] = (int)tmp[i] - (int)'0';
        
    cout << cal_min(0);
    return 0;
}
int cal_min(int here){
    if(arr[here] == 0 && here <tmp.length())
        return 0;
    if(here == tmp.length() -1) 
        return 1;
    if(here == tmp.length())
        return 1;
    int& ref = cache[here];
    if(ref != -1)
        return ref;

    ref = 0;
    if(here < tmp.length()-1){
        if(arr[here] == 2){
            if(arr[here+1] <= 6)
                ref = (cal_min(here+1)%MOD) + (cal_min(here+2) % MOD);
            else
                ref = cal_min(here+1) % MOD;
        }else if(arr[here] == 1)
            ref = (cal_min(here+1)%MOD) + (cal_min(here+2) % MOD);
        else
            ref = cal_min(here+1) % MOD;
    }else
        ref = cal_min(here+1) % MOD;
    return ref % MOD;
}
