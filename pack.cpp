#include <iostream>
using namespace std;

long long int cache[100];
long long int facto(int num){
    if(num == 1)
        return 1;
    long long int& ref = cache[num];
    if(ref != -1)
        return ref;
    ref = num*facto(num-1);
    return ref;
}
int main()
{
    int num;
    cin >> num;
    memset(cache,-1,sizeof(long long int)*100);
    cout << facto(num);
    return 0;
}
