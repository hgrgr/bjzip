#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace  std;
typedef pair<int,int> pll;
const int inf = INT32_MAX;
int n,m;
int ret = inf; 
vector<vector<int> > adj;
vector<pll> virus;
vector<bool> m_select;
vector<pll> block;
int moving[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void ass(int start, int cnt);
int cal_virus();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1,vector<int>(n+1,-1)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
            if(adj[i][j] == 0)
                block.push_back(make_pair(i,j));
            if(adj[i][j] == 2)
                virus.push_back(make_pair(i,j));
        }
    }
    m_select.resize(virus.size(),false);
    ass(0,0);
    if(ret == inf)
        cout << -1;
    else
        cout <<  ret;
    return 0;
}
int cal_virus(){
    priority_queue<pair<int,pll>,vector<pair<int,pll> >, greater<pair<int,pll> > > pq;
    
    while(!pq.empty())
        pq.pop();

    vector<vector<bool> > tmp_v;
    
    for(int i=0; i<tmp_v.size();i++)
        tmp_v[i].clear();
    
    tmp_v.clear();
    tmp_v.resize(n,vector<bool>(n,false));
    int t_max = 0;
    for(int i=0;i<m_select.size();i++){
        if(m_select[i]){
            pq.push(make_pair(0,make_pair(virus[i].first,virus[i].second)));
            tmp_v[virus[i].first][virus[i].second] = true;
        }
    }
    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = pq.top().first;
        adj[y][x] = cost;
        pq.pop();
        for(int k=0;k<4;k++){
            if(y+moving[k][0] >=0 && y+moving[k][0] < n &&
                    x+moving[k][1] >=0 && x+moving[k][1] <n &&
                    !tmp_v[y+moving[k][0]][x+moving[k][1]] &&
                    (adj[y+moving[k][0]][x+moving[k][1]] == 0 || 
                     adj[y+moving[k][0]][x+moving[k][1]] == 2 )){
                if(adj[y+moving[k][0]][x+moving[k][1]] == 0){
                    tmp_v[y+moving[k][0]][x+moving[k][1]] = true;
                    adj[y+moving[k][0]][x+moving[k][1]] = 2;
                    pq.push(make_pair(cost+1,make_pair(y+moving[k][0],x+moving[k][1])));
                }
                else if(adj[y+moving[k][0]][x+moving[k][1]] == 2){
                    tmp_v[y+moving[k][0]][x+moving[k][1]] = true;
                    adj[y+moving[k][0]][x+moving[k][1]] = 2;
                    pq.push(make_pair(cost+1,make_pair(y+moving[k][0],x+moving[k][1])));
                    
                }
            }
        }        
    }
    
    for(int i=0;i<block.size();i++){
        if(adj[block[i].first][block[i].second] == 0){
            t_max = inf;
            break;
        }else{
            t_max = max(t_max,adj[block[i].first][block[i].second]);
        }
    }
    return t_max;

}
void ass(int start, int cnt){
    if(cnt == m){
        vector<vector<int> > tmp(n+1,vector<int>(n+1));
        copy(adj.begin(),adj.end(),tmp.begin());
        ret = min(ret, cal_virus());
        copy(tmp.begin(),tmp.end(),adj.begin());
        return;
    }
    for(int i=start;i<virus.size();i++){
        if(m_select[i]) continue;
        m_select[i] = true;
        ass(i+1,cnt+1);
        m_select[i] = false;
    }
    return;
}
