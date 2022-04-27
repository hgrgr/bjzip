#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[40001];
int cache[40001];
int main(){
    cin >> n;
    memset(cache,-1,sizeof(int)*40001);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i]; 
    }
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(cache[index] == -1 || cache[index] < arr[i]){
            cache[++index] = arr[i];
        }else{
            cache[lower_bound(cache,cache+index,arr[i])-cache] = arr[i];
        }
    }
    cout << index;
    return 0;
}
