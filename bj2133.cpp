#include <iostream>
#include <cstring>
using namespace std;
int n;
long long int cache[31];
long long int num_tile_case(int num);
int main(){

    cin >> n;
    memset(cache,-1,sizeof(long long int)*31);
    cache[0] = 1;
    cache[1] = 0;
    cache[2] = 3;
    cache[3] = 0;

    cout << num_tile_case(n);

    return 0;
}
long long int num_tile_case(int num){
    if(num <0)
        return 0;
    long long int& ref = cache[num];
    if(ref != -1)
        return ref;
    ref = 0;
    ref = num_tile_case(num-2)*3;
    int div = num / 2;
    for(int i=2; i<=div; i++)
    {
        ref +=num_tile_case(num -2*i)*2;
    }
    return ref;
}
