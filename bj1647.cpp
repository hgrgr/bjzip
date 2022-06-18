#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pll;
int n,m;
vector<vector<pll> > adj;
vector<int> m_rank;
priority_queue<pair<int,pll>, vector<pair<int,pll> >, greater<pair<int,pll> > > pq;
int my_find(int v);
bool m_merge(int v, int u);
vector<int> parent;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++)
        parent[i] = i;
    adj.resize(n+1);
    m_rank.resize(n+1,1);
    int a,b,c;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        pq.push(make_pair(c,make_pair(a,b)));
    }
    int total = 0;
    int m_max=0;
    while(!pq.empty()){
        int v = pq.top().second.first;
        int u = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        if(my_find(v) == my_find(u))
            continue;
        total += cost;
        if(m_merge(v,u))
            m_max = max(m_max, cost);
    }
    cout << total-m_max;
    return 0;
}
int my_find(int v){
    if(parent[v] == v)
        return v;
    else 
        return parent[v] = my_find(parent[v]);
}

bool m_merge(int v, int u){
    int v_p = my_find(v);
    int u_p = my_find(u);
    if(v_p == u_p)
        return false;
    if(m_rank[u_p] > m_rank[v_p])
        swap(u_p,v_p);
    parent[u_p] = v_p;
    if(m_rank[u_p] == m_rank[v_p])
        m_rank[u_p]++;
    return true;
}
