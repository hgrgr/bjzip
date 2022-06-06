#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int max_value;
int moving[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int f_moving[4][3][2] = {
        { {0,-1}, {1,0}, {0,1} },
        { {1,0}, {0,1}, {-1,0} },
        { {0,1}, {-1,0}, {0,-1} },
        { {-1,0}, {0,-1}, {1,0} },
};
vector<vector<int> > adj;
vector<vector<bool> > use;
int cal_max(int y,int x,int lest);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1,vector<int>(m+1,0));
    use.resize(n+1,vector<bool>(m+1,false));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> adj[i][j];
    cout << cal_max(0,0,-1);
    return 0;
}
int cal_max(int y,int x,int lest){
    if(lest == 1)
        return adj[y][x];
    if(lest == -1)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max_value = max(max_value, cal_max(i,j,4));
                fflush(stdout);
            }
        }
        return max_value;
    }
    int mx=0;
    int spot = adj[y][x];
    use[y][x] = true;
    if(lest == 4){
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(y + f_moving[i][j][0] >= 0 && y + f_moving[i][j][0] < n &&
                        x + f_moving[i][j][1] >=0 && x + f_moving[i][j][1] < m){
                    if(j < 2)
                        continue;
                    mx = max(mx,spot +
                            cal_max(y+f_moving[i][0][0],x+f_moving[i][0][1],lest-3) +
                            cal_max(y+f_moving[i][1][0],x+f_moving[i][1][1],lest-3) +
                            cal_max(y+f_moving[i][2][0],x+f_moving[i][2][1],lest-3)
                            );
                }
                break;
            }
            if(y + moving[i][0] >= 0 && y + moving[i][0] < n &&
                    x + moving[i][1] >=0 && x + moving[i][1] < m &&
                    !use[y+moving[i][0]][x+moving[i][1]]){
                mx = max(mx,spot + 
                        cal_max(y+moving[i][0],x+moving[i][1],lest-1) 
                        );
            }
        }
    }else{
        for(int i=0;i<4;i++)
        {
            if(y + moving[i][0] >= 0 && y + moving[i][0] < n &&
                    x + moving[i][1] >=0 && x + moving[i][1] < m &&
                    !use[y+moving[i][0]][x+moving[i][1]]){
                mx = max(mx,spot + 
                        cal_max(y+moving[i][0],x+moving[i][1],lest-1) 
                        );
            }
        }
    }
    use[y][x] = false;
    return mx;
}
