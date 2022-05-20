#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pll;
vector<vector<pll> > adj;
vector<pair<int,pll> > edge;
vector<pair<int,pll> > list;
int n,m;
int mst(vector<pair<int,pll> >& lst);
struct Disjoin{
    vector<int> parent, rank;
    Disjoin(int n){
        parent = vector<int> (n);
        rank = vector<int> (n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int u){
        if(parent[u] == u)
            return u;
        
        return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(rank[u] > rank[v])
            swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[u]++;
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n+1);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        edge.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(edge.begin(),edge.end());
    
    cout << mst(list);
    cout << endl;
    /* 
    for(int i=0; i<list.size();i++){
        cout << list[i].first << " " << list[i].second.first << " " << list[i].second.second << endl;
    }
    */
    return 0;
}
int mst(vector<pair<int,pll> >& lst){
    lst.clear();
    Disjoin dj(n+1);
    int ret = 0;
    for(int i=0; i<edge.size();i++){
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int cost = edge[i].first;
        if(dj.find(u) == dj.find(v))
            continue;
        ret += cost;
        dj.merge(u,v);
//        lst.push_back(make_pair(cost,make_pair(u,v)));
    }
    return ret;
}
