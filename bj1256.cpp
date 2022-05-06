#include <iostream>
#include <cstring>
#define INF 1000000000
using namespace std;
typedef long long ll;
int n,m,k;
ll cache[101][101];
ll mak_table(ll a_num, ll z_num);
ll print_str(ll num, ll a_num, ll z_num,ll total);
int main(){
    cin >> n >> m >> k;
    memset(cache,-1,sizeof(cache));
    if( mak_table(n,m) < k )
    {
        cout << "-1";
        return 0;
    }
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
            cout << cache[i][j] << " ";
        cout << endl;
    }
    */
    print_str(k,n,m,n+m);
    return 0;
}
ll mak_table(ll a_num, ll z_num){
    if( a_num == 0 || z_num == 0 )
        return cache[a_num][z_num] = 1;
    ll& ref = cache[a_num][z_num];
    if(ref != -1)
        return ref;
    ref = mak_table(a_num-1,z_num) + mak_table(a_num,z_num-1);
    if(ref >= INF)
        ref = INF;
    return ref; 

}
ll print_str(ll num, ll a_num, ll z_num,ll total){
    if(total == 0){
        return 0;
    }
    if(a_num == 0){
        cout << "z";
        print_str(num - cache[a_num][z_num-1], a_num, z_num-1, total-1);
        return 0;
    }
    else if(z_num == 0){
        cout << "a";
        print_str(num - cache[a_num-1][z_num], a_num-1, z_num, total-1);
        return 0;
    }
    if(num <=  cache[a_num-1][z_num] && a_num -1 >=0){
        cout << "a"; 
        print_str(num,a_num-1,z_num,total-1);
        return 0;
    }
    else{
        cout << "z";
        print_str(num - cache[a_num-1][z_num], a_num, z_num -1,total-1);
        return 0;
    }
    return 0;
}
