#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int l,p;
vector<pair<int,int> > oil;
priority_queue<int> pq;
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    cin >> n;
    int len,we;
    for(int i=0; i<n;i++)
    {
        cin >> len >> we;
        oil.push_back(make_pair(len,we));
    }
    cin >> l >> p;
    sort(oil.begin(),oil.end(),cmp);
    int ret = 0;
    int index = 0;
    while(1)
    {
        if(oil[index].first <= p && index < n){
            pq.push(oil[index++].second);
            continue;
        }
        if(p >= l)
        {
            cout << ret;
            return 0;
        }
        if(p < l && !pq.empty())
        {
            p += pq.top();
            ret += 1;
            pq.pop();
            continue;
        }else if( pq.empty() && p < l){
            cout << "-1";
            return 0;
        }
    }
}

