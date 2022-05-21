#include <iostream>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,pair<int,int> > ppll;
int n,m;
char tmp[101][101];
int adj[101][101];
bool visit[101][101];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
priority_queue<ppll,vector<ppll>,greater<ppll> > pq;
int bfs();
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin >> tmp[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            adj[i][j] = tmp[i][j] == '0' ? 0 : 1;
    /*
    cout << endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    cout << bfs();
    return 0;
}
int bfs(){
    pq.push(make_pair(0,make_pair(1,1)));
    visit[1][1] = true;
    while(!pq.empty()){
        int cost = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(y==m && x==n)
            return cost;
        for(int i=0;i<4;i++)
        {
            if(y+moving[i][0]>=1 && y+moving[i][0] <=m &&
                    x+moving[i][1]>=1 && x+moving[i][1] <=n &&
                    !visit[y+moving[i][0]][x+moving[i][1]])
            {
                if(adj[y+moving[i][0]][x+moving[i][1]] == 1){
                    pq.push(make_pair(cost+1,make_pair(y+moving[i][0],x+moving[i][1])));
                }else
                    pq.push(make_pair(cost,make_pair(y+moving[i][0],x+moving[i][1])));
                visit[y+moving[i][0]][x+moving[i][1]] = true;
            }
        }
    }
    return INF;
}
