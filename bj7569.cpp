#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int m,n,h;
int adj[101][101][101];
int moving[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
struct Pos{
    int x,y,z;
    int num;
};
queue<Pos> q;
int total;
int com;
int non;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> h;
    total = m*n*h;
    com = 0;
    non = 0;
    Pos tmp;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin >> adj[i][j][k]; 
                if(adj[i][j][k] == 1){
                    tmp.z = i;
                    tmp.y = j;
                    tmp.x = k;
                    tmp.num = 0;
                    q.push(tmp);
                    com++;
                }
                else if(adj[i][j][k] == -1)
                    non++;
            }
        }
    }
    if(com >= total - non)
    {
        cout << "0";
        return 0;
    }
    while(!q.empty()){
        int z = q.front().z; 
        int y = q.front().y; 
        int x = q.front().x;
        int num = q.front().num;
        q.pop();
        for(int i=0;i<6;i++){
            if(z + moving[i][0]  >=0 && z + moving[i][0]< h
                && y + moving[i][1]  >=0 && y + moving[i][1]< n
                && x + moving[i][2]  >=0 && x + moving[i][2]< m
                && adj[z+moving[i][0]][y+moving[i][1]][x+moving[i][2]] == 0){
                adj[z+moving[i][0]][y+moving[i][1]][x+moving[i][2]] = 1;
                com++;
                tmp.z = z+moving[i][0];
                tmp.y = y+moving[i][1];
                tmp.x = x+moving[i][2];
                tmp.num = num+1;
                q.push(tmp); 
            }
        }
        if(com >= total - non)
        {
            cout << num+1;
            return 0;
        }
    }
    cout << "-1";
    return 0;

}
