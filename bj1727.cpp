#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 1987654321
using namespace std;
int n,m;
int m_arr[1001];
int g_arr[1001];
int cache[1001][1001];
int min_char(int man, int girl);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> m_arr[i];
    for(int i=0;i<m;i++)
        cin >> g_arr[i];
    sort(m_arr,m_arr+n);
    sort(g_arr,g_arr+m);
    memset(cache,-1,sizeof(cache));
    int min_num = min(n,m);
    cout << min_char(n,m);
    return 0;
}
int min_char(int man, int girl){
    if(man == 0 || girl == 0)
        return 0;
    int& ref = cache[man][girl];
    if(ref != -1)
        return ref;
    ref = 0;
    if(man==girl)
        ref = min_char(man-1,girl-1) + abs(m_arr[man-1]-g_arr[girl-1]);
    else if(man>girl)
        ref = min(min_char(man-1,girl-1) + abs(m_arr[man-1] - g_arr[girl-1]),min_char(man-1,girl));
    else if(man<girl)
        ref = min(min_char(man-1,girl-1) + abs(m_arr[man-1] - g_arr[girl-1]),min_char(man,girl-1));
    return ref;
}
