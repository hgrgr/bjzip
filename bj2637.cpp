#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pll;
int n,m;
int x,y,k;
int cache[101][101];
vector<vector<pll> > m_v(101);
vector<vector<int> > adj(101);
vector<int> need(101,0);
vector<int> order(101,0);
vector<bool> visit;
vector<bool> bais(101,true);
vector<int> topolgicalsort();
void dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m; 
    for(int i=0; i<m; i++){
        cin >> x >> y >> k; 
        m_v[x].push_back(make_pair(y,k));
        adj[y].push_back(x);
        bais[x] = false;
    }
    topolgicalsort();
    for(int i=0;i<order.size();i++){
        if(bais[order[i]])
            continue;
        for(int j=0;j<m_v[order[i]].size();j++){
            if(bais[m_v[order[i]][j].first] == true)
                cache[order[i]][m_v[order[i]][j].first] += m_v[order[i]][j].second;
            else{
                for(int k=1;k<=n;k++){
                    cache[order[i]][k] += cache[m_v[order[i]][j].first][k]*m_v[order[i]][j].second;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(bais[i])
            cout << i << " " << cache[n][i]<<endl;
    }
    return 0;
}
vector<int> topolgicalsort(){
    int _m = n;
    visit = vector<bool>(_m+1,false);
    order.clear();
    for(int i=1;i<=_m;i++){
        if(!visit[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());
    return order;
}
void dfs(int here){
    visit[here] = true;
    for(int i=0; i<adj[here].size();i++){
        if(adj[here][i] && !visit[adj[here][i]])        
            dfs(adj[here][i]);
    }
    order.push_back(here);
}
