#include <iostream>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int n;
vector<vector<int> > adj;
int cache[1001][3][3];
int cost[1001];
int cal_cost(int pos, int color,int first);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n+1,vector<int>(n+1,-1));
    memset(cache,-1,sizeof(cache));
    int tmp;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
            cin >> adj[i][j];
    cout << cal_cost(0,0,0);
    return 0;
}
int cal_cost(int pos, int color, int first){
    if(pos == n && color != first)
        return 0;
    else if(pos ==n && color == first)
        return INF;
    int& ref = cache[pos][color][first];
    if(ref != -1)
        return ref;
    ref = INF;
    int tmp = ref;
    if(pos == 0){
        for(int n_color=0;n_color < 3;n_color++){
            ref = min(ref,cal_cost(pos+1,n_color,n_color) + adj[pos+1][n_color]);
        }
        return ref;
    }
    tmp = ref;
    for(int n_color = 0;n_color < 3;n_color++){
        if(n_color != color){
            ref = min(ref, cal_cost(pos+1,n_color,first) + adj[pos+1][n_color]); 
        }
    }
    return ref;
}
