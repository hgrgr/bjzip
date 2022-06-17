#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m; 
vector<vector<int> > adj;
vector<int> plan;
vector<int> m_rank;
vector<int> visit;
void dfs(int here, int rk);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    plan.resize(m+1,0);
    m_rank.resize(n+1,0);
    visit.resize(n+1,-1);
    adj.resize(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> adj[i][j];
    for(int i=0;i<m;i++)
        cin >> plan[i];
    int r_n = 0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i] == -1)
            dfs(i,r_n++);
    }
    for(int i=0;i+1<m;i++)
    {
        if(m_rank[plan[i]] != m_rank[plan[i+1]]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
void dfs(int here, int rk){
    visit[here] = true;
    m_rank[here] = rk;
    for(int next=1;next<=n;next++)
        if(adj[here][next] == 1 &&
                visit[next] == -1)
            dfs(next,rk);
}
