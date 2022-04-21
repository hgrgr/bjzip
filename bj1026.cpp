#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[51];
int b[51];
int main(){
    memset(a,-1,sizeof(int)*51);
    memset(b,-1,sizeof(int)*51);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    sort(a,a+n);
    sort(b,b+n,greater<int>());
    int ret = 0;
    for(int i=0;i<n;i++){
        ret += a[i]*b[i];
    }
    cout << ret << endl;
    return 0;
}
