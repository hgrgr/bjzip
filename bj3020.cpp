#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n,h;
vector<int> under;
vector<int> upper; 
map<int,int> m_map;
int main(){
    cin >> n >> h;
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if( (i % 2) == 0)
            under.push_back(tmp);
        else
            upper.push_back(tmp);
    }
    sort(under.begin(),under.end());
    sort(upper.begin(),upper.end());
    int hi_i,un_i;
    int total = 0;
    for(int i=1;i<=h;i++)
    {
        un_i = i;
        hi_i = h-i+1; 
        m_map[n -(lower_bound(under.begin(),under.end(),un_i)-under.begin() + lower_bound(upper.begin(),upper.end(),hi_i)-upper.begin())]++;
    }
    map<int,int>::iterator  it = m_map.begin();
    cout << it->first << " " << it->second;
    return 0;
}
