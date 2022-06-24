#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
vector<vector<pll> > adj;
vector<int> money;
int arr[126][126];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void dij(int here);
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
        money.clear();
        memset(arr,-1,sizeof(arr));

        for(int i=0;i<t;i++)
            for(int j=0;j<t;j++)
                cin >> arr[i][j];
        
        adj.resize(t*t+1);
        for(int y=0;y<t;y++)
            for(int x=0;x<t;x++){
                for(int k=0;k<4;k++)
                {
                    if(y+moving[k][0] >=0 && y+moving[k][0] < t &&
                            x+moving[k][1] >=0 && x+moving[k][1] < t){
                        adj[y*t+x].push_back(make_pair((y+moving[k][0])*t + x+moving[k][1],
                                arr[y+moving[k][0]][x+moving[k][1]]));
                    }
                }
            }
        loss = arr[0][0];//start 
        dij(0);
        cout  << "Problem "<< num  << ": "<< money[(t-1)*t + (t-1)] + loss<< '\n';
    }
    return 0;
}
void dij(int here){
    money.clear();
    money.resize(t*t+1,INF);

    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push(make_pair(0,here));
    while(!pq.empty()){
        int pre = pq.top().second;
        int m_cost = pq.top().first;
        pq.pop();
        if(money[pre] < m_cost)
            continue;
        for(int next=0;next<adj[pre].size();next++){
            int aft = adj[pre][next].first;
            int n_cost = adj[pre][next].second + m_cost;
            if(n_cost < money[aft]){
                pq.push(make_pair(n_cost,aft));
                money[aft] = n_cost;
            } 
        }
    }
}


