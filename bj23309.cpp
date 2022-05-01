#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n,m;
typedef struct {
    int pre;
    int next;
}Node;
Node sub[1000002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int tmp;
    sub[0].next = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(i==0)
        {
            sub[0].next = tmp;
            sub[tmp].pre = 0;
            end = sub[0].next; 
            continue;
        }
        sub[end].next = tmp;
        sub[tmp].pre = end;
        end = sub[end].next;
    }
    //add circle
    sub[end].next = sub[0].next;
    sub[sub[0].next].pre = end;
    int t = n*10;
    int start = sub[0].next;
    string cmd;
    int fir,sec;
    int m_t;
    for(int i=0; i<m;i++)
    {
        cin >> cmd; 
        if(!cmd.compare("BN")){
            cin >> fir >> sec;
            cout << sub[fir].next<< "\n";           
            m_t = sub[fir].next;
            sub[sec].next = sub[fir].next;
            sub[sec].pre = sub[sub[fir].next].pre;
            sub[sub[fir].next].pre = sec;
            sub[fir].next = sec;

            n++;
        }else if(!cmd.compare("BP")){
            cin >> fir >> sec;
            cout << sub[fir].pre << "\n";
            sub[sec].next = sub[sub[fir].pre].next;
            sub[sec].pre = sub[fir].pre;
            sub[sub[fir].pre].next = sec;
            sub[fir].pre = sec;
            n++;
        }else if(!cmd.compare("CN")){
            cin >> fir; 
            cout << sub[fir].next << "\n";
            m_t = sub[fir].next;
            sub[sub[m_t].next].pre = fir;
            sub[fir].next = sub[m_t].next;
            n--;
        }else if(!cmd.compare("CP")){
            cin >> fir; 
            cout << sub[fir].pre << "\n";
            m_t = sub[fir].pre;
            sub[sub[m_t].pre].next = fir;
            sub[fir].pre = sub[m_t].pre;
            n--;
        }
    }

    return 0;
}
