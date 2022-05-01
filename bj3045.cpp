#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
char com;
int bef,aft;
int cache[500001];
int ps[500001];
typedef struct {
    int pre;
    int next;
}Node;
Node m_list[500002];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(cache,-1,sizeof(cache));
    memset(ps,-1,sizeof(ps));
    vector<pair<int,int> > ele(500001,make_pair(-1,-1));
    for(int i=0; i <= n + 1;i++)
    {
        if(i == 0)
        {
            m_list[i].next = i+1;
            continue;
        }
        m_list[i].next = i+1;
        m_list[i].pre = i-1;
    }
    for(int i=0; i< m;i++){
        cin >> com >> bef >> aft;
        m_list[m_list[bef].pre].next = m_list[bef].next;
        m_list[m_list[bef].next].pre = m_list[bef].pre;
        // make list
        if(com == 'A')
        {
            m_list[bef].next = aft;
            m_list[bef].pre = m_list[aft].pre;
        }else if(com == 'B')
        {
            m_list[bef].next = m_list[aft].next;
            m_list[bef].pre = aft;
        }
        m_list[m_list[bef].pre].next = bef;
        m_list[m_list[bef].next].pre = bef;
    }
    int index=0;
    int ele_index=0;
    int logest=0;
    cache[0] = 0;
    for(int i =1;i<=n;i++)
        cache[i] = 987654321;
    for(int i=m_list[0].next; i != n+1; i=m_list[i].next){
        int idx = lower_bound(cache, cache + n, i) - cache;
        cache[idx] = i;
        ps[i] = cache[idx-1];
        logest =max(logest,idx);
    }
    cout << n - logest<<"\n";
    fflush(stdout);
    vector<int> use_num;
    for(int i=cache[logest]; i; i=ps[i])
    {
        use_num.push_back(i);
    }
    reverse(use_num.begin(),use_num.end());
    int t_index=1;
    for(int i=0;i<use_num.size();t_index++){
        if(t_index == use_num[i]){
            i++;
            continue;
        }
        cout << "A " << t_index <<" "<< use_num[i] << '\n';
    }
    int j;
    for(int i=t_index,j=use_num[use_num.size()-1];i<=n;i++){
        cout << "B " << i << " " << j << '\n';
        j=i;
    }
    return 0;
}
