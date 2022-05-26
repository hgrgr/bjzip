#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pll;
int n,m;
char pan[11][11];
struct Pos{
    int blue_y;
    int blue_x;
    int red_y;
    int red_x;
    int move;
    Pos(){blue_y = 0, blue_x =0, red_y =0, red_x=0, move = 0;}
    Pos(pll&r , pll&b,int move){
        red_y = r.first;
        red_x = r.second;
        blue_y = b.first;
        blue_x = b.second;
        this->move = move; 
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    pll red;
    pll blue;
    pll out;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> pan[i][j];
            if(pan[i][j] == 'R'){
                red = make_pair(i,j);
                pan[i][j] = '.';
            }
            else if(pan[i][j] == 'B'){
                blue = make_pair(i,j);
                pan[i][j] = '.';
            }
            else if(pan[i][j] == 'O')
                out = make_pair(i,j);
        }
    }
    
    //simul + BFS
    queue<Pos> q;
    q.push(Pos(red,blue,0));
    Pos here;
    while(!q.empty()){
        bool b_out=false, r_out=false;
        here.red_y = q.front().red_y;
        here.red_x = q.front().red_x;
        here.blue_y = q.front().blue_y;
        here.blue_x = q.front().blue_x;
        here.move = q.front().move;
        if(here.move >= 10){
            cout << "-1";
            return 0;
        }
        q.pop();
        //left
        int am=1;
        int am2=1;
        Pos tmp;
        while(1){//blue  - left
            if(here.blue_x + -1*am >= 0 && pan[here.blue_y][here.blue_x + -1*am]=='.'){
                am++;
                continue;
            }
            if(here.blue_x + -1*am >= 0 && pan[here.blue_y][here.blue_x + -1*am]=='O'){
                b_out = true;
            }
            break;
       }
       while(1){//red - left
            if(here.red_x + -1*am2 >= 0 && pan[here.red_y][here.red_x + -1*am2]=='.'){
                am2++;
                continue;
            }
            if(here.red_x + -1*am2 >= 0 && pan[here.red_y][here.red_x + -1*am2]=='O'){
                r_out = true;
            }
            break;
        }
        if(r_out && !b_out)
        {
            cout << here.move+1;
            return 0;
        }
        if(!b_out){
            if(here.blue_y == here.red_y){
                if(here.red_x + (-1*am2) == here.blue_x + (-1*am)){
                    if(here.red_x < here.blue_x)
                        am--;
                    else
                        am2--;
                }
            }
            tmp.red_y = here.red_y;
            tmp.red_x = here.red_x + (-1*--am2);
            tmp.blue_y = here.blue_y;
            tmp.blue_x = here.blue_x + (-1*--am);
            tmp.move = here.move+1;
            q.push(tmp);
        }
        //right
        b_out = false, r_out = false;
        am=1,am2=1;
        while(1){//blue  - right
            if(here.blue_x + 1*am < m && pan[here.blue_y][here.blue_x + 1*am]=='.'){
                am++;
                continue;
            }
            if(here.blue_x + 1*am < m && pan[here.blue_y][here.blue_x + 1*am]=='O'){
                b_out = true;
            }
                 break;
       }
       while(1){//red - rightl
            if(here.red_x + 1*am2 < m && pan[here.red_y][here.red_x + 1*am2]=='.'){
                am2++;
                continue;
            }
            if(here.red_x + 1*am2 < m && pan[here.red_y][here.red_x + 1*am2]=='O'){
                r_out = true;
            }
            break;
        }
        if(r_out && !b_out)
        {
            cout << here.move+1;
            return 0;
        }
        if(!b_out){
            if(here.blue_y == here.red_y){
                if(here.red_x + (1*am2) == here.blue_x + (1*am)){
                    if(here.red_x > here.blue_x)
                        am--;
                    else
                        am2--;
                }
            }
            tmp.red_y = here.red_y;
            tmp.red_x = here.red_x + (1*--am2);
            tmp.blue_y = here.blue_y;
            tmp.blue_x = here.blue_x + (1*--am);
            tmp.move = here.move+1;
            q.push(tmp);
        }
        //up
        b_out = false, r_out = false;
        am=1,am2=1;
        while(1){//blue  - right
            if(here.blue_y + 1*am < n && pan[here.blue_y + 1*am][here.blue_x]=='.'){
                am++;
                continue;
            }
            if(here.blue_y + 1*am < n && pan[here.blue_y + 1*am][here.blue_x]=='O'){
                b_out = true;
            }
                 break;
       }
       while(1){//red - rightl
            if(here.red_y + 1*am2 < m && pan[here.red_y + 1*am2][here.red_x]=='.'){
                am2++;
                continue;
            }
            if(here.red_y + 1*am2 < m && pan[here.red_y + 1*am2][here.red_x]=='O'){
                r_out = true;
            }
            break;
        }
        if(r_out && !b_out)
        {
            cout << here.move+1;
            return 0;
        }
        if(!b_out){
            if(here.blue_x == here.red_x){
                if(here.red_y + (1*am2) == here.blue_y + (1*am)){
                    if(here.red_y > here.blue_y)
                        am--;
                    else
                        am2--;
                }
            }
            tmp.red_y = here.red_y +(1*--am2); 
            tmp.red_x = here.red_x; 
            tmp.blue_y = here.blue_y + (1*--am);
            tmp.blue_x = here.blue_x; 
            tmp.move = here.move+1;
            q.push(tmp);
        }
        //down
        b_out = false, r_out = false;
        am=1,am2=1;
        while(1){//blue  - right
            if(here.blue_y + -1*am >= 0 && pan[here.blue_y + -1*am][here.blue_x]=='.'){
                am++;
                continue;
            }
            if(here.blue_y + -1*am >= 0 && pan[here.blue_y + -1*am][here.blue_x]=='O'){
                b_out = true;
            }
            break;
       }
       while(1){//red - rightl
            if(here.red_y + -1*am2 >= 0 && pan[here.red_y + -1*am2][here.red_x]=='.'){
                am2++;
                continue;
            }
            if(here.red_y + -1*am2 >= 0 && pan[here.red_y + -1*am2][here.red_x]=='O'){
                r_out = true;
            }
            break;
        }
        if(r_out && !b_out)
        {
            cout << here.move+1;
            return 0;
        }
        if(!b_out){
            if(here.blue_x == here.red_x){
                if(here.red_y + (-1*am2) == here.blue_y + (-1*am)){
                    if(here.red_y < here.blue_y)
                        am--;
                    else
                        am2--;
                }
            }
            tmp.red_y = here.red_y + (-1*--am2);
            tmp.red_x = here.red_x; 
            tmp.blue_y = here.blue_y + (-1*--am);
            tmp.blue_x = here.blue_x; 
            tmp.move = here.move+1;
            q.push(tmp);
        }
    }
    return 0;
}
