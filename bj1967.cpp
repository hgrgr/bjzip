#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pll;
int n;
vector<vector<pll> > adj;
bool visit[100001];
int dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int u,v,c;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin >> u >> v >> c; 
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    int _max = 0;
    for(int i=1;i<=n;i++){
        memset(visit,false,sizeof(visit));
        _max = max(_max, dfs(i));
    }
    cout << _max;
    return 0;
}
int dfs(int here){
    visit[here] = true;
    int ret=0;
    for(int there = 0; there < adj[here].size(); there++){
        if(!visit[adj[here][there].first]){
            ret = max(ret,dfs(adj[here][there].first) + adj[here][there].second);
        }
    }
    return ret;
}
