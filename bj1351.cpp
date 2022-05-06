#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> cache;
ll n,p,q;
ll print_num(ll num);
int main(){
    cin >> n >> p >> q;
    cache[0]=1;
    cout << print_num(n);
    return 0;
}
ll print_num(ll num){
    if(cache.count(num))
        return cache[num];
    else 
        return cache[num] = print_num(num / p) + print_num(num / q);
}
