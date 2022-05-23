#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
#define ASIZE 100
using namespace std;
int n;
int flow[ASIZE][ASIZE];
int cap[ASIZE][ASIZE];
int networkFlow(int source, int sink);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    char u,v;
    int c;
    memset(cap,0,sizeof(cap));
    for(int i=0;i<n;i++)
    {
        cin >> u >> v >> c;
        /*
        if(!( u >= 'A' && u <= 'Z'))
            u = u - 'a';
        else
            u = u - 'A';
        if(!( v >= 'A' && v <= 'Z'))
            v = v - 'a';
        else
            v = v - 'A';
        */
        cap[u-'A'][v-'A'] += c;
        cap[v-'A'][u-'A'] += c;
    }
    cout << networkFlow(0,25);

    return 0;
}
int networkFlow(int source, int sink){
    memset(flow,0,sizeof(flow));
    int totalFlow = 0;
    while(true){
        vector<int> parent(ASIZE,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there=0;there<ASIZE;there++){
                if(cap[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1)
            break;
        int amount = INF;
        for(int p = sink; p!=source; p=parent[p]){
            amount = min(cap[parent[p]][p] - flow[parent[p]][p] , amount);
        }
        for(int p = sink;p!=source;p=parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return  totalFlow;
}
