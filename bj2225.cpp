#include <iostream>
#include <cstring>
#define MOD 1000000000
typedef long long int ll;
using namespace std;

int n,k;
int coin[201];
ll cache[201][201];
ll cal_num(int num,int pick_num);
int main(){
    memset(coin,-1,sizeof(int)*201);
    memset(cache,-1,sizeof(ll)*201*201);
    cin >> n >> k;
    for(int i=0; i<=n; i++)
        coin[i] = i;
    cout << cal_num(n,k) % MOD;
    return 0;
}
ll cal_num(int num,int pick_num){
    if(num == 0 && pick_num == 0)
        return 1;
    else if(pick_num == 0 && num !=0)
        return 0;
    ll& ref = cache[num][pick_num];
    if(ref != -1)
        return ref;
    ref = 0;
    for(int i=0;i<=n;i++){
        if(num - coin[i] >=0 && pick_num -1 >=0)
            ref += cal_num(num - coin[i],pick_num -1) % MOD;
    }
    return ref;
}
