//arr
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
vector<vector<pll> > adj;
int money[126][126];
int arr[126][126];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void dij(int y,int x);
int t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num=0;
    while(1){
        num++;
        cin >> t;
        int loss = 0;
        if(t == 0)
            break;
        
        for(int i=0;i<adj.size();i++)
            adj[i].clear();
        adj.clear();

        memset(arr,-1,sizeof(arr));

        for(int i=0;i<t;i++)
            for(int j=0;j<t;j++){
                cin >> arr[i][j];
                money[i][j] = INF;
            }
        
        dij(0,0);
        cout  << "Problem "<< num  << ": "<< money[t-1][t-1] << '\n';
    }
    return 0;
}
void dij(int y,int x){
    priority_queue<pair<int,pll>, vector<pair<int,pll> >, greater<pair<int,pll> > > pq;
    pq.push(make_pair(arr[y][x],make_pair(y,x)));
    while(!pq.empty()){
        int p_y = pq.top().second.first;
        int p_x = pq.top().second.second;
        int m_cost = pq.top().first;
        pq.pop();
        if(money[p_y][p_x] < m_cost)
            continue;
        for(int k=0;k<4;k++){
            if(p_y + moving[k][0] >= 0 && p_y + moving[k][0] < t &&
                    p_x + moving[k][1] >= 0 && p_x + moving[k][1] < t)
            {
                int n_y = p_y + moving[k][0];
                int n_x = p_x + moving[k][1];
                int n_cost = m_cost + arr[n_y][n_x];
                if(n_cost < money[n_y][n_x])
                {
                    money[n_y][n_x] = n_cost;
                    pq.push(make_pair(n_cost,make_pair(n_y,n_x)));
                }
            }
        }
    }
}
