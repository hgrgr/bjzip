#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<vector<int> > adj;
vector<bool> visit;
vector<int> order;
vector<int> toposort();
void dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    visit.resize(n+1,false);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    toposort();
    for(int i=0;i<order.size();i++){
        cout<< order[i] << " ";
    }
    return 0;
}
void dfs(int here){
    visit[here] = true;
    for(int there=0;there < adj[here].size();there++){
        if(!visit[adj[here][there]])
            dfs(adj[here][there]);
    }
    order.push_back(here);
}
vector<int> toposort(){
    order.clear();
    for(int i=1;i<=n;i++){
        if(!visit[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());
    return order;
}
