#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
int n,m;
vector<vector<pll> > adj;
priority_queue<pll,vector<pll>, greater<pll> > pq;
vector<int> cost;
void Dij(int start);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    int u,v,c;
    for(int i=0;i<m;i++){
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v,c));
    }
    int st, end;
    cin >> st >> end;
    cost.resize(n+1,INF);
    Dij(st);
    cout << cost[end];
    return 0;   
}
void Dij(int start){
    cost[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int here = pq.top().second;
        int u_cost = pq.top().first;
        pq.pop();
        if(cost[here] < u_cost)
            continue;
        for(int j=0;j<adj[here].size();j++)
        {
            int there = adj[here][j].first;
            int v_cost = adj[here][j].second + u_cost;
            if(cost[there] > v_cost){
                cost[there] = v_cost;
                pq.push(make_pair(v_cost,there));
            }
        }
    }
}
