#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,a,b;
priority_queue<int,vector<int>, greater<int> > pq;
vector<vector<int> > adj;
vector<bool> visit(32001,false);
vector<int> order;
vector<int> level(32001,0);
int main(){
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        level[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(level[i] == 0){
            pq.push(i);
        }
    }
    int here;
    while(!pq.empty()){
        here = pq.top(); 
        pq.pop();
        visit[here] = true;
        cout << here << " ";
        for(int next=0;next<adj[here].size();next++)
        {
            if(--level[adj[here][next]] == 0 && !visit[adj[here][next]])
                pq.push(adj[here][next]);
        }
    }
    return 0;
}
