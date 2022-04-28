#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef long long int lli;
lli n;
vector<lli> line;
bool judge(long double aab, long double abb);
lli cal_mov(lli x);
int main(){
    cin >> n;
    lli temp;
    for(lli i=0;i<n;i++){
        scanf("%lld",&temp);
        line.push_back(temp);
    }
    lli lo = 0;
    lli hi = line[line.size()-1];
    lli aab,abb;
    
    while(lo + 3 <= hi)
    {
        aab = (lo*2 + hi)/3.0;
        abb = (lo + hi*2)/3.0;
        if(cal_mov(aab) < cal_mov(abb))
            hi = abb;
        else
            lo = aab;
    }
    lli ret = 1e18;

    for(int i=lo; i<=hi;i++)
        ret = min(ret,cal_mov(i));

    printf("%lld",ret);
    return 0;
}
lli cal_mov(lli x){
    lli ret = 0;

    for(lli i = 1; i < n;i++)
        ret += abs(line[i] - x*i);

    return ret;
}
