#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int out,in;
int n,m;
char arr[101][101];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct Edge{
    int target, cap, flow;
    Edge* reverse;
    int calCap() const {
        return cap - flow;
    }
    void push(int amount){
        flow +=amount;
        reverse->flow -= amount;
    }
};
vector<Edge*> adj[10001*2];
void make_cap();
int networkFlow(int source, int sink);
void addEdge(int u,int v, int cap);
int main(){
    cin >> n >> m; 
    out = 0;
    in = n*m;
    int pple;
    int school;
    pair<int,int> p_pair;
    pair<int,int> s_pair;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'K'){
                pple = i*m+j;
                p_pair = make_pair(i,j);
            }
            else if (arr[i][j] =='H'){
                school = i*m+j;
                s_pair = make_pair(i,j);
            }
        }
    if(n == 1 && m == 1)
    {
        cout << "-1";
        return 0;
    }
    if(abs(s_pair.first - p_pair.first) + abs(s_pair.second - p_pair.second) == 1){
        cout << "-1";
        return 0;
    }
    for(int i=0;i<n*m;i++)
    {
        addEdge(i+in,i+out,1);
    }
    make_cap(); 
    int ret=0;
    cout << networkFlow(pple+out,school+in);
    return 0;
}
int networkFlow(int source, int sink){
    int totalflow=0;
    while(true){
        queue<int> q;
        q.push(source);
        vector<int> parent(2*n*m,-1);
        parent[source] = source;
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there=0; there < adj[here].size();there++){
                if(adj[here][there]->calCap()>0
                        && parent[adj[here][there]->target] == -1){
                    parent[adj[here][there]->target] = here;
                    q.push(adj[here][there]->target);
                }
            }
        }
        if(parent[sink]==-1)
            break;
        int amount = INF;
        for(int p=sink; p != source; p = parent[p]){
            for(int i=0;i < adj[p].size();i++){
                if(adj[parent[p]][i]->target == p){
                    amount = min(amount,adj[parent[p]][i]->calCap());
                    break;
                }
            }
        }
        for(int p=sink; p != source; p = parent[p]){
            for(int i=0;i < adj[parent[p]].size();i++){
                if(adj[parent[p]][i]->target == p){
                    adj[parent[p]][i]->push(amount);
                }
            }
        }
        totalflow +=amount;

    }
    return totalflow;
}
void make_cap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((arr[i][j] == '.' || arr[i][j] == 'K') && arr[i][j] != 'H'){
                for(int k=0;k<4;k++){
                    if(i+moving[k][0] >= 0 && i+moving[k][0] < n
                            && j+moving[k][1] >= 0 && j+moving[k][1] < m
                            && !(arr[i+moving[k][0]][j+moving[k][1]] == '#')){
                        addEdge(((i*m)+j+out),((i+moving[k][0])*m + (j+moving[k][1])+in),1);
                    }
                }
            }
        }
    }
}
void addEdge(int u,int v, int cap){
    Edge* uv = new Edge(), *vu = new Edge();
    uv->target = v;
    uv->cap = cap;
    uv->flow = 0;
    uv->reverse = vu;
    
    vu->target = u;
    vu->cap = 0;
    vu->flow = 0;
    vu->reverse = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
