#include <iostream>
#include <cstring>
#define INF -987654321
using namespace std;
int n,m;
int arr[1001][1001];
int cache[1001][1001][3];
int mving[3][2] = {{1,0},{0,-1},{0,1}};
int cal_min(int y, int x,int lr);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<3;k++)
                cache[i][j][k] = INF;
    cout << cal_min(0,0,0) + arr[0][0];

    return 0;
}
int cal_min(int y, int x, int lr){// 0 - dwon , 1 - left, 2 - right
    if(y== n-1 && x == m-1)
        return 0;
    int& ref = cache[y][x][lr];
    if(ref != INF)
        return ref;
    ref = INF;
    for(int i=0; i<3; i++){
        if(y+mving[i][0] >=0 && y+mving[i][0] <n && x+mving[i][1]>=0 && x+mving[i][1]<m)
        {
            if(lr == 0){
                ref = max(ref,cal_min(y+mving[i][0],x+mving[i][1],i) + arr[y+mving[i][0]][x+mving[i][1]]);
            }else if(lr == 1){
                if(i != 2)
                    ref = max(ref,cal_min(y+mving[i][0],x+mving[i][1],i)+arr[y+mving[i][0]][x+mving[i][1]]);
            }
            else if(lr == 2){
                if( i != 1 )
                    ref = max(ref,cal_min(y+mving[i][0],x+mving[i][1],i)+arr[y+mving[i][0]][x+mving[i][1]]);
            }
        }
    }
    return ref;
}
