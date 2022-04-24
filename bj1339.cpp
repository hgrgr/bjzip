#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<char,int> arr;
vector<string> str_v;
bool cmp(const pair<char,int> a,const pair<char,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main(){
    cin >> n;
    string str;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        str_v.push_back(str);
    }
    int tmp=0;
    for(int i=0;i<26;i++){
        arr.insert(make_pair('A'+i,0));
    }
    for(int i=0;i<n;i++)
    {
        tmp =1;
        for(int j=str_v[i].length()-1;j>=0;j--)
        {
            arr[str_v[i][j]] +=tmp;
            tmp *=10;
        }
    }
    vector<pair<char,int> > t_vec(arr.begin(),arr.end() );
    sort(t_vec.begin(),t_vec.end(),cmp);
    int ret =0;
    for(int i=9;i>=0;i--)
    {
        ret += t_vec[9-i].second*i; 
    }
    cout << ret << endl;
       
    return 0;
}
