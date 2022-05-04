#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int use[101];
int cost[101];
int cache[101][10001];
int cache2[10001];
int cal_cost(int start, int _cost);
int main(){
    cin >> n >> m;

    memset(use,-1,sizeof(use));
    memset(cost,-1,sizeof(cost));
    memset(cache,0,sizeof(cache));
    int total = 0;
    for(int i=0; i<n;i++)
        cin >> use[i];
    for(int i=0; i<n;i++){
        cin >> cost[i];
        total += cost[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=total;j >=0;j--){
            if(j-cost[i]<0)
                continue;
            cache2[j] = max(cache2[j], cache2[j-cost[i]] + use[i]);
        }
    }
    for(int j=0; j<=total;j++){
        if(cache2[j] >= m){
            cout << j;
            return 0;
        }
    }

    return 0;
}
