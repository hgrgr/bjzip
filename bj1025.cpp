#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
ll moving[8][2] = { {-1,0}, {1,0}, {0,-1}, {0,1},
                    {-1,-1} , {1,1} , {-1,1}, {1,-1}};
ll n,m;
ll arr[10][10];
ll ret = -1;
bool sqr_ck(ll num);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(arr,-1,sizeof(arr)); 
    
    char tmp;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++){
            cin >> tmp;
            arr[i][j] = (ll)tmp - (ll)'0';
            
            if(arr[i][j] > ret)
                if(sqr_ck(arr[i][j]))
                    ret = arr[i][j];
        }
    
    for(ll y=0;y < n;y++)
        for(ll x=0;x < m;x++)
        {
            for(ll len_y = 0;len_y < n; len_y++){
                for(ll len_x = 0;len_x < m; len_x++){
                    if(len_y == 0 && len_x == 0)
                        continue;
                    for(ll dir = 0;dir < 8; dir++)
                    {
                        ll num = arr[y][x];
                        ll c_y = y;
                        ll c_x = x;
                        while((c_y + (moving[dir][0])*len_y) >= 0 && (c_y + (moving[dir][0])*len_y) < n &&
                                (c_x + (moving[dir][1])*len_x) >= 0 && (c_x + (moving[dir][1])*len_x) < m){
                            if((c_y == (c_y +(moving[dir][0]*len_y))) &&
                                    (c_x == (c_x + (moving[dir][1]*len_x))))
                                break;
                            c_y = c_y + ((moving[dir][0]) * len_y);
                            c_x = c_x + ((moving[dir][1]) * len_x);
                            num *= 10;
                            num += arr[c_y][c_x];
                            if(sqr_ck(num))
                                if(num > ret)
                                    ret = num;
                        }     
                    }
                }
            }
        }   
    cout << ret;
    return 0;
}
bool sqr_ck(ll num){
    ll i = 0;
    while(1){
        if( (i*i) > num)
            break;
        if(num == (i*i)){
            return true;
        }
        i++;
    }
    return false;
}
