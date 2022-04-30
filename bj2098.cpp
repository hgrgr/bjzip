#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[17][17];
int cache[17][1<<17];
int min_cost(int pos,int use);
int first;
int main(){
    cin >> n;
    memset(arr,0,sizeof(int)*17*17);
    for(int i=0; i<n;i++)
        for(int j=0; j<n; j++)
            scanf("%d",&arr[i][j]);

    memset(cache,-1,sizeof(cache));
    cout << min_cost(0,1<<0) << endl;
}
int min_cost(int pos,int use){
    if(__builtin_popcount(use) == n){
        if(arr[pos][0] == 0)
            return 987654321;
        else
            return arr[pos][0];
    }

    int& ref = cache[pos][use];

    if(ref != -1)
        return ref;

    ref = 987654321;
    for(int next = 0; next < n; next++)
    {
        if(use & (1 << next) || arr[pos][next] == 0)
            continue;
        ref = min(ref, min_cost(next, use | (1 << next)) + arr[pos][next]);
    }
    return ref;
}
