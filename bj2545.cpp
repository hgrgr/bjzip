#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int cache[101];
vector<pair<int,int> > line;
int num_line(int start);
int ck_cross();
int main()
{
    cin >> n;
    int n1,n2;
    memset(cache,-1,sizeof(int)*101);
    for(int i=0;i<n;i++)
    {
        cin >> n1 >> n2;
        line.push_back(make_pair(n1,n2));
    }
    sort(line.begin(),line.end());
    cout << n - num_line(-1) << endl;
    return 0;
}
int num_line(int start){
    if(start == n)
        return 0;
    int& ref = cache[start+1];
    if(ref != -1)
        return ref;
    ref = 0;
    for(int next = start+1;next < n;next++){
        if(start == -1 || line[start].second < line[next].second)
            ref = max(ref,num_line(next)+1);
    }
    return ref;
}
