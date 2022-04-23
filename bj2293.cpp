#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int coin[101];
int cache[10001];
void num_coin();
int main(){
    cin >> n >> k; 
    memset(cache,0,sizeof(int)*10001);
    for(int i=0; i<n;i++)
        cin >> coin[i];
    num_coin();
    return 0;
}
void num_coin(){
    cache[0] = 1;
    for(int i=0; i < n;i++){
        for(int j=coin[i]; j<=k; j++){
            if(cache[j-coin[i]]){
                cache[j] += cache[j-coin[i]];
            }
        }
    }
    cout << cache[k] << endl;
}
