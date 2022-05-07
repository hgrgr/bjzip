#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
map<ll,ll> m_map;
ll arr[300001];
ll n, k;
int main(){
    cin >> n >> k;
    string str;
    for(int i=0; i<n;i++){
        cin >> str;
        arr[i] = str.length();
    }
    for(int i=0; i<=k;i++){
        m_map[arr[i]]++;
    }
    ll total = 0;
    ll st,end;
    st = 0, end = k;
    for(int i=0;i<n;i++){
        if(end < n){
            //cout << " total = " << total << " i = " << i << endl;
            total += m_map[arr[i]]-1; 
            m_map[arr[st++]]--;
            m_map[arr[++end]]++;
        }
        else if(end == n && st != end){
            total += m_map[arr[i]]-1; 
            m_map[arr[st++]]--;
        }
    }
    cout << total;
    return 0;
}
