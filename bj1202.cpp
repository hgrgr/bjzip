#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int ll;
int n,k;
int bag[300001];
bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main(){
    cin >> n >>k;
    vector<pair<int,int> > stone(n);
    int f,s,we;
    for(int i=0; i<n;i++)
    {
        scanf("%d %d",&f,&s);
        stone[i].first = f;
        stone[i].second = s;
    }
    for(int i=0; i<k;i++){
        scanf("%d",&bag[i]);
    }
    int t_bag;
    sort(stone.begin(),stone.end());
    sort(bag,bag+k);
    pair<int, int> t_stone;
    ll ret = 0;
    int id=0;
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        while(id < n && stone[id].first <= bag[i]){
            pq.push(stone[id++].second);
        }
        if(!pq.empty())
        {
            ret +=pq.top();
            pq.pop();
        }
    }
    cout << ret;
    return 0;
}
