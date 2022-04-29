#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
bool prime[10000];
bool ck_use[10000];
int bef,aft;
vector<int> m_v;
struct compare{
    bool operator()(ii& a, ii&b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
priority_queue<ii,vector<ii>,compare > m_q;
void make_prime();
int cal_prime(int bef, int aft);
int ret;
int main(){
    int tcase;
    cin >> tcase;

    for(int i=0;i<10000;i++)
        prime[i] = true;
   
    make_prime();

    for(int i=0; i< tcase; i++){
        ret = -1;
        cin >> bef >> aft;
        while(!m_q.empty()) m_q.pop();
        memset(ck_use,0,sizeof(bool)*10000);
        ret = cal_prime(bef,aft);
        if( ret == -1 )
            cout << "Impossible" << endl;
        else
            cout << ret << endl;
    }
    return 0;
}
void add_que(int depth, int bef){
    int b1= bef / 1000;
    int b2= (bef - b1*1000) / 100;
    int b3= (bef - b1*1000 - b2*100) / 10;
    int b4= (bef - b1*1000 - b2*100 - b3*10);
    for(int i=0;i<10;i++){
        if(prime[bef - b4 + i] == true && (bef - b4 + i) != bef && ck_use[bef -b4 +i] ==false)
        {
            m_q.push(make_pair(depth,bef - b4 + i));
            ck_use[bef -b4 + i] = true;
        }
        if(prime[bef - b3*10 + i*10] == true && (bef - b3*10 + i*10) != bef && ck_use[bef -b3*10 +i*10] == false){
            m_q.push(make_pair(depth,bef - b3*10 + i*10));
            ck_use[bef -b3*10 + i*10] = true;

        }
        if(prime[bef - b2*100 + i*100] == true && (bef - b2*100 + i*100) != bef && ck_use[ bef - b2*100 + i*100] == false){
            m_q.push(make_pair(depth,bef - b2*100 + i*100));
            ck_use[bef -b2*100 + i*100] = true;

        }
        if(prime[bef - b1*1000 + i*1000] == true && (bef - b1*1000 + i*1000) != bef && i!=0 && ck_use[bef - b1*1000 + i*1000] == false){
            m_q.push(make_pair(depth,bef - b1*1000 + i*1000));
            ck_use[bef -b1*100 + i*100] = true;

        }
    }
    
}
int cal_prime(int bef, int aft){
    m_q.push(make_pair(0,bef));
    ck_use[bef] = true;
    ii temp;
    while(!m_q.empty()){
        temp = m_q.top();
        if(temp.second == aft)
            return temp.first;
        else{
            m_q.pop();
            add_que(temp.first + 1,temp.second);
        }
    }
    return -1;

}
void make_prime(){
    prime[0] = false;
    prime[1] = false;
    int end = sqrt(10000);
    for(int i=2; i<end;i++)
    {
        if(prime[i] == true){
            for(int j=i*i;j<10000;j +=i)
            {
                prime[j] = false;
            }
        }
    }
}
