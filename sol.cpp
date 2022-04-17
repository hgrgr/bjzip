#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[16][1001];
int cache[16];

int max_money(int day);
int main(){
    cin >> n;
    memset(arr,-1,sizeof(int)*16*1001);
    memset(cache,-1,sizeof(int)*16);
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < 2; j++)
            cin >> arr[i][j];
    }
    cout << max_money(0);
}
int max_money(int day){
    if(day == n)
        return 0;

    int& ref = cache[day];
    if(ref != -1)
        return ref;
    ref = 0;

    if(arr[day][0]+day <= n)
        ref = max(arr[day][1]+max_money(day+arr[day][0]),max_money(day+1));
    else
        ref = max_money(day+1);

    return ref;
}
