#include <iostream>
#include <cstring>
#include <vector>
#define INF 998877665544332211
using namespace std;
typedef pair<int,int> pll;
typedef long long ll;
ll cache[501][501];
int n;
vector<pll> mat;
ll cal_mul(int start, int end);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int r,c;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<n;i++){
        cin >> r >> c;
        mat.push_back(make_pair(r,c));
    } 
    cout << cal_mul(0,n-1);
    return 0;
}
ll cal_mul(int start, int end){
    if(start >= end)
        return 0;
    if(end - start == 1)
        return mat[start].first * mat[start].second * mat[end].second;
    ll& ref = cache[start][end];
    if(ref != -1) 
        return ref;
    ref = INF;
    for(int pos = start; pos < end;pos++){
        ref = min(ref, cal_mul(start,pos) + cal_mul(pos+1,end) + mat[start].first*mat[pos].second*mat[end].second);
    }
    return ref;
}
