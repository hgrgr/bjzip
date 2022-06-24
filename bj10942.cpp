#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
//vector<int> arr;
int m_start,m_end;
int cache[2001][2001];
int arr[2001];
int cal_pal(int s,int e);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    memset(cache,-1,sizeof(cache));
    cin >> m;
    for(int j=0;j<m;j++){
        cin >> m_start >> m_end;
        cout << cal_pal(m_start-1,m_end-1) << '\n';
    }
    return 0;
}
int cal_pal(int s,int e){
    if(s > e)
        return 0;
    if(s == e)
        return cache[s][e] = 1;
    if(s+1 == e)
        return cache[s][e] = (arr[s] == arr[e] ? 1 : 0);
    int& ref = cache[s][e];
    if(ref != -1)
        return ref;
    if(arr[s] == arr[e])
        return ref = cal_pal(s+1,e-1);
    else
        return ref = 0;
}
