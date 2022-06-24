#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pll;
const long long inf = INT64_MAX/2;
int n,m;
vector<vector<pll> > adj;
vector<long long> upper;
int bell_fod();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    upper.resize(n+1,inf);
    int a,b,c;
    for(int i=0;i < m;i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }
    if(bell_fod() == -1)
    {
        cout << "-1" << endl;
        return 0;
    }
    for(int i=2;i<=n;i++)
        if(upper[i] < inf/10)
            cout << upper[i]<< endl;
        else
            cout << "-1" << endl;
    return 0;
}
int bell_fod(){
    bool update = false;
    upper[1] = 0;
    for(int iter=0;iter<n;iter++){
        update = false;
        for(int here=1;here<=n;here++){
            for(int i=0;i<adj[here].size();i++){
                int next = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[next] > upper[here] + cost){
                    upper[next] = upper[here] + cost;
                    update = true;
                    if(upper[here] >= inf/10 && iter == n-1)
                        update = false;
                }
            }
            
        }
        if(!update)
            break;
    }
    if(update)
        return -1;
    else
        return 1;
}
