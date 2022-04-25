#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    long long int total=0;
    for(int i=0;i<n;i++)
    {
        if(total+2 <= arr[i])
        {
            break;
        }
        total += arr[i]; 
    }
    cout << total +1 << endl;
    return 0;
}
