#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;
typedef long long ll;
int n,s;
int arr[100001];
int sum(int start, int end);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n;i++)
    {
        cin >> arr[i];
    }
    int st,ed;
    st = ed = 0;
    int tmp=INF;
    int t_sum;
    t_sum = sum(0,0);
    while(1){
        if(st == n-1 && ed == n-1)
            break;
        if(t_sum >= s){
            tmp = min(tmp, ed - st+1);
            if(ed < n){
                t_sum -=arr[st++];
            }
            else
                t_sum +=arr[++ed];
        }
        else if((t_sum > s && st < ed) || ed == n-1){
            t_sum -=arr[st++];
        }else if((t_sum < s && ed < n) ){
            t_sum +=arr[++ed];
        }

    }
    if(sum(st,ed) >= s)
        tmp = min(tmp, ed - st +1);
    if(tmp == INF)
        cout << "0";
    else
        cout << tmp;
    return 0;
}
int sum(int start, int end){
    int tmp=0;
    for(int i=start; i<=end;i++)
        tmp +=arr[i];
    return tmp;
}
