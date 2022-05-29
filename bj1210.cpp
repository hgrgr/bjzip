#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 998877665544332211
#define INF2 999999999999999999
using namespace std;
typedef long long ll;
typedef pair<int,ll> pll;
int n,m;
int m_start, m_end;
ll networkFlow(int src, int sink);
ll flow[404][404];
ll cap[404][404];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> m_start >> m_end;
    memset(flow,0,sizeof(flow));
    memset(cap,0,sizeof(cap));
    const int in = 0;
    const int out = n;
    int _cost;
    for(int i=1;i <= n;i++){
        cin >> _cost;
        cap[i+in][i+out] = _cost;
    }
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        cap[u+out][v+in] = INF;
        cap[v+out][u+in] = INF;
    }
    int total =0;
    total = networkFlow(m_start,m_end+out);
    queue<int> q;
    bool visit[404];
    memset(visit,false,sizeof(visit));
    visit[m_start] = true;
    q.push(m_start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int next = 0; next < 2*n+1;next++){
            if(cap[here][next] - flow[here][next] >0
                    && !visit[next]){
                q.push(next);
                visit[next] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i+in] && !visit[i+out])
            cout << i <<" ";
    }
    return 0;
}
ll networkFlow(int src, int sink){
    ll totalflow = 0;
    while(1){
        queue<int> q;
        vector<int> parent(404,-1);
        q.push(src);
        parent[src] = src;
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there=0; there<2*n+1; there++){
                if(cap[here][there] - flow[here][there] > 0
                        && parent[there] == -1){
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if(parent[sink] == -1)
            break;
        ll amount = INF;
        for(int p=sink; p != src;p=parent[p]){
            amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p=sink; p != src;p=parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalflow += amount;
    }
    return totalflow;
}
