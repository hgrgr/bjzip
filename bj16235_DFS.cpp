//DFS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
int n,L,R;
int pan[51][51];
vector<vector<int> > adj;
vector<int> use_v;
bool visit[2501];
bool tmp_vi[2501];
int total;
int total_sum;
void dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L >> R;
    memset(pan,-1,sizeof(pan));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> pan[i][j];
        }
    }
    int day = 0;
    while(1){
        //open line_c
        adj.clear();
        adj.resize(n*n+1);
        memset(visit,false,sizeof(visit));
        memset(tmp_vi,false,sizeof(tmp_vi));
        int line_ck = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //ck right 
                if(j+1 < n){
                    if(abs(pan[i][j] - pan[i][j+1]) >= L && abs(pan[i][j] - pan[i][j+1]) <= R){
                        adj[i*n+j].push_back(i*n+(j+1));
                        adj[i*n+(j+1)].push_back(i*n+j);
                        line_ck = 1;
                    }
                }
                //ck down
                if(i+1 < n){
                    if(abs(pan[i][j] - pan[i+1][j]) >= L && abs(pan[i][j] - pan[i+1][j]) <= R){
                        adj[i*n+j].push_back((i+1)*n+j);
                        adj[(i+1)*n+j].push_back(i*n+j);
                        line_ck = 1;
                    }
                }
            }
        }
        if(line_ck == 0){
            cout << day;
            return 0;
        }
        day++;
        //  dfs 
        for(int i=0;i<n*n;i++){
            total = 0;
            total_sum = 0;
            use_v.clear();
            if(!visit[i])
            {
                dfs(i);
                total_sum /= total;
                for(int j=0; j<use_v.size();j++){
                    int tup = use_v[j] / n;
                    int low = use_v[j] % n;
                    pan[tup][low] = total_sum;
                }
            }
        }
    }
    return 0;
}
void dfs(int here){
    visit[here] = true;
    use_v.push_back(here);
    total++;
    int tup = here / n;
    int low = here % n;
    total_sum += pan[tup][low];
    for(int there=0;there<adj[here].size();there++){
        if(!visit[adj[here][there]])
            dfs(adj[here][there]);
    }
}
