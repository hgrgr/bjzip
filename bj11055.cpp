#include <iostream>
#include <cstring>
using namespace std;
int arr[1001];
int cache[1001];
int n;
int max_lis(int start);
int main(){
    cin >> n;
    memset(cache,-1,sizeof(int)*1001);
    for(int i=0; i < n;i++)
        cin >> arr[i];
    cout << max_lis(-1) << endl;
    return 0;
}
int max_lis(int start){
    if(start == n)
        return 0;

    int& ref = cache[start+1];
    if(ref !=-1)
        return ref;
    ref = 0;
    for(int next=start;next<n;next++)
    {
        if(start == -1 || arr[start] < arr[next])
            ref = max(ref, max_lis(next)+arr[next]);
    }
    return ref;

}
