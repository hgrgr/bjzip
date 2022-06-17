#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> pll;
int n,m,x;
vector<vector<pll> >  adj;
vector<int> cost;
priority_queue<pll,vector<pll>,greater<pll> > q;
void Dij(int here);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    adj.resize(n+1);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }
    int m_min = 0;
    for(int k=1;k<=n;k++){
        while(!q.empty())
            q.pop();
        int tt = 0;
        if(k!=x){
            cost.clear();
            cost.resize(n+1,INF);
            Dij(k);
            //cout << " k = " << k << " and " ;
            tt += cost[x];
            //cout << cost[x] << " + ";
            cost.clear();
            cost.resize(n+1,INF);
            Dij(x);
            tt += cost[k];
            //cout << cost[k] << " = "; 
            //cout << tt << endl;
            m_min = max(m_min,tt);
        }
    }
    cout << m_min;
    return 0;
}
void Dij(int here){
    q.push(make_pair(0,here));
    while(!q.empty()){
        int pre = q.top().second;
        int m_cost = q.top().first;
        q.pop();
        if(cost[pre] < m_cost)
            continue;
        for(int next=0;next<adj[pre].size();next++){
            int aft = adj[pre][next].first;
            int a_cost = adj[pre][next].second + m_cost;
            if(a_cost < cost[aft]){
                //cout << "pre = " << pre << " next = " << aft << " a_cost = " << a_cost << endl;
                cost[aft] = a_cost;
                q.push(make_pair(a_cost,aft));
            }
        }
    }
    
}
