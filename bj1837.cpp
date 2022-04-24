#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[501][501];
int cache[501][501];
int ming[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int max_len(int y,int x);
int main(){
    memset(arr,-1,sizeof(int)*501*501);
    memset(cache,-1,sizeof(int)*501*501);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    int m_max=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m_max= max(m_max,max_len(i,j));
    cout << m_max;
    return 0;
}
int max_len(int y,int x){
    //cout << endl << " y = " << y << " x = " << x << endl;
    if(y == n || x == n || y < 0 || x < 0)
        return 0;
    int& ref = cache[y+1][x+1];
    if(ref != -1)
        return ref;
    ref = 1;
    for(int i=0;i<4;i++)
    {
        if((ming[i][0] + y >= 0 && ming[i][0] + y <= n &&
                ming[i][1] + x >= 0 && ming[i][1] <= n &&
                arr[y][x] < arr[y+ming[i][0]][x+ming[i][1]])){
            ref = max(ref,max_len(y+ming[i][0],x+ming[i][1])+1);
        }
    }
    return ref;
}
