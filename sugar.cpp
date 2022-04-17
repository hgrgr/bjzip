#include <iostream>
#include <cstring>
using namespace std;
int weight;
int cache[5001];

int num_bag(int we);
int main()
{
    cin >> weight;
    memset(cache,-1,sizeof(int)*5001);
    if(num_bag(weight) <= 2000)
        cout << num_bag(weight);
    else
        cout << "-1";
    return 0;
}
int num_bag(int we){
    if(we==5 || we==3)
        return 1;
    else if(we <5)
        return 987654321;
    int& ref = cache[we];
    if(ref !=-1)
        return ref;
    ref = min(num_bag(we-5)+1, num_bag(we-3)+1);
    return ref;
}
