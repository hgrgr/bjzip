#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<vector<int> > adj;
int cache[17][17][17][17];
int r_moving[2][2] = {{0,1}, {1,1}};
int do_moving[2][2] = {{1,0}, {1,1}};
int di_moving[3][2] = {{0,1}, {1,0}, {1,1}};
int cal_root(int t_y, int t_x, int h_y, int h_x);
int main(){
    cin >> n;
    adj.resize(n+1,vector<int>(n+1,-1));
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> adj[i][j];
    cout << cal_root(0,0,0,1);
    return 0;
}
int cal_root(int t_y, int t_x, int h_y, int h_x){
    if(h_y == n-1 && h_x == n-1)
        return 1;
    int& ref = cache[t_y][t_x][h_y][h_x];
    if(ref != -1)
        return ref;
    ref = 0;
    if(abs(t_y - h_y) - abs(t_x - h_x) == 0){// dia
        bool ck_r = false;
        bool ck_d = false;
        if(h_y + 1 < n && adj[h_y + 1][h_x] == 0)//down
        {
            ck_d = true;
            ref += cal_root(h_y,h_x,h_y+1,h_x);
        }
        if(h_x + 1 < n && adj[h_y][h_x + 1] == 0)//right
        {
            ck_r = true;
            ref += cal_root(h_y,h_x,h_y,h_x+1);
        }
        if(h_x + 1 < n && h_y +1 < n && adj[h_y+1][h_x+1] == 0 && ck_r && ck_d)//dia
        {
            ref += cal_root(h_y,h_x,h_y+1,h_x+1);
        }
    }else if(abs(t_y - h_y) - abs(t_x - h_x) == 1){// I 
        if(h_y + 1 < n && adj[h_y + 1][h_x] == 0)//down
        {
            ref += cal_root(h_y,h_x,h_y+1,h_x);
        }
        if(h_x + 1 < n && h_y +1 < n && adj[h_y+1][h_x+1] == 0 &&
               adj[h_y+1][h_x] == 0 && adj[h_y][h_x+1] == 0)//dia
        {
            ref += cal_root(h_y,h_x,h_y+1,h_x+1);
        }
    }else if(abs(t_y - h_y) - abs(t_x - h_x) == -1){// ㅡ
        if(h_x + 1 < n && adj[h_y][h_x + 1] == 0)//right
        {
            ref += cal_root(h_y,h_x,h_y,h_x+1);
        }
        if(h_x + 1 < n && h_y +1 < n && adj[h_y+1][h_x+1] == 0 &&
               adj[h_y+1][h_x] == 0 && adj[h_y][h_x+1] == 0)//dia
        {
            ref += cal_root(h_y,h_x,h_y+1,h_x+1);
        }
    }
    return ref;
}
