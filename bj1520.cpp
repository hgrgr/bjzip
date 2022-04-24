#include <iostream>
#include <cstring>
using namespace std;
int m,n;
int arr[501][501];
int cache[501][501];
int min_case = 0;
int moving[4][2]= {{0,-1},{0,1},{1,0},{-1,0}};
int cal_min(int y,int x);
int main(){

    cin >> m >> n; 
    memset(cache,-1,sizeof(int)*501*501);
    for(int i=0;i<m;i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    cout << cal_min(0,0) << endl;

    return 0;
}
int cal_min(int y,int x){
    if(y == m-1 && x == n-1)
        return 1;
    int& ref =cache[y][x];
    if(ref != -1)
        return ref;
    int cur_y = y;
    int cur_x = x;
    ref = 0;
    for(int i=0;i<4;i++)
    {
        if(y+moving[i][0] >=m || x+moving[i][1] >=n || 
                y+moving[i][0]<0 || x+moving[i][1] < 0)
            continue;
        if(arr[y+moving[i][0]][x+moving[i][1]] < arr[y][x])
            ref += cal_min(y+moving[i][0],x+moving[i][1]);
    }
    return ref;
}
