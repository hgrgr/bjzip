#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int> > adj;
vector<vector<char> > visit;
vector<vector<char> > m_visit;
vector<vector<int> > grah;
vector<vector<int> > ck_mod;
void dfs(int pos);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    grah.resize(n*m+1);
    adj.resize(n+1,vector<int>(m+1,-1));
    visit.resize(n+1,vector<char>(m+1,false));
    ck_mod.resize(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> adj[i][j];
    int m_count = 0;
    int sec_r=0;
    int s_tmp=0;
    while(1){
        //make grah
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            {
                ck_mod[i][j] = -1;
                visit[i][j] = false;
            }
        }
        for(int i=0;i<n*m;i++)
            grah[i].clear();
        for(int y=0;y<n;y++)
        {
            for(int x=0;x<m;x++){
                if(adj[y][x] == 0){
                    for(int k=0;k<4;k++)
                    {
                        if(y+moving[k][0] >=0 && y+moving[k][0] < n &&
                                x+moving[k][1] >=0 && x+moving[k][1] < m &&
                                adj[y+moving[k][0]][x+moving[k][1]] == 0)
                            grah[y*m+x].push_back((y+moving[k][0])*m + x+moving[k][1]);
                    }
                }
            }
        }
        //check in and out
        for(int i=0;i<n;i++){
            if(!visit[i][0])
                dfs(i*m);
            if(!visit[i][m-1])
                dfs(i*m);
        }
        for(int j=0;j<m;j++){
            if(!visit[0][j])
                dfs(j);
            if(!visit[n-1][j])
                dfs((n-1)*m+j);
        }
        //find_mod
        s_tmp = sec_r;
        sec_r=0;
        for(int y=0;y<n;y++)
        {
            for(int x=0;x<m;x++)
                if(visit[y][x]){
                    for(int k=0;k<4;k++)
                    {
                        if(y+moving[k][0] >= 0 && y+moving[k][0] <n &&
                                x+moving[k][1] >=0 && x+moving[k][1] < m &&
                                !visit[y+moving[k][0]][x+moving[k][1]] && 
                                adj[y+moving[k][0]][x+moving[k][1]] == 1 &&
                                ck_mod[y+moving[k][0]][x+moving[k][1]] !=1){
                            sec_r++;
                            ck_mod[y+moving[k][0]][x+moving[k][1]] = 1; 
                        }
                    }
                }
        }
        for(int y=0;y<n;y++){
            for(int x=0; x<m;x++){
                if(ck_mod[y][x] == 1)
                    adj[y][x] = 0;
            }
        }
        if(sec_r == 0){
            cout << m_count << endl;
            cout << s_tmp;
            break;
        }
        m_count++;
    }
    
    return 0;
}
void dfs(int pos){
    visit[pos/m][pos%m] = true;
    for(int next=0;next<grah[pos].size();next++)
    {
        if(!visit[grah[pos][next]/m][grah[pos][next]%m]){
            dfs(grah[pos][next]);
        }
    }
}
