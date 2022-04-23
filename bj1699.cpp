#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[401];
int cache[100001];
int num_min(int num);
int main(){
    cin >> n;
    memset(arr,0,sizeof(int)*401);
    memset(cache,-1,sizeof(int)*100001);
    cache[0]=0;
    for(int i=0; i<401;i++){
        arr[i] = i*i;
    }
    cout << num_min(n) << endl;
    return 0;
}
int num_min(int num){
    if(num == 0)
        return 0;
    int& ref = cache[num];
    if(ref != -1)
        return ref;
    ref = 987654321;
    for(int i=1;i<401;i++){
        if(arr[i] <= num)
            ref = min(ref, num_min(num-arr[i])+1);
    }
    return ref;
}
