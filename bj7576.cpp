#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<int> > adj;
vector<vector<int> > grah;
vector<bool> visit;
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n; 
    grah.resize(m*n);
    adj.resize(n+1,vector<int>(m+1)); 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> adj[i][j];
    //make grah
    queue<pair<int,int> > toto;
    visit.resize(n*m,false);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(adj[i][j] != -1)
            {
                for(int k=0;k<4;k++)
                {
                    if(i+moving[k][0] >= 0 && i+moving[k][0] < n &&
                            j+moving[k][1] >= 0 && j+moving[k][1] < m && 
                            adj[i+moving[k][0]][j+moving[k][1]] != -1){
                        grah[i*m + j].push_back((i+moving[k][0])*m + j+moving[k][1]);
                    }
                }
            }
            if(adj[i][j] == 1){
                toto.push(make_pair(i*m+j,0));
                visit[i*m+j] = true;
            }
        }
    int day=0;
    while(!toto.empty()){
        int ver = toto.front().first;
        int days = toto.front().second;
        toto.pop();
        day = max(day,days);
        for(int next=0;next<grah[ver].size();next++){
            if(!visit[grah[ver][next]]){
                toto.push(make_pair(grah[ver][next],days+1));
                visit[grah[ver][next]] = true;
            }
        }
    }
    for(int i=0;i<n*m;i++)
        if(visit[i] == false && adj[i/m][i%m] != -1){
            cout << "-1";
            return 0;
        }
    cout << day;
    return 0;
}
