#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
int cache[101];
int state[101];

bool ck_as(){
    /*
    for(int i =0; i<n; i++)
        cout << state[i] << " ";
    cout << endl;
   */ 
    for(int i=0; i < n/2;i++)
    {
        if(state[i] != state[n-1 -i])
            return false;
    }
    
    return true;
}
int tile_num(int start){
    if(start == n-1)
        state[start] = 1;
    if(start == n-1 || start == n )
    {
        if(ck_as())
            return 0;
        else
            return 1;
    }
    int& ref = cache[start];
    if(ref != -1)
        return ref;
    state[start] = 1;
    ref = tile_num(start+1) % MOD;
    state[start] = 2;
    state[start+1] = 2;
    ref += tile_num(start +2) % MOD;
    state[start] = -1; 
    state[start+1] = -1;
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
        result = tile_num(0) % MOD;
        cout << result << endl;
    }
    return 0;
}
