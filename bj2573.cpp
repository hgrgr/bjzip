#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
int n,m;
vector<vector<int> > adj;
vector<vector<int> > melt;
vector<vector<int> > grah;
bool visit[90001];
int wide[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void dfs(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    grah.resize(n*m);
    adj.resize(n+1,vector<int>(m,0));
    melt.resize(n+1,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> adj[i][j];
   
    int melt_num = 0;
    while(1){
        int all_melt =0;
        for(int i=0;i<n*m;i++)
            grah[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(adj[i][j] != 0){
                    int ze_num = 0;
                    for(int k=0;k<4;k++){
                        if(i+wide[k][0] >=0 && i+wide[k][0] < n &&
                                j+wide[k][1] >= 0 && j+wide[k][1] < m
                                && adj[i+wide[k][0]][j+wide[k][1]] == 0){
                            ze_num++;
                        }
                    }
                    melt[i][j] = adj[i][j] - ze_num;
                    if(melt[i][j] <= 0){
                        melt[i][j] = 0;
                    }
                }
            }
        copy(melt.begin(),melt.end(),adj.begin());
        for(int y=0;y<n;y++)
            for(int x=0;x<m;x++)
                if(adj[y][x] != 0){
                    all_melt = 1;
                    for(int k=0;k<4;k++)
                        if(y+wide[k][0] >= 0 && y+wide[k][0] < n &&
                                x+wide[k][1] >= 0 && x+wide[k][1] < m && 
                                adj[y+wide[k][0]][x+wide[k][1]] != 0){
                            grah[(y*m)+x].push_back(((y+wide[k][0])*m) + (x+wide[k][1]));
                        }

                }
        if(all_melt == 0){
            cout << "0";
            return 0;
        }
        memset(visit,false,sizeof(visit));
        int visit_num=0;
        for(int here =0;here < n*m;here++){
            if(!visit[here] && adj[here/m][here%m] > 0)
            {
                dfs(here);
                visit_num++;
            }
        }
        melt_num++;
        if(visit_num >1){
            cout << melt_num;
            return 0;
        }
    }
    return 0;
}
void dfs(int here){
    visit[here] = true;
    for(int there=0; there<grah[here].size();there++){
        if(!visit[grah[here][there]] && adj[here/m][here%m] > 0)
            dfs(grah[here][there]);
    }
}
