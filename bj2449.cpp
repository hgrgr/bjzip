#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;
int n,k;
int arr[202];
int cache[202][202];
int min_sw(int start, int end);
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    memset(cache,-1,sizeof(cache));
    cout << min_sw(0,n-1);

    return 0;
}
int min_sw(int start, int end){
    if(start == end)
        return 0;
    int& ref = cache[start][end];
    if(ref != -1)
        return ref;
    if(start+1 == end)
        return arr[start] != arr[end];
    ref = INF;
    for(int i=start; i<n;i++)
    {
        ref = min(ref, min_sw(start,i) + min_sw(i+1,end) + (arr[start] != arr[end]));
    }
    return ref;
}
