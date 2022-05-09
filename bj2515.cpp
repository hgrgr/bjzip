#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pll;
int n,s;
vector<pll> m_v;
vector<int> hegiht;
int cache[300001];
bool compare(pll& a, pll& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int max_value(int pos);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    memset(cache,-1,sizeof(cache));
    int h,c;
    for(int i=0;i<n;i++){
        cin >> h >> c;
        m_v.push_back(make_pair(h,c));
        hegiht.push_back(h);
    }
    sort(m_v.begin(),m_v.end(),compare);
    sort(hegiht.begin(),hegiht.end());
    cout << max_value(0);
    return 0;
}
int max_value(int pos){
    if(pos >= n)
        return 0;
    int& ref = cache[pos];
    if(ref != -1)
        return ref;
    int next = lower_bound(hegiht.begin(),hegiht.end(),m_v[pos].first + s)-hegiht.begin();
    ref = max(max_value(next) + m_v[pos].second, max_value(pos+1));
    return ref;
}
