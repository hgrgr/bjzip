#include <iostream>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int n,m;
int total = 0;
struct Cam{
    int y,x;
    int dir;
    int num;
    int limt;
    int shoot;
    Cam(){
        y=-1,x=-1,dir=-1,num=-1,limt=-1;
    };
    Cam(int y,int x,int num){
        this->y = y;
        this->x = x;
        this->dir = 0;
        this->num = num;
        switch(num){
        case 1:
            limt = 4;
            shoot = 1;
            break;
        case 2:
            limt = 2;
            shoot = 2;
            break;
        case 3:
            limt = 4;
            shoot = 2;
            break;
        case 4:
            limt = 4;
            shoot = 3;
            break;
        case 5:
            limt = 1;
            shoot = 4;
            break;
        }
    }
};
vector<Cam> camera;
vector<vector<int> > adj;
int cam_num;
int not_see = 0;
int min_see = INF;
void cal_min(int here);
int moving[5][4][4][2] = {//num - dir, shoot , yx
    {//1
        {//dir 
            {0,1},
            {0,0},
            {0,0},
            {0,0}
        },
        { 
            {1,0},
            {0,0},
            {0,0},
            {0,0}
        },
        { 
            {0,-1},
            {0,0},
            {0,0},
            {0,0}
        },
        { 
            {-1,0},
            {0,0},
            {0,0},
            {0,0}
        },
    },
    {//2
        {//dir 
            {0,1},
            {0,-1},
            {0,0},
            {0,0}
        },
        { 
            {1,0},
            {-1,0},
            {0,0},
            {0,0},
        },
        { 
            {0,0},
            {0,0},
            {0,0},
            {0,0},
        },
        { 
            {0,0},
            {0,0},
            {0,0},
            {0,0},
        },
    },
    {//3
        {//dir 
            {0,1},
            {1,0},
            {0,0},
            {0,0},
        },
        { 
            {1,0},
            {0,-1},
            {0,0},
            {0,0},
        },
        { 
            {0,-1},
            {-1,0},
            {0,0},
            {0,0},
        },
        { 
            {-1,0},
            {0,1},
            {0,0},
            {0,0},
        },
    },
    {//dir 4
        { 
            {0,1},
            {1,0},
            {0,-1},
            {0,0},
        },
        { 
            {1,0},
            {0,-1},
            {-1,0},
            {0,0},
        },
        { 
            {0,-1},
            {-1,0},
            {0,1},
            {0,0},
        },
        { 
            {-1,0},
            {0,1},
            {1,0},
            {0,0},
        },
    },
    {
        { 
            {0,1},
            {1,0},
            {0,-1},
            {-1,0},
        },
        { 
            {0,0},
            {0,0},
            {0,0},
            {0,0},
        },
        { 
            {0,0},
            {0,0},
            {0,0},
            {0,0},
        },
        { 
            {0,0},
            {0,0},
            {0,0},
            {0,0},
        },
    },
};
int main(){
    cin >> n >> m;
    adj.resize(n+1,vector<int>(m+1,6));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> adj[i][j];
            if(adj[i][j] == 0){
                not_see++;
            }
            if(adj[i][j] != 0 && adj[i][j] != 6){
                camera.push_back(Cam(i,j,adj[i][j]));
            }
        }
    cam_num = camera.size();
    cal_min(0);
    cout << min_see;
    return 0;
}
void cal_min(int here){
    if(here > cam_num)
        return;
    if(here == cam_num){
        total++;
        int tmp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(adj[i][j] == 0)
                    tmp++;
        }
        if(tmp < min_see){
            min_see = min(min_see,tmp);
        }
        return;
    }
    vector<vector<int> > t_adj(n+1,vector<int>(m+1,6));
    copy(adj.begin(),adj.end(),t_adj.begin());
    for(int dir=0; dir < camera[here].limt;dir++){
        for(int n_shoot = 0;n_shoot < camera[here].shoot;n_shoot++)
        {
            int y = camera[here].y;     
            int x = camera[here].x;     
            int num = camera[here].num;
            while(1)
            {
                if(y+moving[num-1][dir][n_shoot][0] >= 0 && y+moving[num-1][dir][n_shoot][0] < n
                        && x+moving[num-1][dir][n_shoot][1] >=0 && x+moving[num-1][dir][n_shoot][1] < m
                        && (adj[y+moving[num-1][dir][n_shoot][0]][x+moving[num-1][dir][n_shoot][1]] != 6 )){
                    adj[y+moving[num-1][dir][n_shoot][0]][x+moving[num-1][dir][n_shoot][1]] = 8;
                    y = y+moving[num-1][dir][n_shoot][0];
                    x = x+moving[num-1][dir][n_shoot][1];
                    continue;
                }
                break;
            }
        }
        cal_min(here+1);
        copy(t_adj.begin(),t_adj.end(),adj.begin());
    }
}
