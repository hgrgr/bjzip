#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int> > adj;
vector<bool> visit(1001,false);
vector<int> dis(1001);
vector<int> fin(1001);
vector<int> order;
int counter = 0;
int arr[1001];
void print_order(int size);
void dfs(int here);
vector<int> toposort();
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    adj = vector<vector<int> > (n+1,vector<int> (n+1,0));
    int num;
    int t1,t2;
    for(int i=0;i<m;i++){
        cin >> num;
        memset(arr,0,sizeof(arr));
        for(int j=0;j<num;j++)
            cin >> arr[j];
        if(num == 1)
            continue;
        for(int j=0;j<num-1;j++)
            adj[arr[j]][arr[j+1]] = 1;
    }
    vector<int> ch = toposort();
    if(ch.empty())
    {
        cout << "0";
        return 0;
    }else
        print_order(n);
    return 0;
}
void print_order(int size){
    for(int i=0;i<size;i++)
        cout << order[i] << " ";
}
void dfs(int here){
    visit[here] = true;
    for(int there=0;there < adj[here].size();there++)
    {
        if(adj[here][there] && !visit[there])
            dfs(there);
    }
    order.push_back(here);
}
vector<int> toposort(){
    order.clear();
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            if(adj[order[j]][order[i]])
               return vector<int>();
        }
    }
    return order;
}
