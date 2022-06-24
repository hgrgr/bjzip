#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
typedef pair<int,int> pll;
vector<vector<pll> > adj(10000);
char dslr[4] = {'D','S','L','R'};
int main(){
    int tcase;
    cin >> tcase;
    for(int i=0;i<10000;i++){
        //D
        adj[i].push_back(make_pair((i*2)%10000,0)); 
        //S
        if(i==0)
            adj[i].push_back(make_pair(9999,1));
        else
            adj[i].push_back(make_pair((i-1),1));
        //L
        int r1 = i / 1000;
        adj[i].push_back(make_pair(((i*10)%10000)+r1,2));
        //R
        int l1 = i % 10;
        adj[i].push_back(make_pair(((i/10)%1000) + (l1*1000),3));
    }
    //make GRAH
    for(int t=0;t < tcase;t++){
        vector<int> order;
        order.clear();
        pll visit[10000];
        memset(visit,-1,sizeof(visit));
        queue<pair<int,pll> > q;
        while(!q.empty())
            q.pop();
        int a =0, b = 0;
        cin >> a >> b;
        q.push(make_pair(a,make_pair(0,a)));
        visit[a] = make_pair(-2,-1);
        while(!q.empty()){
            int num = q.front().first;
            int cost = q.front().second.first;
            int parent = q.front().second.second;
            q.pop();
            if(num == b)
            {
                for(int p = num; p != -2 ; p=visit[p].first){
                    order.push_back(p);
                }
   
                reverse(order.begin(),order.end());
                for(int i=0;i<order.size();i++)
                    if(visit[order[i]].second != -1)
                        cout << dslr[visit[order[i]].second];
                break;
            }
            for(int next=0;next < adj[num].size();next++){
                if(visit[adj[num][next].first].first == -1){
                    q.push(make_pair(adj[num][next].first,make_pair(cost+1,num)));
                    visit[adj[num][next].first] = make_pair(num,adj[num][next].second);
                }
            }
            
        }
        cout << '\n';
    }
    return 0;
}
