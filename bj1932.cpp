#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[501][501];
int max_len(int x,int y);
int cache[501][501];
int main(){
    cin >> n;
    memset(cache,-1,sizeof(int)*501*501);
    memset(arr,0,sizeof(int)*501*501);

    for(int i=0;i<n;i++)
    {
       for(int j=0; j<=i;j++)
           cin >> arr[i][j];
    }
    cout << max_len(0,0)<< endl;
    return 0;
}
int max_len(int x,int y){
    if(x == n-1)
        return arr[x][y];

    int& ref = cache[x][y];
    if(ref != -1)
        return ref;
    ref = 0;
    ref = max(max_len(x+1,y)+arr[x][y], max_len(x+1,y+1)+arr[x][y]);
    return ref;
}
