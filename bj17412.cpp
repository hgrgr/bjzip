#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define SOR 1
#define SINK 2 
#define INF 987654321
using namespace std;
int n,p;
int cap[401][401];
int flow[401][401];
void print_cap();
int networkFlow(int source, int sink);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    int u,v;
    for(int i=0;i<p;i++)
    {
        cin >> u >> v;
        cap[u][v] = 1;
    }
    cout << networkFlow(1,2);
    return 0;
}
int networkFlow(int source, int sink){
    memset(flow,0,sizeof(flow));
    int totalflow = 0;
    while(true){
        queue<int> q;
        vector<int> parent(n+1,-1);
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there = 1; there<=n;there++){
                if(parent[there] == -1 && cap[here][there] - flow[here][there] > 0){
                    q.push(there);
                    parent[there] = here;
                }
            }
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
