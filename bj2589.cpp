#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<char> > pan;
vector<vector<int> > adj;
vector<bool> visit;
int max_len=0;
queue<pair<int,int> > q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n*m);
    pan.resize(n+1,vector<char>(m+1));
    visit.resize(n*m,false);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> pan[i][j];
    for(int y=0;y<n;y++)
        for(int x=0;x<m;x++){
            if(pan[y][x] == 'L'){
                for(int k=0;k<4;k++){
                    if(y+moving[k][0] >=0 && y+moving[k][0] < n &&
                            x+moving[k][1] >=0 && x+moving[k][1]<m &&
                            pan[y+moving[k][0]][x+moving[k][1]] == 'L'){
                        adj[(y)*m + x].push_back((y+moving[k][0])*m + (x+moving[k][1])); 
                    }
                } 
            }
        }
    for(int y=0;y<n;y++)
        for(int x=0;x<m;x++)
        {
            while(!q.empty())
                q.pop();
            if(pan[y][x] == 'L'){
                visit.clear();
                visit.resize(n*m,false);
                visit[y*m+x] = true;
                q.push(make_pair(y*m+x,0)); 
                while(!q.empty()){
                    int here = q.front().first;
                    int cost = q.front().second;
                    q.pop();
                    max_len = max(max_len,cost);
                    for(int next=0;next<adj[here].size();next++){
                        if(!visit[adj[here][next]]){
                            visit[adj[here][next]] = true;
                            q.push(make_pair(adj[here][next],cost+1));
                        }
                    }
                }
            }
        }
    cout << max_len;
    return 0;
}
