#include <iostream>
#include <cstring>
using namespace std;
int n;
long long int zero, one;
int fibonacci(int n);
int main()
{
    int tcase;
    cin >> tcase;
    for(int i=0; i < tcase; i++)
    {
        zero = one = 0;
        cin >> n;
        fibonacci(n);
        cout << zero << " " << one << endl;
    }
    return 0;
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
