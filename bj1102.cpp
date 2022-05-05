#include <iostream>
#include <cstring>
#include <cstring>
#define INF 987654321
using namespace std;
string str;
unsigned int str_bit = 0;
int arr[17][17];
int cache[1<<17];
int n;
int p;
int min_cost(unsigned int state);
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    cin >> str;
    cin >> p;
    for(int i=0;i<str.length();i++){
        str_bit = str_bit << 1;
        if(str[i] == 'Y')
            str_bit |= 1;
        else if(str[i] == 'N')
            str_bit |= 0;
    }
    memset(cache,-1,sizeof(cache));
    if(min_cost(str_bit) != INF)
        cout << min_cost(str_bit);
    else
        cout << "-1";
    return 0;
}
int min_cost(unsigned int state){
    if(__builtin_popcount(state) >= p)
        return 0;

    int& ref = cache[state];    
    if(ref != -1)
        return ref;
    ref = INF;
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((state & 1<<(n-i-1)) && (state & 1<<(n-j-1)) == 0)
                ref = min(ref, min_cost(state | 1<<(n-j-1) )+arr[i][j]);
        }
    }
    return ref;
}
