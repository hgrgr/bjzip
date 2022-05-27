#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;
typedef pair<int,char> pll;
int pan[101][101];
int moving[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,k,l;
queue<pll> cmd;
struct Pos{
    int y;
    int x;
    int dir;
    Pos(){
        y = 0;
        x = 0;
        dir = 0;
    };
    Pos(int y,int x){
        this->y = y;
        this->x = x;
        dir = 0;
    }
    void chDir(char _dir){
        if(_dir == 'L')
            dir = (4 + (dir - 1)) % 4;
        else if(_dir == 'D')
            dir = (dir + 1) % 4;
    }
};
deque<Pos> laba;
void print_laba();
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    memset(pan,-1,sizeof(pan));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            pan[i][j] = 0;
    }
    int y,x;
    for(int i=0;i<k;i++)
    {
        cin >> y >> x;
        pan[y][x] = 1;
    }
    cin >> l;
    int time;
    char dir;
    for(int i=0;i<l;i++){
        cin >> time >> dir;
        cmd.push(make_pair(time,dir));
    }
    int time_out = 0;
    laba.push_front(Pos(1,1));
    Pos tmp;
    while(1){
        //time raise
        time_out++;
        tmp.y = laba.front().y;
        tmp.x = laba.front().x;
        tmp.dir = laba.front().dir;
        //  checking complict or apple
        //  complict - end game
        //      block
        if(tmp.y+moving[tmp.dir][0] == 0 || tmp.y+moving[tmp.dir][0] > n
                || tmp.x+moving[tmp.dir][1] == 0 || tmp.x+moving[tmp.dir][1] > n){
            cout << time_out;
            return 0;
        }
        //      body
        for(int i=1;i<laba.size();i++){
            if(tmp.y+moving[tmp.dir][0] == laba[i].y && tmp.x+moving[tmp.dir][1] == laba[i].x){
                cout << time_out;
                return 0;
            }
        }
        //moving fornt
        //  apple - grow body
        if(pan[tmp.y+moving[tmp.dir][0]][tmp.x+moving[tmp.dir][1]] == 1){
            pan[tmp.y+moving[tmp.dir][0]][tmp.x+moving[tmp.dir][1]] = 0;
            tmp.y = tmp.y+moving[tmp.dir][0];
            tmp.x = tmp.x+moving[tmp.dir][1];
            tmp.dir = tmp.dir;
            laba.push_front(tmp);
        }else{
            tmp.y = tmp.y+moving[tmp.dir][0];
            tmp.x = tmp.x+moving[tmp.dir][1];
            tmp.dir = tmp.dir;
            laba.push_front(tmp);
            laba.pop_back();
        }
        //  non - apple - not grow
        //moving end
        //check cma
        if(cmd.front().first == time_out){
            laba.front().chDir(cmd.front().second);
            cmd.pop();
        } 
        //print_laba();
    }
    return 0;
}
void print_laba(){
    cout << "----start -----" << endl;
    for(int i=0;i<laba.size();i++){
        cout << " Laba body num = " << i << " Laba.y = " << laba[i].y << " Laba.x = " << laba[i].x << " Laba.dir = " << laba[i].dir << endl; 
    }
    cout << "----end -----" << endl;
}
