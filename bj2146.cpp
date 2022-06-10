#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n;
int ret = INF;
vector<vector<int> > adj;
vector<vector<int> > grah;
vector<vector<char> > visit;
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int y,int x,int r);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n+1,vector<int>(n+1));
    grah.resize(n*n+1);
    visit.resize(n+1,vector<char>(n+1,false));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> adj[i][j];
    //make grah
    for(int y=0;y<n;y++)
        for(int x=0;x<n;x++){
            if(adj[y][x] == 1){
                for(int k=0;k<4;k++)
                {
                    if(y+moving[k][0]>=0 && y+moving[k][0] <n &&
                            x+moving[k][1] >= 0 && x+moving[k][1] < n &&
                            adj[y+moving[k][0]][x+moving[k][1]] == 1)
                        grah[y*n + x].push_back((y+moving[k][0])*n + x+moving[k][1]);
                    }
                }
            }
    
    //rank;
    int rank = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visit[i][j] && adj[i][j] == 1)
                dfs(i,j,rank++);
        }
    }
    vector<pair<pair<int,int>,int> > sea_q;
    for(int y=0;y<n;y++)
    {
        for(int x=0;x<n;x++)
        {
            int one_ck = 0;
            if(adj[y][x] != 0){
                for(int k=0;k<4;k++){
                    if(y+moving[k][0] >= 0 && y+moving[k][0] < n && 
                        x+moving[k][1] >=0 && x+moving[k][1] < n && 
                        adj[y+moving[k][0]][x+moving[k][1]] == 0 && one_ck == 0){
                        one_ck =1;
                        sea_q.push_back(make_pair(make_pair(y,x),adj[y][x]));
                    }
                }
            }
        }
    }
    for(int t=0;t<sea_q.size();t++){
        queue<pair<pair<int,int>, pair<int,int> > > pos_q;
        vector<vector<char> > t_visit(n+1,vector<char>(n+1,false));
        while(!pos_q.empty())
            pos_q.pop();
        pos_q.push(make_pair(sea_q[t].first,make_pair(0,sea_q[t].second)));
        while(!pos_q.empty()){
            pair<int,int> yx = pos_q.front().first;
            int len = pos_q.front().second.first;
            int color = pos_q.front().second.second; 
            pos_q.pop();
            for(int k=0;k<4;k++){
                if(yx.first + moving[k][0] >= 0 && yx.first + moving[k][0] < n &&
                        yx.second + moving[k][1] >= 0 && yx.second + moving[k][1] < n && 
                        adj[yx.first + moving[k][0]][yx.second + moving[k][1]] == 0 && 
                        !t_visit[yx.first+moving[k][0]][yx.second+moving[k][1]]){
                    pos_q.push(make_pair(make_pair(yx.first+moving[k][0],yx.second+moving[k][1]),
                                make_pair(len+1,color)));
                    t_visit[yx.first+moving[k][0]][yx.second+moving[k][1]] = true;
                }
                if(yx.first + moving[k][0] >= 0 && yx.first + moving[k][0] < n &&
                        yx.second + moving[k][1] >= 0 && yx.second + moving[k][1] < n && 
                        adj[yx.first + moving[k][0]][yx.second + moving[k][1]] != 0 &&
                        adj[yx.first + moving[k][0]][yx.second + moving[k][1]] != color){
                    ret = min(ret, len);
                }
            }
        }
    }
    cout << ret;
    return 0;
}
void dfs(int y,int x, int r){
    visit[y][x] = true;
    adj[y][x] = r;
    for(int next = 0; next < grah[y*n+x].size();next++){
        if(!visit[grah[y*n+x][next] /n][grah[y*n+x][next] % n])
            dfs((grah[y*n+x][next] / n), grah[y*n+x][next] % n, r);
    }
}
