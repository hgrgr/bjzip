#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
#define SRC 0
#define SINK 1
using namespace std;
int cap[503][503];
int flow[503][503];
int n;
void print_mat();
int networkFlow(int source, int sink);
int main(){
    cin >> n;
    int total = 0;
    int total2 = 0;
    for(int tup=0+2;tup<n+2;tup++){
        cin >> cap[SRC][tup]; 
        total += cap[SRC][tup];
    }
    
    for(int tup=n+2;tup<2*n+2;tup++){
        cin >> cap[tup][SINK]; 
        total2 += cap[tup][SINK];
    }
    
    for(int tup=2;tup<n+2;tup++)
        for(int low=n+2;low<2*n+2;low++)
            cap[tup][low] = 1;
    if(total != total2){
        cout << "-1";
        return 0;
    }
    if(networkFlow(0,1) == total){
        cout << "1"<<endl;
        print_mat();
    }
    else
        cout << "-1";
    return 0;
}
void print_mat(){
    for(int tup=2;tup<n+2;tup++)
    {
        for(int low=n+2;low<2*n+2;low++){
            if(flow[tup][low] == 1)
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
    }
}
int networkFlow(int source, int sink){
    queue<int> q;
    int totalflow = 0;
    while(true){
        while(!q.empty())
            q.pop();
        q.push(source);
        vector<int> parent(2*n+2,-1);    
        int amount = INF;
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there = 0; there < 2*n+2;there++){
                if(cap[here][there] - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1)
            break;
        for(int p = parent[SINK]; p!=source; p = parent[p]){
            amount = min(amount,cap[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = SINK; p!=source; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalflow += amount;
    }
    return totalflow;
}
