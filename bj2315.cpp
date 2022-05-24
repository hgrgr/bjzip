#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define SOR 1
#define SINK 2 
#define INF 987654321
using namespace std;
int n,p;
int cap[802][802];
int flow[802][802];
void print_cap();
int networkFlow(int source, int sink);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    int u,v;
    const int in = 0;
    const int out = n;
    for(int i=1;i<=n;i++){
        cap[i+in][i+out] = 1;
    }
    for(int i=0;i<p;i++)
    {
        cin >> u >> v;
        cap[u+out][v+in] = 1;
        cap[v+out][u+in] = 1;
    }
    cout << networkFlow(SOR+out,SINK+in);
    return 0;
}
int networkFlow(int source, int sink){
    memset(flow,0,sizeof(flow));
    int totalflow = 0;
    while(true){
        queue<int> q;
        vector<int> parent(2*n+1,-1);
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there = 1; there<=2*n;there++){
                if(parent[there] == -1 && cap[here][there] - flow[here][there] > 0){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        for(int i=1; i<=2*n;i++){
        }
        if(parent[sink] == -1)
            break;
        int amount = INF;
        for(int p = sink; p != source; p=parent[p]){
            amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; p != source; p=parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalflow += amount;
    }
    return totalflow;

}
