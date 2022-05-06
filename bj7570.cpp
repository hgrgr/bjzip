#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[1000001];
int main(){
    cin >> n;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        arr[tmp] = i;
    }
    int ret = 0;
    tmp=1;
    for(int i=0;i<n-1;i++){
        if(arr[i] < arr[i+1]){
            tmp++;
            ret = max(ret,tmp);
        }else
        {
            tmp = 1;
        }
    }
    cout << n - ret << endl;
    return 0;
}
