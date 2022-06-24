#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pll;
int n,k;
vector<int> back(100001,-1);
vector<bool> visit(100001,false);
vector<int> order;
queue<pll> q;
int main(){
    cin >> n >> k;
    q.push(make_pair(n,0)); 
    visit[n] = true;
    back[n] = n;
    while(!q.empty()){
        int pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        if(pos == k){
            cout << cost << endl;
            for(int i=pos;i != n; i=back[i])
                order.push_back(i);
            
            order.push_back(n);
            reverse(order.begin(),order.end());
            for(int i=0;i<order.size();i++)
                cout << order[i] << " ";
            break;
        } 
        if(pos-1>=0 && !visit[pos-1]){
            visit[pos-1] = true;
            back[pos-1] = pos;
            q.push(make_pair(pos-1,cost+1));
        }
        if(pos+1 <=100000 && !visit[pos+1]){
            visit[pos+1] = true;
            back[pos+1] = pos;
            q.push(make_pair(pos+1,cost+1));
        }
        if(pos*2 <= 100000 && !visit[pos*2]){
            visit[pos*2] = true;
            back[pos*2] = pos;
            q.push(make_pair(pos*2,cost+1));
        }
    }
    return 0;
}
