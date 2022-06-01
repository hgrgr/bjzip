#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
int n,e;
vector<vector<pll> > adj;
vector<bool> visit;
void dfs(int here);
int m_min = INF;
void Dij(int start);
vector<int> cost;
priority_queue<pll,vector<pll>, greater<pll> > pq;
int main(){
    cin >> n >> e;
    adj.resize(n+1);
    visit.resize(n+1,false);
    cost.resize(n+1,INF);
    int a,b,c;
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    int v1,v2;
    cin >> v1 >> v2;
    int t1=0,t2=0;
    Dij(1);
    t1 += cost[v1];
    Dij(v1);
    t1 += cost[v2];
    Dij(v2);
    t1 += cost[n];

    Dij(1);
    t2 += cost[v2];
    Dij(v2);
    t2 += cost[v1];
    Dij(v1);
    t2 += cost[n];

    if(min(t1,t2) >= INF || min(t1,t2) < 0)
        cout << "-1"<<endl;
    else
        cout << min(t1,t2)<<endl;

    return 0;
}
void Dij(int start){
    cost.clear();
    cost.resize(n+1,INF);
    cost[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int u_cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(cost[here] < u_cost)
            continue;
        for(int there=0;there<adj[here].size();there++)
        {
            int v_cost = u_cost + adj[here][there].second;
            int next = adj[here][there].first;
            if(cost[next] > v_cost){
                cost[next] = v_cost;
                pq.push(make_pair(v_cost,next));
            }
        }
    }
}
