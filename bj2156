#include <iostream>
#include <cstring>
using namespace std;
int n;
int wine[100001];
int cache[100001][4];
int mount_wine(int start,int num);
int main()
{
    cin >> n;
    memset(wine,-1,sizeof(int)*100001);
    memset(cache,-1,sizeof(int)*100001*4);
    for(int i=0; i<n;i++)
    {
        cin >> wine[i];
    }
    cout << mount_wine(0,2);
    return 0;
}
int mount_wine(int start,int num){
    if(start == n)
        return 0;

    int& ref = cache[start][num];
    if(ref != -1)
        return ref;
    
    if(num == 0){
        ref = max(ref,mount_wine(start+1,2));
    }
    else{
        ref = max(mount_wine(start+1,num-1)+wine[start],mount_wine(start+1,2));
    }
    return ref;
}
