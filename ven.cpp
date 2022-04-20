#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int make[10001];
int eat[10001];
int time_lunch(int num);
int main(){
    int tcase;
    cin >> tcase;

    for(int i=0; i<tcase; i++)
    {
        memset(make,-1,sizeof(int)*10001);
        memset(eat,-1,sizeof(int)*10001);
        cin >> n;
        for(int j=0; j < n ;j++)
            cin >> make[j];
        for(int j=0; j < n ;j++)
            cin >> eat[j];
        cout << time_lunch(n)<<endl;

    }
    return 0;
}
int time_lunch(int num){
    vector<pair<int,int> > greed_eat;
    for(int i=0; i <num;i++)
        greed_eat.push_back(make_pair(-eat[i],i));
    sort(greed_eat.begin(),greed_eat.end());
    int beginEat=0;
    int box=0,ret=0;
    for(int i=0; i < num;i++)
    {
        box = greed_eat[i].second;
        beginEat += make[box];
        ret = max(ret, beginEat + eat[box]);
    }
    return ret;

}
