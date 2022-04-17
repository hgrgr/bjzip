#include <iostream>
using namespace std;

const int MOD = 10*1000*1000;
int n;
int cache[101][101];
int poly_num(int num, int line){
    
    if(num == line)
        return 1;
  
   int& ref = cache[num][line];
   if(ref != -1)
       return ref;

   ref = 0;
   for(int second=1; second <= num - line; second++)
   {
       int add = (line + second -1);
       add *=poly_num(num-line, second);
       add %= MOD;
       ref +=add;
       ref %=MOD;
   }
   //cout << "ref = " << ref << endl;
   return ref;
}
int main()
{
    int tcase;
    cin >> tcase;
    int result = 0;

    for(int i=0; i < tcase; i++)
    {
        cin >> n;
        memset(cache,-1,sizeof(int)*101*101);
        result = 0;
        for(int first=1; first <= n; first++){
            result += poly_num(n,first);
            result %= MOD;
        }
        cout << result << endl;
    }
    return 0;
}
