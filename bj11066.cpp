#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 998877665544332211
using namespace std;
typedef long long ll;
int k;
ll arr[501];
ll sum[501];
ll cache[501][501];
ll cal_min(int start, int end);
int main(){
    int tcase;
    cin >> tcase;
    for(int i=0; i<tcase;i++)
    {
        cin >> k;
        memset(arr,0,sizeof(arr));
        memset(sum,0,sizeof(sum));
        memset(cache,-1,sizeof(cache));
        for(int j=1;j<=k;j++){
            cin >> arr[j];
            sum[j] += sum[j-1] + arr[j];
        }
        cout << cal_min(1,k) -(sum[k] - sum[0])<<endl;
    }
    return 0;
}
ll cal_min(int start, int end){
    if(start == end)
        return arr[start];
    ll& ref = cache[start][end];
    if(ref !=-1)
        return ref;
    ref = INF;
    for(int mid = start; mid<end; mid++)
    {
        ref = min(cal_min(start,mid) + cal_min(mid+1,end),ref);
    }
    ref +=sum[end] - sum[start-1];
    return ref;

}
