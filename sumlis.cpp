#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int NEGINF = numeric_limits<int>::min();
int first[100];
int second[100];
int cache[101][101];
int n,m;

int sumlis(int x,int y)
{
    int& ref = cache[x+1][y+1];
    if(ref != -1)
        return ref;

    ref = 2;
    int a = (x == -1 ? NEGINF : first[x]);
    int b = (y == -1 ? NEGINF : second[y]);
    int maxelement = max(a,b);
    
    for(int nextX = x+1; nextX < n; nextX++){
        if(maxelement < first[nextX])
            ref = max(ref, sumlis(nextX,y) + 1);
    }
    for(int nextY = y+1; nextY < m; nextY++){
        if(maxelement < second[nextY])
            ref = max(ref, sumlis(x,nextY) + 1);
    }
    return ref;
}

int main(){
    int tcase;
    cin >> tcase;

    for(int i=0; i < tcase; i++)
    {
       cin >> n >> m;
       memset(cache,-1,sizeof(int)*(101)*(101));
       memset(first,-1,sizeof(int)*100);
       memset(second,-1,sizeof(int)*100);
       for(int t=0; t < n; t++)
           cin >> first[t];
       for(int t=0; t < m; t++)
           cin >> second[t];

       int result = sumlis(-1,-1);
       //int result = sumlis(0,1);
       cout << result << endl; 

       
    }
    return 0;
}
