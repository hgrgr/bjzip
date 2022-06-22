#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n;
bool arr[10][10];
bool visit[10];
int parent[10];
pll rate[10][10];
ll gcd(ll a, ll b);
bool dfs(int start, int target);
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll a,b,p,q;
    memset(arr,false,sizeof(arr));
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b >> p >> q;
        arr[a][b] = true;
        arr[b][a] = true;
        ll tmp = gcd(p,q);
        rate[a][b] = make_pair(p/tmp,q/tmp);
        rate[b][a] = make_pair(q/tmp,p/tmp);
    }
    for(int i=0;i<n;i++)
    {
        arr[i][i] = true;
        rate[i][i] = make_pair(1,1);
    }
    int start = 0;
    vector<pll> pq(n);
    for(int target = 0;target < n;target++){
        if(arr[start][target]){
            pq[target] = make_pair(rate[start][target].first, rate[start][target].second);
        }else{
            memset(visit,false,sizeof(visit));
            memset(parent,-1,sizeof(parent));
            dfs(start, target);
            ll p = 1;
            ll q = 1;
            for(int pa = 0;parent[pa] != -1; pa=parent[pa]){
                p *= rate[pa][parent[pa]].first;
                q *= rate[pa][parent[pa]].second;
            }
            pq[target] = make_pair(p,q);
        }
    }
    /*
    for(int i=0;i<n;i++){
        cout << " i = " << i << " p = " << pq[i].first << " q = " << pq[i].second << endl;
    }
    */
    ll lcm = pq[0].first;
   
    for(int i=1;i<n;i++)
        lcm = lcm / gcd(lcm,pq[i].first) * pq[i].first;
    //cout << " lcm = " << lcm << endl;
    vector<ll> ret(n,0); 
     
    for(int i=0;i<n;i++)
        ret[i] = pq[i].second * (lcm / pq[i].first);
    
    //for(int i=0;i<n;i++)
    //    cout << ret[i] << " ";
    //cout << endl; 
    ll gcd_num = ret[0];
    //cal gcd
    for(int i=1;i<n;i++)
        gcd_num = gcd(gcd_num,ret[i]);
    //cout << " gcd = " << gcd_num << endl;
    //call ret 
    for(int i=0;i<n;i++)
        ret[i] = ret[i] / gcd_num;
    //print ret 
    for(int i=0;i<n;i++)
        cout << ret[i] << " ";
    
    return 0;
}
bool dfs(int start, int target){
    visit[start] = true;
    if(arr[start][target])
    {
        parent[start] = target;
        return true;
    }
    for(int next=0;next<n;next++){
        if(!visit[next] && arr[start][next])
        {
            parent[start] = next;
            if(dfs(next,target))
                return true;
        }
    }
    return false;
}
ll gcd(ll a, ll b){
    if(b>a)
        swap(a,b);
    while((a % b != 0) && a != 0 && b != 0){
        ll lest = a % b;    
        a = b;
        b = lest;
    }
    return b;

}
