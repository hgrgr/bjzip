#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n,m;
int _src,_sink;
int people, work;
vector<vector<int> > adj;
vector<int> aMatch;
vector<int> bMatch;
bool visit[2002];
bool dfs(int a);
int binMatch();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(2*n+1);
    int people = n;
    for(int i=1;i<=n;i++){
        int num = 0;
        cin >> num;
        for(int j=0;j<num;j++){
            int work_num = 0;
            cin >> work_num;
            adj[i].push_back(work_num);
            adj[i+people].push_back(work_num);
        }
    }
    cout << binMatch();
    return 0;
}
bool dfs(int a){
    if(visit[a]) return false;
    visit[a] = true;
    for(int b=0;b<adj[a].size();b++){
        if(bMatch[adj[a][b]] == -1 || dfs(bMatch[adj[a][b]])){
            aMatch[a] = adj[a][b];
            bMatch[adj[a][b]] = a;
            return true;
        }
    }
    return false;
}
int binMatch(){
    int size = 0;
    aMatch = vector<int> (2*n+1,-1);
    bMatch = vector<int> (m+1,-1);
    for(int a=1;a<=2*n;a++){
        memset(visit,false,sizeof(visit));
        if(dfs(a))
            size++;
    }
    return size;
}
