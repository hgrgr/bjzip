#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,goal;
vector<int> coin;
int cal_case(int mon, int pos);
int cache[100001][21];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    cin >> tcase;
    for(int t=0;t<tcase;t++)
    {
        memset(cache,-1,sizeof(cache));
        cin >> n;
        coin.clear();
        coin.resize(n);
        for(int i=0;i<n;i++){
            cin >> coin[i]; 
        }
        cin >> goal;
        cout << cal_case(goal,n-1) << endl;
    }

    return 0;
}
int cal_case(int goal, int pos){
    if(goal == 0)
        return 1;
    int& ref = cache[goal][pos];
    if(ref != -1)
        return ref;
    if(pos == 0){
        if((goal % coin[pos]) == 0){
            return ref = 1;
        }
        else
            return ref = 0;
    }
    ref = 0;
    int t_coin = coin[pos];
    for(int coin_su = 0; coin_su*t_coin <= goal; coin_su++){
        ref += cal_case(goal-(coin_su*t_coin),pos-1);
    }
    return ref;
}
