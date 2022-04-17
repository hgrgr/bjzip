#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,w;
string object[101];
int vol[101];
int need[101];
int cache[101][1001];
int memo[101];
int cal_need(int begin, int weight);
void reconstruct(int begin, int weight, vector<string>& picked){
    
    if(begin == n)
        return;
    if(cal_need(begin,weight) == cal_need(begin+1,weight))
    {
        cout<< "a ";
        reconstruct(begin+1,weight,picked);
    }
    else
    {
        cout<< "b ";
        picked.push_back(object[begin]);
        reconstruct(begin+1,weight-vol[begin],picked);
    }
}
int cal_need(int begin, int weight)
{
    if(begin == n)
        return 0;
    int& ref = cache[begin][weight];
    if(ref != -1)
        return ref;
    ref = cal_need(begin+1,weight);
    if(weight - vol[begin] >= 0)
        ref = max(ref, cal_need(begin+1,weight - vol[begin])+need[begin]);
    return ref;


}
int main()
{
    int tcase;
    cin >> tcase;
    int result =0;
    vector<string> pick;
    for(int i=0; i < tcase; i++)
    {
        memset(vol,0,sizeof(int)*101);
        memset(need,0,sizeof(int)*101);
        memset(memo,0,sizeof(int)*101);
        cin >> n >> w;
        memset(cache,-1,sizeof(int)*101*1001);
        for(int j=0; j < n; j++)
        {
            cin >> object[j] >> vol[j] >> need[j];
        }
        result = cal_need(0,w);
        cout << result << endl;
        reconstruct(0,w,pick);
        for(int j=0; j<pick.size();j++)
            cout << pick[j] << endl;
        cout << endl;
        pick.clear();
    }
    return 0;
}
