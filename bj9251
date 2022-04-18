#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string n,m;
int a,b;
int cache[1001][1001];
int num_lcs(int fir,int sec);
int main(){
    cin >> n >> m;
    memset(cache,-1,sizeof(int)*1001*1001);
    cout <<  num_lcs(0,0)<<endl;
    return 0;
}
int num_lcs(int fir,int sec){
    if(fir == n.length() || sec == m.length())
        return 0;
    int& ref = cache[fir+1][sec+1];
    if(ref != -1)
        return ref;
    ref = 0;
    if(n[fir] == m[sec])
        ref = max(ref,num_lcs(fir+1,sec+1)+1);
    else
        ref = max(num_lcs(fir+1,sec),num_lcs(fir,sec+1));
    return ref;
}
