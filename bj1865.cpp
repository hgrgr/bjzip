#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pll;
const long long inf = INT64_MAX/2;
int n,m,w;
vector<vector<pll> > adj;
vector<long long> upper;
bool bell(int start);
int main(){
    int tcase;
    cin >> tcase;
    for(int tc=0;tc < tcase;tc++){
        cin >> n >> m >> w;
        for(int i=0;i<adj.size();i++)
            adj[i].clear();
        adj.clear();
        adj.resize(n+1);
        int s,e,t;
        for(int i=0;i<m;i++){
            cin >> s >> e >> t; 
            adj[s].push_back(make_pair(e,t)); 
            adj[e].push_back(make_pair(s,t)); 
        }
        for(int i=0;i<w;i++){
            cin >> s >> e >> t;
            adj[s].push_back(make_pair(e,-t));
        }
        int ck_bit; 
        for(int start=1;start<=n;start++){
            ck_bit = 0;
            if(bell(start)){
                cout << "YES";
                ck_bit = 1;
                break;
            }
        }
        if(ck_bit == 0)
            cout << "NO";
        cout << '\n';
    }

    return 0;
}
bool bell(int start){
    upper.clear();
    upper.resize(n+1,inf);
    upper[start] = 0;
    bool update;
    for(int iter=0;iter<n;iter++){
        update = false;
        for(int here=1;here<=n;here++){
            for(int i=0;i<adj[here].size();i++)
            {
                int next = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[next] > cost + upper[here]){
                    upper[next] = cost + upper[here];
                    update = true;
                    if(iter == n-1 && upper[here] >= inf/10)
                        update = false;
                }
            }
        }
        if(!update)
            return false;
    }
    return true;
}
