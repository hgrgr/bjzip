#include <iostream>
#include <cstring>
using namespace std;
int n;
int r_n;
int r_max;
int arr[1001];
int cache[1001][2];
int len_ras(int start);
int len_less(int start);
int main(){
    cin >> n;
    for(int i=0; i < n;i++)
    {
        cin >> arr[i];
    }
    int ret = 0;
    for(int i=0;i<n;i++)
    {
        memset(cache,-1,sizeof(int)*1001*2);
        r_n = i;
        r_max = arr[i];
        ret = max(ret,len_ras(-1) + len_less(n));
    }
    cout << ret -1 << endl;
    return 0;
}
int len_ras(int start){//end - r_n , cache - 0
    if(start == r_n)
        return 0;
    int& ref = cache[start+1][0];
    if(ref != -1)
        return ref;
    ref = 1;
    for(int next=start+1; next < r_n; next++)
    {
        if((start == -1 || arr[start] < arr[next]) && arr[next] < r_max)
            ref = max(ref,len_ras(next)+1);
    }
    return ref;
}
int len_less(int start){//end - r_n, cache - 1
    if(start == r_n)
        return 0;
    int& ref = cache[start-1][1];
    if(ref != -1)
        return ref;
    ref = 1;
    for(int next=start-1; next > r_n; next--)
    {
        if((start == n || arr[start] < arr[next]) && arr[next] < r_max)
            ref = max(ref,len_less(next)+1);
    }
    return ref;
}
