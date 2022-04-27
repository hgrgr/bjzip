#include <iostream>
#include <cstring>
#include <algorithm>
#define MIN -1000000001
using namespace std;
int n;
int arr[1000001];
int cache[1000001];
bool find_gap(int gap);
int main(){
    cin >> n;
    memset(arr,-1,sizeof(int)*1000001);
    for(int i=0; i<1000001;i++)
    {
        cache[i] = MIN;
    }
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int index=0;
    for(int i=0;i<n; i++)
    {
        if( cache[index] == MIN || cache[index] < arr[i])
            cache[++index] = arr[i];
        else
        {
            cache[lower_bound(cache,cache+index,arr[i])-cache] = arr[i];
        }
    }
    cout << index;
    return 0;
}

