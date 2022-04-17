#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int num_bri(int x,int y);
int cache[31][31];
int main()
{
    int tcase;
    cin >> tcase;
    memset(cache,-1,sizeof(int)*31*31);
    for(int i=0;i<tcase;i++)
    {
        cin >> n >> m;
        cout << num_bri(n,m) << endl;
    }
    return 0;
}
int num_bri(int x,int y){
    
    if(x==0 || y==0 ||x == y)
    {
        cache[x][y] = 1;
        return cache[x][y];
    }

    int& ref = cache[y][x];
    if(ref != -1)
        return ref;
    
    ref = num_bri(x,y-1) + num_bri(x-1,y-1);
    return ref;

}
