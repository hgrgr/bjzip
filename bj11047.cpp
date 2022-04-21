#include <iostream>
#include <cstring>

using namespace std;
int n,k;
int arr[11];
int main()
{
    cin >> n >> k;
    memset(arr,-1,sizeof(int)*11);
    for(int i=0; i<n;i++)
        cin >> arr[i];
    int div = 0;
    int mod = 0;
    int coin_num = 0;
    int i = n-1;
    while(k != 0){
        div = k / arr[i];
        coin_num += div;
        k -= div*arr[i--];
    }
    cout << coin_num << endl;
    return 0;
}
