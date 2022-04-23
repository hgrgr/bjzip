#include <iostream>
#include <cstring>
#define MOD 10007
using namespace std;

int n,k;
int cache[1001][1001];
int num_com(int n1,int n2);
int main()
{
    cin >> n >> k;
    memset(cache,-1,sizeof(int)*1001*1001);
    cout << num_com(n,k) % MOD;
    

    return 0;
}
int num_com(int n1,int n2){
    if(n1 == n2 ||n1 == 0 || n2 == 0)
        return cache[n1][n2]=1;

    int& ref = cache[n1][n2];

    if(ref != -1)
        return ref;

    ref = num_com(n1-1,n2)%MOD + num_com(n1-1,n2-1)%MOD;
    ref %=MOD;
    return ref;
}
