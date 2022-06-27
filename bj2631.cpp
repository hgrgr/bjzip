#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<int> arr;
int cache[202];
int cal_num(int here);
int main(){
    cin >> n; 
    memset(cache,-1,sizeof(cache));
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << n - cal_num(-1);
    return 0;
}
int cal_num(int here){
    if(here >= n)
        return 0;
    int& ref = cache[here+1];
    if(ref !=-1)
        return ref;
    ref = 0;
    for(int next=here+1;next<n;next++)
        if(here == -1 || arr[here] < arr[next])
            ref = max(ref, cal_num(next)+1);
    return ref;
}
