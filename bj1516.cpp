#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int> > adj(501);
vector<int> resource(501);
vector<bool> visit(501,false);
vector<int> order;
vector<int> toposort();
vector<int> cache(501,0);
void dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int tmp;
    int j=0;
    for(int i=1;i<=n;i++)
    {
        j=0;
        while(1){
            cin >> tmp;
            j++;
            if(tmp == -1)
                break;
            if(j == 1){//time
                resource[i] = tmp; 
                cache[i] = tmp;
                continue;
            }
            adj[tmp].push_back(i);
        }
    }
    toposort();
    for(int i=0;i<order.size();i++){
        for(int j=0;j<adj[order[i]].size();j++){
            cache[adj[order[i]][j]] = max(cache[adj[order[i]][j]],cache[order[i]]+resource[adj[order[i]][j]]);
        }
    }
    for(int i=1;i<=n;i++)
        cout << cache[i] << endl;
    return 0;
}
void dfs(int here){
    visit[here] = true;
    for(int there=0;there<adj[here].size();there++){
        if(!visit[adj[here][there]])
            dfs(adj[here][there]);
    }
    order.push_back(here);
}
vector<int> toposort(){
    order.clear();
    int size = n;
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());
    return order;
}
