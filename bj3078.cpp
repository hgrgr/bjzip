#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n,k;
ll xarr[4000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    ll g,x;
    memset(xarr,0,sizeof(xarr));
    for(int i=0;i<n;i++)
    {
        cin >> g >> x;
        xarr[x] = g;
    }
    ll total = 0;
    for(int i=0;i<=k*2;i++){
        total += xarr[i];
    }
    ll mx = total;
    ll st = 0, end = 2*k;
    for(int i=0;i+k*2<4000001;i++){
        mx = max(mx,total); 
        total -= xarr[st++];
        total += xarr[++end];
    }
    cout << mx;

    return 0;
}
