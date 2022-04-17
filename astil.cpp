#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
int cache[101];
int state[101];

int tile_num(int width){
    if(width <= 1)
        return 1;
    int& ref = cache[width];
    if(ref != -1)
        return ref;

    ref = (tile_num(width -1) + tile_num(width - 2)) % MOD;
    return ref;
}
int main()
{
    int tcase;
    cin >> tcase;
    int result = 0;
    for(int i=0; i<tcase; i++)
    {
        cin >> n;
        memset(cache,-1,sizeof(int)*101);
        memset(state,-1,sizeof(int)*101);
        int ret = tile_num(n);//total num;
        if(n % 2 == 1){
            ret = (ret - tile_num(n/2) + MOD) % MOD;
        }
        else{
            ret = (ret - tile_num(n/2) + MOD) % MOD;
            ret = (ret - tile_num(n/2 -1) + MOD) % MOD;
        }
        cout<< ret << endl;
        
    }
    return 0;
}
