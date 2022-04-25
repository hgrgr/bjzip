#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int> > repo;
priority_queue<int, vector<int>, greater<int> > pq;
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    cin >> n; 
    int time,value;
    int date[n];
    for(int i=0; i <n; i++)
    {
        cin >> time >> value;
        repo.push_back(make_pair(time,value));
        date[i] = i+1;
    }
    sort(repo.begin(),repo.end(),cmp);
    int index=0;
    for(int i=0;i<n;i++)
    {
        index = repo[i].first;
        pq.push(repo[i].second);
        if(index >= pq.size())
        {
            continue;
        }else{
            pq.pop();
        }
    }
    int ret=0;
    while(!pq.empty())
    {
        ret += pq.top();
        pq.pop();
    }
    cout << ret;
    return 0;
}
