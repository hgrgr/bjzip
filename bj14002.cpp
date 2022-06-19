#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<int> arr;
int cache[1002];
int cal_min(int pos);
int parent[1002];
int main(){
    cin >> n;
    arr.resize(n+1);
    memset(cache,-1,sizeof(cache));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int total = 0;
    total = cal_min(-1);
    cout << total << endl;
    for(int i=1;i<=n;i++){
        if(cache[i] == total){
            cout << arr[i-1] << " ";
            total--;
        }
    }
    return 0;
}
int cal_min(int pos){
    if(pos == n)
        return 0;
    int& ref = cache[pos+1];
    if(ref != -1)
        return ref;
    ref = 0; 
    if(pos == -1)
    {
        for(int next=pos+1;next<n;next++)
            ref = max(ref,cal_min(next));
        return ref;
    }
    ref = 1;
    for(int next=pos+1;next<n;next++){
        if(arr[pos] < arr[next])
            ref = max(ref,cal_min(next)+1);
    }

    return ref;
}
