#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int V,E;
vector<vector<int> > adj;
bool visit[200001];
bool ajoin[200001];
bool bjoin[200001];
void dfs(int here, int dep);
int main(){
    ios_base::sync_with_stdio(false);
    int tcase;
    int ck_bit=0;
    cin >> tcase;
    for(int t=0;t<tcase;t++){
        adj.clear();
        ck_bit = 0;
        memset(visit,false,sizeof(visit));
        memset(ajoin,false,sizeof(ajoin));
        memset(bjoin,false,sizeof(bjoin));
        cin >> V >> E;
        adj.resize(V+1);
        int u,v;
        for(int j=0;j<E;j++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=V;i++)
            if(!visit[i])
                dfs(i,0);
        for(int i=1;i<=V;i++){
            if(ajoin[i] == true && bjoin[i] == true)
            {
                ck_bit = 1;
            }
        }
        if(ck_bit == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        /*
        cout << " ----- a join" << endl;
        for(int i=1;i<=V;i++){
            cout << ajoin[i] << " ";
        }
        cout << endl;
        cout << " ----- b join" << endl;
        for(int i=1;i<=V;i++){
            cout << bjoin[i] << " ";
        }
        */
    }
    return 0;
}
void dfs(int here, int dep){
    if((dep % 2) == 0)
        ajoin[here] = true;
    else if((dep % 2) == 1)
        bjoin[here] = true;
    visit[here] = true;
    for(int there=0;there < adj[here].size(); there++)
        if(!visit[adj[here][there]])
            dfs(adj[here][there],dep+1);
        else{
            if(((dep+1) % 2) == 0)
                ajoin[adj[here][there]] = true;
            else if(((dep+1) % 2) == 1)
                bjoin[adj[here][there]] = true;
        }
}
