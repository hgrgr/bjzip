#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
ll arr[301][22];
ll cache[301][301];
ll re[301][301];
ll max_money(int money, int compa);
void print_cost(int money,int compa);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(cache,-1,sizeof(cache));
    for(int i=1; i<=n;i++){
        for(int j=0;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    cout << max_money(n,1)<< endl;
    print_cost(n,1);
    return 0;
}
void print_cost(int money , int compa){
    if(compa == m+1)
        return;
    int consum = re[money][compa];
    cout << consum << " ";
    print_cost(money-consum,compa+1);
}
ll max_money(int money, int compa){
    if(compa == m+1 || money == 0)
        return 0;
    ll& ref = cache[money][compa];
    if( ref != -1 )
        return ref;
    ref = 0;
    int Bnext;
    int tmp;
    for(int cost = 0;cost<=money;cost++){
        tmp = max_money(money-cost,compa+1)+arr[cost][compa];
        if(tmp > ref){
            ref = tmp;
            Bnext = cost;
        }
    }
    re[money][compa]=Bnext;
    return ref;
}
