#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pll;
char adj[1001][1001];
bool visit[1001][1001][2];
int arr[1001][1001];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int zero_one_bfs();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(arr,-1,sizeof(arr));
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> adj[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            arr[i][j] = adj[i][j]=='0' ? 0 : 1;
    cout << zero_one_bfs();

    return 0;
}
int zero_one_bfs(){
    priority_queue<pair<pll,pll>,vector<pair<pll,pll> >,greater<pair<pll,pll> > > pq;    
    pq.push(make_pair(make_pair(1,0),make_pair(1,1)));
    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = pq.top().first.first;
        int brk = pq.top().first.second;
        pq.pop();
        if(y==n && x==m)
            return cost;
        for(int i=0; i<4;i++){
            if(y+moving[i][0] >=1 && y+moving[i][0] <=n 
                    && x+moving[i][1] >=1 && x+moving[i][1] <=m){
                if(arr[y+moving[i][0]][x+moving[i][1]] == 0 && !visit[y+moving[i][0]][x+moving[i][1]][brk]){
                    visit[y+moving[i][0]][x+moving[i][1]][brk] = true;
                    pq.push(make_pair(make_pair(cost+1,brk),make_pair(y+moving[i][0],x+moving[i][1])));
                }
                if(arr[y+moving[i][0]][x+moving[i][1]] == 1 && brk == 0 && !visit[y+moving[i][0]][x+moving[i][1]][brk]){
                    visit[y+moving[i][0]][x+moving[i][1]][brk+1] = true;
                    pq.push(make_pair(make_pair(cost+1,brk+1),make_pair(y+moving[i][0],x+moving[i][1])));
                }
            }
        }
    }
    return -1;    
}
