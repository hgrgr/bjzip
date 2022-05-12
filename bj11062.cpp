#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
ll arr[1001];
ll cache[1001][1001][2];
ll max_value(int start, int end,bool turn);
int main(){
    int tcase;
    cin >> tcase;
    for(int t=0;t<tcase;t++)
    {
        cin >> n;
        memset(arr,0,sizeof(arr));
        memset(cache,-1,sizeof(cache));
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << max_value(0,n-1,0) <<endl;
    }
    return 0;
}
ll max_value(int start,int end,bool turn){
    if(start > end)
        return 0;
    if(start == end && turn == 0)
        return arr[start];
    else if(start == end && turn == 1)
        return 0;
    ll& ref = cache[start][end][turn];
    if(ref != -1)
        return ref;
    ref = 0;
    int ck =0;
    int tmp;
    int tmp2;
    if(turn == true){
        tmp = max_value(start+1,end,!turn);
        tmp2 = max_value(start,end-1,!turn);
        if(tmp > tmp2)
            ref = tmp2;
        else
            ref = tmp;
    }
    else{
        tmp = max_value(start+1,end,!turn) + arr[start];
        tmp2 = max_value(start,end-1,!turn) + arr[end];
        if(tmp > tmp2)
            ref = tmp;
        else
            ref = tmp2;
    }
    return ref;
}
