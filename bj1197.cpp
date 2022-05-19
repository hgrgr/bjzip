#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pll;
int v,e;
map<int,vector<pll> > adj;
vector<pair<int, pair<int,int> > > edge;
struct DisjoinSet{
    map<int,int> parent, rank;
    DisjoinSet(){};
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
};
long long kruskal(vector<pll>& select);
DisjoinSet sets;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e;
    edge.resize(e+1);
    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        sets.parent[a] = a;
        sets.parent[b] = b;
        sets.rank[a] = 1;
        sets.rank[b] = 1;
    }
    vector<pll> temp;
    cout << kruskal(temp);
    
    return 0;
}
long long kruskal(vector<pll>& select){
   long long ret = 0; 
   select.clear();
   for(auto it=adj.begin();it != adj.end();it++)
   {
       for(int i=0;i < it->second.size();i++){
            int v = it->second[i].first;
            int cost = it->second[i].second;
            edge.push_back(make_pair(cost,make_pair(it->first,v)));
       }
   }
   sort(edge.begin(),edge.end());
   for(int i=0; i<edge.size();i++)
   {
       int cost = edge[i].first;
       int u = edge[i].second.first;
       int v = edge[i].second.second;
       if(sets.find(u) == sets.find(v)) continue;
       sets.merge(u,v);
       select.push_back(make_pair(u,v));
       ret +=cost;
   }
   return ret;

}
