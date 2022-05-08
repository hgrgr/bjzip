#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
priority_queue<ll,vector<ll>,greater<ll> > pq;
vector<pll> m_v;
int n;
bool compare(pll& a, pll& b){
    if(a.first == b.first) return a.second < b.second; 
    return a.first < b.first;
}
int main(){
    cin >> n;   
    int dead, cup;
    for(int i=0; i<n; i++)
    {
        cin >> dead >> cup;
        m_v.push_back(make_pair(dead,cup));
    }
    sort(m_v.begin(),m_v.end(),compare);    
    int i=0;
    int deadline = 0;
    for(int i=0; i<n;i++){
        deadline = m_v[i].first;
        if(deadline >= pq.size()){
            pq.push(m_v[i].second);
        }
        while(deadline < pq.size()){
            //cout << " pop = " << pq.top() << endl;
            pq.pop();
        }
    }
    ll total = 0;
    while(!pq.empty()){
        total += pq.top();
        //cout << " top = " << pq.top() << endl;
        pq.pop();
    }
    cout << total;
    return 0;
}
