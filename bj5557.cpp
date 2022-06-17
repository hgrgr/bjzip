#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int n;
vector<int> lst;
ll total;
ll cal_num(int tol, int pos);
ll cache[21][101];
int main(){
    cin >> n;
    lst.resize(n);
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<n;i++)
        cin >> lst[i];
    cout << cal_num(lst[0],1);
    return 0;
}
ll cal_num(int tol, int pos){
    if(pos == n-1 && tol == lst[n-1]){
        return 1;
    }
    else if(pos == n-1)
        return 0;
    ll& ref = cache[tol][pos];
    if(ref != -1)
        return ref;
    ref = 0;
    if(tol + lst[pos] >= 0 && tol + lst[pos] <= 20)
        ref += cal_num(tol + lst[pos],pos+1);
    if(tol - lst[pos] >= 0 && tol - lst[pos] <= 20)
        ref += cal_num(tol - lst[pos],pos+1);
    return ref;
}
