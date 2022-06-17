#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<char> > adj;
int r,c;
int m_num;
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visit[100];
void dfs(int y,int x, int c);
int main(){
    cin >> r >> c;
    adj.resize(r,vector<char>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> adj[i][j];
    memset(visit,false,sizeof(visit));
    dfs(0,0,1);
    cout << m_num;
    return 0;
}
void dfs(int y, int x, int co){
    visit[adj[y][x] % 100] = true;
    bool t_visit[100];
    memcpy(t_visit,visit,sizeof(visit));
    m_num = max(m_num, co);
    for(int k=0;k<4;k++){
        if(y+moving[k][0] >= 0 && y+moving[k][0] < r &&
                x+moving[k][1] >= 0 && x+moving[k][1] < c &&
                !visit[adj[y+moving[k][0]][x+moving[k][1]] % 100]){
            dfs(y+moving[k][0], x+moving[k][1],co+1);
            memcpy(visit,t_visit,sizeof(t_visit));
        }
    }
}
