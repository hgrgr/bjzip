#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
int v,e;
vector<vector<pll> > adj;
vector<int> cost;
priority_queue<pll,vector<pll>,greater<pll> > pq;
int start; 
void Dij(int s);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e >> start;
    adj.resize(v+1);
    int _u,_v,_e;
    for(int i=0;i<e;i++){
        cin >> _u >> _v >> _e; 
        adj[_u].push_back(make_pair(_v,_e));
    }
    Dij(start);
    for(int i=1;i<=v;i++)
    {
        if(cost[i] == INF)
            cout<< "INF"<<endl;
        else
            cout << cost[i] << endl;
    }
    return 0;
}
void Dij(int s){
    cost.resize(v+1,INF);
    cost[s] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int here = pq.top().second;
        int u_cost = pq.top().first;
        pq.pop();
        if(cost[here] < u_cost)
            continue;
        for(int there = 0; there < adj[here].size(); there++){
            int next = adj[here][there].first; 
            int v_cost = u_cost + adj[here][there].second;
            if(cost[next] > v_cost){
                cost[next] = v_cost;
                pq.push(make_pair(v_cost,next));
            }

        }
    }
}
