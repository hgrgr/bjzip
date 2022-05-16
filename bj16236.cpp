#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct {
    int y;
    int x;
    int eat;
    int size;
    int move;
}Shark;
typedef pair<int,int> pll;
typedef pair<pair<int,int>,int> pplll;
int arr[21][21];
bool visit[21][21];
int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n;
queue<pplll> q;
vector<pll> m_v;
pplll dfs(int size);
void print_borad();
bool cmpare(pll& a, pll& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(arr,0,sizeof(arr));
    cin >> n;
    Shark baby;
    baby.eat = 0;
    baby.size = 2;
    baby.move = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9)
            {
                baby.y = i;
                baby.x = j;
            }
        }
    }
    pplll tmp;
    while(1){
        while(!q.empty()){
            q.pop();
        }
        q.push(make_pair(make_pair(baby.y,baby.x),0));
        arr[baby.y][baby.x] = 0;
        memset(visit,0,sizeof(visit));
        tmp = dfs(baby.size);
        if(tmp.first.first == -1 && tmp.first.second == -1){
            cout << baby.move;
            return 0;
        }
        baby.eat++;
        if(baby.eat == baby.size)
        {
            baby.size++;
            baby.eat=0;
        }
        baby.move += tmp.second;
        baby.y = tmp.first.first;
        baby.x = tmp.first.second;
    }
    return 0;
}
pplll dfs(int size){
    m_v.clear();
    pplll tmp;
    int ckbit=0;
    int len;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(arr[tmp.first.first][tmp.first.second] != 0 && arr[tmp.first.first][tmp.first.second] !=9
                && arr[tmp.first.first][tmp.first.second] < size){
            m_v.push_back(make_pair(tmp.first.first,tmp.first.second));
            len = tmp.second;
            while(q.front().second == len && !q.empty()){
                if(arr[q.front().first.first][q.front().first.second] !=0 && arr[q.front().first.first][q.front().first.second] !=9
                        && arr[q.front().first.first][q.front().first.second] < size){
                    m_v.push_back(make_pair(q.front().first.first, q.front().first.second));
                }
                q.pop();
            }
            sort(m_v.begin(),m_v.end(),cmpare);
            return make_pair(m_v[0],len);
        }
        for(int i=0;i<4;i++){
            if(tmp.first.first+moving[i][0] >=0 && tmp.first.first + moving[i][0] < n && !visit[tmp.first.first+moving[i][0]][tmp.first.second+moving[i][1]] &&
                    tmp.first.second + moving[i][1] >=0 && tmp.first.second + moving[i][1] < n && arr[tmp.first.first+moving[i][0]][tmp.first.second+moving[i][1]] <=size){
                    q.push(make_pair(make_pair(tmp.first.first+moving[i][0],tmp.first.second+moving[i][1]),tmp.second+1));
                    visit[tmp.first.first+moving[i][0]][tmp.first.second+moving[i][1]] = true;

            }
        }
        visit[tmp.first.first][tmp.first.second] = true; 
    }        
    return make_pair(make_pair(-1,-1),-1);
}
