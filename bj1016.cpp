#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long ll;
bool era[1000001];
map<ll,bool> mymap;
vector<ll> sq_prime;
vector<bool> sqr_no;
void make_era();
int p_num;
ll in,ax;
int main(){
    memset(era,true,sizeof(era));
    cin >> in >> ax;
    sqr_no.resize(ax-in+1,true);
    make_era();
    int total = 0;
    cout << (ax -in +1) - mymap.size();
    return 0;
}
void make_era(){
    era[1] = false;
    era[2] = true;
    for(ll i=2;i<1000001;i++){
        if(era[i]){
            sq_prime.push_back(i*i);
            p_num++;
            for(int j=2;j*i<1000001;j++)
                era[j*i] = false;
        }
    }
    for(int i=0;i<sq_prime.size();i++){
        ll ml = 0;
        if(in > sq_prime[i])
            ml = (in / sq_prime[i]) - 1;
        else if (sq_prime[i] > ax)
           break; 
        while(1){
            ll m_tmp = sq_prime[i]*ml;
            
            if(m_tmp > ax)
                break;
           
            if( m_tmp >= in && m_tmp <= ax)
                mymap[m_tmp] = true;
            ml++; 
        }
    }
}
