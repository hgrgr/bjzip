#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pll;
int n;
vector<vector<pll> > adj;
int longest = 0;
bool visit[100001];
int cal_dia(int parent,int cost);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int u;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> u;
        while(1){
            int v,c;
            cin >> v;
            if(v == -1)
                break;
            cin >> c;
            adj[u].push_back(make_pair(v,c));
        }
    }
    int root = 1;
    int tmp = cal_dia(root,0);
    cout << max(tmp,longest);
    return 0;
}
int cal_dia(int parent,int cost){
    visit[parent] = true;
    vector<int> costs;
    for(int there = 0; there < adj[parent].size();there++){
        if(!visit[adj[parent][there].first]){
            costs.push_back(cal_dia(adj[parent][there].first, adj[parent][there].second));
        }
    }
    sort(costs.begin(),costs.end());
    if(costs.size() == 0)
        return cost;    
    if(costs.size() >=2){
        longest = max(longest,costs[costs.size()-2] + costs[costs.size()-1]);
    }        
    return costs[costs.size()-1]+cost;
}
