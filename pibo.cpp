#include <iostream>
#include <cstring>
using namespace std;
int n;
long long int zero, one;
int fibonacci(int n);
int find_z(int n);
int find_o(int n);
int cache_z[41];
int cache_o[41];
int main()
{
    int tcase;
    cin >> tcase;
    for(int i=0; i < tcase; i++)
    {
        memset(cache_z,-1,sizeof(int)*41);
        memset(cache_o,-1,sizeof(int)*41);
        zero = one = 0;
        cin >> n;
        if(n <3)
        {
            fibonacci(n);
            cout<< zero << " " << one << endl;
        }      
        else
            cout << find_z(n-1) << " " << find_o(n) << endl;
    }
    return 0;
}
int find_z(int n){
    if(n == 0){
        cache_z[n] = 1;
        return 1;
    }
    else if(n == 1){
        cache_z[n] = 0;
        return 0;
    }
    int& ref = cache_z[n];
    if(ref != -1)
        return ref;
    return (ref = find_o(n-1)+find_o(n-2));
}
int find_o(int n){
    if(n == 0){
        cache_o[n] = 0;
        return 0;
    }
    else if(n == 1){
        cache_o[n] = 1;
        return 1;
    }
    int& ref = cache_o[n];
    if(ref != -1)
        return ref;
    return (ref = find_o(n-1)+find_o(n-2));
}
int fibonacci(int n) {
    if (n == 0) {
        zero++;
        return 0;
    } else if (n == 1) {
        one++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

