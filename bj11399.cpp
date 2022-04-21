#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[1001];

int main(){
    cin >> n;
    memset(arr,-1,sizeof(int)*1001);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    int ret = 0;
    int wait = 0;
    for(int i=0;i<n;i++){
       ret += arr[i]; 
       wait += ret;
    }
    cout << wait << endl;
    return 0;
}
