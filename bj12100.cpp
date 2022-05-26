#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int _max = 0;
void play(int m_num,vector<vector<int> >& pan);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<vector<int> > pan(n,vector<int> (n,0));
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> pan[i][j];
        }
    }
    play(5,pan);
    cout << _max;
    return 0;
}
void play(int m_num,vector<vector<int> >& pan){
    if(m_num == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                _max = max(_max,pan[i][j]);
            }
        }
        return;
    }
    vector<vector<int> > tmp = pan;
    int merge[21][21];
    memset(merge,0,sizeof(merge));
    //left
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int y = i;
            int x = j;
            while(1){
                if(x - 1 >=0 && pan[y][x-1] == 0){
                    pan[y][x-1] = pan[y][x];
                    pan[y][x] = 0;
                    x = x-1;
                    continue;
                }
                else if(x-1 >= 0 && pan[y][x-1] == pan[y][x] && merge[y][x-1]==0){
                    pan[y][x-1] += pan[y][x];
                    pan[y][x] = 0;
                    merge[y][x-1] = 1;
                }
                break;
            }
        }
    }
    play(m_num-1,pan);
    
    pan = tmp;
    //right
    memset(merge,0,sizeof(merge));
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            int y = i;
            int x = j;
            while(1){
                if(x + 1 < n && pan[y][x+1] == 0){
                    pan[y][x+1] = pan[y][x];
                    pan[y][x] = 0;
                    x = x+1;
                    continue;
                }
                else if(x+1 < n && pan[y][x+1] == pan[y][x] && merge[y][x+1] == 0){
                    pan[y][x+1] += pan[y][x];
                    pan[y][x] = 0;
                    merge[y][x+1] = 1;
                }
                break;
            }
        }
    }
    play(m_num-1,pan);
    pan = tmp;
    //up
    memset(merge,0,sizeof(merge));
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            int y = i;
            int x = j;
            while(1){
                if(y - 1 >=0 && pan[y-1][x] == 0){
                    pan[y-1][x] = pan[y][x];
                    pan[y][x] = 0;
                    y = y-1;
                    continue;
                }
                else if(y-1 >= 0 && pan[y-1][x] == pan[y][x] && merge[y-1][x] == 0){
                    pan[y-1][x] += pan[y][x];
                    pan[y][x] = 0;
                    merge[y-1][x] = 1;
                }
                break;
            }
        }
    }
    play(m_num-1,pan);
    pan = tmp;
    //down
    memset(merge,0,sizeof(merge));
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            int y = i;
            int x = j;
            while(1){
                if(y + 1 < n && pan[y+1][x] == 0){
                    pan[y+1][x] = pan[y][x];
                    pan[y][x] = 0;
                    y = y+1;
                    continue;
                }
                else if(y+1 < n && pan[y+1][x] == pan[y][x] && merge[y+1][x] ==0){
                    pan[y+1][x] += pan[y][x];
                    pan[y][x] = 0;
                    merge[y+1][x] = 1;
                }
                break;
            }
        }
    }
    play(m_num-1,pan);
}
