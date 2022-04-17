#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000000000 +1;
int n,k;
int s[501];
int cache_len[501];
int cache_num[501];

int count(int start);
int lis3(int start);
void find_lis(int start,int skip,vector<int>& list);
int main()
{
    int tcase;
    cin >> tcase; 
    vector<int> list;
    for(int i=0; i < tcase; i++)
    {
        cin >> n >> k;
        memset(s,-1,sizeof(int)*501);
        memset(cache_len,-1,sizeof(int)*501);
        memset(cache_num,-1,sizeof(int)*501);
        for(int j =0; j < n; j++){
            cin >> s[j];
        }
        cout << lis3(-1)-1 << endl;
        for(int j =0; j <= n; j++)
            cout << cache_len[j] << " ";
        cout << endl;
        cout << count(-1) << endl;
        for(int j =0; j <= n; j++)
            cout << cache_num[j] << " ";
        cout << endl;
        find_lis(-1,k,list);
        for(int j=0; j <= list.size();j++)
            cout << list[j] << " ";
        cout << endl;
        list.clear();
    }

    return 0;
}
int lis3(int start){
    int& ref = cache_len[start+1];
    if(ref != -1)
        return ref;
    ref = 1;
    for(int next = start+1; next < n; next++){
        if( start == -1 || s[start] < s[next])
            ref = max(ref, lis3(next)+1);
    }
    return ref;
}
int count(int start){
    int& ref = cache_num[start+1];
    if(lis3(start) == 1) return ref=1;
    
    if(ref != -1)
        return ref;

    ref = 0;
    for(int next = start+1; next < n; next++){
        if((s[start] < s[next] || start == -1) && lis3(start) == lis3(next)+1)
        { 
            ref = min<long long>(MAX,(long long)ref + count(next));
        }
    }
    return ref;

}
void find_lis(int start,int skip,vector<int>& list){
    if(start !=-1) list.push_back(s[start]);
    vector<pair<int,int> > followers;
    for(int next=start+1;next<n;next++){
        if(((start == -1 || s[start] < s[next]) && lis3(start) == lis3(next)+1)){
            followers.push_back(make_pair(s[next],next));
        }
    }
    sort(followers.begin(),followers.end());
    for(int i=0; i < followers.size(); i++)
    {
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt < skip)
            skip -=cnt;
        else{
            find_lis(idx,skip,list);
            break;
        }
    }
}
