#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[1001][11];
int num_raise(int num,int start);
int main(){
    cin >> n;
    memset(cache,-1,sizeof(int)*1001*11);
    cout << num_raise(n,0) % 10007;
    return 0;
}
int num_raise(int num,int start){
    if(num == 1)
        return 10-start;

    int& ref = cache[num][start];

    if(ref != -1)
        return ref;

    ref = 0;
    for(int i=start;i<10;i++)
    {
        ref += num_raise(num-1,i) % 10007;
    }
    return ref;

}
