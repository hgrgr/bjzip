#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;
typedef long long int ll;
int n;
ll cal_num(int start, int rem, int use);
int cache[10][100][1<<10];
int main()
{
    cin >> n;
    ll ret = 0;
    memset(cache,-1,sizeof(cache));
    for(int i=1;i<10;i++){
        ret +=cal_num(i,n-1,1 << i) % MOD;
    }
    cout << ret % MOD; 
    return 0;
}
ll cal_num(int start, int rem, int use){
    if(rem <= 0){
        if(use == (1<<10)-1){
            return 1;
        }
        else
            return 0;
    }
    int& ref =cache[start][rem][use];
    if(ref != -1)
        return ref; 
    ref=0;
    if(start == 9){
        ref += cal_num(start-1, rem-1,use | (1<<(start-1))) % MOD;
    }
    else if(start == 0)
    {
        ref += cal_num(start+1, rem-1,use | (1<<(start+1))) % MOD;

    }else{
        ref += cal_num(start+1, rem-1,use | (1<<(start+1))) % MOD;
        ref += cal_num(start-1, rem-1,use | (1<<(start-1))) % MOD;
    }
    return ref % MOD;
}
