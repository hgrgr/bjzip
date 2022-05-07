#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int k,n;
ll arr[101];
map<ll,bool> m_map;
priority_queue<ll,vector<ll> ,greater<ll> > pq;
int main(){
    cin >> k >> n;
    ll mx = -1;
    for(int i=0;i<k;i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        pq.push(arr[i]);
        m_map[arr[i]] = true;
    }
    sort(arr,arr+k);
    ll tmp =-1;
    while(n)
    {
        if(tmp == pq.top()){
            pq.pop();
            continue;
       }
       tmp = pq.top();
       pq.pop();
       n--;
       for(int i=0;i<k;i++){
           if(pq.size() >= n && tmp*arr[i] > mx)
               break;
           if(m_map[tmp*arr[i]] != true){
                pq.push(tmp*arr[i]);
                mx = max(mx, tmp*arr[i]);
                m_map[tmp*arr[i]] = true;
           }
       }
    }
    cout << tmp;
    return 0;
}
