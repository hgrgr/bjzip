#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int start_time[100001];
int end_time[100001];
int main(){
    cin >> n;
    memset(start_time,-1,sizeof(int)*100001);
    memset(end_time,-1,sizeof(int)*100001);
    vector<pair<int,int> > my_vec;
    for(int i=0; i < n; i++)
    {
        cin >> start_time[i] >> end_time[i];
        my_vec.push_back(make_pair(end_time[i],start_time[i]));
    }
    sort(my_vec.begin(),my_vec.end());
    int begin = -1;
    int num = 0;
    for(int i=0; i < my_vec.size(); i++)
    {
        if(begin <= my_vec[i].second){
            num++;
            begin = my_vec[i].first;
        }
        else
            continue;
    }
    cout << num << endl;
    return 0;

}
