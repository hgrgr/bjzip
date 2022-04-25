#include <iostream>
#include <cstring>
using namespace std;
char mmap[100001][501];
int cache[100001][501];
int ming[3][2] = {{-1,1},{0,1},{1,1}};
int r,c;
int cal_root(int y, int x);
int dap=0;
int main(){
    cin >> r >> c;
    memset(mmap,-1,sizeof(char)*100001*501);
    memset(cache,-1,sizeof(int)*100001*501);
    for(int i=0; i<r;i++)
        scanf("%s",mmap[i]);
    int ret =0;
    for(int i=0;i<r;i++){
        ret +=cal_root(i,0);
    }
    cout << ret;
    return 0;
}
int cal_root(int y, int x){
    if(x==c-1)
    {
        return 1;
    }
    int& ref = cache[y][x];
    if(ref !=-1)
        return ref;
    ref = 0;
    for(int i=0;i<3;i++)
    {
        if(mmap[y+ming[i][0]][x+ming[i][1]] == '.' && y+ming[i][0] < r &&
                y+ming[i][0] >=0 && x+ming[i][1] < c && x+ming[i][1] >=0)
        {
            mmap[y+ming[i][0]][x+ming[i][1]] = 'X';
            if(cal_root(y+ming[i][0],x+ming[i][1])){
                ref=1;
                break;
            }else
                mmap[y+ming[i][0]][x+ming[i][1]] = '.';
        }
    }
    return ref;
}
